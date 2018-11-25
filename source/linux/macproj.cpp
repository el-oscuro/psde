//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
// MACRO-LIBRARY MAIN ENGINE                                                              //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  The purpose of this program as well as instructions regarding its use is              //11-05-28|0x001b
//  defined in the associated manual.                                                     //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  This program is free software; you can redistribute it and/or modify                  //11-05-28|0x001b
//  it under the terms of the GNU General Public License as published by                  //11-05-28|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //11-05-28|0x001b
//  (at your option) any later version.                                                   //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//  This program is distributed in the hope that it will be useful,                       //11-05-28|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //11-05-28|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //11-05-28|0x001b
//  GNU General Public License for more details.                                          //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//  You should have received a copy of the GNU General Public License                     //11-05-28|0x001b
//  along with this program; if not, write to the Free Software                           //11-05-28|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //11-05-28|0x001b
//  USA                                                                                   //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  For further information, please contact Robert Adams:                                 //11-05-28|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //11-05-28|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //11-05-28|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
#ifdef WIN31_SYSTEM                                                                       //05-24-97|0x001c
#include "precwn31.h"                                                                     //05-24-97|0x001c
#endif                                                                                    //05-24-97|0x001c
#ifdef WIN95_SYSTEM                                                                       //05-24-97|0x001c
#include "precwn95.h"                                                                     //05-24-97|0x001c
#endif                                                                                    //05-24-97|0x001c
#ifdef MSDOS_SYSTEM                                                                       //05-24-97|0x001c
#include "precdos.h"                                                                      //05-24-97|0x001c
#endif                                                                                    //05-24-97|0x001c
#include "prechost.h"                                                                     //05-24-97|0x001c
#include "macproj.h"                                                                      //06-07-14|0x001c
#include "macproj.hxx"                                                                    //06-07-14|0x001c
#include "macproj.hpp"                                                                    //06-07-14|0x001c
#include "precutil.h"                                                                     //06-07-14|0x001d
#include "precdiag.h"                                                                     //06-07-14|0x001e
#include "precfile.h"                                                                     //06-07-14|0x001f
#include "precform.h"                                                                     //06-07-14|0x0020
#include "prectext.h"                                                                     //06-07-14|0x0021
#include "precmac.h"                                                                      //06-07-14|0x0022
#include "macdict.h"                                                                      //06-07-14|0x0023
#include "maccert.h"                                                                      //11-02-17|0x0024
#include "devreport.h"                                                                    //11-02-17|0x0025
#include "apnddict.h"                                                                     //06-07-14|0x0026
#include "precnum.h"                                                                      //09-03-27|0x0027
#include "global.hxx"                                                                     //07-10-30|0x0028
#define Allocate(k) (k##_FAR) calloc(1,sizeof(k))                                         //06-07-14|0x0030
#define Free(k) free(k)                                                                   //06-07-14|0x0030
#define MemSet(i,j,k) memset(i,j,k)                                                       //06-07-14|0x0030
#define MemCCpy(i,j,k,l) Mem_C_Copy((UCHAR_FAR) i, (UCHAR_FAR) j,k,l)                     //06-07-14|0x0030
#define MemCpy(i,j,k) memcpy(i,j,k)                                                       //06-07-14|0x0030
#define LineEnd 0x0d                                                                      //06-07-14|0x0030
#define StrLen(i) strlen(i)                                                               //06-07-14|0x0031
#define StrCat(i,j) strcat(i,j)                                                           //06-07-14|0x0031
#define StrCpy(i,j) strcpy(i,j)                                                           //06-07-14|0x0031
#define StrCmp(i,j) Str_Comp((SCHAR_FAR)i,j,256)                                          //06-07-14|0x0031
#define StrRChr(i,j) strrchr(i,j)                                                         //06-07-14|0x0031
#define StrChr(i,j) strchr(i,j)                                                           //06-07-14|0x0031
#define StrToByteInt(i,j) GetInteger(i,&j,0xff)                                           //06-07-14|0x0031
#define StrToInt(i,j) GetInteger(i,&j,0xffff)                                             //06-07-14|0x0031
#define StrToLongInt(i,j) GetInteger(i,&j,0xffffffffL)                                    //06-07-14|0x0031
#define StrToByteHex(i,j) GetHex(i,&j,1)                                                  //06-07-14|0x0031
#define StrToHex(i,j) GetHex(i,&j,2)                                                      //06-07-14|0x0031
#define StrToLongHex(i,j) GetHex(i,&j,4)                                                  //06-07-14|0x0031
#define FindName(i) strrchr(i, '/')                                                       //06-07-14|0x0031
MACROPROJ macro_proj;                                                                     //06-07-14|0x0054
static UINT test_samples[TestIndex];                                                      //06-07-14|0x0064
//***************************************************************************             //06-07-14|0x006b
//***************************************************************************             //06-07-14|0x006d
//***************************************************************************             //06-07-14|0x0071
//***************************************************************************             //06-07-14|0x0072
//******                                                               ******             //06-07-14|0x0073
//******                       macproj_allocate                        ******             //06-07-14|0x0074
//******                                                               ******             //06-07-14|0x0075
//***************************************************************************             //06-07-14|0x0076
//***************************************************************************             //06-07-14|0x0077
//*******************************************************************************         //10-29-97|0x007e
//*******************************************************************************         //10-29-97|0x007e
// macproj_allocate                                                                       //06-07-14|0x007e
//*******************************************************************************         //10-29-97|0x007e
//*******************************************************************************         //10-29-97|0x007e
UINT MACROPROJ::macproj_allocate(void) {                                                  //06-07-14|0x007e
//*******************************************************************************         //10-29-97|0x007e
//***************************************************************************             //06-07-14|0x0082
//***************************************************************************             //06-07-14|0x0083
    TestSample(macproj_allocate_1);                                                       //06-07-14|0x0084
    if(macro_project_addr                             != 0) ReturnSystemError             //06-07-14|0x0085
    if((macro_project_addr = Allocate(MACRO_PROJECT)) == 0) ReturnSystemError             //06-07-14|0x0086
//***************************************************************************             //06-07-14|0x0087
  MacroProcessState = 4462; // INITIAL_PROJECT                                            //06-08-21|0x0088
  MacroPrepareState = 4462; // ENTER_PROJECT_NAME                                         //06-08-21|0x0089
  MacroBuildState = 4462; // ENTER_PROJECT_NAME                                           //06-08-21|0x008a
//***************************************************************************             //06-07-14|0x008b
    return(Success);                                                                      //06-07-14|0x008c
}                                                                                         //06-07-14|0x008d
//                                                                                        //05-24-97|0x008d
//***************************************************************************             //06-07-14|0x0090
//***************************************************************************             //06-07-14|0x0091
//******                                                               ******             //06-07-14|0x0092
//******                         macproj_free                          ******             //06-07-14|0x0093
//******                                                               ******             //06-07-14|0x0094
//***************************************************************************             //06-07-14|0x0095
//***************************************************************************             //06-07-14|0x0096
//*******************************************************************************         //10-29-97|0x009a
//*******************************************************************************         //10-29-97|0x009a
// macproj_free                                                                           //06-07-14|0x009a
//*******************************************************************************         //10-29-97|0x009a
//*******************************************************************************         //10-29-97|0x009a
UINT MACROPROJ::macproj_free(void) {                                                      //06-07-14|0x009a
//*******************************************************************************         //10-29-97|0x009a
//***************************************************************************             //06-07-14|0x009e
//***************************************************************************             //06-07-14|0x009f
    TestSample(macproj_free_1);                                                           //06-07-14|0x00a0
    if(macro_project_addr == 0)                             ReturnSystemError             //06-07-14|0x00a1
    Free(macro_project_addr);                                                             //06-07-14|0x00a2
    macro_project_addr = 0;                                                               //06-07-14|0x00a3
//***************************************************************************             //06-07-14|0x00a4
    return(Success);                                                                      //06-07-14|0x00a5
}                                                                                         //06-07-14|0x00a6
//                                                                                        //05-24-97|0x00a6
//***************************************************************************             //06-08-16|0x00a9
//***************************************************************************             //06-08-16|0x00aa
//******                                                               ******             //06-08-16|0x00ab
//******                        macproj_process                        ******             //06-08-16|0x00ac
//******---------------------------------------------------------------******             //06-08-16|0x00ad
//******     Token(1):  Project Complete Path-File Name                ******             //06-08-16|0x00ae
//******     Token(2):  Library Path                                   ******             //06-08-16|0x00af
//******     Token(3):  Macro Path                                     ******             //06-08-16|0x00b0
//******                                                               ******             //06-08-16|0x00b1
//***************************************************************************             //06-08-16|0x00b2
//***************************************************************************             //06-08-16|0x00b3
//*******************************************************************************         //10-29-97|0x00b7
//*******************************************************************************         //10-29-97|0x00b7
// macproj_process                                                                        //09-03-27|0x00b7
//*******************************************************************************         //10-29-97|0x00b7
//*******************************************************************************         //10-29-97|0x00b7
UINT MACROPROJ::macproj_process(                                                          //09-03-27|0x00b7
    TOKENS_FAR InputAddr,                                                                 //09-03-27|0x00b7
    ULONG UpdateTime,                                                                     //09-03-27|0x00b7
    UINT_FAR TaskNoFar                                                                    //09-03-27|0x00b7
    ) {                                                                                   //09-03-27|0x00b7
//*******************************************************************************         //10-29-97|0x00b7
//***************************************************************************             //06-08-16|0x00bb
//***************************************************************************             //06-08-16|0x00bc
    if(macro_project_addr == 0)                             ReturnSystemError             //06-08-16|0x00bd
    if((InputNoTokens == 0) || (InputNoTokens > 10))       ReturnSystemError;             //06-08-16|0x00be
//***************************************************************************             //06-08-21|0x00bf
//******                                                               ******             //06-08-21|0x00c0
//****** State Machine Beginning                                       ******             //06-08-21|0x00c1
//******                                                               ******             //06-08-21|0x00c2
//***************************************************************************             //06-08-21|0x00c3
  MacroRunFlag = 1;                                                                       //06-08-21|0x00c4
  while(MacroRunFlag != 0)                                                                //06-08-21|0x00c4
  {                                                                                       //06-08-21|0x00c4
    switch(MacroProcessState)                                                             //06-08-21|0x00c4
    {                                                                                     //06-08-21|0x00c4
//***************************************************************************             //06-08-21|0x00c5
//******                                                               ******             //06-08-21|0x00c6
//****** Initial time                                                  ******             //06-08-21|0x00c7
//******                                                               ******             //06-08-21|0x00c8
//***************************************************************************             //06-08-21|0x00c9
      case 4462: // INITIAL_PROJECT                                                       //08-04-16|0x00ca
        MacroExternalTime = UpdateTime;                                                   //08-04-16|0x00ca
        MacroProcessState = 10445; // DISPLAY_OFF                                         //08-04-16|0x00ca
        break;                                                                            //08-04-16|0x00ca
//***************************************************************************             //11-02-19|0x00cb
//******                                                               ******             //11-02-19|0x00cc
//****** Initial display                                               ******             //11-02-19|0x00cd
//******                                                               ******             //11-02-19|0x00ce
//***************************************************************************             //11-02-19|0x00cf
      case 10445: // DISPLAY_OFF                                                          //11-02-19|0x00d0
        DisplayOff();                                                                     //11-02-19|0x00d0
        MacroProcessState = 46620; // CREATE_PARITY                                       //11-02-19|0x00d0
        break;                                                                            //11-02-19|0x00d0
//***************************************************************************             //11-02-19|0x00d1
//******                                                               ******             //11-02-19|0x00d2
//****** Create Certification File                                     ******             //11-02-19|0x00d3
//******                                                               ******             //11-02-19|0x00d4
//***************************************************************************             //11-02-19|0x00d5
      case 46620: // CREATE_PARITY                                                        //11-08-17|0x00d6
        switch(MacroCreateCertify)                                                        //11-08-17|0x00d6
        {                                                                                 //11-08-17|0x00d6
          case Success:                                                                   //11-08-17|0x00d6
            MacroRunFlag = 1;                                                             //11-08-17|0x00d6
            MacroProcessState = 6235; // PREPARE_PROJECT                                  //11-08-17|0x00d6
            break;                                                                        //11-08-17|0x00d6
          case UserError:                                                                 //11-08-17|0x00d6
            MacroRunFlag = 1;                                                             //11-08-17|0x00d6
            MacroProcessState = 40586; // USER_ERROR                                      //11-08-17|0x00d6
            break;                                                                        //11-08-17|0x00d6
          default:                                                                        //11-08-17|0x00d6
            MacroStatus = SystemError;                                                    //11-08-17|0x00d6
            MacroRunFlag = 0;                                                             //11-08-17|0x00d6
            SystemMsg;                                                                    //11-08-17|0x00d6
            break;                                                                        //11-08-17|0x00d6
        }                                                                                 //11-08-17|0x00d6
        break;                                                                            //11-08-17|0x00d6
//***************************************************************************             //06-08-21|0x00d7
//******                                                               ******             //06-08-21|0x00d8
//****** Macro Date Analysis                                           ******             //06-08-21|0x00d9
//******                                                               ******             //06-08-21|0x00da
//***************************************************************************             //06-08-21|0x00db
      case 6235: // PREPARE_PROJECT                                                       //11-02-12|0x00dc
        switch(MacProjPrepare)                                                            //11-02-12|0x00dc
        {                                                                                 //11-02-12|0x00dc
          case Display:                                                                   //11-02-12|0x00dc
            MacroProcessState = 34729; // PREPARE_PROJECT_EXIT                            //11-02-12|0x00dc
            MacroStatus = Display;                                                        //11-02-12|0x00dc
            MacroRunFlag = 0;                                                             //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
          case Success:                                                                   //11-02-12|0x00dc
            MacroRunFlag = 1;                                                             //11-02-12|0x00dc
            MacroProcessState = 696; // BUILD_TEST                                        //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
          case UserError:                                                                 //11-02-12|0x00dc
            MacroRunFlag = 1;                                                             //11-02-12|0x00dc
            MacroProcessState = 11959; // USER_ERROR_DISPLAY                              //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
          default:                                                                        //11-02-12|0x00dc
            MacroStatus = SystemError;                                                    //11-02-12|0x00dc
            MacroRunFlag = 0;                                                             //11-02-12|0x00dc
            SystemMsg;                                                                    //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
        }                                                                                 //11-02-12|0x00dc
        break;                                                                            //11-02-12|0x00dc
//**************************************************************************              //11-02-12|0x00dc
      case 34729: // PREPARE_PROJECT_EXIT                                                 //11-02-12|0x00dc
        switch(MacProjPrepare)                                                            //11-02-12|0x00dc
        {                                                                                 //11-02-12|0x00dc
          case Display:                                                                   //11-02-12|0x00dc
            MacroProcessState = 34729; // PREPARE_PROJECT_EXIT                            //11-02-12|0x00dc
            MacroStatus = Display;                                                        //11-02-12|0x00dc
            MacroRunFlag = 0;                                                             //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
          case Success:                                                                   //11-02-12|0x00dc
            MacroRunFlag = 1;                                                             //11-02-12|0x00dc
            MacroProcessState = 696; // BUILD_TEST                                        //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
          case UserError:                                                                 //11-02-12|0x00dc
            MacroRunFlag = 1;                                                             //11-02-12|0x00dc
            MacroProcessState = 11959; // USER_ERROR_DISPLAY                              //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
          default:                                                                        //11-02-12|0x00dc
            MacroStatus = SystemError;                                                    //11-02-12|0x00dc
            MacroRunFlag = 0;                                                             //11-02-12|0x00dc
            SystemMsg;                                                                    //11-02-12|0x00dc
            break;                                                                        //11-02-12|0x00dc
        }                                                                                 //11-02-12|0x00dc
        break;                                                                            //11-02-12|0x00dc
//---------------------------------------------------------------------------             //11-02-12|0x00dd
      case 696: // BUILD_TEST                                                             //11-02-13|0x00de
        switch(FileUpdateRequired)                                                        //11-02-13|0x00de
        {                                                                                 //11-02-13|0x00de
          case Yes:                                                                       //11-02-13|0x00de
            MacroRunFlag = 1;                                                             //11-02-13|0x00de
            MacroProcessState = 6822; // BUILD_OK                                         //11-02-13|0x00de
            break;                                                                        //11-02-13|0x00de
          case No:                                                                        //11-02-13|0x00de
            MacroRunFlag = 1;                                                             //11-02-13|0x00de
            MacroProcessState = 50565; // SUCCESS_DISPLAY                                 //11-02-13|0x00de
            break;                                                                        //11-02-13|0x00de
          default:                                                                        //11-02-13|0x00de
            MacroStatus = SystemError;                                                    //11-02-13|0x00de
            MacroRunFlag = 0;                                                             //11-02-13|0x00de
            SystemMsg;                                                                    //11-02-13|0x00de
            break;                                                                        //11-02-13|0x00de
        }                                                                                 //11-02-13|0x00de
        break;                                                                            //11-02-13|0x00de
//***************************************************************************             //06-08-21|0x00df
//******                                                               ******             //06-08-21|0x00e0
//****** Macro Create Library                                          ******             //06-08-21|0x00e1
//******                                                               ******             //06-08-21|0x00e2
//***************************************************************************             //06-08-21|0x00e3
      case 6822: // BUILD_OK                                                              //11-02-12|0x00e4
        DisplayOn();                                                                      //11-02-12|0x00e4
        MacroProcessState = 7764; // BUILD_PROJECT                                        //11-02-12|0x00e4
        break;                                                                            //11-02-12|0x00e4
//---------------------------------------------------------------------------             //11-02-12|0x00e5
      case 7764: // BUILD_PROJECT                                                         //11-02-12|0x00e6
        switch(MacProjBuild)                                                              //11-02-12|0x00e6
        {                                                                                 //11-02-12|0x00e6
          case Display:                                                                   //11-02-12|0x00e6
            MacroProcessState = 1043; // BUILD_PROJECT_EXIT                               //11-02-12|0x00e6
            MacroStatus = Display;                                                        //11-02-12|0x00e6
            MacroRunFlag = 0;                                                             //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
          case Success:                                                                   //11-02-12|0x00e6
            MacroRunFlag = 1;                                                             //11-02-12|0x00e6
            MacroProcessState = 50565; // SUCCESS_DISPLAY                                 //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
          case UserError:                                                                 //11-02-12|0x00e6
            MacroRunFlag = 1;                                                             //11-02-12|0x00e6
            MacroProcessState = 11959; // USER_ERROR_DISPLAY                              //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
          default:                                                                        //11-02-12|0x00e6
            MacroStatus = SystemError;                                                    //11-02-12|0x00e6
            MacroRunFlag = 0;                                                             //11-02-12|0x00e6
            SystemMsg;                                                                    //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
        }                                                                                 //11-02-12|0x00e6
        break;                                                                            //11-02-12|0x00e6
//**************************************************************************              //11-02-12|0x00e6
      case 1043: // BUILD_PROJECT_EXIT                                                    //11-02-12|0x00e6
        switch(MacProjBuild)                                                              //11-02-12|0x00e6
        {                                                                                 //11-02-12|0x00e6
          case Display:                                                                   //11-02-12|0x00e6
            MacroProcessState = 1043; // BUILD_PROJECT_EXIT                               //11-02-12|0x00e6
            MacroStatus = Display;                                                        //11-02-12|0x00e6
            MacroRunFlag = 0;                                                             //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
          case Success:                                                                   //11-02-12|0x00e6
            MacroRunFlag = 1;                                                             //11-02-12|0x00e6
            MacroProcessState = 50565; // SUCCESS_DISPLAY                                 //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
          case UserError:                                                                 //11-02-12|0x00e6
            MacroRunFlag = 1;                                                             //11-02-12|0x00e6
            MacroProcessState = 11959; // USER_ERROR_DISPLAY                              //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
          default:                                                                        //11-02-12|0x00e6
            MacroStatus = SystemError;                                                    //11-02-12|0x00e6
            MacroRunFlag = 0;                                                             //11-02-12|0x00e6
            SystemMsg;                                                                    //11-02-12|0x00e6
            break;                                                                        //11-02-12|0x00e6
        }                                                                                 //11-02-12|0x00e6
        break;                                                                            //11-02-12|0x00e6
//***************************************************************************             //06-08-21|0x00e7
//******                                                               ******             //06-08-21|0x00e8
//****** Exit States                                                   ******             //06-08-21|0x00e9
//******                                                               ******             //06-08-21|0x00ea
//***************************************************************************             //06-08-21|0x00eb
      case 50565: // SUCCESS_DISPLAY                                                      //11-02-12|0x00ec
        DisplayOn();                                                                      //11-02-12|0x00ec
        MacroProcessState = 17858; // PARITY_SUCCESS                                      //11-02-12|0x00ec
        break;                                                                            //11-02-12|0x00ec
//---------------------------------------------------------------------------             //11-02-12|0x00ed
      case 17858: // PARITY_SUCCESS                                                       //11-02-18|0x00ee
        switch(MacCertDelete())                                                           //11-02-18|0x00ee
        {                                                                                 //11-02-18|0x00ee
          case Success:                                                                   //11-02-18|0x00ee
            MacroRunFlag = 1;                                                             //11-02-18|0x00ee
            MacroProcessState = 41569; // SUCCESS                                         //11-02-18|0x00ee
            break;                                                                        //11-02-18|0x00ee
          default:                                                                        //11-02-18|0x00ee
            MacroStatus = SystemError;                                                    //11-02-18|0x00ee
            MacroRunFlag = 0;                                                             //11-02-18|0x00ee
            SystemMsg;                                                                    //11-02-18|0x00ee
            break;                                                                        //11-02-18|0x00ee
        }                                                                                 //11-02-18|0x00ee
        break;                                                                            //11-02-18|0x00ee
//---------------------------------------------------------------------------             //11-02-18|0x00ef
      case 41569: // SUCCESS                                                              //11-02-18|0x00f0
        MacroProcessState = 4462; // INITIAL_PROJECT                                      //11-02-18|0x00f0
        MacroStatus = Success;                                                            //11-02-18|0x00f0
        MacroRunFlag = 0;                                                                 //11-02-18|0x00f0
        break;                                                                            //11-02-18|0x00f0
//***************************************************************************             //11-02-18|0x00f1
      case 11959: // USER_ERROR_DISPLAY                                                   //11-02-18|0x00f2
        DisplayOn();                                                                      //11-02-18|0x00f2
        MacroProcessState = 51440; // PARITY_ERROR                                        //11-02-18|0x00f2
        break;                                                                            //11-02-18|0x00f2
//---------------------------------------------------------------------------             //11-02-18|0x00f3
      case 51440: // PARITY_ERROR                                                         //11-02-18|0x00f4
        switch(MacCertDelete())                                                           //11-02-18|0x00f4
        {                                                                                 //11-02-18|0x00f4
          case Success:                                                                   //11-02-18|0x00f4
            MacroRunFlag = 1;                                                             //11-02-18|0x00f4
            MacroProcessState = 40586; // USER_ERROR                                      //11-02-18|0x00f4
            break;                                                                        //11-02-18|0x00f4
          default:                                                                        //11-02-18|0x00f4
            MacroStatus = SystemError;                                                    //11-02-18|0x00f4
            MacroRunFlag = 0;                                                             //11-02-18|0x00f4
            SystemMsg;                                                                    //11-02-18|0x00f4
            break;                                                                        //11-02-18|0x00f4
        }                                                                                 //11-02-18|0x00f4
        break;                                                                            //11-02-18|0x00f4
//---------------------------------------------------------------------------             //11-02-18|0x00f5
      case 40586: // USER_ERROR                                                           //11-02-18|0x00f6
        MacroProcessState = 4462; // INITIAL_PROJECT                                      //11-02-18|0x00f6
        MacroStatus = UserError;                                                          //11-02-18|0x00f6
        MacroRunFlag = 0;                                                                 //11-02-18|0x00f6
        break;                                                                            //11-02-18|0x00f6
//***************************************************************************             //06-08-21|0x00f7
      default:                                                                            //06-08-21|0x00f8
        MacroStatus = SystemError;                                                        //06-08-21|0x00f8
        MacroRunFlag = 0;                                                                 //06-08-21|0x00f8
        SystemMsg;                                                                        //06-08-21|0x00f8
        break;                                                                            //06-08-21|0x00f8
    }                                                                                     //06-08-21|0x00f8
  }                                                                                       //06-08-21|0x00f8
//***************************************************************************             //06-08-21|0x00f9
//***************************************************************************             //06-08-21|0x00fa
    return(MacroStatus);                                                                  //06-08-21|0x00fb
}                                                                                         //06-08-21|0x00fe
//                                                                                        //05-24-97|0x00fe
//***************************************************************************             //06-08-16|0x0101
//***************************************************************************             //06-08-16|0x0102
//******                                                               ******             //06-08-16|0x0103
//******                        macproj_prepare                        ******             //06-08-16|0x0104
//******---------------------------------------------------------------******             //06-08-16|0x0105
//******     Token(1):  Project Complete Path-File Name                ******             //06-08-16|0x0106
//******     Token(2):  Library Path                                   ******             //06-08-16|0x0107
//******     Token(3):  Macro Path                                     ******             //06-08-16|0x0108
//******                                                               ******             //06-08-16|0x0109
//***************************************************************************             //06-08-16|0x010a
//***************************************************************************             //06-08-16|0x010b
//*******************************************************************************         //10-29-97|0x010f
//*******************************************************************************         //10-29-97|0x010f
// macproj_prepare                                                                        //09-03-27|0x010f
//*******************************************************************************         //10-29-97|0x010f
//*******************************************************************************         //10-29-97|0x010f
UINT MACROPROJ::macproj_prepare(                                                          //09-03-27|0x010f
    TOKENS_FAR InputAddr,                                                                 //09-03-27|0x010f
    UINT_FAR TaskNoFar                                                                    //09-03-27|0x010f
    ) {                                                                                   //09-03-27|0x010f
//*******************************************************************************         //10-29-97|0x010f
//***************************************************************************             //06-08-16|0x0112
//***************************************************************************             //06-08-16|0x0113
    if(macro_project_addr == 0)                             ReturnSystemError             //06-08-16|0x0114
//***************************************************************************             //06-08-16|0x0115
//******                                                               ******             //06-08-16|0x0116
//****** State Machine Beginning                                       ******             //06-08-16|0x0117
//******                                                               ******             //06-08-16|0x0118
//***************************************************************************             //06-08-16|0x0119
  MacroRunFlag = 1;                                                                       //06-08-21|0x011a
  while(MacroRunFlag != 0)                                                                //06-08-21|0x011a
  {                                                                                       //06-08-21|0x011a
    switch(MacroPrepareState)                                                             //06-08-21|0x011a
    {                                                                                     //06-08-21|0x011a
//***************************************************************************             //06-08-16|0x011b
//******                                                               ******             //06-08-16|0x011c
//****** Open Project File,                                            ******             //06-08-16|0x011d
//******                                                               ******             //06-08-16|0x011e
//***************************************************************************             //06-08-16|0x011f
      case 4462: // ENTER_PROJECT_NAME                                                    //06-08-16|0x0120
        switch(EnterProjectName)                                                          //06-08-16|0x0120
        {                                                                                 //06-08-16|0x0120
          case Success:                                                                   //06-08-16|0x0120
            MacroRunFlag = 1;                                                             //06-08-16|0x0120
            MacroPrepareState = 10445; // PROJECT_FILE_DATE                               //06-08-16|0x0120
            break;                                                                        //06-08-16|0x0120
          default:                                                                        //06-08-16|0x0120
            MacroStatus = SystemError;                                                    //06-08-16|0x0120
            MacroRunFlag = 0;                                                             //06-08-16|0x0120
            SystemMsg;                                                                    //06-08-16|0x0120
            break;                                                                        //06-08-16|0x0120
        }                                                                                 //06-08-16|0x0120
        break;                                                                            //06-08-16|0x0120
//---------------------------------------------------------------------------             //06-08-16|0x0121
      case 10445: // PROJECT_FILE_DATE                                                    //06-08-16|0x0122
        switch(ProjectFileTime)                                                           //06-08-16|0x0122
        {                                                                                 //06-08-16|0x0122
          case Success:                                                                   //06-08-16|0x0122
            MacroRunFlag = 1;                                                             //06-08-16|0x0122
            MacroPrepareState = 46620; // PROJECT_FILE_EXIST                              //06-08-16|0x0122
            break;                                                                        //06-08-16|0x0122
          default:                                                                        //06-08-16|0x0122
            MacroStatus = SystemError;                                                    //06-08-16|0x0122
            MacroRunFlag = 0;                                                             //06-08-16|0x0122
            SystemMsg;                                                                    //06-08-16|0x0122
            break;                                                                        //06-08-16|0x0122
        }                                                                                 //06-08-16|0x0122
        break;                                                                            //06-08-16|0x0122
//---------------------------------------------------------------------------             //06-08-16|0x0123
      case 46620: // PROJECT_FILE_EXIST                                                   //11-02-12|0x0124
        switch(FileInDateExists)                                                          //11-02-12|0x0124
        {                                                                                 //11-02-12|0x0124
          case Yes:                                                                       //11-02-12|0x0124
            MacroRunFlag = 1;                                                             //11-02-12|0x0124
            MacroPrepareState = 6235; // EXTERNAL_DATE_TEST                               //11-02-12|0x0124
            break;                                                                        //11-02-12|0x0124
          case No:                                                                        //11-02-12|0x0124
            MacroRunFlag = 1;                                                             //11-02-12|0x0124
            MacroPrepareState = 40586; // NO_PROJECT_FILE                                 //11-02-12|0x0124
            break;                                                                        //11-02-12|0x0124
          default:                                                                        //11-02-12|0x0124
            MacroStatus = SystemError;                                                    //11-02-12|0x0124
            MacroRunFlag = 0;                                                             //11-02-12|0x0124
            SystemMsg;                                                                    //11-02-12|0x0124
            break;                                                                        //11-02-12|0x0124
        }                                                                                 //11-02-12|0x0124
        break;                                                                            //11-02-12|0x0124
//---------------------------------------------------------------------------             //11-02-12|0x0125
      case 6235: // EXTERNAL_DATE_TEST                                                    //11-02-12|0x0126
        ExternalDateTest;                                                                 //11-02-12|0x0126
        MacroPrepareState = 34729; // OPEN_PROJ                                           //11-02-12|0x0126
        break;                                                                            //11-02-12|0x0126
//---------------------------------------------------------------------------             //06-08-16|0x0127
      case 40586: // NO_PROJECT_FILE                                                      //06-08-16|0x0128
        switch(ProjectDoesNotExist)                                                       //06-08-16|0x0128
        {                                                                                 //06-08-16|0x0128
          case UserError:                                                                 //06-08-16|0x0128
            MacroRunFlag = 1;                                                             //06-08-16|0x0128
            MacroPrepareState = 696; // ERROR                                             //06-08-16|0x0128
            break;                                                                        //06-08-16|0x0128
          default:                                                                        //06-08-16|0x0128
            MacroStatus = SystemError;                                                    //06-08-16|0x0128
            MacroRunFlag = 0;                                                             //06-08-16|0x0128
            SystemMsg;                                                                    //06-08-16|0x0128
            break;                                                                        //06-08-16|0x0128
        }                                                                                 //06-08-16|0x0128
        break;                                                                            //06-08-16|0x0128
//---------------------------------------------------------------------------             //06-08-17|0x0129
      case 34729: // OPEN_PROJ                                                            //11-06-13|0x012a
        switch(OpenProject)                                                               //11-06-13|0x012a
        {                                                                                 //11-06-13|0x012a
          case Success:                                                                   //11-06-13|0x012a
            MacroRunFlag = 1;                                                             //11-06-13|0x012a
            MacroPrepareState = 11959; // READ_DISPLAY                                    //11-06-13|0x012a
            break;                                                                        //11-06-13|0x012a
          default:                                                                        //11-06-13|0x012a
            MacroStatus = SystemError;                                                    //11-06-13|0x012a
            MacroRunFlag = 0;                                                             //11-06-13|0x012a
            SystemMsg;                                                                    //11-06-13|0x012a
            break;                                                                        //11-06-13|0x012a
        }                                                                                 //11-06-13|0x012a
        break;                                                                            //11-06-13|0x012a
//***************************************************************************             //11-06-13|0x012b
//******                                                               ******             //11-06-13|0x012c
//****** Process Display                                               ******             //11-06-13|0x012d
//******                                                               ******             //11-06-13|0x012e
//***************************************************************************             //11-06-13|0x012f
      case 11959: // READ_DISPLAY                                                         //11-06-13|0x0130
        switch(ReadProject)                                                               //11-06-13|0x0130
        {                                                                                 //11-06-13|0x0130
          case Display:                                                                   //11-06-13|0x0130
            MacroPrepareState = 6822; // READ_DISPLAY_EXIT                                //11-06-13|0x0130
            MacroStatus = Display;                                                        //11-06-13|0x0130
            MacroRunFlag = 0;                                                             //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          case LineDone:                                                                  //11-06-13|0x0130
            MacroRunFlag = 1;                                                             //11-06-13|0x0130
            MacroPrepareState = 50565; // DISPLAY                                         //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          case FileDone:                                                                  //11-06-13|0x0130
            MacroRunFlag = 1;                                                             //11-06-13|0x0130
            MacroPrepareState = 7764; // END_FILE                                         //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          case UserError:                                                                 //11-06-13|0x0130
            MacroRunFlag = 1;                                                             //11-06-13|0x0130
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          default:                                                                        //11-06-13|0x0130
            MacroStatus = SystemError;                                                    //11-06-13|0x0130
            MacroRunFlag = 0;                                                             //11-06-13|0x0130
            SystemMsg;                                                                    //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
        }                                                                                 //11-06-13|0x0130
        break;                                                                            //11-06-13|0x0130
//**************************************************************************              //11-06-13|0x0130
      case 6822: // READ_DISPLAY_EXIT                                                     //11-06-13|0x0130
        switch(ReadProject)                                                               //11-06-13|0x0130
        {                                                                                 //11-06-13|0x0130
          case Display:                                                                   //11-06-13|0x0130
            MacroPrepareState = 6822; // READ_DISPLAY_EXIT                                //11-06-13|0x0130
            MacroStatus = Display;                                                        //11-06-13|0x0130
            MacroRunFlag = 0;                                                             //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          case LineDone:                                                                  //11-06-13|0x0130
            MacroRunFlag = 1;                                                             //11-06-13|0x0130
            MacroPrepareState = 50565; // DISPLAY                                         //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          case FileDone:                                                                  //11-06-13|0x0130
            MacroRunFlag = 1;                                                             //11-06-13|0x0130
            MacroPrepareState = 7764; // END_FILE                                         //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          case UserError:                                                                 //11-06-13|0x0130
            MacroRunFlag = 1;                                                             //11-06-13|0x0130
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
          default:                                                                        //11-06-13|0x0130
            MacroStatus = SystemError;                                                    //11-06-13|0x0130
            MacroRunFlag = 0;                                                             //11-06-13|0x0130
            SystemMsg;                                                                    //11-06-13|0x0130
            break;                                                                        //11-06-13|0x0130
        }                                                                                 //11-06-13|0x0130
        break;                                                                            //11-06-13|0x0130
//---------------------------------------------------------------------------             //11-06-13|0x0131
      case 50565: // DISPLAY                                                              //11-06-13|0x0132
        switch(CmdTest("_DISPLAY"))                                                       //11-06-13|0x0132
        {                                                                                 //11-06-13|0x0132
          case -1:                                                                        //11-06-13|0x0132
            MacroRunFlag = 1;                                                             //11-06-13|0x0132
            MacroPrepareState = 17858; // TASK_NO                                         //11-06-13|0x0132
            break;                                                                        //11-06-13|0x0132
          case 0:                                                                         //11-06-13|0x0132
            MacroRunFlag = 1;                                                             //11-06-13|0x0132
            MacroPrepareState = 41569; // ENABLE_DISPLAY                                  //11-06-13|0x0132
            break;                                                                        //11-06-13|0x0132
          case 1:                                                                         //11-06-13|0x0132
            MacroRunFlag = 1;                                                             //11-06-13|0x0132
            MacroPrepareState = 17858; // TASK_NO                                         //11-06-13|0x0132
            break;                                                                        //11-06-13|0x0132
          default:                                                                        //11-06-13|0x0132
            MacroStatus = SystemError;                                                    //11-06-13|0x0132
            MacroRunFlag = 0;                                                             //11-06-13|0x0132
            SystemMsg;                                                                    //11-06-13|0x0132
            break;                                                                        //11-06-13|0x0132
        }                                                                                 //11-06-13|0x0132
        break;                                                                            //11-06-13|0x0132
//---------------------------------------------------------------------------             //11-06-13|0x0133
      case 41569: // ENABLE_DISPLAY                                                       //11-06-13|0x0134
        switch(enable_display())                                                          //11-06-13|0x0134
        {                                                                                 //11-06-13|0x0134
          case Success:                                                                   //11-06-13|0x0134
            MacroRunFlag = 1;                                                             //11-06-13|0x0134
            MacroPrepareState = 51440; // READ_TASK_NO                                    //11-06-13|0x0134
            break;                                                                        //11-06-13|0x0134
          case UserError:                                                                 //11-06-13|0x0134
            MacroRunFlag = 1;                                                             //11-06-13|0x0134
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-06-13|0x0134
            break;                                                                        //11-06-13|0x0134
          default:                                                                        //11-06-13|0x0134
            MacroStatus = SystemError;                                                    //11-06-13|0x0134
            MacroRunFlag = 0;                                                             //11-06-13|0x0134
            SystemMsg;                                                                    //11-06-13|0x0134
            break;                                                                        //11-06-13|0x0134
        }                                                                                 //11-06-13|0x0134
        break;                                                                            //11-06-13|0x0134
//***************************************************************************             //07-10-30|0x0135
//******                                                               ******             //07-10-30|0x0136
//****** Process Task No                                               ******             //11-06-13|0x0137
//******                                                               ******             //07-10-30|0x0138
//***************************************************************************             //07-10-30|0x0139
      case 51440: // READ_TASK_NO                                                         //09-03-27|0x013a
        switch(ReadProject)                                                               //09-03-27|0x013a
        {                                                                                 //09-03-27|0x013a
          case Display:                                                                   //09-03-27|0x013a
            MacroPrepareState = 22639; // READ_TASK_NO_EXIT                               //09-03-27|0x013a
            MacroStatus = Display;                                                        //09-03-27|0x013a
            MacroRunFlag = 0;                                                             //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          case LineDone:                                                                  //09-03-27|0x013a
            MacroRunFlag = 1;                                                             //09-03-27|0x013a
            MacroPrepareState = 17858; // TASK_NO                                         //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          case FileDone:                                                                  //09-03-27|0x013a
            MacroRunFlag = 1;                                                             //09-03-27|0x013a
            MacroPrepareState = 7764; // END_FILE                                         //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          case UserError:                                                                 //09-03-27|0x013a
            MacroRunFlag = 1;                                                             //09-03-27|0x013a
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          default:                                                                        //09-03-27|0x013a
            MacroStatus = SystemError;                                                    //09-03-27|0x013a
            MacroRunFlag = 0;                                                             //09-03-27|0x013a
            SystemMsg;                                                                    //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
        }                                                                                 //09-03-27|0x013a
        break;                                                                            //09-03-27|0x013a
//**************************************************************************              //09-03-27|0x013a
      case 22639: // READ_TASK_NO_EXIT                                                    //09-03-27|0x013a
        switch(ReadProject)                                                               //09-03-27|0x013a
        {                                                                                 //09-03-27|0x013a
          case Display:                                                                   //09-03-27|0x013a
            MacroPrepareState = 22639; // READ_TASK_NO_EXIT                               //09-03-27|0x013a
            MacroStatus = Display;                                                        //09-03-27|0x013a
            MacroRunFlag = 0;                                                             //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          case LineDone:                                                                  //09-03-27|0x013a
            MacroRunFlag = 1;                                                             //09-03-27|0x013a
            MacroPrepareState = 17858; // TASK_NO                                         //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          case FileDone:                                                                  //09-03-27|0x013a
            MacroRunFlag = 1;                                                             //09-03-27|0x013a
            MacroPrepareState = 7764; // END_FILE                                         //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          case UserError:                                                                 //09-03-27|0x013a
            MacroRunFlag = 1;                                                             //09-03-27|0x013a
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
          default:                                                                        //09-03-27|0x013a
            MacroStatus = SystemError;                                                    //09-03-27|0x013a
            MacroRunFlag = 0;                                                             //09-03-27|0x013a
            SystemMsg;                                                                    //09-03-27|0x013a
            break;                                                                        //09-03-27|0x013a
        }                                                                                 //09-03-27|0x013a
        break;                                                                            //09-03-27|0x013a
//---------------------------------------------------------------------------             //09-03-27|0x013b
      case 17858: // TASK_NO                                                              //09-03-27|0x013c
        switch(CmdTest("_TASK_NO"))                                                       //09-03-27|0x013c
        {                                                                                 //09-03-27|0x013c
          case -1:                                                                        //09-03-27|0x013c
            MacroRunFlag = 1;                                                             //09-03-27|0x013c
            MacroPrepareState = 57310; // COMMAND_ERROR                                   //09-03-27|0x013c
            break;                                                                        //09-03-27|0x013c
          case 0:                                                                         //09-03-27|0x013c
            MacroRunFlag = 1;                                                             //09-03-27|0x013c
            MacroPrepareState = 56893; // TASK_NUMBER                                     //09-03-27|0x013c
            break;                                                                        //09-03-27|0x013c
          case 1:                                                                         //09-03-27|0x013c
            MacroRunFlag = 1;                                                             //09-03-27|0x013c
            MacroPrepareState = 57310; // COMMAND_ERROR                                   //09-03-27|0x013c
            break;                                                                        //09-03-27|0x013c
          default:                                                                        //09-03-27|0x013c
            MacroStatus = SystemError;                                                    //09-03-27|0x013c
            MacroRunFlag = 0;                                                             //09-03-27|0x013c
            SystemMsg;                                                                    //09-03-27|0x013c
            break;                                                                        //09-03-27|0x013c
        }                                                                                 //09-03-27|0x013c
        break;                                                                            //09-03-27|0x013c
//---------------------------------------------------------------------------             //09-03-27|0x013d
      case 56893: // TASK_NUMBER                                                          //09-03-27|0x013e
        switch(text_prepare())                                                            //09-03-27|0x013e
        {                                                                                 //09-03-27|0x013e
          case Success:                                                                   //09-03-27|0x013e
            MacroRunFlag = 1;                                                             //09-03-27|0x013e
            MacroPrepareState = 49804; // LOAD_TASK_NO                                    //09-03-27|0x013e
            break;                                                                        //09-03-27|0x013e
          case UserError:                                                                 //09-03-27|0x013e
            MacroRunFlag = 1;                                                             //09-03-27|0x013e
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //09-03-27|0x013e
            break;                                                                        //09-03-27|0x013e
          default:                                                                        //09-03-27|0x013e
            MacroStatus = SystemError;                                                    //09-03-27|0x013e
            MacroRunFlag = 0;                                                             //09-03-27|0x013e
            SystemMsg;                                                                    //09-03-27|0x013e
            break;                                                                        //09-03-27|0x013e
        }                                                                                 //09-03-27|0x013e
        break;                                                                            //09-03-27|0x013e
//---------------------------------------------------------------------------             //09-03-27|0x013f
      case 49804: // LOAD_TASK_NO                                                         //09-03-27|0x0140
        switch(UpdateTaskNo)                                                              //09-03-27|0x0140
        {                                                                                 //09-03-27|0x0140
          case Success:                                                                   //09-03-27|0x0140
            MacroRunFlag = 1;                                                             //09-03-27|0x0140
            MacroPrepareState = 60363; // READ_UPDATE                                     //09-03-27|0x0140
            break;                                                                        //09-03-27|0x0140
          case UserError:                                                                 //09-03-27|0x0140
            MacroRunFlag = 1;                                                             //09-03-27|0x0140
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //09-03-27|0x0140
            break;                                                                        //09-03-27|0x0140
          default:                                                                        //09-03-27|0x0140
            MacroStatus = SystemError;                                                    //09-03-27|0x0140
            MacroRunFlag = 0;                                                             //09-03-27|0x0140
            SystemMsg;                                                                    //09-03-27|0x0140
            break;                                                                        //09-03-27|0x0140
        }                                                                                 //09-03-27|0x0140
        break;                                                                            //09-03-27|0x0140
//***************************************************************************             //07-10-30|0x0141
//******                                                               ******             //07-10-30|0x0142
//****** Process Update                                                ******             //07-10-30|0x0143
//******                                                               ******             //07-10-30|0x0144
//***************************************************************************             //07-10-30|0x0145
      case 60363: // READ_UPDATE                                                          //07-10-30|0x0146
        switch(ReadProject)                                                               //07-10-30|0x0146
        {                                                                                 //07-10-30|0x0146
          case Display:                                                                   //07-10-30|0x0146
            MacroPrepareState = 43258; // READ_UPDATE_EXIT                                //07-10-30|0x0146
            MacroStatus = Display;                                                        //07-10-30|0x0146
            MacroRunFlag = 0;                                                             //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          case LineDone:                                                                  //07-10-30|0x0146
            MacroRunFlag = 1;                                                             //07-10-30|0x0146
            MacroPrepareState = 14617; // UPDATE                                          //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          case FileDone:                                                                  //07-10-30|0x0146
            MacroRunFlag = 1;                                                             //07-10-30|0x0146
            MacroPrepareState = 7764; // END_FILE                                         //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          case UserError:                                                                 //07-10-30|0x0146
            MacroRunFlag = 1;                                                             //07-10-30|0x0146
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          default:                                                                        //07-10-30|0x0146
            MacroStatus = SystemError;                                                    //07-10-30|0x0146
            MacroRunFlag = 0;                                                             //07-10-30|0x0146
            SystemMsg;                                                                    //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
        }                                                                                 //07-10-30|0x0146
        break;                                                                            //07-10-30|0x0146
//**************************************************************************              //07-10-30|0x0146
      case 43258: // READ_UPDATE_EXIT                                                     //07-10-30|0x0146
        switch(ReadProject)                                                               //07-10-30|0x0146
        {                                                                                 //07-10-30|0x0146
          case Display:                                                                   //07-10-30|0x0146
            MacroPrepareState = 43258; // READ_UPDATE_EXIT                                //07-10-30|0x0146
            MacroStatus = Display;                                                        //07-10-30|0x0146
            MacroRunFlag = 0;                                                             //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          case LineDone:                                                                  //07-10-30|0x0146
            MacroRunFlag = 1;                                                             //07-10-30|0x0146
            MacroPrepareState = 14617; // UPDATE                                          //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          case FileDone:                                                                  //07-10-30|0x0146
            MacroRunFlag = 1;                                                             //07-10-30|0x0146
            MacroPrepareState = 7764; // END_FILE                                         //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          case UserError:                                                                 //07-10-30|0x0146
            MacroRunFlag = 1;                                                             //07-10-30|0x0146
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
          default:                                                                        //07-10-30|0x0146
            MacroStatus = SystemError;                                                    //07-10-30|0x0146
            MacroRunFlag = 0;                                                             //07-10-30|0x0146
            SystemMsg;                                                                    //07-10-30|0x0146
            break;                                                                        //07-10-30|0x0146
        }                                                                                 //07-10-30|0x0146
        break;                                                                            //07-10-30|0x0146
//---------------------------------------------------------------------------             //07-10-30|0x0147
      case 14617: // UPDATE                                                               //11-02-12|0x0148
        switch(CmdTest("_UPDATE"))                                                        //11-02-12|0x0148
        {                                                                                 //11-02-12|0x0148
          case -1:                                                                        //11-02-12|0x0148
            MacroRunFlag = 1;                                                             //11-02-12|0x0148
            MacroPrepareState = 52008; // RELEASE_VERSION                                 //11-02-12|0x0148
            break;                                                                        //11-02-12|0x0148
          case 0:                                                                         //11-02-12|0x0148
            MacroRunFlag = 1;                                                             //11-02-12|0x0148
            MacroPrepareState = 32295; // UNCOND_UPDATE                                   //11-02-12|0x0148
            break;                                                                        //11-02-12|0x0148
          case 1:                                                                         //11-02-12|0x0148
            MacroRunFlag = 1;                                                             //11-02-12|0x0148
            MacroPrepareState = 52008; // RELEASE_VERSION                                 //11-02-12|0x0148
            break;                                                                        //11-02-12|0x0148
          default:                                                                        //11-02-12|0x0148
            MacroStatus = SystemError;                                                    //11-02-12|0x0148
            MacroRunFlag = 0;                                                             //11-02-12|0x0148
            SystemMsg;                                                                    //11-02-12|0x0148
            break;                                                                        //11-02-12|0x0148
        }                                                                                 //11-02-12|0x0148
        break;                                                                            //11-02-12|0x0148
//---------------------------------------------------------------------------             //11-02-12|0x0149
      case 32295: // UNCOND_UPDATE                                                        //11-02-14|0x014a
        switch(uncond_update())                                                           //11-02-14|0x014a
        {                                                                                 //11-02-14|0x014a
          case Success:                                                                   //11-02-14|0x014a
            MacroRunFlag = 1;                                                             //11-02-14|0x014a
            MacroPrepareState = 24854; // READ_VERSION                                    //11-02-14|0x014a
            break;                                                                        //11-02-14|0x014a
          case UserError:                                                                 //11-02-14|0x014a
            MacroRunFlag = 1;                                                             //11-02-14|0x014a
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-14|0x014a
            break;                                                                        //11-02-14|0x014a
          default:                                                                        //11-02-14|0x014a
            MacroStatus = SystemError;                                                    //11-02-14|0x014a
            MacroRunFlag = 0;                                                             //11-02-14|0x014a
            SystemMsg;                                                                    //11-02-14|0x014a
            break;                                                                        //11-02-14|0x014a
        }                                                                                 //11-02-14|0x014a
        break;                                                                            //11-02-14|0x014a
//***************************************************************************             //11-02-12|0x014b
//******                                                               ******             //11-02-12|0x014c
//****** Process Development State Commands                            ******             //11-02-12|0x014d
//******                                                               ******             //11-02-12|0x014e
//***************************************************************************             //11-02-12|0x014f
      case 24854: // READ_VERSION                                                         //11-02-14|0x0150
        switch(ReadProject)                                                               //11-02-14|0x0150
        {                                                                                 //11-02-14|0x0150
          case Display:                                                                   //11-02-14|0x0150
            MacroPrepareState = 29429; // READ_VERSION_EXIT                               //11-02-14|0x0150
            MacroStatus = Display;                                                        //11-02-14|0x0150
            MacroRunFlag = 0;                                                             //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          case LineDone:                                                                  //11-02-14|0x0150
            MacroRunFlag = 1;                                                             //11-02-14|0x0150
            MacroPrepareState = 52008; // RELEASE_VERSION                                 //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          case FileDone:                                                                  //11-02-14|0x0150
            MacroRunFlag = 1;                                                             //11-02-14|0x0150
            MacroPrepareState = 7764; // END_FILE                                         //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          case UserError:                                                                 //11-02-14|0x0150
            MacroRunFlag = 1;                                                             //11-02-14|0x0150
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          default:                                                                        //11-02-14|0x0150
            MacroStatus = SystemError;                                                    //11-02-14|0x0150
            MacroRunFlag = 0;                                                             //11-02-14|0x0150
            SystemMsg;                                                                    //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
        }                                                                                 //11-02-14|0x0150
        break;                                                                            //11-02-14|0x0150
//**************************************************************************              //11-02-14|0x0150
      case 29429: // READ_VERSION_EXIT                                                    //11-02-14|0x0150
        switch(ReadProject)                                                               //11-02-14|0x0150
        {                                                                                 //11-02-14|0x0150
          case Display:                                                                   //11-02-14|0x0150
            MacroPrepareState = 29429; // READ_VERSION_EXIT                               //11-02-14|0x0150
            MacroStatus = Display;                                                        //11-02-14|0x0150
            MacroRunFlag = 0;                                                             //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          case LineDone:                                                                  //11-02-14|0x0150
            MacroRunFlag = 1;                                                             //11-02-14|0x0150
            MacroPrepareState = 52008; // RELEASE_VERSION                                 //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          case FileDone:                                                                  //11-02-14|0x0150
            MacroRunFlag = 1;                                                             //11-02-14|0x0150
            MacroPrepareState = 7764; // END_FILE                                         //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          case UserError:                                                                 //11-02-14|0x0150
            MacroRunFlag = 1;                                                             //11-02-14|0x0150
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
          default:                                                                        //11-02-14|0x0150
            MacroStatus = SystemError;                                                    //11-02-14|0x0150
            MacroRunFlag = 0;                                                             //11-02-14|0x0150
            SystemMsg;                                                                    //11-02-14|0x0150
            break;                                                                        //11-02-14|0x0150
        }                                                                                 //11-02-14|0x0150
        break;                                                                            //11-02-14|0x0150
//---------------------------------------------------------------------------             //11-02-12|0x0151
      case 52008: // RELEASE_VERSION                                                      //11-02-12|0x0152
        switch(CmdTest("_RELEASE_VERSION"))                                               //11-02-12|0x0152
        {                                                                                 //11-02-12|0x0152
          case -1:                                                                        //11-02-12|0x0152
            MacroRunFlag = 1;                                                             //11-02-12|0x0152
            MacroPrepareState = 41668; // BETA_VERSION                                    //11-02-12|0x0152
            break;                                                                        //11-02-12|0x0152
          case 0:                                                                         //11-02-12|0x0152
            MacroRunFlag = 1;                                                             //11-02-12|0x0152
            MacroPrepareState = 53123; // RELEASE                                         //11-02-12|0x0152
            break;                                                                        //11-02-12|0x0152
          case 1:                                                                         //11-02-12|0x0152
            MacroRunFlag = 1;                                                             //11-02-12|0x0152
            MacroPrepareState = 41668; // BETA_VERSION                                    //11-02-12|0x0152
            break;                                                                        //11-02-12|0x0152
          default:                                                                        //11-02-12|0x0152
            MacroStatus = SystemError;                                                    //11-02-12|0x0152
            MacroRunFlag = 0;                                                             //11-02-12|0x0152
            SystemMsg;                                                                    //11-02-12|0x0152
            break;                                                                        //11-02-12|0x0152
        }                                                                                 //11-02-12|0x0152
        break;                                                                            //11-02-12|0x0152
//---------------------------------------------------------------------------             //11-02-12|0x0153
      case 53123: // RELEASE                                                              //11-02-19|0x0154
        set_version(DS_RELEASE);                                                          //11-02-19|0x0154
        MacroPrepareState = 51250; // READ_LIBRARY                                        //11-02-19|0x0154
        break;                                                                            //11-02-19|0x0154
//***************************************************************************             //11-02-12|0x0155
      case 41668: // BETA_VERSION                                                         //11-02-12|0x0156
        switch(CmdTest("_BETA_VERSION"))                                                  //11-02-12|0x0156
        {                                                                                 //11-02-12|0x0156
          case -1:                                                                        //11-02-12|0x0156
            MacroRunFlag = 1;                                                             //11-02-12|0x0156
            MacroPrepareState = 19409; // ALPHA_VERSION                                   //11-02-12|0x0156
            break;                                                                        //11-02-12|0x0156
          case 0:                                                                         //11-02-12|0x0156
            MacroRunFlag = 1;                                                             //11-02-12|0x0156
            MacroPrepareState = 2400; // BETA                                             //11-02-12|0x0156
            break;                                                                        //11-02-12|0x0156
          case 1:                                                                         //11-02-12|0x0156
            MacroRunFlag = 1;                                                             //11-02-12|0x0156
            MacroPrepareState = 19409; // ALPHA_VERSION                                   //11-02-12|0x0156
            break;                                                                        //11-02-12|0x0156
          default:                                                                        //11-02-12|0x0156
            MacroStatus = SystemError;                                                    //11-02-12|0x0156
            MacroRunFlag = 0;                                                             //11-02-12|0x0156
            SystemMsg;                                                                    //11-02-12|0x0156
            break;                                                                        //11-02-12|0x0156
        }                                                                                 //11-02-12|0x0156
        break;                                                                            //11-02-12|0x0156
//---------------------------------------------------------------------------             //11-02-12|0x0157
      case 2400: // BETA                                                                  //11-02-19|0x0158
        set_version(DS_BETA);                                                             //11-02-19|0x0158
        MacroPrepareState = 51250; // READ_LIBRARY                                        //11-02-19|0x0158
        break;                                                                            //11-02-19|0x0158
//***************************************************************************             //11-02-12|0x0159
      case 19409: // ALPHA_VERSION                                                        //11-02-12|0x015a
        switch(CmdTest("_ALPHA_VERSION"))                                                 //11-02-12|0x015a
        {                                                                                 //11-02-12|0x015a
          case -1:                                                                        //11-02-12|0x015a
            MacroRunFlag = 1;                                                             //11-02-12|0x015a
            MacroPrepareState = 40927; // EXPERIMENT                                      //11-02-12|0x015a
            break;                                                                        //11-02-12|0x015a
          case 0:                                                                         //11-02-12|0x015a
            MacroRunFlag = 1;                                                             //11-02-12|0x015a
            MacroPrepareState = 40526; // ALPHA                                           //11-02-12|0x015a
            break;                                                                        //11-02-12|0x015a
          case 1:                                                                         //11-02-12|0x015a
            MacroRunFlag = 1;                                                             //11-02-12|0x015a
            MacroPrepareState = 40927; // EXPERIMENT                                      //11-02-12|0x015a
            break;                                                                        //11-02-12|0x015a
          default:                                                                        //11-02-12|0x015a
            MacroStatus = SystemError;                                                    //11-02-12|0x015a
            MacroRunFlag = 0;                                                             //11-02-12|0x015a
            SystemMsg;                                                                    //11-02-12|0x015a
            break;                                                                        //11-02-12|0x015a
        }                                                                                 //11-02-12|0x015a
        break;                                                                            //11-02-12|0x015a
//---------------------------------------------------------------------------             //11-02-12|0x015b
      case 40526: // ALPHA                                                                //11-02-14|0x015c
        set_version(DS_ALPHA);                                                            //11-02-14|0x015c
        MacroPrepareState = 51250; // READ_LIBRARY                                        //11-02-14|0x015c
        break;                                                                            //11-02-14|0x015c
//***************************************************************************             //11-02-12|0x015d
      case 40927: // EXPERIMENT                                                           //11-02-12|0x015e
        set_version(DS_EXPERIMENT);                                                       //11-02-12|0x015e
        MacroPrepareState = 33709; // LIBRARY                                             //11-02-12|0x015e
        break;                                                                            //11-02-12|0x015e
//***************************************************************************             //11-02-12|0x015f
//***************************************************************************             //11-02-12|0x0160
//******                                                               ******             //11-02-12|0x0161
//****** Process Library                                               ******             //11-02-12|0x0162
//******                                                               ******             //11-02-12|0x0163
//***************************************************************************             //11-02-12|0x0164
//***************************************************************************             //11-02-12|0x0165
      case 51250: // READ_LIBRARY                                                         //11-02-12|0x0166
        switch(ReadProject)                                                               //11-02-12|0x0166
        {                                                                                 //11-02-12|0x0166
          case Display:                                                                   //11-02-12|0x0166
            MacroPrepareState = 48892; // READ_LIBRARY_EXIT                               //11-02-12|0x0166
            MacroStatus = Display;                                                        //11-02-12|0x0166
            MacroRunFlag = 0;                                                             //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          case LineDone:                                                                  //11-02-12|0x0166
            MacroRunFlag = 1;                                                             //11-02-12|0x0166
            MacroPrepareState = 33709; // LIBRARY                                         //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          case FileDone:                                                                  //11-02-12|0x0166
            MacroRunFlag = 1;                                                             //11-02-12|0x0166
            MacroPrepareState = 7764; // END_FILE                                         //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          case UserError:                                                                 //11-02-12|0x0166
            MacroRunFlag = 1;                                                             //11-02-12|0x0166
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          default:                                                                        //11-02-12|0x0166
            MacroStatus = SystemError;                                                    //11-02-12|0x0166
            MacroRunFlag = 0;                                                             //11-02-12|0x0166
            SystemMsg;                                                                    //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
        }                                                                                 //11-02-12|0x0166
        break;                                                                            //11-02-12|0x0166
//**************************************************************************              //11-02-12|0x0166
      case 48892: // READ_LIBRARY_EXIT                                                    //11-02-12|0x0166
        switch(ReadProject)                                                               //11-02-12|0x0166
        {                                                                                 //11-02-12|0x0166
          case Display:                                                                   //11-02-12|0x0166
            MacroPrepareState = 48892; // READ_LIBRARY_EXIT                               //11-02-12|0x0166
            MacroStatus = Display;                                                        //11-02-12|0x0166
            MacroRunFlag = 0;                                                             //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          case LineDone:                                                                  //11-02-12|0x0166
            MacroRunFlag = 1;                                                             //11-02-12|0x0166
            MacroPrepareState = 33709; // LIBRARY                                         //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          case FileDone:                                                                  //11-02-12|0x0166
            MacroRunFlag = 1;                                                             //11-02-12|0x0166
            MacroPrepareState = 7764; // END_FILE                                         //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          case UserError:                                                                 //11-02-12|0x0166
            MacroRunFlag = 1;                                                             //11-02-12|0x0166
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
          default:                                                                        //11-02-12|0x0166
            MacroStatus = SystemError;                                                    //11-02-12|0x0166
            MacroRunFlag = 0;                                                             //11-02-12|0x0166
            SystemMsg;                                                                    //11-02-12|0x0166
            break;                                                                        //11-02-12|0x0166
        }                                                                                 //11-02-12|0x0166
        break;                                                                            //11-02-12|0x0166
//---------------------------------------------------------------------------             //11-02-12|0x0167
      case 33709: // LIBRARY                                                              //11-02-12|0x0168
        switch(CmdTest("_LIBRARY"))                                                       //11-02-12|0x0168
        {                                                                                 //11-02-12|0x0168
          case -1:                                                                        //11-02-12|0x0168
            MacroRunFlag = 1;                                                             //11-02-12|0x0168
            MacroPrepareState = 57310; // COMMAND_ERROR                                   //11-02-12|0x0168
            break;                                                                        //11-02-12|0x0168
          case 0:                                                                         //11-02-12|0x0168
            MacroRunFlag = 1;                                                             //11-02-12|0x0168
            MacroPrepareState = 44859; // LIBRARY_PREPARE                                 //11-02-12|0x0168
            break;                                                                        //11-02-12|0x0168
          case 1:                                                                         //11-02-12|0x0168
            MacroRunFlag = 1;                                                             //11-02-12|0x0168
            MacroPrepareState = 57310; // COMMAND_ERROR                                   //11-02-12|0x0168
            break;                                                                        //11-02-12|0x0168
          default:                                                                        //11-02-12|0x0168
            MacroStatus = SystemError;                                                    //11-02-12|0x0168
            MacroRunFlag = 0;                                                             //11-02-12|0x0168
            SystemMsg;                                                                    //11-02-12|0x0168
            break;                                                                        //11-02-12|0x0168
        }                                                                                 //11-02-12|0x0168
        break;                                                                            //11-02-12|0x0168
//---------------------------------------------------------------------------             //11-02-12|0x0169
      case 44859: // LIBRARY_PREPARE                                                      //11-02-12|0x016a
        switch(text_prepare())                                                            //11-02-12|0x016a
        {                                                                                 //11-02-12|0x016a
          case Success:                                                                   //11-02-12|0x016a
            MacroRunFlag = 1;                                                             //11-02-12|0x016a
            MacroPrepareState = 41834; // LIBRARY_NAME                                    //11-02-12|0x016a
            break;                                                                        //11-02-12|0x016a
          case UserError:                                                                 //11-02-12|0x016a
            MacroRunFlag = 1;                                                             //11-02-12|0x016a
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-12|0x016a
            break;                                                                        //11-02-12|0x016a
          default:                                                                        //11-02-12|0x016a
            MacroStatus = SystemError;                                                    //11-02-12|0x016a
            MacroRunFlag = 0;                                                             //11-02-12|0x016a
            SystemMsg;                                                                    //11-02-12|0x016a
            break;                                                                        //11-02-12|0x016a
        }                                                                                 //11-02-12|0x016a
        break;                                                                            //11-02-12|0x016a
//---------------------------------------------------------------------------             //11-02-12|0x016b
      case 41834: // LIBRARY_NAME                                                         //11-02-12|0x016c
        switch(EnterLibraryName)                                                          //11-02-12|0x016c
        {                                                                                 //11-02-12|0x016c
          case Success:                                                                   //11-02-12|0x016c
            MacroRunFlag = 1;                                                             //11-02-12|0x016c
            MacroPrepareState = 55945; // LIBRARY_DATE                                    //11-02-12|0x016c
            break;                                                                        //11-02-12|0x016c
          default:                                                                        //11-02-12|0x016c
            MacroStatus = SystemError;                                                    //11-02-12|0x016c
            MacroRunFlag = 0;                                                             //11-02-12|0x016c
            SystemMsg;                                                                    //11-02-12|0x016c
            break;                                                                        //11-02-12|0x016c
        }                                                                                 //11-02-12|0x016c
        break;                                                                            //11-02-12|0x016c
//---------------------------------------------------------------------------             //11-02-12|0x016d
      case 55945: // LIBRARY_DATE                                                         //11-02-19|0x016e
        switch(LibraryDate)                                                               //11-02-19|0x016e
        {                                                                                 //11-02-19|0x016e
          case Success:                                                                   //11-02-19|0x016e
            MacroRunFlag = 1;                                                             //11-02-19|0x016e
            MacroPrepareState = 33688; // LIBRARY_CERT_INITIAL                            //11-02-19|0x016e
            break;                                                                        //11-02-19|0x016e
          default:                                                                        //11-02-19|0x016e
            MacroStatus = SystemError;                                                    //11-02-19|0x016e
            MacroRunFlag = 0;                                                             //11-02-19|0x016e
            SystemMsg;                                                                    //11-02-19|0x016e
            break;                                                                        //11-02-19|0x016e
        }                                                                                 //11-02-19|0x016e
        break;                                                                            //11-02-19|0x016e
//***************************************************************************             //11-02-19|0x016f
//******                                                               ******             //11-02-19|0x0170
//****** Initial Version Certification Sub-system                      ******             //11-02-19|0x0171
//******                                                               ******             //11-02-19|0x0172
//***************************************************************************             //11-02-19|0x0173
      case 33688: // LIBRARY_CERT_INITIAL                                                 //11-02-19|0x0174
        switch(MacroInitialCertify)                                                       //11-02-19|0x0174
        {                                                                                 //11-02-19|0x0174
          case Success:                                                                   //11-02-19|0x0174
            MacroRunFlag = 1;                                                             //11-02-19|0x0174
            MacroPrepareState = 48535; // LIBRARY_VERSION                                 //11-02-19|0x0174
            break;                                                                        //11-02-19|0x0174
          default:                                                                        //11-02-19|0x0174
            MacroStatus = SystemError;                                                    //11-02-19|0x0174
            MacroRunFlag = 0;                                                             //11-02-19|0x0174
            SystemMsg;                                                                    //11-02-19|0x0174
            break;                                                                        //11-02-19|0x0174
        }                                                                                 //11-02-19|0x0174
        break;                                                                            //11-02-19|0x0174
//***************************************************************************             //11-02-13|0x0175
//******                                                               ******             //11-02-13|0x0176
//****** Process the Library Status                                    ******             //11-02-13|0x0177
//******                                                               ******             //11-02-13|0x0178
//***************************************************************************             //11-02-13|0x0179
      case 48535: // LIBRARY_VERSION                                                      //11-02-26|0x017a
        switch(MacroDevelopStatus)                                                        //11-02-26|0x017a
        {                                                                                 //11-02-26|0x017a
          case DS_RELEASE:                                                                //11-02-26|0x017a
            MacroRunFlag = 1;                                                             //11-02-26|0x017a
            MacroPrepareState = 38790; // PREV_LIB_EXIST                                  //11-02-26|0x017a
            break;                                                                        //11-02-26|0x017a
          case DS_BETA:                                                                   //11-02-26|0x017a
            MacroRunFlag = 1;                                                             //11-02-26|0x017a
            MacroPrepareState = 38790; // PREV_LIB_EXIST                                  //11-02-26|0x017a
            break;                                                                        //11-02-26|0x017a
          case DS_ALPHA:                                                                  //11-02-26|0x017a
            MacroRunFlag = 1;                                                             //11-02-26|0x017a
            MacroPrepareState = 4197; // LIBRARY_UPDATE                                   //11-02-26|0x017a
            break;                                                                        //11-02-26|0x017a
          case DS_EXPERIMENT:                                                             //11-02-26|0x017a
            MacroRunFlag = 1;                                                             //11-02-26|0x017a
            MacroPrepareState = 4197; // LIBRARY_UPDATE                                   //11-02-26|0x017a
            break;                                                                        //11-02-26|0x017a
          default:                                                                        //11-02-26|0x017a
            MacroStatus = SystemError;                                                    //11-02-26|0x017a
            MacroRunFlag = 0;                                                             //11-02-26|0x017a
            SystemMsg;                                                                    //11-02-26|0x017a
            break;                                                                        //11-02-26|0x017a
        }                                                                                 //11-02-26|0x017a
        break;                                                                            //11-02-26|0x017a
//***************************************************************************             //11-02-14|0x017b
      case 38790: // PREV_LIB_EXIST                                                       //11-02-19|0x017c
        switch(FileOutDateExists)                                                         //11-02-19|0x017c
        {                                                                                 //11-02-19|0x017c
          case Yes:                                                                       //11-02-19|0x017c
            MacroRunFlag = 1;                                                             //11-02-19|0x017c
            MacroPrepareState = 5940; // GET_PREV_PARITY                                  //11-02-19|0x017c
            break;                                                                        //11-02-19|0x017c
          case No:                                                                        //11-02-19|0x017c
            MacroRunFlag = 1;                                                             //11-02-19|0x017c
            MacroPrepareState = 35571; // NO_LIBRARY_FILE                                 //11-02-19|0x017c
            break;                                                                        //11-02-19|0x017c
          default:                                                                        //11-02-19|0x017c
            MacroStatus = SystemError;                                                    //11-02-19|0x017c
            MacroRunFlag = 0;                                                             //11-02-19|0x017c
            SystemMsg;                                                                    //11-02-19|0x017c
            break;                                                                        //11-02-19|0x017c
        }                                                                                 //11-02-19|0x017c
        break;                                                                            //11-02-19|0x017c
//---------------------------------------------------------------------------             //11-02-19|0x017d
      case 5940: // GET_PREV_PARITY                                                       //11-02-26|0x017e
        switch(MacCertGetPrev())                                                          //11-02-26|0x017e
        {                                                                                 //11-02-26|0x017e
          case Success:                                                                   //11-02-26|0x017e
            MacroRunFlag = 1;                                                             //11-02-26|0x017e
            MacroPrepareState = 4197; // LIBRARY_UPDATE                                   //11-02-26|0x017e
            break;                                                                        //11-02-26|0x017e
          case UserError:                                                                 //11-02-26|0x017e
            MacroRunFlag = 1;                                                             //11-02-26|0x017e
            MacroPrepareState = 15010; // LIBRARY_CONFLICT                                //11-02-26|0x017e
            break;                                                                        //11-02-26|0x017e
          default:                                                                        //11-02-26|0x017e
            MacroStatus = SystemError;                                                    //11-02-26|0x017e
            MacroRunFlag = 0;                                                             //11-02-26|0x017e
            SystemMsg;                                                                    //11-02-26|0x017e
            break;                                                                        //11-02-26|0x017e
        }                                                                                 //11-02-26|0x017e
        break;                                                                            //11-02-26|0x017e
//***************************************************************************             //11-02-13|0x017f
//***************************************************************************             //11-02-13|0x0180
      case 4197: // LIBRARY_UPDATE                                                        //11-02-13|0x0181
        BasicDateTest(8);                                                                 //11-02-13|0x0181
        MacroPrepareState = 58689; // READ_1ST_NAME                                       //11-02-13|0x0181
        break;                                                                            //11-02-13|0x0181
//***************************************************************************             //11-02-13|0x0182
//***************************************************************************             //11-02-13|0x0183
      case 35571: // NO_LIBRARY_FILE                                                      //11-02-26|0x0184
        switch(LibraryDoesNotExist)                                                       //11-02-26|0x0184
        {                                                                                 //11-02-26|0x0184
          case UserError:                                                                 //11-02-26|0x0184
            MacroRunFlag = 1;                                                             //11-02-26|0x0184
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-26|0x0184
            break;                                                                        //11-02-26|0x0184
          default:                                                                        //11-02-26|0x0184
            MacroStatus = SystemError;                                                    //11-02-26|0x0184
            MacroRunFlag = 0;                                                             //11-02-26|0x0184
            SystemMsg;                                                                    //11-02-26|0x0184
            break;                                                                        //11-02-26|0x0184
        }                                                                                 //11-02-26|0x0184
        break;                                                                            //11-02-26|0x0184
//---------------------------------------------------------------------------             //11-02-26|0x0185
      case 15010: // LIBRARY_CONFLICT                                                     //11-02-26|0x0186
        switch(LibraryConflict)                                                           //11-02-26|0x0186
        {                                                                                 //11-02-26|0x0186
          case UserError:                                                                 //11-02-26|0x0186
            MacroRunFlag = 1;                                                             //11-02-26|0x0186
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-26|0x0186
            break;                                                                        //11-02-26|0x0186
          default:                                                                        //11-02-26|0x0186
            MacroStatus = SystemError;                                                    //11-02-26|0x0186
            MacroRunFlag = 0;                                                             //11-02-26|0x0186
            SystemMsg;                                                                    //11-02-26|0x0186
            break;                                                                        //11-02-26|0x0186
        }                                                                                 //11-02-26|0x0186
        break;                                                                            //11-02-26|0x0186
//***************************************************************************             //11-02-17|0x0187
//******                                                               ******             //11-02-17|0x0188
//****** Process Macros                                                ******             //11-02-17|0x0189
//******                                                               ******             //11-02-17|0x018a
//***************************************************************************             //11-02-17|0x018b
      case 58689: // READ_1ST_NAME                                                        //06-08-18|0x018c
        switch(ReadProject)                                                               //06-08-18|0x018c
        {                                                                                 //06-08-18|0x018c
          case Display:                                                                   //06-08-18|0x018c
            MacroPrepareState = 14800; // READ_1ST_NAME_EXIT                              //06-08-18|0x018c
            MacroStatus = Display;                                                        //06-08-18|0x018c
            MacroRunFlag = 0;                                                             //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          case LineDone:                                                                  //06-08-18|0x018c
            MacroRunFlag = 1;                                                             //06-08-18|0x018c
            MacroPrepareState = 55119; // MACRO                                           //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          case FileDone:                                                                  //06-08-18|0x018c
            MacroRunFlag = 1;                                                             //06-08-18|0x018c
            MacroPrepareState = 7764; // END_FILE                                         //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          case UserError:                                                                 //06-08-18|0x018c
            MacroRunFlag = 1;                                                             //06-08-18|0x018c
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          default:                                                                        //06-08-18|0x018c
            MacroStatus = SystemError;                                                    //06-08-18|0x018c
            MacroRunFlag = 0;                                                             //06-08-18|0x018c
            SystemMsg;                                                                    //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
        }                                                                                 //06-08-18|0x018c
        break;                                                                            //06-08-18|0x018c
//**************************************************************************              //06-08-18|0x018c
      case 14800: // READ_1ST_NAME_EXIT                                                   //06-08-18|0x018c
        switch(ReadProject)                                                               //06-08-18|0x018c
        {                                                                                 //06-08-18|0x018c
          case Display:                                                                   //06-08-18|0x018c
            MacroPrepareState = 14800; // READ_1ST_NAME_EXIT                              //06-08-18|0x018c
            MacroStatus = Display;                                                        //06-08-18|0x018c
            MacroRunFlag = 0;                                                             //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          case LineDone:                                                                  //06-08-18|0x018c
            MacroRunFlag = 1;                                                             //06-08-18|0x018c
            MacroPrepareState = 55119; // MACRO                                           //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          case FileDone:                                                                  //06-08-18|0x018c
            MacroRunFlag = 1;                                                             //06-08-18|0x018c
            MacroPrepareState = 7764; // END_FILE                                         //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          case UserError:                                                                 //06-08-18|0x018c
            MacroRunFlag = 1;                                                             //06-08-18|0x018c
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
          default:                                                                        //06-08-18|0x018c
            MacroStatus = SystemError;                                                    //06-08-18|0x018c
            MacroRunFlag = 0;                                                             //06-08-18|0x018c
            SystemMsg;                                                                    //06-08-18|0x018c
            break;                                                                        //06-08-18|0x018c
        }                                                                                 //06-08-18|0x018c
        break;                                                                            //06-08-18|0x018c
//---------------------------------------------------------------------------             //06-08-18|0x018d
      case 7764: // END_FILE                                                              //06-08-18|0x018e
        switch(IllegalEndOfFile)                                                          //06-08-18|0x018e
        {                                                                                 //06-08-18|0x018e
          case UserError:                                                                 //06-08-18|0x018e
            MacroRunFlag = 1;                                                             //06-08-18|0x018e
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-08-18|0x018e
            break;                                                                        //06-08-18|0x018e
          default:                                                                        //06-08-18|0x018e
            MacroStatus = SystemError;                                                    //06-08-18|0x018e
            MacroRunFlag = 0;                                                             //06-08-18|0x018e
            SystemMsg;                                                                    //06-08-18|0x018e
            break;                                                                        //06-08-18|0x018e
        }                                                                                 //06-08-18|0x018e
        break;                                                                            //06-08-18|0x018e
//---------------------------------------------------------------------------             //06-08-18|0x018f
      case 55119: // MACRO                                                                //06-08-18|0x0190
        switch(CmdTest("_MACRO"))                                                         //06-08-18|0x0190
        {                                                                                 //06-08-18|0x0190
          case -1:                                                                        //06-08-18|0x0190
            MacroRunFlag = 1;                                                             //06-08-18|0x0190
            MacroPrepareState = 19646; // APPEND                                          //06-08-18|0x0190
            break;                                                                        //06-08-18|0x0190
          case 0:                                                                         //06-08-18|0x0190
            MacroRunFlag = 1;                                                             //06-08-18|0x0190
            MacroPrepareState = 6429; // MACRO_PREPARE                                    //06-08-18|0x0190
            break;                                                                        //06-08-18|0x0190
          case 1:                                                                         //06-08-18|0x0190
            MacroRunFlag = 1;                                                             //06-08-18|0x0190
            MacroPrepareState = 19646; // APPEND                                          //06-08-18|0x0190
            break;                                                                        //06-08-18|0x0190
          default:                                                                        //06-08-18|0x0190
            MacroStatus = SystemError;                                                    //06-08-18|0x0190
            MacroRunFlag = 0;                                                             //06-08-18|0x0190
            SystemMsg;                                                                    //06-08-18|0x0190
            break;                                                                        //06-08-18|0x0190
        }                                                                                 //06-08-18|0x0190
        break;                                                                            //06-08-18|0x0190
//---------------------------------------------------------------------------             //06-08-18|0x0191
      case 6429: // MACRO_PREPARE                                                         //06-08-20|0x0192
        switch(text_prepare())                                                            //06-08-20|0x0192
        {                                                                                 //06-08-20|0x0192
          case Success:                                                                   //06-08-20|0x0192
            MacroRunFlag = 1;                                                             //06-08-20|0x0192
            MacroPrepareState = 43884; // MACRO_NAME                                      //06-08-20|0x0192
            break;                                                                        //06-08-20|0x0192
          case UserError:                                                                 //06-08-20|0x0192
            MacroRunFlag = 1;                                                             //06-08-20|0x0192
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-08-20|0x0192
            break;                                                                        //06-08-20|0x0192
          default:                                                                        //06-08-20|0x0192
            MacroStatus = SystemError;                                                    //06-08-20|0x0192
            MacroRunFlag = 0;                                                             //06-08-20|0x0192
            SystemMsg;                                                                    //06-08-20|0x0192
            break;                                                                        //06-08-20|0x0192
        }                                                                                 //06-08-20|0x0192
        break;                                                                            //06-08-20|0x0192
//---------------------------------------------------------------------------             //06-08-20|0x0193
      case 43884: // MACRO_NAME                                                           //06-08-20|0x0194
        switch(EnterMacroName)                                                            //06-08-20|0x0194
        {                                                                                 //06-08-20|0x0194
          case Success:                                                                   //06-08-20|0x0194
            MacroRunFlag = 1;                                                             //06-08-20|0x0194
            MacroPrepareState = 25259; // MACRO_DATE                                      //06-08-20|0x0194
            break;                                                                        //06-08-20|0x0194
          default:                                                                        //06-08-20|0x0194
            MacroStatus = SystemError;                                                    //06-08-20|0x0194
            MacroRunFlag = 0;                                                             //06-08-20|0x0194
            SystemMsg;                                                                    //06-08-20|0x0194
            break;                                                                        //06-08-20|0x0194
        }                                                                                 //06-08-20|0x0194
        break;                                                                            //06-08-20|0x0194
//---------------------------------------------------------------------------             //06-08-20|0x0195
      case 25259: // MACRO_DATE                                                           //06-08-20|0x0196
        switch(MacroFileTime)                                                             //06-08-20|0x0196
        {                                                                                 //06-08-20|0x0196
          case Success:                                                                   //06-08-20|0x0196
            MacroRunFlag = 1;                                                             //06-08-20|0x0196
            MacroPrepareState = 36314; // MACRO_EXIST                                     //06-08-20|0x0196
            break;                                                                        //06-08-20|0x0196
          default:                                                                        //06-08-20|0x0196
            MacroStatus = SystemError;                                                    //06-08-20|0x0196
            MacroRunFlag = 0;                                                             //06-08-20|0x0196
            SystemMsg;                                                                    //06-08-20|0x0196
            break;                                                                        //06-08-20|0x0196
        }                                                                                 //06-08-20|0x0196
        break;                                                                            //06-08-20|0x0196
//---------------------------------------------------------------------------             //06-08-20|0x0197
      case 36314: // MACRO_EXIST                                                          //11-02-13|0x0198
        switch(FileInDateExists)                                                          //11-02-13|0x0198
        {                                                                                 //11-02-13|0x0198
          case Yes:                                                                       //11-02-13|0x0198
            MacroRunFlag = 1;                                                             //11-02-13|0x0198
            MacroPrepareState = 27641; // MACRO_TEST                                      //11-02-13|0x0198
            break;                                                                        //11-02-13|0x0198
          case No:                                                                        //11-02-13|0x0198
            MacroRunFlag = 1;                                                             //11-02-13|0x0198
            MacroPrepareState = 11272; // NO_MACRO_FILE                                   //11-02-13|0x0198
            break;                                                                        //11-02-13|0x0198
          default:                                                                        //11-02-13|0x0198
            MacroStatus = SystemError;                                                    //11-02-13|0x0198
            MacroRunFlag = 0;                                                             //11-02-13|0x0198
            SystemMsg;                                                                    //11-02-13|0x0198
            break;                                                                        //11-02-13|0x0198
        }                                                                                 //11-02-13|0x0198
        break;                                                                            //11-02-13|0x0198
//---------------------------------------------------------------------------             //06-08-20|0x0199
      case 27641: // MACRO_TEST                                                           //11-02-13|0x019a
        BasicDateTest(4);                                                                 //11-02-13|0x019a
        MacroPrepareState = 60679; // READ_MACRO                                          //11-02-13|0x019a
        break;                                                                            //11-02-13|0x019a
//---------------------------------------------------------------------------             //06-09-07|0x019b
      case 11272: // NO_MACRO_FILE                                                        //06-08-20|0x019c
        switch(MacroDoesNotExist)                                                         //06-08-20|0x019c
        {                                                                                 //06-08-20|0x019c
          case UserError:                                                                 //06-08-20|0x019c
            MacroRunFlag = 1;                                                             //06-08-20|0x019c
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-08-20|0x019c
            break;                                                                        //06-08-20|0x019c
          default:                                                                        //06-08-20|0x019c
            MacroStatus = SystemError;                                                    //06-08-20|0x019c
            MacroRunFlag = 0;                                                             //06-08-20|0x019c
            SystemMsg;                                                                    //06-08-20|0x019c
            break;                                                                        //06-08-20|0x019c
        }                                                                                 //06-08-20|0x019c
        break;                                                                            //06-08-20|0x019c
//---------------------------------------------------------------------------             //06-09-07|0x019d
      case 60679: // READ_MACRO                                                           //11-02-13|0x019e
        switch(ReadProject)                                                               //11-02-13|0x019e
        {                                                                                 //11-02-13|0x019e
          case Display:                                                                   //11-02-13|0x019e
            MacroPrepareState = 48630; // READ_MACRO_EXIT                                 //11-02-13|0x019e
            MacroStatus = Display;                                                        //11-02-13|0x019e
            MacroRunFlag = 0;                                                             //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          case LineDone:                                                                  //11-02-13|0x019e
            MacroRunFlag = 1;                                                             //11-02-13|0x019e
            MacroPrepareState = 55119; // MACRO                                           //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          case FileDone:                                                                  //11-02-13|0x019e
            MacroRunFlag = 1;                                                             //11-02-13|0x019e
            MacroPrepareState = 40405; // CLOSE_OK                                        //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          case UserError:                                                                 //11-02-13|0x019e
            MacroRunFlag = 1;                                                             //11-02-13|0x019e
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          default:                                                                        //11-02-13|0x019e
            MacroStatus = SystemError;                                                    //11-02-13|0x019e
            MacroRunFlag = 0;                                                             //11-02-13|0x019e
            SystemMsg;                                                                    //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
        }                                                                                 //11-02-13|0x019e
        break;                                                                            //11-02-13|0x019e
//**************************************************************************              //11-02-13|0x019e
      case 48630: // READ_MACRO_EXIT                                                      //11-02-13|0x019e
        switch(ReadProject)                                                               //11-02-13|0x019e
        {                                                                                 //11-02-13|0x019e
          case Display:                                                                   //11-02-13|0x019e
            MacroPrepareState = 48630; // READ_MACRO_EXIT                                 //11-02-13|0x019e
            MacroStatus = Display;                                                        //11-02-13|0x019e
            MacroRunFlag = 0;                                                             //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          case LineDone:                                                                  //11-02-13|0x019e
            MacroRunFlag = 1;                                                             //11-02-13|0x019e
            MacroPrepareState = 55119; // MACRO                                           //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          case FileDone:                                                                  //11-02-13|0x019e
            MacroRunFlag = 1;                                                             //11-02-13|0x019e
            MacroPrepareState = 40405; // CLOSE_OK                                        //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          case UserError:                                                                 //11-02-13|0x019e
            MacroRunFlag = 1;                                                             //11-02-13|0x019e
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
          default:                                                                        //11-02-13|0x019e
            MacroStatus = SystemError;                                                    //11-02-13|0x019e
            MacroRunFlag = 0;                                                             //11-02-13|0x019e
            SystemMsg;                                                                    //11-02-13|0x019e
            break;                                                                        //11-02-13|0x019e
        }                                                                                 //11-02-13|0x019e
        break;                                                                            //11-02-13|0x019e
//***************************************************************************             //06-08-18|0x019f
//******                                                               ******             //06-08-18|0x01a0
//****** Process Append                                                ******             //06-08-18|0x01a1
//******                                                               ******             //06-08-18|0x01a2
//***************************************************************************             //06-08-18|0x01a3
      case 31652: // READ_APPEND                                                          //06-09-11|0x01a4
        switch(ReadProject)                                                               //06-09-11|0x01a4
        {                                                                                 //06-09-11|0x01a4
          case Display:                                                                   //06-09-11|0x01a4
            MacroPrepareState = 13923; // READ_APPEND_EXIT                                //06-09-11|0x01a4
            MacroStatus = Display;                                                        //06-09-11|0x01a4
            MacroRunFlag = 0;                                                             //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          case LineDone:                                                                  //06-09-11|0x01a4
            MacroRunFlag = 1;                                                             //06-09-11|0x01a4
            MacroPrepareState = 19646; // APPEND                                          //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          case FileDone:                                                                  //06-09-11|0x01a4
            MacroRunFlag = 1;                                                             //06-09-11|0x01a4
            MacroPrepareState = 40405; // CLOSE_OK                                        //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          case UserError:                                                                 //06-09-11|0x01a4
            MacroRunFlag = 1;                                                             //06-09-11|0x01a4
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          default:                                                                        //06-09-11|0x01a4
            MacroStatus = SystemError;                                                    //06-09-11|0x01a4
            MacroRunFlag = 0;                                                             //06-09-11|0x01a4
            SystemMsg;                                                                    //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
        }                                                                                 //06-09-11|0x01a4
        break;                                                                            //06-09-11|0x01a4
//**************************************************************************              //06-09-11|0x01a4
      case 13923: // READ_APPEND_EXIT                                                     //06-09-11|0x01a4
        switch(ReadProject)                                                               //06-09-11|0x01a4
        {                                                                                 //06-09-11|0x01a4
          case Display:                                                                   //06-09-11|0x01a4
            MacroPrepareState = 13923; // READ_APPEND_EXIT                                //06-09-11|0x01a4
            MacroStatus = Display;                                                        //06-09-11|0x01a4
            MacroRunFlag = 0;                                                             //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          case LineDone:                                                                  //06-09-11|0x01a4
            MacroRunFlag = 1;                                                             //06-09-11|0x01a4
            MacroPrepareState = 19646; // APPEND                                          //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          case FileDone:                                                                  //06-09-11|0x01a4
            MacroRunFlag = 1;                                                             //06-09-11|0x01a4
            MacroPrepareState = 40405; // CLOSE_OK                                        //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          case UserError:                                                                 //06-09-11|0x01a4
            MacroRunFlag = 1;                                                             //06-09-11|0x01a4
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
          default:                                                                        //06-09-11|0x01a4
            MacroStatus = SystemError;                                                    //06-09-11|0x01a4
            MacroRunFlag = 0;                                                             //06-09-11|0x01a4
            SystemMsg;                                                                    //06-09-11|0x01a4
            break;                                                                        //06-09-11|0x01a4
        }                                                                                 //06-09-11|0x01a4
        break;                                                                            //06-09-11|0x01a4
//---------------------------------------------------------------------------             //06-09-07|0x01a5
      case 19646: // APPEND                                                               //06-08-18|0x01a6
        switch(CmdTest("_APPEND"))                                                        //06-08-18|0x01a6
        {                                                                                 //06-08-18|0x01a6
          case -1:                                                                        //06-08-18|0x01a6
            MacroRunFlag = 1;                                                             //06-08-18|0x01a6
            MacroPrepareState = 57310; // COMMAND_ERROR                                   //06-08-18|0x01a6
            break;                                                                        //06-08-18|0x01a6
          case 0:                                                                         //06-08-18|0x01a6
            MacroRunFlag = 1;                                                             //06-08-18|0x01a6
            MacroPrepareState = 40210; // APPEND_PREPARE                                  //06-08-18|0x01a6
            break;                                                                        //06-08-18|0x01a6
          case 1:                                                                         //06-08-18|0x01a6
            MacroRunFlag = 1;                                                             //06-08-18|0x01a6
            MacroPrepareState = 57310; // COMMAND_ERROR                                   //06-08-18|0x01a6
            break;                                                                        //06-08-18|0x01a6
          default:                                                                        //06-08-18|0x01a6
            MacroStatus = SystemError;                                                    //06-08-18|0x01a6
            MacroRunFlag = 0;                                                             //06-08-18|0x01a6
            SystemMsg;                                                                    //06-08-18|0x01a6
            break;                                                                        //06-08-18|0x01a6
        }                                                                                 //06-08-18|0x01a6
        break;                                                                            //06-08-18|0x01a6
//---------------------------------------------------------------------------             //06-09-07|0x01a7
      case 40210: // APPEND_PREPARE                                                       //06-09-07|0x01a8
        switch(text_prepare())                                                            //06-09-07|0x01a8
        {                                                                                 //06-09-07|0x01a8
          case Success:                                                                   //06-09-07|0x01a8
            MacroRunFlag = 1;                                                             //06-09-07|0x01a8
            MacroPrepareState = 28337; // APPEND_NAME                                     //06-09-07|0x01a8
            break;                                                                        //06-09-07|0x01a8
          case UserError:                                                                 //06-09-07|0x01a8
            MacroRunFlag = 1;                                                             //06-09-07|0x01a8
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-09-07|0x01a8
            break;                                                                        //06-09-07|0x01a8
          default:                                                                        //06-09-07|0x01a8
            MacroStatus = SystemError;                                                    //06-09-07|0x01a8
            MacroRunFlag = 0;                                                             //06-09-07|0x01a8
            SystemMsg;                                                                    //06-09-07|0x01a8
            break;                                                                        //06-09-07|0x01a8
        }                                                                                 //06-09-07|0x01a8
        break;                                                                            //06-09-07|0x01a8
//---------------------------------------------------------------------------             //06-09-07|0x01a9
      case 28337: // APPEND_NAME                                                          //06-09-07|0x01aa
        switch(EnterAppendName)                                                           //06-09-07|0x01aa
        {                                                                                 //06-09-07|0x01aa
          case Success:                                                                   //06-09-07|0x01aa
            MacroRunFlag = 1;                                                             //06-09-07|0x01aa
            MacroPrepareState = 23104; // APPEND_DATE                                     //06-09-07|0x01aa
            break;                                                                        //06-09-07|0x01aa
          default:                                                                        //06-09-07|0x01aa
            MacroStatus = SystemError;                                                    //06-09-07|0x01aa
            MacroRunFlag = 0;                                                             //06-09-07|0x01aa
            SystemMsg;                                                                    //06-09-07|0x01aa
            break;                                                                        //06-09-07|0x01aa
        }                                                                                 //06-09-07|0x01aa
        break;                                                                            //06-09-07|0x01aa
//---------------------------------------------------------------------------             //06-09-07|0x01ab
      case 23104: // APPEND_DATE                                                          //06-09-07|0x01ac
        switch(AppendFileTime)                                                            //06-09-07|0x01ac
        {                                                                                 //06-09-07|0x01ac
          case Success:                                                                   //06-09-07|0x01ac
            MacroRunFlag = 1;                                                             //06-09-07|0x01ac
            MacroPrepareState = 65215; // APPEND_EXISTS                                   //06-09-07|0x01ac
            break;                                                                        //06-09-07|0x01ac
          default:                                                                        //06-09-07|0x01ac
            MacroStatus = SystemError;                                                    //06-09-07|0x01ac
            MacroRunFlag = 0;                                                             //06-09-07|0x01ac
            SystemMsg;                                                                    //06-09-07|0x01ac
            break;                                                                        //06-09-07|0x01ac
        }                                                                                 //06-09-07|0x01ac
        break;                                                                            //06-09-07|0x01ac
//---------------------------------------------------------------------------             //06-09-07|0x01ad
      case 65215: // APPEND_EXISTS                                                        //11-02-26|0x01ae
        switch(FileInDateExists)                                                          //11-02-26|0x01ae
        {                                                                                 //11-02-26|0x01ae
          case Yes:                                                                       //11-02-26|0x01ae
            MacroRunFlag = 1;                                                             //11-02-26|0x01ae
            MacroPrepareState = 60206; // APPEND_TEST                                     //11-02-26|0x01ae
            break;                                                                        //11-02-26|0x01ae
          case No:                                                                        //11-02-26|0x01ae
            MacroRunFlag = 1;                                                             //11-02-26|0x01ae
            MacroPrepareState = 40589; // NO_APPEND_FILE                                  //11-02-26|0x01ae
            break;                                                                        //11-02-26|0x01ae
          default:                                                                        //11-02-26|0x01ae
            MacroStatus = SystemError;                                                    //11-02-26|0x01ae
            MacroRunFlag = 0;                                                             //11-02-26|0x01ae
            SystemMsg;                                                                    //11-02-26|0x01ae
            break;                                                                        //11-02-26|0x01ae
        }                                                                                 //11-02-26|0x01ae
        break;                                                                            //11-02-26|0x01ae
//---------------------------------------------------------------------------             //11-02-26|0x01af
      case 60206: // APPEND_TEST                                                          //11-02-26|0x01b0
        BasicDateTest(2);                                                                 //11-02-26|0x01b0
        MacroPrepareState = 34780; // APPEND_VERSION                                      //11-02-26|0x01b0
        break;                                                                            //11-02-26|0x01b0
//***************************************************************************             //11-02-26|0x01b1
//***************************************************************************             //11-02-26|0x01b2
      case 34780: // APPEND_VERSION                                                       //11-02-26|0x01b3
        switch(MacroDevelopStatus)                                                        //11-02-26|0x01b3
        {                                                                                 //11-02-26|0x01b3
          case DS_RELEASE:                                                                //11-02-26|0x01b3
            MacroRunFlag = 1;                                                             //11-02-26|0x01b3
            MacroPrepareState = 1563; // GET_APPND_PARITY                                 //11-02-26|0x01b3
            break;                                                                        //11-02-26|0x01b3
          case DS_BETA:                                                                   //11-02-26|0x01b3
            MacroRunFlag = 1;                                                             //11-02-26|0x01b3
            MacroPrepareState = 1563; // GET_APPND_PARITY                                 //11-02-26|0x01b3
            break;                                                                        //11-02-26|0x01b3
          case DS_ALPHA:                                                                  //11-02-26|0x01b3
            MacroRunFlag = 1;                                                             //11-02-26|0x01b3
            MacroPrepareState = 1563; // GET_APPND_PARITY                                 //11-02-26|0x01b3
            break;                                                                        //11-02-26|0x01b3
          case DS_EXPERIMENT:                                                             //11-02-26|0x01b3
            MacroRunFlag = 1;                                                             //11-02-26|0x01b3
            MacroPrepareState = 31652; // READ_APPEND                                     //11-02-26|0x01b3
            break;                                                                        //11-02-26|0x01b3
          default:                                                                        //11-02-26|0x01b3
            MacroStatus = SystemError;                                                    //11-02-26|0x01b3
            MacroRunFlag = 0;                                                             //11-02-26|0x01b3
            SystemMsg;                                                                    //11-02-26|0x01b3
            break;                                                                        //11-02-26|0x01b3
        }                                                                                 //11-02-26|0x01b3
        break;                                                                            //11-02-26|0x01b3
//***************************************************************************             //11-02-26|0x01b4
      case 1563: // GET_APPND_PARITY                                                      //11-02-26|0x01b5
        switch(LoadAppendParity)                                                          //11-02-26|0x01b5
        {                                                                                 //11-02-26|0x01b5
          case Success:                                                                   //11-02-26|0x01b5
            MacroRunFlag = 1;                                                             //11-02-26|0x01b5
            MacroPrepareState = 31652; // READ_APPEND                                     //11-02-26|0x01b5
            break;                                                                        //11-02-26|0x01b5
          case UserError:                                                                 //11-02-26|0x01b5
            MacroRunFlag = 1;                                                             //11-02-26|0x01b5
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //11-02-26|0x01b5
            break;                                                                        //11-02-26|0x01b5
          default:                                                                        //11-02-26|0x01b5
            MacroStatus = SystemError;                                                    //11-02-26|0x01b5
            MacroRunFlag = 0;                                                             //11-02-26|0x01b5
            SystemMsg;                                                                    //11-02-26|0x01b5
            break;                                                                        //11-02-26|0x01b5
        }                                                                                 //11-02-26|0x01b5
        break;                                                                            //11-02-26|0x01b5
//***************************************************************************             //11-02-26|0x01b6
//***************************************************************************             //11-02-26|0x01b7
      case 40589: // NO_APPEND_FILE                                                       //06-09-07|0x01b8
        switch(LibraryDoesNotExist)                                                       //06-09-07|0x01b8
        {                                                                                 //06-09-07|0x01b8
          case UserError:                                                                 //06-09-07|0x01b8
            MacroRunFlag = 1;                                                             //06-09-07|0x01b8
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-09-07|0x01b8
            break;                                                                        //06-09-07|0x01b8
          default:                                                                        //06-09-07|0x01b8
            MacroStatus = SystemError;                                                    //06-09-07|0x01b8
            MacroRunFlag = 0;                                                             //06-09-07|0x01b8
            SystemMsg;                                                                    //06-09-07|0x01b8
            break;                                                                        //06-09-07|0x01b8
        }                                                                                 //06-09-07|0x01b8
        break;                                                                            //06-09-07|0x01b8
//---------------------------------------------------------------------------             //06-08-17|0x01b9
      case 57310: // COMMAND_ERROR                                                        //06-08-17|0x01ba
        switch(IllegalCommand)                                                            //06-08-17|0x01ba
        {                                                                                 //06-08-17|0x01ba
          case UserError:                                                                 //06-08-17|0x01ba
            MacroRunFlag = 1;                                                             //06-08-17|0x01ba
            MacroPrepareState = 1043; // CLOSE_ERROR                                      //06-08-17|0x01ba
            break;                                                                        //06-08-17|0x01ba
          default:                                                                        //06-08-17|0x01ba
            MacroStatus = SystemError;                                                    //06-08-17|0x01ba
            MacroRunFlag = 0;                                                             //06-08-17|0x01ba
            SystemMsg;                                                                    //06-08-17|0x01ba
            break;                                                                        //06-08-17|0x01ba
        }                                                                                 //06-08-17|0x01ba
        break;                                                                            //06-08-17|0x01ba
//***************************************************************************             //06-08-17|0x01bb
//******                                                               ******             //06-08-17|0x01bc
//****** Close States                                                  ******             //06-08-17|0x01bd
//******                                                               ******             //06-08-17|0x01be
//***************************************************************************             //06-08-17|0x01bf
      case 40405: // CLOSE_OK                                                             //11-02-13|0x01c0
        switch(CloseProject)                                                              //11-02-13|0x01c0
        {                                                                                 //11-02-13|0x01c0
          case Success:                                                                   //11-02-13|0x01c0
            MacroRunFlag = 1;                                                             //11-02-13|0x01c0
            MacroPrepareState = 26698; // OK                                              //11-02-13|0x01c0
            break;                                                                        //11-02-13|0x01c0
          default:                                                                        //11-02-13|0x01c0
            MacroStatus = SystemError;                                                    //11-02-13|0x01c0
            MacroRunFlag = 0;                                                             //11-02-13|0x01c0
            SystemMsg;                                                                    //11-02-13|0x01c0
            break;                                                                        //11-02-13|0x01c0
        }                                                                                 //11-02-13|0x01c0
        break;                                                                            //11-02-13|0x01c0
//---------------------------------------------------------------------------             //06-08-17|0x01c1
      case 1043: // CLOSE_ERROR                                                           //06-08-17|0x01c2
        switch(CloseProject)                                                              //06-08-17|0x01c2
        {                                                                                 //06-08-17|0x01c2
          case Success:                                                                   //06-08-17|0x01c2
            MacroRunFlag = 1;                                                             //06-08-17|0x01c2
            MacroPrepareState = 696; // ERROR                                             //06-08-17|0x01c2
            break;                                                                        //06-08-17|0x01c2
          default:                                                                        //06-08-17|0x01c2
            MacroStatus = SystemError;                                                    //06-08-17|0x01c2
            MacroRunFlag = 0;                                                             //06-08-17|0x01c2
            SystemMsg;                                                                    //06-08-17|0x01c2
            break;                                                                        //06-08-17|0x01c2
        }                                                                                 //06-08-17|0x01c2
        break;                                                                            //06-08-17|0x01c2
//***************************************************************************             //06-08-16|0x01c3
//******                                                               ******             //06-08-16|0x01c4
//****** Exit States                                                   ******             //06-08-16|0x01c5
//******                                                               ******             //06-08-16|0x01c6
//***************************************************************************             //06-08-16|0x01c7
      case 26698: // OK                                                                   //11-02-13|0x01c8
        MacroPrepareState = 4462; // ENTER_PROJECT_NAME                                   //11-02-13|0x01c8
        MacroStatus = Success;                                                            //11-02-13|0x01c8
        MacroRunFlag = 0;                                                                 //11-02-13|0x01c8
        break;                                                                            //11-02-13|0x01c8
//---------------------------------------------------------------------------             //06-08-16|0x01c9
      case 696: // ERROR                                                                  //06-08-16|0x01ca
        MacroPrepareState = 4462; // ENTER_PROJECT_NAME                                   //06-08-16|0x01ca
        MacroStatus = UserError;                                                          //06-08-16|0x01ca
        MacroRunFlag = 0;                                                                 //06-08-16|0x01ca
        break;                                                                            //06-08-16|0x01ca
//***************************************************************************             //06-08-16|0x01cb
      default:                                                                            //06-08-16|0x01cc
        MacroStatus = SystemError;                                                        //06-08-16|0x01cc
        MacroRunFlag = 0;                                                                 //06-08-16|0x01cc
        SystemMsg;                                                                        //06-08-16|0x01cc
        break;                                                                            //06-08-16|0x01cc
    }                                                                                     //06-08-16|0x01cc
  }                                                                                       //06-08-16|0x01cc
//***************************************************************************             //06-08-16|0x01cd
//***************************************************************************             //06-08-16|0x01ce
    return(MacroStatus);                                                                  //06-09-07|0x01cf
}                                                                                         //06-08-16|0x01d2
//                                                                                        //05-24-97|0x01d2
//***************************************************************************             //06-08-18|0x01d5
//***************************************************************************             //06-08-18|0x01d6
//******                                                               ******             //06-08-18|0x01d7
//******                        macproj_build                          ******             //06-08-18|0x01d8
//******---------------------------------------------------------------******             //06-08-18|0x01d9
//******     Token(1):  Project Complete Path-File Name                ******             //06-08-18|0x01da
//******     Token(2):  Library Path                                   ******             //06-08-18|0x01db
//******     Token(3):  Macro Path                                     ******             //06-08-18|0x01dc
//******                                                               ******             //06-08-18|0x01dd
//***************************************************************************             //06-08-18|0x01de
//***************************************************************************             //06-08-18|0x01df
//*******************************************************************************         //10-29-97|0x01e3
//*******************************************************************************         //10-29-97|0x01e3
// macproj_build                                                                          //06-08-18|0x01e3
//*******************************************************************************         //10-29-97|0x01e3
//*******************************************************************************         //10-29-97|0x01e3
UINT MACROPROJ::macproj_build(                                                            //06-08-18|0x01e3
    TOKENS_FAR InputAddr                                                                  //06-08-18|0x01e3
    ) {                                                                                   //06-08-18|0x01e3
//*******************************************************************************         //10-29-97|0x01e3
//***************************************************************************             //06-08-18|0x01e6
//***************************************************************************             //06-08-18|0x01e7
    if(macro_project_addr == 0)                             ReturnSystemError             //06-08-18|0x01e8
//***************************************************************************             //06-08-18|0x01e9
//******                                                               ******             //06-08-18|0x01ea
//****** State Machine Beginning                                       ******             //06-08-18|0x01eb
//******                                                               ******             //06-08-18|0x01ec
//***************************************************************************             //06-08-18|0x01ed
  MacroRunFlag = 1;                                                                       //06-09-07|0x01ee
  while(MacroRunFlag != 0)                                                                //06-09-07|0x01ee
  {                                                                                       //06-09-07|0x01ee
    switch(MacroBuildState)                                                               //06-09-07|0x01ee
    {                                                                                     //06-09-07|0x01ee
//***************************************************************************             //06-08-18|0x01ef
//******                                                               ******             //06-08-18|0x01f0
//****** Open Project File,                                            ******             //06-08-18|0x01f1
//******                                                               ******             //06-08-18|0x01f2
//***************************************************************************             //06-08-18|0x01f3
      case 4462: // ENTER_PROJECT_NAME                                                    //06-08-18|0x01f4
        switch(EnterProjectName)                                                          //06-08-18|0x01f4
        {                                                                                 //06-08-18|0x01f4
          case Success:                                                                   //06-08-18|0x01f4
            MacroRunFlag = 1;                                                             //06-08-18|0x01f4
            MacroBuildState = 10445; // OPEN_PROJECT_FILE                                 //06-08-18|0x01f4
            break;                                                                        //06-08-18|0x01f4
          default:                                                                        //06-08-18|0x01f4
            MacroStatus = SystemError;                                                    //06-08-18|0x01f4
            MacroRunFlag = 0;                                                             //06-08-18|0x01f4
            SystemMsg;                                                                    //06-08-18|0x01f4
            break;                                                                        //06-08-18|0x01f4
        }                                                                                 //06-08-18|0x01f4
        break;                                                                            //06-08-18|0x01f4
//---------------------------------------------------------------------------             //06-08-18|0x01f5
      case 10445: // OPEN_PROJECT_FILE                                                    //11-06-13|0x01f6
        switch(OpenProject)                                                               //11-06-13|0x01f6
        {                                                                                 //11-06-13|0x01f6
          case Success:                                                                   //11-06-13|0x01f6
            MacroRunFlag = 1;                                                             //11-06-13|0x01f6
            MacroBuildState = 46620; // READ_DISPLAY                                      //11-06-13|0x01f6
            break;                                                                        //11-06-13|0x01f6
          default:                                                                        //11-06-13|0x01f6
            MacroStatus = SystemError;                                                    //11-06-13|0x01f6
            MacroRunFlag = 0;                                                             //11-06-13|0x01f6
            SystemMsg;                                                                    //11-06-13|0x01f6
            break;                                                                        //11-06-13|0x01f6
        }                                                                                 //11-06-13|0x01f6
        break;                                                                            //11-06-13|0x01f6
//***************************************************************************             //11-06-13|0x01f7
//******                                                               ******             //11-06-13|0x01f8
//****** Process Display                                               ******             //11-06-13|0x01f9
//******                                                               ******             //11-06-13|0x01fa
//***************************************************************************             //11-06-13|0x01fb
      case 46620: // READ_DISPLAY                                                         //11-06-13|0x01fc
        switch(ReadProject)                                                               //11-06-13|0x01fc
        {                                                                                 //11-06-13|0x01fc
          case Display:                                                                   //11-06-13|0x01fc
            MacroBuildState = 6235; // READ_DISPLAY_EXIT                                  //11-06-13|0x01fc
            MacroStatus = Display;                                                        //11-06-13|0x01fc
            MacroRunFlag = 0;                                                             //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          case LineDone:                                                                  //11-06-13|0x01fc
            MacroRunFlag = 1;                                                             //11-06-13|0x01fc
            MacroBuildState = 40586; // DISPLAY                                           //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          case FileDone:                                                                  //11-06-13|0x01fc
            MacroRunFlag = 1;                                                             //11-06-13|0x01fc
            MacroBuildState = 34729; // END_FILE                                          //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          case UserError:                                                                 //11-06-13|0x01fc
            MacroRunFlag = 1;                                                             //11-06-13|0x01fc
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          default:                                                                        //11-06-13|0x01fc
            MacroStatus = SystemError;                                                    //11-06-13|0x01fc
            MacroRunFlag = 0;                                                             //11-06-13|0x01fc
            SystemMsg;                                                                    //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
        }                                                                                 //11-06-13|0x01fc
        break;                                                                            //11-06-13|0x01fc
//**************************************************************************              //11-06-13|0x01fc
      case 6235: // READ_DISPLAY_EXIT                                                     //11-06-13|0x01fc
        switch(ReadProject)                                                               //11-06-13|0x01fc
        {                                                                                 //11-06-13|0x01fc
          case Display:                                                                   //11-06-13|0x01fc
            MacroBuildState = 6235; // READ_DISPLAY_EXIT                                  //11-06-13|0x01fc
            MacroStatus = Display;                                                        //11-06-13|0x01fc
            MacroRunFlag = 0;                                                             //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          case LineDone:                                                                  //11-06-13|0x01fc
            MacroRunFlag = 1;                                                             //11-06-13|0x01fc
            MacroBuildState = 40586; // DISPLAY                                           //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          case FileDone:                                                                  //11-06-13|0x01fc
            MacroRunFlag = 1;                                                             //11-06-13|0x01fc
            MacroBuildState = 34729; // END_FILE                                          //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          case UserError:                                                                 //11-06-13|0x01fc
            MacroRunFlag = 1;                                                             //11-06-13|0x01fc
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
          default:                                                                        //11-06-13|0x01fc
            MacroStatus = SystemError;                                                    //11-06-13|0x01fc
            MacroRunFlag = 0;                                                             //11-06-13|0x01fc
            SystemMsg;                                                                    //11-06-13|0x01fc
            break;                                                                        //11-06-13|0x01fc
        }                                                                                 //11-06-13|0x01fc
        break;                                                                            //11-06-13|0x01fc
//---------------------------------------------------------------------------             //11-06-13|0x01fd
      case 40586: // DISPLAY                                                              //11-06-13|0x01fe
        switch(CmdTest("_DISPLAY"))                                                       //11-06-13|0x01fe
        {                                                                                 //11-06-13|0x01fe
          case -1:                                                                        //11-06-13|0x01fe
            MacroRunFlag = 1;                                                             //11-06-13|0x01fe
            MacroBuildState = 11959; // TASK_NO                                           //11-06-13|0x01fe
            break;                                                                        //11-06-13|0x01fe
          case 0:                                                                         //11-06-13|0x01fe
            MacroRunFlag = 1;                                                             //11-06-13|0x01fe
            MacroBuildState = 6822; // READ_TASK_NO                                       //11-06-13|0x01fe
            break;                                                                        //11-06-13|0x01fe
          case 1:                                                                         //11-06-13|0x01fe
            MacroRunFlag = 1;                                                             //11-06-13|0x01fe
            MacroBuildState = 11959; // TASK_NO                                           //11-06-13|0x01fe
            break;                                                                        //11-06-13|0x01fe
          default:                                                                        //11-06-13|0x01fe
            MacroStatus = SystemError;                                                    //11-06-13|0x01fe
            MacroRunFlag = 0;                                                             //11-06-13|0x01fe
            SystemMsg;                                                                    //11-06-13|0x01fe
            break;                                                                        //11-06-13|0x01fe
        }                                                                                 //11-06-13|0x01fe
        break;                                                                            //11-06-13|0x01fe
//***************************************************************************             //09-03-27|0x01ff
//******                                                               ******             //09-03-27|0x0200
//****** Process Task No                                               ******             //09-03-27|0x0201
//******                                                               ******             //09-03-27|0x0202
//***************************************************************************             //09-03-27|0x0203
      case 6822: // READ_TASK_NO                                                          //09-03-27|0x0204
        switch(ReadProject)                                                               //09-03-27|0x0204
        {                                                                                 //09-03-27|0x0204
          case Display:                                                                   //09-03-27|0x0204
            MacroBuildState = 50565; // READ_TASK_NO_EXIT                                 //09-03-27|0x0204
            MacroStatus = Display;                                                        //09-03-27|0x0204
            MacroRunFlag = 0;                                                             //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          case LineDone:                                                                  //09-03-27|0x0204
            MacroRunFlag = 1;                                                             //09-03-27|0x0204
            MacroBuildState = 11959; // TASK_NO                                           //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          case FileDone:                                                                  //09-03-27|0x0204
            MacroRunFlag = 1;                                                             //09-03-27|0x0204
            MacroBuildState = 34729; // END_FILE                                          //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          case UserError:                                                                 //09-03-27|0x0204
            MacroRunFlag = 1;                                                             //09-03-27|0x0204
            MacroBuildState = 696; // CLOSE_ERROR                                         //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          default:                                                                        //09-03-27|0x0204
            MacroStatus = SystemError;                                                    //09-03-27|0x0204
            MacroRunFlag = 0;                                                             //09-03-27|0x0204
            SystemMsg;                                                                    //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
        }                                                                                 //09-03-27|0x0204
        break;                                                                            //09-03-27|0x0204
//**************************************************************************              //09-03-27|0x0204
      case 50565: // READ_TASK_NO_EXIT                                                    //09-03-27|0x0204
        switch(ReadProject)                                                               //09-03-27|0x0204
        {                                                                                 //09-03-27|0x0204
          case Display:                                                                   //09-03-27|0x0204
            MacroBuildState = 50565; // READ_TASK_NO_EXIT                                 //09-03-27|0x0204
            MacroStatus = Display;                                                        //09-03-27|0x0204
            MacroRunFlag = 0;                                                             //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          case LineDone:                                                                  //09-03-27|0x0204
            MacroRunFlag = 1;                                                             //09-03-27|0x0204
            MacroBuildState = 11959; // TASK_NO                                           //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          case FileDone:                                                                  //09-03-27|0x0204
            MacroRunFlag = 1;                                                             //09-03-27|0x0204
            MacroBuildState = 34729; // END_FILE                                          //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          case UserError:                                                                 //09-03-27|0x0204
            MacroRunFlag = 1;                                                             //09-03-27|0x0204
            MacroBuildState = 696; // CLOSE_ERROR                                         //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
          default:                                                                        //09-03-27|0x0204
            MacroStatus = SystemError;                                                    //09-03-27|0x0204
            MacroRunFlag = 0;                                                             //09-03-27|0x0204
            SystemMsg;                                                                    //09-03-27|0x0204
            break;                                                                        //09-03-27|0x0204
        }                                                                                 //09-03-27|0x0204
        break;                                                                            //09-03-27|0x0204
//---------------------------------------------------------------------------             //09-03-27|0x0205
      case 11959: // TASK_NO                                                              //09-03-27|0x0206
        switch(CmdTest("_TASK_NO"))                                                       //09-03-27|0x0206
        {                                                                                 //09-03-27|0x0206
          case -1:                                                                        //09-03-27|0x0206
            MacroRunFlag = 1;                                                             //09-03-27|0x0206
            MacroBuildState = 7764; // TASK_NO_ERROR                                      //09-03-27|0x0206
            break;                                                                        //09-03-27|0x0206
          case 0:                                                                         //09-03-27|0x0206
            MacroRunFlag = 1;                                                             //09-03-27|0x0206
            MacroBuildState = 1043; // READ_UPDATE                                        //09-03-27|0x0206
            break;                                                                        //09-03-27|0x0206
          case 1:                                                                         //09-03-27|0x0206
            MacroRunFlag = 1;                                                             //09-03-27|0x0206
            MacroBuildState = 7764; // TASK_NO_ERROR                                      //09-03-27|0x0206
            break;                                                                        //09-03-27|0x0206
          default:                                                                        //09-03-27|0x0206
            MacroStatus = SystemError;                                                    //09-03-27|0x0206
            MacroRunFlag = 0;                                                             //09-03-27|0x0206
            SystemMsg;                                                                    //09-03-27|0x0206
            break;                                                                        //09-03-27|0x0206
        }                                                                                 //09-03-27|0x0206
        break;                                                                            //09-03-27|0x0206
//---------------------------------------------------------------------------             //09-03-27|0x0207
      case 7764: // TASK_NO_ERROR                                                         //09-03-27|0x0208
        SystemMsg;                                                                        //09-03-27|0x0208
        MacroBuildState = 17858; // SYSTEM                                                //09-03-27|0x0208
        break;                                                                            //09-03-27|0x0208
//***************************************************************************             //07-10-30|0x0209
//******                                                               ******             //07-10-30|0x020a
//****** Process Update                                                ******             //07-10-30|0x020b
//******                                                               ******             //07-10-30|0x020c
//***************************************************************************             //07-10-30|0x020d
      case 1043: // READ_UPDATE                                                           //07-10-30|0x020e
        switch(ReadProject)                                                               //07-10-30|0x020e
        {                                                                                 //07-10-30|0x020e
          case Display:                                                                   //07-10-30|0x020e
            MacroBuildState = 41569; // READ_UPDATE_EXIT                                  //07-10-30|0x020e
            MacroStatus = Display;                                                        //07-10-30|0x020e
            MacroRunFlag = 0;                                                             //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          case LineDone:                                                                  //07-10-30|0x020e
            MacroRunFlag = 1;                                                             //07-10-30|0x020e
            MacroBuildState = 51440; // UPDATE                                            //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          case FileDone:                                                                  //07-10-30|0x020e
            MacroRunFlag = 1;                                                             //07-10-30|0x020e
            MacroBuildState = 34729; // END_FILE                                          //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          case UserError:                                                                 //07-10-30|0x020e
            MacroRunFlag = 1;                                                             //07-10-30|0x020e
            MacroBuildState = 696; // CLOSE_ERROR                                         //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          default:                                                                        //07-10-30|0x020e
            MacroStatus = SystemError;                                                    //07-10-30|0x020e
            MacroRunFlag = 0;                                                             //07-10-30|0x020e
            SystemMsg;                                                                    //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
        }                                                                                 //07-10-30|0x020e
        break;                                                                            //07-10-30|0x020e
//**************************************************************************              //07-10-30|0x020e
      case 41569: // READ_UPDATE_EXIT                                                     //07-10-30|0x020e
        switch(ReadProject)                                                               //07-10-30|0x020e
        {                                                                                 //07-10-30|0x020e
          case Display:                                                                   //07-10-30|0x020e
            MacroBuildState = 41569; // READ_UPDATE_EXIT                                  //07-10-30|0x020e
            MacroStatus = Display;                                                        //07-10-30|0x020e
            MacroRunFlag = 0;                                                             //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          case LineDone:                                                                  //07-10-30|0x020e
            MacroRunFlag = 1;                                                             //07-10-30|0x020e
            MacroBuildState = 51440; // UPDATE                                            //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          case FileDone:                                                                  //07-10-30|0x020e
            MacroRunFlag = 1;                                                             //07-10-30|0x020e
            MacroBuildState = 34729; // END_FILE                                          //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          case UserError:                                                                 //07-10-30|0x020e
            MacroRunFlag = 1;                                                             //07-10-30|0x020e
            MacroBuildState = 696; // CLOSE_ERROR                                         //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
          default:                                                                        //07-10-30|0x020e
            MacroStatus = SystemError;                                                    //07-10-30|0x020e
            MacroRunFlag = 0;                                                             //07-10-30|0x020e
            SystemMsg;                                                                    //07-10-30|0x020e
            break;                                                                        //07-10-30|0x020e
        }                                                                                 //07-10-30|0x020e
        break;                                                                            //07-10-30|0x020e
//---------------------------------------------------------------------------             //07-10-30|0x020f
      case 51440: // UPDATE                                                               //11-02-14|0x0210
        switch(CmdTest("_UPDATE"))                                                        //11-02-14|0x0210
        {                                                                                 //11-02-14|0x0210
          case -1:                                                                        //11-02-14|0x0210
            MacroRunFlag = 1;                                                             //11-02-14|0x0210
            MacroBuildState = 22639; // RELEASE_VERSION                                   //11-02-14|0x0210
            break;                                                                        //11-02-14|0x0210
          case 0:                                                                         //11-02-14|0x0210
            MacroRunFlag = 1;                                                             //11-02-14|0x0210
            MacroBuildState = 57310; // UNCOND_UPDATE                                     //11-02-14|0x0210
            break;                                                                        //11-02-14|0x0210
          case 1:                                                                         //11-02-14|0x0210
            MacroRunFlag = 1;                                                             //11-02-14|0x0210
            MacroBuildState = 22639; // RELEASE_VERSION                                   //11-02-14|0x0210
            break;                                                                        //11-02-14|0x0210
          default:                                                                        //11-02-14|0x0210
            MacroStatus = SystemError;                                                    //11-02-14|0x0210
            MacroRunFlag = 0;                                                             //11-02-14|0x0210
            SystemMsg;                                                                    //11-02-14|0x0210
            break;                                                                        //11-02-14|0x0210
        }                                                                                 //11-02-14|0x0210
        break;                                                                            //11-02-14|0x0210
//---------------------------------------------------------------------------             //11-02-14|0x0211
      case 57310: // UNCOND_UPDATE                                                        //11-02-14|0x0212
        switch(uncond_update())                                                           //11-02-14|0x0212
        {                                                                                 //11-02-14|0x0212
          case Success:                                                                   //11-02-14|0x0212
            MacroRunFlag = 1;                                                             //11-02-14|0x0212
            MacroBuildState = 56893; // READ_VERSIUB                                      //11-02-14|0x0212
            break;                                                                        //11-02-14|0x0212
          case UserError:                                                                 //11-02-14|0x0212
            MacroRunFlag = 1;                                                             //11-02-14|0x0212
            MacroBuildState = 49804; // UPDATE_ERROR                                      //11-02-14|0x0212
            break;                                                                        //11-02-14|0x0212
          default:                                                                        //11-02-14|0x0212
            MacroStatus = SystemError;                                                    //11-02-14|0x0212
            MacroRunFlag = 0;                                                             //11-02-14|0x0212
            SystemMsg;                                                                    //11-02-14|0x0212
            break;                                                                        //11-02-14|0x0212
        }                                                                                 //11-02-14|0x0212
        break;                                                                            //11-02-14|0x0212
//---------------------------------------------------------------------------             //11-02-14|0x0213
      case 49804: // UPDATE_ERROR                                                         //11-02-14|0x0214
        SystemMsg;                                                                        //11-02-14|0x0214
        MacroBuildState = 17858; // SYSTEM                                                //11-02-14|0x0214
        break;                                                                            //11-02-14|0x0214
//***************************************************************************             //11-02-13|0x0215
//******                                                               ******             //11-02-13|0x0216
//****** Process Development State Commands                            ******             //11-02-13|0x0217
//******                                                               ******             //11-02-13|0x0218
//***************************************************************************             //11-02-13|0x0219
      case 56893: // READ_VERSIUB                                                         //11-02-13|0x021a
        switch(ReadProject)                                                               //11-02-13|0x021a
        {                                                                                 //11-02-13|0x021a
          case Display:                                                                   //11-02-13|0x021a
            MacroBuildState = 60363; // READ_VERSIUB_EXIT                                 //11-02-13|0x021a
            MacroStatus = Display;                                                        //11-02-13|0x021a
            MacroRunFlag = 0;                                                             //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          case LineDone:                                                                  //11-02-13|0x021a
            MacroRunFlag = 1;                                                             //11-02-13|0x021a
            MacroBuildState = 22639; // RELEASE_VERSION                                   //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          case FileDone:                                                                  //11-02-13|0x021a
            MacroRunFlag = 1;                                                             //11-02-13|0x021a
            MacroBuildState = 34729; // END_FILE                                          //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          case UserError:                                                                 //11-02-13|0x021a
            MacroRunFlag = 1;                                                             //11-02-13|0x021a
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          default:                                                                        //11-02-13|0x021a
            MacroStatus = SystemError;                                                    //11-02-13|0x021a
            MacroRunFlag = 0;                                                             //11-02-13|0x021a
            SystemMsg;                                                                    //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
        }                                                                                 //11-02-13|0x021a
        break;                                                                            //11-02-13|0x021a
//**************************************************************************              //11-02-13|0x021a
      case 60363: // READ_VERSIUB_EXIT                                                    //11-02-13|0x021a
        switch(ReadProject)                                                               //11-02-13|0x021a
        {                                                                                 //11-02-13|0x021a
          case Display:                                                                   //11-02-13|0x021a
            MacroBuildState = 60363; // READ_VERSIUB_EXIT                                 //11-02-13|0x021a
            MacroStatus = Display;                                                        //11-02-13|0x021a
            MacroRunFlag = 0;                                                             //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          case LineDone:                                                                  //11-02-13|0x021a
            MacroRunFlag = 1;                                                             //11-02-13|0x021a
            MacroBuildState = 22639; // RELEASE_VERSION                                   //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          case FileDone:                                                                  //11-02-13|0x021a
            MacroRunFlag = 1;                                                             //11-02-13|0x021a
            MacroBuildState = 34729; // END_FILE                                          //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          case UserError:                                                                 //11-02-13|0x021a
            MacroRunFlag = 1;                                                             //11-02-13|0x021a
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
          default:                                                                        //11-02-13|0x021a
            MacroStatus = SystemError;                                                    //11-02-13|0x021a
            MacroRunFlag = 0;                                                             //11-02-13|0x021a
            SystemMsg;                                                                    //11-02-13|0x021a
            break;                                                                        //11-02-13|0x021a
        }                                                                                 //11-02-13|0x021a
        break;                                                                            //11-02-13|0x021a
//---------------------------------------------------------------------------             //11-02-13|0x021b
      case 22639: // RELEASE_VERSION                                                      //11-02-13|0x021c
        switch(CmdTest("_RELEASE_VERSION"))                                               //11-02-13|0x021c
        {                                                                                 //11-02-13|0x021c
          case -1:                                                                        //11-02-13|0x021c
            MacroRunFlag = 1;                                                             //11-02-13|0x021c
            MacroBuildState = 43258; // BETA_VERSION                                      //11-02-13|0x021c
            break;                                                                        //11-02-13|0x021c
          case 0:                                                                         //11-02-13|0x021c
            MacroRunFlag = 1;                                                             //11-02-13|0x021c
            MacroBuildState = 14617; // REPORT_PREPARE                                    //11-02-13|0x021c
            break;                                                                        //11-02-13|0x021c
          case 1:                                                                         //11-02-13|0x021c
            MacroRunFlag = 1;                                                             //11-02-13|0x021c
            MacroBuildState = 43258; // BETA_VERSION                                      //11-02-13|0x021c
            break;                                                                        //11-02-13|0x021c
          default:                                                                        //11-02-13|0x021c
            MacroStatus = SystemError;                                                    //11-02-13|0x021c
            MacroRunFlag = 0;                                                             //11-02-13|0x021c
            SystemMsg;                                                                    //11-02-13|0x021c
            break;                                                                        //11-02-13|0x021c
        }                                                                                 //11-02-13|0x021c
        break;                                                                            //11-02-13|0x021c
//---------------------------------------------------------------------------             //11-02-13|0x021d
      case 43258: // BETA_VERSION                                                         //11-02-13|0x021e
        switch(CmdTest("_BETA_VERSION"))                                                  //11-02-13|0x021e
        {                                                                                 //11-02-13|0x021e
          case -1:                                                                        //11-02-13|0x021e
            MacroRunFlag = 1;                                                             //11-02-13|0x021e
            MacroBuildState = 52008; // ALPHA_VERSION                                     //11-02-13|0x021e
            break;                                                                        //11-02-13|0x021e
          case 0:                                                                         //11-02-13|0x021e
            MacroRunFlag = 1;                                                             //11-02-13|0x021e
            MacroBuildState = 14617; // REPORT_PREPARE                                    //11-02-13|0x021e
            break;                                                                        //11-02-13|0x021e
          case 1:                                                                         //11-02-13|0x021e
            MacroRunFlag = 1;                                                             //11-02-13|0x021e
            MacroBuildState = 52008; // ALPHA_VERSION                                     //11-02-13|0x021e
            break;                                                                        //11-02-13|0x021e
          default:                                                                        //11-02-13|0x021e
            MacroStatus = SystemError;                                                    //11-02-13|0x021e
            MacroRunFlag = 0;                                                             //11-02-13|0x021e
            SystemMsg;                                                                    //11-02-13|0x021e
            break;                                                                        //11-02-13|0x021e
        }                                                                                 //11-02-13|0x021e
        break;                                                                            //11-02-13|0x021e
//---------------------------------------------------------------------------             //11-02-13|0x021f
      case 52008: // ALPHA_VERSION                                                        //11-02-13|0x0220
        switch(CmdTest("_ALPHA_VERSION"))                                                 //11-02-13|0x0220
        {                                                                                 //11-02-13|0x0220
          case -1:                                                                        //11-02-13|0x0220
            MacroRunFlag = 1;                                                             //11-02-13|0x0220
            MacroBuildState = 32295; // LIBRARY                                           //11-02-13|0x0220
            break;                                                                        //11-02-13|0x0220
          case 0:                                                                         //11-02-13|0x0220
            MacroRunFlag = 1;                                                             //11-02-13|0x0220
            MacroBuildState = 14617; // REPORT_PREPARE                                    //11-02-13|0x0220
            break;                                                                        //11-02-13|0x0220
          case 1:                                                                         //11-02-13|0x0220
            MacroRunFlag = 1;                                                             //11-02-13|0x0220
            MacroBuildState = 32295; // LIBRARY                                           //11-02-13|0x0220
            break;                                                                        //11-02-13|0x0220
          default:                                                                        //11-02-13|0x0220
            MacroStatus = SystemError;                                                    //11-02-13|0x0220
            MacroRunFlag = 0;                                                             //11-02-13|0x0220
            SystemMsg;                                                                    //11-02-13|0x0220
            break;                                                                        //11-02-13|0x0220
        }                                                                                 //11-02-13|0x0220
        break;                                                                            //11-02-13|0x0220
//***************************************************************************             //11-02-13|0x0221
      case 14617: // REPORT_PREPARE                                                       //11-02-14|0x0222
        switch(text_prepare())                                                            //11-02-14|0x0222
        {                                                                                 //11-02-14|0x0222
          case Success:                                                                   //11-02-14|0x0222
            MacroRunFlag = 1;                                                             //11-02-14|0x0222
            MacroBuildState = 24854; // CREATE_REPORT                                     //11-02-14|0x0222
            break;                                                                        //11-02-14|0x0222
          case UserError:                                                                 //11-02-14|0x0222
            MacroRunFlag = 1;                                                             //11-02-14|0x0222
            MacroBuildState = 29429; // COMMAND_ERROR                                     //11-02-14|0x0222
            break;                                                                        //11-02-14|0x0222
          default:                                                                        //11-02-14|0x0222
            MacroStatus = SystemError;                                                    //11-02-14|0x0222
            MacroRunFlag = 0;                                                             //11-02-14|0x0222
            SystemMsg;                                                                    //11-02-14|0x0222
            break;                                                                        //11-02-14|0x0222
        }                                                                                 //11-02-14|0x0222
        break;                                                                            //11-02-14|0x0222
//---------------------------------------------------------------------------             //11-02-14|0x0223
      case 24854: // CREATE_REPORT                                                        //11-02-26|0x0224
        switch(create_report())                                                           //11-02-26|0x0224
        {                                                                                 //11-02-26|0x0224
          case Success:                                                                   //11-02-26|0x0224
            MacroRunFlag = 1;                                                             //11-02-26|0x0224
            MacroBuildState = 41668; // READ_LIBRARY_NAME                                 //11-02-26|0x0224
            break;                                                                        //11-02-26|0x0224
          case UserError:                                                                 //11-02-26|0x0224
            MacroRunFlag = 1;                                                             //11-02-26|0x0224
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-02-26|0x0224
            break;                                                                        //11-02-26|0x0224
          default:                                                                        //11-02-26|0x0224
            MacroStatus = SystemError;                                                    //11-02-26|0x0224
            MacroRunFlag = 0;                                                             //11-02-26|0x0224
            SystemMsg;                                                                    //11-02-26|0x0224
            break;                                                                        //11-02-26|0x0224
        }                                                                                 //11-02-26|0x0224
        break;                                                                            //11-02-26|0x0224
//---------------------------------------------------------------------------             //11-02-14|0x0225
      case 29429: // COMMAND_ERROR                                                        //11-02-26|0x0226
        switch(IllegalCommand)                                                            //11-02-26|0x0226
        {                                                                                 //11-02-26|0x0226
          case UserError:                                                                 //11-02-26|0x0226
            MacroRunFlag = 1;                                                             //11-02-26|0x0226
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-02-26|0x0226
            break;                                                                        //11-02-26|0x0226
          default:                                                                        //11-02-26|0x0226
            MacroStatus = SystemError;                                                    //11-02-26|0x0226
            MacroRunFlag = 0;                                                             //11-02-26|0x0226
            SystemMsg;                                                                    //11-02-26|0x0226
            break;                                                                        //11-02-26|0x0226
        }                                                                                 //11-02-26|0x0226
        break;                                                                            //11-02-26|0x0226
//***************************************************************************             //06-08-18|0x0227
//******                                                               ******             //06-08-18|0x0228
//****** Create Library                                                ******             //06-08-18|0x0229
//******                                                               ******             //06-08-18|0x022a
//***************************************************************************             //06-08-18|0x022b
      case 41668: // READ_LIBRARY_NAME                                                    //06-08-18|0x022c
        switch(ReadProject)                                                               //06-08-18|0x022c
        {                                                                                 //06-08-18|0x022c
          case Display:                                                                   //06-08-18|0x022c
            MacroBuildState = 53123; // READ_LIBRARY_NAME_EXIT                            //06-08-18|0x022c
            MacroStatus = Display;                                                        //06-08-18|0x022c
            MacroRunFlag = 0;                                                             //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          case LineDone:                                                                  //06-08-18|0x022c
            MacroRunFlag = 1;                                                             //06-08-18|0x022c
            MacroBuildState = 32295; // LIBRARY                                           //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          case FileDone:                                                                  //06-08-18|0x022c
            MacroRunFlag = 1;                                                             //06-08-18|0x022c
            MacroBuildState = 34729; // END_FILE                                          //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          case UserError:                                                                 //06-08-18|0x022c
            MacroRunFlag = 1;                                                             //06-08-18|0x022c
            MacroBuildState = 696; // CLOSE_ERROR                                         //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          default:                                                                        //06-08-18|0x022c
            MacroStatus = SystemError;                                                    //06-08-18|0x022c
            MacroRunFlag = 0;                                                             //06-08-18|0x022c
            SystemMsg;                                                                    //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
        }                                                                                 //06-08-18|0x022c
        break;                                                                            //06-08-18|0x022c
//**************************************************************************              //06-08-18|0x022c
      case 53123: // READ_LIBRARY_NAME_EXIT                                               //06-08-18|0x022c
        switch(ReadProject)                                                               //06-08-18|0x022c
        {                                                                                 //06-08-18|0x022c
          case Display:                                                                   //06-08-18|0x022c
            MacroBuildState = 53123; // READ_LIBRARY_NAME_EXIT                            //06-08-18|0x022c
            MacroStatus = Display;                                                        //06-08-18|0x022c
            MacroRunFlag = 0;                                                             //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          case LineDone:                                                                  //06-08-18|0x022c
            MacroRunFlag = 1;                                                             //06-08-18|0x022c
            MacroBuildState = 32295; // LIBRARY                                           //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          case FileDone:                                                                  //06-08-18|0x022c
            MacroRunFlag = 1;                                                             //06-08-18|0x022c
            MacroBuildState = 34729; // END_FILE                                          //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          case UserError:                                                                 //06-08-18|0x022c
            MacroRunFlag = 1;                                                             //06-08-18|0x022c
            MacroBuildState = 696; // CLOSE_ERROR                                         //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
          default:                                                                        //06-08-18|0x022c
            MacroStatus = SystemError;                                                    //06-08-18|0x022c
            MacroRunFlag = 0;                                                             //06-08-18|0x022c
            SystemMsg;                                                                    //06-08-18|0x022c
            break;                                                                        //06-08-18|0x022c
        }                                                                                 //06-08-18|0x022c
        break;                                                                            //06-08-18|0x022c
//---------------------------------------------------------------------------             //06-08-18|0x022d
      case 32295: // LIBRARY                                                              //11-02-13|0x022e
        switch(CmdTest("_LIBRARY"))                                                       //11-02-13|0x022e
        {                                                                                 //11-02-13|0x022e
          case -1:                                                                        //11-02-13|0x022e
            MacroRunFlag = 1;                                                             //11-02-13|0x022e
            MacroBuildState = 17858; // SYSTEM                                            //11-02-13|0x022e
            break;                                                                        //11-02-13|0x022e
          case 0:                                                                         //11-02-13|0x022e
            MacroRunFlag = 1;                                                             //11-02-13|0x022e
            MacroBuildState = 51250; // LIBRARY_PREPARE                                   //11-02-13|0x022e
            break;                                                                        //11-02-13|0x022e
          case 1:                                                                         //11-02-13|0x022e
            MacroRunFlag = 1;                                                             //11-02-13|0x022e
            MacroBuildState = 17858; // SYSTEM                                            //11-02-13|0x022e
            break;                                                                        //11-02-13|0x022e
          default:                                                                        //11-02-13|0x022e
            MacroStatus = SystemError;                                                    //11-02-13|0x022e
            MacroRunFlag = 0;                                                             //11-02-13|0x022e
            SystemMsg;                                                                    //11-02-13|0x022e
            break;                                                                        //11-02-13|0x022e
        }                                                                                 //11-02-13|0x022e
        break;                                                                            //11-02-13|0x022e
//---------------------------------------------------------------------------             //06-08-18|0x022f
      case 51250: // LIBRARY_PREPARE                                                      //06-08-18|0x0230
        switch(text_prepare())                                                            //06-08-18|0x0230
        {                                                                                 //06-08-18|0x0230
          case Success:                                                                   //06-08-18|0x0230
            MacroRunFlag = 1;                                                             //06-08-18|0x0230
            MacroBuildState = 19409; // LIBRARY_NAME                                      //06-08-18|0x0230
            break;                                                                        //06-08-18|0x0230
          case UserError:                                                                 //06-08-18|0x0230
            MacroRunFlag = 1;                                                             //06-08-18|0x0230
            MacroBuildState = 17858; // SYSTEM                                            //06-08-18|0x0230
            break;                                                                        //06-08-18|0x0230
          default:                                                                        //06-08-18|0x0230
            MacroStatus = SystemError;                                                    //06-08-18|0x0230
            MacroRunFlag = 0;                                                             //06-08-18|0x0230
            SystemMsg;                                                                    //06-08-18|0x0230
            break;                                                                        //06-08-18|0x0230
        }                                                                                 //06-08-18|0x0230
        break;                                                                            //06-08-18|0x0230
//---------------------------------------------------------------------------             //06-08-18|0x0231
      case 19409: // LIBRARY_NAME                                                         //06-08-18|0x0232
        switch(EnterLibraryName)                                                          //06-08-18|0x0232
        {                                                                                 //06-08-18|0x0232
          case Success:                                                                   //06-08-18|0x0232
            MacroRunFlag = 1;                                                             //06-08-18|0x0232
            MacroBuildState = 2400; // CREATE_LIBRARY                                     //06-08-18|0x0232
            break;                                                                        //06-08-18|0x0232
          default:                                                                        //06-08-18|0x0232
            MacroStatus = SystemError;                                                    //06-08-18|0x0232
            MacroRunFlag = 0;                                                             //06-08-18|0x0232
            SystemMsg;                                                                    //06-08-18|0x0232
            break;                                                                        //06-08-18|0x0232
        }                                                                                 //06-08-18|0x0232
        break;                                                                            //06-08-18|0x0232
//---------------------------------------------------------------------------             //06-08-18|0x0233
      case 2400: // CREATE_LIBRARY                                                        //06-08-18|0x0234
        switch(create_library())                                                          //06-08-18|0x0234
        {                                                                                 //06-08-18|0x0234
          case Success:                                                                   //06-08-18|0x0234
            MacroRunFlag = 1;                                                             //06-08-18|0x0234
            MacroBuildState = 40927; // READ_FIRST_NAME                                   //06-08-18|0x0234
            break;                                                                        //06-08-18|0x0234
          case UserError:                                                                 //06-08-18|0x0234
            MacroRunFlag = 1;                                                             //06-08-18|0x0234
            MacroBuildState = 696; // CLOSE_ERROR                                         //06-08-18|0x0234
            break;                                                                        //06-08-18|0x0234
          default:                                                                        //06-08-18|0x0234
            MacroStatus = SystemError;                                                    //06-08-18|0x0234
            MacroRunFlag = 0;                                                             //06-08-18|0x0234
            SystemMsg;                                                                    //06-08-18|0x0234
            break;                                                                        //06-08-18|0x0234
        }                                                                                 //06-08-18|0x0234
        break;                                                                            //06-08-18|0x0234
//---------------------------------------------------------------------------             //06-08-18|0x0235
      case 40927: // READ_FIRST_NAME                                                      //06-08-18|0x0236
        switch(ReadProject)                                                               //06-08-18|0x0236
        {                                                                                 //06-08-18|0x0236
          case Display:                                                                   //06-08-18|0x0236
            MacroBuildState = 40526; // READ_FIRST_NAME_EXIT                              //06-08-18|0x0236
            MacroStatus = Display;                                                        //06-08-18|0x0236
            MacroRunFlag = 0;                                                             //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          case LineDone:                                                                  //06-08-18|0x0236
            MacroRunFlag = 1;                                                             //06-08-18|0x0236
            MacroBuildState = 33709; // MACRO                                             //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          case FileDone:                                                                  //06-08-18|0x0236
            MacroRunFlag = 1;                                                             //06-08-18|0x0236
            MacroBuildState = 48892; // FILE_END                                          //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          case UserError:                                                                 //06-08-18|0x0236
            MacroRunFlag = 1;                                                             //06-08-18|0x0236
            MacroBuildState = 696; // CLOSE_ERROR                                         //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          default:                                                                        //06-08-18|0x0236
            MacroStatus = SystemError;                                                    //06-08-18|0x0236
            MacroRunFlag = 0;                                                             //06-08-18|0x0236
            SystemMsg;                                                                    //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
        }                                                                                 //06-08-18|0x0236
        break;                                                                            //06-08-18|0x0236
//**************************************************************************              //06-08-18|0x0236
      case 40526: // READ_FIRST_NAME_EXIT                                                 //06-08-18|0x0236
        switch(ReadProject)                                                               //06-08-18|0x0236
        {                                                                                 //06-08-18|0x0236
          case Display:                                                                   //06-08-18|0x0236
            MacroBuildState = 40526; // READ_FIRST_NAME_EXIT                              //06-08-18|0x0236
            MacroStatus = Display;                                                        //06-08-18|0x0236
            MacroRunFlag = 0;                                                             //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          case LineDone:                                                                  //06-08-18|0x0236
            MacroRunFlag = 1;                                                             //06-08-18|0x0236
            MacroBuildState = 33709; // MACRO                                             //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          case FileDone:                                                                  //06-08-18|0x0236
            MacroRunFlag = 1;                                                             //06-08-18|0x0236
            MacroBuildState = 48892; // FILE_END                                          //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          case UserError:                                                                 //06-08-18|0x0236
            MacroRunFlag = 1;                                                             //06-08-18|0x0236
            MacroBuildState = 696; // CLOSE_ERROR                                         //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
          default:                                                                        //06-08-18|0x0236
            MacroStatus = SystemError;                                                    //06-08-18|0x0236
            MacroRunFlag = 0;                                                             //06-08-18|0x0236
            SystemMsg;                                                                    //06-08-18|0x0236
            break;                                                                        //06-08-18|0x0236
        }                                                                                 //06-08-18|0x0236
        break;                                                                            //06-08-18|0x0236
//---------------------------------------------------------------------------             //06-08-18|0x0237
      case 34729: // END_FILE                                                             //06-09-07|0x0238
        SystemMsg;                                                                        //06-09-07|0x0238
        MacroBuildState = 17858; // SYSTEM                                                //06-09-07|0x0238
        break;                                                                            //06-09-07|0x0238
//---------------------------------------------------------------------------             //06-08-18|0x0239
      case 48892: // FILE_END                                                             //06-08-18|0x023a
        switch(IllegalEndOfFile)                                                          //06-08-18|0x023a
        {                                                                                 //06-08-18|0x023a
          case UserError:                                                                 //06-08-18|0x023a
            MacroRunFlag = 1;                                                             //06-08-18|0x023a
            MacroBuildState = 44859; // DELETE_LIB                                        //06-08-18|0x023a
            break;                                                                        //06-08-18|0x023a
          default:                                                                        //06-08-18|0x023a
            MacroStatus = SystemError;                                                    //06-08-18|0x023a
            MacroRunFlag = 0;                                                             //06-08-18|0x023a
            SystemMsg;                                                                    //06-08-18|0x023a
            break;                                                                        //06-08-18|0x023a
        }                                                                                 //06-08-18|0x023a
        break;                                                                            //06-08-18|0x023a
//***************************************************************************             //06-08-18|0x023b
//******                                                               ******             //06-08-18|0x023c
//****** Process Macros                                                ******             //06-08-18|0x023d
//******                                                               ******             //06-08-18|0x023e
//***************************************************************************             //06-08-18|0x023f
      case 33709: // MACRO                                                                //11-02-13|0x0240
        switch(CmdTest("_MACRO"))                                                         //11-02-13|0x0240
        {                                                                                 //11-02-13|0x0240
          case -1:                                                                        //11-02-13|0x0240
            MacroRunFlag = 1;                                                             //11-02-13|0x0240
            MacroBuildState = 41834; // APPEND_FINISH                                     //11-02-13|0x0240
            break;                                                                        //11-02-13|0x0240
          case 0:                                                                         //11-02-13|0x0240
            MacroRunFlag = 1;                                                             //11-02-13|0x0240
            MacroBuildState = 55945; // MACRO_PREPARE                                     //11-02-13|0x0240
            break;                                                                        //11-02-13|0x0240
          case 1:                                                                         //11-02-13|0x0240
            MacroRunFlag = 1;                                                             //11-02-13|0x0240
            MacroBuildState = 41834; // APPEND_FINISH                                     //11-02-13|0x0240
            break;                                                                        //11-02-13|0x0240
          default:                                                                        //11-02-13|0x0240
            MacroStatus = SystemError;                                                    //11-02-13|0x0240
            MacroRunFlag = 0;                                                             //11-02-13|0x0240
            SystemMsg;                                                                    //11-02-13|0x0240
            break;                                                                        //11-02-13|0x0240
        }                                                                                 //11-02-13|0x0240
        break;                                                                            //11-02-13|0x0240
//---------------------------------------------------------------------------             //06-08-18|0x0241
      case 55945: // MACRO_PREPARE                                                        //06-08-20|0x0242
        switch(text_prepare())                                                            //06-08-20|0x0242
        {                                                                                 //06-08-20|0x0242
          case Success:                                                                   //06-08-20|0x0242
            MacroRunFlag = 1;                                                             //06-08-20|0x0242
            MacroBuildState = 33688; // MACRO_NAME                                        //06-08-20|0x0242
            break;                                                                        //06-08-20|0x0242
          case UserError:                                                                 //06-08-20|0x0242
            MacroRunFlag = 1;                                                             //06-08-20|0x0242
            MacroBuildState = 44859; // DELETE_LIB                                        //06-08-20|0x0242
            break;                                                                        //06-08-20|0x0242
          default:                                                                        //06-08-20|0x0242
            MacroStatus = SystemError;                                                    //06-08-20|0x0242
            MacroRunFlag = 0;                                                             //06-08-20|0x0242
            SystemMsg;                                                                    //06-08-20|0x0242
            break;                                                                        //06-08-20|0x0242
        }                                                                                 //06-08-20|0x0242
        break;                                                                            //06-08-20|0x0242
//---------------------------------------------------------------------------             //06-08-20|0x0243
      case 33688: // MACRO_NAME                                                           //06-08-20|0x0244
        switch(EnterMacroName)                                                            //06-08-20|0x0244
        {                                                                                 //06-08-20|0x0244
          case Success:                                                                   //06-08-20|0x0244
            MacroRunFlag = 1;                                                             //06-08-20|0x0244
            MacroBuildState = 48535; // MACRO_DATE                                        //06-08-20|0x0244
            break;                                                                        //06-08-20|0x0244
          default:                                                                        //06-08-20|0x0244
            MacroStatus = SystemError;                                                    //06-08-20|0x0244
            MacroRunFlag = 0;                                                             //06-08-20|0x0244
            SystemMsg;                                                                    //06-08-20|0x0244
            break;                                                                        //06-08-20|0x0244
        }                                                                                 //06-08-20|0x0244
        break;                                                                            //06-08-20|0x0244
//---------------------------------------------------------------------------             //06-08-20|0x0245
      case 48535: // MACRO_DATE                                                           //11-02-13|0x0246
        switch(MacroFileTime)                                                             //11-02-13|0x0246
        {                                                                                 //11-02-13|0x0246
          case Success:                                                                   //11-02-13|0x0246
            MacroRunFlag = 1;                                                             //11-02-13|0x0246
            MacroBuildState = 38790; // MACRO_CERT_BEGIN                                  //11-02-13|0x0246
            break;                                                                        //11-02-13|0x0246
          default:                                                                        //11-02-13|0x0246
            MacroStatus = SystemError;                                                    //11-02-13|0x0246
            MacroRunFlag = 0;                                                             //11-02-13|0x0246
            SystemMsg;                                                                    //11-02-13|0x0246
            break;                                                                        //11-02-13|0x0246
        }                                                                                 //11-02-13|0x0246
        break;                                                                            //11-02-13|0x0246
//---------------------------------------------------------------------------             //11-02-13|0x0247
      case 38790: // MACRO_CERT_BEGIN                                                     //11-02-13|0x0248
        switch(BeginParityMacro)                                                          //11-02-13|0x0248
        {                                                                                 //11-02-13|0x0248
          case Success:                                                                   //11-02-13|0x0248
            MacroRunFlag = 1;                                                             //11-02-13|0x0248
            MacroBuildState = 4197; // PROCESS_MACRO                                      //11-02-13|0x0248
            break;                                                                        //11-02-13|0x0248
          default:                                                                        //11-02-13|0x0248
            MacroStatus = SystemError;                                                    //11-02-13|0x0248
            MacroRunFlag = 0;                                                             //11-02-13|0x0248
            SystemMsg;                                                                    //11-02-13|0x0248
            break;                                                                        //11-02-13|0x0248
        }                                                                                 //11-02-13|0x0248
        break;                                                                            //11-02-13|0x0248
//---------------------------------------------------------------------------             //06-09-04|0x0249
      case 4197: // PROCESS_MACRO                                                         //11-02-17|0x024a
        switch(ProcessMacro)                                                              //11-02-17|0x024a
        {                                                                                 //11-02-17|0x024a
          case Display:                                                                   //11-02-17|0x024a
            MacroBuildState = 5940; // PROCESS_MACRO_EXIT                                 //11-02-17|0x024a
            MacroStatus = Display;                                                        //11-02-17|0x024a
            MacroRunFlag = 0;                                                             //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
          case Success:                                                                   //11-02-17|0x024a
            MacroRunFlag = 1;                                                             //11-02-17|0x024a
            MacroBuildState = 35571; // MACRO_CERT_TEST                                   //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
          case UserError:                                                                 //11-02-17|0x024a
            MacroRunFlag = 1;                                                             //11-02-17|0x024a
            MacroBuildState = 44859; // DELETE_LIB                                        //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
          default:                                                                        //11-02-17|0x024a
            MacroStatus = SystemError;                                                    //11-02-17|0x024a
            MacroRunFlag = 0;                                                             //11-02-17|0x024a
            SystemMsg;                                                                    //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
        }                                                                                 //11-02-17|0x024a
        break;                                                                            //11-02-17|0x024a
//**************************************************************************              //11-02-17|0x024a
      case 5940: // PROCESS_MACRO_EXIT                                                    //11-02-17|0x024a
        switch(ProcessMacro)                                                              //11-02-17|0x024a
        {                                                                                 //11-02-17|0x024a
          case Display:                                                                   //11-02-17|0x024a
            MacroBuildState = 5940; // PROCESS_MACRO_EXIT                                 //11-02-17|0x024a
            MacroStatus = Display;                                                        //11-02-17|0x024a
            MacroRunFlag = 0;                                                             //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
          case Success:                                                                   //11-02-17|0x024a
            MacroRunFlag = 1;                                                             //11-02-17|0x024a
            MacroBuildState = 35571; // MACRO_CERT_TEST                                   //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
          case UserError:                                                                 //11-02-17|0x024a
            MacroRunFlag = 1;                                                             //11-02-17|0x024a
            MacroBuildState = 44859; // DELETE_LIB                                        //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
          default:                                                                        //11-02-17|0x024a
            MacroStatus = SystemError;                                                    //11-02-17|0x024a
            MacroRunFlag = 0;                                                             //11-02-17|0x024a
            SystemMsg;                                                                    //11-02-17|0x024a
            break;                                                                        //11-02-17|0x024a
        }                                                                                 //11-02-17|0x024a
        break;                                                                            //11-02-17|0x024a
//---------------------------------------------------------------------------             //06-09-04|0x024b
      case 35571: // MACRO_CERT_TEST                                                      //11-02-17|0x024c
        switch(MacroDevelopStatus)                                                        //11-02-17|0x024c
        {                                                                                 //11-02-17|0x024c
          case DS_RELEASE:                                                                //11-02-17|0x024c
            MacroRunFlag = 1;                                                             //11-02-17|0x024c
            MacroBuildState = 15010; // MACRO_CERT_END                                    //11-02-17|0x024c
            break;                                                                        //11-02-17|0x024c
          case DS_BETA:                                                                   //11-02-17|0x024c
            MacroRunFlag = 1;                                                             //11-02-17|0x024c
            MacroBuildState = 15010; // MACRO_CERT_END                                    //11-02-17|0x024c
            break;                                                                        //11-02-17|0x024c
          case DS_ALPHA:                                                                  //11-02-17|0x024c
            MacroRunFlag = 1;                                                             //11-02-17|0x024c
            MacroBuildState = 15010; // MACRO_CERT_END                                    //11-02-17|0x024c
            break;                                                                        //11-02-17|0x024c
          case DS_EXPERIMENT:                                                             //11-02-17|0x024c
            MacroRunFlag = 1;                                                             //11-02-17|0x024c
            MacroBuildState = 58689; // READ_MACRO_NAME                                   //11-02-17|0x024c
            break;                                                                        //11-02-17|0x024c
          default:                                                                        //11-02-17|0x024c
            MacroStatus = SystemError;                                                    //11-02-17|0x024c
            MacroRunFlag = 0;                                                             //11-02-17|0x024c
            SystemMsg;                                                                    //11-02-17|0x024c
            break;                                                                        //11-02-17|0x024c
        }                                                                                 //11-02-17|0x024c
        break;                                                                            //11-02-17|0x024c
//---------------------------------------------------------------------------             //11-02-18|0x024d
      case 15010: // MACRO_CERT_END                                                       //<----   |0x024e
        switch(EndParityMacro)                                                            //<----   |0x024e
        {                                                                                 //<----   |0x024e
          case Success:                                                                   //<----   |0x024e
            MacroRunFlag = 1;                                                             //<----   |0x024e
            MacroBuildState = 58689; // READ_MACRO_NAME                                   //<----   |0x024e
            break;                                                                        //<----   |0x024e
          case UserError:                                                                 //<----   |0x024e
            MacroRunFlag = 1;                                                             //<----   |0x024e
            MacroBuildState = 44859; // DELETE_LIB                                        //<----   |0x024e
            break;                                                                        //<----   |0x024e
          default:                                                                        //<----   |0x024e
            MacroStatus = SystemError;                                                    //<----   |0x024e
            MacroRunFlag = 0;                                                             //<----   |0x024e
            SystemMsg;                                                                    //<----   |0x024e
            break;                                                                        //<----   |0x024e
        }                                                                                 //<----   |0x024e
        break;                                                                            //<----   |0x024e
//---------------------------------------------------------------------------             //06-09-04|0x024f
      case 58689: // READ_MACRO_NAME                                                      //11-02-18|0x0250
        switch(ReadProject)                                                               //11-02-18|0x0250
        {                                                                                 //11-02-18|0x0250
          case Display:                                                                   //11-02-18|0x0250
            MacroBuildState = 14800; // READ_MACRO_NAME_EXIT                              //11-02-18|0x0250
            MacroStatus = Display;                                                        //11-02-18|0x0250
            MacroRunFlag = 0;                                                             //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          case LineDone:                                                                  //11-02-18|0x0250
            MacroRunFlag = 1;                                                             //11-02-18|0x0250
            MacroBuildState = 33709; // MACRO                                             //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          case FileDone:                                                                  //11-02-18|0x0250
            MacroRunFlag = 1;                                                             //11-02-18|0x0250
            MacroBuildState = 55119; // LIB_FINISH                                        //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          case UserError:                                                                 //11-02-18|0x0250
            MacroRunFlag = 1;                                                             //11-02-18|0x0250
            MacroBuildState = 44859; // DELETE_LIB                                        //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          default:                                                                        //11-02-18|0x0250
            MacroStatus = SystemError;                                                    //11-02-18|0x0250
            MacroRunFlag = 0;                                                             //11-02-18|0x0250
            SystemMsg;                                                                    //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
        }                                                                                 //11-02-18|0x0250
        break;                                                                            //11-02-18|0x0250
//**************************************************************************              //11-02-18|0x0250
      case 14800: // READ_MACRO_NAME_EXIT                                                 //11-02-18|0x0250
        switch(ReadProject)                                                               //11-02-18|0x0250
        {                                                                                 //11-02-18|0x0250
          case Display:                                                                   //11-02-18|0x0250
            MacroBuildState = 14800; // READ_MACRO_NAME_EXIT                              //11-02-18|0x0250
            MacroStatus = Display;                                                        //11-02-18|0x0250
            MacroRunFlag = 0;                                                             //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          case LineDone:                                                                  //11-02-18|0x0250
            MacroRunFlag = 1;                                                             //11-02-18|0x0250
            MacroBuildState = 33709; // MACRO                                             //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          case FileDone:                                                                  //11-02-18|0x0250
            MacroRunFlag = 1;                                                             //11-02-18|0x0250
            MacroBuildState = 55119; // LIB_FINISH                                        //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          case UserError:                                                                 //11-02-18|0x0250
            MacroRunFlag = 1;                                                             //11-02-18|0x0250
            MacroBuildState = 44859; // DELETE_LIB                                        //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
          default:                                                                        //11-02-18|0x0250
            MacroStatus = SystemError;                                                    //11-02-18|0x0250
            MacroRunFlag = 0;                                                             //11-02-18|0x0250
            SystemMsg;                                                                    //11-02-18|0x0250
            break;                                                                        //11-02-18|0x0250
        }                                                                                 //11-02-18|0x0250
        break;                                                                            //11-02-18|0x0250
//***************************************************************************             //11-02-18|0x0251
      case 41834: // APPEND_FINISH                                                        //11-02-26|0x0252
        switch(FinishParityMacro)                                                         //11-02-26|0x0252
        {                                                                                 //11-02-26|0x0252
          case Success:                                                                   //11-02-26|0x0252
            MacroRunFlag = 1;                                                             //11-02-26|0x0252
            MacroBuildState = 19646; // APPEND_CLOSE                                      //11-02-26|0x0252
            break;                                                                        //11-02-26|0x0252
          case UserError:                                                                 //11-02-26|0x0252
            MacroRunFlag = 1;                                                             //11-02-26|0x0252
            MacroBuildState = 44859; // DELETE_LIB                                        //11-02-26|0x0252
            break;                                                                        //11-02-26|0x0252
          default:                                                                        //11-02-26|0x0252
            MacroStatus = SystemError;                                                    //11-02-26|0x0252
            MacroRunFlag = 0;                                                             //11-02-26|0x0252
            SystemMsg;                                                                    //11-02-26|0x0252
            break;                                                                        //11-02-26|0x0252
        }                                                                                 //11-02-26|0x0252
        break;                                                                            //11-02-26|0x0252
//---------------------------------------------------------------------------             //11-02-18|0x0253
      case 55119: // LIB_FINISH                                                           //11-02-18|0x0254
        switch(FinishParityMacro)                                                         //11-02-18|0x0254
        {                                                                                 //11-02-18|0x0254
          case Success:                                                                   //11-02-18|0x0254
            MacroRunFlag = 1;                                                             //11-02-18|0x0254
            MacroBuildState = 6429; // LIB_CLOSE                                          //11-02-18|0x0254
            break;                                                                        //11-02-18|0x0254
          case UserError:                                                                 //11-02-18|0x0254
            MacroRunFlag = 1;                                                             //11-02-18|0x0254
            MacroBuildState = 44859; // DELETE_LIB                                        //11-02-18|0x0254
            break;                                                                        //11-02-18|0x0254
          default:                                                                        //11-02-18|0x0254
            MacroStatus = SystemError;                                                    //11-02-18|0x0254
            MacroRunFlag = 0;                                                             //11-02-18|0x0254
            SystemMsg;                                                                    //11-02-18|0x0254
            break;                                                                        //11-02-18|0x0254
        }                                                                                 //11-02-18|0x0254
        break;                                                                            //11-02-18|0x0254
//***************************************************************************             //06-08-18|0x0255
      case 19646: // APPEND_CLOSE                                                         //06-08-18|0x0256
        switch(MacDictClose())                                                            //06-08-18|0x0256
        {                                                                                 //06-08-18|0x0256
          case Success:                                                                   //06-08-18|0x0256
            MacroRunFlag = 1;                                                             //06-08-18|0x0256
            MacroBuildState = 43884; // PREPARE_APPEND                                    //06-08-18|0x0256
            break;                                                                        //06-08-18|0x0256
          default:                                                                        //06-08-18|0x0256
            MacroStatus = SystemError;                                                    //06-08-18|0x0256
            MacroRunFlag = 0;                                                             //06-08-18|0x0256
            SystemMsg;                                                                    //06-08-18|0x0256
            break;                                                                        //06-08-18|0x0256
        }                                                                                 //06-08-18|0x0256
        break;                                                                            //06-08-18|0x0256
//---------------------------------------------------------------------------             //06-08-18|0x0257
      case 6429: // LIB_CLOSE                                                             //06-09-04|0x0258
        switch(MacDictClose())                                                            //06-09-04|0x0258
        {                                                                                 //06-09-04|0x0258
          case Success:                                                                   //06-09-04|0x0258
            MacroRunFlag = 1;                                                             //06-09-04|0x0258
            MacroBuildState = 25259; // COMPLETE_LIB                                      //06-09-04|0x0258
            break;                                                                        //06-09-04|0x0258
          default:                                                                        //06-09-04|0x0258
            MacroStatus = SystemError;                                                    //06-09-04|0x0258
            MacroRunFlag = 0;                                                             //06-09-04|0x0258
            SystemMsg;                                                                    //06-09-04|0x0258
            break;                                                                        //06-09-04|0x0258
        }                                                                                 //06-09-04|0x0258
        break;                                                                            //06-09-04|0x0258
//***************************************************************************             //06-08-18|0x0259
      case 43884: // PREPARE_APPEND                                                       //06-08-19|0x025a
        switch(MacDictComplete())                                                         //06-08-19|0x025a
        {                                                                                 //06-08-19|0x025a
          case Success:                                                                   //06-08-19|0x025a
            MacroRunFlag = 1;                                                             //06-08-19|0x025a
            MacroBuildState = 36314; // APPEND                                            //06-08-19|0x025a
            break;                                                                        //06-08-19|0x025a
          default:                                                                        //06-08-19|0x025a
            MacroStatus = SystemError;                                                    //06-08-19|0x025a
            MacroRunFlag = 0;                                                             //06-08-19|0x025a
            SystemMsg;                                                                    //06-08-19|0x025a
            break;                                                                        //06-08-19|0x025a
        }                                                                                 //06-08-19|0x025a
        break;                                                                            //06-08-19|0x025a
//---------------------------------------------------------------------------             //06-08-19|0x025b
      case 25259: // COMPLETE_LIB                                                         //06-09-04|0x025c
        switch(MacDictComplete())                                                         //06-09-04|0x025c
        {                                                                                 //06-09-04|0x025c
          case Success:                                                                   //06-09-04|0x025c
            MacroRunFlag = 1;                                                             //06-09-04|0x025c
            MacroBuildState = 27641; // CLOSE_OK                                          //06-09-04|0x025c
            break;                                                                        //06-09-04|0x025c
          default:                                                                        //06-09-04|0x025c
            MacroStatus = SystemError;                                                    //06-09-04|0x025c
            MacroRunFlag = 0;                                                             //06-09-04|0x025c
            SystemMsg;                                                                    //06-09-04|0x025c
            break;                                                                        //06-09-04|0x025c
        }                                                                                 //06-09-04|0x025c
        break;                                                                            //06-09-04|0x025c
//***************************************************************************             //06-08-19|0x025d
//******                                                               ******             //06-08-19|0x025e
//****** Append Libraries                                              ******             //06-08-19|0x025f
//******                                                               ******             //06-08-19|0x0260
//***************************************************************************             //06-08-19|0x0261
      case 36314: // APPEND                                                               //11-02-26|0x0262
        switch(CmdTest("_APPEND"))                                                        //11-02-26|0x0262
        {                                                                                 //11-02-26|0x0262
          case -1:                                                                        //11-02-26|0x0262
            MacroRunFlag = 1;                                                             //11-02-26|0x0262
            MacroBuildState = 17858; // SYSTEM                                            //11-02-26|0x0262
            break;                                                                        //11-02-26|0x0262
          case 0:                                                                         //11-02-26|0x0262
            MacroRunFlag = 1;                                                             //11-02-26|0x0262
            MacroBuildState = 11272; // APPEND_PREPARE                                    //11-02-26|0x0262
            break;                                                                        //11-02-26|0x0262
          case 1:                                                                         //11-02-26|0x0262
            MacroRunFlag = 1;                                                             //11-02-26|0x0262
            MacroBuildState = 17858; // SYSTEM                                            //11-02-26|0x0262
            break;                                                                        //11-02-26|0x0262
          default:                                                                        //11-02-26|0x0262
            MacroStatus = SystemError;                                                    //11-02-26|0x0262
            MacroRunFlag = 0;                                                             //11-02-26|0x0262
            SystemMsg;                                                                    //11-02-26|0x0262
            break;                                                                        //11-02-26|0x0262
        }                                                                                 //11-02-26|0x0262
        break;                                                                            //11-02-26|0x0262
//---------------------------------------------------------------------------             //11-02-26|0x0263
      case 11272: // APPEND_PREPARE                                                       //11-02-26|0x0264
        switch(text_prepare())                                                            //11-02-26|0x0264
        {                                                                                 //11-02-26|0x0264
          case Success:                                                                   //11-02-26|0x0264
            MacroRunFlag = 1;                                                             //11-02-26|0x0264
            MacroBuildState = 60679; // APPEND_NAME                                       //11-02-26|0x0264
            break;                                                                        //11-02-26|0x0264
          case UserError:                                                                 //11-02-26|0x0264
            MacroRunFlag = 1;                                                             //11-02-26|0x0264
            MacroBuildState = 48630; // APPEND_ERROR                                      //11-02-26|0x0264
            break;                                                                        //11-02-26|0x0264
          default:                                                                        //11-02-26|0x0264
            MacroStatus = SystemError;                                                    //11-02-26|0x0264
            MacroRunFlag = 0;                                                             //11-02-26|0x0264
            SystemMsg;                                                                    //11-02-26|0x0264
            break;                                                                        //11-02-26|0x0264
        }                                                                                 //11-02-26|0x0264
        break;                                                                            //11-02-26|0x0264
//---------------------------------------------------------------------------             //11-02-26|0x0265
      case 60679: // APPEND_NAME                                                          //11-02-26|0x0266
        switch(EnterAppendName)                                                           //11-02-26|0x0266
        {                                                                                 //11-02-26|0x0266
          case Success:                                                                   //11-02-26|0x0266
            MacroRunFlag = 1;                                                             //11-02-26|0x0266
            MacroBuildState = 40405; // APPEND_DATE                                       //11-02-26|0x0266
            break;                                                                        //11-02-26|0x0266
          default:                                                                        //11-02-26|0x0266
            MacroStatus = SystemError;                                                    //11-02-26|0x0266
            MacroRunFlag = 0;                                                             //11-02-26|0x0266
            SystemMsg;                                                                    //11-02-26|0x0266
            break;                                                                        //11-02-26|0x0266
        }                                                                                 //11-02-26|0x0266
        break;                                                                            //11-02-26|0x0266
//---------------------------------------------------------------------------             //11-02-26|0x0267
      case 40405: // APPEND_DATE                                                          //11-02-26|0x0268
        switch(AppendFileTime)                                                            //11-02-26|0x0268
        {                                                                                 //11-02-26|0x0268
          case Success:                                                                   //11-02-26|0x0268
            MacroRunFlag = 1;                                                             //11-02-26|0x0268
            MacroBuildState = 31652; // APPEND_LIBRARY                                    //11-02-26|0x0268
            break;                                                                        //11-02-26|0x0268
          default:                                                                        //11-02-26|0x0268
            MacroStatus = SystemError;                                                    //11-02-26|0x0268
            MacroRunFlag = 0;                                                             //11-02-26|0x0268
            SystemMsg;                                                                    //11-02-26|0x0268
            break;                                                                        //11-02-26|0x0268
        }                                                                                 //11-02-26|0x0268
        break;                                                                            //11-02-26|0x0268
//---------------------------------------------------------------------------             //06-09-07|0x0269
      case 31652: // APPEND_LIBRARY                                                       //06-09-07|0x026a
        switch(ProcessAppend)                                                             //06-09-07|0x026a
        {                                                                                 //06-09-07|0x026a
          case Success:                                                                   //06-09-07|0x026a
            MacroRunFlag = 1;                                                             //06-09-07|0x026a
            MacroBuildState = 13923; // READ_APPEND_NAME                                  //06-09-07|0x026a
            break;                                                                        //06-09-07|0x026a
          case UserError:                                                                 //06-09-07|0x026a
            MacroRunFlag = 1;                                                             //06-09-07|0x026a
            MacroBuildState = 44859; // DELETE_LIB                                        //06-09-07|0x026a
            break;                                                                        //06-09-07|0x026a
          default:                                                                        //06-09-07|0x026a
            MacroStatus = SystemError;                                                    //06-09-07|0x026a
            MacroRunFlag = 0;                                                             //06-09-07|0x026a
            SystemMsg;                                                                    //06-09-07|0x026a
            break;                                                                        //06-09-07|0x026a
        }                                                                                 //06-09-07|0x026a
        break;                                                                            //06-09-07|0x026a
//---------------------------------------------------------------------------             //06-09-07|0x026b
      case 13923: // READ_APPEND_NAME                                                     //11-02-18|0x026c
        switch(ReadProject)                                                               //11-02-18|0x026c
        {                                                                                 //11-02-18|0x026c
          case Display:                                                                   //11-02-18|0x026c
            MacroBuildState = 40210; // READ_APPEND_NAME_EXIT                             //11-02-18|0x026c
            MacroStatus = Display;                                                        //11-02-18|0x026c
            MacroRunFlag = 0;                                                             //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          case LineDone:                                                                  //11-02-18|0x026c
            MacroRunFlag = 1;                                                             //11-02-18|0x026c
            MacroBuildState = 36314; // APPEND                                            //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          case FileDone:                                                                  //11-02-18|0x026c
            MacroRunFlag = 1;                                                             //11-02-18|0x026c
            MacroBuildState = 27641; // CLOSE_OK                                          //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          case UserError:                                                                 //11-02-18|0x026c
            MacroRunFlag = 1;                                                             //11-02-18|0x026c
            MacroBuildState = 48630; // APPEND_ERROR                                      //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          default:                                                                        //11-02-18|0x026c
            MacroStatus = SystemError;                                                    //11-02-18|0x026c
            MacroRunFlag = 0;                                                             //11-02-18|0x026c
            SystemMsg;                                                                    //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
        }                                                                                 //11-02-18|0x026c
        break;                                                                            //11-02-18|0x026c
//**************************************************************************              //11-02-18|0x026c
      case 40210: // READ_APPEND_NAME_EXIT                                                //11-02-18|0x026c
        switch(ReadProject)                                                               //11-02-18|0x026c
        {                                                                                 //11-02-18|0x026c
          case Display:                                                                   //11-02-18|0x026c
            MacroBuildState = 40210; // READ_APPEND_NAME_EXIT                             //11-02-18|0x026c
            MacroStatus = Display;                                                        //11-02-18|0x026c
            MacroRunFlag = 0;                                                             //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          case LineDone:                                                                  //11-02-18|0x026c
            MacroRunFlag = 1;                                                             //11-02-18|0x026c
            MacroBuildState = 36314; // APPEND                                            //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          case FileDone:                                                                  //11-02-18|0x026c
            MacroRunFlag = 1;                                                             //11-02-18|0x026c
            MacroBuildState = 27641; // CLOSE_OK                                          //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          case UserError:                                                                 //11-02-18|0x026c
            MacroRunFlag = 1;                                                             //11-02-18|0x026c
            MacroBuildState = 48630; // APPEND_ERROR                                      //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
          default:                                                                        //11-02-18|0x026c
            MacroStatus = SystemError;                                                    //11-02-18|0x026c
            MacroRunFlag = 0;                                                             //11-02-18|0x026c
            SystemMsg;                                                                    //11-02-18|0x026c
            break;                                                                        //11-02-18|0x026c
        }                                                                                 //11-02-18|0x026c
        break;                                                                            //11-02-18|0x026c
//---------------------------------------------------------------------------             //06-09-07|0x026d
      case 48630: // APPEND_ERROR                                                         //11-02-26|0x026e
        SystemMsg;                                                                        //11-02-26|0x026e
        MacroBuildState = 17858; // SYSTEM                                                //11-02-26|0x026e
        break;                                                                            //11-02-26|0x026e
//***************************************************************************             //11-02-18|0x026f
//******                                                               ******             //11-02-18|0x0270
//****** Error Delete                                                  ******             //11-02-18|0x0271
//******                                                               ******             //11-02-18|0x0272
//***************************************************************************             //11-02-18|0x0273
      case 44859: // DELETE_LIB                                                           //11-02-18|0x0274
        switch(MacDictDelete())                                                           //11-02-18|0x0274
        {                                                                                 //11-02-18|0x0274
          case Success:                                                                   //11-02-18|0x0274
            MacroRunFlag = 1;                                                             //11-02-18|0x0274
            MacroBuildState = 696; // CLOSE_ERROR                                         //11-02-18|0x0274
            break;                                                                        //11-02-18|0x0274
          default:                                                                        //11-02-18|0x0274
            MacroStatus = SystemError;                                                    //11-02-18|0x0274
            MacroRunFlag = 0;                                                             //11-02-18|0x0274
            SystemMsg;                                                                    //11-02-18|0x0274
            break;                                                                        //11-02-18|0x0274
        }                                                                                 //11-02-18|0x0274
        break;                                                                            //11-02-18|0x0274
//***************************************************************************             //11-02-18|0x0275
//******                                                               ******             //11-02-18|0x0276
//****** Close States                                                  ******             //11-02-18|0x0277
//******                                                               ******             //11-02-18|0x0278
//***************************************************************************             //11-02-18|0x0279
      case 27641: // CLOSE_OK                                                             //11-02-18|0x027a
        switch(CloseProject)                                                              //11-02-18|0x027a
        {                                                                                 //11-02-18|0x027a
          case Success:                                                                   //11-02-18|0x027a
            MacroRunFlag = 1;                                                             //11-02-18|0x027a
            MacroBuildState = 28337; // REPORT_OK                                         //11-02-18|0x027a
            break;                                                                        //11-02-18|0x027a
          default:                                                                        //11-02-18|0x027a
            MacroStatus = SystemError;                                                    //11-02-18|0x027a
            MacroRunFlag = 0;                                                             //11-02-18|0x027a
            SystemMsg;                                                                    //11-02-18|0x027a
            break;                                                                        //11-02-18|0x027a
        }                                                                                 //11-02-18|0x027a
        break;                                                                            //11-02-18|0x027a
//---------------------------------------------------------------------------             //11-02-18|0x027b
      case 696: // CLOSE_ERROR                                                            //11-02-18|0x027c
        switch(CloseProject)                                                              //11-02-18|0x027c
        {                                                                                 //11-02-18|0x027c
          case Success:                                                                   //11-02-18|0x027c
            MacroRunFlag = 1;                                                             //11-02-18|0x027c
            MacroBuildState = 23104; // REPORT_ERROR                                      //11-02-18|0x027c
            break;                                                                        //11-02-18|0x027c
          default:                                                                        //11-02-18|0x027c
            MacroStatus = SystemError;                                                    //11-02-18|0x027c
            MacroRunFlag = 0;                                                             //11-02-18|0x027c
            SystemMsg;                                                                    //11-02-18|0x027c
            break;                                                                        //11-02-18|0x027c
        }                                                                                 //11-02-18|0x027c
        break;                                                                            //11-02-18|0x027c
//***************************************************************************             //11-02-18|0x027d
//******                                                               ******             //11-02-18|0x027e
//****** Close Report States                                           ******             //11-02-18|0x027f
//******                                                               ******             //11-02-18|0x0280
//***************************************************************************             //11-02-18|0x0281
      case 28337: // REPORT_OK                                                            //11-02-18|0x0282
        switch(MacroDevelopStatus)                                                        //11-02-18|0x0282
        {                                                                                 //11-02-18|0x0282
          case DS_RELEASE:                                                                //11-02-18|0x0282
            MacroRunFlag = 1;                                                             //11-02-18|0x0282
            MacroBuildState = 65215; // REPORT_CLOSE                                      //11-02-18|0x0282
            break;                                                                        //11-02-18|0x0282
          case DS_BETA:                                                                   //11-02-18|0x0282
            MacroRunFlag = 1;                                                             //11-02-18|0x0282
            MacroBuildState = 65215; // REPORT_CLOSE                                      //11-02-18|0x0282
            break;                                                                        //11-02-18|0x0282
          case DS_ALPHA:                                                                  //11-02-18|0x0282
            MacroRunFlag = 1;                                                             //11-02-18|0x0282
            MacroBuildState = 65215; // REPORT_CLOSE                                      //11-02-18|0x0282
            break;                                                                        //11-02-18|0x0282
          case DS_EXPERIMENT:                                                             //11-02-18|0x0282
            MacroRunFlag = 1;                                                             //11-02-18|0x0282
            MacroBuildState = 60206; // OK                                                //11-02-18|0x0282
            break;                                                                        //11-02-18|0x0282
          default:                                                                        //11-02-18|0x0282
            MacroStatus = SystemError;                                                    //11-02-18|0x0282
            MacroRunFlag = 0;                                                             //11-02-18|0x0282
            SystemMsg;                                                                    //11-02-18|0x0282
            break;                                                                        //11-02-18|0x0282
        }                                                                                 //11-02-18|0x0282
        break;                                                                            //11-02-18|0x0282
//---------------------------------------------------------------------------             //11-02-18|0x0283
      case 65215: // REPORT_CLOSE                                                         //11-02-18|0x0284
        switch(ReportClose())                                                             //11-02-18|0x0284
        {                                                                                 //11-02-18|0x0284
          case Success:                                                                   //11-02-18|0x0284
            MacroRunFlag = 1;                                                             //11-02-18|0x0284
            MacroBuildState = 60206; // OK                                                //11-02-18|0x0284
            break;                                                                        //11-02-18|0x0284
          default:                                                                        //11-02-18|0x0284
            MacroStatus = SystemError;                                                    //11-02-18|0x0284
            MacroRunFlag = 0;                                                             //11-02-18|0x0284
            SystemMsg;                                                                    //11-02-18|0x0284
            break;                                                                        //11-02-18|0x0284
        }                                                                                 //11-02-18|0x0284
        break;                                                                            //11-02-18|0x0284
//***************************************************************************             //11-02-18|0x0285
      case 23104: // REPORT_ERROR                                                         //11-02-18|0x0286
        switch(MacroDevelopStatus)                                                        //11-02-18|0x0286
        {                                                                                 //11-02-18|0x0286
          case DS_RELEASE:                                                                //11-02-18|0x0286
            MacroRunFlag = 1;                                                             //11-02-18|0x0286
            MacroBuildState = 40589; // REPORT_DELETE                                     //11-02-18|0x0286
            break;                                                                        //11-02-18|0x0286
          case DS_BETA:                                                                   //11-02-18|0x0286
            MacroRunFlag = 1;                                                             //11-02-18|0x0286
            MacroBuildState = 40589; // REPORT_DELETE                                     //11-02-18|0x0286
            break;                                                                        //11-02-18|0x0286
          case DS_ALPHA:                                                                  //11-02-18|0x0286
            MacroRunFlag = 1;                                                             //11-02-18|0x0286
            MacroBuildState = 40589; // REPORT_DELETE                                     //11-02-18|0x0286
            break;                                                                        //11-02-18|0x0286
          case DS_EXPERIMENT:                                                             //11-02-18|0x0286
            MacroRunFlag = 1;                                                             //11-02-18|0x0286
            MacroBuildState = 34780; // ERROR                                             //11-02-18|0x0286
            break;                                                                        //11-02-18|0x0286
          default:                                                                        //11-02-18|0x0286
            MacroStatus = SystemError;                                                    //11-02-18|0x0286
            MacroRunFlag = 0;                                                             //11-02-18|0x0286
            SystemMsg;                                                                    //11-02-18|0x0286
            break;                                                                        //11-02-18|0x0286
        }                                                                                 //11-02-18|0x0286
        break;                                                                            //11-02-18|0x0286
//---------------------------------------------------------------------------             //11-02-18|0x0287
      case 40589: // REPORT_DELETE                                                        //11-02-18|0x0288
        switch(ReportDelete())                                                            //11-02-18|0x0288
        {                                                                                 //11-02-18|0x0288
          case Success:                                                                   //11-02-18|0x0288
            MacroRunFlag = 1;                                                             //11-02-18|0x0288
            MacroBuildState = 34780; // ERROR                                             //11-02-18|0x0288
            break;                                                                        //11-02-18|0x0288
          default:                                                                        //11-02-18|0x0288
            MacroStatus = SystemError;                                                    //11-02-18|0x0288
            MacroRunFlag = 0;                                                             //11-02-18|0x0288
            SystemMsg;                                                                    //11-02-18|0x0288
            break;                                                                        //11-02-18|0x0288
        }                                                                                 //11-02-18|0x0288
        break;                                                                            //11-02-18|0x0288
//***************************************************************************             //06-08-18|0x0289
//******                                                               ******             //06-08-18|0x028a
//****** Exit States                                                   ******             //06-08-18|0x028b
//******                                                               ******             //06-08-18|0x028c
//***************************************************************************             //06-08-18|0x028d
      case 60206: // OK                                                                   //06-09-04|0x028e
        MacroBuildState = 4462; // ENTER_PROJECT_NAME                                     //06-09-04|0x028e
        MacroStatus = Success;                                                            //06-09-04|0x028e
        MacroRunFlag = 0;                                                                 //06-09-04|0x028e
        break;                                                                            //06-09-04|0x028e
//---------------------------------------------------------------------------             //06-08-18|0x028f
      case 34780: // ERROR                                                                //06-08-18|0x0290
        MacroBuildState = 4462; // ENTER_PROJECT_NAME                                     //06-08-18|0x0290
        MacroStatus = UserError;                                                          //06-08-18|0x0290
        MacroRunFlag = 0;                                                                 //06-08-18|0x0290
        break;                                                                            //06-08-18|0x0290
//---------------------------------------------------------------------------             //06-09-04|0x0291
      case 17858: // SYSTEM                                                               //06-09-04|0x0292
        MacroBuildState = 4462; // ENTER_PROJECT_NAME                                     //06-09-04|0x0292
        MacroStatus = SystemError;                                                        //06-09-04|0x0292
        MacroRunFlag = 0;                                                                 //06-09-04|0x0292
        break;                                                                            //06-09-04|0x0292
//***************************************************************************             //06-08-18|0x0293
      default:                                                                            //06-08-18|0x0294
        MacroStatus = SystemError;                                                        //06-08-18|0x0294
        MacroRunFlag = 0;                                                                 //06-08-18|0x0294
        SystemMsg;                                                                        //06-08-18|0x0294
        break;                                                                            //06-08-18|0x0294
    }                                                                                     //06-08-18|0x0294
  }                                                                                       //06-08-18|0x0294
//***************************************************************************             //06-08-18|0x0295
//***************************************************************************             //06-08-18|0x0296
    return(MacroStatus);                                                                  //06-09-04|0x0297
}                                                                                         //06-08-18|0x029a
//                                                                                        //05-24-97|0x029a
//***************************************************************************             //06-08-16|0x029d
//***************************************************************************             //06-08-16|0x029e
//******                                                               ******             //06-08-16|0x029f
//******                     enter_name                                ******             //06-08-16|0x02a0
//******                                                               ******             //06-08-16|0x02a1
//***************************************************************************             //06-08-16|0x02a2
//***************************************************************************             //06-08-16|0x02a3
//*******************************************************************************         //10-29-97|0x02a8
//*******************************************************************************         //10-29-97|0x02a8
// enter_name                                                                             //06-08-16|0x02a8
//*******************************************************************************         //10-29-97|0x02a8
//*******************************************************************************         //10-29-97|0x02a8
UINT MACROPROJ::enter_name(                                                               //06-08-16|0x02a8
    TEXT_FILE_DATA_FAR TextFileAddr,                                                      //06-08-16|0x02a8
    TOKENS_FAR InputAddr,                                                                 //06-08-16|0x02a8
    SCHAR_FAR Extent                                                                      //06-08-16|0x02a8
    ) {                                                                                   //06-08-16|0x02a8
//*******************************************************************************         //10-29-97|0x02a8
//***************************************************************************             //06-08-16|0x02ab
//***************************************************************************             //06-08-16|0x02ac
    switch(InitialFile)                                          _SwitchGroup             //06-08-16|0x02ad
    switch(EnterFileName)                                        _SwitchGroup             //06-08-16|0x02ae
    switch(FileRelease())                                        _SwitchGroup             //06-08-16|0x02af
//***************************************************************************             //06-08-16|0x02b0
    return_test(enter_name_1);                                                            //06-08-16|0x02b1
}                                                                                         //06-08-16|0x02b2
//                                                                                        //05-24-97|0x02b2
//***************************************************************************             //06-08-16|0x02b5
//***************************************************************************             //06-08-16|0x02b6
//******                                                               ******             //06-08-16|0x02b7
//******                            file_time                          ******             //06-08-16|0x02b8
//******                                                               ******             //06-08-16|0x02b9
//***************************************************************************             //06-08-16|0x02ba
//***************************************************************************             //06-08-16|0x02bb
//*******************************************************************************         //10-29-97|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
// file_time                                                                              //06-08-16|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
UINT MACROPROJ::file_time(                                                                //06-08-16|0x02c0
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-08-16|0x02c0
    ) {                                                                                   //06-08-16|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
//***************************************************************************             //06-08-16|0x02c3
//***************************************************************************             //06-08-16|0x02c4
    switch(CommitFile)                                           _SwitchGroup             //06-08-16|0x02c5
    switch(FileExists(MacroInTimeAddr))                          _SwitchGroup             //06-08-16|0x02c6
    switch(FileRelease())                                        _SwitchGroup             //06-08-16|0x02c7
    return_test(file_time_1);                                                             //06-08-16|0x02c8
}                                                                                         //06-08-16|0x02c9
//                                                                                        //05-24-97|0x02c9
//***************************************************************************             //06-08-17|0x02cc
//***************************************************************************             //06-08-17|0x02cd
//******                                                               ******             //06-08-17|0x02ce
//******                          open_project                         ******             //06-08-17|0x02cf
//******                                                               ******             //06-08-17|0x02d0
//***************************************************************************             //06-08-17|0x02d1
//***************************************************************************             //06-08-17|0x02d2
//*******************************************************************************         //10-29-97|0x02d7
//*******************************************************************************         //10-29-97|0x02d7
// open_project                                                                           //06-08-17|0x02d7
//*******************************************************************************         //10-29-97|0x02d7
//*******************************************************************************         //10-29-97|0x02d7
UINT MACROPROJ::open_project(                                                             //06-08-17|0x02d7
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-08-17|0x02d7
    ) {                                                                                   //06-08-17|0x02d7
//*******************************************************************************         //10-29-97|0x02d7
//***************************************************************************             //06-08-17|0x02da
//***************************************************************************             //06-08-17|0x02db
    switch(CommitFile)                                           _SwitchGroup             //06-08-17|0x02dc
    switch(FileOpenText())                                       _SwitchGroup             //06-08-17|0x02dd
    switch(FileRelease())                                        _SwitchGroup             //06-08-17|0x02de
//***************************************************************************             //06-08-17|0x02df
    return_test(open_project_1);                                                          //06-08-17|0x02e0
}                                                                                         //06-08-17|0x02e1
//                                                                                        //05-24-97|0x02e1
//***************************************************************************             //06-08-17|0x02e4
//***************************************************************************             //06-08-17|0x02e5
//******                                                               ******             //06-08-17|0x02e6
//******                          read_project                         ******             //06-08-17|0x02e7
//******                                                               ******             //06-08-17|0x02e8
//***************************************************************************             //06-08-17|0x02e9
//***************************************************************************             //06-08-17|0x02ea
//*******************************************************************************         //10-29-97|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
// read_project                                                                           //06-08-17|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
UINT MACROPROJ::read_project(                                                             //06-08-17|0x02f2
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-08-17|0x02f2
    ) {                                                                                   //06-08-17|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
//***************************************************************************             //06-08-17|0x02f5
//***************************************************************************             //06-08-17|0x02f6
  UINT status;                                                                       //06-08-17|0x02f7
//***************************************************************************             //06-08-17|0x02f8
//***************************************************************************             //06-08-17|0x02f9
    switch(CommitFile)                                           _SwitchGroup             //06-08-17|0x02fa
//***************************************************************************             //06-08-17|0x02fb
    status = FileReadText(MacroTokensAddr);                                               //06-08-17|0x02fc
//---------------------------------------------------------------------------             //06-08-17|0x02fd
    switch(status)                                                                        //06-08-17|0x02fe
      {                                                                                   //06-08-17|0x02ff
        case FileDone:                            break_test(read_project_1);             //06-08-17|0x0300
        case LineDone:                            break_test(read_project_2);             //06-08-17|0x0301
        case UserError:                           break_test(read_project_3);             //06-08-17|0x0302
        case Display:                             break_test(read_project_4);             //06-08-17|0x0303
        default:                                            ReturnSystemError             //06-08-17|0x0304
        }                                                                                 //06-08-17|0x0305
//***************************************************************************             //06-08-17|0x0306
    switch(FileRelease())                                        _SwitchGroup             //06-08-17|0x0307
//***************************************************************************             //06-08-17|0x0308
    return(status);                                                                       //06-08-17|0x0309
}                                                                                         //06-08-17|0x030a
//                                                                                        //05-24-97|0x030a
//***************************************************************************             //09-03-27|0x030d
//***************************************************************************             //09-03-27|0x030e
//******                                                               ******             //09-03-27|0x030f
//******                          update_task_no                       ******             //09-03-27|0x0310
//******                                                               ******             //09-03-27|0x0311
//***************************************************************************             //09-03-27|0x0312
//***************************************************************************             //09-03-27|0x0313
//*******************************************************************************         //10-29-97|0x0317
//*******************************************************************************         //10-29-97|0x0317
// update_task_no                                                                         //09-03-27|0x0317
//*******************************************************************************         //10-29-97|0x0317
//*******************************************************************************         //10-29-97|0x0317
UINT MACROPROJ::update_task_no(                                                           //09-03-27|0x0317
    UINT_FAR TaskNoFar                                                                    //09-03-27|0x0317
    ) {                                                                                   //09-03-27|0x0317
//*******************************************************************************         //10-29-97|0x0317
//***************************************************************************             //09-03-27|0x031a
//***************************************************************************             //09-03-27|0x031b
  WORDS task_no;                                                                     //09-03-27|0x031c
//***************************************************************************             //09-03-27|0x031d
//***************************************************************************             //09-03-27|0x031e
    IfNoTokens(2, 2)          ReturnFinish("Illegal No Parameters");                      //09-03-27|0x031f
//***************************************************************************             //09-03-27|0x0320
    if(StrToInt(TokensLineAddr(1),  task_no.ulong) == 0)                                  //09-03-27|0x0321
                              ReturnFinish("Illegal Sequence Parameter");                 //09-03-27|0x0322
//***************************************************************************             //09-03-27|0x0323
    if(*TaskNoFar > task_no.word0)                                                        //09-03-27|0x0324
                              ReturnFinish("Illegal Sequence");                           //09-03-27|0x0325
    *TaskNoFar = task_no.word0;                                                           //09-03-27|0x0326
    return_test(update_task_no_1);                                                        //09-03-27|0x0327
}                                                                                         //09-03-27|0x0328
//                                                                                        //05-24-97|0x0328
//***************************************************************************             //11-06-13|0x032b
//***************************************************************************             //11-06-13|0x032c
//******                                                               ******             //11-06-13|0x032d
//******                          enable_display                       ******             //11-06-13|0x032e
//******                                                               ******             //11-06-13|0x032f
//***************************************************************************             //11-06-13|0x0330
//***************************************************************************             //11-06-13|0x0331
//*******************************************************************************         //10-29-97|0x0335
//*******************************************************************************         //10-29-97|0x0335
// enable_display                                                                         //11-06-13|0x0335
//*******************************************************************************         //10-29-97|0x0335
//*******************************************************************************         //10-29-97|0x0335
UINT MACROPROJ::enable_display(void) {                                                    //11-06-13|0x0335
//*******************************************************************************         //10-29-97|0x0335
//***************************************************************************             //11-06-13|0x0338
//***************************************************************************             //11-06-13|0x0339
    if(TokensNoTokens != 1)            ReturnFinish("Illegal No Parameters");             //11-06-13|0x033a
//***************************************************************************             //11-06-13|0x033b
    DisplayOn();                                                                          //11-06-13|0x033c
//***************************************************************************             //11-06-13|0x033d
    return_test(enable_display_1);                                                        //11-06-13|0x033e
}                                                                                         //11-06-13|0x033f
//                                                                                        //05-24-97|0x033f
//***************************************************************************             //07-10-30|0x0342
//***************************************************************************             //07-10-30|0x0343
//******                                                               ******             //07-10-30|0x0344
//******                          uncond_update                        ******             //07-10-30|0x0345
//******                                                               ******             //07-10-30|0x0346
//***************************************************************************             //07-10-30|0x0347
//***************************************************************************             //07-10-30|0x0348
//*******************************************************************************         //10-29-97|0x034c
//*******************************************************************************         //10-29-97|0x034c
// uncond_update                                                                          //07-10-30|0x034c
//*******************************************************************************         //10-29-97|0x034c
//*******************************************************************************         //10-29-97|0x034c
UINT MACROPROJ::uncond_update(void) {                                                     //07-10-30|0x034c
//*******************************************************************************         //10-29-97|0x034c
//***************************************************************************             //07-10-30|0x034f
//***************************************************************************             //07-10-30|0x0350
    if(TokensNoTokens != 1)            ReturnFinish("Illegal No Parameters");             //07-10-30|0x0351
//***************************************************************************             //07-10-30|0x0352
    MacroInTime       = 0xffffffff;                                                       //11-02-14|0x0353
    MacroDevelopState = 0x0100;                                                           //11-02-14|0x0354
//***************************************************************************             //07-10-30|0x0355
    return_test(uncond_update_1);                                                         //07-10-30|0x0356
}                                                                                         //07-10-30|0x0357
//                                                                                        //05-24-97|0x0357
//***************************************************************************             //11-02-12|0x035a
//***************************************************************************             //11-02-12|0x035b
//******                                                               ******             //11-02-12|0x035c
//******                          set_version                          ******             //11-02-12|0x035d
//******                                                               ******             //11-02-12|0x035e
//***************************************************************************             //11-02-12|0x035f
//***************************************************************************             //11-02-12|0x0360
//*******************************************************************************         //10-29-97|0x0364
//*******************************************************************************         //10-29-97|0x0364
// set_version                                                                            //11-02-12|0x0364
//*******************************************************************************         //10-29-97|0x0364
//*******************************************************************************         //10-29-97|0x0364
UINT MACROPROJ::set_version(                                                              //11-02-12|0x0364
    UINT VersionState                                                                     //11-02-12|0x0364
    ) {                                                                                   //11-02-12|0x0364
//*******************************************************************************         //10-29-97|0x0364
//***************************************************************************             //11-02-12|0x0367
//***************************************************************************             //11-02-12|0x0368
    MacroDevelopStatus = VersionState;                                                    //11-02-12|0x0369
//***************************************************************************             //11-02-12|0x036a
    return_test(set_version_1);                                                           //11-02-12|0x036b
}                                                                                         //11-02-12|0x036c
//                                                                                        //05-24-97|0x036c
//***************************************************************************             //06-08-17|0x036f
//***************************************************************************             //06-08-17|0x0370
//******                                                               ******             //06-08-17|0x0371
//******                          text_prepare                         ******             //06-08-17|0x0372
//******                                                               ******             //06-08-17|0x0373
//***************************************************************************             //06-08-17|0x0374
//***************************************************************************             //06-08-17|0x0375
//*******************************************************************************         //10-29-97|0x0379
//*******************************************************************************         //10-29-97|0x0379
// text_prepare                                                                           //06-08-17|0x0379
//*******************************************************************************         //10-29-97|0x0379
//*******************************************************************************         //10-29-97|0x0379
UINT MACROPROJ::text_prepare(void) {                                                      //06-08-17|0x0379
//*******************************************************************************         //10-29-97|0x0379
//***************************************************************************             //06-08-17|0x037c
//***************************************************************************             //06-08-17|0x037d
    IfNoTokens(2, 3)                   ReturnFinish("Illegal No Parameters");             //06-08-17|0x037e
//***************************************************************************             //06-08-17|0x037f
    switch(FileTextPrepare)                                      _SwitchGroup             //06-08-17|0x0380
    return_test(text_prepare_1);                                                          //06-08-17|0x0381
}                                                                                         //06-08-17|0x0382
//                                                                                        //05-24-97|0x0382
//***************************************************************************             //11-02-14|0x0385
//***************************************************************************             //11-02-14|0x0386
//******                                                               ******             //11-02-14|0x0387
//******                          create_report                        ******             //11-02-14|0x0388
//******                                                               ******             //11-02-14|0x0389
//***************************************************************************             //11-02-14|0x038a
//***************************************************************************             //11-02-14|0x038b
//*******************************************************************************         //10-29-97|0x038f
//*******************************************************************************         //10-29-97|0x038f
// create_report                                                                          //11-02-14 |0x038f
//*******************************************************************************         //10-29-97|0x038f
//*******************************************************************************         //10-29-97|0x038f
UINT MACROPROJ::create_report(void) {                                                     //11-02-14 |0x038f
//*******************************************************************************         //10-29-97|0x038f
//***************************************************************************             //11-02-14 |0x0392
//***************************************************************************             //11-02-14 |0x0393
    IfNoTokens(2, 2)                   ReturnFinish("Illegal No Parameters");             //11-02-14 |0x0394
//***************************************************************************             //11-02-14 |0x0395
    switch(ReportOpen(TokensLineAddr(0), "library"))             _SwitchGroup             //11-02-14 |0x0396
    return_test(create_report_1);                                                         //11-02-14 |0x0397
}                                                                                         //11-02-14 |0x0398
//                                                                                        //05-24-97|0x0398
//***************************************************************************             //06-08-18|0x039b
//***************************************************************************             //06-08-18|0x039c
//******                                                               ******             //06-08-18|0x039d
//******                          create_library                       ******             //06-08-18|0x039e
//******                                                               ******             //06-08-18|0x039f
//***************************************************************************             //06-08-18|0x03a0
//***************************************************************************             //06-08-18|0x03a1
//*******************************************************************************         //10-29-97|0x03a5
//*******************************************************************************         //10-29-97|0x03a5
// create_library                                                                         //06-08-18|0x03a5
//*******************************************************************************         //10-29-97|0x03a5
//*******************************************************************************         //10-29-97|0x03a5
UINT MACROPROJ::create_library(void) {                                                    //06-08-18|0x03a5
//*******************************************************************************         //10-29-97|0x03a5
//***************************************************************************             //06-08-18|0x03a8
//***************************************************************************             //06-08-18|0x03a9
    IfNoTokens(3, 3)                   ReturnFinish("Illegal No Parameters");             //06-08-18|0x03aa
    if(TokensLength(2) >= 100)         ReturnFinish("Class Name Too Large");              //06-08-18|0x03ab
//***************************************************************************             //06-08-18|0x03ac
    switch(MacDictCreate(TokensTokenAddr(2)))                    _SwitchGroup             //07-04-27|0x03ad
    return_test(create_library_1);                                                        //06-08-18|0x03ae
}                                                                                         //06-08-18|0x03af
//                                                                                        //05-24-97|0x03af
//***************************************************************************             //06-08-17|0x03b2
//***************************************************************************             //06-08-17|0x03b3
//******                                                               ******             //06-08-17|0x03b4
//******                         close_project                         ******             //06-08-17|0x03b5
//******                                                               ******             //06-08-17|0x03b6
//***************************************************************************             //06-08-17|0x03b7
//***************************************************************************             //06-08-17|0x03b8
//*******************************************************************************         //10-29-97|0x03bd
//*******************************************************************************         //10-29-97|0x03bd
// close_project                                                                          //06-08-17|0x03bd
//*******************************************************************************         //10-29-97|0x03bd
//*******************************************************************************         //10-29-97|0x03bd
UINT MACROPROJ::close_project(                                                            //06-08-17|0x03bd
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-08-17|0x03bd
    ) {                                                                                   //06-08-17|0x03bd
//*******************************************************************************         //10-29-97|0x03bd
//***************************************************************************             //06-08-17|0x03c0
//***************************************************************************             //06-08-17|0x03c1
    switch(CommitFile)                                           _SwitchGroup             //06-08-17|0x03c2
    switch(FileClose())                                          _SwitchGroup             //06-08-17|0x03c3
    switch(FileRelease())                                        _SwitchGroup             //06-08-17|0x03c4
//***************************************************************************             //06-08-17|0x03c5
    return_test(close_project_1);                                                         //06-08-17|0x03c6
}                                                                                         //06-08-17|0x03c7
//                                                                                        //05-24-97|0x03c7
//***************************************************************************             //06-07-14|0x03ca
//***************************************************************************             //06-07-14|0x03cb
//******                                                               ******             //06-07-14|0x03cc
//******                       TEST WRAPPERS                           ******             //06-07-14|0x03cd
//******                                                               ******             //06-07-14|0x03ce
//***************************************************************************             //06-07-14|0x03cf
//***************************************************************************             //06-07-14|0x03d0
//*******************************************************************************         //10-29-97|0x03d1
//*******************************************************************************         //10-29-97|0x03d1
// macproj_test_reset                                                                     //06-07-14|0x03d1
//*******************************************************************************         //10-29-97|0x03d1
//*******************************************************************************         //10-29-97|0x03d1
UINT MACROPROJ::macproj_test_reset(void) {                                                //06-07-14|0x03d1
//*******************************************************************************         //10-29-97|0x03d1
//************************************************************************                //06-07-14|0x03d1
    switch(BasicTestReset())                                                              //06-07-14|0x03d1
      {                                                                                   //06-07-14|0x03d1
        case Success:                                     return(Success);                //06-07-14|0x03d1
        default:                                        ReturnSystemError;                //06-07-14|0x03d1
        }                                                                                 //06-07-14|0x03d1
}                                                                                         //06-07-14|0x03d1
//                                                                                        //05-24-97|0x03d1
//***************************************************************************             //06-07-14|0x03d2
//*******************************************************************************         //10-29-97|0x03d3
//*******************************************************************************         //10-29-97|0x03d3
// macproj_test_read                                                                      //06-07-14|0x03d3
//*******************************************************************************         //10-29-97|0x03d3
//*******************************************************************************         //10-29-97|0x03d3
UINT MACROPROJ::macproj_test_read(void) {                                                 //06-07-14|0x03d3
//*******************************************************************************         //10-29-97|0x03d3
//************************************************************************                //06-07-14|0x03d3
    switch(BasicTestRead(&test_samples[0], test_samples[0]))                              //06-07-14|0x03d3
      {                                                                                   //06-07-14|0x03d3
        case Success:                                     return(Success);                //06-07-14|0x03d3
        default:                                        ReturnSystemError;                //06-07-14|0x03d3
        }                                                                                 //06-07-14|0x03d3
}                                                                                         //06-07-14|0x03d3
//                                                                                        //05-24-97|0x03d3
//***************************************************************************             //06-07-14|0x03d4
//*******************************************************************************         //10-29-97|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
// macproj_test_write                                                                     //06-07-14|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
UINT MACROPROJ::macproj_test_write(void) {                                                //06-07-14|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
//************************************************************************                //06-07-14|0x03d5
    switch(BasicTestWrite(&test_samples[0]))                                              //06-07-14|0x03d5
      {                                                                                   //06-07-14|0x03d5
        case Success:                                     return(Success);                //06-07-14|0x03d5
        default:                                        ReturnSystemError;                //06-07-14|0x03d5
        }                                                                                 //06-07-14|0x03d5
}                                                                                         //06-07-14|0x03d5
//                                                                                        //05-24-97|0x03d5
//***************************************************************************             //06-07-14|0x03d6
//*******************************************************************************         //10-29-97|0x03d7
//*******************************************************************************         //10-29-97|0x03d7
// macproj_test_report                                                                    //06-07-14|0x03d7
//*******************************************************************************         //10-29-97|0x03d7
//*******************************************************************************         //10-29-97|0x03d7
UINT MACROPROJ::macproj_test_report(void) {                                               //06-07-14|0x03d7
//*******************************************************************************         //10-29-97|0x03d7
//************************************************************************                //06-07-14|0x03d7
    switch(BasicTestReport(&test_samples[0], "MACPROJ"))                                  //06-07-14|0x03d7
      {                                                                                   //06-07-14|0x03d7
        case Success:                                     return(Success);                //06-07-14|0x03d7
        default:                                        ReturnSystemError;                //06-07-14|0x03d7
        }                                                                                 //06-07-14|0x03d7
}                                                                                         //06-07-14|0x03d7
//                                                                                        //05-24-97|0x03d7
//***************************************************************************             //06-07-14|0x03d8
//***************************************************************************             //06-07-14|0x03d9
//******                                                               ******             //06-07-14|0x03da
//******                        constructor                            ******             //06-07-14|0x03db
//******                                                               ******             //06-07-14|0x03dc
//***************************************************************************             //06-07-14|0x03dd
//***************************************************************************             //06-07-14|0x03de
//*******************************************************************************         //10-29-97|0x03df
//*******************************************************************************         //10-29-97|0x03df
// CONSTRUCTOR                                                                            //06-07-14|0x03df
//*******************************************************************************         //10-29-97|0x03df
//*******************************************************************************         //10-29-97|0x03df
MACROPROJ::MACROPROJ() {                                                                  //06-07-14|0x03df
//***************************************************************************             //06-07-14|0x03e0
//***************************************************************************             //06-07-14|0x03e1
    macro_project_addr = 0;                                                               //06-07-14|0x03e2
    { ULONG i;                                                                            //06-07-14|0x03e4
      test_samples[NoTestSamples] = TestIndex;                                            //06-07-14|0x03e4
      i = 1;                                                                              //06-07-14|0x03e4
      while(i<TestIndex)                                                                  //06-07-14|0x03e4
        {                                                                                 //06-07-14|0x03e4
          test_samples[i] = 0;                                                            //06-07-14|0x03e4
          ++i;                                                                            //06-07-14|0x03e4
          }                                                                               //06-07-14|0x03e4
      }                                                                                   //06-07-14|0x03e4
}                                                                                         //06-07-14|0x03e5
//                                                                                        //05-24-97|0x03e5
//*******************************************************************************         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
//****                       END OF FILE                                     ****         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
