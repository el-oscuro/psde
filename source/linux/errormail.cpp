//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
// MAILBOX DICTIONARY_MANAGER                                                             //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-11-09|0x000b
//  defined in the associated manual.                                                     //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-11-09|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-11-09|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-11-09|0x000b
//  (at your option) any later version.                                                   //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-11-09|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-11-09|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-11-09|0x000b
//  GNU General Public License for more details.                                          //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//  You should have received a copy of the GNU General Public License                     //07-11-09|0x000b
//  along with this program; if not, write to the Free Software                           //07-11-09|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-11-09|0x000b
//  USA                                                                                   //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  For further information, please contact Robert Adams:                                 //07-11-09|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-11-09|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-11-09|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
#ifdef WIN31_SYSTEM                                                                       //05-24-97|0x000c
#include "precwn31.h"                                                                     //05-24-97|0x000c
#endif                                                                                    //05-24-97|0x000c
#ifdef WIN95_SYSTEM                                                                       //05-24-97|0x000c
#include "precwn95.h"                                                                     //05-24-97|0x000c
#endif                                                                                    //05-24-97|0x000c
#ifdef MSDOS_SYSTEM                                                                       //05-24-97|0x000c
#include "precdos.h"                                                                      //05-24-97|0x000c
#endif                                                                                    //05-24-97|0x000c
#include "prechost.h"                                                                     //05-24-97|0x000c
#include "errormail.h"                                                                    //07-11-09|0x000c
#include "errormail.hxx"                                                                  //07-11-09|0x000c
#include "errormail.hpp"                                                                  //07-11-09|0x000c
#include "precdiag.h"                                                                     //07-11-09|0x000d
#define StrCmp(i,j) ((strcmp(i,j) == 0) ? 0 : 1)                                          //07-11-09|0x0015
#define StrLen(i) strlen(i)                                                               //07-11-09|0x0015
#define StrCat(i,j) strcat(i,j)                                                           //07-11-09|0x0015
#define StrCpy(i,j) strcpy(i,j)                                                           //07-11-09|0x0015
#define StrChr(i,j) strchr(i,j)                                                           //07-11-09|0x0015
#define StrRChr(i,j) strrchr(i,j)                                                         //07-11-09|0x0015
#define StrToByteInt(i,j) GetInteger(i,&j,0xff)                                           //07-11-09|0x0015
#define StrToInt(i,j) GetInteger(i,&j,0xffff)                                             //07-11-09|0x0015
#define StrToLongInt(i,j) GetInteger(i,&j,0xffffffffL)                                    //07-11-09|0x0015
#define StrToByteHex(i,j) GetHex(i,&j,1)                                                  //07-11-09|0x0015
#define StrToHex(i,j) GetHex(i,&j,2)                                                      //07-11-09|0x0015
#define StrToLongHex(i,j) GetHex(i,&j,4)                                                  //07-11-09|0x0015
#define FindName(i) strrchr(i, '/')                                                       //07-11-09|0x0015
#define Allocate(k) (k##_FAR) calloc(1,sizeof(k))                                         //07-11-09|0x0016
#define Free(k) free(k)                                                                   //07-11-09|0x0016
#define MemSet(i,j,k) memset(i,j,k)                                                       //07-11-09|0x0016
#define MemCCpy(i,j,k,l) Mem_C_Copy((UCHAR_FAR) i, (UCHAR_FAR) j,k,l)                     //07-11-09|0x0016
#define MemCpy(i,j,k) memcpy(i,j,k)                                                       //07-11-09|0x0016
#define LineEnd 0x0d                                                                      //07-11-09|0x0016
ERRORMAIL error_mail;                                                                     //07-11-09|0x0033
static UINT test_samples[TestIndex];                                                      //07-11-09|0x0043
//***************************************************************************             //07-11-12|0x0049
//***************************************************************************             //07-11-12|0x004a
//******                                                               ******             //07-11-12|0x004b
//******          errormail_add_macro(MacroName)                       ******             //07-11-12|0x004c
//******                                                               ******             //07-11-12|0x004d
//***************************************************************************             //07-11-12|0x004e
//***************************************************************************             //07-11-12|0x004f
//*******************************************************************************         //10-29-97|0x0054
//*******************************************************************************         //10-29-97|0x0054
// errormail_add_macro                                                                    //07-11-12|0x0054
//*******************************************************************************         //10-29-97|0x0054
//*******************************************************************************         //10-29-97|0x0054
UINT ERRORMAIL::errormail_add_macro(                                                      //07-11-12|0x0054
    STRING_DATA_FAR Addr                                                                  //07-11-12|0x0054
    ) {                                                                                   //07-11-12|0x0054
//*******************************************************************************         //10-29-97|0x0054
//***************************************************************************             //07-11-12|0x0058
//***************************************************************************             //07-11-12|0x0059
    if(AddrLength           >= 256)                         ReturnSystemError             //07-11-12|0x005a
    if(AddrLength           == 0)                           ReturnSystemError             //07-11-12|0x005b
    if(AddrChar(AddrLength) != 0)                           ReturnSystemError             //07-11-12|0x005c
    if((ULONG) AddrLength   != StrLen(AddrLineAddr))        ReturnSystemError             //07-11-12|0x005d
//***************************************************************************             //07-11-12|0x005e
    MemSet(&error_tokens,      0x00,  sizeof(TOKENS));                                    //07-11-12|0x005f
    MemCpy(TokensTokenAddr(0), Addr,  sizeof(STRING_DATA));                               //07-11-12|0x0060
    TokensNoTokens = 1;                                                                   //07-11-12|0x0061
    return_test(errormail_add_macro_1);                                                   //07-11-12|0x0062
}                                                                                         //07-11-12|0x0063
//                                                                                        //05-24-97|0x0063
//***************************************************************************             //07-11-12|0x0066
//***************************************************************************             //07-11-12|0x0067
//******                                                               ******             //07-11-12|0x0068
//******          errormail_add_error(ErrorName)                       ******             //07-11-12|0x0069
//******                                                               ******             //07-11-12|0x006a
//***************************************************************************             //07-11-12|0x006b
//***************************************************************************             //07-11-12|0x006c
//*******************************************************************************         //10-29-97|0x0071
//*******************************************************************************         //10-29-97|0x0071
// errormail_add_error                                                                    //07-11-12|0x0071
//*******************************************************************************         //10-29-97|0x0071
//*******************************************************************************         //10-29-97|0x0071
UINT ERRORMAIL::errormail_add_error(                                                      //07-11-12|0x0071
    STRING_DATA_FAR Addr                                                                  //07-11-12|0x0071
    ) {                                                                                   //07-11-12|0x0071
//*******************************************************************************         //10-29-97|0x0071
//***************************************************************************             //07-11-12|0x0075
//***************************************************************************             //07-11-12|0x0076
    if(TokensNoTokens       != 1)                           ReturnSystemError             //07-11-12|0x0077
//***************************************************************************             //07-11-12|0x0078
    if(AddrLength           >= 256)                         ReturnSystemError             //07-11-12|0x0079
    if(AddrLength           == 0)                           ReturnSystemError             //07-11-12|0x007a
    if(AddrChar(AddrLength) != 0)                           ReturnSystemError             //07-11-12|0x007b
    if((ULONG) AddrLength   != StrLen(AddrLineAddr))        ReturnSystemError             //07-11-12|0x007c
//***************************************************************************             //07-11-12|0x007d
    MemCpy(TokensTokenAddr(1), Addr,  sizeof(STRING_DATA));                               //07-11-12|0x007e
    TokensNoTokens = 2;                                                                   //07-11-12|0x007f
    return_test(errormail_add_error_1);                                                   //07-11-12|0x0080
}                                                                                         //07-11-12|0x0081
//                                                                                        //05-24-97|0x0081
//***************************************************************************             //07-11-17|0x0084
//***************************************************************************             //07-11-17|0x0085
//******                                                               ******             //07-11-17|0x0086
//******          errormail_test_error                                 ******             //07-11-17|0x0087
//******                                                               ******             //07-11-17|0x0088
//***************************************************************************             //07-11-17|0x0089
//***************************************************************************             //07-11-17|0x008a
//*******************************************************************************         //10-29-97|0x0091
//*******************************************************************************         //10-29-97|0x0091
// errormail_test_error                                                                   //07-11-17|0x0091
//*******************************************************************************         //10-29-97|0x0091
//*******************************************************************************         //10-29-97|0x0091
UINT ERRORMAIL::errormail_test_error(void) {                                              //07-11-17|0x0091
//*******************************************************************************         //10-29-97|0x0091
//***************************************************************************             //07-11-17|0x0095
//***************************************************************************             //07-11-17|0x0096
    switch(TokensNoTokens)                                                                //07-11-17|0x0097
      {                                                                                   //07-11-17|0x0098
        case 0:                           return_no(errormail_test_error_1);              //07-11-17|0x0099
        case 1:                           return_no(errormail_test_error_1);              //07-11-17|0x009a
        case 2:                           return_yes(errormail_test_error_1);             //07-11-17|0x009b
        default:                                            ReturnSystemError             //07-11-17|0x009c
        }                                                                                 //07-11-17|0x009d
}                                                                                         //07-11-17|0x009e
//                                                                                        //05-24-97|0x009e
//***************************************************************************             //07-11-16|0x00a1
//***************************************************************************             //07-11-16|0x00a2
//******                                                               ******             //07-11-16|0x00a3
//******          errormail_read_macro                                 ******             //07-11-16|0x00a4
//******                                                               ******             //07-11-16|0x00a5
//***************************************************************************             //07-11-16|0x00a6
//***************************************************************************             //07-11-16|0x00a7
//*******************************************************************************         //10-29-97|0x00ac
//*******************************************************************************         //10-29-97|0x00ac
// errormail_read_macro                                                                   //07-11-16|0x00ac
//*******************************************************************************         //10-29-97|0x00ac
//*******************************************************************************         //10-29-97|0x00ac
UINT ERRORMAIL::errormail_read_macro(                                                     //07-11-16|0x00ac
    STRING_DATA_FAR Addr                                                                  //07-11-16|0x00ac
    ) {                                                                                   //07-11-16|0x00ac
//*******************************************************************************         //10-29-97|0x00ac
//***************************************************************************             //07-11-16|0x00b0
//***************************************************************************             //07-11-16|0x00b1
    if(TokensNoTokens       != 2)              ReturnFinish("No Error Mail");             //07-11-16|0x00b2
//***************************************************************************             //07-11-16|0x00b3
    MemCpy(Addr, TokensTokenAddr(0),  sizeof(STRING_DATA));                               //07-11-16|0x00b4
//***************************************************************************             //07-11-16|0x00b5
    if(AddrLength           >= 256)                         ReturnSystemError             //07-11-16|0x00b6
    if(AddrLength           == 0)                           ReturnSystemError             //07-11-16|0x00b7
    if(AddrChar(AddrLength) != 0)                           ReturnSystemError             //07-11-16|0x00b8
    if((ULONG) AddrLength   != StrLen(AddrLineAddr))        ReturnSystemError             //07-11-16|0x00b9
    return_test(errormail_read_macro_1);                                                  //07-11-16|0x00ba
}                                                                                         //07-11-16|0x00bb
//                                                                                        //05-24-97|0x00bb
//***************************************************************************             //07-11-16|0x00be
//***************************************************************************             //07-11-16|0x00bf
//******                                                               ******             //07-11-16|0x00c0
//******          errormail_read_error                                 ******             //07-11-16|0x00c1
//******                                                               ******             //07-11-16|0x00c2
//***************************************************************************             //07-11-16|0x00c3
//***************************************************************************             //07-11-16|0x00c4
//*******************************************************************************         //10-29-97|0x00c9
//*******************************************************************************         //10-29-97|0x00c9
// errormail_read_error                                                                   //07-11-16|0x00c9
//*******************************************************************************         //10-29-97|0x00c9
//*******************************************************************************         //10-29-97|0x00c9
UINT ERRORMAIL::errormail_read_error(                                                     //07-11-16|0x00c9
    STRING_DATA_FAR Addr                                                                  //07-11-16|0x00c9
    ) {                                                                                   //07-11-16|0x00c9
//*******************************************************************************         //10-29-97|0x00c9
//***************************************************************************             //07-11-16|0x00cd
//***************************************************************************             //07-11-16|0x00ce
    if(TokensNoTokens       != 2)              ReturnFinish("No Error Mail");             //07-11-16|0x00cf
//***************************************************************************             //07-11-16|0x00d0
    MemCpy(Addr, TokensTokenAddr(1),  sizeof(STRING_DATA));                               //07-11-16|0x00d1
//***************************************************************************             //07-11-16|0x00d2
    if(AddrLength           >= 256)                         ReturnSystemError             //07-11-16|0x00d3
    if(AddrLength           == 0)                           ReturnSystemError             //07-11-16|0x00d4
    if(AddrChar(AddrLength) != 0)                           ReturnSystemError             //07-11-16|0x00d5
    if((ULONG) AddrLength   != StrLen(AddrLineAddr))        ReturnSystemError             //07-11-16|0x00d6
    return_test(errormail_read_error_1);                                                  //07-11-16|0x00d7
}                                                                                         //07-11-16|0x00d8
//                                                                                        //05-24-97|0x00d8
//***************************************************************************             //07-11-09|0x00db
//***************************************************************************             //07-11-09|0x00dc
//******                                                               ******             //07-11-09|0x00dd
//******                       TEST WRAPPERS                           ******             //07-11-09|0x00de
//******                                                               ******             //07-11-09|0x00df
//***************************************************************************             //07-11-09|0x00e0
//***************************************************************************             //07-11-09|0x00e1
//*******************************************************************************         //10-29-97|0x00e2
//*******************************************************************************         //10-29-97|0x00e2
// errormail_test_reset                                                                   //07-11-09|0x00e2
//*******************************************************************************         //10-29-97|0x00e2
//*******************************************************************************         //10-29-97|0x00e2
UINT ERRORMAIL::errormail_test_reset(void) {                                              //07-11-09|0x00e2
//*******************************************************************************         //10-29-97|0x00e2
//************************************************************************                //07-11-09|0x00e2
    switch(BasicTestReset())                                                              //07-11-09|0x00e2
      {                                                                                   //07-11-09|0x00e2
        case Success:                                     return(Success);                //07-11-09|0x00e2
        default:                                        ReturnSystemError;                //07-11-09|0x00e2
        }                                                                                 //07-11-09|0x00e2
}                                                                                         //07-11-09|0x00e2
//                                                                                        //05-24-97|0x00e2
//***************************************************************************             //07-11-09|0x00e3
//*******************************************************************************         //10-29-97|0x00e4
//*******************************************************************************         //10-29-97|0x00e4
// errormail_test_read                                                                    //07-11-09|0x00e4
//*******************************************************************************         //10-29-97|0x00e4
//*******************************************************************************         //10-29-97|0x00e4
UINT ERRORMAIL::errormail_test_read(void) {                                               //07-11-09|0x00e4
//*******************************************************************************         //10-29-97|0x00e4
//************************************************************************                //07-11-09|0x00e4
    switch(BasicTestRead(&test_samples[0], test_samples[0]))                              //07-11-09|0x00e4
      {                                                                                   //07-11-09|0x00e4
        case Success:                                     return(Success);                //07-11-09|0x00e4
        default:                                        ReturnSystemError;                //07-11-09|0x00e4
        }                                                                                 //07-11-09|0x00e4
}                                                                                         //07-11-09|0x00e4
//                                                                                        //05-24-97|0x00e4
//***************************************************************************             //07-11-09|0x00e5
//*******************************************************************************         //10-29-97|0x00e6
//*******************************************************************************         //10-29-97|0x00e6
// errormail_test_write                                                                   //07-11-09|0x00e6
//*******************************************************************************         //10-29-97|0x00e6
//*******************************************************************************         //10-29-97|0x00e6
UINT ERRORMAIL::errormail_test_write(void) {                                              //07-11-09|0x00e6
//*******************************************************************************         //10-29-97|0x00e6
//************************************************************************                //07-11-09|0x00e6
    switch(BasicTestWrite(&test_samples[0]))                                              //07-11-09|0x00e6
      {                                                                                   //07-11-09|0x00e6
        case Success:                                     return(Success);                //07-11-09|0x00e6
        default:                                        ReturnSystemError;                //07-11-09|0x00e6
        }                                                                                 //07-11-09|0x00e6
}                                                                                         //07-11-09|0x00e6
//                                                                                        //05-24-97|0x00e6
//***************************************************************************             //07-11-09|0x00e7
//*******************************************************************************         //10-29-97|0x00e8
//*******************************************************************************         //10-29-97|0x00e8
// errormail_test_report                                                                  //07-11-09|0x00e8
//*******************************************************************************         //10-29-97|0x00e8
//*******************************************************************************         //10-29-97|0x00e8
UINT ERRORMAIL::errormail_test_report(void) {                                             //07-11-09|0x00e8
//*******************************************************************************         //10-29-97|0x00e8
//************************************************************************                //07-11-09|0x00e8
    switch(BasicTestReport(&test_samples[0], "ERRORMAIL"))                                //07-11-09|0x00e8
      {                                                                                   //07-11-09|0x00e8
        case Success:                                     return(Success);                //07-11-09|0x00e8
        default:                                        ReturnSystemError;                //07-11-09|0x00e8
        }                                                                                 //07-11-09|0x00e8
}                                                                                         //07-11-09|0x00e8
//                                                                                        //05-24-97|0x00e8
//***************************************************************************             //07-11-09|0x00eb
//***************************************************************************             //07-11-09|0x00ec
//******                                                               ******             //07-11-09|0x00ed
//******                        constructor                            ******             //07-11-09|0x00ee
//******                                                               ******             //07-11-09|0x00ef
//***************************************************************************             //07-11-09|0x00f0
//***************************************************************************             //07-11-09|0x00f1
//*******************************************************************************         //10-29-97|0x00f2
//*******************************************************************************         //10-29-97|0x00f2
// CONSTRUCTOR                                                                            //07-11-09|0x00f2
//*******************************************************************************         //10-29-97|0x00f2
//*******************************************************************************         //10-29-97|0x00f2
ERRORMAIL::ERRORMAIL() {                                                                  //07-11-09|0x00f2
//***************************************************************************             //07-11-09|0x00f3
//***************************************************************************             //07-11-09|0x00f4
    MemSet(&error_tokens,      0x00,  sizeof(TOKENS));                                    //07-11-09|0x00f5
//***************************************************************************             //07-11-09|0x00f6
    { ULONG i;                                                                            //07-11-09|0x00f7
      test_samples[NoTestSamples] = TestIndex;                                            //07-11-09|0x00f7
      i = 1;                                                                              //07-11-09|0x00f7
      while(i<TestIndex)                                                                  //07-11-09|0x00f7
        {                                                                                 //07-11-09|0x00f7
          test_samples[i] = 0;                                                            //07-11-09|0x00f7
          ++i;                                                                            //07-11-09|0x00f7
          }                                                                               //07-11-09|0x00f7
      }                                                                                   //07-11-09|0x00f7
//***************************************************************************             //07-11-09|0x00f8
}                                                                                         //07-11-09|0x00f9
//                                                                                        //05-24-97|0x00f9
//*******************************************************************************         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
//****                       END OF FILE                                     ****         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
