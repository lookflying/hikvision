#include "Encoder.h"

Encoder::Encoder(int width, int height, int fps, int threads){
	x264_param_t param;
	m_width = width;
	m_height = height;
	m_fps = fps;
	m_threads = threads;
	x264_param_default_preset(&param, "veryfast", "zerolatency");
	param.i_threads = m_threads;
	param.i_width = m_width; 
	param.i_height = m_height;
	param.i_fps_num = fps;
	param.i_fps_den = 1;
	param.i_keyint_max = 25;
	param.b_intra_refresh = 1;
	param.b_annexb = 1;
	x264_param_apply_profile(&param, "baseline");
	m_encoder = x264_encoder_open(&param);
}

Encoder::~Encoder(){
	x264_encoder_close(m_encoder);

}

void Encoder::encode(unsigned char *yuv_buf){
	x264_picture_t pic_in, pic_out;
	x264_picture_alloc(&pic_in,  X264_CSP_I420, m_width, m_height);
	pic_in.img.plane[0] = yuv_buf;
	pic_in.img.plane[1] = pic_in.img.plane[0] + m_width * m_height;
	pic_in.img.plane[2] = pic_in.img.plane[1] + m_width * m_height / 4;
	x264_encoder_encode(m_encoder, &m_nals, &m_nnal, &pic_in, &pic_out);
}