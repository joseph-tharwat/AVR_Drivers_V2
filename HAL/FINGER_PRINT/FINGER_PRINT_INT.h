/*
 * FINGER_PRINT_INT.h
 *
 *  Created on: Mar 12, 2023
 *      Author: joseph
 */

#ifndef FINGER_PRINT_FINGER_PRINT_INT_H_
#define FINGER_PRINT_FINGER_PRINT_INT_H_

#include "FINGER_PRINT_TYPES.h"
/*
 * The User will need the "Important" functions only.
 * User mayy use the other functions to make a spacific reason.
 */

//Important
FP_Confirmation_Code H_FP_HandShake();

FP_Confirmation_Code H_FP_CheckSensor();

FP_Confirmation_Code H_FP_CollectFingerImage();

FP_Confirmation_Code H_FP_GenerateCharacterFileFirstScan();

FP_Confirmation_Code H_FP_GenerateCharacterFileSecondScan();

FP_Confirmation_Code H_FP_FirstScan();

FP_Confirmation_Code H_FP_SecondScan();

FP_Confirmation_Code H_FP_GenerateTemplate();

FP_Confirmation_Code H_FP_StoreTemplate(u8 PageID);

//Important
FP_Confirmation_Code H_FP_ScanAndStore(u8 PageID);

FP_Confirmation_Code H_FP_MatchTwoFingerTemplates();

FP_Confirmation_Code H_FP_SearchFingerLibrary(u16 StartPageNumber,u16 SearchingNumbers);

//Important
FP_Confirmation_Code H_FP_ScanAndSearch(u16 StartPageNumber,u16 SearchingNumbers);

FP_Confirmation_Code H_FP_ReadTemplate(u8 PageID);

//Important
FP_Confirmation_Code H_FP_ScanAndVerify(u8 PageID);

//Important
FP_Confirmation_Code H_FP_EmptyLibrary();


#endif /* FINGER_PRINT_FINGER_PRINT_INT_H_ */
