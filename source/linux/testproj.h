//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
// TEST PROJECT                                                                           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x0008
//  defined in the associated manual.                                                     //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x0008
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x0008
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x0008
//  (at your option) any later version.                                                   //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x0008
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x0008
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x0008
//  GNU General Public License for more details.                                          //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x0008
//  along with this program; if not, write to the Free Software                           //06-07-12|0x0008
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x0008
//  USA                                                                                   //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  For further information, please contact Robert Adams:                                 //06-07-12|0x0008
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x0008
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x0008
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
#ifndef testproj_h                                                                        //06-07-12|0x000b
#define testproj_h                                                                        //06-07-12|0x000b
//***************************************************************************             //06-07-12|0x002f
//***************************************************************************             //06-07-12|0x0030
//******                                                               ******             //06-07-12|0x0031
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0032
//******                                                               ******             //06-07-12|0x0033
//***************************************************************************             //06-07-12|0x0034
//***************************************************************************             //06-07-12|0x0035
//*******************************************************************************         //06-07-12|0x0036
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x0036
#define STRING_DATA_Defined                                                               //06-07-12|0x0036
//-------------------------------------------------------------------------------         //06-07-12|0x0036
typedef struct {                                                                          //06-07-12|0x0036
  SCHAR   line[257];                                                                      //06-07-12|0x0036
  UINT    macro_line_no;                                                                  //06-07-12|0x0036
  UINT    type;                                                                           //06-07-12|0x0036
  UINT    start_col;                                                                      //06-07-12|0x0036
  UINT    start_call;                                                                     //06-07-12|0x0036
  SINT    length;                                                                         //06-07-12|0x0036
  SINT    position;                                                                       //06-07-12|0x0036
  SINT    column;                                                                         //06-07-12|0x0036
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x0036
//-------------------------------------------------------------------------------         //06-07-12|0x0036
#endif                                                                                    //06-07-12|0x0036
//*******************************************************************************         //06-07-12|0x0037
#ifndef TOKENS_Defined                                                                    //06-07-12|0x0037
#define TOKENS_Defined                                                                    //06-07-12|0x0037
//-------------------------------------------------------------------------------         //06-07-12|0x0037
typedef struct {                                                                          //06-07-12|0x0037
  UINT        no_tokens;                                                                  //06-07-12|0x0037
  STRING_DATA token[10];                                                                  //06-07-12|0x0037
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x0037
//-------------------------------------------------------------------------------         //06-07-12|0x0037
#endif                                                                                    //06-07-12|0x0037
//***************************************************************************             //06-07-12|0x0038
//*****************************************************************************           //06-07-12|0x0039
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x0039
#define FILE_CONTROL_Defined                                                              //06-07-12|0x0039
//-----------------------------------------------------------------------------           //06-07-12|0x0039
typedef struct {                                                                          //06-07-12|0x0039
  UINT    state;                                                                          //06-07-12|0x0039
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x0039
  FILE *  stream;                                                                         //06-07-12|0x0039
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x0039
//-----------------------------------------------------------------------------           //06-07-12|0x0039
#endif                                                                                    //06-07-12|0x0039
//*****************************************************************************           //06-07-12|0x003a
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-12|0x003a
#define TEXT_FILE_DATA_Defined                                                            //06-07-12|0x003a
//-----------------------------------------------------------------------------           //06-07-12|0x003a
typedef struct {                                                                          //06-07-12|0x003a
  FILE_CONTROL    file_control;                                                           //06-07-12|0x003a
  STRING_DATA     string;                                                                 //06-07-12|0x003a
  UINT            read_state;                                                             //06-07-12|0x003a
  UINT            get_state;                                                              //06-07-12|0x003a
  UINT            put_state;                                                              //06-07-12|0x003a
  UINT            status;                                                                 //06-07-12|0x003a
  UINT            run_flag;                                                               //06-07-12|0x003a
  UINT            line_no;                                                                //06-07-12|0x003a
  SLONG           length;                                                                 //06-07-12|0x003a
  SLONG           next_position;                                                          //06-07-12|0x003a
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-12|0x003a
//-----------------------------------------------------------------------------           //06-07-12|0x003a
#endif                                                                                    //06-07-12|0x003a
//***************************************************************************             //06-07-12|0x003b
//*******************************************************************************         //06-07-12|0x003c
#ifndef BASIC_ERROR_Defined                                                               //06-07-12|0x003c
#define BASIC_ERROR_Defined                                                               //06-07-12|0x003c
//-------------------------------------------------------------------------------         //06-07-12|0x003c
typedef struct {                                                                          //06-07-12|0x003c
  ULONG           mask[4];                                                                //06-07-12|0x003c
  ULONG           count;                                                                  //06-07-12|0x003c
  } BASIC_ERROR, * BASIC_ERROR_FAR;                                                       //06-07-12|0x003c
//-------------------------------------------------------------------------------         //06-07-12|0x003c
#endif                                                                                    //06-07-12|0x003c
//*******************************************************************************         //06-07-12|0x003d
#ifndef TEST_ERROR_Defined                                                                //06-07-12|0x003d
#define TEST_ERROR_Defined                                                                //06-07-12|0x003d
//-------------------------------------------------------------------------------         //06-07-12|0x003d
typedef struct {                                                                          //06-07-12|0x003d
  BASIC_ERROR     error[32];                                                              //06-07-12|0x003d
  ULONG           no_errors;                                                              //06-07-12|0x003d
  } TEST_ERROR, * TEST_ERROR_FAR;                                                         //06-07-12|0x003d
//-------------------------------------------------------------------------------         //06-07-12|0x003d
#endif                                                                                    //06-07-12|0x003d
//***************************************************************************             //06-07-12|0x003e
//*****************************************************************************           //06-12-09|0x003f
#ifndef EXIT_CODE_TYPEDEF_Defined                                                         //06-12-09|0x003f
#define EXIT_CODE_TYPEDEF_Defined                                                         //06-12-09|0x003f
//-----------------------------------------------------------------------------           //06-12-09|0x003f
typedef struct {                                                                          //06-12-09|0x003f
  UINT                no_exit_codes;                                                      //06-12-09|0x003f
  SLONG               exit_code[9];                                                       //06-12-09|0x003f
  } EXIT_CODE, * EXIT_CODE_FAR;                                                           //06-12-09|0x003f
//-----------------------------------------------------------------------------           //06-12-09|0x003f
#endif                                                                                    //06-12-09|0x003f
//*******************************************************************************         //06-07-12|0x0040
#ifndef COMMAND_LINE_TYPEDEF_Defined                                                      //06-07-12|0x0040
#define COMMAND_LINE_TYPEDEF_Defined                                                      //06-07-12|0x0040
//-------------------------------------------------------------------------------         //06-07-12|0x0040
typedef struct {                                                                          //06-07-12|0x0040
  SCHAR               name[257];                                                          //06-07-12|0x0040
  SCHAR               parms[1025];                                                        //06-07-12|0x0040
  } COMMAND_LINE, * COMMAND_LINE_FAR;                                                     //06-07-12|0x0040
//-------------------------------------------------------------------------------         //06-07-12|0x0040
#endif                                                                                    //06-07-12|0x0040
//*******************************************************************************         //06-07-12|0x0041
#ifndef TEST_ELEMENT_Defined                                                              //06-07-12|0x0041
#define TEST_ELEMENT_Defined                                                              //06-07-12|0x0041
//-------------------------------------------------------------------------------         //06-07-12|0x0041
typedef struct {                                                                          //06-07-12|0x0041
  UINT                threshold;                                                          //06-07-12|0x0041
  ULONG               test_count;                                                         //06-07-12|0x0041
  SLONG               test_flag;                                                          //06-07-12|0x0041
  SLONG               arm_flag;                                                           //06-07-12|0x0041
  } TEST_ELEMENT, * TEST_ELEMENT_FAR;                                                     //06-07-12|0x0041
//-------------------------------------------------------------------------------         //06-07-12|0x0041
#endif                                                                                    //06-07-12|0x0041
//*****************************************************************************           //<----  |0x0042
#ifndef CRYPTO_DATA_Defined                                                               //<----  |0x0042
#define CRYPTO_DATA_Defined                                                               //<----  |0x0042
//-----------------------------------------------------------------------------           //<----  |0x0042
typedef struct {                                                                          //<----  |0x0042
  ULONG             position;                                                             //<----  |0x0042
  UCHAR             random_data[127];                                                     //<----  |0x0042
  SINT              bit0_index;                                                           //<----  |0x0042
  SINT              bit127_index;                                                         //<----  |0x0042
  SINT              load_index;                                                           //<----  |0x0042
  SINT              rotator;                                                              //<----  |0x0042
  UCHAR             parity;                                                               //<----  |0x0042
  UINT              data_state;                                                           //<----  |0x0042
  SINT              index;                                                                //<----  |0x0042
  UCHAR             chain;                                                                //<----  |0x0042
  UCHAR             code_ring;                                                            //<----  |0x0042
  } CRYPTO_DATA, * CRYPTO_DATA_FAR;                                                       //<----  |0x0042
//-----------------------------------------------------------------------------           //<----  |0x0042
#endif                                                                                    //<----  |0x0042
//*******************************************************************************         //06-07-12|0x0043
#ifndef TEST_DATA_Defined                                                                 //06-07-12|0x0043
#define TEST_DATA_Defined                                                                 //06-07-12|0x0043
//-------------------------------------------------------------------------------         //06-07-12|0x0043
typedef struct {                                                                          //06-07-12|0x0043
  TEST_ELEMENT        test_element[128];                                                  //06-07-12|0x0043
  CRYPTO_DATA         crypto_data;                                                        //06-07-12|0x0043
  TOKENS              cleanup;                                                            //06-07-12|0x0043
  TOKENS              prepare;                                                            //06-07-12|0x0043
  TOKENS              build;                                                              //06-07-12|0x0043
  COMMAND_LINE        make;                                                               //06-07-12|0x0043
  COMMAND_LINE        run;                                                                //06-07-12|0x0043
  EXIT_CODE           make_exit;                                                          //06-07-12|0x0043
  EXIT_CODE           run_exit;                                                           //06-07-12|0x0043
  TOKENS              record;                                                             //06-07-12|0x0043
  TEST_ERROR          errors;                                                             //06-07-12|0x0043
  SCHAR               results[4];                                                         //06-07-12|0x0043
  ULONG               error_mask[4];                                                      //06-07-12|0x0043
  ULONG               no_samples;                                                         //06-07-12|0x0043
  ULONG               no_success;                                                         //06-07-12|0x0043
  ULONG               no_run_detects;                                                     //06-07-12|0x0043
  ULONG               no_prep_detects;                                                    //06-07-12|0x0043
  ULONG               no_failures;                                                        //06-07-12|0x0043
  ULONG               no_tests;                                                           //06-07-12|0x0043
  ULONG               type_flag;                                                          //06-07-12|0x0043
  SLONG               bit_offset;                                                         //06-07-12|0x0043
  ULONG               results_flag;                                                       //06-07-12|0x0043
  ULONG               test_no;                                                            //06-07-12|0x0043
  } TEST_DATA, * TEST_DATA_FAR;                                                           //06-07-12|0x0043
//-------------------------------------------------------------------------------         //06-07-12|0x0043
#endif                                                                                    //06-07-12|0x0043
//***************************************************************************             //06-07-12|0x0044
//*****************************************************************************           //06-07-12|0x0045
#ifndef TEST_BASE_Defined                                                                 //06-07-12|0x0045
#define TEST_BASE_Defined                                                                 //06-07-12|0x0045
//-----------------------------------------------------------------------------           //06-07-12|0x0045
typedef struct {                                                                          //06-07-12|0x0045
  TEST_DATA           data;                                                               //06-07-12|0x0045
  TEXT_FILE_DATA      project;                                                            //06-07-12|0x0045
  TOKENS              report;                                                             //06-07-12|0x0045
  TEXT_FILE_DATA      summary;                                                            //06-07-12|0x0045
  STRING_DATA         output;                                                             //06-07-12|0x0045
  TOKENS              tokens;                                                             //06-07-12|0x0045
  TOKENS              drive_path;                                                         //06-07-12|0x0045
  UINT                display_flag;                                                       //06-07-12|0x0045
  UINT                state;                                                              //06-07-12|0x0045
  UINT                run_flag;                                                           //06-07-12|0x0045
  UINT                status;                                                             //06-07-12|0x0045
  ULONG               test_time;                                                          //06-07-12|0x0045
  UINT                task_no;                                                            //06-07-12|0x0045
  } TEST_BASE, * TEST_BASE_FAR;                                                           //06-07-12|0x0045
//-----------------------------------------------------------------------------           //06-07-12|0x0045
#endif                                                                                    //06-07-12|0x0045
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
// CLASS TESTPROJ DEFINITION                                                              //06-07-12|0x004d
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
class TESTPROJ {                                                                          //06-07-12|0x004d
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
// CLASS TESTPROJ DEFINITION                                                              //06-07-12|0x004d
//*******************************************************************************         //10-29-97|0x004d
//*******************************************************************************         //10-29-97|0x004d
    private:                                                                              //10-27-97|0x0055
      TEST_BASE_FAR test_proj_addr;                                                       //10-27-97|0x0055
    public:                                                                               //06-07-12|0x008c
      UINT test_proj_allocate(void);                                                      //06-07-12|0x008c
#define TestProjAllocate test_proj.test_proj_allocate                                     //06-07-12|0x008d
    public:                                                                               //06-07-12|0x00a7
      UINT test_proj_free(void);                                                          //06-07-12|0x00a7
#define TestProjFree test_proj.test_proj_free                                             //06-07-12|0x00a8
    public:                                                                               //07-10-13|0x00bf
      UINT test_proj_process(TOKENS_FAR,ULONG);                                           //07-10-13|0x00bf
#define TestProjProcess test_proj.test_proj_process                                       //06-12-09|0x00c1
    private:                                                                              //06-12-09|0x02a9
      UINT initial(void);                                                                 //06-12-09|0x02a9
    private:                                                                              //06-12-09|0x02be
      UINT enter_project_name(SCHAR_FAR);                                                 //06-12-09|0x02be
    private:                                                                              //07-10-13|0x02cb
      UINT project_exists(ULONG);                                                         //07-10-13|0x02cb
    private:                                                                              //06-12-09|0x02e9
      UINT open_project(void);                                                            //06-12-09|0x02e9
    private:                                                                              //06-12-09|0x02f3
      UINT read_project(void);                                                            //06-12-09|0x02f3
    private:                                                                              //06-12-09|0x0300
      UINT basic_configure(SINT);                                                         //06-12-09|0x0300
    private:                                                                              //06-12-11|0x0326
      UINT drive_path(void);                                                              //06-12-11|0x0326
    private:                                                                              //06-12-11|0x0335
      UINT pcg_name(TOKENS_FAR);                                                          //06-12-11|0x0335
    private:                                                                              //06-12-16|0x0351
      UINT spawn_name(SCHAR_FAR,UINT);                                                    //06-12-16|0x0351
    private:                                                                              //06-12-16|0x0373
      UINT spawn_parms(SCHAR_FAR,UINT);                                                   //06-12-16|0x0373
    private:                                                                              //06-12-16|0x03be
      UINT spawn_exit_codes(EXIT_CODE_FAR,SLONG);                                         //06-12-16|0x03be
    private:                                                                              //06-12-17|0x03e5
      UINT cleanup_names(void);                                                           //06-12-17|0x03e5
    private:                                                                              //06-12-11|0x03fd
      UINT set_generator(void);                                                           //06-12-11|0x03fd
    private:                                                                              //06-12-09|0x0425
      UINT close_project(void);                                                           //06-12-09|0x0425
    private:                                                                              //06-12-12|0x0432
      UINT cleanup_step(void);                                                            //06-12-12|0x0432
    private:                                                                              //06-12-17|0x0452
      UINT basic_cleanup(SCHAR_FAR);                                                      //06-12-17|0x0452
    private:                                                                              //06-12-12|0x0467
      UINT generate_test(void);                                                           //06-12-12|0x0467
    private:                                                                              //06-12-12|0x04f2
      UINT progress_message(SCHAR_FAR);                                                   //06-12-12|0x04f2
    private:                                                                              //06-12-12|0x0509
      UINT pcg_push(TOKENS_FAR);                                                          //06-12-12|0x0509
    private:                                                                              //06-12-12|0x0522
      UINT debug_pause(void);                                                             //06-12-12|0x0522
    private:                                                                              //07-12-28|0x0544
      UINT exit_test(EXIT_CODE_FAR,SLONG,SCHAR_FAR);                                      //07-12-28|0x0544
    private:                                                                              //06-12-16|0x0589
      UINT make_step(void);                                                               //06-12-16|0x0589
    private:                                                                              //06-12-16|0x05ab
      UINT run_step(void);                                                                //06-12-16|0x05ab
    private:                                                                              //06-12-15|0x05cd
      UINT record_results(SCHAR_FAR);                                                     //06-12-15|0x05cd
    private:                                                                              //06-12-16|0x0610
      UINT prepare_active_bits(void);                                                     //06-12-16|0x0610
    private:                                                                              //06-12-16|0x0642
      UINT previous_error(void);                                                          //06-12-16|0x0642
    private:                                                                              //06-12-16|0x0666
      UINT new_error(void);                                                               //06-12-16|0x0666
    private:                                                                              //06-12-15|0x0683
      UINT enter_summary_name(SCHAR_FAR);                                                 //06-12-15|0x0683
    private:                                                                              //06-12-15|0x0690
      UINT report_summaries(void);                                                        //06-12-15|0x0690
    private:                                                                              //06-12-15|0x06bc
      UINT report_active(void);                                                           //06-12-15|0x06bc
    private:                                                                              //06-12-17|0x06f9
      UINT report_error(void);                                                            //06-12-17|0x06f9
    private:                                                                              //06-12-15|0x0743
      UINT report_title(SCHAR_FAR);                                                       //06-12-15|0x0743
    private:                                                                             //06-12-17|0x0768
      UINT report_line(SCHAR_FAR);                                                       //06-12-17|0x0768
    private:                                                                              //06-12-15|0x078e
      UINT report_numeric(SCHAR_FAR,SLONG);                                               //06-12-15|0x078e
    public:                                                                               //06-07-14|0x07b0
      UINT test_proj_test_reset(void);                                                    //06-07-14|0x07b0
#define TestProjTestReset test_proj.test_proj_test_reset                                  //06-07-14|0x07b0
    public:                                                                               //06-07-14|0x07b2
      UINT test_proj_test_read(void);                                                     //06-07-14|0x07b2
#define TestProjTestRead test_proj.test_proj_test_read                                    //06-07-14|0x07b2
    public:                                                                               //06-07-14|0x07b4
      UINT test_proj_test_write(void);                                                    //06-07-14|0x07b4
#define TestProjTestWrite test_proj.test_proj_test_write                                  //06-07-14|0x07b4
    public:                                                                               //06-07-14|0x07b6
      UINT test_proj_test_report(void);                                                   //06-07-14|0x07b6
#define TestProjTestReport test_proj.test_proj_test_report                                //06-07-14|0x07b6
    public:                                                                               //06-07-12|0x07c0
      TESTPROJ();                                                                         //06-07-12|0x07c0
  };                                                                                      //10-29-97|0x07c6
extern class TESTPROJ test_proj;                                                          //98-12-29|0x07c6
//*******************************************************************************         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
//****                       END OF FILE                                     ****         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
#endif                                                                                    //05-24-97|0x07c7
