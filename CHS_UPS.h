// License       : License.txt
// Specifications: Spec-CHS-UPS_UPR_UGS_UGR.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : CHS_UPS.h
// Reason for change: 01.00.00 : 28/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __CHS_UPS_H__
#define __CHS_UPS_H__

#include "user_define.h"

// Components number
#define iCHS_UPS                125U                    // TDK CHS-UPS, CHS-UPR, CHS-UGS, CHS-UGR

// CHS-UPS, CHS-UPR, CHS-UGS, CHS-UGR System Parts definitions
#define iCHS_UPS_xoff           0.0F                    // X offset [V]
#define iCHS_UPS_yoff           0.0F                    // Y offset [%RH]
#define iCHS_UPS_gain           0.01F                   // Gain [V/%RH]
#define iCHS_UPS_max            95.0F                   // Humidity Max [%RH]
#define iCHS_UPS_min            5.0F                    // Humidity Min [%RH]

extern const tbl_adc_t tbl_CHS_UPS;

#endif /*__CHS_UPS_H__*/
