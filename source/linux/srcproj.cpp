//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
// LIBRARY-SOURCE MAIN ENGINE                                                             //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x001b
//  defined in the associated manual.                                                     //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x001b
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x001b
//  (at your option) any later version.                                                   //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x001b
//  GNU General Public License for more details.                                          //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x001b
//  along with this program; if not, write to the Free Software                           //06-07-12|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x001b
//  USA                                                                                   //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  For further information, please contact Robert Adams:                                 //06-07-12|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
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
#include "srcproj.h"                                                                      //06-07-12|0x001c
#include "srcproj.hxx"                                                                    //06-07-12|0x001c
#include "srcproj.hpp"                                                                    //06-07-12|0x001c
#include "crypto.h"                                                                       //10-03-22|0x001d
#include "precutil.h"                                                                     //06-07-12|0x001e
#include "precdiag.h"                                                                     //06-07-12|0x001f
#include "precfile.h"                                                                     //06-07-12|0x0020
#include "precform.h"                                                                     //06-07-12|0x0021
#include "precmac.h"                                                                      //06-07-12|0x0022
#include "macdict.h"                                                                      //06-07-12|0x0023
#include "maildict.h"                                                                     //09-03-10|0x0024
#include "preccall.h"                                                                     //06-07-12|0x0025
#include "prectext.h"                                                                     //06-09-11|0x0026
#include "precsrce.h"                                                                     //06-09-11|0x0027
#include "srcedict.h"                                                                     //06-09-26|0x0028
#include "guicomm.h"                                                                      //09-12-26|0x0029
#include "precnum.h"                                                                      //09-03-27|0x002a
#include "global.hxx"                                                                     //06-11-06|0x002b
#define Allocate(k) (k##_FAR) calloc(1,sizeof(k))                                         //06-07-12|0x0035
#define Free(k) free(k)                                                                   //06-07-12|0x0035
#define MemSet(i,j,k) memset(i,j,k)                                                       //06-07-12|0x0035
#define MemCCpy(i,j,k,l) Mem_C_Copy((UCHAR_FAR) i, (UCHAR_FAR) j,k,l)                     //06-07-12|0x0035
#define MemCpy(i,j,k) memcpy(i,j,k)                                                       //06-07-12|0x0035
#define LineEnd 0x0d                                                                      //06-07-12|0x0035
#define StrLen(i) strlen(i)                                                               //06-07-12|0x0036
#define StrCat(i,j) strcat(i,j)                                                           //06-07-12|0x0036
#define StrCpy(i,j) strcpy(i,j)                                                           //06-07-12|0x0036
#define StrCmp(i,j) Str_Comp((SCHAR_FAR)i,j,256)                                          //06-07-12|0x0036
#define StrRChr(i,j) strrchr(i,j)                                                         //06-07-12|0x0036
#define StrChr(i,j) strchr(i,j)                                                           //06-07-12|0x0036
#define StrToByteInt(i,j) GetInteger(i,&j,0xff)                                           //06-07-12|0x0036
#define StrToInt(i,j) GetInteger(i,&j,0xffff)                                             //06-07-12|0x0036
#define StrToLongInt(i,j) GetInteger(i,&j,0xffffffffL)                                    //06-07-12|0x0036
#define StrToByteHex(i,j) GetHex(i,&j,1)                                                  //06-07-12|0x0036
#define StrToHex(i,j) GetHex(i,&j,2)                                                      //06-07-12|0x0036
#define StrToLongHex(i,j) GetHex(i,&j,4)                                                  //06-07-12|0x0036
#define FindName(i) strrchr(i, '/')                                                       //06-07-12|0x0036
SOURCEPROJ source_proj;                                                                   //06-07-12|0x005a
static UINT test_samples[TestIndex];                                                      //06-07-12|0x006b
//***************************************************************************             //06-07-12|0x0074
//***************************************************************************             //06-07-12|0x0079
//***************************************************************************             //06-07-12|0x007c
//***************************************************************************             //06-07-12|0x007d
//******                                                               ******             //06-07-12|0x007e
//******                       srcproj_allocate                        ******             //06-07-12|0x007f
//******                                                               ******             //06-07-12|0x0080
//***************************************************************************             //06-07-12|0x0081
//***************************************************************************             //06-07-12|0x0082
//*******************************************************************************         //10-29-97|0x0089
//*******************************************************************************         //10-29-97|0x0089
// srcproj_allocate                                                                      //06-07-12|0x0089
//*******************************************************************************         //10-29-97|0x0089
//*******************************************************************************         //10-29-97|0x0089
UINT SOURCEPROJ::srcproj_allocate(void) {                                                //06-07-12|0x0089
//*******************************************************************************         //10-29-97|0x0089
//***************************************************************************             //06-07-12|0x008d
//***************************************************************************             //06-07-12|0x008e
    TestSample(srcproj_allocate_1);                                                       //06-07-12|0x008f
    if(source_project_addr                            != 0) ReturnSystemError             //06-07-12|0x0090
//***************************************************************************             //06-09-11|0x0091
    source_project_addr = Allocate(SOURCE_PROJECT);                                       //06-07-12|0x0092
    if(source_project_addr                            == 0) ReturnSystemError             //06-07-12|0x0093
//***************************************************************************             //06-09-11|0x0094
  SourceState = 4462; // INITIAL_PROJECT                                                  //06-09-11|0x0095
//***************************************************************************             //06-09-11|0x0096
    return(Success);                                                                      //06-07-12|0x0097
}                                                                                         //06-07-12|0x0098
//                                                                                        //05-24-97|0x0098
//***************************************************************************             //06-07-12|0x009b
//***************************************************************************             //06-07-12|0x009c
//******                                                               ******             //06-07-12|0x009d
//******                         srcproj_free                          ******             //06-07-12|0x009e
//******                                                               ******             //06-07-12|0x009f
//***************************************************************************             //06-07-12|0x00a0
//***************************************************************************             //06-07-12|0x00a1
//*******************************************************************************         //10-29-97|0x00a5
//*******************************************************************************         //10-29-97|0x00a5
// srcproj_free                                                                           //06-07-12|0x00a5
//*******************************************************************************         //10-29-97|0x00a5
//*******************************************************************************         //10-29-97|0x00a5
UINT SOURCEPROJ::srcproj_free(void) {                                                     //06-07-12|0x00a5
//*******************************************************************************         //10-29-97|0x00a5
//***************************************************************************             //06-07-12|0x00a9
//***************************************************************************             //06-07-12|0x00aa
    TestSample(srcproj_free_1);                                                           //06-07-12|0x00ab
    if(source_project_addr == 0)                            ReturnSystemError             //06-07-12|0x00ac
    Free(source_project_addr);                                                            //06-07-12|0x00ad
    source_project_addr = 0;                                                              //06-07-12|0x00ae
//***************************************************************************             //06-07-12|0x00af
    return(Success);                                                                      //06-07-12|0x00b0
}                                                                                         //06-07-12|0x00b1
//                                                                                        //05-24-97|0x00b1
//***************************************************************************             //06-09-11|0x00b4
//***************************************************************************             //06-09-11|0x00b5
//******                                                               ******             //06-09-11|0x00b6
//******              srcproj_process(InputtokensFar, UpdateTime)      ******             //06-09-11|0x00b7
//******---------------------------------------------------------------******             //06-09-11|0x00b8
//******     Token(1):  Project Complete Path-File Name                ******             //06-09-11|0x00b9
//******     Token(2):  Library Path                                   ******             //06-09-11|0x00ba
//******     Token(3):  Source Path                                    ******             //06-09-11|0x00bb
//******     Token(4):  Output Path                                    ******             //06-09-11|0x00bc
//******                                                               ******             //06-09-11|0x00bd
//***************************************************************************             //06-09-11|0x00be
//***************************************************************************             //06-09-11|0x00bf
//*******************************************************************************         //10-29-97|0x00c3
//*******************************************************************************         //10-29-97|0x00c3
// srcproj_process                                                                        //09-03-27|0x00c3
//*******************************************************************************         //10-29-97|0x00c3
//*******************************************************************************         //10-29-97|0x00c3
UINT SOURCEPROJ::srcproj_process(                                                         //09-03-27|0x00c3
    TOKENS_FAR InputAddr,                                                                 //09-03-27|0x00c3
    ULONG UpdateTime,                                                                     //09-03-27|0x00c3
    TOKENS_FAR PcgTokenFar,                                                               //09-03-27|0x00c3
    UINT_FAR TaskNoFar                                                                    //09-03-27|0x00c3
    ) {                                                                                   //09-03-27|0x00c3
//*******************************************************************************         //10-29-97|0x00c3
//***************************************************************************             //06-09-25|0x00c7
//***************************************************************************             //06-09-25|0x00c8
    if(source_project_addr == 0)                            ReturnSystemError             //06-09-25|0x00c9
    if(InputNoTokens       == 0)                            ReturnSystemError             //06-09-25|0x00ca
//***************************************************************************             //06-09-25|0x00cb
//******                                                               ******             //06-09-25|0x00cc
//****** State Machine Begins                                          ******             //06-09-25|0x00cd
//******                                                               ******             //06-09-25|0x00ce
//***************************************************************************             //06-09-25|0x00cf
  SourceRunFlag = 1;                                                                      //06-09-25|0x00d0
  while(SourceRunFlag != 0)                                                               //06-09-25|0x00d0
  {                                                                                       //06-09-25|0x00d0
    switch(SourceState)                                                                   //06-09-25|0x00d0
    {                                                                                     //06-09-25|0x00d0
//***************************************************************************             //06-09-25|0x00d1
//******                                                               ******             //06-09-25|0x00d2
//****** State Machine Initialized                                     ******             //06-09-25|0x00d3
//******                                                               ******             //06-09-25|0x00d4
//***************************************************************************             //06-09-25|0x00d5
      case 4462: // INITIAL_PROJECT                                                       //07-03-23|0x00d6
        ZeroFiles;                                                                        //07-03-23|0x00d6
        SourceState = 10445; // INITIAL_TIME                                              //07-03-23|0x00d6
        break;                                                                            //07-03-23|0x00d6
//---------------------------------------------------------------------------             //07-03-23|0x00d7
      case 10445: // INITIAL_TIME                                                         //08-04-16|0x00d8
        SourceOutTime = UpdateTime;                                                       //08-04-16|0x00d8
        SourceState = 46620; // ENABLE_DISPLAY_CONT                                       //08-04-16|0x00d8
        break;                                                                            //08-04-16|0x00d8
//---------------------------------------------------------------------------             //08-04-16|0x00d9
      case 46620: // ENABLE_DISPLAY_CONT                                                  //08-04-16|0x00da
        display_flag = 1;                                                                 //08-04-16|0x00da
        SourceState = 6235; // TURN_OFF_DISPLAY                                           //08-04-16|0x00da
        break;                                                                            //08-04-16|0x00da
//---------------------------------------------------------------------------             //08-04-16|0x00db
      case 6235: // TURN_OFF_DISPLAY                                                      //08-04-16|0x00dc
        if(display_flag) DisplayOff();                                                    //08-04-16|0x00dc
        SourceState = 40586; // PROJECT_NAME                                              //08-04-16|0x00dc
        break;                                                                            //08-04-16|0x00dc
//***************************************************************************             //06-09-25|0x00dd
//******                                                               ******             //06-09-25|0x00de
//****** Open Project File,                                            ******             //06-09-25|0x00df
//******                                                               ******             //06-09-25|0x00e0
//***************************************************************************             //06-09-25|0x00e1
      case 40586: // PROJECT_NAME                                                         //06-09-25|0x00e2
        switch(EnterProjectName)                                                          //06-09-25|0x00e2
        {                                                                                 //06-09-25|0x00e2
          case Success:                                                                   //06-09-25|0x00e2
            SourceRunFlag = 1;                                                            //06-09-25|0x00e2
            SourceState = 34729; // PROJECT_DATE                                          //06-09-25|0x00e2
            break;                                                                        //06-09-25|0x00e2
          default:                                                                        //06-09-25|0x00e2
            SourceStatus = SystemError;                                                   //06-09-25|0x00e2
            SourceRunFlag = 0;                                                            //06-09-25|0x00e2
            SystemMsg;                                                                    //06-09-25|0x00e2
            break;                                                                        //06-09-25|0x00e2
        }                                                                                 //06-09-25|0x00e2
        break;                                                                            //06-09-25|0x00e2
//---------------------------------------------------------------------------             //06-09-25|0x00e3
      case 34729: // PROJECT_DATE                                                         //06-09-25|0x00e4
        switch(ProjectFileTime)                                                           //06-09-25|0x00e4
        {                                                                                 //06-09-25|0x00e4
          case Success:                                                                   //06-09-25|0x00e4
            SourceRunFlag = 1;                                                            //06-09-25|0x00e4
            SourceState = 696; // PROJECT_EXISTS                                          //06-09-25|0x00e4
            break;                                                                        //06-09-25|0x00e4
          default:                                                                        //06-09-25|0x00e4
            SourceStatus = SystemError;                                                   //06-09-25|0x00e4
            SourceRunFlag = 0;                                                            //06-09-25|0x00e4
            SystemMsg;                                                                    //06-09-25|0x00e4
            break;                                                                        //06-09-25|0x00e4
        }                                                                                 //06-09-25|0x00e4
        break;                                                                            //06-09-25|0x00e4
//---------------------------------------------------------------------------             //06-09-25|0x00e5
      case 696: // PROJECT_EXISTS                                                         //06-09-25|0x00e6
        switch(FileDateExists)                                                            //06-09-25|0x00e6
        {                                                                                 //06-09-25|0x00e6
          case Yes:                                                                       //06-09-25|0x00e6
            SourceRunFlag = 1;                                                            //06-09-25|0x00e6
            SourceState = 11959; // PROJ_RECENT                                           //06-09-25|0x00e6
            break;                                                                        //06-09-25|0x00e6
          case No:                                                                        //06-09-25|0x00e6
            SourceRunFlag = 1;                                                            //06-09-25|0x00e6
            SourceState = 6822; // NO_PROJECT                                             //06-09-25|0x00e6
            break;                                                                        //06-09-25|0x00e6
          default:                                                                        //06-09-25|0x00e6
            SourceStatus = SystemError;                                                   //06-09-25|0x00e6
            SourceRunFlag = 0;                                                            //06-09-25|0x00e6
            SystemMsg;                                                                    //06-09-25|0x00e6
            break;                                                                        //06-09-25|0x00e6
        }                                                                                 //06-09-25|0x00e6
        break;                                                                            //06-09-25|0x00e6
//---------------------------------------------------------------------------             //06-09-25|0x00e7
      case 6822: // NO_PROJECT                                                            //07-03-23|0x00e8
        switch(ProjectDoesNotExist)                                                       //07-03-23|0x00e8
        {                                                                                 //07-03-23|0x00e8
          case UserError:                                                                 //07-03-23|0x00e8
            SourceRunFlag = 1;                                                            //07-03-23|0x00e8
            SourceState = 50565; // USER_ERROR                                            //07-03-23|0x00e8
            break;                                                                        //07-03-23|0x00e8
          default:                                                                        //07-03-23|0x00e8
            SourceStatus = SystemError;                                                   //07-03-23|0x00e8
            SourceRunFlag = 0;                                                            //07-03-23|0x00e8
            SystemMsg;                                                                    //07-03-23|0x00e8
            break;                                                                        //07-03-23|0x00e8
        }                                                                                 //07-03-23|0x00e8
        break;                                                                            //07-03-23|0x00e8
//---------------------------------------------------------------------------             //07-03-23|0x00e9
      case 11959: // PROJ_RECENT                                                          //06-09-12|0x00ea
        switch(FileDateRecent)                                                            //06-09-12|0x00ea
        {                                                                                 //06-09-12|0x00ea
          case 1:                                                                         //06-09-12|0x00ea
            SourceRunFlag = 1;                                                            //06-09-12|0x00ea
            SourceState = 7764; // RECENT_PROJ                                            //06-09-12|0x00ea
            break;                                                                        //06-09-12|0x00ea
          case 0:                                                                         //06-09-12|0x00ea
            SourceRunFlag = 1;                                                            //06-09-12|0x00ea
            SourceState = 1043; // OPEN_PROJ                                              //06-09-12|0x00ea
            break;                                                                        //06-09-12|0x00ea
          case -1:                                                                        //06-09-12|0x00ea
            SourceRunFlag = 1;                                                            //06-09-12|0x00ea
            SourceState = 1043; // OPEN_PROJ                                              //06-09-12|0x00ea
            break;                                                                        //06-09-12|0x00ea
          default:                                                                        //06-09-12|0x00ea
            SourceStatus = SystemError;                                                   //06-09-12|0x00ea
            SourceRunFlag = 0;                                                            //06-09-12|0x00ea
            SystemMsg;                                                                    //06-09-12|0x00ea
            break;                                                                        //06-09-12|0x00ea
        }                                                                                 //06-09-12|0x00ea
        break;                                                                            //06-09-12|0x00ea
//---------------------------------------------------------------------------             //06-09-12|0x00eb
      case 7764: // RECENT_PROJ                                                           //06-09-12|0x00ec
        SourceOutTime = SourceInTime;                                                     //06-09-12|0x00ec
        SourceState = 1043; // OPEN_PROJ                                                  //06-09-12|0x00ec
        break;                                                                            //06-09-12|0x00ec
//---------------------------------------------------------------------------             //06-09-12|0x00ed
      case 1043: // OPEN_PROJ                                                             //10-01-03|0x00ee
        switch(OpenProject)                                                               //10-01-03|0x00ee
        {                                                                                 //10-01-03|0x00ee
          case Success:                                                                   //10-01-03|0x00ee
            SourceRunFlag = 1;                                                            //10-01-03|0x00ee
            SourceState = 17858; // CREATE_MAILBOX                                        //10-01-03|0x00ee
            break;                                                                        //10-01-03|0x00ee
          default:                                                                        //10-01-03|0x00ee
            SourceStatus = SystemError;                                                   //10-01-03|0x00ee
            SourceRunFlag = 0;                                                            //10-01-03|0x00ee
            SystemMsg;                                                                    //10-01-03|0x00ee
            break;                                                                        //10-01-03|0x00ee
        }                                                                                 //10-01-03|0x00ee
        break;                                                                            //10-01-03|0x00ee
//***************************************************************************             //10-01-03|0x00ef
//******                                                               ******             //10-01-03|0x00f0
//****** Create a MailBox control file                                 ******             //10-01-03|0x00f1
//******                                                               ******             //10-01-03|0x00f2
//***************************************************************************             //10-01-03|0x00f3
      case 17858: // CREATE_MAILBOX                                                       //10-01-03|0x00f4
        switch(CreateMailbox)                                                             //10-01-03|0x00f4
        {                                                                                 //10-01-03|0x00f4
          case Success:                                                                   //10-01-03|0x00f4
            SourceRunFlag = 1;                                                            //10-01-03|0x00f4
            SourceState = 41569; // READ_TASK_NO                                          //10-01-03|0x00f4
            break;                                                                        //10-01-03|0x00f4
          default:                                                                        //10-01-03|0x00f4
            SourceStatus = SystemError;                                                   //10-01-03|0x00f4
            SourceRunFlag = 0;                                                            //10-01-03|0x00f4
            SystemMsg;                                                                    //10-01-03|0x00f4
            break;                                                                        //10-01-03|0x00f4
        }                                                                                 //10-01-03|0x00f4
        break;                                                                            //10-01-03|0x00f4
//***************************************************************************             //09-03-27|0x00f5
//******                                                               ******             //09-03-27|0x00f6
//****** Process TASK_NO                                               ******             //09-03-27|0x00f7
//******                                                               ******             //09-03-27|0x00f8
//***************************************************************************             //09-03-27|0x00f9
      case 41569: // READ_TASK_NO                                                         //09-03-27|0x00fa
        switch(ReadProject)                                                               //09-03-27|0x00fa
        {                                                                                 //09-03-27|0x00fa
          case Display:                                                                   //09-03-27|0x00fa
            SourceState = 51440; // READ_TASK_NO_EXIT                                     //09-03-27|0x00fa
            SourceStatus = Display;                                                       //09-03-27|0x00fa
            SourceRunFlag = 0;                                                            //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          case LineDone:                                                                  //09-03-27|0x00fa
            SourceRunFlag = 1;                                                            //09-03-27|0x00fa
            SourceState = 22639; // TASK_NO                                               //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          case FileDone:                                                                  //09-03-27|0x00fa
            SourceRunFlag = 1;                                                            //09-03-27|0x00fa
            SourceState = 57310; // END_FILE                                              //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          case UserError:                                                                 //09-03-27|0x00fa
            SourceRunFlag = 1;                                                            //09-03-27|0x00fa
            SourceState = 56893; // CLOSE_USER                                            //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          default:                                                                        //09-03-27|0x00fa
            SourceStatus = SystemError;                                                   //09-03-27|0x00fa
            SourceRunFlag = 0;                                                            //09-03-27|0x00fa
            SystemMsg;                                                                    //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
        }                                                                                 //09-03-27|0x00fa
        break;                                                                            //09-03-27|0x00fa
//**************************************************************************              //09-03-27|0x00fa
      case 51440: // READ_TASK_NO_EXIT                                                    //09-03-27|0x00fa
        switch(ReadProject)                                                               //09-03-27|0x00fa
        {                                                                                 //09-03-27|0x00fa
          case Display:                                                                   //09-03-27|0x00fa
            SourceState = 51440; // READ_TASK_NO_EXIT                                     //09-03-27|0x00fa
            SourceStatus = Display;                                                       //09-03-27|0x00fa
            SourceRunFlag = 0;                                                            //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          case LineDone:                                                                  //09-03-27|0x00fa
            SourceRunFlag = 1;                                                            //09-03-27|0x00fa
            SourceState = 22639; // TASK_NO                                               //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          case FileDone:                                                                  //09-03-27|0x00fa
            SourceRunFlag = 1;                                                            //09-03-27|0x00fa
            SourceState = 57310; // END_FILE                                              //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          case UserError:                                                                 //09-03-27|0x00fa
            SourceRunFlag = 1;                                                            //09-03-27|0x00fa
            SourceState = 56893; // CLOSE_USER                                            //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
          default:                                                                        //09-03-27|0x00fa
            SourceStatus = SystemError;                                                   //09-03-27|0x00fa
            SourceRunFlag = 0;                                                            //09-03-27|0x00fa
            SystemMsg;                                                                    //09-03-27|0x00fa
            break;                                                                        //09-03-27|0x00fa
        }                                                                                 //09-03-27|0x00fa
        break;                                                                            //09-03-27|0x00fa
//---------------------------------------------------------------------------             //09-03-27|0x00fb
      case 22639: // TASK_NO                                                              //09-03-27|0x00fc
        switch(CmdTest("_TASK_NO"))                                                       //09-03-27|0x00fc
        {                                                                                 //09-03-27|0x00fc
          case -1:                                                                        //09-03-27|0x00fc
            SourceRunFlag = 1;                                                            //09-03-27|0x00fc
            SourceState = 49804; // COMMAND_ERROR                                         //09-03-27|0x00fc
            break;                                                                        //09-03-27|0x00fc
          case 0:                                                                         //09-03-27|0x00fc
            SourceRunFlag = 1;                                                            //09-03-27|0x00fc
            SourceState = 60363; // TASK_NUMBER                                           //09-03-27|0x00fc
            break;                                                                        //09-03-27|0x00fc
          case 1:                                                                         //09-03-27|0x00fc
            SourceRunFlag = 1;                                                            //09-03-27|0x00fc
            SourceState = 49804; // COMMAND_ERROR                                         //09-03-27|0x00fc
            break;                                                                        //09-03-27|0x00fc
          default:                                                                        //09-03-27|0x00fc
            SourceStatus = SystemError;                                                   //09-03-27|0x00fc
            SourceRunFlag = 0;                                                            //09-03-27|0x00fc
            SystemMsg;                                                                    //09-03-27|0x00fc
            break;                                                                        //09-03-27|0x00fc
        }                                                                                 //09-03-27|0x00fc
        break;                                                                            //09-03-27|0x00fc
//---------------------------------------------------------------------------             //09-03-27|0x00fd
      case 60363: // TASK_NUMBER                                                          //09-03-27|0x00fe
        switch(text_prepare())                                                            //09-03-27|0x00fe
        {                                                                                 //09-03-27|0x00fe
          case Success:                                                                   //09-03-27|0x00fe
            SourceRunFlag = 1;                                                            //09-03-27|0x00fe
            SourceState = 43258; // LOAD_TASK_NO                                          //09-03-27|0x00fe
            break;                                                                        //09-03-27|0x00fe
          case UserError:                                                                 //09-03-27|0x00fe
            SourceRunFlag = 1;                                                            //09-03-27|0x00fe
            SourceState = 56893; // CLOSE_USER                                            //09-03-27|0x00fe
            break;                                                                        //09-03-27|0x00fe
          default:                                                                        //09-03-27|0x00fe
            SourceStatus = SystemError;                                                   //09-03-27|0x00fe
            SourceRunFlag = 0;                                                            //09-03-27|0x00fe
            SystemMsg;                                                                    //09-03-27|0x00fe
            break;                                                                        //09-03-27|0x00fe
        }                                                                                 //09-03-27|0x00fe
        break;                                                                            //09-03-27|0x00fe
//---------------------------------------------------------------------------             //09-03-27|0x00ff
      case 43258: // LOAD_TASK_NO                                                         //09-03-27|0x0100
        switch(UpdateTaskNo)                                                              //09-03-27|0x0100
        {                                                                                 //09-03-27|0x0100
          case Success:                                                                   //09-03-27|0x0100
            SourceRunFlag = 1;                                                            //09-03-27|0x0100
            SourceState = 14617; // READ_UPDATE                                           //09-03-27|0x0100
            break;                                                                        //09-03-27|0x0100
          case UserError:                                                                 //09-03-27|0x0100
            SourceRunFlag = 1;                                                            //09-03-27|0x0100
            SourceState = 56893; // CLOSE_USER                                            //09-03-27|0x0100
            break;                                                                        //09-03-27|0x0100
          default:                                                                        //09-03-27|0x0100
            SourceStatus = SystemError;                                                   //09-03-27|0x0100
            SourceRunFlag = 0;                                                            //09-03-27|0x0100
            SystemMsg;                                                                    //09-03-27|0x0100
            break;                                                                        //09-03-27|0x0100
        }                                                                                 //09-03-27|0x0100
        break;                                                                            //09-03-27|0x0100
//***************************************************************************             //06-09-13|0x0101
//******                                                               ******             //06-09-13|0x0102
//****** Process update command                                        ******             //06-09-13|0x0103
//******                                                               ******             //06-09-13|0x0104
//***************************************************************************             //06-09-13|0x0105
      case 14617: // READ_UPDATE                                                          //07-03-23|0x0106
        switch(ReadProject)                                                               //07-03-23|0x0106
        {                                                                                 //07-03-23|0x0106
          case Display:                                                                   //07-03-23|0x0106
            SourceState = 52008; // READ_UPDATE_EXIT                                      //07-03-23|0x0106
            SourceStatus = Display;                                                       //07-03-23|0x0106
            SourceRunFlag = 0;                                                            //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          case LineDone:                                                                  //07-03-23|0x0106
            SourceRunFlag = 1;                                                            //07-03-23|0x0106
            SourceState = 32295; // UPDATE                                                //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          case FileDone:                                                                  //07-03-23|0x0106
            SourceRunFlag = 1;                                                            //07-03-23|0x0106
            SourceState = 57310; // END_FILE                                              //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          case UserError:                                                                 //07-03-23|0x0106
            SourceRunFlag = 1;                                                            //07-03-23|0x0106
            SourceState = 56893; // CLOSE_USER                                            //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          default:                                                                        //07-03-23|0x0106
            SourceStatus = SystemError;                                                   //07-03-23|0x0106
            SourceRunFlag = 0;                                                            //07-03-23|0x0106
            SystemMsg;                                                                    //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
        }                                                                                 //07-03-23|0x0106
        break;                                                                            //07-03-23|0x0106
//**************************************************************************              //07-03-23|0x0106
      case 52008: // READ_UPDATE_EXIT                                                     //07-03-23|0x0106
        switch(ReadProject)                                                               //07-03-23|0x0106
        {                                                                                 //07-03-23|0x0106
          case Display:                                                                   //07-03-23|0x0106
            SourceState = 52008; // READ_UPDATE_EXIT                                      //07-03-23|0x0106
            SourceStatus = Display;                                                       //07-03-23|0x0106
            SourceRunFlag = 0;                                                            //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          case LineDone:                                                                  //07-03-23|0x0106
            SourceRunFlag = 1;                                                            //07-03-23|0x0106
            SourceState = 32295; // UPDATE                                                //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          case FileDone:                                                                  //07-03-23|0x0106
            SourceRunFlag = 1;                                                            //07-03-23|0x0106
            SourceState = 57310; // END_FILE                                              //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          case UserError:                                                                 //07-03-23|0x0106
            SourceRunFlag = 1;                                                            //07-03-23|0x0106
            SourceState = 56893; // CLOSE_USER                                            //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
          default:                                                                        //07-03-23|0x0106
            SourceStatus = SystemError;                                                   //07-03-23|0x0106
            SourceRunFlag = 0;                                                            //07-03-23|0x0106
            SystemMsg;                                                                    //07-03-23|0x0106
            break;                                                                        //07-03-23|0x0106
        }                                                                                 //07-03-23|0x0106
        break;                                                                            //07-03-23|0x0106
//---------------------------------------------------------------------------             //07-03-23|0x0107
      case 32295: // UPDATE                                                               //08-04-17|0x0108
        switch(CmdTest("_UPDATE"))                                                        //08-04-17|0x0108
        {                                                                                 //08-04-17|0x0108
          case -1:                                                                        //08-04-17|0x0108
            SourceRunFlag = 1;                                                            //08-04-17|0x0108
            SourceState = 24854; // LIBRARY                                               //08-04-17|0x0108
            break;                                                                        //08-04-17|0x0108
          case 0:                                                                         //08-04-17|0x0108
            SourceRunFlag = 1;                                                            //08-04-17|0x0108
            SourceState = 29429; // INITIAL_DISPLAY                                       //08-04-17|0x0108
            break;                                                                        //08-04-17|0x0108
          case 1:                                                                         //08-04-17|0x0108
            SourceRunFlag = 1;                                                            //08-04-17|0x0108
            SourceState = 24854; // LIBRARY                                               //08-04-17|0x0108
            break;                                                                        //08-04-17|0x0108
          default:                                                                        //08-04-17|0x0108
            SourceStatus = SystemError;                                                   //08-04-17|0x0108
            SourceRunFlag = 0;                                                            //08-04-17|0x0108
            SystemMsg;                                                                    //08-04-17|0x0108
            break;                                                                        //08-04-17|0x0108
        }                                                                                 //08-04-17|0x0108
        break;                                                                            //08-04-17|0x0108
//---------------------------------------------------------------------------             //08-04-17|0x0109
      case 29429: // INITIAL_DISPLAY                                                      //08-04-17|0x010a
        if(display_flag) DisplayOn();                                                     //08-04-17|0x010a
        SourceState = 41668; // DISABLE_DISPLAY_CONT                                      //08-04-17|0x010a
        break;                                                                            //08-04-17|0x010a
//---------------------------------------------------------------------------             //08-04-17|0x010b
      case 41668: // DISABLE_DISPLAY_CONT                                                 //08-04-17|0x010c
        display_flag = 0;                                                                 //08-04-17|0x010c
        SourceState = 53123; // SET_UPDATE_TIME                                           //08-04-17|0x010c
        break;                                                                            //08-04-17|0x010c
//---------------------------------------------------------------------------             //07-03-23|0x010d
      case 53123: // SET_UPDATE_TIME                                                      //07-03-23|0x010e
        switch(uncond_update())                                                           //07-03-23|0x010e
        {                                                                                 //07-03-23|0x010e
          case Success:                                                                   //07-03-23|0x010e
            SourceRunFlag = 1;                                                            //07-03-23|0x010e
            SourceState = 51250; // READ_LIB_NAME                                         //07-03-23|0x010e
            break;                                                                        //07-03-23|0x010e
          case UserError:                                                                 //07-03-23|0x010e
            SourceRunFlag = 1;                                                            //07-03-23|0x010e
            SourceState = 50565; // USER_ERROR                                            //07-03-23|0x010e
            break;                                                                        //07-03-23|0x010e
          default:                                                                        //07-03-23|0x010e
            SourceStatus = SystemError;                                                   //07-03-23|0x010e
            SourceRunFlag = 0;                                                            //07-03-23|0x010e
            SystemMsg;                                                                    //07-03-23|0x010e
            break;                                                                        //07-03-23|0x010e
        }                                                                                 //07-03-23|0x010e
        break;                                                                            //07-03-23|0x010e
//***************************************************************************             //06-09-12|0x010f
//******                                                               ******             //06-09-12|0x0110
//****** Process Library                                               ******             //06-09-12|0x0111
//******                                                               ******             //06-09-12|0x0112
//***************************************************************************             //06-09-12|0x0113
      case 51250: // READ_LIB_NAME                                                        //06-09-12|0x0114
        switch(ReadProject)                                                               //06-09-12|0x0114
        {                                                                                 //06-09-12|0x0114
          case Display:                                                                   //06-09-12|0x0114
            SourceState = 19409; // READ_LIB_NAME_EXIT                                    //06-09-12|0x0114
            SourceStatus = Display;                                                       //06-09-12|0x0114
            SourceRunFlag = 0;                                                            //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          case LineDone:                                                                  //06-09-12|0x0114
            SourceRunFlag = 1;                                                            //06-09-12|0x0114
            SourceState = 24854; // LIBRARY                                               //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          case FileDone:                                                                  //06-09-12|0x0114
            SourceRunFlag = 1;                                                            //06-09-12|0x0114
            SourceState = 57310; // END_FILE                                              //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          case UserError:                                                                 //06-09-12|0x0114
            SourceRunFlag = 1;                                                            //06-09-12|0x0114
            SourceState = 56893; // CLOSE_USER                                            //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          default:                                                                        //06-09-12|0x0114
            SourceStatus = SystemError;                                                   //06-09-12|0x0114
            SourceRunFlag = 0;                                                            //06-09-12|0x0114
            SystemMsg;                                                                    //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
        }                                                                                 //06-09-12|0x0114
        break;                                                                            //06-09-12|0x0114
//**************************************************************************              //06-09-12|0x0114
      case 19409: // READ_LIB_NAME_EXIT                                                   //06-09-12|0x0114
        switch(ReadProject)                                                               //06-09-12|0x0114
        {                                                                                 //06-09-12|0x0114
          case Display:                                                                   //06-09-12|0x0114
            SourceState = 19409; // READ_LIB_NAME_EXIT                                    //06-09-12|0x0114
            SourceStatus = Display;                                                       //06-09-12|0x0114
            SourceRunFlag = 0;                                                            //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          case LineDone:                                                                  //06-09-12|0x0114
            SourceRunFlag = 1;                                                            //06-09-12|0x0114
            SourceState = 24854; // LIBRARY                                               //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          case FileDone:                                                                  //06-09-12|0x0114
            SourceRunFlag = 1;                                                            //06-09-12|0x0114
            SourceState = 57310; // END_FILE                                              //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          case UserError:                                                                 //06-09-12|0x0114
            SourceRunFlag = 1;                                                            //06-09-12|0x0114
            SourceState = 56893; // CLOSE_USER                                            //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
          default:                                                                        //06-09-12|0x0114
            SourceStatus = SystemError;                                                   //06-09-12|0x0114
            SourceRunFlag = 0;                                                            //06-09-12|0x0114
            SystemMsg;                                                                    //06-09-12|0x0114
            break;                                                                        //06-09-12|0x0114
        }                                                                                 //06-09-12|0x0114
        break;                                                                            //06-09-12|0x0114
//---------------------------------------------------------------------------             //06-09-12|0x0115
      case 24854: // LIBRARY                                                              //06-09-12|0x0116
        switch(CmdTest("_LIBRARY"))                                                       //06-09-12|0x0116
        {                                                                                 //06-09-12|0x0116
          case -1:                                                                        //06-09-12|0x0116
            SourceRunFlag = 1;                                                            //06-09-12|0x0116
            SourceState = 49804; // COMMAND_ERROR                                         //06-09-12|0x0116
            break;                                                                        //06-09-12|0x0116
          case 0:                                                                         //06-09-12|0x0116
            SourceRunFlag = 1;                                                            //06-09-12|0x0116
            SourceState = 2400; // LIB_NAME                                               //06-09-12|0x0116
            break;                                                                        //06-09-12|0x0116
          case 1:                                                                         //06-09-12|0x0116
            SourceRunFlag = 1;                                                            //06-09-12|0x0116
            SourceState = 49804; // COMMAND_ERROR                                         //06-09-12|0x0116
            break;                                                                        //06-09-12|0x0116
          default:                                                                        //06-09-12|0x0116
            SourceStatus = SystemError;                                                   //06-09-12|0x0116
            SourceRunFlag = 0;                                                            //06-09-12|0x0116
            SystemMsg;                                                                    //06-09-12|0x0116
            break;                                                                        //06-09-12|0x0116
        }                                                                                 //06-09-12|0x0116
        break;                                                                            //06-09-12|0x0116
//---------------------------------------------------------------------------             //06-09-12|0x0117
      case 2400: // LIB_NAME                                                              //06-09-12|0x0118
        switch(text_prepare())                                                            //06-09-12|0x0118
        {                                                                                 //06-09-12|0x0118
          case Success:                                                                   //06-09-12|0x0118
            SourceRunFlag = 1;                                                            //06-09-12|0x0118
            SourceState = 40927; // LOAD_LIB_NAME                                         //06-09-12|0x0118
            break;                                                                        //06-09-12|0x0118
          case UserError:                                                                 //06-09-12|0x0118
            SourceRunFlag = 1;                                                            //06-09-12|0x0118
            SourceState = 56893; // CLOSE_USER                                            //06-09-12|0x0118
            break;                                                                        //06-09-12|0x0118
          default:                                                                        //06-09-12|0x0118
            SourceStatus = SystemError;                                                   //06-09-12|0x0118
            SourceRunFlag = 0;                                                            //06-09-12|0x0118
            SystemMsg;                                                                    //06-09-12|0x0118
            break;                                                                        //06-09-12|0x0118
        }                                                                                 //06-09-12|0x0118
        break;                                                                            //06-09-12|0x0118
//---------------------------------------------------------------------------             //06-09-12|0x0119
      case 40927: // LOAD_LIB_NAME                                                        //06-09-12|0x011a
        switch(EnterLibraryName)                                                          //06-09-12|0x011a
        {                                                                                 //06-09-12|0x011a
          case Success:                                                                   //06-09-12|0x011a
            SourceRunFlag = 1;                                                            //06-09-12|0x011a
            SourceState = 40526; // LIB_DATE                                              //06-09-12|0x011a
            break;                                                                        //06-09-12|0x011a
          default:                                                                        //06-09-12|0x011a
            SourceStatus = SystemError;                                                   //06-09-12|0x011a
            SourceRunFlag = 0;                                                            //06-09-12|0x011a
            SystemMsg;                                                                    //06-09-12|0x011a
            break;                                                                        //06-09-12|0x011a
        }                                                                                 //06-09-12|0x011a
        break;                                                                            //06-09-12|0x011a
//---------------------------------------------------------------------------             //06-09-12|0x011b
      case 40526: // LIB_DATE                                                             //06-09-12|0x011c
        switch(LibraryDate)                                                               //06-09-12|0x011c
        {                                                                                 //06-09-12|0x011c
          case Success:                                                                   //06-09-12|0x011c
            SourceRunFlag = 1;                                                            //06-09-12|0x011c
            SourceState = 33709; // LIB_EXISTS                                            //06-09-12|0x011c
            break;                                                                        //06-09-12|0x011c
          default:                                                                        //06-09-12|0x011c
            SourceStatus = SystemError;                                                   //06-09-12|0x011c
            SourceRunFlag = 0;                                                            //06-09-12|0x011c
            SystemMsg;                                                                    //06-09-12|0x011c
            break;                                                                        //06-09-12|0x011c
        }                                                                                 //06-09-12|0x011c
        break;                                                                            //06-09-12|0x011c
//---------------------------------------------------------------------------             //06-09-12|0x011d
      case 33709: // LIB_EXISTS                                                           //06-09-12|0x011e
        switch(FileDateExists)                                                            //06-09-12|0x011e
        {                                                                                 //06-09-12|0x011e
          case Yes:                                                                       //06-09-12|0x011e
            SourceRunFlag = 1;                                                            //06-09-12|0x011e
            SourceState = 48892; // LIB_RECENT                                            //06-09-12|0x011e
            break;                                                                        //06-09-12|0x011e
          case No:                                                                        //06-09-12|0x011e
            SourceRunFlag = 1;                                                            //06-09-12|0x011e
            SourceState = 44859; // NO_LIBRARY                                            //06-09-12|0x011e
            break;                                                                        //06-09-12|0x011e
          default:                                                                        //06-09-12|0x011e
            SourceStatus = SystemError;                                                   //06-09-12|0x011e
            SourceRunFlag = 0;                                                            //06-09-12|0x011e
            SystemMsg;                                                                    //06-09-12|0x011e
            break;                                                                        //06-09-12|0x011e
        }                                                                                 //06-09-12|0x011e
        break;                                                                            //06-09-12|0x011e
//---------------------------------------------------------------------------             //06-09-12|0x011f
      case 44859: // NO_LIBRARY                                                           //06-09-12|0x0120
        switch(LibraryDoesNotExist)                                                       //06-09-12|0x0120
        {                                                                                 //06-09-12|0x0120
          case UserError:                                                                 //06-09-12|0x0120
            SourceRunFlag = 1;                                                            //06-09-12|0x0120
            SourceState = 56893; // CLOSE_USER                                            //06-09-12|0x0120
            break;                                                                        //06-09-12|0x0120
          default:                                                                        //06-09-12|0x0120
            SourceStatus = SystemError;                                                   //06-09-12|0x0120
            SourceRunFlag = 0;                                                            //06-09-12|0x0120
            SystemMsg;                                                                    //06-09-12|0x0120
            break;                                                                        //06-09-12|0x0120
        }                                                                                 //06-09-12|0x0120
        break;                                                                            //06-09-12|0x0120
//---------------------------------------------------------------------------             //06-09-12|0x0121
      case 48892: // LIB_RECENT                                                           //06-09-13|0x0122
        switch(FileDateRecent)                                                            //06-09-13|0x0122
        {                                                                                 //06-09-13|0x0122
          case 1:                                                                         //06-09-13|0x0122
            SourceRunFlag = 1;                                                            //06-09-13|0x0122
            SourceState = 41834; // RECENT_LIB                                            //06-09-13|0x0122
            break;                                                                        //06-09-13|0x0122
          case 0:                                                                         //06-09-13|0x0122
            SourceRunFlag = 1;                                                            //06-09-13|0x0122
            SourceState = 55945; // OPEN_LIB                                              //06-09-13|0x0122
            break;                                                                        //06-09-13|0x0122
          case -1:                                                                        //06-09-13|0x0122
            SourceRunFlag = 1;                                                            //06-09-13|0x0122
            SourceState = 55945; // OPEN_LIB                                              //06-09-13|0x0122
            break;                                                                        //06-09-13|0x0122
          default:                                                                        //06-09-13|0x0122
            SourceStatus = SystemError;                                                   //06-09-13|0x0122
            SourceRunFlag = 0;                                                            //06-09-13|0x0122
            SystemMsg;                                                                    //06-09-13|0x0122
            break;                                                                        //06-09-13|0x0122
        }                                                                                 //06-09-13|0x0122
        break;                                                                            //06-09-13|0x0122
//---------------------------------------------------------------------------             //06-09-13|0x0123
      case 41834: // RECENT_LIB                                                           //06-09-13|0x0124
        SourceOutTime = SourceInTime;                                                     //06-09-13|0x0124
        SourceState = 55945; // OPEN_LIB                                                  //06-09-13|0x0124
        break;                                                                            //06-09-13|0x0124
//---------------------------------------------------------------------------             //06-09-13|0x0125
      case 55945: // OPEN_LIB                                                             //06-09-13|0x0126
        switch(open_library())                                                            //06-09-13|0x0126
        {                                                                                 //06-09-13|0x0126
          case Success:                                                                   //06-09-13|0x0126
            SourceRunFlag = 1;                                                            //06-09-13|0x0126
            SourceState = 33688; // READ_ERROR_CONT                                       //06-09-13|0x0126
            break;                                                                        //06-09-13|0x0126
          case UserError:                                                                 //06-09-13|0x0126
            SourceRunFlag = 1;                                                            //06-09-13|0x0126
            SourceState = 56893; // CLOSE_USER                                            //06-09-13|0x0126
            break;                                                                        //06-09-13|0x0126
          default:                                                                        //06-09-13|0x0126
            SourceStatus = SystemError;                                                   //06-09-13|0x0126
            SourceRunFlag = 0;                                                            //06-09-13|0x0126
            SystemMsg;                                                                    //06-09-13|0x0126
            break;                                                                        //06-09-13|0x0126
        }                                                                                 //06-09-13|0x0126
        break;                                                                            //06-09-13|0x0126
//***************************************************************************             //07-06-06|0x0127
//******                                                               ******             //07-06-06|0x0128
//****** Process Error Control Options                                 ******             //07-06-06|0x0129
//******                                                               ******             //07-06-06|0x012a
//***************************************************************************             //07-06-06|0x012b
      case 33688: // READ_ERROR_CONT                                                      //07-06-06|0x012c
        switch(ReadProject)                                                               //07-06-06|0x012c
        {                                                                                 //07-06-06|0x012c
          case Display:                                                                   //07-06-06|0x012c
            SourceState = 48535; // READ_ERROR_CONT_EXIT                                  //07-06-06|0x012c
            SourceStatus = Display;                                                       //07-06-06|0x012c
            SourceRunFlag = 0;                                                            //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          case LineDone:                                                                  //07-06-06|0x012c
            SourceRunFlag = 1;                                                            //07-06-06|0x012c
            SourceState = 38790; // NORMAL_ERR                                            //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          case FileDone:                                                                  //07-06-06|0x012c
            SourceRunFlag = 1;                                                            //07-06-06|0x012c
            SourceState = 4197; // END_LIB                                                //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          case UserError:                                                                 //07-06-06|0x012c
            SourceRunFlag = 1;                                                            //07-06-06|0x012c
            SourceState = 5940; // CLS_LIB_USER                                           //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          default:                                                                        //07-06-06|0x012c
            SourceStatus = SystemError;                                                   //07-06-06|0x012c
            SourceRunFlag = 0;                                                            //07-06-06|0x012c
            SystemMsg;                                                                    //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
        }                                                                                 //07-06-06|0x012c
        break;                                                                            //07-06-06|0x012c
//**************************************************************************              //07-06-06|0x012c
      case 48535: // READ_ERROR_CONT_EXIT                                                 //07-06-06|0x012c
        switch(ReadProject)                                                               //07-06-06|0x012c
        {                                                                                 //07-06-06|0x012c
          case Display:                                                                   //07-06-06|0x012c
            SourceState = 48535; // READ_ERROR_CONT_EXIT                                  //07-06-06|0x012c
            SourceStatus = Display;                                                       //07-06-06|0x012c
            SourceRunFlag = 0;                                                            //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          case LineDone:                                                                  //07-06-06|0x012c
            SourceRunFlag = 1;                                                            //07-06-06|0x012c
            SourceState = 38790; // NORMAL_ERR                                            //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          case FileDone:                                                                  //07-06-06|0x012c
            SourceRunFlag = 1;                                                            //07-06-06|0x012c
            SourceState = 4197; // END_LIB                                                //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          case UserError:                                                                 //07-06-06|0x012c
            SourceRunFlag = 1;                                                            //07-06-06|0x012c
            SourceState = 5940; // CLS_LIB_USER                                           //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
          default:                                                                        //07-06-06|0x012c
            SourceStatus = SystemError;                                                   //07-06-06|0x012c
            SourceRunFlag = 0;                                                            //07-06-06|0x012c
            SystemMsg;                                                                    //07-06-06|0x012c
            break;                                                                        //07-06-06|0x012c
        }                                                                                 //07-06-06|0x012c
        break;                                                                            //07-06-06|0x012c
//---------------------------------------------------------------------------             //07-06-06|0x012d
      case 38790: // NORMAL_ERR                                                           //07-06-06|0x012e
        switch(DefaultError)                                                              //07-06-06|0x012e
        {                                                                                 //07-06-06|0x012e
          case Yes:                                                                       //07-06-06|0x012e
            SourceRunFlag = 1;                                                            //07-06-06|0x012e
            SourceState = 35571; // READ_SRCE_EXT                                         //07-06-06|0x012e
            break;                                                                        //07-06-06|0x012e
          case No:                                                                        //07-06-06|0x012e
            SourceRunFlag = 1;                                                            //07-06-06|0x012e
            SourceState = 15010; // ERR_USER                                              //07-06-06|0x012e
            break;                                                                        //07-06-06|0x012e
          case UserError:                                                                 //07-06-06|0x012e
            SourceRunFlag = 1;                                                            //07-06-06|0x012e
            SourceState = 5940; // CLS_LIB_USER                                           //07-06-06|0x012e
            break;                                                                        //07-06-06|0x012e
          default:                                                                        //07-06-06|0x012e
            SourceStatus = SystemError;                                                   //07-06-06|0x012e
            SourceRunFlag = 0;                                                            //07-06-06|0x012e
            SystemMsg;                                                                    //07-06-06|0x012e
            break;                                                                        //07-06-06|0x012e
        }                                                                                 //07-06-06|0x012e
        break;                                                                            //07-06-06|0x012e
//---------------------------------------------------------------------------             //07-06-06|0x012f
      case 15010: // ERR_USER                                                             //07-06-06|0x0130
        switch(ErrorToUser)                                                               //07-06-06|0x0130
        {                                                                                 //07-06-06|0x0130
          case Yes:                                                                       //07-06-06|0x0130
            SourceRunFlag = 1;                                                            //07-06-06|0x0130
            SourceState = 35571; // READ_SRCE_EXT                                         //07-06-06|0x0130
            break;                                                                        //07-06-06|0x0130
          case No:                                                                        //07-06-06|0x0130
            SourceRunFlag = 1;                                                            //07-06-06|0x0130
            SourceState = 58689; // ERR_BUILD                                             //07-06-06|0x0130
            break;                                                                        //07-06-06|0x0130
          case UserError:                                                                 //07-06-06|0x0130
            SourceRunFlag = 1;                                                            //07-06-06|0x0130
            SourceState = 5940; // CLS_LIB_USER                                           //07-06-06|0x0130
            break;                                                                        //07-06-06|0x0130
          default:                                                                        //07-06-06|0x0130
            SourceStatus = SystemError;                                                   //07-06-06|0x0130
            SourceRunFlag = 0;                                                            //07-06-06|0x0130
            SystemMsg;                                                                    //07-06-06|0x0130
            break;                                                                        //07-06-06|0x0130
        }                                                                                 //07-06-06|0x0130
        break;                                                                            //07-06-06|0x0130
//---------------------------------------------------------------------------             //07-06-06|0x0131
      case 58689: // ERR_BUILD                                                            //07-06-06|0x0132
        switch(ErrorToBuild)                                                              //07-06-06|0x0132
        {                                                                                 //07-06-06|0x0132
          case Yes:                                                                       //07-06-06|0x0132
            SourceRunFlag = 1;                                                            //07-06-06|0x0132
            SourceState = 35571; // READ_SRCE_EXT                                         //07-06-06|0x0132
            break;                                                                        //07-06-06|0x0132
          case No:                                                                        //07-06-06|0x0132
            SourceRunFlag = 1;                                                            //07-06-06|0x0132
            SourceState = 14800; // CMND_LIB_ERR                                          //07-06-06|0x0132
            break;                                                                        //07-06-06|0x0132
          case UserError:                                                                 //07-06-06|0x0132
            SourceRunFlag = 1;                                                            //07-06-06|0x0132
            SourceState = 5940; // CLS_LIB_USER                                           //07-06-06|0x0132
            break;                                                                        //07-06-06|0x0132
          default:                                                                        //07-06-06|0x0132
            SourceStatus = SystemError;                                                   //07-06-06|0x0132
            SourceRunFlag = 0;                                                            //07-06-06|0x0132
            SystemMsg;                                                                    //07-06-06|0x0132
            break;                                                                        //07-06-06|0x0132
        }                                                                                 //07-06-06|0x0132
        break;                                                                            //07-06-06|0x0132
//***************************************************************************             //06-09-13|0x0133
//******                                                               ******             //06-09-13|0x0134
//****** Process input files                                           ******             //10-06-11|0x0135
//******---------------------------------------------------------------******             //10-06-11|0x0136
//****** Process source extent                                         ******             //06-09-13|0x0137
//******                                                               ******             //06-09-13|0x0138
//***************************************************************************             //06-09-13|0x0139
      case 35571: // READ_SRCE_EXT                                                        //06-09-13|0x013a
        switch(ReadProject)                                                               //06-09-13|0x013a
        {                                                                                 //06-09-13|0x013a
          case Display:                                                                   //06-09-13|0x013a
            SourceState = 55119; // READ_SRCE_EXT_EXIT                                    //06-09-13|0x013a
            SourceStatus = Display;                                                       //06-09-13|0x013a
            SourceRunFlag = 0;                                                            //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          case LineDone:                                                                  //06-09-13|0x013a
            SourceRunFlag = 1;                                                            //06-09-13|0x013a
            SourceState = 19646; // SOURCE_EXTENT                                         //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          case FileDone:                                                                  //06-09-13|0x013a
            SourceRunFlag = 1;                                                            //06-09-13|0x013a
            SourceState = 4197; // END_LIB                                                //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          case UserError:                                                                 //06-09-13|0x013a
            SourceRunFlag = 1;                                                            //06-09-13|0x013a
            SourceState = 5940; // CLS_LIB_USER                                           //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          default:                                                                        //06-09-13|0x013a
            SourceStatus = SystemError;                                                   //06-09-13|0x013a
            SourceRunFlag = 0;                                                            //06-09-13|0x013a
            SystemMsg;                                                                    //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
        }                                                                                 //06-09-13|0x013a
        break;                                                                            //06-09-13|0x013a
//**************************************************************************              //06-09-13|0x013a
      case 55119: // READ_SRCE_EXT_EXIT                                                   //06-09-13|0x013a
        switch(ReadProject)                                                               //06-09-13|0x013a
        {                                                                                 //06-09-13|0x013a
          case Display:                                                                   //06-09-13|0x013a
            SourceState = 55119; // READ_SRCE_EXT_EXIT                                    //06-09-13|0x013a
            SourceStatus = Display;                                                       //06-09-13|0x013a
            SourceRunFlag = 0;                                                            //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          case LineDone:                                                                  //06-09-13|0x013a
            SourceRunFlag = 1;                                                            //06-09-13|0x013a
            SourceState = 19646; // SOURCE_EXTENT                                         //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          case FileDone:                                                                  //06-09-13|0x013a
            SourceRunFlag = 1;                                                            //06-09-13|0x013a
            SourceState = 4197; // END_LIB                                                //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          case UserError:                                                                 //06-09-13|0x013a
            SourceRunFlag = 1;                                                            //06-09-13|0x013a
            SourceState = 5940; // CLS_LIB_USER                                           //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
          default:                                                                        //06-09-13|0x013a
            SourceStatus = SystemError;                                                   //06-09-13|0x013a
            SourceRunFlag = 0;                                                            //06-09-13|0x013a
            SystemMsg;                                                                    //06-09-13|0x013a
            break;                                                                        //06-09-13|0x013a
        }                                                                                 //06-09-13|0x013a
        break;                                                                            //06-09-13|0x013a
//---------------------------------------------------------------------------             //06-09-13|0x013b
      case 19646: // SOURCE_EXTENT                                                        //06-09-13|0x013c
        switch(CmdTest("_SOURCE_EXTENT"))                                                 //06-09-13|0x013c
        {                                                                                 //06-09-13|0x013c
          case -1:                                                                        //06-09-13|0x013c
            SourceRunFlag = 1;                                                            //06-09-13|0x013c
            SourceState = 14800; // CMND_LIB_ERR                                          //06-09-13|0x013c
            break;                                                                        //06-09-13|0x013c
          case 0:                                                                         //06-09-13|0x013c
            SourceRunFlag = 1;                                                            //06-09-13|0x013c
            SourceState = 6429; // LOAD_SRCE_EXT                                          //06-09-13|0x013c
            break;                                                                        //06-09-13|0x013c
          case 1:                                                                         //06-09-13|0x013c
            SourceRunFlag = 1;                                                            //06-09-13|0x013c
            SourceState = 14800; // CMND_LIB_ERR                                          //06-09-13|0x013c
            break;                                                                        //06-09-13|0x013c
          default:                                                                        //06-09-13|0x013c
            SourceStatus = SystemError;                                                   //06-09-13|0x013c
            SourceRunFlag = 0;                                                            //06-09-13|0x013c
            SystemMsg;                                                                    //06-09-13|0x013c
            break;                                                                        //06-09-13|0x013c
        }                                                                                 //06-09-13|0x013c
        break;                                                                            //06-09-13|0x013c
//---------------------------------------------------------------------------             //06-09-13|0x013d
      case 6429: // LOAD_SRCE_EXT                                                         //09-03-10|0x013e
        switch(load_srce_extent())                                                        //09-03-10|0x013e
        {                                                                                 //09-03-10|0x013e
          case Success:                                                                   //09-03-10|0x013e
            SourceRunFlag = 1;                                                            //09-03-10|0x013e
            SourceState = 43884; // READ_TEXT_EXTENT                                      //09-03-10|0x013e
            break;                                                                        //09-03-10|0x013e
          case UserError:                                                                 //09-03-10|0x013e
            SourceRunFlag = 1;                                                            //09-03-10|0x013e
            SourceState = 5940; // CLS_LIB_USER                                           //09-03-10|0x013e
            break;                                                                        //09-03-10|0x013e
          default:                                                                        //09-03-10|0x013e
            SourceStatus = SystemError;                                                   //09-03-10|0x013e
            SourceRunFlag = 0;                                                            //09-03-10|0x013e
            SystemMsg;                                                                    //09-03-10|0x013e
            break;                                                                        //09-03-10|0x013e
        }                                                                                 //09-03-10|0x013e
        break;                                                                            //09-03-10|0x013e
//***************************************************************************             //09-03-10|0x013f
//******                                                               ******             //09-03-10|0x0140
//****** Process input files                                           ******             //10-06-11|0x0141
//******---------------------------------------------------------------******             //10-06-11|0x0142
//****** Process optional text extent                                  ******             //09-03-10|0x0143
//******                                                               ******             //09-03-10|0x0144
//***************************************************************************             //09-03-10|0x0145
      case 43884: // READ_TEXT_EXTENT                                                     //10-05-15|0x0146
        switch(ReadProject)                                                               //10-05-15|0x0146
        {                                                                                 //10-05-15|0x0146
          case Display:                                                                   //10-05-15|0x0146
            SourceState = 25259; // READ_TEXT_EXTENT_EXIT                                 //10-05-15|0x0146
            SourceStatus = Display;                                                       //10-05-15|0x0146
            SourceRunFlag = 0;                                                            //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          case LineDone:                                                                  //10-05-15|0x0146
            SourceRunFlag = 1;                                                            //10-05-15|0x0146
            SourceState = 36314; // TEXT_EXTENT                                           //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          case FileDone:                                                                  //10-05-15|0x0146
            SourceRunFlag = 1;                                                            //10-05-15|0x0146
            SourceState = 4197; // END_LIB                                                //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          case UserError:                                                                 //10-05-15|0x0146
            SourceRunFlag = 1;                                                            //10-05-15|0x0146
            SourceState = 5940; // CLS_LIB_USER                                           //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          default:                                                                        //10-05-15|0x0146
            SourceStatus = SystemError;                                                   //10-05-15|0x0146
            SourceRunFlag = 0;                                                            //10-05-15|0x0146
            SystemMsg;                                                                    //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
        }                                                                                 //10-05-15|0x0146
        break;                                                                            //10-05-15|0x0146
//**************************************************************************              //10-05-15|0x0146
      case 25259: // READ_TEXT_EXTENT_EXIT                                                //10-05-15|0x0146
        switch(ReadProject)                                                               //10-05-15|0x0146
        {                                                                                 //10-05-15|0x0146
          case Display:                                                                   //10-05-15|0x0146
            SourceState = 25259; // READ_TEXT_EXTENT_EXIT                                 //10-05-15|0x0146
            SourceStatus = Display;                                                       //10-05-15|0x0146
            SourceRunFlag = 0;                                                            //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          case LineDone:                                                                  //10-05-15|0x0146
            SourceRunFlag = 1;                                                            //10-05-15|0x0146
            SourceState = 36314; // TEXT_EXTENT                                           //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          case FileDone:                                                                  //10-05-15|0x0146
            SourceRunFlag = 1;                                                            //10-05-15|0x0146
            SourceState = 4197; // END_LIB                                                //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          case UserError:                                                                 //10-05-15|0x0146
            SourceRunFlag = 1;                                                            //10-05-15|0x0146
            SourceState = 5940; // CLS_LIB_USER                                           //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
          default:                                                                        //10-05-15|0x0146
            SourceStatus = SystemError;                                                   //10-05-15|0x0146
            SourceRunFlag = 0;                                                            //10-05-15|0x0146
            SystemMsg;                                                                    //10-05-15|0x0146
            break;                                                                        //10-05-15|0x0146
        }                                                                                 //10-05-15|0x0146
        break;                                                                            //10-05-15|0x0146
//---------------------------------------------------------------------------             //10-05-15|0x0147
      case 36314: // TEXT_EXTENT                                                          //10-06-11|0x0148
        switch(CmdTest("_TEXT_EXTENT"))                                                   //10-06-11|0x0148
        {                                                                                 //10-06-11|0x0148
          case -1:                                                                        //10-06-11|0x0148
            SourceRunFlag = 1;                                                            //10-06-11|0x0148
            SourceState = 27641; // 1ST_MAILBOX                                           //10-06-11|0x0148
            break;                                                                        //10-06-11|0x0148
          case 0:                                                                         //10-06-11|0x0148
            SourceRunFlag = 1;                                                            //10-06-11|0x0148
            SourceState = 11272; // INPUT_TEXT_EXT                                        //10-06-11|0x0148
            break;                                                                        //10-06-11|0x0148
          case 1:                                                                         //10-06-11|0x0148
            SourceRunFlag = 1;                                                            //10-06-11|0x0148
            SourceState = 27641; // 1ST_MAILBOX                                           //10-06-11|0x0148
            break;                                                                        //10-06-11|0x0148
          default:                                                                        //10-06-11|0x0148
            SourceStatus = SystemError;                                                   //10-06-11|0x0148
            SourceRunFlag = 0;                                                            //10-06-11|0x0148
            SystemMsg;                                                                    //10-06-11|0x0148
            break;                                                                        //10-06-11|0x0148
        }                                                                                 //10-06-11|0x0148
        break;                                                                            //10-06-11|0x0148
//---------------------------------------------------------------------------             //10-05-15|0x0149
      case 11272: // INPUT_TEXT_EXT                                                       //10-05-15|0x014a
        switch(text_prepare())                                                            //10-05-15|0x014a
        {                                                                                 //10-05-15|0x014a
          case Success:                                                                   //10-05-15|0x014a
            SourceRunFlag = 1;                                                            //10-05-15|0x014a
            SourceState = 60679; // LOAD_TEXT_EXT                                         //10-05-15|0x014a
            break;                                                                        //10-05-15|0x014a
          case UserError:                                                                 //10-05-15|0x014a
            SourceRunFlag = 1;                                                            //10-05-15|0x014a
            SourceState = 5940; // CLS_LIB_USER                                           //10-05-15|0x014a
            break;                                                                        //10-05-15|0x014a
          default:                                                                        //10-05-15|0x014a
            SourceStatus = SystemError;                                                   //10-05-15|0x014a
            SourceRunFlag = 0;                                                            //10-05-15|0x014a
            SystemMsg;                                                                    //10-05-15|0x014a
            break;                                                                        //10-05-15|0x014a
        }                                                                                 //10-05-15|0x014a
        break;                                                                            //10-05-15|0x014a
//---------------------------------------------------------------------------             //10-05-15|0x014b
      case 60679: // LOAD_TEXT_EXT                                                        //10-05-15|0x014c
        switch(load_in_path_ext())                                                        //10-05-15|0x014c
        {                                                                                 //10-05-15|0x014c
          case Success:                                                                   //10-05-15|0x014c
            SourceRunFlag = 1;                                                            //10-05-15|0x014c
            SourceState = 43884; // READ_TEXT_EXTENT                                      //10-05-15|0x014c
            break;                                                                        //10-05-15|0x014c
          case UserError:                                                                 //10-05-15|0x014c
            SourceRunFlag = 1;                                                            //10-05-15|0x014c
            SourceState = 5940; // CLS_LIB_USER                                           //10-05-15|0x014c
            break;                                                                        //10-05-15|0x014c
          default:                                                                        //10-05-15|0x014c
            SourceStatus = SystemError;                                                   //10-05-15|0x014c
            SourceRunFlag = 0;                                                            //10-05-15|0x014c
            SystemMsg;                                                                    //10-05-15|0x014c
            break;                                                                        //10-05-15|0x014c
        }                                                                                 //10-05-15|0x014c
        break;                                                                            //10-05-15|0x014c
//***************************************************************************             //10-06-11|0x014d
//******                                                               ******             //10-06-11|0x014e
//****** Process input files                                           ******             //10-06-11|0x014f
//******---------------------------------------------------------------******             //10-06-11|0x0150
//****** Process mail box paths and extents                            ******             //10-06-11|0x0151
//******                                                               ******             //10-06-11|0x0152
//***************************************************************************             //10-06-11|0x0153
      case 27641: // 1ST_MAILBOX                                                          //10-06-11|0x0154
        switch(CmdTest("_MAILBOX"))                                                       //10-06-11|0x0154
        {                                                                                 //10-06-11|0x0154
          case -1:                                                                        //10-06-11|0x0154
            SourceRunFlag = 1;                                                            //10-06-11|0x0154
            SourceState = 48630; // 1ST_POSTOFFICE                                        //10-06-11|0x0154
            break;                                                                        //10-06-11|0x0154
          case 0:                                                                         //10-06-11|0x0154
            SourceRunFlag = 1;                                                            //10-06-11|0x0154
            SourceState = 40405; // PREPARE_MAIL                                          //10-06-11|0x0154
            break;                                                                        //10-06-11|0x0154
          case 1:                                                                         //10-06-11|0x0154
            SourceRunFlag = 1;                                                            //10-06-11|0x0154
            SourceState = 48630; // 1ST_POSTOFFICE                                        //10-06-11|0x0154
            break;                                                                        //10-06-11|0x0154
          default:                                                                        //10-06-11|0x0154
            SourceStatus = SystemError;                                                   //10-06-11|0x0154
            SourceRunFlag = 0;                                                            //10-06-11|0x0154
            SystemMsg;                                                                    //10-06-11|0x0154
            break;                                                                        //10-06-11|0x0154
        }                                                                                 //10-06-11|0x0154
        break;                                                                            //10-06-11|0x0154
//***************************************************************************             //10-06-11|0x0155
      case 31652: // MAILBOX                                                              //10-06-11|0x0156
        switch(CmdTest("_MAILBOX"))                                                       //10-06-11|0x0156
        {                                                                                 //10-06-11|0x0156
          case -1:                                                                        //10-06-11|0x0156
            SourceRunFlag = 1;                                                            //10-06-11|0x0156
            SourceState = 13923; // 2ST_POSTOFFICE                                        //10-06-11|0x0156
            break;                                                                        //10-06-11|0x0156
          case 0:                                                                         //10-06-11|0x0156
            SourceRunFlag = 1;                                                            //10-06-11|0x0156
            SourceState = 40405; // PREPARE_MAIL                                          //10-06-11|0x0156
            break;                                                                        //10-06-11|0x0156
          case 1:                                                                         //10-06-11|0x0156
            SourceRunFlag = 1;                                                            //10-06-11|0x0156
            SourceState = 13923; // 2ST_POSTOFFICE                                        //10-06-11|0x0156
            break;                                                                        //10-06-11|0x0156
          default:                                                                        //10-06-11|0x0156
            SourceStatus = SystemError;                                                   //10-06-11|0x0156
            SourceRunFlag = 0;                                                            //10-06-11|0x0156
            SystemMsg;                                                                    //10-06-11|0x0156
            break;                                                                        //10-06-11|0x0156
        }                                                                                 //10-06-11|0x0156
        break;                                                                            //10-06-11|0x0156
//---------------------------------------------------------------------------             //10-06-11|0x0157
      case 40405: // PREPARE_MAIL                                                         //10-06-11|0x0158
        switch(text_prepare())                                                            //10-06-11|0x0158
        {                                                                                 //10-06-11|0x0158
          case Success:                                                                   //10-06-11|0x0158
            SourceRunFlag = 1;                                                            //10-06-11|0x0158
            SourceState = 40210; // LOAD_MAILBOX                                          //10-06-11|0x0158
            break;                                                                        //10-06-11|0x0158
          case UserError:                                                                 //10-06-11|0x0158
            SourceRunFlag = 1;                                                            //10-06-11|0x0158
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x0158
            break;                                                                        //10-06-11|0x0158
          default:                                                                        //10-06-11|0x0158
            SourceStatus = SystemError;                                                   //10-06-11|0x0158
            SourceRunFlag = 0;                                                            //10-06-11|0x0158
            SystemMsg;                                                                    //10-06-11|0x0158
            break;                                                                        //10-06-11|0x0158
        }                                                                                 //10-06-11|0x0158
        break;                                                                            //10-06-11|0x0158
//---------------------------------------------------------------------------             //10-06-11|0x0159
      case 40210: // LOAD_MAILBOX                                                         //10-06-11|0x015a
        switch(LoadMailBox)                                                               //10-06-11|0x015a
        {                                                                                 //10-06-11|0x015a
          case Success:                                                                   //10-06-11|0x015a
            SourceRunFlag = 1;                                                            //10-06-11|0x015a
            SourceState = 28337; // READ_MAILBOX                                          //10-06-11|0x015a
            break;                                                                        //10-06-11|0x015a
          case UserError:                                                                 //10-06-11|0x015a
            SourceRunFlag = 1;                                                            //10-06-11|0x015a
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x015a
            break;                                                                        //10-06-11|0x015a
          default:                                                                        //10-06-11|0x015a
            SourceStatus = SystemError;                                                   //10-06-11|0x015a
            SourceRunFlag = 0;                                                            //10-06-11|0x015a
            SystemMsg;                                                                    //10-06-11|0x015a
            break;                                                                        //10-06-11|0x015a
        }                                                                                 //10-06-11|0x015a
        break;                                                                            //10-06-11|0x015a
//---------------------------------------------------------------------------             //10-06-11|0x015b
      case 28337: // READ_MAILBOX                                                         //10-06-11|0x015c
        switch(ReadProject)                                                               //10-06-11|0x015c
        {                                                                                 //10-06-11|0x015c
          case Display:                                                                   //10-06-11|0x015c
            SourceState = 23104; // READ_MAILBOX_EXIT                                     //10-06-11|0x015c
            SourceStatus = Display;                                                       //10-06-11|0x015c
            SourceRunFlag = 0;                                                            //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          case LineDone:                                                                  //10-06-11|0x015c
            SourceRunFlag = 1;                                                            //10-06-11|0x015c
            SourceState = 31652; // MAILBOX                                               //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          case FileDone:                                                                  //10-06-11|0x015c
            SourceRunFlag = 1;                                                            //10-06-11|0x015c
            SourceState = 4197; // END_LIB                                                //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          case UserError:                                                                 //10-06-11|0x015c
            SourceRunFlag = 1;                                                            //10-06-11|0x015c
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          default:                                                                        //10-06-11|0x015c
            SourceStatus = SystemError;                                                   //10-06-11|0x015c
            SourceRunFlag = 0;                                                            //10-06-11|0x015c
            SystemMsg;                                                                    //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
        }                                                                                 //10-06-11|0x015c
        break;                                                                            //10-06-11|0x015c
//**************************************************************************              //10-06-11|0x015c
      case 23104: // READ_MAILBOX_EXIT                                                    //10-06-11|0x015c
        switch(ReadProject)                                                               //10-06-11|0x015c
        {                                                                                 //10-06-11|0x015c
          case Display:                                                                   //10-06-11|0x015c
            SourceState = 23104; // READ_MAILBOX_EXIT                                     //10-06-11|0x015c
            SourceStatus = Display;                                                       //10-06-11|0x015c
            SourceRunFlag = 0;                                                            //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          case LineDone:                                                                  //10-06-11|0x015c
            SourceRunFlag = 1;                                                            //10-06-11|0x015c
            SourceState = 31652; // MAILBOX                                               //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          case FileDone:                                                                  //10-06-11|0x015c
            SourceRunFlag = 1;                                                            //10-06-11|0x015c
            SourceState = 4197; // END_LIB                                                //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          case UserError:                                                                 //10-06-11|0x015c
            SourceRunFlag = 1;                                                            //10-06-11|0x015c
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
          default:                                                                        //10-06-11|0x015c
            SourceStatus = SystemError;                                                   //10-06-11|0x015c
            SourceRunFlag = 0;                                                            //10-06-11|0x015c
            SystemMsg;                                                                    //10-06-11|0x015c
            break;                                                                        //10-06-11|0x015c
        }                                                                                 //10-06-11|0x015c
        break;                                                                            //10-06-11|0x015c
//***************************************************************************             //10-06-11|0x015d
//******                                                               ******             //10-06-11|0x015e
//****** Process output files                                          ******             //10-06-11|0x015f
//******---------------------------------------------------------------******             //10-06-11|0x0160
//****** Process postoffices paths and extents                         ******             //10-06-11|0x0161
//******                                                               ******             //10-06-11|0x0162
//***************************************************************************             //10-06-11|0x0163
      case 48630: // 1ST_POSTOFFICE                                                       //10-06-11|0x0164
        switch(CmdTest("_POSTOFFICE"))                                                    //10-06-11|0x0164
        {                                                                                 //10-06-11|0x0164
          case -1:                                                                        //10-06-11|0x0164
            SourceRunFlag = 1;                                                            //10-06-11|0x0164
            SourceState = 65215; // 1ST_OUT_EXT                                           //10-06-11|0x0164
            break;                                                                        //10-06-11|0x0164
          case 0:                                                                         //10-06-11|0x0164
            SourceRunFlag = 1;                                                            //10-06-11|0x0164
            SourceState = 60206; // PREPARE_POST                                          //10-06-11|0x0164
            break;                                                                        //10-06-11|0x0164
          case 1:                                                                         //10-06-11|0x0164
            SourceRunFlag = 1;                                                            //10-06-11|0x0164
            SourceState = 65215; // 1ST_OUT_EXT                                           //10-06-11|0x0164
            break;                                                                        //10-06-11|0x0164
          default:                                                                        //10-06-11|0x0164
            SourceStatus = SystemError;                                                   //10-06-11|0x0164
            SourceRunFlag = 0;                                                            //10-06-11|0x0164
            SystemMsg;                                                                    //10-06-11|0x0164
            break;                                                                        //10-06-11|0x0164
        }                                                                                 //10-06-11|0x0164
        break;                                                                            //10-06-11|0x0164
//---------------------------------------------------------------------------             //10-06-11|0x0165
      case 13923: // 2ST_POSTOFFICE                                                       //10-06-11|0x0166
        switch(CmdTest("_POSTOFFICE"))                                                    //10-06-11|0x0166
        {                                                                                 //10-06-11|0x0166
          case -1:                                                                        //10-06-11|0x0166
            SourceRunFlag = 1;                                                            //10-06-11|0x0166
            SourceState = 40589; // POST_NAME_DONE                                        //10-06-11|0x0166
            break;                                                                        //10-06-11|0x0166
          case 0:                                                                         //10-06-11|0x0166
            SourceRunFlag = 1;                                                            //10-06-11|0x0166
            SourceState = 60206; // PREPARE_POST                                          //10-06-11|0x0166
            break;                                                                        //10-06-11|0x0166
          case 1:                                                                         //10-06-11|0x0166
            SourceRunFlag = 1;                                                            //10-06-11|0x0166
            SourceState = 40589; // POST_NAME_DONE                                        //10-06-11|0x0166
            break;                                                                        //10-06-11|0x0166
          default:                                                                        //10-06-11|0x0166
            SourceStatus = SystemError;                                                   //10-06-11|0x0166
            SourceRunFlag = 0;                                                            //10-06-11|0x0166
            SystemMsg;                                                                    //10-06-11|0x0166
            break;                                                                        //10-06-11|0x0166
        }                                                                                 //10-06-11|0x0166
        break;                                                                            //10-06-11|0x0166
//***************************************************************************             //10-06-11|0x0167
      case 34780: // POSTOFFICE                                                           //10-06-11|0x0168
        switch(CmdTest("_POSTOFFICE"))                                                    //10-06-11|0x0168
        {                                                                                 //10-06-11|0x0168
          case -1:                                                                        //10-06-11|0x0168
            SourceRunFlag = 1;                                                            //10-06-11|0x0168
            SourceState = 1563; // MAIL_NAME_DONE                                         //10-06-11|0x0168
            break;                                                                        //10-06-11|0x0168
          case 0:                                                                         //10-06-11|0x0168
            SourceRunFlag = 1;                                                            //10-06-11|0x0168
            SourceState = 60206; // PREPARE_POST                                          //10-06-11|0x0168
            break;                                                                        //10-06-11|0x0168
          case 1:                                                                         //10-06-11|0x0168
            SourceRunFlag = 1;                                                            //10-06-11|0x0168
            SourceState = 1563; // MAIL_NAME_DONE                                         //10-06-11|0x0168
            break;                                                                        //10-06-11|0x0168
          default:                                                                        //10-06-11|0x0168
            SourceStatus = SystemError;                                                   //10-06-11|0x0168
            SourceRunFlag = 0;                                                            //10-06-11|0x0168
            SystemMsg;                                                                    //10-06-11|0x0168
            break;                                                                        //10-06-11|0x0168
        }                                                                                 //10-06-11|0x0168
        break;                                                                            //10-06-11|0x0168
//---------------------------------------------------------------------------             //10-06-11|0x0169
      case 60206: // PREPARE_POST                                                         //10-06-11|0x016a
        switch(text_prepare())                                                            //10-06-11|0x016a
        {                                                                                 //10-06-11|0x016a
          case Success:                                                                   //10-06-11|0x016a
            SourceRunFlag = 1;                                                            //10-06-11|0x016a
            SourceState = 26698; // LOAD_POST                                             //10-06-11|0x016a
            break;                                                                        //10-06-11|0x016a
          case UserError:                                                                 //10-06-11|0x016a
            SourceRunFlag = 1;                                                            //10-06-11|0x016a
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x016a
            break;                                                                        //10-06-11|0x016a
          default:                                                                        //10-06-11|0x016a
            SourceStatus = SystemError;                                                   //10-06-11|0x016a
            SourceRunFlag = 0;                                                            //10-06-11|0x016a
            SystemMsg;                                                                    //10-06-11|0x016a
            break;                                                                        //10-06-11|0x016a
        }                                                                                 //10-06-11|0x016a
        break;                                                                            //10-06-11|0x016a
//---------------------------------------------------------------------------             //10-06-11|0x016b
      case 26698: // LOAD_POST                                                            //10-06-11|0x016c
        switch(LoadPostOffice)                                                            //10-06-11|0x016c
        {                                                                                 //10-06-11|0x016c
          case Success:                                                                   //10-06-11|0x016c
            SourceRunFlag = 1;                                                            //10-06-11|0x016c
            SourceState = 60777; // READ_POST                                             //10-06-11|0x016c
            break;                                                                        //10-06-11|0x016c
          case UserError:                                                                 //10-06-11|0x016c
            SourceRunFlag = 1;                                                            //10-06-11|0x016c
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x016c
            break;                                                                        //10-06-11|0x016c
          default:                                                                        //10-06-11|0x016c
            SourceStatus = SystemError;                                                   //10-06-11|0x016c
            SourceRunFlag = 0;                                                            //10-06-11|0x016c
            SystemMsg;                                                                    //10-06-11|0x016c
            break;                                                                        //10-06-11|0x016c
        }                                                                                 //10-06-11|0x016c
        break;                                                                            //10-06-11|0x016c
//---------------------------------------------------------------------------             //10-06-11|0x016d
      case 60777: // READ_POST                                                            //10-06-11|0x016e
        switch(ReadProject)                                                               //10-06-11|0x016e
        {                                                                                 //10-06-11|0x016e
          case Display:                                                                   //10-06-11|0x016e
            SourceState = 50296; // READ_POST_EXIT                                        //10-06-11|0x016e
            SourceStatus = Display;                                                       //10-06-11|0x016e
            SourceRunFlag = 0;                                                            //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          case LineDone:                                                                  //10-06-11|0x016e
            SourceRunFlag = 1;                                                            //10-06-11|0x016e
            SourceState = 34780; // POSTOFFICE                                            //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          case FileDone:                                                                  //10-06-11|0x016e
            SourceRunFlag = 1;                                                            //10-06-11|0x016e
            SourceState = 4197; // END_LIB                                                //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          case UserError:                                                                 //10-06-11|0x016e
            SourceRunFlag = 1;                                                            //10-06-11|0x016e
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          default:                                                                        //10-06-11|0x016e
            SourceStatus = SystemError;                                                   //10-06-11|0x016e
            SourceRunFlag = 0;                                                            //10-06-11|0x016e
            SystemMsg;                                                                    //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
        }                                                                                 //10-06-11|0x016e
        break;                                                                            //10-06-11|0x016e
//**************************************************************************              //10-06-11|0x016e
      case 50296: // READ_POST_EXIT                                                       //10-06-11|0x016e
        switch(ReadProject)                                                               //10-06-11|0x016e
        {                                                                                 //10-06-11|0x016e
          case Display:                                                                   //10-06-11|0x016e
            SourceState = 50296; // READ_POST_EXIT                                        //10-06-11|0x016e
            SourceStatus = Display;                                                       //10-06-11|0x016e
            SourceRunFlag = 0;                                                            //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          case LineDone:                                                                  //10-06-11|0x016e
            SourceRunFlag = 1;                                                            //10-06-11|0x016e
            SourceState = 34780; // POSTOFFICE                                            //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          case FileDone:                                                                  //10-06-11|0x016e
            SourceRunFlag = 1;                                                            //10-06-11|0x016e
            SourceState = 4197; // END_LIB                                                //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          case UserError:                                                                 //10-06-11|0x016e
            SourceRunFlag = 1;                                                            //10-06-11|0x016e
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
          default:                                                                        //10-06-11|0x016e
            SourceStatus = SystemError;                                                   //10-06-11|0x016e
            SourceRunFlag = 0;                                                            //10-06-11|0x016e
            SystemMsg;                                                                    //10-06-11|0x016e
            break;                                                                        //10-06-11|0x016e
        }                                                                                 //10-06-11|0x016e
        break;                                                                            //10-06-11|0x016e
//***************************************************************************             //10-06-11|0x016f
      case 1563: // MAIL_NAME_DONE                                                        //10-06-11|0x0170
        switch(MailDictNameDone())                                                        //10-06-11|0x0170
        {                                                                                 //10-06-11|0x0170
          case Success:                                                                   //10-06-11|0x0170
            SourceRunFlag = 1;                                                            //10-06-11|0x0170
            SourceState = 3191; // OUT_EXT                                                //10-06-11|0x0170
            break;                                                                        //10-06-11|0x0170
          default:                                                                        //10-06-11|0x0170
            SourceStatus = SystemError;                                                   //10-06-11|0x0170
            SourceRunFlag = 0;                                                            //10-06-11|0x0170
            SystemMsg;                                                                    //10-06-11|0x0170
            break;                                                                        //10-06-11|0x0170
        }                                                                                 //10-06-11|0x0170
        break;                                                                            //10-06-11|0x0170
//---------------------------------------------------------------------------             //10-06-11|0x0171
      case 40589: // POST_NAME_DONE                                                       //10-06-11|0x0172
        switch(MailDictNameDone())                                                        //10-06-11|0x0172
        {                                                                                 //10-06-11|0x0172
          case Success:                                                                   //10-06-11|0x0172
            SourceRunFlag = 1;                                                            //10-06-11|0x0172
            SourceState = 65215; // 1ST_OUT_EXT                                           //10-06-11|0x0172
            break;                                                                        //10-06-11|0x0172
          default:                                                                        //10-06-11|0x0172
            SourceStatus = SystemError;                                                   //10-06-11|0x0172
            SourceRunFlag = 0;                                                            //10-06-11|0x0172
            SystemMsg;                                                                    //10-06-11|0x0172
            break;                                                                        //10-06-11|0x0172
        }                                                                                 //10-06-11|0x0172
        break;                                                                            //10-06-11|0x0172
//***************************************************************************             //10-06-11|0x0173
//******                                                               ******             //10-06-11|0x0174
//****** Process output files                                          ******             //10-06-11|0x0175
//******---------------------------------------------------------------******             //10-06-11|0x0176
//****** Process Output text file paths and extents                    ******             //10-06-11|0x0177
//******                                                               ******             //09-03-10|0x0178
//***************************************************************************             //09-03-10|0x0179
      case 65215: // 1ST_OUT_EXT                                                          //10-06-11|0x017a
        switch(CmdTest("_OUT_PATH_EXT"))                                                  //10-06-11|0x017a
        {                                                                                 //10-06-11|0x017a
          case -1:                                                                        //10-06-11|0x017a
            SourceRunFlag = 1;                                                            //10-06-11|0x017a
            SourceState = 14800; // CMND_LIB_ERR                                          //10-06-11|0x017a
            break;                                                                        //10-06-11|0x017a
          case 0:                                                                         //10-06-11|0x017a
            SourceRunFlag = 1;                                                            //10-06-11|0x017a
            SourceState = 54374; // OUT_PATH_EXT                                          //10-06-11|0x017a
            break;                                                                        //10-06-11|0x017a
          case 1:                                                                         //10-06-11|0x017a
            SourceRunFlag = 1;                                                            //10-06-11|0x017a
            SourceState = 14800; // CMND_LIB_ERR                                          //10-06-11|0x017a
            break;                                                                        //10-06-11|0x017a
          default:                                                                        //10-06-11|0x017a
            SourceStatus = SystemError;                                                   //10-06-11|0x017a
            SourceRunFlag = 0;                                                            //10-06-11|0x017a
            SystemMsg;                                                                    //10-06-11|0x017a
            break;                                                                        //10-06-11|0x017a
        }                                                                                 //10-06-11|0x017a
        break;                                                                            //10-06-11|0x017a
//---------------------------------------------------------------------------             //06-09-13|0x017b
      case 3191: // OUT_EXT                                                               //10-06-11|0x017c
        switch(CmdTest("_OUT_PATH_EXT"))                                                  //10-06-11|0x017c
        {                                                                                 //10-06-11|0x017c
          case -1:                                                                        //10-06-11|0x017c
            SourceRunFlag = 1;                                                            //10-06-11|0x017c
            SourceState = 6981; // CLR_ARGUMENTS                                          //10-06-11|0x017c
            break;                                                                        //10-06-11|0x017c
          case 0:                                                                         //10-06-11|0x017c
            SourceRunFlag = 1;                                                            //10-06-11|0x017c
            SourceState = 54374; // OUT_PATH_EXT                                          //10-06-11|0x017c
            break;                                                                        //10-06-11|0x017c
          case 1:                                                                         //10-06-11|0x017c
            SourceRunFlag = 1;                                                            //10-06-11|0x017c
            SourceState = 6981; // CLR_ARGUMENTS                                          //10-06-11|0x017c
            break;                                                                        //10-06-11|0x017c
          default:                                                                        //10-06-11|0x017c
            SourceStatus = SystemError;                                                   //10-06-11|0x017c
            SourceRunFlag = 0;                                                            //10-06-11|0x017c
            SystemMsg;                                                                    //10-06-11|0x017c
            break;                                                                        //10-06-11|0x017c
        }                                                                                 //10-06-11|0x017c
        break;                                                                            //10-06-11|0x017c
//***************************************************************************             //06-09-13|0x017d
      case 54374: // OUT_PATH_EXT                                                         //07-03-23|0x017e
        switch(text_prepare())                                                            //07-03-23|0x017e
        {                                                                                 //07-03-23|0x017e
          case Success:                                                                   //07-03-23|0x017e
            SourceRunFlag = 1;                                                            //07-03-23|0x017e
            SourceState = 53268; // LOAD_OUT_PATH_EXT                                     //07-03-23|0x017e
            break;                                                                        //07-03-23|0x017e
          case UserError:                                                                 //07-03-23|0x017e
            SourceRunFlag = 1;                                                            //07-03-23|0x017e
            SourceState = 5940; // CLS_LIB_USER                                           //07-03-23|0x017e
            break;                                                                        //07-03-23|0x017e
          default:                                                                        //07-03-23|0x017e
            SourceStatus = SystemError;                                                   //07-03-23|0x017e
            SourceRunFlag = 0;                                                            //07-03-23|0x017e
            SystemMsg;                                                                    //07-03-23|0x017e
            break;                                                                        //07-03-23|0x017e
        }                                                                                 //07-03-23|0x017e
        break;                                                                            //07-03-23|0x017e
//---------------------------------------------------------------------------             //06-09-13|0x017f
      case 53268: // LOAD_OUT_PATH_EXT                                                    //07-03-23|0x0180
        switch(load_out_path_ext())                                                       //07-03-23|0x0180
        {                                                                                 //07-03-23|0x0180
          case Success:                                                                   //07-03-23|0x0180
            SourceRunFlag = 1;                                                            //07-03-23|0x0180
            SourceState = 53715; // READ_OUT_EXT                                          //07-03-23|0x0180
            break;                                                                        //07-03-23|0x0180
          case UserError:                                                                 //07-03-23|0x0180
            SourceRunFlag = 1;                                                            //07-03-23|0x0180
            SourceState = 5940; // CLS_LIB_USER                                           //07-03-23|0x0180
            break;                                                                        //07-03-23|0x0180
          default:                                                                        //07-03-23|0x0180
            SourceStatus = SystemError;                                                   //07-03-23|0x0180
            SourceRunFlag = 0;                                                            //07-03-23|0x0180
            SystemMsg;                                                                    //07-03-23|0x0180
            break;                                                                        //07-03-23|0x0180
        }                                                                                 //07-03-23|0x0180
        break;                                                                            //07-03-23|0x0180
//---------------------------------------------------------------------------             //06-09-13|0x0181
      case 53715: // READ_OUT_EXT                                                         //06-09-13|0x0182
        switch(ReadProject)                                                               //06-09-13|0x0182
        {                                                                                 //06-09-13|0x0182
          case Display:                                                                   //06-09-13|0x0182
            SourceState = 61314; // READ_OUT_EXT_EXIT                                     //06-09-13|0x0182
            SourceStatus = Display;                                                       //06-09-13|0x0182
            SourceRunFlag = 0;                                                            //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          case LineDone:                                                                  //06-09-13|0x0182
            SourceRunFlag = 1;                                                            //06-09-13|0x0182
            SourceState = 3191; // OUT_EXT                                                //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          case FileDone:                                                                  //06-09-13|0x0182
            SourceRunFlag = 1;                                                            //06-09-13|0x0182
            SourceState = 4197; // END_LIB                                                //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          case UserError:                                                                 //06-09-13|0x0182
            SourceRunFlag = 1;                                                            //06-09-13|0x0182
            SourceState = 5940; // CLS_LIB_USER                                           //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          default:                                                                        //06-09-13|0x0182
            SourceStatus = SystemError;                                                   //06-09-13|0x0182
            SourceRunFlag = 0;                                                            //06-09-13|0x0182
            SystemMsg;                                                                    //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
        }                                                                                 //06-09-13|0x0182
        break;                                                                            //06-09-13|0x0182
//**************************************************************************              //06-09-13|0x0182
      case 61314: // READ_OUT_EXT_EXIT                                                    //06-09-13|0x0182
        switch(ReadProject)                                                               //06-09-13|0x0182
        {                                                                                 //06-09-13|0x0182
          case Display:                                                                   //06-09-13|0x0182
            SourceState = 61314; // READ_OUT_EXT_EXIT                                     //06-09-13|0x0182
            SourceStatus = Display;                                                       //06-09-13|0x0182
            SourceRunFlag = 0;                                                            //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          case LineDone:                                                                  //06-09-13|0x0182
            SourceRunFlag = 1;                                                            //06-09-13|0x0182
            SourceState = 3191; // OUT_EXT                                                //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          case FileDone:                                                                  //06-09-13|0x0182
            SourceRunFlag = 1;                                                            //06-09-13|0x0182
            SourceState = 4197; // END_LIB                                                //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          case UserError:                                                                 //06-09-13|0x0182
            SourceRunFlag = 1;                                                            //06-09-13|0x0182
            SourceState = 5940; // CLS_LIB_USER                                           //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
          default:                                                                        //06-09-13|0x0182
            SourceStatus = SystemError;                                                   //06-09-13|0x0182
            SourceRunFlag = 0;                                                            //06-09-13|0x0182
            SystemMsg;                                                                    //06-09-13|0x0182
            break;                                                                        //06-09-13|0x0182
        }                                                                                 //06-09-13|0x0182
        break;                                                                            //06-09-13|0x0182
//***************************************************************************             //07-07-11|0x0183
//******                                                               ******             //07-07-11|0x0184
//****** Process optional Argument command                             ******             //07-07-11|0x0185
//******                                                               ******             //07-07-11|0x0186
//***************************************************************************             //07-07-11|0x0187
      case 6981: // CLR_ARGUMENTS                                                         //07-07-11|0x0188
        ClearArguments;                                                                   //07-07-11|0x0188
        SourceState = 59425; // ARGUMENTS                                                 //07-07-11|0x0188
        break;                                                                            //07-07-11|0x0188
//---------------------------------------------------------------------------             //07-07-11|0x0189
      case 59425: // ARGUMENTS                                                            //07-07-11|0x018a
        switch(CmdTest("_ARGUMENTS"))                                                     //07-07-11|0x018a
        {                                                                                 //07-07-11|0x018a
          case -1:                                                                        //07-07-11|0x018a
            SourceRunFlag = 1;                                                            //07-07-11|0x018a
            SourceState = 27312; // SOURCE                                                //07-07-11|0x018a
            break;                                                                        //07-07-11|0x018a
          case 0:                                                                         //07-07-11|0x018a
            SourceRunFlag = 1;                                                            //07-07-11|0x018a
            SourceState = 5679; // LOAD_ARGUMENTS                                         //07-07-11|0x018a
            break;                                                                        //07-07-11|0x018a
          case 1:                                                                         //07-07-11|0x018a
            SourceRunFlag = 1;                                                            //07-07-11|0x018a
            SourceState = 27312; // SOURCE                                                //07-07-11|0x018a
            break;                                                                        //07-07-11|0x018a
          default:                                                                        //07-07-11|0x018a
            SourceStatus = SystemError;                                                   //07-07-11|0x018a
            SourceRunFlag = 0;                                                            //07-07-11|0x018a
            SystemMsg;                                                                    //07-07-11|0x018a
            break;                                                                        //07-07-11|0x018a
        }                                                                                 //07-07-11|0x018a
        break;                                                                            //07-07-11|0x018a
//---------------------------------------------------------------------------             //07-07-11|0x018b
      case 5679: // LOAD_ARGUMENTS                                                        //07-07-11|0x018c
        switch(text_prepare())                                                            //07-07-11|0x018c
        {                                                                                 //07-07-11|0x018c
          case Success:                                                                   //07-07-11|0x018c
            SourceRunFlag = 1;                                                            //07-07-11|0x018c
            SourceState = 31134; // COPY_ARGUMENTS                                        //07-07-11|0x018c
            break;                                                                        //07-07-11|0x018c
          case UserError:                                                                 //07-07-11|0x018c
            SourceRunFlag = 1;                                                            //07-07-11|0x018c
            SourceState = 5940; // CLS_LIB_USER                                           //07-07-11|0x018c
            break;                                                                        //07-07-11|0x018c
          default:                                                                        //07-07-11|0x018c
            SourceStatus = SystemError;                                                   //07-07-11|0x018c
            SourceRunFlag = 0;                                                            //07-07-11|0x018c
            SystemMsg;                                                                    //07-07-11|0x018c
            break;                                                                        //07-07-11|0x018c
        }                                                                                 //07-07-11|0x018c
        break;                                                                            //07-07-11|0x018c
//---------------------------------------------------------------------------             //07-07-11|0x018d
      case 31134: // COPY_ARGUMENTS                                                       //07-07-11|0x018e
        LoadArguments;                                                                    //07-07-11|0x018e
        SourceState = 5117; // READ_ARGUMENTS                                             //07-07-11|0x018e
        break;                                                                            //07-07-11|0x018e
//---------------------------------------------------------------------------             //07-07-11|0x018f
      case 5117: // READ_ARGUMENTS                                                        //07-07-11|0x0190
        switch(ReadProject)                                                               //07-07-11|0x0190
        {                                                                                 //07-07-11|0x0190
          case Display:                                                                   //07-07-11|0x0190
            SourceState = 21580; // READ_ARGUMENTS_EXIT                                   //07-07-11|0x0190
            SourceStatus = Display;                                                       //07-07-11|0x0190
            SourceRunFlag = 0;                                                            //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          case LineDone:                                                                  //07-07-11|0x0190
            SourceRunFlag = 1;                                                            //07-07-11|0x0190
            SourceState = 27312; // SOURCE                                                //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          case FileDone:                                                                  //07-07-11|0x0190
            SourceRunFlag = 1;                                                            //07-07-11|0x0190
            SourceState = 4197; // END_LIB                                                //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          case UserError:                                                                 //07-07-11|0x0190
            SourceRunFlag = 1;                                                            //07-07-11|0x0190
            SourceState = 5940; // CLS_LIB_USER                                           //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          default:                                                                        //07-07-11|0x0190
            SourceStatus = SystemError;                                                   //07-07-11|0x0190
            SourceRunFlag = 0;                                                            //07-07-11|0x0190
            SystemMsg;                                                                    //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
        }                                                                                 //07-07-11|0x0190
        break;                                                                            //07-07-11|0x0190
//**************************************************************************              //07-07-11|0x0190
      case 21580: // READ_ARGUMENTS_EXIT                                                  //07-07-11|0x0190
        switch(ReadProject)                                                               //07-07-11|0x0190
        {                                                                                 //07-07-11|0x0190
          case Display:                                                                   //07-07-11|0x0190
            SourceState = 21580; // READ_ARGUMENTS_EXIT                                   //07-07-11|0x0190
            SourceStatus = Display;                                                       //07-07-11|0x0190
            SourceRunFlag = 0;                                                            //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          case LineDone:                                                                  //07-07-11|0x0190
            SourceRunFlag = 1;                                                            //07-07-11|0x0190
            SourceState = 27312; // SOURCE                                                //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          case FileDone:                                                                  //07-07-11|0x0190
            SourceRunFlag = 1;                                                            //07-07-11|0x0190
            SourceState = 4197; // END_LIB                                                //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          case UserError:                                                                 //07-07-11|0x0190
            SourceRunFlag = 1;                                                            //07-07-11|0x0190
            SourceState = 5940; // CLS_LIB_USER                                           //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
          default:                                                                        //07-07-11|0x0190
            SourceStatus = SystemError;                                                   //07-07-11|0x0190
            SourceRunFlag = 0;                                                            //07-07-11|0x0190
            SystemMsg;                                                                    //07-07-11|0x0190
            break;                                                                        //07-07-11|0x0190
        }                                                                                 //07-07-11|0x0190
        break;                                                                            //07-07-11|0x0190
//***************************************************************************             //06-09-13|0x0191
//******                                                               ******             //06-09-13|0x0192
//****** Process source file                                           ******             //06-09-13|0x0193
//******                                                               ******             //06-09-13|0x0194
//***************************************************************************             //06-09-13|0x0195
      case 27312: // SOURCE                                                               //06-09-13|0x0196
        switch(CmdTest("_SOURCE"))                                                        //06-09-13|0x0196
        {                                                                                 //06-09-13|0x0196
          case -1:                                                                        //06-09-13|0x0196
            SourceRunFlag = 1;                                                            //06-09-13|0x0196
            SourceState = 14800; // CMND_LIB_ERR                                          //06-09-13|0x0196
            break;                                                                        //06-09-13|0x0196
          case 0:                                                                         //06-09-13|0x0196
            SourceRunFlag = 1;                                                            //06-09-13|0x0196
            SourceState = 39307; // SOURCE_NAME                                           //06-09-13|0x0196
            break;                                                                        //06-09-13|0x0196
          case 1:                                                                         //06-09-13|0x0196
            SourceRunFlag = 1;                                                            //06-09-13|0x0196
            SourceState = 14800; // CMND_LIB_ERR                                          //06-09-13|0x0196
            break;                                                                        //06-09-13|0x0196
          default:                                                                        //06-09-13|0x0196
            SourceStatus = SystemError;                                                   //06-09-13|0x0196
            SourceRunFlag = 0;                                                            //06-09-13|0x0196
            SystemMsg;                                                                    //06-09-13|0x0196
            break;                                                                        //06-09-13|0x0196
        }                                                                                 //06-09-13|0x0196
        break;                                                                            //06-09-13|0x0196
//---------------------------------------------------------------------------             //06-09-13|0x0197
      case 39307: // SOURCE_NAME                                                          //06-09-13|0x0198
        switch(text_prepare())                                                            //06-09-13|0x0198
        {                                                                                 //06-09-13|0x0198
          case Success:                                                                   //06-09-13|0x0198
            SourceRunFlag = 1;                                                            //06-09-13|0x0198
            SourceState = 12986; // LOAD_SRCE_NAME                                        //06-09-13|0x0198
            break;                                                                        //06-09-13|0x0198
          case UserError:                                                                 //06-09-13|0x0198
            SourceRunFlag = 1;                                                            //06-09-13|0x0198
            SourceState = 5940; // CLS_LIB_USER                                           //06-09-13|0x0198
            break;                                                                        //06-09-13|0x0198
          default:                                                                        //06-09-13|0x0198
            SourceStatus = SystemError;                                                   //06-09-13|0x0198
            SourceRunFlag = 0;                                                            //06-09-13|0x0198
            SystemMsg;                                                                    //06-09-13|0x0198
            break;                                                                        //06-09-13|0x0198
        }                                                                                 //06-09-13|0x0198
        break;                                                                            //06-09-13|0x0198
//---------------------------------------------------------------------------             //06-09-13|0x0199
      case 12986: // LOAD_SRCE_NAME                                                       //06-09-13|0x019a
        switch(EnterSrcFileName)                                                          //06-09-13|0x019a
        {                                                                                 //06-09-13|0x019a
          case Success:                                                                   //06-09-13|0x019a
            SourceRunFlag = 1;                                                            //06-09-13|0x019a
            SourceState = 24281; // SOURCE_DATE                                           //06-09-13|0x019a
            break;                                                                        //06-09-13|0x019a
          default:                                                                        //06-09-13|0x019a
            SourceStatus = SystemError;                                                   //06-09-13|0x019a
            SourceRunFlag = 0;                                                            //06-09-13|0x019a
            SystemMsg;                                                                    //06-09-13|0x019a
            break;                                                                        //06-09-13|0x019a
        }                                                                                 //06-09-13|0x019a
        break;                                                                            //06-09-13|0x019a
//---------------------------------------------------------------------------             //06-09-13|0x019b
      case 24281: // SOURCE_DATE                                                          //06-09-13|0x019c
        switch(SourceFileTime)                                                            //06-09-13|0x019c
        {                                                                                 //06-09-13|0x019c
          case Success:                                                                   //06-09-13|0x019c
            SourceRunFlag = 1;                                                            //06-09-13|0x019c
            SourceState = 19688; // SOURCE_EXISTS                                         //06-09-13|0x019c
            break;                                                                        //06-09-13|0x019c
          default:                                                                        //06-09-13|0x019c
            SourceStatus = SystemError;                                                   //06-09-13|0x019c
            SourceRunFlag = 0;                                                            //06-09-13|0x019c
            SystemMsg;                                                                    //06-09-13|0x019c
            break;                                                                        //06-09-13|0x019c
        }                                                                                 //06-09-13|0x019c
        break;                                                                            //06-09-13|0x019c
//---------------------------------------------------------------------------             //06-09-13|0x019d
      case 19688: // SOURCE_EXISTS                                                        //06-09-13|0x019e
        switch(FileDateExists)                                                            //06-09-13|0x019e
        {                                                                                 //06-09-13|0x019e
          case Yes:                                                                       //06-09-13|0x019e
            SourceRunFlag = 1;                                                            //06-09-13|0x019e
            SourceState = 7143; // SRC_RECENT                                             //06-09-13|0x019e
            break;                                                                        //06-09-13|0x019e
          case No:                                                                        //06-09-13|0x019e
            SourceRunFlag = 1;                                                            //06-09-13|0x019e
            SourceState = 56022; // NO_SOURCE                                             //06-09-13|0x019e
            break;                                                                        //06-09-13|0x019e
          default:                                                                        //06-09-13|0x019e
            SourceStatus = SystemError;                                                   //06-09-13|0x019e
            SourceRunFlag = 0;                                                            //06-09-13|0x019e
            SystemMsg;                                                                    //06-09-13|0x019e
            break;                                                                        //06-09-13|0x019e
        }                                                                                 //06-09-13|0x019e
        break;                                                                            //06-09-13|0x019e
//---------------------------------------------------------------------------             //06-09-13|0x019f
      case 56022: // NO_SOURCE                                                            //06-09-13|0x01a0
        switch(SourceDoesNotExist)                                                        //06-09-13|0x01a0
        {                                                                                 //06-09-13|0x01a0
          case UserError:                                                                 //06-09-13|0x01a0
            SourceRunFlag = 1;                                                            //06-09-13|0x01a0
            SourceState = 5940; // CLS_LIB_USER                                           //06-09-13|0x01a0
            break;                                                                        //06-09-13|0x01a0
          default:                                                                        //06-09-13|0x01a0
            SourceStatus = SystemError;                                                   //06-09-13|0x01a0
            SourceRunFlag = 0;                                                            //06-09-13|0x01a0
            SystemMsg;                                                                    //06-09-13|0x01a0
            break;                                                                        //06-09-13|0x01a0
        }                                                                                 //06-09-13|0x01a0
        break;                                                                            //06-09-13|0x01a0
//---------------------------------------------------------------------------             //06-09-13|0x01a1
      case 7143: // SRC_RECENT                                                            //07-01-30|0x01a2
        switch(FileDateRecent)                                                            //07-01-30|0x01a2
        {                                                                                 //07-01-30|0x01a2
          case 1:                                                                         //07-01-30|0x01a2
            SourceRunFlag = 1;                                                            //07-01-30|0x01a2
            SourceState = 34997; // RECENT_SRC                                            //07-01-30|0x01a2
            break;                                                                        //07-01-30|0x01a2
          case 0:                                                                         //07-01-30|0x01a2
            SourceRunFlag = 1;                                                            //07-01-30|0x01a2
            SourceState = 5252; // EXISTS_EXT                                             //07-01-30|0x01a2
            break;                                                                        //07-01-30|0x01a2
          case -1:                                                                        //07-01-30|0x01a2
            SourceRunFlag = 1;                                                            //07-01-30|0x01a2
            SourceState = 5252; // EXISTS_EXT                                             //07-01-30|0x01a2
            break;                                                                        //07-01-30|0x01a2
          default:                                                                        //07-01-30|0x01a2
            SourceStatus = SystemError;                                                   //07-01-30|0x01a2
            SourceRunFlag = 0;                                                            //07-01-30|0x01a2
            SystemMsg;                                                                    //07-01-30|0x01a2
            break;                                                                        //07-01-30|0x01a2
        }                                                                                 //07-01-30|0x01a2
        break;                                                                            //07-01-30|0x01a2
//---------------------------------------------------------------------------             //07-01-30|0x01a3
      case 34997: // RECENT_SRC                                                           //07-01-30|0x01a4
        SourceOutTime = SourceInTime;                                                     //07-01-30|0x01a4
        SourceState = 5252; // EXISTS_EXT                                                 //07-01-30|0x01a4
        break;                                                                            //07-01-30|0x01a4
//***************************************************************************             //07-01-30|0x01a5
//******                                                               ******             //07-01-30|0x01a6
//****** Process text file                                             ******             //07-01-30|0x01a7
//******                                                               ******             //07-01-30|0x01a8
//***************************************************************************             //07-01-30|0x01a9
      case 5252: // EXISTS_EXT                                                            //10-05-15|0x01aa
        switch(FileExtentExists)                                                          //10-05-15|0x01aa
        {                                                                                 //10-05-15|0x01aa
          case Yes:                                                                       //10-05-15|0x01aa
            SourceRunFlag = 1;                                                            //10-05-15|0x01aa
            SourceState = 23875; // EXT_EXISTS                                            //10-05-15|0x01aa
            break;                                                                        //10-05-15|0x01aa
          case No:                                                                        //10-05-15|0x01aa
            SourceRunFlag = 1;                                                            //10-05-15|0x01aa
            SourceState = 12786; // EXT_NON_EXISTANT                                      //10-05-15|0x01aa
            break;                                                                        //10-05-15|0x01aa
          default:                                                                        //10-05-15|0x01aa
            SourceStatus = SystemError;                                                   //10-05-15|0x01aa
            SourceRunFlag = 0;                                                            //10-05-15|0x01aa
            SystemMsg;                                                                    //10-05-15|0x01aa
            break;                                                                        //10-05-15|0x01aa
        }                                                                                 //10-05-15|0x01aa
        break;                                                                            //10-05-15|0x01aa
//---------------------------------------------------------------------------             //07-03-23|0x01ab
      case 23875: // EXT_EXISTS                                                           //10-05-15|0x01ac
        switch(TextFileNameExists)                                                        //10-05-15|0x01ac
        {                                                                                 //10-05-15|0x01ac
          case Yes:                                                                       //10-05-15|0x01ac
            SourceRunFlag = 1;                                                            //10-05-15|0x01ac
            SourceState = 20881; // TEXT_NAME                                             //10-05-15|0x01ac
            break;                                                                        //10-05-15|0x01ac
          case No:                                                                        //10-05-15|0x01ac
            SourceRunFlag = 1;                                                            //10-05-15|0x01ac
            SourceState = 27424; // ARG_ERROR                                             //10-05-15|0x01ac
            break;                                                                        //10-05-15|0x01ac
          case UserError:                                                                 //10-05-15|0x01ac
            SourceRunFlag = 1;                                                            //10-05-15|0x01ac
            SourceState = 27424; // ARG_ERROR                                             //10-05-15|0x01ac
            break;                                                                        //10-05-15|0x01ac
          default:                                                                        //10-05-15|0x01ac
            SourceStatus = SystemError;                                                   //10-05-15|0x01ac
            SourceRunFlag = 0;                                                            //10-05-15|0x01ac
            SystemMsg;                                                                    //10-05-15|0x01ac
            break;                                                                        //10-05-15|0x01ac
        }                                                                                 //10-05-15|0x01ac
        break;                                                                            //10-05-15|0x01ac
//---------------------------------------------------------------------------             //07-03-23|0x01ad
      case 12786: // EXT_NON_EXISTANT                                                     //10-05-15|0x01ae
        switch(TextFileNameExists)                                                        //10-05-15|0x01ae
        {                                                                                 //10-05-15|0x01ae
          case Yes:                                                                       //10-05-15|0x01ae
            SourceRunFlag = 1;                                                            //10-05-15|0x01ae
            SourceState = 27424; // ARG_ERROR                                             //10-05-15|0x01ae
            break;                                                                        //10-05-15|0x01ae
          case No:                                                                        //10-05-15|0x01ae
            SourceRunFlag = 1;                                                            //10-05-15|0x01ae
            SourceState = 7583; // OUT_NAMES                                              //10-05-15|0x01ae
            break;                                                                        //10-05-15|0x01ae
          case UserError:                                                                 //10-05-15|0x01ae
            SourceRunFlag = 1;                                                            //10-05-15|0x01ae
            SourceState = 27424; // ARG_ERROR                                             //10-05-15|0x01ae
            break;                                                                        //10-05-15|0x01ae
          default:                                                                        //10-05-15|0x01ae
            SourceStatus = SystemError;                                                   //10-05-15|0x01ae
            SourceRunFlag = 0;                                                            //10-05-15|0x01ae
            SystemMsg;                                                                    //10-05-15|0x01ae
            break;                                                                        //10-05-15|0x01ae
        }                                                                                 //10-05-15|0x01ae
        break;                                                                            //10-05-15|0x01ae
//---------------------------------------------------------------------------             //07-03-23|0x01af
      case 27424: // ARG_ERROR                                                            //07-03-23|0x01b0
        switch(IllegalNoArgs)                                                             //07-03-23|0x01b0
        {                                                                                 //07-03-23|0x01b0
          case UserError:                                                                 //07-03-23|0x01b0
            SourceRunFlag = 1;                                                            //07-03-23|0x01b0
            SourceState = 5940; // CLS_LIB_USER                                           //07-03-23|0x01b0
            break;                                                                        //07-03-23|0x01b0
          default:                                                                        //07-03-23|0x01b0
            SourceStatus = SystemError;                                                   //07-03-23|0x01b0
            SourceRunFlag = 0;                                                            //07-03-23|0x01b0
            SystemMsg;                                                                    //07-03-23|0x01b0
            break;                                                                        //07-03-23|0x01b0
        }                                                                                 //07-03-23|0x01b0
        break;                                                                            //07-03-23|0x01b0
//***************************************************************************             //06-09-25|0x01b1
      case 20881: // TEXT_NAME                                                            //10-05-15|0x01b2
        switch(EnterTxtFileName)                                                          //10-05-15|0x01b2
        {                                                                                 //10-05-15|0x01b2
          case Success:                                                                   //10-05-15|0x01b2
            SourceRunFlag = 1;                                                            //10-05-15|0x01b2
            SourceState = 63502; // TEXT_DATE                                             //10-05-15|0x01b2
            break;                                                                        //10-05-15|0x01b2
          default:                                                                        //10-05-15|0x01b2
            SourceStatus = SystemError;                                                   //10-05-15|0x01b2
            SourceRunFlag = 0;                                                            //10-05-15|0x01b2
            SystemMsg;                                                                    //10-05-15|0x01b2
            break;                                                                        //10-05-15|0x01b2
        }                                                                                 //10-05-15|0x01b2
        break;                                                                            //10-05-15|0x01b2
//---------------------------------------------------------------------------             //07-02-02|0x01b3
      case 63502: // TEXT_DATE                                                            //10-05-15|0x01b4
        switch(TextFileTime)                                                              //10-05-15|0x01b4
        {                                                                                 //10-05-15|0x01b4
          case Success:                                                                   //10-05-15|0x01b4
            SourceRunFlag = 1;                                                            //10-05-15|0x01b4
            SourceState = 31085; // OPEN_TEXT                                             //10-05-15|0x01b4
            break;                                                                        //10-05-15|0x01b4
          case UserError:                                                                 //10-05-15|0x01b4
            SourceRunFlag = 1;                                                            //10-05-15|0x01b4
            SourceState = 4284; // NO_TEXT                                                //10-05-15|0x01b4
            break;                                                                        //10-05-15|0x01b4
          default:                                                                        //10-05-15|0x01b4
            SourceStatus = SystemError;                                                   //10-05-15|0x01b4
            SourceRunFlag = 0;                                                            //10-05-15|0x01b4
            SystemMsg;                                                                    //10-05-15|0x01b4
            break;                                                                        //10-05-15|0x01b4
        }                                                                                 //10-05-15|0x01b4
        break;                                                                            //10-05-15|0x01b4
//---------------------------------------------------------------------------             //07-02-02|0x01b5
      case 4284: // NO_TEXT                                                               //07-03-23|0x01b6
        switch(TextDoesNotExist)                                                          //07-03-23|0x01b6
        {                                                                                 //07-03-23|0x01b6
          case UserError:                                                                 //07-03-23|0x01b6
            SourceRunFlag = 1;                                                            //07-03-23|0x01b6
            SourceState = 5940; // CLS_LIB_USER                                           //07-03-23|0x01b6
            break;                                                                        //07-03-23|0x01b6
          default:                                                                        //07-03-23|0x01b6
            SourceStatus = SystemError;                                                   //07-03-23|0x01b6
            SourceRunFlag = 0;                                                            //07-03-23|0x01b6
            SystemMsg;                                                                    //07-03-23|0x01b6
            break;                                                                        //07-03-23|0x01b6
        }                                                                                 //07-03-23|0x01b6
        break;                                                                            //07-03-23|0x01b6
//---------------------------------------------------------------------------             //07-02-02|0x01b7
      case 31085: // OPEN_TEXT                                                            //10-06-11|0x01b8
        switch(OpenText)                                                                  //10-06-11|0x01b8
        {                                                                                 //10-06-11|0x01b8
          case Success:                                                                   //10-06-11|0x01b8
            SourceRunFlag = 1;                                                            //10-06-11|0x01b8
            SourceState = 7583; // OUT_NAMES                                              //10-06-11|0x01b8
            break;                                                                        //10-06-11|0x01b8
          case UserError:                                                                 //10-06-11|0x01b8
            SourceRunFlag = 1;                                                            //10-06-11|0x01b8
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x01b8
            break;                                                                        //10-06-11|0x01b8
          default:                                                                        //10-06-11|0x01b8
            SourceStatus = SystemError;                                                   //10-06-11|0x01b8
            SourceRunFlag = 0;                                                            //10-06-11|0x01b8
            SystemMsg;                                                                    //10-06-11|0x01b8
            break;                                                                        //10-06-11|0x01b8
        }                                                                                 //10-06-11|0x01b8
        break;                                                                            //10-06-11|0x01b8
//***************************************************************************             //10-06-11|0x01b9
//******                                                               ******             //10-06-11|0x01ba
//****** Process output files                                          ******             //10-06-11|0x01bb
//******---------------------------------------------------------------******             //10-06-11|0x01bc
//****** Process the output file names                                 ******             //10-06-11|0x01bd
//******                                                               ******             //10-06-11|0x01be
//***************************************************************************             //10-06-11|0x01bf
      case 7583: // OUT_NAMES                                                             //10-06-11|0x01c0
        switch(output_names())                                                            //10-06-11|0x01c0
        {                                                                                 //10-06-11|0x01c0
          case Success:                                                                   //10-06-11|0x01c0
            SourceRunFlag = 1;                                                            //10-06-11|0x01c0
            SourceState = 7419; // MAIL_DATE_TEST                                         //10-06-11|0x01c0
            break;                                                                        //10-06-11|0x01c0
          default:                                                                        //10-06-11|0x01c0
            SourceStatus = SystemError;                                                   //10-06-11|0x01c0
            SourceRunFlag = 0;                                                            //10-06-11|0x01c0
            SystemMsg;                                                                    //10-06-11|0x01c0
            break;                                                                        //10-06-11|0x01c0
        }                                                                                 //10-06-11|0x01c0
        break;                                                                            //10-06-11|0x01c0
//***************************************************************************             //10-06-11|0x01c1
//******                                                               ******             //10-06-11|0x01c2
//****** Process postoffices and mailboxes                             ******             //10-06-11|0x01c3
//******                                                               ******             //10-06-11|0x01c4
//***************************************************************************             //10-06-11|0x01c5
      case 7419: // MAIL_DATE_TEST                                                        //10-06-11|0x01c6
        switch(MailBoxTest)                                                               //10-06-11|0x01c6
        {                                                                                 //10-06-11|0x01c6
          case Yes:                                                                       //10-06-11|0x01c6
            SourceRunFlag = 1;                                                            //10-06-11|0x01c6
            SourceState = 60714; // MAILBOX_DATES                                         //10-06-11|0x01c6
            break;                                                                        //10-06-11|0x01c6
          case No:                                                                        //10-06-11|0x01c6
            SourceRunFlag = 1;                                                            //10-06-11|0x01c6
            SourceState = 49225; // OUT_TEST                                              //10-06-11|0x01c6
            break;                                                                        //10-06-11|0x01c6
          default:                                                                        //10-06-11|0x01c6
            SourceStatus = SystemError;                                                   //10-06-11|0x01c6
            SourceRunFlag = 0;                                                            //10-06-11|0x01c6
            SystemMsg;                                                                    //10-06-11|0x01c6
            break;                                                                        //10-06-11|0x01c6
        }                                                                                 //10-06-11|0x01c6
        break;                                                                            //10-06-11|0x01c6
//---------------------------------------------------------------------------             //10-06-11|0x01c7
      case 60714: // MAILBOX_DATES                                                        //10-06-11|0x01c8
        switch(MailBoxDates)                                                              //10-06-11|0x01c8
        {                                                                                 //10-06-11|0x01c8
          case Yes:                                                                       //10-06-11|0x01c8
            SourceRunFlag = 1;                                                            //10-06-11|0x01c8
            SourceState = 50520; // OUT_SETUP                                             //10-06-11|0x01c8
            break;                                                                        //10-06-11|0x01c8
          case No:                                                                        //10-06-11|0x01c8
            SourceRunFlag = 1;                                                            //10-06-11|0x01c8
            SourceState = 49225; // OUT_TEST                                              //10-06-11|0x01c8
            break;                                                                        //10-06-11|0x01c8
          case UserError:                                                                 //10-06-11|0x01c8
            SourceRunFlag = 1;                                                            //10-06-11|0x01c8
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x01c8
            break;                                                                        //10-06-11|0x01c8
          default:                                                                        //10-06-11|0x01c8
            SourceStatus = SystemError;                                                   //10-06-11|0x01c8
            SourceRunFlag = 0;                                                            //10-06-11|0x01c8
            SystemMsg;                                                                    //10-06-11|0x01c8
            break;                                                                        //10-06-11|0x01c8
        }                                                                                 //10-06-11|0x01c8
        break;                                                                            //10-06-11|0x01c8
//***************************************************************************             //10-06-11|0x01c9
//******                                                               ******             //10-06-11|0x01ca
//****** Process output files                                          ******             //10-06-11|0x01cb
//******---------------------------------------------------------------******             //10-06-11|0x01cc
//****** Process the output file dates                                 ******             //10-06-11|0x01cd
//******                                                               ******             //10-06-11|0x01ce
//***************************************************************************             //10-06-11|0x01cf
      case 50520: // OUT_SETUP                                                            //10-06-11|0x01d0
        switch(output_dates())                                                            //10-06-11|0x01d0
        {                                                                                 //10-06-11|0x01d0
          case Yes:                                                                       //10-06-11|0x01d0
            SourceRunFlag = 1;                                                            //10-06-11|0x01d0
            SourceState = 6999; // OPEN_DISPLAY                                           //10-06-11|0x01d0
            break;                                                                        //10-06-11|0x01d0
          case No:                                                                        //10-06-11|0x01d0
            SourceRunFlag = 1;                                                            //10-06-11|0x01d0
            SourceState = 6999; // OPEN_DISPLAY                                           //10-06-11|0x01d0
            break;                                                                        //10-06-11|0x01d0
          default:                                                                        //10-06-11|0x01d0
            SourceStatus = SystemError;                                                   //10-06-11|0x01d0
            SourceRunFlag = 0;                                                            //10-06-11|0x01d0
            SystemMsg;                                                                    //10-06-11|0x01d0
            break;                                                                        //10-06-11|0x01d0
        }                                                                                 //10-06-11|0x01d0
        break;                                                                            //10-06-11|0x01d0
//---------------------------------------------------------------------------             //10-06-11|0x01d1
      case 49225: // OUT_TEST                                                             //10-06-11|0x01d2
        switch(output_dates())                                                            //10-06-11|0x01d2
        {                                                                                 //10-06-11|0x01d2
          case Yes:                                                                       //10-06-11|0x01d2
            SourceRunFlag = 1;                                                            //10-06-11|0x01d2
            SourceState = 6999; // OPEN_DISPLAY                                           //10-06-11|0x01d2
            break;                                                                        //10-06-11|0x01d2
          case No:                                                                        //10-06-11|0x01d2
            SourceRunFlag = 1;                                                            //10-06-11|0x01d2
            SourceState = 53574; // MAILBOX_TEST                                          //10-06-11|0x01d2
            break;                                                                        //10-06-11|0x01d2
          default:                                                                        //10-06-11|0x01d2
            SourceStatus = SystemError;                                                   //10-06-11|0x01d2
            SourceRunFlag = 0;                                                            //10-06-11|0x01d2
            SystemMsg;                                                                    //10-06-11|0x01d2
            break;                                                                        //10-06-11|0x01d2
        }                                                                                 //10-06-11|0x01d2
        break;                                                                            //10-06-11|0x01d2
//***************************************************************************             //09-03-10|0x01d3
//******                                                               ******             //09-03-10|0x01d4
//****** Turn on display                                               ******             //09-03-10|0x01d5
//******                                                               ******             //09-03-10|0x01d6
//***************************************************************************             //09-03-10|0x01d7
      case 6999: // OPEN_DISPLAY                                                          //08-04-17|0x01d8
        if(display_flag) DisplayOn();                                                     //08-04-17|0x01d8
        SourceState = 58917; // OPEN_SOURCE                                               //08-04-17|0x01d8
        break;                                                                            //08-04-17|0x01d8
//***************************************************************************             //06-09-25|0x01d9
//******                                                               ******             //06-09-25|0x01da
//****** Open Source File                                              ******             //06-09-25|0x01db
//******                                                               ******             //06-09-25|0x01dc
//***************************************************************************             //06-09-25|0x01dd
      case 58917: // OPEN_SOURCE                                                          //06-09-25|0x01de
        switch(OpenSource)                                                                //06-09-25|0x01de
        {                                                                                 //06-09-25|0x01de
          case Success:                                                                   //06-09-25|0x01de
            SourceRunFlag = 1;                                                            //06-09-25|0x01de
            SourceState = 18676; // DICT_NAME                                             //06-09-25|0x01de
            break;                                                                        //06-09-25|0x01de
          default:                                                                        //06-09-25|0x01de
            SourceStatus = SystemError;                                                   //06-09-25|0x01de
            SourceRunFlag = 0;                                                            //06-09-25|0x01de
            SystemMsg;                                                                    //06-09-25|0x01de
            break;                                                                        //06-09-25|0x01de
        }                                                                                 //06-09-25|0x01de
        break;                                                                            //06-09-25|0x01de
//***************************************************************************             //06-09-25|0x01df
//******                                                               ******             //06-09-25|0x01e0
//****** Open dictionary                                               ******             //06-09-25|0x01e1
//******                                                               ******             //06-09-25|0x01e2
//***************************************************************************             //06-09-25|0x01e3
      case 18676: // DICT_NAME                                                            //06-09-25|0x01e4
        switch(EnterDictFileName)                                                         //06-09-25|0x01e4
        {                                                                                 //06-09-25|0x01e4
          case Success:                                                                   //06-09-25|0x01e4
            SourceRunFlag = 1;                                                            //06-09-25|0x01e4
            SourceState = 55475; // OPEN_DICT                                             //06-09-25|0x01e4
            break;                                                                        //06-09-25|0x01e4
          default:                                                                        //06-09-25|0x01e4
            SourceStatus = SystemError;                                                   //06-09-25|0x01e4
            SourceRunFlag = 0;                                                            //06-09-25|0x01e4
            SystemMsg;                                                                    //06-09-25|0x01e4
            break;                                                                        //06-09-25|0x01e4
        }                                                                                 //06-09-25|0x01e4
        break;                                                                            //06-09-25|0x01e4
//---------------------------------------------------------------------------             //06-09-25|0x01e5
      case 55475: // OPEN_DICT                                                            //10-03-22|0x01e6
        switch(SrceDictCreate())                                                          //10-03-22|0x01e6
        {                                                                                 //10-03-22|0x01e6
          case Success:                                                                   //10-03-22|0x01e6
            SourceRunFlag = 1;                                                            //10-03-22|0x01e6
            SourceState = 25698; // INITIAL_CRYPTO                                        //10-03-22|0x01e6
            break;                                                                        //10-03-22|0x01e6
          default:                                                                        //10-03-22|0x01e6
            SourceStatus = SystemError;                                                   //10-03-22|0x01e6
            SourceRunFlag = 0;                                                            //10-03-22|0x01e6
            SystemMsg;                                                                    //10-03-22|0x01e6
            break;                                                                        //10-03-22|0x01e6
        }                                                                                 //10-03-22|0x01e6
        break;                                                                            //10-03-22|0x01e6
//***************************************************************************             //10-03-22|0x01e7
//******                                                               ******             //10-03-22|0x01e8
//****** Initial Crypto                                                ******             //10-03-22|0x01e9
//******                                                               ******             //10-03-22|0x01ea
//***************************************************************************             //10-03-22|0x01eb
      case 25698: // INITIAL_CRYPTO                                                       //11-05-30|0x01ec
        switch(InitialCryptofile)                                                         //11-05-30|0x01ec
        {                                                                                 //11-05-30|0x01ec
          case Success:                                                                   //11-05-30|0x01ec
            SourceRunFlag = 1;                                                            //11-05-30|0x01ec
            SourceState = 43777; // INIT_BUFFER_OUT                                       //11-05-30|0x01ec
            break;                                                                        //11-05-30|0x01ec
          default:                                                                        //11-05-30|0x01ec
            SourceStatus = SystemError;                                                   //11-05-30|0x01ec
            SourceRunFlag = 0;                                                            //11-05-30|0x01ec
            SystemMsg;                                                                    //11-05-30|0x01ec
            break;                                                                        //11-05-30|0x01ec
        }                                                                                 //11-05-30|0x01ec
        break;                                                                            //11-05-30|0x01ec
//***************************************************************************             //10-03-22|0x01ed
//******                                                               ******             //10-03-22|0x01ee
//****** Initial Buffer Out                                            ******             //10-03-22|0x01ef
//******                                                               ******             //10-03-22|0x01f0
//***************************************************************************             //10-03-22|0x01f1
      case 43777: // INIT_BUFFER_OUT                                                      //check   |0x01f2
        switch(InitialOutBufferfile)                                                      //check   |0x01f2
        {                                                                                 //check   |0x01f2
          case Success:                                                                   //check   |0x01f2
            SourceRunFlag = 1;                                                            //check   |0x01f2
            SourceState = 23440; // PUSH_STACK                                            //check   |0x01f2
            break;                                                                        //check   |0x01f2
          default:                                                                        //check   |0x01f2
            SourceStatus = SystemError;                                                   //check   |0x01f2
            SourceRunFlag = 0;                                                            //check   |0x01f2
            SystemMsg;                                                                    //check   |0x01f2
            break;                                                                        //check   |0x01f2
        }                                                                                 //check   |0x01f2
        break;                                                                            //check   |0x01f2
//***************************************************************************             //06-09-25|0x01f3
//******                                                               ******             //06-09-25|0x01f4
//****** Push Stack                                                    ******             //06-09-25|0x01f5
//******                                                               ******             //06-09-25|0x01f6
//***************************************************************************             //06-09-25|0x01f7
      case 23440: // PUSH_STACK                                                           //06-09-26|0x01f8
        switch(push_call())                                                               //06-09-26|0x01f8
        {                                                                                 //06-09-26|0x01f8
          case Success:                                                                   //06-09-26|0x01f8
            SourceRunFlag = 1;                                                            //06-09-26|0x01f8
            SourceState = 5391; // PROCESS_SOURCE                                         //06-09-26|0x01f8
            break;                                                                        //06-09-26|0x01f8
          default:                                                                        //06-09-26|0x01f8
            SourceStatus = SystemError;                                                   //06-09-26|0x01f8
            SourceRunFlag = 0;                                                            //06-09-26|0x01f8
            SystemMsg;                                                                    //06-09-26|0x01f8
            break;                                                                        //06-09-26|0x01f8
        }                                                                                 //06-09-26|0x01f8
        break;                                                                            //06-09-26|0x01f8
//***************************************************************************             //06-09-26|0x01f9
//******                                                               ******             //06-09-26|0x01fa
//****** Create Output files                                           ******             //06-09-26|0x01fb
//******                                                               ******             //06-09-26|0x01fc
//***************************************************************************             //06-09-26|0x01fd
      case 5391: // PROCESS_SOURCE                                                        //check   |0x01fe
        switch(ProcessSource)                                                             //check   |0x01fe
        {                                                                                 //check   |0x01fe
          case Display:                                                                   //check   |0x01fe
            SourceState = 26238; // PROCESS_SOURCE_EXIT                                   //check   |0x01fe
            SourceStatus = Display;                                                       //check   |0x01fe
            SourceRunFlag = 0;                                                            //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case KeyBoard:                                                                  //check   |0x01fe
            SourceState = 26238; // PROCESS_SOURCE_EXIT                                   //check   |0x01fe
            SourceStatus = KeyBoard;                                                      //check   |0x01fe
            SourceRunFlag = 0;                                                            //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case Success:                                                                   //check   |0x01fe
            SourceRunFlag = 1;                                                            //check   |0x01fe
            SourceState = 52957; // TEST_OUT_STATUS                                       //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case BuildError:                                                                //check   |0x01fe
            SourceRunFlag = 1;                                                            //check   |0x01fe
            SourceState = 48428; // BUILD_DISP                                            //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case UserError:                                                                 //check   |0x01fe
            SourceRunFlag = 1;                                                            //check   |0x01fe
            SourceState = 36971; // USER_DISP                                             //check   |0x01fe
            break;                                                                        //check   |0x01fe
          default:                                                                        //check   |0x01fe
            SourceStatus = SystemError;                                                   //check   |0x01fe
            SourceRunFlag = 0;                                                            //check   |0x01fe
            SystemMsg;                                                                    //check   |0x01fe
            break;                                                                        //check   |0x01fe
        }                                                                                 //check   |0x01fe
        break;                                                                            //check   |0x01fe
//**************************************************************************              //check   |0x01fe
      case 26238: // PROCESS_SOURCE_EXIT                                                  //check   |0x01fe
        switch(ProcessSource)                                                             //check   |0x01fe
        {                                                                                 //check   |0x01fe
          case Display:                                                                   //check   |0x01fe
            SourceState = 26238; // PROCESS_SOURCE_EXIT                                   //check   |0x01fe
            SourceStatus = Display;                                                       //check   |0x01fe
            SourceRunFlag = 0;                                                            //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case KeyBoard:                                                                  //check   |0x01fe
            SourceState = 26238; // PROCESS_SOURCE_EXIT                                   //check   |0x01fe
            SourceStatus = KeyBoard;                                                      //check   |0x01fe
            SourceRunFlag = 0;                                                            //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case Success:                                                                   //check   |0x01fe
            SourceRunFlag = 1;                                                            //check   |0x01fe
            SourceState = 52957; // TEST_OUT_STATUS                                       //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case BuildError:                                                                //check   |0x01fe
            SourceRunFlag = 1;                                                            //check   |0x01fe
            SourceState = 48428; // BUILD_DISP                                            //check   |0x01fe
            break;                                                                        //check   |0x01fe
          case UserError:                                                                 //check   |0x01fe
            SourceRunFlag = 1;                                                            //check   |0x01fe
            SourceState = 36971; // USER_DISP                                             //check   |0x01fe
            break;                                                                        //check   |0x01fe
          default:                                                                        //check   |0x01fe
            SourceStatus = SystemError;                                                   //check   |0x01fe
            SourceRunFlag = 0;                                                            //check   |0x01fe
            SystemMsg;                                                                    //check   |0x01fe
            break;                                                                        //check   |0x01fe
        }                                                                                 //check   |0x01fe
        break;                                                                            //check   |0x01fe
//***************************************************************************             //check   |0x01ff
//******                                                               ******             //check   |0x0200
//****** Test Output File Status Create Output files                   ******             //check   |0x0201
//******                                                               ******             //check   |0x0202
//***************************************************************************             //check   |0x0203
      case 52957: // TEST_OUT_STATUS                                                      //check   |0x0204
        switch(TestOutStatus)                                                             //check   |0x0204
        {                                                                                 //check   |0x0204
          case Success:                                                                   //check   |0x0204
            SourceRunFlag = 1;                                                            //check   |0x0204
            SourceState = 38810; // POP_STACK                                             //check   |0x0204
            break;                                                                        //check   |0x0204
          case UserError:                                                                 //check   |0x0204
            SourceRunFlag = 1;                                                            //check   |0x0204
            SourceState = 36971; // USER_DISP                                             //check   |0x0204
            break;                                                                        //check   |0x0204
          default:                                                                        //check   |0x0204
            SourceStatus = SystemError;                                                   //check   |0x0204
            SourceRunFlag = 0;                                                            //check   |0x0204
            SystemMsg;                                                                    //check   |0x0204
            break;                                                                        //check   |0x0204
        }                                                                                 //check   |0x0204
        break;                                                                            //check   |0x0204
//***************************************************************************             //09-12-26|0x0205
//******                                                               ******             //09-12-26|0x0206
//****** Process User Error Messages                                   ******             //09-12-26|0x0207
//******                                                               ******             //09-12-26|0x0208
//***************************************************************************             //09-12-26|0x0209
      case 48428: // BUILD_DISP                                                           //09-12-26|0x020a
        switch(MsgTest)                                                                   //09-12-26|0x020a
        {                                                                                 //09-12-26|0x020a
          case No:                                                                        //09-12-26|0x020a
            SourceState = 4537; // BUILD_DISP_EXIT                                        //09-12-26|0x020a
            SourceStatus = Display;                                                       //09-12-26|0x020a
            SourceRunFlag = 0;                                                            //09-12-26|0x020a
            break;                                                                        //09-12-26|0x020a
          case Yes:                                                                       //09-12-26|0x020a
            SourceRunFlag = 1;                                                            //09-12-26|0x020a
            SourceState = 11720; // POP_BUILD                                             //09-12-26|0x020a
            break;                                                                        //09-12-26|0x020a
          default:                                                                        //09-12-26|0x020a
            SourceStatus = SystemError;                                                   //09-12-26|0x020a
            SourceRunFlag = 0;                                                            //09-12-26|0x020a
            SystemMsg;                                                                    //09-12-26|0x020a
            break;                                                                        //09-12-26|0x020a
        }                                                                                 //09-12-26|0x020a
        break;                                                                            //09-12-26|0x020a
//**************************************************************************              //09-12-26|0x020a
      case 4537: // BUILD_DISP_EXIT                                                       //09-12-26|0x020a
        switch(MsgTest)                                                                   //09-12-26|0x020a
        {                                                                                 //09-12-26|0x020a
          case No:                                                                        //09-12-26|0x020a
            SourceState = 4537; // BUILD_DISP_EXIT                                        //09-12-26|0x020a
            SourceStatus = Display;                                                       //09-12-26|0x020a
            SourceRunFlag = 0;                                                            //09-12-26|0x020a
            break;                                                                        //09-12-26|0x020a
          case Yes:                                                                       //09-12-26|0x020a
            SourceRunFlag = 1;                                                            //09-12-26|0x020a
            SourceState = 11720; // POP_BUILD                                             //09-12-26|0x020a
            break;                                                                        //09-12-26|0x020a
          default:                                                                        //09-12-26|0x020a
            SourceStatus = SystemError;                                                   //09-12-26|0x020a
            SourceRunFlag = 0;                                                            //09-12-26|0x020a
            SystemMsg;                                                                    //09-12-26|0x020a
            break;                                                                        //09-12-26|0x020a
        }                                                                                 //09-12-26|0x020a
        break;                                                                            //09-12-26|0x020a
//---------------------------------------------------------------------------             //09-12-26|0x020b
      case 36971: // USER_DISP                                                            //09-12-26|0x020c
        switch(MsgTest)                                                                   //09-12-26|0x020c
        {                                                                                 //09-12-26|0x020c
          case No:                                                                        //09-12-26|0x020c
            SourceState = 2759; // USER_DISP_EXIT                                         //09-12-26|0x020c
            SourceStatus = Display;                                                       //09-12-26|0x020c
            SourceRunFlag = 0;                                                            //09-12-26|0x020c
            break;                                                                        //09-12-26|0x020c
          case Yes:                                                                       //09-12-26|0x020c
            SourceRunFlag = 1;                                                            //09-12-26|0x020c
            SourceState = 47030; // POP_USER                                              //09-12-26|0x020c
            break;                                                                        //09-12-26|0x020c
          default:                                                                        //09-12-26|0x020c
            SourceStatus = SystemError;                                                   //09-12-26|0x020c
            SourceRunFlag = 0;                                                            //09-12-26|0x020c
            SystemMsg;                                                                    //09-12-26|0x020c
            break;                                                                        //09-12-26|0x020c
        }                                                                                 //09-12-26|0x020c
        break;                                                                            //09-12-26|0x020c
//**************************************************************************              //09-12-26|0x020c
      case 2759: // USER_DISP_EXIT                                                        //09-12-26|0x020c
        switch(MsgTest)                                                                   //09-12-26|0x020c
        {                                                                                 //09-12-26|0x020c
          case No:                                                                        //09-12-26|0x020c
            SourceState = 2759; // USER_DISP_EXIT                                         //09-12-26|0x020c
            SourceStatus = Display;                                                       //09-12-26|0x020c
            SourceRunFlag = 0;                                                            //09-12-26|0x020c
            break;                                                                        //09-12-26|0x020c
          case Yes:                                                                       //09-12-26|0x020c
            SourceRunFlag = 1;                                                            //09-12-26|0x020c
            SourceState = 47030; // POP_USER                                              //09-12-26|0x020c
            break;                                                                        //09-12-26|0x020c
          default:                                                                        //09-12-26|0x020c
            SourceStatus = SystemError;                                                   //09-12-26|0x020c
            SourceRunFlag = 0;                                                            //09-12-26|0x020c
            SystemMsg;                                                                    //09-12-26|0x020c
            break;                                                                        //09-12-26|0x020c
        }                                                                                 //09-12-26|0x020c
        break;                                                                            //09-12-26|0x020c
//***************************************************************************             //06-09-30|0x020d
//******                                                               ******             //06-09-30|0x020e
//****** Pop Stack                                                     ******             //06-09-30|0x020f
//******                                                               ******             //06-09-30|0x0210
//***************************************************************************             //06-09-30|0x0211
      case 38810: // POP_STACK                                                            //08-04-18|0x0212
        switch(pop_call())                                                                //08-04-18|0x0212
        {                                                                                 //08-04-18|0x0212
          case Success:                                                                   //08-04-18|0x0212
            SourceRunFlag = 1;                                                            //08-04-18|0x0212
            SourceState = 13205; // CLOSE_OUT                                             //08-04-18|0x0212
            break;                                                                        //08-04-18|0x0212
          default:                                                                        //08-04-18|0x0212
            SourceStatus = SystemError;                                                   //08-04-18|0x0212
            SourceRunFlag = 0;                                                            //08-04-18|0x0212
            SystemMsg;                                                                    //08-04-18|0x0212
            break;                                                                        //08-04-18|0x0212
        }                                                                                 //08-04-18|0x0212
        break;                                                                            //08-04-18|0x0212
//---------------------------------------------------------------------------             //06-10-06|0x0213
      case 11720: // POP_BUILD                                                            //08-04-18|0x0214
        switch(pop_call())                                                                //08-04-18|0x0214
        {                                                                                 //08-04-18|0x0214
          case Success:                                                                   //08-04-18|0x0214
            SourceRunFlag = 1;                                                            //08-04-18|0x0214
            SourceState = 28004; // CLS_OUT_BUILD                                         //08-04-18|0x0214
            break;                                                                        //08-04-18|0x0214
          default:                                                                        //08-04-18|0x0214
            SourceStatus = SystemError;                                                   //08-04-18|0x0214
            SourceRunFlag = 0;                                                            //08-04-18|0x0214
            SystemMsg;                                                                    //08-04-18|0x0214
            break;                                                                        //08-04-18|0x0214
        }                                                                                 //08-04-18|0x0214
        break;                                                                            //08-04-18|0x0214
//---------------------------------------------------------------------------             //06-09-30|0x0215
      case 47030: // POP_USER                                                             //08-04-18|0x0216
        switch(pop_call())                                                                //08-04-18|0x0216
        {                                                                                 //08-04-18|0x0216
          case Success:                                                                   //08-04-18|0x0216
            SourceRunFlag = 1;                                                            //08-04-18|0x0216
            SourceState = 17443; // CLS_OUT_USER                                          //08-04-18|0x0216
            break;                                                                        //08-04-18|0x0216
          default:                                                                        //08-04-18|0x0216
            SourceStatus = SystemError;                                                   //08-04-18|0x0216
            SourceRunFlag = 0;                                                            //08-04-18|0x0216
            SystemMsg;                                                                    //08-04-18|0x0216
            break;                                                                        //08-04-18|0x0216
        }                                                                                 //08-04-18|0x0216
        break;                                                                            //08-04-18|0x0216
//***************************************************************************             //08-04-18|0x0217
//******                                                               ******             //08-04-18|0x0218
//****** Close output files                                            ******             //08-04-18|0x0219
//******                                                               ******             //08-04-18|0x021a
//***************************************************************************             //08-04-18|0x021b
      case 13205: // CLOSE_OUT                                                            //08-04-18|0x021c
        switch(CloseOutFiles)                                                             //08-04-18|0x021c
        {                                                                                 //08-04-18|0x021c
          case Success:                                                                   //08-04-18|0x021c
            SourceRunFlag = 1;                                                            //08-04-18|0x021c
            SourceState = 34514; // CLOSE_DICT                                            //08-04-18|0x021c
            break;                                                                        //08-04-18|0x021c
          default:                                                                        //08-04-18|0x021c
            SourceStatus = SystemError;                                                   //08-04-18|0x021c
            SourceRunFlag = 0;                                                            //08-04-18|0x021c
            SystemMsg;                                                                    //08-04-18|0x021c
            break;                                                                        //08-04-18|0x021c
        }                                                                                 //08-04-18|0x021c
        break;                                                                            //08-04-18|0x021c
//---------------------------------------------------------------------------             //08-04-18|0x021d
      case 28004: // CLS_OUT_BUILD                                                        //08-04-18|0x021e
        switch(CloseOutFiles)                                                             //08-04-18|0x021e
        {                                                                                 //08-04-18|0x021e
          case Success:                                                                   //08-04-18|0x021e
            SourceRunFlag = 1;                                                            //08-04-18|0x021e
            SourceState = 62577; // CLS_DICT_BUILD                                        //08-04-18|0x021e
            break;                                                                        //08-04-18|0x021e
          default:                                                                        //08-04-18|0x021e
            SourceStatus = SystemError;                                                   //08-04-18|0x021e
            SourceRunFlag = 0;                                                            //08-04-18|0x021e
            SystemMsg;                                                                    //08-04-18|0x021e
            break;                                                                        //08-04-18|0x021e
        }                                                                                 //08-04-18|0x021e
        break;                                                                            //08-04-18|0x021e
//---------------------------------------------------------------------------             //08-04-18|0x021f
      case 17443: // CLS_OUT_USER                                                         //08-04-18|0x0220
        switch(CloseOutFiles)                                                             //08-04-18|0x0220
        {                                                                                 //08-04-18|0x0220
          case Success:                                                                   //08-04-18|0x0220
            SourceRunFlag = 1;                                                            //08-04-18|0x0220
            SourceState = 15360; // CLS_DICT_USER                                         //08-04-18|0x0220
            break;                                                                        //08-04-18|0x0220
          default:                                                                        //08-04-18|0x0220
            SourceStatus = SystemError;                                                   //08-04-18|0x0220
            SourceRunFlag = 0;                                                            //08-04-18|0x0220
            SystemMsg;                                                                    //08-04-18|0x0220
            break;                                                                        //08-04-18|0x0220
        }                                                                                 //08-04-18|0x0220
        break;                                                                            //08-04-18|0x0220
//***************************************************************************             //06-09-30|0x0221
//******                                                               ******             //06-09-30|0x0222
//****** Close and Delete dictionary                                   ******             //06-09-30|0x0223
//******                                                               ******             //06-09-30|0x0224
//***************************************************************************             //06-09-30|0x0225
      case 34514: // CLOSE_DICT                                                           //10-03-22|0x0226
        switch(SrceDictClose())                                                           //10-03-22|0x0226
        {                                                                                 //10-03-22|0x0226
          case Success:                                                                   //10-03-22|0x0226
            SourceRunFlag = 1;                                                            //10-03-22|0x0226
            SourceState = 64639; // CLOSE_CRYPTO                                          //10-03-22|0x0226
            break;                                                                        //10-03-22|0x0226
          default:                                                                        //10-03-22|0x0226
            SourceStatus = SystemError;                                                   //10-03-22|0x0226
            SourceRunFlag = 0;                                                            //10-03-22|0x0226
            SystemMsg;                                                                    //10-03-22|0x0226
            break;                                                                        //10-03-22|0x0226
        }                                                                                 //10-03-22|0x0226
        break;                                                                            //10-03-22|0x0226
//---------------------------------------------------------------------------             //06-10-06|0x0227
      case 62577: // CLS_DICT_BUILD                                                       //10-03-22|0x0228
        switch(SrceDictClose())                                                           //10-03-22|0x0228
        {                                                                                 //10-03-22|0x0228
          case Success:                                                                   //10-03-22|0x0228
            SourceRunFlag = 1;                                                            //10-03-22|0x0228
            SourceState = 50414; // CLS_CRY_BUILD                                         //10-03-22|0x0228
            break;                                                                        //10-03-22|0x0228
          default:                                                                        //10-03-22|0x0228
            SourceStatus = SystemError;                                                   //10-03-22|0x0228
            SourceRunFlag = 0;                                                            //10-03-22|0x0228
            SystemMsg;                                                                    //10-03-22|0x0228
            break;                                                                        //10-03-22|0x0228
        }                                                                                 //10-03-22|0x0228
        break;                                                                            //10-03-22|0x0228
//---------------------------------------------------------------------------             //06-09-30|0x0229
      case 15360: // CLS_DICT_USER                                                        //10-03-22|0x022a
        switch(SrceDictClose())                                                           //10-03-22|0x022a
        {                                                                                 //10-03-22|0x022a
          case Success:                                                                   //10-03-22|0x022a
            SourceRunFlag = 1;                                                            //10-03-22|0x022a
            SourceState = 5197; // CLS_CRY_USER                                           //10-03-22|0x022a
            break;                                                                        //10-03-22|0x022a
          default:                                                                        //10-03-22|0x022a
            SourceStatus = SystemError;                                                   //10-03-22|0x022a
            SourceRunFlag = 0;                                                            //10-03-22|0x022a
            SystemMsg;                                                                    //10-03-22|0x022a
            break;                                                                        //10-03-22|0x022a
        }                                                                                 //10-03-22|0x022a
        break;                                                                            //10-03-22|0x022a
//***************************************************************************             //10-03-22|0x022b
//******                                                               ******             //10-03-22|0x022c
//****** Close and Delete crypto                                       ******             //10-03-22|0x022d
//******                                                               ******             //10-03-22|0x022e
//***************************************************************************             //10-03-22|0x022f
      case 64639: // CLOSE_CRYPTO                                                         //11-05-30|0x0230
        switch(CryptoDelete())                                                            //11-05-30|0x0230
        {                                                                                 //11-05-30|0x0230
          case Success:                                                                   //11-05-30|0x0230
            SourceRunFlag = 1;                                                            //11-05-30|0x0230
            SourceState = 22940; // CLOSE_BUFFER                                          //11-05-30|0x0230
            break;                                                                        //11-05-30|0x0230
          default:                                                                        //11-05-30|0x0230
            SourceStatus = SystemError;                                                   //11-05-30|0x0230
            SourceRunFlag = 0;                                                            //11-05-30|0x0230
            SystemMsg;                                                                    //11-05-30|0x0230
            break;                                                                        //11-05-30|0x0230
        }                                                                                 //11-05-30|0x0230
        break;                                                                            //11-05-30|0x0230
//---------------------------------------------------------------------------             //11-05-30|0x0231
      case 50414: // CLS_CRY_BUILD                                                        //11-05-30|0x0232
        switch(CryptoDelete())                                                            //11-05-30|0x0232
        {                                                                                 //11-05-30|0x0232
          case Success:                                                                   //11-05-30|0x0232
            SourceRunFlag = 1;                                                            //11-05-30|0x0232
            SourceState = 62427; // CLS_BUFFER_BUILD                                      //11-05-30|0x0232
            break;                                                                        //11-05-30|0x0232
          default:                                                                        //11-05-30|0x0232
            SourceStatus = SystemError;                                                   //11-05-30|0x0232
            SourceRunFlag = 0;                                                            //11-05-30|0x0232
            SystemMsg;                                                                    //11-05-30|0x0232
            break;                                                                        //11-05-30|0x0232
        }                                                                                 //11-05-30|0x0232
        break;                                                                            //11-05-30|0x0232
//---------------------------------------------------------------------------             //11-05-30|0x0233
      case 5197: // CLS_CRY_USER                                                          //11-05-30|0x0234
        switch(CryptoDelete())                                                            //11-05-30|0x0234
        {                                                                                 //11-05-30|0x0234
          case Success:                                                                   //11-05-30|0x0234
            SourceRunFlag = 1;                                                            //11-05-30|0x0234
            SourceState = 12810; // CLS_BUFFER_USER                                       //11-05-30|0x0234
            break;                                                                        //11-05-30|0x0234
          default:                                                                        //11-05-30|0x0234
            SourceStatus = SystemError;                                                   //11-05-30|0x0234
            SourceRunFlag = 0;                                                            //11-05-30|0x0234
            SystemMsg;                                                                    //11-05-30|0x0234
            break;                                                                        //11-05-30|0x0234
        }                                                                                 //11-05-30|0x0234
        break;                                                                            //11-05-30|0x0234
//***************************************************************************             //11-05-30|0x0235
//******                                                               ******             //11-05-30|0x0236
//****** Close and Delete buffer out                                   ******             //11-05-30|0x0237
//******                                                               ******             //11-05-30|0x0238
//***************************************************************************             //11-05-30|0x0239
      case 22940: // CLOSE_BUFFER                                                         //check   |0x023a
        switch(CloseOutBufferFile)                                                        //check   |0x023a
        {                                                                                 //check   |0x023a
          case Success:                                                                   //check   |0x023a
            SourceRunFlag = 1;                                                            //check   |0x023a
            SourceState = 21289; // CLOSE_TEXT                                            //check   |0x023a
            break;                                                                        //check   |0x023a
          default:                                                                        //check   |0x023a
            SourceStatus = SystemError;                                                   //check   |0x023a
            SourceRunFlag = 0;                                                            //check   |0x023a
            SystemMsg;                                                                    //check   |0x023a
            break;                                                                        //check   |0x023a
        }                                                                                 //check   |0x023a
        break;                                                                            //check   |0x023a
//---------------------------------------------------------------------------             //check   |0x023b
      case 62427: // CLS_BUFFER_BUILD                                                     //check   |0x023c
        switch(CloseOutBufferFile)                                                        //check   |0x023c
        {                                                                                 //check   |0x023c
          case Success:                                                                   //check   |0x023c
            SourceRunFlag = 1;                                                            //check   |0x023c
            SourceState = 34360; // CLS_TXT_BUILD                                         //check   |0x023c
            break;                                                                        //check   |0x023c
          default:                                                                        //check   |0x023c
            SourceStatus = SystemError;                                                   //check   |0x023c
            SourceRunFlag = 0;                                                            //check   |0x023c
            SystemMsg;                                                                    //check   |0x023c
            break;                                                                        //check   |0x023c
        }                                                                                 //check   |0x023c
        break;                                                                            //check   |0x023c
//---------------------------------------------------------------------------             //check   |0x023d
      case 12810: // CLS_BUFFER_USER                                                      //check   |0x023e
        switch(CloseOutBufferFile)                                                        //check   |0x023e
        {                                                                                 //check   |0x023e
          case Success:                                                                   //check   |0x023e
            SourceRunFlag = 1;                                                            //check   |0x023e
            SourceState = 59959; // CLS_TXT_USER                                          //check   |0x023e
            break;                                                                        //check   |0x023e
          default:                                                                        //check   |0x023e
            SourceStatus = SystemError;                                                   //check   |0x023e
            SourceRunFlag = 0;                                                            //check   |0x023e
            SystemMsg;                                                                    //check   |0x023e
            break;                                                                        //check   |0x023e
        }                                                                                 //check   |0x023e
        break;                                                                            //check   |0x023e
//***************************************************************************             //07-01-30|0x023f
//******                                                               ******             //07-01-30|0x0240
//****** Close text                                                    ******             //07-01-30|0x0241
//******                                                               ******             //07-01-30|0x0242
//***************************************************************************             //07-01-30|0x0243
      case 21289: // CLOSE_TEXT                                                           //10-05-15|0x0244
        switch(CloseText)                                                                 //10-05-15|0x0244
        {                                                                                 //10-05-15|0x0244
          case Success:                                                                   //10-05-15|0x0244
            SourceRunFlag = 1;                                                            //10-05-15|0x0244
            SourceState = 36390; // CLOSE_SOURCE                                          //10-05-15|0x0244
            break;                                                                        //10-05-15|0x0244
          default:                                                                        //10-05-15|0x0244
            SourceStatus = SystemError;                                                   //10-05-15|0x0244
            SourceRunFlag = 0;                                                            //10-05-15|0x0244
            SystemMsg;                                                                    //10-05-15|0x0244
            break;                                                                        //10-05-15|0x0244
        }                                                                                 //10-05-15|0x0244
        break;                                                                            //10-05-15|0x0244
//---------------------------------------------------------------------------             //07-01-30|0x0245
      case 34360: // CLS_TXT_BUILD                                                        //10-05-15|0x0246
        switch(CloseText)                                                                 //10-05-15|0x0246
        {                                                                                 //10-05-15|0x0246
          case Success:                                                                   //10-05-15|0x0246
            SourceRunFlag = 1;                                                            //10-05-15|0x0246
            SourceState = 28933; // CLS_SRC_BUILD                                         //10-05-15|0x0246
            break;                                                                        //10-05-15|0x0246
          default:                                                                        //10-05-15|0x0246
            SourceStatus = SystemError;                                                   //10-05-15|0x0246
            SourceRunFlag = 0;                                                            //10-05-15|0x0246
            SystemMsg;                                                                    //10-05-15|0x0246
            break;                                                                        //10-05-15|0x0246
        }                                                                                 //10-05-15|0x0246
        break;                                                                            //10-05-15|0x0246
//---------------------------------------------------------------------------             //07-03-23|0x0247
      case 59959: // CLS_TXT_USER                                                         //10-05-15|0x0248
        switch(CloseText)                                                                 //10-05-15|0x0248
        {                                                                                 //10-05-15|0x0248
          case Success:                                                                   //10-05-15|0x0248
            SourceRunFlag = 1;                                                            //10-05-15|0x0248
            SourceState = 33236; // CLS_SRC_USER                                          //10-05-15|0x0248
            break;                                                                        //10-05-15|0x0248
          default:                                                                        //10-05-15|0x0248
            SourceStatus = SystemError;                                                   //10-05-15|0x0248
            SourceRunFlag = 0;                                                            //10-05-15|0x0248
            SystemMsg;                                                                    //10-05-15|0x0248
            break;                                                                        //10-05-15|0x0248
        }                                                                                 //10-05-15|0x0248
        break;                                                                            //10-05-15|0x0248
//***************************************************************************             //06-09-30|0x0249
//******                                                               ******             //06-09-30|0x024a
//****** Close source                                                  ******             //06-09-30|0x024b
//******                                                               ******             //06-09-30|0x024c
//***************************************************************************             //06-09-30|0x024d
      case 36390: // CLOSE_SOURCE                                                         //09-03-10|0x024e
        switch(CloseSource)                                                               //09-03-10|0x024e
        {                                                                                 //09-03-10|0x024e
          case Success:                                                                   //09-03-10|0x024e
            SourceRunFlag = 1;                                                            //09-03-10|0x024e
            SourceState = 53574; // MAILBOX_TEST                                          //09-03-10|0x024e
            break;                                                                        //09-03-10|0x024e
          default:                                                                        //09-03-10|0x024e
            SourceStatus = SystemError;                                                   //09-03-10|0x024e
            SourceRunFlag = 0;                                                            //09-03-10|0x024e
            SystemMsg;                                                                    //09-03-10|0x024e
            break;                                                                        //09-03-10|0x024e
        }                                                                                 //09-03-10|0x024e
        break;                                                                            //09-03-10|0x024e
//---------------------------------------------------------------------------             //06-10-06|0x024f
      case 28933: // CLS_SRC_BUILD                                                        //09-03-10|0x0250
        switch(CloseSource)                                                               //09-03-10|0x0250
        {                                                                                 //09-03-10|0x0250
          case Success:                                                                   //09-03-10|0x0250
            SourceRunFlag = 1;                                                            //09-03-10|0x0250
            SourceState = 40851; // MAILBOX_BUILD_TEST                                    //09-03-10|0x0250
            break;                                                                        //09-03-10|0x0250
          default:                                                                        //09-03-10|0x0250
            SourceStatus = SystemError;                                                   //09-03-10|0x0250
            SourceRunFlag = 0;                                                            //09-03-10|0x0250
            SystemMsg;                                                                    //09-03-10|0x0250
            break;                                                                        //09-03-10|0x0250
        }                                                                                 //09-03-10|0x0250
        break;                                                                            //09-03-10|0x0250
//---------------------------------------------------------------------------             //06-09-30|0x0251
      case 33236: // CLS_SRC_USER                                                         //09-03-10|0x0252
        switch(CloseSource)                                                               //09-03-10|0x0252
        {                                                                                 //09-03-10|0x0252
          case Success:                                                                   //09-03-10|0x0252
            SourceRunFlag = 1;                                                            //09-03-10|0x0252
            SourceState = 39234; // MAILBOX_USER_TEST                                     //09-03-10|0x0252
            break;                                                                        //09-03-10|0x0252
          default:                                                                        //09-03-10|0x0252
            SourceStatus = SystemError;                                                   //09-03-10|0x0252
            SourceRunFlag = 0;                                                            //09-03-10|0x0252
            SystemMsg;                                                                    //09-03-10|0x0252
            break;                                                                        //09-03-10|0x0252
        }                                                                                 //09-03-10|0x0252
        break;                                                                            //09-03-10|0x0252
//***************************************************************************             //10-06-11|0x0253
//******                                                               ******             //10-06-11|0x0254
//****** Test for need to finish the postoffices                       ******             //10-06-11|0x0255
//******                                                               ******             //10-06-11|0x0256
//***************************************************************************             //10-06-11|0x0257
      case 53574: // MAILBOX_TEST                                                         //10-06-11|0x0258
        switch(MailBoxTest)                                                               //10-06-11|0x0258
        {                                                                                 //10-06-11|0x0258
          case Yes:                                                                       //10-06-11|0x0258
            SourceRunFlag = 1;                                                            //10-06-11|0x0258
            SourceState = 11745; // MAIL_FINISH                                           //10-06-11|0x0258
            break;                                                                        //10-06-11|0x0258
          case No:                                                                        //10-06-11|0x0258
            SourceRunFlag = 1;                                                            //10-06-11|0x0258
            SourceState = 3184; // READ_SOURCE_DISPLY                                     //10-06-11|0x0258
            break;                                                                        //10-06-11|0x0258
          default:                                                                        //10-06-11|0x0258
            SourceStatus = SystemError;                                                   //10-06-11|0x0258
            SourceRunFlag = 0;                                                            //10-06-11|0x0258
            SystemMsg;                                                                    //10-06-11|0x0258
            break;                                                                        //10-06-11|0x0258
        }                                                                                 //10-06-11|0x0258
        break;                                                                            //10-06-11|0x0258
//---------------------------------------------------------------------------             //10-06-11|0x0259
      case 40851: // MAILBOX_BUILD_TEST                                                   //10-06-11|0x025a
        switch(MailBoxTest)                                                               //10-06-11|0x025a
        {                                                                                 //10-06-11|0x025a
          case Yes:                                                                       //10-06-11|0x025a
            SourceRunFlag = 1;                                                            //10-06-11|0x025a
            SourceState = 54255; // MAIL_BUILD_FINISH                                     //10-06-11|0x025a
            break;                                                                        //10-06-11|0x025a
          case No:                                                                        //10-06-11|0x025a
            SourceRunFlag = 1;                                                            //10-06-11|0x025a
            SourceState = 4958; // CLS_LIB_BUILD                                          //10-06-11|0x025a
            break;                                                                        //10-06-11|0x025a
          default:                                                                        //10-06-11|0x025a
            SourceStatus = SystemError;                                                   //10-06-11|0x025a
            SourceRunFlag = 0;                                                            //10-06-11|0x025a
            SystemMsg;                                                                    //10-06-11|0x025a
            break;                                                                        //10-06-11|0x025a
        }                                                                                 //10-06-11|0x025a
        break;                                                                            //10-06-11|0x025a
//---------------------------------------------------------------------------             //10-06-11|0x025b
      case 39234: // MAILBOX_USER_TEST                                                    //10-06-11|0x025c
        switch(MailBoxTest)                                                               //10-06-11|0x025c
        {                                                                                 //10-06-11|0x025c
          case Yes:                                                                       //10-06-11|0x025c
            SourceRunFlag = 1;                                                            //10-06-11|0x025c
            SourceState = 18877; // MAIL_USER_FINISH                                      //10-06-11|0x025c
            break;                                                                        //10-06-11|0x025c
          case No:                                                                        //10-06-11|0x025c
            SourceRunFlag = 1;                                                            //10-06-11|0x025c
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x025c
            break;                                                                        //10-06-11|0x025c
          default:                                                                        //10-06-11|0x025c
            SourceStatus = SystemError;                                                   //10-06-11|0x025c
            SourceRunFlag = 0;                                                            //10-06-11|0x025c
            SystemMsg;                                                                    //10-06-11|0x025c
            break;                                                                        //10-06-11|0x025c
        }                                                                                 //10-06-11|0x025c
        break;                                                                            //10-06-11|0x025c
//***************************************************************************             //10-06-11|0x025d
//******                                                               ******             //10-06-11|0x025e
//****** Finish the postoffices                                        ******             //10-06-11|0x025f
//******                                                               ******             //10-06-11|0x0260
//***************************************************************************             //10-06-11|0x0261
      case 11745: // MAIL_FINISH                                                          //10-06-11 |0x0262
        switch(mailbox_finish())                                                          //10-06-11 |0x0262
        {                                                                                 //10-06-11 |0x0262
          case Success:                                                                   //10-06-11 |0x0262
            SourceRunFlag = 1;                                                            //10-06-11 |0x0262
            SourceState = 58892; // READ_MAIL_DISPLY                                      //10-06-11 |0x0262
            break;                                                                        //10-06-11 |0x0262
          case UserError:                                                                 //10-06-11 |0x0262
            SourceRunFlag = 1;                                                            //10-06-11 |0x0262
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11 |0x0262
            break;                                                                        //10-06-11 |0x0262
          default:                                                                        //10-06-11 |0x0262
            SourceStatus = SystemError;                                                   //10-06-11 |0x0262
            SourceRunFlag = 0;                                                            //10-06-11 |0x0262
            SystemMsg;                                                                    //10-06-11 |0x0262
            break;                                                                        //10-06-11 |0x0262
        }                                                                                 //10-06-11 |0x0262
        break;                                                                            //10-06-11 |0x0262
//---------------------------------------------------------------------------             //10-06-11|0x0263
      case 54255: // MAIL_BUILD_FINISH                                                    //10-06-11|0x0264
        switch(mailbox_finish())                                                          //10-06-11|0x0264
        {                                                                                 //10-06-11|0x0264
          case Success:                                                                   //10-06-11|0x0264
            SourceRunFlag = 1;                                                            //10-06-11|0x0264
            SourceState = 18251; // MAIL_COMP_BUILD                                       //10-06-11|0x0264
            break;                                                                        //10-06-11|0x0264
          case UserError:                                                                 //10-06-11|0x0264
            SourceRunFlag = 1;                                                            //10-06-11|0x0264
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x0264
            break;                                                                        //10-06-11|0x0264
          default:                                                                        //10-06-11|0x0264
            SourceStatus = SystemError;                                                   //10-06-11|0x0264
            SourceRunFlag = 0;                                                            //10-06-11|0x0264
            SystemMsg;                                                                    //10-06-11|0x0264
            break;                                                                        //10-06-11|0x0264
        }                                                                                 //10-06-11|0x0264
        break;                                                                            //10-06-11|0x0264
//---------------------------------------------------------------------------             //10-06-11|0x0265
      case 18877: // MAIL_USER_FINISH                                                     //10-06-11|0x0266
        switch(mailbox_finish())                                                          //10-06-11|0x0266
        {                                                                                 //10-06-11|0x0266
          case Success:                                                                   //10-06-11|0x0266
            SourceRunFlag = 1;                                                            //10-06-11|0x0266
            SourceState = 48250; // MAIL_COMP_USER                                        //10-06-11|0x0266
            break;                                                                        //10-06-11|0x0266
          case UserError:                                                                 //10-06-11|0x0266
            SourceRunFlag = 1;                                                            //10-06-11|0x0266
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x0266
            break;                                                                        //10-06-11|0x0266
          default:                                                                        //10-06-11|0x0266
            SourceStatus = SystemError;                                                   //10-06-11|0x0266
            SourceRunFlag = 0;                                                            //10-06-11|0x0266
            SystemMsg;                                                                    //10-06-11|0x0266
            break;                                                                        //10-06-11|0x0266
        }                                                                                 //10-06-11|0x0266
        break;                                                                            //10-06-11|0x0266
//***************************************************************************             //10-06-11|0x0267
//******                                                               ******             //10-06-11|0x0268
//****** Reset Display Flag                                            ******             //10-06-11|0x0269
//******                                                               ******             //10-06-11|0x026a
//***************************************************************************             //10-06-11|0x026b
      case 3184: // READ_SOURCE_DISPLY                                                    //10-06-11|0x026c
        if(display_flag) DisplayOff();                                                    //10-06-11|0x026c
        SourceState = 33945; // READ_SOURCE                                               //10-06-11|0x026c
        break;                                                                            //10-06-11|0x026c
//---------------------------------------------------------------------------             //10-06-11|0x026d
      case 58892: // READ_MAIL_DISPLY                                                     //10-06-11|0x026e
        if(display_flag) DisplayOff();                                                    //10-06-11|0x026e
        SourceState = 52904; // READ_MAIL_SOURCE                                          //10-06-11|0x026e
        break;                                                                            //10-06-11|0x026e
//***************************************************************************             //10-06-11|0x026f
//******                                                               ******             //10-06-11|0x0270
//****** Read Next Project Line                                        ******             //10-06-11|0x0271
//******                                                               ******             //10-06-11|0x0272
//***************************************************************************             //10-06-11|0x0273
      case 33945: // READ_SOURCE                                                          //10-06-11|0x0274
        switch(ReadProject)                                                               //10-06-11|0x0274
        {                                                                                 //10-06-11|0x0274
          case Display:                                                                   //10-06-11|0x0274
            SourceState = 47527; // READ_SOURCE_EXIT                                      //10-06-11|0x0274
            SourceStatus = Display;                                                       //10-06-11|0x0274
            SourceRunFlag = 0;                                                            //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          case LineDone:                                                                  //10-06-11|0x0274
            SourceRunFlag = 1;                                                            //10-06-11|0x0274
            SourceState = 27312; // SOURCE                                                //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          case FileDone:                                                                  //10-06-11|0x0274
            SourceRunFlag = 1;                                                            //10-06-11|0x0274
            SourceState = 21654; // CLOSE_LIB                                             //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          case UserError:                                                                 //10-06-11|0x0274
            SourceRunFlag = 1;                                                            //10-06-11|0x0274
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          default:                                                                        //10-06-11|0x0274
            SourceStatus = SystemError;                                                   //10-06-11|0x0274
            SourceRunFlag = 0;                                                            //10-06-11|0x0274
            SystemMsg;                                                                    //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
        }                                                                                 //10-06-11|0x0274
        break;                                                                            //10-06-11|0x0274
//**************************************************************************              //10-06-11|0x0274
      case 47527: // READ_SOURCE_EXIT                                                     //10-06-11|0x0274
        switch(ReadProject)                                                               //10-06-11|0x0274
        {                                                                                 //10-06-11|0x0274
          case Display:                                                                   //10-06-11|0x0274
            SourceState = 47527; // READ_SOURCE_EXIT                                      //10-06-11|0x0274
            SourceStatus = Display;                                                       //10-06-11|0x0274
            SourceRunFlag = 0;                                                            //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          case LineDone:                                                                  //10-06-11|0x0274
            SourceRunFlag = 1;                                                            //10-06-11|0x0274
            SourceState = 27312; // SOURCE                                                //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          case FileDone:                                                                  //10-06-11|0x0274
            SourceRunFlag = 1;                                                            //10-06-11|0x0274
            SourceState = 21654; // CLOSE_LIB                                             //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          case UserError:                                                                 //10-06-11|0x0274
            SourceRunFlag = 1;                                                            //10-06-11|0x0274
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
          default:                                                                        //10-06-11|0x0274
            SourceStatus = SystemError;                                                   //10-06-11|0x0274
            SourceRunFlag = 0;                                                            //10-06-11|0x0274
            SystemMsg;                                                                    //10-06-11|0x0274
            break;                                                                        //10-06-11|0x0274
        }                                                                                 //10-06-11|0x0274
        break;                                                                            //10-06-11|0x0274
//---------------------------------------------------------------------------             //10-06-11|0x0275
      case 52904: // READ_MAIL_SOURCE                                                     //10-06-11|0x0276
        switch(ReadProject)                                                               //10-06-11|0x0276
        {                                                                                 //10-06-11|0x0276
          case Display:                                                                   //10-06-11|0x0276
            SourceState = 40565; // READ_MAIL_SOURCE_EXIT                                 //10-06-11|0x0276
            SourceStatus = Display;                                                       //10-06-11|0x0276
            SourceRunFlag = 0;                                                            //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          case LineDone:                                                                  //10-06-11|0x0276
            SourceRunFlag = 1;                                                            //10-06-11|0x0276
            SourceState = 27312; // SOURCE                                                //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          case FileDone:                                                                  //10-06-11|0x0276
            SourceRunFlag = 1;                                                            //10-06-11|0x0276
            SourceState = 34372; // MAIL_COMP_OK                                          //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          case UserError:                                                                 //10-06-11|0x0276
            SourceRunFlag = 1;                                                            //10-06-11|0x0276
            SourceState = 48250; // MAIL_COMP_USER                                        //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          default:                                                                        //10-06-11|0x0276
            SourceStatus = SystemError;                                                   //10-06-11|0x0276
            SourceRunFlag = 0;                                                            //10-06-11|0x0276
            SystemMsg;                                                                    //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
        }                                                                                 //10-06-11|0x0276
        break;                                                                            //10-06-11|0x0276
//**************************************************************************              //10-06-11|0x0276
      case 40565: // READ_MAIL_SOURCE_EXIT                                                //10-06-11|0x0276
        switch(ReadProject)                                                               //10-06-11|0x0276
        {                                                                                 //10-06-11|0x0276
          case Display:                                                                   //10-06-11|0x0276
            SourceState = 40565; // READ_MAIL_SOURCE_EXIT                                 //10-06-11|0x0276
            SourceStatus = Display;                                                       //10-06-11|0x0276
            SourceRunFlag = 0;                                                            //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          case LineDone:                                                                  //10-06-11|0x0276
            SourceRunFlag = 1;                                                            //10-06-11|0x0276
            SourceState = 27312; // SOURCE                                                //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          case FileDone:                                                                  //10-06-11|0x0276
            SourceRunFlag = 1;                                                            //10-06-11|0x0276
            SourceState = 34372; // MAIL_COMP_OK                                          //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          case UserError:                                                                 //10-06-11|0x0276
            SourceRunFlag = 1;                                                            //10-06-11|0x0276
            SourceState = 48250; // MAIL_COMP_USER                                        //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
          default:                                                                        //10-06-11|0x0276
            SourceStatus = SystemError;                                                   //10-06-11|0x0276
            SourceRunFlag = 0;                                                            //10-06-11|0x0276
            SystemMsg;                                                                    //10-06-11|0x0276
            break;                                                                        //10-06-11|0x0276
        }                                                                                 //10-06-11|0x0276
        break;                                                                            //10-06-11|0x0276
//***************************************************************************             //07-03-23|0x0277
//******                                                               ******             //07-03-23|0x0278
//****** Common Error Messages                                         ******             //07-03-23|0x0279
//******                                                               ******             //07-03-23|0x027a
//***************************************************************************             //07-03-23|0x027b
      case 49804: // COMMAND_ERROR                                                        //07-03-23|0x027c
        switch(IllegalCommand)                                                            //07-03-23|0x027c
        {                                                                                 //07-03-23|0x027c
          case UserError:                                                                 //07-03-23|0x027c
            SourceRunFlag = 1;                                                            //07-03-23|0x027c
            SourceState = 56893; // CLOSE_USER                                            //07-03-23|0x027c
            break;                                                                        //07-03-23|0x027c
          default:                                                                        //07-03-23|0x027c
            SourceStatus = SystemError;                                                   //07-03-23|0x027c
            SourceRunFlag = 0;                                                            //07-03-23|0x027c
            SystemMsg;                                                                    //07-03-23|0x027c
            break;                                                                        //07-03-23|0x027c
        }                                                                                 //07-03-23|0x027c
        break;                                                                            //07-03-23|0x027c
//---------------------------------------------------------------------------             //07-03-23|0x027d
      case 57310: // END_FILE                                                             //07-03-23|0x027e
        switch(IllegalEndFile)                                                            //07-03-23|0x027e
        {                                                                                 //07-03-23|0x027e
          case UserError:                                                                 //07-03-23|0x027e
            SourceRunFlag = 1;                                                            //07-03-23|0x027e
            SourceState = 56893; // CLOSE_USER                                            //07-03-23|0x027e
            break;                                                                        //07-03-23|0x027e
          default:                                                                        //07-03-23|0x027e
            SourceStatus = SystemError;                                                   //07-03-23|0x027e
            SourceRunFlag = 0;                                                            //07-03-23|0x027e
            SystemMsg;                                                                    //07-03-23|0x027e
            break;                                                                        //07-03-23|0x027e
        }                                                                                 //07-03-23|0x027e
        break;                                                                            //07-03-23|0x027e
//***************************************************************************             //07-03-23|0x027f
      case 14800: // CMND_LIB_ERR                                                         //10-06-11|0x0280
        switch(IllegalCommand)                                                            //10-06-11|0x0280
        {                                                                                 //10-06-11|0x0280
          case UserError:                                                                 //10-06-11|0x0280
            SourceRunFlag = 1;                                                            //10-06-11|0x0280
            SourceState = 60163; // MAILBOX_ERROR_TEST                                    //10-06-11|0x0280
            break;                                                                        //10-06-11|0x0280
          default:                                                                        //10-06-11|0x0280
            SourceStatus = SystemError;                                                   //10-06-11|0x0280
            SourceRunFlag = 0;                                                            //10-06-11|0x0280
            SystemMsg;                                                                    //10-06-11|0x0280
            break;                                                                        //10-06-11|0x0280
        }                                                                                 //10-06-11|0x0280
        break;                                                                            //10-06-11|0x0280
//---------------------------------------------------------------------------             //10-06-11|0x0281
      case 4197: // END_LIB                                                               //10-06-11|0x0282
        switch(IllegalEndFile)                                                            //10-06-11|0x0282
        {                                                                                 //10-06-11|0x0282
          case UserError:                                                                 //10-06-11|0x0282
            SourceRunFlag = 1;                                                            //10-06-11|0x0282
            SourceState = 60163; // MAILBOX_ERROR_TEST                                    //10-06-11|0x0282
            break;                                                                        //10-06-11|0x0282
          default:                                                                        //10-06-11|0x0282
            SourceStatus = SystemError;                                                   //10-06-11|0x0282
            SourceRunFlag = 0;                                                            //10-06-11|0x0282
            SystemMsg;                                                                    //10-06-11|0x0282
            break;                                                                        //10-06-11|0x0282
        }                                                                                 //10-06-11|0x0282
        break;                                                                            //10-06-11|0x0282
//---------------------------------------------------------------------------             //10-06-11|0x0283
      case 60163: // MAILBOX_ERROR_TEST                                                   //10-06-11|0x0284
        switch(MailBoxTest)                                                               //10-06-11|0x0284
        {                                                                                 //10-06-11|0x0284
          case Yes:                                                                       //10-06-11|0x0284
            SourceRunFlag = 1;                                                            //10-06-11|0x0284
            SourceState = 48250; // MAIL_COMP_USER                                        //10-06-11|0x0284
            break;                                                                        //10-06-11|0x0284
          case No:                                                                        //10-06-11|0x0284
            SourceRunFlag = 1;                                                            //10-06-11|0x0284
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x0284
            break;                                                                        //10-06-11|0x0284
          default:                                                                        //10-06-11|0x0284
            SourceStatus = SystemError;                                                   //10-06-11|0x0284
            SourceRunFlag = 0;                                                            //10-06-11|0x0284
            SystemMsg;                                                                    //10-06-11|0x0284
            break;                                                                        //10-06-11|0x0284
        }                                                                                 //10-06-11|0x0284
        break;                                                                            //10-06-11|0x0284
//***************************************************************************             //10-06-11|0x0285
//******                                                               ******             //10-06-11|0x0286
//****** Complete Mailboxes                                            ******             //10-06-11|0x0287
//******                                                               ******             //10-06-11|0x0288
//***************************************************************************             //10-06-11|0x0289
      case 34372: // MAIL_COMP_OK                                                         //10-06-11|0x028a
        switch(mailbox_complete())                                                        //10-06-11|0x028a
        {                                                                                 //10-06-11|0x028a
          case Success:                                                                   //10-06-11|0x028a
            SourceRunFlag = 1;                                                            //10-06-11|0x028a
            SourceState = 21654; // CLOSE_LIB                                             //10-06-11|0x028a
            break;                                                                        //10-06-11|0x028a
          default:                                                                        //10-06-11|0x028a
            SourceStatus = SystemError;                                                   //10-06-11|0x028a
            SourceRunFlag = 0;                                                            //10-06-11|0x028a
            SystemMsg;                                                                    //10-06-11|0x028a
            break;                                                                        //10-06-11|0x028a
        }                                                                                 //10-06-11|0x028a
        break;                                                                            //10-06-11|0x028a
//---------------------------------------------------------------------------             //10-06-11|0x028b
      case 48250: // MAIL_COMP_USER                                                       //10-06-11|0x028c
        switch(mailbox_complete())                                                        //10-06-11|0x028c
        {                                                                                 //10-06-11|0x028c
          case Success:                                                                   //10-06-11|0x028c
            SourceRunFlag = 1;                                                            //10-06-11|0x028c
            SourceState = 5940; // CLS_LIB_USER                                           //10-06-11|0x028c
            break;                                                                        //10-06-11|0x028c
          default:                                                                        //10-06-11|0x028c
            SourceStatus = SystemError;                                                   //10-06-11|0x028c
            SourceRunFlag = 0;                                                            //10-06-11|0x028c
            SystemMsg;                                                                    //10-06-11|0x028c
            break;                                                                        //10-06-11|0x028c
        }                                                                                 //10-06-11|0x028c
        break;                                                                            //10-06-11|0x028c
//---------------------------------------------------------------------------             //10-06-11|0x028d
      case 18251: // MAIL_COMP_BUILD                                                      //10-06-11|0x028e
        switch(mailbox_complete())                                                        //10-06-11|0x028e
        {                                                                                 //10-06-11|0x028e
          case Success:                                                                   //10-06-11|0x028e
            SourceRunFlag = 1;                                                            //10-06-11|0x028e
            SourceState = 4958; // CLS_LIB_BUILD                                          //10-06-11|0x028e
            break;                                                                        //10-06-11|0x028e
          default:                                                                        //10-06-11|0x028e
            SourceStatus = SystemError;                                                   //10-06-11|0x028e
            SourceRunFlag = 0;                                                            //10-06-11|0x028e
            SystemMsg;                                                                    //10-06-11|0x028e
            break;                                                                        //10-06-11|0x028e
        }                                                                                 //10-06-11|0x028e
        break;                                                                            //10-06-11|0x028e
//***************************************************************************             //06-09-30|0x028f
//******                                                               ******             //06-09-30|0x0290
//****** Close Library States                                          ******             //06-09-30|0x0291
//******                                                               ******             //06-09-30|0x0292
//***************************************************************************             //06-09-30|0x0293
      case 21654: // CLOSE_LIB                                                            //10-01-03|0x0294
        switch(MacDictClose())                                                            //10-01-03|0x0294
        {                                                                                 //10-01-03|0x0294
          case Success:                                                                   //10-01-03|0x0294
            SourceRunFlag = 1;                                                            //10-01-03|0x0294
            SourceState = 39858; // CLOSE_MAILBOX_OK                                      //10-01-03|0x0294
            break;                                                                        //10-01-03|0x0294
          default:                                                                        //10-01-03|0x0294
            SourceStatus = SystemError;                                                   //10-01-03|0x0294
            SourceRunFlag = 0;                                                            //10-01-03|0x0294
            SystemMsg;                                                                    //10-01-03|0x0294
            break;                                                                        //10-01-03|0x0294
        }                                                                                 //10-01-03|0x0294
        break;                                                                            //10-01-03|0x0294
//---------------------------------------------------------------------------             //06-09-30|0x0295
      case 5940: // CLS_LIB_USER                                                          //10-01-03|0x0296
        switch(MacDictEmergencyClose())                                                   //10-01-03|0x0296
        {                                                                                 //10-01-03|0x0296
          case Success:                                                                   //10-01-03|0x0296
            SourceRunFlag = 1;                                                            //10-01-03|0x0296
            SourceState = 22353; // CLOSE_MAILBOX_USER                                    //10-01-03|0x0296
            break;                                                                        //10-01-03|0x0296
          default:                                                                        //10-01-03|0x0296
            SourceStatus = SystemError;                                                   //10-01-03|0x0296
            SourceRunFlag = 0;                                                            //10-01-03|0x0296
            SystemMsg;                                                                    //10-01-03|0x0296
            break;                                                                        //10-01-03|0x0296
        }                                                                                 //10-01-03|0x0296
        break;                                                                            //10-01-03|0x0296
//---------------------------------------------------------------------------             //06-10-06|0x0297
      case 4958: // CLS_LIB_BUILD                                                         //10-01-03|0x0298
        switch(MacDictClose())                                                            //10-01-03|0x0298
        {                                                                                 //10-01-03|0x0298
          case Success:                                                                   //10-01-03|0x0298
            SourceRunFlag = 1;                                                            //10-01-03|0x0298
            SourceState = 52448; // CLOSE_MAILBOX_BUILD                                   //10-01-03|0x0298
            break;                                                                        //10-01-03|0x0298
          default:                                                                        //10-01-03|0x0298
            SourceStatus = SystemError;                                                   //10-01-03|0x0298
            SourceRunFlag = 0;                                                            //10-01-03|0x0298
            SystemMsg;                                                                    //10-01-03|0x0298
            break;                                                                        //10-01-03|0x0298
        }                                                                                 //10-01-03|0x0298
        break;                                                                            //10-01-03|0x0298
//***************************************************************************             //10-06-11|0x0299
//******                                                               ******             //10-06-11|0x029a
//****** Close and delete the mailbox control file                     ******             //10-06-11|0x029b
//******                                                               ******             //10-06-11|0x029c
//***************************************************************************             //10-06-11|0x029d
      case 39858: // CLOSE_MAILBOX_OK                                                     //10-06-11|0x029e
        switch(MailDictEnd())                                                             //10-06-11|0x029e
        {                                                                                 //10-06-11|0x029e
          case Success:                                                                   //10-06-11|0x029e
            SourceRunFlag = 1;                                                            //10-06-11|0x029e
            SourceState = 39775; // CLOSE_OK                                              //10-06-11|0x029e
            break;                                                                        //10-06-11|0x029e
          default:                                                                        //10-06-11|0x029e
            SourceStatus = SystemError;                                                   //10-06-11|0x029e
            SourceRunFlag = 0;                                                            //10-06-11|0x029e
            SystemMsg;                                                                    //10-06-11|0x029e
            break;                                                                        //10-06-11|0x029e
        }                                                                                 //10-06-11|0x029e
        break;                                                                            //10-06-11|0x029e
//---------------------------------------------------------------------------             //10-06-11|0x029f
      case 22353: // CLOSE_MAILBOX_USER                                                   //10-06-11|0x02a0
        switch(MailDictEnd())                                                             //10-06-11|0x02a0
        {                                                                                 //10-06-11|0x02a0
          case Success:                                                                   //10-06-11|0x02a0
            SourceRunFlag = 1;                                                            //10-06-11|0x02a0
            SourceState = 56893; // CLOSE_USER                                            //10-06-11|0x02a0
            break;                                                                        //10-06-11|0x02a0
          default:                                                                        //10-06-11|0x02a0
            SourceStatus = SystemError;                                                   //10-06-11|0x02a0
            SourceRunFlag = 0;                                                            //10-06-11|0x02a0
            SystemMsg;                                                                    //10-06-11|0x02a0
            break;                                                                        //10-06-11|0x02a0
        }                                                                                 //10-06-11|0x02a0
        break;                                                                            //10-06-11|0x02a0
//---------------------------------------------------------------------------             //10-06-11|0x02a1
      case 52448: // CLOSE_MAILBOX_BUILD                                                  //10-06-11|0x02a2
        switch(MailDictEnd())                                                             //10-06-11|0x02a2
        {                                                                                 //10-06-11|0x02a2
          case Success:                                                                   //10-06-11|0x02a2
            SourceRunFlag = 1;                                                            //10-06-11|0x02a2
            SourceState = 20942; // CLOSE_BUILD                                           //10-06-11|0x02a2
            break;                                                                        //10-06-11|0x02a2
          default:                                                                        //10-06-11|0x02a2
            SourceStatus = SystemError;                                                   //10-06-11|0x02a2
            SourceRunFlag = 0;                                                            //10-06-11|0x02a2
            SystemMsg;                                                                    //10-06-11|0x02a2
            break;                                                                        //10-06-11|0x02a2
        }                                                                                 //10-06-11|0x02a2
        break;                                                                            //10-06-11|0x02a2
//***************************************************************************             //06-09-30|0x02a3
//******                                                               ******             //06-09-30|0x02a4
//****** Close Project States                                          ******             //06-09-30|0x02a5
//******                                                               ******             //06-09-30|0x02a6
//***************************************************************************             //06-09-30|0x02a7
      case 39775: // CLOSE_OK                                                             //06-10-09|0x02a8
        switch(CloseProject)                                                              //06-10-09|0x02a8
        {                                                                                 //06-10-09|0x02a8
          case Success:                                                                   //06-10-09|0x02a8
            SourceRunFlag = 1;                                                            //06-10-09|0x02a8
            SourceState = 28461; // SUCCESS                                               //06-10-09|0x02a8
            break;                                                                        //06-10-09|0x02a8
          default:                                                                        //06-10-09|0x02a8
            SourceStatus = SystemError;                                                   //06-10-09|0x02a8
            SourceRunFlag = 0;                                                            //06-10-09|0x02a8
            SystemMsg;                                                                    //06-10-09|0x02a8
            break;                                                                        //06-10-09|0x02a8
        }                                                                                 //06-10-09|0x02a8
        break;                                                                            //06-10-09|0x02a8
//---------------------------------------------------------------------------             //06-09-30|0x02a9
      case 56893: // CLOSE_USER                                                           //06-09-30|0x02aa
        switch(CloseProject)                                                              //06-09-30|0x02aa
        {                                                                                 //06-09-30|0x02aa
          case Success:                                                                   //06-09-30|0x02aa
            SourceRunFlag = 1;                                                            //06-09-30|0x02aa
            SourceState = 50565; // USER_ERROR                                            //06-09-30|0x02aa
            break;                                                                        //06-09-30|0x02aa
          default:                                                                        //06-09-30|0x02aa
            SourceStatus = SystemError;                                                   //06-09-30|0x02aa
            SourceRunFlag = 0;                                                            //06-09-30|0x02aa
            SystemMsg;                                                                    //06-09-30|0x02aa
            break;                                                                        //06-09-30|0x02aa
        }                                                                                 //06-09-30|0x02aa
        break;                                                                            //06-09-30|0x02aa
//---------------------------------------------------------------------------             //06-09-30|0x02ab
      case 20942: // CLOSE_BUILD                                                          //06-10-06|0x02ac
        switch(CloseProject)                                                              //06-10-06|0x02ac
        {                                                                                 //06-10-06|0x02ac
          case Success:                                                                   //06-10-06|0x02ac
            SourceRunFlag = 1;                                                            //06-10-06|0x02ac
            SourceState = 25212; // BUILD_ERROR                                           //06-10-06|0x02ac
            break;                                                                        //06-10-06|0x02ac
          default:                                                                        //06-10-06|0x02ac
            SourceStatus = SystemError;                                                   //06-10-06|0x02ac
            SourceRunFlag = 0;                                                            //06-10-06|0x02ac
            SystemMsg;                                                                    //06-10-06|0x02ac
            break;                                                                        //06-10-06|0x02ac
        }                                                                                 //06-10-06|0x02ac
        break;                                                                            //06-10-06|0x02ac
//***************************************************************************             //06-09-30|0x02ad
//******                                                               ******             //06-09-30|0x02ae
//****** Return States                                                 ******             //06-09-30|0x02af
//******                                                               ******             //06-09-30|0x02b0
//***************************************************************************             //06-09-30|0x02b1
      case 28461: // SUCCESS                                                              //08-04-17|0x02b2
        if(display_flag) DisplayOn();                                                     //08-04-17|0x02b2
        SourceState = 35515; // SUCCESS_DISPLAY                                           //08-04-17|0x02b2
        break;                                                                            //08-04-17|0x02b2
      case 35515: // SUCCESS_DISPLAY                                                      //08-04-17|0x02b3
        SourceState = 4462; // INITIAL_PROJECT                                            //08-04-17|0x02b3
        SourceStatus = Success;                                                           //08-04-17|0x02b3
        SourceRunFlag = 0;                                                                //08-04-17|0x02b3
        break;                                                                            //08-04-17|0x02b3
//---------------------------------------------------------------------------             //06-09-30|0x02b4
      case 50565: // USER_ERROR                                                           //08-04-17|0x02b5
        if(display_flag) DisplayOn();                                                     //08-04-17|0x02b5
        SourceState = 14058; // USER_ERROR_DISPLAY                                        //08-04-17|0x02b5
        break;                                                                            //08-04-17|0x02b5
      case 14058: // USER_ERROR_DISPLAY                                                   //08-04-17|0x02b6
        SourceState = 4462; // INITIAL_PROJECT                                            //08-04-17|0x02b6
        SourceStatus = UserError;                                                         //08-04-17|0x02b6
        SourceRunFlag = 0;                                                                //08-04-17|0x02b6
        break;                                                                            //08-04-17|0x02b6
//---------------------------------------------------------------------------             //06-10-06|0x02b7
      case 25212: // BUILD_ERROR                                                          //08-04-17|0x02b8
        if(display_flag) DisplayOn();                                                     //08-04-17|0x02b8
        SourceState = 42505; // BUILD_ERROR_DISPLAY                                       //08-04-17|0x02b8
        break;                                                                            //08-04-17|0x02b8
      case 42505: // BUILD_ERROR_DISPLAY                                                  //08-04-17|0x02b9
        SourceState = 4462; // INITIAL_PROJECT                                            //08-04-17|0x02b9
        SourceStatus = BuildError;                                                        //08-04-17|0x02b9
        SourceRunFlag = 0;                                                                //08-04-17|0x02b9
        break;                                                                            //08-04-17|0x02b9
//***************************************************************************             //06-09-30|0x02ba
//***************************************************************************             //06-09-30|0x02bb
      default:                                                                            //06-09-30|0x02bc
        SourceStatus = SystemError;                                                       //06-09-30|0x02bc
        SourceRunFlag = 0;                                                                //06-09-30|0x02bc
        SystemMsg;                                                                        //06-09-30|0x02bc
        break;                                                                            //06-09-30|0x02bc
    }                                                                                     //06-09-30|0x02bc
  }                                                                                       //06-09-30|0x02bc
//***************************************************************************             //06-09-30|0x02bd
//***************************************************************************             //06-09-30|0x02be
    return(SourceStatus);                                                                 //06-09-30|0x02bf
}                                                                                         //06-09-30|0x02c0
//                                                                                        //05-24-97|0x02c0
//***************************************************************************             //10-05-15|0x02c3
//***************************************************************************             //10-05-15|0x02c4
//******                                                               ******             //10-05-15|0x02c5
//******                     enter_input_names                         ******             //10-05-15|0x02c6
//******                                                               ******             //10-05-15|0x02c7
//***************************************************************************             //10-05-15|0x02c8
//***************************************************************************             //10-05-15|0x02c9
//*******************************************************************************         //10-29-97|0x02ce
//*******************************************************************************         //10-29-97|0x02ce
// enter_input_names                                                                      //10-05-15|0x02ce
//*******************************************************************************         //10-29-97|0x02ce
//*******************************************************************************         //10-29-97|0x02ce
UINT SOURCEPROJ::enter_input_names(                                                       //10-05-15|0x02ce
    STRING_DATA_FAR InFar                                                                 //10-05-15|0x02ce
    ) {                                                                                   //10-05-15|0x02ce
//*******************************************************************************         //10-29-97|0x02ce
//***************************************************************************             //10-05-15|0x02d1
//***************************************************************************             //10-05-15|0x02d2
  UINT i;                                                                            //10-05-15|0x02d3
//***************************************************************************             //10-05-15|0x02d4
//***************************************************************************             //10-05-15|0x02d5
    if(InLength          >= _MAX_PATH)  ReturnFinish("Input Name Too Large");             //10-05-15|0x02d6
    if(InChar(InLength)  != 0)          ReturnSystemError;                                //10-05-15|0x02d7
//***************************************************************************             //10-05-15|0x02d8
    StrCpy(FilesInName, &(InChar(0)));                                                    //10-05-15|0x02d9
//***************************************************************************             //10-05-15|0x02da
    for(i=0;  i<FilesInNoFiles; ++i)                                                      //10-05-15|0x02db
      {                                                                                   //10-05-15|0x02dc
        switch(InitialTextFile(i))                               _SwitchGroup             //10-05-15|0x02dd
        switch(EnterTextPath(i))                                 _SwitchGroup             //10-05-15|0x02de
        switch(EnterTextFileName(i))                             _SwitchGroup             //10-05-15|0x02df
        switch(FileRelease())                                    _SwitchGroup             //10-05-15|0x02e0
        }                                                                                 //10-05-15|0x02e1
//***************************************************************************             //10-05-15|0x02e2
    return_test(enter_input_names_1);                                                     //10-05-15|0x02e3
}                                                                                         //10-05-15|0x02e4
//                                                                                        //05-24-97|0x02e4
//***************************************************************************             //06-09-11|0x02e7
//***************************************************************************             //06-09-11|0x02e8
//******                                                               ******             //06-09-11|0x02e9
//******                     enter_name                                ******             //06-09-11|0x02ea
//******                                                               ******             //06-09-11|0x02eb
//***************************************************************************             //06-09-11|0x02ec
//***************************************************************************             //06-09-11|0x02ed
//*******************************************************************************         //10-29-97|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
// enter_name                                                                             //07-03-21|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
UINT SOURCEPROJ::enter_name(                                                              //07-03-21|0x02f2
    TEXT_FILE_DATA_FAR TextFileAddr,                                                      //07-03-21|0x02f2
    STRING_DATA_FAR InFar,                                                                //07-03-21|0x02f2
    SCHAR_FAR Extent                                                                      //07-03-21|0x02f2
    ) {                                                                                   //07-03-21|0x02f2
//*******************************************************************************         //10-29-97|0x02f2
//***************************************************************************             //06-09-11|0x02f5
//***************************************************************************             //06-09-11|0x02f6
    switch(InitialFile)                                          _SwitchGroup             //06-09-11|0x02f7
    switch(EnterFileName)                                        _SwitchGroup             //06-09-11|0x02f8
    switch(FileRelease())                                        _SwitchGroup             //06-09-11|0x02f9
//***************************************************************************             //06-09-11|0x02fa
    return_test(enter_name_1);                                                            //06-09-11|0x02fb
}                                                                                         //06-09-11|0x02fc
//                                                                                        //05-24-97|0x02fc
//***************************************************************************             //<----   |0x02ff
//***************************************************************************             //<----   |0x0300
//******                                                               ******             //<----   |0x0301
//******                     initial_buf_out                           ******             //<----   |0x0302
//******                                                               ******             //<----   |0x0303
//***************************************************************************             //<----   |0x0304
//***************************************************************************             //<----   |0x0305
//*******************************************************************************         //10-29-97|0x030a
//*******************************************************************************         //10-29-97|0x030a
// initial_buf_out                                                                        //<----   |0x030a
//*******************************************************************************         //10-29-97|0x030a
//*******************************************************************************         //10-29-97|0x030a
UINT SOURCEPROJ::initial_buf_out(                                                         //<----   |0x030a
    BINARY_FILE_DATA_FAR BinaryFileAddr,                                                  //<----   |0x030a
    STRING_DATA_FAR InFar,                                                                //<----   |0x030a
    SCHAR_FAR Extent                                                                      //<----   |0x030a
    ) {                                                                                   //<----   |0x030a
//*******************************************************************************         //10-29-97|0x030a
//***************************************************************************             //<----   |0x030d
//***************************************************************************             //<----   |0x030e
    switch(FileInitialBinary(BinaryFileAddr))                    _SwitchGroup             //<----   |0x030f
    switch(EnterFileName)                                        _SwitchGroup             //<----   |0x0310
    switch(FileCreateRecord())                                   _SwitchGroup             //<----   |0x0311
    switch(FileRelease())                                        _SwitchGroup             //<----   |0x0312
//***************************************************************************             //<----   |0x0313
    return_test(initial_buf_out_1);                                                       //<----   |0x0314
}                                                                                         //<----   |0x0315
//                                                                                        //05-24-97|0x0315
//***************************************************************************             //<----   |0x0318
//***************************************************************************             //<----   |0x0319
//******                                                               ******             //<----   |0x031a
//******                     close_buffer_out                          ******             //<----   |0x031b
//******                                                               ******             //<----   |0x031c
//***************************************************************************             //<----   |0x031d
//***************************************************************************             //<----   |0x031e
//*******************************************************************************         //10-29-97|0x0323
//*******************************************************************************         //10-29-97|0x0323
// close_buffer_out                                                                       //<----   |0x0323
//*******************************************************************************         //10-29-97|0x0323
//*******************************************************************************         //10-29-97|0x0323
UINT SOURCEPROJ::close_buffer_out(                                                        //<----   |0x0323
    BINARY_FILE_DATA_FAR BinaryFileAddr                                                   //<----   |0x0323
    ) {                                                                                   //<----   |0x0323
//*******************************************************************************         //10-29-97|0x0323
//***************************************************************************             //<----   |0x0326
//***************************************************************************             //<----   |0x0327
    switch(FileCommitBinary(BinaryFileAddr))                     _SwitchGroup             //<----   |0x0328
    switch(FileClose())                                          _SwitchGroup             //<----   |0x0329
    switch(FileDelete())                                         _SwitchGroup             //<----   |0x032a
    switch(FileRelease())                                        _SwitchGroup             //<----   |0x032b
//***************************************************************************             //<----   |0x032c
    return_test(close_buffer_out_1);                                                      //<----   |0x032d
}                                                                                         //<----   |0x032e
//                                                                                        //05-24-97|0x032e
//***************************************************************************             //10-05-15|0x0331
//***************************************************************************             //10-05-15|0x0332
//******                                                               ******             //10-05-15|0x0333
//******                            input_file_times                   ******             //10-05-15|0x0334
//******                                                               ******             //10-05-15|0x0335
//***************************************************************************             //10-05-15|0x0336
//***************************************************************************             //10-05-15|0x0337
//*******************************************************************************         //10-29-97|0x033b
//*******************************************************************************         //10-29-97|0x033b
// input_file_times                                                                       //10-05-15|0x033b
//*******************************************************************************         //10-29-97|0x033b
//*******************************************************************************         //10-29-97|0x033b
UINT SOURCEPROJ::input_file_times(void) {                                                 //10-05-15|0x033b
//*******************************************************************************         //10-29-97|0x033b
//***************************************************************************             //10-05-15|0x033e
//***************************************************************************             //10-05-15|0x033f
  UINT i;                                                                            //10-05-15|0x0340
//***************************************************************************             //10-05-15|0x0341
//***************************************************************************             //10-05-15|0x0342
    for(i=0;  i<FilesInNoFiles; ++i)                                                      //10-05-15|0x0343
      {                                                                                   //10-05-15|0x0344
        switch(file_time(FilesInFileAddr(i)))                    _SwitchGroup             //10-05-15|0x0345
        if(SourceInTime == 0)                              return(UserError);             //10-05-15|0x0346
        if(SourceInTime >  SourceOutTime)                                                 //10-05-15|0x0347
          {                                                                               //10-05-15|0x0348
            SourceOutTime = SourceInTime;                                                 //10-05-15|0x0349
            }                                                                             //10-05-15|0x034a
        }                                                                                 //10-05-15|0x034b
//***************************************************************************             //10-05-15|0x034c
    return_test(input_file_times_1);                                                      //10-05-15|0x034d
}                                                                                         //10-05-15|0x034e
//                                                                                        //05-24-97|0x034e
//***************************************************************************             //06-09-11|0x0351
//***************************************************************************             //06-09-11|0x0352
//******                                                               ******             //06-09-11|0x0353
//******                            file_time                          ******             //06-09-11|0x0354
//******                                                               ******             //06-09-11|0x0355
//***************************************************************************             //06-09-11|0x0356
//***************************************************************************             //06-09-11|0x0357
//*******************************************************************************         //10-29-97|0x035c
//*******************************************************************************         //10-29-97|0x035c
// file_time                                                                              //06-09-11|0x035c
//*******************************************************************************         //10-29-97|0x035c
//*******************************************************************************         //10-29-97|0x035c
UINT SOURCEPROJ::file_time(                                                               //06-09-11|0x035c
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-09-11|0x035c
    ) {                                                                                   //06-09-11|0x035c
//*******************************************************************************         //10-29-97|0x035c
//***************************************************************************             //06-09-11|0x035f
//***************************************************************************             //06-09-11|0x0360
    switch(CommitFile)                                           _SwitchGroup             //06-09-11|0x0361
    switch(FileExists(SourceInTimeAddr))                         _SwitchGroup             //06-09-11|0x0362
    switch(FileRelease())                                        _SwitchGroup             //06-09-11|0x0363
    return_test(file_time_1);                                                             //06-09-11|0x0364
}                                                                                         //06-09-11|0x0365
//                                                                                        //05-24-97|0x0365
//***************************************************************************             //10-05-15|0x0368
//***************************************************************************             //10-05-15|0x0369
//******                                                               ******             //10-05-15|0x036a
//******                          open_input_files                     ******             //10-05-15|0x036b
//******                                                               ******             //10-05-15|0x036c
//***************************************************************************             //10-05-15|0x036d
//***************************************************************************             //10-05-15|0x036e
//*******************************************************************************         //10-29-97|0x0372
//*******************************************************************************         //10-29-97|0x0372
// open_input_files                                                                       //10-05-15|0x0372
//*******************************************************************************         //10-29-97|0x0372
//*******************************************************************************         //10-29-97|0x0372
UINT SOURCEPROJ::open_input_files(void) {                                                 //10-05-15|0x0372
//*******************************************************************************         //10-29-97|0x0372
//***************************************************************************             //10-05-15|0x0375
//***************************************************************************             //10-05-15|0x0376
  UINT i;                                                                            //10-05-15|0x0377
//***************************************************************************             //10-05-15|0x0378
//***************************************************************************             //10-05-15|0x0379
    for(i=0;  i<FilesInNoFiles; ++i)                                                      //10-05-15|0x037a
      {                                                                                   //10-05-15|0x037b
        switch(open_project(FilesInFileAddr(i)))                 _SwitchGroup             //10-05-15|0x037c
        }                                                                                 //10-05-15|0x037d
//***************************************************************************             //10-05-15|0x037e
    return_test(open_input_files_1);                                                      //10-05-15|0x037f
}                                                                                         //10-05-15|0x0380
//                                                                                        //05-24-97|0x0380
//***************************************************************************             //06-09-12|0x0383
//***************************************************************************             //06-09-12|0x0384
//******                                                               ******             //06-09-12|0x0385
//******                          open_project                         ******             //06-09-12|0x0386
//******                                                               ******             //06-09-12|0x0387
//***************************************************************************             //06-09-12|0x0388
//***************************************************************************             //06-09-12|0x0389
//*******************************************************************************         //10-29-97|0x038e
//*******************************************************************************         //10-29-97|0x038e
// open_project                                                                           //06-09-12|0x038e
//*******************************************************************************         //10-29-97|0x038e
//*******************************************************************************         //10-29-97|0x038e
UINT SOURCEPROJ::open_project(                                                            //06-09-12|0x038e
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-09-12|0x038e
    ) {                                                                                   //06-09-12|0x038e
//*******************************************************************************         //10-29-97|0x038e
//***************************************************************************             //06-09-12|0x0391
//***************************************************************************             //06-09-12|0x0392
    switch(CommitFile)                                           _SwitchGroup             //06-09-12|0x0393
    switch(FileOpenText())                                                                //10-06-11|0x0394
      {                                                                                   //10-06-11|0x0395
        case Success:                                                                     //10-06-11|0x0396
          switch(FileRelease())                                  _SwitchGroup             //10-06-11|0x0397
          return_test(open_project_1);                                                    //10-06-11|0x0398
        case UserError:                                                                   //10-06-11|0x0399
          switch(FileRelease())                                  _SwitchGroup             //10-06-11|0x039a
          return(UserError);                                                              //10-06-11|0x039b
        default:                                           ReturnSystemError;             //10-06-11|0x039c
        }                                                                                 //10-06-11|0x039d
//***************************************************************************             //06-09-12|0x039e
}                                                                                         //06-09-12|0x039f
//                                                                                        //05-24-97|0x039f
//***************************************************************************             //06-09-12|0x03a2
//***************************************************************************             //06-09-12|0x03a3
//******                                                               ******             //06-09-12|0x03a4
//******                          read_project                         ******             //06-09-12|0x03a5
//******                                                               ******             //06-09-12|0x03a6
//***************************************************************************             //06-09-12|0x03a7
//***************************************************************************             //06-09-12|0x03a8
//*******************************************************************************         //10-29-97|0x03b0
//*******************************************************************************         //10-29-97|0x03b0
// read_project                                                                           //06-09-12|0x03b0
//*******************************************************************************         //10-29-97|0x03b0
//*******************************************************************************         //10-29-97|0x03b0
UINT SOURCEPROJ::read_project(                                                            //06-09-12|0x03b0
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-09-12|0x03b0
    ) {                                                                                   //06-09-12|0x03b0
//*******************************************************************************         //10-29-97|0x03b0
//***************************************************************************             //06-09-12|0x03b3
//***************************************************************************             //06-09-12|0x03b4
  UINT status;                                                                       //06-09-12|0x03b5
//***************************************************************************             //06-09-12|0x03b6
//***************************************************************************             //06-09-12|0x03b7
    switch(CommitFile)                                           _SwitchGroup             //06-09-12|0x03b8
//***************************************************************************             //06-09-12|0x03b9
    status = FileReadText(SourceTokensAddr);                                              //06-09-12|0x03ba
//---------------------------------------------------------------------------             //06-09-12|0x03bb
    switch(status)                                                                        //06-09-12|0x03bc
      {                                                                                   //06-09-12|0x03bd
        case FileDone:                            break_test(read_project_1);             //06-09-12|0x03be
        case LineDone:                            break_test(read_project_2);             //06-09-12|0x03bf
        case UserError:                           break_test(read_project_3);             //06-09-12|0x03c0
        case Display:                             break_test(read_project_4);             //06-09-12|0x03c1
        default:                                            ReturnSystemError             //06-09-12|0x03c2
        }                                                                                 //06-09-12|0x03c3
//***************************************************************************             //06-09-12|0x03c4
    switch(FileRelease())                                        _SwitchGroup             //06-09-12|0x03c5
//***************************************************************************             //06-09-12|0x03c6
    return(status);                                                                       //06-09-12|0x03c7
}                                                                                         //06-09-12|0x03c8
//                                                                                        //05-24-97|0x03c8
//***************************************************************************             //06-09-12|0x03cb
//***************************************************************************             //06-09-12|0x03cc
//******                                                               ******             //06-09-12|0x03cd
//******                          text_prepare                         ******             //06-09-12|0x03ce
//******                                                               ******             //06-09-12|0x03cf
//***************************************************************************             //06-09-12|0x03d0
//***************************************************************************             //06-09-12|0x03d1
//*******************************************************************************         //10-29-97|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
// text_prepare                                                                           //06-09-12|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
UINT SOURCEPROJ::text_prepare(void) {                                                     //06-09-12|0x03d5
//*******************************************************************************         //10-29-97|0x03d5
//***************************************************************************             //06-09-12|0x03d8
//***************************************************************************             //06-09-12|0x03d9
  UINT i;                                                                            //06-11-06|0x03da
//***************************************************************************             //06-11-06|0x03db
//***************************************************************************             //06-11-06|0x03dc
    IfNoTokens(2, 10)                  ReturnFinish("Illegal No Parameters");             //06-09-12|0x03dd
//***************************************************************************             //06-09-12|0x03de
    for(i=1; i<TokensNoTokens; ++i)                                                       //06-11-06|0x03df
      {                                                                                   //06-11-06|0x03e0
        switch(FileTextPrepare(i))                               _SwitchGroup             //06-11-06|0x03e1
        }                                                                                 //06-11-06|0x03e2
    TokensNoTokens -= 1;                                                                  //06-11-06|0x03e3
    return_test(text_prepare_1);                                                          //06-09-12|0x03e4
}                                                                                         //06-09-12|0x03e5
//                                                                                        //05-24-97|0x03e5
//***************************************************************************             //09-03-27|0x03e8
//***************************************************************************             //09-03-27|0x03e9
//******                                                               ******             //09-03-27|0x03ea
//******                          update_task_no                       ******             //09-03-27|0x03eb
//******                                                               ******             //09-03-27|0x03ec
//***************************************************************************             //09-03-27|0x03ed
//***************************************************************************             //09-03-27|0x03ee
//*******************************************************************************         //10-29-97|0x03f2
//*******************************************************************************         //10-29-97|0x03f2
// update_task_no                                                                         //09-03-27|0x03f2
//*******************************************************************************         //10-29-97|0x03f2
//*******************************************************************************         //10-29-97|0x03f2
UINT SOURCEPROJ::update_task_no(                                                          //09-03-27|0x03f2
    UINT_FAR TaskNoFar                                                                    //09-03-27|0x03f2
    ) {                                                                                   //09-03-27|0x03f2
//*******************************************************************************         //10-29-97|0x03f2
//***************************************************************************             //09-03-27|0x03f5
//***************************************************************************             //09-03-27|0x03f6
  WORDS task_no;                                                                     //09-03-27|0x03f7
//***************************************************************************             //09-03-27|0x03f8
//***************************************************************************             //09-03-27|0x03f9
    IfNoTokens(1, 1)          ReturnFinish("Illegal No Parameters");                      //09-03-27|0x03fa
//***************************************************************************             //09-03-27|0x03fb
    if(StrToInt(TokensLineAddr(0),  task_no.ulong) == 0)                                  //09-03-27|0x03fc
                              ReturnFinish("Illegal Sequence Parameter");                 //09-03-27|0x03fd
//***************************************************************************             //09-03-27|0x03fe
    if(*TaskNoFar > task_no.word0)                                                        //09-03-27|0x03ff
                              ReturnFinish("Illegal Sequence");                           //09-03-27|0x0400
    *TaskNoFar = task_no.word0;                                                           //09-03-27|0x0401
    return_test(update_task_no_1);                                                        //09-03-27|0x0402
}                                                                                         //09-03-27|0x0403
//                                                                                        //05-24-97|0x0403
//***************************************************************************             //06-09-13|0x0406
//***************************************************************************             //06-09-13|0x0407
//******                                                               ******             //06-09-13|0x0408
//******                          open_library                         ******             //06-09-13|0x0409
//******                                                               ******             //06-09-13|0x040a
//***************************************************************************             //06-09-13|0x040b
//***************************************************************************             //06-09-13|0x040c
//*******************************************************************************         //10-29-97|0x0410
//*******************************************************************************         //10-29-97|0x0410
// open_library                                                                           //06-09-13|0x0410
//*******************************************************************************         //10-29-97|0x0410
//*******************************************************************************         //10-29-97|0x0410
UINT SOURCEPROJ::open_library(void) {                                                     //06-09-13|0x0410
//*******************************************************************************         //10-29-97|0x0410
//***************************************************************************             //06-09-13|0x0413
//***************************************************************************             //06-09-13|0x0414
    IfNoTokens(2, 2)                   ReturnFinish("Illegal No Parameters");             //06-09-13|0x0415
//***************************************************************************             //06-09-13|0x0416
    switch(MacDictOpen(TokensTokenAddr(1)))                      _SwitchGroup             //06-09-13|0x0417
    return_test(open_library_1);                                                          //06-09-13|0x0418
}                                                                                         //06-09-13|0x0419
//                                                                                        //05-24-97|0x0419
//***************************************************************************             //06-09-13|0x041c
//***************************************************************************             //06-09-13|0x041d
//******                                                               ******             //06-09-13|0x041e
//******                          load_srce_extent                     ******             //06-09-13|0x041f
//******                                                               ******             //06-09-13|0x0420
//***************************************************************************             //06-09-13|0x0421
//***************************************************************************             //06-09-13|0x0422
//*******************************************************************************         //10-29-97|0x0426
//*******************************************************************************         //10-29-97|0x0426
// load_srce_extent                                                                       //06-09-13|0x0426
//*******************************************************************************         //10-29-97|0x0426
//*******************************************************************************         //10-29-97|0x0426
UINT SOURCEPROJ::load_srce_extent(void) {                                                 //06-09-13|0x0426
//*******************************************************************************         //10-29-97|0x0426
//***************************************************************************             //06-09-13|0x0429
//***************************************************************************             //06-09-13|0x042a
    if(TokensNoTokens  != 2)           ReturnFinish("Illegal No Parameters");             //06-09-13|0x042b
    if(TokensType(1)   != I_TOKEN)    ReturnFinish("Extent Must be a token");             //06-09-13|0x042c
    if(TokensLength(1) >= 48)               ReturnFinish("Extent Too Large");             //08-02-08|0x042d
    if(TokensChar(1, TokensLength(1))  != 0)               ReturnSystemError;             //06-09-13|0x042e
//***************************************************************************             //06-09-13|0x042f
    StrCpy(FilesSrcExtent,  TokensLineAddr(1));                                           //06-09-13|0x0430
    FilesOutNoFiles  = 0;                                                                 //06-09-13|0x0431
    return_test(load_srce_extent_1);                                                      //06-09-13|0x0432
}                                                                                         //06-09-13|0x0433
//                                                                                        //05-24-97|0x0433
//***************************************************************************             //07-03-23|0x0436
//***************************************************************************             //07-03-23|0x0437
//******                                                               ******             //07-03-23|0x0438
//******                          load_out_path_ext                    ******             //07-03-23|0x0439
//******                                                               ******             //07-03-23|0x043a
//***************************************************************************             //07-03-23|0x043b
//***************************************************************************             //07-03-23|0x043c
//*******************************************************************************         //10-29-97|0x0440
//*******************************************************************************         //10-29-97|0x0440
// load_out_path_ext                                                                      //07-03-23|0x0440
//*******************************************************************************         //10-29-97|0x0440
//*******************************************************************************         //10-29-97|0x0440
UINT SOURCEPROJ::load_out_path_ext(void) {                                                //07-03-23|0x0440
//*******************************************************************************         //10-29-97|0x0440
//***************************************************************************             //07-03-23|0x0443
//***************************************************************************             //07-03-23|0x0444
    if(TokensNoTokens  != 2)           ReturnFinish("Illegal No Parameters");             //07-03-23|0x0445
    if(FilesOutNoFiles >= 16)          ReturnFinish("Too Many Output Files");             //07-03-23|0x0446
//***************************************************************************             //07-03-23|0x0447
    if(TokensType(0)   != I_TOKEN)      ReturnFinish("Path Must be a token");             //08-02-08|0x0448
    if(TokensLength(0) >= _MAX_PATH)          ReturnFinish("Path Too Large");             //08-02-08|0x0449
    if(TokensChar(0, TokensLength(0))  != 0)               ReturnSystemError;             //07-03-23|0x044a
//---------------------------------------------------------------------------             //07-03-23|0x044b
    StrCpy(FilesOutPath(FilesOutNoFiles),     TokensLineAddr(0));                         //07-03-23|0x044c
//***************************************************************************             //07-03-23|0x044d
    if(TokensType(1)   != I_TOKEN)    ReturnFinish("Extent Must be a token");             //07-03-23|0x044e
    if(TokensLength(1) >= 48)               ReturnFinish("Extent Too Large");             //08-02-08|0x044f
    if(TokensChar(1, TokensLength(1))  != 0)               ReturnSystemError;             //07-03-23|0x0450
//---------------------------------------------------------------------------             //07-03-23|0x0451
    StrCpy(FilesOutExtent(FilesOutNoFiles),   TokensLineAddr(1));                         //07-03-23|0x0452
//***************************************************************************             //07-03-23|0x0453
    ++FilesOutNoFiles;                                                                    //07-03-23|0x0454
    return_test(load_out_path_ext_1);                                                     //07-03-23|0x0455
}                                                                                         //07-03-23|0x0456
//                                                                                        //05-24-97|0x0456
//***************************************************************************             //09-03-10|0x0459
//***************************************************************************             //09-03-10|0x045a
//******                                                               ******             //09-03-10|0x045b
//******                          load_mailbox                         ******             //09-03-10|0x045c
//******                                                               ******             //09-03-10|0x045d
//***************************************************************************             //09-03-10|0x045e
//***************************************************************************             //09-03-10|0x045f
//*******************************************************************************         //10-29-97|0x0464
//*******************************************************************************         //10-29-97|0x0464
// load_mailbox                                                                           //09-03-10|0x0464
//*******************************************************************************         //10-29-97|0x0464
//*******************************************************************************         //10-29-97|0x0464
UINT SOURCEPROJ::load_mailbox(                                                            //09-03-10|0x0464
    UINT Status                                                                           //09-03-10|0x0464
    ) {                                                                                   //09-03-10|0x0464
//*******************************************************************************         //10-29-97|0x0464
//***************************************************************************             //09-03-10|0x0467
//***************************************************************************             //09-03-10|0x0468
  UINT i;                                                                            //09-06-29|0x0469
  STRING_DATA_FAR mail_box_addr;                                                     //09-06-29|0x046a
//***************************************************************************             //09-06-29|0x046b
//***************************************************************************             //09-06-29|0x046c
    if(TokensNoTokens      != 2)  ReturnFinish("Illegal No Parameters");                  //09-03-10|0x046d
    if(FilesMailBoxNoFiles >= 16) ReturnFinish("Too Many Post Office Files");             //10-01-03|0x046e
//***************************************************************************             //10-01-03|0x046f
//***                                                                    ****             //10-01-03|0x0470
//*** Check the string sizes                                             ****             //10-01-03|0x0471
//***                                                                    ****             //10-01-03|0x0472
//***************************************************************************             //10-01-03|0x0473
    if(TokensType(1)   != I_TOKEN)      ReturnFinish("Name Must be a Token");             //09-03-10|0x0474
    if(TokensLength(1) >= _MAX_PATH)    ReturnFinish("Name Too Large");                   //09-03-10|0x0475
    if(TokensChar(1, TokensLength(1))  != 0)               ReturnSystemError;             //09-03-10|0x0476
//---------------------------------------------------------------------------             //09-03-10|0x0477
    if(TokensType(0)   != I_TOKEN)      ReturnFinish("Path Must be a token");             //09-03-10|0x0478
    if(TokensLength(0) >= _MAX_PATH)          ReturnFinish("Path Too Large");             //09-03-10|0x0479
    if(TokensChar(0, TokensLength(0))  != 0)               ReturnSystemError;             //09-03-10|0x047a
//---------------------------------------------------------------------------             //09-03-10|0x047b
    if((TokensLength(0) + TokensLength(1)) >= _MAX_PATH)                                  //09-03-10|0x047c
                                 ReturnFinish("Mailbox File Name Too Large");             //09-03-10|0x047d
//***************************************************************************             //10-01-03|0x047e
//***                                                                    ****             //10-01-03|0x047f
//*** Check for duplicate names                                          ****             //10-01-03|0x0480
//***                                                                    ****             //10-01-03|0x0481
//***************************************************************************             //10-01-03|0x0482
    for(i=0;  i < FilesMailBoxNoFiles; ++i)                                               //09-06-29|0x0483
      {                                                                                   //09-06-29|0x0484
        mail_box_addr = &FilesMailBoxName(i);                                             //09-06-29|0x0485
        switch(StrCmp(MailBoxNameLineAddr, TokensLineAddr(1)))                            //11-05-30|0x0486
          {                                                                               //11-05-30|0x0487
            case 0:           ReturnFinish("Duplicate PostOffice File Name");             //11-05-30|0x0488
            case 1:                                                                       //11-05-30|0x0489
            case -1:                                                   break;             //11-05-30|0x048a
            default:                                        ReturnSystemError             //11-05-30|0x048b
            }                                                                             //11-05-30|0x048c
        }                                                                                 //09-06-29|0x048d
//***************************************************************************             //10-01-03|0x048e
//***                                                                    ****             //10-01-03|0x048f
//*** Build the complete path and load the name                          ****             //10-01-03|0x0490
//***                                                                    ****             //10-01-03|0x0491
//***************************************************************************             //10-01-03|0x0492
    StrCpy(FilesMailBoxPath,                            TokensLineAddr(0));               //10-01-03|0x0493
    StrCat(FilesMailBoxPath,                            TokensLineAddr(1));               //10-01-03|0x0494
//***************************************************************************             //10-01-03|0x0495
    switch(MailDictName(FilesMailBoxNoFiles,  FilesMailBoxPath)) _SwitchGroup             //10-01-03|0x0496
//***************************************************************************             //10-01-03|0x0497
//***                                                                    ****             //10-01-03|0x0498
//*** Complete the mailbox record                                        ****             //10-01-03|0x0499
//***                                                                    ****             //10-01-03|0x049a
//***************************************************************************             //10-01-03|0x049b
    StrDataCpy(&FilesMailBoxName(FilesMailBoxNoFiles),  TokensTokenAddr(1));              //10-01-03|0x049c
    FilesMailBoxStatus(FilesMailBoxNoFiles) = Status;                                     //09-03-10|0x049d
//---------------------------------------------------------------------------             //09-03-10|0x049e
    ++FilesMailBoxNoFiles;                                                                //09-03-10|0x049f
    return_test(load_mailbox_1);                                                          //09-03-10|0x04a0
}                                                                                         //09-03-10|0x04a1
//                                                                                        //05-24-97|0x04a1
//***************************************************************************             //09-03-10|0x04a4
//***************************************************************************             //09-03-10|0x04a5
//******                                                               ******             //09-03-10|0x04a6
//******                        mailbox_dates                          ******             //09-03-10|0x04a7
//******                                                               ******             //09-03-10|0x04a8
//***************************************************************************             //09-03-10|0x04a9
//***************************************************************************             //09-03-10|0x04aa
//*******************************************************************************         //10-29-97|0x04b2
//*******************************************************************************         //10-29-97|0x04b2
// mailbox_dates                                                                          //10-01-03|0x04b2
//*******************************************************************************         //10-29-97|0x04b2
//*******************************************************************************         //10-29-97|0x04b2
UINT SOURCEPROJ::mailbox_dates(void) {                                                    //10-01-03|0x04b2
//*******************************************************************************         //10-29-97|0x04b2
//***************************************************************************             //09-03-10|0x04b5
//***************************************************************************             //09-03-10|0x04b6
  ULONG mailbox_time;                                                                //09-03-10|0x04b7
  UINT i;                                                                            //09-03-10|0x04b8
  UINT status;                                                                       //09-03-10|0x04b9
//***************************************************************************             //09-03-10|0x04ba
//***************************************************************************             //09-03-10|0x04bb
    status = No;                                                                          //09-03-10|0x04bc
//***************************************************************************             //09-06-20|0x04bd
    if(FilesMailBoxNoFiles  >  16)                         ReturnSystemError;             //09-06-20|0x04be
//***************************************************************************             //10-01-03|0x04bf
//***                                                                     ***             //10-01-03|0x04c0
//***  Check the dates                                                    ***             //10-01-03|0x04c1
//***                                                                     ***             //10-01-03|0x04c2
//***************************************************************************             //10-01-03|0x04c3
    for(i=0;  i<FilesMailBoxNoFiles; ++i)                                                 //09-03-10|0x04c4
      {                                                                                   //09-03-10|0x04c5
        switch(MailDictExists(i,  &mailbox_time))                _SwitchGroup             //09-03-10|0x04c6
//***************************************************************************             //10-01-03|0x04c7
//***                                                                     ***             //10-01-03|0x04c8
//***  mailbox files do not exist                                         ***             //10-01-03|0x04c9
//***                                                                     ***             //10-01-03|0x04ca
//***************************************************************************             //10-01-03|0x04cb
        if(mailbox_time == 0)                                                             //09-03-10|0x04cc
          {                                                                               //09-03-10|0x04cd
            switch(FilesMailBoxStatus(i))                                                 //09-03-10|0x04ce
              {                                                                           //09-03-10|0x04cf
//---------------------------------------------------------------------------             //09-03-10|0x04d0
                case POSTOFFICE_FILE:                                                     //09-03-10|0x04d1
                  FilesMailBoxStatus(i) = CREATE_POSTOFFICE;                              //09-03-10|0x04d2
                  status                = Yes;                                            //09-03-10|0x04d3
                  break_test(mailbox_dates_1);                                            //09-03-10|0x04d4
//---------------------------------------------------------------------------             //09-03-10|0x04d5
                case MAILBOX_FILE:                                                        //09-03-10|0x04d6
                  ReturnFinish("Mail Box File Cannot Be Created");                        //09-11-17|0x04d7
//---------------------------------------------------------------------------             //09-03-10|0x04d8
                default:                                   ReturnSystemError;             //09-03-10|0x04d9
                }                                                                         //09-03-10|0x04da
            }                                                                             //09-03-10|0x04db
//***************************************************************************             //10-01-03|0x04dc
//***                                                                     ***             //10-01-03|0x04dd
//***  mailbox files exist                                                ***             //10-01-03|0x04de
//***                                                                     ***             //10-01-03|0x04df
//***************************************************************************             //10-01-03|0x04e0
          else {                                                                          //09-03-14|0x04e1
            switch(FilesMailBoxStatus(i))                                                 //09-03-14|0x04e2
              {                                                                           //09-03-14|0x04e3
//---------------------------------------------------------------------------             //09-03-14|0x04e4
                case POSTOFFICE_FILE:                                                     //09-03-14|0x04e5
                  FilesMailBoxStatus(i) = CREATE_POSTOFFICE;                              //10-01-03|0x04e6
                  if(mailbox_time <= SourceOutTime)   status = Yes;                       //10-01-03|0x04e7
                  if(0xffffffff   == SourceOutTime)   status = Yes;                       //10-01-03|0x04e8
                  break_test(mailbox_dates_3);                                            //10-01-03|0x04e9
//---------------------------------------------------------------------------             //09-03-14|0x04ea
                case MAILBOX_FILE:                                                        //09-03-14|0x04eb
                  FilesMailBoxStatus(i) = OPEN_MAILBOX;                                   //09-03-14|0x04ec
                  if(mailbox_time >= SourceOutTime)                                       //10-06-11|0x04ed
                                       SourceOutTime = mailbox_time;                      //10-06-11|0x04ee
                  break_test(mailbox_dates_4);                                            //10-01-03|0x04ef
//---------------------------------------------------------------------------             //10-01-03|0x04f0
                case OPENED_POSTOFFICE:                                                   //10-01-06|0x04f1
                  status = Yes;                                                           //10-01-06|0x04f2
                  break_test(mailbox_dates_5);                                            //10-01-06|0x04f3
//---------------------------------------------------------------------------             //10-01-06|0x04f4
                case OPENED_MAILBOX:                                                      //10-01-06|0x04f5
                  if(mailbox_time >= SourceOutTime)                                       //10-06-11|0x04f6
                                       SourceOutTime = mailbox_time;                      //10-06-11|0x04f7
                  break_test(mailbox_dates_6);                                            //10-01-06|0x04f8
//---------------------------------------------------------------------------             //09-03-14|0x04f9
                default:                                   ReturnSystemError;             //09-03-14|0x04fa
                }                                                                         //09-03-14|0x04fb
            }                                                                             //09-03-10|0x04fc
        }                                                                                 //09-03-10|0x04fd
//***************************************************************************             //10-01-06|0x04fe
//***                                                                     ***             //10-01-06|0x04ff
//***  note the end of date analysis                                      ***             //10-01-06|0x0500
//***                                                                     ***             //10-01-06|0x0501
//***************************************************************************             //10-01-06|0x0502
    switch(MailDictDateDone())                                   _SwitchGroup             //10-01-06|0x0503
    return(status);                                                                       //09-03-10|0x0504
}                                                                                         //09-03-10|0x0505
//                                                                                        //05-24-97|0x0505
//***************************************************************************             //07-06-06|0x0508
//***************************************************************************             //07-06-06|0x0509
//******                                                               ******             //07-06-06|0x050a
//******                          error_control                        ******             //07-06-06|0x050b
//******                                                               ******             //07-06-06|0x050c
//***************************************************************************             //07-06-06|0x050d
//***************************************************************************             //07-06-06|0x050e
//*******************************************************************************         //10-29-97|0x0514
//*******************************************************************************         //10-29-97|0x0514
// error_control                                                                          //07-06-06|0x0514
//*******************************************************************************         //10-29-97|0x0514
//*******************************************************************************         //10-29-97|0x0514
UINT SOURCEPROJ::error_control(                                                           //07-06-06|0x0514
    SCHAR_FAR Addr,                                                                       //07-06-06|0x0514
    UINT Error_Control                                                                    //07-06-06|0x0514
    ) {                                                                                   //07-06-06|0x0514
//*******************************************************************************         //10-29-97|0x0514
//***************************************************************************             //07-06-06|0x0517
//***************************************************************************             //07-06-06|0x0518
    if(CmdTest(Addr)  != 0)                       return_no(error_control_1);             //07-06-06|0x0519
    if(TokensNoTokens != 1)            ReturnFinish("Illegal No Parameters");             //07-06-06|0x051a
    SourceErrorControl = Error_Control;                                                   //07-06-06|0x051b
    return_yes(error_control_2);                                                          //07-06-06|0x051c
}                                                                                         //07-06-06|0x051d
//                                                                                        //05-24-97|0x051d
//***************************************************************************             //10-05-15|0x0520
//***************************************************************************             //10-05-15|0x0521
//******                                                               ******             //10-05-15|0x0522
//******                          load_in_path_ext                     ******             //10-05-15|0x0523
//******                                                               ******             //10-05-15|0x0524
//***************************************************************************             //10-05-15|0x0525
//***************************************************************************             //10-05-15|0x0526
//*******************************************************************************         //10-29-97|0x052a
//*******************************************************************************         //10-29-97|0x052a
// load_in_path_ext                                                                       //10-05-15|0x052a
//*******************************************************************************         //10-29-97|0x052a
//*******************************************************************************         //10-29-97|0x052a
UINT SOURCEPROJ::load_in_path_ext(void) {                                                 //10-05-15|0x052a
//*******************************************************************************         //10-29-97|0x052a
//***************************************************************************             //10-05-15|0x052d
//***************************************************************************             //10-05-15|0x052e
    if(TokensNoTokens != 2)            ReturnFinish("Illegal No Parameters");             //10-05-15|0x052f
    if(FilesInNoFiles >= 16)            ReturnFinish("Too Many Input Files");             //10-05-15|0x0530
//***************************************************************************             //10-05-15|0x0531
    if(TokensType(0)   != I_TOKEN)      ReturnFinish("Path Must be a token");             //10-05-15|0x0532
    if(TokensLength(0) >= _MAX_PATH)          ReturnFinish("Path Too Large");             //10-05-15|0x0533
    if(TokensChar(0, TokensLength(0))  != 0)               ReturnSystemError;             //10-05-15|0x0534
//---------------------------------------------------------------------------             //10-05-15|0x0535
    StrCpy(FilesInPath(FilesInNoFiles),     TokensLineAddr(0));                           //10-05-15|0x0536
//***************************************************************************             //10-05-15|0x0537
    if(TokensType(1)   != I_TOKEN)    ReturnFinish("Extent Must be a token");             //10-05-15|0x0538
    if(TokensLength(1) >= 48)               ReturnFinish("Extent Too Large");             //10-05-15|0x0539
    if(TokensChar(1, TokensLength(1))  != 0)               ReturnSystemError;             //10-05-15|0x053a
//---------------------------------------------------------------------------             //10-05-15|0x053b
    StrCpy(FilesInExtent(FilesInNoFiles),   TokensLineAddr(1));                           //10-05-15|0x053c
//***************************************************************************             //10-05-15|0x053d
    ++FilesInNoFiles;                                                                     //10-05-15|0x053e
    return_test(load_in_path_ext_1);                                                      //10-05-15|0x053f
}                                                                                         //10-05-15|0x0540
//                                                                                        //05-24-97|0x0540
//***************************************************************************             //06-09-13|0x0543
//***************************************************************************             //06-09-13|0x0544
//******                                                               ******             //06-09-13|0x0545
//******                          uncond_update                        ******             //06-09-13|0x0546
//******                                                               ******             //06-09-13|0x0547
//***************************************************************************             //06-09-13|0x0548
//***************************************************************************             //06-09-13|0x0549
//*******************************************************************************         //10-29-97|0x054d
//*******************************************************************************         //10-29-97|0x054d
// uncond_update                                                                          //06-09-13|0x054d
//*******************************************************************************         //10-29-97|0x054d
//*******************************************************************************         //10-29-97|0x054d
UINT SOURCEPROJ::uncond_update(void) {                                                    //06-09-13|0x054d
//*******************************************************************************         //10-29-97|0x054d
//***************************************************************************             //06-09-13|0x0550
//***************************************************************************             //06-09-13|0x0551
    if(TokensNoTokens != 1)            ReturnFinish("Illegal No Parameters");             //06-09-13|0x0552
//***************************************************************************             //06-09-13|0x0553
    SourceOutTime = 0xffffffff;                                                           //07-10-30|0x0554
//***************************************************************************             //06-09-13|0x0555
    return_test(uncond_update_1);                                                         //06-09-13|0x0556
}                                                                                         //06-09-13|0x0557
//                                                                                        //05-24-97|0x0557
//***************************************************************************             //06-09-25|0x055a
//***************************************************************************             //06-09-25|0x055b
//******                                                               ******             //06-09-25|0x055c
//******                        output_names                           ******             //06-09-25|0x055d
//******                                                               ******             //06-09-25|0x055e
//***************************************************************************             //06-09-25|0x055f
//***************************************************************************             //06-09-25|0x0560
//*******************************************************************************         //10-29-97|0x0564
//*******************************************************************************         //10-29-97|0x0564
// output_names                                                                           //06-09-25|0x0564
//*******************************************************************************         //10-29-97|0x0564
//*******************************************************************************         //10-29-97|0x0564
UINT SOURCEPROJ::output_names(void) {                                                     //06-09-25|0x0564
//*******************************************************************************         //10-29-97|0x0564
//***************************************************************************             //06-09-25|0x0567
//***************************************************************************             //06-09-25|0x0568
  UINT i;                                                                            //06-09-25|0x0569
//***************************************************************************             //06-09-25|0x056a
//***************************************************************************             //06-09-25|0x056b
    if(GetOutputName == 0)                                  ReturnSystemError             //07-03-23|0x056c
//***************************************************************************             //07-03-23|0x056d
    for(i=0;  i<FilesOutNoFiles; ++i)                                                     //06-09-25|0x056e
      {                                                                                   //06-09-25|0x056f
        switch(InitialOutFile(i))                                _SwitchGroup             //06-09-25|0x0570
        switch(EnterOutPath(i))                                  _SwitchGroup             //07-03-23|0x0571
        switch(EnterOutFileName(i))                              _SwitchGroup             //06-09-25|0x0572
        switch(FileRelease())                                    _SwitchGroup             //06-09-25|0x0573
        }                                                                                 //06-09-25|0x0574
    return_test(output_names_1);                                                          //06-09-25|0x0575
}                                                                                         //06-09-25|0x0576
//                                                                                        //05-24-97|0x0576
//***************************************************************************             //07-01-30|0x0579
//***************************************************************************             //07-01-30|0x057a
//******                                                               ******             //07-01-30|0x057b
//******                        output_dates                           ******             //07-01-30|0x057c
//******                                                               ******             //07-01-30|0x057d
//***************************************************************************             //07-01-30|0x057e
//***************************************************************************             //07-01-30|0x057f
//*******************************************************************************         //10-29-97|0x0585
//*******************************************************************************         //10-29-97|0x0585
// output_dates                                                                           //07-01-30|0x0585
//*******************************************************************************         //10-29-97|0x0585
//*******************************************************************************         //10-29-97|0x0585
UINT SOURCEPROJ::output_dates(void) {                                                     //07-01-30|0x0585
//*******************************************************************************         //10-29-97|0x0585
//***************************************************************************             //07-01-30|0x0588
//***************************************************************************             //07-01-30|0x0589
  UINT i;                                                                            //07-01-30|0x058a
//***************************************************************************             //07-01-30|0x058b
//***************************************************************************             //07-01-30|0x058c
    for(i=0;  i<FilesOutNoFiles; ++i)                                                     //07-01-30|0x058d
      {                                                                                   //07-01-30|0x058e
        switch(CommitOutFile(i))                                 _SwitchGroup             //07-01-30|0x058f
        switch(FileExists(SourceInTimeAddr))                     _SwitchGroup             //07-01-30|0x0590
        switch(FileRelease())                                    _SwitchGroup             //07-01-30|0x0591
        if(SourceInTime < SourceOutTime)                                                  //08-04-17|0x0592
                                                  return_yes(output_dates_1);             //08-04-17|0x0593
        }                                                                                 //07-01-30|0x0594
    return_no(output_dates_2);                                                            //07-01-30|0x0595
}                                                                                         //07-01-30|0x0596
//                                                                                        //05-24-97|0x0596
//***************************************************************************             //06-09-25|0x0599
//***************************************************************************             //06-09-25|0x059a
//******                                                               ******             //06-09-26|0x059b
//******                            push_call                          ******             //06-09-26|0x059c
//******                                                               ******             //06-09-26|0x059d
//***************************************************************************             //06-09-26|0x059e
//***************************************************************************             //06-09-26|0x059f
//*******************************************************************************         //10-29-97|0x05a3
//*******************************************************************************         //10-29-97|0x05a3
// push_call                                                                              //06-09-26|0x05a3
//*******************************************************************************         //10-29-97|0x05a3
//*******************************************************************************         //10-29-97|0x05a3
UINT SOURCEPROJ::push_call(void) {                                                        //06-09-26|0x05a3
//*******************************************************************************         //10-29-97|0x05a3
//***************************************************************************             //06-09-26|0x05a6
//***************************************************************************             //06-09-26|0x05a7
  UINT i;                                                                            //06-09-26|0x05a8
//***************************************************************************             //06-09-26|0x05a9
//***************************************************************************             //06-09-26|0x05aa
    if(TokensNoTokens    < 1)                               ReturnSystemError             //07-07-11|0x05ab
    if(ArgumentsNoTokens > 9)                               ReturnSystemError             //07-07-11|0x05ac
//***************************************************************************             //07-07-11|0x05ad
    TokensNoTokens  = 1;                                                                  //07-07-11|0x05ae
    i               = 0;                                                                  //07-07-11|0x05af
//---------------------------------------------------------------------------             //07-07-11|0x05b0
    while(i<ArgumentsNoTokens)                                                            //07-07-11|0x05b1
      {                                                                                   //07-07-11|0x05b2
        StrDataCpy(TokensTokenAddr(TokensNoTokens), ArgumentsTokenAddr(i));               //07-07-11|0x05b3
        ++TokensNoTokens;                                                                 //07-07-11|0x05b4
        ++i;                                                                              //07-07-11|0x05b5
        }                                                                                 //07-07-11|0x05b6
//***************************************************************************             //06-09-26|0x05b7
    switch(CallPrePush(SourceTokensAddr))                        _SwitchGroup             //07-05-02|0x05b8
//---------------------------------------------------------------------------             //06-09-26|0x05b9
    return_test(push_call_1);                                                             //06-09-26|0x05ba
}                                                                                         //06-09-26|0x05bb
//                                                                                        //05-24-97|0x05bb
//***************************************************************************             //06-09-30|0x05be
//***************************************************************************             //06-09-30|0x05bf
//******                                                               ******             //06-09-30|0x05c0
//******                            pop_call                           ******             //06-09-30|0x05c1
//******                                                               ******             //06-09-30|0x05c2
//***************************************************************************             //06-09-30|0x05c3
//***************************************************************************             //06-09-30|0x05c4
//*******************************************************************************         //10-29-97|0x05ca
//*******************************************************************************         //10-29-97|0x05ca
// pop_call                                                                               //06-09-30|0x05ca
//*******************************************************************************         //10-29-97|0x05ca
//*******************************************************************************         //10-29-97|0x05ca
UINT SOURCEPROJ::pop_call(void) {                                                         //06-09-30|0x05ca
//*******************************************************************************         //10-29-97|0x05ca
//***************************************************************************             //06-10-05|0x05cd
//***************************************************************************             //06-10-05|0x05ce
loop:                                                                                     //06-09-30|0x05cf
    switch(CallPreLeveltest(0))                                                           //06-09-30|0x05d0
      {                                                                                   //06-09-30|0x05d1
//---------------------------------------------------------------------------             //06-09-30|0x05d2
        case No:    switch(CallTestSrc())                                                 //07-06-06|0x05d3
                      {                                                                   //07-06-06|0x05d4
                        case Yes:     switch(CallExitPop())     _SwitchGroup;             //07-07-06|0x05d5
                                      switch(CallPrePop())      _SwitchGroup;             //07-07-06|0x05d6
                                      return_test(pop_call_1);                            //07-07-06|0x05d7
                        case No:      switch(CallExitPop())     _SwitchGroup;             //07-07-11|0x05d8
                                      goto_test(pop_call_2);                              //07-06-06|0x05d9
                        default:                           ReturnSystemError;             //07-06-06|0x05da
                        }                                                                 //07-06-06|0x05db
//---------------------------------------------------------------------------             //06-09-30|0x05dc
        case Yes:    switch(CallPrePop())                        _SwitchGroup             //06-10-05|0x05dd
                     return_test(pop_call_3);                                             //07-06-06|0x05de
//---------------------------------------------------------------------------             //06-10-05|0x05df
        default:                                           ReturnSystemError;             //06-09-30|0x05e0
        }                                                                                 //06-09-30|0x05e1
}                                                                                         //06-10-05|0x05e2
//                                                                                        //05-24-97|0x05e2
//***************************************************************************             //06-09-12|0x05e5
//***************************************************************************             //06-09-12|0x05e6
//******                                                               ******             //06-09-12|0x05e7
//******                         close_project                         ******             //06-09-12|0x05e8
//******                                                               ******             //06-09-12|0x05e9
//***************************************************************************             //06-09-12|0x05ea
//***************************************************************************             //06-09-12|0x05eb
//*******************************************************************************         //10-29-97|0x05f0
//*******************************************************************************         //10-29-97|0x05f0
// close_project                                                                          //06-09-12|0x05f0
//*******************************************************************************         //10-29-97|0x05f0
//*******************************************************************************         //10-29-97|0x05f0
UINT SOURCEPROJ::close_project(                                                           //06-09-12|0x05f0
    TEXT_FILE_DATA_FAR TextFileAddr                                                       //06-09-12|0x05f0
    ) {                                                                                   //06-09-12|0x05f0
//*******************************************************************************         //10-29-97|0x05f0
//***************************************************************************             //06-09-12|0x05f3
//***************************************************************************             //06-09-12|0x05f4
    switch(CommitFile)                                           _SwitchGroup             //06-09-12|0x05f5
    switch(FileClose())                                          _SwitchGroup             //06-09-12|0x05f6
    switch(FileRelease())                                        _SwitchGroup             //06-09-12|0x05f7
//***************************************************************************             //06-09-12|0x05f8
    return_test(close_project_1);                                                         //06-09-12|0x05f9
}                                                                                         //06-09-12|0x05fa
//                                                                                        //05-24-97|0x05fa
//***************************************************************************             //check   |0x05fd
//***************************************************************************             //check   |0x05fe
//******                                                               ******             //check   |0x05ff
//******                        test_output_status                     ******             //check   |0x0600
//******                                                               ******             //check   |0x0601
//***************************************************************************             //check   |0x0602
//***************************************************************************             //check   |0x0603
//*******************************************************************************         //10-29-97|0x0606
//*******************************************************************************         //10-29-97|0x0606
// test_output_status                                                                     //check   |0x0606
//*******************************************************************************         //10-29-97|0x0606
//*******************************************************************************         //10-29-97|0x0606
UINT SOURCEPROJ::test_output_status(void) {                                               //check   |0x0606
//*******************************************************************************         //10-29-97|0x0606
//***************************************************************************             //check   |0x0609
//***************************************************************************             //check   |0x060a
  UINT i;                                                                            //check   |0x060b
//***************************************************************************             //check   |0x060c
//***************************************************************************             //check   |0x060d
    for(i=0;  i<FilesOutNoFiles; ++i)                                                     //check   |0x060e
      {                                                                                   //check   |0x060f
        switch(FilesOutStatus(i))                                                         //check   |0x0610
          {                                                                               //check   |0x0611
            case 0:                                                    break;             //check   |0x0612
            case 1:                                                    break;             //check   |0x0613
            case 2:                   ReturnFinish("Incomplete Output Line");             //check   |0x0614
            default:                                        ReturnSystemError             //check   |0x0615
            }                                                                             //check   |0x0616
        }                                                                                 //check   |0x0617
    return(Success);                                                                      //check   |0x0618
}                                                                                         //check   |0x0619
//                                                                                        //05-24-97|0x0619
//***************************************************************************             //08-04-18|0x061c
//***************************************************************************             //08-04-18|0x061d
//******                                                               ******             //08-04-18|0x061e
//******                        close_output                           ******             //08-04-18|0x061f
//******                                                               ******             //08-04-18|0x0620
//***************************************************************************             //08-04-18|0x0621
//***************************************************************************             //08-04-18|0x0622
//*******************************************************************************         //10-29-97|0x0628
//*******************************************************************************         //10-29-97|0x0628
// close_output                                                                           //08-04-18|0x0628
//*******************************************************************************         //10-29-97|0x0628
//*******************************************************************************         //10-29-97|0x0628
UINT SOURCEPROJ::close_output(void) {                                                     //08-04-18|0x0628
//*******************************************************************************         //10-29-97|0x0628
//***************************************************************************             //08-04-18|0x062b
//***************************************************************************             //08-04-18|0x062c
  UINT i;                                                                            //08-04-18|0x062d
//***************************************************************************             //08-04-18|0x062e
//***************************************************************************             //08-04-18|0x062f
    for(i=0;  i<FilesOutNoFiles; ++i)                                                     //08-04-18|0x0630
      {                                                                                   //08-04-18|0x0631
        switch(OpenStateOutFile(i))                                                       //08-04-18|0x0632
          {                                                                               //08-04-18|0x0633
            case No:                              break_test(close_output_1);             //08-04-18|0x0634
            case Yes:                                                                     //08-04-18|0x0635
              switch(CommitOutFile(i))                           _SwitchGroup             //08-04-18|0x0636
              switch(FileClose())                                _SwitchGroup             //08-04-18|0x0637
              switch(FileRelease())                              _SwitchGroup             //08-04-18|0x0638
              break_test(close_output_2);                                                 //08-04-18|0x0639
            default:                                        ReturnSystemError             //08-04-18|0x063a
            }                                                                             //08-04-18|0x063b
        }                                                                                 //08-04-18|0x063c
    return_test(close_output_3);                                                          //08-04-18|0x063d
}                                                                                         //08-04-18|0x063e
//                                                                                        //05-24-97|0x063e
//***************************************************************************             //10-05-15|0x0641
//***************************************************************************             //10-05-15|0x0642
//******                                                               ******             //10-05-15|0x0643
//******                         close_text                            ******             //10-05-15|0x0644
//******                                                               ******             //10-05-15|0x0645
//***************************************************************************             //10-05-15|0x0646
//***************************************************************************             //10-05-15|0x0647
//*******************************************************************************         //10-29-97|0x064b
//*******************************************************************************         //10-29-97|0x064b
// close_text                                                                             //10-05-15|0x064b
//*******************************************************************************         //10-29-97|0x064b
//*******************************************************************************         //10-29-97|0x064b
UINT SOURCEPROJ::close_text(void) {                                                       //10-05-15|0x064b
//*******************************************************************************         //10-29-97|0x064b
//***************************************************************************             //10-05-15|0x064e
//***************************************************************************             //10-05-15|0x064f
  UINT i;                                                                            //10-05-15|0x0650
//***************************************************************************             //10-05-15|0x0651
//***************************************************************************             //10-05-15|0x0652
    for(i=0;  i<FilesInNoFiles; ++i)                                                      //10-05-15|0x0653
      {                                                                                   //10-05-15|0x0654
        switch(CommitInputFile(i))                               _SwitchGroup             //10-05-15|0x0655
        switch(FileClose())                                      _SwitchGroup             //10-05-15|0x0656
        switch(FileRelease())                                    _SwitchGroup             //10-05-15|0x0657
        }                                                                                 //10-05-15|0x0658
    return_test(close_text_1);                                                            //10-05-15|0x0659
}                                                                                         //10-05-15|0x065a
//                                                                                        //05-24-97|0x065a
//***************************************************************************             //10-01-03|0x065d
//***************************************************************************             //10-01-03|0x065e
//******                                                               ******             //10-01-03|0x065f
//******                        mailbox_finish                         ******             //10-01-03|0x0660
//******                                                               ******             //10-01-03|0x0661
//***************************************************************************             //10-01-03|0x0662
//***************************************************************************             //10-01-03|0x0663
//*******************************************************************************         //10-29-97|0x066f
//*******************************************************************************         //10-29-97|0x066f
// mailbox_finish                                                                         //10-01-03|0x066f
//*******************************************************************************         //10-29-97|0x066f
//*******************************************************************************         //10-29-97|0x066f
UINT SOURCEPROJ::mailbox_finish(void) {                                                   //10-01-03|0x066f
//*******************************************************************************         //10-29-97|0x066f
//***************************************************************************             //10-01-03|0x0672
//***************************************************************************             //10-01-03|0x0673
  UINT i;                                                                            //10-01-03|0x0674
  UINT status;                                                                       //10-01-03|0x0675
//***************************************************************************             //10-01-03|0x0676
//***************************************************************************             //10-01-03|0x0677
    if(FilesMailBoxNoFiles  >  16)                         ReturnSystemError;             //10-01-03|0x0678
    status = Success;                                                                     //10-01-03|0x0679
//***************************************************************************             //10-01-03|0x067a
    for(i=0;  i<FilesMailBoxNoFiles; ++i)                                                 //10-01-03|0x067b
      {                                                                                   //10-01-03|0x067c
        switch(FilesMailBoxStatus(i))                                                     //10-01-03|0x067d
          {                                                                               //10-01-03|0x067e
//***************************************************************************             //10-01-06|0x067f
//*****                                                                ******             //10-01-06|0x0680
//*****   Postoffices and Mailboxes that have not been opened          ******             //10-01-06|0x0681
//*****                                                                ******             //10-01-06|0x0682
//***************************************************************************             //10-01-06|0x0683
            case CREATE_POSTOFFICE:                                                       //10-01-06|0x0684
                 FilesMailBoxStatus(i) = POSTOFFICE_FILE;                                 //10-01-06|0x0685
                 break_test(mailbox_finish_1);                                            //10-01-06|0x0686
//---------------------------------------------------------------------------             //10-01-06|0x0687
            case OPEN_MAILBOX:                                                            //10-01-06|0x0688
                 FilesMailBoxStatus(i) = MAILBOX_FILE;                                    //10-01-06|0x0689
                 break_test(mailbox_finish_2);                                            //10-01-06|0x068a
//***************************************************************************             //10-01-03|0x068b
//*****                                                                ******             //10-01-03|0x068c
//*****   Postoffices and Mailboxes that have been opened              ******             //10-01-03|0x068d
//*****                                                                ******             //10-01-03|0x068e
//***************************************************************************             //10-01-03|0x068f
            case OPENED_POSTOFFICE:             break_test(mailbox_finish_3);             //10-01-03|0x0690
//---------------------------------------------------------------------------             //10-01-06|0x0691
            case OPENED_MAILBOX:                break_test(mailbox_finish_4);             //10-01-06|0x0692
//***************************************************************************             //10-01-06|0x0693
//*****                                                                ******             //10-01-06|0x0694
//*****   Postoffices and Mailboxes that have not been closed          ******             //10-01-06|0x0695
//*****                                                                ******             //10-01-06|0x0696
//***************************************************************************             //10-01-06|0x0697
            case MAILBOX_OPENED:                                                          //10-01-06|0x0698
                switch(MailDictClose(i))                         _SwitchGroup             //10-01-06|0x0699
                status = Finish("Mail Box Not Properly Closed");                          //10-01-06|0x069a
                 break_test(mailbox_finish_5);                                            //10-01-06|0x069b
//---------------------------------------------------------------------------             //10-01-06|0x069c
            case POSTOFFICE_OPENED:                                                       //10-01-06|0x069d
                switch(MailDictClose(i))                         _SwitchGroup             //10-01-06|0x069e
                status = Finish("Mail Box Not Properly Closed");                          //10-01-06|0x069f
                break_test(mailbox_finish_6);                                             //10-01-06|0x06a0
//***************************************************************************             //10-01-06|0x06a1
//*****                                                                ******             //10-01-06|0x06a2
//*****   Postoffices and Mailboxes that have been deleted             ******             //10-01-06|0x06a3
//*****                                                                ******             //10-01-06|0x06a4
//***************************************************************************             //10-01-06|0x06a5
            case POSTOFFICE_FILE:               break_test(mailbox_finish_3);             //10-01-06|0x06a6
//---------------------------------------------------------------------------             //10-01-06|0x06a7
            case MAILBOX_FILE:                  break_test(mailbox_finish_4);             //10-01-06|0x06a8
//***************************************************************************             //10-01-03|0x06a9
            default:                                       ReturnSystemError;             //09-03-10|0x06aa
            }                                                                             //09-03-10|0x06ab
        }                                                                                 //09-03-10|0x06ac
//***************************************************************************             //10-01-19|0x06ad
//***                                                                     ***             //10-01-19|0x06ae
//***  Reset for new source generation file                               ***             //10-01-19|0x06af
//***                                                                     ***             //10-01-19|0x06b0
//***************************************************************************             //10-01-19|0x06b1
    switch(MailDictTaskDone())                                   _SwitchGroup             //10-01-19|0x06b2
    return(status);                                                                       //14-05-13|0x06b3
}                                                                                         //09-03-10|0x06b4
//                                                                                        //05-24-97|0x06b4
//***************************************************************************             //10-01-03|0x06b7
//***************************************************************************             //10-01-03|0x06b8
//******                                                               ******             //10-01-03|0x06b9
//******                        mailbox_complete                       ******             //10-01-03|0x06ba
//******                                                               ******             //10-01-03|0x06bb
//***************************************************************************             //10-01-03|0x06bc
//***************************************************************************             //10-01-03|0x06bd
//*******************************************************************************         //10-29-97|0x06c7
//*******************************************************************************         //10-29-97|0x06c7
// mailbox_complete                                                                       //10-01-03|0x06c7
//*******************************************************************************         //10-29-97|0x06c7
//*******************************************************************************         //10-29-97|0x06c7
UINT SOURCEPROJ::mailbox_complete(void) {                                                 //10-01-03|0x06c7
//*******************************************************************************         //10-29-97|0x06c7
//***************************************************************************             //10-01-03|0x06ca
//***************************************************************************             //10-01-03|0x06cb
  UINT i;                                                                            //10-01-03|0x06cc
//***************************************************************************             //10-01-03|0x06cd
//***************************************************************************             //10-01-03|0x06ce
    if(FilesMailBoxNoFiles  >  16)                         ReturnSystemError;             //10-01-03|0x06cf
//***************************************************************************             //10-01-19|0x06d0
//***                                                                     ***             //10-01-19|0x06d1
//***  Note the end of the source generation project file                 ***             //10-01-19|0x06d2
//***                                                                     ***             //10-01-19|0x06d3
//***************************************************************************             //10-01-19|0x06d4
    switch(MailDictFinishProject())                              _SwitchGroup             //10-01-19|0x06d5
//***************************************************************************             //10-01-03|0x06d6
//***                                                                     ***             //10-01-03|0x06d7
//***  Process the mailboxes                                              ***             //10-01-03|0x06d8
//***                                                                     ***             //10-01-03|0x06d9
//***************************************************************************             //10-01-03|0x06da
    for(i=0;  i<FilesMailBoxNoFiles; ++i)                                                 //10-01-03|0x06db
      {                                                                                   //10-01-03|0x06dc
        switch(FilesMailBoxStatus(i))                                                     //10-01-03|0x06dd
          {                                                                               //10-01-03|0x06de
//***************************************************************************             //10-01-03|0x06df
//*****                                                                ******             //10-01-03|0x06e0
//*****   Postoffices and Mailboxes that have not been opened          ******             //10-01-03|0x06e1
//*****                                                                ******             //10-01-03|0x06e2
//***************************************************************************             //10-01-03|0x06e3
            case OPEN_MAILBOX:                break_test(mailbox_complete_1);             //10-04-27|0x06e4
//---------------------------------------------------------------------------             //10-04-27|0x06e5
            case CREATE_POSTOFFICE:           break_test(mailbox_complete_1);             //10-04-27|0x06e6
//---------------------------------------------------------------------------             //10-04-27|0x06e7
            case POSTOFFICE_FILE:             break_test(mailbox_complete_1);             //10-01-06|0x06e8
//---------------------------------------------------------------------------             //10-01-06|0x06e9
            case MAILBOX_FILE:                break_test(mailbox_complete_2);             //10-01-06|0x06ea
//***************************************************************************             //10-01-03|0x06eb
//*****                                                                ******             //10-01-03|0x06ec
//*****   Postoffices and Mailboxes that have been opened              ******             //10-01-03|0x06ed
//*****                                                                ******             //10-01-03|0x06ee
//***************************************************************************             //10-01-03|0x06ef
            case OPENED_POSTOFFICE:                                                       //10-01-03|0x06f0
              switch(MailDictPublish(i))                         _SwitchGroup             //10-01-03|0x06f1
              break_test(mailbox_complete_3);                                             //10-01-03|0x06f2
//---------------------------------------------------------------------------             //10-01-03|0x06f3
            case OPENED_MAILBOX:                                                          //10-01-06|0x06f4
              switch(MailDictComplete(i))                        _SwitchGroup             //10-01-06|0x06f5
              break_test(mailbox_complete_4);                                             //10-01-06|0x06f6
//***************************************************************************             //10-01-06|0x06f7
//*****                                                                ******             //10-01-06|0x06f8
//*****   Postoffices and Mailboxes that have not been properly closed ******             //10-01-06|0x06f9
//*****                                                                ******             //10-01-06|0x06fa
//***************************************************************************             //10-01-06|0x06fb
            case MAILBOX_OPENED:                                                          //10-01-06|0x06fc
              switch(MailDictComplete(i))                        _SwitchGroup             //10-01-06|0x06fd
              break_test(mailbox_complete_5);                                             //10-01-06|0x06fe
//---------------------------------------------------------------------------             //10-01-06|0x06ff
            case POSTOFFICE_OPENED:                                                       //10-01-06|0x0700
              switch(MailDictDelete(i))                          _SwitchGroup             //10-01-06|0x0701
              break_test(mailbox_finish_6);                                               //10-01-06|0x0702
//***************************************************************************             //10-01-06|0x0703
            default:                                       ReturnSystemError;             //10-01-06|0x0704
            }                                                                             //10-01-06|0x0705
        }                                                                                 //10-01-03|0x0706
//***************************************************************************             //10-01-03|0x0707
    return(Success);                                                                      //09-03-10|0x0708
}                                                                                         //09-03-10|0x0709
//                                                                                        //05-24-97|0x0709
//***************************************************************************             //06-07-14|0x070c
//***************************************************************************             //06-07-14|0x070d
//******                                                               ******             //06-07-14|0x070e
//******                       TEST WRAPPERS                           ******             //06-07-14|0x070f
//******                                                               ******             //06-07-14|0x0710
//***************************************************************************             //06-07-14|0x0711
//***************************************************************************             //06-07-14|0x0712
//*******************************************************************************         //10-29-97|0x0713
//*******************************************************************************         //10-29-97|0x0713
// srcproj_test_reset                                                                     //06-07-14|0x0713
//*******************************************************************************         //10-29-97|0x0713
//*******************************************************************************         //10-29-97|0x0713
UINT SOURCEPROJ::srcproj_test_reset(void) {                                               //06-07-14|0x0713
//*******************************************************************************         //10-29-97|0x0713
//************************************************************************                //06-07-14|0x0713
    switch(BasicTestReset())                                                              //06-07-14|0x0713
      {                                                                                   //06-07-14|0x0713
        case Success:                                     return(Success);                //06-07-14|0x0713
        default:                                        ReturnSystemError;                //06-07-14|0x0713
        }                                                                                 //06-07-14|0x0713
}                                                                                         //06-07-14|0x0713
//                                                                                        //05-24-97|0x0713
//***************************************************************************             //06-07-14|0x0714
//*******************************************************************************         //10-29-97|0x0715
//*******************************************************************************         //10-29-97|0x0715
// srcproj_test_read                                                                      //06-07-14|0x0715
//*******************************************************************************         //10-29-97|0x0715
//*******************************************************************************         //10-29-97|0x0715
UINT SOURCEPROJ::srcproj_test_read(void) {                                                //06-07-14|0x0715
//*******************************************************************************         //10-29-97|0x0715
//************************************************************************                //06-07-14|0x0715
    switch(BasicTestRead(&test_samples[0], test_samples[0]))                              //06-07-14|0x0715
      {                                                                                   //06-07-14|0x0715
        case Success:                                     return(Success);                //06-07-14|0x0715
        default:                                        ReturnSystemError;                //06-07-14|0x0715
        }                                                                                 //06-07-14|0x0715
}                                                                                         //06-07-14|0x0715
//                                                                                        //05-24-97|0x0715
//***************************************************************************             //06-07-14|0x0716
//*******************************************************************************         //10-29-97|0x0717
//*******************************************************************************         //10-29-97|0x0717
// srcproj_test_write                                                                     //06-07-14|0x0717
//*******************************************************************************         //10-29-97|0x0717
//*******************************************************************************         //10-29-97|0x0717
UINT SOURCEPROJ::srcproj_test_write(void) {                                               //06-07-14|0x0717
//*******************************************************************************         //10-29-97|0x0717
//************************************************************************                //06-07-14|0x0717
    switch(BasicTestWrite(&test_samples[0]))                                              //06-07-14|0x0717
      {                                                                                   //06-07-14|0x0717
        case Success:                                     return(Success);                //06-07-14|0x0717
        default:                                        ReturnSystemError;                //06-07-14|0x0717
        }                                                                                 //06-07-14|0x0717
}                                                                                         //06-07-14|0x0717
//                                                                                        //05-24-97|0x0717
//***************************************************************************             //06-07-14|0x0718
//*******************************************************************************         //10-29-97|0x0719
//*******************************************************************************         //10-29-97|0x0719
// srcproj_test_report                                                                    //06-07-14|0x0719
//*******************************************************************************         //10-29-97|0x0719
//*******************************************************************************         //10-29-97|0x0719
UINT SOURCEPROJ::srcproj_test_report(void) {                                              //06-07-14|0x0719
//*******************************************************************************         //10-29-97|0x0719
//************************************************************************                //06-07-14|0x0719
    switch(BasicTestReport(&test_samples[0], "SRCPROJ"))                                  //06-07-14|0x0719
      {                                                                                   //06-07-14|0x0719
        case Success:                                     return(Success);                //06-07-14|0x0719
        default:                                        ReturnSystemError;                //06-07-14|0x0719
        }                                                                                 //06-07-14|0x0719
}                                                                                         //06-07-14|0x0719
//                                                                                        //05-24-97|0x0719
//***************************************************************************             //06-07-12|0x071a
//***************************************************************************             //06-07-12|0x071b
//******                                                               ******             //06-07-12|0x071c
//******                        constructor                            ******             //06-07-12|0x071d
//******                                                               ******             //06-07-12|0x071e
//***************************************************************************             //06-07-12|0x071f
//***************************************************************************             //06-07-12|0x0720
//*******************************************************************************         //10-29-97|0x0721
//*******************************************************************************         //10-29-97|0x0721
// CONSTRUCTOR                                                                            //06-07-12|0x0721
//*******************************************************************************         //10-29-97|0x0721
//*******************************************************************************         //10-29-97|0x0721
SOURCEPROJ::SOURCEPROJ() {                                                                //06-07-12|0x0721
//***************************************************************************             //06-07-12|0x0722
//***************************************************************************             //06-07-12|0x0723
    source_project_addr = 0;                                                              //06-07-12|0x0724
    { ULONG i;                                                                            //06-07-12|0x0726
      test_samples[NoTestSamples] = TestIndex;                                            //06-07-12|0x0726
      i = 1;                                                                              //06-07-12|0x0726
      while(i<TestIndex)                                                                  //06-07-12|0x0726
        {                                                                                 //06-07-12|0x0726
          test_samples[i] = 0;                                                            //06-07-12|0x0726
          ++i;                                                                            //06-07-12|0x0726
          }                                                                               //06-07-12|0x0726
      }                                                                                   //06-07-12|0x0726
}                                                                                         //06-07-12|0x0727
//                                                                                        //05-24-97|0x0727
//*******************************************************************************         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
//****                       END OF FILE                                     ****         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
