#include "Encoder.h"

Encoder::Encoder(int width, int height, int fps, int threads){
	m_width = width;
	m_height = height;
	m_fps = fps;
	m_threads = threads;
	x264_param_default_preset(&m_param, "fast", "zerolatency");
	m_param.i_threads = m_threads;
	m_param.i_width = m_width; 
	m_param.i_height = m_height;
	m_param.i_fps_num = fps;
	m_param.i_fps_den = 1;
	m_param.i_keyint_max = 25;
	m_param.b_intra_refresh = 1;
	m_param.b_annexb = 1;
	x264_param_apply_profile(&m_param, "high");
	m_param.rc.f_rf_constant = 4; 
	m_param.rc.f_rf_constant_max = 8;
	m_param.rc.i_rc_method = X264_RC_ABR;
	m_param.rc.i_vbv_max_bitrate = 24000;
	m_param.rc.i_bitrate = 15000;
	m_param.b_repeat_headers = 1;
	m_encoder = x264_encoder_open(&m_param);
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

void Encoder::getHeaders(){
	x264_encoder_headers(m_encoder, &m_nals, &m_nnal);
}