//*****************************************************************************           //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
// PDE TEXT EXPRESSION ROUTINES                                                           //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-09-29|0x001f
//  defined in the associated manual.                                                     //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-09-29|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-09-29|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-09-29|0x001f
//  (at your option) any later version.                                                   //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-09-29|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-09-29|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-09-29|0x001f
//  GNU General Public License for more details.                                          //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
//  You should have received a copy of the GNU General Public License                     //06-09-29|0x001f
//  along with this program; if not, write to the Free Software                           //06-09-29|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-09-29|0x001f
//  USA                                                                                   //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  For further information, please contact Robert Adams:                                 //06-09-29|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-09-29|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-09-29|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
#ifndef prectext_h                                                                        //05-14-97|0x0022
#define prectext_h                                                                        //05-14-97|0x0022
//***************************************************************************             //06-09-29|0x003d
//***************************************************************************             //06-09-29|0x003e
//******                                                               ******             //06-09-29|0x003f
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-09-29|0x0040
//******                                                               ******             //06-09-29|0x0041
//***************************************************************************             //06-09-29|0x0042
//***************************************************************************             //06-09-29|0x0043
//*******************************************************************************         //06-09-29|0x0044
#ifndef STRING_DATA_Defined                                                               //06-09-29|0x0044
#define STRING_DATA_Defined                                                               //06-09-29|0x0044
//-------------------------------------------------------------------------------         //06-09-29|0x0044
typedef struct {                                                                          //06-09-29|0x0044
  SCHAR   line[257];                                                                      //06-09-29|0x0044
  UINT    macro_line_no;                                                                  //06-09-29|0x0044
  UINT    type;                                                                           //06-09-29|0x0044
  UINT    start_col;                                                                      //06-09-29|0x0044
  UINT    start_call;                                                                     //06-09-29|0x0044
  SINT    length;                                                                         //06-09-29|0x0044
  SINT    position;                                                                       //06-09-29|0x0044
  SINT    column;                                                                         //06-09-29|0x0044
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-09-29|0x0044
//-------------------------------------------------------------------------------         //06-09-29|0x0044
#endif                                                                                    //06-09-29|0x0044
//*******************************************************************************         //06-09-29|0x0045
#ifndef TOKENS_Defined                                                                    //06-09-29|0x0045
#define TOKENS_Defined                                                                    //06-09-29|0x0045
//-------------------------------------------------------------------------------         //06-09-29|0x0045
typedef struct {                                                                          //06-09-29|0x0045
  UINT        no_tokens;                                                                  //06-09-29|0x0045
  STRING_DATA token[10];                                                                  //06-09-29|0x0045
  } TOKENS, * TOKENS_FAR;                                                                 //06-09-29|0x0045
//-------------------------------------------------------------------------------         //06-09-29|0x0045
#endif                                                                                    //06-09-29|0x0045
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
// CLASS PRECTEXT DEFINITION                                                              //06-09-29|0x004d
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
class PRECTEXT {                                                                          //06-09-29|0x004d
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
// CLASS PRECTEXT DEFINITION                                                              //06-09-29|0x004d
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
    public:                                                                               //06-09-29|0x006c
      UINT clear_reg(STRING_DATA_FAR);                                                    //06-09-29|0x006c
#define TextClearReg prec_text.clear_reg                                                  //06-09-29|0x006d
    public:                                                                               //06-09-30|0x0090
      UINT test_parm(STRING_DATA_FAR);                                                    //06-09-30|0x0090
#define TextTestParm prec_text.test_parm                                                  //06-09-30|0x0091
    public:                                                                               //06-09-28|0x00c2
      UINT store_reg(STRING_DATA_FAR,STRING_DATA_FAR);                                    //06-09-28|0x00c2
#define TextStoreReg prec_text.store_reg                                                  //06-09-28|0x00c3
    public:                                                                               //06-09-29|0x00ea
      UINT read_reg(STRING_DATA_FAR,STRING_DATA_FAR);                                     //06-09-29|0x00ea
#define TextReadReg prec_text.read_reg                                                    //06-09-29|0x00eb
    public:                                                                               //06-07-22|0x0109
      UINT prepare_tokens(TOKENS_FAR,UINT);                                               //06-07-22|0x0109
#define TokensPrepare prec_text.prepare_tokens                                            //06-07-22|0x010a
    public:                                                                               //06-07-22|0x012f
      UINT text_prepare(STRING_DATA_FAR,STRING_DATA_FAR);                                 //06-07-22|0x012f
#define TextPrepare prec_text.text_prepare                                                //06-07-22|0x0130
    public:                                                                               //98-03-28|0x014a
      UINT assemble_text(STRING_DATA_FAR,STRING_DATA_FAR);                                //98-03-28|0x014a
#define AssembleText prec_text.assemble_text                                              //98-03-28|0x014b
    private:                                                                              //06-08-17|0x018f
      UINT argument_copy(STRING_DATA_FAR,SCHAR_FAR);                                      //06-08-17|0x018f
    private:                                                                              //06-07-22|0x01d7
      UINT get_parm(SCHAR_FAR);                                                           //06-07-22|0x01d7
    private:                                                                              //05-06-06|0x0204
      UINT check_type(STRING_DATA_FAR,UINT);                                              //05-06-06|0x0204
    public:                                                                               //04-10-05|0x0228
      UINT prectext_test_reset(void);                                                     //04-10-05|0x0228
#define PrecTextTestReset prec_text.prectext_test_reset                                   //04-10-05|0x0228
    public:                                                                               //04-10-05|0x022a
      UINT prectext_test_read(void);                                                      //04-10-05|0x022a
#define PrecTextTestRead prec_text.prectext_test_read                                     //04-10-05|0x022a
    public:                                                                               //04-10-05|0x022c
      UINT prectext_test_write(void);                                                     //04-10-05|0x022c
#define PrecTextTestWrite prec_text.prectext_test_write                                   //04-10-05|0x022c
    public:                                                                               //04-10-05|0x022e
      UINT prectexttest_report(void);                                                     //04-10-05|0x022e
#define PrecTextTestReport prec_text.prectexttest_report                                  //04-10-05|0x022e
    public:                                                                               //04-10-05|0x0236
      PRECTEXT();                                                                         //04-10-05|0x0236
  };                                                                                      //10-29-97|0x023e
extern class PRECTEXT prec_text;                                                          //98-12-29|0x023e
//*******************************************************************************         //05-24-97|0x023f
//*******************************************************************************         //05-24-97|0x023f
//****                       END OF FILE                                     ****         //05-24-97|0x023f
//*******************************************************************************         //05-24-97|0x023f
//*******************************************************************************         //05-24-97|0x023f
#endif                                                                                    //05-24-97|0x023f
