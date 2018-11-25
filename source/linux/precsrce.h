//*****************************************************************************           //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
// PRECEDENCE SOURCE GENERATOR                                                            //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  The purpose of this program as well as instructions regarding its use is              //05-14-97|0x001e
//  defined in the associated manual.                                                     //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  This program is free software; you can redistribute it and/or modify                  //05-14-97|0x001e
//  it under the terms of the GNU General Public License as published by                  //05-14-97|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //05-14-97|0x001e
//  (at your option) any later version.                                                   //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
//  This program is distributed in the hope that it will be useful,                       //05-14-97|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //05-14-97|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //05-14-97|0x001e
//  GNU General Public License for more details.                                          //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
//  You should have received a copy of the GNU General Public License                     //05-14-97|0x001e
//  along with this program; if not, write to the Free Software                           //05-14-97|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //05-14-97|0x001e
//  USA                                                                                   //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  For further information, please contact Robert Adams:                                 //05-14-97|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //05-14-97|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //05-14-97|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
#ifndef precsrce_h                                                                        //05-14-97|0x001f
#define precsrce_h                                                                        //05-14-97|0x001f
//***************************************************************************             //06-07-12|0x0041
//***************************************************************************             //06-07-12|0x0042
//******                                                               ******             //06-07-12|0x0043
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0044
//******                                                               ******             //06-07-12|0x0045
//***************************************************************************             //06-07-12|0x0046
//***************************************************************************             //06-07-12|0x0047
//*******************************************************************************         //06-07-12|0x0048
#ifndef ARITH_DATA_Defined                                                                //06-07-12|0x0048
#define ARITH_DATA_Defined                                                                //06-07-12|0x0048
//-------------------------------------------------------------------------------         //06-07-12|0x0048
typedef struct {                                                                          //06-07-12|0x0048
  WORDS value;                                                                            //06-07-12|0x0048
  UINT  type;                                                                             //06-07-12|0x0048
  } ARITH_DATA, * ARITH_DATA_FAR;                                                         //06-07-12|0x0048
