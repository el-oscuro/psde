//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
// DEVELOPMENT PROJECT ENGINE                                                             //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x0011
//  defined in the associated manual.                                                     //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x0011
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x0011
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x0011
//  (at your option) any later version.                                                   //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x0011
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x0011
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x0011
//  GNU General Public License for more details.                                          //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x0011
//  along with this program; if not, write to the Free Software                           //06-07-12|0x0011
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x0011
//  USA                                                                                   //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  For further information, please contact Robert Adams:                                 //06-07-12|0x0011
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x0011
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x0011
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
#ifdef WIN31_SYSTEM                                                                       //05-24-97|0x0012
#include "precwn31.h"                                                                     //05-24-97|0x0012
#endif                                                                                    //05-24-97|0x0012
#ifdef WIN95_SYSTEM                                                                       //05-24-97|0x0012
#include "precwn95.h"                                                                     //05-24-97|0x0012
#endif                                                                                    //05-24-97|0x0012
#ifdef MSDOS_SYSTEM                                                                       //05-24-97|0x0012
#include "precdos.h"                                                                      //05-24-97|0x0012
#endif                                                                                    //05-24-97|0x0012
#include "prechost.h"                                                                     //05-24-97|0x0012
#include "devproj.h"                                                                      //06-07-12|0x0012
#include "devproj.hxx"                                                                    //06-07-12|0x0012
#include "devproj.hpp"                                                                    //06-07-12|0x0012
#include "precutil.h"                                                                     //09-03-27|0x0013
#include "macproj.h"                                                                      //06-07-12|0x0014
#include "srcproj.h"                                                                      //06-07-12|0x0015
#include "precdiag.h"                                                                     //06-07-12|0x0016
#include "precdbug.h"                                                                     //08-12-31|0x0017
#include "precfile.h"                                                                     //06-07-12|0x0018
#include "preccall.h"                                                                     //06-07-12|0x0019
#include "prectext.h"                                                                     //06-07-23|0x001a
#include "precnum.h"                                                                      //09-03-27|0x001b
#define Allocate(k) (k##_FAR) calloc(1,sizeof(k))                                         //06-07-12|0x0023
#define Free(k) free(k)                                                                   //06-07-12|0x0023
#define MemSet(i,j,k) memset(i,j,k)                                                       //06-07-12|0x0023
#define MemCCpy(i,j,k,l) Mem_C_Copy((UCHAR_FAR) i, (UCHAR_FAR) j,k,l)                     //06-07-12|0x0023
#define MemCpy(i,j,k) memcpy(i,j,k)                                                       //06-07-12|0x0023
#define LineEnd 0x0d                                                                      //06-07-12|0x0023
#define StrLen(i) strlen(i)                                                               //06-07-12|0x0024
#define StrCat(i,j) strcat(i,j)                                                           //06-07-12|0x0024
#define StrCpy(i,j) strcpy(i,j)                                                           //06-07-12|0x0024
#define StrCmp(i,j) Str_Comp((SCHAR_FAR)i,j,256)                                          //06-07-12|0x0024
#define StrRChr(i,j) strrchr(i,j)                                                         //06-07-12|0x0024
#define StrChr(i,j) strchr(i,j)                                                           //06-07-12|0x0024
#define StrToByteInt(i,j) GetInteger(i,&j,0xff)                                           //06-07-12|0x0024
#define StrToInt(i,j) GetInteger(i,&j,0xffff)                                             //06-07-12|0x0024
#define StrToLongInt(i,j) GetInteger(i,&j,0xffffffffL)                                    //06-07-12|0x0024
#define StrToByteHex(i,j) GetHex(i,&j,1)                                                  //06-07-12|0x0024
#define StrToHex(i,j) GetHex(i,&j,2)                                                      //06-07-12|0x0024
#define StrToLongHex(i,j) GetHex(i,&j,4)                                                  //06-07-12|0x0024
#define FindName(i) strrchr(i, '/')                                                       //06-07-12|0x0024
DEVELOPMENTPROJ develop_proj;                                                             //06-07-12|0x0048
static UINT test_samples[TestIndex];                                                      //06-07-12|0x0058
#define FirstArg 1                                                                        //08-12-27|0x0065
//***************************************************************************             //06-07-12|0x0066
//***************************************************************************             //06-07-12|0x0067
//******                                                               ******             //06-07-12|0x0068
//******                       devproj_allocate                        ******             //06-07-12|0x0069
//******                                                               ******             //06-07-12|0x006a
//***************************************************************************             //06-07-12|0x006b
//***************************************************************************             //06-07-12|0x006c
//*******************************************************************************         //10-29-97|0x0073
//*******************************************************************************         //10-29-97|0x0073
// devproj_allocate                                                                       //06-07-12|0x0073
//*******************************************************************************         //10-29-97|0x0073
//*******************************************************************************         //10-29-97|0x0073
UINT DEVELOPMENTPROJ::devproj_allocate(void) {                                            //06-07-12|0x0073
//*******************************************************************************         //10-29-97|0x0073
//***************************************************************************             //06-07-12|0x0077
//***************************************************************************             //06-07-12|0x0078
    TestSample(devproj_allocate_1);                                                       //06-07-12|0x0079
    if(develop_project_addr                           != 0) ReturnSystemError             //06-07-12|0x007a
    develop_project_addr = Allocate(DEVELOPMENT_PROJECT);                                 //06-07-12|0x007b
    if(develop_project_addr                           == 0) ReturnSystemError             //06-07-12|0x007c
//***************************************************************************             //06-08-22|0x007d
  DevelopState = 4462; // INITIAL_DEVPRJ_NO                                               //11-12-12|0x007e
//***************************************************************************             //06-07-12|0x007f
    return(Success);                                                                      //06-07-12|0x0080
}                                                                                         //06-07-12|0x0081
//                                                                                        //05-24-97|0x0081
//***************************************************************************             //06-07-12|0x0084
//***************************************************************************             //06-07-12|0x0085
//******                                                               ******             //06-07-12|0x0086
//******                         devproj_free                          ******             //06-07-12|0x0087
//******                                                               ******             //06-07-12|0x0088
//***************************************************************************             //06-07-12|0x0089
//***************************************************************************             //06-07-12|0x008a
//*******************************************************************************         //10-29-97|0x008e
//*******************************************************************************         //10-29-97|0x008e
// devproj_free                                                                           //06-07-12|0x008e
//*******************************************************************************         //10-29-97|0x008e
//*******************************************************************************         //10-29-97|0x008e
UINT DEVELOPMENTPROJ::devproj_free(void) {                                                //06-07-12|0x008e
//*******************************************************************************         //10-29-97|0x008e
//***************************************************************************             //06-07-12|0x0092
//***************************************************************************             //06-07-12|0x0093
    TestSample(devproj_free_1);                                                           //06-07-12|0x0094
    if(develop_project_addr == 0)                           ReturnSystemError             //06-07-12|0x0095
    Free(develop_project_addr);                                                           //06-07-12|0x0096
    develop_project_addr = 0;                                                             //06-07-12|0x0097
//***************************************************************************             //06-07-12|0x0098
    return(Success);                                                                      //06-07-12|0x0099
}                                                                                         //06-07-12|0x009a
//                                                                                        //05-24-97|0x009a
//***************************************************************************             //06-07-20|0x009d
//***************************************************************************             //06-07-20|0x009e
//******                                                               ******             //06-07-20|0x009f
//******        devproj_process(MainTokensFar)                         ******             //06-07-20|0x00a0
//******                                                               ******             //06-07-20|0x00a1
//***************************************************************************             //06-07-20|0x00a2
//***************************************************************************             //06-07-20|0x00a3
//*******************************************************************************         //10-29-97|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
// devproj_process                                                                        //09-03-27|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
UINT DEVELOPMENTPROJ::devproj_process(                                                    //09-03-27|0x00a7
    TOKENS_FAR InputTokensFar,                                                            //09-03-27|0x00a7
    ULONG MainProjTime,                                                                   //09-03-27|0x00a7
    UINT_FAR TaskNoFar                                                                    //09-03-27|0x00a7
    ) {                                                                                   //09-03-27|0x00a7
//*******************************************************************************         //10-29-97|0x00a7
//***************************************************************************             //06-08-09|0x00ab
//***************************************************************************             //06-08-09|0x00ac
    if(develop_project_addr == 0)                           ReturnSystemError             //06-07-20|0x00ad
//***************************************************************************             //06-08-09|0x00ae
//******                                                               ******             //06-08-09|0x00af
//****** State Machine Beginning                                       ******             //06-08-09|0x00b0
//******                                                               ******             //06-08-09|0x00b1
//***************************************************************************             //06-08-09|0x00b2
  DevelopRunFlag = 1;                                                                     //06-08-22|0x00b3
  while(DevelopRunFlag != 0)                                                              //06-08-22|0x00b3
  {                                                                                       //06-08-22|0x00b3
    switch(DevelopState)                                                                  //06-08-22|0x00b3
    {                                                                                     //06-08-22|0x00b3
//***************************************************************************             //06-07-20|0x00b4
//******                                                               ******             //06-07-20|0x00b5
//****** INITIAL STATUS,                                               ******             //06-07-20|0x00b6
//******                                                               ******             //06-07-20|0x00b7
//***************************************************************************             //06-07-20|0x00b8
      case 4462: // INITIAL_DEVPRJ_NO                                                     //11-12-12|0x00b9
        InitialDevPrjNo;                                                                  //11-12-12|0x00b9
        DevelopState = 10445; // INITIAL_TASK_NO                                          //11-12-12|0x00b9
        break;                                                                            //11-12-12|0x00b9
//***************************************************************************             //11-12-12|0x00ba
      case 10445: // INITIAL_TASK_NO                                                      //11-12-12|0x00bb
        InitialTaskNo;                                                                    //11-12-12|0x00bb
        DevelopState = 46620; // ENTER_UPDATE_TIME                                        //11-12-12|0x00bb
        break;                                                                            //11-12-12|0x00bb
//***************************************************************************             //11-12-12|0x00bc
      case 46620: // ENTER_UPDATE_TIME                                                    //11-12-12|0x00bd
        InitialUpdateTime;                                                                //11-12-12|0x00bd
        DevelopState = 6235; // INITIAL_FILE_NAME                                         //11-12-12|0x00bd
        break;                                                                            //11-12-12|0x00bd
//***************************************************************************             //11-12-12|0x00be
      case 6235: // INITIAL_FILE_NAME                                                     //11-12-12|0x00bf
        InitialFileName;                                                                  //11-12-12|0x00bf
        DevelopState = 40586; // INCREMENT_DEVPRJ_NO                                      //11-12-12|0x00bf
        break;                                                                            //11-12-12|0x00bf
//***************************************************************************             //11-12-12|0x00c0
      case 40586: // INCREMENT_DEVPRJ_NO                                                  //11-12-12|0x00c1
        switch(IncrDevPrjNo)                                                              //11-12-12|0x00c1
        {                                                                                 //11-12-12|0x00c1
          case Success:                                                                   //11-12-12|0x00c1
            DevelopRunFlag = 1;                                                           //11-12-12|0x00c1
            DevelopState = 34729; // ENTER_PROJECT_NAME                                   //11-12-12|0x00c1
            break;                                                                        //11-12-12|0x00c1
          default:                                                                        //11-12-12|0x00c1
            DevelopStatus = SystemError;                                                  //11-12-12|0x00c1
            DevelopRunFlag = 0;                                                           //11-12-12|0x00c1
            SystemMsg;                                                                    //11-12-12|0x00c1
            break;                                                                        //11-12-12|0x00c1
        }                                                                                 //11-12-12|0x00c1
        break;                                                                            //11-12-12|0x00c1
//***************************************************************************             //06-07-20|0x00c2
//******                                                               ******             //06-07-20|0x00c3
//****** Open Project File,                                            ******             //06-07-20|0x00c4
//******                                                               ******             //06-07-20|0x00c5
//***************************************************************************             //06-07-20|0x00c6
      case 34729: // ENTER_PROJECT_NAME                                                   //11-12-12|0x00c7
        switch(EnterProjectName)                                                          //11-12-12|0x00c7
        {                                                                                 //11-12-12|0x00c7
          case Success:                                                                   //11-12-12|0x00c7
            DevelopRunFlag = 1;                                                           //11-12-12|0x00c7
            DevelopState = 696; // EXIST_PROJECT_FILE                                     //11-12-12|0x00c7
            break;                                                                        //11-12-12|0x00c7
          case UserError:                                                                 //11-12-12|0x00c7
            DevelopRunFlag = 1;                                                           //11-12-12|0x00c7
            DevelopState = 11959; // NEED_POP_USER                                        //11-12-12|0x00c7
            break;                                                                        //11-12-12|0x00c7
          default:                                                                        //11-12-12|0x00c7
            DevelopStatus = SystemError;                                                  //11-12-12|0x00c7
            DevelopRunFlag = 0;                                                           //11-12-12|0x00c7
            SystemMsg;                                                                    //11-12-12|0x00c7
            break;                                                                        //11-12-12|0x00c7
        }                                                                                 //11-12-12|0x00c7
        break;                                                                            //11-12-12|0x00c7
//---------------------------------------------------------------------------             //11-12-12|0x00c8
      case 696: // EXIST_PROJECT_FILE                                                     //11-12-12|0x00c9
        switch(ProjectExists)                                                             //11-12-12|0x00c9
        {                                                                                 //11-12-12|0x00c9
          case Success:                                                                   //11-12-12|0x00c9
            DevelopRunFlag = 1;                                                           //11-12-12|0x00c9
            DevelopState = 6822; // OPEN_PROJECT_FILE                                     //11-12-12|0x00c9
            break;                                                                        //11-12-12|0x00c9
          case UserError:                                                                 //11-12-12|0x00c9
            DevelopRunFlag = 1;                                                           //11-12-12|0x00c9
            DevelopState = 50565; // NO_PROJECT_FILE                                      //11-12-12|0x00c9
            break;                                                                        //11-12-12|0x00c9
          default:                                                                        //11-12-12|0x00c9
            DevelopStatus = SystemError;                                                  //11-12-12|0x00c9
            DevelopRunFlag = 0;                                                           //11-12-12|0x00c9
            SystemMsg;                                                                    //11-12-12|0x00c9
            break;                                                                        //11-12-12|0x00c9
        }                                                                                 //11-12-12|0x00c9
        break;                                                                            //11-12-12|0x00c9
//---------------------------------------------------------------------------             //06-07-20|0x00ca
      case 50565: // NO_PROJECT_FILE                                                      //check   |0x00cb
        switch(ProjectDoesNotExist)                                                       //check   |0x00cb
        {                                                                                 //check   |0x00cb
          case UserError:                                                                 //check   |0x00cb
            DevelopRunFlag = 1;                                                           //check   |0x00cb
            DevelopState = 11959; // NEED_POP_USER                                        //check   |0x00cb
            break;                                                                        //check   |0x00cb
          default:                                                                        //check   |0x00cb
            DevelopStatus = SystemError;                                                  //check   |0x00cb
            DevelopRunFlag = 0;                                                           //check   |0x00cb
            SystemMsg;                                                                    //check   |0x00cb
            break;                                                                        //check   |0x00cb
        }                                                                                 //check   |0x00cb
        break;                                                                            //check   |0x00cb
//---------------------------------------------------------------------------             //06-07-20|0x00cd
      case 6822: // OPEN_PROJECT_FILE                                                     //11-12-17|0x00ce
        switch(open_project())                                                            //11-12-17|0x00ce
        {                                                                                 //11-12-17|0x00ce
          case Success:                                                                   //11-12-17|0x00ce
            DevelopRunFlag = 1;                                                           //11-12-17|0x00ce
            DevelopState = 7764; // UPDATE_READ                                           //11-12-17|0x00ce
            break;                                                                        //11-12-17|0x00ce
          default:                                                                        //11-12-17|0x00ce
            DevelopStatus = SystemError;                                                  //11-12-17|0x00ce
            DevelopRunFlag = 0;                                                           //11-12-17|0x00ce
            SystemMsg;                                                                    //11-12-17|0x00ce
            break;                                                                        //11-12-17|0x00ce
        }                                                                                 //11-12-17|0x00ce
        break;                                                                            //11-12-17|0x00ce
//***************************************************************************             //06-07-23|0x00cf
//******                                                               ******             //06-07-23|0x00d0
//****** Perform Update Command                                        ******             //06-07-23|0x00d1
//******                                                               ******             //06-07-23|0x00d2
//***************************************************************************             //06-07-23|0x00d3
      case 7764: // UPDATE_READ                                                           //06-11-13|0x00d4
        switch(read_project())                                                            //06-11-13|0x00d4
        {                                                                                 //06-11-13|0x00d4
          case Display:                                                                   //06-11-13|0x00d4
            DevelopState = 1043; // UPDATE_READ_EXIT                                      //06-11-13|0x00d4
            DevelopStatus = Display;                                                      //06-11-13|0x00d4
            DevelopRunFlag = 0;                                                           //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          case LineDone:                                                                  //06-11-13|0x00d4
            DevelopRunFlag = 1;                                                           //06-11-13|0x00d4
            DevelopState = 17858; // CMD_UPDATE                                           //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          case FileDone:                                                                  //06-11-13|0x00d4
            DevelopRunFlag = 1;                                                           //06-11-13|0x00d4
            DevelopState = 41569; // END_FILE                                             //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          case UserError:                                                                 //06-11-13|0x00d4
            DevelopRunFlag = 1;                                                           //06-11-13|0x00d4
            DevelopState = 51440; // CLOSE_USER                                           //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          default:                                                                        //06-11-13|0x00d4
            DevelopStatus = SystemError;                                                  //06-11-13|0x00d4
            DevelopRunFlag = 0;                                                           //06-11-13|0x00d4
            SystemMsg;                                                                    //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
        }                                                                                 //06-11-13|0x00d4
        break;                                                                            //06-11-13|0x00d4
//**************************************************************************              //06-11-13|0x00d4
      case 1043: // UPDATE_READ_EXIT                                                      //06-11-13|0x00d4
        switch(read_project())                                                            //06-11-13|0x00d4
        {                                                                                 //06-11-13|0x00d4
          case Display:                                                                   //06-11-13|0x00d4
            DevelopState = 1043; // UPDATE_READ_EXIT                                      //06-11-13|0x00d4
            DevelopStatus = Display;                                                      //06-11-13|0x00d4
            DevelopRunFlag = 0;                                                           //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          case LineDone:                                                                  //06-11-13|0x00d4
            DevelopRunFlag = 1;                                                           //06-11-13|0x00d4
            DevelopState = 17858; // CMD_UPDATE                                           //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          case FileDone:                                                                  //06-11-13|0x00d4
            DevelopRunFlag = 1;                                                           //06-11-13|0x00d4
            DevelopState = 41569; // END_FILE                                             //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          case UserError:                                                                 //06-11-13|0x00d4
            DevelopRunFlag = 1;                                                           //06-11-13|0x00d4
            DevelopState = 51440; // CLOSE_USER                                           //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
          default:                                                                        //06-11-13|0x00d4
            DevelopStatus = SystemError;                                                  //06-11-13|0x00d4
            DevelopRunFlag = 0;                                                           //06-11-13|0x00d4
            SystemMsg;                                                                    //06-11-13|0x00d4
            break;                                                                        //06-11-13|0x00d4
        }                                                                                 //06-11-13|0x00d4
        break;                                                                            //06-11-13|0x00d4
//---------------------------------------------------------------------------             //06-11-13|0x00d5
      case 17858: // CMD_UPDATE                                                           //08-06-15|0x00d6
        switch(CmdTest("_UPDATE"))                                                        //08-06-15|0x00d6
        {                                                                                 //08-06-15|0x00d6
          case -1:                                                                        //08-06-15|0x00d6
            DevelopRunFlag = 1;                                                           //08-06-15|0x00d6
            DevelopState = 22639; // DISPLAY_ON_CMD                                       //08-06-15|0x00d6
            break;                                                                        //08-06-15|0x00d6
          case 0:                                                                         //08-06-15|0x00d6
            DevelopRunFlag = 1;                                                           //08-06-15|0x00d6
            DevelopState = 57310; // RUN_UPDATE                                           //08-06-15|0x00d6
            break;                                                                        //08-06-15|0x00d6
          case 1:                                                                         //08-06-15|0x00d6
            DevelopRunFlag = 1;                                                           //08-06-15|0x00d6
            DevelopState = 22639; // DISPLAY_ON_CMD                                       //08-06-15|0x00d6
            break;                                                                        //08-06-15|0x00d6
          default:                                                                        //08-06-15|0x00d6
            DevelopStatus = SystemError;                                                  //08-06-15|0x00d6
            DevelopRunFlag = 0;                                                           //08-06-15|0x00d6
            SystemMsg;                                                                    //08-06-15|0x00d6
            break;                                                                        //08-06-15|0x00d6
        }                                                                                 //08-06-15|0x00d6
        break;                                                                            //08-06-15|0x00d6
//---------------------------------------------------------------------------             //06-11-13|0x00d7
      case 57310: // RUN_UPDATE                                                           //08-06-15|0x00d8
        switch(update_always())                                                           //08-06-15|0x00d8
        {                                                                                 //08-06-15|0x00d8
          case Success:                                                                   //08-06-15|0x00d8
            DevelopRunFlag = 1;                                                           //08-06-15|0x00d8
            DevelopState = 56893; // DISPLAY_ON_READ                                      //08-06-15|0x00d8
            break;                                                                        //08-06-15|0x00d8
          case UserError:                                                                 //08-06-15|0x00d8
            DevelopRunFlag = 1;                                                           //08-06-15|0x00d8
            DevelopState = 51440; // CLOSE_USER                                           //08-06-15|0x00d8
            break;                                                                        //08-06-15|0x00d8
          default:                                                                        //08-06-15|0x00d8
            DevelopStatus = SystemError;                                                  //08-06-15|0x00d8
            DevelopRunFlag = 0;                                                           //08-06-15|0x00d8
            SystemMsg;                                                                    //08-06-15|0x00d8
            break;                                                                        //08-06-15|0x00d8
        }                                                                                 //08-06-15|0x00d8
        break;                                                                            //08-06-15|0x00d8
//***************************************************************************             //08-06-15|0x00d9
//******                                                               ******             //08-06-15|0x00da
//****** Process Display Control command                               ******             //08-06-15|0x00db
//******                                                               ******             //08-06-15|0x00dc
//***************************************************************************             //08-06-15|0x00dd
      case 56893: // DISPLAY_ON_READ                                                      //08-06-15|0x00de
        switch(read_project())                                                            //08-06-15|0x00de
        {                                                                                 //08-06-15|0x00de
          case Display:                                                                   //08-06-15|0x00de
            DevelopState = 49804; // DISPLAY_ON_READ_EXIT                                 //08-06-15|0x00de
            DevelopStatus = Display;                                                      //08-06-15|0x00de
            DevelopRunFlag = 0;                                                           //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          case LineDone:                                                                  //08-06-15|0x00de
            DevelopRunFlag = 1;                                                           //08-06-15|0x00de
            DevelopState = 22639; // DISPLAY_ON_CMD                                       //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          case FileDone:                                                                  //08-06-15|0x00de
            DevelopRunFlag = 1;                                                           //08-06-15|0x00de
            DevelopState = 41569; // END_FILE                                             //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          case UserError:                                                                 //08-06-15|0x00de
            DevelopRunFlag = 1;                                                           //08-06-15|0x00de
            DevelopState = 51440; // CLOSE_USER                                           //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          default:                                                                        //08-06-15|0x00de
            DevelopStatus = SystemError;                                                  //08-06-15|0x00de
            DevelopRunFlag = 0;                                                           //08-06-15|0x00de
            SystemMsg;                                                                    //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
        }                                                                                 //08-06-15|0x00de
        break;                                                                            //08-06-15|0x00de
//**************************************************************************              //08-06-15|0x00de
      case 49804: // DISPLAY_ON_READ_EXIT                                                 //08-06-15|0x00de
        switch(read_project())                                                            //08-06-15|0x00de
        {                                                                                 //08-06-15|0x00de
          case Display:                                                                   //08-06-15|0x00de
            DevelopState = 49804; // DISPLAY_ON_READ_EXIT                                 //08-06-15|0x00de
            DevelopStatus = Display;                                                      //08-06-15|0x00de
            DevelopRunFlag = 0;                                                           //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          case LineDone:                                                                  //08-06-15|0x00de
            DevelopRunFlag = 1;                                                           //08-06-15|0x00de
            DevelopState = 22639; // DISPLAY_ON_CMD                                       //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          case FileDone:                                                                  //08-06-15|0x00de
            DevelopRunFlag = 1;                                                           //08-06-15|0x00de
            DevelopState = 41569; // END_FILE                                             //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          case UserError:                                                                 //08-06-15|0x00de
            DevelopRunFlag = 1;                                                           //08-06-15|0x00de
            DevelopState = 51440; // CLOSE_USER                                           //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
          default:                                                                        //08-06-15|0x00de
            DevelopStatus = SystemError;                                                  //08-06-15|0x00de
            DevelopRunFlag = 0;                                                           //08-06-15|0x00de
            SystemMsg;                                                                    //08-06-15|0x00de
            break;                                                                        //08-06-15|0x00de
        }                                                                                 //08-06-15|0x00de
        break;                                                                            //08-06-15|0x00de
//***************************************************************************             //08-06-15|0x00df
      case 22639: // DISPLAY_ON_CMD                                                       //08-06-15|0x00e0
        switch(CmdTest("_ENABLE_DISPLAY"))                                                //08-06-15|0x00e0
        {                                                                                 //08-06-15|0x00e0
          case -1:                                                                        //08-06-15|0x00e0
            DevelopRunFlag = 1;                                                           //08-06-15|0x00e0
            DevelopState = 60363; // DISPLAY_OFF_CMD                                      //08-06-15|0x00e0
            break;                                                                        //08-06-15|0x00e0
          case 0:                                                                         //08-06-15|0x00e0
            DevelopRunFlag = 1;                                                           //08-06-15|0x00e0
            DevelopState = 43258; // RUN_DISPLAY_ON                                       //08-06-15|0x00e0
            break;                                                                        //08-06-15|0x00e0
          case 1:                                                                         //08-06-15|0x00e0
            DevelopRunFlag = 1;                                                           //08-06-15|0x00e0
            DevelopState = 60363; // DISPLAY_OFF_CMD                                      //08-06-15|0x00e0
            break;                                                                        //08-06-15|0x00e0
          default:                                                                        //08-06-15|0x00e0
            DevelopStatus = SystemError;                                                  //08-06-15|0x00e0
            DevelopRunFlag = 0;                                                           //08-06-15|0x00e0
            SystemMsg;                                                                    //08-06-15|0x00e0
            break;                                                                        //08-06-15|0x00e0
        }                                                                                 //08-06-15|0x00e0
        break;                                                                            //08-06-15|0x00e0
//---------------------------------------------------------------------------             //08-06-15|0x00e1
      case 43258: // RUN_DISPLAY_ON                                                       //09-03-27|0x00e2
        switch(turn_on_display())                                                         //09-03-27|0x00e2
        {                                                                                 //09-03-27|0x00e2
          case Success:                                                                   //09-03-27|0x00e2
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e2
            DevelopState = 14617; // TASK_NO_READ                                         //09-03-27|0x00e2
            break;                                                                        //09-03-27|0x00e2
          case UserError:                                                                 //09-03-27|0x00e2
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e2
            DevelopState = 51440; // CLOSE_USER                                           //09-03-27|0x00e2
            break;                                                                        //09-03-27|0x00e2
          default:                                                                        //09-03-27|0x00e2
            DevelopStatus = SystemError;                                                  //09-03-27|0x00e2
            DevelopRunFlag = 0;                                                           //09-03-27|0x00e2
            SystemMsg;                                                                    //09-03-27|0x00e2
            break;                                                                        //09-03-27|0x00e2
        }                                                                                 //09-03-27|0x00e2
        break;                                                                            //09-03-27|0x00e2
//***************************************************************************             //09-03-27|0x00e3
      case 60363: // DISPLAY_OFF_CMD                                                      //09-03-27|0x00e4
        switch(CmdTest("_DISABLE_DISPLAY"))                                               //09-03-27|0x00e4
        {                                                                                 //09-03-27|0x00e4
          case -1:                                                                        //09-03-27|0x00e4
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e4
            DevelopState = 52008; // TASK_NO_CMD                                          //09-03-27|0x00e4
            break;                                                                        //09-03-27|0x00e4
          case 0:                                                                         //09-03-27|0x00e4
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e4
            DevelopState = 32295; // RUN_DISPLAY_OFF                                      //09-03-27|0x00e4
            break;                                                                        //09-03-27|0x00e4
          case 1:                                                                         //09-03-27|0x00e4
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e4
            DevelopState = 52008; // TASK_NO_CMD                                          //09-03-27|0x00e4
            break;                                                                        //09-03-27|0x00e4
          default:                                                                        //09-03-27|0x00e4
            DevelopStatus = SystemError;                                                  //09-03-27|0x00e4
            DevelopRunFlag = 0;                                                           //09-03-27|0x00e4
            SystemMsg;                                                                    //09-03-27|0x00e4
            break;                                                                        //09-03-27|0x00e4
        }                                                                                 //09-03-27|0x00e4
        break;                                                                            //09-03-27|0x00e4
//---------------------------------------------------------------------------             //09-03-27|0x00e5
      case 32295: // RUN_DISPLAY_OFF                                                      //09-03-27|0x00e6
        switch(turn_off_display())                                                        //09-03-27|0x00e6
        {                                                                                 //09-03-27|0x00e6
          case Success:                                                                   //09-03-27|0x00e6
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e6
            DevelopState = 14617; // TASK_NO_READ                                         //09-03-27|0x00e6
            break;                                                                        //09-03-27|0x00e6
          case UserError:                                                                 //09-03-27|0x00e6
            DevelopRunFlag = 1;                                                           //09-03-27|0x00e6
            DevelopState = 51440; // CLOSE_USER                                           //09-03-27|0x00e6
            break;                                                                        //09-03-27|0x00e6
          default:                                                                        //09-03-27|0x00e6
            DevelopStatus = SystemError;                                                  //09-03-27|0x00e6
            DevelopRunFlag = 0;                                                           //09-03-27|0x00e6
            SystemMsg;                                                                    //09-03-27|0x00e6
            break;                                                                        //09-03-27|0x00e6
        }                                                                                 //09-03-27|0x00e6
        break;                                                                            //09-03-27|0x00e6
//***************************************************************************             //09-03-27|0x00e7
//******                                                               ******             //09-03-27|0x00e8
//****** Process Task No command                                       ******             //09-03-27|0x00e9
//******                                                               ******             //09-03-27|0x00ea
//***************************************************************************             //09-03-27|0x00eb
      case 14617: // TASK_NO_READ                                                         //09-03-27|0x00ec
        switch(read_project())                                                            //09-03-27|0x00ec
        {                                                                                 //09-03-27|0x00ec
          case Display:                                                                   //09-03-27|0x00ec
            DevelopState = 24854; // TASK_NO_READ_EXIT                                    //09-03-27|0x00ec
            DevelopStatus = Display;                                                      //09-03-27|0x00ec
            DevelopRunFlag = 0;                                                           //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          case LineDone:                                                                  //09-03-27|0x00ec
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ec
            DevelopState = 52008; // TASK_NO_CMD                                          //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          case FileDone:                                                                  //09-03-27|0x00ec
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ec
            DevelopState = 41569; // END_FILE                                             //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          case UserError:                                                                 //09-03-27|0x00ec
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ec
            DevelopState = 51440; // CLOSE_USER                                           //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          default:                                                                        //09-03-27|0x00ec
            DevelopStatus = SystemError;                                                  //09-03-27|0x00ec
            DevelopRunFlag = 0;                                                           //09-03-27|0x00ec
            SystemMsg;                                                                    //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
        }                                                                                 //09-03-27|0x00ec
        break;                                                                            //09-03-27|0x00ec
//**************************************************************************              //09-03-27|0x00ec
      case 24854: // TASK_NO_READ_EXIT                                                    //09-03-27|0x00ec
        switch(read_project())                                                            //09-03-27|0x00ec
        {                                                                                 //09-03-27|0x00ec
          case Display:                                                                   //09-03-27|0x00ec
            DevelopState = 24854; // TASK_NO_READ_EXIT                                    //09-03-27|0x00ec
            DevelopStatus = Display;                                                      //09-03-27|0x00ec
            DevelopRunFlag = 0;                                                           //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          case LineDone:                                                                  //09-03-27|0x00ec
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ec
            DevelopState = 52008; // TASK_NO_CMD                                          //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          case FileDone:                                                                  //09-03-27|0x00ec
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ec
            DevelopState = 41569; // END_FILE                                             //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          case UserError:                                                                 //09-03-27|0x00ec
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ec
            DevelopState = 51440; // CLOSE_USER                                           //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
          default:                                                                        //09-03-27|0x00ec
            DevelopStatus = SystemError;                                                  //09-03-27|0x00ec
            DevelopRunFlag = 0;                                                           //09-03-27|0x00ec
            SystemMsg;                                                                    //09-03-27|0x00ec
            break;                                                                        //09-03-27|0x00ec
        }                                                                                 //09-03-27|0x00ec
        break;                                                                            //09-03-27|0x00ec
//***************************************************************************             //09-03-27|0x00ed
      case 52008: // TASK_NO_CMD                                                          //09-03-27|0x00ee
        switch(CmdTest("_TASK_NO"))                                                       //09-03-27|0x00ee
        {                                                                                 //09-03-27|0x00ee
          case -1:                                                                        //09-03-27|0x00ee
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ee
            DevelopState = 29429; // ILLEGAL_COMMAND                                      //09-03-27|0x00ee
            break;                                                                        //09-03-27|0x00ee
          case 0:                                                                         //09-03-27|0x00ee
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ee
            DevelopState = 41668; // LOAD_TASK_NO                                         //09-03-27|0x00ee
            break;                                                                        //09-03-27|0x00ee
          case 1:                                                                         //09-03-27|0x00ee
            DevelopRunFlag = 1;                                                           //09-03-27|0x00ee
            DevelopState = 29429; // ILLEGAL_COMMAND                                      //09-03-27|0x00ee
            break;                                                                        //09-03-27|0x00ee
          default:                                                                        //09-03-27|0x00ee
            DevelopStatus = SystemError;                                                  //09-03-27|0x00ee
            DevelopRunFlag = 0;                                                           //09-03-27|0x00ee
            SystemMsg;                                                                    //09-03-27|0x00ee
            break;                                                                        //09-03-27|0x00ee
        }                                                                                 //09-03-27|0x00ee
        break;                                                                            //09-03-27|0x00ee
//---------------------------------------------------------------------------             //09-03-27|0x00ef
      case 41668: // LOAD_TASK_NO                                                         //11-12-12|0x00f0
        switch(UpdateTaskNo)                                                              //11-12-12|0x00f0
        {                                                                                 //11-12-12|0x00f0
          case Success:                                                                   //11-12-12|0x00f0
            DevelopRunFlag = 1;                                                           //11-12-12|0x00f0
            DevelopState = 53123; // DEBUG_READ                                           //11-12-12|0x00f0
            break;                                                                        //11-12-12|0x00f0
          case UserError:                                                                 //11-12-12|0x00f0
            DevelopRunFlag = 1;                                                           //11-12-12|0x00f0
            DevelopState = 51440; // CLOSE_USER                                           //11-12-12|0x00f0
            break;                                                                        //11-12-12|0x00f0
          default:                                                                        //11-12-12|0x00f0
            DevelopStatus = SystemError;                                                  //11-12-12|0x00f0
            DevelopRunFlag = 0;                                                           //11-12-12|0x00f0
            SystemMsg;                                                                    //11-12-12|0x00f0
            break;                                                                        //11-12-12|0x00f0
        }                                                                                 //11-12-12|0x00f0
        break;                                                                            //11-12-12|0x00f0
//***************************************************************************             //08-12-31|0x00f1
//******                                                               ******             //08-12-31|0x00f2
//****** Process Debug Command                                         ******             //08-12-31|0x00f3
//******                                                               ******             //08-12-31|0x00f4
//***************************************************************************             //08-12-31|0x00f5
      case 53123: // DEBUG_READ                                                           //08-12-31|0x00f6
        switch(read_project())                                                            //08-12-31|0x00f6
        {                                                                                 //08-12-31|0x00f6
          case Display:                                                                   //08-12-31|0x00f6
            DevelopState = 51250; // DEBUG_READ_EXIT                                      //08-12-31|0x00f6
            DevelopStatus = Display;                                                      //08-12-31|0x00f6
            DevelopRunFlag = 0;                                                           //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          case LineDone:                                                                  //08-12-31|0x00f6
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f6
            DevelopState = 19409; // DEBUG_CMD                                            //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          case FileDone:                                                                  //08-12-31|0x00f6
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f6
            DevelopState = 41569; // END_FILE                                             //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          case UserError:                                                                 //08-12-31|0x00f6
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f6
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          default:                                                                        //08-12-31|0x00f6
            DevelopStatus = SystemError;                                                  //08-12-31|0x00f6
            DevelopRunFlag = 0;                                                           //08-12-31|0x00f6
            SystemMsg;                                                                    //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
        }                                                                                 //08-12-31|0x00f6
        break;                                                                            //08-12-31|0x00f6
//**************************************************************************              //08-12-31|0x00f6
      case 51250: // DEBUG_READ_EXIT                                                      //08-12-31|0x00f6
        switch(read_project())                                                            //08-12-31|0x00f6
        {                                                                                 //08-12-31|0x00f6
          case Display:                                                                   //08-12-31|0x00f6
            DevelopState = 51250; // DEBUG_READ_EXIT                                      //08-12-31|0x00f6
            DevelopStatus = Display;                                                      //08-12-31|0x00f6
            DevelopRunFlag = 0;                                                           //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          case LineDone:                                                                  //08-12-31|0x00f6
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f6
            DevelopState = 19409; // DEBUG_CMD                                            //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          case FileDone:                                                                  //08-12-31|0x00f6
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f6
            DevelopState = 41569; // END_FILE                                             //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          case UserError:                                                                 //08-12-31|0x00f6
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f6
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
          default:                                                                        //08-12-31|0x00f6
            DevelopStatus = SystemError;                                                  //08-12-31|0x00f6
            DevelopRunFlag = 0;                                                           //08-12-31|0x00f6
            SystemMsg;                                                                    //08-12-31|0x00f6
            break;                                                                        //08-12-31|0x00f6
        }                                                                                 //08-12-31|0x00f6
        break;                                                                            //08-12-31|0x00f6
//***************************************************************************             //08-12-31|0x00f7
      case 19409: // DEBUG_CMD                                                            //08-12-31|0x00f8
        switch(CmdTest("_DEBUG"))                                                         //08-12-31|0x00f8
        {                                                                                 //08-12-31|0x00f8
          case -1:                                                                        //08-12-31|0x00f8
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f8
            DevelopState = 2400; // FILETIME_ON_CMD                                       //08-12-31|0x00f8
            break;                                                                        //08-12-31|0x00f8
          case 0:                                                                         //08-12-31|0x00f8
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f8
            DevelopState = 40927; // DEBUG_ON                                             //08-12-31|0x00f8
            break;                                                                        //08-12-31|0x00f8
          case 1:                                                                         //08-12-31|0x00f8
            DevelopRunFlag = 1;                                                           //08-12-31|0x00f8
            DevelopState = 2400; // FILETIME_ON_CMD                                       //08-12-31|0x00f8
            break;                                                                        //08-12-31|0x00f8
          default:                                                                        //08-12-31|0x00f8
            DevelopStatus = SystemError;                                                  //08-12-31|0x00f8
            DevelopRunFlag = 0;                                                           //08-12-31|0x00f8
            SystemMsg;                                                                    //08-12-31|0x00f8
            break;                                                                        //08-12-31|0x00f8
        }                                                                                 //08-12-31|0x00f8
        break;                                                                            //08-12-31|0x00f8
//---------------------------------------------------------------------------             //08-12-31|0x00f9
      case 40927: // DEBUG_ON                                                             //08-12-31|0x00fa
        switch(single_step_enable())                                                      //08-12-31|0x00fa
        {                                                                                 //08-12-31|0x00fa
          case Success:                                                                   //08-12-31|0x00fa
            DevelopRunFlag = 1;                                                           //08-12-31|0x00fa
            DevelopState = 40526; // FILETIME_READ                                        //08-12-31|0x00fa
            break;                                                                        //08-12-31|0x00fa
          default:                                                                        //08-12-31|0x00fa
            DevelopStatus = SystemError;                                                  //08-12-31|0x00fa
            DevelopRunFlag = 0;                                                           //08-12-31|0x00fa
            SystemMsg;                                                                    //08-12-31|0x00fa
            break;                                                                        //08-12-31|0x00fa
        }                                                                                 //08-12-31|0x00fa
        break;                                                                            //08-12-31|0x00fa
//***************************************************************************             //08-06-15|0x00fb
//******                                                               ******             //08-06-15|0x00fc
//****** Process File Time Control command                             ******             //08-06-15|0x00fd
//******                                                               ******             //08-06-15|0x00fe
//***************************************************************************             //08-06-15|0x00ff
      case 40526: // FILETIME_READ                                                        //08-12-31|0x0100
        switch(read_project())                                                            //08-12-31|0x0100
        {                                                                                 //08-12-31|0x0100
          case Display:                                                                   //08-12-31|0x0100
            DevelopState = 33709; // FILETIME_READ_EXIT                                   //08-12-31|0x0100
            DevelopStatus = Display;                                                      //08-12-31|0x0100
            DevelopRunFlag = 0;                                                           //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          case LineDone:                                                                  //08-12-31|0x0100
            DevelopRunFlag = 1;                                                           //08-12-31|0x0100
            DevelopState = 48892; // FILETIME_ON_PAUSE                                    //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          case FileDone:                                                                  //08-12-31|0x0100
            DevelopRunFlag = 1;                                                           //08-12-31|0x0100
            DevelopState = 41569; // END_FILE                                             //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          case UserError:                                                                 //08-12-31|0x0100
            DevelopRunFlag = 1;                                                           //08-12-31|0x0100
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          default:                                                                        //08-12-31|0x0100
            DevelopStatus = SystemError;                                                  //08-12-31|0x0100
            DevelopRunFlag = 0;                                                           //08-12-31|0x0100
            SystemMsg;                                                                    //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
        }                                                                                 //08-12-31|0x0100
        break;                                                                            //08-12-31|0x0100
//**************************************************************************              //08-12-31|0x0100
      case 33709: // FILETIME_READ_EXIT                                                   //08-12-31|0x0100
        switch(read_project())                                                            //08-12-31|0x0100
        {                                                                                 //08-12-31|0x0100
          case Display:                                                                   //08-12-31|0x0100
            DevelopState = 33709; // FILETIME_READ_EXIT                                   //08-12-31|0x0100
            DevelopStatus = Display;                                                      //08-12-31|0x0100
            DevelopRunFlag = 0;                                                           //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          case LineDone:                                                                  //08-12-31|0x0100
            DevelopRunFlag = 1;                                                           //08-12-31|0x0100
            DevelopState = 48892; // FILETIME_ON_PAUSE                                    //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          case FileDone:                                                                  //08-12-31|0x0100
            DevelopRunFlag = 1;                                                           //08-12-31|0x0100
            DevelopState = 41569; // END_FILE                                             //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          case UserError:                                                                 //08-12-31|0x0100
            DevelopRunFlag = 1;                                                           //08-12-31|0x0100
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
          default:                                                                        //08-12-31|0x0100
            DevelopStatus = SystemError;                                                  //08-12-31|0x0100
            DevelopRunFlag = 0;                                                           //08-12-31|0x0100
            SystemMsg;                                                                    //08-12-31|0x0100
            break;                                                                        //08-12-31|0x0100
        }                                                                                 //08-12-31|0x0100
        break;                                                                            //08-12-31|0x0100
//---------------------------------------------------------------------------             //08-12-31|0x0101
      case 48892: // FILETIME_ON_PAUSE                                                    //08-12-31|0x0102
        switch(DebugPause)                                                                //08-12-31|0x0102
        {                                                                                 //08-12-31|0x0102
          case Display:                                                                   //08-12-31|0x0102
            DevelopState = 44859; // FILETIME_ON_PAUSE_EXIT                               //08-12-31|0x0102
            DevelopStatus = Display;                                                      //08-12-31|0x0102
            DevelopRunFlag = 0;                                                           //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case KeyBoard:                                                                  //08-12-31|0x0102
            DevelopState = 44859; // FILETIME_ON_PAUSE_EXIT                               //08-12-31|0x0102
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0102
            DevelopRunFlag = 0;                                                           //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case Continue:                                                                  //08-12-31|0x0102
            DevelopRunFlag = 1;                                                           //08-12-31|0x0102
            DevelopState = 48892; // FILETIME_ON_PAUSE                                    //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case Success:                                                                   //08-12-31|0x0102
            DevelopRunFlag = 1;                                                           //08-12-31|0x0102
            DevelopState = 2400; // FILETIME_ON_CMD                                       //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case UserError:                                                                 //08-12-31|0x0102
            DevelopRunFlag = 1;                                                           //08-12-31|0x0102
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          default:                                                                        //08-12-31|0x0102
            DevelopStatus = SystemError;                                                  //08-12-31|0x0102
            DevelopRunFlag = 0;                                                           //08-12-31|0x0102
            SystemMsg;                                                                    //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
        }                                                                                 //08-12-31|0x0102
        break;                                                                            //08-12-31|0x0102
//**************************************************************************              //08-12-31|0x0102
      case 44859: // FILETIME_ON_PAUSE_EXIT                                               //08-12-31|0x0102
        switch(DebugPause)                                                                //08-12-31|0x0102
        {                                                                                 //08-12-31|0x0102
          case Display:                                                                   //08-12-31|0x0102
            DevelopState = 44859; // FILETIME_ON_PAUSE_EXIT                               //08-12-31|0x0102
            DevelopStatus = Display;                                                      //08-12-31|0x0102
            DevelopRunFlag = 0;                                                           //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case KeyBoard:                                                                  //08-12-31|0x0102
            DevelopState = 44859; // FILETIME_ON_PAUSE_EXIT                               //08-12-31|0x0102
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0102
            DevelopRunFlag = 0;                                                           //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case Continue:                                                                  //08-12-31|0x0102
            DevelopRunFlag = 1;                                                           //08-12-31|0x0102
            DevelopState = 48892; // FILETIME_ON_PAUSE                                    //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case Success:                                                                   //08-12-31|0x0102
            DevelopRunFlag = 1;                                                           //08-12-31|0x0102
            DevelopState = 2400; // FILETIME_ON_CMD                                       //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          case UserError:                                                                 //08-12-31|0x0102
            DevelopRunFlag = 1;                                                           //08-12-31|0x0102
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
          default:                                                                        //08-12-31|0x0102
            DevelopStatus = SystemError;                                                  //08-12-31|0x0102
            DevelopRunFlag = 0;                                                           //08-12-31|0x0102
            SystemMsg;                                                                    //08-12-31|0x0102
            break;                                                                        //08-12-31|0x0102
        }                                                                                 //08-12-31|0x0102
        break;                                                                            //08-12-31|0x0102
//***************************************************************************             //08-06-15|0x0103
      case 2400: // FILETIME_ON_CMD                                                       //08-06-15|0x0104
        switch(CmdTest("_ENABLE_FILE_TIME"))                                              //08-06-15|0x0104
        {                                                                                 //08-06-15|0x0104
          case -1:                                                                        //08-06-15|0x0104
            DevelopRunFlag = 1;                                                           //08-06-15|0x0104
            DevelopState = 41834; // FILETIME_OFF_CMD                                     //08-06-15|0x0104
            break;                                                                        //08-06-15|0x0104
          case 0:                                                                         //08-06-15|0x0104
            DevelopRunFlag = 1;                                                           //08-06-15|0x0104
            DevelopState = 55945; // RUN_FILETIME_ON                                      //08-06-15|0x0104
            break;                                                                        //08-06-15|0x0104
          case 1:                                                                         //08-06-15|0x0104
            DevelopRunFlag = 1;                                                           //08-06-15|0x0104
            DevelopState = 41834; // FILETIME_OFF_CMD                                     //08-06-15|0x0104
            break;                                                                        //08-06-15|0x0104
          default:                                                                        //08-06-15|0x0104
            DevelopStatus = SystemError;                                                  //08-06-15|0x0104
            DevelopRunFlag = 0;                                                           //08-06-15|0x0104
            SystemMsg;                                                                    //08-06-15|0x0104
            break;                                                                        //08-06-15|0x0104
        }                                                                                 //08-06-15|0x0104
        break;                                                                            //08-06-15|0x0104
//---------------------------------------------------------------------------             //08-06-15|0x0105
      case 55945: // RUN_FILETIME_ON                                                      //08-06-15|0x0106
        switch(enable_file_time())                                                        //08-06-15|0x0106
        {                                                                                 //08-06-15|0x0106
          case Success:                                                                   //08-06-15|0x0106
            DevelopRunFlag = 1;                                                           //08-06-15|0x0106
            DevelopState = 33688; // FIRST_READ                                           //08-06-15|0x0106
            break;                                                                        //08-06-15|0x0106
          case UserError:                                                                 //08-06-15|0x0106
            DevelopRunFlag = 1;                                                           //08-06-15|0x0106
            DevelopState = 51440; // CLOSE_USER                                           //08-06-15|0x0106
            break;                                                                        //08-06-15|0x0106
          default:                                                                        //08-06-15|0x0106
            DevelopStatus = SystemError;                                                  //08-06-15|0x0106
            DevelopRunFlag = 0;                                                           //08-06-15|0x0106
            SystemMsg;                                                                    //08-06-15|0x0106
            break;                                                                        //08-06-15|0x0106
        }                                                                                 //08-06-15|0x0106
        break;                                                                            //08-06-15|0x0106
//***************************************************************************             //08-06-15|0x0107
      case 41834: // FILETIME_OFF_CMD                                                     //08-06-15|0x0108
        switch(CmdTest("_DISABLE_FILE_TIME"))                                             //08-06-15|0x0108
        {                                                                                 //08-06-15|0x0108
          case -1:                                                                        //08-06-15|0x0108
            DevelopRunFlag = 1;                                                           //08-06-15|0x0108
            DevelopState = 48535; // CMD_DRIVE_PATH                                       //08-06-15|0x0108
            break;                                                                        //08-06-15|0x0108
          case 0:                                                                         //08-06-15|0x0108
            DevelopRunFlag = 1;                                                           //08-06-15|0x0108
            DevelopState = 38790; // RUN_FILETIME_OFF                                     //08-06-15|0x0108
            break;                                                                        //08-06-15|0x0108
          case 1:                                                                         //08-06-15|0x0108
            DevelopRunFlag = 1;                                                           //08-06-15|0x0108
            DevelopState = 48535; // CMD_DRIVE_PATH                                       //08-06-15|0x0108
            break;                                                                        //08-06-15|0x0108
          default:                                                                        //08-06-15|0x0108
            DevelopStatus = SystemError;                                                  //08-06-15|0x0108
            DevelopRunFlag = 0;                                                           //08-06-15|0x0108
            SystemMsg;                                                                    //08-06-15|0x0108
            break;                                                                        //08-06-15|0x0108
        }                                                                                 //08-06-15|0x0108
        break;                                                                            //08-06-15|0x0108
//---------------------------------------------------------------------------             //08-06-15|0x0109
      case 38790: // RUN_FILETIME_OFF                                                     //08-06-15|0x010a
        switch(disable_file_time())                                                       //08-06-15|0x010a
        {                                                                                 //08-06-15|0x010a
          case Success:                                                                   //08-06-15|0x010a
            DevelopRunFlag = 1;                                                           //08-06-15|0x010a
            DevelopState = 33688; // FIRST_READ                                           //08-06-15|0x010a
            break;                                                                        //08-06-15|0x010a
          case UserError:                                                                 //08-06-15|0x010a
            DevelopRunFlag = 1;                                                           //08-06-15|0x010a
            DevelopState = 51440; // CLOSE_USER                                           //08-06-15|0x010a
            break;                                                                        //08-06-15|0x010a
          default:                                                                        //08-06-15|0x010a
            DevelopStatus = SystemError;                                                  //08-06-15|0x010a
            DevelopRunFlag = 0;                                                           //08-06-15|0x010a
            SystemMsg;                                                                    //08-06-15|0x010a
            break;                                                                        //08-06-15|0x010a
        }                                                                                 //08-06-15|0x010a
        break;                                                                            //08-06-15|0x010a
//***************************************************************************             //06-08-09|0x010b
//******                                                               ******             //06-08-09|0x010c
//****** Process Drive-Path command                                    ******             //07-01-31|0x010d
//******                                                               ******             //06-08-09|0x010e
//***************************************************************************             //06-08-09|0x010f
      case 33688: // FIRST_READ                                                           //08-12-31|0x0110
        switch(read_project())                                                            //08-12-31|0x0110
        {                                                                                 //08-12-31|0x0110
          case Display:                                                                   //08-12-31|0x0110
            DevelopState = 4197; // FIRST_READ_EXIT                                       //08-12-31|0x0110
            DevelopStatus = Display;                                                      //08-12-31|0x0110
            DevelopRunFlag = 0;                                                           //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          case LineDone:                                                                  //08-12-31|0x0110
            DevelopRunFlag = 1;                                                           //08-12-31|0x0110
            DevelopState = 5940; // DRIVE_PATH_PAUSE                                      //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          case FileDone:                                                                  //08-12-31|0x0110
            DevelopRunFlag = 1;                                                           //08-12-31|0x0110
            DevelopState = 41569; // END_FILE                                             //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          case UserError:                                                                 //08-12-31|0x0110
            DevelopRunFlag = 1;                                                           //08-12-31|0x0110
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          default:                                                                        //08-12-31|0x0110
            DevelopStatus = SystemError;                                                  //08-12-31|0x0110
            DevelopRunFlag = 0;                                                           //08-12-31|0x0110
            SystemMsg;                                                                    //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
        }                                                                                 //08-12-31|0x0110
        break;                                                                            //08-12-31|0x0110
//**************************************************************************              //08-12-31|0x0110
      case 4197: // FIRST_READ_EXIT                                                       //08-12-31|0x0110
        switch(read_project())                                                            //08-12-31|0x0110
        {                                                                                 //08-12-31|0x0110
          case Display:                                                                   //08-12-31|0x0110
            DevelopState = 4197; // FIRST_READ_EXIT                                       //08-12-31|0x0110
            DevelopStatus = Display;                                                      //08-12-31|0x0110
            DevelopRunFlag = 0;                                                           //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          case LineDone:                                                                  //08-12-31|0x0110
            DevelopRunFlag = 1;                                                           //08-12-31|0x0110
            DevelopState = 5940; // DRIVE_PATH_PAUSE                                      //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          case FileDone:                                                                  //08-12-31|0x0110
            DevelopRunFlag = 1;                                                           //08-12-31|0x0110
            DevelopState = 41569; // END_FILE                                             //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          case UserError:                                                                 //08-12-31|0x0110
            DevelopRunFlag = 1;                                                           //08-12-31|0x0110
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
          default:                                                                        //08-12-31|0x0110
            DevelopStatus = SystemError;                                                  //08-12-31|0x0110
            DevelopRunFlag = 0;                                                           //08-12-31|0x0110
            SystemMsg;                                                                    //08-12-31|0x0110
            break;                                                                        //08-12-31|0x0110
        }                                                                                 //08-12-31|0x0110
        break;                                                                            //08-12-31|0x0110
//---------------------------------------------------------------------------             //08-12-31|0x0111
      case 5940: // DRIVE_PATH_PAUSE                                                      //08-12-31|0x0112
        switch(DebugPause)                                                                //08-12-31|0x0112
        {                                                                                 //08-12-31|0x0112
          case Display:                                                                   //08-12-31|0x0112
            DevelopState = 35571; // DRIVE_PATH_PAUSE_EXIT                                //08-12-31|0x0112
            DevelopStatus = Display;                                                      //08-12-31|0x0112
            DevelopRunFlag = 0;                                                           //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case KeyBoard:                                                                  //08-12-31|0x0112
            DevelopState = 35571; // DRIVE_PATH_PAUSE_EXIT                                //08-12-31|0x0112
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0112
            DevelopRunFlag = 0;                                                           //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case Continue:                                                                  //08-12-31|0x0112
            DevelopRunFlag = 1;                                                           //08-12-31|0x0112
            DevelopState = 5940; // DRIVE_PATH_PAUSE                                      //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case Success:                                                                   //08-12-31|0x0112
            DevelopRunFlag = 1;                                                           //08-12-31|0x0112
            DevelopState = 48535; // CMD_DRIVE_PATH                                       //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case UserError:                                                                 //08-12-31|0x0112
            DevelopRunFlag = 1;                                                           //08-12-31|0x0112
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          default:                                                                        //08-12-31|0x0112
            DevelopStatus = SystemError;                                                  //08-12-31|0x0112
            DevelopRunFlag = 0;                                                           //08-12-31|0x0112
            SystemMsg;                                                                    //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
        }                                                                                 //08-12-31|0x0112
        break;                                                                            //08-12-31|0x0112
//**************************************************************************              //08-12-31|0x0112
      case 35571: // DRIVE_PATH_PAUSE_EXIT                                                //08-12-31|0x0112
        switch(DebugPause)                                                                //08-12-31|0x0112
        {                                                                                 //08-12-31|0x0112
          case Display:                                                                   //08-12-31|0x0112
            DevelopState = 35571; // DRIVE_PATH_PAUSE_EXIT                                //08-12-31|0x0112
            DevelopStatus = Display;                                                      //08-12-31|0x0112
            DevelopRunFlag = 0;                                                           //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case KeyBoard:                                                                  //08-12-31|0x0112
            DevelopState = 35571; // DRIVE_PATH_PAUSE_EXIT                                //08-12-31|0x0112
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0112
            DevelopRunFlag = 0;                                                           //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case Continue:                                                                  //08-12-31|0x0112
            DevelopRunFlag = 1;                                                           //08-12-31|0x0112
            DevelopState = 5940; // DRIVE_PATH_PAUSE                                      //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case Success:                                                                   //08-12-31|0x0112
            DevelopRunFlag = 1;                                                           //08-12-31|0x0112
            DevelopState = 48535; // CMD_DRIVE_PATH                                       //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          case UserError:                                                                 //08-12-31|0x0112
            DevelopRunFlag = 1;                                                           //08-12-31|0x0112
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
          default:                                                                        //08-12-31|0x0112
            DevelopStatus = SystemError;                                                  //08-12-31|0x0112
            DevelopRunFlag = 0;                                                           //08-12-31|0x0112
            SystemMsg;                                                                    //08-12-31|0x0112
            break;                                                                        //08-12-31|0x0112
        }                                                                                 //08-12-31|0x0112
        break;                                                                            //08-12-31|0x0112
//---------------------------------------------------------------------------             //08-12-31|0x0113
      case 48535: // CMD_DRIVE_PATH                                                       //07-01-31|0x0114
        switch(CmdTest("_DRIVE_PATH"))                                                    //07-01-31|0x0114
        {                                                                                 //07-01-31|0x0114
          case -1:                                                                        //07-01-31|0x0114
            DevelopRunFlag = 1;                                                           //07-01-31|0x0114
            DevelopState = 15010; // CMD_DEV                                              //07-01-31|0x0114
            break;                                                                        //07-01-31|0x0114
          case 0:                                                                         //07-01-31|0x0114
            DevelopRunFlag = 1;                                                           //07-01-31|0x0114
            DevelopState = 58689; // RUN_DRIVE_PATH                                       //07-01-31|0x0114
            break;                                                                        //07-01-31|0x0114
          case 1:                                                                         //07-01-31|0x0114
            DevelopRunFlag = 1;                                                           //07-01-31|0x0114
            DevelopState = 15010; // CMD_DEV                                              //07-01-31|0x0114
            break;                                                                        //07-01-31|0x0114
          default:                                                                        //07-01-31|0x0114
            DevelopStatus = SystemError;                                                  //07-01-31|0x0114
            DevelopRunFlag = 0;                                                           //07-01-31|0x0114
            SystemMsg;                                                                    //07-01-31|0x0114
            break;                                                                        //07-01-31|0x0114
        }                                                                                 //07-01-31|0x0114
        break;                                                                            //07-01-31|0x0114
//---------------------------------------------------------------------------             //06-08-09|0x0115
      case 58689: // RUN_DRIVE_PATH                                                       //07-01-31|0x0116
        switch(drive_path())                                                              //07-01-31|0x0116
        {                                                                                 //07-01-31|0x0116
          case Success:                                                                   //07-01-31|0x0116
            DevelopRunFlag = 1;                                                           //07-01-31|0x0116
            DevelopState = 14800; // DRIVE_PATH_READ                                      //07-01-31|0x0116
            break;                                                                        //07-01-31|0x0116
          case UserError:                                                                 //07-01-31|0x0116
            DevelopRunFlag = 1;                                                           //07-01-31|0x0116
            DevelopState = 51440; // CLOSE_USER                                           //07-01-31|0x0116
            break;                                                                        //07-01-31|0x0116
          default:                                                                        //07-01-31|0x0116
            DevelopStatus = SystemError;                                                  //07-01-31|0x0116
            DevelopRunFlag = 0;                                                           //07-01-31|0x0116
            SystemMsg;                                                                    //07-01-31|0x0116
            break;                                                                        //07-01-31|0x0116
        }                                                                                 //07-01-31|0x0116
        break;                                                                            //07-01-31|0x0116
//---------------------------------------------------------------------------             //06-08-09|0x0117
      case 14800: // DRIVE_PATH_READ                                                      //11-12-17|0x0118
        switch(read_project())                                                            //11-12-17|0x0118
        {                                                                                 //11-12-17|0x0118
          case Display:                                                                   //11-12-17|0x0118
            DevelopState = 55119; // DRIVE_PATH_READ_EXIT                                 //11-12-17|0x0118
            DevelopStatus = Display;                                                      //11-12-17|0x0118
            DevelopRunFlag = 0;                                                           //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          case LineDone:                                                                  //11-12-17|0x0118
            DevelopRunFlag = 1;                                                           //11-12-17|0x0118
            DevelopState = 19646; // DEV_PAUSE                                            //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          case FileDone:                                                                  //11-12-17|0x0118
            DevelopRunFlag = 1;                                                           //11-12-17|0x0118
            DevelopState = 41569; // END_FILE                                             //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          case UserError:                                                                 //11-12-17|0x0118
            DevelopRunFlag = 1;                                                           //11-12-17|0x0118
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          default:                                                                        //11-12-17|0x0118
            DevelopStatus = SystemError;                                                  //11-12-17|0x0118
            DevelopRunFlag = 0;                                                           //11-12-17|0x0118
            SystemMsg;                                                                    //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
        }                                                                                 //11-12-17|0x0118
        break;                                                                            //11-12-17|0x0118
//**************************************************************************              //11-12-17|0x0118
      case 55119: // DRIVE_PATH_READ_EXIT                                                 //11-12-17|0x0118
        switch(read_project())                                                            //11-12-17|0x0118
        {                                                                                 //11-12-17|0x0118
          case Display:                                                                   //11-12-17|0x0118
            DevelopState = 55119; // DRIVE_PATH_READ_EXIT                                 //11-12-17|0x0118
            DevelopStatus = Display;                                                      //11-12-17|0x0118
            DevelopRunFlag = 0;                                                           //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          case LineDone:                                                                  //11-12-17|0x0118
            DevelopRunFlag = 1;                                                           //11-12-17|0x0118
            DevelopState = 19646; // DEV_PAUSE                                            //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          case FileDone:                                                                  //11-12-17|0x0118
            DevelopRunFlag = 1;                                                           //11-12-17|0x0118
            DevelopState = 41569; // END_FILE                                             //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          case UserError:                                                                 //11-12-17|0x0118
            DevelopRunFlag = 1;                                                           //11-12-17|0x0118
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
          default:                                                                        //11-12-17|0x0118
            DevelopStatus = SystemError;                                                  //11-12-17|0x0118
            DevelopRunFlag = 0;                                                           //11-12-17|0x0118
            SystemMsg;                                                                    //11-12-17|0x0118
            break;                                                                        //11-12-17|0x0118
        }                                                                                 //11-12-17|0x0118
        break;                                                                            //11-12-17|0x0118
//---------------------------------------------------------------------------             //08-12-31|0x0119
      case 19646: // DEV_PAUSE                                                            //11-12-17|0x011a
        switch(DebugPause)                                                                //11-12-17|0x011a
        {                                                                                 //11-12-17|0x011a
          case Display:                                                                   //11-12-17|0x011a
            DevelopState = 6429; // DEV_PAUSE_EXIT                                        //11-12-17|0x011a
            DevelopStatus = Display;                                                      //11-12-17|0x011a
            DevelopRunFlag = 0;                                                           //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case KeyBoard:                                                                  //11-12-17|0x011a
            DevelopState = 6429; // DEV_PAUSE_EXIT                                        //11-12-17|0x011a
            DevelopStatus = KeyBoard;                                                     //11-12-17|0x011a
            DevelopRunFlag = 0;                                                           //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case Continue:                                                                  //11-12-17|0x011a
            DevelopRunFlag = 1;                                                           //11-12-17|0x011a
            DevelopState = 19646; // DEV_PAUSE                                            //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case Success:                                                                   //11-12-17|0x011a
            DevelopRunFlag = 1;                                                           //11-12-17|0x011a
            DevelopState = 15010; // CMD_DEV                                              //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case UserError:                                                                 //11-12-17|0x011a
            DevelopRunFlag = 1;                                                           //11-12-17|0x011a
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          default:                                                                        //11-12-17|0x011a
            DevelopStatus = SystemError;                                                  //11-12-17|0x011a
            DevelopRunFlag = 0;                                                           //11-12-17|0x011a
            SystemMsg;                                                                    //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
        }                                                                                 //11-12-17|0x011a
        break;                                                                            //11-12-17|0x011a
//**************************************************************************              //11-12-17|0x011a
      case 6429: // DEV_PAUSE_EXIT                                                        //11-12-17|0x011a
        switch(DebugPause)                                                                //11-12-17|0x011a
        {                                                                                 //11-12-17|0x011a
          case Display:                                                                   //11-12-17|0x011a
            DevelopState = 6429; // DEV_PAUSE_EXIT                                        //11-12-17|0x011a
            DevelopStatus = Display;                                                      //11-12-17|0x011a
            DevelopRunFlag = 0;                                                           //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case KeyBoard:                                                                  //11-12-17|0x011a
            DevelopState = 6429; // DEV_PAUSE_EXIT                                        //11-12-17|0x011a
            DevelopStatus = KeyBoard;                                                     //11-12-17|0x011a
            DevelopRunFlag = 0;                                                           //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case Continue:                                                                  //11-12-17|0x011a
            DevelopRunFlag = 1;                                                           //11-12-17|0x011a
            DevelopState = 19646; // DEV_PAUSE                                            //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case Success:                                                                   //11-12-17|0x011a
            DevelopRunFlag = 1;                                                           //11-12-17|0x011a
            DevelopState = 15010; // CMD_DEV                                              //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          case UserError:                                                                 //11-12-17|0x011a
            DevelopRunFlag = 1;                                                           //11-12-17|0x011a
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
          default:                                                                        //11-12-17|0x011a
            DevelopStatus = SystemError;                                                  //11-12-17|0x011a
            DevelopRunFlag = 0;                                                           //11-12-17|0x011a
            SystemMsg;                                                                    //11-12-17|0x011a
            break;                                                                        //11-12-17|0x011a
        }                                                                                 //11-12-17|0x011a
        break;                                                                            //11-12-17|0x011a
//***************************************************************************             //11-12-12|0x011b
//******                                                               ******             //11-12-12|0x011c
//****** Process Development project command                           ******             //11-12-12|0x011d
//******                                                               ******             //11-12-12|0x011e
//***************************************************************************             //11-12-12|0x011f
      case 15010: // CMD_DEV                                                              //11-12-12|0x0120
        switch(CmdTest("_DEVELOP_PROJECT"))                                               //11-12-12|0x0120
        {                                                                                 //11-12-12|0x0120
          case -1:                                                                        //11-12-12|0x0120
            DevelopRunFlag = 1;                                                           //11-12-12|0x0120
            DevelopState = 43884; // CMD_MACRO                                            //11-12-12|0x0120
            break;                                                                        //11-12-12|0x0120
          case 0:                                                                         //11-12-12|0x0120
            DevelopRunFlag = 1;                                                           //11-12-12|0x0120
            DevelopState = 25259; // GET_DEVELOP_NAME                                     //11-12-12|0x0120
            break;                                                                        //11-12-12|0x0120
          case 1:                                                                         //11-12-12|0x0120
            DevelopRunFlag = 1;                                                           //11-12-12|0x0120
            DevelopState = 43884; // CMD_MACRO                                            //11-12-12|0x0120
            break;                                                                        //11-12-12|0x0120
          default:                                                                        //11-12-12|0x0120
            DevelopStatus = SystemError;                                                  //11-12-12|0x0120
            DevelopRunFlag = 0;                                                           //11-12-12|0x0120
            SystemMsg;                                                                    //11-12-12|0x0120
            break;                                                                        //11-12-12|0x0120
        }                                                                                 //11-12-12|0x0120
        break;                                                                            //11-12-12|0x0120
//---------------------------------------------------------------------------             //11-12-12|0x0121
      case 25259: // GET_DEVELOP_NAME                                                     //11-12-17|0x0122
        switch(get_file_name())                                                           //11-12-17|0x0122
        {                                                                                 //11-12-17|0x0122
          case Success:                                                                   //11-12-17|0x0122
            DevelopRunFlag = 1;                                                           //11-12-17|0x0122
            DevelopState = 36314; // DEV_INCR_PROJ_NO                                     //11-12-17|0x0122
            break;                                                                        //11-12-17|0x0122
          case UserError:                                                                 //11-12-17|0x0122
            DevelopRunFlag = 1;                                                           //11-12-17|0x0122
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0122
            break;                                                                        //11-12-17|0x0122
          default:                                                                        //11-12-17|0x0122
            DevelopStatus = SystemError;                                                  //11-12-17|0x0122
            DevelopRunFlag = 0;                                                           //11-12-17|0x0122
            SystemMsg;                                                                    //11-12-17|0x0122
            break;                                                                        //11-12-17|0x0122
        }                                                                                 //11-12-17|0x0122
        break;                                                                            //11-12-17|0x0122
//---------------------------------------------------------------------------             //11-12-17|0x0123
      case 36314: // DEV_INCR_PROJ_NO                                                     //11-12-17|0x0124
        switch(IncrDevPrjNo)                                                              //11-12-17|0x0124
        {                                                                                 //11-12-17|0x0124
          case Success:                                                                   //11-12-17|0x0124
            DevelopRunFlag = 1;                                                           //11-12-17|0x0124
            DevelopState = 27641; // DEVELOP_PUSH                                         //11-12-17|0x0124
            break;                                                                        //11-12-17|0x0124
          case UserError:                                                                 //11-12-17|0x0124
            DevelopRunFlag = 1;                                                           //11-12-17|0x0124
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0124
            break;                                                                        //11-12-17|0x0124
          default:                                                                        //11-12-17|0x0124
            DevelopStatus = SystemError;                                                  //11-12-17|0x0124
            DevelopRunFlag = 0;                                                           //11-12-17|0x0124
            SystemMsg;                                                                    //11-12-17|0x0124
            break;                                                                        //11-12-17|0x0124
        }                                                                                 //11-12-17|0x0124
        break;                                                                            //11-12-17|0x0124
//---------------------------------------------------------------------------             //11-12-17|0x0125
      case 27641: // DEVELOP_PUSH                                                         //11-12-17|0x0126
        switch(develop_push())                                                            //11-12-17|0x0126
        {                                                                                 //11-12-17|0x0126
          case Success:                                                                   //11-12-17|0x0126
            DevelopRunFlag = 1;                                                           //11-12-17|0x0126
            DevelopState = 34729; // ENTER_PROJECT_NAME                                   //11-12-17|0x0126
            break;                                                                        //11-12-17|0x0126
          default:                                                                        //11-12-17|0x0126
            DevelopStatus = SystemError;                                                  //11-12-17|0x0126
            DevelopRunFlag = 0;                                                           //11-12-17|0x0126
            SystemMsg;                                                                    //11-12-17|0x0126
            break;                                                                        //11-12-17|0x0126
        }                                                                                 //11-12-17|0x0126
        break;                                                                            //11-12-17|0x0126
//***************************************************************************             //07-01-31|0x0127
//******                                                               ******             //07-01-31|0x0128
//****** Process Library project command                               ******             //07-01-31|0x0129
//******                                                               ******             //07-01-31|0x012a
//***************************************************************************             //07-01-31|0x012b
      case 43884: // CMD_MACRO                                                            //11-12-12|0x012c
        switch(CmdTest("_LIBRARY_PROJECT"))                                               //11-12-12|0x012c
        {                                                                                 //11-12-12|0x012c
          case -1:                                                                        //11-12-12|0x012c
            DevelopRunFlag = 1;                                                           //11-12-12|0x012c
            DevelopState = 11272; // CMD_SOURCE                                           //11-12-12|0x012c
            break;                                                                        //11-12-12|0x012c
          case 0:                                                                         //11-12-12|0x012c
            DevelopRunFlag = 1;                                                           //11-12-12|0x012c
            DevelopState = 60679; // GET_MACRO_NAME                                       //11-12-12|0x012c
            break;                                                                        //11-12-12|0x012c
          case 1:                                                                         //11-12-12|0x012c
            DevelopRunFlag = 1;                                                           //11-12-12|0x012c
            DevelopState = 11272; // CMD_SOURCE                                           //11-12-12|0x012c
            break;                                                                        //11-12-12|0x012c
          default:                                                                        //11-12-12|0x012c
            DevelopStatus = SystemError;                                                  //11-12-12|0x012c
            DevelopRunFlag = 0;                                                           //11-12-12|0x012c
            SystemMsg;                                                                    //11-12-12|0x012c
            break;                                                                        //11-12-12|0x012c
        }                                                                                 //11-12-12|0x012c
        break;                                                                            //11-12-12|0x012c
//---------------------------------------------------------------------------             //11-12-12|0x012d
      case 60679: // GET_MACRO_NAME                                                       //11-12-12|0x012e
        switch(get_file_name())                                                           //11-12-12|0x012e
        {                                                                                 //11-12-12|0x012e
          case Success:                                                                   //11-12-12|0x012e
            DevelopRunFlag = 1;                                                           //11-12-12|0x012e
            DevelopState = 48630; // MAC_INCR_PROJ_NO                                     //11-12-12|0x012e
            break;                                                                        //11-12-12|0x012e
          case UserError:                                                                 //11-12-12|0x012e
            DevelopRunFlag = 1;                                                           //11-12-12|0x012e
            DevelopState = 51440; // CLOSE_USER                                           //11-12-12|0x012e
            break;                                                                        //11-12-12|0x012e
          default:                                                                        //11-12-12|0x012e
            DevelopStatus = SystemError;                                                  //11-12-12|0x012e
            DevelopRunFlag = 0;                                                           //11-12-12|0x012e
            SystemMsg;                                                                    //11-12-12|0x012e
            break;                                                                        //11-12-12|0x012e
        }                                                                                 //11-12-12|0x012e
        break;                                                                            //11-12-12|0x012e
//---------------------------------------------------------------------------             //11-12-12|0x012f
      case 48630: // MAC_INCR_PROJ_NO                                                     //11-12-12|0x0130
        switch(IncrDevPrjNo)                                                              //11-12-12|0x0130
        {                                                                                 //11-12-12|0x0130
          case Success:                                                                   //11-12-12|0x0130
            DevelopRunFlag = 1;                                                           //11-12-12|0x0130
            DevelopState = 40405; // MACRO_PUSH                                           //11-12-12|0x0130
            break;                                                                        //11-12-12|0x0130
          case UserError:                                                                 //11-12-12|0x0130
            DevelopRunFlag = 1;                                                           //11-12-12|0x0130
            DevelopState = 51440; // CLOSE_USER                                           //11-12-12|0x0130
            break;                                                                        //11-12-12|0x0130
          default:                                                                        //11-12-12|0x0130
            DevelopStatus = SystemError;                                                  //11-12-12|0x0130
            DevelopRunFlag = 0;                                                           //11-12-12|0x0130
            SystemMsg;                                                                    //11-12-12|0x0130
            break;                                                                        //11-12-12|0x0130
        }                                                                                 //11-12-12|0x0130
        break;                                                                            //11-12-12|0x0130
//---------------------------------------------------------------------------             //11-12-12|0x0131
      case 40405: // MACRO_PUSH                                                           //11-12-12|0x0132
        switch(develop_push())                                                            //11-12-12|0x0132
        {                                                                                 //11-12-12|0x0132
          case Success:                                                                   //11-12-12|0x0132
            DevelopRunFlag = 1;                                                           //11-12-12|0x0132
            DevelopState = 31652; // RUN_MACRO                                            //11-12-12|0x0132
            break;                                                                        //11-12-12|0x0132
          default:                                                                        //11-12-12|0x0132
            DevelopStatus = SystemError;                                                  //11-12-12|0x0132
            DevelopRunFlag = 0;                                                           //11-12-12|0x0132
            SystemMsg;                                                                    //11-12-12|0x0132
            break;                                                                        //11-12-12|0x0132
        }                                                                                 //11-12-12|0x0132
        break;                                                                            //11-12-12|0x0132
//---------------------------------------------------------------------------             //11-12-12|0x0133
      case 31652: // RUN_MACRO                                                            //11-12-17|0x0134
        switch(DevelopLib)                                                                //11-12-17|0x0134
        {                                                                                 //11-12-17|0x0134
          case Display:                                                                   //11-12-17|0x0134
            DevelopState = 13923; // RUN_MACRO_EXIT                                       //11-12-17|0x0134
            DevelopStatus = Display;                                                      //11-12-17|0x0134
            DevelopRunFlag = 0;                                                           //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
          case Success:                                                                   //11-12-17|0x0134
            DevelopRunFlag = 1;                                                           //11-12-17|0x0134
            DevelopState = 40210; // MAC_DECR_PROJ_NO                                     //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
          case UserError:                                                                 //11-12-17|0x0134
            DevelopRunFlag = 1;                                                           //11-12-17|0x0134
            DevelopState = 11959; // NEED_POP_USER                                        //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
          default:                                                                        //11-12-17|0x0134
            DevelopStatus = SystemError;                                                  //11-12-17|0x0134
            DevelopRunFlag = 0;                                                           //11-12-17|0x0134
            SystemMsg;                                                                    //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
        }                                                                                 //11-12-17|0x0134
        break;                                                                            //11-12-17|0x0134
//**************************************************************************              //11-12-17|0x0134
      case 13923: // RUN_MACRO_EXIT                                                       //11-12-17|0x0134
        switch(DevelopLib)                                                                //11-12-17|0x0134
        {                                                                                 //11-12-17|0x0134
          case Display:                                                                   //11-12-17|0x0134
            DevelopState = 13923; // RUN_MACRO_EXIT                                       //11-12-17|0x0134
            DevelopStatus = Display;                                                      //11-12-17|0x0134
            DevelopRunFlag = 0;                                                           //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
          case Success:                                                                   //11-12-17|0x0134
            DevelopRunFlag = 1;                                                           //11-12-17|0x0134
            DevelopState = 40210; // MAC_DECR_PROJ_NO                                     //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
          case UserError:                                                                 //11-12-17|0x0134
            DevelopRunFlag = 1;                                                           //11-12-17|0x0134
            DevelopState = 11959; // NEED_POP_USER                                        //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
          default:                                                                        //11-12-17|0x0134
            DevelopStatus = SystemError;                                                  //11-12-17|0x0134
            DevelopRunFlag = 0;                                                           //11-12-17|0x0134
            SystemMsg;                                                                    //11-12-17|0x0134
            break;                                                                        //11-12-17|0x0134
        }                                                                                 //11-12-17|0x0134
        break;                                                                            //11-12-17|0x0134
//---------------------------------------------------------------------------             //11-12-12|0x0135
      case 40210: // MAC_DECR_PROJ_NO                                                     //11-12-12|0x0136
        switch(DecrDevPrjNo)                                                              //11-12-12|0x0136
        {                                                                                 //11-12-12|0x0136
          case Yes:                                                                       //11-12-12|0x0136
            DevelopRunFlag = 1;                                                           //11-12-12|0x0136
            DevelopState = 28337; // POP_MACRO                                            //11-12-12|0x0136
            break;                                                                        //11-12-12|0x0136
          default:                                                                        //11-12-12|0x0136
            DevelopStatus = SystemError;                                                  //11-12-12|0x0136
            DevelopRunFlag = 0;                                                           //11-12-12|0x0136
            SystemMsg;                                                                    //11-12-12|0x0136
            break;                                                                        //11-12-12|0x0136
        }                                                                                 //11-12-12|0x0136
        break;                                                                            //11-12-12|0x0136
//---------------------------------------------------------------------------             //11-12-12|0x0137
      case 28337: // POP_MACRO                                                            //11-12-12|0x0138
        switch(develop_pop())                                                             //11-12-12|0x0138
        {                                                                                 //11-12-12|0x0138
          case Success:                                                                   //11-12-12|0x0138
            DevelopRunFlag = 1;                                                           //11-12-12|0x0138
            DevelopState = 23104; // MAC_READ                                             //11-12-12|0x0138
            break;                                                                        //11-12-12|0x0138
          default:                                                                        //11-12-12|0x0138
            DevelopStatus = SystemError;                                                  //11-12-12|0x0138
            DevelopRunFlag = 0;                                                           //11-12-12|0x0138
            SystemMsg;                                                                    //11-12-12|0x0138
            break;                                                                        //11-12-12|0x0138
        }                                                                                 //11-12-12|0x0138
        break;                                                                            //11-12-12|0x0138
//---------------------------------------------------------------------------             //08-12-31|0x0139
      case 23104: // MAC_READ                                                             //08-12-31|0x013a
        switch(read_project())                                                            //08-12-31|0x013a
        {                                                                                 //08-12-31|0x013a
          case Display:                                                                   //08-12-31|0x013a
            DevelopState = 65215; // MAC_READ_EXIT                                        //08-12-31|0x013a
            DevelopStatus = Display;                                                      //08-12-31|0x013a
            DevelopRunFlag = 0;                                                           //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          case LineDone:                                                                  //08-12-31|0x013a
            DevelopRunFlag = 1;                                                           //08-12-31|0x013a
            DevelopState = 60206; // MAC_PAUSE                                            //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          case FileDone:                                                                  //08-12-31|0x013a
            DevelopRunFlag = 1;                                                           //08-12-31|0x013a
            DevelopState = 40589; // CLOSE_OK                                             //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          case UserError:                                                                 //08-12-31|0x013a
            DevelopRunFlag = 1;                                                           //08-12-31|0x013a
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          default:                                                                        //08-12-31|0x013a
            DevelopStatus = SystemError;                                                  //08-12-31|0x013a
            DevelopRunFlag = 0;                                                           //08-12-31|0x013a
            SystemMsg;                                                                    //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
        }                                                                                 //08-12-31|0x013a
        break;                                                                            //08-12-31|0x013a
//**************************************************************************              //08-12-31|0x013a
      case 65215: // MAC_READ_EXIT                                                        //08-12-31|0x013a
        switch(read_project())                                                            //08-12-31|0x013a
        {                                                                                 //08-12-31|0x013a
          case Display:                                                                   //08-12-31|0x013a
            DevelopState = 65215; // MAC_READ_EXIT                                        //08-12-31|0x013a
            DevelopStatus = Display;                                                      //08-12-31|0x013a
            DevelopRunFlag = 0;                                                           //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          case LineDone:                                                                  //08-12-31|0x013a
            DevelopRunFlag = 1;                                                           //08-12-31|0x013a
            DevelopState = 60206; // MAC_PAUSE                                            //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          case FileDone:                                                                  //08-12-31|0x013a
            DevelopRunFlag = 1;                                                           //08-12-31|0x013a
            DevelopState = 40589; // CLOSE_OK                                             //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          case UserError:                                                                 //08-12-31|0x013a
            DevelopRunFlag = 1;                                                           //08-12-31|0x013a
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
          default:                                                                        //08-12-31|0x013a
            DevelopStatus = SystemError;                                                  //08-12-31|0x013a
            DevelopRunFlag = 0;                                                           //08-12-31|0x013a
            SystemMsg;                                                                    //08-12-31|0x013a
            break;                                                                        //08-12-31|0x013a
        }                                                                                 //08-12-31|0x013a
        break;                                                                            //08-12-31|0x013a
//---------------------------------------------------------------------------             //08-12-31|0x013b
      case 60206: // MAC_PAUSE                                                            //08-12-31|0x013c
        switch(DebugPause)                                                                //08-12-31|0x013c
        {                                                                                 //08-12-31|0x013c
          case Display:                                                                   //08-12-31|0x013c
            DevelopState = 34780; // MAC_PAUSE_EXIT                                       //08-12-31|0x013c
            DevelopStatus = Display;                                                      //08-12-31|0x013c
            DevelopRunFlag = 0;                                                           //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case KeyBoard:                                                                  //08-12-31|0x013c
            DevelopState = 34780; // MAC_PAUSE_EXIT                                       //08-12-31|0x013c
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x013c
            DevelopRunFlag = 0;                                                           //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case Continue:                                                                  //08-12-31|0x013c
            DevelopRunFlag = 1;                                                           //08-12-31|0x013c
            DevelopState = 60206; // MAC_PAUSE                                            //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case Success:                                                                   //08-12-31|0x013c
            DevelopRunFlag = 1;                                                           //08-12-31|0x013c
            DevelopState = 19409; // DEBUG_CMD                                            //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case UserError:                                                                 //08-12-31|0x013c
            DevelopRunFlag = 1;                                                           //08-12-31|0x013c
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          default:                                                                        //08-12-31|0x013c
            DevelopStatus = SystemError;                                                  //08-12-31|0x013c
            DevelopRunFlag = 0;                                                           //08-12-31|0x013c
            SystemMsg;                                                                    //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
        }                                                                                 //08-12-31|0x013c
        break;                                                                            //08-12-31|0x013c
//**************************************************************************              //08-12-31|0x013c
      case 34780: // MAC_PAUSE_EXIT                                                       //08-12-31|0x013c
        switch(DebugPause)                                                                //08-12-31|0x013c
        {                                                                                 //08-12-31|0x013c
          case Display:                                                                   //08-12-31|0x013c
            DevelopState = 34780; // MAC_PAUSE_EXIT                                       //08-12-31|0x013c
            DevelopStatus = Display;                                                      //08-12-31|0x013c
            DevelopRunFlag = 0;                                                           //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case KeyBoard:                                                                  //08-12-31|0x013c
            DevelopState = 34780; // MAC_PAUSE_EXIT                                       //08-12-31|0x013c
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x013c
            DevelopRunFlag = 0;                                                           //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case Continue:                                                                  //08-12-31|0x013c
            DevelopRunFlag = 1;                                                           //08-12-31|0x013c
            DevelopState = 60206; // MAC_PAUSE                                            //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case Success:                                                                   //08-12-31|0x013c
            DevelopRunFlag = 1;                                                           //08-12-31|0x013c
            DevelopState = 19409; // DEBUG_CMD                                            //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          case UserError:                                                                 //08-12-31|0x013c
            DevelopRunFlag = 1;                                                           //08-12-31|0x013c
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
          default:                                                                        //08-12-31|0x013c
            DevelopStatus = SystemError;                                                  //08-12-31|0x013c
            DevelopRunFlag = 0;                                                           //08-12-31|0x013c
            SystemMsg;                                                                    //08-12-31|0x013c
            break;                                                                        //08-12-31|0x013c
        }                                                                                 //08-12-31|0x013c
        break;                                                                            //08-12-31|0x013c
//***************************************************************************             //06-08-09|0x013d
//******                                                               ******             //06-08-09|0x013e
//****** Process Source Project command                                ******             //06-08-09|0x013f
//******                                                               ******             //06-08-09|0x0140
//***************************************************************************             //06-08-09|0x0141
      case 11272: // CMD_SOURCE                                                           //11-12-17|0x0142
        switch(CmdTest("_SOURCE_PROJECT"))                                                //11-12-17|0x0142
        {                                                                                 //11-12-17|0x0142
          case -1:                                                                        //11-12-17|0x0142
            DevelopRunFlag = 1;                                                           //11-12-17|0x0142
            DevelopState = 1563; // CMD_MAKE                                              //11-12-17|0x0142
            break;                                                                        //11-12-17|0x0142
          case 0:                                                                         //11-12-17|0x0142
            DevelopRunFlag = 1;                                                           //11-12-17|0x0142
            DevelopState = 26698; // GET_SOURCE_NAME                                      //11-12-17|0x0142
            break;                                                                        //11-12-17|0x0142
          case 1:                                                                         //11-12-17|0x0142
            DevelopRunFlag = 1;                                                           //11-12-17|0x0142
            DevelopState = 1563; // CMD_MAKE                                              //11-12-17|0x0142
            break;                                                                        //11-12-17|0x0142
          default:                                                                        //11-12-17|0x0142
            DevelopStatus = SystemError;                                                  //11-12-17|0x0142
            DevelopRunFlag = 0;                                                           //11-12-17|0x0142
            SystemMsg;                                                                    //11-12-17|0x0142
            break;                                                                        //11-12-17|0x0142
        }                                                                                 //11-12-17|0x0142
        break;                                                                            //11-12-17|0x0142
//---------------------------------------------------------------------------             //06-11-14|0x0143
      case 26698: // GET_SOURCE_NAME                                                      //11-12-17|0x0144
        switch(get_file_name())                                                           //11-12-17|0x0144
        {                                                                                 //11-12-17|0x0144
          case Success:                                                                   //11-12-17|0x0144
            DevelopRunFlag = 1;                                                           //11-12-17|0x0144
            DevelopState = 60777; // SRC_INCR_PROJ_NO                                     //11-12-17|0x0144
            break;                                                                        //11-12-17|0x0144
          case UserError:                                                                 //11-12-17|0x0144
            DevelopRunFlag = 1;                                                           //11-12-17|0x0144
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0144
            break;                                                                        //11-12-17|0x0144
          default:                                                                        //11-12-17|0x0144
            DevelopStatus = SystemError;                                                  //11-12-17|0x0144
            DevelopRunFlag = 0;                                                           //11-12-17|0x0144
            SystemMsg;                                                                    //11-12-17|0x0144
            break;                                                                        //11-12-17|0x0144
        }                                                                                 //11-12-17|0x0144
        break;                                                                            //11-12-17|0x0144
//---------------------------------------------------------------------------             //11-12-17|0x0145
      case 60777: // SRC_INCR_PROJ_NO                                                     //11-12-17|0x0146
        switch(IncrDevPrjNo)                                                              //11-12-17|0x0146
        {                                                                                 //11-12-17|0x0146
          case Success:                                                                   //11-12-17|0x0146
            DevelopRunFlag = 1;                                                           //11-12-17|0x0146
            DevelopState = 50296; // SOURCE_PUSH                                          //11-12-17|0x0146
            break;                                                                        //11-12-17|0x0146
          case UserError:                                                                 //11-12-17|0x0146
            DevelopRunFlag = 1;                                                           //11-12-17|0x0146
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0146
            break;                                                                        //11-12-17|0x0146
          default:                                                                        //11-12-17|0x0146
            DevelopStatus = SystemError;                                                  //11-12-17|0x0146
            DevelopRunFlag = 0;                                                           //11-12-17|0x0146
            SystemMsg;                                                                    //11-12-17|0x0146
            break;                                                                        //11-12-17|0x0146
        }                                                                                 //11-12-17|0x0146
        break;                                                                            //11-12-17|0x0146
//---------------------------------------------------------------------------             //11-12-17|0x0147
      case 50296: // SOURCE_PUSH                                                          //11-12-17|0x0148
        switch(develop_push())                                                            //11-12-17|0x0148
        {                                                                                 //11-12-17|0x0148
          case Success:                                                                   //11-12-17|0x0148
            DevelopRunFlag = 1;                                                           //11-12-17|0x0148
            DevelopState = 3191; // SOURCE_ARGS                                           //11-12-17|0x0148
            break;                                                                        //11-12-17|0x0148
          default:                                                                        //11-12-17|0x0148
            DevelopStatus = SystemError;                                                  //11-12-17|0x0148
            DevelopRunFlag = 0;                                                           //11-12-17|0x0148
            SystemMsg;                                                                    //11-12-17|0x0148
            break;                                                                        //11-12-17|0x0148
        }                                                                                 //11-12-17|0x0148
        break;                                                                            //11-12-17|0x0148
//---------------------------------------------------------------------------             //06-11-14|0x0149
      case 3191: // SOURCE_ARGS                                                           //06-11-14|0x014a
        switch(SourceArgs)                                                                //06-11-14|0x014a
        {                                                                                 //06-11-14|0x014a
          case Success:                                                                   //06-11-14|0x014a
            DevelopRunFlag = 1;                                                           //06-11-14|0x014a
            DevelopState = 54374; // RUN_SOURCE                                           //06-11-14|0x014a
            break;                                                                        //06-11-14|0x014a
          default:                                                                        //06-11-14|0x014a
            DevelopStatus = SystemError;                                                  //06-11-14|0x014a
            DevelopRunFlag = 0;                                                           //06-11-14|0x014a
            SystemMsg;                                                                    //06-11-14|0x014a
            break;                                                                        //06-11-14|0x014a
        }                                                                                 //06-11-14|0x014a
        break;                                                                            //06-11-14|0x014a
//---------------------------------------------------------------------------             //06-11-14|0x014b
      case 54374: // RUN_SOURCE                                                           //11-12-17|0x014c
        switch(DevelopSrce)                                                               //11-12-17|0x014c
        {                                                                                 //11-12-17|0x014c
          case KeyBoard:                                                                  //11-12-17|0x014c
            DevelopState = 6981; // RUN_SOURCE_EXIT                                       //11-12-17|0x014c
            DevelopStatus = KeyBoard;                                                     //11-12-17|0x014c
            DevelopRunFlag = 0;                                                           //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case Display:                                                                   //11-12-17|0x014c
            DevelopState = 6981; // RUN_SOURCE_EXIT                                       //11-12-17|0x014c
            DevelopStatus = Display;                                                      //11-12-17|0x014c
            DevelopRunFlag = 0;                                                           //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case Success:                                                                   //11-12-17|0x014c
            DevelopRunFlag = 1;                                                           //11-12-17|0x014c
            DevelopState = 53268; // SRC_POP_OK                                           //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case BuildError:                                                                //11-12-17|0x014c
            DevelopRunFlag = 1;                                                           //11-12-17|0x014c
            DevelopState = 53715; // NEED_POP_BUILD                                       //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case UserError:                                                                 //11-12-17|0x014c
            DevelopRunFlag = 1;                                                           //11-12-17|0x014c
            DevelopState = 11959; // NEED_POP_USER                                        //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          default:                                                                        //11-12-17|0x014c
            DevelopStatus = SystemError;                                                  //11-12-17|0x014c
            DevelopRunFlag = 0;                                                           //11-12-17|0x014c
            SystemMsg;                                                                    //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
        }                                                                                 //11-12-17|0x014c
        break;                                                                            //11-12-17|0x014c
//**************************************************************************              //11-12-17|0x014c
      case 6981: // RUN_SOURCE_EXIT                                                       //11-12-17|0x014c
        switch(DevelopSrce)                                                               //11-12-17|0x014c
        {                                                                                 //11-12-17|0x014c
          case KeyBoard:                                                                  //11-12-17|0x014c
            DevelopState = 6981; // RUN_SOURCE_EXIT                                       //11-12-17|0x014c
            DevelopStatus = KeyBoard;                                                     //11-12-17|0x014c
            DevelopRunFlag = 0;                                                           //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case Display:                                                                   //11-12-17|0x014c
            DevelopState = 6981; // RUN_SOURCE_EXIT                                       //11-12-17|0x014c
            DevelopStatus = Display;                                                      //11-12-17|0x014c
            DevelopRunFlag = 0;                                                           //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case Success:                                                                   //11-12-17|0x014c
            DevelopRunFlag = 1;                                                           //11-12-17|0x014c
            DevelopState = 53268; // SRC_POP_OK                                           //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case BuildError:                                                                //11-12-17|0x014c
            DevelopRunFlag = 1;                                                           //11-12-17|0x014c
            DevelopState = 53715; // NEED_POP_BUILD                                       //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          case UserError:                                                                 //11-12-17|0x014c
            DevelopRunFlag = 1;                                                           //11-12-17|0x014c
            DevelopState = 11959; // NEED_POP_USER                                        //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
          default:                                                                        //11-12-17|0x014c
            DevelopStatus = SystemError;                                                  //11-12-17|0x014c
            DevelopRunFlag = 0;                                                           //11-12-17|0x014c
            SystemMsg;                                                                    //11-12-17|0x014c
            break;                                                                        //11-12-17|0x014c
        }                                                                                 //11-12-17|0x014c
        break;                                                                            //11-12-17|0x014c
//---------------------------------------------------------------------------             //11-12-17|0x014d
      case 53268: // SRC_POP_OK                                                           //11-12-17|0x014e
        switch(DecrDevPrjNo)                                                              //11-12-17|0x014e
        {                                                                                 //11-12-17|0x014e
          case Yes:                                                                       //11-12-17|0x014e
            DevelopRunFlag = 1;                                                           //11-12-17|0x014e
            DevelopState = 61314; // POP_SOURCE                                           //11-12-17|0x014e
            break;                                                                        //11-12-17|0x014e
          default:                                                                        //11-12-17|0x014e
            DevelopStatus = SystemError;                                                  //11-12-17|0x014e
            DevelopRunFlag = 0;                                                           //11-12-17|0x014e
            SystemMsg;                                                                    //11-12-17|0x014e
            break;                                                                        //11-12-17|0x014e
        }                                                                                 //11-12-17|0x014e
        break;                                                                            //11-12-17|0x014e
//---------------------------------------------------------------------------             //11-12-17|0x014f
      case 61314: // POP_SOURCE                                                           //11-12-17|0x0150
        switch(develop_pop())                                                             //11-12-17|0x0150
        {                                                                                 //11-12-17|0x0150
          case Success:                                                                   //11-12-17|0x0150
            DevelopRunFlag = 1;                                                           //11-12-17|0x0150
            DevelopState = 59425; // SOURCE_READ                                          //11-12-17|0x0150
            break;                                                                        //11-12-17|0x0150
          default:                                                                        //11-12-17|0x0150
            DevelopStatus = SystemError;                                                  //11-12-17|0x0150
            DevelopRunFlag = 0;                                                           //11-12-17|0x0150
            SystemMsg;                                                                    //11-12-17|0x0150
            break;                                                                        //11-12-17|0x0150
        }                                                                                 //11-12-17|0x0150
        break;                                                                            //11-12-17|0x0150
//---------------------------------------------------------------------------             //11-12-17|0x0151
      case 59425: // SOURCE_READ                                                          //08-12-31|0x0152
        switch(read_project())                                                            //08-12-31|0x0152
        {                                                                                 //08-12-31|0x0152
          case Display:                                                                   //08-12-31|0x0152
            DevelopState = 27312; // SOURCE_READ_EXIT                                     //08-12-31|0x0152
            DevelopStatus = Display;                                                      //08-12-31|0x0152
            DevelopRunFlag = 0;                                                           //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          case LineDone:                                                                  //08-12-31|0x0152
            DevelopRunFlag = 1;                                                           //08-12-31|0x0152
            DevelopState = 5679; // SOURCE_PAUSE                                          //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          case FileDone:                                                                  //08-12-31|0x0152
            DevelopRunFlag = 1;                                                           //08-12-31|0x0152
            DevelopState = 40589; // CLOSE_OK                                             //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          case UserError:                                                                 //08-12-31|0x0152
            DevelopRunFlag = 1;                                                           //08-12-31|0x0152
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          default:                                                                        //08-12-31|0x0152
            DevelopStatus = SystemError;                                                  //08-12-31|0x0152
            DevelopRunFlag = 0;                                                           //08-12-31|0x0152
            SystemMsg;                                                                    //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
        }                                                                                 //08-12-31|0x0152
        break;                                                                            //08-12-31|0x0152
//**************************************************************************              //08-12-31|0x0152
      case 27312: // SOURCE_READ_EXIT                                                     //08-12-31|0x0152
        switch(read_project())                                                            //08-12-31|0x0152
        {                                                                                 //08-12-31|0x0152
          case Display:                                                                   //08-12-31|0x0152
            DevelopState = 27312; // SOURCE_READ_EXIT                                     //08-12-31|0x0152
            DevelopStatus = Display;                                                      //08-12-31|0x0152
            DevelopRunFlag = 0;                                                           //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          case LineDone:                                                                  //08-12-31|0x0152
            DevelopRunFlag = 1;                                                           //08-12-31|0x0152
            DevelopState = 5679; // SOURCE_PAUSE                                          //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          case FileDone:                                                                  //08-12-31|0x0152
            DevelopRunFlag = 1;                                                           //08-12-31|0x0152
            DevelopState = 40589; // CLOSE_OK                                             //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          case UserError:                                                                 //08-12-31|0x0152
            DevelopRunFlag = 1;                                                           //08-12-31|0x0152
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
          default:                                                                        //08-12-31|0x0152
            DevelopStatus = SystemError;                                                  //08-12-31|0x0152
            DevelopRunFlag = 0;                                                           //08-12-31|0x0152
            SystemMsg;                                                                    //08-12-31|0x0152
            break;                                                                        //08-12-31|0x0152
        }                                                                                 //08-12-31|0x0152
        break;                                                                            //08-12-31|0x0152
//---------------------------------------------------------------------------             //08-12-31|0x0153
      case 5679: // SOURCE_PAUSE                                                          //08-12-31|0x0154
        switch(DebugPause)                                                                //08-12-31|0x0154
        {                                                                                 //08-12-31|0x0154
          case Display:                                                                   //08-12-31|0x0154
            DevelopState = 31134; // SOURCE_PAUSE_EXIT                                    //08-12-31|0x0154
            DevelopStatus = Display;                                                      //08-12-31|0x0154
            DevelopRunFlag = 0;                                                           //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case KeyBoard:                                                                  //08-12-31|0x0154
            DevelopState = 31134; // SOURCE_PAUSE_EXIT                                    //08-12-31|0x0154
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0154
            DevelopRunFlag = 0;                                                           //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case Continue:                                                                  //08-12-31|0x0154
            DevelopRunFlag = 1;                                                           //08-12-31|0x0154
            DevelopState = 5679; // SOURCE_PAUSE                                          //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case Success:                                                                   //08-12-31|0x0154
            DevelopRunFlag = 1;                                                           //08-12-31|0x0154
            DevelopState = 19409; // DEBUG_CMD                                            //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case UserError:                                                                 //08-12-31|0x0154
            DevelopRunFlag = 1;                                                           //08-12-31|0x0154
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          default:                                                                        //08-12-31|0x0154
            DevelopStatus = SystemError;                                                  //08-12-31|0x0154
            DevelopRunFlag = 0;                                                           //08-12-31|0x0154
            SystemMsg;                                                                    //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
        }                                                                                 //08-12-31|0x0154
        break;                                                                            //08-12-31|0x0154
//**************************************************************************              //08-12-31|0x0154
      case 31134: // SOURCE_PAUSE_EXIT                                                    //08-12-31|0x0154
        switch(DebugPause)                                                                //08-12-31|0x0154
        {                                                                                 //08-12-31|0x0154
          case Display:                                                                   //08-12-31|0x0154
            DevelopState = 31134; // SOURCE_PAUSE_EXIT                                    //08-12-31|0x0154
            DevelopStatus = Display;                                                      //08-12-31|0x0154
            DevelopRunFlag = 0;                                                           //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case KeyBoard:                                                                  //08-12-31|0x0154
            DevelopState = 31134; // SOURCE_PAUSE_EXIT                                    //08-12-31|0x0154
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0154
            DevelopRunFlag = 0;                                                           //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case Continue:                                                                  //08-12-31|0x0154
            DevelopRunFlag = 1;                                                           //08-12-31|0x0154
            DevelopState = 5679; // SOURCE_PAUSE                                          //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case Success:                                                                   //08-12-31|0x0154
            DevelopRunFlag = 1;                                                           //08-12-31|0x0154
            DevelopState = 19409; // DEBUG_CMD                                            //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          case UserError:                                                                 //08-12-31|0x0154
            DevelopRunFlag = 1;                                                           //08-12-31|0x0154
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
          default:                                                                        //08-12-31|0x0154
            DevelopStatus = SystemError;                                                  //08-12-31|0x0154
            DevelopRunFlag = 0;                                                           //08-12-31|0x0154
            SystemMsg;                                                                    //08-12-31|0x0154
            break;                                                                        //08-12-31|0x0154
        }                                                                                 //08-12-31|0x0154
        break;                                                                            //08-12-31|0x0154
//***************************************************************************             //08-12-27|0x0155
//******                                                               ******             //08-12-27|0x0156
//****** Process Make command                                          ******             //08-12-27|0x0157
//******                                                               ******             //08-12-27|0x0158
//***************************************************************************             //08-12-27|0x0159
      case 1563: // CMD_MAKE                                                              //08-12-27|0x015a
        switch(CmdTest("_MAKE"))                                                          //08-12-27|0x015a
        {                                                                                 //08-12-27|0x015a
          case -1:                                                                        //08-12-27|0x015a
            DevelopRunFlag = 1;                                                           //08-12-27|0x015a
            DevelopState = 29429; // ILLEGAL_COMMAND                                      //08-12-27|0x015a
            break;                                                                        //08-12-27|0x015a
          case 0:                                                                         //08-12-27|0x015a
            DevelopRunFlag = 1;                                                           //08-12-27|0x015a
            DevelopState = 5117; // MAKE_NAME                                             //08-12-27|0x015a
            break;                                                                        //08-12-27|0x015a
          case 1:                                                                         //08-12-27|0x015a
            DevelopRunFlag = 1;                                                           //08-12-27|0x015a
            DevelopState = 29429; // ILLEGAL_COMMAND                                      //08-12-27|0x015a
            break;                                                                        //08-12-27|0x015a
          default:                                                                        //08-12-27|0x015a
            DevelopStatus = SystemError;                                                  //08-12-27|0x015a
            DevelopRunFlag = 0;                                                           //08-12-27|0x015a
            SystemMsg;                                                                    //08-12-27|0x015a
            break;                                                                        //08-12-27|0x015a
        }                                                                                 //08-12-27|0x015a
        break;                                                                            //08-12-27|0x015a
//---------------------------------------------------------------------------             //08-12-31|0x015b
      case 5117: // MAKE_NAME                                                             //08-12-27|0x015c
        switch(spawn_name())                                                              //08-12-27|0x015c
        {                                                                                 //08-12-27|0x015c
          case Success:                                                                   //08-12-27|0x015c
            DevelopRunFlag = 1;                                                           //08-12-27|0x015c
            DevelopState = 21580; // MAKE_PARMS                                           //08-12-27|0x015c
            break;                                                                        //08-12-27|0x015c
          case UserError:                                                                 //08-12-27|0x015c
            DevelopRunFlag = 1;                                                           //08-12-27|0x015c
            DevelopState = 51440; // CLOSE_USER                                           //08-12-27|0x015c
            break;                                                                        //08-12-27|0x015c
          default:                                                                        //08-12-27|0x015c
            DevelopStatus = SystemError;                                                  //08-12-27|0x015c
            DevelopRunFlag = 0;                                                           //08-12-27|0x015c
            SystemMsg;                                                                    //08-12-27|0x015c
            break;                                                                        //08-12-27|0x015c
        }                                                                                 //08-12-27|0x015c
        break;                                                                            //08-12-27|0x015c
//---------------------------------------------------------------------------             //08-12-27|0x015d
      case 21580: // MAKE_PARMS                                                           //08-12-27|0x015e
        switch(spawn_parms())                                                             //08-12-27|0x015e
        {                                                                                 //08-12-27|0x015e
          case Success:                                                                   //08-12-27|0x015e
            DevelopRunFlag = 1;                                                           //08-12-27|0x015e
            DevelopState = 39307; // MAKE_STEP                                            //08-12-27|0x015e
            break;                                                                        //08-12-27|0x015e
          case UserError:                                                                 //08-12-27|0x015e
            DevelopRunFlag = 1;                                                           //08-12-27|0x015e
            DevelopState = 51440; // CLOSE_USER                                           //08-12-27|0x015e
            break;                                                                        //08-12-27|0x015e
          default:                                                                        //08-12-27|0x015e
            DevelopStatus = SystemError;                                                  //08-12-27|0x015e
            DevelopRunFlag = 0;                                                           //08-12-27|0x015e
            SystemMsg;                                                                    //08-12-27|0x015e
            break;                                                                        //08-12-27|0x015e
        }                                                                                 //08-12-27|0x015e
        break;                                                                            //08-12-27|0x015e
//---------------------------------------------------------------------------             //08-12-27|0x015f
      case 39307: // MAKE_STEP                                                            //08-12-31|0x0160
        switch(make_step())                                                               //08-12-31|0x0160
        {                                                                                 //08-12-31|0x0160
          case Success:                                                                   //08-12-31|0x0160
            DevelopRunFlag = 1;                                                           //08-12-31|0x0160
            DevelopState = 12986; // MAKE_PAUSE                                           //08-12-31|0x0160
            break;                                                                        //08-12-31|0x0160
          case UserError:                                                                 //08-12-31|0x0160
            DevelopRunFlag = 1;                                                           //08-12-31|0x0160
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0160
            break;                                                                        //08-12-31|0x0160
          default:                                                                        //08-12-31|0x0160
            DevelopStatus = SystemError;                                                  //08-12-31|0x0160
            DevelopRunFlag = 0;                                                           //08-12-31|0x0160
            SystemMsg;                                                                    //08-12-31|0x0160
            break;                                                                        //08-12-31|0x0160
        }                                                                                 //08-12-31|0x0160
        break;                                                                            //08-12-31|0x0160
//---------------------------------------------------------------------------             //08-12-31|0x0161
      case 12986: // MAKE_PAUSE                                                           //08-12-31|0x0162
        switch(DebugPause)                                                                //08-12-31|0x0162
        {                                                                                 //08-12-31|0x0162
          case Display:                                                                   //08-12-31|0x0162
            DevelopState = 24281; // MAKE_PAUSE_EXIT                                      //08-12-31|0x0162
            DevelopStatus = Display;                                                      //08-12-31|0x0162
            DevelopRunFlag = 0;                                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case KeyBoard:                                                                  //08-12-31|0x0162
            DevelopState = 24281; // MAKE_PAUSE_EXIT                                      //08-12-31|0x0162
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0162
            DevelopRunFlag = 0;                                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case Continue:                                                                  //08-12-31|0x0162
            DevelopRunFlag = 1;                                                           //08-12-31|0x0162
            DevelopState = 12986; // MAKE_PAUSE                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case Success:                                                                   //08-12-31|0x0162
            DevelopRunFlag = 1;                                                           //08-12-31|0x0162
            DevelopState = 19688; // MAKE_READ                                            //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case UserError:                                                                 //08-12-31|0x0162
            DevelopRunFlag = 1;                                                           //08-12-31|0x0162
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          default:                                                                        //08-12-31|0x0162
            DevelopStatus = SystemError;                                                  //08-12-31|0x0162
            DevelopRunFlag = 0;                                                           //08-12-31|0x0162
            SystemMsg;                                                                    //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
        }                                                                                 //08-12-31|0x0162
        break;                                                                            //08-12-31|0x0162
//**************************************************************************              //08-12-31|0x0162
      case 24281: // MAKE_PAUSE_EXIT                                                      //08-12-31|0x0162
        switch(DebugPause)                                                                //08-12-31|0x0162
        {                                                                                 //08-12-31|0x0162
          case Display:                                                                   //08-12-31|0x0162
            DevelopState = 24281; // MAKE_PAUSE_EXIT                                      //08-12-31|0x0162
            DevelopStatus = Display;                                                      //08-12-31|0x0162
            DevelopRunFlag = 0;                                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case KeyBoard:                                                                  //08-12-31|0x0162
            DevelopState = 24281; // MAKE_PAUSE_EXIT                                      //08-12-31|0x0162
            DevelopStatus = KeyBoard;                                                     //08-12-31|0x0162
            DevelopRunFlag = 0;                                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case Continue:                                                                  //08-12-31|0x0162
            DevelopRunFlag = 1;                                                           //08-12-31|0x0162
            DevelopState = 12986; // MAKE_PAUSE                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case Success:                                                                   //08-12-31|0x0162
            DevelopRunFlag = 1;                                                           //08-12-31|0x0162
            DevelopState = 19688; // MAKE_READ                                            //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          case UserError:                                                                 //08-12-31|0x0162
            DevelopRunFlag = 1;                                                           //08-12-31|0x0162
            DevelopState = 51440; // CLOSE_USER                                           //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
          default:                                                                        //08-12-31|0x0162
            DevelopStatus = SystemError;                                                  //08-12-31|0x0162
            DevelopRunFlag = 0;                                                           //08-12-31|0x0162
            SystemMsg;                                                                    //08-12-31|0x0162
            break;                                                                        //08-12-31|0x0162
        }                                                                                 //08-12-31|0x0162
        break;                                                                            //08-12-31|0x0162
//---------------------------------------------------------------------------             //08-12-31|0x0163
      case 19688: // MAKE_READ                                                            //08-12-27|0x0164
        switch(read_project())                                                            //08-12-27|0x0164
        {                                                                                 //08-12-27|0x0164
          case Display:                                                                   //08-12-27|0x0164
            DevelopState = 7143; // MAKE_READ_EXIT                                        //08-12-27|0x0164
            DevelopStatus = Display;                                                      //08-12-27|0x0164
            DevelopRunFlag = 0;                                                           //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          case LineDone:                                                                  //08-12-27|0x0164
            DevelopRunFlag = 1;                                                           //08-12-27|0x0164
            DevelopState = 41569; // END_FILE                                             //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          case FileDone:                                                                  //08-12-27|0x0164
            DevelopRunFlag = 1;                                                           //08-12-27|0x0164
            DevelopState = 40589; // CLOSE_OK                                             //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          case UserError:                                                                 //08-12-27|0x0164
            DevelopRunFlag = 1;                                                           //08-12-27|0x0164
            DevelopState = 51440; // CLOSE_USER                                           //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          default:                                                                        //08-12-27|0x0164
            DevelopStatus = SystemError;                                                  //08-12-27|0x0164
            DevelopRunFlag = 0;                                                           //08-12-27|0x0164
            SystemMsg;                                                                    //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
        }                                                                                 //08-12-27|0x0164
        break;                                                                            //08-12-27|0x0164
//**************************************************************************              //08-12-27|0x0164
      case 7143: // MAKE_READ_EXIT                                                        //08-12-27|0x0164
        switch(read_project())                                                            //08-12-27|0x0164
        {                                                                                 //08-12-27|0x0164
          case Display:                                                                   //08-12-27|0x0164
            DevelopState = 7143; // MAKE_READ_EXIT                                        //08-12-27|0x0164
            DevelopStatus = Display;                                                      //08-12-27|0x0164
            DevelopRunFlag = 0;                                                           //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          case LineDone:                                                                  //08-12-27|0x0164
            DevelopRunFlag = 1;                                                           //08-12-27|0x0164
            DevelopState = 41569; // END_FILE                                             //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          case FileDone:                                                                  //08-12-27|0x0164
            DevelopRunFlag = 1;                                                           //08-12-27|0x0164
            DevelopState = 40589; // CLOSE_OK                                             //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          case UserError:                                                                 //08-12-27|0x0164
            DevelopRunFlag = 1;                                                           //08-12-27|0x0164
            DevelopState = 51440; // CLOSE_USER                                           //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
          default:                                                                        //08-12-27|0x0164
            DevelopStatus = SystemError;                                                  //08-12-27|0x0164
            DevelopRunFlag = 0;                                                           //08-12-27|0x0164
            SystemMsg;                                                                    //08-12-27|0x0164
            break;                                                                        //08-12-27|0x0164
        }                                                                                 //08-12-27|0x0164
        break;                                                                            //08-12-27|0x0164
//***************************************************************************             //11-12-17|0x0165
//******                                                               ******             //11-12-17|0x0166
//****** ERRORS MESSAGES                                               ******             //11-12-17|0x0167
//******                                                               ******             //11-12-17|0x0168
//***************************************************************************             //11-12-17|0x0169
      case 29429: // ILLEGAL_COMMAND                                                      //06-09-30|0x016a
        switch(IllegalCommand)                                                            //06-09-30|0x016a
        {                                                                                 //06-09-30|0x016a
          case UserError:                                                                 //06-09-30|0x016a
            DevelopRunFlag = 1;                                                           //06-09-30|0x016a
            DevelopState = 51440; // CLOSE_USER                                           //06-09-30|0x016a
            break;                                                                        //06-09-30|0x016a
          default:                                                                        //06-09-30|0x016a
            DevelopStatus = SystemError;                                                  //06-09-30|0x016a
            DevelopRunFlag = 0;                                                           //06-09-30|0x016a
            SystemMsg;                                                                    //06-09-30|0x016a
            break;                                                                        //06-09-30|0x016a
        }                                                                                 //06-09-30|0x016a
        break;                                                                            //06-09-30|0x016a
//---------------------------------------------------------------------------             //06-08-09|0x016b
      case 41569: // END_FILE                                                             //06-09-30|0x016c
        switch(IllegalEndOfFile)                                                          //06-09-30|0x016c
        {                                                                                 //06-09-30|0x016c
          case UserError:                                                                 //06-09-30|0x016c
            DevelopRunFlag = 1;                                                           //06-09-30|0x016c
            DevelopState = 51440; // CLOSE_USER                                           //06-09-30|0x016c
            break;                                                                        //06-09-30|0x016c
          default:                                                                        //06-09-30|0x016c
            DevelopStatus = SystemError;                                                  //06-09-30|0x016c
            DevelopRunFlag = 0;                                                           //06-09-30|0x016c
            SystemMsg;                                                                    //06-09-30|0x016c
            break;                                                                        //06-09-30|0x016c
        }                                                                                 //06-09-30|0x016c
        break;                                                                            //06-09-30|0x016c
//***************************************************************************             //11-12-12|0x016d
//******                                                               ******             //11-12-12|0x016e
//****** Complete a Successful process                                 ******             //11-12-12|0x016f
//******                                                               ******             //11-12-12|0x0170
//***************************************************************************             //11-12-12|0x0171
      case 40589: // CLOSE_OK                                                             //11-12-12|0x0172
        switch(close_project())                                                           //11-12-12|0x0172
        {                                                                                 //11-12-12|0x0172
          case Success:                                                                   //11-12-12|0x0172
            DevelopRunFlag = 1;                                                           //11-12-12|0x0172
            DevelopState = 56022; // NEED_POP_OK                                          //11-12-12|0x0172
            break;                                                                        //11-12-12|0x0172
          default:                                                                        //11-12-12|0x0172
            DevelopStatus = SystemError;                                                  //11-12-12|0x0172
            DevelopRunFlag = 0;                                                           //11-12-12|0x0172
            SystemMsg;                                                                    //11-12-12|0x0172
            break;                                                                        //11-12-12|0x0172
        }                                                                                 //11-12-12|0x0172
        break;                                                                            //11-12-12|0x0172
//---------------------------------------------------------------------------             //11-12-12|0x0173
      case 56022: // NEED_POP_OK                                                          //11-12-12|0x0174
        switch(DecrDevPrjNo)                                                              //11-12-12|0x0174
        {                                                                                 //11-12-12|0x0174
          case Yes:                                                                       //11-12-12|0x0174
            DevelopRunFlag = 1;                                                           //11-12-12|0x0174
            DevelopState = 34997; // POP_OK                                               //11-12-12|0x0174
            break;                                                                        //11-12-12|0x0174
          case No:                                                                        //11-12-12|0x0174
            DevelopRunFlag = 1;                                                           //11-12-12|0x0174
            DevelopState = 5252; // RETURN_TASK_NO                                        //11-12-12|0x0174
            break;                                                                        //11-12-12|0x0174
          default:                                                                        //11-12-12|0x0174
            DevelopStatus = SystemError;                                                  //11-12-12|0x0174
            DevelopRunFlag = 0;                                                           //11-12-12|0x0174
            SystemMsg;                                                                    //11-12-12|0x0174
            break;                                                                        //11-12-12|0x0174
        }                                                                                 //11-12-12|0x0174
        break;                                                                            //11-12-12|0x0174
//---------------------------------------------------------------------------             //11-12-12|0x0175
      case 34997: // POP_OK                                                               //11-12-17|0x0176
        switch(develop_pop())                                                             //11-12-17|0x0176
        {                                                                                 //11-12-17|0x0176
          case Success:                                                                   //11-12-17|0x0176
            DevelopRunFlag = 1;                                                           //11-12-17|0x0176
            DevelopState = 23875; // CONT_MACRO_READ                                      //11-12-17|0x0176
            break;                                                                        //11-12-17|0x0176
          default:                                                                        //11-12-17|0x0176
            DevelopStatus = SystemError;                                                  //11-12-17|0x0176
            DevelopRunFlag = 0;                                                           //11-12-17|0x0176
            SystemMsg;                                                                    //11-12-17|0x0176
            break;                                                                        //11-12-17|0x0176
        }                                                                                 //11-12-17|0x0176
        break;                                                                            //11-12-17|0x0176
//***************************************************************************             //11-12-12|0x0177
      case 23875: // CONT_MACRO_READ                                                      //11-12-17|0x0178
        switch(read_project())                                                            //11-12-17|0x0178
        {                                                                                 //11-12-17|0x0178
          case Display:                                                                   //11-12-17|0x0178
            DevelopState = 12786; // CONT_MACRO_READ_EXIT                                 //11-12-17|0x0178
            DevelopStatus = Display;                                                      //11-12-17|0x0178
            DevelopRunFlag = 0;                                                           //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          case LineDone:                                                                  //11-12-17|0x0178
            DevelopRunFlag = 1;                                                           //11-12-17|0x0178
            DevelopState = 20881; // CONT_MACRO_PAUSE                                     //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          case FileDone:                                                                  //11-12-17|0x0178
            DevelopRunFlag = 1;                                                           //11-12-17|0x0178
            DevelopState = 40589; // CLOSE_OK                                             //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          case UserError:                                                                 //11-12-17|0x0178
            DevelopRunFlag = 1;                                                           //11-12-17|0x0178
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          default:                                                                        //11-12-17|0x0178
            DevelopStatus = SystemError;                                                  //11-12-17|0x0178
            DevelopRunFlag = 0;                                                           //11-12-17|0x0178
            SystemMsg;                                                                    //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
        }                                                                                 //11-12-17|0x0178
        break;                                                                            //11-12-17|0x0178
//**************************************************************************              //11-12-17|0x0178
      case 12786: // CONT_MACRO_READ_EXIT                                                 //11-12-17|0x0178
        switch(read_project())                                                            //11-12-17|0x0178
        {                                                                                 //11-12-17|0x0178
          case Display:                                                                   //11-12-17|0x0178
            DevelopState = 12786; // CONT_MACRO_READ_EXIT                                 //11-12-17|0x0178
            DevelopStatus = Display;                                                      //11-12-17|0x0178
            DevelopRunFlag = 0;                                                           //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          case LineDone:                                                                  //11-12-17|0x0178
            DevelopRunFlag = 1;                                                           //11-12-17|0x0178
            DevelopState = 20881; // CONT_MACRO_PAUSE                                     //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          case FileDone:                                                                  //11-12-17|0x0178
            DevelopRunFlag = 1;                                                           //11-12-17|0x0178
            DevelopState = 40589; // CLOSE_OK                                             //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          case UserError:                                                                 //11-12-17|0x0178
            DevelopRunFlag = 1;                                                           //11-12-17|0x0178
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
          default:                                                                        //11-12-17|0x0178
            DevelopStatus = SystemError;                                                  //11-12-17|0x0178
            DevelopRunFlag = 0;                                                           //11-12-17|0x0178
            SystemMsg;                                                                    //11-12-17|0x0178
            break;                                                                        //11-12-17|0x0178
        }                                                                                 //11-12-17|0x0178
        break;                                                                            //11-12-17|0x0178
//---------------------------------------------------------------------------             //11-12-17|0x0179
      case 20881: // CONT_MACRO_PAUSE                                                     //11-12-17|0x017a
        switch(DebugPause)                                                                //11-12-17|0x017a
        {                                                                                 //11-12-17|0x017a
          case Display:                                                                   //11-12-17|0x017a
            DevelopState = 27424; // CONT_MACRO_PAUSE_EXIT                                //11-12-17|0x017a
            DevelopStatus = Display;                                                      //11-12-17|0x017a
            DevelopRunFlag = 0;                                                           //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case KeyBoard:                                                                  //11-12-17|0x017a
            DevelopState = 27424; // CONT_MACRO_PAUSE_EXIT                                //11-12-17|0x017a
            DevelopStatus = KeyBoard;                                                     //11-12-17|0x017a
            DevelopRunFlag = 0;                                                           //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case Continue:                                                                  //11-12-17|0x017a
            DevelopRunFlag = 1;                                                           //11-12-17|0x017a
            DevelopState = 20881; // CONT_MACRO_PAUSE                                     //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case Success:                                                                   //11-12-17|0x017a
            DevelopRunFlag = 1;                                                           //11-12-17|0x017a
            DevelopState = 19409; // DEBUG_CMD                                            //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case UserError:                                                                 //11-12-17|0x017a
            DevelopRunFlag = 1;                                                           //11-12-17|0x017a
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          default:                                                                        //11-12-17|0x017a
            DevelopStatus = SystemError;                                                  //11-12-17|0x017a
            DevelopRunFlag = 0;                                                           //11-12-17|0x017a
            SystemMsg;                                                                    //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
        }                                                                                 //11-12-17|0x017a
        break;                                                                            //11-12-17|0x017a
//**************************************************************************              //11-12-17|0x017a
      case 27424: // CONT_MACRO_PAUSE_EXIT                                                //11-12-17|0x017a
        switch(DebugPause)                                                                //11-12-17|0x017a
        {                                                                                 //11-12-17|0x017a
          case Display:                                                                   //11-12-17|0x017a
            DevelopState = 27424; // CONT_MACRO_PAUSE_EXIT                                //11-12-17|0x017a
            DevelopStatus = Display;                                                      //11-12-17|0x017a
            DevelopRunFlag = 0;                                                           //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case KeyBoard:                                                                  //11-12-17|0x017a
            DevelopState = 27424; // CONT_MACRO_PAUSE_EXIT                                //11-12-17|0x017a
            DevelopStatus = KeyBoard;                                                     //11-12-17|0x017a
            DevelopRunFlag = 0;                                                           //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case Continue:                                                                  //11-12-17|0x017a
            DevelopRunFlag = 1;                                                           //11-12-17|0x017a
            DevelopState = 20881; // CONT_MACRO_PAUSE                                     //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case Success:                                                                   //11-12-17|0x017a
            DevelopRunFlag = 1;                                                           //11-12-17|0x017a
            DevelopState = 19409; // DEBUG_CMD                                            //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          case UserError:                                                                 //11-12-17|0x017a
            DevelopRunFlag = 1;                                                           //11-12-17|0x017a
            DevelopState = 51440; // CLOSE_USER                                           //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
          default:                                                                        //11-12-17|0x017a
            DevelopStatus = SystemError;                                                  //11-12-17|0x017a
            DevelopRunFlag = 0;                                                           //11-12-17|0x017a
            SystemMsg;                                                                    //11-12-17|0x017a
            break;                                                                        //11-12-17|0x017a
        }                                                                                 //11-12-17|0x017a
        break;                                                                            //11-12-17|0x017a
//***************************************************************************             //11-12-12|0x017b
      case 5252: // RETURN_TASK_NO                                                        //11-12-12|0x017c
        ReturnTaskNo;                                                                     //11-12-12|0x017c
        DevelopState = 7583; // SUCCESSFUL                                                //11-12-12|0x017c
        break;                                                                            //11-12-12|0x017c
//---------------------------------------------------------------------------             //11-12-12|0x017d
      case 7583: // SUCCESSFUL                                                            //11-12-12|0x017e
        DevelopState = 4462; // INITIAL_DEVPRJ_NO                                         //11-12-12|0x017e
        DevelopStatus = Success;                                                          //11-12-12|0x017e
        DevelopRunFlag = 0;                                                               //11-12-12|0x017e
        break;                                                                            //11-12-12|0x017e
//***************************************************************************             //11-12-12|0x017f
//******                                                               ******             //11-12-12|0x0180
//****** Complete a User Error                                         ******             //11-12-12|0x0181
//******                                                               ******             //11-12-12|0x0182
//***************************************************************************             //11-12-12|0x0183
      case 51440: // CLOSE_USER                                                           //11-12-12|0x0184
        switch(close_project())                                                           //11-12-12|0x0184
        {                                                                                 //11-12-12|0x0184
          case Success:                                                                   //11-12-12|0x0184
            DevelopRunFlag = 1;                                                           //11-12-12|0x0184
            DevelopState = 11959; // NEED_POP_USER                                        //11-12-12|0x0184
            break;                                                                        //11-12-12|0x0184
          default:                                                                        //11-12-12|0x0184
            DevelopStatus = SystemError;                                                  //11-12-12|0x0184
            DevelopRunFlag = 0;                                                           //11-12-12|0x0184
            SystemMsg;                                                                    //11-12-12|0x0184
            break;                                                                        //11-12-12|0x0184
        }                                                                                 //11-12-12|0x0184
        break;                                                                            //11-12-12|0x0184
//---------------------------------------------------------------------------             //11-12-12|0x0185
      case 11959: // NEED_POP_USER                                                        //11-12-12|0x0186
        switch(DecrDevPrjNo)                                                              //11-12-12|0x0186
        {                                                                                 //11-12-12|0x0186
          case Yes:                                                                       //11-12-12|0x0186
            DevelopRunFlag = 1;                                                           //11-12-12|0x0186
            DevelopState = 63502; // POP_USER                                             //11-12-12|0x0186
            break;                                                                        //11-12-12|0x0186
          case No:                                                                        //11-12-12|0x0186
            DevelopRunFlag = 1;                                                           //11-12-12|0x0186
            DevelopState = 31085; // USER_ERROR                                           //11-12-12|0x0186
            break;                                                                        //11-12-12|0x0186
          default:                                                                        //11-12-12|0x0186
            DevelopStatus = SystemError;                                                  //11-12-12|0x0186
            DevelopRunFlag = 0;                                                           //11-12-12|0x0186
            SystemMsg;                                                                    //11-12-12|0x0186
            break;                                                                        //11-12-12|0x0186
        }                                                                                 //11-12-12|0x0186
        break;                                                                            //11-12-12|0x0186
//---------------------------------------------------------------------------             //11-12-12|0x0187
      case 63502: // POP_USER                                                             //11-12-12|0x0188
        switch(develop_pop())                                                             //11-12-12|0x0188
        {                                                                                 //11-12-12|0x0188
          case Success:                                                                   //11-12-12|0x0188
            DevelopRunFlag = 1;                                                           //11-12-12|0x0188
            DevelopState = 51440; // CLOSE_USER                                           //11-12-12|0x0188
            break;                                                                        //11-12-12|0x0188
          default:                                                                        //11-12-12|0x0188
            DevelopStatus = SystemError;                                                  //11-12-12|0x0188
            DevelopRunFlag = 0;                                                           //11-12-12|0x0188
            SystemMsg;                                                                    //11-12-12|0x0188
            break;                                                                        //11-12-12|0x0188
        }                                                                                 //11-12-12|0x0188
        break;                                                                            //11-12-12|0x0188
//---------------------------------------------------------------------------             //06-08-09|0x0189
      case 31085: // USER_ERROR                                                           //11-12-12|0x018a
        DevelopState = 4462; // INITIAL_DEVPRJ_NO                                         //11-12-12|0x018a
        DevelopStatus = UserError;                                                        //11-12-12|0x018a
        DevelopRunFlag = 0;                                                               //11-12-12|0x018a
        break;                                                                            //11-12-12|0x018a
//***************************************************************************             //11-12-12|0x018b
//******                                                               ******             //11-12-12|0x018c
//****** Complete a Build Error                                        ******             //11-12-12|0x018d
//******                                                               ******             //11-12-12|0x018e
//***************************************************************************             //11-12-12|0x018f
      case 4284: // CLOSE_BUILD                                                           //11-12-12|0x0190
        switch(close_project())                                                           //11-12-12|0x0190
        {                                                                                 //11-12-12|0x0190
          case Success:                                                                   //11-12-12|0x0190
            DevelopRunFlag = 1;                                                           //11-12-12|0x0190
            DevelopState = 53715; // NEED_POP_BUILD                                       //11-12-12|0x0190
            break;                                                                        //11-12-12|0x0190
          default:                                                                        //11-12-12|0x0190
            DevelopStatus = SystemError;                                                  //11-12-12|0x0190
            DevelopRunFlag = 0;                                                           //11-12-12|0x0190
            SystemMsg;                                                                    //11-12-12|0x0190
            break;                                                                        //11-12-12|0x0190
        }                                                                                 //11-12-12|0x0190
        break;                                                                            //11-12-12|0x0190
//---------------------------------------------------------------------------             //11-12-12|0x0191
      case 53715: // NEED_POP_BUILD                                                       //11-12-12|0x0192
        switch(DecrDevPrjNo)                                                              //11-12-12|0x0192
        {                                                                                 //11-12-12|0x0192
          case Yes:                                                                       //11-12-12|0x0192
            DevelopRunFlag = 1;                                                           //11-12-12|0x0192
            DevelopState = 7419; // POP_BUILD                                             //11-12-12|0x0192
            break;                                                                        //11-12-12|0x0192
          case No:                                                                        //11-12-12|0x0192
            DevelopRunFlag = 1;                                                           //11-12-12|0x0192
            DevelopState = 60714; // BUILD_ERROR                                          //11-12-12|0x0192
            break;                                                                        //11-12-12|0x0192
          default:                                                                        //11-12-12|0x0192
            DevelopStatus = SystemError;                                                  //11-12-12|0x0192
            DevelopRunFlag = 0;                                                           //11-12-12|0x0192
            SystemMsg;                                                                    //11-12-12|0x0192
            break;                                                                        //11-12-12|0x0192
        }                                                                                 //11-12-12|0x0192
        break;                                                                            //11-12-12|0x0192
//---------------------------------------------------------------------------             //11-12-12|0x0193
      case 7419: // POP_BUILD                                                             //11-12-12|0x0194
        switch(develop_pop())                                                             //11-12-12|0x0194
        {                                                                                 //11-12-12|0x0194
          case Success:                                                                   //11-12-12|0x0194
            DevelopRunFlag = 1;                                                           //11-12-12|0x0194
            DevelopState = 4284; // CLOSE_BUILD                                           //11-12-12|0x0194
            break;                                                                        //11-12-12|0x0194
          default:                                                                        //11-12-12|0x0194
            DevelopStatus = SystemError;                                                  //11-12-12|0x0194
            DevelopRunFlag = 0;                                                           //11-12-12|0x0194
            SystemMsg;                                                                    //11-12-12|0x0194
            break;                                                                        //11-12-12|0x0194
        }                                                                                 //11-12-12|0x0194
        break;                                                                            //11-12-12|0x0194
//---------------------------------------------------------------------------             //06-09-30|0x0195
      case 60714: // BUILD_ERROR                                                          //11-12-12|0x0196
        DevelopState = 4462; // INITIAL_DEVPRJ_NO                                         //11-12-12|0x0196
        DevelopStatus = BuildError;                                                       //11-12-12|0x0196
        DevelopRunFlag = 0;                                                               //11-12-12|0x0196
        break;                                                                            //11-12-12|0x0196
//***************************************************************************             //06-08-09|0x0197
      default:                                                                            //06-07-23|0x0198
        DevelopStatus = SystemError;                                                      //06-07-23|0x0198
        DevelopRunFlag = 0;                                                               //06-07-23|0x0198
        SystemMsg;                                                                        //06-07-23|0x0198
        break;                                                                            //06-07-23|0x0198
    }                                                                                     //06-07-23|0x0198
  }                                                                                       //06-07-23|0x0198
//***************************************************************************             //06-08-09|0x0199
//***************************************************************************             //06-08-09|0x019a
    return(DevelopStatus);                                                                //06-09-30|0x019b
}                                                                                         //06-07-23|0x019c
//                                                                                        //05-24-97|0x019c
//***************************************************************************             //11-12-12|0x019f
//***************************************************************************             //11-12-12|0x01a0
//******                                                               ******             //11-12-12|0x01a1
//******                     increment_project_no                      ******             //11-12-12|0x01a2
//******                                                               ******             //11-12-12|0x01a3
//***************************************************************************             //11-12-12|0x01a4
//***************************************************************************             //11-12-12|0x01a5
//*******************************************************************************         //10-29-97|0x01a9
//*******************************************************************************         //10-29-97|0x01a9
// increment_project_no                                                                   //11-12-12|0x01a9
//*******************************************************************************         //10-29-97|0x01a9
//*******************************************************************************         //10-29-97|0x01a9
UINT DEVELOPMENTPROJ::increment_project_no(void) {                                        //11-12-12|0x01a9
//*******************************************************************************         //10-29-97|0x01a9
//***************************************************************************             //11-12-12|0x01ac
//***************************************************************************             //11-12-12|0x01ad
    ++DevelopDevPrjNo;                                                                    //11-12-12|0x01ae
    if(DevelopDevPrjNo > 16)       ReturnFinish("Over 16 Development Files");             //11-12-12|0x01af
//***************************************************************************             //11-12-12|0x01b0
    return_test(increment_project_no_1);                                                  //11-12-12|0x01b1
}                                                                                         //11-12-12|0x01b2
//                                                                                        //05-24-97|0x01b2
//***************************************************************************             //06-08-09|0x01b5
//***************************************************************************             //06-08-09|0x01b6
//******                                                               ******             //06-08-09|0x01b7
//******                     enter_project_name                        ******             //06-08-09|0x01b8
//******                                                               ******             //06-08-09|0x01b9
//***************************************************************************             //06-08-09|0x01ba
//***************************************************************************             //06-08-09|0x01bb
//*******************************************************************************         //10-29-97|0x01bf
//*******************************************************************************         //10-29-97|0x01bf
// enter_project_name                                                                     //11-12-12|0x01bf
//*******************************************************************************         //10-29-97|0x01bf
//*******************************************************************************         //10-29-97|0x01bf
UINT DEVELOPMENTPROJ::enter_project_name(void) {                                          //11-12-12|0x01bf
//*******************************************************************************         //10-29-97|0x01bf
//***************************************************************************             //06-08-09|0x01c2
//***************************************************************************             //06-08-09|0x01c3
  UINT i;                                                                            //11-12-12|0x01c4
//***************************************************************************             //06-08-09|0x01c5
//***************************************************************************             //06-08-09|0x01c6
    if(DevelopDevPrjNo > 16)                                ReturnSystemError             //11-12-12|0x01c7
    if(DevelopDevPrjNo < 1)                                 ReturnSystemError             //11-12-12|0x01c8
//***************************************************************************             //11-12-12|0x01c9
    DevelopTaskNo         = 0;                                                            //09-03-27|0x01ca
    DevelopSingleStepFlag = 0;                                                            //08-12-31|0x01cb
    switch(InitialProjFile)                                      _SwitchGroup             //06-08-09|0x01cc
    switch(EnterProjFileName)                                    _SwitchGroup             //11-12-12|0x01cd
    switch(FileRelease())                                        _SwitchGroup             //06-08-09|0x01ce
//***************************************************************************             //06-08-09|0x01cf
    for(i=1; i<DevelopDevPrjNo; ++i)                                                      //11-12-12|0x01d0
      {                                                                                   //11-12-12|0x01d1
        if(StrCmp(DevelopFileName, DevelopPastFileName(i)) == 0)                          //11-12-12|0x01d2
                          ReturnFinish("Previously Opened Development File");             //11-12-12|0x01d3
        }                                                                                 //11-12-12|0x01d4
//***************************************************************************             //06-08-09|0x01d5
    return_test(enter_project_name_1);                                                    //06-08-09|0x01d6
}                                                                                         //06-08-09|0x01d7
//                                                                                        //05-24-97|0x01d7
//***************************************************************************             //06-08-09|0x01da
//***************************************************************************             //06-08-09|0x01db
//******                                                               ******             //06-08-09|0x01dc
//******                       project_exists                          ******             //06-08-09|0x01dd
//******                                                               ******             //06-08-09|0x01de
//***************************************************************************             //06-08-09|0x01df
//***************************************************************************             //06-08-09|0x01e0
//*******************************************************************************         //10-29-97|0x01e4
//*******************************************************************************         //10-29-97|0x01e4
// project_exists                                                                         //11-12-12|0x01e4
//*******************************************************************************         //10-29-97|0x01e4
//*******************************************************************************         //10-29-97|0x01e4
UINT DEVELOPMENTPROJ::project_exists(void) {                                              //11-12-12|0x01e4
//*******************************************************************************         //10-29-97|0x01e4
//***************************************************************************             //06-08-09|0x01e7
//***************************************************************************             //06-08-09|0x01e8
    if(DevelopDevPrjNo > 16)                                ReturnSystemError             //11-12-12|0x01e9
    if(DevelopDevPrjNo < 1)                                 ReturnSystemError             //11-12-12|0x01ea
//***************************************************************************             //11-12-12|0x01eb
    switch(CommitProjFile)                                       _SwitchGroup             //06-08-09|0x01ec
    switch(FileExists(DevelopProjectTimeAddr))                   _SwitchGroup             //08-06-15|0x01ed
    switch(FileRelease())                                        _SwitchGroup             //06-08-09|0x01ee
//***************************************************************************             //06-08-09|0x01ef
    switch(DevelopProjectTime)                                                            //08-06-15|0x01f0
      {                                                                                   //06-08-09|0x01f1
        case  0:                                           return(UserError);             //06-08-09|0x01f2
        default:                                                       break;             //07-06-04|0x01f3
        }                                                                                 //06-08-09|0x01f4
//***************************************************************************             //06-08-09|0x01f5
    DevelopDisplayState = 0;                                                              //11-12-12|0x01f6
    if(DevelopPreUpdateTime > DevelopProjectTime)                                         //08-06-15|0x01f7
      {                                                                                   //11-12-12|0x01f8
        DevelopDisplayState = 1;                                                          //11-12-12|0x01f9
        DevelopProjectTime = DevelopPreUpdateTime;                                        //11-12-12|0x01fa
        }                                                                                 //07-06-04|0x01fb
    DevelopUpdateTime = DevelopProjectTime;                                               //08-06-15|0x01fc
    DevelopMainTime   = DevelopPreUpdateTime;                                             //11-12-12|0x01fd
    return_test(project_exists_1);                                                        //07-06-04|0x01fe
}                                                                                         //06-08-09|0x01ff
//                                                                                        //05-24-97|0x01ff
//***************************************************************************             //06-08-09|0x0202
//***************************************************************************             //06-08-09|0x0203
//******                                                               ******             //06-08-09|0x0204
//******                          open_project                         ******             //06-08-09|0x0205
//******                                                               ******             //06-08-09|0x0206
//***************************************************************************             //06-08-09|0x0207
//***************************************************************************             //06-08-09|0x0208
//*******************************************************************************         //10-29-97|0x020c
//*******************************************************************************         //10-29-97|0x020c
// open_project                                                                           //06-08-09|0x020c
//*******************************************************************************         //10-29-97|0x020c
//*******************************************************************************         //10-29-97|0x020c
UINT DEVELOPMENTPROJ::open_project(void) {                                                //06-08-09|0x020c
//*******************************************************************************         //10-29-97|0x020c
//***************************************************************************             //06-08-09|0x020f
//***************************************************************************             //06-08-09|0x0210
    switch(CommitProjFile)                                       _SwitchGroup             //06-08-09|0x0211
    switch(FileOpenText())                                       _SwitchGroup             //06-08-09|0x0212
    switch(FileRelease())                                        _SwitchGroup             //06-08-09|0x0213
//***************************************************************************             //06-08-09|0x0214
    return_test(open_project_1);                                                          //06-08-09|0x0215
}                                                                                         //06-08-09|0x0216
//                                                                                        //05-24-97|0x0216
//***************************************************************************             //06-08-09|0x0219
//***************************************************************************             //06-08-09|0x021a
//******                                                               ******             //06-08-09|0x021b
//******                          read_project                         ******             //06-08-09|0x021c
//******                                                               ******             //06-08-09|0x021d
//***************************************************************************             //06-08-09|0x021e
//***************************************************************************             //06-08-09|0x021f
//*******************************************************************************         //10-29-97|0x0226
//*******************************************************************************         //10-29-97|0x0226
// read_project                                                                           //06-08-09|0x0226
//*******************************************************************************         //10-29-97|0x0226
//*******************************************************************************         //10-29-97|0x0226
UINT DEVELOPMENTPROJ::read_project(void) {                                                //06-08-09|0x0226
//*******************************************************************************         //10-29-97|0x0226
//***************************************************************************             //06-08-09|0x0229
//***************************************************************************             //06-08-09|0x022a
  UINT status;                                                                       //06-08-09|0x022b
//***************************************************************************             //06-08-09|0x022c
//***************************************************************************             //06-08-09|0x022d
    switch(DevelopSingleStepFlag)                                                         //08-12-31|0x022e
      {                                                                                   //08-12-31|0x022f
        case 0:                                                                           //08-12-31|0x0230
          switch(DevelopDisplayState)                                                     //11-12-12|0x0231
            {                                                                             //08-12-31|0x0232
              case 0:   DisplayOff();                                 break;              //08-12-31|0x0233
              default:  DisplayOn();                                  break;              //08-12-31|0x0234
              }                                                                           //08-12-31|0x0235
          break;                                                                          //08-12-31|0x0236
        default:  DisplayOn();                                        break;              //08-12-31|0x0237
        }                                                                                 //08-12-31|0x0238
//***************************************************************************             //08-04-25|0x0239
    switch(CommitProjFile)                                       _SwitchGroup             //06-08-09|0x023a
//***************************************************************************             //06-08-09|0x023b
    status = FileReadText(DevelopTokensAddr);                                             //06-08-09|0x023c
//---------------------------------------------------------------------------             //06-08-09|0x023d
    switch(status)                                                                        //06-08-09|0x023e
      {                                                                                   //06-08-09|0x023f
        case FileDone:                            break_test(read_project_1);             //06-08-09|0x0240
        case LineDone:                            break_test(read_project_2);             //06-08-09|0x0241
        case UserError:                           break_test(read_project_3);             //06-08-09|0x0242
        case Display:                             break_test(read_project_4);             //06-08-09|0x0243
        default:                                            ReturnSystemError             //06-08-09|0x0244
        }                                                                                 //06-08-09|0x0245
//***************************************************************************             //06-08-09|0x0246
    switch(FileRelease())                                        _SwitchGroup             //06-08-09|0x0247
//***************************************************************************             //08-12-31|0x0248
    switch(DevelopDisplayState)                                                           //11-12-12|0x0249
      {                                                                                   //08-12-31|0x024a
        case 0:   DisplayOff();                                       break;              //08-12-31|0x024b
        default:  DisplayOn();                                        break;              //08-12-31|0x024c
        }                                                                                 //08-12-31|0x024d
//***************************************************************************             //06-08-09|0x024e
//***************************************************************************             //06-08-09|0x024f
    return(status);                                                                       //06-08-09|0x0250
}                                                                                         //06-08-09|0x0251
//                                                                                        //05-24-97|0x0251
//***************************************************************************             //06-11-13|0x0254
//***************************************************************************             //06-11-13|0x0255
//******                                                               ******             //06-11-13|0x0256
//******                        update_always                          ******             //06-11-13|0x0257
//******                                                               ******             //06-11-13|0x0258
//***************************************************************************             //06-11-13|0x0259
//***************************************************************************             //06-11-13|0x025a
//*******************************************************************************         //10-29-97|0x025e
//*******************************************************************************         //10-29-97|0x025e
// update_always                                                                          //07-10-30|0x025e
//*******************************************************************************         //10-29-97|0x025e
//*******************************************************************************         //10-29-97|0x025e
UINT DEVELOPMENTPROJ::update_always(void) {                                               //07-10-30|0x025e
//*******************************************************************************         //10-29-97|0x025e
//***************************************************************************             //06-11-13|0x0261
//***************************************************************************             //06-11-13|0x0262
    IfNoTokens(1, 1)                   ReturnFinish("Illegal No Parameters");             //06-11-13|0x0263
//---------------------------------------------------------------------------             //06-11-13|0x0264
    DevelopDisplayState = 1;                                                              //11-12-12|0x0265
    DevelopProjectTime  = 0xffffffff;                                                     //08-06-15|0x0266
    DevelopUpdateTime   = 0xffffffff;                                                     //08-06-15|0x0267
//***************************************************************************             //06-11-13|0x0268
    return_test(update_always_1);                                                         //07-10-30|0x0269
}                                                                                         //06-11-13|0x026a
//                                                                                        //05-24-97|0x026a
//***************************************************************************             //08-06-15|0x026d
//***************************************************************************             //08-06-15|0x026e
//******                                                               ******             //08-06-15|0x026f
//******                        turn_off_display                       ******             //08-06-15|0x0270
//******                                                               ******             //08-06-15|0x0271
//***************************************************************************             //08-06-15|0x0272
//***************************************************************************             //08-06-15|0x0273
//*******************************************************************************         //10-29-97|0x0277
//*******************************************************************************         //10-29-97|0x0277
// turn_off_display                                                                       //08-06-15|0x0277
//*******************************************************************************         //10-29-97|0x0277
//*******************************************************************************         //10-29-97|0x0277
UINT DEVELOPMENTPROJ::turn_off_display(void) {                                            //08-06-15|0x0277
//*******************************************************************************         //10-29-97|0x0277
//***************************************************************************             //08-06-15|0x027a
//***************************************************************************             //08-06-15|0x027b
    IfNoTokens(1, 1)                   ReturnFinish("Illegal No Parameters");             //08-06-15|0x027c
    DevelopDisplayState = 0;                                                              //11-12-12|0x027d
//***************************************************************************             //08-06-15|0x027e
    return_test(turn_off_display_1);                                                      //08-06-15|0x027f
}                                                                                         //08-06-15|0x0280
//                                                                                        //05-24-97|0x0280
//***************************************************************************             //08-06-15|0x0283
//***************************************************************************             //08-06-15|0x0284
//******                                                               ******             //08-06-15|0x0285
//******                        turn_on_display                        ******             //08-06-15|0x0286
//******                                                               ******             //08-06-15|0x0287
//***************************************************************************             //08-06-15|0x0288
//***************************************************************************             //08-06-15|0x0289
//*******************************************************************************         //10-29-97|0x028d
//*******************************************************************************         //10-29-97|0x028d
// turn_on_display                                                                        //08-06-15|0x028d
//*******************************************************************************         //10-29-97|0x028d
//*******************************************************************************         //10-29-97|0x028d
UINT DEVELOPMENTPROJ::turn_on_display(void) {                                             //08-06-15|0x028d
//*******************************************************************************         //10-29-97|0x028d
//***************************************************************************             //08-06-15|0x0290
//***************************************************************************             //08-06-15|0x0291
    IfNoTokens(1, 1)                   ReturnFinish("Illegal No Parameters");             //08-06-15|0x0292
    DevelopDisplayState = 1;                                                              //11-12-12|0x0293
//***************************************************************************             //08-06-15|0x0294
    return_test(turn_on_display_1);                                                       //08-06-15|0x0295
}                                                                                         //08-06-15|0x0296
//                                                                                        //05-24-97|0x0296
//***************************************************************************             //08-06-15|0x0299
//***************************************************************************             //08-06-15|0x029a
//******                                                               ******             //08-06-15|0x029b
//******                        enable_file_time                       ******             //08-06-15|0x029c
//******                                                               ******             //08-06-15|0x029d
//***************************************************************************             //08-06-15|0x029e
//***************************************************************************             //08-06-15|0x029f
//*******************************************************************************         //10-29-97|0x02a3
//*******************************************************************************         //10-29-97|0x02a3
// enable_file_time                                                                       //08-06-15|0x02a3
//*******************************************************************************         //10-29-97|0x02a3
//*******************************************************************************         //10-29-97|0x02a3
UINT DEVELOPMENTPROJ::enable_file_time(void) {                                            //08-06-15|0x02a3
//*******************************************************************************         //10-29-97|0x02a3
//***************************************************************************             //08-06-15|0x02a6
//***************************************************************************             //08-06-15|0x02a7
    IfNoTokens(1, 1)                   ReturnFinish("Illegal No Parameters");             //08-06-15|0x02a8
//---------------------------------------------------------------------------             //08-06-15|0x02a9
    DevelopUpdateTime = DevelopProjectTime;                                               //08-06-15|0x02aa
//---------------------------------------------------------------------------             //08-06-15|0x02ab
    switch(DevelopDisplayState)                                                           //11-12-17|0x02ac
      {                                                                                   //08-06-15|0x02ad
        case 0:   DevelopDisplayState = 2;                            break;              //checj   |0x02ae
        default:                                                      break;              //08-06-15|0x02af
        }                                                                                 //08-06-15|0x02b0
//***************************************************************************             //08-06-15|0x02b1
    return_test(enable_file_time_1);                                                      //08-06-15|0x02b2
}                                                                                         //08-06-15|0x02b3
//                                                                                        //05-24-97|0x02b3
//***************************************************************************             //08-06-15|0x02b6
//***************************************************************************             //08-06-15|0x02b7
//******                                                               ******             //08-06-15|0x02b8
//******                        disable_file_time                      ******             //08-06-15|0x02b9
//******                                                               ******             //08-06-15|0x02ba
//***************************************************************************             //08-06-15|0x02bb
//***************************************************************************             //08-06-15|0x02bc
//*******************************************************************************         //10-29-97|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
// disable_file_time                                                                      //08-06-15|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
UINT DEVELOPMENTPROJ::disable_file_time(void) {                                           //08-06-15|0x02c0
//*******************************************************************************         //10-29-97|0x02c0
//***************************************************************************             //08-06-15|0x02c3
//***************************************************************************             //08-06-15|0x02c4
    IfNoTokens(1, 1)                   ReturnFinish("Illegal No Parameters");             //08-06-15|0x02c5
//---------------------------------------------------------------------------             //08-06-15|0x02c6
    DevelopUpdateTime = DevelopMainTime;                                                  //08-06-15|0x02c7
//---------------------------------------------------------------------------             //08-06-15|0x02c8
    switch(DevelopDisplayState)                                                           //11-12-12|0x02c9
      {                                                                                   //08-06-15|0x02ca
        case 2:   DevelopDisplayState = 0;                            break;              //11-12-12|0x02cb
        default:                                                      break;              //08-06-15|0x02cc
        }                                                                                 //08-06-15|0x02cd
//***************************************************************************             //08-06-15|0x02ce
    return_test(disable_file_time_1);                                                     //08-06-15|0x02cf
}                                                                                         //08-06-15|0x02d0
//                                                                                        //05-24-97|0x02d0
//***************************************************************************             //09-03-27|0x02d3
//***************************************************************************             //09-03-27|0x02d4
//******                                                               ******             //09-03-27|0x02d5
//******                          update_task_no                       ******             //09-03-27|0x02d6
//******                                                               ******             //09-03-27|0x02d7
//***************************************************************************             //09-03-27|0x02d8
//***************************************************************************             //09-03-27|0x02d9
//*******************************************************************************         //10-29-97|0x02df
//*******************************************************************************         //10-29-97|0x02df
// update_task_no                                                                         //11-12-12|0x02df
//*******************************************************************************         //10-29-97|0x02df
//*******************************************************************************         //10-29-97|0x02df
UINT DEVELOPMENTPROJ::update_task_no(void) {                                              //11-12-12|0x02df
//*******************************************************************************         //10-29-97|0x02df
//***************************************************************************             //09-03-27|0x02e2
//***************************************************************************             //09-03-27|0x02e3
  WORDS task_no;                                                                     //09-03-27|0x02e4
  WORDS stack_no;                                                                    //11-12-12|0x02e5
//***************************************************************************             //11-12-12|0x02e6
//***************************************************************************             //11-12-12|0x02e7
    switch(TokensNoTokens)                                                                //11-12-12|0x02e8
      {                                                                                   //11-12-12|0x02e9
//***************************************************************************             //11-12-12|0x02ea
        case 3:                                                                           //11-12-17|0x02eb
          switch(TokensPrepare(DevelopTokensAddr, 1))            _SwitchGroup             //11-12-17|0x02ec
//---------------------------------------------------------------------------             //11-12-17|0x02ed
          if(StrToInt(TokensLineAddr(1),  task_no.ulong) == 0)                            //11-12-17|0x02ee
                              ReturnFinish("Illegal Sequence Parameter");                 //11-12-17|0x02ef
//---------------------------------------------------------------------------             //11-12-17|0x02f0
          if(StrToInt(TokensLineAddr(2),  stack_no.ulong) == 0)                           //11-12-17|0x02f1
                              ReturnFinish("Illegal Stack Parameter");                    //11-12-17|0x02f2
          break_test(update_task_no_1);                                                   //11-12-17|0x02f3
//***************************************************************************             //11-12-12|0x02f4
        case 2:                                                                           //11-12-12|0x02f5
          switch(TokensPrepare(DevelopTokensAddr, 1))            _SwitchGroup             //11-12-12|0x02f6
//---------------------------------------------------------------------------             //11-12-12|0x02f7
          if(StrToInt(TokensLineAddr(1),  task_no.ulong) == 0)                            //11-12-12|0x02f8
                              ReturnFinish("Illegal Sequence Parameter");                 //11-12-12|0x02f9
//---------------------------------------------------------------------------             //11-12-12|0x02fa
          stack_no.ulong = 1;                                                             //11-12-12|0x02fb
          break_test(update_task_no_2);                                                   //11-12-12|0x02fc
//***************************************************************************             //11-12-12|0x02fd
        default:                  ReturnFinish("Illegal No Parameters");                  //11-12-12|0x02fe
        }                                                                                 //11-12-12|0x02ff
//***************************************************************************             //11-12-12|0x0300
    if(DevelopDevPrjNo > 16)                                ReturnSystemError             //11-12-12|0x0301
    if(DevelopDevPrjNo < 1)                                 ReturnSystemError             //11-12-12|0x0302
//***************************************************************************             //11-12-12|0x0303
    if(DevelopDevPrjNo  != stack_no.word0)  ReturnFinish("Illegal Stack No");             //11-12-17|0x0304
//***************************************************************************             //11-12-12|0x0305
    if(DevelopPreTaskNo >  task_no.word0)                                                 //11-12-12|0x0306
                              ReturnFinish("Illegal Sequence");                           //11-12-12|0x0307
    DevelopPreTaskNo = task_no.word0;                                                     //11-12-12|0x0308
    return_test(update_task_no_3);                                                        //11-12-12|0x0309
}                                                                                         //11-12-12|0x030a
//                                                                                        //05-24-97|0x030a
//***************************************************************************             //06-08-09|0x030d
//***************************************************************************             //06-08-09|0x030e
//******                                                               ******             //06-08-09|0x030f
//******                          drive_path                           ******             //06-08-09|0x0310
//******                                                               ******             //06-08-09|0x0311
//***************************************************************************             //06-08-09|0x0312
//***************************************************************************             //06-08-09|0x0313
//*******************************************************************************         //10-29-97|0x0317
//*******************************************************************************         //10-29-97|0x0317
// drive_path                                                                             //06-08-09|0x0317
//*******************************************************************************         //10-29-97|0x0317
//*******************************************************************************         //10-29-97|0x0317
UINT DEVELOPMENTPROJ::drive_path(void) {                                                  //06-08-09|0x0317
//*******************************************************************************         //10-29-97|0x0317
//***************************************************************************             //06-08-09|0x031a
//***************************************************************************             //06-08-09|0x031b
    IfNoTokens(2, 10)                  ReturnFinish("Illegal No Parameters");             //06-08-09|0x031c
//---------------------------------------------------------------------------             //06-08-09|0x031d
    MemCpy(DevelopDrivesAddr,      DevelopTokensAddr,  sizeof(TOKENS));                   //06-08-09|0x031e
    MemSet(DrivePathTokenAddr(0),  0x00,               sizeof(STRING_DATA));              //06-08-09|0x031f
//---------------------------------------------------------------------------             //06-08-09|0x0320
    switch(TokensPrepare(DevelopDrivesAddr, 1))                  _SwitchGroup             //06-08-09|0x0321
//***************************************************************************             //06-08-09|0x0322
    return_test(drive_path_1);                                                            //06-08-09|0x0323
}                                                                                         //06-08-09|0x0324
//                                                                                        //05-24-97|0x0324
//***************************************************************************             //06-08-29|0x0327
//***************************************************************************             //06-08-29|0x0328
//******                                                               ******             //06-08-29|0x0329
//******                            get_file_name                      ******             //06-08-29|0x032a
//******                                                               ******             //06-08-29|0x032b
//***************************************************************************             //06-08-29|0x032c
//***************************************************************************             //06-08-29|0x032d
//*******************************************************************************         //10-29-97|0x0331
//*******************************************************************************         //10-29-97|0x0331
// get_file_name                                                                          //11-12-12|0x0331
//*******************************************************************************         //10-29-97|0x0331
//*******************************************************************************         //10-29-97|0x0331
UINT DEVELOPMENTPROJ::get_file_name(void) {                                               //11-12-12|0x0331
//*******************************************************************************         //10-29-97|0x0331
//***************************************************************************             //11-12-12|0x0334
//***************************************************************************             //11-12-12|0x0335
    IfNoTokens(2, 2)                   ReturnFinish("Illegal No Parameters");             //11-12-12|0x0336
    if(DrivePathNoTokens == 0) DrivePathNoTokens = 1;                                     //11-12-12|0x0337
    switch(FileTextPrepare)                                      _SwitchGroup             //11-12-12|0x0338
//***************************************************************************             //11-12-12|0x0339
    return_test(get_file_name_1);                                                         //11-12-12|0x033a
}                                                                                         //11-12-12|0x033b
//                                                                                        //05-24-97|0x033b
//***************************************************************************             //06-08-29|0x033e
//***************************************************************************             //06-08-29|0x033f
//******                                                               ******             //06-08-29|0x0340
//******                            develop_push                       ******             //06-08-29|0x0341
//******                                                               ******             //06-08-29|0x0342
//***************************************************************************             //06-08-29|0x0343
//***************************************************************************             //06-08-29|0x0344
//*******************************************************************************         //10-29-97|0x0348
//*******************************************************************************         //10-29-97|0x0348
// develop_push                                                                           //11-12-12|0x0348
//*******************************************************************************         //10-29-97|0x0348
//*******************************************************************************         //10-29-97|0x0348
UINT DEVELOPMENTPROJ::develop_push(void) {                                                //11-12-12|0x0348
//*******************************************************************************         //10-29-97|0x0348
//***************************************************************************             //06-08-29|0x034b
//***************************************************************************             //06-08-29|0x034c
    if(CallPrePush(DevelopDrivesAddr)      != Success)      ReturnSystemError             //11-12-12|0x034d
//***************************************************************************             //06-08-29|0x034e
    return_test(develop_push_1);                                                          //06-08-29|0x034f
}                                                                                         //06-08-29|0x0350
//                                                                                        //05-24-97|0x0350
//***************************************************************************             //11-12-12|0x0353
//***************************************************************************             //11-12-12|0x0354
//******                                                               ******             //11-12-12|0x0355
//******                     decrement_project_no                      ******             //11-12-12|0x0356
//******                                                               ******             //11-12-12|0x0357
//***************************************************************************             //11-12-12|0x0358
//***************************************************************************             //11-12-12|0x0359
//*******************************************************************************         //10-29-97|0x035e
//*******************************************************************************         //10-29-97|0x035e
// decrement_project_no                                                                   //11-12-12|0x035e
//*******************************************************************************         //10-29-97|0x035e
//*******************************************************************************         //10-29-97|0x035e
UINT DEVELOPMENTPROJ::decrement_project_no(void) {                                        //11-12-12|0x035e
//*******************************************************************************         //10-29-97|0x035e
//***************************************************************************             //11-12-12|0x0361
//***************************************************************************             //11-12-12|0x0362
    if(DevelopDevPrjNo > 16)                                ReturnSystemError             //11-12-12|0x0363
    if(DevelopDevPrjNo < 1)                                 ReturnSystemError             //11-12-12|0x0364
//***************************************************************************             //11-12-12|0x0365
    if(DevelopDevPrjNo == 1)                                                              //11-12-12|0x0366
                                           return_no(decrement_project_no_1);             //11-12-12|0x0367
//***************************************************************************             //11-12-12|0x0368
    --DevelopDevPrjNo;                                                                    //11-12-12|0x0369
    return_yes(decrement_project_no_2);                                                   //11-12-12|0x036a
}                                                                                         //11-12-12|0x036b
//                                                                                        //05-24-97|0x036b
//***************************************************************************             //06-08-29|0x036e
//***************************************************************************             //06-08-29|0x036f
//******                                                               ******             //06-08-29|0x0370
//******                            develop_pop                        ******             //06-08-29|0x0371
//******                                                               ******             //06-08-29|0x0372
//***************************************************************************             //06-08-29|0x0373
//***************************************************************************             //06-08-29|0x0374
//*******************************************************************************         //10-29-97|0x0378
//*******************************************************************************         //10-29-97|0x0378
// develop_pop                                                                            //11-12-17|0x0378
//*******************************************************************************         //10-29-97|0x0378
//*******************************************************************************         //10-29-97|0x0378
UINT DEVELOPMENTPROJ::develop_pop(void) {                                                 //11-12-17|0x0378
//*******************************************************************************         //10-29-97|0x0378
//***************************************************************************             //11-12-12|0x037b
//***************************************************************************             //11-12-12|0x037c
    switch(CallPrePop())                                         _SwitchGroup             //11-12-12|0x037d
//***************************************************************************             //11-12-12|0x037e
    return_test(develop_pop_1);                                                           //11-12-12|0x037f
}                                                                                         //11-12-12|0x0380
//                                                                                        //05-24-97|0x0380
//***************************************************************************             //06-11-14|0x0383
//***************************************************************************             //06-11-14|0x0384
//******                                                               ******             //06-11-14|0x0385
//******                            source_args                        ******             //06-11-14|0x0386
//******                                                               ******             //06-11-14|0x0387
//***************************************************************************             //06-11-14|0x0388
//***************************************************************************             //06-11-14|0x0389
//*******************************************************************************         //10-29-97|0x038d
//*******************************************************************************         //10-29-97|0x038d
// source_args                                                                            //06-11-14|0x038d
//*******************************************************************************         //10-29-97|0x038d
//*******************************************************************************         //10-29-97|0x038d
UINT DEVELOPMENTPROJ::source_args(                                                        //06-11-14|0x038d
    TOKENS_FAR InputTokensFar                                                             //06-11-14|0x038d
    ) {                                                                                   //06-11-14|0x038d
//*******************************************************************************         //10-29-97|0x038d
//***************************************************************************             //06-11-14|0x0390
//***************************************************************************             //06-11-14|0x0391
    if((InputNoTokens < 1) || (InputNoTokens > 2))          ReturnSystemError             //06-12-01|0x0392
//***************************************************************************             //06-11-14|0x0393
    MemSet(DevelopTokensAddr,  0x00,                  sizeof(TOKENS));                    //06-11-14|0x0394
    MemCpy(TokensTokenAddr(0), DrivePathTokenAddr(0), sizeof(STRING_DATA));               //06-11-14|0x0395
    TokensNoTokens = 1;                                                                   //06-12-01|0x0396
//***************************************************************************             //06-12-01|0x0397
    return_test(source_args_1);                                                           //06-12-01|0x0398
}                                                                                         //06-11-14|0x0399
//                                                                                        //05-24-97|0x0399
//***************************************************************************             //08-12-27|0x039c
//***************************************************************************             //08-12-27|0x039d
//******                                                               ******             //08-12-27|0x039e
//******                        spawn_name                             ******             //08-12-27|0x039f
//******                                                               ******             //08-12-27|0x03a0
//***************************************************************************             //08-12-27|0x03a1
//***************************************************************************             //08-12-27|0x03a2
//***************************************************************************             //08-12-27|0x03a4
//***************************************************************************             //08-12-27|0x03a5
//*******************************************************************************         //10-29-97|0x03a8
//*******************************************************************************         //10-29-97|0x03a8
// spawn_name                                                                             //08-12-27|0x03a8
//*******************************************************************************         //10-29-97|0x03a8
//*******************************************************************************         //10-29-97|0x03a8
UINT DEVELOPMENTPROJ::spawn_name(void) {                                                  //08-12-27|0x03a8
//*******************************************************************************         //10-29-97|0x03a8
//***************************************************************************             //08-12-27|0x03ab
//***************************************************************************             //08-12-27|0x03ac
    WORDS work;                                                                      //08-12-27|0x03ad
//***************************************************************************             //08-12-27|0x03ae
    TestSample(spawn_mame_1);                                                             //08-12-27|0x03af
//---------------------------------------------------------------------------             //08-12-27|0x03b0
    IfNoTokens(2, 9)                   ReturnFinish("Illegal No Parameters");             //08-12-27|0x03b1
    switch(TokensPrepare(DevelopTokensAddr, 1))                  _SwitchGroup             //08-12-27|0x03b2
//---------------------------------------------------------------------------             //08-12-27|0x03b3
    work.ulong = 0;                                                                       //08-12-27|0x03b4
    if(TokensLength(1)    == 0)                             ReturnSystemError             //08-12-27|0x03b5
    if(TokensLength(1)    >  256)                           ReturnSystemError             //08-12-27|0x03b6
    StrCpy(MakeNameAddr,  TokensLineAddr(1));                                             //08-12-27|0x03b7
    work.ulong = StrLen(MakeNameAddr);                                                    //08-12-27|0x03b8
    if(TokensLength(1) != work.sint0)                       ReturnSystemError             //08-12-27|0x03b9
    return(Success);                                                                      //08-12-27|0x03ba
}                                                                                         //08-12-27|0x03bb
//                                                                                        //05-24-97|0x03bb
//***************************************************************************             //08-12-27|0x03be
//***************************************************************************             //08-12-27|0x03bf
//******                                                               ******             //08-12-27|0x03c0
//******                        spawn_parms                            ******             //08-12-27|0x03c1
//******                                                               ******             //08-12-27|0x03c2
//***************************************************************************             //08-12-27|0x03c3
//***************************************************************************             //08-12-27|0x03c4
//***************************************************************************             //08-12-27|0x03c6
//***************************************************************************             //08-12-27|0x03c7
//*******************************************************************************         //10-29-97|0x03ca
//*******************************************************************************         //10-29-97|0x03ca
// spawn_parms                                                                            //08-12-27|0x03ca
//*******************************************************************************         //10-29-97|0x03ca
//*******************************************************************************         //10-29-97|0x03ca
UINT DEVELOPMENTPROJ::spawn_parms(void) {                                                 //08-12-27|0x03ca
//*******************************************************************************         //10-29-97|0x03ca
//***************************************************************************             //08-12-27|0x03cd
//***************************************************************************             //08-12-27|0x03ce
  SLONG space;                                                                       //08-12-27|0x03cf
  ULONG size;                                                                        //08-12-27|0x03d0
  WORDS total_size;                                                                  //08-12-27|0x03d1
  SCHAR_FAR out_addr;                                                                //08-12-27|0x03d2
  SCHAR_FAR in_addr;                                                                 //08-12-27|0x03d3
  UINT token_no;                                                                     //08-12-27|0x03d4
//***************************************************************************             //08-12-27|0x03d5
//***************************************************************************             //08-12-27|0x03d6
    TestSample(spawn_parms_1);                                                            //08-12-27|0x03d7
//***************************************************************************             //08-12-27|0x03d8
//***************************************************************************             //08-12-27|0x03d9
    MemSet(MakeParmsAddr, 0, 1025);                                                       //08-12-27|0x03da
    StrCpy(MakeParmsAddr, "  ");                                                          //08-12-27|0x03db
//---------------------------------------------------------------------------             //08-12-27|0x03dc
    token_no = FirstArg;                                                                  //08-12-27|0x03dd
    if(token_no >= TokensNoTokens)                                                        //08-12-27|0x03de
                                                             return(Success);             //08-12-27|0x03df
//---------------------------------------------------------------------------             //08-12-27|0x03e0
    total_size.ulong  = 0;                                                                //08-12-27|0x03e1
//***************************************************************************             //08-12-27|0x03e2
//***                                                                   *****             //08-12-27|0x03e3
//*** PROCESS EACH OF THE TOKENS                                        *****             //08-12-27|0x03e4
//***                                                                   *****             //08-12-27|0x03e5
//***************************************************************************             //08-12-27|0x03e6
loop:                                                                                     //08-12-27|0x03e7
        size = TokensLength(token_no);                                                    //08-12-27|0x03e8
        if(size == 0)                                       ReturnSystemError             //08-12-27|0x03e9
        if(size  > 256)                                     ReturnSystemError             //08-12-27|0x03ea
        if(TokensChar(token_no, size) != 0)                 ReturnSystemError             //08-12-27|0x03eb
//---------------------------------------------------------------------------             //08-12-27|0x03ec
        in_addr   = TokensLineAddr(token_no);                                             //08-12-27|0x03ed
        out_addr  = MakeParmsAddr + total_size.ulong;                                     //08-12-27|0x03ee
        if((space = 1024 - total_size.slong) <= 0)          ReturnSystemError             //08-12-27|0x03ef
//---------------------------------------------------------------------------             //08-12-27|0x03f0
        if(MemCCpy(out_addr, in_addr, 0x00, space) == 0)                                  //08-12-27|0x03f1
                                         ReturnFinish("Parameter Too Large");             //08-12-27|0x03f2
//---------------------------------------------------------------------------             //08-12-27|0x03f3
        if((total_size.ulong += size) != StrLen(MakeParmsAddr))                           //08-12-27|0x03f4
                                                            ReturnSystemError             //08-12-27|0x03f5
//***************************************************************************             //08-12-27|0x03f6
//***                                                                   *****             //08-12-27|0x03f7
//*** EXIT IF WE ARE DONE                                               *****             //08-12-27|0x03f8
//***                                                                   *****             //08-12-27|0x03f9
//***************************************************************************             //08-12-27|0x03fa
        if((++token_no) >= TokensNoTokens)                                                //08-12-27|0x03fb
                                                             return(Success);             //08-12-27|0x03fc
//***************************************************************************             //08-12-27|0x03fd
//***                                                                   *****             //08-12-27|0x03fe
//*** INSERT A BLANK CHARACTER                                          *****             //08-12-27|0x03ff
//***                                                                   *****             //08-12-27|0x0400
//***************************************************************************             //08-12-27|0x0401
        if((space = 1024 - total_size.slong) <= 1)          ReturnSystemError             //08-12-27|0x0402
        out_addr  = MakeParmsAddr + total_size.ulong;                                     //08-12-27|0x0403
//---------------------------------------------------------------------------             //08-12-27|0x0404
        *out_addr = ' ';                                                                  //08-12-27|0x0405
//---------------------------------------------------------------------------             //08-12-27|0x0406
        if((total_size.ulong += 1) != StrLen(MakeParmsAddr))                              //08-12-27|0x0407
                                                            ReturnSystemError             //08-12-27|0x0408
        goto loop;                                                                        //08-12-27|0x0409
}                                                                                         //08-12-27|0x040a
//                                                                                        //05-24-97|0x040a
//***************************************************************************             //08-12-27|0x040d
//***************************************************************************             //08-12-27|0x040e
//******                                                               ******             //08-12-27|0x040f
//******                        make_step                              ******             //08-12-27|0x0410
//******                                                               ******             //08-12-27|0x0411
//***************************************************************************             //08-12-27|0x0412
//***************************************************************************             //08-12-27|0x0413
//*******************************************************************************         //10-29-97|0x0418
//*******************************************************************************         //10-29-97|0x0418
// make_step                                                                              //08-12-27|0x0418
//*******************************************************************************         //10-29-97|0x0418
//*******************************************************************************         //10-29-97|0x0418
UINT DEVELOPMENTPROJ::make_step(void) {                                                   //08-12-27|0x0418
//*******************************************************************************         //10-29-97|0x0418
//***************************************************************************             //08-12-27|0x041b
//***************************************************************************             //08-12-27|0x041c
  SLONG status;                                                                      //08-12-27|0x041d
//***************************************************************************             //08-12-27|0x041e
//***************************************************************************             //08-12-27|0x041f
    status = system(MakeParmsAddr);                                                       //08-12-27|0x0420
    if(WIFEXITED(status)!=0)                                                              //08-12-27|0x0420
      {                                                                                   //08-12-27|0x0420
        status = WEXITSTATUS(status);                                                     //08-12-27|0x0420
        }                                                                                 //08-12-27|0x0420
//--------------------------------------------------------------------------=             //08-12-27|0x0421
    if(status == 0)                                 return_test(make_step_1);             //08-12-27|0x0422
    TestSample(make_step_2);                                                              //08-12-27|0x0423
    ReturnFinish("Make / Spawn Error");                                                   //08-12-27|0x0424
}                                                                                         //08-12-27|0x0425
//                                                                                        //05-24-97|0x0425
//***************************************************************************             //08-12-31|0x0428
//***************************************************************************             //08-12-31|0x0429
//******                                                               ******             //08-12-31|0x042a
//******                        single_step_enable                     ******             //08-12-31|0x042b
//******                                                               ******             //08-12-31|0x042c
//***************************************************************************             //08-12-31|0x042d
//***************************************************************************             //08-12-31|0x042e
//*******************************************************************************         //10-29-97|0x0431
//*******************************************************************************         //10-29-97|0x0431
// single_step_enable                                                                     //08-12-31|0x0431
//*******************************************************************************         //10-29-97|0x0431
//*******************************************************************************         //10-29-97|0x0431
UINT DEVELOPMENTPROJ::single_step_enable(void) {                                          //08-12-31|0x0431
//*******************************************************************************         //10-29-97|0x0431
//***************************************************************************             //08-12-31|0x0434
//***************************************************************************             //08-12-31|0x0435
    IfNoTokens(1, 1)                   ReturnFinish("Illegal No Parameters");             //08-12-31|0x0436
//---------------------------------------------------------------------------             //08-12-31|0x0437
    DevelopSingleStepFlag = 1;                                                            //08-12-31|0x0438
    return(Success);                                                                      //08-12-31|0x0439
}                                                                                         //08-12-31|0x043a
//                                                                                        //05-24-97|0x043a
//***************************************************************************             //08-12-31|0x043d
//***************************************************************************             //08-12-31|0x043e
//******                                                               ******             //08-12-31|0x043f
//******                       debug_pause                             ******             //08-12-31|0x0440
//******                                                               ******             //08-12-31|0x0441
//***************************************************************************             //08-12-31|0x0442
//***************************************************************************             //08-12-31|0x0443
//*******************************************************************************         //10-29-97|0x0446
//*******************************************************************************         //10-29-97|0x0446
// debug_pause                                                                            //08-12-31|0x0446
//*******************************************************************************         //10-29-97|0x0446
//*******************************************************************************         //10-29-97|0x0446
UINT DEVELOPMENTPROJ::debug_pause(void) {                                                 //08-12-31|0x0446
//*******************************************************************************         //10-29-97|0x0446
//***************************************************************************             //08-12-31|0x0449
//***************************************************************************             //08-12-31|0x044a
    if(DevelopSingleStepFlag==0)                                                          //08-12-31|0x044b
                                                           return(Success);               //08-12-31|0x044c
//***************************************************************************             //08-12-31|0x044d
    switch(PrecMenuCmd())                                                                 //08-12-31|0x044e
      {                                                                                   //08-12-31|0x044f
        case No:    DevelopSingleStepFlag = 0;             return(Success);               //08-12-31|0x0450
        case Yes:                                          return(Success);               //08-12-31|0x0451
        case UserError:                                    return(UserError);             //08-12-31|0x0452
        case Continue:                                     return(Continue);              //08-12-31|0x0453
        case Display:                                      return(Display);               //08-12-31|0x0454
        case KeyBoard:                                     return(KeyBoard);              //08-12-31|0x0455
        default:                                           ReturnSystemError;             //08-12-31|0x0456
        }                                                                                 //08-12-31|0x0457
}                                                                                         //08-12-31|0x0458
//                                                                                        //05-24-97|0x0458
//***************************************************************************             //06-08-09|0x045b
//***************************************************************************             //06-08-09|0x045c
//******                                                               ******             //06-08-09|0x045d
//******                         close_project                         ******             //06-08-09|0x045e
//******                                                               ******             //06-08-09|0x045f
//***************************************************************************             //06-08-09|0x0460
//***************************************************************************             //06-08-09|0x0461
//*******************************************************************************         //10-29-97|0x0465
//*******************************************************************************         //10-29-97|0x0465
// close_project                                                                          //06-08-09|0x0465
//*******************************************************************************         //10-29-97|0x0465
//*******************************************************************************         //10-29-97|0x0465
UINT DEVELOPMENTPROJ::close_project(void) {                                               //06-08-09|0x0465
//*******************************************************************************         //10-29-97|0x0465
//***************************************************************************             //06-08-09|0x0468
//***************************************************************************             //06-08-09|0x0469
    switch(CommitProjFile)                                       _SwitchGroup             //06-08-09|0x046a
    switch(FileClose())                                          _SwitchGroup             //06-08-09|0x046b
    switch(FileRelease())                                        _SwitchGroup             //06-08-09|0x046c
//***************************************************************************             //06-08-09|0x046d
    return_test(close_project_1);                                                         //06-08-09|0x046e
}                                                                                         //06-08-09|0x046f
//                                                                                        //05-24-97|0x046f
//***************************************************************************             //06-07-14|0x0472
//***************************************************************************             //06-07-14|0x0473
//******                                                               ******             //06-07-14|0x0474
//******                       TEST WRAPPERS                           ******             //06-07-14|0x0475
//******                                                               ******             //06-07-14|0x0476
//***************************************************************************             //06-07-14|0x0477
//***************************************************************************             //06-07-14|0x0478
//*******************************************************************************         //10-29-97|0x0479
//*******************************************************************************         //10-29-97|0x0479
// devproj_test_reset                                                                     //06-07-14|0x0479
//*******************************************************************************         //10-29-97|0x0479
//*******************************************************************************         //10-29-97|0x0479
UINT DEVELOPMENTPROJ::devproj_test_reset(void) {                                          //06-07-14|0x0479
//*******************************************************************************         //10-29-97|0x0479
//************************************************************************                //06-07-14|0x0479
    switch(BasicTestReset())                                                              //06-07-14|0x0479
      {                                                                                   //06-07-14|0x0479
        case Success:                                     return(Success);                //06-07-14|0x0479
        default:                                        ReturnSystemError;                //06-07-14|0x0479
        }                                                                                 //06-07-14|0x0479
}                                                                                         //06-07-14|0x0479
//                                                                                        //05-24-97|0x0479
//***************************************************************************             //06-07-14|0x047a
//*******************************************************************************         //10-29-97|0x047b
//*******************************************************************************         //10-29-97|0x047b
// devproj_test_read                                                                      //06-07-14|0x047b
//*******************************************************************************         //10-29-97|0x047b
//*******************************************************************************         //10-29-97|0x047b
UINT DEVELOPMENTPROJ::devproj_test_read(void) {                                           //06-07-14|0x047b
//*******************************************************************************         //10-29-97|0x047b
//************************************************************************                //06-07-14|0x047b
    switch(BasicTestRead(&test_samples[0], test_samples[0]))                              //06-07-14|0x047b
      {                                                                                   //06-07-14|0x047b
        case Success:                                     return(Success);                //06-07-14|0x047b
        default:                                        ReturnSystemError;                //06-07-14|0x047b
        }                                                                                 //06-07-14|0x047b
}                                                                                         //06-07-14|0x047b
//                                                                                        //05-24-97|0x047b
//***************************************************************************             //06-07-14|0x047c
//*******************************************************************************         //10-29-97|0x047d
//*******************************************************************************         //10-29-97|0x047d
// devproj_test_write                                                                     //06-07-14|0x047d
//*******************************************************************************         //10-29-97|0x047d
//*******************************************************************************         //10-29-97|0x047d
UINT DEVELOPMENTPROJ::devproj_test_write(void) {                                          //06-07-14|0x047d
//*******************************************************************************         //10-29-97|0x047d
//************************************************************************                //06-07-14|0x047d
    switch(BasicTestWrite(&test_samples[0]))                                              //06-07-14|0x047d
      {                                                                                   //06-07-14|0x047d
        case Success:                                     return(Success);                //06-07-14|0x047d
        default:                                        ReturnSystemError;                //06-07-14|0x047d
        }                                                                                 //06-07-14|0x047d
}                                                                                         //06-07-14|0x047d
//                                                                                        //05-24-97|0x047d
//***************************************************************************             //06-07-14|0x047e
//*******************************************************************************         //10-29-97|0x047f
//*******************************************************************************         //10-29-97|0x047f
// devproj_test_report                                                                    //06-07-14|0x047f
//*******************************************************************************         //10-29-97|0x047f
//*******************************************************************************         //10-29-97|0x047f
UINT DEVELOPMENTPROJ::devproj_test_report(void) {                                         //06-07-14|0x047f
//*******************************************************************************         //10-29-97|0x047f
//************************************************************************                //06-07-14|0x047f
    switch(BasicTestReport(&test_samples[0], "DEVPROJ"))                                  //06-07-14|0x047f
      {                                                                                   //06-07-14|0x047f
        case Success:                                     return(Success);                //06-07-14|0x047f
        default:                                        ReturnSystemError;                //06-07-14|0x047f
        }                                                                                 //06-07-14|0x047f
}                                                                                         //06-07-14|0x047f
//                                                                                        //05-24-97|0x047f
//***************************************************************************             //06-07-12|0x0480
//***************************************************************************             //06-07-12|0x0481
//******                                                               ******             //06-07-12|0x0482
//******                        constructor                            ******             //06-07-12|0x0483
//******                                                               ******             //06-07-12|0x0484
//***************************************************************************             //06-07-12|0x0485
//***************************************************************************             //06-07-12|0x0486
//*******************************************************************************         //10-29-97|0x0487
//*******************************************************************************         //10-29-97|0x0487
// CONSTRUCTOR                                                                            //06-07-12|0x0487
//*******************************************************************************         //10-29-97|0x0487
//*******************************************************************************         //10-29-97|0x0487
DEVELOPMENTPROJ::DEVELOPMENTPROJ() {                                                      //06-07-12|0x0487
//***************************************************************************             //06-07-12|0x0488
//***************************************************************************             //06-07-12|0x0489
    develop_project_addr = 0;                                                             //06-07-12|0x048a
    { ULONG i;                                                                            //06-07-12|0x048c
      test_samples[NoTestSamples] = TestIndex;                                            //06-07-12|0x048c
      i = 1;                                                                              //06-07-12|0x048c
      while(i<TestIndex)                                                                  //06-07-12|0x048c
        {                                                                                 //06-07-12|0x048c
          test_samples[i] = 0;                                                            //06-07-12|0x048c
          ++i;                                                                            //06-07-12|0x048c
          }                                                                               //06-07-12|0x048c
      }                                                                                   //06-07-12|0x048c
}                                                                                         //06-07-12|0x048d
//                                                                                        //05-24-97|0x048d
//*******************************************************************************         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
//****                       END OF FILE                                     ****         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
