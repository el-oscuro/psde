//*****************************************************************************           //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//                                                                                        //98-07-28|0x001e
// PRECEDENCE TEXT FORMAT MANAGER                                                         //98-07-28|0x001e
//                                                                                        //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//  The purpose of this program as well as instructions regarding its use is              //98-07-28|0x001e
//  defined in the associated manual.                                                     //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//  This program is free software; you can redistribute it and/or modify                  //98-07-28|0x001e
//  it under the terms of the GNU General Public License as published by                  //98-07-28|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //98-07-28|0x001e
//  (at your option) any later version.                                                   //98-07-28|0x001e
//                                                                                        //98-07-28|0x001e
//  This program is distributed in the hope that it will be useful,                       //98-07-28|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //98-07-28|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //98-07-28|0x001e
//  GNU General Public License for more details.                                          //98-07-28|0x001e
//                                                                                        //98-07-28|0x001e
//  You should have received a copy of the GNU General Public License                     //98-07-28|0x001e
//  along with this program; if not, write to the Free Software                           //98-07-28|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //98-07-28|0x001e
//  USA                                                                                   //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//  For further information, please contact Robert Adams:                                 //98-07-28|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //98-07-28|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //98-07-28|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
//*****************************************************************************           //98-07-28|0x001e
#ifndef precform_h                                                                        //06-07-22|0x0021
#define precform_h                                                                        //06-07-22|0x0021
//***************************************************************************             //06-07-22|0x0039
//***************************************************************************             //06-07-22|0x003a
//******                                                               ******             //06-07-22|0x003b
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-22|0x003c
//******                                                               ******             //06-07-22|0x003d
//***************************************************************************             //06-07-22|0x003e
//***************************************************************************             //06-07-22|0x003f
//*******************************************************************************         //06-07-22|0x0040
#ifndef STRING_DATA_Defined                                                               //06-07-22|0x0040
#define STRING_DATA_Defined                                                               //06-07-22|0x0040
//-------------------------------------------------------------------------------         //06-07-22|0x0040
typedef struct {                                                                          //06-07-22|0x0040
  SCHAR   line[257];                                                                      //06-07-22|0x0040
  UINT    macro_line_no;                                                                  //06-07-22|0x0040
  UINT    type;                                                                           //06-07-22|0x0040
  UINT    start_col;                                                                      //06-07-22|0x0040
  UINT    start_call;                                                                     //06-07-22|0x0040
  SINT    length;                                                                         //06-07-22|0x0040
  SINT    position;                                                                       //06-07-22|0x0040
  SINT    column;                                                                         //06-07-22|0x0040
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-22|0x0040
//-------------------------------------------------------------------------------         //06-07-22|0x0040
#endif                                                                                    //06-07-22|0x0040
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
// CLASS PRECFORM DEFINITION                                                              //98-07-28|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
class PRECFORM {                                                                          //98-07-28|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
// CLASS PRECFORM DEFINITION                                                              //98-07-28|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
    public:                                                                               //check   |0x0061
      UINT concat(STRING_DATA_FAR,STRING_DATA_FAR);                                       //check   |0x0061
#define PrecFormConcat prec_format.concat                                                 //check   |0x0063
    public:                                                                               //98-07-28|0x008d
      UINT get_token(STRING_DATA_FAR,STRING_DATA_FAR);                                    //98-07-28|0x008d
#define PrecformGetToken prec_format.get_token                                            //98-07-28|0x008e
    public:                                                                               //04-04-97|0x00b3
      UINT get_text(STRING_DATA_FAR,STRING_DATA_FAR);                                     //04-04-97|0x00b3
#define PrecformGetText prec_format.get_text                                              //04-04-97|0x00b4
    public:                                                                               //04-04-97|0x00e1
      UINT get_string(STRING_DATA_FAR,STRING_DATA_FAR);                                   //04-04-97|0x00e1
#define PrecformGetString prec_format.get_string                                          //04-04-97|0x00e2
    private:                                                                              //98-07-28|0x010f
      UINT char_input(STRING_DATA_FAR,STRING_DATA_FAR);                                   //98-07-28|0x010f
    public:                                                                               //98-07-28|0x0127
      UINT flag_end(STRING_DATA_FAR);                                                     //98-07-28|0x0127
#define PrecformFlagEnd prec_format.flag_end                                              //98-07-28|0x0128
    public:                                                                               //05-06-13|0x0148
      UINT name_test(STRING_DATA_FAR);                                                    //05-06-13|0x0148
#define PrecformNameTest prec_format.name_test                                            //05-06-13|0x0149
    public:                                                                               //05-06-13|0x0183
      UINT string_test(STRING_DATA_FAR);                                                  //05-06-13|0x0183
#define PrecformStringTest prec_format.string_test                                        //05-06-13|0x0184
    public:                                                                               //06-07-22|0x01d7
      UINT process_backslash(STRING_DATA_FAR,STRING_DATA_FAR,UINT);                       //06-07-22|0x01d7
#define ProcessBackSlash prec_format.process_backslash                                    //06-07-22|0x01d9
    public:                                                                               //04-10-22|0x020f
      UINT precformat_test_reset(void);                                                   //04-10-22|0x020f
#define PrecFormatTestReset prec_format.precformat_test_reset                             //04-10-22|0x020f
    public:                                                                               //04-10-22|0x0211
      UINT precformat_test_read(void);                                                    //04-10-22|0x0211
#define PrecFormatTestRead prec_format.precformat_test_read                               //04-10-22|0x0211
    public:                                                                               //04-10-22|0x0213
      UINT precformat_test_write(void);                                                   //04-10-22|0x0213
#define PrecFormatTestWrite prec_format.precformat_test_write                             //04-10-22|0x0213
    public:                                                                               //04-10-22|0x0215
      UINT precformat_test_report(void);                                                  //04-10-22|0x0215
#define PrecFormatTestReport prec_format.precformat_test_report                           //04-10-22|0x0215
    public:                                                                               //04-10-22|0x021f
      PRECFORM();                                                                         //04-10-22|0x021f
  };                                                                                      //10-29-97|0x0224
extern class PRECFORM prec_format;                                                        //98-12-29|0x0224
//*******************************************************************************         //05-24-97|0x0225
//*******************************************************************************         //05-24-97|0x0225
//****                       END OF FILE                                     ****         //05-24-97|0x0225
//*******************************************************************************         //05-24-97|0x0225
//*******************************************************************************         //05-24-97|0x0225
#endif                                                                                    //05-24-97|0x0225
