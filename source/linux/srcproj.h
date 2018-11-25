//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
// LIBRARY-SOURCE MAIN ENGINE                                                             //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x001b
//  defined in the associated manual.                                                     //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x001b
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x001b
//  (at your option) any later version.                                                   //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x001b
//  GNU General Public License for more details.                                          //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x001b
//  along with this program; if not, write to the Free Software                           //06-07-12|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x001b
//  USA                                                                                   //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  For further information, please contact Robert Adams:                                 //06-07-12|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
#ifndef srcproj_h                                                                         //06-07-12|0x001c
#define srcproj_h                                                                         //06-07-12|0x001c
//***************************************************************************             //06-07-12|0x0043
//***************************************************************************             //06-07-12|0x0044
//******                                                               ******             //06-07-12|0x0045
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0046
//******                                                               ******             //06-07-12|0x0047
//***************************************************************************             //06-07-12|0x0048
//***************************************************************************             //06-07-12|0x0049
//*******************************************************************************         //06-07-12|0x004a
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x004a
#define STRING_DATA_Defined                                                               //06-07-12|0x004a
//-------------------------------------------------------------------------------         //06-07-12|0x004a
typedef struct {                                                                          //06-07-12|0x004a
  SCHAR   line[257];                                                                      //06-07-12|0x004a
  UINT    macro_line_no;                                                                  //06-07-12|0x004a
  UINT    type;                                                                           //06-07-12|0x004a
  UINT    start_col;                                                                      //06-07-12|0x004a
  UINT    start_call;                                                                     //06-07-12|0x004a
  SINT    length;                                                                         //06-07-12|0x004a
  SINT    position;                                                                       //06-07-12|0x004a
  SINT    column;                                                                         //06-07-12|0x004a
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x004a
//-------------------------------------------------------------------------------         //06-07-12|0x004a
#endif                                                                                    //06-07-12|0x004a
//*******************************************************************************         //06-07-12|0x004b
#ifndef TOKENS_Defined                                                                    //06-07-12|0x004b
#define TOKENS_Defined                                                                    //06-07-12|0x004b
//-------------------------------------------------------------------------------         //06-07-12|0x004b
typedef struct {                                                                          //06-07-12|0x004b
  UINT        no_tokens;                                                                  //06-07-12|0x004b
  STRING_DATA token[10];                                                                  //06-07-12|0x004b
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x004b
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
//***************************************************************************             //06-07-12|0x0050
#ifndef MAILBOX_FILES_Defined                                                             //06-07-12|0x0051
#define MAILBOX_FILES_Defined                                                             //06-07-12|0x0051
//-------------------------------------------------------------------------------         //06-07-12|0x0051
typedef struct {                                                                          //06-07-12|0x0051
  UINT            status;                                                                 //06-07-12|0x0051
  STRING_DATA     name;                                                                   //06-07-12|0x0051
  } MAILBOX_FILES, * MAILBOX_FILES_FAR;                                                   //06-07-12|0x0051
//-------------------------------------------------------------------------------         //06-07-12|0x0051
#endif                                                                                    //06-07-12|0x0051
//*******************************************************************************         //06-07-12|0x0051
#ifndef TEXT_FILES_Defined                                                                //06-07-12|0x0051
#define TEXT_FILES_Defined                                                                //06-07-12|0x0051
//-------------------------------------------------------------------------------         //06-07-12|0x0051
typedef struct {                                                                          //06-07-12|0x0051
  TEXT_FILE_DATA  file;                                                                   //06-07-12|0x0051
  SCHAR           extent[48];                                                             //06-07-12|0x0051
  SCHAR           path[_MAX_PATH+1];                                                      //06-07-12|0x0051
  UINT            status;                                                                 //06-07-12|0x0051
  } TEXT_FILES, * TEXT_FILES_FAR;                                                         //06-07-12|0x0051
//-------------------------------------------------------------------------------         //06-07-12|0x0051
#endif                                                                                    //06-07-12|0x0051
//*******************************************************************************         //06-07-12|0x0051
#ifndef PROCESS_FILES_Defined                                                             //06-07-12|0x0051
#define PROCESS_FILES_Defined                                                             //06-07-12|0x0051
//-------------------------------------------------------------------------------         //06-07-12|0x0051
typedef struct {                                                                          //06-07-12|0x0051
  SINT              mailbox_file_no;                                                      //06-07-12|0x0051
  SINT              no_mailbox_files;                                                     //06-07-12|0x0051
  SCHAR             mailbox_path[_MAX_PATH+1];                                            //06-07-12|0x0051
  MAILBOX_FILES     mailbox_file[16];                                                     //06-07-12|0x0051
  UINT              no_output_files;                                                      //06-07-12|0x0051
  TEXT_FILES        output_file[16];                                                      //06-07-12|0x0051
  SCHAR             output_name[_MAX_PATH+1];                                             //06-07-12|0x0051
  UINT              no_input_files;                                                       //06-07-12|0x0051
  TEXT_FILES        input_file[16];                                                       //06-07-12|0x0051
  SCHAR             input_name[_MAX_PATH+1];                                              //06-07-12|0x0051
  ULONG             out_buffer_file_size;                                                 //06-07-12|0x0051
  BINARY_FILE_DATA  out_buffer_file;                                                      //06-07-12|0x0051
  TEXT_FILE_DATA    source_file;                                                          //06-07-12|0x0051
  SCHAR             source_extent[48];                                                    //06-07-12|0x0051
  } PROCESS_FILES, * PROCESS_FILES_FAR;                                                   //06-07-12|0x0051
//-------------------------------------------------------------------------------         //06-07-12|0x0051
#endif                                                                                    //06-07-12|0x0051
#ifndef SOURCE_PROJECT_Defined                                                            //06-07-12|0x0052
#define SOURCE_PROJECT_Defined                                                            //06-07-12|0x0052
//-----------------------------------------------------------------------------           //06-07-12|0x0052
typedef struct {                                                                          //06-07-12|0x0052
  UINT            state;                                                                  //06-07-12|0x0052
  UINT            status;                                                                 //06-07-12|0x0052
  UINT            run_flag;                                                               //06-07-12|0x0052
  UINT            error_control;                                                          //06-07-12|0x0052
  TEXT_FILE_DATA  project_file;                                                           //06-07-12|0x0052
  PROCESS_FILES   files;                                                                  //06-07-12|0x0052
  STRING_DATA     work;                                                                   //06-07-12|0x0052
  STRING_DATA     lib_name;                                                               //06-07-12|0x0052
  TOKENS          tokens;                                                                 //06-07-12|0x0052
  TOKENS          arguments;                                                              //06-07-12|0x0052
  ULONG           out_time;                                                               //06-07-12|0x0052
  ULONG           in_time;                                                                //06-07-12|0x0052
  } SOURCE_PROJECT, * SOURCE_PROJECT_FAR;                                                 //06-07-12|0x0052
//-----------------------------------------------------------------------------           //06-07-12|0x0052
#endif                                                                                    //06-07-12|0x0052
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
// CLASS SOURCEPROJ DEFINITION                                                            //06-07-12|0x005a
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
class SOURCEPROJ {                                                                        //06-07-12|0x005a
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
// CLASS SOURCEPROJ DEFINITION                                                            //06-07-12|0x005a
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
    private:                                                                              //10-27-97|0x0062
      SOURCE_PROJECT_FAR source_project_addr;                                             //10-27-97|0x0062
    private:                                                                              //10-27-97|0x0063
      UINT display_flag;                                                                  //10-27-97|0x0063
    public:                                                                              //06-07-12|0x0089
      UINT srcproj_allocate(void);                                                       //06-07-12|0x0089
#define SrcProjAllocate source_proj.srcproj_allocate                                     //06-07-12|0x008a
    public:                                                                               //06-07-12|0x00a5
      UINT srcproj_free(void);                                                            //06-07-12|0x00a5
#define SrcProjFree source_proj.srcproj_free                                              //06-07-12|0x00a6
    public:                                                                               //09-03-27|0x00c2
       UINT srcproj_process(TOKENS_FAR,ULONG,TOKENS_FAR,UINT_FAR);                        //09-03-27|0x00c2
#define SrcProjProcess source_proj.srcproj_process                                        //07-01-30|0x00c4
    private:                                                                              //10-05-15|0x02cd
      UINT enter_input_names(STRING_DATA_FAR);                                            //10-05-15|0x02cd
    private:                                                                              //07-03-21|0x02f1
      UINT enter_name(TEXT_FILE_DATA_FAR,STRING_DATA_FAR,SCHAR_FAR);                      //07-03-21|0x02f1
    private:                                                                              //<----   |0x0309
      UINT initial_buf_out(BINARY_FILE_DATA_FAR,STRING_DATA_FAR,SCHAR_FAR);               //<----   |0x0309
    private:                                                                              //<----   |0x0322
      UINT close_buffer_out(BINARY_FILE_DATA_FAR);                                        //<----   |0x0322
    private:                                                                              //10-05-15|0x033b
      UINT input_file_times(void);                                                        //10-05-15|0x033b
    private:                                                                              //06-09-11|0x035b
      UINT file_time(TEXT_FILE_DATA_FAR);                                                 //06-09-11|0x035b
    private:                                                                              //10-05-15|0x0372
      UINT open_input_files(void);                                                        //10-05-15|0x0372
    private:                                                                              //06-09-12|0x038d
      UINT open_project(TEXT_FILE_DATA_FAR);                                              //06-09-12|0x038d
    private:                                                                              //06-09-12|0x03af
      UINT read_project(TEXT_FILE_DATA_FAR);                                              //06-09-12|0x03af
    private:                                                                              //06-09-12|0x03d5
      UINT text_prepare(void);                                                            //06-09-12|0x03d5
    private:                                                                              //09-03-27|0x03f2
      UINT update_task_no(UINT_FAR);                                                      //09-03-27|0x03f2
    private:                                                                              //06-09-13|0x0410
      UINT open_library(void);                                                            //06-09-13|0x0410
    private:                                                                              //06-09-13|0x0426
      UINT load_srce_extent(void);                                                        //06-09-13|0x0426
    private:                                                                              //07-03-23|0x0440
      UINT load_out_path_ext(void);                                                       //07-03-23|0x0440
    private:                                                                              //09-03-10|0x0463
      UINT load_mailbox(UINT);                                                            //09-03-10|0x0463
    private:                                                                              //10-01-03|0x04b2
      UINT mailbox_dates(void);                                                           //10-01-03|0x04b2
    private:                                                                              //07-06-06|0x0513
      UINT error_control(SCHAR_FAR,UINT);                                                 //07-06-06|0x0513
    private:                                                                              //10-05-15|0x052a
      UINT load_in_path_ext(void);                                                        //10-05-15|0x052a
    private:                                                                              //06-09-13|0x054d
      UINT uncond_update(void);                                                           //06-09-13|0x054d
    private:                                                                              //06-09-25|0x0564
      UINT output_names(void);                                                            //06-09-25|0x0564
    private:                                                                              //07-01-30|0x0584
      UINT output_dates(void);                                                            //07-01-30|0x0584
    private:                                                                              //06-09-26|0x05a3
      UINT push_call(void);                                                               //06-09-26|0x05a3
    private:                                                                              //06-09-30|0x05ca
      UINT pop_call(void);                                                                //06-09-30|0x05ca
    private:                                                                              //06-09-12|0x05ef
      UINT close_project(TEXT_FILE_DATA_FAR);                                             //06-09-12|0x05ef
    private:                                                                              //check   |0x0606
      UINT test_output_status(void);                                                      //check   |0x0606
    private:                                                                              //08-04-18|0x0628
      UINT close_output(void);                                                            //08-04-18|0x0628
    private:                                                                              //10-05-15|0x064b
      UINT close_text(void);                                                              //10-05-15|0x064b
    private:                                                                              //10-01-03|0x066e
      UINT mailbox_finish(void);                                                          //10-01-03|0x066e
    private:                                                                              //10-01-03|0x06c6
      UINT mailbox_complete(void);                                                        //10-01-03|0x06c6
    public:                                                                               //06-07-14|0x0713
      UINT srcproj_test_reset(void);                                                      //06-07-14|0x0713
#define SrcProjTestReset source_proj.srcproj_test_reset                                   //06-07-14|0x0713
    public:                                                                               //06-07-14|0x0715
      UINT srcproj_test_read(void);                                                       //06-07-14|0x0715
#define SrcProjTestRead source_proj.srcproj_test_read                                     //06-07-14|0x0715
    public:                                                                               //06-07-14|0x0717
      UINT srcproj_test_write(void);                                                      //06-07-14|0x0717
#define SrcProjTestWrite source_proj.srcproj_test_write                                   //06-07-14|0x0717
    public:                                                                               //06-07-14|0x0719
      UINT srcproj_test_report(void);                                                     //06-07-14|0x0719
#define SrcProjTestReport source_proj.srcproj_test_report                                 //06-07-14|0x0719
    public:                                                                               //06-07-12|0x0721
      SOURCEPROJ();                                                                       //06-07-12|0x0721
  };                                                                                      //10-29-97|0x072b
extern class SOURCEPROJ source_proj;                                                      //98-12-29|0x072b
//*******************************************************************************         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
//****                       END OF FILE                                     ****         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
#endif                                                                                    //05-24-97|0x072c
