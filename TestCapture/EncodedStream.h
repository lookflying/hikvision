#ifndef ENCODEDSTREAM_H
#define ENCODEDSTREAM_H
#include "HikVisionSdk.h"
#include <Windows.h>
#include <cassert>
#include <map>
#include "Encoder.h"
#include "StreamWriter.h"
#define WIDTH 704
#define HEIGHT 576
#define FPS	25

class EncodedStream{
public:
	EncodedStream(int id);
	~EncodedStream();

	static void interOriHandler(UINT channel_id, void* context){
		if (m_g_real_ori_handler != NULL){
			m_g_real_ori_handler(channel_id, context);
		}
	}

	static int internalHandler(ULONG channel_id,void *buf,DWORD len,int frame_type,void *context){
		if (m_g_real_handler != NULL){
			return m_g_real_handler(channel_id, buf, len,frame_type, context);
		}else
			return 0;
	}

	static int internalHandlerExt(ULONG channel_id, void * context){
		if (m_g_real_handler_ext != NULL){
			return m_g_real_handler_ext(channel_id,context);
		}else
			return 0;
	}
	static EncodedStream* getStream(int id){
		if (m_g_channel_map.find(id) != m_g_channel_map.end()){
			return m_g_channel_map[id];
		}else{
			return NULL;
		}
	}

	static void setOriHandler(IMAGE_STREAM_CALLBACK handler){
		m_g_real_ori_handler = handler;
	}

	static void setHandler(STREAM_DIRECT_READ_CALLBACK handler){
		m_g_real_handler = handler;
	}

	static void setHandlerExt(STREAM_READ_CALLBACK handler){
		m_g_real_handler_ext = handler;
	}

	void start();
	void stop();
	HANDLE getHandle(){
		return m_channel_handle;
	}

	unsigned char* getYuvBuf(){
		return m_yuv_buf;
	}

	unsigned int getYuvBufSize(){
		return m_yuv_buf_size;
	}

	Encoder* getEncoder(){
		return m_encoder;
	}

	void write264(unsigned char* buf, unsigned int len){
		if (m_stream_writer != NULL){
			m_stream_writer->write264(buf, len);
		}
	}

	void writeYuv(unsigned char* buf, unsigned int len){
		if (m_stream_writer != NULL){
			m_stream_writer->writeYuv(buf, len);
		}
	}

	void writePipe264(unsigned char *buf, unsigned int len){
		if (m_stream_writer != NULL){
			m_stream_writer->writePipe264(buf, len);
		}
	}

	void writePipeYuv(unsigned char *buf, unsigned int len){
		if (m_stream_writer != NULL){
			m_stream_writer->writePipeYuv(buf, len);
		}
	}


private:
	HANDLE m_channel_handle;
	int m_channel_id;
	unsigned char* m_yuv_buf;
	unsigned int m_yuv_buf_size;
	Encoder *m_encoder;
	StreamWriter *m_stream_writer;

	static bool m_g_dsp_opened;
	static int m_g_count;
	static int m_g_channel_count;
	static std::map<int, EncodedStream*> m_g_channel_map; 
	static void openDSP();
	static void closeDSP();
	static IMAGE_STREAM_CALLBACK m_g_real_ori_handler;
	static STREAM_DIRECT_READ_CALLBACK m_g_real_handler;
	static STREAM_READ_CALLBACK m_g_real_handler_ext;

};

#endif