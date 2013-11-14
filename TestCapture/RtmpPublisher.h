#ifndef RTMPPUBLISHER_H
#define RTMPPUBLISHER_H


#ifdef __cplusplus
extern "C"{
#endif
#include "rtmp.h"
#include "x264.h"
#ifdef __cplusplus
};
#endif
#include "Encoder.h"
#include <Windows.h>
#define AMF_BUF_SIZE	(1024*32)
#define BUF_SIZE	(1024*32)

#define HEX2BIN(a)      (((a)&0x40)?((a)&0xf)+9:((a)&0xf))
int hex2bin(char *str, char **hex);
char * put_byte( char *output, uint8_t nVal );
char * put_be16(char *output, uint16_t nVal );
char * put_be24(char *output,uint32_t nVal );
char * put_be32(char *output, uint32_t nVal );
char * put_be64( char *output, uint64_t nVal );
char * put_amf_string( char *c, const char *str );
char * put_amf_double( char *c, double d );

class RtmpPublisher{
public:
	RtmpPublisher(RTMP * rtmp, const char* url);
	RtmpPublisher(const char* url);
	~RtmpPublisher();
	void send(const unsigned char* buf, unsigned int len, int type, unsigned int timestamp);
	void prepare(Encoder * encoder, x264_param_t * param);
	void sendFrame(Encoder * encoder);
	unsigned int getTimestamp(){
		unsigned long timestamp = m_last_timestamp;
		m_last_timestamp = GetTickCount();
		return  (unsigned int) m_last_timestamp - timestamp;
	}
	//unsigned char * getAmfBuf(){
	//	return m_amf;
	//}
	//unsigned int getAmfLen(){
	//	return m_amf_len;
	//}
private:
	static void initSockets();
	static void cleanupSockets();
	static int m_g_count;
	RTMP* m_rtmp;
	RTMP m_rtmp_real;
	char* m_url;
	//unsigned char m_amf[AMF_BUF_SIZE];
	//unsigned int m_amf_len;
	//RTMPPacket m_packet;
	
	unsigned long m_last_timestamp;
};



#endif