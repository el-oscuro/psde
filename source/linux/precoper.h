//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
// OPERATION GENERATOR                                                                    //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  Copyright: 2006 Robert H. Adams                                                       //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  The purpose of this program as well as instructions regarding its use is              //06-07-14|0x000c
//  defined in the associated manual.                                                     //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  This program is free software; you can redistribute it and/or modify                  //06-07-14|0x000c
//  it under the terms of the GNU General Public License as published by                  //06-07-14|0x000c
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-14|0x000c
//  (at your option) any later version.                                                   //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//  This program is distributed in the hope that it will be useful,                       //06-07-14|0x000c
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-14|0x000c
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-14|0x000c
//  GNU General Public License for more details.                                          //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//  You should have received a copy of the GNU General Public License                     //06-07-14|0x000c
//  along with this program; if not, write to the Free Software                           //06-07-14|0x000c
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-14|0x000c
//  USA                                                                                   //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  For further information, please contact Robert Adams:                                 //06-07-14|0x000c
//     EMail:    robert.adams@whatifwe.com                                                //06-07-14|0x000c
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-14|0x000c
//  Or visit the website, "www.whatifwe.com".                                             //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
#ifndef precoper_h                                                                        //06-07-14|0x000d
#define precoper_h                                                                        //06-07-14|0x000d
//***************************************************************************             //06-07-14|0x0040
//***************************************************************************             //06-07-14|0x0041
//******                                                               ******             //06-07-14|0x0042
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-14|0x0043
//******                                                               ******             //06-07-14|0x0044
//***************************************************************************             //06-07-14|0x0045
//***************************************************************************             //06-07-14|0x0046
//*******************************************************************************         //06-07-14|0x0047
#ifndef ARITH_DATA_Defined                                                                //06-07-14|0x0047
#define ARITH_DATA_Defined                                                                //06-07-14|0x0047
//-------------------------------------------------------------------------------         //06-07-14|0x0047
typedef struct {                                                                          //06-07-14|0x0047
  WORDS value;                                                                            //06-07-14|0x0047
  UINT  type;                                                                             //06-07-14|0x0047
  } ARITH_DATA, * ARITH_DATA_FAR;                                                         //06-07-14|0x0047
