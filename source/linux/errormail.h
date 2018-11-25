//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
// MAILBOX DICTIONARY_MANAGER                                                             //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-11-09|0x000b
//  defined in the associated manual.                                                     //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-11-09|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-11-09|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-11-09|0x000b
//  (at your option) any later version.                                                   //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-11-09|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-11-09|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-11-09|0x000b
//  GNU General Public License for more details.                                          //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//  You should have received a copy of the GNU General Public License                     //07-11-09|0x000b
//  along with this program; if not, write to the Free Software                           //07-11-09|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-11-09|0x000b
//  USA                                                                                   //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  For further information, please contact Robert Adams:                                 //07-11-09|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-11-09|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-11-09|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
#ifndef errormail_h                                                                       //07-11-09|0x000c
#define errormail_h                                                                       //07-11-09|0x000c
//***************************************************************************             //07-11-09|0x0023
//***************************************************************************             //07-11-09|0x0024
//******                                                               ******             //07-11-09|0x0025
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //07-11-09|0x0026
//******                                                               ******             //07-11-09|0x0027
//***************************************************************************             //07-11-09|0x0028
//***************************************************************************             //07-11-09|0x0029
//*******************************************************************************         //07-11-09|0x002a
#ifndef STRING_DATA_Defined                                                               //07-11-09|0x002a
#define STRING_DATA_Defined                                                               //07-11-09|0x002a
//-------------------------------------------------------------------------------         //07-11-09|0x002a
typedef struct {                                                                          //07-11-09|0x002a
  SCHAR   line[257];                                                                      //07-11-09|0x002a
  UINT    macro_line_no;                                                                  //07-11-09|0x002a
  UINT    type;                                                                           //07-11-09|0x002a
  UINT    start_col;                                                                      //07-11-09|0x002a
  UINT    start_call;                                                                     //07-11-09|0x002a
  SINT    length;                                                                         //07-11-09|0x002a
  SINT    position;                                                                       //07-11-09|0x002a
  SINT    column;                                                                         //07-11-09|0x002a
  } STRING_DATA, * STRING_DATA_FAR;                                                       //07-11-09|0x002a
//-------------------------------------------------------------------------------         //07-11-09|0x002a
#endif                                                                                    //07-11-09|0x002a
//*******************************************************************************         //07-11-09|0x002b
#ifndef TOKENS_Defined                                                                    //07-11-09|0x002b
#define TOKENS_Defined                                                                    //07-11-09|0x002b
//-------------------------------------------------------------------------------         //07-11-09|0x002b
typedef struct {                                                                          //07-11-09|0x002b
  UINT        no_tokens;                                                                  //07-11-09|0x002b
  STRING_DATA token[10];                                                                  //07-11-09|0x002b
  } TOKENS, * TOKENS_FAR;                                                                 //07-11-09|0x002b
//-------------------------------------------------------------------------------         //07-11-09|0x002b
#endif                                                                                    //07-11-09|0x002b
//*******************************************************************************         //10-29-97|0x0033
//*******************************************************************************         //10-29-97|0x0033
// CLASS ERRORMAIL DEFINITION                                                             //07-11-09|0x0033
//*******************************************************************************         //10-29-97|0x0033
//*******************************************************************************         //10-29-97|0x0033
class ERRORMAIL {                                                                         //07-11-09|0x0033
//*******************************************************************************         //10-29-97|0x0033
//*******************************************************************************         //10-29-97|0x0033
// CLASS ERRORMAIL DEFINITION                                                             //07-11-09|0x0033
//*******************************************************************************         //10-29-97|0x0033
//*******************************************************************************         //10-29-97|0x0033
    private:                                                                              //10-27-97|0x003b
      TOKENS error_tokens;                                                                //10-27-97|0x003b
    public:                                                                               //07-11-12|0x0053
      UINT errormail_add_macro(STRING_DATA_FAR);                                          //07-11-12|0x0053
#define ErrorMailAddMacro error_mail.errormail_add_macro                                  //07-11-12|0x0055
    public:                                                                               //07-11-12|0x0070
      UINT errormail_add_error(STRING_DATA_FAR);                                          //07-11-12|0x0070
#define ErrorMailAddError error_mail.errormail_add_error                                  //07-11-12|0x0072
    public:                                                                               //07-11-17|0x0090
      UINT errormail_test_error(void);                                                    //07-11-17|0x0090
#define ErrorMailTestError error_mail.errormail_test_error                                //07-11-17|0x0092
    public:                                                                               //07-11-16|0x00ab
      UINT errormail_read_macro(STRING_DATA_FAR);                                         //07-11-16|0x00ab
#define ErrorMailReadMacro error_mail.errormail_read_macro                                //07-11-16|0x00ad
    public:                                                                               //07-11-16|0x00c8
      UINT errormail_read_error(STRING_DATA_FAR);                                         //07-11-16|0x00c8
#define ErrorMailReadError error_mail.errormail_read_error                                //07-11-16|0x00ca
    public:                                                                               //07-11-09|0x00e2
      UINT errormail_test_reset(void);                                                    //07-11-09|0x00e2
#define ErrorMailTestReset error_mail.errormail_test_reset                                //07-11-09|0x00e2
    public:                                                                               //07-11-09|0x00e4
      UINT errormail_test_read(void);                                                     //07-11-09|0x00e4
#define ErrorMailTestRead error_mail.errormail_test_read                                  //07-11-09|0x00e4
    public:                                                                               //07-11-09|0x00e6
      UINT errormail_test_write(void);                                                    //07-11-09|0x00e6
#define ErrorMailTestWrite error_mail.errormail_test_write                                //07-11-09|0x00e6
    public:                                                                               //07-11-09|0x00e8
      UINT errormail_test_report(void);                                                   //07-11-09|0x00e8
#define ErrorMailTestReport error_mail.errormail_test_report                              //07-11-09|0x00e8
    public:                                                                               //07-11-09|0x00f2
      ERRORMAIL();                                                                        //07-11-09|0x00f2
  };                                                                                      //10-29-97|0x00fc
extern class ERRORMAIL error_mail;                                                        //98-12-29|0x00fc
//*******************************************************************************         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
//****                       END OF FILE                                     ****         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
#endif                                                                                    //05-24-97|0x00fd
