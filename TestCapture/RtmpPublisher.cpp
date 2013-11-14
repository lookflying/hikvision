#include "RtmpPublisher.h"
#include <cstring>
#include <cassert>
#include <cstdio>

#ifdef WIN32
#include <WinSock.h>
#pragma comment(lib,"WS2_32.lib")
#pragma comment(lib,"winmm.lib")
#endif

#pragma comment(lib, "librtmp.lib")

int hex2bin(char *str, char **hex)
{
	char *ptr;
	int i, l = strlen(str);
	if (l & 1)
		return 0;
	*hex = (char *)malloc(l/2);
	ptr = *hex;
	if (!ptr)
		return 0;
	for (i=0; i<l; i+=2)
		*ptr++ = (HEX2BIN(str[i]) << 4) | HEX2BIN(str[i+1]);
	return l/2;
}
char * put_byte( char *output, uint8_t nVal )
{
	output[0] = nVal;
	return output+1;
}
char * put_be16(char *output, uint16_t nVal )
{
	output[1] = nVal & 0xff;
	output[0] = nVal >> 8;
	return output+2;
}
char * put_be24(char *output,uint32_t nVal )
{
	output[2] = nVal & 0xff;
	output[1] = nVal >> 8;
	output[0] = nVal >> 16;
	return output+3;
}
char * put_be32(char *output, uint32_t nVal )
{
	output[3] = nVal & 0xff;
	output[2] = nVal >> 8;
	output[1] = nVal >> 16;
	output[0] = nVal >> 24;
	return output+4;
}
char *  put_be64( char *output, uint64_t nVal )
{
	output=put_be32( output, nVal >> 32 );
	output=put_be32( output, (uint32_t)nVal );
	return output;
}
char * put_amf_string( char *c, const char *str )
{
	uint16_t len = strlen( str );
	c=put_be16( c, len );
	memcpy(c,str,len);
	return c+len;
}
char * put_amf_double( char *c, double d )
{
	*c++ = AMF_NUMBER;	/* type: Number */
	{
		unsigned char *ci, *co;
		ci = (unsigned char *)&d;
		co = (unsigned char *)c;
		co[0] = ci[7];
		co[1] = ci[6];
		co[2] = ci[5];
		co[3] = ci[4];
		co[4] = ci[3];
		co[5] = ci[2];
		co[6] = ci[1];
		co[7] = ci[0];
	}
	return c+8;
}


int RtmpPublisher::m_g_count = 0;

RtmpPublisher::RtmpPublisher(RTMP * rtmp, const char* url){
	if (m_g_count == 0){
		initSockets();
	}
	int err;
	unsigned int len = strlen(url);
	m_url = new char[len + 1];
	memcpy(m_url, url, len);
	m_url[len] = (char)0;
	m_rtmp = rtmp;
	RTMP_Init(m_rtmp);
	RTMP_Init(&m_rtmp_real);
	m_rtmp = &m_rtmp_real;

	err = RTMP_SetupURL(m_rtmp, m_url);
	assert(err > 0);
	RTMP_EnableWrite(m_rtmp);
	err = RTMP_Connect(m_rtmp, NULL);
	assert(err > 0);
	err = RTMP_ConnectStream(m_rtmp, 0);
	assert(err > 0);

	m_g_count++;
}
RtmpPublisher::RtmpPublisher(const char* url){
	if (m_g_count == 0){
		initSockets();
	}
	int err;
	unsigned int len = strlen(url);
	m_url = new char[len + 1];
	memcpy(m_url, url, len);
	m_url[len] = (char)0;
	m_rtmp = RTMP_Alloc();
	RTMP_Init(m_rtmp);

	err = RTMP_SetupURL(m_rtmp, m_url);
	assert(err > 0);
	RTMP_EnableWrite(m_rtmp);
	err = RTMP_Connect(m_rtmp, NULL);
	assert(err > 0);
	err = RTMP_ConnectStream(m_rtmp, 0);
	assert(err > 0);

	m_g_count++;
}

