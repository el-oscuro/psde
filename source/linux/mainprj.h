//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
// PROGRAMMABLE DEVELOPMENT ENVIRONMENT                                                   //06-07-12|0x0008
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
#ifndef mainprj_h                                                                         //06-07-12|0x000b
#define mainprj_h                                                                         //06-07-12|0x000b
//***************************************************************************             //06-07-12|0x0042
//***************************************************************************             //06-07-12|0x0043
//******                                                               ******             //06-07-12|0x0044
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0045
//******                                                               ******             //06-07-12|0x0046
//***************************************************************************             //06-07-12|0x0047
//***************************************************************************             //06-07-12|0x0048
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
//***************************************************************************             //06-07-12|0x004b
//*****************************************************************************           //06-07-12|0x004c
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x004c
#define FILE_CONTROL_Defined                                                              //06-07-12|0x004c
//-----------------------------------------------------------------------------           //06-07-12|0x004c
typedef struct {                                                                          //06-07-12|0x004c
  UINT    state;                                                                          //06-07-12|0x004c
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x004c
  FILE *  stream;                                                                         //06-07-12|0x004c
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x004c
//-----------------------------------------------------------------------------           //06-07-12|0x004c
#endif                                                                                    //06-07-12|0x004c
//*****************************************************************************           //06-07-12|0x004d
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-12|0x004d
#define TEXT_FILE_DATA_Defined                                                            //06-07-12|0x004d
//-----------------------------------------------------------------------------           //06-07-12|0x004d
typedef struct {                                                                          //06-07-12|0x004d
  FILE_CONTROL    file_control;                                                           //06-07-12|0x004d
  STRING_DATA     string;                                                                 //06-07-12|0x004d
  UINT            read_state;                                                             //06-07-12|0x004d
  UINT            get_state;                                                              //06-07-12|0x004d
  UINT            put_state;                                                              //06-07-12|0x004d
  UINT            status;                                                                 //06-07-12|0x004d
  UINT            run_flag;                                                               //06-07-12|0x004d
  UINT            line_no;                                                                //06-07-12|0x004d
  SLONG           length;                                                                 //06-07-12|0x004d
  SLONG           next_position;                                                          //06-07-12|0x004d
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-12|0x004d
//-----------------------------------------------------------------------------           //06-07-12|0x004d
#endif                                                                                    //06-07-12|0x004d
//***************************************************************************             //06-07-12|0x004e
//*****************************************************************************           //06-07-12|0x004f
#ifndef MAIN_BASE_Defined                                                                 //06-07-12|0x004f
#define MAIN_BASE_Defined                                                                 //06-07-12|0x004f
//-----------------------------------------------------------------------------           //06-07-12|0x004f
typedef struct {                                                                          //06-07-12|0x004f
  TEXT_FILE_DATA      project;                                                            //06-07-12|0x004f
  SCHAR_FAR           project_name;                                                       //06-07-12|0x004f
  TOKENS              tokens;                                                             //06-07-12|0x004f
  TOKENS              drives;                                                             //06-07-12|0x004f
  ULONG               project_time;                                                       //06-07-12|0x004f
  ULONG               update_time;                                                        //06-07-12|0x004f
  ULONG               exec_time;                                                          //06-07-12|0x004f
  ULONG               state;                                                              //06-07-12|0x004f
  UINT                status;                                                             //06-07-12|0x004f
  UINT                run_flag;                                                           //06-07-12|0x004f
  UINT                task_no;                                                            //06-07-12|0x004f
  } MAIN_BASE, * MAIN_BASE_FAR;                                                           //06-07-12|0x004f
//-----------------------------------------------------------------------------           //06-07-12|0x004f
#endif                                                                                    //06-07-12|0x004f
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
// CLASS EXPLRPDE DEFINITION                                                              //06-07-12|0x0057
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
class EXPLRPDE {                                                                          //06-07-12|0x0057
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
// CLASS EXPLRPDE DEFINITION                                                              //06-07-12|0x0057
//*******************************************************************************         //10-29-97|0x0057
//*******************************************************************************         //10-29-97|0x0057
    private:                                                                              //10-27-97|0x005f
      MAIN_BASE_FAR main_base_addr;                                                       //10-27-97|0x005f
    private:                                                                              //10-27-97|0x0060
      UINT self_test_flag;                                                                //10-27-97|0x0060
    private:                                                                              //10-27-97|0x0061
      UINT display_state;                                                                 //10-27-97|0x0061
    public:                                                                               //06-07-12|0x0080
      UINT main_allocate(void);                                                           //06-07-12|0x0080
#define MainAllocate explrpde.main_allocate                                               //06-07-12|0x0081
    public:                                                                               //06-07-12|0x00ac
      UINT main_free(void);                                                               //06-07-12|0x00ac
#define MainFree explrpde.main_free                                                       //06-07-12|0x00ad
    public:                                                                               //06-07-20|0x00d3
      UINT get_arguments(SINT,char * *);                                                  //06-07-20|0x00d3
#define GetArguments explrpde.get_arguments                                               //06-07-20|0x00d4
    public:                                                                               //06-09-21|0x00fe
      UINT pcg_success(void);                                                             //06-09-21|0x00fe
#define PcgSuccess explrpde.pcg_success                                                   //06-09-21|0x00ff
    public:                                                                               //06-07-12|0x0113
      UINT pcg_stop(void);                                                                //06-07-12|0x0113
#define PcgStop explrpde.pcg_stop                                                         //06-07-12|0x0114
    public:                                                                               //06-07-20|0x0137
      UINT main_process(void);                                                            //06-07-20|0x0137
#define MainProcess explrpde.main_process                                                 //06-07-13|0x0139
    public:                                                                               //06-07-12|0x01f0
      UINT write_self_test(void);                                                         //06-07-12|0x01f0
#define WriteSelfTest explrpde.write_self_test                                            //06-07-12|0x01f1
    public:                                                                               //06-07-12|0x0222
      UINT report_self_test(void);                                                        //06-07-12|0x0222
#define ReportSelfTest explrpde.report_self_test                                          //06-07-12|0x0223
    private:                                                                              //06-08-08|0x0255
      UINT enter_project_name(void);                                                      //06-08-08|0x0255
    private:                                                                              //06-08-08|0x026e
      UINT project_exists(void);                                                          //06-08-08|0x026e
    private:                                                                              //06-08-08|0x0299
      UINT open_project(void);                                                            //06-08-08|0x0299
    private:                                                                              //06-08-08|0x02b3
      UINT read_project(void);                                                            //06-08-08|0x02b3
    private:                                                                              //08-06-14|0x02de
      UINT turn_off_display(void);                                                        //08-06-14|0x02de
    private:                                                                              //08-06-14|0x02f4
      UINT turn_on_display(void);                                                         //08-06-14|0x02f4
    private:                                                                              //06-07-14|0x030a
      UINT reset_self_test(void);                                                         //06-07-14|0x030a
    private:                                                                              //06-07-14|0x0320
      UINT start_self_test(void);                                                         //06-07-14|0x0320
    private:                                                                              //06-07-14|0x0354
      UINT set_tab(void);                                                                 //06-07-14|0x0354
    private:                                                                              //12-05-18|0x0373
      UINT load_report_file(void);                                                        //12-05-18|0x0373
    private:                                                                              //12-05-21|0x038a
      UINT enable_report_file(void);                                                      //12-05-21|0x038a
    private:                                                                              //12-05-21|0x03a0
      UINT disable_report_file(void);                                                     //12-05-21|0x03a0
    private:                                                                              //08-06-14|0x03b6
      UINT enable_file_time(void);                                                        //08-06-14|0x03b6
    private:                                                                              //08-06-14|0x03d3
      UINT disable_file_time(void);                                                       //08-06-14|0x03d3
    private:                                                                              //06-08-08|0x03f0
      UINT drive_path(void);                                                              //06-08-08|0x03f0
    private:                                                                              //06-08-28|0x040a
      UINT push_project(void);                                                            //06-08-28|0x040a
    private:                                                                              //06-08-08|0x0427
      UINT close_project(void);                                                           //06-08-08|0x0427
    public:                                                                               //06-07-14|0x043d
      UINT explrpde_test_reset(void);                                                     //06-07-14|0x043d
#define ExplrPdeTestReset explrpde.explrpde_test_reset                                    //06-07-14|0x043d
    public:                                                                               //06-07-14|0x043f
      UINT explrpde_test_read(void);                                                      //06-07-14|0x043f
#define ExplrPdeTestRead explrpde.explrpde_test_read                                      //06-07-14|0x043f
    public:                                                                               //06-07-14|0x0441
      UINT explrpde_test_write(void);                                                     //06-07-14|0x0441
#define ExplrPdeTestWrite explrpde.explrpde_test_write                                    //06-07-14|0x0441
    public:                                                                               //06-07-14|0x0443
      UINT explrpde_test_report(void);                                                    //06-07-14|0x0443
#define ExplrPdeTestReport explrpde.explrpde_test_report                                  //06-07-14|0x0443
    public:                                                                               //06-07-12|0x044b
      EXPLRPDE();                                                                         //06-07-12|0x044b
  };                                                                                      //10-29-97|0x0456
extern class EXPLRPDE explrpde;                                                           //98-12-29|0x0456
//*******************************************************************************         //05-24-97|0x0457
//*******************************************************************************         //05-24-97|0x0457
//****                       END OF FILE                                     ****         //05-24-97|0x0457
//*******************************************************************************         //05-24-97|0x0457
//*******************************************************************************         //05-24-97|0x0457
#endif                                                                                    //05-24-97|0x0457
