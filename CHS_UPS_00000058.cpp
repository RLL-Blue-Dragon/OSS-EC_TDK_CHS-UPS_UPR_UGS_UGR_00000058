// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : CHS_UPS_00000058.cpp
// BSL              : 00000058
// Model number     : TDK CHS-UPS, CHS-UPR, CHS-UGS, CHS-UGR
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 28/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "CHS_UPS.h"

AnalogIn CHS_UPS_adc( iCHS_UPS_pin , iVref );           // AnalogIn object

// Main Function
pp2ap_adc_t CHS_UPS_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( CHS_UPS_adc , tbl_CHS_UPS );
        return( res );
}
