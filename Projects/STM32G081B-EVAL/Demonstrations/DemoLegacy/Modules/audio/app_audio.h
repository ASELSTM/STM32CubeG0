/**
  ******************************************************************************
  * @file    app_audio.h
  * @author  MCD Application Team
  * @brief   Audio application interface
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#undef GLOBAL
#ifdef __APP_AUDIO_C
#define GLOBAL
#else
#define GLOBAL extern
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"
#include "ff.h"
#include "k_module.h"

/* Exported types ------------------------------------------------------------*/
/* WAV header structure */
typedef struct
{
  char       RIFF[4];          /* 0 */ 
  uint32_t   ChunkSize;        /* 4 */
  char       WAVE[4];          /* 8 */
  char       fmt[4];           /* 12 */
  uint32_t   SubChunk1Size;    /* 16*/  
  uint16_t   AudioFormat;      /* 20 */ 
  uint16_t   NbrChannels;      /* 22 */   
  uint32_t   SampleRate;       /* 24 */
  uint32_t   ByteRate;         /* 28 */
  uint16_t   BlockAlign;       /* 32 */  
  uint16_t   BitPerSample;     /* 34 */  
} WAV_HeaderTypeDef;

/* Exported constants --------------------------------------------------------*/
/* Size of audio buffers (two buffers) in byte */
#define BUFFER_SIZE_BYTE   (_MAX_SS*8)
#define BUFFER_SIZE_WORD   BUFFER_SIZE_BYTE/4

/* Size of the header of a WAV (RIFF) file (36 bytes long) */
#define WAV_HEADER_SIZE 36

/* Offset of the "fmt" sub-chunk in the wave header */
#define FMT_CHK_POS 12

/* Sub-chunk id length (in bbytes) */
#define SUB_CHUNK_ID_LENGHT 4

/* Record file name */
#define REC_FILE_NAME           "USER/rec.wav"

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
GLOBAL const K_ModuleItem_Typedef ModuleAudio;

/* WAVE file descriptor */
GLOBAL FIL WaveFile;

/* Peripherals HAL handles */
GLOBAL DAC_HandleTypeDef hdac;
GLOBAL ADC_HandleTypeDef hadc;

/* Audio samples buffer */
GLOBAL uint32_t Buffer1[];
GLOBAL uint32_t Buffer2[];

/* Active audio buffer  */
GLOBAL __IO uint32_t * BufferSelect;

/* DMA transfer complete flag */
GLOBAL __IO uint8_t DMATxComplete;

/* Progress bar handle */
GLOBAL void * hProgressBar;

/* Exported functions --------------------------------------------------------*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
