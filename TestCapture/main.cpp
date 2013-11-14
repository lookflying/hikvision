#include <cstdio>
#include <cassert>
#include <time.h>
#include <Windows.h>
#include "EncodedStream.h"
#include "RtmpPublisher.h"
#define MAX_CHANNELS 64
HANDLE ChannelHandle[MAX_CHANNELS];
#define WIDTH 704
#define HEIGHT 576
#define FILE_NAME_MAX_LEN	256

time_t timestamp = time(0);
RtmpPublisher* rtmp_publisher;
void resetTimestamp(){
	timestamp = time(0);
}
int getTimestamp(){
	return static_cast<int>(timestamp);
}
void writeStream(int channel_id, unsigned char* buf, unsigned int len, int timestamp){
	static FILE * h264_file;
	char name[FILE_NAME_MAX_LEN];
	sprintf_s(name, "channel%d_%d.264", channel_id, getTimestamp());
	h264_file = fopen(name, "ab");
	assert(h264_file != NULL);
	fwrite(buf, 1, len, h264_file);
	fclose(h264_file);
}
void writeYUV(int channel_id, unsigned char* buf, unsigned int len, int timestamp){
	static FILE * yuv_file;
	char name[FILE_NAME_MAX_LEN];
	sprintf_s(name, "channel%d_%d.yuv", channel_id, getTimestamp());
	fopen_s(&yuv_file, name, "ab");
	assert(yuv_file != NULL);
	fwrite(buf, 1, len, yuv_file);
	fclose(yuv_file);
}

int streamHandler(ULONG channel_id,void *buf,DWORD len,int frame_type,void *context){
	printf("channel %d:\tframe_type = %d, len=%ld\n", channel_id, frame_type, (long)len); 
	if (frame_type == 128){
		unsigned int i;
		for (i = 0; i < len; ++i){
			printf("%02X ", (unsigned char)*(((char*)buf) + i));
		}
		printf("\n");
	}
	return 0;
}

int streamHandlerExt(ULONG channel_id, void* context){
	static int count = 0;
	assert(count == 0);
	++count;
	printf("%d handler now!", count);
	DWORD len = 1024*1024;
	unsigned char* buf = (unsigned char*)malloc(len);
	int frame_type = 1;
	int ret;
	//CaptureIFrame(EncodedStream::getStream(channel_id)->getHandle());
	ret = ReadStreamData(EncodedStream::getStream(channel_id)->getHandle(), buf, &len, &frame_type);
	if (ret == 0 || ret == 1){
		printf("channel %d:\tframe_type = %d, len=%ld\n", channel_id, frame_type, (long)len); 
		/*if (frame_type == 128){
		int i;
		for (i = 0; i < len; ++i){
		printf("%02X ", (unsigned char)*(((char*)buf) + i));
		}
		printf("\n");
		}else{
		int size = 100 < len? 100: len;
		int i;
		for (i = 0; i < size; ++i){
		printf("%02X ", (unsigned char)*(((char*)buf) + i));
		}
		printf("\n");
		}*/
		writeStream(0, buf, len, getTimestamp());
	}
	else{
		printf("return error, error code = %X\n", ret);
	}
	free(buf);
	--count;
	return 0;

}

void oriStreamHandler(UINT channel_id, void* context){
	static int count = 0;
	assert(count == 0);
	++count;
	printf("writing to yuv...");
	//writeYUV(channel_id, 
	//	EncodedStream::getStream(channel_id)->getYuvBuf(),
	//	EncodedStream::getStream(channel_id)->getYuvBufSize(),
	//	getTimestamp());
	printf("encoding...");
	EncodedStream::getStream(channel_id)->getEncoder()->encode(EncodedStream::getStream(channel_id)->getYuvBuf());
	x264_nal_t* nal = EncodedStream::getStream(channel_id)->getEncoder()->getNal();
	printf("wring stream...");
	unsigned int len = 0;
	for (x264_nal_t* cur = nal; cur < nal + EncodedStream::getStream(channel_id)->getEncoder()->getNNal(); cur++){
		len += cur->i_payload;
		writeStream(channel_id, cur->p_payload, cur->i_payload, getTimestamp());
		//rtmp_publisher->send(cur->p_payload, cur->i_payload, RTMP_PACKET_TYPE_VIDEO, EncodedStream::getStream(channel_id)->getTimeStamp());
	}
	printf("sending stream...");
	rtmp_publisher->sendFrame(EncodedStream::getStream(channel_id)->getEncoder());
	printf("\n");

	
	--count;
}

int main(int argc, char** argv){
	resetTimestamp();
	
	EncodedStream::setOriHandler(oriStreamHandler);
	//EncodedStream::setHandler(streamHandler);
	//EncodedStream::setHandlerExt(streamHandlerExt);
	EncodedStream stream(3);
	//RTMP * rtmp = RTMP_Alloc();

	//RtmpPublisher publisher
	
	//rtmp_publisher = new RtmpPublisher(rtmp, "rtmp://127.0.0.1/oflaDemo/test");
	rtmp_publisher = new RtmpPublisher("rtmp://127.0.0.1/oflaDemo/test");
	rtmp_publisher->prepare(EncodedStream::getStream(3)->getEncoder(), EncodedStream::getStream(3)->getEncoder()->getParam());
	//x264_nal_t* nal = EncodedStream::getStream(3)->getEncoder()->getNal();
	//unsigned int len = 0;
	//for (x264_nal_t* cur = nal; cur < nal + EncodedStream::getStream(3)->getEncoder()->getNNal(); cur++){
	//	writeStream(3, cur->p_payload, cur->i_payload, getTimestamp());
	//	//rtmp_publisher->send(cur->p_payload, cur->i_payload, RTMP_PACKET_TYPE_VIDEO, EncodedStream::getStream(channel_id)->getTimeStamp());
	//}
	stream.start();
	printf("start capture\n");
	getchar();
	printf("stop capture\n");
	stream.stop();
	Sleep(10);
	delete rtmp_publisher;
	return 0;
}

