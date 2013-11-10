///////////////////////////////////////////////////////////////////////////
// HIKVISION DS-4xxx/iDS-4xxx/DS-5xxx series SYSTEM SDK					 //	
// Copyright (c) 2004-2010 Hangzhou Hikvision digtial technology co,. ltd//
/////////////////////////////////////////////////////////////////////////// 

#ifndef HIKVISION_SDK_H
#define HIKVISION_SDK_H

#include "datatype.h"

#define DLLEXPORT_API  extern "C"__declspec(dllexport) 
#define ERR_WAIT_TIMEOUT					0xc0000001
#define ERR_INVALID_HANDLE					0xc0000002
#define ERR_INVALID_ARGUMENT				0xc0000003
#define ERR_DDRAW_CREATE_FAILED				0xc0000004
#define ERR_DDRAW_CAPS_FAULT				0xc0000005
#define ERR_SET_COOPERATIVELEVEL_FAILED		0xc0000006
#define ERR_PRIMARY_SURFACE_CREATE_FAILED	0xc0000007
#define ERR_GET_OVERLAY_ADDRESS_FAILED		0xc0000008
#define ERR_OVERLAY_SURFACE_CREATE_FAILED	0xc0000009
#define ERR_OVERLAY_UPDATE_FAILED			0xc000000a
#define ERR_TMMAN_FAILURE					0xc000000b
#define ERR_CHANNELMAGIC_MISMATCH			0xc000000c
#define ERR_CALLBACK_REGISTERED				0xc000000d
#define ERR_QUEUE_OVERFLOW					0xc000000e
#define ERR_STREAM_THREAD_FAILURE			0xc000000f
#define ERR_THREAD_STOP_ERROR				0xc0000010
#define ERR_NOT_SUPPORT						0xc0000011
#define ERR_OUTOF_MEMORY					0xc0000012
#define ERR_DSP_BUSY						0xc0000013
#define ERR_DATA_ERROR						0xc0000014
#define ERR_KERNEL							0xc0000016
#define ERR_OFFSCREEN_CREATE_FAILED			0xc0000017
#define ERR_MULTICLOCK_FAILURE				0xc0000018
#define ERR_INVALID_DEVICE					0xc0000019
#define ERR_INVALID_DRIVER					0xc000001a
#define ERR_OFFSCREEN_BLT_FAILED			0xc000001b
#define ERR_ORDER               			0xc000001c
#define ERR_DDRAW_NONE               		0xc000001d
#define ERR_DDRAW7_UNSUPPORT               	0xc000001e
#define ERR_GLOBAL_OVE_FAILED               0xc000001f
#define ERR_DDRAW_GENERAL                   0xc0000020
//error code for MD card
#define HWERR_SUCCESS							0
#define HWERR_ALLOCATE_MEMORY					0xc1000001
#define HWERR_INVALID_HANDLE					0xc1000002
#define HWERR_DDRAW_CREATE_FAILED				0xc1000003
#define HWERR_DDRAW_CAPS_FAULT					0xc1000004
#define HWERR_SET_COOPERATIVELEVEL_FAILED		0xc1000005
#define HWERR_PRIMARY_SURFACE_CREATE_FAILED		0xc1000006
#define HWERR_OVERLAY_CREATE_FAILED				0xc1000007
#define HWERR_GET_OVERLAY_ADDRESS_FAILED		0xc1000008
#define HWERR_OVERLAY_UPDATE_FAILED				0xc1000009
#define HWERR_SURFACE_NULL						0xc100000a
#define HWERR_FILEHEADER_UNKNOWN				0xc100000b
#define HWERR_CREATE_FILE_FAILED				0xc100000c
#define HWERR_FILE_SIZE_ZERO					0xc100000d
#define HWERR_FILE_SIZE_INVALID					0xc100000e
#define HWERR_CREATE_OBJ_FAILED					0xc100000f
#define HWERR_CHANNELMAGIC_MISMATCH				0xc1000010
#define HWERR_PARA_OVER							0xc1000011
#define HWERR_ORDER								0xc1000012
#define HWERR_COMMAND							0xc1000013
#define HWERR_UNSUPPORTED						0xc1000014
#define HWERR_DSPOPEN							0xc1000015
#define HWERR_DSPLOAD							0xc1000016
#define HWERR_ALLOCATE_DSPMEMORY				0xc1000017
#define HWERR_DSPCHECHER						0xc1000018
#define HWERR_IMGFILE_UNKNOWN					0xc1000019
#define HWERR_INVALID_FILE						0xc100001a
#define HWERR_OFFSCREEN_CREATE_FAILED			0xc100001b
#define HWERR_OFFSCREEN_BLT_FAILED			    0xc100001c
#define HWERR_DDRAW_NONE               			0xc100001d
#define HWERR_DDRAW7_UNSUPPORT               	0xc100001e
#define HWERR_GLOBAL_OVE_FAILED                 0xc100001f
#define HWERR_DDRAW_GENERAL                     0xc1000020
//standart
#define HW_PAL									2
#define HW_NTSC									1
//jump direction
#define HW_JUMP_FORWARD							309 
#define HW_JUMP_BACKWARD						310


typedef enum  {
   vdfRGB8A_233              = 0x00000001,
   vdfRGB8R_332              = 0x00000002,
   vdfRGB15Alpha             = 0x00000004,
   vdfRGB16                  = 0x00000008,
   vdfRGB24                  = 0x00000010,
   vdfRGB24Alpha             = 0x00000020,
   
   vdfYUV420Planar           = 0x00000040,
   vdfYUV422Planar           = 0x00000080,
   vdfYUV411Planar           = 0x00000100,
   vdfYUV420Interspersed     = 0x00000200,
   vdfYUV422Interspersed     = 0x00000400,
   vdfYUV411Interspersed     = 0x00000800,
   vdfYUV422Sequence         = 0x00001000,   /* U0, Y0, V0, Y1:  For VO overlay */
   vdfYUV422SequenceAlpha    = 0x00002000,   
   /* U0, Y0, V0, Y1:  For VO overlay, with low bit for alpha blending */
   vdfMono                   = 0x00004000,  /* 8 bit monochrome */

   vdfYUV444Planar           = 0x00008000,
}TypeVideoFormat;


typedef enum {
	brCBR = 0,
	brVBR = 1,
}BitrateControlType_t;
typedef enum {
	DS4004HC			=2,		//4004HC
	DS4008HC			=3,		//4008HC
	DS4016HC			=4,		//4016HC
	DS4001HF			=5,		//4001HF
	DS4004HF			=6,		//4004HF
	DS4002MD			=7,		//4002MD
	DS4004MD			=8,		//4004MD
	DS4016HCS			=9,		//4016HCS
	DS4004HC_PLUS		=13,	//4004HC+
	DS4008HC_PLUS		=14,	//4008HC+
	DS4016HC_PLUS		=15,	//4016HC+
	DS4008HF			=16,	//4008HF
	DS4008MD			=17,	//4008MD
	DS4008HS			=18,	//4008HS
	DS4016HS			=19,	//4016HS

	DS4108HCV			=20,	//4108HCV
	DS4116HCV			=21,	//4116HCV
	DS5016HC			=22,    //5016HC

	DS4208HFV			=23,    //4208HFV
	DS4216HC			=24,    //4216HC
	DS4216HFV			=25,    //4216HFV

	DS5008HF			=26,    //5008HF
	DS5116HF			=27,    //5116HF
                                                                   
	DS5216HC			=28,	//5216HC
	DS5208HF			=29,	//5208HF
	DS5216HF			=30,	//5216HF

	DS4101HD			=31,	//4101HD
	DS4102HD			=32,	//4102HD
	DS4104HD			=33,	//4104HD

	DS4002MD_PLUS       =34,    //4002MD+  
	DS4004MD_PLUS       =35,    //4004MD+

	DS4204HFV			=36,	//4204HFV
	DS4308HCV			=37,    //4308HCV
	DS4308HFV			=38,    //4308HFV
	DS4316HCV			=39,    //4316HCV
	DS4316HFV			=40,    //4316HFV
	DS4304HD			=41,    //4304HD
	DS4304HFH           =42,    //4304HFH
	DS4304HFV           =43,    //4304HFV
	DS4302HFH           =44,    //4302HFH
	DS5316HF            =45,    //5316HF
	DS4308HW            =46,    //4308HW
	DS4316HW            =47,    //4316HW
	DS4308MD            =48,    //4308MD
	INVALID_BOARD_TYPE	=0xffffffff,
}BOARD_TYPE_DS;

#define STREAM_TYPE_VIDEO	1
#define STREAM_TYPE_AUDIO	2
#define STREAM_TYPE_AVSYNC	3

#define STREAM_PACK_TYPE_NONE		1
#define STREAM_PACK_TYPE_HIKVISION	2
#define STREAM_PACK_TYPE_PS	3
#define STREAM_PACK_TYPE_TS	4
#define STREAM_PACK_TYPE_RTP	5

#define AUDIO_TYPE_G722_1   1
#define AUDIO_TYPE_G711_A   2
#define AUDIO_TYPE_MPEG     3

