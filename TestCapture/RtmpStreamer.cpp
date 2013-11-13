#include "RtmpStreamer.h"
#include <cstring>
#include <cassert>

#ifdef WIN32
#include <WinSock.h>
#pragma comment(lib,"WS2_32.lib")
#pragma comment(lib,"winmm.lib")
#endif

#pragma comment(lib, "librtmp.lib")

int RtmpStreamer::m_g_count = 0;

RtmpStreamer::RtmpStreamer(const char* url){
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
	/*err = RTMP_ConnectStream(m_rtmp, 0);
	assert(err > 0);*/

	m_g_count++;
}

RtmpStreamer::~RtmpStreamer(){
	RTMP_Close(m_rtmp);
	RTMP_Free(m_rtmp);
	delete[] m_url;
	m_g_count--;
	if (m_g_count == 0){
		cleanupSockets();
	}
}

void RtmpStreamer::initSockets(){
#ifdef WIN32
	WORD version;
	WSADATA wsaData;
	version = MAKEWORD(1, 1);
	assert(WSAStartup(version, &wsaData) == 0);
#endif
}


void RtmpStreamer::cleanupSockets(){
#ifdef WIN32
	WSACleanup();
#endif
}

void RtmpStreamer::send(const unsigned char *buf, unsigned int len, int type, unsigned int timestamp){
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
	RTMP_SendPacket(m_rtmp, &pakt, 0);
	RTMPPacket_Free(&pakt);

}