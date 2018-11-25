//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
// DEVELOPMENT PROJECT ENGINE                                                             //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x0011
//  defined in the associated manual.                                                     //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x0011
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x0011
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x0011
//  (at your option) any later version.                                                   //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x0011
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x0011
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x0011
//  GNU General Public License for more details.                                          //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x0011
//  along with this program; if not, write to the Free Software                           //06-07-12|0x0011
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x0011
//  USA                                                                                   //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  For further information, please contact Robert Adams:                                 //06-07-12|0x0011
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x0011
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x0011
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
#ifndef devproj_h                                                                         //06-07-12|0x0012
#define devproj_h                                                                         //06-07-12|0x0012
//***************************************************************************             //06-07-12|0x0031
//***************************************************************************             //06-07-12|0x0032
//******                                                               ******             //06-07-12|0x0033
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0034
//******                                                               ******             //06-07-12|0x0035
//***************************************************************************             //06-07-12|0x0036
//***************************************************************************             //06-07-12|0x0037
//*******************************************************************************         //08-12-27|0x0038
#ifndef COMMAND_LINE_TYPEDEF_Defined                                                      //08-12-27|0x0038
#define COMMAND_LINE_TYPEDEF_Defined                                                      //08-12-27|0x0038
//-------------------------------------------------------------------------------         //08-12-27|0x0038
typedef struct {                                                                          //08-12-27|0x0038
  SCHAR               name[257];                                                          //08-12-27|0x0038
  SCHAR               parms[1025];                                                        //08-12-27|0x0038
  } COMMAND_LINE, * COMMAND_LINE_FAR;                                                     //08-12-27|0x0038
