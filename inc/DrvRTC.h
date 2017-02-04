/***********************************************************************************************************************
* @file     DrvRTC.h
* @author   Boyan Bonev
* @version  1.0
* @date     22 Sep 2016
* @brief
*
* @copyright
***********************************************************************************************************************/

#ifndef DRV_RTC_H
#define DRV_RTC_H

///=====================================================================================================================
/// EXPORTED TYPES
///=====================================================================================================================
typedef struct
{
    uint16_t    year;
    uint8_t     month;
    uint8_t     day;
    uint8_t     hour;
    uint8_t     minutes;
    uint8_t     seconds;
    uint8_t     weekday;
} DateTimeType;

///=====================================================================================================================
/// EXPORTED FUNCTIONS
///=====================================================================================================================
void    DrvRTC_Init( void );
///---------------------------------------------------------------------------------------------------------------------
uint32_t DrvRTC_GetUTC( void );
///---------------------------------------------------------------------------------------------------------------------
void    DrvRTC_SetUTC( const uint32_t utc );
///---------------------------------------------------------------------------------------------------------------------
void    DrvRTC_SetDate( const uint8_t day, const uint8_t month, const uint16_t year );
///---------------------------------------------------------------------------------------------------------------------
void    DrvRTC_SetTime( const uint8_t hour, const uint8_t minutes, const uint8_t seconds );
///---------------------------------------------------------------------------------------------------------------------
void    DrvRTC_GetTimeStr( uint8_t* const currTimeStr );
///---------------------------------------------------------------------------------------------------------------------
void    DrvRTC_GetDateStr( uint8_t* const currDateStr );

///=====================================================================================================================
/// @brief RTC OS interface
///=====================================================================================================================
#define configRTC_TASK_STACK_SIZE       ( configMINIMAL_STACK_SIZE / 2 )
#define configRTC_TASK_PRIORITY         ( tskIDLE_PRIORITY + 1 )

extern StackType_t xRtcStack[configRTC_TASK_STACK_SIZE];
extern StaticTask_t xRtcTaskTCBBuffer;
extern TaskHandle_t xRtcToNotify;

extern void DrvRTC_Task( void *pvParameters );
///---------------------------------------------------------------------------------------------------------------------


#endif /// DRV_RTC_H
