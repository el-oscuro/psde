//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
// PRECEDENCE FILE MANAGER                                                                //04-01-97|0x001e
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
#ifndef precfile_hxx                                                                      //04-01-97|0x0023
#define precfile_hxx                                                                      //04-01-97|0x0023
#define SystemMainExit { SystemMsg; PcgStop(); return(3); }                               //06-07-13|0x003f
#define _HXX_ENUM(_a) _a+1                                                                //06-07-13|0x0052
#define LOCAL_ZERO 0                                                                      //06-07-13|0x0052
#define FCT_READY _HXX_ENUM(LOCAL_ZERO)                                                   //06-07-13|0x00a0
#define FCB_READY _HXX_ENUM(FCT_READY)                                                    //06-08-18|0x01b9
#define FC_INACTIVE _HXX_ENUM(FCB_READY)                                                  //06-07-13|0x0215
#define FC_READY _HXX_ENUM(FC_INACTIVE)                                                   //07-03-23|0x0238
#define FD_PATH _HXX_ENUM(FC_READY)                                                       //07-03-23|0x0239
#define FD_NAME _HXX_ENUM(FD_PATH)                                                        //06-07-13|0x025e
#define FD_TIME _HXX_ENUM(FD_NAME)                                                        //06-09-04|0x0283
#define FD_INACTIVE _HXX_ENUM(FD_TIME)                                                    //06-07-13|0x02a1
#define FD_DELETE _HXX_ENUM(FD_INACTIVE)                                                  //06-09-04|0x02c2
#define FD_OPEN_TEXT _HXX_ENUM(FD_DELETE)                                                 //06-07-13|0x031f
#define FD_READ_TEXT _HXX_ENUM(FD_OPEN_TEXT)                                              //07-08-11|0x034a
#define FT_NEXT_PUT _HXX_ENUM(FD_READ_TEXT)                                               //10-08-19|0x0470
#define FT_WRITE_LINE _HXX_ENUM(FT_NEXT_PUT)                                              //10-08-19|0x0472
#define FT_EXIT _HXX_ENUM(FT_WRITE_LINE)                                                  //10-08-19|0x0473
#define FT_CLOSE_TEXT _HXX_ENUM(FT_EXIT)                                                  //<----   |0x04ef
#define FD_CREATE_RECORD _HXX_ENUM(FT_CLOSE_TEXT)                                         //06-07-27|0x09ae
#define FD_APPEND_RECORD _HXX_ENUM(FD_CREATE_RECORD)                                      //06-07-27|0x09ce
#define FD_OPEN_RECORD _HXX_ENUM(FD_APPEND_RECORD)                                        //06-07-27|0x09f0
#define FD_READ_RECORD _HXX_ENUM(FD_OPEN_RECORD)                                          //06-07-27|0x0a15
#define FD_WRITE_RECORD _HXX_ENUM(FD_READ_RECORD)                                         //06-07-27|0x0a3c
//*******************************************************************************         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
//****                       END OF FILE                                     ****         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
#endif                                                                                    //05-24-97|0x0b43
