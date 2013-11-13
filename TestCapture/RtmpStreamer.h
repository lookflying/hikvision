#ifndef RTMPSTREAMER_H
#define RTMPSTREAMER_H
#include "rtmp.h"

class RtmpStreamer{
public:
	RtmpStreamer(const char* url);
	~RtmpStreamer();
	void send(const unsigned char* buf, unsigned int len, int type, unsigned int timestamp);
private:
	static void initSockets();
	static void cleanupSockets();
	static int m_g_count;
	RTMP* m_rtmp;
	char* m_url;

};



#endif