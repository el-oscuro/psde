//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
// OPERATION GENERATOR                                                                    //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  Copyright: 2006 Robert H. Adams                                                       //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  The purpose of this program as well as instructions regarding its use is              //06-07-14|0x000c
//  defined in the associated manual.                                                     //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  This program is free software; you can redistribute it and/or modify                  //06-07-14|0x000c
//  it under the terms of the GNU General Public License as published by                  //06-07-14|0x000c
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-14|0x000c
//  (at your option) any later version.                                                   //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//  This program is distributed in the hope that it will be useful,                       //06-07-14|0x000c
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-14|0x000c
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-14|0x000c
//  GNU General Public License for more details.                                          //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//  You should have received a copy of the GNU General Public License                     //06-07-14|0x000c
//  along with this program; if not, write to the Free Software                           //06-07-14|0x000c
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-14|0x000c
//  USA                                                                                   //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  For further information, please contact Robert Adams:                                 //06-07-14|0x000c
//     EMail:    robert.adams@whatifwe.com                                                //06-07-14|0x000c
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-14|0x000c
//  Or visit the website, "www.whatifwe.com".                                             //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
#ifdef WIN31_SYSTEM                                                                       //05-24-97|0x000d
#include "precwn31.h"                                                                     //05-24-97|0x000d
#endif                                                                                    //05-24-97|0x000d
#ifdef WIN95_SYSTEM                                                                       //05-24-97|0x000d
#include "precwn95.h"                                                                     //05-24-97|0x000d
#endif                                                                                    //05-24-97|0x000d
#ifdef MSDOS_SYSTEM                                                                       //05-24-97|0x000d
#include "precdos.h"                                                                      //05-24-97|0x000d
#endif                                                                                    //05-24-97|0x000d
#include "prechost.h"                                                                     //05-24-97|0x000d
#include "precoper.h"                                                                     //06-07-14|0x000d
#include "precoper.hxx"                                                                   //06-07-14|0x000d
#include "precoper.hpp"                                                                   //06-07-14|0x000d
#include "precdbug.h"                                                                     //check   |0x000e
#include "precdiag.h"                                                                     //check   |0x000f
#include "prime.h"                                                                        //check    |0x0010
#include "crypto.h"                                                                       //10-03-23|0x0011
#include "precutil.h"                                                                     //09-03-11|0x0012
#include "errormail.h"                                                                    //09-03-11|0x0013
#include "guicomm.h"                                                                      //06-09-26|0x0014
#include "precdiag.h"                                                                     //06-07-14|0x0015
#include "precform.h"                                                                     //06-07-14|0x0016
#include "precfile.h"                                                                     //06-07-14|0x0017
#include "precstck.h"                                                                     //06-07-14|0x0018
#include "prectext.h"                                                                     //06-07-14|0x0019
#include "precreg.h"                                                                      //06-07-14|0x001a
#include "precnum.h"                                                                      //06-07-14|0x001b
#include "srcedict.h"                                                                     //06-07-14|0x001c
#include "maildict.h"                                                                     //09-03-11|0x001d
#include "macdict.h"                                                                      //06-07-14|0x001e
#include "preccall.h"                                                                     //06-07-14|0x001f
#include "global.hxx"                                                                     //06-12-19|0x0020
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
PRECOPER prec_oper;                                                                       //06-07-14|0x0057
static UINT test_samples[TestIndex];                                                      //06-07-14|0x005f
//***************************************************************************             //06-07-14|0x007d
//***************************************************************************             //06-07-14|0x007e
//******                                                               ******             //06-07-14|0x007f
//******                        process_command                        ******             //06-07-14|0x0080
//******                                                               ******             //06-07-14|0x0081
//***************************************************************************             //06-07-14|0x0082
//***************************************************************************             //06-09-26|0x0083
//*******************************************************************************         //10-29-97|0x0087
//*******************************************************************************         //10-29-97|0x0087
// proc_cmd                                                                               //06-12-19|0x0087
//*******************************************************************************         //10-29-97|0x0087
//*******************************************************************************         //10-29-97|0x0087
UINT PRECOPER::proc_cmd(                                                                  //06-12-19|0x0087
    PROCESS_DATA_FAR ProcessDataFar,                                                      //06-12-19|0x0087
    PROCESS_FILES_FAR ProcessFilesFar,                                                    //06-12-19|0x0087
    TOKENS_FAR PcgTokenFar                                                                //06-12-19|0x0087
    ) {                                                                                   //06-12-19|0x0087
//*******************************************************************************         //10-29-97|0x0087
//***************************************************************************             //06-09-26|0x008b
//***************************************************************************             //06-09-26|0x008c
  UINT status;                                                                       //06-09-26|0x008d
//***************************************************************************             //06-09-26|0x008e
//***************************************************************************             //06-09-26|0x008f
    status = Continue;                                                                    //06-09-26|0x0090
    if(ProcessProcessCommand & 0x8000)                                                    //06-09-26|0x0090
      {                                                                                   //06-09-26|0x0090
        switch(auto_debug_on(ProcessDataFar))              _SwitchGroup;                  //06-09-26|0x0090
        }                                                                                 //06-09-26|0x0090
    switch(ProcessProcessCommand & 0x7fff)                                                //06-09-26|0x0090
      {                                                                                   //06-09-26|0x0090
//***************************************************************************             //06-09-26|0x0091
//***************************************************************************             //06-09-26|0x0092
//******                                                               ******             //06-09-26|0x0093
//******                   macro begin -- end commands                 ******             //06-09-26|0x0094
//******                                                               ******             //06-09-26|0x0095
//***************************************************************************             //07-09-13|0x0096
//***************************************************************************             //07-09-13|0x0097
//******                          In Manual                            ******             //07-09-13|0x0098
//***************************************************************************             //06-09-26|0x0099
//***************************************************************************             //06-09-26|0x009a
        case I_BEGIN:                                                                     //06-09-26|0x009b
          TestSample(_BEGIN_1);                                                           //06-09-26|0x009b
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-26|0x009c
          if(TokensNoTokens >  4)                   ReturnSystemError;                    //06-09-26|0x009c
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-26|0x009c
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-26|0x009d
          switch(macro_begin(ProcessDataFar))               _SwitchGroup                  //06-09-26|0x009d
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-26|0x009e
          return(status);                                                                 //06-09-26|0x009e
//***************************************************************************             //06-09-26|0x009f
        case I_END:                                                                       //06-09-28|0x00a0
          TestSample(_END_1);                                                             //06-09-28|0x00a0
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-28|0x00a1
          if(TokensNoTokens   != 1)                   ReturnSystemError;                  //06-09-28|0x00a1
          status = MacroReturn;                                                           //06-09-28|0x00a1
          switch(status)                                                                  //06-09-28|0x00a1
            {                                                                             //06-09-28|0x00a1
              case Continue:                                      break;                  //06-09-28|0x00a1
              case LineDone:                                      break;                  //06-09-28|0x00a1
              case UserError:                         return(UserError);                  //06-09-28|0x00a1
              default:                                ReturnSystemError;                  //06-09-28|0x00a1
              }                                                                           //06-09-28|0x00a1
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-28|0x00a2
          return(status);                                                                 //06-09-28|0x00a2
//***************************************************************************             //09-03-11|0x00a3
//***************************************************************************             //09-03-11|0x00a4
//******                                                               ******             //09-03-11|0x00a5
//******                      call related commands                    ******             //09-03-11|0x00a6
//******                                                               ******             //09-03-11|0x00a7
//***************************************************************************             //09-03-11|0x00a8
//***************************************************************************             //09-03-11|0x00a9
        case I_GET_NO_PARMS:                                                              //07-04-09|0x00aa
          TestSample(_GET_NO_PARMS_1);                                                    //07-04-09|0x00aa
          if(TokensNoTokens !=2)                     ReturnSystemError;                   //07-04-09|0x00ab
          switch(FetchNoParms)                              _SwitchGroup                  //07-04-09|0x00ab
          ResultNumType   = 2;                                                            //07-04-09|0x00ab
          switch(NumericRegOut)                               _SwitchGroup                //07-04-09|0x00ac
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-04-09|0x00ad
          return(status);                                                                 //07-04-09|0x00ad
//***************************************************************************             //06-11-19|0x00ae
        case I_TEST_PARM:                                                                 //06-09-30|0x00af
          TestSample(_TEST_PARM_1);                                                       //06-09-30|0x00af
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-30|0x00b0
          if(TokensNoTokens != 2)                     ReturnSystemError;                  //06-09-30|0x00b0
          switch(TestParmExist)                                                           //06-09-30|0x00b0
            {                                                                             //06-09-30|0x00b0
              case Yes: ProcessFlagState =  1;                    break;                  //06-09-30|0x00b0
              case No:  ProcessFlagState = -1;                    break;                  //06-09-30|0x00b0
              case UserError:                         return(UserError);                  //06-09-30|0x00b0
              default:                                ReturnSystemError;                  //06-09-30|0x00b0
              }                                                                           //06-09-30|0x00b0
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-09-30|0x00b1
          return(status);                                                                 //06-09-30|0x00b1
//***************************************************************************             //06-09-26|0x00b2
        case I_CALL:                                                                      //06-09-26|0x00b3
          TestSample(_CALL_1);                                                            //06-09-26|0x00b3
          if(TokensNoTokens <  1)                   ReturnSystemError;                    //06-09-26|0x00b4
          if(TokensNoTokens >  10)                   ReturnSystemError;                   //06-09-26|0x00b4
          switch(TokensPrepare(ProcessTokensAddr, 0))      _SwitchGroup                   //06-09-26|0x00b4
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-26|0x00b5
          switch(MacroCall)                                                               //06-09-26|0x00b5
            {                                                                             //06-09-26|0x00b5
              case Success:                                       break;                  //06-09-26|0x00b5
              case UserError:                         return(UserError);                  //06-09-26|0x00b5
              default:                                ReturnSystemError;                  //06-09-26|0x00b5
              }                                                                           //06-09-26|0x00b5
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-26|0x00b6
          return(status);                                                                 //06-09-26|0x00b6
//***************************************************************************             //06-09-26|0x00b7
        case I_TEST_RETURN:                                                               //07-02-17|0x00b8
          TestSample(_TEST_RETURN_1);                                                     //07-02-17|0x00b8
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-02-17|0x00b9
          if(TokensNoTokens != 1)                     ReturnSystemError;                  //07-02-17|0x00b9
          switch(TestReturn)                                                              //07-02-17|0x00b9
            {                                                                             //07-02-17|0x00b9
              case Yes: ProcessFlagState =  1;                    break;                  //07-02-17|0x00b9
              case No:  ProcessFlagState = -1;                    break;                  //07-02-17|0x00b9
              case UserError:                         return(UserError);                  //07-02-17|0x00b9
              default:                                ReturnSystemError;                  //07-02-17|0x00b9
              }                                                                           //07-02-17|0x00b9
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-02-17|0x00ba
          return(status);                                                                 //07-02-17|0x00ba
//***************************************************************************             //06-09-26|0x00bb
//***************************************************************************             //06-09-26|0x00bc
//******                                                               ******             //06-09-26|0x00bd
//******                      program_control_operations               ******             //06-09-26|0x00be
//******                                                               ******             //06-09-26|0x00bf
//***************************************************************************             //07-09-13|0x00c0
//***************************************************************************             //07-09-13|0x00c1
//******                          In Manual                            ******             //07-09-13|0x00c2
//***************************************************************************             //06-09-26|0x00c3
//***************************************************************************             //06-09-26|0x00c4
        case I_JUMP_IF:                                                                   //06-09-28|0x00c5
          TestSample(_JUMP_IF_1);                                                         //06-09-28|0x00c5
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-28|0x00c6
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-09-28|0x00c6
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-28|0x00c6
          switch(label_prepare(ProcessDataFar))             _SwitchGroup                  //06-09-28|0x00c7
          switch(ProcessFlagState)                                                        //06-09-28|0x00c8
            {                                                                             //06-09-28|0x00c8
              case 1:                                                                     //06-09-28|0x00c8
                switch(MacDictMacroEnd())                   _SwitchGroup                  //06-09-28|0x00c8
                switch(FindLabel)                                                         //06-09-28|0x00c8
                  {                                                                       //06-09-28|0x00c8
                    case Success:                                 break;                  //06-09-28|0x00c8
                    case UserError:   ReturnFinish("Label Not Defined");                  //06-09-28|0x00c8
                    default:                          ReturnSystemError;                  //06-09-28|0x00c8
                    }                                                                     //06-09-28|0x00c8
                break;                                                                    //06-09-28|0x00c8
              case -1:                                            break;                  //06-09-28|0x00c8
              default:       ReturnFinish("Test Flag Not Properly Set");                  //06-09-28|0x00c8
              }                                                                           //06-09-28|0x00c8
          ProcessFlagState = 0;                                                           //06-09-28|0x00c8
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-28|0x00c9
          return(status);                                                                 //06-09-28|0x00c9
//***************************************************************************             //06-09-29|0x00ca
        case I_JUMP_IF_NOT:                                                               //06-09-29|0x00cb
          TestSample(_JUMP_IF_NOT_1);                                                     //06-09-29|0x00cb
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-29|0x00cc
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-09-29|0x00cc
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-29|0x00cc
          switch(label_prepare(ProcessDataFar))             _SwitchGroup                  //06-09-29|0x00cd
          switch(ProcessFlagState)                                                        //06-09-29|0x00ce
            {                                                                             //06-09-29|0x00ce
              case -1:                                                                    //06-09-29|0x00ce
                switch(MacDictMacroEnd())                   _SwitchGroup                  //06-09-29|0x00ce
                switch(FindLabel)                                                         //06-09-29|0x00ce
                  {                                                                       //06-09-29|0x00ce
                    case Success:                                 break;                  //06-09-29|0x00ce
                    case UserError:   ReturnFinish("Label Not Defined");                  //06-09-29|0x00ce
                    default:                          ReturnSystemError;                  //06-09-29|0x00ce
                    }                                                                     //06-09-29|0x00ce
                break;                                                                    //06-09-29|0x00ce
              case 1:                                            break;                   //06-09-29|0x00ce
              default:       ReturnFinish("Test Flag Not Properly Set");                  //06-09-29|0x00ce
              }                                                                           //06-09-29|0x00ce
          ProcessFlagState = 0;                                                           //06-09-29|0x00ce
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-29|0x00cf
          return(status);                                                                 //06-09-29|0x00cf
//***************************************************************************             //06-09-28|0x00d0
        case I_JUMP_ALWAYS:                                                               //06-09-28|0x00d1
          TestSample(_JUMP_ALWAYS_1);                                                     //06-09-28|0x00d1
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-28|0x00d2
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-09-28|0x00d2
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-28|0x00d2
          switch(label_prepare(ProcessDataFar))             _SwitchGroup                  //06-09-28|0x00d3
          switch(ProcessFlagState)                                                        //06-09-28|0x00d4
            {                                                                             //06-09-28|0x00d4
              case 0:                                                                     //06-09-28|0x00d4
                switch(MacDictMacroEnd())                   _SwitchGroup                  //06-09-28|0x00d4
                switch(FindLabel)                                                         //06-09-28|0x00d4
                  {                                                                       //06-09-28|0x00d4
                    case Success:                                 break;                  //06-09-28|0x00d4
                    case UserError:   ReturnFinish("Label Not Defined");                  //06-09-28|0x00d4
                    default:                          ReturnSystemError;                  //06-09-28|0x00d4
                    }                                                                     //06-09-28|0x00d4
                break;                                                                    //06-09-28|0x00d4
              default:          ReturnFinish("Test Flag Illegally Set");                  //06-09-28|0x00d4
              }                                                                           //06-09-28|0x00d4
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-28|0x00d5
          return(status);                                                                 //06-09-28|0x00d5
//***************************************************************************             //06-09-28|0x00d6
        case I_LABEL:                                                                     //08-01-09|0x00d7
          TestSample(_LABEL_1);                                                           //08-01-09|0x00d7
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //08-01-09|0x00d8
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //08-01-09|0x00d8
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //08-01-09|0x00d8
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //08-01-09|0x00d9
          return(status);                                                                 //08-01-09|0x00d9
//***************************************************************************             //06-09-28|0x00da
        case I_TEST_CLASS:                                                                //07-07-18|0x00db
          TestSample(_TEST_CLASS_1);                                                      //07-07-18|0x00db
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //07-07-18|0x00dc
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //07-07-18|0x00dc
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //07-07-18|0x00dc
          switch(class_search(ProcessDataFar))              _SwitchGroup                  //07-07-18|0x00dd
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-07-18|0x00de
          return(status);                                                                 //07-07-18|0x00de
//***************************************************************************             //07-12-25|0x00df
//***************************************************************************             //07-12-25|0x00e0
        case I_GET_FLAG:                                                                  //07-12-25|0x00e1
          TestSample(_GET_FLAG_1);                                                        //07-12-25|0x00e1
          if(TokensNoTokens != 2)                     ReturnSystemError;                  //07-12-25|0x00e2
          ResultsType         = I_NAME;                                                   //07-12-25|0x00e2
          ResultsMacroLineNo  = TokensMacroLineNo(1);                                     //07-12-25|0x00e2
          switch(ProcessFlagState)                                                        //07-12-25|0x00e2
            {                                                                             //07-12-25|0x00e2
              case -1:                                                                    //07-12-25|0x00e2
                StrCpy(ResultsLineAddr, "false");                                         //07-12-25|0x00e2
                ResultsLength = 5;                                                        //07-12-25|0x00e2
                break;                                                                    //07-12-25|0x00e2
              case 1:                                                                     //07-12-25|0x00e2
                StrCpy(ResultsLineAddr, "true");                                          //07-12-25|0x00e2
                ResultsLength = 4;                                                        //07-12-25|0x00e2
                break;                                                                    //07-12-25|0x00e2
              default:       ReturnFinish("Test Flag Not Properly Set");                  //07-12-25|0x00e2
              }                                                                           //07-12-25|0x00e2
          ProcessFlagState = 0;                                                           //07-12-25|0x00e2
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-12-25|0x00e3
                                                            _SwitchGroup                  //07-12-25|0x00e3
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-12-25|0x00e4
          return(status);                                                                 //07-12-25|0x00e4
//***************************************************************************             //07-12-25|0x00e5
        case I_STATE_FLAG:                                                                //07-12-25|0x00e6
          TestSample(_STATE_FLAG_1);                                                      //07-12-25|0x00e6
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //07-12-25|0x00e7
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //07-12-25|0x00e7
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //07-12-25|0x00e7
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-12-25|0x00e8
          switch(TokensLength(1))                                                         //07-12-25|0x00e8
            {                                                                             //07-12-25|0x00e8
              case 4:                                                                     //07-12-25|0x00e8
                ProcessFlagState = 1;                                                     //07-12-25|0x00e8
                if(TokensChar(1,4) != 0)              ReturnSystemError;                  //07-12-25|0x00e8
                switch(StrCmp(TokensLineAddr(1), "true"))                                 //07-12-25|0x00e8
                  {                                                                       //07-12-25|0x00e8
                    case 0:                                       break;                  //07-12-25|0x00e8
                    case 1:                                                               //07-12-25|0x00e8
                    case -1: ReturnFinish("Test Flag Not Properly Set");                  //07-12-25|0x00e8
                    default: ReturnSystemError;                                           //07-12-25|0x00e8
                    }                                                                     //07-12-25|0x00e8
                break;                                                                    //07-12-25|0x00e8
              case 5:                                                                     //07-12-25|0x00e8
                ProcessFlagState = -1;                                                    //07-12-25|0x00e8
                if(TokensChar(1,5) != 0)              ReturnSystemError;                  //07-12-25|0x00e8
                switch(StrCmp(TokensLineAddr(1), "false"))                                //07-12-25|0x00e8
                  {                                                                       //07-12-25|0x00e8
                    case 0:                                       break;                  //07-12-25|0x00e8
                    case 1:                                                               //07-12-25|0x00e8
                    case -1: ReturnFinish("Test Flag Not Properly Set");                  //07-12-25|0x00e8
                    default: ReturnSystemError;                                           //07-12-25|0x00e8
                    }                                                                     //07-12-25|0x00e8
                break;                                                                    //07-12-25|0x00e8
              default:       ReturnFinish("Test Flag Not Properly Set");                  //07-12-25|0x00e8
              }                                                                           //07-12-25|0x00e8
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-12-25|0x00e9
          return(status);                                                                 //07-12-25|0x00e9
//***************************************************************************             //check   |0x00ea
//***************************************************************************             //check   |0x00eb
        case I_CONTINUE_IF:                                                               //check   |0x00ec
          TestSample(_CONTINUE_IF_1);                                                     //check   |0x00ec
          if(TokensNoTokens   != 1)                   ReturnSystemError;                  //check   |0x00ed
          if(ProcessFlagState == -1)    ReturnFinish("Test Flag Error");                  //check   |0x00ed
          if(ProcessFlagState != 1)                  ReturnSystemError;                   //check   |0x00ed
          ProcessFlagState = 0;                                                           //check   |0x00ed
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //check   |0x00ee
          return(status);                                                                 //check   |0x00ee
//***************************************************************************             //check   |0x00ef
        case I_CONTINUE_IF_NOT:                                                           //check   |0x00f0
          TestSample(_CONTINUE_IF_NOT_1);                                                 //check   |0x00f0
          if(TokensNoTokens   != 1)                   ReturnSystemError;                  //check   |0x00f1
          if(ProcessFlagState == 1)    ReturnFinish("Test Flag Error");                   //check   |0x00f1
          if(ProcessFlagState != -1)                  ReturnSystemError;                  //check   |0x00f1
          ProcessFlagState = 0;                                                           //check   |0x00f1
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //check   |0x00f2
          return(status);                                                                 //check   |0x00f2
//***************************************************************************             //06-09-29|0x00f3
//***************************************************************************             //06-09-29|0x00f4
//******                                                               ******             //06-09-29|0x00f5
//******                      basic stack operations                   ******             //06-09-29|0x00f6
//******                                                               ******             //06-09-29|0x00f7
//***************************************************************************             //07-09-13|0x00f8
//***************************************************************************             //07-09-13|0x00f9
//******                          In Manual                            ******             //07-09-13|0x00fa
//***************************************************************************             //07-03-19|0x00fb
//***************************************************************************             //07-03-19|0x00fc
        case I_ASSIGN_STACK:                                                              //07-03-19|0x00fd
          TestSample(_ASSIGN_STACK_1);                                                    //07-03-19|0x00fd
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //07-03-19|0x00fe
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //07-03-19|0x00fe
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //07-03-19|0x00fe
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-03-19|0x00ff
          switch(AssignStack)                               _SwitchGroup                  //07-03-19|0x00ff
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-03-19|0x0100
          return(status);                                                                 //07-03-19|0x0100
//***************************************************************************             //06-09-29|0x0101
//***************************************************************************             //06-09-29|0x0102
        case I_PUSH_TOKEN:                                                                //06-12-21|0x0103
          TestSample(_PUSH_TOKEN_1);                                                      //06-12-21|0x0103
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-12-21|0x0104
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-12-21|0x0104
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-12-21|0x0104
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-12-21|0x0105
          switch(StackPush(TokensTokenAddr(1)))             _SwitchGroup                  //06-12-21|0x0105
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-12-21|0x0106
          return(status);                                                                 //06-12-21|0x0106
//***************************************************************************             //06-12-21|0x0107
//***************************************************************************             //06-12-21|0x0108
        case I_POP_TOKEN:                                                                 //06-12-22|0x0109
          TestSample(_POP_TOKEN_1);                                                       //06-12-22|0x0109
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-12-22|0x010a
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-12-22|0x010a
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-12-22|0x010a
//---------------------------------------------------------------------------             //06-12-22|0x010b
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-12-22|0x010c
          switch(StackEmptyTest())                                                        //06-12-22|0x010c
            {                                                                             //06-12-22|0x010c
              case No:                  ReturnFinish("_POP_TOKEN: Stack Empty");          //06-12-22|0x010c
              case Yes:                                           break;                  //06-12-22|0x010c
              default:                                ReturnSystemError;                  //06-12-22|0x010c
              }                                                                           //06-12-22|0x010c
//---------------------------------------------------------------------------             //06-12-22|0x010d
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-12-22|0x010e
          switch(StackTest(0, TokensTokenAddr(1)))                                        //06-12-22|0x010e
            {                                                                             //06-12-22|0x010e
              case No:               ReturnFinish("_POP_TOKEN: Token Mismatch");          //06-12-22|0x010e
              case Yes:                                           break;                  //06-12-22|0x010e
              default:                                ReturnSystemError;                  //06-12-22|0x010e
              }                                                                           //06-12-22|0x010e
//---------------------------------------------------------------------------             //06-12-22|0x010f
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-12-22|0x0110
          switch(StackPop(1))                               _SwitchGroup                  //06-12-22|0x0110
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-12-22|0x0111
          return(status);                                                                 //06-12-22|0x0111
//***************************************************************************             //06-12-22|0x0112
//***************************************************************************             //06-12-22|0x0113
        case I_GET_STACK_LEVEL:                                                           //07-09-13|0x0114
          TestSample(_GET_STACK_LEVEL_1);                                                 //07-09-13|0x0114
//---------------------------------------------------------------------------             //07-09-13|0x0115
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-09-13|0x0116
          switch(StackStackLevel(&ResultNumUlong))          _SwitchGroup                  //07-09-13|0x0116
          if(ResultNumUlong >= 0x10000)              ReturnSystemError;                   //07-09-13|0x0116
          ResultNumType = 2;                                                              //07-09-13|0x0116
//---------------------------------------------------------------------------             //07-09-13|0x0117
          switch(NumericRegOut)                               _SwitchGroup                //07-09-13|0x0118
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-13|0x0119
          return(status);                                                                 //07-09-13|0x0119
//***************************************************************************             //07-03-28|0x011a
//***************************************************************************             //07-03-28|0x011b
        case I_STATE_TOKEN:                                                               //07-03-28|0x011c
          TestSample(_STATE_TOKEN_1);                                                     //07-03-28|0x011c
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //07-03-28|0x011d
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //07-03-28|0x011d
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //07-03-28|0x011d
//---------------------------------------------------------------------------             //07-03-28|0x011e
          if(ProcessFlagState != 0)   ReturnFinish("Test Flag Not Reset");                //07-03-28|0x011f
          switch(StackTest(0, TokensTokenAddr(1)))                                        //07-03-28|0x011f
            {                                                                             //07-03-28|0x011f
              case No:     ProcessFlagState = -1;                   break;                //07-03-28|0x011f
              case Yes:    ProcessFlagState =  1;                   break;                //07-03-28|0x011f
              default:                                  ReturnSystemError;                //07-03-28|0x011f
              }                                                                           //07-03-28|0x011f
//---------------------------------------------------------------------------             //07-03-28|0x0120
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-03-28|0x0121
          return(status);                                                                 //07-03-28|0x0121
//***************************************************************************             //07-03-16|0x0122
//***************************************************************************             //07-03-16|0x0123
        case I_GET_TOKEN:                                                                 //07-03-16|0x0124
          TestSample(_GET_TOKEN_1);                                                       //07-03-16|0x0124
          if(TokensNoTokens   != 2)                  ReturnSystemError;                   //07-03-16|0x0125
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-03-16|0x0125
          switch(StackGet(ProcessResultsAddr))              _SwitchGroup                  //07-03-16|0x0125
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-03-16|0x0126
                                                            _SwitchGroup                  //07-03-16|0x0126
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-03-16|0x0127
          return(status);                                                                 //07-03-16|0x0127
//***************************************************************************             //07-09-13|0x0128
//***************************************************************************             //07-09-13|0x0129
        case I_STATE_STACK:                                                               //07-09-13|0x012a
          TestSample(_STATE_STACK_1);                                                     //07-09-13|0x012a
//---------------------------------------------------------------------------             //07-09-13|0x012b
          if(ProcessFlagState != 0)   ReturnFinish("Test Flag Not Reset");                //07-09-13|0x012c
          switch(StackEmptyTest())                                                        //07-09-13|0x012c
            {                                                                             //07-09-13|0x012c
              case No:     ProcessFlagState = -1;                   break;                //07-09-13|0x012c
              case Yes:    ProcessFlagState =  1;                   break;                //07-09-13|0x012c
              default:                                  ReturnSystemError;                //07-09-13|0x012c
              }                                                                           //07-09-13|0x012c
//---------------------------------------------------------------------------             //07-09-13|0x012d
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-09-13|0x012e
          return(status);                                                                 //07-09-13|0x012e
//***************************************************************************             //06-12-21|0x012f
//***************************************************************************             //06-12-21|0x0130
//******                                                               ******             //06-12-21|0x0131
//******                      stack rule operations                    ******             //06-12-21|0x0132
//******                                                               ******             //06-12-21|0x0133
//***************************************************************************             //07-09-13|0x0134
//***************************************************************************             //07-09-13|0x0135
//******                          In Manual                            ******             //07-09-13|0x0136
//***************************************************************************             //06-12-21|0x0137
//***************************************************************************             //06-12-21|0x0138
        case I_RULE_START:                                                                //06-12-21|0x0139
          TestSample(_RULE_START_1);                                                      //06-12-21|0x0139
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-12-21|0x013a
          if(TokensNoTokens   != 1)                   ReturnSystemError;                  //06-12-21|0x013a
          if(ProcessRuleState != 0)                                                       //06-12-21|0x013a
                      ReturnFinish("Previous Rule Group Not Completed");                  //06-12-21|0x013a
          ProcessRuleState = 11;                                                          //06-12-21|0x013a
          ProcessFlagState = -2;                                                          //06-12-21|0x013a
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-12-21|0x013b
          return(status);                                                                 //06-12-21|0x013b
//***************************************************************************             //06-12-21|0x013c
//***************************************************************************             //06-12-22|0x013d
        case I_RULE_END:                                                                  //06-12-22|0x013e
          TestSample(_RULE_END_1);                                                        //06-12-22|0x013e
//---------------------------------------------------------------------------             //06-12-22|0x013f
          if(TokensNoTokens   != 1)                   ReturnSystemError;                  //06-12-22|0x0140
          switch(ProcessRuleState)                                                        //06-12-22|0x0140
            {                                                                             //06-12-22|0x0140
              case 3:                                             break;                  //06-12-22|0x0140
              case 4:                                                                     //06-12-22|0x0140
              case 5:                                                                     //06-12-22|0x0140
              case 6:                                                                     //06-12-22|0x0140
              case 7:                                                                     //06-12-22|0x0140
              case 8:                                                                     //06-12-22|0x0140
              case 9:                                             break;                  //06-12-22|0x0140
              case 0:   ReturnFinish("Rule Group Not Properly Started");                  //06-12-22|0x0140
              case 11:  ReturnFinish("Rule Group Empty");                                 //06-12-22|0x0140
              default:                                ReturnSystemError;                  //06-12-22|0x0140
              }                                                                           //06-12-22|0x0140
//---------------------------------------------------------------------------             //06-12-22|0x0141
          switch(ProcessFlagState)                                                        //06-12-22|0x0142
            {                                                                             //06-12-22|0x0142
              case  2:                                            break;                  //06-12-22|0x0142
              case -2:           ReturnFinish("No Rule was successful");                  //06-12-22|0x0142
              default:                                ReturnSystemError;                  //06-12-22|0x0142
              }                                                                           //06-12-22|0x0142
         ProcessFlagState = 0;                                                            //06-12-22|0x0142
         ProcessRuleState = 0;                                                            //06-12-22|0x0142
//---------------------------------------------------------------------------             //06-12-22|0x0143
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-12-22|0x0144
          return(status);                                                                 //06-12-22|0x0144
//***************************************************************************             //06-12-22|0x0145
//***************************************************************************             //06-12-22|0x0146
        case I_RULE_STATE:                                                                //07-02-07|0x0147
          TestSample(_RULE_STATE_1);                                                      //07-02-07|0x0147
//---------------------------------------------------------------------------             //07-02-07|0x0148
          if(TokensNoTokens   != 1)                   ReturnSystemError;                  //07-02-07|0x0149
          switch(ProcessRuleState)                                                        //07-02-07|0x0149
            {                                                                             //07-02-07|0x0149
              case 3:                                             break;                  //07-02-07|0x0149
              case 4:                                                                     //07-02-07|0x0149
              case 5:                                                                     //07-02-07|0x0149
              case 6:                                                                     //07-02-07|0x0149
              case 7:                                                                     //07-02-07|0x0149
              case 8:                                                                     //07-02-07|0x0149
              case 9:                                             break;                  //07-02-07|0x0149
              case 0:   ReturnFinish("Rule Group Not Properly Started");                  //07-02-07|0x0149
              case 11:  ReturnFinish("Rule Group Empty");                                 //07-02-07|0x0149
              default:                                ReturnSystemError;                  //07-02-07|0x0149
              }                                                                           //07-02-07|0x0149
//---------------------------------------------------------------------------             //07-02-07|0x014a
          switch(ProcessFlagState)                                                        //07-02-07|0x014b
            {                                                                             //07-02-07|0x014b
              case  2:                     ProcessFlagState =  1; break;                  //07-02-07|0x014b
              case -2:                     ProcessFlagState = -1; break;                  //07-02-07|0x014b
              default:                                ReturnSystemError;                  //07-02-07|0x014b
              }                                                                           //07-02-07|0x014b
         ProcessRuleState = 0;                                                            //07-02-07|0x014b
//---------------------------------------------------------------------------             //07-02-07|0x014c
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-02-07|0x014d
          return(status);                                                                 //07-02-07|0x014d
//***************************************************************************             //06-12-22|0x014e
//***************************************************************************             //06-12-22|0x014f
        case I_MOVE:                                                                      //06-12-22|0x0150
          TestSample(_MOVE_1);                                                            //06-12-22|0x0150
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-12-22|0x0151
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //06-12-22|0x0151
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-12-22|0x0151
//---------------------------------------------------------------------------             //06-12-22|0x0152
          switch(ProcessRuleState)                                                        //06-12-22|0x0153
            {                                                                             //06-12-22|0x0153
              case 3:                                             break;                  //06-12-22|0x0153
              case 4:                                                                     //06-12-22|0x0153
              case 5:                                                                     //06-12-22|0x0153
              case 6:                                                                     //06-12-22|0x0153
              case 7:                                                                     //06-12-22|0x0153
              case 8:                                                                     //06-12-22|0x0153
              case 9:   ReturnFinish("Move Command in Emit Group");                       //06-12-22|0x0153
              case 0:   ReturnFinish("Rule Group Not Properly Started");                  //06-12-22|0x0153
              case 11:  ProcessRuleState = 3;                     break;                  //06-12-22|0x0153
              default:                                ReturnSystemError;                  //06-12-22|0x0153
              }                                                                           //06-12-22|0x0153
//---------------------------------------------------------------------------             //06-12-22|0x0154
          switch(ProcessFlagState)                                                        //06-12-22|0x0155
            {                                                                             //06-12-22|0x0155
              case  2:                                            break;                  //06-12-22|0x0155
              case -2:                                                                    //06-12-22|0x0155
                switch(StackTest(0, TokensTokenAddr(1)))                                  //06-12-22|0x0155
                  {                                                                       //06-12-22|0x0155
                    case No:                                      break;                  //06-12-22|0x0155
                    case Yes:                                                             //06-12-22|0x0155
                      ProcessFlagState = 3;                                               //06-12-22|0x0155
                      switch(StackPush(TokensTokenAddr(2)))                               //06-12-22|0x0155
                                                           _SwitchBreak;                  //06-12-22|0x0155
                    default:                          ReturnSystemError;                  //06-12-22|0x0155
                    }                                                                     //06-12-22|0x0155
                break;                                                                    //06-12-22|0x0155
              default:                                ReturnSystemError;                  //06-12-22|0x0155
              }                                                                           //06-12-22|0x0155
//---------------------------------------------------------------------------             //06-12-22|0x0156
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-12-22|0x0157
          return(status);                                                                 //06-12-22|0x0157
//***************************************************************************             //06-12-22|0x0158
//***************************************************************************             //06-12-22|0x0159
        case I_EMIT:                                                                      //06-12-22|0x015a
          TestSample(_EMIT_1);                                                            //06-12-22|0x015a
          if(TokensNoTokens <  4)                   ReturnSystemError;                    //06-12-22|0x015b
          if(TokensNoTokens >  10)                   ReturnSystemError;                   //06-12-22|0x015b
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-12-22|0x015b
//---------------------------------------------------------------------------             //06-12-22|0x015c
          if(TokensNoTokens   <= 3)                   ReturnSystemError;                  //06-12-22|0x015d
          switch(ProcessRuleState)                                                        //06-12-22|0x015d
            {                                                                             //06-12-22|0x015d
              case 3:    ReturnFinish("Emit Command in Move Group");                      //06-12-22|0x015d
              case 4:                                                                     //06-12-22|0x015d
              case 5:                                                                     //06-12-22|0x015d
              case 6:                                                                     //06-12-22|0x015d
              case 7:                                                                     //06-12-22|0x015d
              case 8:                                                                     //06-12-22|0x015d
              case 9:  if(TokensNoTokens <= ProcessRuleState)     break;                  //06-12-22|0x015d
                       ReturnFinish("Larger Rule Follows Smaller Rule");                  //06-12-22|0x015d
              case 0:  ReturnFinish("Rule Group Not Properly Started");                   //06-12-22|0x015d
              case 11:                                            break;                  //06-12-22|0x015d
              default:                                ReturnSystemError;                  //06-12-22|0x015d
              }                                                                           //06-12-22|0x015d
          ProcessRuleState = TokensNoTokens;                                              //06-12-22|0x015d
//---------------------------------------------------------------------------             //06-12-22|0x015e
          switch(ProcessFlagState)                                                        //06-12-22|0x015f
            {                                                                             //06-12-22|0x015f
              case  2:                                            break;                  //06-12-22|0x015f
              case -2:                                                                    //06-12-22|0x015f
                switch(StackTestTokens(2, ProcessTokensAddr))                             //06-12-22|0x015f
                  {                                                                       //06-12-22|0x015f
                    case No:                                      break;                  //06-12-22|0x015f
                    case Yes:                                                             //06-12-22|0x015f
                      ProcessFlagState = 3;                                               //06-12-22|0x015f
                      switch(StackPop(TokensNoTokens-2))    _SwitchGroup                  //06-12-22|0x015f
                      switch(StackPush(TokensTokenAddr(1)))                               //06-12-22|0x015f
                                                           _SwitchBreak;                  //06-12-22|0x015f
                    default:                          ReturnSystemError;                  //06-12-22|0x015f
                    }                                                                     //06-12-22|0x015f
                break;                                                                    //06-12-22|0x015f
              default:                                ReturnSystemError;                  //06-12-22|0x015f
              }                                                                           //06-12-22|0x015f
//---------------------------------------------------------------------------             //06-12-22|0x0160
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-12-22|0x0161
          return(status);                                                                 //06-12-22|0x0161
//***************************************************************************             //06-09-28|0x0162
//***************************************************************************             //06-09-28|0x0163
//******                                                               ******             //06-09-28|0x0164
//******                       basic register operations               ******             //06-09-28|0x0165
//******                                                               ******             //06-09-28|0x0166
//***************************************************************************             //07-11-05|0x0167
//***************************************************************************             //07-11-05|0x0168
//******                          In Manual                            ******             //07-11-05|0x0169
//***************************************************************************             //07-11-05|0x016a
//***************************************************************************             //07-11-05|0x016b
        case I_STORE:                                                                     //06-09-28|0x016c
          TestSample(_STORE_1);                                                           //06-09-28|0x016c
          switch(BasicRegStore)                             _SwitchGroup                  //06-09-28|0x016d
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-28|0x016e
          return(status);                                                                 //06-09-28|0x016e
//***************************************************************************             //06-09-29|0x016f
//***************************************************************************             //06-09-29|0x0170
        case I_CLEAR:                                                                     //06-09-29|0x0171
          TestSample(_CLEAR_1);                                                           //06-09-29|0x0171
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-29|0x0172
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //06-09-29|0x0172
          switch(TextClearReg(TokensTokenAddr(1)))          _SwitchGroup                  //06-09-29|0x0172
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-29|0x0173
          return(status);                                                                 //06-09-29|0x0173
//***************************************************************************             //06-09-29|0x0174
//***************************************************************************             //06-09-29|0x0175
//******                                                               ******             //06-09-29|0x0176
//******                      basic arithmetic operations              ******             //06-09-29|0x0177
//******                                                               ******             //06-09-29|0x0178
//***************************************************************************             //06-09-29|0x0179
//***************************************************************************             //06-09-29|0x017a
//******                          In Manual                            ******             //07-09-17|0x017b
//***************************************************************************             //07-09-17|0x017c
//***************************************************************************             //07-09-17|0x017d
        case I_ADD:                                                                       //06-09-29|0x017e
          TestSample(_ADD_1);                                                             //06-09-29|0x017e
          switch(NumericIn2)                                _SwitchGroup                  //06-09-29|0x017f
          ResultNumUlong += ParmNumUlong;                                                 //06-09-29|0x0180
          switch(NumericRegOut)                               _SwitchGroup                //06-09-29|0x0181
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-09-29|0x0182
          return(status);                                                                 //06-09-29|0x0182
//***************************************************************************             //06-09-29|0x0183
        case I_SUBT:                                                                      //06-10-05|0x0184
          TestSample(_SUBT_1);                                                            //06-10-05|0x0184
          switch(NumericIn2)                                _SwitchGroup                  //06-10-05|0x0185
          ResultNumUlong -= ParmNumUlong;                                                 //06-10-05|0x0186
          switch(NumericRegOut)                               _SwitchGroup                //06-10-05|0x0187
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-10-05|0x0188
          return(status);                                                                 //06-10-05|0x0188
//***************************************************************************             //06-10-05|0x0189
        case I_MULT:                                                                      //06-10-06|0x018a
          TestSample(_MULT_1);                                                            //06-10-06|0x018a
          switch(NumericIn2)                                _SwitchGroup                  //06-10-06|0x018b
          ResultNumUlong *= ParmNumUlong;                                                 //06-10-06|0x018c
          switch(NumericRegOut)                               _SwitchGroup                //06-10-06|0x018d
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-10-06|0x018e
          return(status);                                                                 //06-10-06|0x018e
//***************************************************************************             //06-10-06|0x018f
        case I_DIV:                                                                       //07-07-27|0x0190
          TestSample(_DIV_1);                                                             //07-07-27|0x0190
          switch(NumericIn2)                                _SwitchGroup                  //07-07-27|0x0191
          if(ResultNumType < ParmNumType)  ReturnFinish("Numeric Size");                  //07-07-27|0x0192
          if(ParmNumUlong  == 0)           ReturnFinish("Zero Divide");                   //07-07-27|0x0192
          ResultNumUlong /= ParmNumUlong;                                                 //07-07-27|0x0192
          switch(NumericRegOut)                               _SwitchGroup                //07-07-27|0x0193
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-07-27|0x0194
          return(status);                                                                 //07-07-27|0x0194
//***************************************************************************             //07-07-27|0x0195
        case I_MOD:                                                                       //07-09-07|0x0196
          TestSample(_MOD_1);                                                             //07-09-07|0x0196
          switch(NumericIn2)                                _SwitchGroup                  //07-09-07|0x0197
          if(ResultNumType < ParmNumType)  ReturnFinish("Numeric Size");                  //07-09-07|0x0198
          if(ParmNumUlong  == 0)           ReturnFinish("Zero Divide");                   //07-09-07|0x0198
          ResultNumUlong %= ParmNumUlong;                                                 //07-09-07|0x0198
          switch(NumericRegOut)                               _SwitchGroup                //07-09-07|0x0199
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-07|0x019a
          return(status);                                                                 //07-09-07|0x019a
//***************************************************************************             //07-09-07|0x019b
        case I_AND:                                                                       //07-09-17|0x019c
          TestSample(_AND_1);                                                             //07-09-17|0x019c
          switch(NumericIn2)                                _SwitchGroup                  //07-09-17|0x019d
          ResultNumUlong &= ParmNumUlong;                                                 //07-09-17|0x019e
          switch(NumericRegOut)                               _SwitchGroup                //07-09-17|0x019f
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-17|0x01a0
          return(status);                                                                 //07-09-17|0x01a0
//***************************************************************************             //07-09-17|0x01a1
        case I_OR:                                                                        //07-09-17|0x01a2
          TestSample(_OR_1);                                                              //07-09-17|0x01a2
          switch(NumericIn2)                                _SwitchGroup                  //07-09-17|0x01a3
          ResultNumUlong |= ParmNumUlong;                                                 //07-09-17|0x01a4
          switch(NumericRegOut)                               _SwitchGroup                //07-09-17|0x01a5
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-17|0x01a6
          return(status);                                                                 //07-09-17|0x01a6
//***************************************************************************             //07-09-17|0x01a7
        case I_EXOR:                                                                      //07-09-17|0x01a8
          TestSample(_EXOR_1);                                                            //07-09-17|0x01a8
          switch(NumericIn2)                                _SwitchGroup                  //07-09-17|0x01a9
          ResultNumUlong ^= ParmNumUlong;                                                 //07-09-17|0x01aa
          switch(NumericRegOut)                               _SwitchGroup                //07-09-17|0x01ab
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-17|0x01ac
          return(status);                                                                 //07-09-17|0x01ac
//***************************************************************************             //06-10-06|0x01ad
//***************************************************************************             //06-10-06|0x01ae
//******                                                               ******             //06-10-06|0x01af
//******                      arithmetic comparison                    ******             //06-10-06|0x01b0
//******                                                               ******             //06-10-06|0x01b1
//***************************************************************************             //06-10-06|0x01b2
//***************************************************************************             //06-10-06|0x01b3
//******                          In Manual                            ******             //07-09-17|0x01b4
//***************************************************************************             //07-09-17|0x01b5
//***************************************************************************             //07-09-17|0x01b6
        case I_LESS:                                                                      //06-10-06|0x01b7
          TestSample(_LESS_1);                                                            //06-10-06|0x01b7
          switch(NumericIn2)                                _SwitchGroup                  //06-10-06|0x01b8
          ProcessFlagState = (ResultNumUlong < ParmNumUlong) ? 1: -1;                     //06-10-06|0x01b9
          switch(NumericRegOut)                               _SwitchGroup                //06-10-06|0x01ba
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-10-06|0x01bb
          return(status);                                                                 //06-10-06|0x01bb
//***************************************************************************             //06-10-06|0x01bc
        case I_EQUAL:                                                                     //06-10-06|0x01bd
          TestSample(_EQUAL_1);                                                           //06-10-06|0x01bd
          switch(NumericIn2)                                _SwitchGroup                  //06-10-06|0x01be
          ProcessFlagState = (ResultNumUlong == ParmNumUlong) ? 1: -1;                    //06-10-06|0x01bf
          switch(NumericRegOut)                               _SwitchGroup                //06-10-06|0x01c0
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-10-06|0x01c1
          return(status);                                                                 //06-10-06|0x01c1
//***************************************************************************             //06-10-05|0x01c2
        case I_GREAT:                                                                     //06-10-05|0x01c3
          TestSample(_GREAT_1);                                                           //06-10-05|0x01c3
          switch(NumericIn2)                                _SwitchGroup                  //06-10-05|0x01c4
          ProcessFlagState = (ResultNumUlong > ParmNumUlong) ? 1: -1;                     //06-10-05|0x01c5
          switch(NumericRegOut)                               _SwitchGroup                //06-10-05|0x01c6
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-10-05|0x01c7
          return(status);                                                                 //06-10-05|0x01c7
//***************************************************************************             //07-09-18|0x01c8
//***************************************************************************             //07-09-18|0x01c9
//******                                                               ******             //07-09-18|0x01ca
//******                      arithmetic type                          ******             //07-09-18|0x01cb
//******                                                               ******             //07-09-18|0x01cc
//***************************************************************************             //07-09-18|0x01cd
//***************************************************************************             //07-09-18|0x01ce
//******                          In Manual                            ******             //07-09-18|0x01cf
//***************************************************************************             //07-09-18|0x01d0
//***************************************************************************             //07-03-28|0x01d1
        case I_STATE_NUMBER:                                                              //07-03-28|0x01d2
          TestSample(_STATE_NUMBER_1);                                                    //07-03-28|0x01d2
          switch(StringInReg)                               _SwitchGroup                  //07-03-28|0x01d3
          switch(NumResultsIn)                              _SwitchGroup                  //07-03-28|0x01d4
          ProcessFlagState = ((ResultNumType & 7) != 0) ? 1: -1;                          //07-03-28|0x01d4
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-03-28|0x01d5
                                                            _SwitchGroup                  //07-03-28|0x01d5
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-03-28|0x01d6
          return(status);                                                                 //07-03-28|0x01d6
//***************************************************************************             //07-09-18|0x01d7
        case I_STATE_BYTE:                                                                //07-09-18|0x01d8
          TestSample(_STATE_BYTE_1);                                                      //07-09-18|0x01d8
          switch(StringInReg)                               _SwitchGroup                  //07-09-18|0x01d9
          switch(NumResultsIn)                              _SwitchGroup                  //07-09-18|0x01da
          ProcessFlagState = ((ResultNumType & 1) != 0) ? 1: -1;                          //07-09-18|0x01da
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-09-18|0x01db
                                                            _SwitchGroup                  //07-09-18|0x01db
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-09-18|0x01dc
          return(status);                                                                 //07-09-18|0x01dc
//***************************************************************************             //07-09-18|0x01dd
        case I_STATE_INTEGER:                                                             //07-09-18|0x01de
          TestSample(_STATE_INTEGER_1);                                                   //07-09-18|0x01de
          switch(StringInReg)                               _SwitchGroup                  //07-09-18|0x01df
          switch(NumResultsIn)                              _SwitchGroup                  //07-09-18|0x01e0
          ProcessFlagState = ((ResultNumType & 2) != 0) ? 1: -1;                          //07-09-18|0x01e0
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-09-18|0x01e1
                                                            _SwitchGroup                  //07-09-18|0x01e1
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-09-18|0x01e2
          return(status);                                                                 //07-09-18|0x01e2
//***************************************************************************             //07-09-18|0x01e3
        case I_STATE_LONG:                                                                //07-09-18|0x01e4
          TestSample(_STATE_LONG_1);                                                      //07-09-18|0x01e4
          switch(StringInReg)                               _SwitchGroup                  //07-09-18|0x01e5
          switch(NumResultsIn)                              _SwitchGroup                  //07-09-18|0x01e6
          ProcessFlagState = ((ResultNumType & 4) != 0) ? 1: -1;                          //07-09-18|0x01e6
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-09-18|0x01e7
                                                            _SwitchGroup                  //07-09-18|0x01e7
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-09-18|0x01e8
          return(status);                                                                 //07-09-18|0x01e8
//***************************************************************************             //06-11-19|0x01e9
//***************************************************************************             //06-11-19|0x01ea
//******                                                               ******             //06-11-19|0x01eb
//******                   special arithmetic operations               ******             //06-11-19|0x01ec
//******                                                               ******             //06-11-19|0x01ed
//***************************************************************************             //06-11-19|0x01ee
//***************************************************************************             //06-11-19|0x01ef
//******                          In Manual                            ******             //06-11-19|0x01f0
//***************************************************************************             //06-11-19|0x01f1
//***************************************************************************             //06-11-19|0x01f2
        case I_PRIME:                                                                     //07-09-18|0x01f3
          TestSample(_PRIME_1);                                                           //07-09-18|0x01f3
          switch(NumericInData)                             _SwitchGroup                  //07-09-18|0x01f4
          if(ParmNumUlong >= 4096)            ReturnFinish("Prime Error");                //07-09-18|0x01f5
          ResultNumUlong = 0;                                                             //07-09-18|0x01f5
          switch(PrimeGet(&ResultNumWord0,  ParmNumWord0))    _SwitchGroup                //07-09-18|0x01f5
          ResultNumType   = 2;                                                            //07-09-18|0x01f5
          switch(NumericRegOut)                               _SwitchGroup                //07-09-18|0x01f6
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-18|0x01f7
          return(status);                                                                 //07-09-18|0x01f7
//***************************************************************************             //06-11-19|0x01f8
        case I_DECIMAL:                                                                   //06-11-19|0x01f9
          TestSample(_DECIMAL_1);                                                         //06-11-19|0x01f9
          switch(NumericInData)                             _SwitchGroup                  //06-11-19|0x01fa
          sprintf(ResultsLineAddr, "%d", ParmNumUlong);                                   //06-11-19|0x01fb
          if(TruncStringSize(&ResultsLength, ResultsLineAddr) != Success)                 //06-11-19|0x01fb
                                                        ReturnSystemError;                //06-11-19|0x01fb
          ResultsType   = I_NAME;                                                         //06-11-19|0x01fb
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //06-11-19|0x01fc
                                                            _SwitchGroup                  //06-11-19|0x01fc
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-11-19|0x01fd
          return(status);                                                                 //06-11-19|0x01fd
//***************************************************************************             //07-11-05|0x01fe
//***************************************************************************             //07-11-05|0x01ff
//******                                                               ******             //07-11-05|0x0200
//******                      string comparison operations             ******             //07-11-05|0x0201
//******                                                               ******             //07-11-05|0x0202
//***************************************************************************             //07-11-05|0x0203
//***************************************************************************             //07-11-05|0x0204
//******                          In Manual                            ******             //07-11-05|0x0205
//***************************************************************************             //07-11-05|0x0206
//***************************************************************************             //07-11-05|0x0207
        case I_STRING_LESS:                                                               //07-11-05|0x0208
          TestSample(_STRING_LESS_1);                                                     //07-11-05|0x0208
          switch(StringIn2)                                 _SwitchGroup                  //07-11-05|0x0209
          ProcessFlagState = (StringComp < 0) ? 1 : -1;                                   //07-11-05|0x020a
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-11-05|0x020b
                                                            _SwitchGroup                  //07-11-05|0x020b
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-11-05|0x020c
          return(status);                                                                 //07-11-05|0x020c
//***************************************************************************             //06-10-09|0x020d
//***************************************************************************             //06-10-09|0x020e
        case I_STRING_EQUAL:                                                              //06-10-09|0x020f
          TestSample(_STRING_EQUAL_1);                                                    //06-10-09|0x020f
          switch(StringIn2)                                 _SwitchGroup                  //06-10-09|0x0210
          ProcessFlagState = (StringComp == 0) ? 1 : -1;                                  //06-10-09|0x0211
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //06-10-09|0x0212
                                                            _SwitchGroup                  //06-10-09|0x0212
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-10-09|0x0213
          return(status);                                                                 //06-10-09|0x0213
//***************************************************************************             //07-11-05|0x0214
//***************************************************************************             //07-11-05|0x0215
        case I_STRING_GREAT:                                                              //07-11-05|0x0216
          TestSample(_STRING_GREAT_1);                                                    //07-11-05|0x0216
          switch(StringIn2)                                 _SwitchGroup                  //07-11-05|0x0217
          ProcessFlagState = (StringComp > 0) ? 1 : -1;                                   //07-11-05|0x0218
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-11-05|0x0219
                                                            _SwitchGroup                  //07-11-05|0x0219
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-11-05|0x021a
          return(status);                                                                 //07-11-05|0x021a
//***************************************************************************             //06-11-19|0x021b
//***************************************************************************             //06-11-19|0x021c
//******                                                               ******             //06-11-19|0x021d
//******                      string type operations                   ******             //06-11-19|0x021e
//******                                                               ******             //06-11-19|0x021f
//***************************************************************************             //06-11-19|0x0220
//***************************************************************************             //06-11-19|0x0221
//******                          In Manual                            ******             //07-11-05|0x0222
//***************************************************************************             //07-11-05|0x0223
//***************************************************************************             //07-11-05|0x0224
        case I_STATE_STRING:                                                              //06-11-19|0x0225
          TestSample(_STATE_STRING_1);                                                    //06-11-19|0x0225
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-11-19|0x0226
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-11-19|0x0226
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-11-19|0x0226
//---------------------------------------------------------------------------             //06-11-19|0x0227
          if(TokensNoTokens != 2)                       ReturnSystemError;                //06-11-19|0x0228
          switch(PrecformStringTest(TokensTokenAddr(1)))                                  //06-11-19|0x0228
            {                                                                             //06-11-19|0x0228
              case Success:   ProcessFlagState = 1;                 break;                //06-11-19|0x0228
              case UserError: ProcessFlagState = -1;                break;                //06-11-19|0x0228
              default:                                  ReturnSystemError;                //06-11-19|0x0228
              }                                                                           //06-11-19|0x0228
//---------------------------------------------------------------------------             //06-11-19|0x0229
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-11-19|0x022a
          return(status);                                                                 //06-11-19|0x022a
//***************************************************************************             //06-11-19|0x022b
//***************************************************************************             //06-11-19|0x022c
        case I_STATE_NAME:                                                                //06-11-19|0x022d
          TestSample(_STATE_NAME_1);                                                      //06-11-19|0x022d
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-11-19|0x022e
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-11-19|0x022e
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-11-19|0x022e
//---------------------------------------------------------------------------             //06-11-19|0x022f
          if(TokensNoTokens != 2)                       ReturnSystemError;                //06-11-19|0x0230
          switch(PrecformNameTest(TokensTokenAddr(1)))                                    //06-11-19|0x0230
            {                                                                             //06-11-19|0x0230
              case Success:   ProcessFlagState = 1;                 break;                //06-11-19|0x0230
              case UserError: ProcessFlagState = -1;                break;                //06-11-19|0x0230
              default:                                  ReturnSystemError;                //06-11-19|0x0230
              }                                                                           //06-11-19|0x0230
//---------------------------------------------------------------------------             //06-11-19|0x0231
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-11-19|0x0232
          return(status);                                                                 //06-11-19|0x0232
//***************************************************************************             //06-11-19|0x0233
//***************************************************************************             //06-11-19|0x0234
//******                                                               ******             //06-11-19|0x0235
//******                      string operations                        ******             //06-11-19|0x0236
//******                                                               ******             //06-11-19|0x0237
//***************************************************************************             //06-11-19|0x0238
//***************************************************************************             //06-11-19|0x0239
//******                          In Manual                            ******             //07-11-05|0x023a
//***************************************************************************             //07-11-05|0x023b
//***************************************************************************             //07-11-05|0x023c
        case I_STRING_BEFORE:                                                             //07-02-02|0x023d
          TestSample(_STRING_BEFORE_1);                                                   //07-02-02|0x023d
          switch(StringNumIn3(2))                          _SwitchGroup                   //07-02-02|0x023e
          if(ParmNumWord0 == 0)                                                           //07-02-02|0x023f
                             ReturnFinish("_STRING_BEFORE: Empty Results");               //07-02-02|0x023f
          if(ParmNumWord0 > TokensLength(2))                                              //07-02-02|0x023f
                             ReturnFinish("_STRING_BEFORE: Index > Length");              //07-02-02|0x023f
          if(TokensType(2) == I_STRING)                                                   //07-02-02|0x023f
                        ReturnFinish("_STRING_BEFORE: String Type Illegal");              //07-02-02|0x023f
          StringDataCopy(ProcessResultsAddr, TokensTokenAddr(2));                         //07-02-02|0x023f
          ResultsChar(ParmNumWord0)= 0x00;                                                //07-02-02|0x023f
          ResultsLength            = ParmNumWord0;                                        //07-02-02|0x023f
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-02-02|0x0240
                                                            _SwitchGroup                  //07-02-02|0x0240
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-02-02|0x0241
          return(status);                                                                 //07-02-02|0x0241
//***************************************************************************             //07-02-02|0x0242
//***************************************************************************             //07-02-06|0x0243
        case I_STRING_AFTER:                                                              //07-02-06|0x0244
          TestSample(_STRING_AFTER_1);                                                    //07-02-06|0x0244
          switch(StringNumIn3(2))                          _SwitchGroup                   //07-02-06|0x0245
          if(ParmNumWord0 >= TokensLength(2))                                             //07-02-06|0x0246
                           ReturnFinish("_STRING_AFTER: Index >= Length");                //07-02-06|0x0246
          if(TokensType(2) == I_STRING)                                                   //07-02-06|0x0246
                      ReturnFinish("_STRING_AFTERE: String Type Illegal");                //07-02-06|0x0246
          StrCpy(ResultsLineAddr, &TokensChar(2, ParmNumWord0));                          //07-02-06|0x0246
          if(TruncStringSize(&ResultsLength,  ResultsLineAddr) != Success)                //07-02-06|0x0246
                                                        ReturnSystemError;                //07-02-06|0x0246
          ResultsType   = TokensType(2);                                                  //07-02-06|0x0246
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-02-06|0x0247
                                                            _SwitchGroup                  //07-02-06|0x0247
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-02-06|0x0248
          return(status);                                                                 //07-02-06|0x0248
//***************************************************************************             //06-12-12|0x0249
//***************************************************************************             //06-12-12|0x024a
        case I_ASCII_VALUE:                                                               //06-12-12|0x024b
          TestSample(_ASCII_VALUE_1);                                                     //06-12-12|0x024b
          switch(StringNumIn3(2))                          _SwitchGroup                   //06-12-12|0x024c
          if(ParmNumWord0 > TokensLength(2))                                              //06-12-12|0x024d
                              ReturnFinish("_ASCII_VALUE: Index >= Length");              //06-12-12|0x024d
          ResultNumUlong = TokensChar(2, ParmNumWord0);                                   //06-12-12|0x024d
          ResultNumType  = 1;                                                             //06-12-12|0x024d
          switch(NumericRegOut)                               _SwitchGroup                //06-12-12|0x024e
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-12-12|0x024f
          return(status);                                                                 //06-12-12|0x024f
//***************************************************************************             //06-10-05|0x0250
//***************************************************************************             //07-02-06|0x0251
        case I_STATE_CHAR:                                                                //07-02-06|0x0252
          TestSample(_STATE_CHAR_1);                                                      //07-02-06|0x0252
          switch(StringNumIn2)                              _SwitchGroup                  //07-02-06|0x0253
          if(ParmNumType != 1)           ReturnFinish("Not A Byte Value");                //07-02-06|0x0254
          ProcessFlagState = (FindChar2 == 0xffffffff) ? -1 : 1;                          //07-02-06|0x0254
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-02-06|0x0255
          return(status);                                                                 //07-02-06|0x0255
//***************************************************************************             //07-02-06|0x0256
//***************************************************************************             //07-02-02|0x0257
        case I_FIRST_CHAR:                                                                //07-02-02|0x0258
          TestSample(_FIRST_CHAR_1);                                                      //07-02-02|0x0258
          switch(StringNumIn3(2))                          _SwitchGroup                   //07-02-02|0x0259
          if(ParmNumType != 1)             ReturnFinish("Not A Byte Value");              //07-02-02|0x025a
          ResultNumUlong = FindChar3;                                                     //07-02-02|0x025a
          if(ResultNumUlong == 0xffffffff)                                                //07-02-02|0x025a
                                           ReturnFinish("Char Not Found");                //07-02-02|0x025a
          ResultNumUlong %= 0x10000;                                                      //07-02-02|0x025a
          ResultNumType   = 2;                                                            //07-02-02|0x025a
          switch(NumericRegOut)                               _SwitchGroup                //07-02-02|0x025b
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-02-02|0x025c
          return(status);                                                                 //07-02-02|0x025c
//***************************************************************************             //07-02-02|0x025d
//***************************************************************************             //07-11-05|0x025e
        case I_LAST_CHAR:                                                                 //07-11-05|0x025f
          TestSample(_LAST_CHAR_1);                                                       //07-11-05|0x025f
          switch(StringNumIn3(2))                          _SwitchGroup                   //07-11-05|0x0260
          if(ParmNumType != 1)             ReturnFinish("Not A Byte Value");              //07-11-05|0x0261
          ResultNumUlong = FindChar3;                                                     //07-11-05|0x0261
          if(ResultNumUlong == 0xffffffff)                                                //07-11-05|0x0261
                                           ReturnFinish("Char Not Found");                //07-11-05|0x0261
          ResultNumUlong /= 0x10000;                                                      //07-11-05|0x0261
          ResultNumType   = 2;                                                            //07-11-05|0x0261
          switch(NumericRegOut)                               _SwitchGroup                //07-11-05|0x0262
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-11-05|0x0263
          return(status);                                                                 //07-11-05|0x0263
//***************************************************************************             //06-10-05|0x0264
//***************************************************************************             //06-10-05|0x0265
        case I_STRING_LENGTH:                                                             //06-10-05|0x0266
          TestSample(_STRING_LENGTH_1);                                                   //06-10-05|0x0266
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-10-05|0x0267
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //06-10-05|0x0267
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //06-10-05|0x0267
          ResultNumType  = 2;                                                             //06-10-05|0x0268
          if(TokensChar(2, 256) != 0)                    ReturnSystemError                //06-10-05|0x0268
          ResultNumUlong = StrLen(TokensLineAddr(2));                                     //06-10-05|0x0268
          if(ResultNumWord0 != TokensLength(2))          ReturnSystemError                //06-10-05|0x0268
          switch(NumericRegOut)                               _SwitchGroup                //06-10-05|0x0269
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-10-05|0x026a
          return(status);                                                                 //06-10-05|0x026a
//***************************************************************************             //06-09-28|0x026b
//***************************************************************************             //06-09-28|0x026c
        case I_LEAD_BLANKS:                                                               //07-02-07|0x026d
          TestSample(_LEAD_BLANKS_1);                                                     //07-02-07|0x026d
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //07-02-07|0x026e
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //07-02-07|0x026e
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //07-02-07|0x026e
            ResultNumUlong  = 0;                                                          //07-02-07|0x026f
            ResultNumType  = 2;                                                           //07-02-07|0x026f
            while(ResultNumWord0 < TokensLength(2))                                       //07-02-07|0x026f
              {                                                                           //07-02-07|0x026f
                if(TokensChar(2, ResultNumWord0) != 0x20)             break;              //07-02-07|0x026f
                ++ResultNumWord0;                                                         //07-02-07|0x026f
                }                                                                         //07-02-07|0x026f
          switch(NumericRegOut)                               _SwitchGroup                //07-02-07|0x0270
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-02-07|0x0271
          return(status);                                                                 //07-02-07|0x0271
//***************************************************************************             //06-10-05|0x0272
//***************************************************************************             //06-10-05|0x0273
        case I_BLANKS:                                                                    //06-10-05|0x0274
          TestSample(_BLANKS_1);                                                          //06-10-05|0x0274
          switch(NumericInData)                             _SwitchGroup                  //06-10-05|0x0275
          if(ParmNumUlong >  255)         ReturnFinish("Too many blanks");                //06-10-05|0x0276
          if(ParmNumUlong == 0)           ReturnFinish("Zero blanks");                    //06-10-05|0x0276
          MemSet(ResultsLineAddr, 0x20, ParmNumWord0);                                    //06-10-05|0x0276
          ResultsType   = I_TOKEN;                                                        //06-10-05|0x0276
          if(ResultsChar(256)    != 0)                   ReturnSystemError                //06-10-05|0x0276
          if(TruncStringSize(&ResultsLength,  ResultsLineAddr) != Success)                //06-10-05|0x0276
                                                        ReturnSystemError;                //06-10-05|0x0276
          if(ResultsLength != ParmNumWord0)              ReturnSystemError                //06-10-05|0x0276
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //06-10-05|0x0277
                                                            _SwitchGroup                  //06-10-05|0x0277
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-10-05|0x0278
          return(status);                                                                 //06-10-05|0x0278
//***************************************************************************             //06-10-04|0x0279
//***************************************************************************             //06-10-04|0x027a
        case I_START_COL:                                                                 //06-10-04|0x027b
          TestSample(_START_COL_1);                                                       //06-10-04|0x027b
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-10-04|0x027c
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //06-10-04|0x027c
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //06-10-04|0x027c
            ResultNumType  = 2;                                                           //06-10-04|0x027d
            ResultNumUlong =  TokensStartCol(2);                                          //06-10-04|0x027d
          switch(NumericRegOut)                               _SwitchGroup                //06-10-04|0x027e
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-10-04|0x027f
          return(status);                                                                 //06-10-04|0x027f
//***************************************************************************             //07-02-02|0x0280
//***************************************************************************             //07-02-02|0x0281
//******                                                               ******             //06-09-28|0x0282
//******                      dictionary operations                    ******             //06-09-28|0x0283
//******                                                               ******             //06-09-28|0x0284
//***************************************************************************             //06-09-28|0x0285
//***************************************************************************             //06-09-28|0x0286
//******                          In Manual                            ******             //07-09-13|0x0287
//***************************************************************************             //06-10-05|0x0288
//***************************************************************************             //06-10-05|0x0289
        case I_LOAD_DICT:                                                                 //06-09-29|0x028a
          TestSample(_LOAD_DICT_1);                                                       //06-09-29|0x028a
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-29|0x028b
          if(TokensNoTokens >  10)                   ReturnSystemError;                   //06-09-29|0x028b
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-29|0x028b
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-29|0x028c
          switch(DictIn(1))                                 _SwitchGroup                  //06-09-29|0x028c
          switch(DictAddEntry)                              _SwitchGroup                  //06-09-29|0x028c
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-29|0x028d
          return(status);                                                                 //06-09-29|0x028d
//***************************************************************************             //06-11-08|0x028e
        case I_LOAD_SUBDICT:                                                              //06-11-08|0x028f
          TestSample(_LOAD_SUBDICT_1);                                                    //06-11-08|0x028f
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-11-08|0x0290
          if(TokensNoTokens >  10)                   ReturnSystemError;                   //06-11-08|0x0290
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-11-08|0x0290
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-11-08|0x0291
          switch(DictIn(1))                                 _SwitchGroup                  //06-11-08|0x0291
          switch(DictAddSub)                                _SwitchGroup                  //06-11-08|0x0291
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-11-08|0x0292
          return(status);                                                                 //06-11-08|0x0292
//***************************************************************************             //06-09-29|0x0293
//***************************************************************************             //06-09-29|0x0294
        case I_RELOAD_DICT:                                                               //06-12-22|0x0295
          TestSample(_RELOAD_DICT_1);                                                     //06-12-22|0x0295
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-29|0x0296
          if(TokensNoTokens >  10)                   ReturnSystemError;                   //06-09-29|0x0296
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-29|0x0296
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-29|0x0297
          switch(DictIn(1))                                 _SwitchGroup                  //06-09-29|0x0297
          switch(DictUpdateEntry)                           _SwitchGroup                  //06-09-29|0x0297
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-09-29|0x0298
          return(status);                                                                 //06-09-29|0x0298
//***************************************************************************             //06-11-08|0x0299
        case I_RELOAD_SUBDICT:                                                            //06-11-08|0x029a
          TestSample(_RELOAD_SUBDICT_1);                                                  //06-11-08|0x029a
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-11-08|0x029b
          if(TokensNoTokens >  10)                   ReturnSystemError;                   //06-11-08|0x029b
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-11-08|0x029b
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-11-08|0x029c
          switch(DictIn(1))                                 _SwitchGroup                  //06-11-08|0x029c
          switch(DictUpdateSub)                             _SwitchGroup                  //06-11-08|0x029c
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-11-08|0x029d
          return(status);                                                                 //06-11-08|0x029d
//***************************************************************************             //06-09-29|0x029e
//***************************************************************************             //06-09-29|0x029f
        case I_GET_DICT:                                                                  //06-12-22|0x02a0
          TestSample(_GET_DICT_1);                                                        //06-12-22|0x02a0
          switch(StringNumIn3(2))                          _SwitchGroup                   //06-09-29|0x02a1
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-11-08|0x02a2
          switch(DictIn(2))                                 _SwitchGroup                  //06-11-08|0x02a2
          switch(DictGetData)                               _SwitchGroup                  //06-11-08|0x02a2
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //06-09-29|0x02a3
                                                            _SwitchGroup                  //06-09-29|0x02a3
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-09-29|0x02a4
          return(status);                                                                 //06-09-29|0x02a4
//***************************************************************************             //06-11-08|0x02a5
        case I_GET_SUBDICT:                                                               //06-11-08|0x02a6
          TestSample(_GET_SUBDICT_1);                                                     //06-11-08|0x02a6
          switch(StringNumIn4)                              _SwitchGroup                  //06-11-08|0x02a7
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-11-08|0x02a8
          switch(DictIn(2))                                 _SwitchGroup                  //06-11-08|0x02a8
          switch(DictGetSub)                                _SwitchGroup                  //06-11-08|0x02a8
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //06-11-08|0x02a9
                                                            _SwitchGroup                  //06-11-08|0x02a9
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-11-08|0x02aa
          return(status);                                                                 //06-11-08|0x02aa
//***************************************************************************             //06-09-28|0x02ab
//***************************************************************************             //06-09-28|0x02ac
        case I_STATE_DICT:                                                                //06-09-28|0x02ad
          TestSample(_STATE_DICT_1);                                                      //06-09-28|0x02ad
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-09-28|0x02ae
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-09-28|0x02ae
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-09-28|0x02ae
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-09-28|0x02af
          switch(DictIn(1))                                 _SwitchGroup                  //06-09-28|0x02af
          switch(DictExists)                                                              //06-09-28|0x02af
            {                                                                             //06-09-28|0x02af
              case  Yes:  ProcessFlagState =  1;                  break;                  //06-09-28|0x02af
              case  No:   ProcessFlagState = -1;                  break;                  //06-09-28|0x02af
              default:                                ReturnSystemError;                  //06-09-28|0x02af
              }                                                                           //06-09-28|0x02af
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-09-28|0x02b0
          return(status);                                                                 //06-09-28|0x02b0
//***************************************************************************             //06-11-08|0x02b1
        case I_STATE_SUBDICT:                                                             //06-11-08|0x02b2
          TestSample(_STATE_SUBDICT_1);                                                   //06-11-08|0x02b2
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-11-08|0x02b3
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //06-11-08|0x02b3
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-11-08|0x02b3
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-11-08|0x02b4
          switch(DictIn(1))                                 _SwitchGroup                  //06-11-08|0x02b4
          switch(SubDictExists)                                                           //06-11-08|0x02b4
            {                                                                             //06-11-08|0x02b4
              case  Yes:  ProcessFlagState =  1;                  break;                  //06-11-08|0x02b4
              case  No:   ProcessFlagState = -1;                  break;                  //06-11-08|0x02b4
              case  UserError:                        return(UserError);                  //06-11-08|0x02b4
              default:                                ReturnSystemError;                  //06-11-08|0x02b4
              }                                                                           //06-11-08|0x02b4
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-11-08|0x02b5
          return(status);                                                                 //06-11-08|0x02b5
//***************************************************************************             //06-11-08|0x02b6
//***************************************************************************             //06-11-08|0x02b7
        case I_STATE_DICT_GET:                                                            //07-02-03|0x02b8
          TestSample(_STATE_DICT_GET_1);                                                  //07-02-03|0x02b8
          switch(StringNumIn2)                              _SwitchGroup                  //07-02-03|0x02b9
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-02-03|0x02ba
          switch(DictIn(1))                                 _SwitchGroup                  //07-02-03|0x02ba
          switch(DictDataExists)                                                          //07-02-03|0x02ba
            {                                                                             //07-02-03|0x02ba
              case  Yes:  ProcessFlagState =  1;                  break;                  //07-02-03|0x02ba
              case  No:   ProcessFlagState = -1;                  break;                  //07-02-03|0x02ba
              case  UserError:                        return(UserError);                  //07-02-03|0x02ba
              default:                                ReturnSystemError;                  //07-02-03|0x02ba
              }                                                                           //07-02-03|0x02ba
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-02-03|0x02bb
          return(status);                                                                 //07-02-03|0x02bb
//***************************************************************************             //06-11-08|0x02bc
        case I_STATE_SUBDICT_GET:                                                         //06-11-08|0x02bd
          TestSample(_STATE_SUBDICT_GET_1);                                               //06-11-08|0x02bd
          switch(StringNumIn3(1))                          _SwitchGroup                   //06-11-08|0x02be
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //06-11-08|0x02bf
          switch(DictIn(1))                                 _SwitchGroup                  //06-11-08|0x02bf
          switch(SubDataExists)                                                           //06-11-08|0x02bf
            {                                                                             //06-11-08|0x02bf
              case  Yes:  ProcessFlagState =  1;                  break;                  //06-11-08|0x02bf
              case  No:   ProcessFlagState = -1;                  break;                  //06-11-08|0x02bf
              case  UserError:                        return(UserError);                  //06-11-08|0x02bf
              default:                                ReturnSystemError;                  //06-11-08|0x02bf
              }                                                                           //06-11-08|0x02bf
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //06-11-08|0x02c0
          return(status);                                                                 //06-11-08|0x02c0
//***************************************************************************             //07-11-05|0x02c1
//***************************************************************************             //07-11-05|0x02c2
//******                                                               ******             //07-11-05|0x02c3
//******                        mail box operations                    ******             //07-11-05|0x02c4
//******                                                               ******             //07-11-05|0x02c5
//***************************************************************************             //07-11-05|0x02c6
//***************************************************************************             //07-11-05|0x02c7
//******                          In Manual                            ******             //07-12-05|0x02c8
//***************************************************************************             //07-12-05|0x02c9
//***************************************************************************             //07-12-05|0x02ca
        case I_GET_POSTOFFICE_NO:                                                         //09-06-02|0x02cb
          TestSample(_GET_POSTOFFICE_NO_1);                                               //09-06-02|0x02cb
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //09-06-02|0x02cc
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //09-06-02|0x02cc
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //09-06-02|0x02cc
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-06-02|0x02cd
          switch(MailGetFileNo)                             _SwitchGroup                  //09-06-02|0x02cd
          switch(NumericRegOut)                               _SwitchGroup                //09-06-02|0x02ce
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //09-06-02|0x02cf
          return(status);                                                                 //09-06-02|0x02cf
//***************************************************************************             //07-12-05|0x02d0
//***************************************************************************             //07-12-05|0x02d1
        case I_DELETE_POSTOFFICE:                                                         //09-03-11|0x02d2
          TestSample(_DELETE_POSTOFFICE_1);                                               //09-03-11|0x02d2
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-11|0x02d3
          switch(MailDelete)                                _SwitchGroup                  //09-03-11|0x02d3
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //09-03-11|0x02d4
          return(status);                                                                 //09-03-11|0x02d4
//***************************************************************************             //07-12-05|0x02d5
//***************************************************************************             //07-12-05|0x02d6
        case I_OPEN_POSTOFFICE:                                                           //09-03-10|0x02d7
          TestSample(_OPEN_POSTOFFICE_1);                                                 //09-03-10|0x02d7
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-10|0x02d8
          switch(MailOpen)                                  _SwitchGroup                  //09-03-10|0x02d8
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //09-03-10|0x02d9
          return(status);                                                                 //09-03-10|0x02d9
//***************************************************************************             //07-12-05|0x02da
        case I_CREATE_POSTOFFICE:                                                         //09-03-27|0x02db
          TestSample(_CREATE_POSTOFFICE_1);                                               //09-03-27|0x02db
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-10|0x02dc
          switch(MailAddZip)                                _SwitchGroup                  //09-03-10|0x02dc
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-11-05|0x02dd
          return(status);                                                                 //07-11-05|0x02dd
//***************************************************************************             //07-11-05|0x02de
        case I_CREATE_PO_BOX:                                                             //07-11-05|0x02df
          TestSample(_CREATE_PO_BOX_1);                                                   //07-11-05|0x02df
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-11|0x02e0
          switch(MailAddPOBox)                              _SwitchGroup                  //09-03-11|0x02e0
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-11-05|0x02e1
          return(status);                                                                 //07-11-05|0x02e1
//***************************************************************************             //07-11-05|0x02e2
//***************************************************************************             //07-11-05|0x02e3
        case I_SEND_MAIL:                                                                 //07-11-05|0x02e4
          TestSample(_SEND_MAIL_1);                                                       //07-11-05|0x02e4
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-13|0x02e5
          switch(MailLoadPOBox)                             _SwitchGroup                  //09-03-13|0x02e5
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-11-05|0x02e6
          return(status);                                                                 //07-11-05|0x02e6
//***************************************************************************             //07-11-05|0x02e7
        case I_EMPTY_PO_BOX:                                                              //09-09-17|0x02e8
          TestSample(_EMPTY_PO_BOX_1);                                                    //09-09-17|0x02e8
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-09-17|0x02e9
          switch(MailEmptyPOBox)                            _SwitchGroup                  //09-09-17|0x02e9
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //09-09-17|0x02ea
          return(status);                                                                 //09-09-17|0x02ea
//***************************************************************************             //07-11-05|0x02eb
//***************************************************************************             //07-11-05|0x02ec
        case I_GET_MAIL:                                                                  //07-11-05|0x02ed
          TestSample(_GET_MAIL_1);                                                        //07-11-05|0x02ed
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-14|0x02ee
          switch(MailGet)                                   _SwitchGroup                  //09-03-14|0x02ee
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-11-05|0x02ef
                                                            _SwitchGroup                  //07-11-05|0x02ef
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-11-05|0x02f0
          return(status);                                                                 //07-11-05|0x02f0
//***************************************************************************             //07-11-05|0x02f1
//***************************************************************************             //07-11-05|0x02f2
        case I_POSTOFFICE_EXISTS:                                                         //07-11-05|0x02f3
          TestSample(_POSTOFFICE_EXISTS_1);                                               //07-11-05|0x02f3
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-17|0x02f4
          switch(MailZipExists)                                                           //09-03-17|0x02f4
            {                                                                             //09-03-17|0x02f4
              case  Yes:  ProcessFlagState =  1;                  break;                  //09-03-17|0x02f4
              case  No:   ProcessFlagState = -1;                  break;                  //09-03-17|0x02f4
              case  UserError:                        return(UserError);                  //09-03-17|0x02f4
              default:                                ReturnSystemError;                  //09-03-17|0x02f4
              }                                                                           //09-03-17|0x02f4
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-11-05|0x02f5
          return(status);                                                                 //07-11-05|0x02f5
//***************************************************************************             //07-11-05|0x02f6
        case I_PO_BOX_EXISTS:                                                             //07-11-05|0x02f7
          TestSample(_PO_BOX_EXISTS_1);                                                   //07-11-05|0x02f7
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-17|0x02f8
          switch(MailPOBoxExists)                                                         //09-03-17|0x02f8
            {                                                                             //09-03-17|0x02f8
              case  Yes:  ProcessFlagState =  1;                  break;                  //09-03-17|0x02f8
              case  No:   ProcessFlagState = -1;                  break;                  //09-03-17|0x02f8
              case  UserError:                        return(UserError);                  //09-03-17|0x02f8
              default:                                ReturnSystemError;                  //09-03-17|0x02f8
              }                                                                           //09-03-17|0x02f8
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-11-05|0x02f9
          return(status);                                                                 //07-11-05|0x02f9
//***************************************************************************             //07-11-05|0x02fa
        case I_PO_BOX_EMPTY:                                                              //07-11-05|0x02fb
          TestSample(_PO_BOX_EMPTY_1);                                                    //07-11-05|0x02fb
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-17|0x02fc
          switch(MailTestMail)                                                            //09-03-17|0x02fc
            {                                                                             //09-03-17|0x02fc
              case  Yes:  ProcessFlagState =  1;                  break;                  //09-03-17|0x02fc
              case  No:   ProcessFlagState = -1;                  break;                  //09-03-17|0x02fc
              case  UserError:                        return(UserError);                  //09-03-17|0x02fc
              default:                                ReturnSystemError;                  //09-03-17|0x02fc
              }                                                                           //09-03-17|0x02fc
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-11-05|0x02fd
          return(status);                                                                 //07-11-05|0x02fd
//***************************************************************************             //07-11-05|0x02fe
//***************************************************************************             //07-11-05|0x02ff
        case I_CLOSE_POSTOFFICE:                                                          //09-03-11|0x0300
          TestSample(_CLOSE_POSTOFFICE_1);                                                //09-03-11|0x0300
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //09-03-11|0x0301
          switch(MailClose)                                 _SwitchGroup                  //09-03-11|0x0301
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //09-03-11|0x0302
          return(status);                                                                 //09-03-11|0x0302
//***************************************************************************             //06-10-05|0x0303
//***************************************************************************             //06-10-05|0x0304
//******                                                               ******             //06-10-05|0x0305
//******                    Output file operations                     ******             //06-10-05|0x0306
//******                                                               ******             //06-10-05|0x0307
//***************************************************************************             //07-09-13|0x0308
//***************************************************************************             //07-09-13|0x0309
        case I_NO_OUT_FILES:                                                              //07-09-11|0x030a
          TestSample(_NO_OUT_FILES_1);                                                    //07-09-11|0x030a
          if(TokensNoTokens != 2)                    ReturnSystemError;                   //07-09-11|0x030b
          ResultNumUlong = FileOutNoFiles;                                                //07-09-11|0x030b
          if(ResultNumUlong >= 16)                   ReturnSystemError;                   //07-09-11|0x030b
          ResultNumType = 2;                                                              //07-09-11|0x030b
          switch(NumericRegOut)                               _SwitchGroup                //07-09-11|0x030c
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-11|0x030d
          return(status);                                                                 //07-09-11|0x030d
//***************************************************************************             //07-02-02|0x030e
        case I_WRITE_OUT:                                                                 //06-10-05|0x030f
          TestSample(_WRITE_OUT_1);                                                       //06-10-05|0x030f
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //06-10-05|0x0310
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //06-10-05|0x0310
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-10-05|0x0310
          switch(NumTextIn(1))                             _SwitchGroup                   //06-10-05|0x0311
          if(ParmNumType  == 0)                                                           //06-10-05|0x0311
                              ReturnFinish("Illegal Output File Index");                  //06-10-05|0x0311
          if(ParmNumUlong >= FileOutNoFiles)                                              //06-10-05|0x0311
                             ReturnFinish("Illegal Output File Number");                  //06-10-05|0x0311
          switch(WriteOut)                                  _SwitchGroup                  //06-10-05|0x0312
          if(FileOutStatus(ParmNumUlong) > 2)         ReturnSystemError;                  //06-10-05|0x0312
          FileOutStatus(ParmNumUlong) = 1;                                                //06-10-05|0x0312
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-10-05|0x0313
          return(status);                                                                 //06-10-05|0x0313
//***************************************************************************             //13-07-25|0x0314
        case I_WRITE_SEGMENT:                                                             //13-07-25|0x0315
          TestSample(_WRITE_SEGMENT_1);                                                   //13-07-25|0x0315
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //13-07-25|0x0316
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //13-07-25|0x0316
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //13-07-25|0x0316
          switch(NumTextIn(1))                             _SwitchGroup                   //13-07-25|0x0317
          if(ParmNumType  == 0)                                                           //13-07-25|0x0317
                              ReturnFinish("Illegal Output File Index");                  //13-07-25|0x0317
          if(ParmNumUlong >= FileOutNoFiles)                                              //13-07-25|0x0317
                             ReturnFinish("Illegal Output File Number");                  //13-07-25|0x0317
          if(TokensNoTokens != 3)                    ReturnSystemError;                   //13-07-25|0x0318
          switch(                                                                         //13-07-25|0x0318
              segment_out(ProcessDataFar, ProcessFilesFar, ParmNumWord0)                  //13-07-25|0x0318
              )                                            _SwitchGroup                   //13-07-25|0x0318
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //13-07-25|0x0319
          return(status);                                                                 //13-07-25|0x0319
//***************************************************************************             //07-02-03|0x031a
        case I_LOAD_BUFFER:                                                               //07-02-03|0x031b
          TestSample(_LOAD_BUFFER_1);                                                     //07-02-03|0x031b
          switch(LoadBuffer)                                _SwitchGroup                  //07-02-03|0x031c
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-02-03|0x031d
          return(status);                                                                 //07-02-03|0x031d
//***************************************************************************             //07-02-03|0x031e
        case I_APPEND_BUFFER:                                                             //07-09-11|0x031f
          TestSample(_APPEND_BUFFER_1);                                                   //07-09-11|0x031f
          switch(AppendBuffer)                              _SwitchGroup                  //07-09-11|0x0320
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-09-11|0x0321
          return(status);                                                                 //07-09-11|0x0321
//***************************************************************************             //07-02-03|0x0322
        case I_WRITE_BUFFER:                                                              //07-02-03|0x0323
          TestSample(_WRITE_BUFFER_1);                                                    //07-02-03|0x0323
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //07-02-03|0x0324
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //07-02-03|0x0324
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //07-02-03|0x0324
          switch(NumTextIn(1))                             _SwitchGroup                   //07-02-03|0x0325
          if(ParmNumType  == 0)                                                           //07-02-03|0x0325
                              ReturnFinish("Illegal Output File Index");                  //07-02-03|0x0325
          if(ParmNumUlong >= FileOutNoFiles)                                              //07-02-03|0x0325
                             ReturnFinish("Illegal Output File Number");                  //07-02-03|0x0325
          switch(WriteBuffer)                               _SwitchGroup                  //07-02-03|0x0326
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //07-02-03|0x0327
          return(status);                                                                 //07-02-03|0x0327
//***************************************************************************             //07-09-11|0x0328
        case I_OUT_BASE_NAME:                                                             //08-01-14|0x0329
          TestSample(_OUT_BASE_NAME_1);                                                   //08-01-14|0x0329
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //08-01-14|0x032a
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //08-01-14|0x032a
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //08-01-14|0x032a
          if(FileName(FileOutName) == 0)                                                  //08-01-14|0x032b
                                                      ReturnSystemError;                  //08-01-14|0x032b
          ResultsType   = I_TOKEN;                                                        //08-01-14|0x032b
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //08-01-14|0x032b
          ResultNumUlong = strlen(FileOutName);                                           //08-01-14|0x032b
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //08-01-14|0x032b
                                                      ReturnSystemError;                  //08-01-14|0x032b
          ResultsLength = ResultNumWord0;                                                 //08-01-14|0x032b
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //08-01-14|0x032c
                                                            _SwitchGroup                  //08-01-14|0x032c
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //08-01-14|0x032d
          return(status);                                                                 //08-01-14|0x032d
//***************************************************************************             //08-01-14|0x032e
        case I_OUT_NAME:                                                                  //08-01-14|0x032f
          TestSample(_OUT_NAME_1);                                                        //08-01-14|0x032f
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //08-01-14|0x0330
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //08-01-14|0x0330
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //08-01-14|0x0330
          switch(NumTextIn(2))                             _SwitchGroup                   //08-01-14|0x0331
          if(ParmNumType  == 0)                                                           //08-01-14|0x0331
                              ReturnFinish("Illegal Output File Index");                  //08-01-14|0x0331
          if(ParmNumUlong >= FileOutNoFiles)                                              //08-01-14|0x0331
                             ReturnFinish("Illegal Output File Number");                  //08-01-14|0x0331
          if(FileName(FileOutFileName(ParmNumUlong)) == 0)                                //08-01-14|0x0332
                                                      ReturnSystemError;                  //08-01-14|0x0332
          ResultsType   = I_TOKEN;                                                        //08-01-14|0x0332
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //08-01-14|0x0332
          ResultNumUlong = strlen(FileOutFileName(ParmNumUlong));                         //08-01-14|0x0332
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //08-01-14|0x0332
                                                      ReturnSystemError;                  //08-01-14|0x0332
          ResultsLength = ResultNumWord0;                                                 //08-01-14|0x0332
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //08-01-14|0x0333
                                                            _SwitchGroup                  //08-01-14|0x0333
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //08-01-14|0x0334
          return(status);                                                                 //08-01-14|0x0334
//***************************************************************************             //08-01-14|0x0335
        case I_OUT_PATH:                                                                  //08-01-14|0x0336
          TestSample(_OUT_PATH_1);                                                        //08-01-14|0x0336
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //08-01-14|0x0337
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //08-01-14|0x0337
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //08-01-14|0x0337
          switch(NumTextIn(2))                             _SwitchGroup                   //08-01-14|0x0338
          if(ParmNumType  == 0)                                                           //08-01-14|0x0338
                              ReturnFinish("Illegal Output File Index");                  //08-01-14|0x0338
          if(ParmNumUlong >= FileOutNoFiles)                                              //08-01-14|0x0338
                             ReturnFinish("Illegal Output File Number");                  //08-01-14|0x0338
          if(FileName(FileOutPath(ParmNumUlong)) == 0)                                    //08-01-14|0x0339
                                                      ReturnSystemError;                  //08-01-14|0x0339
          ResultsType   = I_TOKEN;                                                        //08-01-14|0x0339
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //08-01-14|0x0339
          ResultNumUlong = strlen(FileOutPath(ParmNumUlong));                             //08-01-14|0x0339
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //08-01-14|0x0339
                                                      ReturnSystemError;                  //08-01-14|0x0339
          ResultsLength = ResultNumWord0;                                                 //08-01-14|0x0339
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //08-01-14|0x033a
                                                            _SwitchGroup                  //08-01-14|0x033a
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //08-01-14|0x033b
          return(status);                                                                 //08-01-14|0x033b
//***************************************************************************             //08-01-14|0x033c
        case I_OUT_EXTENT:                                                                //08-01-14|0x033d
          TestSample(_OUT_EXTENT_1);                                                      //08-01-14|0x033d
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //08-01-14|0x033e
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //08-01-14|0x033e
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //08-01-14|0x033e
          switch(NumTextIn(2))                             _SwitchGroup                   //08-01-14|0x033f
          if(ParmNumType  == 0)                                                           //08-01-14|0x033f
                              ReturnFinish("Illegal Output File Index");                  //08-01-14|0x033f
          if(ParmNumUlong >= FileOutNoFiles)                                              //08-01-14|0x033f
                             ReturnFinish("Illegal Output File Number");                  //08-01-14|0x033f
          if(FileName(FileOutExtent(ParmNumUlong)) == 0)                                  //08-01-14|0x0340
                                                      ReturnSystemError;                  //08-01-14|0x0340
          ResultsType   = I_TOKEN;                                                        //08-01-14|0x0340
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //08-01-14|0x0340
          ResultNumUlong = strlen(FileOutExtent(ParmNumUlong));                           //08-01-14|0x0340
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //08-01-14|0x0340
                                                      ReturnSystemError;                  //08-01-14|0x0340
          ResultsLength = ResultNumWord0;                                                 //08-01-14|0x0340
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //08-01-14|0x0341
                                                            _SwitchGroup                  //08-01-14|0x0341
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //08-01-14|0x0342
          return(status);                                                                 //08-01-14|0x0342
//***************************************************************************             //06-10-05|0x0343
        case I_OUT_LINE_NO:                                                               //07-09-11|0x0344
          TestSample(_OUT_LINE_NO_1);                                                     //07-09-11|0x0344
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //07-09-11|0x0345
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //07-09-11|0x0345
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //07-09-11|0x0345
          switch(NumTextIn(2))                             _SwitchGroup                   //07-09-11|0x0346
          if(ParmNumType  == 0)                                                           //07-09-11|0x0346
                              ReturnFinish("Illegal Output File Index");                  //07-09-11|0x0346
          if(ParmNumUlong >= FileOutNoFiles)                                              //07-09-11|0x0346
                             ReturnFinish("Illegal Output File Number");                  //07-09-11|0x0346
          ResultNumUlong = FileOutLineNo(ParmNumUlong);                                   //07-09-11|0x0347
          if(ResultNumUlong >= 0x10000)              ReturnSystemError;                   //07-09-11|0x0347
          ResultNumType = 2;                                                              //07-09-11|0x0347
          switch(NumericRegOut)                               _SwitchGroup                //07-09-11|0x0348
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-11|0x0349
          return(status);                                                                 //07-09-11|0x0349
//***************************************************************************             //06-10-03|0x034a
//***************************************************************************             //06-10-05|0x034b
//******                                                               ******             //06-10-05|0x034c
//******                     Input Source file operations              ******             //06-10-05|0x034d
//******                                                               ******             //06-10-05|0x034e
//***************************************************************************             //07-09-13|0x034f
//***************************************************************************             //07-09-13|0x0350
//******                          In Manual                            ******             //07-09-13|0x0351
//***************************************************************************             //06-10-05|0x0352
//***************************************************************************             //06-10-05|0x0353
        case I_SOURCE_LINE_NO:                                                            //06-10-03|0x0354
          TestSample(_SOURCE_LINE_NO_1);                                                  //06-10-03|0x0354
          if(TokensNoTokens != 2)                    ReturnSystemError;                   //06-10-03|0x0355
          ResultNumUlong = FileSrcLineNo;                                                 //06-10-03|0x0355
          if(ResultNumUlong >= 0x10000)              ReturnSystemError;                   //06-10-03|0x0355
          ResultNumType = 2;                                                              //06-10-03|0x0355
          switch(NumericRegOut)                               _SwitchGroup                //06-10-03|0x0356
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-10-03|0x0357
          return(status);                                                                 //06-10-03|0x0357
//***************************************************************************             //06-10-03|0x0358
        case I_SOURCE_NAME:                                                               //07-09-19|0x0359
          TestSample(_SOURCE_NAME_1);                                                     //07-09-19|0x0359
          if(TokensNoTokens             != 2)         ReturnSystemError;                  //07-09-19|0x035a
          if(FileName(FileSrcFileName)  == 0)                                             //07-09-19|0x035a
                                                      ReturnSystemError;                  //07-09-19|0x035a
          ResultsType   = I_TOKEN;                                                        //07-09-19|0x035a
          if(ResultsChar(256)           != 0)         ReturnSystemError;                  //07-09-19|0x035a
          ResultNumUlong = strlen(FileSrcFileName);                                       //07-09-19|0x035a
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //07-09-19|0x035a
                                                      ReturnSystemError;                  //07-09-19|0x035a
          ResultsLength = ResultNumWord0;                                                 //07-09-19|0x035a
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-09-19|0x035b
                                                            _SwitchGroup                  //07-09-19|0x035b
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-09-19|0x035c
          return(status);                                                                 //07-09-19|0x035c
//***************************************************************************             //10-03-22|0x035d
//***************************************************************************             //10-03-22|0x035e
//******                                                               ******             //10-03-22|0x035f
//******                     Cryptographic operations                  ******             //10-03-22|0x0360
//******                                                               ******             //10-03-22|0x0361
//***************************************************************************             //10-03-22|0x0362
//***************************************************************************             //10-03-22|0x0363
//******                                                               ******             //10-03-22|0x0364
//***************************************************************************             //10-03-22|0x0365
//***************************************************************************             //10-03-22|0x0366
        case I_CREATE_RANDOM:                                                             //10-03-22|0x0367
          TestSample(_CREATE_RANDOM_1);                                                   //10-03-22|0x0367
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-22|0x0368
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //10-03-22|0x0368
          ResultNumUlong = 0;                                                             //10-03-22|0x0368
          ResultNumType  = 2;                                                             //10-03-22|0x0368
          switch(CreateRandom)                                        _SwitchGroup        //10-03-22|0x0368
          switch(NumericRegOut)                               _SwitchGroup                //10-03-22|0x0369
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-03-22|0x036a
          return(status);                                                                 //10-03-22|0x036a
//***************************************************************************             //10-03-22|0x036b
        case I_RESET_RANDOM:                                                              //10-03-23|0x036c
          TestSample(_RESET_RANDOM_1);                                                    //10-03-23|0x036c
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-23|0x036d
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //10-03-23|0x036d
          switch(TokensPrepare(ProcessTokensAddr, 1))       _SwitchGroup                  //10-03-23|0x036d
          switch(NumTextIn(1))                              _SwitchGroup                  //10-03-23|0x036d
          if(ParmNumType == 0)        ReturnFinish("Numeric Conersion");                  //10-03-23|0x036d
          switch(ResetRandom)                                        _SwitchGroup         //10-03-23|0x036d
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-23|0x036e
          return(status);                                                                 //10-03-23|0x036e
//***************************************************************************             //10-03-22|0x036f
        case I_OPEN_RANDOM:                                                               //10-03-22|0x0370
          TestSample(_OPEN_RANDOM_1);                                                     //10-03-22|0x0370
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-22|0x0371
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //10-03-22|0x0371
          switch(TokensPrepare(ProcessTokensAddr, 1))       _SwitchGroup                  //10-03-22|0x0371
          switch(NumTextIn(1))                              _SwitchGroup                  //10-03-22|0x0371
          if(ParmNumType == 0)        ReturnFinish("Numeric Conersion");                  //10-03-22|0x0371
          switch(OpenRandom)                                        _SwitchGroup          //10-03-22|0x0371
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-22|0x0372
          return(status);                                                                 //10-03-22|0x0372
//***************************************************************************             //10-03-22|0x0373
        case I_CLOSE_RANDOM:                                                              //10-03-22|0x0374
          TestSample(_CLOSE_RANDOM_1);                                                    //10-03-22|0x0374
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-22|0x0375
          if(TokensNoTokens   != 1)                    ReturnSystemError                  //10-03-22|0x0375
          switch(CryptoClose())                             _SwitchGroup                  //10-03-22|0x0375
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-22|0x0376
          return(status);                                                                 //10-03-22|0x0376
//***************************************************************************             //10-03-22|0x0377
//***************************************************************************             //10-03-22|0x0378
        case I_LOAD_RANDOM:                                                               //10-03-22|0x0379
          TestSample(_LOAD_RANDOM_1);                                                     //10-03-22|0x0379
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-22|0x037a
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //10-03-22|0x037a
          switch(TokensPrepare(ProcessTokensAddr, 1))       _SwitchGroup                  //10-03-22|0x037a
          switch(LoadRandom)                                        _SwitchGroup          //10-03-22|0x037a
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-22|0x037b
          return(status);                                                                 //10-03-22|0x037b
//***************************************************************************             //10-03-23|0x037c
        case I_GET_RANDOM:                                                                //10-03-23|0x037d
          TestSample(_GET_RANDOM_1);                                                      //10-03-23|0x037d
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-23|0x037e
          if(TokensNoTokens   != 3)                    ReturnSystemError                  //10-03-23|0x037e
          switch(TokensPrepare(ProcessTokensAddr, 2))       _SwitchGroup                  //10-03-23|0x037e
          switch(NumTextIn(2))                              _SwitchGroup                  //10-03-23|0x037e
          if(ParmNumType == 0)        ReturnFinish("Numeric Conersion");                  //10-03-23|0x037e
          switch(GetRandom)                                 _SwitchGroup                  //10-03-23|0x037e
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-03-23|0x037f
                                                            _SwitchGroup                  //10-03-23|0x037f
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-23|0x0380
          return(status);                                                                 //10-03-23|0x0380
//***************************************************************************             //10-03-23|0x0381
//***************************************************************************             //10-03-23|0x0382
        case I_COMPUTE_PARITY:                                                            //10-03-23|0x0383
          TestSample(_COMPUTE_PARITY_1);                                                  //10-03-23|0x0383
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-23|0x0384
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //10-03-23|0x0384
          switch(TokensPrepare(ProcessTokensAddr, 1))       _SwitchGroup                  //10-03-23|0x0384
          switch(ComputeParity)                                        _SwitchGroup       //10-03-23|0x0384
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-23|0x0385
          return(status);                                                                 //10-03-23|0x0385
//***************************************************************************             //10-03-23|0x0386
        case I_GET_PARITY:                                                                //10-03-23|0x0387
          TestSample(_GET_PARITY_1);                                                      //10-03-23|0x0387
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-23|0x0388
          if(TokensNoTokens   != 2)                    ReturnSystemError                  //10-03-23|0x0388
          ResultNumUlong = 0;                                                             //10-03-23|0x0388
          ResultNumType  = 1;                                                             //10-03-23|0x0388
          switch(GetParity)                                        _SwitchGroup           //10-03-23|0x0388
          switch(NumericRegOut)                               _SwitchGroup                //10-03-23|0x0389
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-03-23|0x038a
          return(status);                                                                 //10-03-23|0x038a
//***************************************************************************             //10-03-23|0x038b
//***************************************************************************             //10-03-23|0x038c
        case I_ENCRYPT:                                                                   //10-03-23|0x038d
          TestSample(_ENCRYPT_1);                                                         //10-03-23|0x038d
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-23|0x038e
          if(TokensNoTokens   != 3)                    ReturnSystemError                  //10-03-23|0x038e
          switch(TokensPrepare(ProcessTokensAddr, 2))       _SwitchGroup                  //10-03-23|0x038e
          switch(Encrypt)                                        _SwitchGroup             //10-03-23|0x038e
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-03-23|0x038f
                                                            _SwitchGroup                  //10-03-23|0x038f
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-23|0x0390
          return(status);                                                                 //10-03-23|0x0390
//***************************************************************************             //10-03-23|0x0391
        case I_DECRYPT:                                                                   //10-03-23|0x0392
          TestSample(_DECRYPT_1);                                                         //10-03-23|0x0392
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //10-03-23|0x0393
          if(TokensNoTokens   != 3)                    ReturnSystemError                  //10-03-23|0x0393
          switch(TokensPrepare(ProcessTokensAddr, 2))       _SwitchGroup                  //10-03-23|0x0393
          switch(Decrypt)                                        _SwitchGroup             //10-03-23|0x0393
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-03-23|0x0394
                                                            _SwitchGroup                  //10-03-23|0x0394
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //10-03-23|0x0395
          return(status);                                                                 //10-03-23|0x0395
//***************************************************************************             //06-10-03|0x0396
//***************************************************************************             //06-10-05|0x0397
//******                                                               ******             //06-10-05|0x0398
//******                     Miscellaneous Input operations            ******             //06-10-05|0x0399
//******                                                               ******             //06-10-05|0x039a
//***************************************************************************             //07-09-13|0x039b
//***************************************************************************             //07-09-13|0x039c
//******                          In Manual                            ******             //07-09-13|0x039d
//***************************************************************************             //06-10-05|0x039e
//***************************************************************************             //06-10-05|0x039f
        case I_GET_TAB:                                                                   //06-09-29|0x03a0
          TestSample(_GET_TAB_1);                                                         //06-09-29|0x03a0
          if(TokensNoTokens != 2)                    ReturnSystemError;                   //06-09-29|0x03a1
          ResultNumUlong = FileGetTab();                                                  //06-09-29|0x03a1
          if(ResultNumUlong >= 0x100)                ReturnSystemError;                   //06-09-29|0x03a1
          ResultNumType = 2;                                                              //06-09-29|0x03a1
          switch(NumericRegOut)                               _SwitchGroup                //06-09-29|0x03a2
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-09-29|0x03a3
          return(status);                                                                 //06-09-29|0x03a3
//***************************************************************************             //06-10-03|0x03a4
//***************************************************************************             //06-10-05|0x03a5
//******                                                               ******             //06-10-05|0x03a6
//******                     Input Text file operations                ******             //06-10-05|0x03a7
//******                                                               ******             //06-10-05|0x03a8
//***************************************************************************             //07-09-13|0x03a9
//***************************************************************************             //07-09-13|0x03aa
//******                          In Manual                            ******             //07-09-13|0x03ab
//***************************************************************************             //06-10-05|0x03ac
//***************************************************************************             //06-10-05|0x03ad
        case I_READ_TEXT:                                                                 //10-05-16|0x03ae
          TestSample(_READ_TEXT_1);                                                       //10-05-16|0x03ae
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //10-05-16|0x03af
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //10-05-16|0x03af
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //10-05-16|0x03af
          switch(NumTextIn(2))                             _SwitchGroup                   //10-05-16|0x03b0
          if(ParmNumType  == 0)                                                           //10-05-16|0x03b0
                              ReturnFinish("Illegal Text File Index");                    //10-05-16|0x03b0
          if(ParmNumUlong >= FileInNoFiles)                                               //10-05-16|0x03b0
                             ReturnFinish("Illegal Text File Number");                    //10-05-16|0x03b0
          if(TokensNoTokens != 3)                    ReturnSystemError;                   //10-05-16|0x03b1
          switch(FileCommitText(FileInFileAddr(ParmNumUlong)))                            //10-05-16|0x03b1
                                                           _SwitchGroup                   //10-05-16|0x03b1
          switch(FileGetText(ProcessResultsAddr, 0))                                      //10-05-16|0x03b1
            {                                                                             //10-05-16|0x03b1
              case Success:     switch(FileRelease())      _SwitchBreak;                  //10-05-16|0x03b1
              case UserError:   switch(FileRelease())      _SwitchGroup                   //10-05-16|0x03b1
                                ReturnFinish("Unexpected End of File");                   //10-05-16|0x03b1
              default:                               ReturnSystemError;                   //10-05-16|0x03b1
              }                                                                           //10-05-16|0x03b1
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //10-05-16|0x03b1
          ResultNumUlong     = strlen(ResultsLineAddr);                                   //10-05-16|0x03b1
          if(ResultNumUlong != (ULONG) ResultsLength) ReturnSystemError;                  //10-05-16|0x03b1
          switch(ResultsChar(ResultsLength-1))                                            //10-05-16|0x03b1
            {                                                                             //10-05-16|0x03b1
              case 0x0a:                                      break;                      //10-05-16|0x03b1
              case 0x0d:                                      break;                      //10-05-16|0x03b1
              default:                               ReturnSystemError;                   //10-05-16|0x03b1
              }                                                                           //10-05-16|0x03b1
          switch(ResultNumUlong)                                                          //10-05-16|0x03b1
            {                                                                             //10-05-16|0x03b1
              case 0:                                ReturnSystemError;                   //10-05-16|0x03b1
              case 1:   ProcessFlagState = -1;                    break;                  //10-05-16|0x03b1
              default:                                                                    //10-05-16|0x03b1
                ResultsLength -= 1;                                                       //10-05-16|0x03b1
                ResultsChar(ResultsLength) = 0;                                           //10-05-16|0x03b1
                ResultsType   = I_TOKEN;                                                  //10-05-16|0x03b1
                switch(                                                                   //10-05-16|0x03b1
                  TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr)                    //10-05-16|0x03b1
                  )                                        _SwitchGroup                   //10-05-16|0x03b1
                ProcessFlagState = 1;                             break;                  //10-05-16|0x03b1
              }                                                                           //10-05-16|0x03b1
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //10-05-16|0x03b2
          return(status);                                                                 //10-05-16|0x03b2
//***************************************************************************             //10-05-15|0x03b3
        case I_STATE_READ_TEXT:                                                           //10-05-15|0x03b4
          TestSample(_STATE_READ_TEXT_1);                                                 //10-05-15|0x03b4
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //10-05-15|0x03b5
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //10-05-15|0x03b5
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //10-05-15|0x03b5
          switch(NumTextIn(1))                             _SwitchGroup                   //10-05-15|0x03b6
          if(ParmNumType  == 0)                                                           //10-05-15|0x03b6
                              ReturnFinish("Illegal Text File Index");                    //10-05-15|0x03b6
          if(ParmNumUlong >= FileInNoFiles)                                               //10-05-15|0x03b6
                             ReturnFinish("Illegal Text File Number");                    //10-05-15|0x03b6
          if(TokensNoTokens != 2)                    ReturnSystemError;                   //10-05-15|0x03b7
          switch(FileCommitText(FileInFileAddr(ParmNumUlong)))                            //10-05-15|0x03b7
                                                           _SwitchGroup                   //10-05-15|0x03b7
          switch(FileTextReadStatus())                                                    //10-05-15|0x03b7
            {                                                                             //10-05-15|0x03b7
              case Yes:    ProcessFlagState = 1;                  break;                  //10-05-15|0x03b7
              case No:     ProcessFlagState = -1;                 break;                  //10-05-15|0x03b7
              default:                               ReturnSystemError;                   //10-05-15|0x03b7
              }                                                                           //10-05-15|0x03b7
          switch(FileRelease())                            _SwitchGroup;                  //10-05-15|0x03b7
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //10-05-15|0x03b8
          return(status);                                                                 //10-05-15|0x03b8
//***************************************************************************             //10-05-16|0x03b9
        case I_NO_TEXT_FILES:                                                             //10-05-16|0x03ba
          TestSample(_NO_TEXT_FILES_1);                                                   //10-05-16|0x03ba
          if(TokensNoTokens != 2)                    ReturnSystemError;                   //10-05-16|0x03bb
          ResultNumUlong = FileInNoFiles;                                                 //10-05-16|0x03bb
          if(ResultNumUlong >= 16)                   ReturnSystemError;                   //10-05-16|0x03bb
          ResultNumType = 2;                                                              //10-05-16|0x03bb
          switch(NumericRegOut)                               _SwitchGroup                //10-05-16|0x03bc
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-05-16|0x03bd
          return(status);                                                                 //10-05-16|0x03bd
//***************************************************************************             //10-05-16|0x03be
        case I_TEXT_BASE_NAME:                                                            //10-05-16|0x03bf
          TestSample(_TEXT_BASE_NAME_1);                                                  //10-05-16|0x03bf
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //10-05-16|0x03c0
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //10-05-16|0x03c0
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //10-05-16|0x03c0
          if(FileName(FileInName) == 0)                                                   //10-05-25|0x03c1
                             ReturnFinish("Input File Not Specified");                    //10-05-25|0x03c1
          ResultsType   = I_TOKEN;                                                        //10-05-25|0x03c1
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //10-05-25|0x03c1
          ResultNumUlong = strlen(FileInName);                                            //10-05-25|0x03c1
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //10-05-25|0x03c1
                                                      ReturnSystemError;                  //10-05-25|0x03c1
          ResultsLength = ResultNumWord0;                                                 //10-05-25|0x03c1
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-05-16|0x03c2
                                                            _SwitchGroup                  //10-05-16|0x03c2
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-05-16|0x03c3
          return(status);                                                                 //10-05-16|0x03c3
//***************************************************************************             //10-05-16|0x03c4
        case I_TEXT_NAME:                                                                 //10-05-16|0x03c5
          TestSample(_TEXT_NAME_1);                                                       //10-05-16|0x03c5
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //10-05-16|0x03c6
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //10-05-16|0x03c6
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //10-05-16|0x03c6
          switch(NumTextIn(2))                             _SwitchGroup                   //10-05-16|0x03c7
          if(ParmNumType  == 0)                                                           //10-05-16|0x03c7
                              ReturnFinish("Illegal Text File Index");                    //10-05-16|0x03c7
          if(ParmNumUlong >= FileInNoFiles)                                               //10-05-16|0x03c7
                             ReturnFinish("Illegal Text File Number");                    //10-05-16|0x03c7
          if(FileName(FileInFileName(ParmNumUlong)) == 0)                                 //10-05-25|0x03c8
                             ReturnFinish("Input File Not Specified");                    //10-05-25|0x03c8
          ResultsType   = I_TOKEN;                                                        //10-05-25|0x03c8
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //10-05-25|0x03c8
          ResultNumUlong = strlen(FileInFileName(ParmNumUlong));                          //10-05-25|0x03c8
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //10-05-25|0x03c8
                                                      ReturnSystemError;                  //10-05-25|0x03c8
          ResultsLength = ResultNumWord0;                                                 //10-05-25|0x03c8
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-05-16|0x03c9
                                                            _SwitchGroup                  //10-05-16|0x03c9
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-05-16|0x03ca
          return(status);                                                                 //10-05-16|0x03ca
//***************************************************************************             //10-05-16|0x03cb
        case I_TEXT_PATH:                                                                 //10-05-16|0x03cc
          TestSample(_TEXT_PATH_1);                                                       //10-05-16|0x03cc
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //10-05-16|0x03cd
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //10-05-16|0x03cd
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //10-05-16|0x03cd
          switch(NumTextIn(2))                             _SwitchGroup                   //10-05-16|0x03ce
          if(ParmNumType  == 0)                                                           //10-05-16|0x03ce
                              ReturnFinish("Illegal Text File Index");                    //10-05-16|0x03ce
          if(ParmNumUlong >= FileInNoFiles)                                               //10-05-16|0x03ce
                             ReturnFinish("Illegal Text File Number");                    //10-05-16|0x03ce
          if(FileName(FileInPath(ParmNumUlong)) == 0)                                     //chec k  |0x03cf
                             ReturnFinish("Input File Not Specified");                    //chec k  |0x03cf
          ResultsType   = I_TOKEN;                                                        //chec k  |0x03cf
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //chec k  |0x03cf
          ResultNumUlong = strlen(FileInPath(ParmNumUlong));                              //chec k  |0x03cf
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //chec k  |0x03cf
                                                      ReturnSystemError;                  //chec k  |0x03cf
          ResultsLength = ResultNumWord0;                                                 //chec k  |0x03cf
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-05-16|0x03d0
                                                            _SwitchGroup                  //10-05-16|0x03d0
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-05-16|0x03d1
          return(status);                                                                 //10-05-16|0x03d1
//***************************************************************************             //10-05-16|0x03d2
        case I_TEXT_EXTENT:                                                               //10-05-16|0x03d3
          TestSample(_TEXT_EXTENT_1);                                                     //10-05-16|0x03d3
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //10-05-16|0x03d4
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //10-05-16|0x03d4
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //10-05-16|0x03d4
          switch(NumTextIn(2))                             _SwitchGroup                   //10-05-16|0x03d5
          if(ParmNumType  == 0)                                                           //10-05-16|0x03d5
                              ReturnFinish("Illegal Text File Index");                    //10-05-16|0x03d5
          if(ParmNumUlong >= FileInNoFiles)                                               //10-05-16|0x03d5
                             ReturnFinish("Illegal Text File Number");                    //10-05-16|0x03d5
          if(FileName(FileInExtent(ParmNumUlong)) == 0)                                   //10-05-25|0x03d6
                             ReturnFinish("Input File Not Specified");                    //10-05-25|0x03d6
          ResultsType   = I_TOKEN;                                                        //10-05-25|0x03d6
          if(ResultsChar(256) != 0)                   ReturnSystemError;                  //10-05-25|0x03d6
          ResultNumUlong = strlen(FileInExtent(ParmNumUlong));                            //10-05-25|0x03d6
          if(ResultNumUlong != strlen(ResultsLineAddr))                                   //10-05-25|0x03d6
                                                      ReturnSystemError;                  //10-05-25|0x03d6
          ResultsLength = ResultNumWord0;                                                 //10-05-25|0x03d6
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //10-05-16|0x03d7
                                                            _SwitchGroup                  //10-05-16|0x03d7
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-05-16|0x03d8
          return(status);                                                                 //10-05-16|0x03d8
//***************************************************************************             //10-05-16|0x03d9
        case I_TEXT_LINE_NO:                                                              //10-05-16|0x03da
          TestSample(_TEXT_LINE_NO_1);                                                    //10-05-16|0x03da
          if(TokensNoTokens <  3)                   ReturnSystemError;                    //10-05-16|0x03db
          if(TokensNoTokens >  3)                   ReturnSystemError;                    //10-05-16|0x03db
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //10-05-16|0x03db
          switch(NumTextIn(2))                             _SwitchGroup                   //10-05-16|0x03dc
          if(ParmNumType  == 0)                                                           //10-05-16|0x03dc
                              ReturnFinish("Illegal Text File Index");                    //10-05-16|0x03dc
          if(ParmNumUlong >= FileInNoFiles)                                               //10-05-16|0x03dc
                             ReturnFinish("Illegal Text File Number");                    //10-05-16|0x03dc
          ResultNumUlong = FileInLineNo(ParmNumUlong);                                    //10-05-16|0x03dd
          if(ResultNumUlong >= 0x10000)              ReturnSystemError;                   //10-05-16|0x03dd
          ResultNumType = 2;                                                              //10-05-16|0x03dd
          switch(NumericRegOut)                               _SwitchGroup                //10-05-16|0x03de
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //10-05-16|0x03df
          return(status);                                                                 //10-05-16|0x03df
//***************************************************************************             //06-10-05|0x03e0
        case I_READ_SEGMENT:                                                              //check   |0x03e1
          TestSample(_READ_SEGMENT_1);                                                    //check   |0x03e1
          if(TokensNoTokens <  4)                   ReturnSystemError;                    //check   |0x03e2
          if(TokensNoTokens >  4)                   ReturnSystemError;                    //check   |0x03e2
          switch(TokensPrepare(ProcessTokensAddr, 2))      _SwitchGroup                   //check   |0x03e2
          switch(NumTextIn(2))                             _SwitchGroup                   //check   |0x03e3
          if(ParmNumType  == 0)                                                           //check   |0x03e3
                              ReturnFinish("Illegal Text File Index");                    //check   |0x03e3
          if(ParmNumUlong >= FileInNoFiles)                                               //check   |0x03e3
                             ReturnFinish("Illegal Text File Number");                    //check   |0x03e3
          if(TokensNoTokens != 4)                    ReturnSystemError;                   //10-05-16|0x03e4
          switch(FileCommitText(FileInFileAddr(ParmNumUlong)))                            //10-05-16|0x03e4
                                                           _SwitchGroup                   //10-05-16|0x03e4
          ParmNumType = 0;                                                                //10-05-16|0x03e4
          switch(NumTextIn(3))                             _SwitchGroup                   //10-05-16|0x03e4
          if((ParmNumType  != 1) && (ParmNumType  != 2))                                  //10-05-16|0x03e4
                                     ReturnFinish("Illegal Max Size");                    //10-05-16|0x03e4
          switch(segment_in(ProcessDataFar, ParmNumWord0))                                //10-05-16|0x03e4
            {                                                                             //10-05-16|0x03e4
              case Yes: ProcessFlagState = 1;                                             //10-05-16|0x03e4
                        switch(FileRelease())              _SwitchBreak;                  //10-05-16|0x03e4
              case No:  ProcessFlagState = -1;                                            //10-05-16|0x03e4
                        switch(FileRelease())              _SwitchBreak;                  //10-05-16|0x03e4
              case UserError:   switch(FileRelease())      _SwitchGroup                   //10-05-16|0x03e4
                                                     return(UserError);                   //10-05-16|0x03e4
              default:                               ReturnSystemError;                   //10-05-16|0x03e4
              }                                                                           //10-05-16|0x03e4
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //10-05-16|0x03e5
          return(status);                                                                 //10-05-16|0x03e5
//***************************************************************************             //06-10-01|0x03e6
//***************************************************************************             //06-10-01|0x03e7
//******                                                               ******             //06-10-01|0x03e8
//******                         error operations                      ******             //06-10-01|0x03e9
//******                                                               ******             //06-10-01|0x03ea
//***************************************************************************             //06-10-01|0x03eb
//***************************************************************************             //06-10-01|0x03ec
//******                          In Manual                            ******             //07-09-13|0x03ed
//***************************************************************************             //06-10-05|0x03ee
//***************************************************************************             //06-10-05|0x03ef
        case I_ERROR:                                                                     //07-12-26|0x03f0
          TestSample(_ERROR_1);                                                           //07-12-26|0x03f0
          if(TokensNoTokens <  1)                   ReturnSystemError;                    //07-11-16|0x03f1
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //07-11-16|0x03f1
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //07-11-16|0x03f1
          switch(TokensNoTokens)                                                          //07-12-26|0x03f2
            {                                                                             //07-12-26|0x03f2
              case 2:                                                                     //07-12-26|0x03f2
                if(TokensType(1) != I_NAME) ReturnFinish("Illegal Error");                //07-12-26|0x03f2
                switch(ErrorMailAddMacro(ProcessMacroNameAddr))                           //07-12-26|0x03f2
                                                              _SwitchGroup                //07-12-26|0x03f2
                switch(ErrorMailAddError(TokensTokenAddr(1))) _SwitchGroup                //07-12-26|0x03f2
                switch(ProcessDebugCommand)                                               //07-12-26|0x03f2
                  {                                                                       //07-12-26|0x03f2
                    case DBG_OFF:                                                         //07-12-26|0x03f2
                        ReturnFinishBuild("User Error Termination");                      //07-12-26|0x03f2
                    case DBG_ON:                                                          //07-12-26|0x03f2
                      ReturnFinish("User Test Error Termination");                        //07-12-26|0x03f2
                    default:                            ReturnSystemError;                //07-12-26|0x03f2
                    }                                                                     //07-12-26|0x03f2
              case 1:                                                                     //07-12-26|0x03f2
                ReturnFinish("Unconditional User Error Termination");                     //07-12-26|0x03f2
              default:                                              break;                //07-12-26|0x03f2
              }                                                                           //07-12-26|0x03f2
          ReturnSystemError;                                                              //07-12-26|0x03f2
//***************************************************************************             //07-11-16|0x03f3
        case I_STATE_ERROR:                                                               //07-11-17|0x03f4
          TestSample(_STATE_ERROR_1);                                                     //07-11-17|0x03f4
//---------------------------------------------------------------------------             //07-11-17|0x03f5
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-11-17|0x03f6
          switch(ErrorMailTestError())                                                    //07-11-17|0x03f6
            {                                                                             //07-11-17|0x03f6
              case No:     ProcessFlagState = -1;                 break;                  //07-11-17|0x03f6
              case Yes:    ProcessFlagState =  1;                 break;                  //07-11-17|0x03f6
              default:                                ReturnSystemError;                  //07-11-17|0x03f6
              }                                                                           //07-11-17|0x03f6
//---------------------------------------------------------------------------             //07-11-17|0x03f7
          switch(DebugManager(DBG_TOKENS_FLAG))                       _SwitchGroup        //07-11-17|0x03f8
          return(status);                                                                 //07-11-17|0x03f8
//***************************************************************************             //07-11-16|0x03f9
        case I_GET_ERROR_MACRO:                                                           //07-11-16|0x03fa
          TestSample(_GET_ERROR_MACRO_1);                                                 //07-11-16|0x03fa
          if(TokensNoTokens   != 2)                  ReturnSystemError;                   //07-11-16|0x03fb
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-11-16|0x03fb
          switch(ErrorMailReadMacro(ProcessResultsAddr))    _SwitchGroup                  //07-11-16|0x03fb
          ResultsType = I_TOKEN;                                                          //07-11-16|0x03fb
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-11-16|0x03fc
                                                            _SwitchGroup                  //07-11-16|0x03fc
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-11-16|0x03fd
          return(status);                                                                 //07-11-16|0x03fd
//***************************************************************************             //07-11-16|0x03fe
        case I_GET_ERROR_TYPE:                                                            //07-11-16|0x03ff
          TestSample(_GET_ERROR_TYPE_1);                                                  //07-11-16|0x03ff
          if(TokensNoTokens   != 2)                  ReturnSystemError;                   //07-11-16|0x0400
          if(ProcessFlagState != 0) ReturnFinish("Test Flag Not Reset");                  //07-11-16|0x0400
          switch(ErrorMailReadError(ProcessResultsAddr))    _SwitchGroup                  //07-11-16|0x0400
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //07-11-16|0x0401
                                                            _SwitchGroup                  //07-11-16|0x0401
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //07-11-16|0x0402
          return(status);                                                                 //07-11-16|0x0402
//***************************************************************************             //06-10-01|0x0403
//***************************************************************************             //06-10-01|0x0404
//******                                                               ******             //06-10-01|0x0405
//******                      debug operations                         ******             //06-10-01|0x0406
//******                                                               ******             //06-10-01|0x0407
//***************************************************************************             //06-10-01|0x0408
//***************************************************************************             //06-10-06|0x0409
//******                          In Manual                            ******             //06-10-01|0x040a
//***************************************************************************             //06-10-01|0x040b
//***************************************************************************             //06-10-01|0x040c
        case I_DEBUG_ON:                                                                  //06-10-01|0x040d
          TestSample(_DEBUG_ON_1);                                                        //06-10-01|0x040d
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-10-01|0x040e
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-10-01|0x040e
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-10-01|0x040e
          switch(DebugOn)                                   _SwitchGroup                  //06-10-01|0x040f
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-10-01|0x0410
          return(status);                                                                 //06-10-01|0x0410
//***************************************************************************             //06-10-01|0x0411
//***************************************************************************             //06-10-01|0x0412
//******                                                               ******             //06-10-01|0x0413
//******                   display/keyboard operations                 ******             //06-10-01|0x0414
//******                                                               ******             //06-10-01|0x0415
//***************************************************************************             //06-10-01|0x0416
//***************************************************************************             //06-12-12|0x0417
//******                          In Manual                            ******             //06-10-01|0x0418
//***************************************************************************             //06-10-01|0x0419
//***************************************************************************             //06-10-01|0x041a
        case I_DISPLAY:                                                                   //06-10-06|0x041b
          TestSample(_DISPLAY_1);                                                         //06-10-06|0x041b
          if(TokensNoTokens <  2)                   ReturnSystemError;                    //06-10-06|0x041c
          if(TokensNoTokens >  2)                   ReturnSystemError;                    //06-10-06|0x041c
          switch(TokensPrepare(ProcessTokensAddr, 1))      _SwitchGroup                   //06-10-06|0x041c
          if(ProcessFlagState  != 0)  ReturnFinish("Test Flag Not Reset");                //06-10-06|0x041d
          if(TokensLength(1)   >= 78)                                                     //06-10-06|0x041d
            {                                                                             //06-10-06|0x041d
              TokensLength(1)  = 78;                                                      //06-10-06|0x041d
              TokensChar(1,78) = 0;                                                       //06-10-06|0x041d
              }                                                                           //06-10-06|0x041d
          switch(GuiWriteLine(TokensLineAddr(1)))             _SwitchGroup                //06-10-06|0x041d
          status = Display;                                                               //06-10-06|0x041d
          switch(DebugManager(DBG_TOKENS_ONLY))                       _SwitchGroup        //06-10-06|0x041e
          return(status);                                                                 //06-10-06|0x041e
//***************************************************************************             //06-12-25|0x041f
        case I_KEYBOARD:                                                                  //06-12-25|0x0420
          TestSample(_KEYBOARD_1);                                                        //06-12-25|0x0420
          if(TokensNoTokens != 2)                       ReturnSystemError;                //06-12-25|0x0421
          switch(ProcessFlagState)                                                        //06-12-25|0x0421
            {                                                                             //06-12-25|0x0421
              case 0:                                                                     //06-12-25|0x0421
                ProcessFlagState = 4;                                                     //06-12-25|0x0421
                status = KeyBoard;                                                        //06-12-25|0x0421
                break;                                                                    //06-12-25|0x0421
              case 4:                                                                     //06-12-25|0x0421
                if(ReadKeyBoard != No)                  ReturnSystemError;                //06-12-25|0x0421
                if(ReadKeyBoard != Yes)                 ReturnSystemError;                //06-12-25|0x0421
                if(TruncStringSize(&ResultsLength,  ResultsLineAddr)                      //06-12-25|0x0421
                                        != Success)     ReturnSystemError;                //06-12-25|0x0421
                if(ResultsLength <= 0)                  ReturnSystemError;                //06-12-25|0x0421
                --ResultsLength;                                                          //06-12-25|0x0421
                if(ResultsChar(ResultsLength) != 0x0a)  ReturnSystemError;                //06-12-25|0x0421
                switch(ResultsLength)                                                     //06-12-25|0x0421
                  {                                                                       //06-12-25|0x0421
                    case 0:                                                               //06-12-25|0x0421
                      ProcessFlagState = -1;                                              //06-12-25|0x0421
                      break;                                                              //06-12-25|0x0421
                    default:                                                              //06-12-25|0x0421
                      ResultsType                 = I_TOKEN;                              //06-12-25|0x0421
                      ResultsChar(ResultsLength)  = 0x00;                                 //06-12-25|0x0421
                      switch(ResultRegOut)                    _SwitchGroup                //06-12-25|0x0421
                      ProcessFlagState = 1;                                               //06-12-25|0x0421
                      break;                                                              //06-12-25|0x0421
                  }                                                                       //06-12-25|0x0421
                status = Continue;                                                        //06-12-25|0x0421
                switch(DebugManager(DBG_TOKENS_FLAG))                   _SwitchGroup      //06-12-25|0x0421
                break;                                                                    //06-12-25|0x0421
              default:                                  ReturnSystemError;                //06-12-25|0x0421
              }                                                                           //06-12-25|0x0421
          return(status);                                                                 //06-12-25|0x0421
//***************************************************************************             //06-10-01|0x0422
//***************************************************************************             //06-10-01|0x0423
//******                                                               ******             //06-10-01|0x0424
//******                   pcg argument operations                     ******             //06-10-01|0x0425
//******                                                               ******             //06-10-01|0x0426
//***************************************************************************             //06-10-01|0x0427
//***************************************************************************             //06-12-12|0x0428
//******                          In Manual                            ******             //06-10-01|0x0429
//***************************************************************************             //06-10-01|0x042a
//***************************************************************************             //06-10-01|0x042b
        case I_GET_PCG_ARG:                                                               //06-12-12|0x042c
          TestSample(_GET_PCG_ARG_1);                                                     //06-12-12|0x042c
          switch(NumericInData)                             _SwitchGroup                  //06-12-12|0x042d
          if(ParmNumWord0 >= PcgNoTokens)                                                 //06-12-12|0x042e
                      ReturnFinish("_GET_PCG_DATA: Token Does Not Exist");                //06-12-12|0x042e
          if(PcgLength(ParmNumWord0) == 0)               ReturnSystemError                //06-12-12|0x042e
          if(PcgLength(ParmNumWord0)  > 256)             ReturnSystemError                //06-12-12|0x042e
          StrDataCpy(ProcessResultsAddr, PcgTokenAddr(ParmNumWord0));                     //06-12-12|0x042e
          switch(TextStoreReg(TokensTokenAddr(1), ProcessResultsAddr))                    //06-12-12|0x042f
                                                            _SwitchGroup                  //06-12-12|0x042f
          switch(DebugManager(DBG_TOKENS_RES))                       _SwitchGroup         //06-12-12|0x0430
          return(status);                                                                 //06-12-12|0x0430
//***************************************************************************             //06-10-01|0x0431
//***************************************************************************             //06-10-01|0x0432
        default:                                       ReturnSystemError;                 //06-10-01|0x0433
        }                                                                                 //06-10-01|0x0433
}                                                                                         //06-10-01|0x0434
//                                                                                        //05-24-97|0x0434
//***************************************************************************             //07-05-18|0x0437
//***************************************************************************             //07-05-18|0x0438
//******                                                               ******             //07-05-18|0x0439
//******                        call_initial                           ******             //07-05-18|0x043a
//******                                                               ******             //07-05-18|0x043b
//***************************************************************************             //07-05-18|0x043c
//***************************************************************************             //07-05-18|0x043d
//*******************************************************************************         //10-29-97|0x0444
//*******************************************************************************         //10-29-97|0x0444
// call_initial                                                                           //07-05-18|0x0444
//*******************************************************************************         //10-29-97|0x0444
//*******************************************************************************         //10-29-97|0x0444
UINT PRECOPER::call_initial(                                                              //07-05-18|0x0444
    PROCESS_DATA_FAR ProcessDataFar                                                       //07-05-18|0x0444
    ) {                                                                                   //07-05-18|0x0444
//*******************************************************************************         //10-29-97|0x0444
  ProcessCallReturnState = 2286; // SOURCE_CALL                                           //07-05-21|0x0448
//***************************************************************************             //07-05-18|0x0449
    return_test(call_initial_1);                                                          //07-05-18|0x044a
}                                                                                         //07-05-18|0x044c
//                                                                                        //05-24-97|0x044c
//***************************************************************************             //07-05-18|0x044f
//***************************************************************************             //07-05-18|0x0450
//******                                                               ******             //07-05-18|0x0451
//******                             execute_call                      ******             //07-05-18|0x0452
//******                                                               ******             //07-05-18|0x0453
//***************************************************************************             //07-05-18|0x0454
//***************************************************************************             //07-05-18|0x0455
//*******************************************************************************         //10-29-97|0x0459
//*******************************************************************************         //10-29-97|0x0459
// execute_call                                                                           //07-05-18|0x0459
//*******************************************************************************         //10-29-97|0x0459
//*******************************************************************************         //10-29-97|0x0459
UINT PRECOPER::execute_call(                                                              //07-05-18|0x0459
    PROCESS_DATA_FAR ProcessDataFar                                                       //07-05-18|0x0459
    ) {                                                                                   //07-05-18|0x0459
//*******************************************************************************         //10-29-97|0x0459
//***************************************************************************             //06-09-28|0x045c
//***************************************************************************             //06-09-28|0x045d
  UINT no_includes;                                                                  //07-05-22|0x045e
  SINT search_offset;                                                                //07-05-22|0x045f
//***************************************************************************             //07-05-22|0x0460
//***************************************************************************             //07-05-22|0x0461
  no_includes   = 0;                                                                      //07-05-22|0x0462
//***************************************************************************             //07-05-18|0x0463
//******                                                               ******             //07-05-18|0x0464
//******  State Machine Begins                                         ******             //07-05-18|0x0465
//******                                                               ******             //07-05-18|0x0466
//***************************************************************************             //07-05-18|0x0467
  ProcessCallReturnRunFlag = 1;                                                           //07-05-18|0x0468
  while(ProcessCallReturnRunFlag != 0)                                                    //07-05-18|0x0468
  {                                                                                       //07-05-18|0x0468
    switch(ProcessCallReturnState)                                                        //07-05-18|0x0468
    {                                                                                     //07-05-18|0x0468
//***************************************************************************             //07-05-18|0x0469
//******                                                               ******             //07-05-18|0x046a
//******  Cleanup calling routine                                      ******             //07-05-18|0x046b
//******                                                               ******             //07-05-18|0x046c
//***************************************************************************             //07-05-18|0x046d
      case 38989: // SOURCE_CALLED                                                        //07-05-24|0x046e
        switch(StackMacroEnd())                                                           //07-05-24|0x046e
        {                                                                                 //07-05-24|0x046e
          case Success:                                                                   //07-05-24|0x046e
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x046e
            ProcessCallReturnState = 7580; // SAVE_REG                                    //07-05-24|0x046e
            break;                                                                        //07-05-24|0x046e
          default:                                                                        //07-05-24|0x046e
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x046e
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x046e
            SystemMsg;                                                                    //07-05-24|0x046e
            break;                                                                        //07-05-24|0x046e
        }                                                                                 //07-05-24|0x046e
        break;                                                                            //07-05-24|0x046e
//---------------------------------------------------------------------------             //07-05-18|0x046f
      case 63451: // MACRO_CALLED                                                         //07-05-24|0x0470
        switch(StackMacroEnd())                                                           //07-05-24|0x0470
        {                                                                                 //07-05-24|0x0470
          case Success:                                                                   //07-05-24|0x0470
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x0470
            ProcessCallReturnState = 7580; // SAVE_REG                                    //07-05-24|0x0470
            break;                                                                        //07-05-24|0x0470
          default:                                                                        //07-05-24|0x0470
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x0470
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x0470
            SystemMsg;                                                                    //07-05-24|0x0470
            break;                                                                        //07-05-24|0x0470
        }                                                                                 //07-05-24|0x0470
        break;                                                                            //07-05-24|0x0470
//***************************************************************************             //07-06-30|0x0471
      case 7580: // SAVE_REG                                                              //07-06-30|0x0472
        switch(PrecRegSave())                                                             //07-06-30|0x0472
        {                                                                                 //07-06-30|0x0472
          case Success:                                                                   //07-06-30|0x0472
            ProcessCallReturnRunFlag = 1;                                                 //07-06-30|0x0472
            ProcessCallReturnState = 30218; // MACRO_END                                  //07-06-30|0x0472
            break;                                                                        //07-06-30|0x0472
          default:                                                                        //07-06-30|0x0472
            ProcessCallReturnStatus = SystemError;                                        //07-06-30|0x0472
            ProcessCallReturnRunFlag = 0;                                                 //07-06-30|0x0472
            SystemMsg;                                                                    //07-06-30|0x0472
            break;                                                                        //07-06-30|0x0472
        }                                                                                 //07-06-30|0x0472
        break;                                                                            //07-06-30|0x0472
//***************************************************************************             //07-05-18|0x0473
      case 30218: // MACRO_END                                                            //07-05-18|0x0474
        switch(MacDictMacroEnd())                                                         //07-05-18|0x0474
        {                                                                                 //07-05-18|0x0474
          case Success:                                                                   //07-05-18|0x0474
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x0474
            ProcessCallReturnState = 55081; // BRIDGE_NAME                                //07-05-18|0x0474
            break;                                                                        //07-05-18|0x0474
          default:                                                                        //07-05-18|0x0474
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x0474
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x0474
            SystemMsg;                                                                    //07-05-18|0x0474
            break;                                                                        //07-05-18|0x0474
        }                                                                                 //07-05-18|0x0474
        break;                                                                            //07-05-18|0x0474
//***************************************************************************             //07-05-18|0x0475
//******                                                               ******             //07-05-18|0x0476
//******  Initialize process                                           ******             //07-05-18|0x0477
//******                                                               ******             //07-05-18|0x0478
//***************************************************************************             //07-05-18|0x0479
      case 55081: // BRIDGE_NAME                                                          //07-05-18|0x047a
        CopyToBridge;                                                                     //07-05-18|0x047a
        ProcessCallReturnState = 19000; // MACRO_NAME                                     //07-05-18|0x047a
        break;                                                                            //07-05-18|0x047a
//---------------------------------------------------------------------------             //07-05-18|0x047b
      case 19000: // MACRO_NAME                                                           //07-05-18|0x047c
        CopyToMacro;                                                                      //07-05-18|0x047c
        ProcessCallReturnState = 60983; // UTILITY_NAME                                   //07-05-18|0x047c
        break;                                                                            //07-05-18|0x047c
//---------------------------------------------------------------------------             //07-05-24|0x047d
      case 60983: // UTILITY_NAME                                                         //07-05-24|0x047e
        switch(UtilBridgeName)                                                            //07-05-24|0x047e
        {                                                                                 //07-05-24|0x047e
          case Success:                                                                   //07-05-24|0x047e
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x047e
            ProcessCallReturnState = 53798; // ZERO_INCLUDES                              //07-05-24|0x047e
            break;                                                                        //07-05-24|0x047e
          default:                                                                        //07-05-24|0x047e
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x047e
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x047e
            SystemMsg;                                                                    //07-05-24|0x047e
            break;                                                                        //07-05-24|0x047e
        }                                                                                 //07-05-24|0x047e
        break;                                                                            //07-05-24|0x047e
//***************************************************************************             //07-05-24|0x047f
      case 53798: // ZERO_INCLUDES                                                        //07-05-24|0x0480
        no_includes = 0;                                                                  //07-05-24|0x0480
        ProcessCallReturnState = 62725; // ZERO_OFFSET                                    //07-05-24|0x0480
        break;                                                                            //07-05-24|0x0480
//---------------------------------------------------------------------------             //07-05-24|0x0481
      case 62725: // ZERO_OFFSET                                                          //07-05-24|0x0482
        search_offset = 0;                                                                //07-05-24|0x0482
        ProcessCallReturnState = 17876; // FIND_UTILITY                                   //07-05-24|0x0482
        break;                                                                            //07-05-24|0x0482
//***************************************************************************             //07-05-24|0x0483
//******                                                               ******             //07-05-24|0x0484
//******  FIND CALLED MACRO BRIDGE                                     ******             //07-05-24|0x0485
//******---------------------------------------------------------------******             //07-05-24|0x0486
//******  Find Utility Bridge                                          ******             //07-05-24|0x0487
//******                                                               ******             //07-05-24|0x0488
//***************************************************************************             //07-05-24|0x0489
      case 17876: // FIND_UTILITY                                                         //07-05-24|0x048a
        switch(FindUtilBridge)                                                            //07-05-24|0x048a
        {                                                                                 //07-05-24|0x048a
          case Yes:                                                                       //07-05-24|0x048a
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x048a
            ProcessCallReturnState = 41875; // UTILITY_TYPE                               //07-05-24|0x048a
            break;                                                                        //07-05-24|0x048a
          case No:                                                                        //07-05-24|0x048a
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x048a
            ProcessCallReturnState = 56642; // FIND_REGIONAL                              //07-05-24|0x048a
            break;                                                                        //07-05-24|0x048a
          case UserError:                                                                 //07-05-24|0x048a
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x048a
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x048a
            break;                                                                        //07-05-24|0x048a
          default:                                                                        //07-05-24|0x048a
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x048a
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x048a
            SystemMsg;                                                                    //07-05-24|0x048a
            break;                                                                        //07-05-24|0x048a
        }                                                                                 //07-05-24|0x048a
        break;                                                                            //07-05-24|0x048a
//---------------------------------------------------------------------------             //07-05-24|0x048b
      case 41875: // UTILITY_TYPE                                                         //07-07-18|0x048c
        UtilityBridgeType = I_UTILITY_NAME;                                               //07-07-18|0x048c
        ProcessCallReturnState = 53360; // UTIL_INCLUDE                                   //07-07-18|0x048c
        break;                                                                            //07-07-18|0x048c
//***************************************************************************             //07-07-18|0x048d
      case 53360: // UTIL_INCLUDE                                                         //07-07-18|0x048e
        switch(FindCallInc)                                                               //07-07-18|0x048e
        {                                                                                 //07-07-18|0x048e
          case Yes:                                                                       //07-07-18|0x048e
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x048e
            ProcessCallReturnState = 55279; // DUPLICATE                                  //07-07-18|0x048e
            break;                                                                        //07-07-18|0x048e
          case No:                                                                        //07-07-18|0x048e
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x048e
            ProcessCallReturnState = 22366; // UTIL_REGION                                //07-07-18|0x048e
            break;                                                                        //07-07-18|0x048e
          case UserError:                                                                 //07-07-18|0x048e
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x048e
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-07-18|0x048e
            break;                                                                        //07-07-18|0x048e
          default:                                                                        //07-07-18|0x048e
            ProcessCallReturnStatus = SystemError;                                        //07-07-18|0x048e
            ProcessCallReturnRunFlag = 0;                                                 //07-07-18|0x048e
            SystemMsg;                                                                    //07-07-18|0x048e
            break;                                                                        //07-07-18|0x048e
        }                                                                                 //07-07-18|0x048e
        break;                                                                            //07-07-18|0x048e
//---------------------------------------------------------------------------             //07-07-18|0x048f
      case 22366: // UTIL_REGION                                                          //07-07-18|0x0490
        switch(FindRegBridge)                                                             //07-07-18|0x0490
        {                                                                                 //07-07-18|0x0490
          case Yes:                                                                       //07-07-18|0x0490
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x0490
            ProcessCallReturnState = 55279; // DUPLICATE                                  //07-07-18|0x0490
            break;                                                                        //07-07-18|0x0490
          case No:                                                                        //07-07-18|0x0490
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x0490
            ProcessCallReturnState = 52669; // UTIL_PUBLIC                                //07-07-18|0x0490
            break;                                                                        //07-07-18|0x0490
          case UserError:                                                                 //07-07-18|0x0490
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x0490
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-07-18|0x0490
            break;                                                                        //07-07-18|0x0490
          default:                                                                        //07-07-18|0x0490
            ProcessCallReturnStatus = SystemError;                                        //07-07-18|0x0490
            ProcessCallReturnRunFlag = 0;                                                 //07-07-18|0x0490
            SystemMsg;                                                                    //07-07-18|0x0490
            break;                                                                        //07-07-18|0x0490
        }                                                                                 //07-07-18|0x0490
        break;                                                                            //07-07-18|0x0490
//---------------------------------------------------------------------------             //07-07-18|0x0491
      case 52669: // UTIL_PUBLIC                                                          //07-07-18|0x0492
        switch(FindPubBridge)                                                             //07-07-18|0x0492
        {                                                                                 //07-07-18|0x0492
          case Yes:                                                                       //07-07-18|0x0492
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x0492
            ProcessCallReturnState = 55279; // DUPLICATE                                  //07-07-18|0x0492
            break;                                                                        //07-07-18|0x0492
          case No:                                                                        //07-07-18|0x0492
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x0492
            ProcessCallReturnState = 43532; // COPY_BRIDGE                                //07-07-18|0x0492
            break;                                                                        //07-07-18|0x0492
          case UserError:                                                                 //07-07-18|0x0492
            ProcessCallReturnRunFlag = 1;                                                 //07-07-18|0x0492
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-07-18|0x0492
            break;                                                                        //07-07-18|0x0492
          default:                                                                        //07-07-18|0x0492
            ProcessCallReturnStatus = SystemError;                                        //07-07-18|0x0492
            ProcessCallReturnRunFlag = 0;                                                 //07-07-18|0x0492
            SystemMsg;                                                                    //07-07-18|0x0492
            break;                                                                        //07-07-18|0x0492
        }                                                                                 //07-07-18|0x0492
        break;                                                                            //07-07-18|0x0492
//---------------------------------------------------------------------------             //07-07-18|0x0493
      case 43532: // COPY_BRIDGE                                                          //07-07-18|0x0494
        CopyUtilBridge;                                                                   //07-07-18|0x0494
        ProcessCallReturnState = 19275; // PUSH_STACK                                     //07-07-18|0x0494
        break;                                                                            //07-07-18|0x0494
//***************************************************************************             //07-05-24|0x0495
//******                                                               ******             //07-05-24|0x0496
//******  FIND CALLED MACRO BRIDGE                                     ******             //07-05-24|0x0497
//******---------------------------------------------------------------******             //07-05-24|0x0498
//******  Find Regional Bridge                                         ******             //07-05-24|0x0499
//******                                                               ******             //07-05-24|0x049a
//***************************************************************************             //07-05-24|0x049b
      case 56642: // FIND_REGIONAL                                                        //07-05-24|0x049c
        switch(FindRegBridge)                                                             //07-05-24|0x049c
        {                                                                                 //07-05-24|0x049c
          case Yes:                                                                       //07-05-24|0x049c
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x049c
            ProcessCallReturnState = 122; // REGIONAL_TYPE                                //07-05-24|0x049c
            break;                                                                        //07-05-24|0x049c
          case No:                                                                        //07-05-24|0x049c
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x049c
            ProcessCallReturnState = 2201; // PUBLIC_CHECK                                //07-05-24|0x049c
            break;                                                                        //07-05-24|0x049c
          case UserError:                                                                 //07-05-24|0x049c
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x049c
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x049c
            break;                                                                        //07-05-24|0x049c
          default:                                                                        //07-05-24|0x049c
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x049c
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x049c
            SystemMsg;                                                                    //07-05-24|0x049c
            break;                                                                        //07-05-24|0x049c
        }                                                                                 //07-05-24|0x049c
        break;                                                                            //07-05-24|0x049c
//---------------------------------------------------------------------------             //07-05-24|0x049d
      case 122: // REGIONAL_TYPE                                                          //07-05-24|0x049e
        BridgeType = I_BRIDGE_NAME;                                                       //07-05-24|0x049e
        ProcessCallReturnState = 37544; // REG_PUBLIC                                     //07-05-24|0x049e
        break;                                                                            //07-05-24|0x049e
//***************************************************************************             //07-05-24|0x049f
      case 37544: // REG_PUBLIC                                                           //07-05-24|0x04a0
        switch(FindPubBridge)                                                             //07-05-24|0x04a0
        {                                                                                 //07-05-24|0x04a0
          case Yes:                                                                       //07-05-24|0x04a0
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04a0
            ProcessCallReturnState = 55279; // DUPLICATE                                  //07-05-24|0x04a0
            break;                                                                        //07-05-24|0x04a0
          case No:                                                                        //07-05-24|0x04a0
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04a0
            ProcessCallReturnState = 19275; // PUSH_STACK                                 //07-05-24|0x04a0
            break;                                                                        //07-05-24|0x04a0
          case UserError:                                                                 //07-05-24|0x04a0
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04a0
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x04a0
            break;                                                                        //07-05-24|0x04a0
          default:                                                                        //07-05-24|0x04a0
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04a0
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04a0
            SystemMsg;                                                                    //07-05-24|0x04a0
            break;                                                                        //07-05-24|0x04a0
        }                                                                                 //07-05-24|0x04a0
        break;                                                                            //07-05-24|0x04a0
//***************************************************************************             //07-05-24|0x04a1
//******                                                               ******             //07-05-24|0x04a2
//******  FIND CALLED MACRO BRIDGE                                     ******             //07-05-24|0x04a3
//******---------------------------------------------------------------******             //07-05-24|0x04a4
//******  Public must not be found in current search region            ******             //07-05-24|0x04a5
//******                                                               ******             //07-05-24|0x04a6
//***************************************************************************             //07-05-24|0x04a7
      case 2201: // PUBLIC_CHECK                                                          //07-05-24|0x04a8
        switch(FindPubBridge)                                                             //07-05-24|0x04a8
        {                                                                                 //07-05-24|0x04a8
          case Yes:                                                                       //07-05-24|0x04a8
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04a8
            ProcessCallReturnState = 55279; // DUPLICATE                                  //07-05-24|0x04a8
            break;                                                                        //07-05-24|0x04a8
          case No:                                                                        //07-05-24|0x04a8
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04a8
            ProcessCallReturnState = 48551; // PARALLEL                                   //07-05-24|0x04a8
            break;                                                                        //07-05-24|0x04a8
          case UserError:                                                                 //07-05-24|0x04a8
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04a8
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x04a8
            break;                                                                        //07-05-24|0x04a8
          default:                                                                        //07-05-24|0x04a8
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04a8
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04a8
            SystemMsg;                                                                    //07-05-24|0x04a8
            break;                                                                        //07-05-24|0x04a8
        }                                                                                 //07-05-24|0x04a8
        break;                                                                            //07-05-24|0x04a8
//***************************************************************************             //07-05-24|0x04a9
//******                                                               ******             //07-05-24|0x04aa
//******  FIND CALLED MACRO BRIDGE                                     ******             //07-05-24|0x04ab
//******---------------------------------------------------------------******             //07-05-24|0x04ac
//******  Find Parallel Include Bridge                                 ******             //07-05-24|0x04ad
//******                                                               ******             //07-05-24|0x04ae
//***************************************************************************             //07-05-24|0x04af
      case 48551: // PARALLEL                                                             //07-05-24|0x04b0
        switch(FindCallInc)                                                               //07-05-24|0x04b0
        {                                                                                 //07-05-24|0x04b0
          case Yes:                                                                       //07-05-24|0x04b0
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04b0
            ProcessCallReturnState = 39062; // PUBLIC_OFFSET                              //07-05-24|0x04b0
            break;                                                                        //07-05-24|0x04b0
          case No:                                                                        //07-05-24|0x04b0
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04b0
            ProcessCallReturnState = 39062; // PUBLIC_OFFSET                              //07-05-24|0x04b0
            break;                                                                        //07-05-24|0x04b0
          case UserError:                                                                 //07-05-24|0x04b0
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04b0
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x04b0
            break;                                                                        //07-05-24|0x04b0
          default:                                                                        //07-05-24|0x04b0
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04b0
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04b0
            SystemMsg;                                                                    //07-05-24|0x04b0
            break;                                                                        //07-05-24|0x04b0
        }                                                                                 //07-05-24|0x04b0
        break;                                                                            //07-05-24|0x04b0
//***************************************************************************             //07-05-24|0x04b1
//******                                                               ******             //07-05-24|0x04b2
//******  FIND CALLED MACRO BRIDGE                                     ******             //07-05-24|0x04b3
//******---------------------------------------------------------------******             //07-05-24|0x04b4
//******  Find Public Bridge                                           ******             //07-05-24|0x04b5
//******                                                               ******             //07-05-24|0x04b6
//***************************************************************************             //07-05-24|0x04b7
      case 39062: // PUBLIC_OFFSET                                                        //07-05-24|0x04b8
        search_offset = 1;                                                                //07-05-24|0x04b8
        ProcessCallReturnState = 8821; // FIND_PUBLIC                                     //07-05-24|0x04b8
        break;                                                                            //07-05-24|0x04b8
//---------------------------------------------------------------------------             //07-05-24|0x04b9
      case 8821: // FIND_PUBLIC                                                           //07-05-24|0x04ba
        switch(FindPubBridge)                                                             //07-05-24|0x04ba
        {                                                                                 //07-05-24|0x04ba
          case Yes:                                                                       //07-05-24|0x04ba
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04ba
            ProcessCallReturnState = 19012; // PUBLIC_TYPE                                //07-05-24|0x04ba
            break;                                                                        //07-05-24|0x04ba
          case No:                                                                        //07-05-24|0x04ba
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04ba
            ProcessCallReturnState = 61187; // FIND_INCLUDE                               //07-05-24|0x04ba
            break;                                                                        //07-05-24|0x04ba
          case UserError:                                                                 //07-05-24|0x04ba
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04ba
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x04ba
            break;                                                                        //07-05-24|0x04ba
          default:                                                                        //07-05-24|0x04ba
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04ba
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04ba
            SystemMsg;                                                                    //07-05-24|0x04ba
            break;                                                                        //07-05-24|0x04ba
        }                                                                                 //07-05-24|0x04ba
        break;                                                                            //07-05-24|0x04ba
//---------------------------------------------------------------------------             //07-05-24|0x04bb
      case 19012: // PUBLIC_TYPE                                                          //07-09-19|0x04bc
        BridgeType = I_PUBLIC_NAME;                                                       //07-09-19|0x04bc
        ProcessCallReturnState = 57266; // PUBLIC_RESET                                   //07-09-19|0x04bc
        break;                                                                            //07-09-19|0x04bc
//***************************************************************************             //07-09-19|0x04bd
      case 57266: // PUBLIC_RESET                                                         //07-09-19|0x04be
        search_offset = 0;                                                                //07-09-19|0x04be
        ProcessCallReturnState = 56145; // PUB_INCLUDE                                    //07-09-19|0x04be
        break;                                                                            //07-09-19|0x04be
//---------------------------------------------------------------------------             //07-09-19|0x04bf
      case 56145: // PUB_INCLUDE                                                          //07-09-19|0x04c0
        switch(FindCallInc)                                                               //07-09-19|0x04c0
        {                                                                                 //07-09-19|0x04c0
          case Yes:                                                                       //07-09-19|0x04c0
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x04c0
            ProcessCallReturnState = 55279; // DUPLICATE                                  //07-09-19|0x04c0
            break;                                                                        //07-09-19|0x04c0
          case No:                                                                        //07-09-19|0x04c0
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x04c0
            ProcessCallReturnState = 37088; // PUB_REGION                                 //07-09-19|0x04c0
            break;                                                                        //07-09-19|0x04c0
          case UserError:                                                                 //07-09-19|0x04c0
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x04c0
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-09-19|0x04c0
            break;                                                                        //07-09-19|0x04c0
          default:                                                                        //07-09-19|0x04c0
            ProcessCallReturnStatus = SystemError;                                        //07-09-19|0x04c0
            ProcessCallReturnRunFlag = 0;                                                 //07-09-19|0x04c0
            SystemMsg;                                                                    //07-09-19|0x04c0
            break;                                                                        //07-09-19|0x04c0
        }                                                                                 //07-09-19|0x04c0
        break;                                                                            //07-09-19|0x04c0
//---------------------------------------------------------------------------             //07-09-19|0x04c1
      case 37088: // PUB_REGION                                                           //09-01-17|0x04c2
        switch(FindRegBridge)                                                             //09-01-17|0x04c2
        {                                                                                 //09-01-17|0x04c2
          case Yes:                                                                       //09-01-17|0x04c2
            ProcessCallReturnRunFlag = 1;                                                 //09-01-17|0x04c2
            ProcessCallReturnState = 55279; // DUPLICATE                                  //09-01-17|0x04c2
            break;                                                                        //09-01-17|0x04c2
          case No:                                                                        //09-01-17|0x04c2
            ProcessCallReturnRunFlag = 1;                                                 //09-01-17|0x04c2
            ProcessCallReturnState = 19275; // PUSH_STACK                                 //09-01-17|0x04c2
            break;                                                                        //09-01-17|0x04c2
          case UserError:                                                                 //09-01-17|0x04c2
            ProcessCallReturnRunFlag = 1;                                                 //09-01-17|0x04c2
            ProcessCallReturnState = 45537; // USER_ERROR                                 //09-01-17|0x04c2
            break;                                                                        //09-01-17|0x04c2
          default:                                                                        //09-01-17|0x04c2
            ProcessCallReturnStatus = SystemError;                                        //09-01-17|0x04c2
            ProcessCallReturnRunFlag = 0;                                                 //09-01-17|0x04c2
            SystemMsg;                                                                    //09-01-17|0x04c2
            break;                                                                        //09-01-17|0x04c2
        }                                                                                 //09-01-17|0x04c2
        break;                                                                            //09-01-17|0x04c2
//***************************************************************************             //07-05-24|0x04c3
//******                                                               ******             //07-05-24|0x04c4
//******  FIND CALLED MACRO BRIDGE                                     ******             //07-05-24|0x04c5
//******---------------------------------------------------------------******             //07-05-24|0x04c6
//******  Find Include Bridge                                          ******             //07-05-24|0x04c7
//******                                                               ******             //07-05-24|0x04c8
//***************************************************************************             //07-05-24|0x04c9
      case 61187: // FIND_INCLUDE                                                         //07-05-24|0x04ca
        switch(FindCallInc)                                                               //07-05-24|0x04ca
        {                                                                                 //07-05-24|0x04ca
          case Yes:                                                                       //07-05-24|0x04ca
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04ca
            ProcessCallReturnState = 40799; // INCR_INCLUDE                               //07-05-24|0x04ca
            break;                                                                        //07-05-24|0x04ca
          case No:                                                                        //07-05-24|0x04ca
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04ca
            ProcessCallReturnState = 38350; // NOT_FOUND                                  //07-05-24|0x04ca
            break;                                                                        //07-05-24|0x04ca
          case UserError:                                                                 //07-05-24|0x04ca
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04ca
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x04ca
            break;                                                                        //07-05-24|0x04ca
          default:                                                                        //07-05-24|0x04ca
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04ca
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04ca
            SystemMsg;                                                                    //07-05-24|0x04ca
            break;                                                                        //07-05-24|0x04ca
        }                                                                                 //07-05-24|0x04ca
        break;                                                                            //07-05-24|0x04ca
//---------------------------------------------------------------------------             //07-05-24|0x04cb
      case 40799: // INCR_INCLUDE                                                         //07-05-24|0x04cc
        ++no_includes;                                                                    //07-05-24|0x04cc
        ProcessCallReturnState = 62253; // RESET_OFFSET                                   //07-05-24|0x04cc
        break;                                                                            //07-05-24|0x04cc
//---------------------------------------------------------------------------             //07-05-24|0x04cd
      case 62253: // RESET_OFFSET                                                         //07-05-24|0x04ce
        search_offset = 0;                                                                //07-05-24|0x04ce
        ProcessCallReturnState = 56642; // FIND_REGIONAL                                  //07-05-24|0x04ce
        break;                                                                            //07-05-24|0x04ce
//***************************************************************************             //07-05-24|0x04cf
//******                                                               ******             //07-05-24|0x04d0
//******  CALLING MACRO BRIDGE HAS BEEN FOUND                          ******             //07-05-24|0x04d1
//******---------------------------------------------------------------******             //07-05-24|0x04d2
//******  Complete the calling process                                 ******             //07-05-24|0x04d3
//******                                                               ******             //07-05-24|0x04d4
//***************************************************************************             //07-05-24|0x04d5
      case 19275: // PUSH_STACK                                                           //07-05-24|0x04d6
        switch(MacroPush)                                                                 //07-05-24|0x04d6
        {                                                                                 //07-05-24|0x04d6
          case Success:                                                                   //07-05-24|0x04d6
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04d6
            ProcessCallReturnState = 9852; // GET_CLASS                                   //07-05-24|0x04d6
            break;                                                                        //07-05-24|0x04d6
          case UserError:                                                                 //07-05-24|0x04d6
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04d6
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-05-24|0x04d6
            break;                                                                        //07-05-24|0x04d6
          default:                                                                        //07-05-24|0x04d6
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04d6
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04d6
            SystemMsg;                                                                    //07-05-24|0x04d6
            break;                                                                        //07-05-24|0x04d6
        }                                                                                 //07-05-24|0x04d6
        break;                                                                            //07-05-24|0x04d6
//***************************************************************************             //07-05-24|0x04d7
      case 9852: // GET_CLASS                                                             //07-05-24|0x04d8
        switch(GetClassName)                                                              //07-05-24|0x04d8
        {                                                                                 //07-05-24|0x04d8
          case Success:                                                                   //07-05-24|0x04d8
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04d8
            ProcessCallReturnState = 36539; // FIND_MACRO                                 //07-05-24|0x04d8
            break;                                                                        //07-05-24|0x04d8
          default:                                                                        //07-05-24|0x04d8
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04d8
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04d8
            SystemMsg;                                                                    //07-05-24|0x04d8
            break;                                                                        //07-05-24|0x04d8
        }                                                                                 //07-05-24|0x04d8
        break;                                                                            //07-05-24|0x04d8
//***************************************************************************             //07-05-24|0x04d9
      case 36539: // FIND_MACRO                                                           //07-05-24|0x04da
        switch(FindEntry)                                                                 //07-05-24|0x04da
        {                                                                                 //07-05-24|0x04da
          case Success:                                                                   //07-05-24|0x04da
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x04da
            ProcessCallReturnState = 31466; // SUCCESS                                    //07-05-24|0x04da
            break;                                                                        //07-05-24|0x04da
          default:                                                                        //07-05-24|0x04da
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x04da
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x04da
            SystemMsg;                                                                    //07-05-24|0x04da
            break;                                                                        //07-05-24|0x04da
        }                                                                                 //07-05-24|0x04da
        break;                                                                            //07-05-24|0x04da
//***************************************************************************             //07-05-24|0x04db
//******                                                               ******             //07-05-24|0x04dc
//******  ERROR AND EXIT STATES                                        ******             //07-05-24|0x04dd
//******                                                               ******             //07-05-24|0x04de
//***************************************************************************             //07-05-24|0x04df
      case 38350: // NOT_FOUND                                                            //07-10-29|0x04e0
        switch(MacroNameMsg)                                                              //07-10-29|0x04e0
        {                                                                                 //07-10-29|0x04e0
          case UserError:                                                                 //07-10-29|0x04e0
            ProcessCallReturnRunFlag = 1;                                                 //07-10-29|0x04e0
            ProcessCallReturnState = 10761; // NOT_FOUND_MSG                              //07-10-29|0x04e0
            break;                                                                        //07-10-29|0x04e0
          default:                                                                        //07-10-29|0x04e0
            ProcessCallReturnStatus = SystemError;                                        //07-10-29|0x04e0
            ProcessCallReturnRunFlag = 0;                                                 //07-10-29|0x04e0
            SystemMsg;                                                                    //07-10-29|0x04e0
            break;                                                                        //07-10-29|0x04e0
        }                                                                                 //07-10-29|0x04e0
        break;                                                                            //07-10-29|0x04e0
      case 10761: // NOT_FOUND_MSG                                                        //07-10-29|0x04e1
        switch(NotFoundMsg)                                                               //07-10-29|0x04e1
        {                                                                                 //07-10-29|0x04e1
          case UserError:                                                                 //07-10-29|0x04e1
            ProcessCallReturnRunFlag = 1;                                                 //07-10-29|0x04e1
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-10-29|0x04e1
            break;                                                                        //07-10-29|0x04e1
          default:                                                                        //07-10-29|0x04e1
            ProcessCallReturnStatus = SystemError;                                        //07-10-29|0x04e1
            ProcessCallReturnRunFlag = 0;                                                 //07-10-29|0x04e1
            SystemMsg;                                                                    //07-10-29|0x04e1
            break;                                                                        //07-10-29|0x04e1
        }                                                                                 //07-10-29|0x04e1
        break;                                                                            //07-10-29|0x04e1
//---------------------------------------------------------------------------             //07-05-24|0x04e2
      case 55279: // DUPLICATE                                                            //07-09-19|0x04e3
        switch(DupNameMsg)                                                                //07-09-19|0x04e3
        {                                                                                 //07-09-19|0x04e3
          case UserError:                                                                 //07-09-19|0x04e3
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x04e3
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-09-19|0x04e3
            break;                                                                        //07-09-19|0x04e3
          default:                                                                        //07-09-19|0x04e3
            ProcessCallReturnStatus = SystemError;                                        //07-09-19|0x04e3
            ProcessCallReturnRunFlag = 0;                                                 //07-09-19|0x04e3
            SystemMsg;                                                                    //07-09-19|0x04e3
            break;                                                                        //07-09-19|0x04e3
        }                                                                                 //07-09-19|0x04e3
        break;                                                                            //07-09-19|0x04e3
//***************************************************************************             //07-05-24|0x04e4
      case 31466: // SUCCESS                                                              //07-05-24|0x04e5
        ProcessCallReturnState = 51992; // MACRO_CALL                                     //07-05-24|0x04e5
        ProcessCallReturnStatus = Success;                                                //07-05-24|0x04e5
        ProcessCallReturnRunFlag = 0;                                                     //07-05-24|0x04e5
        break;                                                                            //07-05-24|0x04e5
//---------------------------------------------------------------------------             //07-05-24|0x04e6
      case 45537: // USER_ERROR                                                           //07-05-24|0x04e7
        ProcessCallReturnState = 38989; // SOURCE_CALLED                                  //07-05-24|0x04e7
        ProcessCallReturnStatus = UserError;                                              //07-05-24|0x04e7
        ProcessCallReturnRunFlag = 0;                                                     //07-05-24|0x04e7
        break;                                                                            //07-05-24|0x04e7
//***************************************************************************             //07-05-18|0x04e8
//******                                                               ******             //07-05-18|0x04e9
//******  State Machine Ends                                           ******             //07-05-18|0x04ea
//******                                                               ******             //07-05-18|0x04eb
//***************************************************************************             //07-05-18|0x04ec
      default:                                                                            //07-05-18|0x04ed
        ProcessCallReturnStatus = SystemError;                                            //07-05-18|0x04ed
        ProcessCallReturnRunFlag = 0;                                                     //07-05-18|0x04ed
        SystemMsg;                                                                        //07-05-18|0x04ed
        break;                                                                            //07-05-18|0x04ed
    }                                                                                     //07-05-18|0x04ed
  }                                                                                       //07-05-18|0x04ed
//***************************************************************************             //07-05-18|0x04ee
//***************************************************************************             //07-05-18|0x04ef
    return(ProcessCallReturnStatus);                                                      //07-05-18|0x04f0
}                                                                                         //07-05-18|0x04f2
//                                                                                        //05-24-97|0x04f2
//***************************************************************************             //07-05-21|0x04f5
//***************************************************************************             //07-05-21|0x04f6
//******                                                               ******             //07-05-21|0x04f7
//******                             macro_begin                       ******             //07-05-21|0x04f8
//******                                                               ******             //07-05-21|0x04f9
//***************************************************************************             //07-05-21|0x04fa
//***************************************************************************             //07-05-21|0x04fb
//*******************************************************************************         //10-29-97|0x04ff
//*******************************************************************************         //10-29-97|0x04ff
// macro_begin                                                                            //07-05-21|0x04ff
//*******************************************************************************         //10-29-97|0x04ff
//*******************************************************************************         //10-29-97|0x04ff
UINT PRECOPER::macro_begin(                                                               //07-05-21|0x04ff
    PROCESS_DATA_FAR ProcessDataFar                                                       //07-05-21|0x04ff
    ) {                                                                                   //07-05-21|0x04ff
//*******************************************************************************         //10-29-97|0x04ff
//***************************************************************************             //07-05-21|0x0502
//***************************************************************************             //07-05-21|0x0503
//******                                                               ******             //07-05-21|0x0504
//******  State Machine Begins                                         ******             //07-05-21|0x0505
//******                                                               ******             //07-05-21|0x0506
//***************************************************************************             //07-05-21|0x0507
  ProcessCallReturnRunFlag = 1;                                                           //07-05-21|0x0508
  while(ProcessCallReturnRunFlag != 0)                                                    //07-05-21|0x0508
  {                                                                                       //07-05-21|0x0508
    switch(ProcessCallReturnState)                                                        //07-05-21|0x0508
    {                                                                                     //07-05-21|0x0508
//***************************************************************************             //07-05-21|0x0509
//******                                                               ******             //07-05-21|0x050a
//******  Initial User Stack                                           ******             //07-05-21|0x050b
//******                                                               ******             //07-05-21|0x050c
//***************************************************************************             //07-05-21|0x050d
      case 2286: // SOURCE_CALL                                                           //07-05-21|0x050e
        switch(BeginStack)                                                                //07-05-21|0x050e
        {                                                                                 //07-05-21|0x050e
          case Success:                                                                   //07-05-21|0x050e
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x050e
            ProcessCallReturnState = 32023; // NO_CALL_ARGS                               //07-05-21|0x050e
            break;                                                                        //07-05-21|0x050e
          default:                                                                        //07-05-21|0x050e
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x050e
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x050e
            SystemMsg;                                                                    //07-05-21|0x050e
            break;                                                                        //07-05-21|0x050e
        }                                                                                 //07-05-21|0x050e
        break;                                                                            //07-05-21|0x050e
//---------------------------------------------------------------------------             //07-05-22|0x050f
      case 51992: // MACRO_CALL                                                           //07-05-22|0x0510
        switch(BeginStack)                                                                //07-05-22|0x0510
        {                                                                                 //07-05-22|0x0510
          case Success:                                                                   //07-05-22|0x0510
            ProcessCallReturnRunFlag = 1;                                                 //07-05-22|0x0510
            ProcessCallReturnState = 32023; // NO_CALL_ARGS                               //07-05-22|0x0510
            break;                                                                        //07-05-22|0x0510
          default:                                                                        //07-05-22|0x0510
            ProcessCallReturnStatus = SystemError;                                        //07-05-22|0x0510
            ProcessCallReturnRunFlag = 0;                                                 //07-05-22|0x0510
            SystemMsg;                                                                    //07-05-22|0x0510
            break;                                                                        //07-05-22|0x0510
        }                                                                                 //07-05-22|0x0510
        break;                                                                            //07-05-22|0x0510
//***************************************************************************             //07-05-21|0x0511
//******                                                               ******             //07-05-21|0x0512
//******  Get No calling parameters                                    ******             //07-05-21|0x0513
//******                                                               ******             //07-05-21|0x0514
//***************************************************************************             //07-05-21|0x0515
      case 32023: // NO_CALL_ARGS                                                         //07-05-21|0x0516
        switch(FetchNoParms)                                                              //07-05-21|0x0516
        {                                                                                 //07-05-21|0x0516
          case Success:                                                                   //07-05-21|0x0516
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0516
            ProcessCallReturnState = 20230; // NO_BEGIN_ARGS                              //07-05-21|0x0516
            break;                                                                        //07-05-21|0x0516
          default:                                                                        //07-05-21|0x0516
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0516
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0516
            SystemMsg;                                                                    //07-05-21|0x0516
            break;                                                                        //07-05-21|0x0516
        }                                                                                 //07-05-21|0x0516
        break;                                                                            //07-05-21|0x0516
//***************************************************************************             //07-05-21|0x0517
//******                                                               ******             //07-05-21|0x0518
//******  Get No of Begin instruction parameters                       ******             //07-05-21|0x0519
//******                                                               ******             //07-05-21|0x051a
//***************************************************************************             //07-05-21|0x051b
      case 20230: // NO_BEGIN_ARGS                                                        //07-05-21|0x051c
        switch(TokensNoTokens)                                                            //07-05-21|0x051c
        {                                                                                 //07-05-21|0x051c
          case 0x0004:                                                                    //07-05-21|0x051c
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x051c
            ProcessCallReturnState = 16357; // GET_PARM_3                                 //07-05-21|0x051c
            break;                                                                        //07-05-21|0x051c
          case 0x0003:                                                                    //07-05-21|0x051c
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x051c
            ProcessCallReturnState = 16052; // GET_PARM_2                                 //07-05-21|0x051c
            break;                                                                        //07-05-21|0x051c
          case 0x0002:                                                                    //07-05-21|0x051c
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x051c
            ProcessCallReturnState = 10867; // STACK_LEVEL                                //07-05-21|0x051c
            break;                                                                        //07-05-21|0x051c
          default:                                                                        //07-05-21|0x051c
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x051c
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x051c
            SystemMsg;                                                                    //07-05-21|0x051c
            break;                                                                        //07-05-21|0x051c
        }                                                                                 //07-05-21|0x051c
        break;                                                                            //07-05-21|0x051c
//***************************************************************************             //07-05-21|0x051d
//******                                                               ******             //07-05-21|0x051e
//******  Process the four parameter case                              ******             //07-05-21|0x051f
//******                                                               ******             //07-05-21|0x0520
//***************************************************************************             //07-05-21|0x0521
      case 16357: // GET_PARM_3                                                           //07-05-21|0x0522
        switch(NumTextIn(3))                                                              //07-05-21|0x0522
        {                                                                                 //07-05-21|0x0522
          case Success:                                                                   //07-05-21|0x0522
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0522
            ProcessCallReturnState = 53794; // TEST_UPPER_3                               //07-05-21|0x0522
            break;                                                                        //07-05-21|0x0522
          default:                                                                        //07-05-21|0x0522
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0522
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0522
            SystemMsg;                                                                    //07-05-21|0x0522
            break;                                                                        //07-05-21|0x0522
        }                                                                                 //07-05-21|0x0522
        break;                                                                            //07-05-21|0x0522
//***************************************************************************             //07-05-21|0x0523
      case 53794: // TEST_UPPER_3                                                         //07-05-21|0x0524
        switch(LimitTest)                                                                 //07-05-21|0x0524
        {                                                                                 //07-05-21|0x0524
          case 1:                                                                         //07-05-21|0x0524
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0524
            ProcessCallReturnState = 62657; // PARM_ERROR                                 //07-05-21|0x0524
            break;                                                                        //07-05-21|0x0524
          case 0:                                                                         //07-05-21|0x0524
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0524
            ProcessCallReturnState = 16720; // ZERO_ARG3                                  //07-05-21|0x0524
            break;                                                                        //07-05-21|0x0524
          case -1:                                                                        //07-05-21|0x0524
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0524
            ProcessCallReturnState = 16720; // ZERO_ARG3                                  //07-05-21|0x0524
            break;                                                                        //07-05-21|0x0524
          default:                                                                        //07-05-21|0x0524
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0524
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0524
            SystemMsg;                                                                    //07-05-21|0x0524
            break;                                                                        //07-05-21|0x0524
        }                                                                                 //07-05-21|0x0524
        break;                                                                            //07-05-21|0x0524
//***************************************************************************             //07-05-21|0x0525
      case 16720: // ZERO_ARG3                                                            //07-05-21|0x0526
        ZeroNumParm;                                                                      //07-05-21|0x0526
        ProcessCallReturnState = 22223; // GET_PARM_TWO                                   //07-05-21|0x0526
        break;                                                                            //07-05-21|0x0526
//***************************************************************************             //07-05-21|0x0527
      case 22223: // GET_PARM_TWO                                                         //07-05-21|0x0528
        switch(NumTextIn(2))                                                              //07-05-21|0x0528
        {                                                                                 //07-05-21|0x0528
          case Success:                                                                   //07-05-21|0x0528
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0528
            ProcessCallReturnState = 50238; // TEST_LOWER_2                               //07-05-21|0x0528
            break;                                                                        //07-05-21|0x0528
          default:                                                                        //07-05-21|0x0528
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0528
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0528
            SystemMsg;                                                                    //07-05-21|0x0528
            break;                                                                        //07-05-21|0x0528
        }                                                                                 //07-05-21|0x0528
        break;                                                                            //07-05-21|0x0528
//***************************************************************************             //07-05-21|0x0529
      case 50238: // TEST_LOWER_2                                                         //07-05-21|0x052a
        switch(LimitTest)                                                                 //07-05-21|0x052a
        {                                                                                 //07-05-21|0x052a
          case 1:                                                                         //07-05-21|0x052a
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x052a
            ProcessCallReturnState = 10867; // STACK_LEVEL                                //07-05-21|0x052a
            break;                                                                        //07-05-21|0x052a
          case 0:                                                                         //07-05-21|0x052a
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x052a
            ProcessCallReturnState = 10867; // STACK_LEVEL                                //07-05-21|0x052a
            break;                                                                        //07-05-21|0x052a
          case -1:                                                                        //07-05-21|0x052a
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x052a
            ProcessCallReturnState = 62657; // PARM_ERROR                                 //07-05-21|0x052a
            break;                                                                        //07-05-21|0x052a
          default:                                                                        //07-05-21|0x052a
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x052a
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x052a
            SystemMsg;                                                                    //07-05-21|0x052a
            break;                                                                        //07-05-21|0x052a
        }                                                                                 //07-05-21|0x052a
        break;                                                                            //07-05-21|0x052a
//***************************************************************************             //07-05-21|0x052b
//******                                                               ******             //07-05-21|0x052c
//******  Process the three parameter case                             ******             //07-05-21|0x052d
//******                                                               ******             //07-05-21|0x052e
//***************************************************************************             //07-05-21|0x052f
      case 16052: // GET_PARM_2                                                           //07-05-21|0x0530
        switch(NumTextIn(2))                                                              //07-05-21|0x0530
        {                                                                                 //07-05-21|0x0530
          case Success:                                                                   //07-05-21|0x0530
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0530
            ProcessCallReturnState = 2205; // TEST_EQUAL_2                                //07-05-21|0x0530
            break;                                                                        //07-05-21|0x0530
          default:                                                                        //07-05-21|0x0530
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0530
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0530
            SystemMsg;                                                                    //07-05-21|0x0530
            break;                                                                        //07-05-21|0x0530
        }                                                                                 //07-05-21|0x0530
        break;                                                                            //07-05-21|0x0530
//***************************************************************************             //07-05-21|0x0531
      case 2205: // TEST_EQUAL_2                                                          //07-05-21|0x0532
        switch(LimitTest)                                                                 //07-05-21|0x0532
        {                                                                                 //07-05-21|0x0532
          case 1:                                                                         //07-05-21|0x0532
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0532
            ProcessCallReturnState = 62657; // PARM_ERROR                                 //07-05-21|0x0532
            break;                                                                        //07-05-21|0x0532
          case 0:                                                                         //07-05-21|0x0532
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0532
            ProcessCallReturnState = 10867; // STACK_LEVEL                                //07-05-21|0x0532
            break;                                                                        //07-05-21|0x0532
          case -1:                                                                        //07-05-21|0x0532
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0532
            ProcessCallReturnState = 62657; // PARM_ERROR                                 //07-05-21|0x0532
            break;                                                                        //07-05-21|0x0532
          default:                                                                        //07-05-21|0x0532
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0532
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0532
            SystemMsg;                                                                    //07-05-21|0x0532
            break;                                                                        //07-05-21|0x0532
        }                                                                                 //07-05-21|0x0532
        break;                                                                            //07-05-21|0x0532
//***************************************************************************             //07-05-21|0x0533
//******                                                               ******             //07-05-21|0x0534
//******  Test the Stack State                                         ******             //07-05-21|0x0535
//******                                                               ******             //07-05-21|0x0536
//***************************************************************************             //07-05-21|0x0537
      case 10867: // STACK_LEVEL                                                          //07-05-21|0x0538
        switch(CallTestSrc())                                                             //07-05-21|0x0538
        {                                                                                 //07-05-21|0x0538
          case Yes:                                                                       //07-05-21|0x0538
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0538
            ProcessCallReturnState = 37612; // SOURCE_EXIT                                //07-05-21|0x0538
            break;                                                                        //07-05-21|0x0538
          case No:                                                                        //07-05-21|0x0538
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0538
            ProcessCallReturnState = 49707; // MACRO_EXIT                                 //07-05-21|0x0538
            break;                                                                        //07-05-21|0x0538
          default:                                                                        //07-05-21|0x0538
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0538
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0538
            SystemMsg;                                                                    //07-05-21|0x0538
            break;                                                                        //07-05-21|0x0538
        }                                                                                 //07-05-21|0x0538
        break;                                                                            //07-05-21|0x0538
//***************************************************************************             //07-05-21|0x0539
//******                                                               ******             //07-05-21|0x053a
//******  Exit States                                                  ******             //07-05-21|0x053b
//******                                                               ******             //07-05-21|0x053c
//***************************************************************************             //07-05-21|0x053d
      case 62657: // PARM_ERROR                                                           //07-09-19|0x053e
        switch(NoArgMsg)                                                                  //07-09-19|0x053e
        {                                                                                 //07-09-19|0x053e
          case UserError:                                                                 //07-09-19|0x053e
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x053e
            ProcessCallReturnState = 45537; // USER_ERROR                                 //07-09-19|0x053e
            break;                                                                        //07-09-19|0x053e
          default:                                                                        //07-09-19|0x053e
            ProcessCallReturnStatus = SystemError;                                        //07-09-19|0x053e
            ProcessCallReturnRunFlag = 0;                                                 //07-09-19|0x053e
            SystemMsg;                                                                    //07-09-19|0x053e
            break;                                                                        //07-09-19|0x053e
        }                                                                                 //07-09-19|0x053e
        break;                                                                            //07-09-19|0x053e
//---------------------------------------------------------------------------             //07-09-19|0x053f
      case 45537: // USER_ERROR                                                           //07-09-19|0x0540
        ProcessCallReturnState = 2286; // SOURCE_CALL                                     //07-09-19|0x0540
        ProcessCallReturnStatus = UserError;                                              //07-09-19|0x0540
        ProcessCallReturnRunFlag = 0;                                                     //07-09-19|0x0540
        break;                                                                            //07-09-19|0x0540
//***************************************************************************             //07-05-21|0x0541
      case 37612: // SOURCE_EXIT                                                          //07-05-21|0x0542
        ProcessCallReturnState = 38989; // SOURCE_CALLED                                  //07-05-21|0x0542
        ProcessCallReturnStatus = Success;                                                //07-05-21|0x0542
        ProcessCallReturnRunFlag = 0;                                                     //07-05-21|0x0542
        break;                                                                            //07-05-21|0x0542
//---------------------------------------------------------------------------             //07-05-21|0x0543
      case 49707: // MACRO_EXIT                                                           //07-05-21|0x0544
        ProcessCallReturnState = 63451; // MACRO_CALLED                                   //07-05-21|0x0544
        ProcessCallReturnStatus = Success;                                                //07-05-21|0x0544
        ProcessCallReturnRunFlag = 0;                                                     //07-05-21|0x0544
        break;                                                                            //07-05-21|0x0544
//***************************************************************************             //07-05-21|0x0545
//******                                                               ******             //07-05-21|0x0546
//******  State Machine Ends                                           ******             //07-05-21|0x0547
//******                                                               ******             //07-05-21|0x0548
//***************************************************************************             //07-05-21|0x0549
      default:                                                                            //07-05-21|0x054a
        ProcessCallReturnStatus = SystemError;                                            //07-05-21|0x054a
        ProcessCallReturnRunFlag = 0;                                                     //07-05-21|0x054a
        SystemMsg;                                                                        //07-05-21|0x054a
        break;                                                                            //07-05-21|0x054a
    }                                                                                     //07-05-21|0x054a
  }                                                                                       //07-05-21|0x054a
//***************************************************************************             //07-05-21|0x054b
//***************************************************************************             //07-05-21|0x054c
    return(ProcessCallReturnStatus);                                                      //07-05-21|0x054d
}                                                                                         //07-05-21|0x054f
//                                                                                        //05-24-97|0x054f
//***************************************************************************             //06-09-28|0x0552
//***************************************************************************             //06-09-28|0x0553
//******                                                               ******             //06-09-28|0x0554
//******                             macro_return                      ******             //06-09-28|0x0555
//******                                                               ******             //06-09-28|0x0556
//***************************************************************************             //06-09-28|0x0557
//***************************************************************************             //06-09-28|0x0558
//*******************************************************************************         //10-29-97|0x055c
//*******************************************************************************         //10-29-97|0x055c
// execute_return                                                                         //06-09-28|0x055c
//*******************************************************************************         //10-29-97|0x055c
//*******************************************************************************         //10-29-97|0x055c
UINT PRECOPER::execute_return(                                                            //06-09-28|0x055c
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-09-28|0x055c
    ) {                                                                                   //06-09-28|0x055c
//*******************************************************************************         //10-29-97|0x055c
//***************************************************************************             //06-09-28|0x055f
//***************************************************************************             //06-09-28|0x0560
  SINT no_includes;                                                                  //07-05-22|0x0561
  UINT return_line_no;                                                               //07-05-04|0x0562
  SINT search_offset;                                                                //07-09-19|0x0563
//***************************************************************************             //07-05-18|0x0564
//******                                                               ******             //07-05-18|0x0565
//******  State Machine Begins                                         ******             //07-05-18|0x0566
//******                                                               ******             //07-05-18|0x0567
//***************************************************************************             //07-05-18|0x0568
  ProcessCallReturnRunFlag = 1;                                                           //07-05-18|0x0569
  while(ProcessCallReturnRunFlag != 0)                                                    //07-05-18|0x0569
  {                                                                                       //07-05-18|0x0569
    switch(ProcessCallReturnState)                                                        //07-05-18|0x0569
    {                                                                                     //07-05-18|0x0569
//***************************************************************************             //07-05-18|0x056a
//******                                                               ******             //07-05-18|0x056b
//******  Source called macro                                          ******             //07-05-18|0x056c
//******---------------------------------------------------------------******             //07-05-18|0x056d
//******  Cleanup routine called from source                           ******             //07-05-18|0x056e
//******                                                               ******             //07-05-18|0x056f
//***************************************************************************             //07-05-18|0x0570
      case 38989: // SOURCE_CALLED                                                        //07-05-21|0x0571
        switch(StackMacroEnd())                                                           //07-05-21|0x0571
        {                                                                                 //07-05-21|0x0571
          case Success:                                                                   //07-05-21|0x0571
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0571
            ProcessCallReturnState = 58714; // SOURCE_MACRO                               //07-05-21|0x0571
            break;                                                                        //07-05-21|0x0571
          default:                                                                        //07-05-21|0x0571
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0571
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0571
            SystemMsg;                                                                    //07-05-21|0x0571
            break;                                                                        //07-05-21|0x0571
        }                                                                                 //07-05-21|0x0571
        break;                                                                            //07-05-21|0x0571
//***************************************************************************             //07-05-18|0x0572
      case 58714: // SOURCE_MACRO                                                         //07-05-21|0x0573
        switch(MacDictMacroEnd())                                                         //07-05-21|0x0573
        {                                                                                 //07-05-21|0x0573
          case Success:                                                                   //07-05-21|0x0573
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0573
            ProcessCallReturnState = 15225; // SOURCE_POP                                 //07-05-21|0x0573
            break;                                                                        //07-05-21|0x0573
          default:                                                                        //07-05-21|0x0573
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0573
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0573
            SystemMsg;                                                                    //07-05-21|0x0573
            break;                                                                        //07-05-21|0x0573
        }                                                                                 //07-05-21|0x0573
        break;                                                                            //07-05-21|0x0573
//***************************************************************************             //07-05-18|0x0574
//******                                                               ******             //07-05-18|0x0575
//******  Source called macro                                          ******             //07-05-18|0x0576
//******---------------------------------------------------------------******             //07-05-18|0x0577
//******  Perform the source pop                                       ******             //07-05-18|0x0578
//******                                                               ******             //07-05-18|0x0579
//***************************************************************************             //07-05-18|0x057a
      case 15225: // SOURCE_POP                                                           //07-05-18|0x057b
        switch(CallSrcPop())                                                              //07-05-18|0x057b
        {                                                                                 //07-05-18|0x057b
          case Success:                                                                   //07-05-18|0x057b
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x057b
            ProcessCallReturnState = 37612; // SOURCE_EXIT                                //07-05-18|0x057b
            break;                                                                        //07-05-18|0x057b
          case UserError:                                                                 //07-05-18|0x057b
            ProcessCallReturnState = 2286; // SOURCE_CALL                                 //07-05-18|0x057b
            ProcessCallReturnStatus = UserError;                                          //07-05-18|0x057b
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x057b
            break;                                                                        //07-05-18|0x057b
          default:                                                                        //07-05-18|0x057b
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x057b
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x057b
            SystemMsg;                                                                    //07-05-18|0x057b
            break;                                                                        //07-05-18|0x057b
        }                                                                                 //07-05-18|0x057b
        break;                                                                            //07-05-18|0x057b
//***************************************************************************             //07-05-18|0x057c
//******                                                               ******             //07-05-18|0x057d
//******  Macro called macro                                           ******             //07-05-18|0x057e
//******---------------------------------------------------------------******             //07-05-18|0x057f
//******  Cleanup routine called from macro                            ******             //07-05-18|0x0580
//******                                                               ******             //07-05-18|0x0581
//***************************************************************************             //07-05-18|0x0582
      case 63451: // MACRO_CALLED                                                         //07-05-21|0x0583
        switch(StackMacroEnd())                                                           //07-05-21|0x0583
        {                                                                                 //07-05-21|0x0583
          case Success:                                                                   //07-05-21|0x0583
            ProcessCallReturnRunFlag = 1;                                                 //07-05-21|0x0583
            ProcessCallReturnState = 30218; // MACRO_END                                  //07-05-21|0x0583
            break;                                                                        //07-05-21|0x0583
          default:                                                                        //07-05-21|0x0583
            ProcessCallReturnStatus = SystemError;                                        //07-05-21|0x0583
            ProcessCallReturnRunFlag = 0;                                                 //07-05-21|0x0583
            SystemMsg;                                                                    //07-05-21|0x0583
            break;                                                                        //07-05-21|0x0583
        }                                                                                 //07-05-21|0x0583
        break;                                                                            //07-05-21|0x0583
//***************************************************************************             //07-05-18|0x0584
      case 30218: // MACRO_END                                                            //07-09-19|0x0585
        switch(MacDictMacroEnd())                                                         //07-09-19|0x0585
        {                                                                                 //07-09-19|0x0585
          case Success:                                                                   //07-09-19|0x0585
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x0585
            ProcessCallReturnState = 62344; // ZERO_SEARCH                                //07-09-19|0x0585
            break;                                                                        //07-09-19|0x0585
          default:                                                                        //07-09-19|0x0585
            ProcessCallReturnStatus = SystemError;                                        //07-09-19|0x0585
            ProcessCallReturnRunFlag = 0;                                                 //07-09-19|0x0585
            SystemMsg;                                                                    //07-09-19|0x0585
            break;                                                                        //07-09-19|0x0585
        }                                                                                 //07-09-19|0x0585
        break;                                                                            //07-09-19|0x0585
//***************************************************************************             //07-05-22|0x0586
//******                                                               ******             //07-05-22|0x0587
//******  Macro called macro                                           ******             //07-05-22|0x0588
//******---------------------------------------------------------------******             //07-05-22|0x0589
//******  Initial the bridge search                                    ******             //07-05-22|0x058a
//******                                                               ******             //07-05-22|0x058b
//***************************************************************************             //07-05-22|0x058c
      case 62344: // ZERO_SEARCH                                                          //07-05-24|0x058d
        search_offset = 0;                                                                //07-05-24|0x058d
        ProcessCallReturnState = 11399; // BRIDGE_TYPE                                    //07-05-24|0x058d
        break;                                                                            //07-05-24|0x058d
//---------------------------------------------------------------------------             //07-05-24|0x058e
      case 11399: // BRIDGE_TYPE                                                          //07-05-24|0x058f
        switch(BridgeType)                                                                //07-05-24|0x058f
        {                                                                                 //07-05-24|0x058f
          case I_PUBLIC_NAME:                                                             //07-05-24|0x058f
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x058f
            ProcessCallReturnState = 62838; // RET_INITIAL                                //07-05-24|0x058f
            break;                                                                        //07-05-24|0x058f
          case I_BRIDGE_NAME:                                                             //07-05-24|0x058f
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x058f
            ProcessCallReturnState = 19797; // GET_NO_INCLUDE                             //07-05-24|0x058f
            break;                                                                        //07-05-24|0x058f
          case I_UTILITY_NAME:                                                            //07-05-24|0x058f
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x058f
            ProcessCallReturnState = 19797; // GET_NO_INCLUDE                             //07-05-24|0x058f
            break;                                                                        //07-05-24|0x058f
          default:                                                                        //07-05-24|0x058f
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x058f
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x058f
            SystemMsg;                                                                    //07-05-24|0x058f
            break;                                                                        //07-05-24|0x058f
        }                                                                                 //07-05-24|0x058f
        break;                                                                            //07-05-24|0x058f
//***************************************************************************             //07-05-24|0x0590
      case 62838: // RET_INITIAL                                                          //07-09-19|0x0591
        search_offset = -1;                                                               //07-09-19|0x0591
        ProcessCallReturnState = 19797; // GET_NO_INCLUDE                                 //07-09-19|0x0591
        break;                                                                            //07-09-19|0x0591
//***************************************************************************             //07-05-22|0x0592
//******                                                               ******             //07-05-22|0x0593
//******  Macro called macro                                           ******             //07-05-22|0x0594
//******---------------------------------------------------------------******             //07-05-22|0x0595
//******  Process the includes                                         ******             //07-05-22|0x0596
//******                                                               ******             //07-05-22|0x0597
//***************************************************************************             //07-05-22|0x0598
      case 19797: // GET_NO_INCLUDE                                                       //07-05-22|0x0599
        switch(GetNoIncludes)                                                             //07-05-22|0x0599
        {                                                                                 //07-05-22|0x0599
          case Success:                                                                   //07-05-22|0x0599
            ProcessCallReturnRunFlag = 1;                                                 //07-05-22|0x0599
            ProcessCallReturnState = 8996; // INCLUDES_EXIST                              //07-05-22|0x0599
            break;                                                                        //07-05-22|0x0599
          case UserError:                                                                 //07-05-22|0x0599
            ProcessCallReturnState = 2286; // SOURCE_CALL                                 //07-05-22|0x0599
            ProcessCallReturnStatus = UserError;                                          //07-05-22|0x0599
            ProcessCallReturnRunFlag = 0;                                                 //07-05-22|0x0599
            break;                                                                        //07-05-22|0x0599
          default:                                                                        //07-05-22|0x0599
            ProcessCallReturnStatus = SystemError;                                        //07-05-22|0x0599
            ProcessCallReturnRunFlag = 0;                                                 //07-05-22|0x0599
            SystemMsg;                                                                    //07-05-22|0x0599
            break;                                                                        //07-05-22|0x0599
        }                                                                                 //07-05-22|0x0599
        break;                                                                            //07-05-22|0x0599
//***************************************************************************             //07-05-22|0x059a
      case 8996: // INCLUDES_EXIST                                                        //07-05-22|0x059b
        switch(IncludesTest)                                                              //07-05-22|0x059b
        {                                                                                 //07-05-22|0x059b
          case Yes:                                                                       //07-05-22|0x059b
            ProcessCallReturnRunFlag = 1;                                                 //07-05-22|0x059b
            ProcessCallReturnState = 21987; // INCLUDE_BRIDGE                             //07-05-22|0x059b
            break;                                                                        //07-05-22|0x059b
          case No:                                                                        //07-05-22|0x059b
            ProcessCallReturnRunFlag = 1;                                                 //07-05-22|0x059b
            ProcessCallReturnState = 46226; // LINE_NO                                    //07-05-22|0x059b
            break;                                                                        //07-05-22|0x059b
          default:                                                                        //07-05-22|0x059b
            ProcessCallReturnStatus = SystemError;                                        //07-05-22|0x059b
            ProcessCallReturnRunFlag = 0;                                                 //07-05-22|0x059b
            SystemMsg;                                                                    //07-05-22|0x059b
            break;                                                                        //07-05-22|0x059b
        }                                                                                 //07-05-22|0x059b
        break;                                                                            //07-05-22|0x059b
//***************************************************************************             //07-05-24|0x059c
      case 21987: // INCLUDE_BRIDGE                                                       //07-05-24|0x059d
        switch(FindReturnInc)                                                             //07-05-24|0x059d
        {                                                                                 //07-05-24|0x059d
          case Yes:                                                                       //07-05-24|0x059d
            ProcessCallReturnRunFlag = 1;                                                 //07-05-24|0x059d
            ProcessCallReturnState = 65073; // RET_OFFSET                                 //07-05-24|0x059d
            break;                                                                        //07-05-24|0x059d
          default:                                                                        //07-05-24|0x059d
            ProcessCallReturnStatus = SystemError;                                        //07-05-24|0x059d
            ProcessCallReturnRunFlag = 0;                                                 //07-05-24|0x059d
            SystemMsg;                                                                    //07-05-24|0x059d
            break;                                                                        //07-05-24|0x059d
        }                                                                                 //07-05-24|0x059d
        break;                                                                            //07-05-24|0x059d
//***************************************************************************             //07-05-24|0x059e
      case 65073: // RET_OFFSET                                                           //07-05-24|0x059f
        search_offset = -1;                                                               //07-05-24|0x059f
        ProcessCallReturnState = 8996; // INCLUDES_EXIST                                  //07-05-24|0x059f
        break;                                                                            //07-05-24|0x059f
//***************************************************************************             //07-05-18|0x05a0
//******                                                               ******             //07-05-18|0x05a1
//******  Macro called macro                                           ******             //07-05-18|0x05a2
//******---------------------------------------------------------------******             //07-05-18|0x05a3
//******  Get calling line number and pop the stack                    ******             //07-05-18|0x05a4
//******                                                               ******             //07-05-18|0x05a5
//***************************************************************************             //07-05-18|0x05a6
      case 46226: // LINE_NO                                                              //07-05-18|0x05a7
        switch(GetRetLineNo)                                                              //07-05-18|0x05a7
        {                                                                                 //07-05-18|0x05a7
          case Success:                                                                   //07-05-18|0x05a7
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05a7
            ProcessCallReturnState = 57792; // MACRO_POP                                  //07-05-18|0x05a7
            break;                                                                        //07-05-18|0x05a7
          default:                                                                        //07-05-18|0x05a7
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05a7
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05a7
            SystemMsg;                                                                    //07-05-18|0x05a7
            break;                                                                        //07-05-18|0x05a7
        }                                                                                 //07-05-18|0x05a7
        break;                                                                            //07-05-18|0x05a7
//***************************************************************************             //07-05-18|0x05a8
      case 57792: // MACRO_POP                                                            //07-05-18|0x05a9
        switch(CallPop())                                                                 //07-05-18|0x05a9
        {                                                                                 //07-05-18|0x05a9
          case Success:                                                                   //07-05-18|0x05a9
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05a9
            ProcessCallReturnState = 65087; // GET_BRIDGE                                 //07-05-18|0x05a9
            break;                                                                        //07-05-18|0x05a9
          default:                                                                        //07-05-18|0x05a9
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05a9
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05a9
            SystemMsg;                                                                    //07-05-18|0x05a9
            break;                                                                        //07-05-18|0x05a9
        }                                                                                 //07-05-18|0x05a9
        break;                                                                            //07-05-18|0x05a9
//***************************************************************************             //07-05-18|0x05aa
//******                                                               ******             //07-05-18|0x05ab
//******  Macro called macro                                           ******             //07-05-18|0x05ac
//******---------------------------------------------------------------******             //07-05-18|0x05ad
//******  Restore the calling bridge                                   ******             //07-05-18|0x05ae
//******                                                               ******             //07-05-18|0x05af
//***************************************************************************             //07-05-18|0x05b0
      case 65087: // GET_BRIDGE                                                           //07-05-18|0x05b1
        switch(GetBridgeName)                                                             //07-05-18|0x05b1
        {                                                                                 //07-05-18|0x05b1
          case Success:                                                                   //07-05-18|0x05b1
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05b1
            ProcessCallReturnState = 58030; // FIND_BRIDGE                                //07-05-18|0x05b1
            break;                                                                        //07-05-18|0x05b1
          default:                                                                        //07-05-18|0x05b1
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05b1
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05b1
            SystemMsg;                                                                    //07-05-18|0x05b1
            break;                                                                        //07-05-18|0x05b1
        }                                                                                 //07-05-18|0x05b1
        break;                                                                            //07-05-18|0x05b1
//***************************************************************************             //07-05-18|0x05b2
      case 58030: // FIND_BRIDGE                                                          //07-05-18|0x05b3
        switch(FindRetBridge)                                                             //07-05-18|0x05b3
        {                                                                                 //07-05-18|0x05b3
          case Yes:                                                                       //07-05-18|0x05b3
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05b3
            ProcessCallReturnState = 3597; // GET_MACRO                                   //07-05-18|0x05b3
            break;                                                                        //07-05-18|0x05b3
          default:                                                                        //07-05-18|0x05b3
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05b3
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05b3
            SystemMsg;                                                                    //07-05-18|0x05b3
            break;                                                                        //07-05-18|0x05b3
        }                                                                                 //07-05-18|0x05b3
        break;                                                                            //07-05-18|0x05b3
//***************************************************************************             //07-05-18|0x05b4
//******                                                               ******             //07-05-18|0x05b5
//******  Macro called macro                                           ******             //07-05-18|0x05b6
//******---------------------------------------------------------------******             //07-05-18|0x05b7
//******  Get macro name, class name and restore calling user stack    ******             //07-05-18|0x05b8
//******                                                               ******             //07-05-18|0x05b9
//***************************************************************************             //07-05-18|0x05ba
      case 3597: // GET_MACRO                                                             //07-05-18|0x05bb
        switch(GetReturnName)                                                             //07-05-18|0x05bb
        {                                                                                 //07-05-18|0x05bb
          case Success:                                                                   //07-05-18|0x05bb
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05bb
            ProcessCallReturnState = 9852; // GET_CLASS                                   //07-05-18|0x05bb
            break;                                                                        //07-05-18|0x05bb
          default:                                                                        //07-05-18|0x05bb
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05bb
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05bb
            SystemMsg;                                                                    //07-05-18|0x05bb
            break;                                                                        //07-05-18|0x05bb
        }                                                                                 //07-05-18|0x05bb
        break;                                                                            //07-05-18|0x05bb
//***************************************************************************             //07-05-18|0x05bc
      case 9852: // GET_CLASS                                                             //07-05-18|0x05bd
        switch(GetClassName)                                                              //07-05-18|0x05bd
        {                                                                                 //07-05-18|0x05bd
          case Success:                                                                   //07-05-18|0x05bd
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05bd
            ProcessCallReturnState = 61276; // USER_STACK                                 //07-05-18|0x05bd
            break;                                                                        //07-05-18|0x05bd
          default:                                                                        //07-05-18|0x05bd
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05bd
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05bd
            SystemMsg;                                                                    //07-05-18|0x05bd
            break;                                                                        //07-05-18|0x05bd
        }                                                                                 //07-05-18|0x05bd
        break;                                                                            //07-05-18|0x05bd
//***************************************************************************             //07-05-18|0x05be
      case 61276: // USER_STACK                                                           //07-05-18|0x05bf
        switch(BeginStack)                                                                //07-05-18|0x05bf
        {                                                                                 //07-05-18|0x05bf
          case Success:                                                                   //07-05-18|0x05bf
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05bf
            ProcessCallReturnState = 58779; // RESTORE_REG                                //07-05-18|0x05bf
            break;                                                                        //07-05-18|0x05bf
          default:                                                                        //07-05-18|0x05bf
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05bf
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05bf
            SystemMsg;                                                                    //07-05-18|0x05bf
            break;                                                                        //07-05-18|0x05bf
        }                                                                                 //07-05-18|0x05bf
        break;                                                                            //07-05-18|0x05bf
//***************************************************************************             //07-07-05|0x05c0
      case 58779: // RESTORE_REG                                                          //07-07-05|0x05c1
        switch(PrecRegRestore())                                                          //07-07-05|0x05c1
        {                                                                                 //07-07-05|0x05c1
          case Success:                                                                   //07-07-05|0x05c1
            ProcessCallReturnRunFlag = 1;                                                 //07-07-05|0x05c1
            ProcessCallReturnState = 16330; // LABEL_NAME                                 //07-07-05|0x05c1
            break;                                                                        //07-07-05|0x05c1
          default:                                                                        //07-07-05|0x05c1
            ProcessCallReturnStatus = SystemError;                                        //07-07-05|0x05c1
            ProcessCallReturnRunFlag = 0;                                                 //07-07-05|0x05c1
            SystemMsg;                                                                    //07-07-05|0x05c1
            break;                                                                        //07-07-05|0x05c1
        }                                                                                 //07-07-05|0x05c1
        break;                                                                            //07-07-05|0x05c1
//***************************************************************************             //07-05-18|0x05c2
//******                                                               ******             //07-05-18|0x05c3
//******  Macro called macro                                           ******             //07-05-18|0x05c4
//******---------------------------------------------------------------******             //07-05-18|0x05c5
//******  Restart the calling macro at the return label                ******             //07-05-18|0x05c6
//******                                                               ******             //07-05-18|0x05c7
//***************************************************************************             //07-05-18|0x05c8
      case 16330: // LABEL_NAME                                                           //07-05-18|0x05c9
        switch(PrepRetLabel)                                                              //07-05-18|0x05c9
        {                                                                                 //07-05-18|0x05c9
          case Success:                                                                   //07-05-18|0x05c9
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05c9
            ProcessCallReturnState = 15593; // FIND_LABEL                                 //07-05-18|0x05c9
            break;                                                                        //07-05-18|0x05c9
          default:                                                                        //07-05-18|0x05c9
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05c9
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05c9
            SystemMsg;                                                                    //07-05-18|0x05c9
            break;                                                                        //07-05-18|0x05c9
        }                                                                                 //07-05-18|0x05c9
        break;                                                                            //07-05-18|0x05c9
//***************************************************************************             //07-05-18|0x05ca
      case 15593: // FIND_LABEL                                                           //07-05-18|0x05cb
        switch(FindLabel)                                                                 //07-05-18|0x05cb
        {                                                                                 //07-05-18|0x05cb
          case Success:                                                                   //07-05-18|0x05cb
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05cb
            ProcessCallReturnState = 3064; // TEST_EXIT                                   //07-05-18|0x05cb
            break;                                                                        //07-05-18|0x05cb
          default:                                                                        //07-05-18|0x05cb
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05cb
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05cb
            SystemMsg;                                                                    //07-05-18|0x05cb
            break;                                                                        //07-05-18|0x05cb
        }                                                                                 //07-05-18|0x05cb
        break;                                                                            //07-05-18|0x05cb
//***************************************************************************             //07-05-18|0x05cc
//******                                                               ******             //07-05-18|0x05cd
//******  MAKE THE PROPER EXIT                                         ******             //07-05-18|0x05ce
//******                                                               ******             //07-05-18|0x05cf
//***************************************************************************             //07-05-18|0x05d0
      case 3064: // TEST_EXIT                                                             //07-05-18|0x05d1
        switch(CallTestSrc())                                                             //07-05-18|0x05d1
        {                                                                                 //07-05-18|0x05d1
          case Yes:                                                                       //07-05-18|0x05d1
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05d1
            ProcessCallReturnState = 52215; // RESET_EXIT                                 //07-05-18|0x05d1
            break;                                                                        //07-05-18|0x05d1
          case No:                                                                        //07-05-18|0x05d1
            ProcessCallReturnRunFlag = 1;                                                 //07-05-18|0x05d1
            ProcessCallReturnState = 49707; // MACRO_EXIT                                 //07-05-18|0x05d1
            break;                                                                        //07-05-18|0x05d1
          default:                                                                        //07-05-18|0x05d1
            ProcessCallReturnStatus = SystemError;                                        //07-05-18|0x05d1
            ProcessCallReturnRunFlag = 0;                                                 //07-05-18|0x05d1
            SystemMsg;                                                                    //07-05-18|0x05d1
            break;                                                                        //07-05-18|0x05d1
        }                                                                                 //07-05-18|0x05d1
        break;                                                                            //07-05-18|0x05d1
//---------------------------------------------------------------------------             //07-09-19|0x05d2
      case 52215: // RESET_EXIT                                                           //07-09-19|0x05d3
        switch(CallResetMacro())                                                          //07-09-19|0x05d3
        {                                                                                 //07-09-19|0x05d3
          case Success:                                                                   //07-09-19|0x05d3
            ProcessCallReturnRunFlag = 1;                                                 //07-09-19|0x05d3
            ProcessCallReturnState = 35814; // LAST_EXIT                                  //07-09-19|0x05d3
            break;                                                                        //07-09-19|0x05d3
          default:                                                                        //07-09-19|0x05d3
            ProcessCallReturnStatus = SystemError;                                        //07-09-19|0x05d3
            ProcessCallReturnRunFlag = 0;                                                 //07-09-19|0x05d3
            SystemMsg;                                                                    //07-09-19|0x05d3
            break;                                                                        //07-09-19|0x05d3
        }                                                                                 //07-09-19|0x05d3
        break;                                                                            //07-09-19|0x05d3
//***************************************************************************             //07-05-18|0x05d4
      case 49707: // MACRO_EXIT                                                           //07-09-19|0x05d5
        ProcessCallReturnState = 63451; // MACRO_CALLED                                   //07-09-19|0x05d5
        ProcessCallReturnStatus = Continue;                                               //07-09-19|0x05d5
        ProcessCallReturnRunFlag = 0;                                                     //07-09-19|0x05d5
        break;                                                                            //07-09-19|0x05d5
//---------------------------------------------------------------------------             //07-05-18|0x05d6
      case 35814: // LAST_EXIT                                                            //07-05-21|0x05d7
        ProcessCallReturnState = 38989; // SOURCE_CALLED                                  //07-05-21|0x05d7
        ProcessCallReturnStatus = Continue;                                               //07-05-21|0x05d7
        ProcessCallReturnRunFlag = 0;                                                     //07-05-21|0x05d7
        break;                                                                            //07-05-21|0x05d7
//---------------------------------------------------------------------------             //07-05-18|0x05d8
      case 37612: // SOURCE_EXIT                                                          //07-05-21|0x05d9
        ProcessCallReturnState = 2286; // SOURCE_CALL                                     //07-05-21|0x05d9
        ProcessCallReturnStatus = LineDone;                                               //07-05-21|0x05d9
        ProcessCallReturnRunFlag = 0;                                                     //07-05-21|0x05d9
        break;                                                                            //07-05-21|0x05d9
//***************************************************************************             //07-05-21|0x05da
//******                                                               ******             //07-05-21|0x05db
//******  State Machine Ends                                           ******             //07-05-21|0x05dc
//******                                                               ******             //07-05-21|0x05dd
//***************************************************************************             //07-05-21|0x05de
      default:                                                                            //07-05-21|0x05df
        ProcessCallReturnStatus = SystemError;                                            //07-05-21|0x05df
        ProcessCallReturnRunFlag = 0;                                                     //07-05-21|0x05df
        SystemMsg;                                                                        //07-05-21|0x05df
        break;                                                                            //07-05-21|0x05df
    }                                                                                     //07-05-21|0x05df
  }                                                                                       //07-05-21|0x05df
//***************************************************************************             //07-05-21|0x05e0
//***************************************************************************             //07-05-21|0x05e1
    return(ProcessCallReturnStatus);                                                      //07-05-21|0x05e2
}                                                                                         //06-09-28|0x05e4
//                                                                                        //05-24-97|0x05e4
//***************************************************************************             //07-05-24|0x05e7
//***************************************************************************             //07-05-24|0x05e8
//******                                                               ******             //07-05-24|0x05e9
//******                         utility_bridge                        ******             //07-05-24|0x05ea
//******                                                               ******             //07-05-24|0x05eb
//***************************************************************************             //07-05-24|0x05ec
//***************************************************************************             //07-05-24|0x05ed
//*******************************************************************************         //10-29-97|0x05f2
//*******************************************************************************         //10-29-97|0x05f2
// utility_bridge                                                                         //07-05-24|0x05f2
//*******************************************************************************         //10-29-97|0x05f2
//*******************************************************************************         //10-29-97|0x05f2
UINT PRECOPER::utility_bridge(                                                            //07-05-24|0x05f2
    PROCESS_DATA_FAR ProcessDataFar                                                       //07-05-24|0x05f2
    ) {                                                                                   //07-05-24|0x05f2
//*******************************************************************************         //10-29-97|0x05f2
//***************************************************************************             //07-05-24|0x05f5
//***************************************************************************             //07-05-24|0x05f6
    MemSet(ProcessUtilityBridgeAddr, 0x00, sizeof(STRING_DATA));                          //07-05-24|0x05f7
    UtilityBridgeLength = MacroNameLength + ClassNameLength;                              //07-05-24|0x05f8
    if(UtilityBridgeLength >= 256)                         ReturnSystemError;             //07-05-24|0x05f9
    StrCpy(UtilityBridgeLineAddr, ClassNameLineAddr);                                     //07-05-24|0x05fa
    StrCat(UtilityBridgeLineAddr, MacroNameLineAddr);                                     //07-05-24|0x05fb
    return_test(utility_bridge_1);                                                        //07-05-24|0x05fc
}                                                                                         //07-05-24|0x05fd
//                                                                                        //05-24-97|0x05fd
//***************************************************************************             //07-05-18|0x0600
//***************************************************************************             //07-05-18|0x0601
//******                                                               ******             //07-05-18|0x0602
//******                                return_label                   ******             //07-05-18|0x0603
//******                                                               ******             //07-05-18|0x0604
//***************************************************************************             //07-05-18|0x0605
//***************************************************************************             //07-05-18|0x0606
//*******************************************************************************         //10-29-97|0x060d
//*******************************************************************************         //10-29-97|0x060d
// return_label                                                                           //07-05-18|0x060d
//*******************************************************************************         //10-29-97|0x060d
//*******************************************************************************         //10-29-97|0x060d
UINT PRECOPER::return_label(                                                              //07-05-18|0x060d
    PROCESS_DATA_FAR ProcessDataFar,                                                      //07-05-18|0x060d
    UINT ReturnLineNo                                                                     //07-05-18|0x060d
    ) {                                                                                   //07-05-18|0x060d
//*******************************************************************************         //10-29-97|0x060d
//***************************************************************************             //07-05-18|0x0610
//***************************************************************************             //07-05-18|0x0611
  SCHAR work[16];                                                                    //07-05-18|0x0612
//***************************************************************************             //07-05-18|0x0613
//***************************************************************************             //07-05-18|0x0614
    StrDataCpy(ProcessResultsAddr,   ProcessMacroNameAddr);                               //07-05-18|0x0615
//---------------------------------------------------------------------------             //07-05-18|0x0616
    if(ResultsLength >= 244)                               ReturnSystemError;             //07-05-18|0x0617
    sprintf(&work[0], " 0x%08x", ReturnLineNo);                                           //07-05-18|0x0618
    StrCat(ResultsLineAddr, &work[0]);                                                    //07-05-18|0x0619
    ResultsLength += 11;                                                                  //07-05-18|0x061a
    ResultsType    = I_TOKEN;                                                             //07-05-18|0x061b
    return_test(return_label_1);                                                          //07-05-18|0x061c
}                                                                                         //07-05-18|0x061e
//                                                                                        //05-24-97|0x061e
//***************************************************************************             //08-01-09|0x0621
//***************************************************************************             //08-01-09|0x0622
//******                                                               ******             //08-01-09|0x0623
//******                           auto_debug_on                       ******             //08-01-09|0x0624
//******                                                               ******             //08-01-09|0x0625
//***************************************************************************             //08-01-09|0x0626
//***************************************************************************             //08-01-09|0x0627
//*******************************************************************************         //10-29-97|0x062f
//*******************************************************************************         //10-29-97|0x062f
// auto_debug_on                                                                          //08-01-09|0x062f
//*******************************************************************************         //10-29-97|0x062f
//*******************************************************************************         //10-29-97|0x062f
UINT PRECOPER::auto_debug_on(                                                             //08-01-09|0x062f
    PROCESS_DATA_FAR ProcessDataFar                                                       //08-01-09|0x062f
    ) {                                                                                   //08-01-09|0x062f
//*******************************************************************************         //10-29-97|0x062f
//***************************************************************************             //08-01-09|0x0632
//***************************************************************************             //08-01-09|0x0633
    switch(basic_debug_on(ProcessDataFar))                                                //08-01-09|0x0634
      {                                                                                   //08-01-09|0x0635
//***************************************************************************             //08-01-09|0x0636
        case Yes:                                                                         //08-01-09|0x0637
          if(MacroNameLength >= 50)                                                       //08-01-09|0x0638
            {                                                                             //08-01-09|0x0639
              sprintf(DebugNameLineAddr, "%.50s-%d",                                      //08-01-09|0x063a
                      MacroNameLineAddr, TokensMacroLineNo(0));                           //08-01-09|0x063b
              }                                                                           //08-01-09|0x063c
            else {                                                                        //08-01-09|0x063d
              sprintf(DebugNameLineAddr, "%s-%d",                                         //08-01-09|0x063e
                      MacroNameLineAddr, TokensMacroLineNo(0));                           //08-01-09|0x063f
              }                                                                           //08-01-09|0x0640
          if(TruncStringSize(&DebugNameLength,  DebugNameLineAddr)                        //check   |0x0641
                                              != Success)   ReturnSystemError;             //check   |0x0642
          DebugNameMacroLineNo = TokensMacroLineNo(0);                                    //08-01-09|0x0643
          return_test(auto_debug_on_1);                                                   //08-01-09|0x0644
//***************************************************************************             //08-01-09|0x0645
        case No:                               return_test(auto_debug_on_2);              //08-01-09|0x0646
//***************************************************************************             //08-01-09|0x0647
        default:                                          ReturnSystemError;              //08-01-09|0x0648
        }                                                                                 //08-01-09|0x0649
}                                                                                         //07-05-18|0x064c
//                                                                                        //05-24-97|0x064c
//***************************************************************************             //08-01-08|0x064f
//***************************************************************************             //08-01-08|0x0650
//******                                                               ******             //08-01-08|0x0651
//******                                debug_on                       ******             //08-01-08|0x0652
//******                                                               ******             //08-01-08|0x0653
//***************************************************************************             //08-01-08|0x0654
//***************************************************************************             //08-01-08|0x0655
//*******************************************************************************         //10-29-97|0x065d
//*******************************************************************************         //10-29-97|0x065d
// debug_on                                                                               //08-01-08|0x065d
//*******************************************************************************         //10-29-97|0x065d
//*******************************************************************************         //10-29-97|0x065d
UINT PRECOPER::debug_on(                                                                  //08-01-08|0x065d
    PROCESS_DATA_FAR ProcessDataFar,                                                      //08-01-08|0x065d
    STRING_DATA_FAR StringFar                                                             //08-01-08|0x065d
    ) {                                                                                   //08-01-08|0x065d
//*******************************************************************************         //10-29-97|0x065d
//***************************************************************************             //08-01-08|0x0660
//***************************************************************************             //08-01-08|0x0661
    switch(basic_debug_on(ProcessDataFar))                                                //08-01-08|0x0662
      {                                                                                   //08-01-08|0x0663
//***************************************************************************             //08-01-08|0x0664
        case Yes:                                                                         //08-01-08|0x0665
          StrDataCpy(&ProcessDebugName, StringFar);                                       //08-01-08|0x0666
          return_test(debug_on_1);                                                        //08-01-08|0x0667
//***************************************************************************             //08-01-08|0x0668
        case No:                                    return_test(debug_on_2);              //08-01-08|0x0669
//***************************************************************************             //08-01-08|0x066a
        default:                                          ReturnSystemError;              //08-01-08|0x066b
        }                                                                                 //08-01-08|0x066c
}                                                                                         //07-05-18|0x066f
//                                                                                        //05-24-97|0x066f
//***************************************************************************             //08-01-08|0x0673
//***************************************************************************             //08-01-08|0x0674
//******                                                               ******             //08-01-08|0x0675
//******                          basic_debug_on                       ******             //08-01-08|0x0676
//******                                                               ******             //08-01-08|0x0677
//***************************************************************************             //08-01-08|0x0678
//***************************************************************************             //08-01-08|0x0679
//*******************************************************************************         //10-29-97|0x0682
//*******************************************************************************         //10-29-97|0x0682
// basic_debug_on                                                                         //08-01-08|0x0682
//*******************************************************************************         //10-29-97|0x0682
//*******************************************************************************         //10-29-97|0x0682
UINT PRECOPER::basic_debug_on(                                                            //08-01-08|0x0682
    PROCESS_DATA_FAR ProcessDataFar                                                       //08-01-08|0x0682
    ) {                                                                                   //08-01-08|0x0682
//*******************************************************************************         //10-29-97|0x0682
//***************************************************************************             //08-01-08|0x0685
//***************************************************************************             //08-01-08|0x0686
    switch(ProcessFlagState)                                                              //08-01-08|0x0687
      {                                                                                   //08-01-08|0x0688
//***************************************************************************             //08-01-08|0x0689
        case -2:                                                                          //08-01-08|0x068a
        case -1:                                                                          //08-01-08|0x068b
        case  0:                                                                          //08-01-08|0x068c
        case  1:                                                                          //08-01-08|0x068d
          switch(ProcessDebugCommand)                                                     //08-01-08|0x068e
            {                                                                             //08-01-08|0x068f
//---------------------------------------------------------------------------             //08-01-08|0x0690
              case DBG_OFF:                                                               //08-01-08|0x0691
                ProcessDebugCommand = DBG_ON;                                             //08-01-08|0x0692
                return_yes(basic_debug_on_1);                                             //08-01-08|0x0693
//---------------------------------------------------------------------------             //08-01-08|0x0694
              case DBG_ON:                                                                //08-01-08|0x0695
                return_yes(basic_debug_on_2);                                             //08-01-08|0x0696
//---------------------------------------------------------------------------             //08-01-08|0x0697
              default:                                    ReturnSystemError;              //08-01-08|0x0698
              }                                                                           //08-01-08|0x0699
//***************************************************************************             //08-01-08|0x069a
        case 2:                                 return_no(basic_debug_on_3);              //08-01-08|0x069b
//***************************************************************************             //08-01-08|0x069c
        default:                                          ReturnSystemError;              //08-01-08|0x069d
        }                                                                                 //08-01-08|0x069e
}                                                                                         //07-05-18|0x06a1
//                                                                                        //05-24-97|0x06a1
//***************************************************************************             //06-09-28|0x06a5
//***************************************************************************             //06-09-28|0x06a6
//******                                                               ******             //06-09-28|0x06a7
//******                                label_prepare                  ******             //06-09-28|0x06a8
//******                                                               ******             //06-09-28|0x06a9
//***************************************************************************             //06-09-28|0x06aa
//***************************************************************************             //06-09-28|0x06ab
//*******************************************************************************         //10-29-97|0x06b2
//*******************************************************************************         //10-29-97|0x06b2
// label_prepare                                                                          //06-09-28|0x06b2
//*******************************************************************************         //10-29-97|0x06b2
//*******************************************************************************         //10-29-97|0x06b2
UINT PRECOPER::label_prepare(                                                             //06-09-28|0x06b2
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-09-28|0x06b2
    ) {                                                                                   //06-09-28|0x06b2
//*******************************************************************************         //10-29-97|0x06b2
//***************************************************************************             //06-09-28|0x06b5
//***************************************************************************             //06-09-28|0x06b6
  ULONG Size;                                                                        //06-09-28|0x06b7
//***************************************************************************             //06-09-28|0x06b8
//***************************************************************************             //06-09-28|0x06b9
    StrDataCpy(ProcessResultsAddr,   ProcessMacroNameAddr);                               //07-04-28|0x06ba
//---------------------------------------------------------------------------             //06-09-28|0x06bb
    switch(PrecformNameTest(TokensTokenAddr(1)))                                          //06-09-28|0x06bc
      {                                                                                   //06-09-28|0x06bd
        case Success:                                                  break;             //06-09-28|0x06be
        case UserError:                 ReturnFinish("Label Must Be A Name");             //06-09-28|0x06bf
        case SystemError:                                  ReturnSystemError;             //06-09-28|0x06c0
        }                                                                                 //06-09-28|0x06c1
//***************************************************************************             //06-09-28|0x06c2
    if(TokensChar(1,TokensLength(1))  != 0)                ReturnSystemError;             //06-09-28|0x06c3
    if(ResultsChar(ResultsLength)     != 0)                ReturnSystemError;             //06-09-28|0x06c4
//---------------------------------------------------------------------------             //06-09-28|0x06c5
    Size  = TokensLength(1);                                                              //06-09-28|0x06c6
    Size += 1;                                                                            //06-09-28|0x06c7
    Size += ResultsLength;                                                                //06-09-28|0x06c8
    if(Size >= 255)                   ReturnFinish("Label Name is too long");             //06-09-28|0x06c9
//---------------------------------------------------------------------------             //06-09-28|0x06ca
    StrCat(ResultsLineAddr, " ");                                                         //06-09-28|0x06cb
    StrCat(ResultsLineAddr, TokensLineAddr(1));                                           //06-09-28|0x06cc
//---------------------------------------------------------------------------             //06-09-28|0x06cd
    ResultsLength += 1;                                                                   //06-09-28|0x06ce
    ResultsLength += TokensLength(1);                                                     //06-09-28|0x06cf
    ResultsType    = I_TOKEN;                                                             //06-09-28|0x06d0
//---------------------------------------------------------------------------             //06-09-28|0x06d1
    if(ResultsChar(ResultsLength) != 0)                    ReturnSystemError;             //06-09-28|0x06d2
    if(Size != StrLen(ResultsLineAddr))                    ReturnSystemError;             //06-09-28|0x06d3
    return_test(label_prepare_1);                                                         //06-09-28|0x06d4
}                                                                                         //06-09-28|0x06d5
//                                                                                        //05-24-97|0x06d5
//***************************************************************************             //07-05-18|0x06d8
//***************************************************************************             //07-05-18|0x06d9
//******                                                               ******             //07-05-18|0x06da
//******                       class_search                            ******             //07-05-18|0x06db
//******                                                               ******             //07-05-18|0x06dc
//***************************************************************************             //07-05-18|0x06dd
//***************************************************************************             //07-05-18|0x06de
//*******************************************************************************         //10-29-97|0x06e7
//*******************************************************************************         //10-29-97|0x06e7
// class_search                                                                           //07-05-18|0x06e7
//*******************************************************************************         //10-29-97|0x06e7
//*******************************************************************************         //10-29-97|0x06e7
UINT PRECOPER::class_search(                                                              //07-05-18|0x06e7
    PROCESS_DATA_FAR ProcessDataFar                                                       //07-05-18|0x06e7
    ) {                                                                                   //07-05-18|0x06e7
//*******************************************************************************         //10-29-97|0x06e7
//***************************************************************************             //07-05-18|0x06ea
//***************************************************************************             //07-05-18|0x06eb
    switch(MacDictMacroEnd())                                    _SwitchGroup             //07-07-18|0x06ec
//***************************************************************************             //07-05-18|0x06ed
    switch(FindTestClass)                                                                 //07-07-18|0x06ee
      {                                                                                   //07-07-18|0x06ef
        case Yes:                                                                         //07-07-18|0x06f0
          switch(FindResetClass)                                                          //07-07-18|0x06f1
            {                                                                             //07-07-18|0x06f2
              case Yes:                                                break;             //07-07-18|0x06f3
              default:                                     ReturnSystemError;             //07-07-18|0x06f4
              }                                                                           //07-07-18|0x06f5
          ProcessFlagState = 1;                   break_test(class_search_1);             //07-07-18|0x06f6
//---------------------------------------------------------------------------             //07-05-18|0x06f7
        case No:  ProcessFlagState = -1;          break_test(class_search_2);             //07-07-18|0x06f8
        default:                                           ReturnSystemError;             //07-07-18|0x06f9
        }                                                                                 //07-07-18|0x06fa
//***************************************************************************             //07-05-18|0x06fb
    StrDataCpy(ProcessResultsAddr, ProcessMacroNameAddr);                                 //07-07-18|0x06fc
    if(PrepClassLabel != Success)                          ReturnSystemError;             //07-07-18|0x06fd
    if(FindLabel      != Success)                          ReturnSystemError;             //07-07-18|0x06fe
    return_test(class_search_3);                                                          //06-09-28|0x06ff
}                                                                                         //07-05-18|0x0700
//                                                                                        //05-24-97|0x0700
//***************************************************************************             //07-05-04|0x0703
//***************************************************************************             //07-05-04|0x0704
//******                                                               ******             //07-05-04|0x0705
//******                        dict_in                                ******             //07-05-04|0x0706
//******                                                               ******             //07-05-04|0x0707
//***************************************************************************             //07-05-04|0x0708
//***************************************************************************             //07-05-04|0x0709
//*******************************************************************************         //10-29-97|0x0710
//*******************************************************************************         //10-29-97|0x0710
// dict_in                                                                                //07-05-04|0x0710
//*******************************************************************************         //10-29-97|0x0710
//*******************************************************************************         //10-29-97|0x0710
UINT PRECOPER::dict_in(                                                                   //07-05-04|0x0710
    PROCESS_DATA_FAR ProcessDataFar,                                                      //07-05-04|0x0710
    UINT TokenNo                                                                          //07-05-04|0x0710
    ) {                                                                                   //07-05-04|0x0710
//*******************************************************************************         //10-29-97|0x0710
//***************************************************************************             //07-05-04|0x0713
//***************************************************************************             //07-05-04|0x0714
  UINT size;                                                                         //07-05-04|0x0715
//***************************************************************************             //07-05-04|0x0716
//***************************************************************************             //07-05-04|0x0717
    MemSet(ProcessDictAddr, 0x00,              sizeof(TOKENS));                           //07-05-04|0x0718
    MemCpy(ProcessDictAddr, ProcessTokensAddr, sizeof(TOKENS));                           //07-05-04|0x0719
//***************************************************************************             //07-05-04|0x071a
    if(DictChar(TokenNo, DictLength(TokenNo))   != 0)       ReturnSystemError             //07-05-04|0x071b
    if(DictChar(TokenNo, DictLength(TokenNo)+1) != 0)       ReturnSystemError             //07-05-04|0x071c
    if(ClassNameChar(ClassNameLength)           != 0)       ReturnSystemError             //07-05-04|0x071d
//***************************************************************************             //07-05-04|0x071e
    size  = DictLength(TokenNo);                                                          //07-05-04|0x071f
    size += 1;                                                                            //07-05-04|0x0720
    size += ClassNameLength;                                                              //07-05-04|0x0721
//---------------------------------------------------------------------------             //07-05-04|0x0722
    if(size >= 256)        ReturnFinish("Class + Dictionary Name Too Large");             //07-05-04|0x0723
//***************************************************************************             //07-05-04|0x0724
    DictChar(TokenNo, DictLength(TokenNo)) = 0x09;                                        //07-05-04|0x0725
//---------------------------------------------------------------------------             //07-05-04|0x0726
    StrCat(DictLineAddr(TokenNo), ClassNameLineAddr);                                     //07-05-04|0x0727
    DictLength(TokenNo) = size;                                                           //07-05-04|0x0728
//---------------------------------------------------------------------------             //07-05-04|0x0729
    if(DictChar(TokenNo, DictLength(TokenNo))   != 0)       ReturnSystemError             //07-05-04|0x072a
//***************************************************************************             //07-05-04|0x072b
    return_test(dict_in_1);                                                               //07-05-04|0x072c
}                                                                                         //07-05-04|0x072d
//                                                                                        //05-24-97|0x072d
//***************************************************************************             //09-03-19|0x0730
//***************************************************************************             //09-03-19|0x0731
//******                                                               ******             //09-03-19|0x0732
//******                        string_in_reg                          ******             //09-03-19|0x0733
//******                                                               ******             //09-03-19|0x0734
//***************************************************************************             //09-03-19|0x0735
//***************************************************************************             //09-03-19|0x0736
//*******************************************************************************         //10-29-97|0x073d
//*******************************************************************************         //10-29-97|0x073d
// string_in_reg                                                                          //09-03-19|0x073d
//*******************************************************************************         //10-29-97|0x073d
//*******************************************************************************         //10-29-97|0x073d
UINT PRECOPER::string_in_reg(                                                             //09-03-19|0x073d
    PROCESS_DATA_FAR ProcessDataFar                                                       //09-03-19|0x073d
    ) {                                                                                   //09-03-19|0x073d
//*******************************************************************************         //10-29-97|0x073d
//***************************************************************************             //09-03-19|0x0740
//***************************************************************************             //09-03-19|0x0741
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-19|0x0742
    if(TokensNoTokens   != 2)                               ReturnSystemError             //09-03-19|0x0743
//***************************************************************************             //09-03-19|0x0744
    switch(TextRegIn)                                            _SwitchGroup             //09-03-19|0x0745
    switch(ClearRegIn)                                           _SwitchGroup             //09-03-19|0x0746
//***************************************************************************             //09-03-19|0x0747
    return_test(string_in_reg_1);                                                         //09-03-19|0x0748
}                                                                                         //09-03-19|0x0749
//                                                                                        //05-24-97|0x0749
//***************************************************************************             //06-11-19|0x074c
//***************************************************************************             //06-11-19|0x074d
//******                                                               ******             //06-11-19|0x074e
//******                        numeric_in_data                        ******             //06-11-19|0x074f
//******                                                               ******             //06-11-19|0x0750
//***************************************************************************             //06-11-19|0x0751
//***************************************************************************             //06-11-19|0x0752
//*******************************************************************************         //10-29-97|0x0759
//*******************************************************************************         //10-29-97|0x0759
// numeric_in_data                                                                        //06-11-19|0x0759
//*******************************************************************************         //10-29-97|0x0759
//*******************************************************************************         //10-29-97|0x0759
UINT PRECOPER::numeric_in_data(                                                           //06-11-19|0x0759
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-11-19|0x0759
    ) {                                                                                   //06-11-19|0x0759
//*******************************************************************************         //10-29-97|0x0759
//***************************************************************************             //06-11-19|0x075a
//***************************************************************************             //06-11-19|0x075b
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //06-11-19|0x075c
    if(TokensNoTokens   != 3)                               ReturnSystemError             //06-11-19|0x075d
//***************************************************************************             //06-11-19|0x075e
    switch(TokensPrepare(ProcessTokensAddr, 2))                  _SwitchGroup             //06-11-19|0x075f
//***************************************************************************             //06-11-19|0x0760
    switch(NumTextIn(2))                                         _SwitchGroup             //06-11-19|0x0761
    if(ParmNumType == 0)    ReturnFinish("Numeric Conersion -- Parameter 2");             //06-11-19|0x0762
//***************************************************************************             //06-11-19|0x0763
    return_test(numeric_in_data_1);                                                       //06-11-19|0x0764
}                                                                                         //06-11-19|0x0765
//                                                                                        //05-24-97|0x0765
//***************************************************************************             //10-08-27|0x0768
//***************************************************************************             //10-08-27|0x0769
//******                                                               ******             //10-08-27|0x076a
//******                        write_crlf                             ******             //10-08-27|0x076b
//******                                                               ******             //10-08-27|0x076c
//***************************************************************************             //10-08-27|0x076d
//***************************************************************************             //10-08-27|0x076e
//*******************************************************************************         //10-29-97|0x0776
//*******************************************************************************         //10-29-97|0x0776
// write_crlf                                                                             //10-08-27|0x0776
//*******************************************************************************         //10-29-97|0x0776
//*******************************************************************************         //10-29-97|0x0776
UINT PRECOPER::write_crlf(                                                                //10-08-27|0x0776
    PROCESS_DATA_FAR ProcessDataFar                                                       //10-08-27|0x0776
    ) {                                                                                   //10-08-27|0x0776
//*******************************************************************************         //10-29-97|0x0776
//***************************************************************************             //10-08-27|0x0777
//***************************************************************************             //10-08-27|0x0778
    switch(ProcessDebugCommand)                                                           //10-08-27|0x0779
      {                                                                                   //10-08-27|0x077a
        case DBG_ON:                                                                      //10-08-27|0x077b
          switch(WriteDbug)                                                               //10-08-27|0x077c
            {                                                                             //10-08-27|0x077d
              case Success:   switch(FileRelease())             _SwitchBreak;             //10-08-27|0x077e
              case UserError: switch(FileRelease())             _SwitchGroup;             //10-08-27|0x077f
                              return(UserError);                                          //10-08-27|0x0780
              default:                                      ReturnSystemError             //10-08-27|0x0781
              }                                                                           //10-08-27|0x0782
          return_test(write_crlf_1);                                                      //10-08-27|0x0783
//***************************************************************************             //10-08-27|0x0784
        case DBG_OFF:                                                                     //10-08-27|0x0785
          switch(WriteCRLF)                                                               //10-08-27|0x0786
            {                                                                             //10-08-27|0x0787
              case Success:   switch(FileRelease())             _SwitchBreak;             //10-08-27|0x0788
              case UserError: switch(FileRelease())             _SwitchGroup;             //10-08-27|0x0789
                              return(UserError);                                          //10-08-27|0x078a
              default:                                      ReturnSystemError             //10-08-27|0x078b
              }                                                                           //10-08-27|0x078c
          return_test(write_crlf_2);                                                      //10-08-27|0x078d
//***************************************************************************             //10-08-27|0x078e
        default:                                            ReturnSystemError             //10-08-27|0x078f
        }                                                                                 //10-08-27|0x0790
}                                                                                         //10-08-27|0x0791
//                                                                                        //05-24-97|0x0791
//***************************************************************************             //10-08-27|0x0794
//***************************************************************************             //10-08-27|0x0795
//******                                                               ******             //10-08-27|0x0796
//******                        write_output                           ******             //10-08-27|0x0797
//******                                                               ******             //10-08-27|0x0798
//***************************************************************************             //10-08-27|0x0799
//***************************************************************************             //10-08-27|0x079a
//*******************************************************************************         //10-29-97|0x07a3
//*******************************************************************************         //10-29-97|0x07a3
// write_output                                                                           //10-08-27|0x07a3
//*******************************************************************************         //10-29-97|0x07a3
//*******************************************************************************         //10-29-97|0x07a3
UINT PRECOPER::write_output(                                                              //10-08-27|0x07a3
    PROCESS_DATA_FAR ProcessDataFar,                                                      //10-08-27|0x07a3
    PROCESS_FILES_FAR ProcessFilesFar                                                     //10-08-27|0x07a3
    ) {                                                                                   //10-08-27|0x07a3
//*******************************************************************************         //10-29-97|0x07a3
//***************************************************************************             //10-08-27|0x07a4
//***************************************************************************             //10-08-27|0x07a5
    switch(CommitOut(ParmNumUlong))                              _SwitchGroup             //10-08-27|0x07a6
//***************************************************************************             //10-08-27|0x07a7
    switch(WriteText(TokensTokenAddr(2)))                                                 //10-08-27|0x07a8
      {                                                                                   //10-08-27|0x07a9
        case Success:                             break_test(write_output_1);             //10-08-27|0x07aa
        case UserError: switch(FileRelease())                   _SwitchGroup;             //10-08-27|0x07ab
                        return(UserError);                                                //10-08-27|0x07ac
        default:                                            ReturnSystemError             //10-08-27|0x07ad
        }                                                                                 //10-08-27|0x07ae
//***************************************************************************             //10-08-27|0x07af
    switch(write_crlf(ProcessDataFar))                           _SwitchGroup             //10-08-27|0x07b0
    return_test(write_output_2);                                                          //10-08-27|0x07b1
}                                                                                         //10-08-27|0x07b2
//                                                                                        //05-24-97|0x07b2
//***************************************************************************             //13-07-25|0x07b5
//***************************************************************************             //13-07-25|0x07b6
//******                                                               ******             //13-07-25|0x07b7
//******                        segment_out                            ******             //13-07-25|0x07b8
//******                                                               ******             //13-07-25|0x07b9
//***************************************************************************             //13-07-25|0x07ba
//***************************************************************************             //13-07-25|0x07bb
//*******************************************************************************         //10-29-97|0x07c4
//*******************************************************************************         //10-29-97|0x07c4
// segment_out                                                                            //13-07-25|0x07c4
//*******************************************************************************         //10-29-97|0x07c4
//*******************************************************************************         //10-29-97|0x07c4
UINT PRECOPER::segment_out(                                                               //13-07-25|0x07c4
    PROCESS_DATA_FAR ProcessDataFar,                                                      //13-07-25|0x07c4
    PROCESS_FILES_FAR ProcessFilesFar,                                                    //13-07-25|0x07c4
    UINT FileNo                                                                           //13-07-25|0x07c4
    ) {                                                                                   //13-07-25|0x07c4
//*******************************************************************************         //10-29-97|0x07c4
//***************************************************************************             //13-07-25|0x07c5
//***************************************************************************             //13-07-25|0x07c6
    if(TokensNoTokens   != 3)                               ReturnSystemError             //13-07-25|0x07c7
    if(FileOutStatus(FileNo) > 2)                          ReturnSystemError;             //13-07-25|0x07c8
    FileOutStatus(FileNo) = 2;                                                            //13-07-25|0x07c9
//***************************************************************************             //13-07-25|0x07ca
    StrDataCpy(ProcessResultsAddr,  TokensTokenAddr(2));                                  //13-07-25|0x07cc
//***************************************************************************             //13-07-25|0x07cd
//****                                                               ********             //13-07-25|0x07ce
//**** DETERMINE ARGUMENT TYPE                                       ********             //13-07-25|0x07cf
//****                                                               ********             //13-07-25|0x07d0
//***************************************************************************             //13-07-25|0x07d1
    switch(ResultsType)                                                                   //13-07-25|0x07d2
      {                                                                                   //13-07-25|0x07d3
//***************************************************************************             //13-07-25|0x07d4
//****                                                               ********             //13-07-25|0x07d5
//**** PROCESS SINGLE BYTE NUMBERS                                   ********             //13-07-25|0x07d6
//****                                                               ********             //13-07-25|0x07d7
//***************************************************************************             //13-07-25|0x07d8
        case I_NAME:                                                                      //13-07-25|0x07d9
          switch(NumResultsIn)                                   _SwitchGroup             //13-07-25|0x07da
          switch(ResultNumType)                                                           //13-07-25|0x07db
            {                                                                             //13-07-25|0x07dc
//---------------------------------------------------------------------------             //13-07-25|0x07dd
              case 1:                                                                     //13-07-25|0x07de
                if(ResultNumChar0 == 0x0a)                                                //13-07-25|0x07df
                  {                                                                       //13-07-25|0x07e0
                    switch(CommitOut(FileNo))                    _SwitchGroup             //13-07-25|0x07e1
                    switch(write_crlf(ProcessDataFar))           _SwitchGroup             //13-07-25|0x07e2
                    FileOutStatus(FileNo) = 1;                                            //13-07-25|0x07e3
                    return_test(segment_out_1);                                           //13-07-25|0x07e4
                    }                                                                     //13-07-25|0x07e5
//---------------------------------------------------------------------------             //13-07-25|0x07e6
                if(((ResultNumChar0 > 31) &&                                              //13-07-25|0x07e7
                    (ResultNumChar0 < 127)) ||                                            //13-07-25|0x07e8
                    (ResultNumChar0 == 0x0d))                                             //13-07-25|0x07e9
                                          ReturnFinish("Illegal Byte Value");             //13-07-25|0x07ea
                MemSet(ProcessBufferAddr, 0, sizeof(STRING_DATA));                        //13-07-25|0x07eb
                BufferChar(0) = ResultNumChar0;                                           //10-09-01|0x07ec
                BufferLength  = 1;                                                        //10-09-01|0x07ed
                switch(CommitOut(FileNo))                        _SwitchGroup             //10-09-01|0x07ee
                switch(WriteText(ProcessBufferAddr))             _SwitchGroup             //10-09-01|0x07ef
                switch(FileRelease())                            _SwitchGroup             //10-09-01|0x07f0
                return_test(segment_out_2);                                               //10-09-01|0x07f1
//---------------------------------------------------------------------------             //10-08-31|0x07f2
              case 0:                     ReturnFinish("Numeric Conversion");             //10-08-31|0x07f3
              case 2:  case 4:          ReturnFinish("Illegal Numeric Size");             //10-08-31|0x07f4
              default:                                      ReturnSystemError             //10-08-31|0x07f5
              }                                                                           //10-08-31|0x07f6
//***************************************************************************             //13-07-25|0x07f7
//****                                                               ********             //13-07-25|0x07f8
//**** PROCESS TEXT AND STRING                                       ********             //13-07-25|0x07f9
//****                                                               ********             //13-07-25|0x07fa
//***************************************************************************             //13-07-25|0x07fb
        case I_TOKEN:                                                                     //13-07-25|0x07fc
        case I_STRING:                                                                    //13-07-25|0x07fd
          if(ResultsLength >= 255)                          ReturnSystemError             //13-07-25|0x07fe
          if(ResultsChar(ResultsLength))                    ReturnSystemError             //13-07-25|0x07ff
//---------------------------------------------------------------------------             //13-07-25|0x0800
          switch(CommitOut(FileNo))                              _SwitchGroup             //13-07-25|0x0801
          switch(WriteText(ProcessResultsAddr))                  _SwitchGroup             //13-07-25|0x0802
          switch(FileRelease())                                  _SwitchGroup             //13-07-25|0x0803
          return_test(segment_out_3);                                                     //13-07-25|0x0804
//***************************************************************************             //13-07-25|0x0805
        default:                                            ReturnSystemError             //13-07-25|0x0806
        }                                                                                 //13-07-25|0x0807
}                                                                                         //13-07-25|0x0808
//                                                                                        //05-24-97|0x0808
//***************************************************************************             //check   |0x080b
//***************************************************************************             //check   |0x080c
//******                                                               ******             //check   |0x080d
//******                        segment_in                             ******             //check   |0x080e
//******                                                               ******             //check   |0x080f
//***************************************************************************             //check   |0x0810
//***************************************************************************             //check   |0x0811
//*******************************************************************************         //10-29-97|0x0818
//*******************************************************************************         //10-29-97|0x0818
// segment_in                                                                             //check   |0x0818
//*******************************************************************************         //10-29-97|0x0818
//*******************************************************************************         //10-29-97|0x0818
UINT PRECOPER::segment_in(                                                                //check   |0x0818
    PROCESS_DATA_FAR ProcessDataFar,                                                      //check   |0x0818
    UINT MaxSize                                                                          //check   |0x0818
    ) {                                                                                   //check   |0x0818
//*******************************************************************************         //10-29-97|0x0818
//***************************************************************************             //check   |0x0819
  if((MaxSize == 0) || (MaxSize > 255))     ReturnFinish("Illegal Max Size");             //check   |0x081a
//***************************************************************************             //check   |0x081b
  MemSet(ProcessBufferAddr, 0, sizeof(STRING_DATA));                                      //check   |0x081c
  switch(FileReadTextSegment(MaxSize,   ProcessBufferAddr))                               //check   |0x081d
    {                                                                                     //check   |0x081e
//---------------------------------------------------------------------------             //check   |0x081f
        case LineDone:                                                                    //check   |0x0820
        case Yes:                                                                         //check   |0x0821
        case No:                                                                          //check   |0x0822
          if(BufferLength != 1)                           ReturnSystemError;              //check   |0x0823
          ResultNumType    = 1;                                                           //check   |0x0824
          ResultNumChar0   = BufferChar(0);                                               //check   |0x0825
          switch(NumericRegOut)                                  _SwitchGroup             //check   |0x0826
          return_no(segment_in_1);                                                        //check   |0x0827
//---------------------------------------------------------------------------             //check   |0x0828
        case Continue:                                                                    //check   |0x0829
        case Success:                                                                     //check   |0x082a
          BufferType = I_TOKEN;                                                           //check   |0x082b
          switch(BufferRegOut)                                   _SwitchGroup             //check   |0x082c
          return_yes(segment_in_2);                                                       //check   |0x082d
//---------------------------------------------------------------------------             //check   |0x082e
        case UserError:                                   return(UserError);              //check   |0x082f
        default:                                          ReturnSystemError;              //check   |0x0830
        }                                                                                 //check   |0x0831
}                                                                                         //check   |0x0832
//                                                                                        //05-24-97|0x0832
//***************************************************************************             //10-08-31|0x0835
//***************************************************************************             //10-08-31|0x0836
//******                                                               ******             //10-08-31|0x0837
//******                        buffer_out_utility                     ******             //10-08-31|0x0838
//******                                                               ******             //10-08-31|0x0839
//***************************************************************************             //10-08-31|0x083a
//***************************************************************************             //10-08-31|0x083b
//*******************************************************************************         //10-29-97|0x0844
//*******************************************************************************         //10-29-97|0x0844
// buffer_out_utility                                                                     //10-08-31|0x0844
//*******************************************************************************         //10-29-97|0x0844
//*******************************************************************************         //10-29-97|0x0844
UINT PRECOPER::buffer_out_utility(                                                        //10-08-31|0x0844
    PROCESS_DATA_FAR ProcessDataFar,                                                      //10-08-31|0x0844
    PROCESS_FILES_FAR ProcessFilesFar                                                     //10-08-31|0x0844
    ) {                                                                                   //10-08-31|0x0844
//*******************************************************************************         //10-29-97|0x0844
//***************************************************************************             //10-08-31|0x0845
//***************************************************************************             //10-08-31|0x0846
//***************************************************************************             //10-08-31|0x0847
    if(TokensNoTokens   != 2)                               ReturnSystemError             //10-08-31|0x0848
//***************************************************************************             //10-08-31|0x0849
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //10-08-31|0x084a
//***************************************************************************             //10-08-31|0x084b
    StrDataCpy(ProcessResultsAddr,  TokensTokenAddr(1));                                  //10-08-31|0x084c
    switch(ResultsType)                                                                   //10-08-31|0x084d
      {                                                                                   //10-08-31|0x084e
//***************************************************************************             //10-08-31|0x084f
        case I_NAME:                                                                      //10-08-31|0x0850
          switch(NumResultsIn)                                   _SwitchGroup             //10-08-31|0x0851
          switch(ResultNumType)                                                           //10-08-31|0x0852
            {                                                                             //10-08-31|0x0853
//---------------------------------------------------------------------------             //10-08-31|0x0854
              case 1:                                                                     //10-08-31|0x0855
                if(((ResultNumChar0 > 31) &&                                              //check   |0x0856
                    (ResultNumChar0 < 127)) ||                                            //check   |0x0857
                    (ResultNumChar0 == 0x0d))                                             //check   |0x0858
                                          ReturnFinish("Illegal Byte Value");             //check   |0x0859
                if(ResultNumChar0 != 0x0a)                                                //10-08-31|0x085a
                  {                                                                       //10-08-31|0x085b
                    switch(CommitOutBuf)                         _SwitchGroup             //10-09-01|0x085c
                    switch(WriteBufNum)                          _SwitchGroup             //10-09-01|0x085d
                    switch(FileRelease())                        _SwitchGroup             //10-09-01|0x085e
                    FileOutBufferFileSize += 1;                                           //check   |0x085f
                    return_yes(load_buffer_1);                                            //10-09-01|0x0860
                    }                                                                     //10-09-01|0x0861
                return_no(load_buffer_1);                                                 //10-08-31|0x0862
//---------------------------------------------------------------------------             //10-08-31|0x0863
              case 0:                     ReturnFinish("Numeric Conversion");             //10-08-31|0x0864
              case 2:  case 4:          ReturnFinish("Illegal Numeric Size");             //10-08-31|0x0865
              default:                                      ReturnSystemError             //10-08-31|0x0866
              }                                                                           //10-08-31|0x0867
//***************************************************************************             //10-08-31|0x0868
        case I_TOKEN:                                                                     //10-08-31|0x0869
        case I_STRING:                                                                    //10-08-31|0x086a
          if(ResultsLength >= 255)                          ReturnSystemError             //10-08-31|0x086b
          if(ResultsChar(ResultsLength))                    ReturnSystemError             //10-08-31|0x086c
//---------------------------------------------------------------------------             //10-08-31|0x086d
          switch(CommitOutBuf)                                   _SwitchGroup             //10-08-31|0x086e
          switch(WriteBufStr)                                    _SwitchGroup             //10-08-31|0x086f
          switch(FileRelease())                                  _SwitchGroup             //10-08-31|0x0870
          FileOutBufferFileSize += ResultsLength;                                         //check   |0x0871
          return_yes(load_buffer_2);                                                      //10-08-31|0x0872
//***************************************************************************             //10-08-31|0x0873
        default:                                            ReturnSystemError             //10-08-31|0x0874
        }                                                                                 //10-08-31|0x0875
}                                                                                         //10-08-31|0x0876
//                                                                                        //05-24-97|0x0876
//***************************************************************************             //10-08-31|0x0879
//***************************************************************************             //10-08-31|0x087a
//******                                                               ******             //10-08-31|0x087b
//******                        load_buffer                            ******             //10-08-31|0x087c
//******                                                               ******             //10-08-31|0x087d
//***************************************************************************             //10-08-31|0x087e
//***************************************************************************             //10-08-31|0x087f
//*******************************************************************************         //10-29-97|0x0887
//*******************************************************************************         //10-29-97|0x0887
// load_buffer                                                                            //10-08-31|0x0887
//*******************************************************************************         //10-29-97|0x0887
//*******************************************************************************         //10-29-97|0x0887
UINT PRECOPER::load_buffer(                                                               //10-08-31|0x0887
    PROCESS_DATA_FAR ProcessDataFar,                                                      //10-08-31|0x0887
    PROCESS_FILES_FAR ProcessFilesFar                                                     //10-08-31|0x0887
    ) {                                                                                   //10-08-31|0x0887
//*******************************************************************************         //10-29-97|0x0887
//***************************************************************************             //10-08-31|0x0888
//***************************************************************************             //10-08-31|0x0889
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //10-08-31|0x088a
    if(TokensNoTokens   != 2)                               ReturnSystemError             //10-08-31|0x088b
//***************************************************************************             //10-08-31|0x088c
    if(ProcessOutBufferState != BUFFER_READY)                                             //check   |0x088d
                                ReturnFinish("Illegal _LOAD_BUFFER Command");             //10-08-31|0x088e
//***************************************************************************             //10-08-31|0x088f
    FileOutBufferFileSize = 0;                                                            //check   |0x0890
    switch(buffer_out_utility(ProcessDataFar, ProcessFilesFar))                           //10-08-31|0x0891
      {                                                                                   //10-08-31|0x0892
        case Yes: ProcessOutBufferState = BUFFER_OUT_APPEND;                              //check   |0x0893
                  return_test(load_buffer_1);                                             //10-08-31|0x0894
//---------------------------------------------------------------------------             //10-09-01|0x0895
        case No:  ProcessOutBufferState = BUFFER_OUT_WRITE;                               //check   |0x0896
                  return_test(load_buffer_2);                                             //10-09-01|0x0897
//---------------------------------------------------------------------------             //10-09-01|0x0898
        case UserError:                                   return(UserError);              //10-09-01|0x0899
        default:                                            ReturnSystemError             //10-09-01|0x089a
        }                                                                                 //10-09-01|0x089b
}                                                                                         //10-09-01|0x089c
//                                                                                        //05-24-97|0x089c
//***************************************************************************             //10-08-31|0x089f
//***************************************************************************             //10-08-31|0x08a0
//******                                                               ******             //10-08-31|0x08a1
//******                        append_buffer                          ******             //10-08-31|0x08a2
//******                                                               ******             //10-08-31|0x08a3
//***************************************************************************             //10-08-31|0x08a4
//***************************************************************************             //10-08-31|0x08a5
//*******************************************************************************         //10-29-97|0x08ad
//*******************************************************************************         //10-29-97|0x08ad
// append_buffer                                                                          //10-08-31|0x08ad
//*******************************************************************************         //10-29-97|0x08ad
//*******************************************************************************         //10-29-97|0x08ad
UINT PRECOPER::append_buffer(                                                             //10-08-31|0x08ad
    PROCESS_DATA_FAR ProcessDataFar,                                                      //10-08-31|0x08ad
    PROCESS_FILES_FAR ProcessFilesFar                                                     //10-08-31|0x08ad
    ) {                                                                                   //10-08-31|0x08ad
//*******************************************************************************         //10-29-97|0x08ad
//***************************************************************************             //10-08-31|0x08ae
//***************************************************************************             //10-08-31|0x08af
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //10-08-31|0x08b0
    if(TokensNoTokens   != 2)                               ReturnSystemError             //10-08-31|0x08b1
//***************************************************************************             //10-08-31|0x08b2
    if(ProcessOutBufferState != BUFFER_OUT_APPEND)                                        //check   |0x08b3
                              ReturnFinish("Illegal _APPEND_BUFFER Command");             //check   |0x08b4
//***************************************************************************             //10-08-31|0x08b5
    switch(buffer_out_utility(ProcessDataFar, ProcessFilesFar))                           //10-08-31|0x08b6
      {                                                                                   //10-08-31|0x08b7
//---------------------------------------------------------------------------             //10-08-31|0x08b8
        case Yes: ProcessOutBufferState = BUFFER_OUT_APPEND;                              //check   |0x08b9
                  return_test(append_buffer_1);                                           //check   |0x08ba
//---------------------------------------------------------------------------             //10-09-01|0x08bb
        case No:  ProcessOutBufferState = BUFFER_OUT_WRITE;                               //check   |0x08bc
                  return_test(append_buffer_2);                                           //check   |0x08bd
//---------------------------------------------------------------------------             //10-09-01|0x08be
        case UserError:                                   return(UserError);              //10-09-01|0x08bf
        default:                                            ReturnSystemError             //10-09-01|0x08c0
        }                                                                                 //10-09-01|0x08c1
}                                                                                         //10-09-01|0x08c2
//                                                                                        //05-24-97|0x08c2
//***************************************************************************             //10-09-01|0x08c5
//***************************************************************************             //10-09-01|0x08c6
//******                                                               ******             //10-09-01|0x08c7
//******                        write_buffer                           ******             //10-09-01|0x08c8
//******                                                               ******             //10-09-01|0x08c9
//***************************************************************************             //10-09-01|0x08ca
//***************************************************************************             //10-09-01|0x08cb
//*******************************************************************************         //10-29-97|0x08d3
//*******************************************************************************         //10-29-97|0x08d3
// write_buffer                                                                           //10-09-01|0x08d3
//*******************************************************************************         //10-29-97|0x08d3
//*******************************************************************************         //10-29-97|0x08d3
UINT PRECOPER::write_buffer(                                                              //10-09-01|0x08d3
    PROCESS_DATA_FAR ProcessDataFar,                                                      //10-09-01|0x08d3
    PROCESS_FILES_FAR ProcessFilesFar                                                     //10-09-01|0x08d3
    ) {                                                                                   //10-09-01|0x08d3
//*******************************************************************************         //10-29-97|0x08d3
//***************************************************************************             //10-09-01|0x08d4
//***************************************************************************             //10-09-01|0x08d5
  SLONG position;                                                                    //10-09-01|0x08d6
  WORDS size;                                                                        //10-09-01|0x08d7
//***************************************************************************             //10-09-01|0x08d8
//***************************************************************************             //10-09-01|0x08d9
    if(ProcessOutBufferState != BUFFER_OUT_WRITE)                                         //check   |0x08da
                                 ReturnFinish("Illegal _LOAD_WRITE Command");             //10-09-01|0x08db
    ProcessOutBufferState = BUFFER_READY;                                                 //check   |0x08dc
//***************************************************************************             //10-09-01|0x08dd
    for(position=0; position<FileOutBufferFileSize;  position+=256)                       //check   |0x08de
      {                                                                                   //10-09-01|0x08df
        MemSet(ProcessBufferAddr, 0, sizeof(STRING_DATA));                                //10-09-01|0x08e0
        size.slong = FileOutBufferFileSize - position;                                    //check   |0x08e1
        BufferLength  = (size.slong < 256) ? size.sint0 : 256;                            //10-09-01|0x08e2
//---------------------------------------------------------------------------             //10-09-01|0x08e3
        switch(CommitOutBuf)                                     _SwitchGroup             //10-09-01|0x08e4
        switch(ReadBuffer)                                       _SwitchGroup             //10-09-01|0x08e5
        switch(FileRelease())                                    _SwitchGroup             //10-09-01|0x08e6
//---------------------------------------------------------------------------             //10-09-01|0x08e7
        switch(CommitOut(ParmNumUlong))                          _SwitchGroup             //10-09-01|0x08e8
        switch(WriteText(ProcessBufferAddr))                                              //10-09-01|0x08e9
          {                                                                               //10-09-01|0x08ea
            case Success:                         break_test(write_buffer_1);             //10-09-01|0x08eb
            case UserError: switch(FileRelease())               _SwitchGroup;             //10-09-01|0x08ec
                            return(UserError);                                            //10-09-01|0x08ed
            default:                                        ReturnSystemError             //10-09-01|0x08ee
            }                                                                             //10-09-01|0x08ef
        switch(FileRelease())                                    _SwitchGroup             //10-09-01|0x08f0
        }                                                                                 //10-09-01|0x08f1
//***************************************************************************             //10-09-01|0x08f2
    switch(CommitOut(ParmNumUlong))                              _SwitchGroup             //10-09-01|0x08f3
    if(FileOutStatus(ParmNumUlong) > 2)                    ReturnSystemError;             //check   |0x08f4
    FileOutStatus(ParmNumUlong) = 1;                                                      //check   |0x08f5
    switch(write_crlf(ProcessDataFar))                           _SwitchGroup             //10-09-01|0x08f6
    return_test(write_buffer_2);                                                          //10-09-01|0x08f7
}                                                                                         //10-09-01|0x08f8
//                                                                                        //05-24-97|0x08f8
//***************************************************************************             //06-09-29|0x08fb
//***************************************************************************             //06-09-29|0x08fc
//******                                                               ******             //06-09-29|0x08fd
//******                        numeric_in_2                           ******             //06-09-29|0x08fe
//******                                                               ******             //06-09-29|0x08ff
//***************************************************************************             //06-09-29|0x0900
//***************************************************************************             //06-09-29|0x0901
//*******************************************************************************         //10-29-97|0x0908
//*******************************************************************************         //10-29-97|0x0908
// numeric_in_2                                                                           //06-09-29|0x0908
//*******************************************************************************         //10-29-97|0x0908
//*******************************************************************************         //10-29-97|0x0908
UINT PRECOPER::numeric_in_2(                                                              //06-09-29|0x0908
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-09-29|0x0908
    ) {                                                                                   //06-09-29|0x0908
//*******************************************************************************         //10-29-97|0x0908
//***************************************************************************             //06-09-29|0x0909
//***************************************************************************             //06-09-29|0x090a
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //06-09-29|0x090b
    if(TokensNoTokens   != 3)                               ReturnSystemError             //06-09-29|0x090c
//***************************************************************************             //06-09-29|0x090d
    switch(TokensPrepare(ProcessTokensAddr, 2))                  _SwitchGroup             //06-09-29|0x090e
    switch(TextRegIn)                                            _SwitchGroup             //06-09-29|0x090f
    switch(ClearRegIn)                                           _SwitchGroup             //06-09-29|0x0910
//***************************************************************************             //06-09-29|0x0911
    switch(NumResultsIn)                                         _SwitchGroup             //06-09-29|0x0912
    if(ResultNumType == 0)    ReturnFinish("Numeric Conversion -- Register");             //06-09-29|0x0913
//***************************************************************************             //06-09-29|0x0914
    switch(NumTextIn(2))                                         _SwitchGroup             //06-09-29|0x0915
    if(ParmNumType   == 0)  ReturnFinish("Numeric Conersion -- Parameter 2");             //06-09-29|0x0916
//***************************************************************************             //06-09-29|0x0917
    return_test(numeric_in_2_1);                                                          //06-09-29|0x0918
}                                                                                         //06-09-29|0x0919
//                                                                                        //05-24-97|0x0919
//***************************************************************************             //06-09-29|0x091c
//***************************************************************************             //06-10-09|0x091d
//******                                                               ******             //06-10-09|0x091e
//******                        string_in_2                            ******             //06-10-09|0x091f
//******                                                               ******             //06-10-09|0x0920
//***************************************************************************             //06-10-09|0x0921
//***************************************************************************             //06-10-09|0x0922
//*******************************************************************************         //10-29-97|0x0929
//*******************************************************************************         //10-29-97|0x0929
// string_in_2                                                                            //06-10-09|0x0929
//*******************************************************************************         //10-29-97|0x0929
//*******************************************************************************         //10-29-97|0x0929
UINT PRECOPER::string_in_2(                                                               //06-10-09|0x0929
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-10-09|0x0929
    ) {                                                                                   //06-10-09|0x0929
//*******************************************************************************         //10-29-97|0x0929
//***************************************************************************             //06-10-09|0x092a
//***************************************************************************             //06-10-09|0x092b
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //06-10-09|0x092c
    if(TokensNoTokens   != 3)                               ReturnSystemError             //06-10-09|0x092d
//***************************************************************************             //06-10-09|0x092e
    switch(TokensPrepare(ProcessTokensAddr, 2))                  _SwitchGroup             //06-10-09|0x092f
    switch(TextRegIn)                                            _SwitchGroup             //06-10-09|0x0930
    switch(ClearRegIn)                                           _SwitchGroup             //06-10-09|0x0931
//***************************************************************************             //06-10-09|0x0932
    return_test(string_in_2_1);                                                           //06-10-09|0x0933
}                                                                                         //06-10-09|0x0934
//                                                                                        //05-24-97|0x0934
//***************************************************************************             //09-03-19|0x0937
//***************************************************************************             //09-03-19|0x0938
//******                                                               ******             //09-03-19|0x0939
//******                        string_numeric_in_2                    ******             //09-03-19|0x093a
//******                                                               ******             //09-03-19|0x093b
//***************************************************************************             //09-03-19|0x093c
//***************************************************************************             //09-03-19|0x093d
//*******************************************************************************         //10-29-97|0x0944
//*******************************************************************************         //10-29-97|0x0944
// string_numeric_in_2                                                                    //09-03-19|0x0944
//*******************************************************************************         //10-29-97|0x0944
//*******************************************************************************         //10-29-97|0x0944
UINT PRECOPER::string_numeric_in_2(                                                       //09-03-19|0x0944
    PROCESS_DATA_FAR ProcessDataFar                                                       //09-03-19|0x0944
    ) {                                                                                   //09-03-19|0x0944
//*******************************************************************************         //10-29-97|0x0944
//***************************************************************************             //09-03-19|0x0945
//***************************************************************************             //09-03-19|0x0946
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-19|0x0947
    if(TokensNoTokens   != 3)                               ReturnSystemError             //09-03-19|0x0948
//***************************************************************************             //09-03-19|0x0949
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-19|0x094a
//***************************************************************************             //09-03-19|0x094b
    switch(NumTextIn(2))                                         _SwitchGroup             //09-03-19|0x094c
    if(ParmNumType   == 0)  ReturnFinish("Numeric Conersion -- Parameter 2");             //09-03-19|0x094d
//***************************************************************************             //09-03-19|0x094e
    return_test(string_numeric_in_2_1);                                                   //09-03-19|0x094f
}                                                                                         //09-03-19|0x0950
//                                                                                        //05-24-97|0x0950
//***************************************************************************             //06-09-29|0x0953
//***************************************************************************             //06-09-29|0x0954
//******                                                               ******             //06-09-29|0x0955
//******                        string_numeric_in_3                    ******             //06-09-29|0x0956
//******                                                               ******             //06-09-29|0x0957
//***************************************************************************             //06-09-29|0x0958
//***************************************************************************             //06-09-29|0x0959
//*******************************************************************************         //10-29-97|0x0960
//*******************************************************************************         //10-29-97|0x0960
// string_numeric_in_3                                                                    //06-09-29|0x0960
//*******************************************************************************         //10-29-97|0x0960
//*******************************************************************************         //10-29-97|0x0960
UINT PRECOPER::string_numeric_in_3(                                                       //06-09-29|0x0960
    PROCESS_DATA_FAR ProcessDataFar,                                                      //06-09-29|0x0960
    UINT StartNo                                                                          //06-09-29|0x0960
    ) {                                                                                   //06-09-29|0x0960
//*******************************************************************************         //10-29-97|0x0960
//***************************************************************************             //06-09-29|0x0961
//***************************************************************************             //06-09-29|0x0962
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //06-09-29|0x0963
    if(TokensNoTokens   != 4)                               ReturnSystemError             //06-09-29|0x0964
//***************************************************************************             //06-09-29|0x0965
    switch(TokensPrepare(ProcessTokensAddr, StartNo))            _SwitchGroup             //06-09-29|0x0966
//***************************************************************************             //06-09-29|0x0967
    switch(NumTextIn(3))                                         _SwitchGroup             //06-09-29|0x0968
    if(ParmNumType   == 0)  ReturnFinish("Numeric Conersion -- Parameter 3");             //06-09-29|0x0969
//***************************************************************************             //06-09-29|0x096a
    return_test(string_numeric_in_3_1);                                                   //06-09-29|0x096b
}                                                                                         //06-09-29|0x096c
//                                                                                        //05-24-97|0x096c
//***************************************************************************             //09-03-19|0x096f
//***************************************************************************             //09-03-19|0x0970
//******                                                               ******             //09-03-19|0x0971
//******                        string_numeric_in_4                    ******             //09-03-19|0x0972
//******                                                               ******             //09-03-19|0x0973
//***************************************************************************             //09-03-19|0x0974
//***************************************************************************             //09-03-19|0x0975
//*******************************************************************************         //10-29-97|0x097c
//*******************************************************************************         //10-29-97|0x097c
// string_numeric_in_4                                                                    //09-03-19|0x097c
//*******************************************************************************         //10-29-97|0x097c
//*******************************************************************************         //10-29-97|0x097c
UINT PRECOPER::string_numeric_in_4(                                                       //09-03-19|0x097c
    PROCESS_DATA_FAR ProcessDataFar                                                       //09-03-19|0x097c
    ) {                                                                                   //09-03-19|0x097c
//*******************************************************************************         //10-29-97|0x097c
//***************************************************************************             //09-03-19|0x097d
//***************************************************************************             //09-03-19|0x097e
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-19|0x097f
    if(TokensNoTokens   != 5)                               ReturnSystemError             //09-03-19|0x0980
//***************************************************************************             //09-03-19|0x0981
    switch(TokensPrepare(ProcessTokensAddr, 2))                  _SwitchGroup             //09-03-19|0x0982
//***************************************************************************             //09-03-19|0x0983
    switch(NumTextIn(4))                                         _SwitchGroup             //09-03-19|0x0984
    if(ParmNumType   == 0)  ReturnFinish("Numeric Conersion -- Parameter 2");             //09-03-19|0x0985
//***************************************************************************             //09-03-19|0x0986
    return_test(string_numeric_in_4_1);                                                   //09-03-19|0x0987
}                                                                                         //09-03-19|0x0988
//                                                                                        //05-24-97|0x0988
//***************************************************************************             //09-03-19|0x098b
//***************************************************************************             //09-03-19|0x098c
//******                                                               ******             //09-03-19|0x098d
//******                        basic_reg_store                        ******             //09-03-19|0x098e
//******                                                               ******             //09-03-19|0x098f
//***************************************************************************             //09-03-19|0x0990
//***************************************************************************             //09-03-19|0x0991
//*******************************************************************************         //10-29-97|0x0998
//*******************************************************************************         //10-29-97|0x0998
// basic_reg_store                                                                        //09-03-19|0x0998
//*******************************************************************************         //10-29-97|0x0998
//*******************************************************************************         //10-29-97|0x0998
UINT PRECOPER::basic_reg_store(                                                           //09-03-19|0x0998
    PROCESS_DATA_FAR ProcessDataFar                                                       //09-03-19|0x0998
    ) {                                                                                   //09-03-19|0x0998
//*******************************************************************************         //10-29-97|0x0998
//***************************************************************************             //09-03-19|0x099b
//***************************************************************************             //09-03-19|0x099c
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-19|0x099d
    if(TokensNoTokens   != 3)                               ReturnSystemError             //09-03-19|0x099e
//***************************************************************************             //09-03-19|0x099f
    switch(TokensPrepare(ProcessTokensAddr, 2))                  _SwitchGroup             //09-03-19|0x09a0
//***************************************************************************             //09-03-19|0x09a1
    StrDataCpy(ProcessResultsAddr,  TokensTokenAddr(2));                                  //09-03-19|0x09a2
    switch(BasicStrngType)                                       _SwitchGroup             //09-03-19|0x09a3
    switch(ResultRegOut)                                         _SwitchGroup             //09-03-19|0x09a4
//***************************************************************************             //09-03-19|0x09a5
    return_test(basic_reg_store_1);                                                       //09-03-19|0x09a6
}                                                                                         //09-03-19|0x09a7
//                                                                                        //05-24-97|0x09a7
//***************************************************************************             //09-03-19|0x09aa
//***************************************************************************             //09-03-19|0x09ab
//******                                                               ******             //09-03-19|0x09ac
//******                       find_char                               ******             //09-03-19|0x09ad
//******                                                               ******             //09-03-19|0x09ae
//***************************************************************************             //09-03-19|0x09af
//***************************************************************************             //09-03-19|0x09b0
//***************************************************************************             //09-03-19|0x09b3
//***************************************************************************             //09-03-19|0x09b4
//*******************************************************************************         //10-29-97|0x09b5
//*******************************************************************************         //10-29-97|0x09b5
// find_char                                                                              //09-03-19|0x09b5
//*******************************************************************************         //10-29-97|0x09b5
//*******************************************************************************         //10-29-97|0x09b5
ULONG PRECOPER::find_char(                                                                //09-03-19|0x09b5
    STRING_DATA_FAR StringFar,                                                            //09-03-19|0x09b5
    SCHAR TestChar                                                                        //09-03-19|0x09b5
    ) {                                                                                   //09-03-19|0x09b5
//*******************************************************************************         //10-29-97|0x09b5
//***************************************************************************             //09-03-19|0x09b6
//***************************************************************************             //09-03-19|0x09b7
  WORDS work;                                                                        //09-03-19|0x09b8
  UINT index;                                                                        //09-03-19|0x09b9
//***************************************************************************             //09-03-19|0x09ba
    TestSample(find_char_1);                                                              //09-03-19|0x09bb
    work.ulong = 0xffffffff;                                                              //09-03-19|0x09bc
//---------------------------------------------------------------------------             //09-03-19|0x09bd
    for(index=0;  index<StringLength; ++index)                                            //09-03-19|0x09be
      {                                                                                   //09-03-19|0x09bf
        if(StringChar(index) == TestChar)                                                 //09-03-19|0x09c0
          {                                                                               //09-03-19|0x09c1
            work.word1 = index;                                                           //09-03-19|0x09c2
            if(work.word0 == 0xffff)                                                      //09-03-19|0x09c3
              {                                                                           //09-03-19|0x09c4
                TestSample(find_char_2);                                                  //09-03-19|0x09c5
                work.word0 = index;                                                       //09-03-19|0x09c6
                }                                                                         //09-03-19|0x09c7
            }                                                                             //09-03-19|0x09c8
        }                                                                                 //09-03-19|0x09c9
    return(work.ulong);                                                                   //09-03-19|0x09ca
}                                                                                         //09-03-19|0x09cb
//                                                                                        //05-24-97|0x09cb
//***************************************************************************             //06-09-28|0x09ce
//***************************************************************************             //06-09-28|0x09cf
//******                                                               ******             //06-09-28|0x09d0
//******                        string_type                            ******             //06-09-28|0x09d1
//******                                                               ******             //06-09-28|0x09d2
//***************************************************************************             //06-09-28|0x09d3
//***************************************************************************             //06-09-28|0x09d4
//*******************************************************************************         //10-29-97|0x09dd
//*******************************************************************************         //10-29-97|0x09dd
// basic_string_type                                                                      //06-09-28|0x09dd
//*******************************************************************************         //10-29-97|0x09dd
//*******************************************************************************         //10-29-97|0x09dd
UINT PRECOPER::basic_string_type(                                                         //06-09-28|0x09dd
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-09-28|0x09dd
    ) {                                                                                   //06-09-28|0x09dd
//*******************************************************************************         //10-29-97|0x09dd
    switch(PrecformNameTest(ProcessResultsAddr))                                          //06-09-28|0x09e0
      {                                                                                   //06-09-28|0x09e1
        case Success:     ResultsType = I_NAME;   return_test(string_type_1);             //06-09-28|0x09e2
        case UserError:                                                break;             //09-03-19|0x09e3
        case SystemError:                                  ReturnSystemError;             //06-09-28|0x09e4
        }                                                                                 //06-09-28|0x09e5
//***************************************************************************             //06-09-28|0x09e6
    switch(PrecformStringTest(ProcessResultsAddr))                                        //09-03-19|0x09e7
      {                                                                                   //09-03-19|0x09e8
        case Success:     ResultsType = I_STRING; return_test(string_type_2);             //09-03-19|0x09e9
        case UserError:   ResultsType = I_TOKEN;                       break;             //09-03-19|0x09ea
        case SystemError:                                  ReturnSystemError;             //09-03-19|0x09eb
        }                                                                                 //09-03-19|0x09ec
//***************************************************************************             //09-03-19|0x09ed
    return_test(string_type_3);                                                           //09-03-19|0x09ee
}                                                                                         //09-03-19|0x09ef
//                                                                                        //05-24-97|0x09ef
//***************************************************************************             //06-09-29|0x09f2
//***************************************************************************             //06-09-29|0x09f3
//******                                                               ******             //06-09-29|0x09f4
//******                        numeric_reg_out                        ******             //06-09-29|0x09f5
//******                                                               ******             //06-09-29|0x09f6
//***************************************************************************             //06-09-29|0x09f7
//***************************************************************************             //06-09-29|0x09f8
//*******************************************************************************         //10-29-97|0x09ff
//*******************************************************************************         //10-29-97|0x09ff
// numeric_reg_out                                                                        //06-09-29|0x09ff
//*******************************************************************************         //10-29-97|0x09ff
//*******************************************************************************         //10-29-97|0x09ff
UINT PRECOPER::numeric_reg_out(                                                           //06-09-29|0x09ff
    PROCESS_DATA_FAR ProcessDataFar                                                       //06-09-29|0x09ff
    ) {                                                                                   //06-09-29|0x09ff
//*******************************************************************************         //10-29-97|0x09ff
//***************************************************************************             //06-09-29|0x0a00
//***************************************************************************             //06-09-29|0x0a01
    switch(NumResultOut)                                         _SwitchGroup             //06-09-29|0x0a02
    switch(ResultRegOut)                                         _SwitchGroup             //06-09-29|0x0a03
    return_test(numeric_reg_out_1);                                                       //06-09-29|0x0a04
}                                                                                         //06-09-29|0x0a05
//                                                                                        //05-24-97|0x0a05
//***************************************************************************             //09-06-02|0x0a08
//***************************************************************************             //09-06-02|0x0a09
//******                                                               ******             //09-06-02|0x0a0a
//******                        get_postoffice_no                      ******             //09-06-02|0x0a0b
//******                                                               ******             //09-06-02|0x0a0c
//***************************************************************************             //09-06-02|0x0a0d
//***************************************************************************             //09-06-02|0x0a0e
//*******************************************************************************         //10-29-97|0x0a15
//*******************************************************************************         //10-29-97|0x0a15
// get_postoffice_no                                                                      //09-06-02|0x0a15
//*******************************************************************************         //10-29-97|0x0a15
//*******************************************************************************         //10-29-97|0x0a15
UINT PRECOPER::get_postoffice_no(                                                         //09-06-02|0x0a15
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-06-02|0x0a15
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-06-02|0x0a15
    ) {                                                                                   //09-06-02|0x0a15
//*******************************************************************************         //10-29-97|0x0a15
//***************************************************************************             //09-06-02|0x0a18
//***************************************************************************             //09-06-02|0x0a19
  STRING_DATA_FAR mail_box_addr;                                                     //09-06-02|0x0a1a
//***************************************************************************             //09-06-02|0x0a1b
//***************************************************************************             //09-06-02|0x0a1c
    if(TokensChar(2, 256) != 0)                             ReturnSystemError             //09-06-02|0x0a1d
    ResultNumType  = 2;                                                                   //09-06-02|0x0a1e
    ResultNumUlong = 0;                                                                   //09-06-02|0x0a1f
//***************************************************************************             //09-06-02|0x0a20
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //11-12-22|0x0a21
//***************************************************************************             //09-06-20|0x0a22
    while(ResultNumUlong < FileMailBoxNoFiles)                                            //09-06-02|0x0a23
      {                                                                                   //09-06-02|0x0a24
        mail_box_addr = &FileMailBoxName(ResultNumUlong);                                 //09-06-02|0x0a25
        switch(StrCmp(MailBoxNameLineAddr, TokensLineAddr(2)))                            //11-05-30|0x0a26
          {                                                                               //11-05-30|0x0a27
            case 0:                         return_test(get_postoffice_no_1);             //11-05-30|0x0a28
            case 1:                                                                       //11-05-30|0x0a29
            case -1:                        ++ResultNumUlong;          break;             //11-05-30|0x0a2a
            default:                                       ReturnSystemError;             //11-05-30|0x0a2b
            }                                                                             //11-05-30|0x0a2c
        }                                                                                 //09-06-02|0x0a2d
    ReturnFinish("Mail Box File Not Specified");                                          //09-06-02|0x0a2e
}                                                                                         //09-06-02|0x0a2f
//                                                                                        //05-24-97|0x0a2f
//***************************************************************************             //09-03-11|0x0a32
//***************************************************************************             //09-03-11|0x0a33
//******                                                               ******             //09-03-11|0x0a34
//******                        delete_postoffice                      ******             //09-03-11|0x0a35
//******                                                               ******             //09-03-11|0x0a36
//***************************************************************************             //09-03-11|0x0a37
//***************************************************************************             //09-03-11|0x0a38
//*******************************************************************************         //10-29-97|0x0a42
//*******************************************************************************         //10-29-97|0x0a42
// delete_postoffice                                                                      //09-03-11|0x0a42
//*******************************************************************************         //10-29-97|0x0a42
//*******************************************************************************         //10-29-97|0x0a42
UINT PRECOPER::delete_postoffice(                                                         //09-03-11|0x0a42
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-11|0x0a42
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-11|0x0a42
    ) {                                                                                   //09-03-11|0x0a42
//*******************************************************************************         //10-29-97|0x0a42
//***************************************************************************             //09-03-11|0x0a45
//***************************************************************************             //09-03-11|0x0a46
    if(ProcessFlagState   != 0)          ReturnFinish("Test Flag Not Reset");             //09-03-11|0x0a47
    if(TokensNoTokens     != 2)                             ReturnSystemError             //09-03-11|0x0a48
//***************************************************************************             //09-03-11|0x0a49
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0a4a
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-06|0x0a4b
//***************************************************************************             //09-06-20|0x0a4c
//***                                                                    ****             //09-03-11|0x0a4d
//***  GET THE POSTOFFICE FILE NUMBER                                    ****             //09-03-11|0x0a4e
//***                                                                    ****             //09-03-11|0x0a4f
//***************************************************************************             //09-03-11|0x0a50
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-11|0x0a51
    switch(NumTextIn(1))                                         _SwitchGroup             //09-03-11|0x0a52
//***************************************************************************             //09-03-11|0x0a53
    if(ParmNumType  == 0)                                                                 //09-03-11|0x0a54
                                 ReturnFinish("Illegal MailBox File Index");              //09-03-11|0x0a55
    if(ParmNumUlong >= FileMailBoxNoFiles)                                                //09-03-11|0x0a56
                                 ReturnFinish("Illegal MailBox File Number");             //09-03-11|0x0a57
    FileMailBoxFileNo = ParmNumSint0;                                                     //09-03-11|0x0a58
//***************************************************************************             //09-03-11|0x0a59
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-11|0x0a5a
      {                                                                                   //09-03-11|0x0a5b
//---------------------------------------------------------------------------             //09-03-11|0x0a5c
        case OPENED_POSTOFFICE:                                                           //09-06-29|0x0a5d
          switch(MailDictDelete(FileMailBoxFileNo))              _SwitchGroup             //10-01-06|0x0a5e
          FileMailBoxStatus(FileMailBoxFileNo) = POSTOFFICE_FILE;                         //10-01-06|0x0a5f
          return_test(delete_postoffice_1);                                               //09-06-29|0x0a60
//---------------------------------------------------------------------------             //09-03-11|0x0a61
        case OPEN_MAILBOX:   ReturnFinish("Mail Box File Cannot be Deleted");             //10-01-06|0x0a62
        case OPENED_MAILBOX: ReturnFinish("Mail Box file Cannot be Deleted");             //10-01-06|0x0a63
//---------------------------------------------------------------------------             //09-03-11|0x0a64
        case CREATE_POSTOFFICE:             return_test(delete_postoffice_3);             //10-01-06|0x0a65
        case POSTOFFICE_FILE:               return_test(delete_postoffice_4);             //10-01-06|0x0a66
        case MAILBOX_FILE:                  return_test(delete_postoffice_5);             //10-01-06|0x0a67
//---------------------------------------------------------------------------             //09-03-11|0x0a68
        case POSTOFFICE_OPENED:      ReturnFinish("Post Office File Opened");             //09-03-17|0x0a69
        case MAILBOX_OPENED:         ReturnFinish("Mail Box File Opened");                //09-03-17|0x0a6a
//---------------------------------------------------------------------------             //09-03-11|0x0a6b
        default:                                            ReturnSystemError             //09-03-11|0x0a6c
        }                                                                                 //09-03-11|0x0a6d
}                                                                                         //09-03-11|0x0a6e
//                                                                                        //05-24-97|0x0a6e
//***************************************************************************             //09-03-11|0x0a71
//***************************************************************************             //09-03-11|0x0a72
//******                                                               ******             //09-03-11|0x0a73
//******                        open_mailbox                           ******             //09-03-11|0x0a74
//******                                                               ******             //09-03-11|0x0a75
//***************************************************************************             //09-03-11|0x0a76
//***************************************************************************             //09-03-11|0x0a77
//*******************************************************************************         //10-29-97|0x0a81
//*******************************************************************************         //10-29-97|0x0a81
// open_mailbox                                                                           //09-03-11|0x0a81
//*******************************************************************************         //10-29-97|0x0a81
//*******************************************************************************         //10-29-97|0x0a81
UINT PRECOPER::open_mailbox(                                                              //09-03-11|0x0a81
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-11|0x0a81
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-11|0x0a81
    ) {                                                                                   //09-03-11|0x0a81
//*******************************************************************************         //10-29-97|0x0a81
//***************************************************************************             //09-03-11|0x0a84
//***************************************************************************             //09-03-11|0x0a85
    if(ProcessFlagState   != 0)          ReturnFinish("Test Flag Not Reset");             //09-03-11|0x0a86
    if(TokensNoTokens     != 2)                             ReturnSystemError             //09-03-11|0x0a87
//***************************************************************************             //09-03-11|0x0a88
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0a89
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-03|0x0a8a
//***************************************************************************             //09-06-20|0x0a8b
//***                                                                    ****             //09-03-11|0x0a8c
//***  GET THE POSTOFFICE FILE NUMBER                                    ****             //09-03-11|0x0a8d
//***                                                                    ****             //09-03-11|0x0a8e
//***************************************************************************             //09-03-11|0x0a8f
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-11|0x0a90
    switch(NumTextIn(1))                                         _SwitchGroup             //09-03-11|0x0a91
//***************************************************************************             //09-03-11|0x0a92
    if(ParmNumType  == 0)                                                                 //09-03-11|0x0a93
                                 ReturnFinish("Illegal MailBox File Index");              //09-03-11|0x0a94
    if(ParmNumUlong >= FileMailBoxNoFiles)                                                //09-03-11|0x0a95
                                 ReturnFinish("Illegal MailBox File Number");             //09-03-11|0x0a96
    FileMailBoxFileNo = ParmNumSint0;                                                     //09-03-11|0x0a97
//***************************************************************************             //09-03-11|0x0a98
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-11|0x0a99
      {                                                                                   //09-03-11|0x0a9a
//---------------------------------------------------------------------------             //09-03-13|0x0a9b
        case OPEN_MAILBOX:                                                                //09-03-13|0x0a9c
          switch(MailDictRead(FileMailBoxFileNo))                _SwitchGroup             //10-01-06|0x0a9d
          FileMailBoxStatus(FileMailBoxFileNo) = MAILBOX_OPENED;                          //10-01-06|0x0a9e
          return_test(open_mailbox_1);                                                    //10-01-06|0x0a9f
//---------------------------------------------------------------------------             //09-03-11|0x0aa0
        case CREATE_POSTOFFICE:                                                           //09-03-11|0x0aa1
          switch(MailDictCreate(FileMailBoxFileNo))              _SwitchGroup             //10-01-03|0x0aa2
          FileMailBoxStatus(FileMailBoxFileNo) = POSTOFFICE_OPENED;                       //10-01-03|0x0aa3
          return_test(open_mailbox_2);                                                    //10-01-03|0x0aa4
//---------------------------------------------------------------------------             //09-03-11|0x0aa5
        case OPENED_POSTOFFICE:                                                           //09-03-13|0x0aa6
          switch(MailDictOpen(FileMailBoxFileNo))                _SwitchGroup             //10-01-06|0x0aa7
          FileMailBoxStatus(FileMailBoxFileNo) = POSTOFFICE_OPENED;                       //10-01-06|0x0aa8
          return_test(open_mailbox_3);                                                    //10-01-06|0x0aa9
//---------------------------------------------------------------------------             //09-03-11|0x0aaa
        case OPENED_MAILBOX:                                                              //10-01-06|0x0aab
          switch(MailDictOpen(FileMailBoxFileNo))                _SwitchGroup             //10-01-06|0x0aac
          FileMailBoxStatus(FileMailBoxFileNo) = MAILBOX_OPENED;                          //10-01-06|0x0aad
          return_test(open_mailbox_3);                                                    //10-01-06|0x0aae
//---------------------------------------------------------------------------             //09-06-13|0x0aaf
        case POSTOFFICE_OPENED: ReturnFinish("Mail Box File Already Opened");             //09-06-13|0x0ab0
        case MAILBOX_OPENED:    ReturnFinish("Mail Box File Already Opened");             //09-06-13|0x0ab1
        case POSTOFFICE_FILE:   ReturnFinish("Mail Box File Deleted");                    //10-01-06|0x0ab2
        case MAILBOX_FILE:      ReturnFinish("Mail Box File Deleted");                    //10-01-06|0x0ab3
//---------------------------------------------------------------------------             //09-03-11|0x0ab4
        default:                                            ReturnSystemError             //09-03-11|0x0ab5
        }                                                                                 //09-03-11|0x0ab6
}                                                                                         //09-03-11|0x0ab7
//                                                                                        //05-24-97|0x0ab7
//***************************************************************************             //09-03-10|0x0aba
//***************************************************************************             //09-03-10|0x0abb
//******                                                               ******             //09-03-10|0x0abc
//******                         create_postoffice                     ******             //09-03-10|0x0abd
//******                                                               ******             //09-03-10|0x0abe
//***************************************************************************             //09-03-10|0x0abf
//***************************************************************************             //09-03-10|0x0ac0
//*******************************************************************************         //10-29-97|0x0ac8
//*******************************************************************************         //10-29-97|0x0ac8
// create_postoffice                                                                      //09-03-10|0x0ac8
//*******************************************************************************         //10-29-97|0x0ac8
//*******************************************************************************         //10-29-97|0x0ac8
UINT PRECOPER::create_postoffice(                                                         //09-03-10|0x0ac8
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-10|0x0ac8
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-10|0x0ac8
    ) {                                                                                   //09-03-10|0x0ac8
//*******************************************************************************         //10-29-97|0x0ac8
//***************************************************************************             //09-03-10|0x0acb
//***************************************************************************             //09-03-10|0x0acc
    if(ProcessFlagState   != 0)          ReturnFinish("Test Flag Not Reset");             //09-03-11|0x0acd
    if(TokensNoTokens     != 2)                             ReturnSystemError             //09-03-11|0x0ace
//***************************************************************************             //09-03-11|0x0acf
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0ad0
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-03|0x0ad1
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0ad2
//***************************************************************************             //09-03-10|0x0ad3
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-10|0x0ad4
//***************************************************************************             //09-03-10|0x0ad5
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-10|0x0ad6
      {                                                                                   //09-03-10|0x0ad7
//---------------------------------------------------------------------------             //09-03-10|0x0ad8
        case POSTOFFICE_OPENED:              break_test(create_postoffice_1);             //09-03-10|0x0ad9
//---------------------------------------------------------------------------             //09-03-10|0x0ada
        case MAILBOX_OPENED:        ReturnFinish("Not a Post Office File");               //09-06-29|0x0adb
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0adc
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0add
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0ade
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0adf
//---------------------------------------------------------------------------             //09-03-10|0x0ae0
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0ae1
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0ae2
//---------------------------------------------------------------------------             //09-03-11|0x0ae3
        default:                                            ReturnSystemError             //09-03-10|0x0ae4
        }                                                                                 //09-03-10|0x0ae5
//***************************************************************************             //09-03-10|0x0ae6
    switch(MailDictAddZip(FileMailBoxFileNo,ProcessTokensAddr))  _SwitchGroup             //10-01-03|0x0ae7
    return_test(create_postoffice_2);                                                     //09-03-10|0x0ae8
}                                                                                         //09-03-10|0x0ae9
//                                                                                        //05-24-97|0x0ae9
//***************************************************************************             //09-03-11|0x0aec
//***************************************************************************             //09-03-11|0x0aed
//******                                                               ******             //09-03-11|0x0aee
//******                            create_po_box                      ******             //09-03-11|0x0aef
//******                                                               ******             //09-03-11|0x0af0
//***************************************************************************             //09-03-11|0x0af1
//***************************************************************************             //09-03-11|0x0af2
//*******************************************************************************         //10-29-97|0x0afa
//*******************************************************************************         //10-29-97|0x0afa
// create_po_box                                                                          //09-03-11|0x0afa
//*******************************************************************************         //10-29-97|0x0afa
//*******************************************************************************         //10-29-97|0x0afa
UINT PRECOPER::create_po_box(                                                             //09-03-11|0x0afa
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-11|0x0afa
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-11|0x0afa
    ) {                                                                                   //09-03-11|0x0afa
//*******************************************************************************         //10-29-97|0x0afa
//***************************************************************************             //09-03-11|0x0afd
//***************************************************************************             //09-03-11|0x0afe
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-11|0x0aff
    if(TokensNoTokens   != 3)                               ReturnSystemError             //09-03-11|0x0b00
//***************************************************************************             //09-03-11|0x0b01
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0b02
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-03|0x0b03
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0b04
//***************************************************************************             //09-03-11|0x0b05
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-11|0x0b06
//***************************************************************************             //09-03-11|0x0b07
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-11|0x0b08
      {                                                                                   //09-03-11|0x0b09
//---------------------------------------------------------------------------             //09-03-11|0x0b0a
        case POSTOFFICE_OPENED:                  break_test(create_po_box_1);             //09-03-11|0x0b0b
//---------------------------------------------------------------------------             //09-03-11|0x0b0c
        case MAILBOX_OPENED:        ReturnFinish("Not a Post Office File");               //09-06-29|0x0b0d
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0b0e
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0b0f
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0b10
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0b11
//---------------------------------------------------------------------------             //09-03-10|0x0b12
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0b13
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0b14
//---------------------------------------------------------------------------             //09-03-11|0x0b15
        default:                                            ReturnSystemError             //09-03-11|0x0b16
        }                                                                                 //09-03-11|0x0b17
//***************************************************************************             //09-03-11|0x0b18
    switch(MailDictAddPOBox(ProcessTokensAddr))                  _SwitchGroup             //check   |0x0b19
    return_test(create_po_box_2);                                                         //09-03-11|0x0b1a
}                                                                                         //09-03-11|0x0b1b
//                                                                                        //05-24-97|0x0b1b
//***************************************************************************             //09-03-13|0x0b1e
//***************************************************************************             //09-03-13|0x0b1f
//******                                                               ******             //09-03-13|0x0b20
//******                           send_mail                           ******             //09-03-13|0x0b21
//******                                                               ******             //09-03-13|0x0b22
//***************************************************************************             //09-03-13|0x0b23
//***************************************************************************             //09-03-13|0x0b24
//*******************************************************************************         //10-29-97|0x0b2c
//*******************************************************************************         //10-29-97|0x0b2c
// send_mail                                                                              //09-03-13|0x0b2c
//*******************************************************************************         //10-29-97|0x0b2c
//*******************************************************************************         //10-29-97|0x0b2c
UINT PRECOPER::send_mail(                                                                 //09-03-13|0x0b2c
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-13|0x0b2c
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-13|0x0b2c
    ) {                                                                                   //09-03-13|0x0b2c
//*******************************************************************************         //10-29-97|0x0b2c
//***************************************************************************             //09-03-13|0x0b2f
//***************************************************************************             //09-03-13|0x0b30
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-13|0x0b31
    if(TokensNoTokens   != 4)                               ReturnSystemError             //09-03-13|0x0b32
//***************************************************************************             //09-03-13|0x0b33
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0b34
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-03|0x0b35
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0b36
//***************************************************************************             //09-03-13|0x0b37
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-13|0x0b38
//***************************************************************************             //09-03-13|0x0b39
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-13|0x0b3a
      {                                                                                   //09-03-13|0x0b3b
//---------------------------------------------------------------------------             //09-03-13|0x0b3c
        case POSTOFFICE_OPENED:                      break_test(send_mail_1);             //10-01-03|0x0b3d
//---------------------------------------------------------------------------             //09-03-13|0x0b3e
        case MAILBOX_OPENED:        ReturnFinish("Not a Post Office File");               //09-06-13|0x0b3f
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0b40
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0b41
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0b42
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0b43
//---------------------------------------------------------------------------             //09-03-10|0x0b44
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0b45
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0b46
//---------------------------------------------------------------------------             //09-03-11|0x0b47
        default:                                            ReturnSystemError             //09-03-13|0x0b48
        }                                                                                 //09-03-13|0x0b49
//***************************************************************************             //09-03-13|0x0b4a
    switch(MailDictLoadPOBox(FileMailBoxFileNo, ProcessTokensAddr))                       //10-01-03|0x0b4b
                                                                 _SwitchGroup             //10-01-03|0x0b4c
    return_test(send_mail_2);                                                             //10-01-03|0x0b4d
}                                                                                         //09-03-13|0x0b4e
//                                                                                        //05-24-97|0x0b4e
//***************************************************************************             //09-09-17|0x0b51
//***************************************************************************             //09-09-17|0x0b52
//******                                                               ******             //09-09-17|0x0b53
//******                           empty_po_box                        ******             //09-09-17|0x0b54
//******                                                               ******             //09-09-17|0x0b55
//***************************************************************************             //09-09-17|0x0b56
//***************************************************************************             //09-09-17|0x0b57
//*******************************************************************************         //10-29-97|0x0b5f
//*******************************************************************************         //10-29-97|0x0b5f
// empty_po_box                                                                           //09-09-17|0x0b5f
//*******************************************************************************         //10-29-97|0x0b5f
//*******************************************************************************         //10-29-97|0x0b5f
UINT PRECOPER::empty_po_box(                                                              //09-09-17|0x0b5f
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-09-17|0x0b5f
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-09-17|0x0b5f
    ) {                                                                                   //09-09-17|0x0b5f
//*******************************************************************************         //10-29-97|0x0b5f
//***************************************************************************             //09-09-17|0x0b62
//***************************************************************************             //09-09-17|0x0b63
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-09-17|0x0b64
    if(TokensNoTokens   != 3)                               ReturnSystemError             //09-09-17|0x0b65
//***************************************************************************             //09-03-13|0x0b66
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0b67
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-06|0x0b68
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0b69
//***************************************************************************             //09-09-17|0x0b6a
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-09-17|0x0b6b
//***************************************************************************             //09-09-17|0x0b6c
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-09-17|0x0b6d
      {                                                                                   //09-09-17|0x0b6e
//---------------------------------------------------------------------------             //09-09-17|0x0b6f
        case POSTOFFICE_OPENED:                   break_test(empty_po_box_1);             //10-01-06|0x0b70
//---------------------------------------------------------------------------             //09-03-13|0x0b71
        case MAILBOX_OPENED:        ReturnFinish("Not a Post Office File");               //09-06-13|0x0b72
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0b73
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0b74
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0b75
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0b76
//---------------------------------------------------------------------------             //09-03-10|0x0b77
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0b78
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0b79
//---------------------------------------------------------------------------             //09-09-17|0x0b7a
        default:                                            ReturnSystemError             //09-09-17|0x0b7b
        }                                                                                 //09-09-17|0x0b7c
//***************************************************************************             //09-09-17|0x0b7d
    switch(MailDictEmptyPOBox(FileMailBoxFileNo,  ProcessTokensAddr))                     //10-01-06|0x0b7e
                                                                 _SwitchGroup             //10-01-06|0x0b7f
    return_test(empty_po_box_2);                                                          //09-09-17|0x0b80
}                                                                                         //09-09-17|0x0b81
//                                                                                        //05-24-97|0x0b81
//***************************************************************************             //09-03-16|0x0b84
//***************************************************************************             //09-03-16|0x0b85
//******                                                               ******             //09-03-16|0x0b86
//******                             get_mail                          ******             //09-03-16|0x0b87
//******                                                               ******             //09-03-16|0x0b88
//***************************************************************************             //09-03-16|0x0b89
//***************************************************************************             //09-03-16|0x0b8a
//*******************************************************************************         //10-29-97|0x0b93
//*******************************************************************************         //10-29-97|0x0b93
// get_mail                                                                               //09-03-16|0x0b93
//*******************************************************************************         //10-29-97|0x0b93
//*******************************************************************************         //10-29-97|0x0b93
UINT PRECOPER::get_mail(                                                                  //09-03-16|0x0b93
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-16|0x0b93
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-16|0x0b93
    ) {                                                                                   //09-03-16|0x0b93
//*******************************************************************************         //10-29-97|0x0b93
//***************************************************************************             //09-03-16|0x0b96
//***************************************************************************             //09-03-16|0x0b97
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-16|0x0b98
    if(TokensNoTokens   != 4)                               ReturnSystemError             //09-03-16|0x0b99
//***************************************************************************             //09-03-16|0x0b9a
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0b9b
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-03|0x0b9c
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0b9d
//***************************************************************************             //09-03-16|0x0b9e
    switch(TokensPrepare(ProcessTokensAddr, 2))                  _SwitchGroup             //09-03-16|0x0b9f
//***************************************************************************             //09-03-16|0x0ba0
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-16|0x0ba1
      {                                                                                   //09-03-16|0x0ba2
//---------------------------------------------------------------------------             //09-03-16|0x0ba3
        case POSTOFFICE_OPENED:                       break_test(get_mail_1);             //09-03-16|0x0ba4
        case MAILBOX_OPENED:                          break_test(get_mail_2);             //09-06-14|0x0ba5
//---------------------------------------------------------------------------             //09-03-16|0x0ba6
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0ba7
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0ba8
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0ba9
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0baa
//---------------------------------------------------------------------------             //09-03-10|0x0bab
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-03|0x0bac
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-03|0x0bad
//---------------------------------------------------------------------------             //09-03-16|0x0bae
        default:                                            ReturnSystemError             //09-03-16|0x0baf
        }                                                                                 //09-03-16|0x0bb0
//***************************************************************************             //09-03-16|0x0bb1
    switch(MailDictGetMail(FileMailBoxFileNo,                                             //10-01-03|0x0bb2
                           ProcessResultsAddr, ProcessTokensAddr))                        //10-01-03|0x0bb3
                                                                 _SwitchGroup             //10-01-03|0x0bb4
    return_test(get_mail_3);                                                              //09-03-16|0x0bb5
}                                                                                         //09-03-16|0x0bb6
//                                                                                        //05-24-97|0x0bb6
//***************************************************************************             //09-03-17|0x0bb9
//***************************************************************************             //09-03-17|0x0bba
//******                                                               ******             //09-03-17|0x0bbb
//******                       postoffice_exists                       ******             //09-03-17|0x0bbc
//******                                                               ******             //09-03-17|0x0bbd
//***************************************************************************             //09-03-17|0x0bbe
//***************************************************************************             //09-03-17|0x0bbf
//*******************************************************************************         //10-29-97|0x0bc9
//*******************************************************************************         //10-29-97|0x0bc9
// postoffice_exists                                                                      //09-03-17|0x0bc9
//*******************************************************************************         //10-29-97|0x0bc9
//*******************************************************************************         //10-29-97|0x0bc9
UINT PRECOPER::postoffice_exists(                                                         //09-03-17|0x0bc9
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-17|0x0bc9
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-17|0x0bc9
    ) {                                                                                   //09-03-17|0x0bc9
//*******************************************************************************         //10-29-97|0x0bc9
//***************************************************************************             //09-03-17|0x0bcc
//***************************************************************************             //09-03-17|0x0bcd
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-17|0x0bce
    if(TokensNoTokens   != 2)                               ReturnSystemError             //09-03-17|0x0bcf
//***************************************************************************             //09-03-17|0x0bd0
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0bd1
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-03|0x0bd2
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0bd3
//***************************************************************************             //09-03-17|0x0bd4
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-17|0x0bd5
//***************************************************************************             //09-03-17|0x0bd6
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-17|0x0bd7
      {                                                                                   //09-03-17|0x0bd8
//---------------------------------------------------------------------------             //09-03-17|0x0bd9
        case POSTOFFICE_OPENED:              break_test(postoffice_exists_1);             //09-03-17|0x0bda
        case MAILBOX_OPENED:                 break_test(postoffice_exists_2);             //09-03-17|0x0bdb
//---------------------------------------------------------------------------             //09-03-17|0x0bdc
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0bdd
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0bde
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0bdf
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0be0
//---------------------------------------------------------------------------             //09-03-10|0x0be1
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-03|0x0be2
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-03|0x0be3
//---------------------------------------------------------------------------             //09-03-17|0x0be4
        default:                                            ReturnSystemError             //09-03-17|0x0be5
        }                                                                                 //09-03-17|0x0be6
//***************************************************************************             //09-03-17|0x0be7
    switch(MailDictZipExists(FileMailBoxFileNo, TokensTokenAddr(1)))                      //10-01-03|0x0be8
      {                                                                                   //09-03-17|0x0be9
        case  Yes:                           return_yes(postoffice_exists_3);             //09-03-17|0x0bea
        case  No:                             return_no(postoffice_exists_4);             //09-03-17|0x0beb
        case  UserError:                                   return(UserError);             //09-03-17|0x0bec
        default:                                           ReturnSystemError;             //09-03-17|0x0bed
        }                                                                                 //09-03-17|0x0bee
}                                                                                         //09-03-17|0x0bef
//                                                                                        //05-24-97|0x0bef
//***************************************************************************             //09-03-17|0x0bf2
//***************************************************************************             //09-03-17|0x0bf3
//******                                                               ******             //09-03-17|0x0bf4
//******                       po_box_exists                           ******             //09-03-17|0x0bf5
//******                                                               ******             //09-03-17|0x0bf6
//***************************************************************************             //09-03-17|0x0bf7
//***************************************************************************             //09-03-17|0x0bf8
//*******************************************************************************         //10-29-97|0x0c02
//*******************************************************************************         //10-29-97|0x0c02
// po_box_exists                                                                          //09-03-17|0x0c02
//*******************************************************************************         //10-29-97|0x0c02
//*******************************************************************************         //10-29-97|0x0c02
UINT PRECOPER::po_box_exists(                                                             //09-03-17|0x0c02
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-17|0x0c02
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-17|0x0c02
    ) {                                                                                   //09-03-17|0x0c02
//*******************************************************************************         //10-29-97|0x0c02
//***************************************************************************             //09-03-17|0x0c05
//***************************************************************************             //09-03-17|0x0c06
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-17|0x0c07
    if(TokensNoTokens   != 3)                               ReturnSystemError             //09-03-17|0x0c08
//***************************************************************************             //09-03-17|0x0c09
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0c0a
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-06|0x0c0b
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0c0c
//***************************************************************************             //09-03-17|0x0c0d
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-17|0x0c0e
//***************************************************************************             //09-03-17|0x0c0f
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-17|0x0c10
      {                                                                                   //09-03-17|0x0c11
//---------------------------------------------------------------------------             //09-03-17|0x0c12
        case POSTOFFICE_OPENED:                  break_test(po_box_exists_1);             //09-03-17|0x0c13
        case MAILBOX_OPENED:                     break_test(po_box_exists_2);             //09-03-17|0x0c14
//---------------------------------------------------------------------------             //09-03-17|0x0c15
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0c16
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0c17
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0c18
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0c19
//---------------------------------------------------------------------------             //09-03-10|0x0c1a
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0c1b
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0c1c
//---------------------------------------------------------------------------             //09-03-17|0x0c1d
        default:                                            ReturnSystemError             //09-03-17|0x0c1e
        }                                                                                 //09-03-17|0x0c1f
//***************************************************************************             //09-03-17|0x0c20
    switch(MailDictPOBoxExists(FileMailBoxFileNo, ProcessTokensAddr))                     //10-01-06|0x0c21
      {                                                                                   //09-03-17|0x0c22
        case  Yes:                               return_yes(po_box_exists_3);             //09-03-17|0x0c23
        case  No:                                 return_no(po_box_exists_4);             //09-03-17|0x0c24
        case  UserError:                                   return(UserError);             //09-03-17|0x0c25
        default:                                           ReturnSystemError;             //09-03-17|0x0c26
        }                                                                                 //09-03-17|0x0c27
}                                                                                         //09-03-17|0x0c28
//                                                                                        //05-24-97|0x0c28
//***************************************************************************             //09-03-17|0x0c2b
//***************************************************************************             //09-03-17|0x0c2c
//******                                                               ******             //09-03-17|0x0c2d
//******                       po_box_empty                            ******             //09-03-17|0x0c2e
//******                                                               ******             //09-03-17|0x0c2f
//***************************************************************************             //09-03-17|0x0c30
//***************************************************************************             //09-03-17|0x0c31
//*******************************************************************************         //10-29-97|0x0c3b
//*******************************************************************************         //10-29-97|0x0c3b
// po_box_empty                                                                           //09-03-17|0x0c3b
//*******************************************************************************         //10-29-97|0x0c3b
//*******************************************************************************         //10-29-97|0x0c3b
UINT PRECOPER::po_box_empty(                                                              //09-03-17|0x0c3b
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-17|0x0c3b
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-17|0x0c3b
    ) {                                                                                   //09-03-17|0x0c3b
//*******************************************************************************         //10-29-97|0x0c3b
//***************************************************************************             //09-03-17|0x0c3e
//***************************************************************************             //09-03-17|0x0c3f
    if(FileMailBoxNoFiles   >  8)                          ReturnSystemError;             //09-06-20|0x0c40
    if(FileMailBoxFileNo    >= FileMailBoxNoFiles)         ReturnSystemError;             //09-06-20|0x0c41
//***************************************************************************             //09-06-20|0x0c42
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0c43
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-06|0x0c44
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0c45
//***************************************************************************             //09-03-17|0x0c46
    switch(TokensPrepare(ProcessTokensAddr, 1))                  _SwitchGroup             //09-03-17|0x0c47
//***************************************************************************             //09-03-17|0x0c48
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-17|0x0c49
      {                                                                                   //09-03-17|0x0c4a
//---------------------------------------------------------------------------             //09-03-17|0x0c4b
        case POSTOFFICE_OPENED:                   break_test(po_box_empty_1);             //09-03-17|0x0c4c
        case MAILBOX_OPENED:                      break_test(po_box_empty_2);             //09-03-17|0x0c4d
//---------------------------------------------------------------------------             //09-03-17|0x0c4e
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0c4f
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0c50
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0c51
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0c52
//---------------------------------------------------------------------------             //09-03-10|0x0c53
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0c54
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0c55
//---------------------------------------------------------------------------             //09-03-17|0x0c56
        default:                                            ReturnSystemError             //09-03-17|0x0c57
        }                                                                                 //09-03-17|0x0c58
//***************************************************************************             //09-03-17|0x0c59
    switch(MailDictTestMail(FileMailBoxFileNo,  ProcessTokensAddr))                       //10-01-06|0x0c5a
      {                                                                                   //09-03-17|0x0c5b
        case  Yes:                                return_yes(po_box_empty_3);             //09-03-17|0x0c5c
        case  No:                                  return_no(po_box_empty_4);             //09-03-17|0x0c5d
        case  UserError:                                   return(UserError);             //09-03-17|0x0c5e
        default:                                           ReturnSystemError;             //09-03-17|0x0c5f
        }                                                                                 //09-03-17|0x0c60
}                                                                                         //09-03-17|0x0c61
//                                                                                        //05-24-97|0x0c61
//***************************************************************************             //09-03-11|0x0c64
//***************************************************************************             //09-03-11|0x0c65
//******                                                               ******             //09-03-11|0x0c66
//******                        close_mailbox                          ******             //09-03-11|0x0c67
//******                                                               ******             //09-03-11|0x0c68
//***************************************************************************             //09-03-11|0x0c69
//***************************************************************************             //09-03-11|0x0c6a
//*******************************************************************************         //10-29-97|0x0c72
//*******************************************************************************         //10-29-97|0x0c72
// close_mailbox                                                                          //09-03-11|0x0c72
//*******************************************************************************         //10-29-97|0x0c72
//*******************************************************************************         //10-29-97|0x0c72
UINT PRECOPER::close_mailbox(                                                             //09-03-11|0x0c72
    PROCESS_DATA_FAR ProcessDataFar,                                                      //09-03-11|0x0c72
    PROCESS_FILES_FAR ProcessFilesFar                                                     //09-03-11|0x0c72
    ) {                                                                                   //09-03-11|0x0c72
//*******************************************************************************         //10-29-97|0x0c72
//***************************************************************************             //09-03-11|0x0c75
//***************************************************************************             //09-03-11|0x0c76
    if(ProcessFlagState != 0)            ReturnFinish("Test Flag Not Reset");             //09-03-11|0x0c77
    if(TokensNoTokens   != 1)                               ReturnSystemError             //09-03-11|0x0c78
//***************************************************************************             //09-03-11|0x0c79
    if(FileMailBoxNoFiles >  16)                           ReturnSystemError;             //09-06-20|0x0c7a
    if(FileMailBoxNoFiles == 0)             ReturnFinish("No MailBox Files");             //10-01-06|0x0c7b
    if(FileMailBoxFileNo  >= FileMailBoxNoFiles)            ReturnSystemError             //09-03-10|0x0c7c
//***************************************************************************             //09-06-20|0x0c7d
    if(FileMailBoxNoFiles == 0)     ReturnFinish("Unspecified MailBox File");             //09-03-11|0x0c7e
//***************************************************************************             //09-03-11|0x0c7f
    switch(FileMailBoxStatus(FileMailBoxFileNo))                                          //09-03-11|0x0c80
      {                                                                                   //09-03-11|0x0c81
//---------------------------------------------------------------------------             //09-03-11|0x0c82
        case POSTOFFICE_OPENED:                                                           //09-03-11|0x0c83
          switch(MailDictClose(FileMailBoxFileNo))               _SwitchGroup             //09-03-11|0x0c84
          FileMailBoxStatus(FileMailBoxFileNo) = OPENED_POSTOFFICE;                       //09-06-13|0x0c85
          return_test(close_mailbox_1);                                                   //09-03-11|0x0c86
//---------------------------------------------------------------------------             //09-03-11|0x0c87
        case MAILBOX_OPENED:                                                              //09-03-11|0x0c88
          switch(MailDictClose(FileMailBoxFileNo))               _SwitchGroup             //09-03-11|0x0c89
          FileMailBoxStatus(FileMailBoxFileNo) = OPENED_MAILBOX;                          //09-03-11|0x0c8a
          return_test(close_mailbox_2);                                                   //09-03-11|0x0c8b
//---------------------------------------------------------------------------             //09-03-11|0x0c8c
        case OPENED_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0c8d
        case OPENED_MAILBOX:        ReturnFinish("Mail Box File Not Opened");             //09-06-29|0x0c8e
        case OPEN_MAILBOX:          ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0c8f
        case CREATE_POSTOFFICE:     ReturnFinish("Mail Box File Not Opened");             //09-06-13|0x0c90
//---------------------------------------------------------------------------             //09-03-10|0x0c91
        case POSTOFFICE_FILE:       ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0c92
        case MAILBOX_FILE:          ReturnFinish("Mail Box File Deleted");                //10-01-06|0x0c93
//---------------------------------------------------------------------------             //09-03-11|0x0c94
        default:                                            ReturnSystemError             //09-03-11|0x0c95
        }                                                                                 //09-03-11|0x0c96
}                                                                                         //09-03-11|0x0c97
//                                                                                        //05-24-97|0x0c97
//***************************************************************************             //06-09-26|0x0c9a
//***************************************************************************             //06-09-26|0x0c9b
//******                                                               ******             //06-09-26|0x0c9c
//******                        debug_manager                          ******             //06-09-26|0x0c9d
//******                                                               ******             //06-09-26|0x0c9e
//***************************************************************************             //06-09-26|0x0c9f
//***************************************************************************             //06-09-26|0x0ca0
//*******************************************************************************         //10-29-97|0x0cab
//*******************************************************************************         //10-29-97|0x0cab
// debug_manager                                                                          //06-09-26|0x0cab
//*******************************************************************************         //10-29-97|0x0cab
//*******************************************************************************         //10-29-97|0x0cab
UINT PRECOPER::debug_manager(                                                             //06-09-26|0x0cab
    PROCESS_DATA_FAR ProcessDataFar,                                                      //06-09-26|0x0cab
    UINT DebugToken                                                                       //06-09-26|0x0cab
    ) {                                                                                   //06-09-26|0x0cab
//*******************************************************************************         //10-29-97|0x0cab
//***************************************************************************             //06-09-26|0x0cac
//***************************************************************************             //06-09-26|0x0cad
    switch(ProcessDebugCommand)                                                           //06-09-26|0x0cae
      {                                                                                   //06-09-26|0x0caf
//***************************************************************************             //06-09-26|0x0cb0
        case DBG_ON:                                                                      //06-10-01|0x0cb1
          switch(ProcessFlagState)                                                        //06-10-01|0x0cb2
            {                                                                             //06-10-01|0x0cb3
//---------------------------------------------------------------------------             //06-10-01|0x0cb4
              case 3:                                                                     //06-12-22|0x0cb5
                ProcessFlagState    = 2;                                                  //06-12-22|0x0cb6
                ProcessDebugCommand = DebugToken;                                         //06-12-22|0x0cb7
                return_test(debug_manager_11);                                            //06-12-22|0x0cb8
//---------------------------------------------------------------------------             //06-12-22|0x0cb9
              case 2:                                                                     //09-03-11|0x0cba
                return_test(debug_manager_11);                                            //09-03-11|0x0cbb
//---------------------------------------------------------------------------             //06-10-01|0x0cbc
              case  1:                                                                    //06-10-01|0x0cbd
              case  0:                                                                    //06-10-01|0x0cbe
              case -1:                                                                    //06-10-01|0x0cbf
              case -2:                                                                    //06-10-01|0x0cc0
                ProcessDebugCommand = DebugToken;                                         //06-10-01|0x0cc1
                return_test(debug_manager_11);                                            //06-10-01|0x0cc2
//---------------------------------------------------------------------------             //06-10-01|0x0cc3
              default:                                     ReturnSystemError;             //06-12-22|0x0cc4
              }                                                                           //06-12-22|0x0cc5
//***************************************************************************             //06-09-26|0x0cc6
        case DBG_OFF:                                                                     //06-09-26|0x0cc7
          switch(ProcessFlagState)                                                        //06-09-26|0x0cc8
            {                                                                             //06-09-26|0x0cc9
//---------------------------------------------------------------------------             //06-09-26|0x0cca
              case 3:                                                                     //09-03-11|0x0ccb
                ProcessFlagState    = 2;                                                  //09-03-11|0x0ccc
                return_test(debug_manager_21);                                            //09-03-11|0x0ccd
//---------------------------------------------------------------------------             //06-09-26|0x0cce
              case  2:                                                                    //06-09-26|0x0ccf
              case  1:                                                                    //06-09-26|0x0cd0
              case  0:                                                                    //06-09-26|0x0cd1
              case -1:                                                                    //06-09-26|0x0cd2
              case -2:                                                                    //06-09-26|0x0cd3
                return_test(debug_manager_21);                                            //06-09-26|0x0cd4
//---------------------------------------------------------------------------             //06-09-26|0x0cd5
              default:                                     ReturnSystemError;             //06-12-22|0x0cd6
              }                                                                           //06-12-22|0x0cd7
//***************************************************************************             //06-09-26|0x0cd8
        default:                                           ReturnSystemError;             //06-09-26|0x0cd9
        }                                                                                 //06-09-26|0x0cda
}                                                                                         //06-09-26|0x0cdb
//                                                                                        //05-24-97|0x0cdb
//***************************************************************************             //06-12-19|0x0cde
//***************************************************************************             //06-12-19|0x0cdf
//******                                                               ******             //06-12-19|0x0ce0
//******                       checkout_pause                          ******             //06-12-19|0x0ce1
//******                                                               ******             //06-12-19|0x0ce2
//***************************************************************************             //06-12-19|0x0ce3
//***************************************************************************             //06-12-19|0x0ce4
//*******************************************************************************         //10-29-97|0x0ce8
//*******************************************************************************         //10-29-97|0x0ce8
// checkout_pause                                                                         //06-12-19|0x0ce8
//*******************************************************************************         //10-29-97|0x0ce8
//*******************************************************************************         //10-29-97|0x0ce8
UINT PRECOPER::checkout_pause(                                                            //06-12-19|0x0ce8
    PROCESS_DATA_FAR ProcessDataFar,                                                      //06-12-19|0x0ce8
    SCHAR_FAR Name                                                                        //06-12-19|0x0ce8
    ) {                                                                                   //06-12-19|0x0ce8
//*******************************************************************************         //10-29-97|0x0ce8
//***************************************************************************             //06-12-19|0x0ceb
//***************************************************************************             //06-12-19|0x0cec
    switch(CheckoutMenu(Name))                                   _SwitchGroup             //09-03-11|0x0ced
//***************************************************************************             //06-12-19|0x0cee
    MemSet(&ProcessDebugName, 0x00, sizeof(STRING_DATA));                                 //06-12-19|0x0cef
    StrCpy(DebugNameLineAddr, "Checkout Debug: ");                                        //06-12-19|0x0cf0
    StrCat(DebugNameLineAddr, Name);                                                      //06-12-19|0x0cf1
    if(TruncStringSize(&DebugNameLength,  DebugNameLineAddr) != Success)                  //check   |0x0cf2
                                                           ReturnSystemError;             //check   |0x0cf3
    DebugNameType   = I_TOKEN;                                                            //06-12-19|0x0cf4
    return(Success);                                                                      //06-12-19|0x0cf5
}                                                                                         //06-12-19|0x0cf6
//                                                                                        //05-24-97|0x0cf6
//***************************************************************************             //06-07-14|0x0cf9
//***************************************************************************             //06-07-14|0x0cfa
//******                                                               ******             //06-07-14|0x0cfb
//******                       TEST WRAPPERS                           ******             //06-07-14|0x0cfc
//******                                                               ******             //06-07-14|0x0cfd
//***************************************************************************             //06-07-14|0x0cfe
//***************************************************************************             //06-07-14|0x0cff
//*******************************************************************************         //10-29-97|0x0d00
//*******************************************************************************         //10-29-97|0x0d00
// precoper_test_reset                                                                    //06-07-14|0x0d00
//*******************************************************************************         //10-29-97|0x0d00
//*******************************************************************************         //10-29-97|0x0d00
UINT PRECOPER::precoper_test_reset(void) {                                                //06-07-14|0x0d00
//*******************************************************************************         //10-29-97|0x0d00
//************************************************************************                //06-07-14|0x0d00
    switch(BasicTestReset())                                                              //06-07-14|0x0d00
      {                                                                                   //06-07-14|0x0d00
        case Success:                                     return(Success);                //06-07-14|0x0d00
        default:                                        ReturnSystemError;                //06-07-14|0x0d00
        }                                                                                 //06-07-14|0x0d00
}                                                                                         //06-07-14|0x0d00
//                                                                                        //05-24-97|0x0d00
//***************************************************************************             //06-07-14|0x0d01
//*******************************************************************************         //10-29-97|0x0d02
//*******************************************************************************         //10-29-97|0x0d02
// precoper_test_read                                                                     //06-07-14|0x0d02
//*******************************************************************************         //10-29-97|0x0d02
//*******************************************************************************         //10-29-97|0x0d02
UINT PRECOPER::precoper_test_read(void) {                                                 //06-07-14|0x0d02
//*******************************************************************************         //10-29-97|0x0d02
//************************************************************************                //06-07-14|0x0d02
    switch(BasicTestRead(&test_samples[0], test_samples[0]))                              //06-07-14|0x0d02
      {                                                                                   //06-07-14|0x0d02
        case Success:                                     return(Success);                //06-07-14|0x0d02
        default:                                        ReturnSystemError;                //06-07-14|0x0d02
        }                                                                                 //06-07-14|0x0d02
}                                                                                         //06-07-14|0x0d02
//                                                                                        //05-24-97|0x0d02
//***************************************************************************             //06-07-14|0x0d03
//*******************************************************************************         //10-29-97|0x0d04
//*******************************************************************************         //10-29-97|0x0d04
// precoper_test_write                                                                    //06-07-14|0x0d04
//*******************************************************************************         //10-29-97|0x0d04
//*******************************************************************************         //10-29-97|0x0d04
UINT PRECOPER::precoper_test_write(void) {                                                //06-07-14|0x0d04
//*******************************************************************************         //10-29-97|0x0d04
//************************************************************************                //06-07-14|0x0d04
    switch(BasicTestWrite(&test_samples[0]))                                              //06-07-14|0x0d04
      {                                                                                   //06-07-14|0x0d04
        case Success:                                     return(Success);                //06-07-14|0x0d04
        default:                                        ReturnSystemError;                //06-07-14|0x0d04
        }                                                                                 //06-07-14|0x0d04
}                                                                                         //06-07-14|0x0d04
//                                                                                        //05-24-97|0x0d04
//***************************************************************************             //06-07-14|0x0d05
//*******************************************************************************         //10-29-97|0x0d06
//*******************************************************************************         //10-29-97|0x0d06
// precoper_test_report                                                                   //06-07-14|0x0d06
//*******************************************************************************         //10-29-97|0x0d06
//*******************************************************************************         //10-29-97|0x0d06
UINT PRECOPER::precoper_test_report(void) {                                               //06-07-14|0x0d06
//*******************************************************************************         //10-29-97|0x0d06
//************************************************************************                //06-07-14|0x0d06
    switch(BasicTestReport(&test_samples[0], "PRECOPER"))                                 //06-07-14|0x0d06
      {                                                                                   //06-07-14|0x0d06
        case Success:                                     return(Success);                //06-07-14|0x0d06
        default:                                        ReturnSystemError;                //06-07-14|0x0d06
        }                                                                                 //06-07-14|0x0d06
}                                                                                         //06-07-14|0x0d06
//                                                                                        //05-24-97|0x0d06
//***************************************************************************             //06-07-14|0x0d07
//***************************************************************************             //06-07-14|0x0d08
//******                                                               ******             //06-07-14|0x0d09
//******                        constructor                            ******             //06-07-14|0x0d0a
//******                                                               ******             //06-07-14|0x0d0b
//***************************************************************************             //06-07-14|0x0d0c
//***************************************************************************             //06-07-14|0x0d0d
//*******************************************************************************         //10-29-97|0x0d0e
//*******************************************************************************         //10-29-97|0x0d0e
// CONSTRUCTOR                                                                            //06-07-14|0x0d0e
//*******************************************************************************         //10-29-97|0x0d0e
//*******************************************************************************         //10-29-97|0x0d0e
PRECOPER::PRECOPER() {                                                                    //06-07-14|0x0d0e
//***************************************************************************             //06-07-14|0x0d0f
//***************************************************************************             //06-07-14|0x0d10
    { ULONG i;                                                                            //06-07-14|0x0d11
      test_samples[NoTestSamples] = TestIndex;                                            //06-07-14|0x0d11
      i = 1;                                                                              //06-07-14|0x0d11
      while(i<TestIndex)                                                                  //06-07-14|0x0d11
        {                                                                                 //06-07-14|0x0d11
          test_samples[i] = 0;                                                            //06-07-14|0x0d11
          ++i;                                                                            //06-07-14|0x0d11
          }                                                                               //06-07-14|0x0d11
      }                                                                                   //06-07-14|0x0d11
}                                                                                         //06-07-14|0x0d12
//                                                                                        //05-24-97|0x0d12
//*******************************************************************************         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
//****                       END OF FILE                                     ****         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
