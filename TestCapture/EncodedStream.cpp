#include "EncodedStream.h"
#include <ctime>


bool EncodedStream::m_g_dsp_opened = false;
int EncodedStream::m_g_count = 0;
int EncodedStream::m_g_channel_count = 0;
std::map<int, EncodedStream*> EncodedStream::m_g_channel_map;
IMAGE_STREAM_CALLBACK EncodedStream::m_g_real_ori_handler = NULL;
STREAM_DIRECT_READ_CALLBACK EncodedStream::m_g_real_handler = NULL;
STREAM_READ_CALLBACK EncodedStream::m_g_real_handler_ext = NULL;
EncodedStream::EncodedStream(int id){
	m_channel_id = -1;
	m_yuv_buf = NULL;
	m_encoder = NULL;
	m_stream_writer = NULL;
	if (!m_g_dsp_opened){
		openDSP();
	}
	if (id < m_g_channel_count){
		m_channel_id = id;
		m_channel_handle = ChannelOpen(m_channel_id);		
		m_g_count++;
		m_g_channel_map[m_channel_id] = this;
		m_encoder = new Encoder(WIDTH, HEIGHT, FPS, 4);
		m_stream_writer = new StreamWriter(m_channel_id, time(0));
	}
}
EncodedStream::~EncodedStream(){
	ChannelClose(m_channel_handle);
	m_g_count--;
	m_g_channel_map.erase(m_channel_id);
	if (m_yuv_buf != NULL){
		delete[] m_yuv_buf;
	}
	if (m_encoder != NULL){
		delete m_encoder;
	}
	if (m_stream_writer != NULL){
		delete m_stream_writer;
	}
	if (m_g_count == 0){
		closeDSP();
	}
	
}

void EncodedStream::openDSP(){
	SetDefaultVideoStandard(StandardPAL); //no need default PAL
	m_g_channel_count = InitDSPs();
	RegisterImageStreamCallback(EncodedStream::interOriHandler, NULL);
	RegisterStreamDirectReadCallback(EncodedStream::internalHandler, NULL);
	RegisterStreamReadCallback(EncodedStream::internalHandlerExt, NULL);
	m_g_count = 0;
	m_g_dsp_opened = true;
}

void EncodedStream::closeDSP(){
	DeInitDSPs();
	m_g_dsp_opened = false;
}

void EncodedStream::start(){
	if (m_channel_id >= 0){
		if (m_g_real_handler != NULL || m_g_real_handler_ext != NULL){
			SetStreamPackType(m_channel_handle, 3);//2:hikvision pack, 3:ps pack
			SetEncoderPictureFormat(m_channel_handle, ENC_DCIF_FORMAT);
			SetStreamType(m_channel_handle, STREAM_TYPE_VIDEO);
			SetDefaultQuant(m_channel_handle, 18, 18, 23);//use the default, the less the better (range:12-30)
			SetIBPMode(m_channel_handle, 100, 2, 0, FPS);//the last is framerate
			SetupBitrateControl(m_channel_handle, 2000000);//unit:bps
			SetBitrateControlMode(m_channel_handle, brCBR);//use cbr, or brVBR
			StartVideoCapture(m_channel_handle);
		}else if (m_g_real_ori_handler != NULL){
			m_yuv_buf_size = WIDTH * HEIGHT * 3 / 2; 
			m_yuv_buf = new unsigned char[m_yuv_buf_size];
			SetImageStream(m_channel_handle, true, 25, WIDTH, HEIGHT, m_yuv_buf);
		}
	}

}

void EncodedStream::stop(){
	if (m_channel_id >= 0){
		StopVideoCapture(m_channel_handle);
		SetImageStream(m_channel_handle, false, 25, WIDTH, HEIGHT, NULL);
	}

}
