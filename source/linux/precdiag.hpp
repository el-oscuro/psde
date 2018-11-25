//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
// PRECEDENCE DIAGNOSTIC MANAGER                                                          //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  The purpose of this program as well as instructions regarding its use is              //04-01-97|0x001e
//  defined in the associated manual.                                                     //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  This program is free software; you can redistribute it and/or modify                  //04-01-97|0x001e
//  it under the terms of the GNU General Public License as published by                  //04-01-97|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //04-01-97|0x001e
//  (at your option) any later version.                                                   //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//  This program is distributed in the hope that it will be useful,                       //04-01-97|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //04-01-97|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //04-01-97|0x001e
//  GNU General Public License for more details.                                          //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//  You should have received a copy of the GNU General Public License                     //04-01-97|0x001e
//  along with this program; if not, write to the Free Software                           //04-01-97|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //04-01-97|0x001e
//  USA                                                                                   //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  For further information, please contact Robert Adams:                                 //04-01-97|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //04-01-97|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //04-01-97|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
#ifndef precdiag_hpp                                                                      //06-08-23|0x0021
#define precdiag_hpp                                                                      //06-08-23|0x0021
//***************************************************************************             //06-08-23|0x0027
//***************************************************************************             //06-08-23|0x0028
//******                                                               ******             //06-08-23|0x0029
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-08-23|0x002a
//******                                                               ******             //06-08-23|0x002b
//***************************************************************************             //06-08-23|0x002c
//***************************************************************************             //06-08-23|0x002d
//***************************************************************************             //06-08-23|0x0030
//***************************************************************************             //06-08-23|0x0031
//******                                                               ******             //06-08-23|0x0032
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-08-23|0x0033
//******                                                               ******             //06-08-23|0x0034
//***************************************************************************             //06-08-23|0x0035
//***************************************************************************             //06-08-23|0x0036
#define UserError 0x0000                                                                  //06-08-23|0x0037
#define BuildError 0x7fff                                                                 //06-08-23|0x0037
#define Display 0x7ffe                                                                    //06-08-23|0x0037
#define KeyBoard 0x7ffd                                                                   //06-08-23|0x0037
#define Success 0xffff                                                                    //06-08-23|0x0037
#define SystemError 0x8000                                                                //06-08-23|0x0037
#define Continue 0x0001                                                                   //06-08-23|0x0037
#define FileDone 0x0002                                                                   //06-08-23|0x0037
#define LineDone 0x0003                                                                   //06-08-23|0x0037
#define Yes 0x0004                                                                        //06-08-23|0x0037
#define No 0x0005                                                                         //06-08-23|0x0037
#define RepeatChar '\x6'                                                                  //06-08-23|0x0037
#define Great 0x0007                                                                      //06-08-23|0x0037
#define Equal 0x0008                                                                      //06-08-23|0x0037
#define Less 0x0009                                                                       //06-08-23|0x0037
#define Zero 0x000a                                                                       //06-08-23|0x0037
#define Minus 0x000b                                                                      //06-08-23|0x0037
//***************************************************************************             //06-08-23|0x0038
#define SystemMsg PcgSystemError("Precdiag", __LINE__);                                   //06-08-23|0x0039
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-08-23|0x0039
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-08-23|0x0039
//*******************************************************************************         //05-24-97|0x01d9
//*******************************************************************************         //05-24-97|0x01d9
//****                       END OF FILE                                     ****         //05-24-97|0x01d9
//*******************************************************************************         //05-24-97|0x01d9
//*******************************************************************************         //05-24-97|0x01d9
#endif                                                                                    //05-24-97|0x01d9
