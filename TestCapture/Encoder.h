#ifndef ENCODER_H
#define ENCODER_H
#ifdef __cplusplus
extern "C"{
#include "x264.h"
};
#endif

class Encoder{
public:
	Encoder(int width, int height, int fps, int threads = 1);
	~Encoder();
	void encode(unsigned char* yuv_buf);
	void getHeaders();
	x264_nal_t *getNal(){
		return m_nals;
	}
	int getNNal(){
		return m_nnal;
	}
	int getWidth(){
		return m_width;
	}
	int getHeight(){
		return m_height;
	}
	int getFps(){
		return m_fps;
	}
	x264_param_t* getParam(){
		return &m_param;
	}

	x264_t * getRealEncoder(){
		return m_encoder;
	}
private:
	x264_t *m_encoder;
	int m_width, m_height;
	int m_fps;
	int m_threads;
	x264_nal_t *m_nals;
	int m_nnal;
	x264_param_t m_param;
	


 

};

#endif
