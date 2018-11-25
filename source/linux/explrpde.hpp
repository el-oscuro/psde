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
#ifndef explrpde_hpp                                                                      //06-07-12|0x000b
#define explrpde_hpp                                                                      //06-07-12|0x000b
//***************************************************************************             //06-07-12|0x0011
//***************************************************************************             //06-07-12|0x0012
//******                                                               ******             //06-07-12|0x0013
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0014
//******                                                               ******             //06-07-12|0x0015
//***************************************************************************             //06-07-12|0x0016
//***************************************************************************             //06-07-12|0x0017
//***************************************************************************             //06-07-12|0x001a
//***************************************************************************             //06-07-12|0x001b
//******                                                               ******             //06-07-12|0x001c
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x001d
//******                                                               ******             //06-07-12|0x001e
//***************************************************************************             //06-07-12|0x001f
//***************************************************************************             //06-07-12|0x0020
#define UserError 0x0000                                                                  //06-07-12|0x0021
#define BuildError 0x7fff                                                                 //06-07-12|0x0021
#define Display 0x7ffe                                                                    //06-07-12|0x0021
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x0021
#define Success 0xffff                                                                    //06-07-12|0x0021
#define SystemError 0x8000                                                                //06-07-12|0x0021
#define Continue 0x0001                                                                   //06-07-12|0x0021
#define FileDone 0x0002                                                                   //06-07-12|0x0021
#define LineDone 0x0003                                                                   //06-07-12|0x0021
#define Yes 0x0004                                                                        //06-07-12|0x0021
#define No 0x0005                                                                         //06-07-12|0x0021
#define RepeatChar '\x6'                                                                  //06-07-12|0x0021
#define Great 0x0007                                                                      //06-07-12|0x0021
#define Equal 0x0008                                                                      //06-07-12|0x0021
#define Less 0x0009                                                                       //06-07-12|0x0021
#define Zero 0x000a                                                                       //06-07-12|0x0021
#define Minus 0x000b                                                                      //06-07-12|0x0021
//***************************************************************************             //06-07-12|0x0022
#define SystemMsg PcgSystemError("explrpde", __LINE__);                                   //06-07-12|0x0023
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x0023
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x0023
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0024
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0024
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0024
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0024
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0025
#define _SwitchOk case Success: break                                                     //06-07-12|0x0025
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0025
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0025
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0025
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0025
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0025
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0025
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0025
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0025
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0025
//***************************************************************************             //06-07-29|0x0026
//***************************************************************************             //06-07-29|0x0027
//******                                                               ******             //06-07-29|0x0028
//******               FUNCTIONAL DEFINE STATEMENTS                    ******             //06-07-29|0x0029
//******                                                               ******             //06-07-29|0x002a
//***************************************************************************             //06-07-29|0x002b
//***************************************************************************             //06-07-29|0x002c
#define CmdLineArgs GetArguments(no_args, &args[0])                                       //06-07-29|0x002d
#define GetKeyBoard1 fgets(line, 80, stdin)                                               //06-07-29|0x002d
#define GetKeyBoard ((GetKeyBoard1 != 0) ? KeyBoard : 1)                                  //06-07-29|0x002d
//*******************************************************************************         //05-24-97|0x00ba
//*******************************************************************************         //05-24-97|0x00ba
//****                       END OF FILE                                     ****         //05-24-97|0x00ba
//*******************************************************************************         //05-24-97|0x00ba
//*******************************************************************************         //05-24-97|0x00ba
#endif                                                                                    //05-24-97|0x00ba
