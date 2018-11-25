//*****************************************************************************           //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
// NUMERICAL MANAGEMENT ROUTINES                                                          //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-09-28|0x001f
//  defined in the associated manual.                                                     //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-09-28|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-09-28|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-09-28|0x001f
//  (at your option) any later version.                                                   //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-09-28|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-09-28|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-09-28|0x001f
//  GNU General Public License for more details.                                          //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
//  You should have received a copy of the GNU General Public License                     //06-09-28|0x001f
//  along with this program; if not, write to the Free Software                           //06-09-28|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-09-28|0x001f
//  USA                                                                                   //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  For further information, please contact Robert Adams:                                 //06-09-28|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-09-28|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-09-28|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
#ifndef precnum_h                                                                         //06-09-28|0x0020
#define precnum_h                                                                         //06-09-28|0x0020
//***************************************************************************             //06-09-29|0x003a
//***************************************************************************             //06-09-29|0x003b
//******                                                               ******             //06-09-29|0x003c
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-09-29|0x003d
//******                                                               ******             //06-09-29|0x003e
//***************************************************************************             //06-09-29|0x003f
//***************************************************************************             //06-09-29|0x0040
//*******************************************************************************         //06-09-29|0x0041
#ifndef STRING_DATA_Defined                                                               //06-09-29|0x0041
#define STRING_DATA_Defined                                                               //06-09-29|0x0041
//-------------------------------------------------------------------------------         //06-09-29|0x0041
typedef struct {                                                                          //06-09-29|0x0041
  SCHAR   line[257];                                                                      //06-09-29|0x0041
  UINT    macro_line_no;                                                                  //06-09-29|0x0041
  UINT    type;                                                                           //06-09-29|0x0041
  UINT    start_col;                                                                      //06-09-29|0x0041
  UINT    start_call;                                                                     //06-09-29|0x0041
  SINT    length;                                                                         //06-09-29|0x0041
  SINT    position;                                                                       //06-09-29|0x0041
  SINT    column;                                                                         //06-09-29|0x0041
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-09-29|0x0041
//-------------------------------------------------------------------------------         //06-09-29|0x0041
#endif                                                                                    //06-09-29|0x0041
//*******************************************************************************         //06-09-29|0x0042
#ifndef ARITH_DATA_Defined                                                                //06-09-29|0x0042
#define ARITH_DATA_Defined                                                                //06-09-29|0x0042
//-------------------------------------------------------------------------------         //06-09-29|0x0042
typedef struct {                                                                          //06-09-29|0x0042
  WORDS value;                                                                            //06-09-29|0x0042
  UINT  type;                                                                             //06-09-29|0x0042
  } ARITH_DATA, * ARITH_DATA_FAR;                                                         //06-09-29|0x0042
//-------------------------------------------------------------------------------         //06-09-29|0x0042
#endif                                                                                    //06-09-29|0x0042
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
// CLASS PRECNUM DEFINITION                                                               //06-09-29|0x004a
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
class PRECNUM {                                                                           //06-09-29|0x004a
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
// CLASS PRECNUM DEFINITION                                                               //06-09-29|0x004a
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
    public:                                                                               //06-09-29|0x0069
      UINT numeric_text_in(ARITH_DATA_FAR,STRING_DATA_FAR);                               //06-09-29|0x0069
#define NumericTextIn prec_num.numeric_text_in                                            //06-09-29|0x006a
    public:                                                                               //06-09-29|0x00a1
      UINT numeric_out(STRING_DATA_FAR,ARITH_DATA_FAR);                                   //06-09-29|0x00a1
#define NumericOut prec_num.numeric_out                                                   //06-09-29|0x00a4
    public:                                                                               //check   |0x00cd
      UINT get_integer(SCHAR_FAR,ULONG_FAR,ULONG);                                        //check   |0x00cd
#define GetInteger prec_num.get_integer                                                   //05-04-22|0x00cf
    public:                                                                               //04-10-05|0x0109
      UINT precnum_test_reset(void);                                                      //04-10-05|0x0109
#define PrecNumTestReset prec_num.precnum_test_reset                                      //04-10-05|0x0109
    public:                                                                               //04-10-05|0x010b
      UINT precnum_test_read(void);                                                       //04-10-05|0x010b
#define PrecNumTestRead prec_num.precnum_test_read                                        //04-10-05|0x010b
    public:                                                                               //04-10-05|0x010d
      UINT precnum_test_write(void);                                                      //04-10-05|0x010d
#define PrecNumTestWrite prec_num.precnum_test_write                                      //04-10-05|0x010d
    public:                                                                               //04-10-05|0x010f
      UINT precnum_test_report(void);                                                     //04-10-05|0x010f
#define PrecNumTestReport prec_num.precnum_test_report                                    //04-10-05|0x010f
    public:                                                                               //04-10-05|0x0117
      PRECNUM();                                                                          //04-10-05|0x0117
  };                                                                                      //10-29-97|0x011f
extern class PRECNUM prec_num;                                                            //98-12-29|0x011f
//*******************************************************************************         //05-24-97|0x0120
//*******************************************************************************         //05-24-97|0x0120
//****                       END OF FILE                                     ****         //05-24-97|0x0120
//*******************************************************************************         //05-24-97|0x0120
//*******************************************************************************         //05-24-97|0x0120
#endif                                                                                    //05-24-97|0x0120