#define DRAWFUN(x)				void  (CALLBACK* x)(long nPort,HDC hDc,LONG nUser)

typedef void (*LOGRECORD_CALLBACK)(char *str, void *context);
#ifdef _WIN32
typedef int (*STREAM_READ_CALLBACK)(ULONG channelNumber, void *context);
typedef int (*STREAM_DIRECT_READ_CALLBACK)(ULONG channelNumber,void *DataBuf,DWORD Length,int FrameType,void *context);
#endif //#ifdef _WIN32

typedef struct tagChannelCapability{
	UCHAR bAudioPreview;
	UCHAR bAlarmIO;
	UCHAR bWatchDog;
}CHANNEL_CAPABILITY, *PCHANNEL_CAPABILITY;

typedef struct tagFramsStatistics{
	ULONG VideoFrames;
	ULONG AudioFrames;
	ULONG FramesLost;
	ULONG QueueOverflow;
	ULONG CurBps;
}FRAMES_STATISTICS, *PFRAMES_STATISTICS;

DLLEXPORT_API int __stdcall InitDSPs();
DLLEXPORT_API int __stdcall DeInitDSPs();
#ifdef _WIN32
DLLEXPORT_API HANDLE __stdcall ChannelOpen(int ChannelNum);
#endif //#ifdef _WIN32
#ifdef __LINUX__
DLLEXPORT_API HANDLE __stdcall ChannelOpen(UINT channelNum, STREAM_READ_CALLBACK streamReadCallback);
#endif //#ifdef __LINUX__
DLLEXPORT_API int __stdcall ChannelClose(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall GetTotalChannels();
DLLEXPORT_API int __stdcall GetTotalDSPs();
#ifdef _WIN32
DLLEXPORT_API int __stdcall StartVideoPreview(HANDLE hChannelHandle,HWND WndHandle, RECT *rect, BOOLEAN bOverlay, int VideoFormat, int FrameRate);
#endif //#ifdef _WIN32
#ifdef __LINUX__
DLLEXPORT_API int __stdcall StartVideoPreview(int hChannelHandle, PREVIEWCONFIG* pPreviewConf, UINT useSyncSem);
DLLEXPORT_API int __stdcall StartVideoPreviewEx(int hChannelHandle, PREVIEWCONFIG* pPreviewConf, UINT useSyncSem, UINT mode);
#endif //#ifdef __LINUX__
DLLEXPORT_API int __stdcall StopVideoPreview(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall SetVideoPara(HANDLE hChannelHandle, int Brightness, int Contrast, int Saturation, int Hue);
DLLEXPORT_API int __stdcall GetVideoPara(HANDLE hChannelHandle, VideoStandard_t *VideoStandard, int *Brightness, int *Contrast, int *Saturation, int *Hue);
DLLEXPORT_API int __stdcall GetVideoSignal(HANDLE  hChannelHandle);
DLLEXPORT_API int __stdcall GetSDKVersion(PVERSION_INFO VersionInfo);
DLLEXPORT_API int __stdcall GetCapability(HANDLE hChannelHandle, CHANNEL_CAPABILITY *Capability);
DLLEXPORT_API int __stdcall GetLastErrorNum(HANDLE hChannelHandle, ULONG *DspError, ULONG *SdkError);
DLLEXPORT_API int __stdcall SetStreamType(HANDLE hChannelHandle, USHORT Type);
DLLEXPORT_API int __stdcall GetStreamType(HANDLE hChannelHandle, USHORT *StreamType);

DLLEXPORT_API int __stdcall SetStreamPackType(HANDLE hChannelHandle,USHORT Type);
DLLEXPORT_API int __stdcall SetDeNoise(HANDLE hChannelHandle,UINT level);
DLLEXPORT_API int __stdcall SetSceneMode(HANDLE hChannelHandle,UINT mode);

DLLEXPORT_API int __stdcall GetFramesStatistics(HANDLE hChannelHandle, 	PFRAMES_STATISTICS framesStatistics);
DLLEXPORT_API int __stdcall StartMotionDetection(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall GetBoardInfo(HANDLE hChannelHandle, ULONG *BoardType, UCHAR *SerialNo);
DLLEXPORT_API int __stdcall StopMotionDetection(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall GetOriginalImage(HANDLE hChannelHandle, UCHAR *ImageBuf, ULONG *Size);
DLLEXPORT_API int __stdcall RegisterLogRecordCallback(LOGRECORD_CALLBACK LogRecordFunc, void *Context);
DLLEXPORT_API int __stdcall SetAudioPreview(HANDLE hChannelHandle, BOOL bEnable);
#ifdef _WIN32
DLLEXPORT_API int __stdcall ReadStreamData(HANDLE hChannelHandle, void *DataBuf, DWORD *Length, int *FrameType);
DLLEXPORT_API int __stdcall RegisterMessageNotifyHandle(HWND hWnd, UINT MessageId);
#endif //#ifdef _WIN32
DLLEXPORT_API int __stdcall StartVideoCapture(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall StopVideoCapture(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall SetIBPMode(HANDLE hChannelHandle, int KeyFrameIntervals, int BFrames, int PFrames, int FrameRate);
DLLEXPORT_API int __stdcall SetDefaultQuant(HANDLE hChannelHandle, int IQuantVal, int PQuantVal, int BQuantVal);
DLLEXPORT_API int __stdcall SetOsd(HANDLE hChannelHandle, BOOL Enable);

DLLEXPORT_API int __stdcall SetLogo(HANDLE hChannelHandle, int x, int y, int w, int h, unsigned char *yuv);
DLLEXPORT_API int __stdcall StopLogo(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall SetupMotionDetection(HANDLE hChannelHandle, RECT *RectList, int iAreas);
DLLEXPORT_API int __stdcall MotionAnalyzer(HANDLE hChannelHandle, char *MotionData, int iThreshold, int *iResult);
DLLEXPORT_API int __stdcall LoadYUVFromBmpFile(char *FileName, unsigned char *yuv, int BufLen, int *Width, int *Height);
DLLEXPORT_API int __stdcall SaveYUVToBmpFile(char *FileName, unsigned char *yuv, int Width, int Height);
DLLEXPORT_API int __stdcall CaptureIFrame(HANDLE hChannelHandle);
#ifdef _WIN32
DLLEXPORT_API int __stdcall RegisterStreamReadCallback(STREAM_READ_CALLBACK StreamReadCallback, void *Context);
#endif //#ifdef _WIN32
DLLEXPORT_API int __stdcall AdjustMotionDetectPrecision(HANDLE hChannelHandle, 
										   int iGrade, int iFastMotionDetectFps, 
										   int iSlowMotionDetectFps);
DLLEXPORT_API int __stdcall SetupBitrateControl(HANDLE hChannelHandle, ULONG MaxBps);
#ifdef _WIN32
DLLEXPORT_API int __stdcall SetOverlayColorKey(COLORREF DestColorKey);
#endif //#ifdef _WIN32
DLLEXPORT_API int __stdcall SetOsdDisplayMode(HANDLE hChannelHandle, int Brightness, BOOL Translucent, int parameter, USHORT *Format1, USHORT *Format2);
DLLEXPORT_API int __stdcall SetLogoDisplayMode(HANDLE hChannelHandle, COLORREF ColorKey, BOOL Translucent, int TwinkleInterval);
DLLEXPORT_API int __stdcall SetEncoderPictureFormat(HANDLE hChannelHandle, PictureFormat_t PictureFormat);
DLLEXPORT_API int __stdcall SetVideoStandard(HANDLE hChannelHandle, VideoStandard_t VideoStandard);
#ifdef _WIN32
DLLEXPORT_API int __stdcall RestoreOverlay();
#endif //#ifdef _WIN32
DLLEXPORT_API int __stdcall ResetDSP(int DspNumber);
DLLEXPORT_API int __stdcall GetSoundLevel(HANDLE hChannelHandle);

DLLEXPORT_API int __stdcall SetBitrateControlMode(HANDLE hChannelHandle, BitrateControlType_t brc);
DLLEXPORT_API int __stdcall SetupNotifyThreshold(HANDLE hChannelHandle, int iFramesThreshold);

DLLEXPORT_API int __stdcall SetupSubChannel(HANDLE hChannelHandle, int iSubChannel);
DLLEXPORT_API int __stdcall GetSubChannelStreamType(void  *DataBuf, int FrameType);
//add for HC/HF 
#ifdef _WIN32
DLLEXPORT_API int __stdcall RegisterStreamDirectReadCallback(STREAM_DIRECT_READ_CALLBACK StreamDirectReadCallback,void *Context);
DLLEXPORT_API int __stdcall RegisterDrawFun(DWORD nport, DRAWFUN(DrawFun),LONG nUser);
#endif //#ifdef _WIN32
DLLEXPORT_API int __stdcall SetupMask(HANDLE hChannelHandle, RECT *RectList, int iAreas);
DLLEXPORT_API int __stdcall StopMask(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall SetSubEncoderPictureFormat(HANDLE hChannelHandle, PictureFormat_t PictureFormat);
DLLEXPORT_API int __stdcall StartSubVideoCapture(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall StopSubVideoCapture(HANDLE hChannelHandle);
DLLEXPORT_API int __stdcall SetupDateTime(HANDLE hChannelHandle, SYSTEMTIME *now);

//get original video stream
typedef void (*IMAGE_STREAM_CALLBACK)(UINT channelNumber,void *context);
DLLEXPORT_API int __stdcall SetImageStream(HANDLE hChannel,BOOL bStart,UINT fps,UINT width,UINT height,unsigned char *imageBuffer);
DLLEXPORT_API int __stdcall RegisterImageStreamCallback(IMAGE_STREAM_CALLBACK ImageStreamCallback,void *context);
/*
	Set video input position:
		(x,y) is the coordinate in the input original image of the upper left corner of the handled image.
		x should be integer multiple of 2.
		The range of (x,y) is related to camera type. If the specified value doesn't match with the input value, it may result in still image or horizontal, vertical scroll.
*/
DLLEXPORT_API int __stdcall SetInputVideoPosition(HANDLE hChannel,UINT x,UINT y);
#ifdef _WIN32
DLLEXPORT_API int __stdcall StopRegisterDrawFun(DWORD nport);
#endif //#ifdef _WIN32
/*
	3.0
*/

#define SERIAL_NUMBER_LENGTH	12	//Length of card serial no.

typedef struct
{
	BOARD_TYPE_DS type;					//card type
	BYTE sn[16];						//serial no.
	UINT dspCount;						//sum of DSPs in the card
	UINT firstDspIndex;					//index of the first DSP of this card in all DSP
	UINT encodeChannelCount;			//sum of encode channels on this card
	UINT firstEncodeChannelIndex;		//the index of the first encode channel of the current card
	UINT decodeChannelCount;			//sum of decode channels on the current card
	UINT firstDecodeChannelIndex;		//the index of the first decode channel of the current card
	UINT displayChannelCount;			//sum of display channels included in the current card
	UINT firstDisplayChannelIndex;		//the index of the first video output (display) channel of the current card
	UINT reserved1;
	UINT reserved2;
	UINT initInfo;
	UINT version;						//Hardware version, format: major.minor.build, major: bit 16-19, minor: bit8-15, build: 0-7 
}DS_BOARD_DETAIL;

typedef struct
{
	UINT encodeChannelCount;			//sum of encode channels in the current DSP
	UINT firstEncodeChannelIndex;		//the index of the first encode channel of the current DSP
	UINT decodeChannelCount;			//sum of decode channels in the current DSP
	UINT firstDecodeChannelIndex;		//the index of the first decode channel of the current DSP
	UINT displayChannelCount;			//sum of display channels (video output channel) in the current DSP
	UINT firstDisplayChannelIndex;		//index of the first video output(display) channel of the current DSP
	UINT reserved1;
	UINT reserved2;
	UINT reserved3;
	UINT initInfo;
}DSP_DETAIL;
DLLEXPORT_API unsigned int __stdcall GetBoardCount();
DLLEXPORT_API int __stdcall GetBoardDetail(UINT boardNum,DS_BOARD_DETAIL *pBoardDetail);
DLLEXPORT_API unsigned int __stdcall GetDspCount();
DLLEXPORT_API int __stdcall GetDspDetail(UINT dspNum,DSP_DETAIL *pDspDetail);
DLLEXPORT_API unsigned int __stdcall GetEncodeChannelCount();
DLLEXPORT_API unsigned int __stdcall GetDecodeChannelCount();
DLLEXPORT_API unsigned int __stdcall GetDisplayChannelCount();
DLLEXPORT_API int __stdcall SetDefaultVideoStandard(VideoStandard_t VideoStandard);
DLLEXPORT_API int __stdcall SetDefaultHDVideoStandard(VideoStandard_t VideoStandard);
DLLEXPORT_API int __stdcall SetVideoDetectPrecision(HANDLE hChannel,unsigned int value);
DLLEXPORT_API int __stdcall SetSubStreamType(HANDLE hChannelHandle, USHORT Type);
DLLEXPORT_API int __stdcall GetSubStreamType(HANDLE hChannelHandle, USHORT *StreamType);

#define MAX_DISPLAY_REGION		16
typedef struct
{
	UINT left;
	UINT top;
	UINT width;
	UINT height;
	COLORREF color;
	UINT param;
}REGION_PARAM;

DLLEXPORT_API int __stdcall SetDisplayStandard(UINT nDisplayChannel,VideoStandard_t VideoStandard);
DLLEXPORT_API int __stdcall SetDisplayRegion(UINT nDisplayChannel,UINT nRegionCount,REGION_PARAM *pParam,UINT nReserved);
DLLEXPORT_API int __stdcall ClearDisplayRegion(UINT nDisplayChannel,UINT nRegionFlag);
DLLEXPORT_API int __stdcall SetDisplayRegionPosition(UINT nDisplayChannel,UINT nRegion,UINT nLeft,UINT nTop);
DLLEXPORT_API int __stdcall FillDisplayRegion(UINT nDisplayChannel,UINT nRegion,unsigned char *pImage);
DLLEXPORT_API int __stdcall SetEncoderVideoExtOutput(UINT nEncodeChannel,UINT nPort,BOOL bOpen,UINT nDisplayChannel,UINT nDisplayRegion,UINT nFrameRate);
DLLEXPORT_API int __stdcall SetDecoderVideoExtOutput(UINT nDecodeChannel,UINT nPort,BOOL bOpen,UINT nDisplayChannel,UINT nDisplayRegion,UINT nReserved);
DLLEXPORT_API int __stdcall SetDecoderVideoOutput(UINT nDecodeChannel,UINT nPort,BOOL bOpen,UINT nDisplayChannel,UINT nDisplayRegion,UINT nReserved);
DLLEXPORT_API int __stdcall SetDecoderAudioOutput(UINT nDecodeChannel,BOOL bOpen,UINT nOutputChannel);
//3.1
DLLEXPORT_API int __stdcall SetDeInterlace(HANDLE hChannelHandle,UINT mode,UINT level);
#ifdef _WIN32
DLLEXPORT_API int __stdcall SetPreviewOverlayMode(BOOL bTrue);
/*************************************************
Function:    	SetPreviewOverlayModeEx
Description:    Enable or disable global Overlay, it is an extended mode and adds detecting NV12
Input:			
	- True: if Graphics card supports overlay, it will enable global Overlay; false: disable Overlay.
Output£º		none
Return:			If the function succeeds, the return value is 0. If the function fails, the return value is the error code
  
*************************************************/
DLLEXPORT_API int __stdcall SetPreviewOverlayModeEx(BOOL bTrue);

#endif //#ifdef _WIN32

//DECODE functions for MD card
#ifdef _WIN32
typedef struct{
	long bToScreen;
	long bToVideoOut;
	long nLeft;
	long nTop;
	long nWidth;
	long nHeight;
	long nReserved;
}DISPLAY_PARA,*PDISPLAY_PARA;
#endif //#ifdef _WIN32

#ifdef __LINUX__
typedef struct _Preview_Config
{
	ULONG	imageSize;
	ULONG	w;
	ULONG	h;
	char*	dataAddr;
	sem_t*  SyncSem;				//the semphore for have new image coming
	sem_t*	ChangeSem;				//the semphore for the image size changed
}PREVIEWCONFIG, *PPREVIEWCONFIG;
#endif //#ifdef __LINUX__

//Version info
typedef struct {
	ULONG DspVersion, DspBuildNum;
	ULONG DriverVersion, DriverBuildNum;
	ULONG SDKVersion, SDKBuildNum;
}HW_VERSION, *PHW_VERSION;

//init part
#ifdef _WIN32
DLLEXPORT_API int __stdcall HW_InitDirectDraw(HWND hParent,COLORREF colorKey);
DLLEXPORT_API int __stdcall HW_ReleaseDirectDraw();
#endif //#ifdef _WIN32
DLLEXPORT_API int __stdcall HW_InitDecDevice(long *pDeviceTotal);
DLLEXPORT_API int __stdcall HW_ReleaseDecDevice();
DLLEXPORT_API int __stdcall HW_ChannelOpen(long nChannelNum,HANDLE* phChannel);
DLLEXPORT_API int __stdcall HW_ChannelClose(HANDLE hChannel);

//open part
DLLEXPORT_API int __stdcall HW_OpenStream(HANDLE hChannel,PBYTE pFileHeadBuf,DWORD nSize);
DLLEXPORT_API int __stdcall HW_ResetStream(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_CloseStream(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_InputData(HANDLE hChannel,PBYTE pBuf,DWORD nSize);
DLLEXPORT_API int __stdcall HW_OpenFile(HANDLE hChannel,LPTSTR sFileName);
DLLEXPORT_API int __stdcall HW_CloseFile(HANDLE hChannel);

//play part
#ifdef _WIN32
DLLEXPORT_API int __stdcall HW_SetDisplayPara(HANDLE hChannel,DISPLAY_PARA *pPara);
#endif //_WIN32
#ifdef __LINUX__
DLLEXPORT_API int __stdcall HW_StartDecVgaDisplay(int hChannel, PREVIEWCONFIG* pPreviewConf, UINT useSyncSem);
DLLEXPORT_API int __stdcall HW_StopDecChanVgaDisplay(int hChannel);
#endif //#ifdef __LINUX__
DLLEXPORT_API int __stdcall HW_Play(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_Stop(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_Pause(HANDLE hChannel,ULONG bPause);

//sound part
DLLEXPORT_API int __stdcall HW_PlaySound(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_StopSound(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_SetVolume(HANDLE hChannel,ULONG nVolume);

#ifdef _WIN32
//overlay part
DLLEXPORT_API int __stdcall HW_RefreshSurface();
DLLEXPORT_API int __stdcall HW_RestoreSurface();
DLLEXPORT_API int __stdcall HW_ClearSurface();
DLLEXPORT_API int __stdcall HW_ZoomOverlay(RECT* pSrcClientRect, RECT* pDecScreenRect);
#endif //_WIN32

//cut file
DLLEXPORT_API int __stdcall HW_StartCapFile(HANDLE hChannel,LPTSTR sFileName);
DLLEXPORT_API int __stdcall HW_StopCapFile(HANDLE hChannel);

//capture picture
DLLEXPORT_API int __stdcall HW_GetYV12Image(HANDLE hChannel, PBYTE pBuffer, ULONG nSize);
DLLEXPORT_API int __stdcall HW_GetPictureSize(HANDLE hChannel,ULONG* pWidth, ULONG* pHeight);
DLLEXPORT_API int __stdcall HW_ConvertToBmpFile(BYTE * pBuf,ULONG nSize,ULONG nWidth,ULONG nHeight,char *sFileName,ULONG nReserved);
//setting and getting  part
DLLEXPORT_API int __stdcall HW_Jump(HANDLE hChannel,ULONG nDirection);
DLLEXPORT_API int __stdcall HW_SetJumpInterval(HANDLE hChannel,ULONG nSecond);
DLLEXPORT_API int __stdcall HW_GetSpeed(HANDLE hChannel,long *pSpeed);
DLLEXPORT_API int __stdcall HW_SetSpeed(HANDLE hChannel,long nSpeed);
DLLEXPORT_API int __stdcall HW_SetPlayPos(HANDLE hChannel,ULONG nPos);
DLLEXPORT_API int __stdcall HW_GetPlayPos(HANDLE hChannel,ULONG* pPos);
DLLEXPORT_API int __stdcall HW_GetVersion(PHW_VERSION pVersion);
DLLEXPORT_API int __stdcall HW_GetCurrentFrameRate(HANDLE hChannel,ULONG* pFrameRate);
DLLEXPORT_API int __stdcall HW_GetCurrentFrameNum(HANDLE hChannel,ULONG* pFrameNum);
DLLEXPORT_API int __stdcall HW_GetFileTotalFrames(HANDLE hChannel,ULONG* pTotalFrames);
DLLEXPORT_API int __stdcall HW_GetFileTime(HANDLE hChannel, ULONG* pFileTime);
DLLEXPORT_API int __stdcall HW_GetCurrentFrameTime(HANDLE hChannel,ULONG* pFrameTime);
DLLEXPORT_API int __stdcall HW_GetPlayedFrames(HANDLE hChannel,ULONG *pDecVFrames);
DLLEXPORT_API int __stdcall HW_GetDeviceSerialNo(HANDLE hChannel,ULONG *pDeviceSerialNo);
#ifdef _WIN32
DLLEXPORT_API int __stdcall HW_SetFileEndMsg(HANDLE hChannel,HWND hWnd,UINT nMsg);
#endif//#ifdef _WIN32
#ifdef __LINUX__
DLLEXPORT_API int __stdcall HW_SetFileEndMsg(int hChannel, sem_t* nMsg)
#endif //#ifdef __LINUX__
DLLEXPORT_API int __stdcall HW_SetStreamOpenMode(HANDLE hChannel,ULONG nMode);
DLLEXPORT_API int __stdcall HW_GetStreamOpenMode(HANDLE hChannel,ULONG *pMode);
DLLEXPORT_API int __stdcall HW_SetVideoOutStandard(HANDLE hChannel,ULONG nStandard);
DLLEXPORT_API int __stdcall HW_SetDspDeadlockMsg(HWND hWnd,UINT nMsg);
DLLEXPORT_API int __stdcall HW_GetChannelNum(long nDspNum,long *pChannelNum,ULONG nNumsToGet,ULONG * pNumsGotten);
DLLEXPORT_API int __stdcall HW_ResetDsp(long nDspNum);
DLLEXPORT_API int __stdcall HW_SetAudioPreview(HANDLE hChannel, BOOL bEnable);
//////////////////////////////////////////////

DLLEXPORT_API int __stdcall HW_OpenStreamEx(HANDLE hChannel,PBYTE pFileHeadBuf,DWORD nSize);
DLLEXPORT_API int __stdcall HW_CloseStreamEx(HANDLE hChannel);
DLLEXPORT_API int __stdcall HW_InputVideoData(HANDLE hChannel,PBYTE pBuf,DWORD nSize);
DLLEXPORT_API int __stdcall HW_InputAudioData(HANDLE hChannel,PBYTE pBuf,DWORD nSize);

//4.0
DLLEXPORT_API int __stdcall SetOsdDisplayModeEx(HANDLE hChannelHandle,int color,BOOL Translucent,int param,int nLineCount,USHORT **Format);
typedef void (*MOTION_DETECTION_CALLBACK)(ULONG channelNumber,BOOL bMotionDetected,void *context);
DLLEXPORT_API int __stdcall SetupMotionDetectionEx(HANDLE hChannelHandle,int iGrade,int iFastMotionDetectFps,
												   int iSlowMotionDetectFps,UINT delay,RECT *RectList, int iAreas,
												   MOTION_DETECTION_CALLBACK MotionDetectionCallback,int reserved);
DLLEXPORT_API int __stdcall GetJpegImage(HANDLE hChannelHandle,UCHAR *ImageBuf,ULONG *Size,UINT nQuality);
//WatchDog
DLLEXPORT_API int __stdcall SetWatchDog(UINT boardNumber,BOOL bEnable);
//4.1
typedef void (*FILE_REF_DONE_CALLBACK)(UINT nChannel,UINT nSize);
DLLEXPORT_API int __stdcall HW_SetFileRef(HANDLE hChannel,BOOL bEnable,FILE_REF_DONE_CALLBACK FileRefDoneCallback);
DLLEXPORT_API int __stdcall HW_LocateByAbsoluteTime(HANDLE hChannel,SYSTEMTIME time);
DLLEXPORT_API int __stdcall HW_LocateByFrameNumber(HANDLE hChannel,UINT frmNum);
DLLEXPORT_API int __stdcall HW_GetCurrentAbsoluteTime(HANDLE hChannel,SYSTEMTIME *pTime);
DLLEXPORT_API int __stdcall HW_GetFileAbsoluteTime(HANDLE hChannel,SYSTEMTIME *pStartTime,SYSTEMTIME *pEndTime);
//4.2
DLLEXPORT_API int __stdcall HW_ImportFileRef(HANDLE hChannel,char *pBuffer,UINT nSize);
DLLEXPORT_API int __stdcall HW_ExportFileRef(HANDLE hChannel,char *pBuffer,UINT nSize);
DLLEXPORT_API int __stdcall SetDisplayVideoCapture(UINT nDisplayChannel,BOOL bStart,UINT fps,UINT width,UINT height,unsigned char *imageBuffer);
DLLEXPORT_API int __stdcall RegisterDisplayVideoCaptureCallback(IMAGE_STREAM_CALLBACK DisplayVideoCaptureCallback,void *context);
DLLEXPORT_API int __stdcall SetDisplayVideoBrightness(UINT chan,int Brightness);
DLLEXPORT_API int __stdcall SetChannelStreamCRC(HANDLE hChannel,BOOL bEnable);
DLLEXPORT_API int __stdcall SetSubChannelStreamCRC(HANDLE hChannel,BOOL bEnable);
DLLEXPORT_API int __stdcall HW_SetDecoderPostProcess(HANDLE hChannel,UINT param);
//
typedef void (*DECODER_VIDEO_CAPTURE_CALLBACK)(UINT nChannelNumber,void *DataBuf,UINT width,UINT height,UINT nFrameNum,UINT nFrameTime,SYSTEMTIME *pFrameAbsoluteTime,void *context);
DLLEXPORT_API int __stdcall RegisterDecoderVideoCaptureCallback(DECODER_VIDEO_CAPTURE_CALLBACK DecoderVideoCaptureCallback,void *context);
DLLEXPORT_API int __stdcall HW_SetDecoderVideoCapture(HANDLE hChannel,BOOL bStart,UINT param);
DLLEXPORT_API int __stdcall HW_InputDataByFrame(HANDLE hChannel,PBYTE pBuf,DWORD nSize);
//4.3
#ifdef _WIN32
DLLEXPORT_API int __stdcall HW_RegisterDrawFun(DWORD nport, DRAWFUN(DrawFun),LONG nUser);
DLLEXPORT_API int __stdcall HW_StopRegisterDrawFun(DWORD nport);
#endif //#ifdef _WIN32

//5.0
DLLEXPORT_API int __stdcall SetEncoderAudioOutput(UINT nEncodeChannel,BOOL bEnable,UINT nOutputChannel);
DLLEXPORT_API int __stdcall SetEncoderAudioExtOutput(UINT nEncodeChannel,UINT nPort,BOOL bOpen,UINT nOutChannel,UINT nReserved);
DLLEXPORT_API int __stdcall SetDecoderAudioExtOutput(UINT nDecodeChannel,UINT nPort,BOOL bOpen,UINT nOutChannel,UINT nReserved);

//6.0 new added APIs
/*************************************************
  Function:    	SetDirectAudioPreview
  Description:	Start PCI audio preview of encode channel
  Input:        hChannelHandle		channel handle
				bEnable				enable or not
  Output:      	none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall SetDirectAudioPreview(HANDLE hChannelHandle,BOOL bEnable);

/*************************************************
  Function:    	HW_SetDirectAudioPreview
  Description:	Start PCI audio preview of decode channel
  Input:        hChannel		channel handle
				bEnable			enable or not
  Output:      	none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall	HW_SetDirectAudioPreview(HANDLE hChannel,BOOL bEnable);

/*************************************************
  Function:    	GetEncoderJpegImage
  Description:	Get JPEG image of specific resolution
  Input:		hChannelHandle			channel handle
				ImageBuf				buffer to save image data
				Size					size of the buffer
				nQuality				image quality
				picFormat				image definition
  Output£º		Size					size of JPEG image
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall GetEncoderJpegImage(HANDLE hChannelHandle,UCHAR *ImageBuf,ULONG *Size,UINT nQuality,PictureFormat_t picFormat);

/*************************************************
  Function:    	GetEncoderOriginalImage
  Description:	Get original image (YUV422) 
  Input:		hChannelHandle			channel handle
				ImageBuf				buffer to save image data
				Size					size of the buffer
				picFormat				image definition
  Output£º		Size					size of image
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall GetEncoderOriginalImage(HANDLE hChannelHandle, UCHAR *ImageBuf, ULONG *Size,PictureFormat_t picFormat);

/*********************************************************************************************************************************************
Function:    	SetEncoderOsdDisplayMode
Description:	Set OSD display mode of encode channel

  Input:
			HANDLE hChannelHandle	      channel handle
			BOOL   bEnableOsd			  enable or disable OSD
			UINT   nLuminance			  OSD brightness, value range: [0,255]
			UINT   nFlash				  OSD flash parameter. Bit0-7: stopping seconds, Bit8-15: display seconds. E.g. flash= (2<<8)|1 means LOGO display for 2 seconds, stopping for 1s.
			COLORREF CharacterColor		  colour of OSD, supports RGB format. If its value is ¡®-1¡¯, it is of normal mode, and OSD is white.
			COLORREF BackGroundColor	  background colour of OSD, supports RGB format. If its value is ¡®-1¡¯, it is of normal mode, and the background is transparent. 
			UINT	 nTranslucentMode	  set to be translucent or not. 
                                          0- both foreground and background are not transparent, 1- foreground translucent and background not transparent, 
										  2-  foreground not transparent and background translucent, 3- both foreground and background translucent
			BOOL     bAutoAdjustLum       adjust brightness automatically or not. When set to adjust automatically, the defined brightness value is invalid
			int      *param				  int type array, to set horizontal and vertical magnification of every OSD line. Bit0-7: vertical magnification, Bit8-15: horizontal magnification
			int      nLineCount           lines of OSD display, max 8 lines
			UINT	 **Format	          describle the position of overlay and pattern of order.
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
************************************************************************************************************************************************/
DLLEXPORT_API int __stdcall SetEncoderOsdDisplayMode(HANDLE hChannelHandle, BOOL bEnableOsd, UINT nLuminance, UINT nFlash, \
												 COLORREF CharacterColor, COLORREF BackGroundColor,UINT nTranslucentMode,\
												 BOOL bAutoAdjustLum, int *param, int nLineCount, UINT **Format);

/*********************************************************************************************************************************************
  Function:    	SetDecoderOsdDisplayMode
  Description:	Set OSD display mode of decode channel

  Input:
			UINT hChannel       	      channel handle
			BOOL bEnableOsd				  enable or disable OSD
			UINT   nLuminance			  OSD brightness
			UINT   nFlash				  OSD flash parameter. Bit0-7: stopping seconds, Bit8-15: display seconds. E.g. flash= (2<<8)|1 means LOGO display for 2 seconds, stopping for 1s.
			COLORREF CharacterColor		  colour of OSD, supports RGB format.
			COLORREF BackGroundColor	  background colour of OSD, supports RGB format. 
			UINT	 nTranslucentMode	  set to be translucent or not. 
                                          0- both foreground and background are not transparent, 1- foreground translucent and background not transparent, 
                                          2- foreground not transparent and background translucent, 3- both foreground and background translucent
			BOOL     bAutoAdjustLum       adjust brightness automatically or not. When set to adjust automatically, the defined brightness value is invalid
			UINT	 timeMode             0- system time, 1- decoding time
			int      *param				  int type array, to set horizontal and vertical magnification of every OSD line. Bit0-7: vertical magnification, Bit8-15: horizontal magnification
			int      nLineCount           lines of OSD display, max 8 lines
			UINT     **Format	          describle the position of overlay and pattern of order.
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
************************************************************************************************************************************************/
DLLEXPORT_API int __stdcall SetDecoderOsdDisplayMode(HANDLE hChannel, BOOL bEnableOsd, UINT nLuminance, UINT nFlash,\
												 COLORREF CharacterColor, COLORREF BackGroundColor, UINT nTranslucentMode, \
												 BOOL bAutoAdjustLum, UINT timeMode, int *param, int nLineCount, UINT **Format);

/*********************************************************************************************************************************************
  Function:    	SetDisplayOsdDisplayMode
  Description:	Set OSD display mode of display channel

  Input:
			UINT nDisplayChannel	      display channel number¡£
			BOOL bEnableOsd				  enable or disable OSD
			UINT   nLuminance			  OSD brightness
			UINT   nFlash				  OSD flash parameter. Bit0-7: stopping seconds, Bit8-15: display seconds. E.g. flash= (2<<8)|1 means LOGO display for 2 seconds, stopping for 1s.
			COLORREF CharacterColor		  colour of OSD, supports RGB format. If its value is ¡®-1¡¯, it is of normal mode, and OSD is white.
			COLORREF BackGroundColor	  background colour of OSD, supports RGB format. If its value is ¡®-1¡¯, it is of normal mode, and the background is transparent.
			UINT	 nTranslucentMode	  set to be translucent or not. 
                                          0- both foreground and background are not transparent, 1- foreground translucent and background not transparent, 
                                          2- foreground not transparent and background translucent, 3- both foreground and background translucent
			BOOL     bAutoAdjustLum       adjust brightness automatically or not. When set to adjust automatically, the defined brightness value is invalid
			int      *param				  int type array, to set horizontal and vertical magnification of every OSD line. Bit0-7: vertical magnification, Bit8-15: horizontal magnification
			int      nLineCount           lines of OSD display, max 8 lines
			UINT     **Format	          describle the position of overlay and pattern of order.
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
************************************************************************************************************************************************/
DLLEXPORT_API int __stdcall SetDisplayOsdDisplayMode(UINT nDisplayChannel, BOOL bEnableOsd, UINT nLuminance, UINT nFlash,\
													 COLORREF CharacterColor, COLORREF BackGroundColor, UINT nTranslucentMode,\
													 BOOL bAutoAdjustLum, int *param, int nLineCount, UINT **Format);

/*************************************************
  Function:    	SetDisplayLogo
  Description:	Setup LOGO of display channel 
  Input:        nDisplayChannel			display channel number
				x,y,w,h					coordinate of LOGO bmp
				*YUV					image data of UYVY(YUV422) format
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall SetDisplayLogo(UINT nDisplayChannel, int x, int y, int w, int h, unsigned char *yuv);

/*************************************************
  Function:    	StopDisplayLogo
  Description:	Stop LOGO display on display channel
  Input:        nDisplayChannel			display channel handle
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall StopDisplayLogo(UINT nDisplayChannel);

/*************************************************
  Function:    	SetDisplayLogoDisplayMode
  Description:	Set LOGO parameter of display channel
  Input:        nDisplayChannel			display channel handle
				ColorKey				key color of LOGO image
				Translucent				whether translucent or not
				Twinkle					time setting of twinkle. 
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall SetDisplayLogoDisplayMode(UINT nDisplayChannel, COLORREF ColorKey, BOOL Translucent, int Twinkle);

/*Mask area parameter*/
typedef struct
{
	UINT left;		/*Upper left X-axis coordinate of mask area*/
	UINT top;		/*Upper left Y-axis coordinate of mask area*/
	UINT width;		/*Width of mask area*/
	UINT height;	/*Height of mask area */
	COLORREF color;	/*Colour of mask area*/
}MASK_AREA_PARAM;

/*************************************************
  Function:    	SetupEncoderMask
  Description:	Set mask (supports to set colour of every mask area)
  Input:        hChannelHandle			channel handle
				iAreaCount				mask area number,0 means to disable mask function
				*pAreaParam				mask area parameter
  Output:		none
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall SetupEncoderMask(HANDLE hChannelHandle, int iAreaCount, MASK_AREA_PARAM* pAreaParam);

/* Normalized area, the float value is the percentage of original video width and height size, accuracy of 0.001 */
typedef struct _ZOOM_RECT_NORMALIZE_
{
	float left;           /* Upper left X-axis coordinate of zoom area */
	float top;            /* Upper left Y-axis coordinate of zoom area */
	float width;          /* Width of zoom area */
	float height;         /* Height of zoom area */
}ZOOM_RECT_NORMALIZE;

/*************************************************
  Function:    	ZoomOutEncoderVideoPreview
  Description:	Set partial zoom on video preview of encode channel
  Input:        hChannelHandle			channel handle
				nRectIdx				index of zoom area.0 means display on the preview window of current encode channel after zoomed in.
				bEnable					enable or disable the partial zoom operation. 
				hWnd					window handle to display zoom area. When nRectIdx is 0, the parameter is invalid.
				pZoomRect				coordinate of partial zoom area relative to encode channel video preview area, and its value is normalized. Please see to ZOOM_RECT_NORMALIZE
				pRect					target area to display zoomed video, usually it is the client area of hWnd. When nRectIdx is 0, the parameter is invalid.
  Output:	
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall ZoomOutEncoderVideoPreview(HANDLE hChannelHandle, UINT nRectIdx, BOOL bEnable, HWND hWnd,
													   ZOOM_RECT_NORMALIZE* pZoomRect, RECT* pRect);

/*************************************************
  Function:    	ZoomOutDecoderVideoPreview
  Description:	Set partial zoom on video preview of decode channel
  Input:        hChannel				channel handle
				nRectIdx				index of zoom area.0 means display on the preview window of current encode channel after zoomed in.
				bEnable					enable or disable the partial zoom operation. 
				hWnd					window handle to display zoom area. When nRectIdx is 0, the parameter is invalid.
				pZoomRect				coordinate of partial zoom area relative to encode channel video preview area, and its value is normalized. Please see to ZOOM_RECT_NORMALIZE
				pRect					target area to display zoomed video, usually it is the client area of hWnd. When nRectIdx is 0, the parameter is invalid.
  Output:	
  Return:		If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*************************************************/
DLLEXPORT_API int __stdcall ZoomOutDecoderVideoPreview(HANDLE hChannel, UINT nRectIdx, BOOL bEnable, HWND hWnd,
													   ZOOM_RECT_NORMALIZE* pZoomRect, RECT* pRect);


/*************************************************
Function:    	SetEncoderZoomOutAntiTearing
Description:    Set preview vertical sync of encode channel partial zoom
Input:			
				hChannelHandle:	  channel handle	
				nRectIdx		  index of zoom area, must not be less than 1
				bAntiTearing:	  enable vertical sync or not
				reserved:		  reserved
Output:         none
Return:	        If the function succeeds, the return value is 0. If the function fails, the return value is the error code.  
*************************************************/
DLLEXPORT_API int __stdcall SetEncoderZoomOutAntiTearing(HANDLE hChannelHandle, UINT nRectIdx, BOOL bAntiTearing, DWORD reserved);

/*************************************************
Function:    	SetDecoderZoomOutAntiTearing
Description:    Set preview vertical sync of decode channel partial zoom
Input:			hChannel			channel handle
				nRectIdx			index of zoom area, must not be less than 1	
				BOOL bAntiTearing	enable vertical sync or not
				DWORD reserved		reserved
Output£º		none
Return:			If the function succeeds, the return value is 0. If the function fails, the return value is the error code.  
*************************************************/
DLLEXPORT_API int __stdcall SetDecoderZoomOutAntiTearing(HANDLE hChannel, UINT nRectIdx, BOOL bAntiTearing, DWORD reserved);

/*************************************************
Function:    	SetEncoderVideoSharpness
Description:    Set video sharpness parameter
Input:			hChannelHandle			channel handle
				sharpness				sharpness parameter	
Output£º		none
Return:			If the function succeeds, the return value is 0. If the function fails, the return value is the error code.  
*************************************************/
DLLEXPORT_API int __stdcall SetEncoderVideoSharpness(HANDLE hChannelHandle, int sharpness);

/*************************************************
Function:    	GetEncoderVideoSharpness
Description:    Get video sharpness parameter
Input:			hChannelHandle			channel handle
Output£º		pSharpness				sharpness parameter
Return:			If the function succeeds, the return value is 0. If the function fails, the return value is the error code.  
*************************************************/
DLLEXPORT_API int __stdcall GetEncoderVideoSharpness(HANDLE hChannelHandle, int *pSharpness);

/********************************************************************
* Function: FillDisplayRegionEx
* Description: Fill display region with image(extended)
* Input:	
	- nDisplayChannel				display channel
	- nRegion						region to be filled
	- pImageBuf						pointer to YV12(YUV420) image data
	- nWidth						width of the image data to be filled
	- nHeight						height of the image data to be filled
* Output: none
* Return: If the function succeeds, the return value is 0. If the function fails, the return value is the error code. 
*********************************************************************/
DLLEXPORT_API int __stdcall FillDisplayRegionEx(UINT nDisplayChannel,UINT nRegion,unsigned char *pImageBuf, UINT nWidth, UINT nHeight);

/* Intelligent capability */
typedef enum _VCA_CAPABILITY_
{
    NONE_CAPABILITY        = 0x0,    /* support no intelligent ability */
	BEHAVIOR_CAPABILITY    = 0x1,    /* support behavior analysis */
	PLATE_CAPABILITY       = 0x2,    /* support license plate recognition */
	FACE_CAPABILITY		   = 0x4	 /* support face detection */
}VCA_CAPABILITY;

/* Type of intelligent channel */
typedef enum _VCA_CHANNEL_TYPE_
{
    NORMAL_CHAN                    = 0,    /* channel in unintelligent card */
	VCA_CHAN_ON_VCA_BOARD          = 1,    /* intelligent channel in intelligent card */
	NORMAL_CHAN_ON_VCA_BOARD       = 2     /* unintelligent channel in intelligent card */
}VCA_CHANNEL_TYPE;

/* Channel type */
typedef enum _CHANNEL_TYPE_
{
    ENCODE_CHANNEL    = 1,    /* encode channel */
	DECODE_CHANNEL    = 2,    /* decode channel */
	DISPLAY_CHANNEL   = 3     /* display channel */
}CHANNEL_TYPE;

/*DEINTERLACE mode*/
typedef enum _DEINTERLACE_MODE_
{
    NO_DEINTERLACE         = 0x0,    /* don¡¯t support DEINTERLACE */
	DEINTERLACE_MODE1      = 0x1,    /* Mode 1 */
	DEINTERLACE_MODE2      = 0x2,    /* Mode 2 */
	DEINTERLACE_MODE3      = 0x4	 /* Mode 3 */
} DEINTERLACE_MODE;

/*Audio preview*/
typedef enum  _AUDIO_PREVIEW_
{
	AUDIO_PREVIEW_NOT_SUPPORT	=0x00000000,	/*don¡¯t support audio preview*/
	AUDIO_PREVIEW_HARD			=0x00000001,	/*audio preview with connecting audio cable*/
	AUDIO_PREVIEW_SOFT			=0x00000002		/*audio preview in PCI mode, and without connecting audio cable*/
} AUIDO_PREVIEW;

/*Image resolution */
typedef enum  _CAP_PICTURE_FORMAT_
{
	CAP_PICTURE_FORMAT_INVALID		= 0x00000000,
	CAP_PICTURE_FORMAT_QCIF			= 0x00000001,	/* QCIF. The definition is only used in capability set.*/
	CAP_PICTURE_FORMAT_CIF			= 0x00000002,	/* CIF. The definition is only used in capability set.*/
	CAP_PICTURE_FORMAT_2CIF			= 0x00000004,	/* 2CIF. The definition is only used in capability set.*/
	CAP_PICTURE_FORMAT_DCIF			= 0x00000008,	/* DCIF. The definition is only used in capability set.*/
	CAP_PICTURE_FORMAT_4CIF			= 0x00000010,	/* 4CIF. The definition is only used in capability set.*/
	CAP_PICTURE_FORMAT_VGA			= 0x00000020,	/* VGA. The definition is only used in capability set.*/
	CAP_PICTURE_FORMAT_WD1			= 0x00000040,	/* WD1. The definition is only used in capability set.*/
}CAP_PICTURE_FORMAT;

/*Image resolution (extended)*/
typedef enum  _CAP_PICTURE_FORMAT_EX_
{
	CAP_PICTURE_FORMAT_SVGA			= 0x00000001,	/*800*600 resolution, the definition is only used in capability set*/
	CAP_PICTURE_FORMAT_XGA			= 0x00000002,	/*1024*768 resolution, the definition is only used in capability set*/
	CAP_PICTURE_FORMAT_SXGA			= 0x00000004,	/*1280*1024 resolution, the definition is only used in capability set */
	CAP_PICTURE_FORMAT_SXGA_960		= 0x00000008,	/*1280*960 resolution, the definition is only used in capability set*/
	CAP_PICTURE_FORMAT_720			= 0x00000010,	/*1280*720 resolution, the definition is only used in capability set*/
	CAP_PICTURE_FORMAT_1080			= 0x00000020,	/*1920*1080 resolution, the definition is only used in capability set*/
	CAP_PICTURE_FORMAT_UXGA			= 0x00000040,	/*1600*1200 resolution, the definition is only used in capability set */
	CAP_PICTURE_FORMAT_HD_Q			= 0x00000080,
	CAP_PICTURE_FORMAT_HD_H			= 0x00000100,
	CAP_PICTURE_FORMAT_HD_F			= 0x00000200
}CAP_PICTURE_FORMAT_EX;


/*Channel capacity set*/
typedef struct _CHANNEL_CAPABILITY_EX_
{
	BOARD_TYPE_DS boardType;				   /* type of the card which the channel belongs to*/
	CHANNEL_TYPE  channelType;				   /* channel type, see to CHANNEL_TYPE*/
	VCA_CHANNEL_TYPE vcaChanType;			   /* intelligent channel type, see to VCA_CHANNEL_TYPE */
	DWORD		dwVcaCapability;		       /* intelligent Capability, see to VCA_CAPABILITY */
	DWORD       dwStreamPackType;			   /* the stream packaging format supported by the main channel. It is invalid and reserved, and set to 0. */
	DWORD       dwSubStreamPackType;		   /* the stream packaging format supported by the Subchannel.It is invalid and reserved, and set to 0. */
	DWORD       dwVideoCodec;				   /* video encode algorithm supported by the main channel, not in use now. It is invalid and reserved, and set to 0. */
	DWORD		dwSubVideoCodec;			   /* video encode algorithm supported by the subchannel, not in use now. It is invalid and reserved, and set to 0. */
	DWORD       dwAudioCodec;				   /* audio encode algorithm supported by the main channel, not in use now. It is invalid and reserved, and set to 0. */
	DWORD       dwSubAudioCodec;			   /* audio encode algorithm supported by the Subchannel. It is invalid and reserved, and set to 0. */
	DWORD       dwInputVideoPosition;		   /* whether to support the adjustment of the location of the video input, DS-42xx doesn¡¯t support it. */
	DWORD		dwMbcsOsdMode;			       /* the related functions supported by Multi-byte character set OSD,
                                                  0: supports characters of the 8bit gray adjustment arrange from 0~225, 
                                                  1: only supports white and black characters, 
                                                  2: not supports this kind of OSD mode (Only encode channel supports this OSD mode). 
                                                  DS-42xx card only supports black and white brightness adjustment.*/
	DWORD		dwUnicodeOsdMode;			   /* the related functions supported by Unicode OSD, 
                                                  0: supports the character brightness adjustment, supports setting characters and background color, and supports setting translucent effect to the character and background; 
                                                  1: only supports black and white character, and doesn¡¯t support brightness adjustment, doesn¡¯t support setting the characters and background color, and only supports setting translucent effect to characters. 
                                                  DS-42xx card only supports black and white brightness adjustment */
	DWORD		dwImageStream;			       /* whether to support capturing original Image steram. */
	DWORD	    dwEncoderPIP;			       /* whether to support the encoding preview function of ¡®picture in picture¡¯*/
	DWORD       dwAdaptiveMotionDetection;	   /* whether to support self-adaptive motion detection, DS-42xx card does not support it. */
	DWORD		dwEncoderAudioOutput;	       /* whether to support encode channel audio output in non-matrix mode, DS-40xx and DS-4101HDI both not support */  
	DWORD		dwEncoderAudioExtOutput;	   /* whether to support encode channel audio output in matrix mode, DS-4101HDI both not support */
	DWORD       dwAudioPreview;				   /* the type supports audio preview, 
                                                  0: doesn¡¯t support, 
                                                  1: supports audio preview with connecting audio cable, 
                                                  2: supports audio preview in PCI mode, without connecting audio cable, 
                                                  3: supports both the two types*/
	DWORD		dwSubVideoCapture;		       /* whether to support the sub channel encoding, DS-4016HCSI and DS-40xxHSI don't support */
	DWORD       dwEncoderPictureFormat;		   /* the supported main channel encoding resolution. DS-40xxHCSI card and the DS-40xxHSI card in non-expansion mode, 
											      only supports CIF or even lower resolution. DS-40xxHSI card can support the 4CIF/DCIF/2CIF/CIF/ QCIF in expansion mode,
											      DS-4216HCI supports the resolution up to CIF, and DS-42xxHFVI card supports 4CIF/2CIF/DCIF/CIF/QCIF. */
	DWORD		dwEncoderPictureFormatEx;      /* the supported main channel encoding resolution, and is invalid. Corresponds to the type of CAP_PICTURE_FORMAT_EX */  
	DWORD		dwSubEncoderPictureFormat;     /* the supported subchannel encoding resolution, DS-42xx card only supports the CIF encoding resolution or lower. Corresponds to the types of CAP_PICTURE_FORMAT */   
	DWORD		dwSubEncoderPictureFormatEx;   /* the supported subchannel encoding resolution, DS-42xx card supports the CIF encoding resolution or lower. Corresponds to the type of CAP_PICTURE_FORMAT_EX */    
	DWORD		dwWatermark;				   /* support watermark or not, DS-42xx card doesn¡¯t support it */
	DWORD		dwStreamCRC;				   /* support CRC Checksum or not, DS-42xx card doesn¡¯t support it */
	DWORD		dwStreamEncrypt;			   /* whether to support the encoding stream encryption */
	DWORD		dwEncoderParam;			       /* whether to support the adjustment of the main channel encoding framework and encoding complexity */
	DWORD       dwSubEncoderParam;		       /* whether to support the adjustment of sub-channel encoding framework and encoding complexity */
	DWORD		dwEncoderVideoOutput;	       /* whether to support the encode channel video output, non-matrix. */	
	DWORD       dwEncoderVideoExtOutput;       /* whether to support the encode channel video matrix output. */
	DWORD		dwWatchDog;				       /* whether to support watchdog, only DS-40xxHCSI cards supports. */
	DWORD       dwAlarmIn;					   /* whether to support the alarm input, only DS-40xxHCSI card supports. */
	DWORD       dwAlarmOut;					   /* whether to support the alarm output, only DS-40xxHCSI card supports.*/
	DWORD		dwDeInterlace;			       /* supported the deinterlace mode, see to DEINTERLACE_MODE */
	DWORD		dwDrawEncoderLineRect;		   /* whether to support the encode channel to draw line an rect on video picture by DSP */
	DWORD		dwDisplayFormat;			   /* supported video output formats, the specific definition refer to DISPLAY_FORMAT. */
	DWORD       dwDeNoise;                     /* whether to support noise reduction*/
	DWORD       dwSceneMode;                   /* supported  video scene mode*/
	DWORD		dwReserved[18];				   /* reserved */
}CHANNEL_CAPABILITY_EX;

/*Channel capacity set (CHANNEL_CAPABILITY_TYPE), corresponding to the members of CHANNEL_CAPABILITY_EX.*/
typedef enum _CHANNEL_CAPABILITY_TYPE_
{
	NormalCapability           = 1,    /* describe the capability of functions, these functions are outside of the functions which are corresponding to the capability of CHANNEL_CAPABILITY_EX structure */
    VcaChanType				   = 2,    /* intelligent channel type, corresponding to vcaChanType */
	VcaCapability              = 3,    /* intelligent capability, corresponding dwVcaCapability */
	StreamPackType	           = 4,    /* the encoding package format supported by main stream channel, corresponding to dwStreamPackType  */
	SubStreamPackType          = 5,	   /* the encoding package format supported by sub-channel, corresponding to dwSubStreamPackType */
	VideoCodec                 = 6,    /* the video encoding algorithm supported by main stream channel, corresponding to dwVideoCodec */
	SubVideoCodec              = 7,    /* the video encoding algorithm supported by sub-channel, corresponding to dwSubVideoCodec */
	AudioCodec                 = 8,    /* the audio encoding algorithm supported by main stream channel, corresponding to dwAudioCodec */
	SubAudioCodec              = 9,    /* the audio encoding algorithm supported by the sub-channel, corresponding to dwSubAudioCodec */
	InputVideoPosition         = 10,   /* whether to support the adjustment of the location of the video input, corresponding to dwInputVideoPosition */
	MbcsOsdMode				   = 11,   /* multi-byte character set OSD related functions, corresponding to dwMbcsOsdMode */
	UnicodeOsdMode			   = 12,   /* Unicode OSD related functions, corresponding to dwUnicodeOsdMode */
	ImageStream                = 13,   /* whether to support capturing original image stream, corresponding to dwImageStream */
	EncoderPIP                 = 14,   /* whether to support picture in picture function, corresponding to dwEncoderPIP */   
	AdaptiveMotionDetection    = 15,   /* whether to support self-adaptive motion detection, corresponding to dwAdaptiveMotionDetection */
	EncoderAudioOutput         = 16,   /* whether to support the encode-channel audio output, non-matrix, corresponding to dwEncoderAudioOutput*/
	EncoderAudioExtOutput      = 17,   /* whether to support encode-channel audio matrix output, corresponding to dwEncoderAudioExtOutput */ 
	AudioPreview               = 18,   /* supported audio preview, corresponding to dwAudioPreview */
	SubVideoCapture		       = 19,   /* whether to support the sub-channel encoding, corresponding to dwSubVideoCapture */
	EncoderPictureFormat       = 20,   /* the supported main channel encoding resolution, corresponding to dwEncoderPictureFormat */ 
	EncoderPictureFormatEx	   = 21,   /* the supported main channel encoding resolution, corresponding to dwEncoderPictureFormatEx */
	SubEncoderPictureFormat    = 22,   /* the supported sub-channel encoding resolution, corresponding to dwSubEncoderPictureFormat */  
	SubEncoderPictureFormatEx  = 23,   /* the supported sub-channel encoding resolution, corresponding to dwSubEncoderPictureFormatEx*/  
	Watermark                  = 24,   /* whether to support watermark, corresponding to dwWatermark */  
	StreamCRC				   = 25,   /* whether to support CRC Checksum, corresponding to dwStreamCRC */  
	StreamEncrypt              = 26,   /* whether to support the stream encryption, corresponding to dwStreamEncrypt */  
	EncoderParam               = 27,   /* whether to support the adjustment of the main channel encoding framework and encoding complexity, corresponding to dwEncoderParam */  
	SubEncoderParam            = 28,   /* whether to support the adjustment of sub-channel encoding framework and encoding complexity, corresponding to dwSubEncoderParam */
	EncoderVideoOutput         = 29,   /* whether to support the encode channel video output, non-matrix, corresponding to dwEncoderVideoOutput */
	EncoderVideoExtOutput      = 30,   /* whether to support the encode channel video matrix output, corresponding to dwEncoderVideoExtOutput */
	WatchDog                   = 31,   /* whether to support watchdog, corresponding to dwWatchDog */
	AlarmIn                    = 32,   /* whether to support alarm input , corresponding to dwAlarmIn */
	AlarmOut                   = 33,   /* whether to support alarm output, corresponding to dwAlarmOut */
	DeInterlace		           = 34,   /* the Supported deinterlace mode, corresponding to dwDeInterlace */
	DrawEncoderLineRect		   = 35,   /* whether to support encode channel to draw line and rect on video picture by DSP, corresponding to dwDrawEncoderLineRect */
	DisplayFormat			   = 36,    /* the supported video output format, corresponding to dwDisplayFormat */
    DeNoise                    = 37,   /* whether to support noise reduction */
	SceneMode                  = 38    /* the support video scene mode */
} CHANNEL_CAPABILITY_TYPE;

/*************************************************
Function:    	GetChannelCapability
Description:	Get the channel capability
Input:       chanType     channel type
			 chan         channel index
Output:      pCapability  channel capability set;
Return:		 If the function succeeds, the return value is 0. If the function fails, the return value is the error code. 
*************************************************/
DLLEXPORT_API int __stdcall GetChannelCapability(CHANNEL_TYPE chanType, UINT chan, CHANNEL_CAPABILITY_EX * pCapability);

/*the channel capability structure, returned by CheckFunctionChannelCapability */
typedef struct _FUNCTION_CHANNEL_CAPABILITY_
{
	CHANNEL_CAPABILITY_TYPE dwChanCapType1;   //channel capability type 1
	CHANNEL_CAPABILITY_TYPE dwChanCapType2;	  //channel capability type 2
	DWORD					dwChanCapValue1;  //channel capability value 1
	DWORD					dwChanCapValue2;  //channel capability value 2
	DWORD	                dwReserved[8];	
}FUNCTION_CHANNEL_CAPABILITY;

/*************************************************
Function:    	CheckFunctionChannelCapability
Description:	Get the channel capability according to the input API name
Input:       chanType      channel type
		     chan          channel index
			 functionName  the name of interface function
Output:     pFuncChanCap   capability
Return:		 If the function succeeds, the return value is 0. If the function fails, the return value is the error code. 
*************************************************/
DLLEXPORT_API int __stdcall CheckFunctionChannelCapability(CHANNEL_TYPE chanType, UINT chan, 
														   const char *functionName, FUNCTION_CHANNEL_CAPABILITY *pFuncChanCap);
typedef enum
{
	DISPLAY_FORMAT_INVALID		= 0x00000000,
	DISPLAY_FORMAT_CVBS			= 0x00000001,
	DISPLAY_FORMAT_DVI			= 0x00000002,
	DISPLAY_FORMAT_VGA			= 0x00000004,	
	DISPLAY_FORMAT_HDMI			= 0x00000008,	
	DISPLAY_FORMAT_YPbPr		= 0x00000010
}DISPLAY_FORMAT;

/*resolution*/
typedef enum  _DISPLAY_RESOLUTION_
{
	DISPLAY_RESOLUTION_INVALID			= 0x00000000,
	DISPLAY_RESOLUTION_D1				= 0x00000001,
	DISPLAY_RESOLUTION_XGA_60HZ			= 0x00000002,  //1024*768
	DISPLAY_RESOLUTION_SXGA_60HZ		= 0x00000004,  //1280*1024
	DISPLAY_RESOLUTION_SXGA_960_60HZ	= 0x00000008,  //1280*960	
	DISPLAY_RESOLUTION_720P_50HZ		= 0x00000010,  //1280*720
	DISPLAY_RESOLUTION_720P_60HZ		= 0x00000020,  //1280*720
	DISPLAY_RESOLUTION_1080I_50HZ		= 0x00000040,  //1920*1080
	DISPLAY_RESOLUTION_1080I_60HZ		= 0x00000080,  //1920*1080
	DISPLAY_RESOLUTION_1080P_24HZ		= 0x00000100,  //1920*1080
	DISPLAY_RESOLUTION_1080P_25HZ		= 0x00000200,  //1920*1080
	DISPLAY_RESOLUTION_1080P_30HZ		= 0x00000400,  //1920*1080
	DISPLAY_RESOLUTION_1080P_50HZ		= 0x00000800,  //1920*1080
	DISPLAY_RESOLUTION_1080P_60HZ		= 0x00001000,  //1920*1080
	DISPLAY_RESOLUTION_UXGA_30HZ		= 0x00002000,  //1600*1200
	DISPLAY_RESOLUTION_UXGA_60HZ		= 0x00004000   //1600*1200
}DISPLAY_RESOLUTION;

/********************************************************************
* Function: SetDisplayVideoMode
* Description:  Set video output mode: output interface, output resolution and refresh rate
* Input:	
		UINT nDisplayChannel,			output channel
		DISPLAY_TYPE displayFormat,		output interface	
		DISPLAY_FORMAT displayResolution	output resolution and refresh rate
* Output: none
* Return: If the function succeeds, the return value is 0. If the function fails, the return value is the error code.
*********************************************************************/
DLLEXPORT_API int _stdcall SetDisplayVideoMode(UINT nDisplayChannel,DISPLAY_FORMAT displayFormat,DISPLAY_RESOLUTION displayResolution);

/********************************************************************
* Function: GetDisplayVideoMode
* Description: Get video output mode: output interface, output resolution and refresh rate
* Input:	
		UINT nDisplayChannel,			output channel
		DWORD *dwDisplayFormat,			output interface
		DWORD *dwDisplayResolution		output resolution and refresh rate
* Output: none
* Return: If the function succeeds, the return value is 0. If the function fails, the return value is the error code. 
*********************************************************************/
DLLEXPORT_API int _stdcall GetDisplayVideoMode(UINT nDisplayChannel,DWORD *dwDisplayFormat,DWORD *dwDisplayResolution);

/********************************************************************
* Function: GetDisplayFormatCapability
* Description: Get supported display resolution
* Input:	
	UINT nDisplayChannel,				output channel
	CAP_DISPLAY_FORMAT displayFormat,	output mode
* Output: 
	DWORD *dwResolutionCapabiltiy		return resolution supported by the mode

* Return: If the function succeeds, the return value is 0. If the function fails, the return value is the error code. 
*********************************************************************/
DLLEXPORT_API int __stdcall GetDisplayFormatCapability(UINT nDisplayChannel,DISPLAY_FORMAT displayFormat,DWORD *dwResolutionCapabiltiy);

#ifdef __linux__
typedef struct
{
	UINT year;
	UINT month;
	UINT day;
	UINT dayOfWeek;
	UINT hour;
	UINT minute;
	UINT second;
	UINT milliSecond;
}SYSTEMTIME;
#endif //#ifdef __linux__

#endif //#ifndef HIKVISION_SDK_H
