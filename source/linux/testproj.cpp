//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
// TEST PROJECT                                                                           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x0008
//  defined in the associated manual.                                                     //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x0008
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x0008
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x0008
//  (at your option) any later version.                                                   //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x0008
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x0008
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x0008
//  GNU General Public License for more details.                                          //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x0008
//  along with this program; if not, write to the Free Software                           //06-07-12|0x0008
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x0008
//  USA                                                                                   //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  For further information, please contact Robert Adams:                                 //06-07-12|0x0008
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x0008
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x0008
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
#ifdef WIN31_SYSTEM                                                                       //05-24-97|0x000b
#include "precwn31.h"                                                                     //05-24-97|0x000b
#endif                                                                                    //05-24-97|0x000b
#ifdef WIN95_SYSTEM                                                                       //05-24-97|0x000b
#include "precwn95.h"                                                                     //05-24-97|0x000b
#endif                                                                                    //05-24-97|0x000b
#ifdef MSDOS_SYSTEM                                                                       //05-24-97|0x000b
#include "precdos.h"                                                                      //05-24-97|0x000b
#endif                                                                                    //05-24-97|0x000b
#include "prechost.h"                                                                     //05-24-97|0x000b
#include "testproj.h"                                                                     //06-07-12|0x000b
#include "testproj.hxx"                                                                   //06-07-12|0x000b
#include "testproj.hpp"                                                                   //06-07-12|0x000b
#include "precutil.h"                                                                     //11-12-17|0x000d
#include "errormail.h"                                                                    //07-12-28|0x000e
#include "guicomm.h"                                                                      //04-10-18|0x000f
#include "prectext.h"                                                                     //06-07-12|0x0010
#include "precdbug.h"                                                                     //06-07-12|0x0011
#include "preccall.h"                                                                     //06-07-12|0x0012
#include "precnum.h"                                                                      //06-07-12|0x0013
#include "precdiag.h"                                                                     //06-07-12|0x0014
#include "precfile.h"                                                                     //06-07-12|0x0015
#include "crypto.h"                                                                       //15-06-16|0x0016
#include "devproj.h"                                                                      //06-07-12|0x0017
#include "global.hxx"                                                                     //06-12-09|0x0018
#define Allocate(k) (k##_FAR) calloc(1,sizeof(k))                                         //06-07-12|0x0020
#define Free(k) free(k)                                                                   //06-07-12|0x0020
#define MemSet(i,j,k) memset(i,j,k)                                                       //06-07-12|0x0020
#define MemCCpy(i,j,k,l) Mem_C_Copy((UCHAR_FAR) i, (UCHAR_FAR) j,k,l)                     //06-07-12|0x0020
#define MemCpy(i,j,k) memcpy(i,j,k)                                                       //06-07-12|0x0020
#define LineEnd 0x0d                                                                      //06-07-12|0x0020
#define StrLen(i) strlen(i)                                                               //06-07-12|0x0021
#define StrCat(i,j) strcat(i,j)                                                           //06-07-12|0x0021
#define StrCpy(i,j) strcpy(i,j)                                                           //06-07-12|0x0021
#define StrCmp(i,j) Str_Comp((SCHAR_FAR)i,j,256)                                          //06-07-12|0x0021
#define StrRChr(i,j) strrchr(i,j)                                                         //06-07-12|0x0021
#define StrChr(i,j) strchr(i,j)                                                           //06-07-12|0x0021
#define StrToByteInt(i,j) GetInteger(i,&j,0xff)                                           //06-07-12|0x0021
#define StrToInt(i,j) GetInteger(i,&j,0xffff)                                             //06-07-12|0x0021
#define StrToLongInt(i,j) GetInteger(i,&j,0xffffffffL)                                    //06-07-12|0x0021
#define StrToByteHex(i,j) GetHex(i,&j,1)                                                  //06-07-12|0x0021
#define StrToHex(i,j) GetHex(i,&j,2)                                                      //06-07-12|0x0021
#define StrToLongHex(i,j) GetHex(i,&j,4)                                                  //06-07-12|0x0021
#define FindName(i) strrchr(i, '/')                                                       //06-07-12|0x0021
TESTPROJ test_proj;                                                                       //06-07-12|0x004d
static UINT test_samples[TestIndex];                                                      //06-07-12|0x005d
#define FirstArg 1                                                                        //06-07-12|0x007a
//***************************************************************************             //06-07-12|0x007f
//***************************************************************************             //06-07-12|0x0080
//******                                                               ******             //06-07-12|0x0081
//******                      test_proj_allocate                       ******             //06-07-12|0x0082
//******                                                               ******             //06-07-12|0x0083
//***************************************************************************             //06-07-12|0x0084
//***************************************************************************             //06-07-12|0x0085
//*******************************************************************************         //10-29-97|0x008c
//*******************************************************************************         //10-29-97|0x008c
// test_proj_allocate                                                                     //06-07-12|0x008c
//*******************************************************************************         //10-29-97|0x008c
//*******************************************************************************         //10-29-97|0x008c
UINT TESTPROJ::test_proj_allocate(void) {                                                 //06-07-12|0x008c
//*******************************************************************************         //10-29-97|0x008c
//***************************************************************************             //06-07-12|0x0090
//***************************************************************************             //06-07-12|0x0091
    TestSample(test_proj_allocate_1);                                                     //06-07-12|0x0092
    if(test_proj_addr                           != 0)       ReturnSystemError             //06-07-12|0x0093
    test_proj_addr = Allocate(TEST_BASE);                                                 //06-07-12|0x0094
    if(test_proj_addr                           == 0)       ReturnSystemError             //06-07-12|0x0095
//***************************************************************************             //06-12-09|0x0096
  BaseState = 2286; // INITIAL_SYSTEM                                                     //06-12-09|0x0097
//***************************************************************************             //06-12-09|0x0098
    return(Success);                                                                      //06-07-12|0x0099
}                                                                                         //06-07-12|0x009a
//                                                                                        //05-24-97|0x009a
//***************************************************************************             //06-07-12|0x009d
//***************************************************************************             //06-07-12|0x009e
//******                                                               ******             //06-07-12|0x009f
//******                         test_proj_free                        ******             //06-07-12|0x00a0
//******                                                               ******             //06-07-12|0x00a1
//***************************************************************************             //06-07-12|0x00a2
//***************************************************************************             //06-07-12|0x00a3
//*******************************************************************************         //10-29-97|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
// test_proj_free                                                                         //06-07-12|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
UINT TESTPROJ::test_proj_free(void) {                                                     //06-07-12|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
//***************************************************************************             //06-07-12|0x00ab
//***************************************************************************             //06-07-12|0x00ac
    TestSample(test_proj_free_1);                                                         //06-07-12|0x00ad
    if(test_proj_addr == 0)                                 ReturnSystemError             //06-07-12|0x00ae
    Free(test_proj_addr);                                                                 //06-07-12|0x00af
    test_proj_addr = 0;                                                                   //06-07-12|0x00b0
//***************************************************************************             //06-07-12|0x00b1
    return(Success);                                                                      //06-07-12|0x00b2
}                                                                                         //06-07-12|0x00b3
//                                                                                        //05-24-97|0x00b3
//***************************************************************************             //06-12-09|0x00b6
//***************************************************************************             //06-12-09|0x00b7
//******                                                               ******             //06-12-09|0x00b8
//******        test_proj_process(InputTokensFar)                      ******             //06-12-09|0x00b9
//******                                                               ******             //06-12-09|0x00ba
//***************************************************************************             //06-12-09|0x00bb
//***************************************************************************             //06-12-09|0x00bc
//*******************************************************************************         //10-29-97|0x00c0
//*******************************************************************************         //10-29-97|0x00c0
// test_proj_process                                                                      //07-10-13|0x00c0
//*******************************************************************************         //10-29-97|0x00c0
//*******************************************************************************         //10-29-97|0x00c0
UINT TESTPROJ::test_proj_process(                                                         //07-10-13|0x00c0
    TOKENS_FAR InputTokensFar,                                                            //07-10-13|0x00c0
    ULONG MainProjTime                                                                    //07-10-13|0x00c0
    ) {                                                                                   //07-10-13|0x00c0
//*******************************************************************************         //10-29-97|0x00c0
//***************************************************************************             //06-12-09|0x00c4
//***************************************************************************             //06-12-09|0x00c5
    if(test_proj_addr == 0)                                 ReturnSystemError             //06-12-09|0x00c6
//***************************************************************************             //06-12-09|0x00c7
//******                                                               ******             //06-12-09|0x00c8
//******  STATE MACHINE STARTS                                         ******             //06-12-09|0x00c9
//******                                                               ******             //06-12-09|0x00ca
//***************************************************************************             //06-12-09|0x00cb
  BaseRunFlag = 1;                                                                        //06-12-09|0x00cc
  while(BaseRunFlag != 0)                                                                 //06-12-09|0x00cc
  {                                                                                       //06-12-09|0x00cc
    switch(BaseState)                                                                     //06-12-09|0x00cc
    {                                                                                     //06-12-09|0x00cc
//***************************************************************************             //06-12-09|0x00cd
//******                                                               ******             //06-12-09|0x00ce
//******  Initial System                                               ******             //06-12-09|0x00cf
//******                                                               ******             //06-12-09|0x00d0
//***************************************************************************             //06-12-09|0x00d1
      case 2286: // INITIAL_SYSTEM                                                        //06-12-09|0x00d2
        initial();                                                                        //06-12-09|0x00d2
        BaseState = 38989; // PROJECT_NAME                                                //06-12-09|0x00d2
        break;                                                                            //06-12-09|0x00d2
//***************************************************************************             //06-12-09|0x00d3
//******                                                               ******             //06-12-09|0x00d4
//******  Open the Test Project File                                   ******             //06-12-09|0x00d5
//******                                                               ******             //06-12-09|0x00d6
//***************************************************************************             //06-12-09|0x00d7
      case 38989: // PROJECT_NAME                                                         //06-12-09|0x00d8
        switch(enter_project_name(InputLineAddr(0)))                                      //06-12-09|0x00d8
        {                                                                                 //06-12-09|0x00d8
          case Success:                                                                   //06-12-09|0x00d8
            BaseRunFlag = 1;                                                              //06-12-09|0x00d8
            BaseState = 7580; // PROJECT_EXIST                                            //06-12-09|0x00d8
            break;                                                                        //06-12-09|0x00d8
          default:                                                                        //06-12-09|0x00d8
            BaseStatus = SystemError;                                                     //06-12-09|0x00d8
            BaseRunFlag = 0;                                                              //06-12-09|0x00d8
            SystemMsg;                                                                    //06-12-09|0x00d8
            break;                                                                        //06-12-09|0x00d8
        }                                                                                 //06-12-09|0x00d8
        break;                                                                            //06-12-09|0x00d8
//***************************************************************************             //06-12-09|0x00d9
      case 7580: // PROJECT_EXIST                                                         //06-12-09|0x00da
        switch(ProjectExists)                                                             //06-12-09|0x00da
        {                                                                                 //06-12-09|0x00da
          case Success:                                                                   //06-12-09|0x00da
            BaseRunFlag = 1;                                                              //06-12-09|0x00da
            BaseState = 63451; // PROJECT_OPEN                                            //06-12-09|0x00da
            break;                                                                        //06-12-09|0x00da
          case UserError:                                                                 //06-12-09|0x00da
            BaseRunFlag = 1;                                                              //06-12-09|0x00da
            BaseState = 30218; // NO_PROJECT_FILE                                         //06-12-09|0x00da
            break;                                                                        //06-12-09|0x00da
          default:                                                                        //06-12-09|0x00da
            BaseStatus = SystemError;                                                     //06-12-09|0x00da
            BaseRunFlag = 0;                                                              //06-12-09|0x00da
            SystemMsg;                                                                    //06-12-09|0x00da
            break;                                                                        //06-12-09|0x00da
        }                                                                                 //06-12-09|0x00da
        break;                                                                            //06-12-09|0x00da
//***************************************************************************             //06-12-09|0x00db
      case 30218: // NO_PROJECT_FILE                                                      //06-12-09|0x00dc
        switch(ProjectDoesNotExist)                                                       //06-12-09|0x00dc
        {                                                                                 //06-12-09|0x00dc
          case UserError:                                                                 //06-12-09|0x00dc
            BaseRunFlag = 1;                                                              //06-12-09|0x00dc
            BaseState = 55081; // USER                                                    //06-12-09|0x00dc
            break;                                                                        //06-12-09|0x00dc
          default:                                                                        //06-12-09|0x00dc
            BaseStatus = SystemError;                                                     //06-12-09|0x00dc
            BaseRunFlag = 0;                                                              //06-12-09|0x00dc
            SystemMsg;                                                                    //06-12-09|0x00dc
            break;                                                                        //06-12-09|0x00dc
        }                                                                                 //06-12-09|0x00dc
        break;                                                                            //06-12-09|0x00dc
//***************************************************************************             //06-12-09|0x00dd
      case 63451: // PROJECT_OPEN                                                         //06-12-09|0x00de
        switch(open_project())                                                            //06-12-09|0x00de
        {                                                                                 //06-12-09|0x00de
          case Success:                                                                   //06-12-09|0x00de
            BaseRunFlag = 1;                                                              //06-12-09|0x00de
            BaseState = 19000; // FIRST_CONFIG_READ                                       //06-12-09|0x00de
            break;                                                                        //06-12-09|0x00de
          default:                                                                        //06-12-09|0x00de
            BaseStatus = SystemError;                                                     //06-12-09|0x00de
            BaseRunFlag = 0;                                                              //06-12-09|0x00de
            SystemMsg;                                                                    //06-12-09|0x00de
            break;                                                                        //06-12-09|0x00de
        }                                                                                 //06-12-09|0x00de
        break;                                                                            //06-12-09|0x00de
//***************************************************************************             //06-12-09|0x00df
//******                                                               ******             //06-12-09|0x00e0
//******  READ PROJECT COMMANDS                                        ******             //06-12-09|0x00e1
//******---------------------------------------------------------------******             //06-12-09|0x00e2
//******  DEFINED RANDOM GENERATOR TEST BITS                           ******             //06-12-09|0x00e3
//******---------------------------------------------------------------******             //06-12-09|0x00e4
//******  Load Configuration bits                                      ******             //06-12-09|0x00e5
//******                                                               ******             //06-12-09|0x00e6
//***************************************************************************             //06-12-09|0x00e7
      case 19000: // FIRST_CONFIG_READ                                                    //06-12-09|0x00e8
        switch(ReadProject)                                                               //06-12-09|0x00e8
        {                                                                                 //06-12-09|0x00e8
          case Display:                                                                   //06-12-09|0x00e8
            BaseState = 60983; // FIRST_CONFIG_READ_EXIT                                  //06-12-09|0x00e8
            BaseStatus = Display;                                                         //06-12-09|0x00e8
            BaseRunFlag = 0;                                                              //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          case LineDone:                                                                  //06-12-09|0x00e8
            BaseRunFlag = 1;                                                              //06-12-09|0x00e8
            BaseState = 53798; // FIRST_CONFIGURE                                         //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          case FileDone:                                                                  //06-12-09|0x00e8
            BaseRunFlag = 1;                                                              //06-12-09|0x00e8
            BaseState = 62725; // END_FILE                                                //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          case UserError:                                                                 //06-12-09|0x00e8
            BaseRunFlag = 1;                                                              //06-12-09|0x00e8
            BaseState = 55081; // USER                                                    //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          default:                                                                        //06-12-09|0x00e8
            BaseStatus = SystemError;                                                     //06-12-09|0x00e8
            BaseRunFlag = 0;                                                              //06-12-09|0x00e8
            SystemMsg;                                                                    //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
        }                                                                                 //06-12-09|0x00e8
        break;                                                                            //06-12-09|0x00e8
//**************************************************************************              //06-12-09|0x00e8
      case 60983: // FIRST_CONFIG_READ_EXIT                                               //06-12-09|0x00e8
        switch(ReadProject)                                                               //06-12-09|0x00e8
        {                                                                                 //06-12-09|0x00e8
          case Display:                                                                   //06-12-09|0x00e8
            BaseState = 60983; // FIRST_CONFIG_READ_EXIT                                  //06-12-09|0x00e8
            BaseStatus = Display;                                                         //06-12-09|0x00e8
            BaseRunFlag = 0;                                                              //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          case LineDone:                                                                  //06-12-09|0x00e8
            BaseRunFlag = 1;                                                              //06-12-09|0x00e8
            BaseState = 53798; // FIRST_CONFIGURE                                         //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          case FileDone:                                                                  //06-12-09|0x00e8
            BaseRunFlag = 1;                                                              //06-12-09|0x00e8
            BaseState = 62725; // END_FILE                                                //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          case UserError:                                                                 //06-12-09|0x00e8
            BaseRunFlag = 1;                                                              //06-12-09|0x00e8
            BaseState = 55081; // USER                                                    //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
          default:                                                                        //06-12-09|0x00e8
            BaseStatus = SystemError;                                                     //06-12-09|0x00e8
            BaseRunFlag = 0;                                                              //06-12-09|0x00e8
            SystemMsg;                                                                    //06-12-09|0x00e8
            break;                                                                        //06-12-09|0x00e8
        }                                                                                 //06-12-09|0x00e8
        break;                                                                            //06-12-09|0x00e8
//***************************************************************************             //06-12-09|0x00e9
      case 53798: // FIRST_CONFIGURE                                                      //06-12-09|0x00ea
        switch(CmdTest("_CONFIGURE"))                                                     //06-12-09|0x00ea
        {                                                                                 //06-12-09|0x00ea
          case -1:                                                                        //06-12-09|0x00ea
            BaseRunFlag = 1;                                                              //06-12-09|0x00ea
            BaseState = 17876; // FIRST_MAKE_ERROR                                        //06-12-09|0x00ea
            break;                                                                        //06-12-09|0x00ea
          case 0:                                                                         //06-12-09|0x00ea
            BaseRunFlag = 1;                                                              //06-12-09|0x00ea
            BaseState = 41875; // CONFIG_BIT                                              //06-12-09|0x00ea
            break;                                                                        //06-12-09|0x00ea
          case 1:                                                                         //06-12-09|0x00ea
            BaseRunFlag = 1;                                                              //06-12-09|0x00ea
            BaseState = 17876; // FIRST_MAKE_ERROR                                        //06-12-09|0x00ea
            break;                                                                        //06-12-09|0x00ea
          default:                                                                        //06-12-09|0x00ea
            BaseStatus = SystemError;                                                     //06-12-09|0x00ea
            BaseRunFlag = 0;                                                              //06-12-09|0x00ea
            SystemMsg;                                                                    //06-12-09|0x00ea
            break;                                                                        //06-12-09|0x00ea
        }                                                                                 //06-12-09|0x00ea
        break;                                                                            //06-12-09|0x00ea
//***************************************************************************             //06-12-09|0x00eb
      case 41875: // CONFIG_BIT                                                           //06-12-09|0x00ec
        switch(basic_configure(1))                                                        //06-12-09|0x00ec
        {                                                                                 //06-12-09|0x00ec
          case Success:                                                                   //06-12-09|0x00ec
            BaseRunFlag = 1;                                                              //06-12-09|0x00ec
            BaseState = 56642; // CONFIG_READ                                             //06-12-09|0x00ec
            break;                                                                        //06-12-09|0x00ec
          case UserError:                                                                 //06-12-09|0x00ec
            BaseRunFlag = 1;                                                              //06-12-09|0x00ec
            BaseState = 55081; // USER                                                    //06-12-09|0x00ec
            break;                                                                        //06-12-09|0x00ec
          default:                                                                        //06-12-09|0x00ec
            BaseStatus = SystemError;                                                     //06-12-09|0x00ec
            BaseRunFlag = 0;                                                              //06-12-09|0x00ec
            SystemMsg;                                                                    //06-12-09|0x00ec
            break;                                                                        //06-12-09|0x00ec
        }                                                                                 //06-12-09|0x00ec
        break;                                                                            //06-12-09|0x00ec
//***************************************************************************             //06-12-09|0x00ed
      case 56642: // CONFIG_READ                                                          //06-12-09|0x00ee
        switch(ReadProject)                                                               //06-12-09|0x00ee
        {                                                                                 //06-12-09|0x00ee
          case Display:                                                                   //06-12-09|0x00ee
            BaseState = 45537; // CONFIG_READ_EXIT                                        //06-12-09|0x00ee
            BaseStatus = Display;                                                         //06-12-09|0x00ee
            BaseRunFlag = 0;                                                              //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          case LineDone:                                                                  //06-12-09|0x00ee
            BaseRunFlag = 1;                                                              //06-12-09|0x00ee
            BaseState = 53360; // CONFIGURE                                               //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          case FileDone:                                                                  //06-12-09|0x00ee
            BaseRunFlag = 1;                                                              //06-12-09|0x00ee
            BaseState = 62725; // END_FILE                                                //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          case UserError:                                                                 //06-12-09|0x00ee
            BaseRunFlag = 1;                                                              //06-12-09|0x00ee
            BaseState = 55279; // USR_CLS                                                 //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          default:                                                                        //06-12-09|0x00ee
            BaseStatus = SystemError;                                                     //06-12-09|0x00ee
            BaseRunFlag = 0;                                                              //06-12-09|0x00ee
            SystemMsg;                                                                    //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
        }                                                                                 //06-12-09|0x00ee
        break;                                                                            //06-12-09|0x00ee
//**************************************************************************              //06-12-09|0x00ee
      case 45537: // CONFIG_READ_EXIT                                                     //06-12-09|0x00ee
        switch(ReadProject)                                                               //06-12-09|0x00ee
        {                                                                                 //06-12-09|0x00ee
          case Display:                                                                   //06-12-09|0x00ee
            BaseState = 45537; // CONFIG_READ_EXIT                                        //06-12-09|0x00ee
            BaseStatus = Display;                                                         //06-12-09|0x00ee
            BaseRunFlag = 0;                                                              //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          case LineDone:                                                                  //06-12-09|0x00ee
            BaseRunFlag = 1;                                                              //06-12-09|0x00ee
            BaseState = 53360; // CONFIGURE                                               //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          case FileDone:                                                                  //06-12-09|0x00ee
            BaseRunFlag = 1;                                                              //06-12-09|0x00ee
            BaseState = 62725; // END_FILE                                                //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          case UserError:                                                                 //06-12-09|0x00ee
            BaseRunFlag = 1;                                                              //06-12-09|0x00ee
            BaseState = 55279; // USR_CLS                                                 //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
          default:                                                                        //06-12-09|0x00ee
            BaseStatus = SystemError;                                                     //06-12-09|0x00ee
            BaseRunFlag = 0;                                                              //06-12-09|0x00ee
            SystemMsg;                                                                    //06-12-09|0x00ee
            break;                                                                        //06-12-09|0x00ee
        }                                                                                 //06-12-09|0x00ee
        break;                                                                            //06-12-09|0x00ee
//***************************************************************************             //06-12-09|0x00ef
      case 53360: // CONFIGURE                                                            //06-12-09|0x00f0
        switch(CmdTest("_CONFIGURE"))                                                     //06-12-09|0x00f0
        {                                                                                 //06-12-09|0x00f0
          case -1:                                                                        //06-12-09|0x00f0
            BaseRunFlag = 1;                                                              //06-12-09|0x00f0
            BaseState = 22366; // MAKE_ERROR                                              //06-12-09|0x00f0
            break;                                                                        //06-12-09|0x00f0
          case 0:                                                                         //06-12-09|0x00f0
            BaseRunFlag = 1;                                                              //06-12-09|0x00f0
            BaseState = 41875; // CONFIG_BIT                                              //06-12-09|0x00f0
            break;                                                                        //06-12-09|0x00f0
          case 1:                                                                         //06-12-09|0x00f0
            BaseRunFlag = 1;                                                              //06-12-09|0x00f0
            BaseState = 22366; // MAKE_ERROR                                              //06-12-09|0x00f0
            break;                                                                        //06-12-09|0x00f0
          default:                                                                        //06-12-09|0x00f0
            BaseStatus = SystemError;                                                     //06-12-09|0x00f0
            BaseRunFlag = 0;                                                              //06-12-09|0x00f0
            SystemMsg;                                                                    //06-12-09|0x00f0
            break;                                                                        //06-12-09|0x00f0
        }                                                                                 //06-12-09|0x00f0
        break;                                                                            //06-12-09|0x00f0
//***************************************************************************             //06-12-09|0x00f1
//******                                                               ******             //06-12-09|0x00f2
//******  READ PROJECT COMMANDS                                        ******             //06-12-09|0x00f3
//******---------------------------------------------------------------******             //06-12-09|0x00f4
//******  DEFINED RANDOM GENERATOR TEST BITS                           ******             //06-12-09|0x00f5
//******---------------------------------------------------------------******             //06-12-09|0x00f6
//******  Load Make Error bits                                         ******             //06-12-09|0x00f7
//******                                                               ******             //06-12-09|0x00f8
//***************************************************************************             //06-12-09|0x00f9
      case 17876: // FIRST_MAKE_ERROR                                                     //06-12-10|0x00fa
        switch(CmdTest("_MAKE_ERROR"))                                                    //06-12-10|0x00fa
        {                                                                                 //06-12-10|0x00fa
          case -1:                                                                        //06-12-10|0x00fa
            BaseRunFlag = 1;                                                              //06-12-10|0x00fa
            BaseState = 52669; // FIRST_RUN_ERROR                                         //06-12-10|0x00fa
            break;                                                                        //06-12-10|0x00fa
          case 0:                                                                         //06-12-10|0x00fa
            BaseRunFlag = 1;                                                              //06-12-10|0x00fa
            BaseState = 43532; // MAKE_ERROR_BIT                                          //06-12-10|0x00fa
            break;                                                                        //06-12-10|0x00fa
          case 1:                                                                         //06-12-10|0x00fa
            BaseRunFlag = 1;                                                              //06-12-10|0x00fa
            BaseState = 52669; // FIRST_RUN_ERROR                                         //06-12-10|0x00fa
            break;                                                                        //06-12-10|0x00fa
          default:                                                                        //06-12-10|0x00fa
            BaseStatus = SystemError;                                                     //06-12-10|0x00fa
            BaseRunFlag = 0;                                                              //06-12-10|0x00fa
            SystemMsg;                                                                    //06-12-10|0x00fa
            break;                                                                        //06-12-10|0x00fa
        }                                                                                 //06-12-10|0x00fa
        break;                                                                            //06-12-10|0x00fa
//***************************************************************************             //06-12-10|0x00fb
      case 43532: // MAKE_ERROR_BIT                                                       //06-12-10|0x00fc
        switch(basic_configure(-1))                                                       //06-12-10|0x00fc
        {                                                                                 //06-12-10|0x00fc
          case Success:                                                                   //06-12-10|0x00fc
            BaseRunFlag = 1;                                                              //06-12-10|0x00fc
            BaseState = 19275; // MAKE_ERROR_READ                                         //06-12-10|0x00fc
            break;                                                                        //06-12-10|0x00fc
          case UserError:                                                                 //06-12-10|0x00fc
            BaseRunFlag = 1;                                                              //06-12-10|0x00fc
            BaseState = 55279; // USR_CLS                                                 //06-12-10|0x00fc
            break;                                                                        //06-12-10|0x00fc
          default:                                                                        //06-12-10|0x00fc
            BaseStatus = SystemError;                                                     //06-12-10|0x00fc
            BaseRunFlag = 0;                                                              //06-12-10|0x00fc
            SystemMsg;                                                                    //06-12-10|0x00fc
            break;                                                                        //06-12-10|0x00fc
        }                                                                                 //06-12-10|0x00fc
        break;                                                                            //06-12-10|0x00fc
//***************************************************************************             //06-12-10|0x00fd
      case 19275: // MAKE_ERROR_READ                                                      //06-12-10|0x00fe
        switch(ReadProject)                                                               //06-12-10|0x00fe
        {                                                                                 //06-12-10|0x00fe
          case Display:                                                                   //06-12-10|0x00fe
            BaseState = 122; // MAKE_ERROR_READ_EXIT                                      //06-12-10|0x00fe
            BaseStatus = Display;                                                         //06-12-10|0x00fe
            BaseRunFlag = 0;                                                              //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          case LineDone:                                                                  //06-12-10|0x00fe
            BaseRunFlag = 1;                                                              //06-12-10|0x00fe
            BaseState = 22366; // MAKE_ERROR                                              //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          case FileDone:                                                                  //06-12-10|0x00fe
            BaseRunFlag = 1;                                                              //06-12-10|0x00fe
            BaseState = 62725; // END_FILE                                                //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          case UserError:                                                                 //06-12-10|0x00fe
            BaseRunFlag = 1;                                                              //06-12-10|0x00fe
            BaseState = 55279; // USR_CLS                                                 //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          default:                                                                        //06-12-10|0x00fe
            BaseStatus = SystemError;                                                     //06-12-10|0x00fe
            BaseRunFlag = 0;                                                              //06-12-10|0x00fe
            SystemMsg;                                                                    //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
        }                                                                                 //06-12-10|0x00fe
        break;                                                                            //06-12-10|0x00fe
//**************************************************************************              //06-12-10|0x00fe
      case 122: // MAKE_ERROR_READ_EXIT                                                   //06-12-10|0x00fe
        switch(ReadProject)                                                               //06-12-10|0x00fe
        {                                                                                 //06-12-10|0x00fe
          case Display:                                                                   //06-12-10|0x00fe
            BaseState = 122; // MAKE_ERROR_READ_EXIT                                      //06-12-10|0x00fe
            BaseStatus = Display;                                                         //06-12-10|0x00fe
            BaseRunFlag = 0;                                                              //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          case LineDone:                                                                  //06-12-10|0x00fe
            BaseRunFlag = 1;                                                              //06-12-10|0x00fe
            BaseState = 22366; // MAKE_ERROR                                              //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          case FileDone:                                                                  //06-12-10|0x00fe
            BaseRunFlag = 1;                                                              //06-12-10|0x00fe
            BaseState = 62725; // END_FILE                                                //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          case UserError:                                                                 //06-12-10|0x00fe
            BaseRunFlag = 1;                                                              //06-12-10|0x00fe
            BaseState = 55279; // USR_CLS                                                 //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
          default:                                                                        //06-12-10|0x00fe
            BaseStatus = SystemError;                                                     //06-12-10|0x00fe
            BaseRunFlag = 0;                                                              //06-12-10|0x00fe
            SystemMsg;                                                                    //06-12-10|0x00fe
            break;                                                                        //06-12-10|0x00fe
        }                                                                                 //06-12-10|0x00fe
        break;                                                                            //06-12-10|0x00fe
//***************************************************************************             //06-12-10|0x00ff
      case 22366: // MAKE_ERROR                                                           //06-12-10|0x0100
        switch(CmdTest("_MAKE_ERROR"))                                                    //06-12-10|0x0100
        {                                                                                 //06-12-10|0x0100
          case -1:                                                                        //06-12-10|0x0100
            BaseRunFlag = 1;                                                              //06-12-10|0x0100
            BaseState = 2201; // DRIVE_PATH_CMD                                           //06-12-10|0x0100
            break;                                                                        //06-12-10|0x0100
          case 0:                                                                         //06-12-10|0x0100
            BaseRunFlag = 1;                                                              //06-12-10|0x0100
            BaseState = 43532; // MAKE_ERROR_BIT                                          //06-12-10|0x0100
            break;                                                                        //06-12-10|0x0100
          case 1:                                                                         //06-12-10|0x0100
            BaseRunFlag = 1;                                                              //06-12-10|0x0100
            BaseState = 2201; // DRIVE_PATH_CMD                                           //06-12-10|0x0100
            break;                                                                        //06-12-10|0x0100
          default:                                                                        //06-12-10|0x0100
            BaseStatus = SystemError;                                                     //06-12-10|0x0100
            BaseRunFlag = 0;                                                              //06-12-10|0x0100
            SystemMsg;                                                                    //06-12-10|0x0100
            break;                                                                        //06-12-10|0x0100
        }                                                                                 //06-12-10|0x0100
        break;                                                                            //06-12-10|0x0100
//***************************************************************************             //06-12-10|0x0101
//******                                                               ******             //06-12-10|0x0102
//******  READ PROJECT COMMANDS                                        ******             //06-12-10|0x0103
//******---------------------------------------------------------------******             //06-12-10|0x0104
//******  DEFINED RANDOM GENERATOR TEST BITS                           ******             //06-12-10|0x0105
//******---------------------------------------------------------------******             //06-12-10|0x0106
//******  Load Run Error bits                                          ******             //06-12-10|0x0107
//******                                                               ******             //06-12-10|0x0108
//***************************************************************************             //06-12-10|0x0109
      case 52669: // FIRST_RUN_ERROR                                                      //06-12-10|0x010a
        switch(CmdTest("_RUN_ERROR"))                                                     //06-12-10|0x010a
        {                                                                                 //06-12-10|0x010a
          case -1:                                                                        //06-12-10|0x010a
            BaseRunFlag = 1;                                                              //06-12-10|0x010a
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-10|0x010a
            break;                                                                        //06-12-10|0x010a
          case 0:                                                                         //06-12-10|0x010a
            BaseRunFlag = 1;                                                              //06-12-10|0x010a
            BaseState = 48551; // RUN_ERROR_BIT                                           //06-12-10|0x010a
            break;                                                                        //06-12-10|0x010a
          case 1:                                                                         //06-12-10|0x010a
            BaseRunFlag = 1;                                                              //06-12-10|0x010a
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-10|0x010a
            break;                                                                        //06-12-10|0x010a
          default:                                                                        //06-12-10|0x010a
            BaseStatus = SystemError;                                                     //06-12-10|0x010a
            BaseRunFlag = 0;                                                              //06-12-10|0x010a
            SystemMsg;                                                                    //06-12-10|0x010a
            break;                                                                        //06-12-10|0x010a
        }                                                                                 //06-12-10|0x010a
        break;                                                                            //06-12-10|0x010a
//***************************************************************************             //06-12-10|0x010b
      case 48551: // RUN_ERROR_BIT                                                        //06-12-10|0x010c
        switch(basic_configure(-2))                                                       //06-12-10|0x010c
        {                                                                                 //06-12-10|0x010c
          case Success:                                                                   //06-12-10|0x010c
            BaseRunFlag = 1;                                                              //06-12-10|0x010c
            BaseState = 39062; // RUN_ERROR_READ                                          //06-12-10|0x010c
            break;                                                                        //06-12-10|0x010c
          case UserError:                                                                 //06-12-10|0x010c
            BaseRunFlag = 1;                                                              //06-12-10|0x010c
            BaseState = 55279; // USR_CLS                                                 //06-12-10|0x010c
            break;                                                                        //06-12-10|0x010c
          default:                                                                        //06-12-10|0x010c
            BaseStatus = SystemError;                                                     //06-12-10|0x010c
            BaseRunFlag = 0;                                                              //06-12-10|0x010c
            SystemMsg;                                                                    //06-12-10|0x010c
            break;                                                                        //06-12-10|0x010c
        }                                                                                 //06-12-10|0x010c
        break;                                                                            //06-12-10|0x010c
//***************************************************************************             //06-12-10|0x010d
      case 39062: // RUN_ERROR_READ                                                       //06-12-10|0x010e
        switch(ReadProject)                                                               //06-12-10|0x010e
        {                                                                                 //06-12-10|0x010e
          case Display:                                                                   //06-12-10|0x010e
            BaseState = 8821; // RUN_ERROR_READ_EXIT                                      //06-12-10|0x010e
            BaseStatus = Display;                                                         //06-12-10|0x010e
            BaseRunFlag = 0;                                                              //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          case LineDone:                                                                  //06-12-10|0x010e
            BaseRunFlag = 1;                                                              //06-12-10|0x010e
            BaseState = 19012; // RUN_ERROR                                               //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          case FileDone:                                                                  //06-12-10|0x010e
            BaseRunFlag = 1;                                                              //06-12-10|0x010e
            BaseState = 62725; // END_FILE                                                //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          case UserError:                                                                 //06-12-10|0x010e
            BaseRunFlag = 1;                                                              //06-12-10|0x010e
            BaseState = 55279; // USR_CLS                                                 //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          default:                                                                        //06-12-10|0x010e
            BaseStatus = SystemError;                                                     //06-12-10|0x010e
            BaseRunFlag = 0;                                                              //06-12-10|0x010e
            SystemMsg;                                                                    //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
        }                                                                                 //06-12-10|0x010e
        break;                                                                            //06-12-10|0x010e
//**************************************************************************              //06-12-10|0x010e
      case 8821: // RUN_ERROR_READ_EXIT                                                   //06-12-10|0x010e
        switch(ReadProject)                                                               //06-12-10|0x010e
        {                                                                                 //06-12-10|0x010e
          case Display:                                                                   //06-12-10|0x010e
            BaseState = 8821; // RUN_ERROR_READ_EXIT                                      //06-12-10|0x010e
            BaseStatus = Display;                                                         //06-12-10|0x010e
            BaseRunFlag = 0;                                                              //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          case LineDone:                                                                  //06-12-10|0x010e
            BaseRunFlag = 1;                                                              //06-12-10|0x010e
            BaseState = 19012; // RUN_ERROR                                               //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          case FileDone:                                                                  //06-12-10|0x010e
            BaseRunFlag = 1;                                                              //06-12-10|0x010e
            BaseState = 62725; // END_FILE                                                //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          case UserError:                                                                 //06-12-10|0x010e
            BaseRunFlag = 1;                                                              //06-12-10|0x010e
            BaseState = 55279; // USR_CLS                                                 //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
          default:                                                                        //06-12-10|0x010e
            BaseStatus = SystemError;                                                     //06-12-10|0x010e
            BaseRunFlag = 0;                                                              //06-12-10|0x010e
            SystemMsg;                                                                    //06-12-10|0x010e
            break;                                                                        //06-12-10|0x010e
        }                                                                                 //06-12-10|0x010e
        break;                                                                            //06-12-10|0x010e
//***************************************************************************             //06-12-10|0x010f
      case 19012: // RUN_ERROR                                                            //06-12-10|0x0110
        switch(CmdTest("_RUN_ERROR"))                                                     //06-12-10|0x0110
        {                                                                                 //06-12-10|0x0110
          case -1:                                                                        //06-12-10|0x0110
            BaseRunFlag = 1;                                                              //06-12-10|0x0110
            BaseState = 2201; // DRIVE_PATH_CMD                                           //06-12-10|0x0110
            break;                                                                        //06-12-10|0x0110
          case 0:                                                                         //06-12-10|0x0110
            BaseRunFlag = 1;                                                              //06-12-10|0x0110
            BaseState = 48551; // RUN_ERROR_BIT                                           //06-12-10|0x0110
            break;                                                                        //06-12-10|0x0110
          case 1:                                                                         //06-12-10|0x0110
            BaseRunFlag = 1;                                                              //06-12-10|0x0110
            BaseState = 2201; // DRIVE_PATH_CMD                                           //06-12-10|0x0110
            break;                                                                        //06-12-10|0x0110
          default:                                                                        //06-12-10|0x0110
            BaseStatus = SystemError;                                                     //06-12-10|0x0110
            BaseRunFlag = 0;                                                              //06-12-10|0x0110
            SystemMsg;                                                                    //06-12-10|0x0110
            break;                                                                        //06-12-10|0x0110
        }                                                                                 //06-12-10|0x0110
        break;                                                                            //06-12-10|0x0110
//***************************************************************************             //06-12-11|0x0111
//******                                                               ******             //06-12-11|0x0112
//******  READ PROJECT COMMANDS                                        ******             //06-12-11|0x0113
//******---------------------------------------------------------------******             //06-12-11|0x0114
//******  Get Drive-Path Data                                          ******             //06-12-11|0x0115
//******                                                               ******             //06-12-11|0x0116
//***************************************************************************             //06-12-11|0x0117
      case 2201: // DRIVE_PATH_CMD                                                        //06-12-11|0x0118
        switch(CmdTest("_DRIVE_PATH"))                                                    //06-12-11|0x0118
        {                                                                                 //06-12-11|0x0118
          case -1:                                                                        //06-12-11|0x0118
            BaseRunFlag = 1;                                                              //06-12-11|0x0118
            BaseState = 61187; // TEST_GEN_NAME_CMD                                       //06-12-11|0x0118
            break;                                                                        //06-12-11|0x0118
          case 0:                                                                         //06-12-11|0x0118
            BaseRunFlag = 1;                                                              //06-12-11|0x0118
            BaseState = 57266; // DRIVE_PATH                                              //06-12-11|0x0118
            break;                                                                        //06-12-11|0x0118
          case 1:                                                                         //06-12-11|0x0118
            BaseRunFlag = 1;                                                              //06-12-11|0x0118
            BaseState = 61187; // TEST_GEN_NAME_CMD                                       //06-12-11|0x0118
            break;                                                                        //06-12-11|0x0118
          default:                                                                        //06-12-11|0x0118
            BaseStatus = SystemError;                                                     //06-12-11|0x0118
            BaseRunFlag = 0;                                                              //06-12-11|0x0118
            SystemMsg;                                                                    //06-12-11|0x0118
            break;                                                                        //06-12-11|0x0118
        }                                                                                 //06-12-11|0x0118
        break;                                                                            //06-12-11|0x0118
//***************************************************************************             //06-12-11|0x0119
      case 57266: // DRIVE_PATH                                                           //06-12-11|0x011a
        switch(drive_path())                                                              //06-12-11|0x011a
        {                                                                                 //06-12-11|0x011a
          case Success:                                                                   //06-12-11|0x011a
            BaseRunFlag = 1;                                                              //06-12-11|0x011a
            BaseState = 56145; // READ_GEN_NAME                                           //06-12-11|0x011a
            break;                                                                        //06-12-11|0x011a
          case UserError:                                                                 //06-12-11|0x011a
            BaseRunFlag = 1;                                                              //06-12-11|0x011a
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x011a
            break;                                                                        //06-12-11|0x011a
          default:                                                                        //06-12-11|0x011a
            BaseStatus = SystemError;                                                     //06-12-11|0x011a
            BaseRunFlag = 0;                                                              //06-12-11|0x011a
            SystemMsg;                                                                    //06-12-11|0x011a
            break;                                                                        //06-12-11|0x011a
        }                                                                                 //06-12-11|0x011a
        break;                                                                            //06-12-11|0x011a
//***************************************************************************             //06-12-11|0x011b
//******                                                               ******             //06-12-11|0x011c
//******  READ PROJECT COMMANDS                                        ******             //06-12-11|0x011d
//******---------------------------------------------------------------******             //06-12-11|0x011e
//******  Get Prepare Project Name                                     ******             //06-12-11|0x011f
//******                                                               ******             //06-12-11|0x0120
//***************************************************************************             //06-12-11|0x0121
      case 56145: // READ_GEN_NAME                                                        //06-12-11|0x0122
        switch(ReadProject)                                                               //06-12-11|0x0122
        {                                                                                 //06-12-11|0x0122
          case Display:                                                                   //06-12-11|0x0122
            BaseState = 37088; // READ_GEN_NAME_EXIT                                      //06-12-11|0x0122
            BaseStatus = Display;                                                         //06-12-11|0x0122
            BaseRunFlag = 0;                                                              //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          case LineDone:                                                                  //06-12-11|0x0122
            BaseRunFlag = 1;                                                              //06-12-11|0x0122
            BaseState = 61187; // TEST_GEN_NAME_CMD                                       //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          case FileDone:                                                                  //06-12-11|0x0122
            BaseRunFlag = 1;                                                              //06-12-11|0x0122
            BaseState = 62725; // END_FILE                                                //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          case UserError:                                                                 //06-12-11|0x0122
            BaseRunFlag = 1;                                                              //06-12-11|0x0122
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          default:                                                                        //06-12-11|0x0122
            BaseStatus = SystemError;                                                     //06-12-11|0x0122
            BaseRunFlag = 0;                                                              //06-12-11|0x0122
            SystemMsg;                                                                    //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
        }                                                                                 //06-12-11|0x0122
        break;                                                                            //06-12-11|0x0122
//**************************************************************************              //06-12-11|0x0122
      case 37088: // READ_GEN_NAME_EXIT                                                   //06-12-11|0x0122
        switch(ReadProject)                                                               //06-12-11|0x0122
        {                                                                                 //06-12-11|0x0122
          case Display:                                                                   //06-12-11|0x0122
            BaseState = 37088; // READ_GEN_NAME_EXIT                                      //06-12-11|0x0122
            BaseStatus = Display;                                                         //06-12-11|0x0122
            BaseRunFlag = 0;                                                              //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          case LineDone:                                                                  //06-12-11|0x0122
            BaseRunFlag = 1;                                                              //06-12-11|0x0122
            BaseState = 61187; // TEST_GEN_NAME_CMD                                       //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          case FileDone:                                                                  //06-12-11|0x0122
            BaseRunFlag = 1;                                                              //06-12-11|0x0122
            BaseState = 62725; // END_FILE                                                //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          case UserError:                                                                 //06-12-11|0x0122
            BaseRunFlag = 1;                                                              //06-12-11|0x0122
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
          default:                                                                        //06-12-11|0x0122
            BaseStatus = SystemError;                                                     //06-12-11|0x0122
            BaseRunFlag = 0;                                                              //06-12-11|0x0122
            SystemMsg;                                                                    //06-12-11|0x0122
            break;                                                                        //06-12-11|0x0122
        }                                                                                 //06-12-11|0x0122
        break;                                                                            //06-12-11|0x0122
//***************************************************************************             //06-12-11|0x0123
      case 61187: // TEST_GEN_NAME_CMD                                                    //06-12-11|0x0124
        switch(CmdTest("_PREPARE_NAME"))                                                  //06-12-11|0x0124
        {                                                                                 //06-12-11|0x0124
          case -1:                                                                        //06-12-11|0x0124
            BaseRunFlag = 1;                                                              //06-12-11|0x0124
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-11|0x0124
            break;                                                                        //06-12-11|0x0124
          case 0:                                                                         //06-12-11|0x0124
            BaseRunFlag = 1;                                                              //06-12-11|0x0124
            BaseState = 40799; // TEST_GEN_NAME                                           //06-12-11|0x0124
            break;                                                                        //06-12-11|0x0124
          case 1:                                                                         //06-12-11|0x0124
            BaseRunFlag = 1;                                                              //06-12-11|0x0124
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-11|0x0124
            break;                                                                        //06-12-11|0x0124
          default:                                                                        //06-12-11|0x0124
            BaseStatus = SystemError;                                                     //06-12-11|0x0124
            BaseRunFlag = 0;                                                              //06-12-11|0x0124
            SystemMsg;                                                                    //06-12-11|0x0124
            break;                                                                        //06-12-11|0x0124
        }                                                                                 //06-12-11|0x0124
        break;                                                                            //06-12-11|0x0124
//***************************************************************************             //06-12-11|0x0125
      case 40799: // TEST_GEN_NAME                                                        //06-12-11|0x0126
        switch(TestGenPcgName)                                                            //06-12-11|0x0126
        {                                                                                 //06-12-11|0x0126
          case Success:                                                                   //06-12-11|0x0126
            BaseRunFlag = 1;                                                              //06-12-11|0x0126
            BaseState = 38350; // READ_BUILD_NAME                                         //06-12-11|0x0126
            break;                                                                        //06-12-11|0x0126
          case UserError:                                                                 //06-12-11|0x0126
            BaseRunFlag = 1;                                                              //06-12-11|0x0126
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x0126
            break;                                                                        //06-12-11|0x0126
          default:                                                                        //06-12-11|0x0126
            BaseStatus = SystemError;                                                     //06-12-11|0x0126
            BaseRunFlag = 0;                                                              //06-12-11|0x0126
            SystemMsg;                                                                    //06-12-11|0x0126
            break;                                                                        //06-12-11|0x0126
        }                                                                                 //06-12-11|0x0126
        break;                                                                            //06-12-11|0x0126
//***************************************************************************             //06-12-11|0x0127
//******                                                               ******             //06-12-11|0x0128
//******  READ PROJECT COMMANDS                                        ******             //06-12-11|0x0129
//******---------------------------------------------------------------******             //06-12-11|0x012a
//******  Get Build Project Name                                       ******             //06-12-11|0x012b
//******                                                               ******             //06-12-11|0x012c
//***************************************************************************             //06-12-11|0x012d
      case 38350: // READ_BUILD_NAME                                                      //06-12-11|0x012e
        switch(ReadProject)                                                               //06-12-11|0x012e
        {                                                                                 //06-12-11|0x012e
          case Display:                                                                   //06-12-11|0x012e
            BaseState = 62253; // READ_BUILD_NAME_EXIT                                    //06-12-11|0x012e
            BaseStatus = Display;                                                         //06-12-11|0x012e
            BaseRunFlag = 0;                                                              //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          case LineDone:                                                                  //06-12-11|0x012e
            BaseRunFlag = 1;                                                              //06-12-11|0x012e
            BaseState = 9852; // TEST_BUILD_NAME_CMD                                      //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          case FileDone:                                                                  //06-12-11|0x012e
            BaseRunFlag = 1;                                                              //06-12-11|0x012e
            BaseState = 62725; // END_FILE                                                //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          case UserError:                                                                 //06-12-11|0x012e
            BaseRunFlag = 1;                                                              //06-12-11|0x012e
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          default:                                                                        //06-12-11|0x012e
            BaseStatus = SystemError;                                                     //06-12-11|0x012e
            BaseRunFlag = 0;                                                              //06-12-11|0x012e
            SystemMsg;                                                                    //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
        }                                                                                 //06-12-11|0x012e
        break;                                                                            //06-12-11|0x012e
//**************************************************************************              //06-12-11|0x012e
      case 62253: // READ_BUILD_NAME_EXIT                                                 //06-12-11|0x012e
        switch(ReadProject)                                                               //06-12-11|0x012e
        {                                                                                 //06-12-11|0x012e
          case Display:                                                                   //06-12-11|0x012e
            BaseState = 62253; // READ_BUILD_NAME_EXIT                                    //06-12-11|0x012e
            BaseStatus = Display;                                                         //06-12-11|0x012e
            BaseRunFlag = 0;                                                              //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          case LineDone:                                                                  //06-12-11|0x012e
            BaseRunFlag = 1;                                                              //06-12-11|0x012e
            BaseState = 9852; // TEST_BUILD_NAME_CMD                                      //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          case FileDone:                                                                  //06-12-11|0x012e
            BaseRunFlag = 1;                                                              //06-12-11|0x012e
            BaseState = 62725; // END_FILE                                                //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          case UserError:                                                                 //06-12-11|0x012e
            BaseRunFlag = 1;                                                              //06-12-11|0x012e
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
          default:                                                                        //06-12-11|0x012e
            BaseStatus = SystemError;                                                     //06-12-11|0x012e
            BaseRunFlag = 0;                                                              //06-12-11|0x012e
            SystemMsg;                                                                    //06-12-11|0x012e
            break;                                                                        //06-12-11|0x012e
        }                                                                                 //06-12-11|0x012e
        break;                                                                            //06-12-11|0x012e
//***************************************************************************             //06-12-11|0x012f
      case 9852: // TEST_BUILD_NAME_CMD                                                   //09-01-03|0x0130
        switch(CmdTest("_BUILD_NAME"))                                                    //09-01-03|0x0130
        {                                                                                 //09-01-03|0x0130
          case -1:                                                                        //09-01-03|0x0130
            BaseRunFlag = 1;                                                              //09-01-03|0x0130
            BaseState = 36539; // TEST_MAKE_NAME_CMD                                      //09-01-03|0x0130
            break;                                                                        //09-01-03|0x0130
          case 0:                                                                         //09-01-03|0x0130
            BaseRunFlag = 1;                                                              //09-01-03|0x0130
            BaseState = 31466; // TEST_BUILD_NAME                                         //09-01-03|0x0130
            break;                                                                        //09-01-03|0x0130
          case 1:                                                                         //09-01-03|0x0130
            BaseRunFlag = 1;                                                              //09-01-03|0x0130
            BaseState = 36539; // TEST_MAKE_NAME_CMD                                      //09-01-03|0x0130
            break;                                                                        //09-01-03|0x0130
          default:                                                                        //09-01-03|0x0130
            BaseStatus = SystemError;                                                     //09-01-03|0x0130
            BaseRunFlag = 0;                                                              //09-01-03|0x0130
            SystemMsg;                                                                    //09-01-03|0x0130
            break;                                                                        //09-01-03|0x0130
        }                                                                                 //09-01-03|0x0130
        break;                                                                            //09-01-03|0x0130
//***************************************************************************             //06-12-14|0x0131
      case 31466: // TEST_BUILD_NAME                                                      //06-12-14|0x0132
        switch(TestBuildPcgName)                                                          //06-12-14|0x0132
        {                                                                                 //06-12-14|0x0132
          case Success:                                                                   //06-12-14|0x0132
            BaseRunFlag = 1;                                                              //06-12-14|0x0132
            BaseState = 10761; // READ_MAKE_NAME                                          //06-12-14|0x0132
            break;                                                                        //06-12-14|0x0132
          case UserError:                                                                 //06-12-14|0x0132
            BaseRunFlag = 1;                                                              //06-12-14|0x0132
            BaseState = 55279; // USR_CLS                                                 //06-12-14|0x0132
            break;                                                                        //06-12-14|0x0132
          default:                                                                        //06-12-14|0x0132
            BaseStatus = SystemError;                                                     //06-12-14|0x0132
            BaseRunFlag = 0;                                                              //06-12-14|0x0132
            SystemMsg;                                                                    //06-12-14|0x0132
            break;                                                                        //06-12-14|0x0132
        }                                                                                 //06-12-14|0x0132
        break;                                                                            //06-12-14|0x0132
//***************************************************************************             //06-12-14|0x0133
//******                                                               ******             //06-12-14|0x0134
//******  READ PROJECT COMMANDS                                        ******             //06-12-14|0x0135
//******---------------------------------------------------------------******             //06-12-14|0x0136
//******  Get Make Command                                             ******             //06-12-14|0x0137
//******                                                               ******             //06-12-14|0x0138
//***************************************************************************             //06-12-14|0x0139
      case 10761: // READ_MAKE_NAME                                                       //06-12-14|0x013a
        switch(ReadProject)                                                               //06-12-14|0x013a
        {                                                                                 //06-12-14|0x013a
          case Display:                                                                   //06-12-14|0x013a
            BaseState = 51992; // READ_MAKE_NAME_EXIT                                     //06-12-14|0x013a
            BaseStatus = Display;                                                         //06-12-14|0x013a
            BaseRunFlag = 0;                                                              //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          case LineDone:                                                                  //06-12-14|0x013a
            BaseRunFlag = 1;                                                              //06-12-14|0x013a
            BaseState = 36539; // TEST_MAKE_NAME_CMD                                      //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          case FileDone:                                                                  //06-12-14|0x013a
            BaseRunFlag = 1;                                                              //06-12-14|0x013a
            BaseState = 62725; // END_FILE                                                //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          case UserError:                                                                 //06-12-14|0x013a
            BaseRunFlag = 1;                                                              //06-12-14|0x013a
            BaseState = 55279; // USR_CLS                                                 //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          default:                                                                        //06-12-14|0x013a
            BaseStatus = SystemError;                                                     //06-12-14|0x013a
            BaseRunFlag = 0;                                                              //06-12-14|0x013a
            SystemMsg;                                                                    //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
        }                                                                                 //06-12-14|0x013a
        break;                                                                            //06-12-14|0x013a
//**************************************************************************              //06-12-14|0x013a
      case 51992: // READ_MAKE_NAME_EXIT                                                  //06-12-14|0x013a
        switch(ReadProject)                                                               //06-12-14|0x013a
        {                                                                                 //06-12-14|0x013a
          case Display:                                                                   //06-12-14|0x013a
            BaseState = 51992; // READ_MAKE_NAME_EXIT                                     //06-12-14|0x013a
            BaseStatus = Display;                                                         //06-12-14|0x013a
            BaseRunFlag = 0;                                                              //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          case LineDone:                                                                  //06-12-14|0x013a
            BaseRunFlag = 1;                                                              //06-12-14|0x013a
            BaseState = 36539; // TEST_MAKE_NAME_CMD                                      //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          case FileDone:                                                                  //06-12-14|0x013a
            BaseRunFlag = 1;                                                              //06-12-14|0x013a
            BaseState = 62725; // END_FILE                                                //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          case UserError:                                                                 //06-12-14|0x013a
            BaseRunFlag = 1;                                                              //06-12-14|0x013a
            BaseState = 55279; // USR_CLS                                                 //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
          default:                                                                        //06-12-14|0x013a
            BaseStatus = SystemError;                                                     //06-12-14|0x013a
            BaseRunFlag = 0;                                                              //06-12-14|0x013a
            SystemMsg;                                                                    //06-12-14|0x013a
            break;                                                                        //06-12-14|0x013a
        }                                                                                 //06-12-14|0x013a
        break;                                                                            //06-12-14|0x013a
//---------------------------------------------------------------------------             //06-12-14|0x013b
      case 36539: // TEST_MAKE_NAME_CMD                                                   //09-01-03|0x013c
        switch(CmdTest("_MAKE_NAME"))                                                     //09-01-03|0x013c
        {                                                                                 //09-01-03|0x013c
          case -1:                                                                        //09-01-03|0x013c
            BaseRunFlag = 1;                                                              //09-01-03|0x013c
            BaseState = 32023; // TEST_RUN_NAME_CMD                                       //09-01-03|0x013c
            break;                                                                        //09-01-03|0x013c
          case 0:                                                                         //09-01-03|0x013c
            BaseRunFlag = 1;                                                              //09-01-03|0x013c
            BaseState = 20230; // MAKE_NAME                                               //09-01-03|0x013c
            break;                                                                        //09-01-03|0x013c
          case 1:                                                                         //09-01-03|0x013c
            BaseRunFlag = 1;                                                              //09-01-03|0x013c
            BaseState = 32023; // TEST_RUN_NAME_CMD                                       //09-01-03|0x013c
            break;                                                                        //09-01-03|0x013c
          default:                                                                        //09-01-03|0x013c
            BaseStatus = SystemError;                                                     //09-01-03|0x013c
            BaseRunFlag = 0;                                                              //09-01-03|0x013c
            SystemMsg;                                                                    //09-01-03|0x013c
            break;                                                                        //09-01-03|0x013c
        }                                                                                 //09-01-03|0x013c
        break;                                                                            //09-01-03|0x013c
//---------------------------------------------------------------------------             //06-12-16|0x013d
      case 20230: // MAKE_NAME                                                            //06-12-16|0x013e
        switch(SpawnMakeName)                                                             //06-12-16|0x013e
        {                                                                                 //06-12-16|0x013e
          case Success:                                                                   //06-12-16|0x013e
            BaseRunFlag = 1;                                                              //06-12-16|0x013e
            BaseState = 16357; // MAKE_ARGS                                               //06-12-16|0x013e
            break;                                                                        //06-12-16|0x013e
          case UserError:                                                                 //06-12-16|0x013e
            BaseRunFlag = 1;                                                              //06-12-16|0x013e
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x013e
            break;                                                                        //06-12-16|0x013e
          default:                                                                        //06-12-16|0x013e
            BaseStatus = SystemError;                                                     //06-12-16|0x013e
            BaseRunFlag = 0;                                                              //06-12-16|0x013e
            SystemMsg;                                                                    //06-12-16|0x013e
            break;                                                                        //06-12-16|0x013e
        }                                                                                 //06-12-16|0x013e
        break;                                                                            //06-12-16|0x013e
//---------------------------------------------------------------------------             //06-12-16|0x013f
      case 16357: // MAKE_ARGS                                                            //06-12-16|0x0140
        switch(SpawnMakeArgs)                                                             //06-12-16|0x0140
        {                                                                                 //06-12-16|0x0140
          case Success:                                                                   //06-12-16|0x0140
            BaseRunFlag = 1;                                                              //06-12-16|0x0140
            BaseState = 16052; // READ_MAKE_EXIT                                          //06-12-16|0x0140
            break;                                                                        //06-12-16|0x0140
          case UserError:                                                                 //06-12-16|0x0140
            BaseRunFlag = 1;                                                              //06-12-16|0x0140
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0140
            break;                                                                        //06-12-16|0x0140
          default:                                                                        //06-12-16|0x0140
            BaseStatus = SystemError;                                                     //06-12-16|0x0140
            BaseRunFlag = 0;                                                              //06-12-16|0x0140
            SystemMsg;                                                                    //06-12-16|0x0140
            break;                                                                        //06-12-16|0x0140
        }                                                                                 //06-12-16|0x0140
        break;                                                                            //06-12-16|0x0140
//***************************************************************************             //06-12-16|0x0141
      case 16052: // READ_MAKE_EXIT                                                       //06-12-16|0x0142
        switch(ReadProject)                                                               //06-12-16|0x0142
        {                                                                                 //06-12-16|0x0142
          case Display:                                                                   //06-12-16|0x0142
            BaseState = 10867; // READ_MAKE_EXIT_EXIT                                     //06-12-16|0x0142
            BaseStatus = Display;                                                         //06-12-16|0x0142
            BaseRunFlag = 0;                                                              //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          case LineDone:                                                                  //06-12-16|0x0142
            BaseRunFlag = 1;                                                              //06-12-16|0x0142
            BaseState = 53794; // TEST_MAKE_EXIT_CMD                                      //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          case FileDone:                                                                  //06-12-16|0x0142
            BaseRunFlag = 1;                                                              //06-12-16|0x0142
            BaseState = 62725; // END_FILE                                                //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          case UserError:                                                                 //06-12-16|0x0142
            BaseRunFlag = 1;                                                              //06-12-16|0x0142
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          default:                                                                        //06-12-16|0x0142
            BaseStatus = SystemError;                                                     //06-12-16|0x0142
            BaseRunFlag = 0;                                                              //06-12-16|0x0142
            SystemMsg;                                                                    //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
        }                                                                                 //06-12-16|0x0142
        break;                                                                            //06-12-16|0x0142
//**************************************************************************              //06-12-16|0x0142
      case 10867: // READ_MAKE_EXIT_EXIT                                                  //06-12-16|0x0142
        switch(ReadProject)                                                               //06-12-16|0x0142
        {                                                                                 //06-12-16|0x0142
          case Display:                                                                   //06-12-16|0x0142
            BaseState = 10867; // READ_MAKE_EXIT_EXIT                                     //06-12-16|0x0142
            BaseStatus = Display;                                                         //06-12-16|0x0142
            BaseRunFlag = 0;                                                              //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          case LineDone:                                                                  //06-12-16|0x0142
            BaseRunFlag = 1;                                                              //06-12-16|0x0142
            BaseState = 53794; // TEST_MAKE_EXIT_CMD                                      //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          case FileDone:                                                                  //06-12-16|0x0142
            BaseRunFlag = 1;                                                              //06-12-16|0x0142
            BaseState = 62725; // END_FILE                                                //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          case UserError:                                                                 //06-12-16|0x0142
            BaseRunFlag = 1;                                                              //06-12-16|0x0142
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
          default:                                                                        //06-12-16|0x0142
            BaseStatus = SystemError;                                                     //06-12-16|0x0142
            BaseRunFlag = 0;                                                              //06-12-16|0x0142
            SystemMsg;                                                                    //06-12-16|0x0142
            break;                                                                        //06-12-16|0x0142
        }                                                                                 //06-12-16|0x0142
        break;                                                                            //06-12-16|0x0142
//---------------------------------------------------------------------------             //06-12-16|0x0143
      case 53794: // TEST_MAKE_EXIT_CMD                                                   //06-12-16|0x0144
        switch(CmdTest("_MAKE_EXIT"))                                                     //06-12-16|0x0144
        {                                                                                 //06-12-16|0x0144
          case -1:                                                                        //06-12-16|0x0144
            BaseRunFlag = 1;                                                              //06-12-16|0x0144
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-16|0x0144
            break;                                                                        //06-12-16|0x0144
          case 0:                                                                         //06-12-16|0x0144
            BaseRunFlag = 1;                                                              //06-12-16|0x0144
            BaseState = 62657; // MAKE_EXIT                                               //06-12-16|0x0144
            break;                                                                        //06-12-16|0x0144
          case 1:                                                                         //06-12-16|0x0144
            BaseRunFlag = 1;                                                              //06-12-16|0x0144
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-16|0x0144
            break;                                                                        //06-12-16|0x0144
          default:                                                                        //06-12-16|0x0144
            BaseStatus = SystemError;                                                     //06-12-16|0x0144
            BaseRunFlag = 0;                                                              //06-12-16|0x0144
            SystemMsg;                                                                    //06-12-16|0x0144
            break;                                                                        //06-12-16|0x0144
        }                                                                                 //06-12-16|0x0144
        break;                                                                            //06-12-16|0x0144
//---------------------------------------------------------------------------             //06-12-16|0x0145
      case 62657: // MAKE_EXIT                                                            //06-12-16|0x0146
        switch(SpawnMakeExit)                                                             //06-12-16|0x0146
        {                                                                                 //06-12-16|0x0146
          case Success:                                                                   //06-12-16|0x0146
            BaseRunFlag = 1;                                                              //06-12-16|0x0146
            BaseState = 16720; // READ_RUN_NAME                                           //06-12-16|0x0146
            break;                                                                        //06-12-16|0x0146
          case UserError:                                                                 //06-12-16|0x0146
            BaseRunFlag = 1;                                                              //06-12-16|0x0146
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0146
            break;                                                                        //06-12-16|0x0146
          default:                                                                        //06-12-16|0x0146
            BaseStatus = SystemError;                                                     //06-12-16|0x0146
            BaseRunFlag = 0;                                                              //06-12-16|0x0146
            SystemMsg;                                                                    //06-12-16|0x0146
            break;                                                                        //06-12-16|0x0146
        }                                                                                 //06-12-16|0x0146
        break;                                                                            //06-12-16|0x0146
//***************************************************************************             //06-12-16|0x0147
//******                                                               ******             //06-12-16|0x0148
//******  READ PROJECT COMMANDS                                        ******             //06-12-16|0x0149
//******---------------------------------------------------------------******             //06-12-16|0x014a
//******  Get Run Command                                              ******             //06-12-16|0x014b
//******                                                               ******             //06-12-16|0x014c
//***************************************************************************             //06-12-16|0x014d
      case 16720: // READ_RUN_NAME                                                        //06-12-16|0x014e
        switch(ReadProject)                                                               //06-12-16|0x014e
        {                                                                                 //06-12-16|0x014e
          case Display:                                                                   //06-12-16|0x014e
            BaseState = 22223; // READ_RUN_NAME_EXIT                                      //06-12-16|0x014e
            BaseStatus = Display;                                                         //06-12-16|0x014e
            BaseRunFlag = 0;                                                              //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          case LineDone:                                                                  //06-12-16|0x014e
            BaseRunFlag = 1;                                                              //06-12-16|0x014e
            BaseState = 32023; // TEST_RUN_NAME_CMD                                       //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          case FileDone:                                                                  //06-12-16|0x014e
            BaseRunFlag = 1;                                                              //06-12-16|0x014e
            BaseState = 62725; // END_FILE                                                //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          case UserError:                                                                 //06-12-16|0x014e
            BaseRunFlag = 1;                                                              //06-12-16|0x014e
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          default:                                                                        //06-12-16|0x014e
            BaseStatus = SystemError;                                                     //06-12-16|0x014e
            BaseRunFlag = 0;                                                              //06-12-16|0x014e
            SystemMsg;                                                                    //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
        }                                                                                 //06-12-16|0x014e
        break;                                                                            //06-12-16|0x014e
//**************************************************************************              //06-12-16|0x014e
      case 22223: // READ_RUN_NAME_EXIT                                                   //06-12-16|0x014e
        switch(ReadProject)                                                               //06-12-16|0x014e
        {                                                                                 //06-12-16|0x014e
          case Display:                                                                   //06-12-16|0x014e
            BaseState = 22223; // READ_RUN_NAME_EXIT                                      //06-12-16|0x014e
            BaseStatus = Display;                                                         //06-12-16|0x014e
            BaseRunFlag = 0;                                                              //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          case LineDone:                                                                  //06-12-16|0x014e
            BaseRunFlag = 1;                                                              //06-12-16|0x014e
            BaseState = 32023; // TEST_RUN_NAME_CMD                                       //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          case FileDone:                                                                  //06-12-16|0x014e
            BaseRunFlag = 1;                                                              //06-12-16|0x014e
            BaseState = 62725; // END_FILE                                                //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          case UserError:                                                                 //06-12-16|0x014e
            BaseRunFlag = 1;                                                              //06-12-16|0x014e
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
          default:                                                                        //06-12-16|0x014e
            BaseStatus = SystemError;                                                     //06-12-16|0x014e
            BaseRunFlag = 0;                                                              //06-12-16|0x014e
            SystemMsg;                                                                    //06-12-16|0x014e
            break;                                                                        //06-12-16|0x014e
        }                                                                                 //06-12-16|0x014e
        break;                                                                            //06-12-16|0x014e
//---------------------------------------------------------------------------             //06-12-16|0x014f
      case 32023: // TEST_RUN_NAME_CMD                                                    //06-12-16|0x0150
        switch(CmdTest("_RUN_NAME"))                                                      //06-12-16|0x0150
        {                                                                                 //06-12-16|0x0150
          case -1:                                                                        //06-12-16|0x0150
            BaseRunFlag = 1;                                                              //06-12-16|0x0150
            BaseState = 50238; // RECORD_NAME_CMD                                         //06-12-16|0x0150
            break;                                                                        //06-12-16|0x0150
          case 0:                                                                         //06-12-16|0x0150
            BaseRunFlag = 1;                                                              //06-12-16|0x0150
            BaseState = 2205; // RUN_NAME                                                 //06-12-16|0x0150
            break;                                                                        //06-12-16|0x0150
          case 1:                                                                         //06-12-16|0x0150
            BaseRunFlag = 1;                                                              //06-12-16|0x0150
            BaseState = 50238; // RECORD_NAME_CMD                                         //06-12-16|0x0150
            break;                                                                        //06-12-16|0x0150
          default:                                                                        //06-12-16|0x0150
            BaseStatus = SystemError;                                                     //06-12-16|0x0150
            BaseRunFlag = 0;                                                              //06-12-16|0x0150
            SystemMsg;                                                                    //06-12-16|0x0150
            break;                                                                        //06-12-16|0x0150
        }                                                                                 //06-12-16|0x0150
        break;                                                                            //06-12-16|0x0150
//---------------------------------------------------------------------------             //06-12-16|0x0151
      case 2205: // RUN_NAME                                                              //06-12-16|0x0152
        switch(SpawnRunName)                                                              //06-12-16|0x0152
        {                                                                                 //06-12-16|0x0152
          case Success:                                                                   //06-12-16|0x0152
            BaseRunFlag = 1;                                                              //06-12-16|0x0152
            BaseState = 37612; // RUN_ARGS                                                //06-12-16|0x0152
            break;                                                                        //06-12-16|0x0152
          case UserError:                                                                 //06-12-16|0x0152
            BaseRunFlag = 1;                                                              //06-12-16|0x0152
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0152
            break;                                                                        //06-12-16|0x0152
          default:                                                                        //06-12-16|0x0152
            BaseStatus = SystemError;                                                     //06-12-16|0x0152
            BaseRunFlag = 0;                                                              //06-12-16|0x0152
            SystemMsg;                                                                    //06-12-16|0x0152
            break;                                                                        //06-12-16|0x0152
        }                                                                                 //06-12-16|0x0152
        break;                                                                            //06-12-16|0x0152
//---------------------------------------------------------------------------             //06-12-16|0x0153
      case 37612: // RUN_ARGS                                                             //06-12-16|0x0154
        switch(SpawnRunArgs)                                                              //06-12-16|0x0154
        {                                                                                 //06-12-16|0x0154
          case Success:                                                                   //06-12-16|0x0154
            BaseRunFlag = 1;                                                              //06-12-16|0x0154
            BaseState = 49707; // READ_RUN_EXIT                                           //06-12-16|0x0154
            break;                                                                        //06-12-16|0x0154
          case UserError:                                                                 //06-12-16|0x0154
            BaseRunFlag = 1;                                                              //06-12-16|0x0154
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0154
            break;                                                                        //06-12-16|0x0154
          default:                                                                        //06-12-16|0x0154
            BaseStatus = SystemError;                                                     //06-12-16|0x0154
            BaseRunFlag = 0;                                                              //06-12-16|0x0154
            SystemMsg;                                                                    //06-12-16|0x0154
            break;                                                                        //06-12-16|0x0154
        }                                                                                 //06-12-16|0x0154
        break;                                                                            //06-12-16|0x0154
//***************************************************************************             //06-12-16|0x0155
      case 49707: // READ_RUN_EXIT                                                        //06-12-16|0x0156
        switch(ReadProject)                                                               //06-12-16|0x0156
        {                                                                                 //06-12-16|0x0156
          case Display:                                                                   //06-12-16|0x0156
            BaseState = 58714; // READ_RUN_EXIT_EXIT                                      //06-12-16|0x0156
            BaseStatus = Display;                                                         //06-12-16|0x0156
            BaseRunFlag = 0;                                                              //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          case LineDone:                                                                  //06-12-16|0x0156
            BaseRunFlag = 1;                                                              //06-12-16|0x0156
            BaseState = 15225; // TEST_RUN_EXIT_CMD                                       //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          case FileDone:                                                                  //06-12-16|0x0156
            BaseRunFlag = 1;                                                              //06-12-16|0x0156
            BaseState = 62725; // END_FILE                                                //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          case UserError:                                                                 //06-12-16|0x0156
            BaseRunFlag = 1;                                                              //06-12-16|0x0156
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          default:                                                                        //06-12-16|0x0156
            BaseStatus = SystemError;                                                     //06-12-16|0x0156
            BaseRunFlag = 0;                                                              //06-12-16|0x0156
            SystemMsg;                                                                    //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
        }                                                                                 //06-12-16|0x0156
        break;                                                                            //06-12-16|0x0156
//**************************************************************************              //06-12-16|0x0156
      case 58714: // READ_RUN_EXIT_EXIT                                                   //06-12-16|0x0156
        switch(ReadProject)                                                               //06-12-16|0x0156
        {                                                                                 //06-12-16|0x0156
          case Display:                                                                   //06-12-16|0x0156
            BaseState = 58714; // READ_RUN_EXIT_EXIT                                      //06-12-16|0x0156
            BaseStatus = Display;                                                         //06-12-16|0x0156
            BaseRunFlag = 0;                                                              //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          case LineDone:                                                                  //06-12-16|0x0156
            BaseRunFlag = 1;                                                              //06-12-16|0x0156
            BaseState = 15225; // TEST_RUN_EXIT_CMD                                       //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          case FileDone:                                                                  //06-12-16|0x0156
            BaseRunFlag = 1;                                                              //06-12-16|0x0156
            BaseState = 62725; // END_FILE                                                //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          case UserError:                                                                 //06-12-16|0x0156
            BaseRunFlag = 1;                                                              //06-12-16|0x0156
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
          default:                                                                        //06-12-16|0x0156
            BaseStatus = SystemError;                                                     //06-12-16|0x0156
            BaseRunFlag = 0;                                                              //06-12-16|0x0156
            SystemMsg;                                                                    //06-12-16|0x0156
            break;                                                                        //06-12-16|0x0156
        }                                                                                 //06-12-16|0x0156
        break;                                                                            //06-12-16|0x0156
//---------------------------------------------------------------------------             //06-12-16|0x0157
      case 15225: // TEST_RUN_EXIT_CMD                                                    //06-12-16|0x0158
        switch(CmdTest("_RUN_EXIT"))                                                      //06-12-16|0x0158
        {                                                                                 //06-12-16|0x0158
          case -1:                                                                        //06-12-16|0x0158
            BaseRunFlag = 1;                                                              //06-12-16|0x0158
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-16|0x0158
            break;                                                                        //06-12-16|0x0158
          case 0:                                                                         //06-12-16|0x0158
            BaseRunFlag = 1;                                                              //06-12-16|0x0158
            BaseState = 62344; // RUN_EXIT                                                //06-12-16|0x0158
            break;                                                                        //06-12-16|0x0158
          case 1:                                                                         //06-12-16|0x0158
            BaseRunFlag = 1;                                                              //06-12-16|0x0158
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-16|0x0158
            break;                                                                        //06-12-16|0x0158
          default:                                                                        //06-12-16|0x0158
            BaseStatus = SystemError;                                                     //06-12-16|0x0158
            BaseRunFlag = 0;                                                              //06-12-16|0x0158
            SystemMsg;                                                                    //06-12-16|0x0158
            break;                                                                        //06-12-16|0x0158
        }                                                                                 //06-12-16|0x0158
        break;                                                                            //06-12-16|0x0158
//---------------------------------------------------------------------------             //06-12-16|0x0159
      case 62344: // RUN_EXIT                                                             //06-12-16|0x015a
        switch(SpawnRunExit)                                                              //06-12-16|0x015a
        {                                                                                 //06-12-16|0x015a
          case Success:                                                                   //06-12-16|0x015a
            BaseRunFlag = 1;                                                              //06-12-16|0x015a
            BaseState = 11399; // READ_RECORD_NAME                                        //06-12-16|0x015a
            break;                                                                        //06-12-16|0x015a
          case UserError:                                                                 //06-12-16|0x015a
            BaseRunFlag = 1;                                                              //06-12-16|0x015a
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x015a
            break;                                                                        //06-12-16|0x015a
          default:                                                                        //06-12-16|0x015a
            BaseStatus = SystemError;                                                     //06-12-16|0x015a
            BaseRunFlag = 0;                                                              //06-12-16|0x015a
            SystemMsg;                                                                    //06-12-16|0x015a
            break;                                                                        //06-12-16|0x015a
        }                                                                                 //06-12-16|0x015a
        break;                                                                            //06-12-16|0x015a
//***************************************************************************             //06-12-16|0x015b
//******                                                               ******             //06-12-16|0x015c
//******  READ PROJECT COMMANDS                                        ******             //06-12-16|0x015d
//******---------------------------------------------------------------******             //06-12-16|0x015e
//******  Get Record Project Name                                      ******             //06-12-16|0x015f
//******                                                               ******             //06-12-16|0x0160
//***************************************************************************             //06-12-16|0x0161
      case 11399: // READ_RECORD_NAME                                                     //06-12-16|0x0162
        switch(ReadProject)                                                               //06-12-16|0x0162
        {                                                                                 //06-12-16|0x0162
          case Display:                                                                   //06-12-16|0x0162
            BaseState = 62838; // READ_RECORD_NAME_EXIT                                   //06-12-16|0x0162
            BaseStatus = Display;                                                         //06-12-16|0x0162
            BaseRunFlag = 0;                                                              //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          case LineDone:                                                                  //06-12-16|0x0162
            BaseRunFlag = 1;                                                              //06-12-16|0x0162
            BaseState = 50238; // RECORD_NAME_CMD                                         //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          case FileDone:                                                                  //06-12-16|0x0162
            BaseRunFlag = 1;                                                              //06-12-16|0x0162
            BaseState = 62725; // END_FILE                                                //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          case UserError:                                                                 //06-12-16|0x0162
            BaseRunFlag = 1;                                                              //06-12-16|0x0162
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          default:                                                                        //06-12-16|0x0162
            BaseStatus = SystemError;                                                     //06-12-16|0x0162
            BaseRunFlag = 0;                                                              //06-12-16|0x0162
            SystemMsg;                                                                    //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
        }                                                                                 //06-12-16|0x0162
        break;                                                                            //06-12-16|0x0162
//**************************************************************************              //06-12-16|0x0162
      case 62838: // READ_RECORD_NAME_EXIT                                                //06-12-16|0x0162
        switch(ReadProject)                                                               //06-12-16|0x0162
        {                                                                                 //06-12-16|0x0162
          case Display:                                                                   //06-12-16|0x0162
            BaseState = 62838; // READ_RECORD_NAME_EXIT                                   //06-12-16|0x0162
            BaseStatus = Display;                                                         //06-12-16|0x0162
            BaseRunFlag = 0;                                                              //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          case LineDone:                                                                  //06-12-16|0x0162
            BaseRunFlag = 1;                                                              //06-12-16|0x0162
            BaseState = 50238; // RECORD_NAME_CMD                                         //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          case FileDone:                                                                  //06-12-16|0x0162
            BaseRunFlag = 1;                                                              //06-12-16|0x0162
            BaseState = 62725; // END_FILE                                                //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          case UserError:                                                                 //06-12-16|0x0162
            BaseRunFlag = 1;                                                              //06-12-16|0x0162
            BaseState = 55279; // USR_CLS                                                 //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
          default:                                                                        //06-12-16|0x0162
            BaseStatus = SystemError;                                                     //06-12-16|0x0162
            BaseRunFlag = 0;                                                              //06-12-16|0x0162
            SystemMsg;                                                                    //06-12-16|0x0162
            break;                                                                        //06-12-16|0x0162
        }                                                                                 //06-12-16|0x0162
        break;                                                                            //06-12-16|0x0162
//***************************************************************************             //06-12-16|0x0163
      case 50238: // RECORD_NAME_CMD                                                      //06-12-16|0x0164
        switch(CmdTest("_RECORD_NAME"))                                                   //06-12-16|0x0164
        {                                                                                 //06-12-16|0x0164
          case -1:                                                                        //06-12-16|0x0164
            BaseRunFlag = 1;                                                              //06-12-16|0x0164
            BaseState = 19797; // DELETE_NAMES_CMD                                        //06-12-16|0x0164
            break;                                                                        //06-12-16|0x0164
          case 0:                                                                         //06-12-16|0x0164
            BaseRunFlag = 1;                                                              //06-12-16|0x0164
            BaseState = 8996; // RECORD_NAME                                              //06-12-16|0x0164
            break;                                                                        //06-12-16|0x0164
          case 1:                                                                         //06-12-16|0x0164
            BaseRunFlag = 1;                                                              //06-12-16|0x0164
            BaseState = 19797; // DELETE_NAMES_CMD                                        //06-12-16|0x0164
            break;                                                                        //06-12-16|0x0164
          default:                                                                        //06-12-16|0x0164
            BaseStatus = SystemError;                                                     //06-12-16|0x0164
            BaseRunFlag = 0;                                                              //06-12-16|0x0164
            SystemMsg;                                                                    //06-12-16|0x0164
            break;                                                                        //06-12-16|0x0164
        }                                                                                 //06-12-16|0x0164
        break;                                                                            //06-12-16|0x0164
//***************************************************************************             //06-12-17|0x0165
      case 8996: // RECORD_NAME                                                           //06-12-17|0x0166
        switch(RecordPcgName)                                                             //06-12-17|0x0166
        {                                                                                 //06-12-17|0x0166
          case Success:                                                                   //06-12-17|0x0166
            BaseRunFlag = 1;                                                              //06-12-17|0x0166
            BaseState = 21987; // READ_REPORT_NAME                                        //06-12-17|0x0166
            break;                                                                        //06-12-17|0x0166
          case UserError:                                                                 //06-12-17|0x0166
            BaseRunFlag = 1;                                                              //06-12-17|0x0166
            BaseState = 55279; // USR_CLS                                                 //06-12-17|0x0166
            break;                                                                        //06-12-17|0x0166
          default:                                                                        //06-12-17|0x0166
            BaseStatus = SystemError;                                                     //06-12-17|0x0166
            BaseRunFlag = 0;                                                              //06-12-17|0x0166
            SystemMsg;                                                                    //06-12-17|0x0166
            break;                                                                        //06-12-17|0x0166
        }                                                                                 //06-12-17|0x0166
        break;                                                                            //06-12-17|0x0166
//***************************************************************************             //06-12-17|0x0167
//******                                                               ******             //06-12-17|0x0168
//******  READ PROJECT COMMANDS                                        ******             //06-12-17|0x0169
//******---------------------------------------------------------------******             //06-12-17|0x016a
//******  Get Report Project Name                                      ******             //06-12-17|0x016b
//******                                                               ******             //06-12-17|0x016c
//***************************************************************************             //06-12-18|0x016d
      case 21987: // READ_REPORT_NAME                                                     //06-12-18|0x016e
        switch(ReadProject)                                                               //06-12-18|0x016e
        {                                                                                 //06-12-18|0x016e
          case Display:                                                                   //06-12-18|0x016e
            BaseState = 46226; // READ_REPORT_NAME_EXIT                                   //06-12-18|0x016e
            BaseStatus = Display;                                                         //06-12-18|0x016e
            BaseRunFlag = 0;                                                              //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          case LineDone:                                                                  //06-12-18|0x016e
            BaseRunFlag = 1;                                                              //06-12-18|0x016e
            BaseState = 65073; // REPORT_NAME_CMD                                         //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          case FileDone:                                                                  //06-12-18|0x016e
            BaseRunFlag = 1;                                                              //06-12-18|0x016e
            BaseState = 62725; // END_FILE                                                //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          case UserError:                                                                 //06-12-18|0x016e
            BaseRunFlag = 1;                                                              //06-12-18|0x016e
            BaseState = 55279; // USR_CLS                                                 //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          default:                                                                        //06-12-18|0x016e
            BaseStatus = SystemError;                                                     //06-12-18|0x016e
            BaseRunFlag = 0;                                                              //06-12-18|0x016e
            SystemMsg;                                                                    //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
        }                                                                                 //06-12-18|0x016e
        break;                                                                            //06-12-18|0x016e
//**************************************************************************              //06-12-18|0x016e
      case 46226: // READ_REPORT_NAME_EXIT                                                //06-12-18|0x016e
        switch(ReadProject)                                                               //06-12-18|0x016e
        {                                                                                 //06-12-18|0x016e
          case Display:                                                                   //06-12-18|0x016e
            BaseState = 46226; // READ_REPORT_NAME_EXIT                                   //06-12-18|0x016e
            BaseStatus = Display;                                                         //06-12-18|0x016e
            BaseRunFlag = 0;                                                              //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          case LineDone:                                                                  //06-12-18|0x016e
            BaseRunFlag = 1;                                                              //06-12-18|0x016e
            BaseState = 65073; // REPORT_NAME_CMD                                         //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          case FileDone:                                                                  //06-12-18|0x016e
            BaseRunFlag = 1;                                                              //06-12-18|0x016e
            BaseState = 62725; // END_FILE                                                //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          case UserError:                                                                 //06-12-18|0x016e
            BaseRunFlag = 1;                                                              //06-12-18|0x016e
            BaseState = 55279; // USR_CLS                                                 //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
          default:                                                                        //06-12-18|0x016e
            BaseStatus = SystemError;                                                     //06-12-18|0x016e
            BaseRunFlag = 0;                                                              //06-12-18|0x016e
            SystemMsg;                                                                    //06-12-18|0x016e
            break;                                                                        //06-12-18|0x016e
        }                                                                                 //06-12-18|0x016e
        break;                                                                            //06-12-18|0x016e
//***************************************************************************             //06-12-18|0x016f
      case 65073: // REPORT_NAME_CMD                                                      //06-12-18|0x0170
        switch(CmdTest("_REPORT_NAME"))                                                   //06-12-18|0x0170
        {                                                                                 //06-12-18|0x0170
          case -1:                                                                        //06-12-18|0x0170
            BaseRunFlag = 1;                                                              //06-12-18|0x0170
            BaseState = 19797; // DELETE_NAMES_CMD                                        //06-12-18|0x0170
            break;                                                                        //06-12-18|0x0170
          case 0:                                                                         //06-12-18|0x0170
            BaseRunFlag = 1;                                                              //06-12-18|0x0170
            BaseState = 57792; // REPORT_NAME                                             //06-12-18|0x0170
            break;                                                                        //06-12-18|0x0170
          case 1:                                                                         //06-12-18|0x0170
            BaseRunFlag = 1;                                                              //06-12-18|0x0170
            BaseState = 19797; // DELETE_NAMES_CMD                                        //06-12-18|0x0170
            break;                                                                        //06-12-18|0x0170
          default:                                                                        //06-12-18|0x0170
            BaseStatus = SystemError;                                                     //06-12-18|0x0170
            BaseRunFlag = 0;                                                              //06-12-18|0x0170
            SystemMsg;                                                                    //06-12-18|0x0170
            break;                                                                        //06-12-18|0x0170
        }                                                                                 //06-12-18|0x0170
        break;                                                                            //06-12-18|0x0170
//***************************************************************************             //06-12-18|0x0171
      case 57792: // REPORT_NAME                                                          //06-12-18|0x0172
        switch(ReportPcgName)                                                             //06-12-18|0x0172
        {                                                                                 //06-12-18|0x0172
          case Success:                                                                   //06-12-18|0x0172
            BaseRunFlag = 1;                                                              //06-12-18|0x0172
            BaseState = 65087; // READ_DELETE_NAMES                                       //06-12-18|0x0172
            break;                                                                        //06-12-18|0x0172
          case UserError:                                                                 //06-12-18|0x0172
            BaseRunFlag = 1;                                                              //06-12-18|0x0172
            BaseState = 55279; // USR_CLS                                                 //06-12-18|0x0172
            break;                                                                        //06-12-18|0x0172
          default:                                                                        //06-12-18|0x0172
            BaseStatus = SystemError;                                                     //06-12-18|0x0172
            BaseRunFlag = 0;                                                              //06-12-18|0x0172
            SystemMsg;                                                                    //06-12-18|0x0172
            break;                                                                        //06-12-18|0x0172
        }                                                                                 //06-12-18|0x0172
        break;                                                                            //06-12-18|0x0172
//***************************************************************************             //06-12-11|0x0173
//******                                                               ******             //06-12-11|0x0174
//******  READ PROJECT COMMANDS                                        ******             //06-12-11|0x0175
//******---------------------------------------------------------------******             //06-12-11|0x0176
//******  Get Cleanup File Names                                       ******             //06-12-11|0x0177
//******                                                               ******             //06-12-11|0x0178
//***************************************************************************             //06-12-11|0x0179
      case 65087: // READ_DELETE_NAMES                                                    //06-12-17|0x017a
        switch(ReadProject)                                                               //06-12-17|0x017a
        {                                                                                 //06-12-17|0x017a
          case Display:                                                                   //06-12-17|0x017a
            BaseState = 58030; // READ_DELETE_NAMES_EXIT                                  //06-12-17|0x017a
            BaseStatus = Display;                                                         //06-12-17|0x017a
            BaseRunFlag = 0;                                                              //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          case LineDone:                                                                  //06-12-17|0x017a
            BaseRunFlag = 1;                                                              //06-12-17|0x017a
            BaseState = 19797; // DELETE_NAMES_CMD                                        //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          case FileDone:                                                                  //06-12-17|0x017a
            BaseRunFlag = 1;                                                              //06-12-17|0x017a
            BaseState = 62725; // END_FILE                                                //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          case UserError:                                                                 //06-12-17|0x017a
            BaseRunFlag = 1;                                                              //06-12-17|0x017a
            BaseState = 55279; // USR_CLS                                                 //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          default:                                                                        //06-12-17|0x017a
            BaseStatus = SystemError;                                                     //06-12-17|0x017a
            BaseRunFlag = 0;                                                              //06-12-17|0x017a
            SystemMsg;                                                                    //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
        }                                                                                 //06-12-17|0x017a
        break;                                                                            //06-12-17|0x017a
//**************************************************************************              //06-12-17|0x017a
      case 58030: // READ_DELETE_NAMES_EXIT                                               //06-12-17|0x017a
        switch(ReadProject)                                                               //06-12-17|0x017a
        {                                                                                 //06-12-17|0x017a
          case Display:                                                                   //06-12-17|0x017a
            BaseState = 58030; // READ_DELETE_NAMES_EXIT                                  //06-12-17|0x017a
            BaseStatus = Display;                                                         //06-12-17|0x017a
            BaseRunFlag = 0;                                                              //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          case LineDone:                                                                  //06-12-17|0x017a
            BaseRunFlag = 1;                                                              //06-12-17|0x017a
            BaseState = 19797; // DELETE_NAMES_CMD                                        //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          case FileDone:                                                                  //06-12-17|0x017a
            BaseRunFlag = 1;                                                              //06-12-17|0x017a
            BaseState = 62725; // END_FILE                                                //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          case UserError:                                                                 //06-12-17|0x017a
            BaseRunFlag = 1;                                                              //06-12-17|0x017a
            BaseState = 55279; // USR_CLS                                                 //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
          default:                                                                        //06-12-17|0x017a
            BaseStatus = SystemError;                                                     //06-12-17|0x017a
            BaseRunFlag = 0;                                                              //06-12-17|0x017a
            SystemMsg;                                                                    //06-12-17|0x017a
            break;                                                                        //06-12-17|0x017a
        }                                                                                 //06-12-17|0x017a
        break;                                                                            //06-12-17|0x017a
//***************************************************************************             //06-12-11|0x017b
      case 19797: // DELETE_NAMES_CMD                                                     //06-12-11|0x017c
        switch(CmdTest("_DELETE_FILES"))                                                  //06-12-11|0x017c
        {                                                                                 //06-12-11|0x017c
          case -1:                                                                        //06-12-11|0x017c
            BaseRunFlag = 1;                                                              //06-12-11|0x017c
            BaseState = 3597; // RANDOM_SET_CMD                                           //06-12-11|0x017c
            break;                                                                        //06-12-11|0x017c
          case 0:                                                                         //06-12-11|0x017c
            BaseRunFlag = 1;                                                              //06-12-11|0x017c
            BaseState = 61276; // DELETE_NAMES                                            //06-12-11|0x017c
            break;                                                                        //06-12-11|0x017c
          case 1:                                                                         //06-12-11|0x017c
            BaseRunFlag = 1;                                                              //06-12-11|0x017c
            BaseState = 3597; // RANDOM_SET_CMD                                           //06-12-11|0x017c
            break;                                                                        //06-12-11|0x017c
          default:                                                                        //06-12-11|0x017c
            BaseStatus = SystemError;                                                     //06-12-11|0x017c
            BaseRunFlag = 0;                                                              //06-12-11|0x017c
            SystemMsg;                                                                    //06-12-11|0x017c
            break;                                                                        //06-12-11|0x017c
        }                                                                                 //06-12-11|0x017c
        break;                                                                            //06-12-11|0x017c
//***************************************************************************             //06-12-17|0x017d
      case 61276: // DELETE_NAMES                                                         //06-12-17|0x017e
        switch(cleanup_names())                                                           //06-12-17|0x017e
        {                                                                                 //06-12-17|0x017e
          case Success:                                                                   //06-12-17|0x017e
            BaseRunFlag = 1;                                                              //06-12-17|0x017e
            BaseState = 58779; // READ_RANDOM_SET                                         //06-12-17|0x017e
            break;                                                                        //06-12-17|0x017e
          case UserError:                                                                 //06-12-17|0x017e
            BaseRunFlag = 1;                                                              //06-12-17|0x017e
            BaseState = 55279; // USR_CLS                                                 //06-12-17|0x017e
            break;                                                                        //06-12-17|0x017e
          default:                                                                        //06-12-17|0x017e
            BaseStatus = SystemError;                                                     //06-12-17|0x017e
            BaseRunFlag = 0;                                                              //06-12-17|0x017e
            SystemMsg;                                                                    //06-12-17|0x017e
            break;                                                                        //06-12-17|0x017e
        }                                                                                 //06-12-17|0x017e
        break;                                                                            //06-12-17|0x017e
//***************************************************************************             //06-12-11|0x017f
//******                                                               ******             //06-12-11|0x0180
//******  READ PROJECT COMMANDS                                        ******             //06-12-11|0x0181
//******---------------------------------------------------------------******             //06-12-11|0x0182
//******  Get Random Set Command                                       ******             //06-12-11|0x0183
//******                                                               ******             //06-12-11|0x0184
//***************************************************************************             //06-12-11|0x0185
      case 58779: // READ_RANDOM_SET                                                      //06-12-11|0x0186
        switch(ReadProject)                                                               //06-12-11|0x0186
        {                                                                                 //06-12-11|0x0186
          case Display:                                                                   //06-12-11|0x0186
            BaseState = 16330; // READ_RANDOM_SET_EXIT                                    //06-12-11|0x0186
            BaseStatus = Display;                                                         //06-12-11|0x0186
            BaseRunFlag = 0;                                                              //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          case LineDone:                                                                  //06-12-11|0x0186
            BaseRunFlag = 1;                                                              //06-12-11|0x0186
            BaseState = 3597; // RANDOM_SET_CMD                                           //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          case FileDone:                                                                  //06-12-11|0x0186
            BaseRunFlag = 1;                                                              //06-12-11|0x0186
            BaseState = 62725; // END_FILE                                                //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          case UserError:                                                                 //06-12-11|0x0186
            BaseRunFlag = 1;                                                              //06-12-11|0x0186
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          default:                                                                        //06-12-11|0x0186
            BaseStatus = SystemError;                                                     //06-12-11|0x0186
            BaseRunFlag = 0;                                                              //06-12-11|0x0186
            SystemMsg;                                                                    //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
        }                                                                                 //06-12-11|0x0186
        break;                                                                            //06-12-11|0x0186
//**************************************************************************              //06-12-11|0x0186
      case 16330: // READ_RANDOM_SET_EXIT                                                 //06-12-11|0x0186
        switch(ReadProject)                                                               //06-12-11|0x0186
        {                                                                                 //06-12-11|0x0186
          case Display:                                                                   //06-12-11|0x0186
            BaseState = 16330; // READ_RANDOM_SET_EXIT                                    //06-12-11|0x0186
            BaseStatus = Display;                                                         //06-12-11|0x0186
            BaseRunFlag = 0;                                                              //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          case LineDone:                                                                  //06-12-11|0x0186
            BaseRunFlag = 1;                                                              //06-12-11|0x0186
            BaseState = 3597; // RANDOM_SET_CMD                                           //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          case FileDone:                                                                  //06-12-11|0x0186
            BaseRunFlag = 1;                                                              //06-12-11|0x0186
            BaseState = 62725; // END_FILE                                                //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          case UserError:                                                                 //06-12-11|0x0186
            BaseRunFlag = 1;                                                              //06-12-11|0x0186
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
          default:                                                                        //06-12-11|0x0186
            BaseStatus = SystemError;                                                     //06-12-11|0x0186
            BaseRunFlag = 0;                                                              //06-12-11|0x0186
            SystemMsg;                                                                    //06-12-11|0x0186
            break;                                                                        //06-12-11|0x0186
        }                                                                                 //06-12-11|0x0186
        break;                                                                            //06-12-11|0x0186
//***************************************************************************             //06-12-11|0x0187
      case 3597: // RANDOM_SET_CMD                                                        //06-12-11|0x0188
        switch(CmdTest("_RANDOM_SET"))                                                    //06-12-11|0x0188
        {                                                                                 //06-12-11|0x0188
          case -1:                                                                        //06-12-11|0x0188
            BaseRunFlag = 1;                                                              //06-12-11|0x0188
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-11|0x0188
            break;                                                                        //06-12-11|0x0188
          case 0:                                                                         //06-12-11|0x0188
            BaseRunFlag = 1;                                                              //06-12-11|0x0188
            BaseState = 15593; // RANDOM_SET                                              //06-12-11|0x0188
            break;                                                                        //06-12-11|0x0188
          case 1:                                                                         //06-12-11|0x0188
            BaseRunFlag = 1;                                                              //06-12-11|0x0188
            BaseState = 37544; // COMMAND_ERROR                                           //06-12-11|0x0188
            break;                                                                        //06-12-11|0x0188
          default:                                                                        //06-12-11|0x0188
            BaseStatus = SystemError;                                                     //06-12-11|0x0188
            BaseRunFlag = 0;                                                              //06-12-11|0x0188
            SystemMsg;                                                                    //06-12-11|0x0188
            break;                                                                        //06-12-11|0x0188
        }                                                                                 //06-12-11|0x0188
        break;                                                                            //06-12-11|0x0188
//***************************************************************************             //06-12-11|0x0189
      case 15593: // RANDOM_SET                                                           //06-12-11|0x018a
        switch(set_generator())                                                           //06-12-11|0x018a
        {                                                                                 //06-12-11|0x018a
          case Success:                                                                   //06-12-11|0x018a
            BaseRunFlag = 1;                                                              //06-12-11|0x018a
            BaseState = 3064; // READ_FINAL                                               //06-12-11|0x018a
            break;                                                                        //06-12-11|0x018a
          case UserError:                                                                 //06-12-11|0x018a
            BaseRunFlag = 1;                                                              //06-12-11|0x018a
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x018a
            break;                                                                        //06-12-11|0x018a
          default:                                                                        //06-12-11|0x018a
            BaseStatus = SystemError;                                                     //06-12-11|0x018a
            BaseRunFlag = 0;                                                              //06-12-11|0x018a
            SystemMsg;                                                                    //06-12-11|0x018a
            break;                                                                        //06-12-11|0x018a
        }                                                                                 //06-12-11|0x018a
        break;                                                                            //06-12-11|0x018a
//***************************************************************************             //06-12-11|0x018b
      case 3064: // READ_FINAL                                                            //06-12-11|0x018c
        switch(ReadProject)                                                               //06-12-11|0x018c
        {                                                                                 //06-12-11|0x018c
          case Display:                                                                   //06-12-11|0x018c
            BaseState = 52215; // READ_FINAL_EXIT                                         //06-12-11|0x018c
            BaseStatus = Display;                                                         //06-12-11|0x018c
            BaseRunFlag = 0;                                                              //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          case LineDone:                                                                  //06-12-11|0x018c
            BaseRunFlag = 1;                                                              //06-12-11|0x018c
            BaseState = 62725; // END_FILE                                                //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          case FileDone:                                                                  //06-12-11|0x018c
            BaseRunFlag = 1;                                                              //06-12-11|0x018c
            BaseState = 35814; // OK_CLS                                                  //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          case UserError:                                                                 //06-12-11|0x018c
            BaseRunFlag = 1;                                                              //06-12-11|0x018c
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          default:                                                                        //06-12-11|0x018c
            BaseStatus = SystemError;                                                     //06-12-11|0x018c
            BaseRunFlag = 0;                                                              //06-12-11|0x018c
            SystemMsg;                                                                    //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
        }                                                                                 //06-12-11|0x018c
        break;                                                                            //06-12-11|0x018c
//**************************************************************************              //06-12-11|0x018c
      case 52215: // READ_FINAL_EXIT                                                      //06-12-11|0x018c
        switch(ReadProject)                                                               //06-12-11|0x018c
        {                                                                                 //06-12-11|0x018c
          case Display:                                                                   //06-12-11|0x018c
            BaseState = 52215; // READ_FINAL_EXIT                                         //06-12-11|0x018c
            BaseStatus = Display;                                                         //06-12-11|0x018c
            BaseRunFlag = 0;                                                              //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          case LineDone:                                                                  //06-12-11|0x018c
            BaseRunFlag = 1;                                                              //06-12-11|0x018c
            BaseState = 62725; // END_FILE                                                //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          case FileDone:                                                                  //06-12-11|0x018c
            BaseRunFlag = 1;                                                              //06-12-11|0x018c
            BaseState = 35814; // OK_CLS                                                  //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          case UserError:                                                                 //06-12-11|0x018c
            BaseRunFlag = 1;                                                              //06-12-11|0x018c
            BaseState = 55279; // USR_CLS                                                 //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
          default:                                                                        //06-12-11|0x018c
            BaseStatus = SystemError;                                                     //06-12-11|0x018c
            BaseRunFlag = 0;                                                              //06-12-11|0x018c
            SystemMsg;                                                                    //06-12-11|0x018c
            break;                                                                        //06-12-11|0x018c
        }                                                                                 //06-12-11|0x018c
        break;                                                                            //06-12-11|0x018c
//***************************************************************************             //06-12-09|0x018d
//******                                                               ******             //06-12-09|0x018e
//******  READ PROJECT COMMANDS                                        ******             //06-12-09|0x018f
//******---------------------------------------------------------------******             //06-12-09|0x0190
//******  Error Messages                                               ******             //06-12-09|0x0191
//******                                                               ******             //06-12-09|0x0192
//***************************************************************************             //06-12-09|0x0193
      case 62725: // END_FILE                                                             //06-12-09|0x0194
        switch(IllegalFileEnd)                                                            //06-12-09|0x0194
        {                                                                                 //06-12-09|0x0194
          case UserError:                                                                 //06-12-09|0x0194
            BaseRunFlag = 1;                                                              //06-12-09|0x0194
            BaseState = 55279; // USR_CLS                                                 //06-12-09|0x0194
            break;                                                                        //06-12-09|0x0194
          default:                                                                        //06-12-09|0x0194
            BaseStatus = SystemError;                                                     //06-12-09|0x0194
            BaseRunFlag = 0;                                                              //06-12-09|0x0194
            SystemMsg;                                                                    //06-12-09|0x0194
            break;                                                                        //06-12-09|0x0194
        }                                                                                 //06-12-09|0x0194
        break;                                                                            //06-12-09|0x0194
//***************************************************************************             //06-12-09|0x0195
      case 37544: // COMMAND_ERROR                                                        //06-12-09|0x0196
        switch(IllegalCommand)                                                            //06-12-09|0x0196
        {                                                                                 //06-12-09|0x0196
          case UserError:                                                                 //06-12-09|0x0196
            BaseRunFlag = 1;                                                              //06-12-09|0x0196
            BaseState = 55279; // USR_CLS                                                 //06-12-09|0x0196
            break;                                                                        //06-12-09|0x0196
          default:                                                                        //06-12-09|0x0196
            BaseStatus = SystemError;                                                     //06-12-09|0x0196
            BaseRunFlag = 0;                                                              //06-12-09|0x0196
            SystemMsg;                                                                    //06-12-09|0x0196
            break;                                                                        //06-12-09|0x0196
        }                                                                                 //06-12-09|0x0196
        break;                                                                            //06-12-09|0x0196
//***************************************************************************             //06-12-09|0x0197
//******                                                               ******             //06-12-09|0x0198
//******  READ PROJECT COMMANDS                                        ******             //06-12-09|0x0199
//******---------------------------------------------------------------******             //06-12-09|0x019a
//******  Close Commands                                               ******             //06-12-09|0x019b
//******                                                               ******             //06-12-09|0x019c
//***************************************************************************             //06-12-09|0x019d
      case 35814: // OK_CLS                                                               //06-12-11|0x019e
        switch(close_project())                                                           //06-12-11|0x019e
        {                                                                                 //06-12-11|0x019e
          case Success:                                                                   //06-12-11|0x019e
            BaseRunFlag = 1;                                                              //06-12-11|0x019e
            BaseState = 19141; // CLEANUP_FILES                                           //06-12-11|0x019e
            break;                                                                        //06-12-11|0x019e
          default:                                                                        //06-12-11|0x019e
            BaseStatus = SystemError;                                                     //06-12-11|0x019e
            BaseRunFlag = 0;                                                              //06-12-11|0x019e
            SystemMsg;                                                                    //06-12-11|0x019e
            break;                                                                        //06-12-11|0x019e
        }                                                                                 //06-12-11|0x019e
        break;                                                                            //06-12-11|0x019e
//***************************************************************************             //06-12-09|0x019f
      case 55279: // USR_CLS                                                              //06-12-09|0x01a0
        switch(close_project())                                                           //06-12-09|0x01a0
        {                                                                                 //06-12-09|0x01a0
          case Success:                                                                   //06-12-09|0x01a0
            BaseRunFlag = 1;                                                              //06-12-09|0x01a0
            BaseState = 55081; // USER                                                    //06-12-09|0x01a0
            break;                                                                        //06-12-09|0x01a0
          default:                                                                        //06-12-09|0x01a0
            BaseStatus = SystemError;                                                     //06-12-09|0x01a0
            BaseRunFlag = 0;                                                              //06-12-09|0x01a0
            SystemMsg;                                                                    //06-12-09|0x01a0
            break;                                                                        //06-12-09|0x01a0
        }                                                                                 //06-12-09|0x01a0
        break;                                                                            //06-12-09|0x01a0
//***************************************************************************             //06-12-09|0x01a1
//******                                                               ******             //06-12-12|0x01a2
//******  PERFORM THE TESTS                                            ******             //06-12-12|0x01a3
//******---------------------------------------------------------------******             //06-12-12|0x01a4
//******  Delete the Cleanup Files                                     ******             //06-12-12|0x01a5
//******                                                               ******             //06-12-12|0x01a6
//***************************************************************************             //06-12-12|0x01a7
      case 19141: // CLEANUP_FILES                                                        //06-12-12|0x01a8
        switch(cleanup_step())                                                            //06-12-12|0x01a8
        {                                                                                 //06-12-12|0x01a8
          case Success:                                                                   //06-12-12|0x01a8
            BaseRunFlag = 1;                                                              //06-12-12|0x01a8
            BaseState = 63380; // NEXT_TEST                                               //06-12-12|0x01a8
            break;                                                                        //06-12-12|0x01a8
          case UserError:                                                                 //06-12-12|0x01a8
            BaseRunFlag = 1;                                                              //06-12-12|0x01a8
            BaseState = 55081; // USER                                                    //06-12-12|0x01a8
            break;                                                                        //06-12-12|0x01a8
          default:                                                                        //06-12-12|0x01a8
            BaseStatus = SystemError;                                                     //06-12-12|0x01a8
            BaseRunFlag = 0;                                                              //06-12-12|0x01a8
            SystemMsg;                                                                    //06-12-12|0x01a8
            break;                                                                        //06-12-12|0x01a8
        }                                                                                 //06-12-12|0x01a8
        break;                                                                            //06-12-12|0x01a8
//***************************************************************************             //06-12-12|0x01a9
//******                                                               ******             //06-12-12|0x01aa
//******  PERFORM THE TESTS                                            ******             //06-12-12|0x01ab
//******---------------------------------------------------------------******             //06-12-12|0x01ac
//******  Generate the Test conditions                                 ******             //06-12-12|0x01ad
//******                                                               ******             //06-12-12|0x01ae
//***************************************************************************             //06-12-12|0x01af
      case 63380: // NEXT_TEST                                                            //06-12-12|0x01b0
        switch(TestDoneCond)                                                              //06-12-12|0x01b0
        {                                                                                 //06-12-12|0x01b0
          case Yes:                                                                       //06-12-12|0x01b0
            BaseRunFlag = 1;                                                              //06-12-12|0x01b0
            BaseState = 29011; // REPORT_EXISTS                                           //06-12-12|0x01b0
            break;                                                                        //06-12-12|0x01b0
          case No:                                                                        //06-12-12|0x01b0
            BaseRunFlag = 1;                                                              //06-12-12|0x01b0
            BaseState = 34562; // GENERATE_TEST                                           //06-12-12|0x01b0
            break;                                                                        //06-12-12|0x01b0
          default:                                                                        //06-12-12|0x01b0
            BaseStatus = SystemError;                                                     //06-12-12|0x01b0
            BaseRunFlag = 0;                                                              //06-12-12|0x01b0
            SystemMsg;                                                                    //06-12-12|0x01b0
            break;                                                                        //06-12-12|0x01b0
        }                                                                                 //06-12-12|0x01b0
        break;                                                                            //06-12-12|0x01b0
//***************************************************************************             //06-12-12|0x01b1
      case 34562: // GENERATE_TEST                                                        //06-12-12|0x01b2
        switch(generate_test())                                                           //06-12-12|0x01b2
        {                                                                                 //06-12-12|0x01b2
          case Success:                                                                   //06-12-12|0x01b2
            BaseRunFlag = 1;                                                              //06-12-12|0x01b2
            BaseState = 63393; // PREPARE_MESSAGE                                         //06-12-12|0x01b2
            break;                                                                        //06-12-12|0x01b2
          default:                                                                        //06-12-12|0x01b2
            BaseStatus = SystemError;                                                     //06-12-12|0x01b2
            BaseRunFlag = 0;                                                              //06-12-12|0x01b2
            SystemMsg;                                                                    //06-12-12|0x01b2
            break;                                                                        //06-12-12|0x01b2
        }                                                                                 //06-12-12|0x01b2
        break;                                                                            //06-12-12|0x01b2
//***************************************************************************             //06-12-12|0x01b3
//******                                                               ******             //06-12-12|0x01b4
//******  PERFORM THE TESTS                                            ******             //06-12-12|0x01b5
//******---------------------------------------------------------------******             //06-12-12|0x01b6
//******  Prepare Test Step                                            ******             //06-12-12|0x01b7
//******                                                               ******             //06-12-12|0x01b8
//***************************************************************************             //06-12-12|0x01b9
      case 63393: // PREPARE_MESSAGE                                                      //06-12-12|0x01ba
        switch(PrepareStepMessage)                                                        //06-12-12|0x01ba
        {                                                                                 //06-12-12|0x01ba
          case Success:                                                                   //06-12-12|0x01ba
            BaseState = 29232; // PREPARE_PUSH                                            //06-12-12|0x01ba
            BaseStatus = Display;                                                         //06-12-12|0x01ba
            BaseRunFlag = 0;                                                              //06-12-12|0x01ba
            break;                                                                        //06-12-12|0x01ba
          default:                                                                        //06-12-12|0x01ba
            BaseStatus = SystemError;                                                     //06-12-12|0x01ba
            BaseRunFlag = 0;                                                              //06-12-12|0x01ba
            SystemMsg;                                                                    //06-12-12|0x01ba
            break;                                                                        //06-12-12|0x01ba
        }                                                                                 //06-12-12|0x01ba
        break;                                                                            //06-12-12|0x01ba
//***************************************************************************             //06-12-12|0x01bb
      case 29232: // PREPARE_PUSH                                                         //06-12-12|0x01bc
        switch(pcg_push(DataPrepareAddr))                                                 //06-12-12|0x01bc
        {                                                                                 //06-12-12|0x01bc
          case Success:                                                                   //06-12-12|0x01bc
            BaseRunFlag = 1;                                                              //06-12-12|0x01bc
            BaseState = 38319; // PREPARE_PCG                                             //06-12-12|0x01bc
            break;                                                                        //06-12-12|0x01bc
          default:                                                                        //06-12-12|0x01bc
            BaseStatus = SystemError;                                                     //06-12-12|0x01bc
            BaseRunFlag = 0;                                                              //06-12-12|0x01bc
            SystemMsg;                                                                    //06-12-12|0x01bc
            break;                                                                        //06-12-12|0x01bc
        }                                                                                 //06-12-12|0x01bc
        break;                                                                            //06-12-12|0x01bc
//***************************************************************************             //06-12-12|0x01bd
      case 38319: // PREPARE_PCG                                                          //06-12-12|0x01be
        switch(TestProject(DataPrepareAddr))                                              //06-12-12|0x01be
        {                                                                                 //06-12-12|0x01be
          case Display:                                                                   //06-12-12|0x01be
            BaseState = 61726; // PREPARE_PCG_EXIT                                        //06-12-12|0x01be
            BaseStatus = Display;                                                         //06-12-12|0x01be
            BaseRunFlag = 0;                                                              //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case KeyBoard:                                                                  //06-12-12|0x01be
            BaseState = 61726; // PREPARE_PCG_EXIT                                        //06-12-12|0x01be
            BaseStatus = KeyBoard;                                                        //06-12-12|0x01be
            BaseRunFlag = 0;                                                              //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case Success:                                                                   //06-12-12|0x01be
            BaseRunFlag = 1;                                                              //06-12-12|0x01be
            BaseState = 893; // PREPARE_POP                                               //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case BuildError:                                                                //06-12-12|0x01be
            BaseRunFlag = 1;                                                              //06-12-12|0x01be
            BaseState = 15308; // USR_POP                                                 //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case UserError:                                                                 //06-12-12|0x01be
            BaseRunFlag = 1;                                                              //06-12-12|0x01be
            BaseState = 15308; // USR_POP                                                 //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          default:                                                                        //06-12-12|0x01be
            BaseStatus = SystemError;                                                     //06-12-12|0x01be
            BaseRunFlag = 0;                                                              //06-12-12|0x01be
            SystemMsg;                                                                    //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
        }                                                                                 //06-12-12|0x01be
        break;                                                                            //06-12-12|0x01be
//**************************************************************************              //06-12-12|0x01be
      case 61726: // PREPARE_PCG_EXIT                                                     //06-12-12|0x01be
        switch(TestProject(DataPrepareAddr))                                              //06-12-12|0x01be
        {                                                                                 //06-12-12|0x01be
          case Display:                                                                   //06-12-12|0x01be
            BaseState = 61726; // PREPARE_PCG_EXIT                                        //06-12-12|0x01be
            BaseStatus = Display;                                                         //06-12-12|0x01be
            BaseRunFlag = 0;                                                              //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case KeyBoard:                                                                  //06-12-12|0x01be
            BaseState = 61726; // PREPARE_PCG_EXIT                                        //06-12-12|0x01be
            BaseStatus = KeyBoard;                                                        //06-12-12|0x01be
            BaseRunFlag = 0;                                                              //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case Success:                                                                   //06-12-12|0x01be
            BaseRunFlag = 1;                                                              //06-12-12|0x01be
            BaseState = 893; // PREPARE_POP                                               //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case BuildError:                                                                //06-12-12|0x01be
            BaseRunFlag = 1;                                                              //06-12-12|0x01be
            BaseState = 15308; // USR_POP                                                 //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          case UserError:                                                                 //06-12-12|0x01be
            BaseRunFlag = 1;                                                              //06-12-12|0x01be
            BaseState = 15308; // USR_POP                                                 //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
          default:                                                                        //06-12-12|0x01be
            BaseStatus = SystemError;                                                     //06-12-12|0x01be
            BaseRunFlag = 0;                                                              //06-12-12|0x01be
            SystemMsg;                                                                    //06-12-12|0x01be
            break;                                                                        //06-12-12|0x01be
        }                                                                                 //06-12-12|0x01be
        break;                                                                            //06-12-12|0x01be
//***************************************************************************             //06-12-12|0x01bf
      case 893: // PREPARE_POP                                                            //06-12-12|0x01c0
        switch(CallPrePop())                                                              //06-12-12|0x01c0
        {                                                                                 //06-12-12|0x01c0
          case Success:                                                                   //06-12-12|0x01c0
            BaseRunFlag = 1;                                                              //06-12-12|0x01c0
            BaseState = 63755; // PREPARE_PAUSE                                           //06-12-12|0x01c0
            break;                                                                        //06-12-12|0x01c0
          default:                                                                        //06-12-12|0x01c0
            BaseStatus = SystemError;                                                     //06-12-12|0x01c0
            BaseRunFlag = 0;                                                              //06-12-12|0x01c0
            SystemMsg;                                                                    //06-12-12|0x01c0
            break;                                                                        //06-12-12|0x01c0
        }                                                                                 //06-12-12|0x01c0
        break;                                                                            //06-12-12|0x01c0
//***************************************************************************             //06-12-12|0x01c1
      case 63755: // PREPARE_PAUSE                                                        //06-12-12|0x01c2
        switch(DebugPause)                                                                //06-12-12|0x01c2
        {                                                                                 //06-12-12|0x01c2
          case Display:                                                                   //06-12-12|0x01c2
            BaseState = 35386; // PREPARE_PAUSE_EXIT                                      //06-12-12|0x01c2
            BaseStatus = Display;                                                         //06-12-12|0x01c2
            BaseRunFlag = 0;                                                              //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case KeyBoard:                                                                  //06-12-12|0x01c2
            BaseState = 35386; // PREPARE_PAUSE_EXIT                                      //06-12-12|0x01c2
            BaseStatus = KeyBoard;                                                        //06-12-12|0x01c2
            BaseRunFlag = 0;                                                              //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case Continue:                                                                  //06-12-12|0x01c2
            BaseRunFlag = 1;                                                              //06-12-12|0x01c2
            BaseState = 63755; // PREPARE_PAUSE                                           //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case Success:                                                                   //06-12-12|0x01c2
            BaseRunFlag = 1;                                                              //06-12-12|0x01c2
            BaseState = 11865; // BUILD_TEST                                              //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case UserError:                                                                 //06-12-12|0x01c2
            BaseRunFlag = 1;                                                              //06-12-12|0x01c2
            BaseState = 55081; // USER                                                    //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          default:                                                                        //06-12-12|0x01c2
            BaseStatus = SystemError;                                                     //06-12-12|0x01c2
            BaseRunFlag = 0;                                                              //06-12-12|0x01c2
            SystemMsg;                                                                    //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
        }                                                                                 //06-12-12|0x01c2
        break;                                                                            //06-12-12|0x01c2
//**************************************************************************              //06-12-12|0x01c2
      case 35386: // PREPARE_PAUSE_EXIT                                                   //06-12-12|0x01c2
        switch(DebugPause)                                                                //06-12-12|0x01c2
        {                                                                                 //06-12-12|0x01c2
          case Display:                                                                   //06-12-12|0x01c2
            BaseState = 35386; // PREPARE_PAUSE_EXIT                                      //06-12-12|0x01c2
            BaseStatus = Display;                                                         //06-12-12|0x01c2
            BaseRunFlag = 0;                                                              //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case KeyBoard:                                                                  //06-12-12|0x01c2
            BaseState = 35386; // PREPARE_PAUSE_EXIT                                      //06-12-12|0x01c2
            BaseStatus = KeyBoard;                                                        //06-12-12|0x01c2
            BaseRunFlag = 0;                                                              //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case Continue:                                                                  //06-12-12|0x01c2
            BaseRunFlag = 1;                                                              //06-12-12|0x01c2
            BaseState = 63755; // PREPARE_PAUSE                                           //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case Success:                                                                   //06-12-12|0x01c2
            BaseRunFlag = 1;                                                              //06-12-12|0x01c2
            BaseState = 11865; // BUILD_TEST                                              //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          case UserError:                                                                 //06-12-12|0x01c2
            BaseRunFlag = 1;                                                              //06-12-12|0x01c2
            BaseState = 55081; // USER                                                    //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
          default:                                                                        //06-12-12|0x01c2
            BaseStatus = SystemError;                                                     //06-12-12|0x01c2
            BaseRunFlag = 0;                                                              //06-12-12|0x01c2
            SystemMsg;                                                                    //06-12-12|0x01c2
            break;                                                                        //06-12-12|0x01c2
        }                                                                                 //06-12-12|0x01c2
        break;                                                                            //06-12-12|0x01c2
//***************************************************************************             //06-12-12|0x01c3
//******                                                               ******             //06-12-12|0x01c4
//******  PERFORM THE TESTS                                            ******             //06-12-12|0x01c5
//******---------------------------------------------------------------******             //06-12-12|0x01c6
//******  Build Test Step                                              ******             //06-12-12|0x01c7
//******                                                               ******             //06-12-12|0x01c8
//***************************************************************************             //06-12-12|0x01c9
      case 11865: // BUILD_TEST                                                           //09-01-03|0x01ca
        switch(BuildStepExists)                                                           //09-01-03|0x01ca
        {                                                                                 //09-01-03|0x01ca
          case Yes:                                                                       //09-01-03|0x01ca
            BaseRunFlag = 1;                                                              //09-01-03|0x01ca
            BaseState = 5224; // BUILD_MESSAGE                                            //09-01-03|0x01ca
            break;                                                                        //09-01-03|0x01ca
          case No:                                                                        //09-01-03|0x01ca
            BaseRunFlag = 1;                                                              //09-01-03|0x01ca
            BaseState = 23399; // MAKE_TEST                                               //09-01-03|0x01ca
            break;                                                                        //09-01-03|0x01ca
          default:                                                                        //09-01-03|0x01ca
            BaseStatus = SystemError;                                                     //09-01-03|0x01ca
            BaseRunFlag = 0;                                                              //09-01-03|0x01ca
            SystemMsg;                                                                    //09-01-03|0x01ca
            break;                                                                        //09-01-03|0x01ca
        }                                                                                 //09-01-03|0x01ca
        break;                                                                            //09-01-03|0x01ca
//***************************************************************************             //06-12-15|0x01cb
      case 5224: // BUILD_MESSAGE                                                         //06-12-15|0x01cc
        switch(BuildStepMessage)                                                          //06-12-15|0x01cc
        {                                                                                 //06-12-15|0x01cc
          case Success:                                                                   //06-12-15|0x01cc
            BaseState = 4694; // BUILD_PUSH                                               //06-12-15|0x01cc
            BaseStatus = Display;                                                         //06-12-15|0x01cc
            BaseRunFlag = 0;                                                              //06-12-15|0x01cc
            break;                                                                        //06-12-15|0x01cc
          default:                                                                        //06-12-15|0x01cc
            BaseStatus = SystemError;                                                     //06-12-15|0x01cc
            BaseRunFlag = 0;                                                              //06-12-15|0x01cc
            SystemMsg;                                                                    //06-12-15|0x01cc
            break;                                                                        //06-12-15|0x01cc
        }                                                                                 //06-12-15|0x01cc
        break;                                                                            //06-12-15|0x01cc
//***************************************************************************             //06-12-15|0x01cd
      case 4694: // BUILD_PUSH                                                            //06-12-15|0x01ce
        switch(pcg_push(DataBuildAddr))                                                   //06-12-15|0x01ce
        {                                                                                 //06-12-15|0x01ce
          case Success:                                                                   //06-12-15|0x01ce
            BaseRunFlag = 1;                                                              //06-12-15|0x01ce
            BaseState = 14389; // BUILD_PCG                                               //06-12-15|0x01ce
            break;                                                                        //06-12-15|0x01ce
          default:                                                                        //06-12-15|0x01ce
            BaseStatus = SystemError;                                                     //06-12-15|0x01ce
            BaseRunFlag = 0;                                                              //06-12-15|0x01ce
            SystemMsg;                                                                    //06-12-15|0x01ce
            break;                                                                        //06-12-15|0x01ce
        }                                                                                 //06-12-15|0x01ce
        break;                                                                            //06-12-15|0x01ce
//***************************************************************************             //06-12-15|0x01cf
      case 14389: // BUILD_PCG                                                            //06-12-15|0x01d0
        switch(TestProject(DataBuildAddr))                                                //06-12-15|0x01d0
        {                                                                                 //06-12-15|0x01d0
          case Display:                                                                   //06-12-15|0x01d0
            BaseState = 48132; // BUILD_PCG_EXIT                                          //06-12-15|0x01d0
            BaseStatus = Display;                                                         //06-12-15|0x01d0
            BaseRunFlag = 0;                                                              //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case KeyBoard:                                                                  //06-12-15|0x01d0
            BaseState = 48132; // BUILD_PCG_EXIT                                          //06-12-15|0x01d0
            BaseStatus = KeyBoard;                                                        //06-12-15|0x01d0
            BaseRunFlag = 0;                                                              //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case Success:                                                                   //06-12-15|0x01d0
            BaseRunFlag = 1;                                                              //06-12-15|0x01d0
            BaseState = 31939; // BUILD_POP                                               //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case BuildError:                                                                //06-12-15|0x01d0
            BaseRunFlag = 1;                                                              //06-12-15|0x01d0
            BaseState = 18802; // ERR_MSG                                                 //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case UserError:                                                                 //06-12-15|0x01d0
            BaseRunFlag = 1;                                                              //06-12-15|0x01d0
            BaseState = 15308; // USR_POP                                                 //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          default:                                                                        //06-12-15|0x01d0
            BaseStatus = SystemError;                                                     //06-12-15|0x01d0
            BaseRunFlag = 0;                                                              //06-12-15|0x01d0
            SystemMsg;                                                                    //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
        }                                                                                 //06-12-15|0x01d0
        break;                                                                            //06-12-15|0x01d0
//**************************************************************************              //06-12-15|0x01d0
      case 48132: // BUILD_PCG_EXIT                                                       //06-12-15|0x01d0
        switch(TestProject(DataBuildAddr))                                                //06-12-15|0x01d0
        {                                                                                 //06-12-15|0x01d0
          case Display:                                                                   //06-12-15|0x01d0
            BaseState = 48132; // BUILD_PCG_EXIT                                          //06-12-15|0x01d0
            BaseStatus = Display;                                                         //06-12-15|0x01d0
            BaseRunFlag = 0;                                                              //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case KeyBoard:                                                                  //06-12-15|0x01d0
            BaseState = 48132; // BUILD_PCG_EXIT                                          //06-12-15|0x01d0
            BaseStatus = KeyBoard;                                                        //06-12-15|0x01d0
            BaseRunFlag = 0;                                                              //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case Success:                                                                   //06-12-15|0x01d0
            BaseRunFlag = 1;                                                              //06-12-15|0x01d0
            BaseState = 31939; // BUILD_POP                                               //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case BuildError:                                                                //06-12-15|0x01d0
            BaseRunFlag = 1;                                                              //06-12-15|0x01d0
            BaseState = 18802; // ERR_MSG                                                 //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          case UserError:                                                                 //06-12-15|0x01d0
            BaseRunFlag = 1;                                                              //06-12-15|0x01d0
            BaseState = 15308; // USR_POP                                                 //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
          default:                                                                        //06-12-15|0x01d0
            BaseStatus = SystemError;                                                     //06-12-15|0x01d0
            BaseRunFlag = 0;                                                              //06-12-15|0x01d0
            SystemMsg;                                                                    //06-12-15|0x01d0
            break;                                                                        //06-12-15|0x01d0
        }                                                                                 //06-12-15|0x01d0
        break;                                                                            //06-12-15|0x01d0
//***************************************************************************             //06-12-15|0x01d1
      case 18802: // ERR_MSG                                                              //06-12-15|0x01d2
        BaseState = 57617; // ERR_POP                                                     //06-12-15|0x01d2
        BaseStatus = Display;                                                             //06-12-15|0x01d2
        BaseRunFlag = 0;                                                                  //06-12-15|0x01d2
        break;                                                                            //06-12-15|0x01d2
//***************************************************************************             //06-12-15|0x01d3
      case 31939: // BUILD_POP                                                            //06-12-16|0x01d4
        switch(CallPrePop())                                                              //06-12-16|0x01d4
        {                                                                                 //06-12-16|0x01d4
          case Success:                                                                   //06-12-16|0x01d4
            BaseRunFlag = 1;                                                              //06-12-16|0x01d4
            BaseState = 62112; // BUILD_PAUSE                                             //06-12-16|0x01d4
            break;                                                                        //06-12-16|0x01d4
          default:                                                                        //06-12-16|0x01d4
            BaseStatus = SystemError;                                                     //06-12-16|0x01d4
            BaseRunFlag = 0;                                                              //06-12-16|0x01d4
            SystemMsg;                                                                    //06-12-16|0x01d4
            break;                                                                        //06-12-16|0x01d4
        }                                                                                 //06-12-16|0x01d4
        break;                                                                            //06-12-16|0x01d4
//---------------------------------------------------------------------------             //06-12-15|0x01d5
      case 57617: // ERR_POP                                                              //06-12-15|0x01d6
        switch(CallPrePop())                                                              //06-12-15|0x01d6
        {                                                                                 //06-12-15|0x01d6
          case Success:                                                                   //06-12-15|0x01d6
            BaseRunFlag = 1;                                                              //06-12-15|0x01d6
            BaseState = 7455; // MAKE_ERR_REC                                             //06-12-15|0x01d6
            break;                                                                        //06-12-15|0x01d6
          default:                                                                        //06-12-15|0x01d6
            BaseStatus = SystemError;                                                     //06-12-15|0x01d6
            BaseRunFlag = 0;                                                              //06-12-15|0x01d6
            SystemMsg;                                                                    //06-12-15|0x01d6
            break;                                                                        //06-12-15|0x01d6
        }                                                                                 //06-12-15|0x01d6
        break;                                                                            //06-12-15|0x01d6
//***************************************************************************             //06-12-16|0x01d7
      case 62112: // BUILD_PAUSE                                                          //06-12-16|0x01d8
        switch(DebugPause)                                                                //06-12-16|0x01d8
        {                                                                                 //06-12-16|0x01d8
          case Display:                                                                   //06-12-16|0x01d8
            BaseState = 61326; // BUILD_PAUSE_EXIT                                        //06-12-16|0x01d8
            BaseStatus = Display;                                                         //06-12-16|0x01d8
            BaseRunFlag = 0;                                                              //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case KeyBoard:                                                                  //06-12-16|0x01d8
            BaseState = 61326; // BUILD_PAUSE_EXIT                                        //06-12-16|0x01d8
            BaseStatus = KeyBoard;                                                        //06-12-16|0x01d8
            BaseRunFlag = 0;                                                              //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case Continue:                                                                  //06-12-16|0x01d8
            BaseRunFlag = 1;                                                              //06-12-16|0x01d8
            BaseState = 62112; // BUILD_PAUSE                                             //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case Success:                                                                   //06-12-16|0x01d8
            BaseRunFlag = 1;                                                              //06-12-16|0x01d8
            BaseState = 59629; // BUILD_MAKE_TEST                                         //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case UserError:                                                                 //06-12-16|0x01d8
            BaseRunFlag = 1;                                                              //06-12-16|0x01d8
            BaseState = 55081; // USER                                                    //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          default:                                                                        //06-12-16|0x01d8
            BaseStatus = SystemError;                                                     //06-12-16|0x01d8
            BaseRunFlag = 0;                                                              //06-12-16|0x01d8
            SystemMsg;                                                                    //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
        }                                                                                 //06-12-16|0x01d8
        break;                                                                            //06-12-16|0x01d8
//**************************************************************************              //06-12-16|0x01d8
      case 61326: // BUILD_PAUSE_EXIT                                                     //06-12-16|0x01d8
        switch(DebugPause)                                                                //06-12-16|0x01d8
        {                                                                                 //06-12-16|0x01d8
          case Display:                                                                   //06-12-16|0x01d8
            BaseState = 61326; // BUILD_PAUSE_EXIT                                        //06-12-16|0x01d8
            BaseStatus = Display;                                                         //06-12-16|0x01d8
            BaseRunFlag = 0;                                                              //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case KeyBoard:                                                                  //06-12-16|0x01d8
            BaseState = 61326; // BUILD_PAUSE_EXIT                                        //06-12-16|0x01d8
            BaseStatus = KeyBoard;                                                        //06-12-16|0x01d8
            BaseRunFlag = 0;                                                              //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case Continue:                                                                  //06-12-16|0x01d8
            BaseRunFlag = 1;                                                              //06-12-16|0x01d8
            BaseState = 62112; // BUILD_PAUSE                                             //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case Success:                                                                   //06-12-16|0x01d8
            BaseRunFlag = 1;                                                              //06-12-16|0x01d8
            BaseState = 59629; // BUILD_MAKE_TEST                                         //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          case UserError:                                                                 //06-12-16|0x01d8
            BaseRunFlag = 1;                                                              //06-12-16|0x01d8
            BaseState = 55081; // USER                                                    //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
          default:                                                                        //06-12-16|0x01d8
            BaseStatus = SystemError;                                                     //06-12-16|0x01d8
            BaseRunFlag = 0;                                                              //06-12-16|0x01d8
            SystemMsg;                                                                    //06-12-16|0x01d8
            break;                                                                        //06-12-16|0x01d8
        }                                                                                 //06-12-16|0x01d8
        break;                                                                            //06-12-16|0x01d8
//***************************************************************************             //06-12-16|0x01d9
//******                                                               ******             //06-12-16|0x01da
//******  PERFORM THE TESTS                                            ******             //06-12-16|0x01db
//******---------------------------------------------------------------******             //06-12-16|0x01dc
//******  Make Test Step                                               ******             //06-12-16|0x01dd
//******                                                               ******             //06-12-16|0x01de
//***************************************************************************             //06-12-16|0x01df
      case 23399: // MAKE_TEST                                                            //09-01-03|0x01e0
        switch(MakeStepExists)                                                            //09-01-03|0x01e0
        {                                                                                 //09-01-03|0x01e0
          case Yes:                                                                       //09-01-03|0x01e0
            BaseRunFlag = 1;                                                              //09-01-03|0x01e0
            BaseState = 30780; // MAKE_MESSAGE                                            //09-01-03|0x01e0
            break;                                                                        //09-01-03|0x01e0
          case No:                                                                        //09-01-03|0x01e0
            BaseRunFlag = 1;                                                              //09-01-03|0x01e0
            BaseState = 64635; // RUN_TEST                                                //09-01-03|0x01e0
            break;                                                                        //09-01-03|0x01e0
          default:                                                                        //09-01-03|0x01e0
            BaseStatus = SystemError;                                                     //09-01-03|0x01e0
            BaseRunFlag = 0;                                                              //09-01-03|0x01e0
            SystemMsg;                                                                    //09-01-03|0x01e0
            break;                                                                        //09-01-03|0x01e0
        }                                                                                 //09-01-03|0x01e0
        break;                                                                            //09-01-03|0x01e0
//---------------------------------------------------------------------------             //09-01-03|0x01e1
      case 59629: // BUILD_MAKE_TEST                                                      //09-01-03|0x01e2
        switch(MakeStepExists)                                                            //09-01-03|0x01e2
        {                                                                                 //09-01-03|0x01e2
          case Yes:                                                                       //09-01-03|0x01e2
            BaseRunFlag = 1;                                                              //09-01-03|0x01e2
            BaseState = 30780; // MAKE_MESSAGE                                            //09-01-03|0x01e2
            break;                                                                        //09-01-03|0x01e2
          case No:                                                                        //09-01-03|0x01e2
            BaseRunFlag = 1;                                                              //09-01-03|0x01e2
            BaseState = 50346; // BUILD_RUN_TEST                                          //09-01-03|0x01e2
            break;                                                                        //09-01-03|0x01e2
          default:                                                                        //09-01-03|0x01e2
            BaseStatus = SystemError;                                                     //09-01-03|0x01e2
            BaseRunFlag = 0;                                                              //09-01-03|0x01e2
            SystemMsg;                                                                    //09-01-03|0x01e2
            break;                                                                        //09-01-03|0x01e2
        }                                                                                 //09-01-03|0x01e2
        break;                                                                            //09-01-03|0x01e2
//***************************************************************************             //06-12-16|0x01e3
      case 30780: // MAKE_MESSAGE                                                         //06-12-16|0x01e4
        switch(MakeStepMessage)                                                           //06-12-16|0x01e4
        {                                                                                 //06-12-16|0x01e4
          case Success:                                                                   //06-12-16|0x01e4
            BaseState = 4041; // MAKE_SPAWN                                               //06-12-16|0x01e4
            BaseStatus = Display;                                                         //06-12-16|0x01e4
            BaseRunFlag = 0;                                                              //06-12-16|0x01e4
            break;                                                                        //06-12-16|0x01e4
          default:                                                                        //06-12-16|0x01e4
            BaseStatus = SystemError;                                                     //06-12-16|0x01e4
            BaseRunFlag = 0;                                                              //06-12-16|0x01e4
            SystemMsg;                                                                    //06-12-16|0x01e4
            break;                                                                        //06-12-16|0x01e4
        }                                                                                 //06-12-16|0x01e4
        break;                                                                            //06-12-16|0x01e4
//***************************************************************************             //06-12-16|0x01e5
      case 4041: // MAKE_SPAWN                                                            //06-12-16|0x01e6
        switch(make_step())                                                               //06-12-16|0x01e6
        {                                                                                 //06-12-16|0x01e6
          case Yes:                                                                       //06-12-16|0x01e6
            BaseRunFlag = 1;                                                              //06-12-16|0x01e6
            BaseState = 3288; // MAKE_PAUSE                                               //06-12-16|0x01e6
            break;                                                                        //06-12-16|0x01e6
          case No:                                                                        //06-12-16|0x01e6
            BaseRunFlag = 1;                                                              //06-12-16|0x01e6
            BaseState = 7455; // MAKE_ERR_REC                                             //06-12-16|0x01e6
            break;                                                                        //06-12-16|0x01e6
          case UserError:                                                                 //06-12-16|0x01e6
            BaseRunFlag = 1;                                                              //06-12-16|0x01e6
            BaseState = 55081; // USER                                                    //06-12-16|0x01e6
            break;                                                                        //06-12-16|0x01e6
          default:                                                                        //06-12-16|0x01e6
            BaseStatus = SystemError;                                                     //06-12-16|0x01e6
            BaseRunFlag = 0;                                                              //06-12-16|0x01e6
            SystemMsg;                                                                    //06-12-16|0x01e6
            break;                                                                        //06-12-16|0x01e6
        }                                                                                 //06-12-16|0x01e6
        break;                                                                            //06-12-16|0x01e6
//***************************************************************************             //06-12-16|0x01e7
      case 3288: // MAKE_PAUSE                                                            //09-01-03|0x01e8
        switch(DebugPause)                                                                //09-01-03|0x01e8
        {                                                                                 //09-01-03|0x01e8
          case Display:                                                                   //09-01-03|0x01e8
            BaseState = 56023; // MAKE_PAUSE_EXIT                                         //09-01-03|0x01e8
            BaseStatus = Display;                                                         //09-01-03|0x01e8
            BaseRunFlag = 0;                                                              //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case KeyBoard:                                                                  //09-01-03|0x01e8
            BaseState = 56023; // MAKE_PAUSE_EXIT                                         //09-01-03|0x01e8
            BaseStatus = KeyBoard;                                                        //09-01-03|0x01e8
            BaseRunFlag = 0;                                                              //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case Continue:                                                                  //09-01-03|0x01e8
            BaseRunFlag = 1;                                                              //09-01-03|0x01e8
            BaseState = 3288; // MAKE_PAUSE                                               //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case Success:                                                                   //09-01-03|0x01e8
            BaseRunFlag = 1;                                                              //09-01-03|0x01e8
            BaseState = 35014; // MAKE_RUN_TEST                                           //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case UserError:                                                                 //09-01-03|0x01e8
            BaseRunFlag = 1;                                                              //09-01-03|0x01e8
            BaseState = 55081; // USER                                                    //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          default:                                                                        //09-01-03|0x01e8
            BaseStatus = SystemError;                                                     //09-01-03|0x01e8
            BaseRunFlag = 0;                                                              //09-01-03|0x01e8
            SystemMsg;                                                                    //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
        }                                                                                 //09-01-03|0x01e8
        break;                                                                            //09-01-03|0x01e8
//**************************************************************************              //09-01-03|0x01e8
      case 56023: // MAKE_PAUSE_EXIT                                                      //09-01-03|0x01e8
        switch(DebugPause)                                                                //09-01-03|0x01e8
        {                                                                                 //09-01-03|0x01e8
          case Display:                                                                   //09-01-03|0x01e8
            BaseState = 56023; // MAKE_PAUSE_EXIT                                         //09-01-03|0x01e8
            BaseStatus = Display;                                                         //09-01-03|0x01e8
            BaseRunFlag = 0;                                                              //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case KeyBoard:                                                                  //09-01-03|0x01e8
            BaseState = 56023; // MAKE_PAUSE_EXIT                                         //09-01-03|0x01e8
            BaseStatus = KeyBoard;                                                        //09-01-03|0x01e8
            BaseRunFlag = 0;                                                              //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case Continue:                                                                  //09-01-03|0x01e8
            BaseRunFlag = 1;                                                              //09-01-03|0x01e8
            BaseState = 3288; // MAKE_PAUSE                                               //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case Success:                                                                   //09-01-03|0x01e8
            BaseRunFlag = 1;                                                              //09-01-03|0x01e8
            BaseState = 35014; // MAKE_RUN_TEST                                           //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          case UserError:                                                                 //09-01-03|0x01e8
            BaseRunFlag = 1;                                                              //09-01-03|0x01e8
            BaseState = 55081; // USER                                                    //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
          default:                                                                        //09-01-03|0x01e8
            BaseStatus = SystemError;                                                     //09-01-03|0x01e8
            BaseRunFlag = 0;                                                              //09-01-03|0x01e8
            SystemMsg;                                                                    //09-01-03|0x01e8
            break;                                                                        //09-01-03|0x01e8
        }                                                                                 //09-01-03|0x01e8
        break;                                                                            //09-01-03|0x01e8
//***************************************************************************             //06-12-16|0x01e9
//******                                                               ******             //06-12-16|0x01ea
//******  PERFORM THE TESTS                                            ******             //06-12-16|0x01eb
//******---------------------------------------------------------------******             //06-12-16|0x01ec
//******  Run Test Step                                                ******             //06-12-16|0x01ed
//******                                                               ******             //06-12-16|0x01ee
//***************************************************************************             //06-12-16|0x01ef
      case 64635: // RUN_TEST                                                             //06-12-16|0x01f0
        switch(RunStepExists)                                                             //06-12-16|0x01f0
        {                                                                                 //06-12-16|0x01f0
          case Yes:                                                                       //06-12-16|0x01f0
            BaseRunFlag = 1;                                                              //06-12-16|0x01f0
            BaseState = 5541; // RUN_PERMIT                                               //06-12-16|0x01f0
            break;                                                                        //06-12-16|0x01f0
          case No:                                                                        //06-12-16|0x01f0
            BaseRunFlag = 1;                                                              //06-12-16|0x01f0
            BaseState = 28788; // OK                                                      //06-12-16|0x01f0
            break;                                                                        //06-12-16|0x01f0
          default:                                                                        //06-12-16|0x01f0
            BaseStatus = SystemError;                                                     //06-12-16|0x01f0
            BaseRunFlag = 0;                                                              //06-12-16|0x01f0
            SystemMsg;                                                                    //06-12-16|0x01f0
            break;                                                                        //06-12-16|0x01f0
        }                                                                                 //06-12-16|0x01f0
        break;                                                                            //06-12-16|0x01f0
//---------------------------------------------------------------------------             //09-01-03|0x01f1
      case 50346: // BUILD_RUN_TEST                                                       //09-01-03|0x01f2
        switch(RunStepExists)                                                             //09-01-03|0x01f2
        {                                                                                 //09-01-03|0x01f2
          case Yes:                                                                       //09-01-03|0x01f2
            BaseRunFlag = 1;                                                              //09-01-03|0x01f2
            BaseState = 30771; // BUILD_RUN_PERMIT                                        //09-01-03|0x01f2
            break;                                                                        //09-01-03|0x01f2
          case No:                                                                        //09-01-03|0x01f2
            BaseRunFlag = 1;                                                              //09-01-03|0x01f2
            BaseState = 64482; // MAKE_OK_REC                                             //09-01-03|0x01f2
            break;                                                                        //09-01-03|0x01f2
          default:                                                                        //09-01-03|0x01f2
            BaseStatus = SystemError;                                                     //09-01-03|0x01f2
            BaseRunFlag = 0;                                                              //09-01-03|0x01f2
            SystemMsg;                                                                    //09-01-03|0x01f2
            break;                                                                        //09-01-03|0x01f2
        }                                                                                 //09-01-03|0x01f2
        break;                                                                            //09-01-03|0x01f2
//---------------------------------------------------------------------------             //09-01-03|0x01f3
      case 35014: // MAKE_RUN_TEST                                                        //09-01-03|0x01f4
        switch(RunStepExists)                                                             //09-01-03|0x01f4
        {                                                                                 //09-01-03|0x01f4
          case Yes:                                                                       //09-01-03|0x01f4
            BaseRunFlag = 1;                                                              //09-01-03|0x01f4
            BaseState = 47745; // MAKE_RUN_PERMIT                                         //09-01-03|0x01f4
            break;                                                                        //09-01-03|0x01f4
          case No:                                                                        //09-01-03|0x01f4
            BaseRunFlag = 1;                                                              //09-01-03|0x01f4
            BaseState = 64482; // MAKE_OK_REC                                             //09-01-03|0x01f4
            break;                                                                        //09-01-03|0x01f4
          default:                                                                        //09-01-03|0x01f4
            BaseStatus = SystemError;                                                     //09-01-03|0x01f4
            BaseRunFlag = 0;                                                              //09-01-03|0x01f4
            SystemMsg;                                                                    //09-01-03|0x01f4
            break;                                                                        //09-01-03|0x01f4
        }                                                                                 //09-01-03|0x01f4
        break;                                                                            //09-01-03|0x01f4
//***************************************************************************             //06-12-16|0x01f5
      case 5541: // RUN_PERMIT                                                            //09-01-03|0x01f6
        switch(DataTypeFlag)                                                              //09-01-03|0x01f6
        {                                                                                 //09-01-03|0x01f6
          case 1:                                                                         //09-01-03|0x01f6
            BaseRunFlag = 1;                                                              //09-01-03|0x01f6
            BaseState = 25360; // RUN_MESSAGE                                             //09-01-03|0x01f6
            break;                                                                        //09-01-03|0x01f6
          case -1:                                                                        //09-01-03|0x01f6
            BaseRunFlag = 1;                                                              //09-01-03|0x01f6
            BaseState = 38031; // ILLEGAL_TEST                                            //09-01-03|0x01f6
            break;                                                                        //09-01-03|0x01f6
          case -2:                                                                        //09-01-03|0x01f6
            BaseRunFlag = 1;                                                              //09-01-03|0x01f6
            BaseState = 25360; // RUN_MESSAGE                                             //09-01-03|0x01f6
            break;                                                                        //09-01-03|0x01f6
          default:                                                                        //09-01-03|0x01f6
            BaseStatus = SystemError;                                                     //09-01-03|0x01f6
            BaseRunFlag = 0;                                                              //09-01-03|0x01f6
            SystemMsg;                                                                    //09-01-03|0x01f6
            break;                                                                        //09-01-03|0x01f6
        }                                                                                 //09-01-03|0x01f6
        break;                                                                            //09-01-03|0x01f6
//---------------------------------------------------------------------------             //09-01-03|0x01f7
      case 30771: // BUILD_RUN_PERMIT                                                     //09-01-03|0x01f8
        switch(DataTypeFlag)                                                              //09-01-03|0x01f8
        {                                                                                 //09-01-03|0x01f8
          case 1:                                                                         //09-01-03|0x01f8
            BaseRunFlag = 1;                                                              //09-01-03|0x01f8
            BaseState = 25360; // RUN_MESSAGE                                             //09-01-03|0x01f8
            break;                                                                        //09-01-03|0x01f8
          case -1:                                                                        //09-01-03|0x01f8
            BaseRunFlag = 1;                                                              //09-01-03|0x01f8
            BaseState = 56830; // OK_MAKE_ERR_MSG                                         //09-01-03|0x01f8
            break;                                                                        //09-01-03|0x01f8
          case -2:                                                                        //09-01-03|0x01f8
            BaseRunFlag = 1;                                                              //09-01-03|0x01f8
            BaseState = 25360; // RUN_MESSAGE                                             //09-01-03|0x01f8
            break;                                                                        //09-01-03|0x01f8
          default:                                                                        //09-01-03|0x01f8
            BaseStatus = SystemError;                                                     //09-01-03|0x01f8
            BaseRunFlag = 0;                                                              //09-01-03|0x01f8
            SystemMsg;                                                                    //09-01-03|0x01f8
            break;                                                                        //09-01-03|0x01f8
        }                                                                                 //09-01-03|0x01f8
        break;                                                                            //09-01-03|0x01f8
//---------------------------------------------------------------------------             //09-01-03|0x01f9
      case 47745: // MAKE_RUN_PERMIT                                                      //06-12-16|0x01fa
        switch(DataTypeFlag)                                                              //06-12-16|0x01fa
        {                                                                                 //06-12-16|0x01fa
          case 1:                                                                         //06-12-16|0x01fa
            BaseRunFlag = 1;                                                              //06-12-16|0x01fa
            BaseState = 25360; // RUN_MESSAGE                                             //06-12-16|0x01fa
            break;                                                                        //06-12-16|0x01fa
          case -1:                                                                        //06-12-16|0x01fa
            BaseRunFlag = 1;                                                              //06-12-16|0x01fa
            BaseState = 56830; // OK_MAKE_ERR_MSG                                         //06-12-16|0x01fa
            break;                                                                        //06-12-16|0x01fa
          case -2:                                                                        //06-12-16|0x01fa
            BaseRunFlag = 1;                                                              //06-12-16|0x01fa
            BaseState = 25360; // RUN_MESSAGE                                             //06-12-16|0x01fa
            break;                                                                        //06-12-16|0x01fa
          default:                                                                        //06-12-16|0x01fa
            BaseStatus = SystemError;                                                     //06-12-16|0x01fa
            BaseRunFlag = 0;                                                              //06-12-16|0x01fa
            SystemMsg;                                                                    //06-12-16|0x01fa
            break;                                                                        //06-12-16|0x01fa
        }                                                                                 //06-12-16|0x01fa
        break;                                                                            //06-12-16|0x01fa
//***************************************************************************             //06-12-16|0x01fb
      case 25360: // RUN_MESSAGE                                                          //06-12-16|0x01fc
        switch(RunStepMessage)                                                            //06-12-16|0x01fc
        {                                                                                 //06-12-16|0x01fc
          case Success:                                                                   //06-12-16|0x01fc
            BaseState = 48733; // RUN_SPAWN                                               //06-12-16|0x01fc
            BaseStatus = Display;                                                         //06-12-16|0x01fc
            BaseRunFlag = 0;                                                              //06-12-16|0x01fc
            break;                                                                        //06-12-16|0x01fc
          default:                                                                        //06-12-16|0x01fc
            BaseStatus = SystemError;                                                     //06-12-16|0x01fc
            BaseRunFlag = 0;                                                              //06-12-16|0x01fc
            SystemMsg;                                                                    //06-12-16|0x01fc
            break;                                                                        //06-12-16|0x01fc
        }                                                                                 //06-12-16|0x01fc
        break;                                                                            //06-12-16|0x01fc
//***************************************************************************             //06-12-16|0x01fd
      case 48733: // RUN_SPAWN                                                            //06-12-16|0x01fe
        switch(run_step())                                                                //06-12-16|0x01fe
        {                                                                                 //06-12-16|0x01fe
          case Yes:                                                                       //06-12-16|0x01fe
            BaseRunFlag = 1;                                                              //06-12-16|0x01fe
            BaseState = 42156; // RUN_OK_REC                                              //06-12-16|0x01fe
            break;                                                                        //06-12-16|0x01fe
          case No:                                                                        //06-12-16|0x01fe
            BaseRunFlag = 1;                                                              //06-12-16|0x01fe
            BaseState = 61419; // RUN_ERR_REC                                             //06-12-16|0x01fe
            break;                                                                        //06-12-16|0x01fe
          case UserError:                                                                 //06-12-16|0x01fe
            BaseRunFlag = 1;                                                              //06-12-16|0x01fe
            BaseState = 55081; // USER                                                    //06-12-16|0x01fe
            break;                                                                        //06-12-16|0x01fe
          default:                                                                        //06-12-16|0x01fe
            BaseStatus = SystemError;                                                     //06-12-16|0x01fe
            BaseRunFlag = 0;                                                              //06-12-16|0x01fe
            SystemMsg;                                                                    //06-12-16|0x01fe
            break;                                                                        //06-12-16|0x01fe
        }                                                                                 //06-12-16|0x01fe
        break;                                                                            //06-12-16|0x01fe
//***************************************************************************             //06-12-15|0x01ff
//******                                                               ******             //06-12-15|0x0200
//******  PERFORM THE TESTS                                            ******             //06-12-15|0x0201
//******---------------------------------------------------------------******             //06-12-15|0x0202
//******  Sort / Record Make Test Results                              ******             //06-12-15|0x0203
//******                                                               ******             //06-12-15|0x0204
//***************************************************************************             //06-12-15|0x0205
      case 64482: // MAKE_OK_REC                                                          //06-12-16|0x0206
        switch(RecordSuccess)                                                             //06-12-16|0x0206
        {                                                                                 //06-12-16|0x0206
          case Success:                                                                   //06-12-16|0x0206
            BaseRunFlag = 1;                                                              //06-12-16|0x0206
            BaseState = 61210; // MAKE_OK_END                                             //06-12-16|0x0206
            break;                                                                        //06-12-16|0x0206
          default:                                                                        //06-12-16|0x0206
            BaseStatus = SystemError;                                                     //06-12-16|0x0206
            BaseRunFlag = 0;                                                              //06-12-16|0x0206
            SystemMsg;                                                                    //06-12-16|0x0206
            break;                                                                        //06-12-16|0x0206
        }                                                                                 //06-12-16|0x0206
        break;                                                                            //06-12-16|0x0206
//---------------------------------------------------------------------------             //06-12-16|0x0207
      case 61210: // MAKE_OK_END                                                          //06-12-16|0x0208
        switch(DataTypeFlag)                                                              //06-12-16|0x0208
        {                                                                                 //06-12-16|0x0208
          case 1:                                                                         //06-12-16|0x0208
            BaseRunFlag = 1;                                                              //06-12-16|0x0208
            BaseState = 57657; // TEST_OK_MSG                                             //06-12-16|0x0208
            break;                                                                        //06-12-16|0x0208
          case -1:                                                                        //06-12-16|0x0208
            BaseRunFlag = 1;                                                              //06-12-16|0x0208
            BaseState = 62792; // MAKE_OK_ERR_MSG                                         //06-12-16|0x0208
            break;                                                                        //06-12-16|0x0208
          case -2:                                                                        //06-12-16|0x0208
            BaseRunFlag = 1;                                                              //06-12-16|0x0208
            BaseState = 19015; // SETUP_ERROR                                             //06-12-16|0x0208
            break;                                                                        //06-12-16|0x0208
          default:                                                                        //06-12-16|0x0208
            BaseStatus = SystemError;                                                     //06-12-16|0x0208
            BaseRunFlag = 0;                                                              //06-12-16|0x0208
            SystemMsg;                                                                    //06-12-16|0x0208
            break;                                                                        //06-12-16|0x0208
        }                                                                                 //06-12-16|0x0208
        break;                                                                            //06-12-16|0x0208
//***************************************************************************             //06-12-15|0x0209
      case 7455: // MAKE_ERR_REC                                                          //06-12-15|0x020a
        switch(RecordMake)                                                                //06-12-15|0x020a
        {                                                                                 //06-12-15|0x020a
          case Success:                                                                   //06-12-15|0x020a
            BaseRunFlag = 1;                                                              //06-12-15|0x020a
            BaseState = 61238; // MAKE_ERR_TST                                            //06-12-15|0x020a
            break;                                                                        //06-12-15|0x020a
          default:                                                                        //06-12-15|0x020a
            BaseStatus = SystemError;                                                     //06-12-15|0x020a
            BaseRunFlag = 0;                                                              //06-12-15|0x020a
            SystemMsg;                                                                    //06-12-15|0x020a
            break;                                                                        //06-12-15|0x020a
        }                                                                                 //06-12-15|0x020a
        break;                                                                            //06-12-15|0x020a
//---------------------------------------------------------------------------             //06-12-15|0x020b
      case 61238: // MAKE_ERR_TST                                                         //06-12-15|0x020c
        switch(DataTypeFlag)                                                              //06-12-15|0x020c
        {                                                                                 //06-12-15|0x020c
          case 1:                                                                         //06-12-15|0x020c
            BaseRunFlag = 1;                                                              //06-12-15|0x020c
            BaseState = 62792; // MAKE_OK_ERR_MSG                                         //06-12-15|0x020c
            break;                                                                        //06-12-15|0x020c
          case -1:                                                                        //06-12-15|0x020c
            BaseRunFlag = 1;                                                              //06-12-15|0x020c
            BaseState = 58133; // MAKE_OK_MSG                                             //06-12-15|0x020c
            break;                                                                        //06-12-15|0x020c
          case -2:                                                                        //06-12-15|0x020c
            BaseRunFlag = 1;                                                              //06-12-15|0x020c
            BaseState = 62792; // MAKE_OK_ERR_MSG                                         //06-12-15|0x020c
            break;                                                                        //06-12-15|0x020c
          default:                                                                        //06-12-15|0x020c
            BaseStatus = SystemError;                                                     //06-12-15|0x020c
            BaseRunFlag = 0;                                                              //06-12-15|0x020c
            SystemMsg;                                                                    //06-12-15|0x020c
            break;                                                                        //06-12-15|0x020c
        }                                                                                 //06-12-15|0x020c
        break;                                                                            //06-12-15|0x020c
//***************************************************************************             //06-12-15|0x020d
      case 19015: // SETUP_ERROR                                                          //06-12-16|0x020e
        switch(SetupRunError)                                                             //06-12-16|0x020e
        {                                                                                 //06-12-16|0x020e
          case UserError:                                                                 //06-12-16|0x020e
            BaseRunFlag = 1;                                                              //06-12-16|0x020e
            BaseState = 55081; // USER                                                    //06-12-16|0x020e
            break;                                                                        //06-12-16|0x020e
          default:                                                                        //06-12-16|0x020e
            BaseStatus = SystemError;                                                     //06-12-16|0x020e
            BaseRunFlag = 0;                                                              //06-12-16|0x020e
            SystemMsg;                                                                    //06-12-16|0x020e
            break;                                                                        //06-12-16|0x020e
        }                                                                                 //06-12-16|0x020e
        break;                                                                            //06-12-16|0x020e
//***************************************************************************             //06-12-16|0x020f
//******                                                               ******             //06-12-16|0x0210
//******  RECORD - DISPLAY TEST RESULTS                                ******             //06-12-16|0x0211
//******---------------------------------------------------------------******             //06-12-16|0x0212
//******  Sort / Record Run Test Results                               ******             //06-12-16|0x0213
//******                                                               ******             //06-12-16|0x0214
//***************************************************************************             //06-12-16|0x0215
      case 42156: // RUN_OK_REC                                                           //06-12-16|0x0216
        switch(RecordSuccess)                                                             //06-12-16|0x0216
        {                                                                                 //06-12-16|0x0216
          case Success:                                                                   //06-12-16|0x0216
            BaseRunFlag = 1;                                                              //06-12-16|0x0216
            BaseState = 5348; // RUN_OK_TEST                                              //06-12-16|0x0216
            break;                                                                        //06-12-16|0x0216
          default:                                                                        //06-12-16|0x0216
            BaseStatus = SystemError;                                                     //06-12-16|0x0216
            BaseRunFlag = 0;                                                              //06-12-16|0x0216
            SystemMsg;                                                                    //06-12-16|0x0216
            break;                                                                        //06-12-16|0x0216
        }                                                                                 //06-12-16|0x0216
        break;                                                                            //06-12-16|0x0216
//---------------------------------------------------------------------------             //06-12-16|0x0217
      case 5348: // RUN_OK_TEST                                                           //06-12-16|0x0218
        switch(DataTypeFlag)                                                              //06-12-16|0x0218
        {                                                                                 //06-12-16|0x0218
          case 1:                                                                         //06-12-16|0x0218
            BaseRunFlag = 1;                                                              //06-12-16|0x0218
            BaseState = 57657; // TEST_OK_MSG                                             //06-12-16|0x0218
            break;                                                                        //06-12-16|0x0218
          case -1:                                                                        //06-12-16|0x0218
            BaseRunFlag = 1;                                                              //06-12-16|0x0218
            BaseState = 38031; // ILLEGAL_TEST                                            //06-12-16|0x0218
            break;                                                                        //06-12-16|0x0218
          case -2:                                                                        //06-12-16|0x0218
            BaseRunFlag = 1;                                                              //06-12-16|0x0218
            BaseState = 25507; // RUN_OK_ERR_MSG                                          //06-12-16|0x0218
            break;                                                                        //06-12-16|0x0218
          default:                                                                        //06-12-16|0x0218
            BaseStatus = SystemError;                                                     //06-12-16|0x0218
            BaseRunFlag = 0;                                                              //06-12-16|0x0218
            SystemMsg;                                                                    //06-12-16|0x0218
            break;                                                                        //06-12-16|0x0218
        }                                                                                 //06-12-16|0x0218
        break;                                                                            //06-12-16|0x0218
//***************************************************************************             //06-12-16|0x0219
      case 61419: // RUN_ERR_REC                                                          //06-12-17|0x021a
        switch(RecordMake)                                                                //06-12-17|0x021a
        {                                                                                 //06-12-17|0x021a
          case Success:                                                                   //06-12-17|0x021a
            BaseRunFlag = 1;                                                              //06-12-17|0x021a
            BaseState = 40530; // RUN_ERR_TEST                                            //06-12-17|0x021a
            break;                                                                        //06-12-17|0x021a
          default:                                                                        //06-12-17|0x021a
            BaseStatus = SystemError;                                                     //06-12-17|0x021a
            BaseRunFlag = 0;                                                              //06-12-17|0x021a
            SystemMsg;                                                                    //06-12-17|0x021a
            break;                                                                        //06-12-17|0x021a
        }                                                                                 //06-12-17|0x021a
        break;                                                                            //06-12-17|0x021a
//---------------------------------------------------------------------------             //06-12-17|0x021b
      case 40530: // RUN_ERR_TEST                                                         //06-12-17|0x021c
        switch(DataTypeFlag)                                                              //06-12-17|0x021c
        {                                                                                 //06-12-17|0x021c
          case 1:                                                                         //06-12-17|0x021c
            BaseRunFlag = 1;                                                              //06-12-17|0x021c
            BaseState = 33777; // OK_RUN_ERR_MSG                                          //06-12-17|0x021c
            break;                                                                        //06-12-17|0x021c
          case -1:                                                                        //06-12-17|0x021c
            BaseRunFlag = 1;                                                              //06-12-17|0x021c
            BaseState = 38031; // ILLEGAL_TEST                                            //06-12-17|0x021c
            break;                                                                        //06-12-17|0x021c
          case -2:                                                                        //06-12-17|0x021c
            BaseRunFlag = 1;                                                              //06-12-17|0x021c
            BaseState = 50048; // RUN_OK_MSG                                              //06-12-17|0x021c
            break;                                                                        //06-12-17|0x021c
          default:                                                                        //06-12-17|0x021c
            BaseStatus = SystemError;                                                     //06-12-17|0x021c
            BaseRunFlag = 0;                                                              //06-12-17|0x021c
            SystemMsg;                                                                    //06-12-17|0x021c
            break;                                                                        //06-12-17|0x021c
        }                                                                                 //06-12-17|0x021c
        break;                                                                            //06-12-17|0x021c
//***************************************************************************             //07-10-13|0x021d
      case 38031: // ILLEGAL_TEST                                                         //09-01-03|0x021e
        switch(IllegalTestCondition)                                                      //09-01-03|0x021e
        {                                                                                 //09-01-03|0x021e
          case UserError:                                                                 //09-01-03|0x021e
            BaseRunFlag = 1;                                                              //09-01-03|0x021e
            BaseState = 55081; // USER                                                    //09-01-03|0x021e
            break;                                                                        //09-01-03|0x021e
          default:                                                                        //09-01-03|0x021e
            BaseStatus = SystemError;                                                     //09-01-03|0x021e
            BaseRunFlag = 0;                                                              //09-01-03|0x021e
            SystemMsg;                                                                    //09-01-03|0x021e
            break;                                                                        //09-01-03|0x021e
        }                                                                                 //09-01-03|0x021e
        break;                                                                            //09-01-03|0x021e
//***************************************************************************             //06-12-15|0x021f
//******                                                               ******             //06-12-15|0x0220
//******  RECORD - DISPLAY TEST RESULTS                                ******             //06-12-15|0x0221
//******---------------------------------------------------------------******             //06-12-15|0x0222
//******  Display test results                                         ******             //06-12-15|0x0223
//******                                                               ******             //06-12-15|0x0224
//***************************************************************************             //06-12-15|0x0225
      case 57657: // TEST_OK_MSG                                                          //06-12-16|0x0226
        switch(TestSuccessMsg)                                                            //06-12-16|0x0226
        {                                                                                 //06-12-16|0x0226
          case Success:                                                                   //06-12-16|0x0226
            BaseState = 64511; // PAUSE_OK                                                //06-12-16|0x0226
            BaseStatus = Display;                                                         //06-12-16|0x0226
            BaseRunFlag = 0;                                                              //06-12-16|0x0226
            break;                                                                        //06-12-16|0x0226
          default:                                                                        //06-12-16|0x0226
            BaseStatus = SystemError;                                                     //06-12-16|0x0226
            BaseRunFlag = 0;                                                              //06-12-16|0x0226
            SystemMsg;                                                                    //06-12-16|0x0226
            break;                                                                        //06-12-16|0x0226
        }                                                                                 //06-12-16|0x0226
        break;                                                                            //06-12-16|0x0226
//***************************************************************************             //06-12-15|0x0227
      case 58133: // MAKE_OK_MSG                                                          //06-12-15|0x0228
        switch(ExpectedMakeErrorMsg)                                                      //06-12-15|0x0228
        {                                                                                 //06-12-15|0x0228
          case Success:                                                                   //06-12-15|0x0228
            BaseState = 48238; // PAUSE_MAKE                                              //06-12-15|0x0228
            BaseStatus = Display;                                                         //06-12-15|0x0228
            BaseRunFlag = 0;                                                              //06-12-15|0x0228
            break;                                                                        //06-12-15|0x0228
          default:                                                                        //06-12-15|0x0228
            BaseStatus = SystemError;                                                     //06-12-15|0x0228
            BaseRunFlag = 0;                                                              //06-12-15|0x0228
            SystemMsg;                                                                    //06-12-15|0x0228
            break;                                                                        //06-12-15|0x0228
        }                                                                                 //06-12-15|0x0228
        break;                                                                            //06-12-15|0x0228
//---------------------------------------------------------------------------             //06-12-15|0x0229
      case 62792: // MAKE_OK_ERR_MSG                                                      //06-12-16|0x022a
        switch(UnexpectedMakeErrorMsg)                                                    //06-12-16|0x022a
        {                                                                                 //06-12-16|0x022a
          case Success:                                                                   //06-12-16|0x022a
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-16|0x022a
            BaseStatus = Display;                                                         //06-12-16|0x022a
            BaseRunFlag = 0;                                                              //06-12-16|0x022a
            break;                                                                        //06-12-16|0x022a
          default:                                                                        //06-12-16|0x022a
            BaseStatus = SystemError;                                                     //06-12-16|0x022a
            BaseRunFlag = 0;                                                              //06-12-16|0x022a
            SystemMsg;                                                                    //06-12-16|0x022a
            break;                                                                        //06-12-16|0x022a
        }                                                                                 //06-12-16|0x022a
        break;                                                                            //06-12-16|0x022a
//---------------------------------------------------------------------------             //06-12-17|0x022b
      case 56830: // OK_MAKE_ERR_MSG                                                      //06-12-17|0x022c
        switch(UnexpectedMakeOkMsg)                                                       //06-12-17|0x022c
        {                                                                                 //06-12-17|0x022c
          case Success:                                                                   //06-12-17|0x022c
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-17|0x022c
            BaseStatus = Display;                                                         //06-12-17|0x022c
            BaseRunFlag = 0;                                                              //06-12-17|0x022c
            break;                                                                        //06-12-17|0x022c
          default:                                                                        //06-12-17|0x022c
            BaseStatus = SystemError;                                                     //06-12-17|0x022c
            BaseRunFlag = 0;                                                              //06-12-17|0x022c
            SystemMsg;                                                                    //06-12-17|0x022c
            break;                                                                        //06-12-17|0x022c
        }                                                                                 //06-12-17|0x022c
        break;                                                                            //06-12-17|0x022c
//***************************************************************************             //06-12-17|0x022d
      case 50048: // RUN_OK_MSG                                                           //06-12-17|0x022e
        switch(ExpectedRunErrorMsg)                                                       //06-12-17|0x022e
        {                                                                                 //06-12-17|0x022e
          case Success:                                                                   //06-12-17|0x022e
            BaseState = 49436; // PAUSE_RUN                                               //06-12-17|0x022e
            BaseStatus = Display;                                                         //06-12-17|0x022e
            BaseRunFlag = 0;                                                              //06-12-17|0x022e
            break;                                                                        //06-12-17|0x022e
          default:                                                                        //06-12-17|0x022e
            BaseStatus = SystemError;                                                     //06-12-17|0x022e
            BaseRunFlag = 0;                                                              //06-12-17|0x022e
            SystemMsg;                                                                    //06-12-17|0x022e
            break;                                                                        //06-12-17|0x022e
        }                                                                                 //06-12-17|0x022e
        break;                                                                            //06-12-17|0x022e
//---------------------------------------------------------------------------             //06-12-17|0x022f
      case 25507: // RUN_OK_ERR_MSG                                                       //06-12-17|0x0230
        switch(UnexpectedRunErrorMsg)                                                     //06-12-17|0x0230
        {                                                                                 //06-12-17|0x0230
          case Success:                                                                   //06-12-17|0x0230
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-17|0x0230
            BaseStatus = Display;                                                         //06-12-17|0x0230
            BaseRunFlag = 0;                                                              //06-12-17|0x0230
            break;                                                                        //06-12-17|0x0230
          default:                                                                        //06-12-17|0x0230
            BaseStatus = SystemError;                                                     //06-12-17|0x0230
            BaseRunFlag = 0;                                                              //06-12-17|0x0230
            SystemMsg;                                                                    //06-12-17|0x0230
            break;                                                                        //06-12-17|0x0230
        }                                                                                 //06-12-17|0x0230
        break;                                                                            //06-12-17|0x0230
//---------------------------------------------------------------------------             //06-12-17|0x0231
      case 33777: // OK_RUN_ERR_MSG                                                       //06-12-17|0x0232
        switch(UnexpectedRunOkMsg)                                                        //06-12-17|0x0232
        {                                                                                 //06-12-17|0x0232
          case Success:                                                                   //06-12-17|0x0232
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-17|0x0232
            BaseStatus = Display;                                                         //06-12-17|0x0232
            BaseRunFlag = 0;                                                              //06-12-17|0x0232
            break;                                                                        //06-12-17|0x0232
          default:                                                                        //06-12-17|0x0232
            BaseStatus = SystemError;                                                     //06-12-17|0x0232
            BaseRunFlag = 0;                                                              //06-12-17|0x0232
            SystemMsg;                                                                    //06-12-17|0x0232
            break;                                                                        //06-12-17|0x0232
        }                                                                                 //06-12-17|0x0232
        break;                                                                            //06-12-17|0x0232
//***************************************************************************             //06-12-16|0x0233
      case 64511: // PAUSE_OK                                                             //06-12-16|0x0234
        switch(DebugPause)                                                                //06-12-16|0x0234
        {                                                                                 //06-12-16|0x0234
          case Display:                                                                   //06-12-16|0x0234
            BaseState = 64511; // PAUSE_OK                                                //06-12-16|0x0234
            BaseStatus = Display;                                                         //06-12-16|0x0234
            BaseRunFlag = 0;                                                              //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case KeyBoard:                                                                  //06-12-16|0x0234
            BaseState = 64511; // PAUSE_OK                                                //06-12-16|0x0234
            BaseStatus = KeyBoard;                                                        //06-12-16|0x0234
            BaseRunFlag = 0;                                                              //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case Continue:                                                                  //06-12-16|0x0234
            BaseRunFlag = 1;                                                              //06-12-16|0x0234
            BaseState = 54107; // PAUSE_OK_LOCAL                                          //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case Success:                                                                   //06-12-16|0x0234
            BaseRunFlag = 1;                                                              //06-12-16|0x0234
            BaseState = 2442; // SUMMARY_OK                                               //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case UserError:                                                                 //06-12-16|0x0234
            BaseRunFlag = 1;                                                              //06-12-16|0x0234
            BaseState = 55081; // USER                                                    //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          default:                                                                        //06-12-16|0x0234
            BaseStatus = SystemError;                                                     //06-12-16|0x0234
            BaseRunFlag = 0;                                                              //06-12-16|0x0234
            SystemMsg;                                                                    //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
        }                                                                                 //06-12-16|0x0234
        break;                                                                            //06-12-16|0x0234
//**************************************************************************              //06-12-16|0x0234
      case 54107: // PAUSE_OK_LOCAL                                                       //06-12-16|0x0234
        switch(DebugPause)                                                                //06-12-16|0x0234
        {                                                                                 //06-12-16|0x0234
          case Display:                                                                   //06-12-16|0x0234
            BaseState = 64511; // PAUSE_OK                                                //06-12-16|0x0234
            BaseStatus = Display;                                                         //06-12-16|0x0234
            BaseRunFlag = 0;                                                              //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case KeyBoard:                                                                  //06-12-16|0x0234
            BaseState = 64511; // PAUSE_OK                                                //06-12-16|0x0234
            BaseStatus = KeyBoard;                                                        //06-12-16|0x0234
            BaseRunFlag = 0;                                                              //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case Continue:                                                                  //06-12-16|0x0234
            BaseRunFlag = 1;                                                              //06-12-16|0x0234
            BaseState = 54107; // PAUSE_OK_LOCAL                                          //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case Success:                                                                   //06-12-16|0x0234
            BaseRunFlag = 1;                                                              //06-12-16|0x0234
            BaseState = 2442; // SUMMARY_OK                                               //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          case UserError:                                                                 //06-12-16|0x0234
            BaseRunFlag = 1;                                                              //06-12-16|0x0234
            BaseState = 55081; // USER                                                    //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
          default:                                                                        //06-12-16|0x0234
            BaseStatus = SystemError;                                                     //06-12-16|0x0234
            BaseRunFlag = 0;                                                              //06-12-16|0x0234
            SystemMsg;                                                                    //06-12-16|0x0234
            break;                                                                        //06-12-16|0x0234
        }                                                                                 //06-12-16|0x0234
        break;                                                                            //06-12-16|0x0234
//---------------------------------------------------------------------------             //06-12-15|0x0235
      case 48238: // PAUSE_MAKE                                                           //06-12-15|0x0236
        switch(DebugPause)                                                                //06-12-15|0x0236
        {                                                                                 //06-12-15|0x0236
          case Display:                                                                   //06-12-15|0x0236
            BaseState = 48238; // PAUSE_MAKE                                              //06-12-15|0x0236
            BaseStatus = Display;                                                         //06-12-15|0x0236
            BaseRunFlag = 0;                                                              //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case KeyBoard:                                                                  //06-12-15|0x0236
            BaseState = 48238; // PAUSE_MAKE                                              //06-12-15|0x0236
            BaseStatus = KeyBoard;                                                        //06-12-15|0x0236
            BaseRunFlag = 0;                                                              //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case Continue:                                                                  //06-12-15|0x0236
            BaseRunFlag = 1;                                                              //06-12-15|0x0236
            BaseState = 41641; // PAUSE_MAKE_LOCAL                                        //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case Success:                                                                   //06-12-15|0x0236
            BaseRunFlag = 1;                                                              //06-12-15|0x0236
            BaseState = 52664; // SUMMARY_MAKE                                            //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case UserError:                                                                 //06-12-15|0x0236
            BaseRunFlag = 1;                                                              //06-12-15|0x0236
            BaseState = 55081; // USER                                                    //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          default:                                                                        //06-12-15|0x0236
            BaseStatus = SystemError;                                                     //06-12-15|0x0236
            BaseRunFlag = 0;                                                              //06-12-15|0x0236
            SystemMsg;                                                                    //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
        }                                                                                 //06-12-15|0x0236
        break;                                                                            //06-12-15|0x0236
//**************************************************************************              //06-12-15|0x0236
      case 41641: // PAUSE_MAKE_LOCAL                                                     //06-12-15|0x0236
        switch(DebugPause)                                                                //06-12-15|0x0236
        {                                                                                 //06-12-15|0x0236
          case Display:                                                                   //06-12-15|0x0236
            BaseState = 48238; // PAUSE_MAKE                                              //06-12-15|0x0236
            BaseStatus = Display;                                                         //06-12-15|0x0236
            BaseRunFlag = 0;                                                              //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case KeyBoard:                                                                  //06-12-15|0x0236
            BaseState = 48238; // PAUSE_MAKE                                              //06-12-15|0x0236
            BaseStatus = KeyBoard;                                                        //06-12-15|0x0236
            BaseRunFlag = 0;                                                              //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case Continue:                                                                  //06-12-15|0x0236
            BaseRunFlag = 1;                                                              //06-12-15|0x0236
            BaseState = 41641; // PAUSE_MAKE_LOCAL                                        //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case Success:                                                                   //06-12-15|0x0236
            BaseRunFlag = 1;                                                              //06-12-15|0x0236
            BaseState = 52664; // SUMMARY_MAKE                                            //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          case UserError:                                                                 //06-12-15|0x0236
            BaseRunFlag = 1;                                                              //06-12-15|0x0236
            BaseState = 55081; // USER                                                    //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
          default:                                                                        //06-12-15|0x0236
            BaseStatus = SystemError;                                                     //06-12-15|0x0236
            BaseRunFlag = 0;                                                              //06-12-15|0x0236
            SystemMsg;                                                                    //06-12-15|0x0236
            break;                                                                        //06-12-15|0x0236
        }                                                                                 //06-12-15|0x0236
        break;                                                                            //06-12-15|0x0236
//---------------------------------------------------------------------------             //06-12-15|0x0237
      case 49436: // PAUSE_RUN                                                            //06-12-17|0x0238
        switch(DebugPause)                                                                //06-12-17|0x0238
        {                                                                                 //06-12-17|0x0238
          case Display:                                                                   //06-12-17|0x0238
            BaseState = 49436; // PAUSE_RUN                                               //06-12-17|0x0238
            BaseStatus = Display;                                                         //06-12-17|0x0238
            BaseRunFlag = 0;                                                              //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case KeyBoard:                                                                  //06-12-17|0x0238
            BaseState = 49436; // PAUSE_RUN                                               //06-12-17|0x0238
            BaseStatus = KeyBoard;                                                        //06-12-17|0x0238
            BaseRunFlag = 0;                                                              //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case Continue:                                                                  //06-12-17|0x0238
            BaseRunFlag = 1;                                                              //06-12-17|0x0238
            BaseState = 43447; // PAUSE_RUN_LOCAL                                         //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case Success:                                                                   //06-12-17|0x0238
            BaseRunFlag = 1;                                                              //06-12-17|0x0238
            BaseState = 17830; // SUMMARY_RUN                                             //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case UserError:                                                                 //06-12-17|0x0238
            BaseRunFlag = 1;                                                              //06-12-17|0x0238
            BaseState = 55081; // USER                                                    //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          default:                                                                        //06-12-17|0x0238
            BaseStatus = SystemError;                                                     //06-12-17|0x0238
            BaseRunFlag = 0;                                                              //06-12-17|0x0238
            SystemMsg;                                                                    //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
        }                                                                                 //06-12-17|0x0238
        break;                                                                            //06-12-17|0x0238
//**************************************************************************              //06-12-17|0x0238
      case 43447: // PAUSE_RUN_LOCAL                                                      //06-12-17|0x0238
        switch(DebugPause)                                                                //06-12-17|0x0238
        {                                                                                 //06-12-17|0x0238
          case Display:                                                                   //06-12-17|0x0238
            BaseState = 49436; // PAUSE_RUN                                               //06-12-17|0x0238
            BaseStatus = Display;                                                         //06-12-17|0x0238
            BaseRunFlag = 0;                                                              //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case KeyBoard:                                                                  //06-12-17|0x0238
            BaseState = 49436; // PAUSE_RUN                                               //06-12-17|0x0238
            BaseStatus = KeyBoard;                                                        //06-12-17|0x0238
            BaseRunFlag = 0;                                                              //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case Continue:                                                                  //06-12-17|0x0238
            BaseRunFlag = 1;                                                              //06-12-17|0x0238
            BaseState = 43447; // PAUSE_RUN_LOCAL                                         //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case Success:                                                                   //06-12-17|0x0238
            BaseRunFlag = 1;                                                              //06-12-17|0x0238
            BaseState = 17830; // SUMMARY_RUN                                             //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          case UserError:                                                                 //06-12-17|0x0238
            BaseRunFlag = 1;                                                              //06-12-17|0x0238
            BaseState = 55081; // USER                                                    //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
          default:                                                                        //06-12-17|0x0238
            BaseStatus = SystemError;                                                     //06-12-17|0x0238
            BaseRunFlag = 0;                                                              //06-12-17|0x0238
            SystemMsg;                                                                    //06-12-17|0x0238
            break;                                                                        //06-12-17|0x0238
        }                                                                                 //06-12-17|0x0238
        break;                                                                            //06-12-17|0x0238
//---------------------------------------------------------------------------             //06-12-15|0x0239
      case 33741: // PAUSE_ERROR                                                          //06-12-15|0x023a
        switch(DebugPause)                                                                //06-12-15|0x023a
        {                                                                                 //06-12-15|0x023a
          case Display:                                                                   //06-12-15|0x023a
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-15|0x023a
            BaseStatus = Display;                                                         //06-12-15|0x023a
            BaseRunFlag = 0;                                                              //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case KeyBoard:                                                                  //06-12-15|0x023a
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-15|0x023a
            BaseStatus = KeyBoard;                                                        //06-12-15|0x023a
            BaseRunFlag = 0;                                                              //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case Continue:                                                                  //06-12-15|0x023a
            BaseRunFlag = 1;                                                              //06-12-15|0x023a
            BaseState = 41093; // PAUSE_ERROR_LOCAL                                       //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case Success:                                                                   //06-12-15|0x023a
            BaseRunFlag = 1;                                                              //06-12-15|0x023a
            BaseState = 43348; // SUMMARY_ERROR                                           //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case UserError:                                                                 //06-12-15|0x023a
            BaseRunFlag = 1;                                                              //06-12-15|0x023a
            BaseState = 55081; // USER                                                    //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          default:                                                                        //06-12-15|0x023a
            BaseStatus = SystemError;                                                     //06-12-15|0x023a
            BaseRunFlag = 0;                                                              //06-12-15|0x023a
            SystemMsg;                                                                    //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
        }                                                                                 //06-12-15|0x023a
        break;                                                                            //06-12-15|0x023a
//**************************************************************************              //06-12-15|0x023a
      case 41093: // PAUSE_ERROR_LOCAL                                                    //06-12-15|0x023a
        switch(DebugPause)                                                                //06-12-15|0x023a
        {                                                                                 //06-12-15|0x023a
          case Display:                                                                   //06-12-15|0x023a
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-15|0x023a
            BaseStatus = Display;                                                         //06-12-15|0x023a
            BaseRunFlag = 0;                                                              //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case KeyBoard:                                                                  //06-12-15|0x023a
            BaseState = 33741; // PAUSE_ERROR                                             //06-12-15|0x023a
            BaseStatus = KeyBoard;                                                        //06-12-15|0x023a
            BaseRunFlag = 0;                                                              //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case Continue:                                                                  //06-12-15|0x023a
            BaseRunFlag = 1;                                                              //06-12-15|0x023a
            BaseState = 41093; // PAUSE_ERROR_LOCAL                                       //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case Success:                                                                   //06-12-15|0x023a
            BaseRunFlag = 1;                                                              //06-12-15|0x023a
            BaseState = 43348; // SUMMARY_ERROR                                           //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          case UserError:                                                                 //06-12-15|0x023a
            BaseRunFlag = 1;                                                              //06-12-15|0x023a
            BaseState = 55081; // USER                                                    //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
          default:                                                                        //06-12-15|0x023a
            BaseStatus = SystemError;                                                     //06-12-15|0x023a
            BaseRunFlag = 0;                                                              //06-12-15|0x023a
            SystemMsg;                                                                    //06-12-15|0x023a
            break;                                                                        //06-12-15|0x023a
        }                                                                                 //06-12-15|0x023a
        break;                                                                            //06-12-15|0x023a
//***************************************************************************             //06-12-15|0x023b
//******                                                               ******             //06-12-15|0x023c
//******  RECORD - DISPLAY TEST RESULTS                                ******             //06-12-15|0x023d
//******---------------------------------------------------------------******             //06-12-15|0x023e
//******  Record summary data                                          ******             //06-12-15|0x023f
//******                                                               ******             //06-12-15|0x0240
//***************************************************************************             //06-12-15|0x0241
      case 2442: // SUMMARY_OK                                                            //06-12-15|0x0242
        IncrNoSuccess;                                                                    //06-12-15|0x0242
        BaseState = 16147; // RECORD_EXISTS                                               //06-12-15|0x0242
        break;                                                                            //06-12-15|0x0242
//---------------------------------------------------------------------------             //06-12-15|0x0243
      case 52664: // SUMMARY_MAKE                                                         //06-12-15|0x0244
        IncrNoPrepDetects;                                                                //06-12-15|0x0244
        BaseState = 16147; // RECORD_EXISTS                                               //06-12-15|0x0244
        break;                                                                            //06-12-15|0x0244
//---------------------------------------------------------------------------             //06-12-15|0x0245
      case 17830: // SUMMARY_RUN                                                          //06-12-17|0x0246
        IncrNoRunDetects;                                                                 //06-12-17|0x0246
        BaseState = 16147; // RECORD_EXISTS                                               //06-12-17|0x0246
        break;                                                                            //06-12-17|0x0246
//---------------------------------------------------------------------------             //06-12-17|0x0247
      case 43348: // SUMMARY_ERROR                                                        //06-12-15|0x0248
        IncrNoFailures;                                                                   //06-12-15|0x0248
        BaseState = 12482; // ACTIVE_BITS                                                 //06-12-15|0x0248
        break;                                                                            //06-12-15|0x0248
//***************************************************************************             //06-12-16|0x0249
//******                                                               ******             //06-12-16|0x024a
//******  RECORD - DISPLAY TEST RESULTS                                ******             //06-12-16|0x024b
//******---------------------------------------------------------------******             //06-12-16|0x024c
//******  Record error data                                            ******             //06-12-16|0x024d
//******                                                               ******             //06-12-16|0x024e
//***************************************************************************             //06-12-16|0x024f
      case 12482: // ACTIVE_BITS                                                          //06-12-16|0x0250
        switch(prepare_active_bits())                                                     //06-12-16|0x0250
        {                                                                                 //06-12-16|0x0250
          case Success:                                                                   //06-12-16|0x0250
            BaseRunFlag = 1;                                                              //06-12-16|0x0250
            BaseState = 15713; // PREVIOUS_ERROR                                          //06-12-16|0x0250
            break;                                                                        //06-12-16|0x0250
          default:                                                                        //06-12-16|0x0250
            BaseStatus = SystemError;                                                     //06-12-16|0x0250
            BaseRunFlag = 0;                                                              //06-12-16|0x0250
            SystemMsg;                                                                    //06-12-16|0x0250
            break;                                                                        //06-12-16|0x0250
        }                                                                                 //06-12-16|0x0250
        break;                                                                            //06-12-16|0x0250
//---------------------------------------------------------------------------             //06-12-16|0x0251
      case 15713: // PREVIOUS_ERROR                                                       //06-12-16|0x0252
        switch(previous_error())                                                          //06-12-16|0x0252
        {                                                                                 //06-12-16|0x0252
          case Yes:                                                                       //06-12-16|0x0252
            BaseRunFlag = 1;                                                              //06-12-16|0x0252
            BaseState = 16147; // RECORD_EXISTS                                           //06-12-16|0x0252
            break;                                                                        //06-12-16|0x0252
          case No:                                                                        //06-12-16|0x0252
            BaseRunFlag = 1;                                                              //06-12-16|0x0252
            BaseState = 5104; // NEW_ERROR                                                //06-12-16|0x0252
            break;                                                                        //06-12-16|0x0252
          default:                                                                        //06-12-16|0x0252
            BaseStatus = SystemError;                                                     //06-12-16|0x0252
            BaseRunFlag = 0;                                                              //06-12-16|0x0252
            SystemMsg;                                                                    //06-12-16|0x0252
            break;                                                                        //06-12-16|0x0252
        }                                                                                 //06-12-16|0x0252
        break;                                                                            //06-12-16|0x0252
//---------------------------------------------------------------------------             //06-12-16|0x0253
      case 5104: // NEW_ERROR                                                             //06-12-16|0x0254
        switch(new_error())                                                               //06-12-16|0x0254
        {                                                                                 //06-12-16|0x0254
          case Yes:                                                                       //06-12-16|0x0254
            BaseRunFlag = 1;                                                              //06-12-16|0x0254
            BaseState = 16147; // RECORD_EXISTS                                           //06-12-16|0x0254
            break;                                                                        //06-12-16|0x0254
          case No:                                                                        //06-12-16|0x0254
            BaseRunFlag = 1;                                                              //06-12-16|0x0254
            BaseState = 29011; // REPORT_EXISTS                                           //06-12-16|0x0254
            break;                                                                        //06-12-16|0x0254
          default:                                                                        //06-12-16|0x0254
            BaseStatus = SystemError;                                                     //06-12-16|0x0254
            BaseRunFlag = 0;                                                              //06-12-16|0x0254
            SystemMsg;                                                                    //06-12-16|0x0254
            break;                                                                        //06-12-16|0x0254
        }                                                                                 //06-12-16|0x0254
        break;                                                                            //06-12-16|0x0254
//***************************************************************************             //06-12-15|0x0255
//******                                                               ******             //06-12-15|0x0256
//******  RECORD - DISPLAY TEST RESULTS                                ******             //06-12-15|0x0257
//******---------------------------------------------------------------******             //06-12-15|0x0258
//******  Record PCG Step                                              ******             //06-12-15|0x0259
//******                                                               ******             //06-12-15|0x025a
//***************************************************************************             //06-12-15|0x025b
      case 16147: // RECORD_EXISTS                                                        //06-12-15|0x025c
        switch(RecordStepExists)                                                          //06-12-15|0x025c
        {                                                                                 //06-12-15|0x025c
          case Yes:                                                                       //06-12-15|0x025c
            BaseRunFlag = 1;                                                              //06-12-15|0x025c
            BaseState = 21359; // RECORD_MESSAGE                                          //06-12-15|0x025c
            break;                                                                        //06-12-15|0x025c
          case No:                                                                        //06-12-15|0x025c
            BaseRunFlag = 1;                                                              //06-12-15|0x025c
            BaseState = 19141; // CLEANUP_FILES                                           //06-12-15|0x025c
            break;                                                                        //06-12-15|0x025c
          default:                                                                        //06-12-15|0x025c
            BaseStatus = SystemError;                                                     //06-12-15|0x025c
            BaseRunFlag = 0;                                                              //06-12-15|0x025c
            SystemMsg;                                                                    //06-12-15|0x025c
            break;                                                                        //06-12-15|0x025c
        }                                                                                 //06-12-15|0x025c
        break;                                                                            //06-12-15|0x025c
//***************************************************************************             //06-12-15|0x025d
      case 21359: // RECORD_MESSAGE                                                       //06-12-18|0x025e
        switch(RecordStepMessage)                                                         //06-12-18|0x025e
        {                                                                                 //06-12-18|0x025e
          case Success:                                                                   //06-12-18|0x025e
            BaseState = 35550; // RECORD_PUSH                                             //06-12-18|0x025e
            BaseStatus = Display;                                                         //06-12-18|0x025e
            BaseRunFlag = 0;                                                              //06-12-18|0x025e
            break;                                                                        //06-12-18|0x025e
          default:                                                                        //06-12-18|0x025e
            BaseStatus = SystemError;                                                     //06-12-18|0x025e
            BaseRunFlag = 0;                                                              //06-12-18|0x025e
            SystemMsg;                                                                    //06-12-18|0x025e
            break;                                                                        //06-12-18|0x025e
        }                                                                                 //06-12-18|0x025e
        break;                                                                            //06-12-18|0x025e
//***************************************************************************             //06-12-18|0x025f
      case 35550: // RECORD_PUSH                                                          //06-12-18|0x0260
        switch(pcg_push(DataRecordAddr))                                                  //06-12-18|0x0260
        {                                                                                 //06-12-18|0x0260
          case Success:                                                                   //06-12-18|0x0260
            BaseRunFlag = 1;                                                              //06-12-18|0x0260
            BaseState = 14653; // RECORD_PCG                                              //06-12-18|0x0260
            break;                                                                        //06-12-18|0x0260
          default:                                                                        //06-12-18|0x0260
            BaseStatus = SystemError;                                                     //06-12-18|0x0260
            BaseRunFlag = 0;                                                              //06-12-18|0x0260
            SystemMsg;                                                                    //06-12-18|0x0260
            break;                                                                        //06-12-18|0x0260
        }                                                                                 //06-12-18|0x0260
        break;                                                                            //06-12-18|0x0260
//***************************************************************************             //06-12-18|0x0261
      case 14653: // RECORD_PCG                                                           //06-12-18|0x0262
        switch(TestProject(DataRecordAddr))                                               //06-12-18|0x0262
        {                                                                                 //06-12-18|0x0262
          case Display:                                                                   //06-12-18|0x0262
            BaseState = 52620; // RECORD_PCG_EXIT                                         //06-12-18|0x0262
            BaseStatus = Display;                                                         //06-12-18|0x0262
            BaseRunFlag = 0;                                                              //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case KeyBoard:                                                                  //06-12-18|0x0262
            BaseState = 52620; // RECORD_PCG_EXIT                                         //06-12-18|0x0262
            BaseStatus = KeyBoard;                                                        //06-12-18|0x0262
            BaseRunFlag = 0;                                                              //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case Success:                                                                   //06-12-18|0x0262
            BaseRunFlag = 1;                                                              //06-12-18|0x0262
            BaseState = 42699; // RECORD_POP                                              //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case BuildError:                                                                //06-12-18|0x0262
            BaseRunFlag = 1;                                                              //06-12-18|0x0262
            BaseState = 5114; // STOP_TEST_RET                                            //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case UserError:                                                                 //06-12-18|0x0262
            BaseRunFlag = 1;                                                              //06-12-18|0x0262
            BaseState = 15308; // USR_POP                                                 //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          default:                                                                        //06-12-18|0x0262
            BaseStatus = SystemError;                                                     //06-12-18|0x0262
            BaseRunFlag = 0;                                                              //06-12-18|0x0262
            SystemMsg;                                                                    //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
        }                                                                                 //06-12-18|0x0262
        break;                                                                            //06-12-18|0x0262
//**************************************************************************              //06-12-18|0x0262
      case 52620: // RECORD_PCG_EXIT                                                      //06-12-18|0x0262
        switch(TestProject(DataRecordAddr))                                               //06-12-18|0x0262
        {                                                                                 //06-12-18|0x0262
          case Display:                                                                   //06-12-18|0x0262
            BaseState = 52620; // RECORD_PCG_EXIT                                         //06-12-18|0x0262
            BaseStatus = Display;                                                         //06-12-18|0x0262
            BaseRunFlag = 0;                                                              //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case KeyBoard:                                                                  //06-12-18|0x0262
            BaseState = 52620; // RECORD_PCG_EXIT                                         //06-12-18|0x0262
            BaseStatus = KeyBoard;                                                        //06-12-18|0x0262
            BaseRunFlag = 0;                                                              //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case Success:                                                                   //06-12-18|0x0262
            BaseRunFlag = 1;                                                              //06-12-18|0x0262
            BaseState = 42699; // RECORD_POP                                              //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case BuildError:                                                                //06-12-18|0x0262
            BaseRunFlag = 1;                                                              //06-12-18|0x0262
            BaseState = 5114; // STOP_TEST_RET                                            //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          case UserError:                                                                 //06-12-18|0x0262
            BaseRunFlag = 1;                                                              //06-12-18|0x0262
            BaseState = 15308; // USR_POP                                                 //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
          default:                                                                        //06-12-18|0x0262
            BaseStatus = SystemError;                                                     //06-12-18|0x0262
            BaseRunFlag = 0;                                                              //06-12-18|0x0262
            SystemMsg;                                                                    //06-12-18|0x0262
            break;                                                                        //06-12-18|0x0262
        }                                                                                 //06-12-18|0x0262
        break;                                                                            //06-12-18|0x0262
//***************************************************************************             //06-12-15|0x0263
      case 5114: // STOP_TEST_RET                                                         //06-12-18|0x0264
        BaseState = 21529; // STOP_TEST_POP                                               //06-12-18|0x0264
        BaseStatus = Display;                                                             //06-12-18|0x0264
        BaseRunFlag = 0;                                                                  //06-12-18|0x0264
        break;                                                                            //06-12-18|0x0264
//***************************************************************************             //06-12-18|0x0265
      case 42699: // RECORD_POP                                                           //06-12-18|0x0266
        switch(CallPrePop())                                                              //06-12-18|0x0266
        {                                                                                 //06-12-18|0x0266
          case Success:                                                                   //06-12-18|0x0266
            BaseRunFlag = 1;                                                              //06-12-18|0x0266
            BaseState = 38440; // RECORD_PAUSE                                            //06-12-18|0x0266
            break;                                                                        //06-12-18|0x0266
          default:                                                                        //06-12-18|0x0266
            BaseStatus = SystemError;                                                     //06-12-18|0x0266
            BaseRunFlag = 0;                                                              //06-12-18|0x0266
            SystemMsg;                                                                    //06-12-18|0x0266
            break;                                                                        //06-12-18|0x0266
        }                                                                                 //06-12-18|0x0266
        break;                                                                            //06-12-18|0x0266
//---------------------------------------------------------------------------             //06-12-18|0x0267
      case 21529: // STOP_TEST_POP                                                        //06-12-18|0x0268
        switch(CallPrePop())                                                              //06-12-18|0x0268
        {                                                                                 //06-12-18|0x0268
          case Success:                                                                   //06-12-18|0x0268
            BaseRunFlag = 1;                                                              //06-12-18|0x0268
            BaseState = 29011; // REPORT_EXISTS                                           //06-12-18|0x0268
            break;                                                                        //06-12-18|0x0268
          default:                                                                        //06-12-18|0x0268
            BaseStatus = SystemError;                                                     //06-12-18|0x0268
            BaseRunFlag = 0;                                                              //06-12-18|0x0268
            SystemMsg;                                                                    //06-12-18|0x0268
            break;                                                                        //06-12-18|0x0268
        }                                                                                 //06-12-18|0x0268
        break;                                                                            //06-12-18|0x0268
//***************************************************************************             //06-12-18|0x0269
      case 38440: // RECORD_PAUSE                                                         //06-12-18|0x026a
        switch(DebugPause)                                                                //06-12-18|0x026a
        {                                                                                 //06-12-18|0x026a
          case Display:                                                                   //06-12-18|0x026a
            BaseState = 63783; // RECORD_PAUSE_EXIT                                       //06-12-18|0x026a
            BaseStatus = Display;                                                         //06-12-18|0x026a
            BaseRunFlag = 0;                                                              //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case KeyBoard:                                                                  //06-12-18|0x026a
            BaseState = 63783; // RECORD_PAUSE_EXIT                                       //06-12-18|0x026a
            BaseStatus = KeyBoard;                                                        //06-12-18|0x026a
            BaseRunFlag = 0;                                                              //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case Continue:                                                                  //06-12-18|0x026a
            BaseRunFlag = 1;                                                              //06-12-18|0x026a
            BaseState = 38440; // RECORD_PAUSE                                            //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case Success:                                                                   //06-12-18|0x026a
            BaseRunFlag = 1;                                                              //06-12-18|0x026a
            BaseState = 19141; // CLEANUP_FILES                                           //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case UserError:                                                                 //06-12-18|0x026a
            BaseRunFlag = 1;                                                              //06-12-18|0x026a
            BaseState = 55081; // USER                                                    //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          default:                                                                        //06-12-18|0x026a
            BaseStatus = SystemError;                                                     //06-12-18|0x026a
            BaseRunFlag = 0;                                                              //06-12-18|0x026a
            SystemMsg;                                                                    //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
        }                                                                                 //06-12-18|0x026a
        break;                                                                            //06-12-18|0x026a
//**************************************************************************              //06-12-18|0x026a
      case 63783: // RECORD_PAUSE_EXIT                                                    //06-12-18|0x026a
        switch(DebugPause)                                                                //06-12-18|0x026a
        {                                                                                 //06-12-18|0x026a
          case Display:                                                                   //06-12-18|0x026a
            BaseState = 63783; // RECORD_PAUSE_EXIT                                       //06-12-18|0x026a
            BaseStatus = Display;                                                         //06-12-18|0x026a
            BaseRunFlag = 0;                                                              //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case KeyBoard:                                                                  //06-12-18|0x026a
            BaseState = 63783; // RECORD_PAUSE_EXIT                                       //06-12-18|0x026a
            BaseStatus = KeyBoard;                                                        //06-12-18|0x026a
            BaseRunFlag = 0;                                                              //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case Continue:                                                                  //06-12-18|0x026a
            BaseRunFlag = 1;                                                              //06-12-18|0x026a
            BaseState = 38440; // RECORD_PAUSE                                            //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case Success:                                                                   //06-12-18|0x026a
            BaseRunFlag = 1;                                                              //06-12-18|0x026a
            BaseState = 19141; // CLEANUP_FILES                                           //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          case UserError:                                                                 //06-12-18|0x026a
            BaseRunFlag = 1;                                                              //06-12-18|0x026a
            BaseState = 55081; // USER                                                    //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
          default:                                                                        //06-12-18|0x026a
            BaseStatus = SystemError;                                                     //06-12-18|0x026a
            BaseRunFlag = 0;                                                              //06-12-18|0x026a
            SystemMsg;                                                                    //06-12-18|0x026a
            break;                                                                        //06-12-18|0x026a
        }                                                                                 //06-12-18|0x026a
        break;                                                                            //06-12-18|0x026a
//***************************************************************************             //06-12-15|0x026b
//******                                                               ******             //06-12-15|0x026c
//******  REPORT TEST RESULTS                                          ******             //06-12-15|0x026d
//******---------------------------------------------------------------******             //06-12-15|0x026e
//******  Record PCG Step                                              ******             //06-12-15|0x026f
//******                                                               ******             //06-12-15|0x0270
//***************************************************************************             //06-12-15|0x0271
      case 29011: // REPORT_EXISTS                                                        //06-12-15|0x0272
        switch(ReportStepExists)                                                          //06-12-15|0x0272
        {                                                                                 //06-12-15|0x0272
          case Yes:                                                                       //06-12-15|0x0272
            BaseRunFlag = 1;                                                              //06-12-15|0x0272
            BaseState = 35862; // REPORT_PUSH                                             //06-12-15|0x0272
            break;                                                                        //06-12-15|0x0272
          case No:                                                                        //06-12-15|0x0272
            BaseRunFlag = 1;                                                              //06-12-15|0x0272
            BaseState = 19957; // SUMMARY_NAME                                            //06-12-15|0x0272
            break;                                                                        //06-12-15|0x0272
          default:                                                                        //06-12-15|0x0272
            BaseStatus = SystemError;                                                     //06-12-15|0x0272
            BaseRunFlag = 0;                                                              //06-12-15|0x0272
            SystemMsg;                                                                    //06-12-15|0x0272
            break;                                                                        //06-12-15|0x0272
        }                                                                                 //06-12-15|0x0272
        break;                                                                            //06-12-15|0x0272
//***************************************************************************             //06-12-15|0x0273
      case 35862: // REPORT_PUSH                                                          //06-12-18|0x0274
        switch(pcg_push(BaseReportAddr))                                                  //06-12-18|0x0274
        {                                                                                 //06-12-18|0x0274
          case Success:                                                                   //06-12-18|0x0274
            BaseRunFlag = 1;                                                              //06-12-18|0x0274
            BaseState = 11716; // REPORT_PCG                                              //06-12-18|0x0274
            break;                                                                        //06-12-18|0x0274
          default:                                                                        //06-12-18|0x0274
            BaseStatus = SystemError;                                                     //06-12-18|0x0274
            BaseRunFlag = 0;                                                              //06-12-18|0x0274
            SystemMsg;                                                                    //06-12-18|0x0274
            break;                                                                        //06-12-18|0x0274
        }                                                                                 //06-12-18|0x0274
        break;                                                                            //06-12-18|0x0274
//***************************************************************************             //06-12-18|0x0275
      case 11716: // REPORT_PCG                                                           //06-12-18|0x0276
        switch(TestProject(BaseReportAddr))                                               //06-12-18|0x0276
        {                                                                                 //06-12-18|0x0276
          case Display:                                                                   //06-12-18|0x0276
            BaseState = 2691; // REPORT_PCG_EXIT                                          //06-12-18|0x0276
            BaseStatus = Display;                                                         //06-12-18|0x0276
            BaseRunFlag = 0;                                                              //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case KeyBoard:                                                                  //06-12-18|0x0276
            BaseState = 2691; // REPORT_PCG_EXIT                                          //06-12-18|0x0276
            BaseStatus = KeyBoard;                                                        //06-12-18|0x0276
            BaseRunFlag = 0;                                                              //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case Success:                                                                   //06-12-18|0x0276
            BaseRunFlag = 1;                                                              //06-12-18|0x0276
            BaseState = 45874; // REPORT_POP                                              //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case BuildError:                                                                //06-12-18|0x0276
            BaseRunFlag = 1;                                                              //06-12-18|0x0276
            BaseState = 15308; // USR_POP                                                 //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case UserError:                                                                 //06-12-18|0x0276
            BaseRunFlag = 1;                                                              //06-12-18|0x0276
            BaseState = 15308; // USR_POP                                                 //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          default:                                                                        //06-12-18|0x0276
            BaseStatus = SystemError;                                                     //06-12-18|0x0276
            BaseRunFlag = 0;                                                              //06-12-18|0x0276
            SystemMsg;                                                                    //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
        }                                                                                 //06-12-18|0x0276
        break;                                                                            //06-12-18|0x0276
//**************************************************************************              //06-12-18|0x0276
      case 2691: // REPORT_PCG_EXIT                                                       //06-12-18|0x0276
        switch(TestProject(BaseReportAddr))                                               //06-12-18|0x0276
        {                                                                                 //06-12-18|0x0276
          case Display:                                                                   //06-12-18|0x0276
            BaseState = 2691; // REPORT_PCG_EXIT                                          //06-12-18|0x0276
            BaseStatus = Display;                                                         //06-12-18|0x0276
            BaseRunFlag = 0;                                                              //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case KeyBoard:                                                                  //06-12-18|0x0276
            BaseState = 2691; // REPORT_PCG_EXIT                                          //06-12-18|0x0276
            BaseStatus = KeyBoard;                                                        //06-12-18|0x0276
            BaseRunFlag = 0;                                                              //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case Success:                                                                   //06-12-18|0x0276
            BaseRunFlag = 1;                                                              //06-12-18|0x0276
            BaseState = 45874; // REPORT_POP                                              //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case BuildError:                                                                //06-12-18|0x0276
            BaseRunFlag = 1;                                                              //06-12-18|0x0276
            BaseState = 15308; // USR_POP                                                 //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          case UserError:                                                                 //06-12-18|0x0276
            BaseRunFlag = 1;                                                              //06-12-18|0x0276
            BaseState = 15308; // USR_POP                                                 //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
          default:                                                                        //06-12-18|0x0276
            BaseStatus = SystemError;                                                     //06-12-18|0x0276
            BaseRunFlag = 0;                                                              //06-12-18|0x0276
            SystemMsg;                                                                    //06-12-18|0x0276
            break;                                                                        //06-12-18|0x0276
        }                                                                                 //06-12-18|0x0276
        break;                                                                            //06-12-18|0x0276
//***************************************************************************             //06-12-18|0x0277
      case 45874: // REPORT_POP                                                           //06-12-18|0x0278
        switch(CallPrePop())                                                              //06-12-18|0x0278
        {                                                                                 //06-12-18|0x0278
          case Success:                                                                   //06-12-18|0x0278
            BaseRunFlag = 1;                                                              //06-12-18|0x0278
            BaseState = 19957; // SUMMARY_NAME                                            //06-12-18|0x0278
            break;                                                                        //06-12-18|0x0278
          default:                                                                        //06-12-18|0x0278
            BaseStatus = SystemError;                                                     //06-12-18|0x0278
            BaseRunFlag = 0;                                                              //06-12-18|0x0278
            SystemMsg;                                                                    //06-12-18|0x0278
            break;                                                                        //06-12-18|0x0278
        }                                                                                 //06-12-18|0x0278
        break;                                                                            //06-12-18|0x0278
//***************************************************************************             //06-12-15|0x0279
//******                                                               ******             //06-12-15|0x027a
//******  REPORT TEST RESULTS                                          ******             //06-12-15|0x027b
//******---------------------------------------------------------------******             //06-12-15|0x027c
//******  Execute Prepare Summary Report                               ******             //06-12-15|0x027d
//******                                                               ******             //06-12-15|0x027e
//***************************************************************************             //06-12-15|0x027f
      case 19957: // SUMMARY_NAME                                                         //06-12-15|0x0280
        switch(enter_summary_name(InputLineAddr(0)))                                      //06-12-15|0x0280
        {                                                                                 //06-12-15|0x0280
          case Success:                                                                   //06-12-15|0x0280
            BaseRunFlag = 1;                                                              //06-12-15|0x0280
            BaseState = 59089; // REPORT_SUMMARY                                          //06-12-15|0x0280
            break;                                                                        //06-12-15|0x0280
          default:                                                                        //06-12-15|0x0280
            BaseStatus = SystemError;                                                     //06-12-15|0x0280
            BaseRunFlag = 0;                                                              //06-12-15|0x0280
            SystemMsg;                                                                    //06-12-15|0x0280
            break;                                                                        //06-12-15|0x0280
        }                                                                                 //06-12-15|0x0280
        break;                                                                            //06-12-15|0x0280
//***************************************************************************             //06-12-15|0x0281
      case 59089: // REPORT_SUMMARY                                                       //06-12-15|0x0282
        switch(report_summaries())                                                        //06-12-15|0x0282
        {                                                                                 //06-12-15|0x0282
          case Success:                                                                   //06-12-15|0x0282
            BaseState = 21600; // REPORT_ACTIVE                                           //06-12-15|0x0282
            BaseStatus = Display;                                                         //06-12-15|0x0282
            BaseRunFlag = 0;                                                              //06-12-15|0x0282
            break;                                                                        //06-12-15|0x0282
          default:                                                                        //06-12-15|0x0282
            BaseStatus = SystemError;                                                     //06-12-15|0x0282
            BaseRunFlag = 0;                                                              //06-12-15|0x0282
            SystemMsg;                                                                    //06-12-15|0x0282
            break;                                                                        //06-12-15|0x0282
        }                                                                                 //06-12-15|0x0282
        break;                                                                            //06-12-15|0x0282
//***************************************************************************             //06-12-15|0x0283
      case 21600: // REPORT_ACTIVE                                                        //06-12-15|0x0284
        switch(report_active())                                                           //06-12-15|0x0284
        {                                                                                 //06-12-15|0x0284
          case Success:                                                                   //06-12-15|0x0284
            BaseState = 39647; // ERRORS_EXIST                                            //06-12-15|0x0284
            BaseStatus = Display;                                                         //06-12-15|0x0284
            BaseRunFlag = 0;                                                              //06-12-15|0x0284
            break;                                                                        //06-12-15|0x0284
          default:                                                                        //06-12-15|0x0284
            BaseStatus = SystemError;                                                     //06-12-15|0x0284
            BaseRunFlag = 0;                                                              //06-12-15|0x0284
            SystemMsg;                                                                    //06-12-15|0x0284
            break;                                                                        //06-12-15|0x0284
        }                                                                                 //06-12-15|0x0284
        break;                                                                            //06-12-15|0x0284
//***************************************************************************             //06-12-15|0x0285
      case 39647: // ERRORS_EXIST                                                         //06-12-16|0x0286
        switch(ReportErrorsExists)                                                        //06-12-16|0x0286
        {                                                                                 //06-12-16|0x0286
          case Yes:                                                                       //06-12-16|0x0286
            BaseRunFlag = 1;                                                              //06-12-16|0x0286
            BaseState = 18766; // REPORT_ERRORS                                           //06-12-16|0x0286
            break;                                                                        //06-12-16|0x0286
          case No:                                                                        //06-12-16|0x0286
            BaseRunFlag = 1;                                                              //06-12-16|0x0286
            BaseState = 28788; // OK                                                      //06-12-16|0x0286
            break;                                                                        //06-12-16|0x0286
          default:                                                                        //06-12-16|0x0286
            BaseStatus = SystemError;                                                     //06-12-16|0x0286
            BaseRunFlag = 0;                                                              //06-12-16|0x0286
            SystemMsg;                                                                    //06-12-16|0x0286
            break;                                                                        //06-12-16|0x0286
        }                                                                                 //06-12-16|0x0286
        break;                                                                            //06-12-16|0x0286
//---------------------------------------------------------------------------             //06-12-16|0x0287
      case 18766: // REPORT_ERRORS                                                        //06-12-16|0x0288
        switch(report_error())                                                            //06-12-16|0x0288
        {                                                                                 //06-12-16|0x0288
          case Success:                                                                   //06-12-16|0x0288
            BaseState = 57005; // ERRORS_REPORTED                                         //06-12-16|0x0288
            BaseStatus = Display;                                                         //06-12-16|0x0288
            BaseRunFlag = 0;                                                              //06-12-16|0x0288
            break;                                                                        //06-12-16|0x0288
          default:                                                                        //06-12-16|0x0288
            BaseStatus = SystemError;                                                     //06-12-16|0x0288
            BaseRunFlag = 0;                                                              //06-12-16|0x0288
            SystemMsg;                                                                    //06-12-16|0x0288
            break;                                                                        //06-12-16|0x0288
        }                                                                                 //06-12-16|0x0288
        break;                                                                            //06-12-16|0x0288
//***************************************************************************             //06-12-09|0x0289
//******                                                               ******             //06-12-09|0x028a
//******  EXIT CONDITIONS                                              ******             //06-12-09|0x028b
//******                                                               ******             //06-12-09|0x028c
//***************************************************************************             //06-12-09|0x028d
      case 15308: // USR_POP                                                              //06-12-15|0x028e
        switch(CallPrePop())                                                              //06-12-15|0x028e
        {                                                                                 //06-12-15|0x028e
          case Success:                                                                   //06-12-15|0x028e
            BaseRunFlag = 1;                                                              //06-12-15|0x028e
            BaseState = 55081; // USER                                                    //06-12-15|0x028e
            break;                                                                        //06-12-15|0x028e
          default:                                                                        //06-12-15|0x028e
            BaseStatus = SystemError;                                                     //06-12-15|0x028e
            BaseRunFlag = 0;                                                              //06-12-15|0x028e
            SystemMsg;                                                                    //06-12-15|0x028e
            break;                                                                        //06-12-15|0x028e
        }                                                                                 //06-12-15|0x028e
        break;                                                                            //06-12-15|0x028e
//***************************************************************************             //06-12-09|0x028f
      case 57005: // ERRORS_REPORTED                                                      //06-12-12|0x0290
        BaseState = 2286; // INITIAL_SYSTEM                                               //06-12-12|0x0290
        BaseStatus = Success;                                                             //06-12-12|0x0290
        BaseRunFlag = 0;                                                                  //06-12-12|0x0290
        break;                                                                            //06-12-12|0x0290
      case 28788: // OK                                                                   //06-12-12|0x0291
        BaseState = 2286; // INITIAL_SYSTEM                                               //06-12-12|0x0291
        BaseStatus = Success;                                                             //06-12-12|0x0291
        BaseRunFlag = 0;                                                                  //06-12-12|0x0291
        break;                                                                            //06-12-12|0x0291
//---------------------------------------------------------------------------             //06-12-09|0x0292
      case 55081: // USER                                                                 //06-12-09|0x0293
        BaseState = 2286; // INITIAL_SYSTEM                                               //06-12-09|0x0293
        BaseStatus = UserError;                                                           //06-12-09|0x0293
        BaseRunFlag = 0;                                                                  //06-12-09|0x0293
        break;                                                                            //06-12-09|0x0293
//***************************************************************************             //06-12-09|0x0294
//******                                                               ******             //06-12-09|0x0295
//******  STATE MACHINE ENDS                                           ******             //06-12-09|0x0296
//******                                                               ******             //06-12-09|0x0297
//***************************************************************************             //06-12-09|0x0298
      default:                                                                            //06-12-09|0x0299
        BaseStatus = SystemError;                                                         //06-12-09|0x0299
        BaseRunFlag = 0;                                                                  //06-12-09|0x0299
        SystemMsg;                                                                        //06-12-09|0x0299
        break;                                                                            //06-12-09|0x0299
    }                                                                                     //06-12-09|0x0299
  }                                                                                       //06-12-09|0x0299
//***************************************************************************             //06-12-09|0x029a
    return(BaseStatus);                                                                   //06-12-09|0x029b
}                                                                                         //06-12-09|0x029c
//                                                                                        //05-24-97|0x029c
//***************************************************************************             //06-12-09|0x029f
//***************************************************************************             //06-12-09|0x02a0
//******                                                               ******             //06-12-09|0x02a1
//******                     initial                                   ******             //06-12-09|0x02a2
//******                                                               ******             //06-12-09|0x02a3
//***************************************************************************             //06-12-09|0x02a4
//***************************************************************************             //06-12-09|0x02a5
//*******************************************************************************         //10-29-97|0x02a9
//*******************************************************************************         //10-29-97|0x02a9
// initial                                                                                //06-12-09|0x02a9
//*******************************************************************************         //10-29-97|0x02a9
//*******************************************************************************         //10-29-97|0x02a9
UINT TESTPROJ::initial(void) {                                                            //06-12-09|0x02a9
//*******************************************************************************         //10-29-97|0x02a9
//***************************************************************************             //06-12-09|0x02ac
//***************************************************************************             //06-12-09|0x02ad
    MemSet(BaseDataAddr,        0x00,  sizeof(TEST_DATA));                                //06-12-09|0x02ae
    MemSet(BaseReportAddr,      0x00,  sizeof(TOKENS));                                   //06-12-09|0x02af
    MemSet(BaseDrivePathAddr,   0x00,  sizeof(TOKENS));                                   //06-12-09|0x02b0
    BaseDisplayFlag   = 1;                                                                //06-07-12|0x02b1
    DataBitOffset     = -1;                                                               //07-12-28|0x02b2
    return_test(initial_1);                                                               //06-12-09|0x02b3
}                                                                                         //06-12-09|0x02b4
//                                                                                        //05-24-97|0x02b4
//***************************************************************************             //06-12-09|0x02b7
//***************************************************************************             //06-12-09|0x02b8
//******                                                               ******             //06-12-09|0x02b9
//******                     enter_project_name                        ******             //06-12-09|0x02ba
//******                                                               ******             //06-12-09|0x02bb
//***************************************************************************             //06-12-09|0x02bc
//***************************************************************************             //06-12-09|0x02bd
//*******************************************************************************         //10-29-97|0x02be
//*******************************************************************************         //10-29-97|0x02be
// enter_project_name                                                                     //06-12-09|0x02be
//*******************************************************************************         //10-29-97|0x02be
//*******************************************************************************         //10-29-97|0x02be
UINT TESTPROJ::enter_project_name(                                                        //06-12-09|0x02be
    SCHAR_FAR NameAddr                                                                    //06-12-09|0x02be
    ) {                                                                                   //06-12-09|0x02be
//*******************************************************************************         //10-29-97|0x02be
//**********************************************************************                  //06-12-09|0x02be
//**********************************************************************                  //06-12-09|0x02be
    switch(InitialProjFile) _SwitchGroup                                                  //06-12-09|0x02be
    switch(FileEnterName(NameAddr, TMK_EXTENT)) _SwitchGroup                              //06-12-09|0x02be
    switch(FileRelease()) _SwitchGroup                                                    //06-12-09|0x02be
//**********************************************************************                  //06-12-09|0x02be
    return_test(enter_project_name_1);                                                    //06-12-09|0x02be
}                                                                                         //06-12-09|0x02be
//                                                                                        //05-24-97|0x02be
//***************************************************************************             //06-12-09|0x02c1
//***************************************************************************             //06-12-09|0x02c2
//******                                                               ******             //06-12-09|0x02c3
//******                       project_exists                          ******             //06-12-09|0x02c4
//******                                                               ******             //06-12-09|0x02c5
//***************************************************************************             //06-12-09|0x02c6
//***************************************************************************             //06-12-09|0x02c7
//*******************************************************************************         //10-29-97|0x02cb
//*******************************************************************************         //10-29-97|0x02cb
// project_exists                                                                         //07-10-13|0x02cb
//*******************************************************************************         //10-29-97|0x02cb
//*******************************************************************************         //10-29-97|0x02cb
UINT TESTPROJ::project_exists(                                                            //07-10-13|0x02cb
    ULONG MainProjTime                                                                    //07-10-13|0x02cb
    ) {                                                                                   //07-10-13|0x02cb
//*******************************************************************************         //10-29-97|0x02cb
//***************************************************************************             //06-08-09|0x02ce
//***************************************************************************             //06-08-09|0x02cf
    switch(CommitProjFile)                                       _SwitchGroup             //06-08-09|0x02d0
    switch(FileExists(BaseTestTimeAddr))                         _SwitchGroup             //07-10-13|0x02d1
    switch(FileRelease())                                        _SwitchGroup             //06-08-09|0x02d2
//***************************************************************************             //06-08-09|0x02d3
    switch(BaseTestTime)                                                                  //06-08-09|0x02d4
      {                                                                                   //06-08-09|0x02d5
        case  0:                                           return(UserError);             //06-08-09|0x02d6
        default:                                                       break;             //07-10-13|0x02d7
        }                                                                                 //06-08-09|0x02d8
//***************************************************************************             //06-08-09|0x02d9
    if(MainProjTime > BaseTestTime)                                                       //07-10-13|0x02da
      {                                                                                   //07-10-13|0x02db
        BaseTestTime = MainProjTime;                                                      //07-10-13|0x02dc
        }                                                                                 //07-10-13|0x02dd
    return_test(project_exists_1);                                                        //07-10-13|0x02de
}                                                                                         //06-08-09|0x02df
//                                                                                        //05-24-97|0x02df
//***************************************************************************             //06-12-09|0x02e2
//***************************************************************************             //06-12-09|0x02e3
//******                                                               ******             //06-12-09|0x02e4
//******                          open_project                         ******             //06-12-09|0x02e5
//******                                                               ******             //06-12-09|0x02e6
//***************************************************************************             //06-12-09|0x02e7
//***************************************************************************             //06-12-09|0x02e8
//*******************************************************************************         //10-29-97|0x02e9
//*******************************************************************************         //10-29-97|0x02e9
// open_project                                                                           //06-12-09|0x02e9
//*******************************************************************************         //10-29-97|0x02e9
//*******************************************************************************         //10-29-97|0x02e9
UINT TESTPROJ::open_project(void) {                                                       //06-12-09|0x02e9
//*******************************************************************************         //10-29-97|0x02e9
//**********************************************************************                  //06-12-09|0x02e9
//**********************************************************************                  //06-12-09|0x02e9
    switch(CommitProjFile) _SwitchGroup                                                   //06-12-09|0x02e9
    switch(FileOpenText()) _SwitchGroup                                                   //06-12-09|0x02e9
    switch(FileRelease()) _SwitchGroup                                                    //06-12-09|0x02e9
//**********************************************************************                  //06-12-09|0x02e9
    return_test(open_project_1);                                                          //06-12-09|0x02e9
}                                                                                         //06-12-09|0x02e9
//                                                                                        //05-24-97|0x02e9
//***************************************************************************             //06-12-09|0x02ec
//***************************************************************************             //06-12-09|0x02ed
//******                                                               ******             //06-12-09|0x02ee
//******                          read_project                         ******             //06-12-09|0x02ef
//******                                                               ******             //06-12-09|0x02f0
//***************************************************************************             //06-12-09|0x02f1
//***************************************************************************             //06-12-09|0x02f2
//*******************************************************************************         //10-29-97|0x02f3
//*******************************************************************************         //10-29-97|0x02f3
// read_project                                                                           //06-12-09|0x02f3
//*******************************************************************************         //10-29-97|0x02f3
//*******************************************************************************         //10-29-97|0x02f3
UINT TESTPROJ::read_project(void) {                                                       //06-12-09|0x02f3
//*******************************************************************************         //10-29-97|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
  UINT status;                                                                       //06-12-09|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
    switch(CommitProjFile) _SwitchGroup                                                   //06-12-09|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
    status = FileReadText(BaseTokensAddr);                                                //06-12-09|0x02f3
//----------------------------------------------------------------------                  //06-12-09|0x02f3
    switch(status)                                                                        //06-12-09|0x02f3
      {                                                                                   //06-12-09|0x02f3
        case FileDone:                                 break_test(read_project_1);        //06-12-09|0x02f3
        case LineDone:                                 break_test(read_project_2);        //06-12-09|0x02f3
        case UserError:                                break_test(read_project_3);        //06-12-09|0x02f3
        case Display:                                  break_test(read_project_4);        //06-12-09|0x02f3
        default:                                       ReturnSystemError                  //06-12-09|0x02f3
        }                                                                                 //06-12-09|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
    switch(FileRelease()) _SwitchGroup                                                    //06-12-09|0x02f3
//**********************************************************************                  //06-12-09|0x02f3
    return(status);                                                                       //06-12-09|0x02f3
}                                                                                         //06-12-09|0x02f3
//                                                                                        //05-24-97|0x02f3
//***************************************************************************             //06-12-09|0x02f6
//***************************************************************************             //06-12-09|0x02f7
//******                                                               ******             //06-12-09|0x02f8
//******                        basic_configure                        ******             //06-12-09|0x02f9
//******                                                               ******             //06-12-09|0x02fa
//***************************************************************************             //06-12-09|0x02fb
//***************************************************************************             //06-12-09|0x02fc
//*******************************************************************************         //10-29-97|0x0300
//*******************************************************************************         //10-29-97|0x0300
// basic_configure                                                                        //06-12-09|0x0300
//*******************************************************************************         //10-29-97|0x0300
//*******************************************************************************         //10-29-97|0x0300
UINT TESTPROJ::basic_configure(                                                           //06-12-09|0x0300
    SINT flag                                                                             //06-12-09|0x0300
    ) {                                                                                   //06-12-09|0x0300
//*******************************************************************************         //10-29-97|0x0300
//***************************************************************************             //06-12-09|0x0303
//***************************************************************************             //06-12-09|0x0304
  WORDS work;                                                                        //06-12-09|0x0305
  UINT index;                                                                        //06-12-09|0x0306
//***************************************************************************             //06-12-09|0x0307
//***************************************************************************             //06-12-09|0x0308
    TestSample(basic_configure_1);                                                        //06-12-09|0x0309
//---------------------------------------------------------------------------             //06-12-09|0x030a
    if(TokensNoTokens != 3)            ReturnFinish("Illegal No Parameters");             //06-12-09|0x030b
//---------------------------------------------------------------------------             //06-12-09|0x030c
    work.ulong = 0;                                                                       //06-12-09|0x030d
    IfTokenToInt(1, work.ulong)       ReturnFinish("Index Conversion Error");             //06-12-09|0x030e
//---------------------------------------------------------------------------             //06-12-09|0x030f
    if(work.ulong >= 128)    ReturnFinish("Character Position Out Of Range");             //06-12-09|0x0310
    index = work.word0;                                                                   //06-12-09|0x0311
//---------------------------------------------------------------------------             //06-12-09|0x0312
    if(DataTestFlag(index) != 0)          ReturnFinish("Previously Defined");             //06-12-09|0x0313
    DataTestFlag(index) = flag;                                                           //06-12-09|0x0314
//---------------------------------------------------------------------------             //06-12-09|0x0315
    work.ulong = 0;                                                                       //06-12-09|0x0316
    IfTokenToInt(2, work.ulong)   ReturnFinish("Threshold Conversion Error");             //06-12-09|0x0317
    if(work.ulong >  256)             ReturnFinish("Threshold Out Of Range");             //06-12-09|0x0318
    DataThreshold(index) = work.word0;                                                    //06-12-09|0x0319
//---------------------------------------------------------------------------             //06-12-09|0x031a
    return(Success);                                                                      //06-12-09|0x031b
}                                                                                         //06-12-09|0x031c
//                                                                                        //05-24-97|0x031c
//***************************************************************************             //06-12-11|0x031f
//***************************************************************************             //06-12-11|0x0320
//******                                                               ******             //06-12-11|0x0321
//******                          drive_path                           ******             //06-12-11|0x0322
//******                                                               ******             //06-12-11|0x0323
//***************************************************************************             //06-12-11|0x0324
//***************************************************************************             //06-12-11|0x0325
//*******************************************************************************         //10-29-97|0x0326
//*******************************************************************************         //10-29-97|0x0326
// drive_path                                                                             //06-12-11|0x0326
//*******************************************************************************         //10-29-97|0x0326
//*******************************************************************************         //10-29-97|0x0326
UINT TESTPROJ::drive_path(void) {                                                         //06-12-11|0x0326
//*******************************************************************************         //10-29-97|0x0326
//***********************************************************************                 //06-12-11|0x0326
//***********************************************************************                 //06-12-11|0x0326
    IfNoTokens(2, 10)              ReturnFinish("Illegal No Parameters");                 //06-12-11|0x0326
//-----------------------------------------------------------------------                 //06-12-11|0x0326
    MemCpy(BaseDrivePathAddr,   BaseTokensAddr,  sizeof(TOKENS));                         //06-12-11|0x0326
//-----------------------------------------------------------------------                 //06-12-11|0x0326
    switch(TokensPrepare(BaseDrivePathAddr, 1))                         _SwitchGroup      //06-12-11|0x0326
//***********************************************************************                 //06-12-11|0x0326
    return_test(drive_path_1);                                                            //06-12-11|0x0326
}                                                                                         //06-12-11|0x0326
//                                                                                        //05-24-97|0x0326
//***************************************************************************             //06-12-11|0x0329
//***************************************************************************             //06-12-11|0x032a
//******                                                               ******             //06-12-11|0x032b
//******                          pcg_name                             ******             //06-12-11|0x032c
//******                                                               ******             //06-12-11|0x032d
//***************************************************************************             //06-12-11|0x032e
//***************************************************************************             //06-12-11|0x032f
//***************************************************************************             //06-12-11|0x0331
//***************************************************************************             //06-12-11|0x0332
//*******************************************************************************         //10-29-97|0x0335
//*******************************************************************************         //10-29-97|0x0335
// pcg_name                                                                               //06-12-11|0x0335
//*******************************************************************************         //10-29-97|0x0335
//*******************************************************************************         //10-29-97|0x0335
UINT TESTPROJ::pcg_name(                                                                  //06-12-11|0x0335
    TOKENS_FAR PcgTokensFar                                                               //06-12-11|0x0335
    ) {                                                                                   //06-12-11|0x0335
//*******************************************************************************         //10-29-97|0x0335
//***************************************************************************             //06-12-11|0x0338
//***************************************************************************             //06-12-11|0x0339
    TestSample(pcg_mame_1);                                                               //06-12-11|0x033a
//---------------------------------------------------------------------------             //06-12-11|0x033b
    IfNoTokens(2, 2)                   ReturnFinish("Illegal No Parameters");             //06-12-11|0x033c
    TokenDataClr(PcgTokensFar);                                                           //06-12-11|0x033d
    switch(TokensPrepare(BaseTokensAddr, 1))                     _SwitchGroup             //06-12-11|0x033e
    StrDataCpy(PcgTokenAddr(0), TokensTokenAddr(1));                                      //06-12-11|0x033f
    PcgNoTokens = 1;                                                                      //06-12-11|0x0340
    return(Success);                                                                      //06-12-11|0x0341
}                                                                                         //06-12-11|0x0342
//                                                                                        //05-24-97|0x0342
//***************************************************************************             //06-12-15|0x0345
//***************************************************************************             //06-12-16|0x0346
//******                                                               ******             //06-12-16|0x0347
//******                        spawn_name                             ******             //06-12-16|0x0348
//******                                                               ******             //06-12-16|0x0349
//***************************************************************************             //06-12-16|0x034a
//***************************************************************************             //06-12-16|0x034b
//***************************************************************************             //06-12-16|0x034d
//***************************************************************************             //06-12-16|0x034e
//*******************************************************************************         //10-29-97|0x0351
//*******************************************************************************         //10-29-97|0x0351
// spawn_name                                                                             //06-12-16|0x0351
//*******************************************************************************         //10-29-97|0x0351
//*******************************************************************************         //10-29-97|0x0351
UINT TESTPROJ::spawn_name(                                                                //06-12-16|0x0351
    SCHAR_FAR Addr,                                                                       //06-12-16|0x0351
    UINT MinParms                                                                         //06-12-16|0x0351
    ) {                                                                                   //06-12-16|0x0351
//*******************************************************************************         //10-29-97|0x0351
//***************************************************************************             //06-12-16|0x0354
//***************************************************************************             //06-12-16|0x0355
    WORDS work;                                                                      //06-12-16|0x0356
//***************************************************************************             //06-12-16|0x0357
    TestSample(spawn_mame_1);                                                             //06-12-16|0x0358
//---------------------------------------------------------------------------             //06-12-16|0x0359
    IfNoTokens(MinParms, 9)            ReturnFinish("Illegal No Parameters");             //06-12-16|0x035a
    switch(TokensPrepare(BaseTokensAddr, 1))                     _SwitchGroup             //06-12-16|0x035b
//---------------------------------------------------------------------------             //06-12-16|0x035c
    work.ulong = 0;                                                                       //06-12-16|0x035d
    if(TokensLength(1)    == 0)                             ReturnSystemError             //06-12-16|0x035e
    if(TokensLength(1)    >  256)                           ReturnSystemError             //06-12-16|0x035f
    StrCpy(Addr,  TokensLineAddr(1));                                                     //06-12-16|0x0360
    work.ulong = StrLen(Addr);                                                            //06-12-16|0x0361
    if(TokensLength(1) != work.sint0)                       ReturnSystemError             //06-12-16|0x0362
    return(Success);                                                                      //06-12-16|0x0363
}                                                                                         //06-12-16|0x0364
//                                                                                        //05-24-97|0x0364
//***************************************************************************             //06-12-16|0x0367
//***************************************************************************             //06-12-16|0x0368
//******                                                               ******             //06-12-16|0x0369
//******                        spawn_parms                            ******             //06-12-16|0x036a
//******                                                               ******             //06-12-16|0x036b
//***************************************************************************             //06-12-16|0x036c
//***************************************************************************             //06-12-16|0x036d
//***************************************************************************             //06-12-16|0x036f
//***************************************************************************             //06-12-16|0x0370
//*******************************************************************************         //10-29-97|0x0373
//*******************************************************************************         //10-29-97|0x0373
// spawn_parms                                                                            //06-12-16|0x0373
//*******************************************************************************         //10-29-97|0x0373
//*******************************************************************************         //10-29-97|0x0373
UINT TESTPROJ::spawn_parms(                                                               //06-12-16|0x0373
    SCHAR_FAR Addr,                                                                       //06-12-16|0x0373
    UINT token_no                                                                         //06-12-16|0x0373
    ) {                                                                                   //06-12-16|0x0373
//*******************************************************************************         //10-29-97|0x0373
//***************************************************************************             //06-12-16|0x0376
//***************************************************************************             //06-12-16|0x0377
  SLONG space;                                                                       //06-12-16|0x0378
  ULONG size;                                                                        //06-12-16|0x0379
  WORDS total_size;                                                                  //06-12-16|0x037a
  SCHAR_FAR out_addr;                                                                //06-12-16|0x037b
  SCHAR_FAR in_addr;                                                                 //06-12-16|0x037c
//***************************************************************************             //06-12-16|0x037d
//***************************************************************************             //06-12-16|0x037e
    TestSample(spawn_parms_1);                                                            //06-12-16|0x037f
//***************************************************************************             //06-12-16|0x0380
//***************************************************************************             //06-12-16|0x0381
    MemSet(Addr, 0, 1025);                                                                //06-12-16|0x0382
    StrCpy(Addr, "  ");                                                                   //06-12-16|0x0383
    if(token_no >= TokensNoTokens)                                                        //06-12-16|0x0384
                                                             return(Success);             //06-12-16|0x0385
//---------------------------------------------------------------------------             //06-12-16|0x0386
    total_size.ulong  = 0;                                                                //06-12-16|0x0387
//***************************************************************************             //06-12-16|0x0388
//***                                                                   *****             //06-12-16|0x0389
//*** PROCESS EACH OF THE TOKENS                                        *****             //06-12-16|0x038a
//***                                                                   *****             //06-12-16|0x038b
//***************************************************************************             //06-12-16|0x038c
loop:                                                                                     //06-12-16|0x038d
        size = TokensLength(token_no);                                                    //06-12-16|0x038e
        if(size == 0)                                       ReturnSystemError             //06-12-16|0x038f
        if(size  > 256)                                     ReturnSystemError             //06-12-16|0x0390
        if(TokensChar(token_no, size) != 0)                 ReturnSystemError             //06-12-16|0x0391
//---------------------------------------------------------------------------             //06-12-16|0x0392
        in_addr   = TokensLineAddr(token_no);                                             //06-12-16|0x0393
        out_addr  = Addr + total_size.ulong;                                              //06-12-16|0x0394
        if((space = 1024 - total_size.slong) <= 0)          ReturnSystemError             //06-12-16|0x0395
//---------------------------------------------------------------------------             //06-12-16|0x0396
        if(MemCCpy(out_addr, in_addr, 0x00, space) == 0)                                  //06-12-16|0x0397
                                         ReturnFinish("Parameter Too Large");             //06-12-16|0x0398
//---------------------------------------------------------------------------             //06-12-16|0x0399
        if((total_size.ulong += size) != StrLen(Addr))      ReturnSystemError             //06-12-16|0x039a
//***************************************************************************             //06-12-16|0x039b
//***                                                                   *****             //06-12-16|0x039c
//*** EXIT IF WE ARE DONE                                               *****             //06-12-16|0x039d
//***                                                                   *****             //06-12-16|0x039e
//***************************************************************************             //06-12-16|0x039f
        if((++token_no) >= TokensNoTokens)                                                //06-12-16|0x03a0
                                                             return(Success);             //06-12-16|0x03a1
//***************************************************************************             //06-12-16|0x03a2
//***                                                                   *****             //06-12-16|0x03a3
//*** INSERT A BLANK CHARACTER                                          *****             //06-12-16|0x03a4
//***                                                                   *****             //06-12-16|0x03a5
//***************************************************************************             //06-12-16|0x03a6
        if((space = 1024 - total_size.slong) <= 1)          ReturnSystemError             //06-12-16|0x03a7
        out_addr  = Addr + total_size.ulong;                                              //06-12-16|0x03a8
//---------------------------------------------------------------------------             //06-12-16|0x03a9
        *out_addr = ' ';                                                                  //06-12-16|0x03aa
//---------------------------------------------------------------------------             //06-12-16|0x03ab
        if((total_size.ulong += 1) != StrLen(Addr))         ReturnSystemError             //06-12-16|0x03ac
        goto loop;                                                                        //06-12-16|0x03ad
}                                                                                         //06-12-16|0x03ae
//                                                                                        //05-24-97|0x03ae
//***************************************************************************             //06-12-16|0x03b1
//***************************************************************************             //06-12-16|0x03b2
//******                                                               ******             //06-12-16|0x03b3
//******                        spawn_exit_codes                       ******             //06-12-16|0x03b4
//******                                                               ******             //06-12-16|0x03b5
//***************************************************************************             //06-12-16|0x03b6
//***************************************************************************             //06-12-16|0x03b7
//***************************************************************************             //06-12-16|0x03ba
//***************************************************************************             //06-12-16|0x03bb
//*******************************************************************************         //10-29-97|0x03be
//*******************************************************************************         //10-29-97|0x03be
// spawn_exit_codes                                                                       //06-12-16|0x03be
//*******************************************************************************         //10-29-97|0x03be
//*******************************************************************************         //10-29-97|0x03be
UINT TESTPROJ::spawn_exit_codes(                                                          //06-12-16|0x03be
    EXIT_CODE_FAR ExitCodesAddr,                                                          //06-12-16|0x03be
    SLONG exit_code                                                                       //06-12-16|0x03be
    ) {                                                                                   //06-12-16|0x03be
//*******************************************************************************         //10-29-97|0x03be
  ULONG i;                                                                           //06-12-16|0x03c1
  WORDS work;                                                                        //06-12-16|0x03c2
//***************************************************************************             //06-12-16|0x03c3
    if(TokensNoTokens > 9)                                  ReturnSystemError             //06-12-16|0x03c4
//***************************************************************************             //06-12-16|0x03c5
    if(TokensNoTokens == 1)                                                               //06-12-16|0x03c6
      {                                                                                   //06-12-16|0x03c7
        ExitCodesNoExitCodes = 1;                                                         //06-12-16|0x03c8
        ExitCodesExitCode(0) = exit_code;                                                 //06-12-16|0x03c9
        return_test(spawn_exit_codes_1);                                                  //06-12-16|0x03ca
        }                                                                                 //06-12-16|0x03cb
//***************************************************************************             //06-12-16|0x03cc
    ExitCodesNoExitCodes = 0;                                                             //06-12-16|0x03cd
    for(i=1; i<TokensNoTokens; ++i)                                                       //06-12-16|0x03ce
      {                                                                                   //06-12-16|0x03cf
        IfTokenToInt(i, work.ulong)         ReturnFinish("Conversion Error");             //06-12-16|0x03d0
        if(work.word1 != 0)              ReturnFinish("Status Out Of Range");             //06-12-16|0x03d1
        ExitCodesExitCode(ExitCodesNoExitCodes) = work.slong;                             //06-12-16|0x03d2
        ++ExitCodesNoExitCodes;                                                           //06-12-16|0x03d3
        }                                                                                 //06-12-16|0x03d4
    return_test(spawn_exit_codes_2);                                                      //06-12-16|0x03d5
}                                                                                         //06-12-16|0x03d6
//                                                                                        //05-24-97|0x03d6
//***************************************************************************             //06-12-17|0x03d9
//***************************************************************************             //06-12-17|0x03da
//******                                                               ******             //06-12-17|0x03db
//******                        cleanup_names                          ******             //06-12-17|0x03dc
//******                                                               ******             //06-12-17|0x03dd
//***************************************************************************             //06-12-17|0x03de
//***************************************************************************             //06-12-17|0x03df
//***************************************************************************             //06-12-17|0x03e1
//***************************************************************************             //06-12-17|0x03e2
//*******************************************************************************         //10-29-97|0x03e5
//*******************************************************************************         //10-29-97|0x03e5
// cleanup_names                                                                          //06-12-17|0x03e5
//*******************************************************************************         //10-29-97|0x03e5
//*******************************************************************************         //10-29-97|0x03e5
UINT TESTPROJ::cleanup_names(void) {                                                      //06-12-17|0x03e5
//*******************************************************************************         //10-29-97|0x03e5
//***************************************************************************             //06-12-17|0x03e8
//***************************************************************************             //06-12-17|0x03e9
    if(TokensNoTokens < 2)             ReturnFinish("Illegal No Parameters");             //06-12-17|0x03ea
//---------------------------------------------------------------------------             //06-12-17|0x03eb
    switch(TokensPrepare(BaseTokensAddr, 1))                     _SwitchGroup             //06-12-17|0x03ec
    MemCpy(DataCleanupAddr, BaseTokensAddr,  sizeof(TOKENS));                             //06-12-17|0x03ed
//---------------------------------------------------------------------------             //06-12-17|0x03ee
    return_test(cleanup_names_1);                                                         //06-12-17|0x03ef
}                                                                                         //06-12-17|0x03f0
//                                                                                        //05-24-97|0x03f0
//***************************************************************************             //06-12-11|0x03f3
//***************************************************************************             //06-12-11|0x03f4
//******                                                               ******             //06-12-11|0x03f5
//******                        set_generator                          ******             //06-12-11|0x03f6
//******                                                               ******             //06-12-11|0x03f7
//***************************************************************************             //06-12-11|0x03f8
//***************************************************************************             //06-12-11|0x03f9
//*******************************************************************************         //10-29-97|0x03fd
//*******************************************************************************         //10-29-97|0x03fd
// set_generator                                                                          //06-12-11|0x03fd
//*******************************************************************************         //10-29-97|0x03fd
//*******************************************************************************         //10-29-97|0x03fd
UINT TESTPROJ::set_generator(void) {                                                      //06-12-11|0x03fd
//*******************************************************************************         //10-29-97|0x03fd
//***************************************************************************             //06-12-11|0x0400
//***************************************************************************             //06-12-11|0x0401
  WORDS work;                                                                        //06-12-11|0x0402
//***************************************************************************             //06-12-11|0x0403
//***************************************************************************             //06-12-11|0x0404
    if(TokensNoTokens != 4)            ReturnFinish("Illegal No Parameters");             //06-12-11|0x0405
//---------------------------------------------------------------------------             //06-12-11|0x0406
    work.ulong = 0;                                                                       //06-12-11|0x0407
    IfTokenToInt(1, work.ulong)  ReturnFinish("Test Count Conversion Error");             //06-12-11|0x0408
    DataNoTests = work.word0;                                                             //06-12-11|0x0409
//---------------------------------------------------------------------------             //06-12-11|0x040a
    if(TokensLength(2) != 16)       ReturnFinish("Illegal Random Seed Size");             //06-12-11|0x040b
    InitialRandom;                                                                        //15-06-16|0x040c
    switch(LoadRandom)                                           _SwitchGroup             //15-06-16|0x040d
//---------------------------------------------------------------------------             //06-12-11|0x040e
    if(TokensLength(3) != 1)       ReturnFinish("Illegal Display Flag Size");             //06-12-11|0x040f
    switch(TokensChar(3,0))                                                               //06-12-11|0x0410
      {                                                                                   //06-12-11|0x0411
        case 'N': BaseDisplayFlag = 0;                              break;                //06-12-11|0x0412
        case 'Y':                                                   break;                //06-12-11|0x0413
        case 'n': BaseDisplayFlag = 0; DataBitOffset = 0;           break;                //07-12-28|0x0414
        case 'y':                      DataBitOffset = 0;           break;                //07-12-28|0x0415
        default:                        ReturnFinish("Illegal Display Flag");             //06-12-11|0x0416
        }                                                                                 //06-12-11|0x0417
    SetDisplayFlag(BaseDisplayFlag);                                                      //06-12-11|0x0418
//---------------------------------------------------------------------------             //06-12-11|0x0419
    return_test(set_generator_1);                                                         //06-12-11|0x041a
}                                                                                         //06-12-11|0x041b
//                                                                                        //05-24-97|0x041b
//***************************************************************************             //06-12-09|0x041e
//***************************************************************************             //06-12-09|0x041f
//******                                                               ******             //06-12-09|0x0420
//******                          close_project                        ******             //06-12-09|0x0421
//******                                                               ******             //06-12-09|0x0422
//***************************************************************************             //06-12-09|0x0423
//***************************************************************************             //06-12-09|0x0424
//*******************************************************************************         //10-29-97|0x0425
//*******************************************************************************         //10-29-97|0x0425
// close_project                                                                          //06-12-09|0x0425
//*******************************************************************************         //10-29-97|0x0425
//*******************************************************************************         //10-29-97|0x0425
UINT TESTPROJ::close_project(void) {                                                      //06-12-09|0x0425
//*******************************************************************************         //10-29-97|0x0425
//**********************************************************************                  //06-12-09|0x0425
//**********************************************************************                  //06-12-09|0x0425
    switch(CommitProjFile)                                  _SwitchGroup                  //06-12-09|0x0425
    switch(FileClose())                                     _SwitchGroup                  //06-12-09|0x0425
    switch(FileRelease())                                   _SwitchGroup                  //06-12-09|0x0425
//**********************************************************************                  //06-12-09|0x0425
    return_test(close_project_1);                                                         //06-12-09|0x0425
}                                                                                         //06-12-09|0x0425
//                                                                                        //05-24-97|0x0425
//***************************************************************************             //06-12-12|0x0428
//***************************************************************************             //06-12-12|0x0429
//******                                                               ******             //06-12-12|0x042a
//******                        cleanup_step                           ******             //06-12-12|0x042b
//******                                                               ******             //06-12-12|0x042c
//***************************************************************************             //06-12-12|0x042d
//***************************************************************************             //06-12-12|0x042e
//*******************************************************************************         //10-29-97|0x0432
//*******************************************************************************         //10-29-97|0x0432
// cleanup_step                                                                           //06-12-12|0x0432
//*******************************************************************************         //10-29-97|0x0432
//*******************************************************************************         //10-29-97|0x0432
UINT TESTPROJ::cleanup_step(void) {                                                       //06-12-12|0x0432
//*******************************************************************************         //10-29-97|0x0432
//***************************************************************************             //06-12-12|0x0435
//***************************************************************************             //06-12-12|0x0436
  WORDS size;                                                                        //06-12-12|0x0437
  ULONG token_no;                                                                    //06-12-12|0x0438
//***************************************************************************             //06-12-12|0x0439
//***************************************************************************             //06-12-12|0x043a
    for(token_no=1; token_no<CleanupNoTokens; ++token_no)                                 //06-12-12|0x043b
      {                                                                                   //06-12-17|0x043c
        if(CleanupChar(token_no,256) != 0)                 ReturnSystemError;             //06-12-17|0x043d
        size.slong = StrLen(CleanupLineAddr(token_no));                                   //06-12-17|0x043e
        if(size.word0 != CleanupLength(token_no))          ReturnSystemError;             //06-12-17|0x043f
//---------------------------------------------------------------------------             //06-12-17|0x0440
        switch(basic_cleanup(CleanupLineAddr(token_no)))         _SwitchGroup             //06-12-17|0x0441
        }                                                                                 //06-12-12|0x0442
//***************************************************************************             //06-12-12|0x0443
    return(Success);                                                                      //06-12-12|0x0444
}                                                                                         //06-12-12|0x0445
//                                                                                        //05-24-97|0x0445
//***************************************************************************             //06-12-17|0x0448
//***************************************************************************             //06-12-17|0x0449
//******                                                               ******             //06-12-17|0x044a
//******                        basic_cleanup                          ******             //06-12-17|0x044b
//******                                                               ******             //06-12-17|0x044c
//***************************************************************************             //06-12-17|0x044d
//***************************************************************************             //06-12-17|0x044e
//*******************************************************************************         //10-29-97|0x0452
//*******************************************************************************         //10-29-97|0x0452
// basic_cleanup                                                                          //06-12-17|0x0452
//*******************************************************************************         //10-29-97|0x0452
//*******************************************************************************         //10-29-97|0x0452
UINT TESTPROJ::basic_cleanup(                                                             //06-12-17|0x0452
    SCHAR_FAR Addr                                                                        //06-12-17|0x0452
    ) {                                                                                   //06-12-17|0x0452
//*******************************************************************************         //10-29-97|0x0452
//***************************************************************************             //06-12-17|0x0455
//***************************************************************************             //06-12-17|0x0456
    if(remove(Addr) == -1)                                                                //06-12-17|0x0457
      {                                                                                   //06-12-17|0x0457
        switch(errno)                                                                     //06-12-17|0x0457
          {                                                                               //06-12-17|0x0457
            case 13:      ReturnFinish("CLEANUP -- FILE IN USE");                         //06-12-17|0x0457
            case 2:                                                break;                 //06-12-17|0x0457
            case 22:      ReturnFinish("CLEANUP -- INVALID NAME");                        //06-12-17|0x0457
            default:                                   ReturnSystemError;                 //06-12-17|0x0457
            }                                                                             //06-12-17|0x0457
        }                                                                                 //06-12-17|0x0457
//***************************************************************************             //06-12-17|0x0458
    return_test(basic_cleanup_1);                                                         //06-12-17|0x0459
}                                                                                         //06-12-17|0x045a
//                                                                                        //05-24-97|0x045a
//***************************************************************************             //06-12-12|0x045d
//***************************************************************************             //06-12-12|0x045e
//******                                                               ******             //06-12-12|0x045f
//******                        generate_test                          ******             //06-12-12|0x0460
//******                                                               ******             //06-12-12|0x0461
//***************************************************************************             //06-12-12|0x0462
//***************************************************************************             //06-12-12|0x0463
//*******************************************************************************         //10-29-97|0x0467
//*******************************************************************************         //10-29-97|0x0467
// generate_test                                                                          //06-12-12|0x0467
//*******************************************************************************         //10-29-97|0x0467
//*******************************************************************************         //10-29-97|0x0467
UINT TESTPROJ::generate_test(void) {                                                      //06-12-12|0x0467
//*******************************************************************************         //10-29-97|0x0467
//***************************************************************************             //06-12-12|0x046a
//***************************************************************************             //06-12-12|0x046b
  UCHAR work;                                                                        //06-12-12|0x046c
  UINT j;                                                                            //06-12-12|0x046d
  SLONG i;                                                                           //06-12-12|0x046e
  SLONG k;                                                                           //07-12-28|0x046f
  UINT flag;                                                                         //07-12-28|0x0470
//***************************************************************************             //06-12-12|0x0471
//***                                                                    ****             //06-12-12|0x0472
//***  Initial Random Generation Process                                 ****             //06-12-12|0x0473
//***                                                                    ****             //06-12-12|0x0474
//***************************************************************************             //06-12-12|0x0475
    StrDataClr(PrepareTokenAddr(1));                                                      //06-12-12|0x0476
    MemSet(PrepareLineAddr(1), 0x20, 128);                                                //06-12-12|0x0477
//---------------------------------------------------------------------------             //06-12-12|0x0478
    BaseTaskNo        = 0;                                                                //11-12-17|0x0479
//---------------------------------------------------------------------------             //11-12-17|0x047a
    PrepareLength(1)  = 128;                                                              //06-12-12|0x047b
    PrepareType(1)    = I_TOKEN;                                                          //06-12-12|0x047c
    PrepareNoTokens   = 2;                                                                //06-12-12|0x047d
//---------------------------------------------------------------------------             //06-12-12|0x047e
    DataTypeFlag      = 1;                                                                //06-12-12|0x047f
    flag              = 1;                                                                //07-12-28|0x0480
//***************************************************************************             //06-12-12|0x0481
//***                                                                    ****             //06-12-12|0x0482
//***  Process the 128 Possible Test Characters                          ****             //06-12-12|0x0483
//***                                                                    ****             //06-12-12|0x0484
//***************************************************************************             //06-12-12|0x0485
    for(k=0; k<128; ++k)                                                                  //07-12-28|0x0486
      {                                                                                   //06-12-12|0x0487
//***************************************************************************             //06-12-12|0x0488
//***                                                                    ****             //06-12-12|0x0489
//***  Prepare the test index                                            ****             //06-12-12|0x048a
//***                                                                    ****             //06-12-12|0x048b
//***************************************************************************             //06-12-12|0x048c
//***************************************************************************             //07-12-28|0x048d
        if(DataBitOffset < 0)                                                             //07-12-28|0x048e
          {                                                                               //07-12-28|0x048f
            i = k;                                                                        //07-12-28|0x0490
            }                                                                             //07-12-28|0x0491
//***************************************************************************             //07-12-28|0x0492
          else {                                                                          //07-12-28|0x0493
            if(flag > 0)                                                                  //07-12-28|0x0494
              {                                                                           //07-12-28|0x0495
                i = DataBitOffset;                                                        //07-12-28|0x0496
                DataBitOffset += 1;                                                       //07-12-28|0x0497
                DataBitOffset %= 128;                                                     //07-12-28|0x0498
                }                                                                         //07-12-28|0x0499
//---------------------------------------------------------------------------             //07-12-28|0x049a
              else {                                                                      //07-12-28|0x049b
                i += 1;                                                                   //07-12-28|0x049c
                i %= 128;                                                                 //07-12-28|0x049d
                }                                                                         //07-12-28|0x049e
            }                                                                             //07-12-28|0x049f
//***************************************************************************             //07-12-28|0x04a0
//***                                                                    ****             //07-12-28|0x04a1
//***  Initial the test bit                                              ****             //07-12-28|0x04a2
//***                                                                    ****             //07-12-28|0x04a3
//***************************************************************************             //07-12-28|0x04a4
        DataArmFlag(i) = 0;                                                               //06-12-12|0x04a5
//***************************************************************************             //07-12-28|0x04a6
//***                                                                    ****             //07-12-28|0x04a7
//***  Is a test evaulation required?                                    ****             //07-12-28|0x04a8
//***                                                                    ****             //07-12-28|0x04a9
//***************************************************************************             //07-12-28|0x04aa
        if(DataTestFlag(i) != 0)                                                          //06-12-12|0x04ab
          {                                                                               //06-12-12|0x04ac
//***************************************************************************             //06-12-12|0x04ad
//***                                                                    ****             //06-12-12|0x04ae
//***  A test evaulation is required                                     ****             //06-12-12|0x04af
//***--------------------------------------------------------------------****             //06-12-12|0x04b0
//***  Advance the Shift Register Generator                              ****             //06-12-12|0x04b1
//***                                                                    ****             //06-12-12|0x04b2
//***************************************************************************             //06-12-12|0x04b3
             switch(GetRandom)                                   _SwitchGroup             //15-06-16|0x04b4
//***************************************************************************             //06-12-12|0x04b5
//***                                                                    ****             //06-12-12|0x04b6
//***  Test Character is required                                        ****             //06-12-12|0x04b7
//***--------------------------------------------------------------------****             //06-12-12|0x04b8
//***  Does the random number satisfy the threshold                      ****             //06-12-12|0x04b9
//***                                                                    ****             //06-12-12|0x04ba
//***************************************************************************             //06-12-12|0x04bb
            if(work < DataThreshold(i))                                                   //15-06-16|0x04bc
              {                                                                           //06-12-12|0x04bd
//***************************************************************************             //07-12-28|0x04be
//***                                                                    ****             //07-12-28|0x04bf
//***  The Random number satisfies the threshold                         ****             //07-12-28|0x04c0
//***--------------------------------------------------------------------****             //07-12-28|0x04c1
//***  Process the configuration test                                    ****             //07-12-28|0x04c2
//***                                                                    ****             //07-12-28|0x04c3
//***************************************************************************             //07-12-28|0x04c4
                if(DataTestFlag(i) > 0)                                                   //07-12-28|0x04c5
                  {                                                                       //07-12-28|0x04c6
                    DataArmFlag(i)     = 1;                                               //07-12-28|0x04c7
                    DataTestCount(i)  += 1;                                               //07-12-28|0x04c8
                    PrepareChar(1,i)   = '*';                                             //07-12-28|0x04c9
                    }                                                                     //07-12-28|0x04ca
//***************************************************************************             //07-12-28|0x04cb
//***                                                                    ****             //07-12-28|0x04cc
//***  The Random number satisfies the threshold                         ****             //07-12-28|0x04cd
//***--------------------------------------------------------------------****             //07-12-28|0x04ce
//***  Process the error test                                            ****             //07-12-28|0x04cf
//***                                                                    ****             //07-12-28|0x04d0
//***************************************************************************             //07-12-28|0x04d1
                  else {                                                                  //07-12-28|0x04d2
                    if(flag > 0)                                                          //07-12-28|0x04d3
                      {                                                                   //07-12-28|0x04d4
                        DataArmFlag(i)     = 1;                                           //07-12-28|0x04d5
                        DataTestCount(i)  += 1;                                           //07-12-28|0x04d6
                        PrepareChar(1,i)   = '*';                                         //07-12-28|0x04d7
                        DataTypeFlag       = DataTestFlag(i);                             //07-12-28|0x04d8
//***************************************************************************             //07-12-28|0x04d9
                        if(DataBitOffset >= 0)                                            //07-12-28|0x04da
                          {                                                               //07-12-28|0x04db
                            flag = 0;                                                     //07-12-28|0x04dc
                            }                                                             //07-12-28|0x04dd
                        }                                                                 //07-12-28|0x04de
                    }                                                                     //07-12-28|0x04df
                }                                                                         //06-12-12|0x04e0
            }                                                                             //06-12-12|0x04e1
        }                                                                                 //06-12-12|0x04e2
//***************************************************************************             //06-12-12|0x04e3
    return_test(generate_test_1);                                                         //06-12-12|0x04e4
}                                                                                         //06-12-12|0x04e5
//                                                                                        //05-24-97|0x04e5
//***************************************************************************             //06-12-12|0x04e8
//***************************************************************************             //06-12-12|0x04e9
//******                                                               ******             //06-12-12|0x04ea
//******                       progress_message                        ******             //06-12-12|0x04eb
//******                                                               ******             //06-12-12|0x04ec
//***************************************************************************             //06-12-12|0x04ed
//***************************************************************************             //06-12-12|0x04ee
//*******************************************************************************         //10-29-97|0x04f2
//*******************************************************************************         //10-29-97|0x04f2
// progress_message                                                                       //06-12-12|0x04f2
//*******************************************************************************         //10-29-97|0x04f2
//*******************************************************************************         //10-29-97|0x04f2
UINT TESTPROJ::progress_message(                                                          //06-12-12|0x04f2
    SCHAR_FAR MessageAddr                                                                 //06-12-12|0x04f2
    ) {                                                                                   //06-12-12|0x04f2
//*******************************************************************************         //10-29-97|0x04f2
//***************************************************************************             //06-12-12|0x04f5
//***************************************************************************             //06-12-12|0x04f6
  SCHAR work[64];                                                                    //06-12-12|0x04f7
//***************************************************************************             //06-12-12|0x04f8
    sprintf(work, "%s %d\n", MessageAddr, DataTestNo);                                    //06-12-12|0x04f9
    switch(GuiWriteLine(work))                                   _SwitchGroup             //06-12-12|0x04fa
    return_test(progress_message_1);                                                      //06-12-12|0x04fb
}                                                                                         //06-12-12|0x04fc
//                                                                                        //05-24-97|0x04fc
//***************************************************************************             //06-12-12|0x04ff
//***************************************************************************             //06-12-12|0x0500
//******                                                               ******             //06-12-12|0x0501
//******                       pcg_push                                ******             //06-12-12|0x0502
//******                                                               ******             //06-12-12|0x0503
//***************************************************************************             //06-12-12|0x0504
//***************************************************************************             //06-12-12|0x0505
//*******************************************************************************         //10-29-97|0x0509
//*******************************************************************************         //10-29-97|0x0509
// pcg_push                                                                               //06-12-12|0x0509
//*******************************************************************************         //10-29-97|0x0509
//*******************************************************************************         //10-29-97|0x0509
UINT TESTPROJ::pcg_push(                                                                  //06-12-12|0x0509
    TOKENS_FAR PcgTokensFar                                                               //06-12-12|0x0509
    ) {                                                                                   //06-12-12|0x0509
//*******************************************************************************         //10-29-97|0x0509
//***************************************************************************             //06-12-12|0x050c
//***************************************************************************             //06-12-12|0x050d
    if(DrivePathNoTokens == 0) DrivePathNoTokens = 1;                                     //06-12-12|0x0510
    StrDataCpy(DrivePathTokenAddr(0), PcgTokenAddr(0));                                   //06-12-12|0x0511
//***************************************************************************             //06-12-12|0x0512
    if(CallPrePush(BaseDrivePathAddr) != Success)           ReturnSystemError             //11-12-17|0x0513
//***************************************************************************             //06-12-12|0x0514
    return_test(pcg_push_1);                                                              //06-12-12|0x0515
}                                                                                         //06-12-12|0x0516
//                                                                                        //05-24-97|0x0516
//***************************************************************************             //06-12-12|0x0519
//***************************************************************************             //06-12-12|0x051a
//******                                                               ******             //06-12-12|0x051b
//******                       debug_pause                             ******             //06-12-12|0x051c
//******                                                               ******             //06-12-12|0x051d
//***************************************************************************             //06-12-12|0x051e
//***************************************************************************             //06-12-12|0x051f
//*******************************************************************************         //10-29-97|0x0522
//*******************************************************************************         //10-29-97|0x0522
// debug_pause                                                                            //06-12-12|0x0522
//*******************************************************************************         //10-29-97|0x0522
//*******************************************************************************         //10-29-97|0x0522
UINT TESTPROJ::debug_pause(void) {                                                        //06-12-12|0x0522
//*******************************************************************************         //10-29-97|0x0522
//***************************************************************************             //06-12-12|0x0525
//***************************************************************************             //06-12-12|0x0526
    if(BaseDisplayFlag == 0)                               return(Success);               //06-12-12|0x0527
//***************************************************************************             //06-12-12|0x0528
    switch(PrecMenuCmd())                                                                 //06-12-12|0x0529
      {                                                                                   //06-12-12|0x052a
        case No:    BaseDisplayFlag = 0;                                                  //06-12-17|0x052b
                    SetDisplayFlag(BaseDisplayFlag);                                      //06-12-17|0x052c
                    return(Success);                                                      //06-12-17|0x052d
        case Yes:                                          return(Success);               //06-12-12|0x052e
        case UserError:                                    return(UserError);             //06-12-17|0x052f
        case Continue:                                     return(Continue);              //06-12-17|0x0530
        case Display:                                      return(Display);               //06-12-12|0x0531
        case KeyBoard:                                     return(KeyBoard);              //06-12-12|0x0532
        default:                                           ReturnSystemError;             //06-12-12|0x0533
        }                                                                                 //06-12-12|0x0534
}                                                                                         //06-12-12|0x0535
//                                                                                        //05-24-97|0x0535
//***************************************************************************             //06-12-16|0x0538
//***************************************************************************             //06-12-16|0x0539
//******                                                               ******             //06-12-16|0x053a
//******                        exit_test                              ******             //06-12-16|0x053b
//******                                                               ******             //06-12-16|0x053c
//***************************************************************************             //06-12-16|0x053d
//***************************************************************************             //06-12-16|0x053e
//*******************************************************************************         //10-29-97|0x0545
//*******************************************************************************         //10-29-97|0x0545
// exit_test                                                                              //07-12-28|0x0545
//*******************************************************************************         //10-29-97|0x0545
//*******************************************************************************         //10-29-97|0x0545
UINT TESTPROJ::exit_test(                                                                 //07-12-28|0x0545
    EXIT_CODE_FAR ExitCodesAddr,                                                          //07-12-28|0x0545
    SLONG Status,                                                                         //07-12-28|0x0545
    SCHAR_FAR SpawnType                                                                   //07-12-28|0x0545
    ) {                                                                                   //07-12-28|0x0545
//*******************************************************************************         //10-29-97|0x0545
//***************************************************************************             //07-12-28|0x0548
//***************************************************************************             //07-12-28|0x0549
  STRING_DATA error_macro;                                                           //07-12-28|0x054a
  STRING_DATA error_name;                                                            //07-12-28|0x054b
//***************************************************************************             //06-12-16|0x054c
//***************************************************************************             //06-12-16|0x054d
  UINT i;                                                                            //06-12-16|0x054e
//***************************************************************************             //07-12-28|0x054f
//******                                                               ******             //07-12-28|0x0550
//****** Were we successful                                            ******             //07-12-28|0x0551
//******                                                               ******             //07-12-28|0x0552
//***************************************************************************             //07-12-28|0x0553
    if(Status == 0)                                  return_yes(exit_test_1);             //06-12-16|0x0554
//***************************************************************************             //07-12-28|0x0555
//******                                                               ******             //07-12-28|0x0556
//****** We were not successful                                        ******             //07-12-28|0x0557
//******---------------------------------------------------------------******             //07-12-28|0x0558
//****** Prepare the mailbox data                                      ******             //07-12-28|0x0559
//******                                                               ******             //07-12-28|0x055a
//***************************************************************************             //07-12-28|0x055b
    MemSet(&error_macro, 0x00, sizeof(STRING_DATA));                                      //07-12-28|0x055c
    StrCpy(ErrorMacroLineAddr, "SYSTEM");                                                 //07-12-28|0x055d
    ErrorMacroLength = 6;                                                                 //07-12-28|0x055e
    ErrorMacroType   = I_NAME;                                                            //07-12-28|0x055f
//---------------------------------------------------------------------------             //07-12-28|0x0560
    MemSet(&error_name,  0x00, sizeof(STRING_DATA));                                      //07-12-28|0x0561
    if(TruncStringSize(&ErrorNameLength, SpawnType) != Success)                           //check   |0x0562
                                                           ReturnSystemError;             //check   |0x0563
    if((ErrorNameLength + 11) >= 255)                      ReturnSystemError;             //check   |0x0564
    sprintf(ErrorNameLineAddr, "%s-0x%08x", SpawnType, Status);                           //07-12-28|0x0565
    ErrorNameType    = I_TOKEN;                                                           //07-12-28|0x0566
//***************************************************************************             //07-12-28|0x0567
//******                                                               ******             //07-12-28|0x0568
//****** We were not successful                                        ******             //07-12-28|0x0569
//******---------------------------------------------------------------******             //07-12-28|0x056a
//****** Compare the error code against the approved list              ******             //07-12-28|0x056b
//****** Apply the Error Mailbox if appropriate                        ******             //07-12-28|0x056c
//******                                                               ******             //07-12-28|0x056d
//***************************************************************************             //07-12-28|0x056e
    for(i=0; i<ExitCodesNoExitCodes; ++i)                                                 //06-12-16|0x056f
      {                                                                                   //06-12-16|0x0570
        if(ExitCodesExitCode(i) == Status)                                                //09-01-03|0x0571
          {                                                                               //09-01-03|0x0572
            switch(ErrorMailAddMacro(&error_macro))              _SwitchGroup             //09-01-03|0x0573
            switch(ErrorMailAddError(&error_name))               _SwitchGroup             //09-01-03|0x0574
            return_no(exit_test_2);                                                       //09-01-03|0x0575
            }                                                                             //09-01-03|0x0576
        }                                                                                 //06-12-16|0x0577
    ReturnUserError(exit_test_3);                                                         //06-12-16|0x0578
}                                                                                         //06-12-16|0x057a
//                                                                                        //05-24-97|0x057a
//***************************************************************************             //06-12-16|0x057d
//***************************************************************************             //06-12-16|0x057e
//******                                                               ******             //06-12-16|0x057f
//******                        make_step                              ******             //06-12-16|0x0580
//******                                                               ******             //06-12-16|0x0581
//***************************************************************************             //06-12-16|0x0582
//***************************************************************************             //06-12-16|0x0583
//*******************************************************************************         //10-29-97|0x0589
//*******************************************************************************         //10-29-97|0x0589
// make_step                                                                              //06-12-16|0x0589
//*******************************************************************************         //10-29-97|0x0589
//*******************************************************************************         //10-29-97|0x0589
UINT TESTPROJ::make_step(void) {                                                          //06-12-16|0x0589
//*******************************************************************************         //10-29-97|0x0589
//***************************************************************************             //06-12-16|0x058c
//***************************************************************************             //06-12-16|0x058d
  SLONG status;                                                                      //06-12-16|0x058e
//***************************************************************************             //06-12-16|0x058f
//***************************************************************************             //06-12-16|0x0590
    status = system(MakeParmsAddr);                                                       //06-12-16|0x0591
    if(WIFEXITED(status)!=0)                                                              //06-12-16|0x0591
      {                                                                                   //06-12-16|0x0591
        status = WEXITSTATUS(status);                                                     //06-12-16|0x0591
        }                                                                                 //06-12-16|0x0591
//--------------------------------------------------------------------------*             //06-12-16|0x0592
    switch(exit_test(DataMakeExitAddr, status,  "MAKE"))                                  //09-01-03|0x0593
      {                                                                                   //06-12-16|0x0594
        case Yes:                                    return_yes(make_step_1);             //06-12-16|0x0595
        case No:                                     return_no(make_step_2);              //06-12-16|0x0596
        case UserError:                              break_test(make_step_3);             //06-12-16|0x0597
        default:                                     ReturnSystemError;                   //06-12-16|0x0598
        }                                                                                 //06-12-16|0x0599
//---------------------------------------------------------------------------             //06-12-16|0x059a
    ReturnFinish("Launch Error relative to system function");                             //06-12-16|0x059b
}                                                                                         //06-12-16|0x059c
//                                                                                        //05-24-97|0x059c
//***************************************************************************             //06-12-16|0x059f
//***************************************************************************             //06-12-16|0x05a0
//******                                                               ******             //06-12-16|0x05a1
//******                        run_step                               ******             //06-12-16|0x05a2
//******                                                               ******             //06-12-16|0x05a3
//***************************************************************************             //06-12-16|0x05a4
//***************************************************************************             //06-12-16|0x05a5
//*******************************************************************************         //10-29-97|0x05ab
//*******************************************************************************         //10-29-97|0x05ab
// run_step                                                                               //06-12-16|0x05ab
//*******************************************************************************         //10-29-97|0x05ab
//*******************************************************************************         //10-29-97|0x05ab
UINT TESTPROJ::run_step(void) {                                                           //06-12-16|0x05ab
//*******************************************************************************         //10-29-97|0x05ab
//***************************************************************************             //06-12-16|0x05ae
//***************************************************************************             //06-12-16|0x05af
  SLONG status;                                                                      //06-12-16|0x05b0
//***************************************************************************             //06-12-16|0x05b1
//***************************************************************************             //06-12-16|0x05b2
    status = system(RunParmsAddr);                                                        //06-12-16|0x05b3
    if(WIFEXITED(status)!=0)                                                              //06-12-16|0x05b3
      {                                                                                   //06-12-16|0x05b3
        status = WEXITSTATUS(status);                                                     //06-12-16|0x05b3
        }                                                                                 //06-12-16|0x05b3
//---------------------------------------------------------------------------             //06-12-16|0x05b4
    switch(exit_test(DataRunExitAddr, status, "RUN"))                                     //09-01-03|0x05b5
      {                                                                                   //06-12-16|0x05b6
        case Yes:                                    return_yes(run_step_1);              //06-12-16|0x05b7
        case No:                                     return_no(run_step_2);               //06-12-16|0x05b8
        case UserError:                              break_test(run_step_3);              //06-12-16|0x05b9
        default:                                     ReturnSystemError;                   //06-12-16|0x05ba
        }                                                                                 //06-12-16|0x05bb
//---------------------------------------------------------------------------             //06-12-16|0x05bc
    ReturnFinish("Launch Error relative to system function");                             //06-12-16|0x05bd
}                                                                                         //06-12-16|0x05be
//                                                                                        //05-24-97|0x05be
//***************************************************************************             //06-12-15|0x05c1
//***************************************************************************             //06-12-15|0x05c2
//******                                                               ******             //06-12-15|0x05c3
//******                        record_results                         ******             //06-12-15|0x05c4
//******                                                               ******             //06-12-15|0x05c5
//***************************************************************************             //06-12-15|0x05c6
//***************************************************************************             //06-12-15|0x05c7
//*******************************************************************************         //10-29-97|0x05cd
//*******************************************************************************         //10-29-97|0x05cd
// record_results                                                                         //06-12-15|0x05cd
//*******************************************************************************         //10-29-97|0x05cd
//*******************************************************************************         //10-29-97|0x05cd
UINT TESTPROJ::record_results(                                                            //06-12-15|0x05cd
    SCHAR_FAR LetterAddr                                                                  //06-12-15|0x05cd
    ) {                                                                                   //06-12-15|0x05cd
//*******************************************************************************         //10-29-97|0x05cd
//***************************************************************************             //07-10-13|0x05d0
//******                                                               ******             //07-10-13|0x05d1
//******  Does the record project exist                                ******             //07-10-13|0x05d2
//******                                                               ******             //07-10-13|0x05d3
//***************************************************************************             //07-10-13|0x05d4
    if(RecordNoTokens == 0)                                  return(Success);             //07-10-13|0x05d5
//***************************************************************************             //06-12-15|0x05d6
//***************************************************************************             //06-12-15|0x05d7
    switch(DataTypeFlag)                                                                  //06-12-15|0x05d8
      {                                                                                   //06-12-15|0x05d9
//***************************************************************************             //06-12-15|0x05da
//******                                                               ******             //06-12-16|0x05db
//******  No Error Bit Set                                             ******             //06-12-16|0x05dc
//******                                                               ******             //06-12-16|0x05dd
//***************************************************************************             //06-12-16|0x05de
        case 1:                                                                           //06-12-16|0x05df
          StrCpy(RecordLineAddr(1), "S");                                                 //06-12-16|0x05e0
          break_test(record_results_1);                                                   //06-12-16|0x05e1
//***************************************************************************             //06-12-15|0x05e2
//******                                                               ******             //06-12-15|0x05e3
//******  Make Error Bit Set                                           ******             //06-12-15|0x05e4
//******                                                               ******             //06-12-15|0x05e5
//***************************************************************************             //06-12-15|0x05e6
        case -1:                                                                          //06-12-15|0x05e7
          StrCpy(RecordLineAddr(1), "M");                                                 //06-12-15|0x05e8
          break_test(record_results_2);                                                   //06-12-15|0x05e9
//***************************************************************************             //06-12-17|0x05ea
//******                                                               ******             //06-12-17|0x05eb
//******  Run Error Bit Set                                            ******             //06-12-17|0x05ec
//******                                                               ******             //06-12-17|0x05ed
//***************************************************************************             //06-12-17|0x05ee
        case -2:                                                                          //06-12-17|0x05ef
          StrCpy(RecordLineAddr(1), "R");                                                 //06-12-17|0x05f0
          break_test(record_results_3);                                                   //06-12-17|0x05f1
//***************************************************************************             //06-12-17|0x05f2
        default:                                            ReturnSystemError             //06-12-17|0x05f3
        }                                                                                 //06-12-17|0x05f4
//***************************************************************************             //06-12-15|0x05f5
//******                                                               ******             //06-12-15|0x05f6
//******  Complete the process                                         ******             //06-12-15|0x05f7
//******                                                               ******             //06-12-15|0x05f8
//***************************************************************************             //06-12-15|0x05f9
    StrCat(RecordLineAddr(1), LetterAddr);                                                //06-12-15|0x05fa
    RecordLength(1) = 2;                                                                  //06-12-15|0x05fb
    RecordType(1)   = I_TOKEN;                                                            //06-12-15|0x05fc
    RecordNoTokens  = 2;                                                                  //06-12-15|0x05fd
//***************************************************************************             //06-12-15|0x05fe
    return(Success);                                                                      //06-12-15|0x05ff
}                                                                                         //06-12-15|0x0600
//                                                                                        //05-24-97|0x0600
//***************************************************************************             //06-12-16|0x0603
//***************************************************************************             //06-12-16|0x0604
//******                                                               ******             //06-12-16|0x0605
//******                        prepare_active_bits                    ******             //06-12-16|0x0606
//******                                                               ******             //06-12-16|0x0607
//***************************************************************************             //06-12-16|0x0608
//***************************************************************************             //06-12-16|0x0609
//*******************************************************************************         //10-29-97|0x0610
//*******************************************************************************         //10-29-97|0x0610
// prepare_active_bits                                                                    //06-12-16|0x0610
//*******************************************************************************         //10-29-97|0x0610
//*******************************************************************************         //10-29-97|0x0610
UINT TESTPROJ::prepare_active_bits(void) {                                                //06-12-16|0x0610
//*******************************************************************************         //10-29-97|0x0610
//***************************************************************************             //06-12-16|0x0613
//***************************************************************************             //06-12-16|0x0614
  SLONG i;                                                                           //06-12-16|0x0615
  SLONG j;                                                                           //06-12-16|0x0616
  ULONG mask_bit;                                                                    //06-12-16|0x0617
//***************************************************************************             //06-12-16|0x0618
//***************************************************************************             //06-12-16|0x0619
    TestSample(prep_active_bits_1);                                                       //06-12-16|0x061a
    mask_bit          = 1;                                                                //06-12-16|0x061b
    j                 = 0;                                                                //06-12-16|0x061c
    DataErrorMask(0)  = 0;                                                                //06-12-16|0x061d
//***************************************************************************             //06-12-16|0x061e
    for(i=0; i<128; ++i)                                                                  //06-12-16|0x061f
      {                                                                                   //06-12-16|0x0620
        if(DataArmFlag(i) != 0)                                                           //06-12-16|0x0621
          {                                                                               //06-12-16|0x0622
            TestSample(prep_active_bits_2);                                               //06-12-16|0x0623
            DataErrorMask(j) |= mask_bit;                                                 //06-12-16|0x0624
            }                                                                             //06-12-16|0x0625
//---------------------------------------------------------------------------             //06-12-16|0x0626
        if(mask_bit >= 0x80000000)                                                        //06-12-16|0x0627
          {                                                                               //06-12-16|0x0628
            TestSample(prep_active_bits_3);                                               //06-12-16|0x0629
            j                 += 1;                                                       //06-12-16|0x062a
            DataErrorMask(j)   = 0;                                                       //06-12-16|0x062b
            mask_bit           = 1;                                                       //06-12-16|0x062c
            }                                                                             //06-12-16|0x062d
          else {                                                                          //06-12-16|0x062e
            TestSample(prep_active_bits_4);                                               //06-12-16|0x062f
            mask_bit          += mask_bit;                                                //06-12-16|0x0630
            }                                                                             //06-12-16|0x0631
        }                                                                                 //06-12-16|0x0632
    return(Success);                                                                      //06-12-16|0x0633
}                                                                                         //06-12-16|0x0634
//                                                                                        //05-24-97|0x0634
//***************************************************************************             //06-12-16|0x0637
//***************************************************************************             //06-12-16|0x0638
//******                                                               ******             //06-12-16|0x0639
//******                            previous_error                     ******             //06-12-16|0x063a
//******                                                               ******             //06-12-16|0x063b
//***************************************************************************             //06-12-16|0x063c
//***************************************************************************             //06-12-16|0x063d
//*******************************************************************************         //10-29-97|0x0642
//*******************************************************************************         //10-29-97|0x0642
// previous_error                                                                         //06-12-16|0x0642
//*******************************************************************************         //10-29-97|0x0642
//*******************************************************************************         //10-29-97|0x0642
UINT TESTPROJ::previous_error(void) {                                                     //06-12-16|0x0642
//*******************************************************************************         //10-29-97|0x0642
//***************************************************************************             //06-12-16|0x0645
//***************************************************************************             //06-12-16|0x0646
  ULONG i;                                                                           //06-12-16|0x0647
  ULONG j;                                                                           //06-12-16|0x0648
//***************************************************************************             //06-12-16|0x0649
//***************************************************************************             //06-12-16|0x064a
    for(i=0; i<ErrorsNoErrors; ++i)                                                       //06-12-16|0x064b
      {                                                                                   //06-12-16|0x064c
        j = 0;                                                                            //06-12-16|0x064d
        while(ErrorsMask(i,j) == DataErrorMask(j))                                        //06-12-16|0x064e
          {                                                                               //06-12-16|0x064f
            if((++j) >= 4)                                                                //06-12-16|0x0650
              {                                                                           //06-12-16|0x0651
                ErrorsCount(i) += 1;                                                      //06-12-16|0x0652
                return_yes(previous_error_1);                                             //06-12-16|0x0653
                }                                                                         //06-12-16|0x0654
            }                                                                             //06-12-16|0x0655
        }                                                                                 //06-12-16|0x0656
    return_no(previous_error_2);                                                          //06-12-16|0x0657
}                                                                                         //06-12-16|0x0658
//                                                                                        //05-24-97|0x0658
//***************************************************************************             //06-12-16|0x065b
//***************************************************************************             //06-12-16|0x065c
//******                                                               ******             //06-12-16|0x065d
//******                            new_error                          ******             //06-12-16|0x065e
//******                                                               ******             //06-12-16|0x065f
//***************************************************************************             //06-12-16|0x0660
//***************************************************************************             //06-12-16|0x0661
//*******************************************************************************         //10-29-97|0x0666
//*******************************************************************************         //10-29-97|0x0666
// new_error                                                                              //06-12-16|0x0666
//*******************************************************************************         //10-29-97|0x0666
//*******************************************************************************         //10-29-97|0x0666
UINT TESTPROJ::new_error(void) {                                                          //06-12-16|0x0666
//*******************************************************************************         //10-29-97|0x0666
//***************************************************************************             //06-12-16|0x0669
//***************************************************************************             //06-12-16|0x066a
    if(ErrorsNoErrors >= 32)                                                              //06-12-16|0x066b
      {                                                                                   //06-12-16|0x066c
        return_no(new_error_1);                                                           //06-12-18|0x066d
        }                                                                                 //06-12-18|0x066e
//---------------------------------------------------------------------------             //06-12-16|0x066f
      else {                                                                              //06-12-16|0x0670
        ErrorsMask(ErrorsNoErrors,0)  = DataErrorMask(0);                                 //06-12-16|0x0671
        ErrorsMask(ErrorsNoErrors,1)  = DataErrorMask(1);                                 //06-12-16|0x0672
        ErrorsMask(ErrorsNoErrors,2)  = DataErrorMask(2);                                 //06-12-16|0x0673
        ErrorsMask(ErrorsNoErrors,3)  = DataErrorMask(3);                                 //06-12-16|0x0674
        ErrorsCount(ErrorsNoErrors)   = 1;                                                //06-12-16|0x0675
        ++ErrorsNoErrors;                                                                 //06-12-16|0x0676
        return_yes(new_error_2);                                                          //06-12-16|0x0677
        }                                                                                 //06-12-16|0x0678
}                                                                                         //06-12-16|0x0679
//                                                                                        //05-24-97|0x0679
//***************************************************************************             //06-12-15|0x067c
//***************************************************************************             //06-12-15|0x067d
//******                                                               ******             //06-12-15|0x067e
//******                     enter_summary_name                        ******             //06-12-15|0x067f
//******                                                               ******             //06-12-15|0x0680
//***************************************************************************             //06-12-15|0x0681
//***************************************************************************             //06-12-15|0x0682
//*******************************************************************************         //10-29-97|0x0683
//*******************************************************************************         //10-29-97|0x0683
// enter_summary_name                                                                     //06-12-15|0x0683
//*******************************************************************************         //10-29-97|0x0683
//*******************************************************************************         //10-29-97|0x0683
UINT TESTPROJ::enter_summary_name(                                                        //06-12-15|0x0683
    SCHAR_FAR NameAddr                                                                    //06-12-15|0x0683
    ) {                                                                                   //06-12-15|0x0683
//*******************************************************************************         //10-29-97|0x0683
//**********************************************************************                  //06-12-15|0x0683
//**********************************************************************                  //06-12-15|0x0683
    switch(InitialSummaryFile) _SwitchGroup                                               //06-12-15|0x0683
    switch(FileEnterName(NameAddr, RPT_EXTENT)) _SwitchGroup                              //06-12-15|0x0683
    switch(FileRelease()) _SwitchGroup                                                    //06-12-15|0x0683
//**********************************************************************                  //06-12-15|0x0683
    return_test(enter_summary_name_1);                                                    //06-12-15|0x0683
}                                                                                         //06-12-15|0x0683
//                                                                                        //05-24-97|0x0683
//***************************************************************************             //06-12-15|0x0686
//***************************************************************************             //06-12-15|0x0687
//******                                                               ******             //06-12-15|0x0688
//******                        report_summary                         ******             //06-12-15|0x0689
//******                                                               ******             //06-12-15|0x068a
//***************************************************************************             //06-12-15|0x068b
//***************************************************************************             //06-12-15|0x068c
//*******************************************************************************         //10-29-97|0x0690
//*******************************************************************************         //10-29-97|0x0690
// report_summaries                                                                       //06-12-15|0x0690
//*******************************************************************************         //10-29-97|0x0690
//*******************************************************************************         //10-29-97|0x0690
UINT TESTPROJ::report_summaries(void) {                                                   //06-12-15|0x0690
//*******************************************************************************         //10-29-97|0x0690
//***************************************************************************             //06-12-15|0x0693
//***************************************************************************             //06-12-15|0x0694
    TestSample(report_summaries_1);                                                       //06-12-15|0x0695
//---------------------------------------------------------------------------             //06-12-15|0x0696
    switch(report_title("\nSUMMARIES:"))                        _SwitchGroup              //06-12-15|0x0697
//---------------------------------------------------------------------------             //06-12-15|0x0698
    switch(report_numeric("     NO TESTS:",           DataNoTests))                       //06-12-15|0x0699
                                                                 _SwitchGroup             //06-12-15|0x069a
//---------------------------------------------------------------------------             //06-12-15|0x069b
    switch(report_numeric("     NO MEASUREMENTS:",    --DataTestNo))                      //06-12-15|0x069c
                                                                 _SwitchGroup             //06-12-15|0x069d
//---------------------------------------------------------------------------             //06-12-15|0x069e
    switch(report_numeric("     NO RUN DETECTS:",     DataNoRunDetects))                  //06-12-15|0x069f
                                                                 _SwitchGroup             //06-12-15|0x06a0
//---------------------------------------------------------------------------             //06-12-15|0x06a1
    switch(report_numeric("     NO DESIGN DETECTS:",  DataNoPrepDetects))                 //06-12-15|0x06a2
                                                                 _SwitchGroup             //06-12-15|0x06a3
//---------------------------------------------------------------------------             //06-12-15|0x06a4
    switch(report_numeric("     NO SUCCESSES:",       DataNoSuccess))                     //06-12-15|0x06a5
                                                                 _SwitchGroup             //06-12-15|0x06a6
//---------------------------------------------------------------------------             //06-12-15|0x06a7
    switch(report_numeric("     NO FAILURES:",        DataNoFailures))                    //06-12-15|0x06a8
                                                                 _SwitchGroup             //06-12-15|0x06a9
//---------------------------------------------------------------------------             //06-12-15|0x06aa
    return(Success);                                                                      //06-12-15|0x06ab
}                                                                                         //06-12-15|0x06ac
//                                                                                        //05-24-97|0x06ac
//***************************************************************************             //06-12-15|0x06af
//***************************************************************************             //06-12-15|0x06b0
//******                                                               ******             //06-12-15|0x06b1
//******                        report_active                          ******             //06-12-15|0x06b2
//******                                                               ******             //06-12-15|0x06b3
//***************************************************************************             //06-12-15|0x06b4
//***************************************************************************             //06-12-15|0x06b5
//*******************************************************************************         //10-29-97|0x06bc
//*******************************************************************************         //10-29-97|0x06bc
// report_active                                                                          //06-12-15|0x06bc
//*******************************************************************************         //10-29-97|0x06bc
//*******************************************************************************         //10-29-97|0x06bc
UINT TESTPROJ::report_active(void) {                                                      //06-12-15|0x06bc
//*******************************************************************************         //10-29-97|0x06bc
//***************************************************************************             //06-12-15|0x06bf
//***************************************************************************             //06-12-15|0x06c0
  SCHAR header[256];                                                                 //06-12-15|0x06c1
  SLONG i;                                                                           //06-12-15|0x06c2
//***************************************************************************             //06-12-15|0x06c3
//***************************************************************************             //06-12-15|0x06c4
    TestSample(report_active_1);                                                          //06-12-15|0x06c5
//---------------------------------------------------------------------------             //06-12-15|0x06c6
    switch(report_title("\nACTIVE ELEMENTS:"))                  _SwitchGroup              //06-12-15|0x06c7
//***************************************************************************             //06-12-15|0x06c8
    for(i=0;  i<128;  ++i)                                                                //06-12-15|0x06c9
      {                                                                                   //06-12-15|0x06ca
        switch(DataTestFlag(i))                                                           //06-12-15|0x06cb
          {                                                                               //06-12-15|0x06cc
//---------------------------------------------------------------------------             //06-12-15|0x06cd
            case 1:                                                                       //06-12-18|0x06ce
              sprintf(&header[0], "     CONFIGURE-%5.5d:  ", i);                          //06-12-18|0x06cf
              switch(ReportActive(i))                            _SwitchGroup             //06-12-18|0x06d0
              TestSample(report_active_2);                                                //06-12-18|0x06d1
              break;                                                                      //06-12-18|0x06d2
//---------------------------------------------------------------------------             //06-12-15|0x06d3
            case -1:                                                                      //06-12-15|0x06d4
              sprintf(&header[0], "     MAKE ERROR-%5.5d: ", i);                          //06-12-15|0x06d5
              switch(ReportActive(i))                            _SwitchGroup             //06-12-15|0x06d6
              TestSample(report_active_3);                                                //06-12-15|0x06d7
              break;                                                                      //06-12-15|0x06d8
//---------------------------------------------------------------------------             //06-12-17|0x06d9
            case -2:                                                                      //06-12-17|0x06da
              sprintf(&header[0], "     RUN ERROR-%5.5d:  ", i);                          //06-12-17|0x06db
              switch(ReportActive(i))                            _SwitchGroup             //06-12-17|0x06dc
              TestSample(report_active_3);                                                //06-12-17|0x06dd
              break;                                                                      //06-12-17|0x06de
//---------------------------------------------------------------------------             //06-12-15|0x06df
            case 0:                                                                       //06-12-15|0x06e0
                TestSample(report_active_4);                                              //06-12-15|0x06e1
                break;                                                                    //06-12-15|0x06e2
//---------------------------------------------------------------------------             //06-12-15|0x06e3
            default:                                        ReturnSystemError             //06-12-15|0x06e4
            }                                                                             //06-12-15|0x06e5
        }                                                                                 //06-12-15|0x06e6
    return(Success);                                                                      //06-12-15|0x06e7
}                                                                                         //06-12-15|0x06e8
//                                                                                        //05-24-97|0x06e8
//***************************************************************************             //06-12-17|0x06eb
//***************************************************************************             //06-12-17|0x06ec
//******                                                               ******             //06-12-17|0x06ed
//******                        report_error                           ******             //06-12-17|0x06ee
//******                                                               ******             //06-12-17|0x06ef
//***************************************************************************             //06-12-17|0x06f0
//***************************************************************************             //06-12-17|0x06f1
//*******************************************************************************         //10-29-97|0x06f9
//*******************************************************************************         //10-29-97|0x06f9
// report_error                                                                           //06-12-17|0x06f9
//*******************************************************************************         //10-29-97|0x06f9
//*******************************************************************************         //10-29-97|0x06f9
UINT TESTPROJ::report_error(void) {                                                       //06-12-17|0x06f9
//*******************************************************************************         //10-29-97|0x06f9
//***************************************************************************             //06-12-17|0x06fc
//***************************************************************************             //06-12-17|0x06fd
  SCHAR header[256];                                                                 //06-12-17|0x06fe
  SCHAR number[32];                                                                  //06-12-17|0x06ff
  ULONG i;                                                                           //06-12-17|0x0700
  ULONG j;                                                                           //06-12-17|0x0701
  ULONG k;                                                                           //06-12-17|0x0702
  ULONG m;                                                                           //06-12-17|0x0703
  ULONG mask_bits;                                                                   //06-12-17|0x0704
//***************************************************************************             //06-12-17|0x0705
//***************************************************************************             //06-12-17|0x0706
    switch(report_title("ERROR REPORT"))                         _SwitchGroup             //06-12-17|0x0707
//***************************************************************************             //06-12-17|0x0708
    for(i=0; i<ErrorsNoErrors; ++i)                                                       //06-12-17|0x0709
      {                                                                                   //06-12-17|0x070a
//---------------------------------------------------------------------------             //06-12-17|0x070b
        TestSample(report_error_1);                                                       //06-12-17|0x070c
//***************************************************************************             //06-12-17|0x070d
        k         = 0;                                                                    //06-12-17|0x070e
        m         = 0;                                                                    //06-12-17|0x070f
//---------------------------------------------------------------------------             //06-12-17|0x0710
        sprintf(&header[0], "     %6.6d ",  ErrorsCount(i));                              //06-12-17|0x0711
//---------------------------------------------------------------------------             //06-12-17|0x0712
        for(j=0; j<128; ++j)                                                              //06-12-17|0x0713
          {                                                                               //06-12-17|0x0714
//---------------------------------------------------------------------------             //06-12-17|0x0715
            TestSample(report_error_2);                                                   //06-12-17|0x0716
            if((j & 31) == 0)                                                             //06-12-17|0x0717
              {                                                                           //06-12-17|0x0718
                mask_bits = ErrorsMask(i,k);                                              //06-12-17|0x0719
                k        += 1;                                                            //06-12-17|0x071a
                TestSample(report_error_3);                                               //06-12-17|0x071b
                }                                                                         //06-12-17|0x071c
//---------------------------------------------------------------------------             //06-12-17|0x071d
            if(mask_bits & 1)                                                             //06-12-17|0x071e
              {                                                                           //06-12-17|0x071f
                TestSample(report_error_4);                                               //06-12-17|0x0720
                sprintf(&number[0], "%3.3d ", j);                                         //06-12-17|0x0721
                strcat(&header[0], &number[0]);                                           //06-12-17|0x0722
                if((m & 7) == 7)                                                          //06-12-17|0x0723
                  {                                                                       //06-12-17|0x0724
                    switch(report_line(&header[0]))              _SwitchGroup             //06-12-17|0x0725
                    StrCpy(&header[0], "            ");                                   //06-12-17|0x0726
                    TestSample(report_error_5);                                           //06-12-17|0x0727
                    }                                                                     //06-12-17|0x0728
                m += 1;                                                                   //06-12-17|0x0729
                }                                                                         //06-12-17|0x072a
            mask_bits /= 2;                                                               //06-12-17|0x072b
            }                                                                             //06-12-17|0x072c
//---------------------------------------------------------------------------             //06-12-17|0x072d
        if((m & 7) != 0)                                                                  //06-12-17|0x072e
          {                                                                               //06-12-17|0x072f
            switch(report_line(&header[0]))                      _SwitchGroup             //06-12-17|0x0730
            TestSample(report_error_5);                                                   //06-12-17|0x0731
            }                                                                             //06-12-17|0x0732
//---------------------------------------------------------------------------             //06-12-17|0x0733
        }                                                                                 //06-12-17|0x0734
    return(Success);                                                                      //06-12-17|0x0735
}                                                                                         //06-12-17|0x0736
//                                                                                        //05-24-97|0x0736
//***************************************************************************             //06-12-15|0x0739
//***************************************************************************             //06-12-15|0x073a
//******                                                               ******             //06-12-15|0x073b
//******                        report_title                           ******             //06-12-15|0x073c
//******                                                               ******             //06-12-15|0x073d
//***************************************************************************             //06-12-15|0x073e
//***************************************************************************             //06-12-15|0x073f
//*******************************************************************************         //10-29-97|0x0743
//*******************************************************************************         //10-29-97|0x0743
// report_title                                                                           //06-12-15|0x0743
//*******************************************************************************         //10-29-97|0x0743
//*******************************************************************************         //10-29-97|0x0743
UINT TESTPROJ::report_title(                                                              //06-12-15|0x0743
    SCHAR_FAR Title                                                                       //06-12-15|0x0743
    ) {                                                                                   //06-12-15|0x0743
//*******************************************************************************         //10-29-97|0x0743
//***************************************************************************             //06-12-15|0x0746
//***************************************************************************             //06-12-15|0x0747
  WORDS work;                                                                        //06-12-15|0x0748
//***************************************************************************             //06-12-15|0x0749
//***************************************************************************             //06-12-15|0x074a
    TestSample(report_title_1);                                                           //06-12-15|0x074b
//***************************************************************************             //06-12-15|0x074c
    StrDataClr(BaseOutputAddr);                                                           //06-12-15|0x074d
//---------------------------------------------------------------------------             //06-12-15|0x074e
    if(MemCCpy(OutputLineAddr, Title, 0x00, 80) == 0)       ReturnSystemError             //06-12-15|0x074f
    work.ulong = strlen(OutputLineAddr);                                                  //06-12-15|0x0750
    OutputLength = work.word0;                                                            //06-12-15|0x0751
//***************************************************************************             //06-12-15|0x0752
    switch(GuiWriteLine(OutputLineAddr))                         _SwitchGroup             //06-12-15|0x0753
//---------------------------------------------------------------------------             //06-12-15|0x0754
    switch(CommitSummaryFile)                                    _SwitchGroup             //06-12-15|0x0755
    switch(FilePutText(BaseOutputAddr))                          _SwitchGroup             //12-04-04|0x0756
    switch(FilePutCRLF())                                        _SwitchGroup             //12-04-04|0x0757
    switch(FileRelease())                                        _SwitchGroup             //06-12-15|0x0758
//***************************************************************************             //06-12-15|0x0759
    return(Success);                                                                      //06-12-15|0x075a
}                                                                                         //06-12-15|0x075b
//                                                                                        //05-24-97|0x075b
//***************************************************************************             //06-12-17|0x075e
//***************************************************************************             //06-12-17|0x075f
//******                                                               ******             //06-12-17|0x0760
//******                        report_line                            ******             //06-12-17|0x0761
//******                                                               ******             //06-12-17|0x0762
//***************************************************************************             //06-12-17|0x0763
//***************************************************************************             //06-12-17|0x0764
//*******************************************************************************         //10-29-97|0x0768
//*******************************************************************************         //10-29-97|0x0768
// report_line                                                                           //06-12-17|0x0768
//*******************************************************************************         //10-29-97|0x0768
//*******************************************************************************         //10-29-97|0x0768
UINT TESTPROJ::report_line(                                                              //06-12-17|0x0768
    SCHAR_FAR Title                                                                      //06-12-17|0x0768
    ) {                                                                                  //06-12-17|0x0768
//*******************************************************************************         //10-29-97|0x0768
//***************************************************************************             //06-12-17|0x076b
//***************************************************************************             //06-12-17|0x076c
  WORDS work;                                                                        //06-12-17|0x076d
//***************************************************************************             //06-12-17|0x076e
//***************************************************************************             //06-12-17|0x076f
    TestSample(report_title_1);                                                           //06-12-17|0x0770
//***************************************************************************             //06-12-17|0x0771
    StrDataClr(BaseOutputAddr);                                                           //06-12-17|0x0772
//---------------------------------------------------------------------------             //06-12-17|0x0773
    if(MemCCpy(OutputLineAddr, Title, 0x00, 80) == 0)       ReturnSystemError             //06-12-17|0x0774
    work.ulong = strlen(OutputLineAddr);                                                  //06-12-17|0x0775
    OutputLength = work.word0;                                                            //06-12-17|0x0776
//***************************************************************************             //06-12-17|0x0777
    switch(GuiAppendLine(OutputLineAddr))                        _SwitchGroup             //06-12-17|0x0778
//---------------------------------------------------------------------------             //06-12-17|0x0779
    switch(CommitSummaryFile)                                    _SwitchGroup             //06-12-17|0x077a
    switch(FilePutText(BaseOutputAddr))                          _SwitchGroup             //12-04-04|0x077b
    switch(FilePutCRLF())                                        _SwitchGroup             //12-04-04|0x077c
    switch(FileRelease())                                        _SwitchGroup             //06-12-17|0x077d
//***************************************************************************             //06-12-17|0x077e
    return(Success);                                                                      //06-12-17|0x077f
}                                                                                         //06-12-17|0x0780
//                                                                                        //05-24-97|0x0780
//***************************************************************************             //06-12-15|0x0783
//***************************************************************************             //06-12-15|0x0784
//******                                                               ******             //06-12-15|0x0785
//******                        report_numeric                         ******             //06-12-15|0x0786
//******                                                               ******             //06-12-15|0x0787
//***************************************************************************             //06-12-15|0x0788
//***************************************************************************             //06-12-15|0x0789
//*******************************************************************************         //10-29-97|0x078e
//*******************************************************************************         //10-29-97|0x078e
// report_numeric                                                                         //06-12-15|0x078e
//*******************************************************************************         //10-29-97|0x078e
//*******************************************************************************         //10-29-97|0x078e
UINT TESTPROJ::report_numeric(                                                            //06-12-15|0x078e
    SCHAR_FAR Title,                                                                      //06-12-15|0x078e
    SLONG Value                                                                           //06-12-15|0x078e
    ) {                                                                                   //06-12-15|0x078e
//*******************************************************************************         //10-29-97|0x078e
//***************************************************************************             //06-12-15|0x0791
//***************************************************************************             //06-12-15|0x0792
  WORDS work;                                                                        //06-12-15|0x0793
//***************************************************************************             //06-12-15|0x0794
//***************************************************************************             //06-12-15|0x0795
    TestSample(report_numeric_1);                                                         //06-12-15|0x0796
//***************************************************************************             //06-12-15|0x0797
    StrDataClr(BaseOutputAddr);                                                           //06-12-15|0x0798
//---------------------------------------------------------------------------             //06-12-15|0x0799
    sprintf(OutputLineAddr, "%-25.25s %6.6d", Title, Value);                              //06-12-15|0x079a
    work.ulong    = strlen(OutputLineAddr);                                               //06-12-15|0x079b
    OutputLength  = work.word0;                                                           //06-12-15|0x079c
//***************************************************************************             //06-12-15|0x079d
    switch(GuiAppendLine(OutputLineAddr))                        _SwitchGroup             //06-12-15|0x079e
//---------------------------------------------------------------------------             //06-12-15|0x079f
    switch(CommitSummaryFile)                                    _SwitchGroup             //06-12-15|0x07a0
    switch(FilePutText(BaseOutputAddr))                          _SwitchGroup             //12-04-04|0x07a1
    switch(FilePutCRLF())                                        _SwitchGroup             //12-04-04|0x07a2
    switch(FileRelease())                                        _SwitchGroup             //12-04-04|0x07a3
//---------------------------------------------------------------------------             //06-12-15|0x07a4
    return(Success);                                                                      //06-12-15|0x07a5
}                                                                                         //06-12-15|0x07a6
//                                                                                        //05-24-97|0x07a6
//***************************************************************************             //06-07-14|0x07a9
//***************************************************************************             //06-07-14|0x07aa
//******                                                               ******             //06-07-14|0x07ab
//******                       TEST WRAPPERS                           ******             //06-07-14|0x07ac
//******                                                               ******             //06-07-14|0x07ad
//***************************************************************************             //06-07-14|0x07ae
//***************************************************************************             //06-07-14|0x07af
//*******************************************************************************         //10-29-97|0x07b0
//*******************************************************************************         //10-29-97|0x07b0
// test_proj_test_reset                                                                   //06-07-14|0x07b0
//*******************************************************************************         //10-29-97|0x07b0
//*******************************************************************************         //10-29-97|0x07b0
UINT TESTPROJ::test_proj_test_reset(void) {                                               //06-07-14|0x07b0
//*******************************************************************************         //10-29-97|0x07b0
//************************************************************************                //06-07-14|0x07b0
    switch(BasicTestReset())                                                              //06-07-14|0x07b0
      {                                                                                   //06-07-14|0x07b0
        case Success:                                     return(Success);                //06-07-14|0x07b0
        default:                                        ReturnSystemError;                //06-07-14|0x07b0
        }                                                                                 //06-07-14|0x07b0
}                                                                                         //06-07-14|0x07b0
//                                                                                        //05-24-97|0x07b0
//***************************************************************************             //06-07-14|0x07b1
//*******************************************************************************         //10-29-97|0x07b2
//*******************************************************************************         //10-29-97|0x07b2
// test_proj_test_read                                                                    //06-07-14|0x07b2
//*******************************************************************************         //10-29-97|0x07b2
//*******************************************************************************         //10-29-97|0x07b2
UINT TESTPROJ::test_proj_test_read(void) {                                                //06-07-14|0x07b2
//*******************************************************************************         //10-29-97|0x07b2
//************************************************************************                //06-07-14|0x07b2
    switch(BasicTestRead(&test_samples[0], test_samples[0]))                              //06-07-14|0x07b2
      {                                                                                   //06-07-14|0x07b2
        case Success:                                     return(Success);                //06-07-14|0x07b2
        default:                                        ReturnSystemError;                //06-07-14|0x07b2
        }                                                                                 //06-07-14|0x07b2
}                                                                                         //06-07-14|0x07b2
//                                                                                        //05-24-97|0x07b2
//***************************************************************************             //06-07-14|0x07b3
//*******************************************************************************         //10-29-97|0x07b4
//*******************************************************************************         //10-29-97|0x07b4
// test_proj_test_write                                                                   //06-07-14|0x07b4
//*******************************************************************************         //10-29-97|0x07b4
//*******************************************************************************         //10-29-97|0x07b4
UINT TESTPROJ::test_proj_test_write(void) {                                               //06-07-14|0x07b4
//*******************************************************************************         //10-29-97|0x07b4
//************************************************************************                //06-07-14|0x07b4
    switch(BasicTestWrite(&test_samples[0]))                                              //06-07-14|0x07b4
      {                                                                                   //06-07-14|0x07b4
        case Success:                                     return(Success);                //06-07-14|0x07b4
        default:                                        ReturnSystemError;                //06-07-14|0x07b4
        }                                                                                 //06-07-14|0x07b4
}                                                                                         //06-07-14|0x07b4
//                                                                                        //05-24-97|0x07b4
//***************************************************************************             //06-07-14|0x07b5
//*******************************************************************************         //10-29-97|0x07b6
//*******************************************************************************         //10-29-97|0x07b6
// test_proj_test_report                                                                  //06-07-14|0x07b6
//*******************************************************************************         //10-29-97|0x07b6
//*******************************************************************************         //10-29-97|0x07b6
UINT TESTPROJ::test_proj_test_report(void) {                                              //06-07-14|0x07b6
//*******************************************************************************         //10-29-97|0x07b6
//************************************************************************                //06-07-14|0x07b6
    switch(BasicTestReport(&test_samples[0], "TEST_PROJ"))                                //06-07-14|0x07b6
      {                                                                                   //06-07-14|0x07b6
        case Success:                                     return(Success);                //06-07-14|0x07b6
        default:                                        ReturnSystemError;                //06-07-14|0x07b6
        }                                                                                 //06-07-14|0x07b6
}                                                                                         //06-07-14|0x07b6
//                                                                                        //05-24-97|0x07b6
//***************************************************************************             //06-07-12|0x07b9
//***************************************************************************             //06-07-12|0x07ba
//******                                                               ******             //06-07-12|0x07bb
//******                        constructor                            ******             //06-07-12|0x07bc
//******                                                               ******             //06-07-12|0x07bd
//***************************************************************************             //06-07-12|0x07be
//***************************************************************************             //06-07-12|0x07bf
//*******************************************************************************         //10-29-97|0x07c0
//*******************************************************************************         //10-29-97|0x07c0
// CONSTRUCTOR                                                                            //06-07-12|0x07c0
//*******************************************************************************         //10-29-97|0x07c0
//*******************************************************************************         //10-29-97|0x07c0
TESTPROJ::TESTPROJ() {                                                                    //06-07-12|0x07c0
//***************************************************************************             //06-07-12|0x07c1
//***************************************************************************             //06-07-12|0x07c2
    { ULONG i;                                                                            //06-07-12|0x07c3
      test_samples[NoTestSamples] = TestIndex;                                            //06-07-12|0x07c3
      i = 1;                                                                              //06-07-12|0x07c3
      while(i<TestIndex)                                                                  //06-07-12|0x07c3
        {                                                                                 //06-07-12|0x07c3
          test_samples[i] = 0;                                                            //06-07-12|0x07c3
          ++i;                                                                            //06-07-12|0x07c3
          }                                                                               //06-07-12|0x07c3
      }                                                                                   //06-07-12|0x07c3
    test_proj_addr = 0;                                                                   //06-07-12|0x07c4
}                                                                                         //06-07-12|0x07c5
//                                                                                        //05-24-97|0x07c5
//*******************************************************************************         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
//****                       END OF FILE                                     ****         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
