//*****************************************************************************           //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
// MACRO ENTRY SUB-SYSTEM                                                                 //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x001d
//  defined in the associated manual.                                                     //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x001d
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x001d
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x001d
//  (at your option) any later version.                                                   //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x001d
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x001d
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x001d
//  GNU General Public License for more details.                                          //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x001d
//  along with this program; if not, write to the Free Software                           //06-07-12|0x001d
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x001d
//  USA                                                                                   //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  For further information, please contact Robert Adams:                                 //06-07-12|0x001d
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x001d
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x001d
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
#ifndef precmac_h                                                                         //06-07-12|0x001e
#define precmac_h                                                                         //06-07-12|0x001e
//***************************************************************************             //06-07-12|0x003e
//***************************************************************************             //06-07-12|0x003f
//******                                                               ******             //06-07-12|0x0040
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0041
//******                                                               ******             //06-07-12|0x0042
//***************************************************************************             //06-07-12|0x0043
//***************************************************************************             //06-07-12|0x0044
//*******************************************************************************         //06-07-12|0x0045
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x0045
#define STRING_DATA_Defined                                                               //06-07-12|0x0045
//-------------------------------------------------------------------------------         //06-07-12|0x0045
typedef struct {                                                                          //06-07-12|0x0045
  SCHAR   line[257];                                                                      //06-07-12|0x0045
  UINT    macro_line_no;                                                                  //06-07-12|0x0045
  UINT    type;                                                                           //06-07-12|0x0045
  UINT    start_col;                                                                      //06-07-12|0x0045
  UINT    start_call;                                                                     //06-07-12|0x0045
  SINT    length;                                                                         //06-07-12|0x0045
  SINT    position;                                                                       //06-07-12|0x0045
  SINT    column;                                                                         //06-07-12|0x0045
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x0045
//-------------------------------------------------------------------------------         //06-07-12|0x0045
#endif                                                                                    //06-07-12|0x0045
//*******************************************************************************         //06-07-12|0x0046
#ifndef TOKENS_Defined                                                                    //06-07-12|0x0046
#define TOKENS_Defined                                                                    //06-07-12|0x0046
//-------------------------------------------------------------------------------         //06-07-12|0x0046
typedef struct {                                                                          //06-07-12|0x0046
  UINT        no_tokens;                                                                  //06-07-12|0x0046
  STRING_DATA token[10];                                                                  //06-07-12|0x0046
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x0046
//-------------------------------------------------------------------------------         //06-07-12|0x0046
#endif                                                                                    //06-07-12|0x0046
#ifndef MACRO_DATA_Defined                                                                //06-07-12|0x0047
#define MACRO_DATA_Defined                                                                //06-07-12|0x0047
//-------------------------------------------------------------------------------         //06-07-12|0x0047
typedef struct {                                                                          //06-07-12|0x0047
  UINT          rule_state;                                                               //06-07-12|0x0047
  UINT          label_state;                                                              //06-07-12|0x0047
  UINT          control_state;                                                            //06-07-12|0x0047
  UINT          command_state;                                                            //06-07-12|0x0047
  UINT          process_state;                                                            //06-07-12|0x0047
  UINT          bridge_state;                                                             //06-07-12|0x0047
  UINT          run_flag;                                                                 //06-07-12|0x0047
  UINT          status;                                                                   //06-07-12|0x0047
  STRING_DATA   class_name;                                                               //06-07-12|0x0047
  STRING_DATA   utility_bridge;                                                           //06-07-12|0x0047
  STRING_DATA   macro_name;                                                               //06-07-12|0x0047
  STRING_DATA   label;                                                                    //06-07-12|0x0047
  TOKENS        tokens;                                                                   //06-07-12|0x0047
  } MACRO_DATA, * MACRO_DATA_FAR;                                                         //06-07-12|0x0047
//-------------------------------------------------------------------------------         //06-07-12|0x0047
#endif                                                                                    //06-07-12|0x0047
//***************************************************************************             //06-07-12|0x0048
//*****************************************************************************           //06-07-12|0x0049
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x0049
#define FILE_CONTROL_Defined                                                              //06-07-12|0x0049
//-----------------------------------------------------------------------------           //06-07-12|0x0049
typedef struct {                                                                          //06-07-12|0x0049
  UINT    state;                                                                          //06-07-12|0x0049
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x0049
  FILE *  stream;                                                                         //06-07-12|0x0049
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x0049
//-----------------------------------------------------------------------------           //06-07-12|0x0049
#endif                                                                                    //06-07-12|0x0049
//*****************************************************************************           //06-07-12|0x004a
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-12|0x004a
#define TEXT_FILE_DATA_Defined                                                            //06-07-12|0x004a
//-----------------------------------------------------------------------------           //06-07-12|0x004a
typedef struct {                                                                          //06-07-12|0x004a
  FILE_CONTROL    file_control;                                                           //06-07-12|0x004a
  STRING_DATA     string;                                                                 //06-07-12|0x004a
  UINT            read_state;                                                             //06-07-12|0x004a
  UINT            get_state;                                                              //06-07-12|0x004a
  UINT            put_state;                                                              //06-07-12|0x004a
  UINT            status;                                                                 //06-07-12|0x004a
  UINT            run_flag;                                                               //06-07-12|0x004a
  UINT            line_no;                                                                //06-07-12|0x004a
  SLONG           length;                                                                 //06-07-12|0x004a
  SLONG           next_position;                                                          //06-07-12|0x004a
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-12|0x004a
//-----------------------------------------------------------------------------           //06-07-12|0x004a
#endif                                                                                    //06-07-12|0x004a
#ifndef MACRO_DEVELOP_Defined                                                             //11-02-14|0x004b
#define MACRO_DEVELOP_Defined                                                             //11-02-14|0x004b
//-----------------------------------------------------------------------------           //11-02-14|0x004b
typedef struct {                                                                          //11-02-14|0x004b
  UINT            develop_status;                                                         //11-02-14|0x004b
  ULONG           in_time;                                                                //11-02-14|0x004b
  TEXT_FILE_DATA  macro_file;                                                             //11-02-14|0x004b
  } MACRO_DEVELOP, * MACRO_DEVELOP_FAR;                                                   //11-02-14|0x004b
//-----------------------------------------------------------------------------           //11-02-14|0x004b
#endif                                                                                    //11-02-14|0x004b
//*******************************************************************************         //10-29-97|0x0053
//*******************************************************************************         //10-29-97|0x0053
// CLASS PRECMACRO DEFINITION                                                             //06-07-12|0x0053
//*******************************************************************************         //10-29-97|0x0053
//*******************************************************************************         //10-29-97|0x0053
class PRECMACRO {                                                                         //06-07-12|0x0053
//*******************************************************************************         //10-29-97|0x0053
//*******************************************************************************         //10-29-97|0x0053
// CLASS PRECMACRO DEFINITION                                                             //06-07-12|0x0053
//*******************************************************************************         //10-29-97|0x0053
//*******************************************************************************         //10-29-97|0x0053
    private:                                                                              //10-27-97|0x005b
      MACRO_DATA_FAR macro_data_addr;                                                     //10-27-97|0x005b
    private:                                                                              //11-02-17|0x0081
      UINT load_command(MACRO_DEVELOP_FAR,SCHAR_FAR,UINT,UINT,UINT);                      //11-02-17|0x0081
    public:                                                                               //06-07-12|0x00a4
      UINT precmac_allocate(void);                                                        //06-07-12|0x00a4
#define PrecmacAllocate prec_macro.precmac_allocate                                       //06-07-12|0x00a5
    public:                                                                               //06-07-12|0x00c3
      UINT precmac_free(void);                                                            //06-07-12|0x00c3
#define PrecmacFree prec_macro.precmac_free                                               //06-07-12|0x00c4
    public:                                                                               //11-02-14|0x00db
      UINT precmac_process(MACRO_DEVELOP_FAR);                                            //11-02-14|0x00db
#define PrecmacProcess prec_macro.precmac_process                                         //06-09-04|0x00dd
    private:                                                                              //11-02-14|0x0156
      UINT precmac_command(MACRO_DEVELOP_FAR);                                            //11-02-14|0x0156
    private:                                                                              //11-02-14|0x0287
      UINT precmac_control(MACRO_DEVELOP_FAR);                                            //11-02-14|0x0287
    private:                                                                              //11-02-14|0x02c4
      UINT precmac_label(MACRO_DEVELOP_FAR);                                              //11-02-14|0x02c4
    private:                                                                              //11-02-14|0x02f6
      UINT precmac_rule(MACRO_DEVELOP_FAR);                                               //11-02-14|0x02f6
    private:                                                                              //07-07-18|0x0337
      UINT begin_command(SCHAR_FAR,UINT);                                                 //07-07-18|0x0337
    private:                                                                              //11-02-14|0x0357
      UINT begin_report(MACRO_DEVELOP_FAR,SCHAR_FAR);                                     //11-02-14|0x0357
    private:                                                                              //07-05-22|0x0382
      UINT utility_bridge(void);                                                          //07-05-22|0x0382
    private:                                                                              //11-02-14|0x039e
      UINT begin_load_command(MACRO_DEVELOP_FAR);                                         //11-02-14|0x039e
    private:                                                                              //11-02-14|0x03be
      UINT end_command(MACRO_DEVELOP_FAR);                                                //11-02-14|0x03be
    private:                                                                              //06-09-04|0x0405
      UINT error_command(SCHAR_FAR);                                                      //06-09-04|0x0405
    private:                                                                              //11-02-18|0x0422
      UINT load_label_command(MACRO_DEVELOP_FAR);                                         //11-02-18|0x0422
    private:                                                                              //11-02-14|0x0447
      UINT enter_command(MACRO_DEVELOP_FAR,UINT);                                         //11-02-14|0x0447
    private:                                                                              //14-12-03|0x046b
      UINT basic_parity(MACRO_DEVELOP_FAR);                                               //14-12-03|0x046b
    private:                                                                              //11-02-17|0x04d7
      UINT load_label_name(MACRO_DEVELOP_FAR);                                            //11-02-17|0x04d7
    private:                                                                              //06-09-04|0x04fb
      UINT prepare_label_name(void);                                                      //06-09-04|0x04fb
    private:                                                                              //06-09-05|0x052f
      UINT load_dummy_label(void);                                                        //06-09-05|0x052f
    private:                                                                              //11-02-17|0x055c
      UINT open_macro(MACRO_DEVELOP_FAR);                                                 //11-02-17|0x055c
    private:                                                                              //11-02-17|0x0577
      UINT read_macro(MACRO_DEVELOP_FAR);                                                 //11-02-17|0x0577
    private:                                                                              //11-02-17|0x059d
      UINT close_macro(MACRO_DEVELOP_FAR);                                                //11-02-17|0x059d
    public:                                                                               //06-07-14|0x05b2
      UINT precmac_test_reset(void);                                                      //06-07-14|0x05b2
#define PrecMacTestReset prec_macro.precmac_test_reset                                    //06-07-14|0x05b2
    public:                                                                               //06-07-14|0x05b4
      UINT precmac_test_read(void);                                                       //06-07-14|0x05b4
#define PrecMacTestRead prec_macro.precmac_test_read                                      //06-07-14|0x05b4
    public:                                                                               //06-07-14|0x05b6
      UINT precmac_test_write(void);                                                      //06-07-14|0x05b6
#define PrecMacTestWrite prec_macro.precmac_test_write                                    //06-07-14|0x05b6
    public:                                                                               //06-07-14|0x05b8
      UINT precmac_test_report(void);                                                     //06-07-14|0x05b8
#define PrecMacTestReport prec_macro.precmac_test_report                                  //06-07-14|0x05b8
    public:                                                                               //06-07-12|0x05c2
      PRECMACRO();                                                                        //06-07-12|0x05c2
  };                                                                                      //10-29-97|0x05c7
extern class PRECMACRO prec_macro;                                                        //98-12-29|0x05c7
//*******************************************************************************         //05-24-97|0x05c8
//*******************************************************************************         //05-24-97|0x05c8
//****                       END OF FILE                                     ****         //05-24-97|0x05c8
//*******************************************************************************         //05-24-97|0x05c8
//*******************************************************************************         //05-24-97|0x05c8
#endif                                                                                    //05-24-97|0x05c8
