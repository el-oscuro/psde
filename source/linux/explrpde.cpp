//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
// PROGRAMMABLE DEVELOPMENT ENVIRONMENT                                                   //06-07-12|0x0008
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
#include "explrpde.h"                                                                     //06-07-12|0x000b
#include "explrpde.hxx"                                                                   //06-07-12|0x000b
#include "explrpde.hpp"                                                                   //06-07-12|0x000b
#include "mainprj.h"                                                                      //06-07-12|0x000e
#include "precdiag.h"                                                                     //06-07-12|0x000f
#include "guicomm.h"                                                                      //06-09-04|0x0010
#define Allocate(k) (k##_FAR) calloc(1,sizeof(k))                                         //06-07-12|0x0018
#define Free(k) free(k)                                                                   //06-07-12|0x0018
#define MemSet(i,j,k) memset(i,j,k)                                                       //06-07-12|0x0018
#define MemCCpy(i,j,k,l) Mem_C_Copy((UCHAR_FAR) i, (UCHAR_FAR) j,k,l)                     //06-07-12|0x0018
#define MemCpy(i,j,k) memcpy(i,j,k)                                                       //06-07-12|0x0018
#define LineEnd 0x0d                                                                      //06-07-12|0x0018
#define StrLen(i) strlen(i)                                                               //06-07-12|0x0019
#define StrCat(i,j) strcat(i,j)                                                           //06-07-12|0x0019
#define StrCpy(i,j) strcpy(i,j)                                                           //06-07-12|0x0019
#define StrCmp(i,j) Str_Comp((SCHAR_FAR)i,j,256)                                          //06-07-12|0x0019
#define StrRChr(i,j) strrchr(i,j)                                                         //06-07-12|0x0019
#define StrChr(i,j) strchr(i,j)                                                           //06-07-12|0x0019
#define StrToByteInt(i,j) GetInteger(i,&j,0xff)                                           //06-07-12|0x0019
#define StrToInt(i,j) GetInteger(i,&j,0xffff)                                             //06-07-12|0x0019
#define StrToLongInt(i,j) GetInteger(i,&j,0xffffffffL)                                    //06-07-12|0x0019
#define StrToByteHex(i,j) GetHex(i,&j,1)                                                  //06-07-12|0x0019
#define StrToHex(i,j) GetHex(i,&j,2)                                                      //06-07-12|0x0019
#define StrToLongHex(i,j) GetHex(i,&j,4)                                                  //06-07-12|0x0019
#define FindName(i) strrchr(i, '/')                                                       //06-07-12|0x0019
//***************************************************************************             //06-07-12|0x002e
//***************************************************************************             //06-07-12|0x002f
//******                                                               ******             //06-07-12|0x0030
//******                           main                                ******             //06-07-12|0x0031
//******                                                               ******             //06-07-12|0x0032
//***************************************************************************             //06-07-12|0x0033
//***************************************************************************             //06-07-12|0x0034
int  main( int         no_args,                                                           //06-07-29|0x0036
           char *      args[])                                                            //06-07-29|0x0036
{                                                                                         //06-07-29|0x0036
//***************************************************************************             //06-07-12|0x0038
//***************************************************************************             //06-07-12|0x0039
  UINT  status;                                                                           //06-09-04|0x003a
  SCHAR line[80];                                                                         //06-09-04|0x003b
//***************************************************************************             //06-07-29|0x003c
//******                                                               ******             //06-07-29|0x003d
//****** State Machine Beginning                                       ******             //06-07-29|0x003e
//******                                                               ******             //06-07-29|0x003f
//***************************************************************************             //06-07-29|0x0040
  {                                                                                       //06-07-29|0x0041
    UINT run_flag;                                                                        //06-07-29|0x0041
    UINT state;                                                                           //06-07-29|0x0041
//---------------------------------------------------------------------------             //06-07-29|0x0042
    state = 144; // SETUP_SELF_TEST                                                       //06-07-29|0x0043
    run_flag = 1;                                                                         //06-07-29|0x0043
    while(run_flag != 0)                                                                  //06-07-29|0x0043
    {                                                                                     //06-07-29|0x0043
      switch(state)                                                                       //06-07-29|0x0043
      {                                                                                   //06-07-29|0x0043
//***************************************************************************             //06-07-29|0x0044
//******                                                               ******             //06-07-29|0x0045
//****** Program Initialization Initiallization                        ******             //06-07-29|0x0046
//******                                                               ******             //06-07-29|0x0047
//***************************************************************************             //06-07-29|0x0048
        case 144: // SETUP_SELF_TEST                                                      //06-07-29|0x0049
          DiagnosticFileNames(args[0]);                                                   //06-07-29|0x0049
          state = 2575; // ALLOCATE_MEMORY                                                //06-07-29|0x0049
          break;                                                                          //06-07-29|0x0049
//---------------------------------------------------------------------------             //06-07-29|0x004a
        case 2575: // ALLOCATE_MEMORY                                                     //check  |0x004b
          switch(MainAllocate())                                                          //check  |0x004b
          {                                                                               //check  |0x004b
            case Success:                                                                 //check  |0x004b
              run_flag = 1;                                                               //check  |0x004b
              state = 43902; // GET_CMND_LINE                                             //check  |0x004b
              break;                                                                      //check  |0x004b
            default:                                                                      //check  |0x004b
              status = 3;                                                                 //check  |0x004b
              run_flag = 0;                                                               //check  |0x004b
              SystemMsg;                                                                  //check  |0x004b
              break;                                                                      //check  |0x004b
          }                                                                               //check  |0x004b
          break;                                                                          //check  |0x004b
//***************************************************************************             //06-07-29|0x004c
//******                                                               ******             //06-07-29|0x004d
//****** Process Project File                                          ******             //06-07-29|0x004e
//******                                                               ******             //06-07-29|0x004f
//***************************************************************************             //06-07-29|0x0050
        case 43902: // GET_CMND_LINE                                                     //check   |0x0051
          switch(CmdLineArgs)                                                            //check   |0x0051
          {                                                                              //check   |0x0051
            case Success:                                                                //check   |0x0051
              run_flag = 1;                                                              //check   |0x0051
              state = 25565; // MAIN                                                     //check   |0x0051
              break;                                                                     //check   |0x0051
            case UserError:                                                              //check   |0x0051
              run_flag = 1;                                                              //check   |0x0051
              state = 41516; // FREE_USER                                                //check   |0x0051
              break;                                                                     //check   |0x0051
            default:                                                                     //check   |0x0051
              status = 3;                                                                //check   |0x0051
              run_flag = 0;                                                              //check   |0x0051
              SystemMsg;                                                                 //check   |0x0051
              break;                                                                     //check   |0x0051
          }                                                                              //check   |0x0051
          break;                                                                         //check   |0x0051
//***************************************************************************             //06-07-29|0x0052
        case 25565: // MAIN                                                               //check   |0x0053
          switch(MainProcess())                                                           //check   |0x0053
          {                                                                               //check   |0x0053
            case KeyBoard:                                                                //check   |0x0053
              run_flag = 1;                                                               //check   |0x0053
              state = 50539; // GET_KEYBRD                                                //check   |0x0053
              break;                                                                      //check   |0x0053
            case Display:                                                                 //check   |0x0053
              run_flag = 1;                                                               //check   |0x0053
              state = 7322; // GET_DSPLY                                                  //check   |0x0053
              break;                                                                      //check   |0x0053
            case UserError:                                                               //check   |0x0053
              run_flag = 1;                                                               //check   |0x0053
              state = 41516; // FREE_USER                                                 //check   |0x0053
              break;                                                                      //check   |0x0053
            case BuildError:                                                              //check   |0x0053
              run_flag = 1;                                                               //check   |0x0053
              state = 59065; // FREE_BUILD                                                //check   |0x0053
              break;                                                                      //check   |0x0053
            case Success:                                                                 //check   |0x0053
              run_flag = 1;                                                               //check   |0x0053
              state = 21192; // FREE_OK                                                   //check   |0x0053
              break;                                                                      //check   |0x0053
            default:                                                                      //check   |0x0053
              status = 3;                                                                 //check   |0x0053
              run_flag = 0;                                                               //check   |0x0053
              SystemMsg;                                                                  //check   |0x0053
              break;                                                                      //check   |0x0053
          }                                                                               //check   |0x0053
          break;                                                                          //check   |0x0053
//***************************************************************************             //06-07-29|0x0054
        case 7322: // GET_DSPLY                                                           //06-08-29|0x0055
          switch(GuiReadLine(line,80))                                                    //06-08-29|0x0055
          {                                                                               //06-08-29|0x0055
            case Yes:                                                                     //06-08-29|0x0055
              run_flag = 1;                                                               //06-08-29|0x0055
              state = 25565; // MAIN                                                      //06-08-29|0x0055
              break;                                                                      //06-08-29|0x0055
            case No:                                                                      //06-08-29|0x0055
              run_flag = 1;                                                               //06-08-29|0x0055
              state = 32711; // DISPLAY                                                   //06-08-29|0x0055
              break;                                                                      //06-08-29|0x0055
            default:                                                                      //06-08-29|0x0055
              status = 3;                                                                 //06-08-29|0x0055
              run_flag = 0;                                                               //06-08-29|0x0055
              SystemMsg;                                                                  //06-08-29|0x0055
              break;                                                                      //06-08-29|0x0055
          }                                                                               //06-08-29|0x0055
          break;                                                                          //06-08-29|0x0055
//---------------------------------------------------------------------------             //06-08-29|0x0056
        case 32711: // DISPLAY                                                            //06-08-29|0x0057
          printf("%s", line);                                                             //06-08-29|0x0057
          state = 7322; // GET_DSPLY                                                      //06-08-29|0x0057
          break;                                                                          //06-08-29|0x0057
//***************************************************************************             //06-07-29|0x0058
        case 50539: // GET_KEYBRD                                                         //06-10-06|0x0059
          switch(GetKeyBoard)                                                             //06-10-06|0x0059
          {                                                                               //06-10-06|0x0059
            case KeyBoard:                                                                //06-10-06|0x0059
              run_flag = 1;                                                               //06-10-06|0x0059
              state = 31926; // SEND_KEYBRD                                               //06-10-06|0x0059
              break;                                                                      //06-10-06|0x0059
            default:                                                                      //06-10-06|0x0059
              status = 3;                                                                 //06-10-06|0x0059
              run_flag = 0;                                                               //06-10-06|0x0059
              SystemMsg;                                                                  //06-10-06|0x0059
              break;                                                                      //06-10-06|0x0059
          }                                                                               //06-10-06|0x0059
          break;                                                                          //06-10-06|0x0059
//---------------------------------------------------------------------------             //06-10-06|0x005a
        case 31926: // SEND_KEYBRD                                                        //06-10-06|0x005b
          switch(GuiWriteKeybrd(line))                                                    //06-10-06|0x005b
          {                                                                               //06-10-06|0x005b
            case Success:                                                                 //06-10-06|0x005b
              run_flag = 1;                                                               //06-10-06|0x005b
              state = 25565; // MAIN                                                      //06-10-06|0x005b
              break;                                                                      //06-10-06|0x005b
            default:                                                                      //06-10-06|0x005b
              status = 3;                                                                 //06-10-06|0x005b
              run_flag = 0;                                                               //06-10-06|0x005b
              SystemMsg;                                                                  //06-10-06|0x005b
              break;                                                                      //06-10-06|0x005b
          }                                                                               //06-10-06|0x005b
          break;                                                                          //06-10-06|0x005b
//***************************************************************************             //06-07-29|0x005c
//******                                                               ******             //06-07-29|0x005d
//****** Tear Down Program                                             ******             //06-07-29|0x005e
//******                                                               ******             //06-07-29|0x005f
//***************************************************************************             //06-07-29|0x0060
        case 21192: // FREE_OK                                                            //06-10-06|0x006b
          switch(MainFree())                                                              //06-10-06|0x006b
          {                                                                               //06-10-06|0x006b
            case Success:                                                                 //06-10-06|0x006b
              run_flag = 1;                                                               //06-10-06|0x006b
              state = 18581; // SUCCESS_MESSAGE                                           //06-10-06|0x006b
              break;                                                                      //06-10-06|0x006b
            default:                                                                      //06-10-06|0x006b
              status = 3;                                                                 //06-10-06|0x006b
              run_flag = 0;                                                               //06-10-06|0x006b
              SystemMsg;                                                                  //06-10-06|0x006b
              break;                                                                      //06-10-06|0x006b
          }                                                                               //06-10-06|0x006b
          break;                                                                          //06-10-06|0x006b
//---------------------------------------------------------------------------             //06-09-04|0x006c
        case 59065: // FREE_BUILD                                                         //06-10-06|0x006d
          switch(MainFree())                                                              //06-10-06|0x006d
          {                                                                               //06-10-06|0x006d
            case Success:                                                                 //06-10-06|0x006d
              run_flag = 1;                                                               //06-10-06|0x006d
              state = 53860; // MESSAGE_BUILD                                             //06-10-06|0x006d
              break;                                                                      //06-10-06|0x006d
            default:                                                                      //06-10-06|0x006d
              status = 3;                                                                 //06-10-06|0x006d
              run_flag = 0;                                                               //06-10-06|0x006d
              SystemMsg;                                                                  //06-10-06|0x006d
              break;                                                                      //06-10-06|0x006d
          }                                                                               //06-10-06|0x006d
          break;                                                                          //06-10-06|0x006d
//---------------------------------------------------------------------------             //06-07-29|0x006e
        case 41516: // FREE_USER                                                          //06-07-29|0x006f
          switch(MainFree())                                                              //06-07-29|0x006f
          {                                                                               //06-07-29|0x006f
            case Success:                                                                 //06-07-29|0x006f
              run_flag = 1;                                                               //06-07-29|0x006f
              state = 63779; // MESSAGE_USER                                              //06-07-29|0x006f
              break;                                                                      //06-07-29|0x006f
            default:                                                                      //06-07-29|0x006f
              status = 3;                                                                 //06-07-29|0x006f
              run_flag = 0;                                                               //06-07-29|0x006f
              SystemMsg;                                                                  //06-07-29|0x006f
              break;                                                                      //06-07-29|0x006f
          }                                                                               //06-07-29|0x006f
          break;                                                                          //06-07-29|0x006f
//***************************************************************************             //06-07-29|0x0070
//******                                                               ******             //06-07-29|0x0071
//****** Completion message                                            ******             //06-07-29|0x0072
//******                                                               ******             //06-07-29|0x0073
//***************************************************************************             //06-07-29|0x0074
        case 18581: // SUCCESS_MESSAGE                                                    //06-10-09|0x0075
          switch(PcgSuccess())                                                            //06-10-09|0x0075
          {                                                                               //06-10-09|0x0075
            case Success:                                                                 //06-10-09|0x0075
              run_flag = 1;                                                               //06-10-09|0x0075
              state = 35794; // MESSAGE_OK                                                //06-10-09|0x0075
              break;                                                                      //06-10-09|0x0075
            default:                                                                      //06-10-09|0x0075
              status = 3;                                                                 //06-10-09|0x0075
              run_flag = 0;                                                               //06-10-09|0x0075
              SystemMsg;                                                                  //06-10-09|0x0075
              break;                                                                      //06-10-09|0x0075
          }                                                                               //06-10-09|0x0075
          break;                                                                          //06-10-09|0x0075
//***************************************************************************             //06-10-09|0x0076
        case 35794: // MESSAGE_OK                                                         //06-09-04|0x0077
          switch(PcgStop())                                                               //06-09-04|0x0077
          {                                                                               //06-09-04|0x0077
            case Success:                                                                 //06-09-04|0x0077
              run_flag = 1;                                                               //06-09-04|0x0077
              state = 18801; // OK_DISPLAY                                                //06-09-04|0x0077
              break;                                                                      //06-09-04|0x0077
            default:                                                                      //06-09-04|0x0077
              status = 3;                                                                 //06-09-04|0x0077
              run_flag = 0;                                                               //06-09-04|0x0077
              SystemMsg;                                                                  //06-09-04|0x0077
              break;                                                                      //06-09-04|0x0077
          }                                                                               //06-09-04|0x0077
          break;                                                                          //06-09-04|0x0077
//---------------------------------------------------------------------------             //06-09-04|0x0078
        case 53860: // MESSAGE_BUILD                                                      //06-10-06|0x0079
          switch(PcgStop())                                                               //06-10-06|0x0079
          {                                                                               //06-10-06|0x0079
            case Success:                                                                 //06-10-06|0x0079
              run_flag = 1;                                                               //06-10-06|0x0079
              state = 57600; // BUILD_DISPLAY                                             //06-10-06|0x0079
              break;                                                                      //06-10-06|0x0079
            default:                                                                      //06-10-06|0x0079
              status = 3;                                                                 //06-10-06|0x0079
              run_flag = 0;                                                               //06-10-06|0x0079
              SystemMsg;                                                                  //06-10-06|0x0079
              break;                                                                      //06-10-06|0x0079
          }                                                                               //06-10-06|0x0079
          break;                                                                          //06-10-06|0x0079
//---------------------------------------------------------------------------             //06-10-06|0x007a
        case 63779: // MESSAGE_USER                                                       //06-08-23|0x007b
          switch(PcgStop())                                                               //06-08-23|0x007b
          {                                                                               //06-08-23|0x007b
            case Success:                                                                 //06-08-23|0x007b
              run_flag = 1;                                                               //06-08-23|0x007b
              state = 61823; // USER_DISPLAY                                              //06-08-23|0x007b
              break;                                                                      //06-08-23|0x007b
            default:                                                                      //06-08-23|0x007b
              status = 3;                                                                 //06-08-23|0x007b
              run_flag = 0;                                                               //06-08-23|0x007b
              SystemMsg;                                                                  //06-08-23|0x007b
              break;                                                                      //06-08-23|0x007b
          }                                                                               //06-08-23|0x007b
          break;                                                                          //06-08-23|0x007b
//***************************************************************************             //06-08-23|0x007c
//******                                                               ******             //06-08-23|0x007d
//****** Display Final Messages                                        ******             //06-08-23|0x007e
//******                                                               ******             //06-08-23|0x007f
//***************************************************************************             //06-08-23|0x0080
        case 18801: // OK_DISPLAY                                                         //12-05-21|0x0081
          switch(GuiReadLine(line,80))                                                    //12-05-21|0x0081
          {                                                                               //12-05-21|0x0081
            case Yes:                                                                     //12-05-21|0x0081
              run_flag = 1;                                                               //12-05-21|0x0081
              state = 2542; // CLS_RPRT_OK                                                //12-05-21|0x0081
              break;                                                                      //12-05-21|0x0081
            case No:                                                                      //12-05-21|0x0081
              run_flag = 1;                                                               //12-05-21|0x0081
              state = 43341; // DISPLAY_OK                                                //12-05-21|0x0081
              break;                                                                      //12-05-21|0x0081
            default:                                                                      //12-05-21|0x0081
              status = 3;                                                                 //12-05-21|0x0081
              run_flag = 0;                                                               //12-05-21|0x0081
              SystemMsg;                                                                  //12-05-21|0x0081
              break;                                                                      //12-05-21|0x0081
          }                                                                               //12-05-21|0x0081
          break;                                                                          //12-05-21|0x0081
//---------------------------------------------------------------------------             //06-09-04|0x0082
        case 43341: // DISPLAY_OK                                                         //06-09-04|0x0083
          printf("%s", line);                                                             //06-09-04|0x0083
          state = 18801; // OK_DISPLAY                                                    //06-09-04|0x0083
          break;                                                                          //06-09-04|0x0083
//***************************************************************************             //06-09-04|0x0084
        case 57600: // BUILD_DISPLAY                                                      //12-05-21|0x0085
          switch(GuiReadLine(line,80))                                                    //12-05-21|0x0085
          {                                                                               //12-05-21|0x0085
            case Yes:                                                                     //12-05-21|0x0085
              run_flag = 1;                                                               //12-05-21|0x0085
              state = 16028; // CLS_RPRT_BUILD                                            //12-05-21|0x0085
              break;                                                                      //12-05-21|0x0085
            case No:                                                                      //12-05-21|0x0085
              run_flag = 1;                                                               //12-05-21|0x0085
              state = 10459; // DISPLAY_BUILD                                             //12-05-21|0x0085
              break;                                                                      //12-05-21|0x0085
            default:                                                                      //12-05-21|0x0085
              status = 3;                                                                 //12-05-21|0x0085
              run_flag = 0;                                                               //12-05-21|0x0085
              SystemMsg;                                                                  //12-05-21|0x0085
              break;                                                                      //12-05-21|0x0085
          }                                                                               //12-05-21|0x0085
          break;                                                                          //12-05-21|0x0085
//---------------------------------------------------------------------------             //06-10-06|0x0086
        case 10459: // DISPLAY_BUILD                                                      //06-10-06|0x0087
          printf("%s", line);                                                             //06-10-06|0x0087
          state = 57600; // BUILD_DISPLAY                                                 //06-10-06|0x0087
          break;                                                                          //06-10-06|0x0087
//***************************************************************************             //06-08-23|0x0088
        case 61823: // USER_DISPLAY                                                       //12-05-21|0x0089
          switch(GuiReadLine(line,80))                                                    //12-05-21|0x0089
          {                                                                               //12-05-21|0x0089
            case Yes:                                                                     //12-05-21|0x0089
              run_flag = 1;                                                               //12-05-21|0x0089
              state = 46858; // CLS_RPRT_USER                                             //12-05-21|0x0089
              break;                                                                      //12-05-21|0x0089
            case No:                                                                      //12-05-21|0x0089
              run_flag = 1;                                                               //12-05-21|0x0089
              state = 10281; // DISPLAY_USER                                              //12-05-21|0x0089
              break;                                                                      //12-05-21|0x0089
            default:                                                                      //12-05-21|0x0089
              status = 3;                                                                 //12-05-21|0x0089
              run_flag = 0;                                                               //12-05-21|0x0089
              SystemMsg;                                                                  //12-05-21|0x0089
              break;                                                                      //12-05-21|0x0089
          }                                                                               //12-05-21|0x0089
          break;                                                                          //12-05-21|0x0089
//---------------------------------------------------------------------------             //06-08-23|0x008a
        case 10281: // DISPLAY_USER                                                       //06-08-23|0x008b
          printf("%s", line);                                                             //06-08-23|0x008b
          state = 61823; // USER_DISPLAY                                                  //06-08-23|0x008b
          break;                                                                          //06-08-23|0x008b
//***************************************************************************             //12-05-21|0x008c
//******                                                               ******             //12-05-21|0x008d
//****** Close  Console Report File                                    ******             //12-05-21|0x008e
//******                                                               ******             //12-05-21|0x008f
//***************************************************************************             //12-05-21|0x0090
        case 2542: // CLS_RPRT_OK                                                         //12-05-21|0x0091
          switch(GuiCloseReport())                                                        //12-05-21|0x0091
          {                                                                               //12-05-21|0x0091
            case Success:                                                                 //12-05-21|0x0091
              run_flag = 1;                                                               //12-05-21|0x0091
              state = 43832; // WRITE_TEST_OK                                             //12-05-21|0x0091
              break;                                                                      //12-05-21|0x0091
            default:                                                                      //12-05-21|0x0091
              status = 3;                                                                 //12-05-21|0x0091
              run_flag = 0;                                                               //12-05-21|0x0091
              SystemMsg;                                                                  //12-05-21|0x0091
              break;                                                                      //12-05-21|0x0091
          }                                                                               //12-05-21|0x0091
          break;                                                                          //12-05-21|0x0091
//---------------------------------------------------------------------------             //12-05-21|0x0092
        case 16028: // CLS_RPRT_BUILD                                                     //12-05-21|0x0093
          switch(GuiCloseReport())                                                        //12-05-21|0x0093
          {                                                                               //12-05-21|0x0093
            case Success:                                                                 //12-05-21|0x0093
              run_flag = 1;                                                               //12-05-21|0x0093
              state = 24375; // WRITE_TEST_BUILD                                          //12-05-21|0x0093
              break;                                                                      //12-05-21|0x0093
            default:                                                                      //12-05-21|0x0093
              status = 3;                                                                 //12-05-21|0x0093
              run_flag = 0;                                                               //12-05-21|0x0093
              SystemMsg;                                                                  //12-05-21|0x0093
              break;                                                                      //12-05-21|0x0093
          }                                                                               //12-05-21|0x0093
          break;                                                                          //12-05-21|0x0093
//---------------------------------------------------------------------------             //12-05-21|0x0094
        case 46858: // CLS_RPRT_USER                                                      //12-05-21|0x0095
          switch(GuiCloseReport())                                                        //12-05-21|0x0095
          {                                                                               //12-05-21|0x0095
            case Success:                                                                 //12-05-21|0x0095
              run_flag = 1;                                                               //12-05-21|0x0095
              state = 21286; // WRITE_TEST_USER                                           //12-05-21|0x0095
              break;                                                                      //12-05-21|0x0095
            default:                                                                      //12-05-21|0x0095
              status = 3;                                                                 //12-05-21|0x0095
              run_flag = 0;                                                               //12-05-21|0x0095
              SystemMsg;                                                                  //12-05-21|0x0095
              break;                                                                      //12-05-21|0x0095
          }                                                                               //12-05-21|0x0095
          break;                                                                          //12-05-21|0x0095
//***************************************************************************             //06-07-29|0x0096
//******                                                               ******             //06-07-29|0x0097
//****** Record Test Results                                           ******             //06-07-29|0x0098
//******                                                               ******             //06-07-29|0x0099
//***************************************************************************             //06-07-29|0x009a
        case 43832: // WRITE_TEST_OK                                                      //06-09-04|0x009b
          WriteSelfTest();                                                                //06-09-04|0x009b
          state = 34309; // REPRT_TEST_OK                                                 //06-09-04|0x009b
          break;                                                                          //06-09-04|0x009b
//---------------------------------------------------------------------------             //06-10-06|0x009c
        case 24375: // WRITE_TEST_BUILD                                                   //06-10-06|0x009d
          WriteSelfTest();                                                                //06-10-06|0x009d
          state = 59092; // REPRT_TEST_BUILD                                              //06-10-06|0x009d
          break;                                                                          //06-10-06|0x009d
//---------------------------------------------------------------------------             //06-07-29|0x009e
        case 21286: // WRITE_TEST_USER                                                    //06-07-29|0x009f
          WriteSelfTest();                                                                //06-07-29|0x009f
          state = 21651; // REPRT_TEST_USER                                               //06-07-29|0x009f
          break;                                                                          //06-07-29|0x009f
//***************************************************************************             //06-07-29|0x00a0
        case 34309: // REPRT_TEST_OK                                                      //06-09-04|0x00a1
          ReportSelfTest();                                                               //06-09-04|0x00a1
          state = 40514; // EXIT_OK                                                       //06-09-04|0x00a1
          break;                                                                          //06-09-04|0x00a1
//---------------------------------------------------------------------------             //06-09-04|0x00a2
        case 59092: // REPRT_TEST_BUILD                                                   //06-10-06|0x00a3
          ReportSelfTest();                                                               //06-10-06|0x00a3
          state = 33505; // EXIT_BUILD                                                    //06-10-06|0x00a3
          break;                                                                          //06-10-06|0x00a3
//---------------------------------------------------------------------------             //06-07-29|0x00a4
        case 21651: // REPRT_TEST_USER                                                    //06-07-29|0x00a5
          ReportSelfTest();                                                               //06-07-29|0x00a5
          state = 45424; // EXIT_USER                                                     //06-07-29|0x00a5
          break;                                                                          //06-07-29|0x00a5
//***************************************************************************             //06-07-29|0x00a6
//******                                                               ******             //06-07-29|0x00a7
//****** Exit State Machine                                            ******             //06-07-29|0x00a8
//******                                                               ******             //06-07-29|0x00a9
//***************************************************************************             //06-07-29|0x00aa
        case 40514: // EXIT_OK                                                            //06-09-04|0x00ab
          state = 144; // SETUP_SELF_TEST                                                 //06-09-04|0x00ab
          status = 0;                                                                     //06-09-04|0x00ab
          run_flag = 0;                                                                   //06-09-04|0x00ab
          break;                                                                          //06-09-04|0x00ab
//---------------------------------------------------------------------------             //06-09-04|0x00ac
        case 33505: // EXIT_BUILD                                                         //06-10-06|0x00ad
          state = 144; // SETUP_SELF_TEST                                                 //06-10-06|0x00ad
          status = 1;                                                                     //06-10-06|0x00ad
          run_flag = 0;                                                                   //06-10-06|0x00ad
          break;                                                                          //06-10-06|0x00ad
//---------------------------------------------------------------------------             //06-07-29|0x00ae
        case 45424: // EXIT_USER                                                          //06-07-29|0x00af
          state = 144; // SETUP_SELF_TEST                                                 //06-07-29|0x00af
          status = 2;                                                                     //06-07-29|0x00af
          run_flag = 0;                                                                   //06-07-29|0x00af
          break;                                                                          //06-07-29|0x00af
//***************************************************************************             //06-07-29|0x00b0
        default:                                                                          //06-07-29|0x00b1
          status = 3;                                                                     //06-07-29|0x00b1
          run_flag = 0;                                                                   //06-07-29|0x00b1
          SystemMsg;                                                                      //06-07-29|0x00b1
          break;                                                                          //06-07-29|0x00b1
      }                                                                                   //06-07-29|0x00b1
    }                                                                                     //06-07-29|0x00b1
  }                                                                                       //06-07-29|0x00b1
  return(status);                                                                         //06-07-29|0x00b2
}                                                                                         //06-07-29|0x00b3
//*******************************************************************************         //05-24-97|0x00ba
//*******************************************************************************         //05-24-97|0x00ba
//****                       END OF FILE                                     ****         //05-24-97|0x00ba
//*******************************************************************************         //05-24-97|0x00ba
//*******************************************************************************         //05-24-97|0x00ba