//-------------------------------------------------------------------------------         //06-07-14|0x0047
#endif                                                                                    //06-07-14|0x0047
//*******************************************************************************         //06-07-14|0x0048
#ifndef STRING_DATA_Defined                                                               //06-07-14|0x0048
#define STRING_DATA_Defined                                                               //06-07-14|0x0048
//-------------------------------------------------------------------------------         //06-07-14|0x0048
typedef struct {                                                                          //06-07-14|0x0048
  SCHAR   line[257];                                                                      //06-07-14|0x0048
  UINT    macro_line_no;                                                                  //06-07-14|0x0048
  UINT    type;                                                                           //06-07-14|0x0048
  UINT    start_col;                                                                      //06-07-14|0x0048
  UINT    start_call;                                                                     //06-07-14|0x0048
  SINT    length;                                                                         //06-07-14|0x0048
  SINT    position;                                                                       //06-07-14|0x0048
  SINT    column;                                                                         //06-07-14|0x0048
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-14|0x0048
//-------------------------------------------------------------------------------         //06-07-14|0x0048
#endif                                                                                    //06-07-14|0x0048
//*******************************************************************************         //06-07-14|0x0049
#ifndef TOKENS_Defined                                                                    //06-07-14|0x0049
#define TOKENS_Defined                                                                    //06-07-14|0x0049
//-------------------------------------------------------------------------------         //06-07-14|0x0049
typedef struct {                                                                          //06-07-14|0x0049
  UINT        no_tokens;                                                                  //06-07-14|0x0049
  STRING_DATA token[10];                                                                  //06-07-14|0x0049
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-14|0x0049
//-------------------------------------------------------------------------------         //06-07-14|0x0049
#endif                                                                                    //06-07-14|0x0049
#ifndef PROCESS_DATA_Defined                                                              //06-07-14|0x004a
#define PROCESS_DATA_Defined                                                              //06-07-14|0x004a
//-------------------------------------------------------------------------------         //06-07-14|0x004a
typedef struct {                                                                          //06-07-14|0x004a
  UINT          call_return_status;                                                       //06-07-14|0x004a
  UINT          call_return_run_flag;                                                     //06-07-14|0x004a
  UINT          call_return_state;                                                        //06-07-14|0x004a
  UINT          process_command;                                                          //06-07-14|0x004a
  UINT          debug_command;                                                            //06-07-14|0x004a
  SINT          out_buffer_state;                                                         //06-07-14|0x004a
  SINT          in_buffer_state;                                                          //06-07-14|0x004a
  SINT          flag_state;                                                               //06-07-14|0x004a
  SINT          rule_state;                                                               //06-07-14|0x004a
  UINT          process_state;                                                            //06-07-14|0x004a
  UINT          run_flag;                                                                 //06-07-14|0x004a
  UINT          status;                                                                   //06-07-14|0x004a
  STRING_DATA   class_name;                                                               //06-07-14|0x004a
  STRING_DATA   bridge_name;                                                              //06-07-14|0x004a
  STRING_DATA   buffer;                                                                   //06-07-14|0x004a
  STRING_DATA   utility_bridge;                                                           //06-07-14|0x004a
  STRING_DATA   macro_name;                                                               //06-07-14|0x004a
  STRING_DATA   debug_name;                                                               //06-07-14|0x004a
  STRING_DATA   results;                                                                  //06-07-14|0x004a
  TOKENS        dict;                                                                     //06-07-14|0x004a
  TOKENS        tokens;                                                                   //06-07-14|0x004a
  ARITH_DATA    parm_num;                                                                 //06-07-14|0x004a
  ARITH_DATA    result_num;                                                               //06-07-14|0x004a
  } PROCESS_DATA, * PROCESS_DATA_FAR;                                                     //06-07-14|0x004a
//-------------------------------------------------------------------------------         //06-07-14|0x004a
#endif                                                                                    //06-07-14|0x004a
//***************************************************************************             //06-07-14|0x004b
//*****************************************************************************           //06-07-14|0x004c
#ifndef FILE_CONTROL_Defined                                                              //06-07-14|0x004c
#define FILE_CONTROL_Defined                                                              //06-07-14|0x004c
//-----------------------------------------------------------------------------           //06-07-14|0x004c
typedef struct {                                                                          //06-07-14|0x004c
  UINT    state;                                                                          //06-07-14|0x004c
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-14|0x004c
  FILE *  stream;                                                                         //06-07-14|0x004c
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-14|0x004c
//-----------------------------------------------------------------------------           //06-07-14|0x004c
#endif                                                                                    //06-07-14|0x004c
//*****************************************************************************           //06-07-14|0x004d
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-14|0x004d
#define TEXT_FILE_DATA_Defined                                                            //06-07-14|0x004d
//-----------------------------------------------------------------------------           //06-07-14|0x004d
typedef struct {                                                                          //06-07-14|0x004d
  FILE_CONTROL    file_control;                                                           //06-07-14|0x004d
  STRING_DATA     string;                                                                 //06-07-14|0x004d
  UINT            read_state;                                                             //06-07-14|0x004d
  UINT            get_state;                                                              //06-07-14|0x004d
  UINT            put_state;                                                              //06-07-14|0x004d
  UINT            status;                                                                 //06-07-14|0x004d
  UINT            run_flag;                                                               //06-07-14|0x004d
  UINT            line_no;                                                                //06-07-14|0x004d
  SLONG           length;                                                                 //06-07-14|0x004d
  SLONG           next_position;                                                          //06-07-14|0x004d
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-14|0x004d
//-----------------------------------------------------------------------------           //06-07-14|0x004d
#endif                                                                                    //06-07-14|0x004d
//*******************************************************************************         //<----   |0x004e
#ifndef BINARY_FILE_DATA_Defined                                                          //<----   |0x004e
#define BINARY_FILE_DATA_Defined                                                          //<----   |0x004e
//-------------------------------------------------------------------------------         //<----   |0x004e
typedef struct {                                                                          //<----   |0x004e
  FILE_CONTROL    file_control;                                                           //<----   |0x004e
  SLONG           file_position;                                                          //<----   |0x004e
  SLONG           file_length;                                                            //<----   |0x004e
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //<----   |0x004e
//-------------------------------------------------------------------------------         //<----   |0x004e
#endif                                                                                    //<----   |0x004e
#ifndef MAILBOX_FILES_Defined                                                             //06-07-14|0x004f
#define MAILBOX_FILES_Defined                                                             //06-07-14|0x004f
//-------------------------------------------------------------------------------         //06-07-14|0x004f
typedef struct {                                                                          //06-07-14|0x004f
  UINT            status;                                                                 //06-07-14|0x004f
  STRING_DATA     name;                                                                   //06-07-14|0x004f
  } MAILBOX_FILES, * MAILBOX_FILES_FAR;                                                   //06-07-14|0x004f
//-------------------------------------------------------------------------------         //06-07-14|0x004f
#endif                                                                                    //06-07-14|0x004f
//*******************************************************************************         //06-07-14|0x004f
#ifndef TEXT_FILES_Defined                                                                //06-07-14|0x004f
#define TEXT_FILES_Defined                                                                //06-07-14|0x004f
//-------------------------------------------------------------------------------         //06-07-14|0x004f
typedef struct {                                                                          //06-07-14|0x004f
  TEXT_FILE_DATA  file;                                                                   //06-07-14|0x004f
  SCHAR           extent[48];                                                             //06-07-14|0x004f
  SCHAR           path[_MAX_PATH+1];                                                      //06-07-14|0x004f
  UINT            status;                                                                 //06-07-14|0x004f
  } TEXT_FILES, * TEXT_FILES_FAR;                                                         //06-07-14|0x004f
//-------------------------------------------------------------------------------         //06-07-14|0x004f
#endif                                                                                    //06-07-14|0x004f
//*******************************************************************************         //06-07-14|0x004f
#ifndef PROCESS_FILES_Defined                                                             //06-07-14|0x004f
#define PROCESS_FILES_Defined                                                             //06-07-14|0x004f
//-------------------------------------------------------------------------------         //06-07-14|0x004f
typedef struct {                                                                          //06-07-14|0x004f
  SINT              mailbox_file_no;                                                      //06-07-14|0x004f
  SINT              no_mailbox_files;                                                     //06-07-14|0x004f
  SCHAR             mailbox_path[_MAX_PATH+1];                                            //06-07-14|0x004f
  MAILBOX_FILES     mailbox_file[16];                                                     //06-07-14|0x004f
  UINT              no_output_files;                                                      //06-07-14|0x004f
  TEXT_FILES        output_file[16];                                                      //06-07-14|0x004f
  SCHAR             output_name[_MAX_PATH+1];                                             //06-07-14|0x004f
  UINT              no_input_files;                                                       //06-07-14|0x004f
  TEXT_FILES        input_file[16];                                                       //06-07-14|0x004f
  SCHAR             input_name[_MAX_PATH+1];                                              //06-07-14|0x004f
  ULONG             out_buffer_file_size;                                                 //06-07-14|0x004f
  BINARY_FILE_DATA  out_buffer_file;                                                      //06-07-14|0x004f
  TEXT_FILE_DATA    source_file;                                                          //06-07-14|0x004f
  SCHAR             source_extent[48];                                                    //06-07-14|0x004f
  } PROCESS_FILES, * PROCESS_FILES_FAR;                                                   //06-07-14|0x004f
//-------------------------------------------------------------------------------         //06-07-14|0x004f
#endif                                                                                    //06-07-14|0x004f
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
// CLASS PRECOPER DEFINITION                                                              //06-07-14|0x0057
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
class PRECOPER {                                                                          //06-07-14|0x0057
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
// CLASS PRECOPER DEFINITION                                                              //06-07-14|0x0057
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
    public:                                                                               //06-12-19|0x0086
      UINT proc_cmd(PROCESS_DATA_FAR,PROCESS_FILES_FAR,TOKENS_FAR);                       //06-12-19|0x0086
#define PrecOperProcCmd prec_oper.proc_cmd                                                //06-12-19|0x0088
    public:                                                                               //07-05-18|0x0443
      UINT call_initial(PROCESS_DATA_FAR);                                                //07-05-18|0x0443
#define PrecOperCallInitial prec_oper.call_initial                                        //07-05-18|0x0445
    private:                                                                              //07-05-18|0x0458
      UINT execute_call(PROCESS_DATA_FAR);                                                //07-05-18|0x0458
    private:                                                                              //07-05-21|0x04fe
      UINT macro_begin(PROCESS_DATA_FAR);                                                 //07-05-21|0x04fe
    private:                                                                              //06-09-28|0x055b
      UINT execute_return(PROCESS_DATA_FAR);                                              //06-09-28|0x055b
    private:                                                                              //07-05-24|0x05f1
      UINT utility_bridge(PROCESS_DATA_FAR);                                              //07-05-24|0x05f1
    private:                                                                              //07-05-18|0x060c
      UINT return_label(PROCESS_DATA_FAR,UINT);                                           //07-05-18|0x060c
    private:                                                                              //08-01-09|0x062e
      UINT auto_debug_on(PROCESS_DATA_FAR);                                               //08-01-09|0x062e
    private:                                                                              //08-01-08|0x065c
      UINT debug_on(PROCESS_DATA_FAR,STRING_DATA_FAR);                                    //08-01-08|0x065c
    private:                                                                              //08-01-08|0x0681
      UINT basic_debug_on(PROCESS_DATA_FAR);                                              //08-01-08|0x0681
    private:                                                                              //06-09-28|0x06b1
      UINT label_prepare(PROCESS_DATA_FAR);                                               //06-09-28|0x06b1
    private:                                                                              //07-05-18|0x06e6
      UINT class_search(PROCESS_DATA_FAR);                                                //07-05-18|0x06e6
    private:                                                                              //07-05-04|0x070f
      UINT dict_in(PROCESS_DATA_FAR,UINT);                                                //07-05-04|0x070f
    private:                                                                              //09-03-19|0x073c
      UINT string_in_reg(PROCESS_DATA_FAR);                                               //09-03-19|0x073c
    private:                                                                              //06-11-19|0x0758
      UINT numeric_in_data(PROCESS_DATA_FAR);                                             //06-11-19|0x0758
    private:                                                                              //10-08-27|0x0775
      UINT write_crlf(PROCESS_DATA_FAR);                                                  //10-08-27|0x0775
    private:                                                                              //10-08-27|0x07a2
      UINT write_output(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                              //10-08-27|0x07a2
    private:                                                                              //13-07-25|0x07c3
      UINT segment_out(PROCESS_DATA_FAR,PROCESS_FILES_FAR,UINT);                          //13-07-25|0x07c3
    private:                                                                              //check   |0x0817
      UINT segment_in(PROCESS_DATA_FAR,UINT);                                             //check   |0x0817
    private:                                                                              //10-08-31|0x0843
      UINT buffer_out_utility(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                        //10-08-31|0x0843
    private:                                                                              //10-08-31|0x0886
      UINT load_buffer(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                               //10-08-31|0x0886
    private:                                                                              //10-08-31|0x08ac
      UINT append_buffer(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                             //10-08-31|0x08ac
    private:                                                                              //10-09-01|0x08d2
      UINT write_buffer(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                              //10-09-01|0x08d2
    private:                                                                              //06-09-29|0x0907
      UINT numeric_in_2(PROCESS_DATA_FAR);                                                //06-09-29|0x0907
    private:                                                                              //06-10-09|0x0928
      UINT string_in_2(PROCESS_DATA_FAR);                                                 //06-10-09|0x0928
    private:                                                                              //09-03-19|0x0943
      UINT string_numeric_in_2(PROCESS_DATA_FAR);                                         //09-03-19|0x0943
    private:                                                                              //06-09-29|0x095f
      UINT string_numeric_in_3(PROCESS_DATA_FAR,UINT);                                    //06-09-29|0x095f
    private:                                                                              //09-03-19|0x097b
      UINT string_numeric_in_4(PROCESS_DATA_FAR);                                         //09-03-19|0x097b
    private:                                                                              //09-03-19|0x0997
      UINT basic_reg_store(PROCESS_DATA_FAR);                                             //09-03-19|0x0997
    private:                                                                              //09-03-19|0x09b5
      ULONG find_char(STRING_DATA_FAR,SCHAR);                                             //09-03-19|0x09b5
    private:                                                                              //06-09-28|0x09dc
      UINT basic_string_type(PROCESS_DATA_FAR);                                           //06-09-28|0x09dc
    private:                                                                              //06-09-29|0x09fe
      UINT numeric_reg_out(PROCESS_DATA_FAR);                                             //06-09-29|0x09fe
    private:                                                                              //09-06-02|0x0a14
      UINT get_postoffice_no(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                         //09-06-02|0x0a14
    private:                                                                              //09-03-11|0x0a41
      UINT delete_postoffice(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                         //09-03-11|0x0a41
    private:                                                                              //09-03-11|0x0a80
      UINT open_mailbox(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                              //09-03-11|0x0a80
    private:                                                                              //09-03-10|0x0ac7
      UINT create_postoffice(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                         //09-03-10|0x0ac7
    private:                                                                              //09-03-11|0x0af9
      UINT create_po_box(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                             //09-03-11|0x0af9
    private:                                                                              //09-03-13|0x0b2b
      UINT send_mail(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                                 //09-03-13|0x0b2b
    private:                                                                              //09-09-17|0x0b5e
      UINT empty_po_box(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                              //09-09-17|0x0b5e
    private:                                                                              //09-03-16|0x0b92
      UINT get_mail(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                                  //09-03-16|0x0b92
    private:                                                                              //09-03-17|0x0bc8
      UINT postoffice_exists(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                         //09-03-17|0x0bc8
    private:                                                                              //09-03-17|0x0c01
      UINT po_box_exists(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                             //09-03-17|0x0c01
    private:                                                                              //09-03-17|0x0c3a
      UINT po_box_empty(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                              //09-03-17|0x0c3a
    private:                                                                              //09-03-11|0x0c71
      UINT close_mailbox(PROCESS_DATA_FAR,PROCESS_FILES_FAR);                             //09-03-11|0x0c71
    private:                                                                              //06-09-26|0x0caa
      UINT debug_manager(PROCESS_DATA_FAR,UINT);                                          //06-09-26|0x0caa
    private:                                                                              //06-12-19|0x0ce7
      UINT checkout_pause(PROCESS_DATA_FAR,SCHAR_FAR);                                    //06-12-19|0x0ce7
    public:                                                                               //06-07-14|0x0d00
      UINT precoper_test_reset(void);                                                     //06-07-14|0x0d00
#define PrecOperTestReset prec_oper.precoper_test_reset                                   //06-07-14|0x0d00
    public:                                                                               //06-07-14|0x0d02
      UINT precoper_test_read(void);                                                      //06-07-14|0x0d02
#define PrecOperTestRead prec_oper.precoper_test_read                                     //06-07-14|0x0d02
    public:                                                                               //06-07-14|0x0d04
      UINT precoper_test_write(void);                                                     //06-07-14|0x0d04
#define PrecOperTestWrite prec_oper.precoper_test_write                                   //06-07-14|0x0d04
    public:                                                                               //06-07-14|0x0d06
      UINT precoper_test_report(void);                                                    //06-07-14|0x0d06
#define PrecOperTestReport prec_oper.precoper_test_report                                 //06-07-14|0x0d06
    public:                                                                               //06-07-14|0x0d0e
      PRECOPER();                                                                         //06-07-14|0x0d0e
  };                                                                                      //10-29-97|0x0d19
extern class PRECOPER prec_oper;                                                          //98-12-29|0x0d19
//*******************************************************************************         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
//****                       END OF FILE                                     ****         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
#endif                                                                                    //05-24-97|0x0d1a
