#include <cstdio>
#include <cassert>
#include <Windows.h>

#define FILE_NAME_MAX_LEN	256
#define PIPE_BUF	(1024*1024*3)

class StreamWriter{
public:
	StreamWriter(int channel_id, long timestamp){
		m_channel_id = channel_id;
		m_timestamp = timestamp;
		char name[FILE_NAME_MAX_LEN];
		sprintf_s(name, "channel%d_%ld.264", m_channel_id, m_timestamp);
		m_264_file = fopen(name, "ab");
		assert(m_264_file != NULL);
		sprintf_s(name, "channel%d_%ld.yuv", m_channel_id, m_timestamp);
		m_yuv_file = fopen(name, "ab");
		assert(m_yuv_file != NULL);
		m_pipe_264 = INVALID_HANDLE_VALUE;
		m_pipe_yuv = INVALID_HANDLE_VALUE;

	}
	~StreamWriter(){
		if (m_264_file != NULL){
			fclose(m_264_file);
		}
		if (m_yuv_file != NULL){
			fclose(m_yuv_file);
		}
		if (m_pipe_264 != INVALID_HANDLE_VALUE){
			CloseHandle(m_pipe_264);
		}
		if (m_pipe_yuv != INVALID_HANDLE_VALUE){
			CloseHandle(m_pipe_yuv);
		}
	}

	void writeYuv(unsigned char* buf, unsigned int len){
		if (m_yuv_file != NULL){
			fwrite(buf, 1, len, m_yuv_file);	
		}
	}

	void write264(unsigned char* buf, unsigned int len){
		if (m_264_file != NULL){
			fwrite(buf, 1, len, m_264_file);
		}
	}

	void writePipe264(unsigned char* buf, unsigned int len){
		if (m_pipe_264 == INVALID_HANDLE_VALUE){
			wchar_t name[FILE_NAME_MAX_LEN];
			wsprintf(name, TEXT("\\\\.\\Pipe\\channel%d.264"), m_channel_id);
			m_pipe_264 = CreateNamedPipe(name, 
				PIPE_ACCESS_DUPLEX | WRITE_DAC, // OpenMode
				PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, // PipeMode
				PIPE_UNLIMITED_INSTANCES, // MaxInstances
				PIPE_BUF, // OutBufferSize
				PIPE_BUF, // InBuffersize
				2000, // TimeOut
				NULL); // Security
			if (m_pipe_264 == INVALID_HANDLE_VALUE) 
			{
				assert(0); 

			}
			if (!ConnectNamedPipe(m_pipe_264, NULL)){
				assert(0);
			}
		}
		DWORD written;
		if (!WriteFile(m_pipe_264, buf, len, &written , NULL)){
			assert(written == len);
			assert(0);
		}	

	}
	void writePipeYuv(unsigned char* buf, unsigned int len){
		if (m_pipe_yuv == INVALID_HANDLE_VALUE){
			wchar_t name[FILE_NAME_MAX_LEN];
			wsprintf(name, TEXT("\\\\.\\Pipe\\channel%d.yuv"), m_channel_id);
			m_pipe_yuv = CreateNamedPipe(name, 
				PIPE_ACCESS_DUPLEX | WRITE_DAC, // OpenMode
				PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT, // PipeMode
				PIPE_UNLIMITED_INSTANCES, // MaxInstances
				PIPE_BUF, // OutBufferSize
				PIPE_BUF, // InBuffersize
				2000, // TimeOut
				NULL); // Security
			if (m_pipe_yuv == INVALID_HANDLE_VALUE) 
			{
				assert(0); 

			}
			if (!ConnectNamedPipe(m_pipe_yuv, NULL)){
				assert(0);
			}
		}
		DWORD written;
		if (!WriteFile(m_pipe_yuv, buf, len, &written , NULL)){
			assert(0);
		}	

	}

private:
	int m_channel_id;
	FILE* m_264_file;
	FILE* m_yuv_file;
	HANDLE m_pipe_264;
	HANDLE m_pipe_yuv;
	long m_timestamp;

};