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
#ifndef prime_h                                                                           //13-06-15|0x001e
#define prime_h                                                                           //13-06-15|0x001e
//*******************************************************************************         //10-29-97|0x0034
//*******************************************************************************         //10-29-97|0x0034
// CLASS PRIME DEFINITION                                                                 //13-06-15|0x0034
//*******************************************************************************         //10-29-97|0x0034
//*******************************************************************************         //10-29-97|0x0034
class PRIME {                                                                             //13-06-15|0x0034
//*******************************************************************************         //10-29-97|0x0034
//*******************************************************************************         //10-29-97|0x0034
// CLASS PRIME DEFINITION                                                                 //13-06-15|0x0034
//*******************************************************************************         //10-29-97|0x0034
//*******************************************************************************         //10-29-97|0x0034
    private:                                                                              //10-27-97|0x003c
      UINT prime_no[4096];                                                                //10-27-97|0x003c
    public:                                                                               //check   |0x0044
      UINT prime_get(UINT_FAR,UINT);                                                      //check   |0x0044
#define PrimeGet prime_resource.prime_get                                                 //check   |0x0046
    public:                                                                               //13-06-15|0x0057
      UINT prime_create(void);                                                            //13-06-15|0x0057
#define PrimeCreate prime_resource.prime_create                                           //13-06-15|0x0058
    private:                                                                              //13-06-15|0x007d
      UINT prime_test(UINT,UINT);                                                         //13-06-15|0x007d
    public:                                                                               //13-06-15|0x009f
      PRIME();                                                                            //13-06-15|0x009f
  };                                                                                      //10-29-97|0x00ab
extern class PRIME prime_resource;                                                        //98-12-29|0x00ab
//*******************************************************************************         //05-24-97|0x00ac
//*******************************************************************************         //05-24-97|0x00ac
//****                       END OF FILE                                     ****         //05-24-97|0x00ac
//*******************************************************************************         //05-24-97|0x00ac
//*******************************************************************************         //05-24-97|0x00ac
#endif                                                                                    //05-24-97|0x00ac
