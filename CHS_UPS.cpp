// License       : License.txt
// Specifications: Spec-CHS-UPS-UPR-UGS-UGR.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : CHS_UPS.cpp
// Reason for change: 01.00.00 : 28/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "CHS_UPS.h"

#if     iCHS_UPS_ma == iSMA                             // Simple moving average filter
static float32 CHS_UPS_sma_buf[iCHS_UPS_SMA_num];
static sma_f32_t CHS_UPS_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iCHS_UPS_SMA_num ,                              // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &CHS_UPS_sma_buf[0]                             // buffer
};

#elif   iCHS_UPS_ma == iEMA                             // Exponential moving average filter
static ema_f32_t CHS_UPS_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iCHS_UPS_EMA_K                                  // Exponential smoothing factor
};

#elif   iCHS_UPS_ma == iWMA                             // Weighted moving average filter
static float32 CHS_UPS_wma_buf[iCHS_UPS_WMA_num];
static wma_f32_t CHS_UPS_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iCHS_UPS_WMA_num ,                              // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iCHS_UPS_WMA_num * (iCHS_UPS_WMA_num + 1)/2 ,   // kn sum
        &CHS_UPS_wma_buf[0]                             // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_CHS_UPS =
{
        iCHS_UPS                ,
        iCHS_UPS_pin            ,
        iCHS_UPS_xoff           ,
        iCHS_UPS_yoff           ,
        iCHS_UPS_gain           ,
        iCHS_UPS_max            ,
        iCHS_UPS_min            ,
        iCHS_UPS_ma             ,
        
#if     iCHS_UPS_ma == iSMA                             // Simple moving average filter
        &CHS_UPS_Phy_SMA        ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iCHS_UPS_ma == iEMA                             // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &CHS_UPS_Phy_EMA        ,
        (wma_f32_t*)iDummy_adr
#elif   iCHS_UPS_ma == iWMA                             // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &CHS_UPS_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