//-------------------------------------------------------------------------------         //06-07-12|0x0048
#endif                                                                                    //06-07-12|0x0048
//*******************************************************************************         //06-07-12|0x0049
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x0049
#define STRING_DATA_Defined                                                               //06-07-12|0x0049
//-------------------------------------------------------------------------------         //06-07-12|0x0049
typedef struct {                                                                          //06-07-12|0x0049
  SCHAR   line[257];                                                                      //06-07-12|0x0049
  UINT    macro_line_no;                                                                  //06-07-12|0x0049
  UINT    type;                                                                           //06-07-12|0x0049
  UINT    start_col;                                                                      //06-07-12|0x0049
  UINT    start_call;                                                                     //06-07-12|0x0049
  SINT    length;                                                                         //06-07-12|0x0049
  SINT    position;                                                                       //06-07-12|0x0049
  SINT    column;                                                                         //06-07-12|0x0049
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x0049
//-------------------------------------------------------------------------------         //06-07-12|0x0049
#endif                                                                                    //06-07-12|0x0049
//*******************************************************************************         //06-07-12|0x004a
#ifndef TOKENS_Defined                                                                    //06-07-12|0x004a
#define TOKENS_Defined                                                                    //06-07-12|0x004a
//-------------------------------------------------------------------------------         //06-07-12|0x004a
typedef struct {                                                                          //06-07-12|0x004a
  UINT        no_tokens;                                                                  //06-07-12|0x004a
  STRING_DATA token[10];                                                                  //06-07-12|0x004a
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x004a
//-------------------------------------------------------------------------------         //06-07-12|0x004a
#endif                                                                                    //06-07-12|0x004a
#ifndef PROCESS_DATA_Defined                                                              //06-07-12|0x004b
#define PROCESS_DATA_Defined                                                              //06-07-12|0x004b
//-------------------------------------------------------------------------------         //06-07-12|0x004b
typedef struct {                                                                          //06-07-12|0x004b
  UINT          call_return_status;                                                       //06-07-12|0x004b
  UINT          call_return_run_flag;                                                     //06-07-12|0x004b
  UINT          call_return_state;                                                        //06-07-12|0x004b
  UINT          process_command;                                                          //06-07-12|0x004b
  UINT          debug_command;                                                            //06-07-12|0x004b
  SINT          out_buffer_state;                                                         //06-07-12|0x004b
  SINT          in_buffer_state;                                                          //06-07-12|0x004b
  SINT          flag_state;                                                               //06-07-12|0x004b
  SINT          rule_state;                                                               //06-07-12|0x004b
  UINT          process_state;                                                            //06-07-12|0x004b
  UINT          run_flag;                                                                 //06-07-12|0x004b
  UINT          status;                                                                   //06-07-12|0x004b
  STRING_DATA   class_name;                                                               //06-07-12|0x004b
  STRING_DATA   bridge_name;                                                              //06-07-12|0x004b
  STRING_DATA   buffer;                                                                   //06-07-12|0x004b
  STRING_DATA   utility_bridge;                                                           //06-07-12|0x004b
  STRING_DATA   macro_name;                                                               //06-07-12|0x004b
  STRING_DATA   debug_name;                                                               //06-07-12|0x004b
  STRING_DATA   results;                                                                  //06-07-12|0x004b
  TOKENS        dict;                                                                     //06-07-12|0x004b
  TOKENS        tokens;                                                                   //06-07-12|0x004b
  ARITH_DATA    parm_num;                                                                 //06-07-12|0x004b
  ARITH_DATA    result_num;                                                               //06-07-12|0x004b
  } PROCESS_DATA, * PROCESS_DATA_FAR;                                                     //06-07-12|0x004b
//-------------------------------------------------------------------------------         //06-07-12|0x004b
#endif                                                                                    //06-07-12|0x004b
//***************************************************************************             //06-07-12|0x004c
//*****************************************************************************           //06-07-12|0x004d
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x004d
#define FILE_CONTROL_Defined                                                              //06-07-12|0x004d
//-----------------------------------------------------------------------------           //06-07-12|0x004d
typedef struct {                                                                          //06-07-12|0x004d
  UINT    state;                                                                          //06-07-12|0x004d
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x004d
  FILE *  stream;                                                                         //06-07-12|0x004d
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x004d
//-----------------------------------------------------------------------------           //06-07-12|0x004d
#endif                                                                                    //06-07-12|0x004d
//*****************************************************************************           //06-07-12|0x004e
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-12|0x004e
#define TEXT_FILE_DATA_Defined                                                            //06-07-12|0x004e
//-----------------------------------------------------------------------------           //06-07-12|0x004e
typedef struct {                                                                          //06-07-12|0x004e
  FILE_CONTROL    file_control;                                                           //06-07-12|0x004e
  STRING_DATA     string;                                                                 //06-07-12|0x004e
  UINT            read_state;                                                             //06-07-12|0x004e
  UINT            get_state;                                                              //06-07-12|0x004e
  UINT            put_state;                                                              //06-07-12|0x004e
  UINT            status;                                                                 //06-07-12|0x004e
  UINT            run_flag;                                                               //06-07-12|0x004e
  UINT            line_no;                                                                //06-07-12|0x004e
  SLONG           length;                                                                 //06-07-12|0x004e
  SLONG           next_position;                                                          //06-07-12|0x004e
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-12|0x004e
//-----------------------------------------------------------------------------           //06-07-12|0x004e
#endif                                                                                    //06-07-12|0x004e
//*******************************************************************************         //<----   |0x004f
#ifndef BINARY_FILE_DATA_Defined                                                          //<----   |0x004f
#define BINARY_FILE_DATA_Defined                                                          //<----   |0x004f
//-------------------------------------------------------------------------------         //<----   |0x004f
typedef struct {                                                                          //<----   |0x004f
  FILE_CONTROL    file_control;                                                           //<----   |0x004f
  SLONG           file_position;                                                          //<----   |0x004f
  SLONG           file_length;                                                            //<----   |0x004f
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //<----   |0x004f
//-------------------------------------------------------------------------------         //<----   |0x004f
#endif                                                                                    //<----   |0x004f
#ifndef MAILBOX_FILES_Defined                                                             //06-07-12|0x0050
#define MAILBOX_FILES_Defined                                                             //06-07-12|0x0050
//-------------------------------------------------------------------------------         //06-07-12|0x0050
typedef struct {                                                                          //06-07-12|0x0050
  UINT            status;                                                                 //06-07-12|0x0050
  STRING_DATA     name;                                                                   //06-07-12|0x0050
  } MAILBOX_FILES, * MAILBOX_FILES_FAR;                                                   //06-07-12|0x0050
//-------------------------------------------------------------------------------         //06-07-12|0x0050
#endif                                                                                    //06-07-12|0x0050
//*******************************************************************************         //06-07-12|0x0050
#ifndef TEXT_FILES_Defined                                                                //06-07-12|0x0050
#define TEXT_FILES_Defined                                                                //06-07-12|0x0050
//-------------------------------------------------------------------------------         //06-07-12|0x0050
typedef struct {                                                                          //06-07-12|0x0050
  TEXT_FILE_DATA  file;                                                                   //06-07-12|0x0050
  SCHAR           extent[48];                                                             //06-07-12|0x0050
  SCHAR           path[_MAX_PATH+1];                                                      //06-07-12|0x0050
  UINT            status;                                                                 //06-07-12|0x0050
  } TEXT_FILES, * TEXT_FILES_FAR;                                                         //06-07-12|0x0050
//-------------------------------------------------------------------------------         //06-07-12|0x0050
#endif                                                                                    //06-07-12|0x0050
//*******************************************************************************         //06-07-12|0x0050
#ifndef PROCESS_FILES_Defined                                                             //06-07-12|0x0050
#define PROCESS_FILES_Defined                                                             //06-07-12|0x0050
//-------------------------------------------------------------------------------         //06-07-12|0x0050
typedef struct {                                                                          //06-07-12|0x0050
  SINT              mailbox_file_no;                                                      //06-07-12|0x0050
  SINT              no_mailbox_files;                                                     //06-07-12|0x0050
  SCHAR             mailbox_path[_MAX_PATH+1];                                            //06-07-12|0x0050
  MAILBOX_FILES     mailbox_file[16];                                                     //06-07-12|0x0050
  UINT              no_output_files;                                                      //06-07-12|0x0050
  TEXT_FILES        output_file[16];                                                      //06-07-12|0x0050
  SCHAR             output_name[_MAX_PATH+1];                                             //06-07-12|0x0050
  UINT              no_input_files;                                                       //06-07-12|0x0050
  TEXT_FILES        input_file[16];                                                       //06-07-12|0x0050
  SCHAR             input_name[_MAX_PATH+1];                                              //06-07-12|0x0050
  ULONG             out_buffer_file_size;                                                 //06-07-12|0x0050
  BINARY_FILE_DATA  out_buffer_file;                                                      //06-07-12|0x0050
  TEXT_FILE_DATA    source_file;                                                          //06-07-12|0x0050
  SCHAR             source_extent[48];                                                    //06-07-12|0x0050
  } PROCESS_FILES, * PROCESS_FILES_FAR;                                                   //06-07-12|0x0050
//-------------------------------------------------------------------------------         //06-07-12|0x0050
#endif                                                                                    //06-07-12|0x0050
//*******************************************************************************         //10-29-97|0x0058
//*******************************************************************************         //10-29-97|0x0058
// CLASS PRECSRCE DEFINITION                                                              //06-07-12|0x0058
//*******************************************************************************         //10-29-97|0x0058
//*******************************************************************************         //10-29-97|0x0058
class PRECSRCE {                                                                          //06-07-12|0x0058
//*******************************************************************************         //10-29-97|0x0058
//*******************************************************************************         //10-29-97|0x0058
// CLASS PRECSRCE DEFINITION                                                              //06-07-12|0x0058
//*******************************************************************************         //10-29-97|0x0058
//*******************************************************************************         //10-29-97|0x0058
    private:                                                                              //10-27-97|0x0060
      PROCESS_DATA_FAR process_addr;                                                      //10-27-97|0x0060
    public:                                                                               //06-07-12|0x0085
      UINT precsrce_allocate(void);                                                       //06-07-12|0x0085
#define PrecsrceAllocate prec_source.precsrce_allocate                                    //06-07-12|0x0086
    public:                                                                               //06-07-12|0x00a1
      UINT precsrce_free(void);                                                           //06-07-12|0x00a1
#define PrecsrceFree prec_source.precsrce_free                                            //06-07-12|0x00a2
    public:                                                                               //07-06-06|0x00b9
      UINT precsrce_process(PROCESS_FILES_FAR,TOKENS_FAR,UINT);                           //07-06-06|0x00b9
#define PrecsrceProcess prec_source.precsrce_process                                      //06-12-17|0x00bb
    private:                                                                              //06-09-26|0x0178
      UINT initial_process(void);                                                         //06-09-26|0x0178
    private:                                                                              //06-09-26|0x0195
      UINT read_source(PROCESS_FILES_FAR);                                                //06-09-26|0x0195
    private:                                                                              //06-09-26|0x01bd
      UINT initial_step(void);                                                            //06-09-26|0x01bd
    private:                                                                              //06-10-09|0x01dc
      UINT check_stack(void);                                                             //06-10-09|0x01dc
    public:                                                                               //04-10-05|0x0205
      UINT precsrce_test_reset(void);                                                     //04-10-05|0x0205
#define PrecSrceTestReset prec_source.precsrce_test_reset                                 //04-10-05|0x0205
    public:                                                                               //04-10-05|0x0207
      UINT precsrce_test_read(void);                                                      //04-10-05|0x0207
#define PrecSrceTestRead prec_source.precsrce_test_read                                   //04-10-05|0x0207
    public:                                                                               //04-10-05|0x0209
      UINT precsrce_test_write(void);                                                     //04-10-05|0x0209
#define PrecSrceTestWrite prec_source.precsrce_test_write                                 //04-10-05|0x0209
    public:                                                                               //04-10-05|0x020b
      UINT precsrce_test_report(void);                                                    //04-10-05|0x020b
#define PrecSrceTestReport prec_source.precsrce_test_report                               //04-10-05|0x020b
    public:                                                                               //04-10-05|0x0213
      PRECSRCE();                                                                         //04-10-05|0x0213
  };                                                                                      //10-29-97|0x021d
extern class PRECSRCE prec_source;                                                        //98-12-29|0x021d
//*******************************************************************************         //05-24-97|0x021e
//*******************************************************************************         //05-24-97|0x021e
//****                       END OF FILE                                     ****         //05-24-97|0x021e
//*******************************************************************************         //05-24-97|0x021e
//*******************************************************************************         //05-24-97|0x021e
#endif                                                                                    //05-24-97|0x021e
