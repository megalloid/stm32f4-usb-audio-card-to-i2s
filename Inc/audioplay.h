#ifndef AUDIOPLAY_H_
#define AUDIOPLAY_H_

#ifdef __cplusplus
 extern "C" {
#endif
//------------------------------------------------
#include "stm32f4xx_hal.h"
//------------------------------------------------

#define I2S3                            SPI3

typedef enum
{
  BUFFER_OFFSET_NONE = 0,  
  BUFFER_OFFSET_HALF,  
  BUFFER_OFFSET_FULL,     
}BUFFER_StateTypeDef;

typedef struct
{
  uint32_t   ChunkID;       /* 0 */ 
  uint32_t   FileSize;      /* 4 */
  uint32_t   FileFormat;    /* 8 */
  uint32_t   SubChunk1ID;   /* 12 */
  uint32_t   SubChunk1Size; /* 16 */  
  uint16_t   AudioFormat;   /* 20 */ 
  uint16_t   NbrChannels;   /* 22 */   
  uint32_t   SampleRate;    /* 24 */
  
  uint32_t   ByteRate;      /* 28 */
  uint16_t   BlockAlign;    /* 32 */  
  uint16_t   BitPerSample;  /* 34 */  
  uint32_t   SubChunk2ID;   /* 36 */   
  uint32_t   SubChunk2Size; /* 40 */    

}WAVE_FormatTypeDef;
/* Audio State Structure */    
typedef enum {
  AUDIO_IDLE = 0,
  AUDIO_WAIT,  
  AUDIO_EXPLORE,
  AUDIO_PLAYBACK,
  AUDIO_IN,  
}AUDIO_State;

/* Audio Demo State Machine Structure */
typedef struct _StateMachine {
  __IO AUDIO_State state;
  __IO uint8_t select;  
}AUDIO_StateMachine;
//------------------------------------------------
void AudioPlay_Init(uint32_t AudioFreq);
void AudioPlay_Start(uint32_t AudioFreq);
void AudioPlay_HalfTransfer_Callback(void);
void AudioPlay_Transfer_Callback(void);
//------------------------------------------------
#ifdef __cplusplus
}
#endif
#endif /* AUDIOPLAY_H_ */
