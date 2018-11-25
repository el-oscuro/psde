//*****************************************************************************           //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//                                                                                        //13-06-15|0x001b
// PRECEDENCE ANALYSIS PRIME NUMBER RESOURCE                                              //13-06-15|0x001b
//                                                                                        //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//  The purpose of this program as well as instructions regarding its use is              //13-06-15|0x001b
//  defined in the associated manual.                                                     //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//  This program is free software; you can redistribute it and/or modify                  //13-06-15|0x001b
//  it under the terms of the GNU General Public License as published by                  //13-06-15|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //13-06-15|0x001b
//  (at your option) any later version.                                                   //13-06-15|0x001b
//                                                                                        //13-06-15|0x001b
//  This program is distributed in the hope that it will be useful,                       //13-06-15|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //13-06-15|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //13-06-15|0x001b
//  GNU General Public License for more details.                                          //13-06-15|0x001b
//                                                                                        //13-06-15|0x001b
//  You should have received a copy of the GNU General Public License                     //13-06-15|0x001b
//  along with this program; if not, write to the Free Software                           //13-06-15|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //13-06-15|0x001b
//  USA                                                                                   //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//  For further information, please contact Robert Adams:                                 //13-06-15|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //13-06-15|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //13-06-15|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
//*****************************************************************************           //13-06-15|0x001b
#ifndef prime_hpp                                                                         //13-06-15|0x001e
#define prime_hpp                                                                         //13-06-15|0x001e
//***************************************************************************             //13-06-15|0x0023
//***************************************************************************             //13-06-15|0x0024
//******                                                               ******             //13-06-15|0x0025
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //13-06-15|0x0026
//******                                                               ******             //13-06-15|0x0027
//***************************************************************************             //13-06-15|0x0028
//***************************************************************************             //13-06-15|0x0029
#define UserError 0x0000                                                                  //13-06-15|0x002a
#define BuildError 0x7fff                                                                 //13-06-15|0x002a
#define Display 0x7ffe                                                                    //13-06-15|0x002a
#define KeyBoard 0x7ffd                                                                   //13-06-15|0x002a
#define Success 0xffff                                                                    //13-06-15|0x002a
#define SystemError 0x8000                                                                //13-06-15|0x002a
#define Continue 0x0001                                                                   //13-06-15|0x002a
#define FileDone 0x0002                                                                   //13-06-15|0x002a
#define LineDone 0x0003                                                                   //13-06-15|0x002a
#define Yes 0x0004                                                                        //13-06-15|0x002a
#define No 0x0005                                                                         //13-06-15|0x002a
#define RepeatChar '\x6'                                                                  //13-06-15|0x002a
#define Great 0x0007                                                                      //13-06-15|0x002a
#define Equal 0x0008                                                                      //13-06-15|0x002a
#define Less 0x0009                                                                       //13-06-15|0x002a
#define Zero 0x000a                                                                       //13-06-15|0x002a
#define Minus 0x000b                                                                      //13-06-15|0x002a
//***************************************************************************             //13-06-15|0x002b
#define SystemMsg PcgSystemError("prime", __LINE__);                                      //13-06-15|0x002c
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //13-06-15|0x002c
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //13-06-15|0x002c
#define BreakFinish(_a) status = Finish(_a); break                                        //13-06-15|0x002d
#define ReturnFinish(_a) return(Finish(_a))                                               //13-06-15|0x002d
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //13-06-15|0x002d
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //13-06-15|0x002d
#define _SwitchErr case UserError: return(UserError)                                      //13-06-15|0x002e
#define _SwitchOk case Success: break                                                     //13-06-15|0x002e
#define _SwitchEnd default: ReturnSystemError                                             //13-06-15|0x002e
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //13-06-15|0x002e
#define _SwitchYes case Yes:      return(Yes)                                             //13-06-15|0x002e
#define _SwitchNo case No:       return(No)                                               //13-06-15|0x002e
#define _SwitchGroup { _SwitchBase; }                                                     //13-06-15|0x002e
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //13-06-15|0x002e
#define _SwitchReturn _SwitchGroup return(Success)                                        //13-06-15|0x002e
#define _SwitchBreak _SwitchGroup break                                                   //13-06-15|0x002e
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //13-06-15|0x002e
//*******************************************************************************         //05-24-97|0x00ac
//*******************************************************************************         //05-24-97|0x00ac
//****                       END OF FILE                                     ****         //05-24-97|0x00ac
//*******************************************************************************         //05-24-97|0x00ac
//*******************************************************************************         //05-24-97|0x00ac
#endif                                                                                    //05-24-97|0x00ac
