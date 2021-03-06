//*****************************************************************************           //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//                                                                                        //03-29-97|0x001b
// PRECEDENCE ANALYSIS UTILITY                                                            //03-29-97|0x001b
//                                                                                        //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//  The purpose of this program as well as instructions regarding its use is              //03-29-97|0x001b
//  defined in the associated manual.                                                     //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//  This program is free software; you can redistribute it and/or modify                  //03-29-97|0x001b
//  it under the terms of the GNU General Public License as published by                  //03-29-97|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //03-29-97|0x001b
//  (at your option) any later version.                                                   //03-29-97|0x001b
//                                                                                        //03-29-97|0x001b
//  This program is distributed in the hope that it will be useful,                       //03-29-97|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //03-29-97|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //03-29-97|0x001b
//  GNU General Public License for more details.                                          //03-29-97|0x001b
//                                                                                        //03-29-97|0x001b
//  You should have received a copy of the GNU General Public License                     //03-29-97|0x001b
//  along with this program; if not, write to the Free Software                           //03-29-97|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //03-29-97|0x001b
//  USA                                                                                   //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//  For further information, please contact Robert Adams:                                 //03-29-97|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //03-29-97|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //03-29-97|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
//*****************************************************************************           //03-29-97|0x001b
#ifndef precutil_h                                                                        //03-29-97|0x001c
#define precutil_h                                                                        //03-29-97|0x001c
//*******************************************************************************         //10-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
// CLASS PRECUTIL DEFINITION                                                              //03-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
class PRECUTIL {                                                                          //03-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
// CLASS PRECUTIL DEFINITION                                                              //03-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
//*******************************************************************************         //10-29-97|0x0022
    public:                                                                               //05-04-22|0x002a
       UCHAR_FAR mem_c_copy(UCHAR_FAR,UCHAR_FAR,UINT,UINT);                               //05-04-22|0x002a
#define Mem_C_Copy prec_util.mem_c_copy                                                   //05-04-22|0x002c
    public:                                                                               //11-05-27|0x0040
      SLONG str_comp(SCHAR_FAR,SCHAR_FAR,UINT);                                           //11-05-27|0x0040
#define Str_Comp prec_util.str_comp                                                       //11-05-27|0x0042
    public:                                                                               //check   |0x006b
      UINT get_hex(SCHAR_FAR,ULONG_FAR,ULONG);                                            //check   |0x006b
#define GetHex prec_util.get_hex                                                          //05-04-22|0x006d
  };                                                                                      //10-29-97|0x00ad
extern class PRECUTIL prec_util;                                                          //98-12-29|0x00ad
//*******************************************************************************         //05-24-97|0x00ae
//*******************************************************************************         //05-24-97|0x00ae
//****                       END OF FILE                                     ****         //05-24-97|0x00ae
//*******************************************************************************         //05-24-97|0x00ae
//*******************************************************************************         //05-24-97|0x00ae
#endif                                                                                    //05-24-97|0x00ae