//-------------------------------------------------------------------------------         //08-12-27|0x0038
#endif                                                                                    //08-12-27|0x0038
//***************************************************************************             //06-07-12|0x0039
//*******************************************************************************         //06-07-12|0x003a
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x003a
#define STRING_DATA_Defined                                                               //06-07-12|0x003a
//-------------------------------------------------------------------------------         //06-07-12|0x003a
typedef struct {                                                                          //06-07-12|0x003a
  SCHAR   line[257];                                                                      //06-07-12|0x003a
  UINT    macro_line_no;                                                                  //06-07-12|0x003a
  UINT    type;                                                                           //06-07-12|0x003a
  UINT    start_col;                                                                      //06-07-12|0x003a
  UINT    start_call;                                                                     //06-07-12|0x003a
  SINT    length;                                                                         //06-07-12|0x003a
  SINT    position;                                                                       //06-07-12|0x003a
  SINT    column;                                                                         //06-07-12|0x003a
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x003a
//-------------------------------------------------------------------------------         //06-07-12|0x003a
#endif                                                                                    //06-07-12|0x003a
//*******************************************************************************         //06-07-12|0x003b
#ifndef TOKENS_Defined                                                                    //06-07-12|0x003b
#define TOKENS_Defined                                                                    //06-07-12|0x003b
//-------------------------------------------------------------------------------         //06-07-12|0x003b
typedef struct {                                                                          //06-07-12|0x003b
  UINT        no_tokens;                                                                  //06-07-12|0x003b
  STRING_DATA token[10];                                                                  //06-07-12|0x003b
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x003b
//-------------------------------------------------------------------------------         //06-07-12|0x003b
#endif                                                                                    //06-07-12|0x003b
//***************************************************************************             //06-07-12|0x003c
//*****************************************************************************           //06-07-12|0x003d
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x003d
#define FILE_CONTROL_Defined                                                              //06-07-12|0x003d
//-----------------------------------------------------------------------------           //06-07-12|0x003d
typedef struct {                                                                          //06-07-12|0x003d
  UINT    state;                                                                          //06-07-12|0x003d
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x003d
  FILE *  stream;                                                                         //06-07-12|0x003d
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x003d
//-----------------------------------------------------------------------------           //06-07-12|0x003d
#endif                                                                                    //06-07-12|0x003d
//*****************************************************************************           //06-07-12|0x003e
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-12|0x003e
#define TEXT_FILE_DATA_Defined                                                            //06-07-12|0x003e
//-----------------------------------------------------------------------------           //06-07-12|0x003e
typedef struct {                                                                          //06-07-12|0x003e
  FILE_CONTROL    file_control;                                                           //06-07-12|0x003e
  STRING_DATA     string;                                                                 //06-07-12|0x003e
  UINT            read_state;                                                             //06-07-12|0x003e
  UINT            get_state;                                                              //06-07-12|0x003e
  UINT            put_state;                                                              //06-07-12|0x003e
  UINT            status;                                                                 //06-07-12|0x003e
  UINT            run_flag;                                                               //06-07-12|0x003e
  UINT            line_no;                                                                //06-07-12|0x003e
  SLONG           length;                                                                 //06-07-12|0x003e
  SLONG           next_position;                                                          //06-07-12|0x003e
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-12|0x003e
//-----------------------------------------------------------------------------           //06-07-12|0x003e
#endif                                                                                    //06-07-12|0x003e
//***************************************************************************             //06-07-12|0x003f
#ifndef DEVELOPMENT_PROJECT_Defined                                                       //06-07-12|0x0040
#define DEVELOPMENT_PROJECT_Defined                                                       //06-07-12|0x0040
//-----------------------------------------------------------------------------           //06-07-12|0x0040
typedef struct {                                                                          //06-07-12|0x0040
  TEXT_FILE_DATA    project_file;                                                         //06-07-12|0x0040
  UINT              task_no;                                                              //06-07-12|0x0040
  ULONG             main_time;                                                            //06-07-12|0x0040
  ULONG             update_time;                                                          //06-07-12|0x0040
  ULONG             project_time;                                                         //06-07-12|0x0040
  UINT              display_state;                                                        //06-07-12|0x0040
  } DEVELOPMENT_STACK, * DEVELOPMENT_STACK_FAR;                                           //06-07-12|0x0040
//-----------------------------------------------------------------------------           //06-07-12|0x0040
typedef struct {                                                                          //06-07-12|0x0040
  ULONG             state;                                                                //06-07-12|0x0040
  UINT              status;                                                               //06-07-12|0x0040
  UINT              run_flag;                                                             //06-07-12|0x0040
  UINT              devprj_no;                                                            //06-07-12|0x0040
  UINT              single_step_flag;                                                     //06-07-12|0x0040
  TOKENS            drives;                                                               //06-07-12|0x0040
  TOKENS            tokens;                                                               //06-07-12|0x0040
  COMMAND_LINE      make;                                                                 //06-07-12|0x0040
  DEVELOPMENT_STACK stack[17];                                                            //06-07-12|0x0040
  } DEVELOPMENT_PROJECT, * DEVELOPMENT_PROJECT_FAR;                                       //06-07-12|0x0040
//-----------------------------------------------------------------------------           //06-07-12|0x0040
#endif                                                                                    //06-07-12|0x0040
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
// CLASS DEVELOPMENTPROJ DEFINITION                                                       //06-07-12|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
class DEVELOPMENTPROJ {                                                                   //06-07-12|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
// CLASS DEVELOPMENTPROJ DEFINITION                                                       //06-07-12|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
    private:                                                                              //10-27-97|0x0050
      DEVELOPMENT_PROJECT_FAR develop_project_addr;                                       //10-27-97|0x0050
    public:                                                                               //06-07-12|0x0073
      UINT devproj_allocate(void);                                                        //06-07-12|0x0073
#define DevProjAllocate develop_proj.devproj_allocate                                     //06-07-12|0x0074
    public:                                                                               //06-07-12|0x008e
      UINT devproj_free(void);                                                            //06-07-12|0x008e
#define DevProjFree develop_proj.devproj_free                                             //06-07-12|0x008f
    public:                                                                               //09-03-27|0x00a6
      UINT devproj_process(TOKENS_FAR,ULONG,UINT_FAR);                                    //09-03-27|0x00a6
#define DevProjProcess develop_proj.devproj_process                                       //06-07-20|0x00a8
    private:                                                                              //11-12-12|0x01a9
      UINT increment_project_no(void);                                                    //11-12-12|0x01a9
    private:                                                                              //11-12-12|0x01bf
      UINT enter_project_name(void);                                                      //11-12-12|0x01bf
    private:                                                                              //11-12-12|0x01e4
      UINT project_exists(void);                                                          //11-12-12|0x01e4
    private:                                                                              //06-08-09|0x020c
      UINT open_project(void);                                                            //06-08-09|0x020c
    private:                                                                              //06-08-09|0x0226
      UINT read_project(void);                                                            //06-08-09|0x0226
    private:                                                                              //07-10-30|0x025e
      UINT update_always(void);                                                           //07-10-30|0x025e
    private:                                                                              //08-06-15|0x0277
      UINT turn_off_display(void);                                                        //08-06-15|0x0277
    private:                                                                              //08-06-15|0x028d
      UINT turn_on_display(void);                                                         //08-06-15|0x028d
    private:                                                                              //08-06-15|0x02a3
      UINT enable_file_time(void);                                                        //08-06-15|0x02a3
    private:                                                                              //08-06-15|0x02c0
      UINT disable_file_time(void);                                                       //08-06-15|0x02c0
    private:                                                                              //11-12-12|0x02df
      UINT update_task_no(void);                                                          //11-12-12|0x02df
    private:                                                                              //06-08-09|0x0317
      UINT drive_path(void);                                                              //06-08-09|0x0317
    private:                                                                              //11-12-12|0x0331
      UINT get_file_name(void);                                                           //11-12-12|0x0331
    private:                                                                              //11-12-12|0x0348
      UINT develop_push(void);                                                            //11-12-12|0x0348
    private:                                                                              //11-12-12|0x035e
      UINT decrement_project_no(void);                                                    //11-12-12|0x035e
    private:                                                                              //11-12-17|0x0378
      UINT develop_pop(void);                                                             //11-12-17|0x0378
    private:                                                                              //06-11-14|0x038d
      UINT source_args(TOKENS_FAR);                                                       //06-11-14|0x038d
    private:                                                                              //08-12-27|0x03a8
      UINT spawn_name(void);                                                              //08-12-27|0x03a8
    private:                                                                              //08-12-27|0x03ca
      UINT spawn_parms(void);                                                             //08-12-27|0x03ca
    private:                                                                              //08-12-27|0x0418
      UINT make_step(void);                                                               //08-12-27|0x0418
    private:                                                                              //08-12-31|0x0431
      UINT single_step_enable(void);                                                      //08-12-31|0x0431
    private:                                                                              //08-12-31|0x0446
      UINT debug_pause(void);                                                             //08-12-31|0x0446
    private:                                                                              //06-08-09|0x0465
      UINT close_project(void);                                                           //06-08-09|0x0465
    public:                                                                               //06-07-14|0x0479
      UINT devproj_test_reset(void);                                                      //06-07-14|0x0479
#define DevProjTestReset develop_proj.devproj_test_reset                                  //06-07-14|0x0479
    public:                                                                               //06-07-14|0x047b
      UINT devproj_test_read(void);                                                       //06-07-14|0x047b
#define DevProjTestRead develop_proj.devproj_test_read                                    //06-07-14|0x047b
    public:                                                                               //06-07-14|0x047d
      UINT devproj_test_write(void);                                                      //06-07-14|0x047d
#define DevProjTestWrite develop_proj.devproj_test_write                                  //06-07-14|0x047d
    public:                                                                               //06-07-14|0x047f
      UINT devproj_test_report(void);                                                     //06-07-14|0x047f
#define DevProjTestReport develop_proj.devproj_test_report                                //06-07-14|0x047f
    public:                                                                               //06-07-12|0x0487
      DEVELOPMENTPROJ();                                                                  //06-07-12|0x0487
  };                                                                                      //10-29-97|0x0491
extern class DEVELOPMENTPROJ develop_proj;                                                //98-12-29|0x0491
//*******************************************************************************         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
//****                       END OF FILE                                     ****         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
#endif                                                                                    //05-24-97|0x0492