RtmpPublisher::~RtmpPublisher(){
	RTMP_Close(m_rtmp);
	RTMP_Free(m_rtmp);
	delete[] m_url;
	m_g_count--;
	if (m_g_count == 0){
		cleanupSockets();
	}
}

void RtmpPublisher::initSockets(){
#ifdef WIN32
	WORD version;
	WSADATA wsaData;
	version = MAKEWORD(1, 1);
	assert(WSAStartup(version, &wsaData) == 0);
#endif
}


void RtmpPublisher::cleanupSockets(){
#ifdef WIN32
	WSACleanup();
#endif
}

void RtmpPublisher::send(const unsigned char *buf, unsigned int len, int type, unsigned int timestamp){
	RTMPPacket pakt;
	RTMPPacket_Reset(&pakt);
	RTMPPacket_Alloc(&pakt, (int)len);

	pakt.m_packetType = type;
	pakt.m_nBodySize = len;
	pakt.m_nTimeStamp = timestamp;
	pakt.m_nChannel = 4;
	pakt.m_headerType = RTMP_PACKET_SIZE_LARGE;
	pakt.m_nInfoField2 = m_rtmp->m_stream_id;
	memcpy(pakt.m_body, buf, len);

	assert(RTMP_IsConnected(m_rtmp));
	RTMP_SendPacket(m_rtmp, &pakt, 0);
	RTMPPacket_Free(&pakt);

}



static inline char* put_sps_pps(char* ptr, x264_t* encoder){
	//unsigned char buf[BUF_SIZE];
	//bs_t bs;
	//unsigned short bs_len, bs_len_net;
	////sps
	//bs_init(&bs, buf, 16);
	//x264_sps_write(&bs, encoder->sps);
	//bs_len = (unsigned short) (bs.p - bs.p_start + 1);
	//bs_len_net = htons(bs_len);
	//memcpy(ptr,&bs_len_net, sizeof(unsigned short));
	//ptr += sizeof(unsigned short);
	//*ptr = 0x67;
	//ptr++;
	//memcpy(ptr, bs.p_start, bs_len - 1);
	//ptr += (bs_len - 1);
	//*ptr = 0x01;
	//ptr++;
	////pps
	//bs_init(&bs, buf, 16);
	//x264_pps_write(&bs, encoder->sps, encoder->pps);
	//bs_len = (unsigned short) (bs.p - bs.p_start + 1);
	//bs_len_net = htons(bs_len);
	//memcpy(ptr, &bs_len_net, sizeof(unsigned short));
	//ptr += sizeof(unsigned short);
	//*ptr = 0x68;
	//ptr++;
	//memcpy(ptr, bs.p_start, bs_len - 1);
	//ptr += (bs_len - 1);
	return ptr;
}

static inline char* put_headers(char* ptr, Encoder* encoder){
	encoder->getHeaders();
	assert(encoder->getNNal() >= 2);
	unsigned short sps_len, sps_len_net;
	*ptr = 0x01;//sps count
	ptr++;
	sps_len = encoder->getNal()->i_payload - 4;//always begin with 00 00 00 01
	sps_len_net = htons(sps_len);
	memcpy(ptr, &sps_len_net, sizeof(unsigned short));
	ptr += sizeof(unsigned short);
	memcpy(ptr, encoder->getNal()->p_payload + 4, sps_len);
	ptr += sps_len;

	unsigned short pps_len, pps_len_net;
	*ptr = 0x01;//pps count;
	ptr++;
	pps_len = encoder->getNal()->i_payload - 4;
	pps_len_net = htons(pps_len);
	memcpy(ptr, &pps_len_net, sizeof(unsigned short));
	ptr += sizeof(unsigned short);
	memcpy(ptr, (encoder->getNal() + 1)->p_payload + 4, pps_len);
	ptr += pps_len;

	return ptr;
}

void RtmpPublisher::prepare(Encoder * encoder, x264_param_t *param){
	RTMPPacket packet;
	char* amf_ptr;
	unsigned int amf_len;
	RTMPPacket_Reset(&packet);
	RTMPPacket_Alloc(&packet, AMF_BUF_SIZE);
	packet.m_nChannel = 0x04;
	packet.m_headerType = RTMP_PACKET_SIZE_LARGE;
	packet.m_nTimeStamp = 0;
	packet.m_nInfoField2 = m_rtmp->m_stream_id;
	packet.m_hasAbsTimestamp = 0;
	packet.m_packetType = RTMP_PACKET_TYPE_INFO;
	amf_ptr = packet.m_body;
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string(amf_ptr, "@setDataFrame" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string(amf_ptr, "onMetaData" );
	amf_ptr=put_byte(amf_ptr, AMF_OBJECT );
	amf_ptr=put_amf_string( amf_ptr, "author" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "" );
	amf_ptr=put_amf_string( amf_ptr, "copyright" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "" );
	amf_ptr=put_amf_string( amf_ptr, "description" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "" );
	amf_ptr=put_amf_string( amf_ptr, "keywords" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "" );
	amf_ptr=put_amf_string( amf_ptr, "rating" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "" );
	amf_ptr=put_amf_string( amf_ptr, "presetname" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "Custom" );
	amf_ptr=put_amf_string( amf_ptr, "width" );
	amf_ptr=put_amf_double( amf_ptr, (double)param->i_width);
	amf_ptr=put_amf_string( amf_ptr, "height" );
	amf_ptr=put_amf_double( amf_ptr, (double)param->i_height);
	amf_ptr=put_amf_string( amf_ptr, "framerate" );
	amf_ptr=put_amf_double( amf_ptr, (double)param->i_fps_num / param->i_fps_den);
	amf_ptr=put_amf_string( amf_ptr, "videocodecid" );
	amf_ptr=put_byte(amf_ptr, AMF_STRING );
	amf_ptr=put_amf_string( amf_ptr, "avc1" );
	amf_ptr=put_amf_string( amf_ptr, "videodatarate" );
	amf_ptr=put_amf_double( amf_ptr, (double)param->rc.i_bitrate ); 
	amf_ptr=put_amf_string( amf_ptr, "avclevel" );
	amf_ptr=put_amf_double( amf_ptr, (double)param->i_level_idc ); 
	amf_ptr=put_amf_string( amf_ptr, "avcprofile" );
	amf_ptr=put_amf_double( amf_ptr, 0x42 ); 
	amf_ptr=put_amf_string( amf_ptr, "videokeyframe_frequency" );
	amf_ptr=put_amf_double( amf_ptr, 3 ); 
	amf_ptr=put_amf_string( amf_ptr, "" );
	amf_ptr=put_byte( amf_ptr, AMF_OBJECT_END );
	amf_len = (unsigned int)(amf_ptr - packet.m_body);
	packet.m_nBodySize = amf_len;
	assert(RTMP_IsConnected(this->m_rtmp));
	assert(RTMP_SendPacket(this->m_rtmp, &packet, 0));
	RTMPPacket_Free(&packet);


	//send sps pps
	RTMPPacket_Reset(&packet);
	RTMPPacket_Alloc(&packet, BUF_SIZE);
	packet.m_nChannel = 0x04;
	packet.m_headerType = RTMP_PACKET_SIZE_LARGE;
	packet.m_nTimeStamp = 0;
	packet.m_nInfoField2 = m_rtmp->m_stream_id;
	packet.m_hasAbsTimestamp = 0;
	packet.m_packetType = RTMP_PACKET_TYPE_VIDEO;
	amf_ptr = packet.m_body;
	packet.m_body[0] = (char)0x17;
	packet.m_body[1] = (char)0x00;
	packet.m_body[2] = (char)0x00;
	packet.m_body[3] = (char)0x00;
	packet.m_body[4] = (char)0x00;
	packet.m_body[5] = (char)0x01;
	packet.m_body[6] = (char)0x42;
	packet.m_body[7] = (char)0xC0;
	packet.m_body[8] = (char)0x15;
	packet.m_body[9] = (char)0x03;
	amf_ptr = packet.m_body + 10;


	amf_ptr = put_headers(amf_ptr, encoder);


	/*printf("num of nal = %d\n",  encoder->getNNal());
	for (int i = 0; i < encoder->getNNal(); ++i){
	int len = (encoder->getNal() + i)->i_payload;
	unsigned char* buf = (encoder->getNal() + i)->p_payload;
	printf("nal %d, size = %lu\n", i, (encoder->getNal() + i)->i_payload);
	int size = 100 < len? 100: len;
	int j;
	for (j = 0; j < size; ++j){
	printf("%02X ", *(buf + j));
	}
	printf("\n");
	}*/
	amf_len = (unsigned int)(amf_ptr - packet.m_body);
	packet.m_nBodySize = amf_len;


 	assert(RTMP_IsConnected(this->m_rtmp));
	RTMP_SendPacket(this->m_rtmp, &packet, 0);

	m_last_timestamp = GetTickCount();
	RTMPPacket_Free(&packet);
}	

static inline int nal_start_pos(unsigned char * buf){
	assert(buf[0] == 0x00 && buf[1] == 0x00);
	if (buf[2] == 0x00 && buf[3] == 0x01){
		return 4;
	}else if (buf[2] == 0x01){
		return 3;
	}else{
		int j;
		for (j = 0; j < 5; ++j){
			printf("%02X ", *(buf + j));
		}
		printf("\n");
		assert(0);
		return 0;
	}
}

void RtmpPublisher::sendFrame(Encoder *encoder){
	RTMPPacket packet;
	x264_nal_t* nal = encoder->getNal();
	int nnal = encoder->getNNal();
	int total_len = 0;
	char* ptr;
	int* start_pos = new int[nnal];
	for (int i = 0; i < nnal; ++i){
		x264_nal_t *cur = nal + i;
		start_pos[i] = nal_start_pos(cur->p_payload);
		total_len += (cur->i_payload - start_pos[i] + 4);//4 bytes for size
	}
	total_len += 5;
	RTMPPacket_Reset(&packet);
	RTMPPacket_Alloc(&packet, total_len);
	packet.m_nChannel = 0x04;
	packet.m_headerType = RTMP_PACKET_SIZE_LARGE;
	packet.m_nInfoField2 = m_rtmp->m_stream_id;
	packet.m_hasAbsTimestamp = 0;
	packet.m_packetType = RTMP_PACKET_TYPE_VIDEO;
	ptr = packet.m_body;
	if (nnal == 1){
		ptr[0] = 0x27;
	}else{
		ptr[0] = 0x17;//0x17 i frame, 0x27 p frame
	}
	ptr[1] = 0x01;// AVC NALU
	ptr[2] = 0x00;
	ptr[3] = 0x00;
	ptr[4] = 0x00;
	ptr += 5;
	for (int i = 0; i < nnal; ++i){
		x264_nal_t *cur = nal + i;
		ptr = put_be32(ptr, cur->i_payload - start_pos[i]);
		memcpy(ptr, cur->p_payload + start_pos[i], cur->i_payload - start_pos[i]);
		ptr += (cur->i_payload - start_pos[i]);
	}
	packet.m_nBodySize = (unsigned int)total_len;
	packet.m_nTimeStamp = getTimestamp();

	assert(RTMP_IsConnected(m_rtmp));
	RTMP_SendPacket(m_rtmp, &packet, 0);
	delete[] start_pos;
	RTMPPacket_Free(&packet);


}