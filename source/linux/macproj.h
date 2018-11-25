//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
// MACRO-LIBRARY MAIN ENGINE                                                              //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  The purpose of this program as well as instructions regarding its use is              //11-05-28|0x001b
//  defined in the associated manual.                                                     //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  This program is free software; you can redistribute it and/or modify                  //11-05-28|0x001b
//  it under the terms of the GNU General Public License as published by                  //11-05-28|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //11-05-28|0x001b
//  (at your option) any later version.                                                   //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//  This program is distributed in the hope that it will be useful,                       //11-05-28|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //11-05-28|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //11-05-28|0x001b
//  GNU General Public License for more details.                                          //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//  You should have received a copy of the GNU General Public License                     //11-05-28|0x001b
//  along with this program; if not, write to the Free Software                           //11-05-28|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //11-05-28|0x001b
//  USA                                                                                   //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  For further information, please contact Robert Adams:                                 //11-05-28|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //11-05-28|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //11-05-28|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
#ifndef macproj_h                                                                         //06-07-14|0x001c
#define macproj_h                                                                         //06-07-14|0x001c
//***************************************************************************             //06-07-14|0x003e
//***************************************************************************             //06-07-14|0x003f
//******                                                               ******             //06-07-14|0x0040
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-14|0x0041
//******                                                               ******             //06-07-14|0x0042
//***************************************************************************             //06-07-14|0x0043
//***************************************************************************             //06-07-14|0x0044
//*******************************************************************************         //06-07-14|0x0045
#ifndef STRING_DATA_Defined                                                               //06-07-14|0x0045
#define STRING_DATA_Defined                                                               //06-07-14|0x0045
//-------------------------------------------------------------------------------         //06-07-14|0x0045
typedef struct {                                                                          //06-07-14|0x0045
  SCHAR   line[257];                                                                      //06-07-14|0x0045
  UINT    macro_line_no;                                                                  //06-07-14|0x0045
  UINT    type;                                                                           //06-07-14|0x0045
  UINT    start_col;                                                                      //06-07-14|0x0045
  UINT    start_call;                                                                     //06-07-14|0x0045
  SINT    length;                                                                         //06-07-14|0x0045
  SINT    position;                                                                       //06-07-14|0x0045
  SINT    column;                                                                         //06-07-14|0x0045
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-14|0x0045
//-------------------------------------------------------------------------------         //06-07-14|0x0045
#endif                                                                                    //06-07-14|0x0045
//*******************************************************************************         //06-07-14|0x0046
#ifndef TOKENS_Defined                                                                    //06-07-14|0x0046
#define TOKENS_Defined                                                                    //06-07-14|0x0046
//-------------------------------------------------------------------------------         //06-07-14|0x0046
typedef struct {                                                                          //06-07-14|0x0046
  UINT        no_tokens;                                                                  //06-07-14|0x0046
  STRING_DATA token[10];                                                                  //06-07-14|0x0046
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-14|0x0046
//-------------------------------------------------------------------------------         //06-07-14|0x0046
#endif                                                                                    //06-07-14|0x0046
//***************************************************************************             //06-07-14|0x0047
//*****************************************************************************           //06-07-14|0x0048
#ifndef FILE_CONTROL_Defined                                                              //06-07-14|0x0048
#define FILE_CONTROL_Defined                                                              //06-07-14|0x0048
//-----------------------------------------------------------------------------           //06-07-14|0x0048
typedef struct {                                                                          //06-07-14|0x0048
  UINT    state;                                                                          //06-07-14|0x0048
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-14|0x0048
  FILE *  stream;                                                                         //06-07-14|0x0048
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-14|0x0048
//-----------------------------------------------------------------------------           //06-07-14|0x0048
#endif                                                                                    //06-07-14|0x0048
//*****************************************************************************           //06-07-14|0x0049
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-14|0x0049
#define TEXT_FILE_DATA_Defined                                                            //06-07-14|0x0049
//-----------------------------------------------------------------------------           //06-07-14|0x0049
typedef struct {                                                                          //06-07-14|0x0049
  FILE_CONTROL    file_control;                                                           //06-07-14|0x0049
  STRING_DATA     string;                                                                 //06-07-14|0x0049
  UINT            read_state;                                                             //06-07-14|0x0049
  UINT            get_state;                                                              //06-07-14|0x0049
  UINT            put_state;                                                              //06-07-14|0x0049
  UINT            status;                                                                 //06-07-14|0x0049
  UINT            run_flag;                                                               //06-07-14|0x0049
  UINT            line_no;                                                                //06-07-14|0x0049
  SLONG           length;                                                                 //06-07-14|0x0049
  SLONG           next_position;                                                          //06-07-14|0x0049
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-14|0x0049
//-----------------------------------------------------------------------------           //06-07-14|0x0049
#endif                                                                                    //06-07-14|0x0049
//***************************************************************************             //06-07-14|0x004a
#ifndef MACRO_DEVELOP_Defined                                                             //11-02-17|0x004b
#define MACRO_DEVELOP_Defined                                                             //11-02-17|0x004b
//-----------------------------------------------------------------------------           //11-02-17|0x004b
typedef struct {                                                                          //11-02-17|0x004b
  UINT            develop_status;                                                         //11-02-17|0x004b
  ULONG           in_time;                                                                //11-02-17|0x004b
  TEXT_FILE_DATA  macro_file;                                                             //11-02-17|0x004b
  } MACRO_DEVELOP, * MACRO_DEVELOP_FAR;                                                   //11-02-17|0x004b
//-----------------------------------------------------------------------------           //11-02-17|0x004b
#endif                                                                                    //11-02-17|0x004b
#ifndef MACRO_PROJECT_Defined                                                             //06-07-14|0x004c
#define MACRO_PROJECT_Defined                                                             //06-07-14|0x004c
//-----------------------------------------------------------------------------           //06-07-14|0x004c
typedef struct {                                                                          //06-07-14|0x004c
  MACRO_DEVELOP   macro_develop;                                                          //06-07-14|0x004c
  TEXT_FILE_DATA  project_file;                                                           //06-07-14|0x004c
  TOKENS          tokens;                                                                 //06-07-14|0x004c
  STRING_DATA     work;                                                                   //06-07-14|0x004c
  ULONG           out_time;                                                               //06-07-14|0x004c
  ULONG           external_time;                                                          //06-07-14|0x004c
  UINT            develop_state;                                                          //06-07-14|0x004c
  UINT            process_state;                                                          //06-07-14|0x004c
  UINT            prepare_state;                                                          //06-07-14|0x004c
  UINT            build_state;                                                            //06-07-14|0x004c
  UINT            run_flag;                                                               //06-07-14|0x004c
  UINT            status;                                                                 //06-07-14|0x004c
  } MACRO_PROJECT, * MACRO_PROJECT_FAR;                                                   //06-07-14|0x004c
//-----------------------------------------------------------------------------           //06-07-14|0x004c
#endif                                                                                    //06-07-14|0x004c
//*******************************************************************************         //10-29-97|0x0054
//*******************************************************************************         //10-29-97|0x0054
// CLASS MACROPROJ DEFINITION                                                             //06-07-14|0x0054
//*******************************************************************************         //10-29-97|0x0054
//*******************************************************************************         //10-29-97|0x0054
class MACROPROJ {                                                                         //06-07-14|0x0054
//*******************************************************************************         //10-29-97|0x0054
//*******************************************************************************         //10-29-97|0x0054
// CLASS MACROPROJ DEFINITION                                                             //06-07-14|0x0054
//*******************************************************************************         //10-29-97|0x0054
//*******************************************************************************         //10-29-97|0x0054
    private:                                                                              //10-27-97|0x005c
      MACRO_PROJECT_FAR macro_project_addr;                                               //10-27-97|0x005c
    public:                                                                               //06-07-14|0x007e
      UINT macproj_allocate(void);                                                        //06-07-14|0x007e
#define MacProjAllocate macro_proj.macproj_allocate                                       //06-07-14|0x007f
    public:                                                                               //06-07-14|0x009a
      UINT macproj_free(void);                                                            //06-07-14|0x009a
#define MacProjFree macro_proj.macproj_free                                               //06-07-14|0x009b
    public:                                                                               //09-03-27|0x00b6
      UINT macproj_process(TOKENS_FAR,ULONG,UINT_FAR);                                    //09-03-27|0x00b6
#define MacProjProcess macro_proj.macproj_process                                         //06-08-16|0x00b8
    private:                                                                              //09-03-27|0x010e
      UINT macproj_prepare(TOKENS_FAR,UINT_FAR);                                          //09-03-27|0x010e
    private:                                                                              //06-08-18|0x01e2
      UINT macproj_build(TOKENS_FAR);                                                     //06-08-18|0x01e2
    private:                                                                              //06-08-16|0x02a7
      UINT enter_name(TEXT_FILE_DATA_FAR,TOKENS_FAR,SCHAR_FAR);                           //06-08-16|0x02a7
    private:                                                                              //06-08-16|0x02bf
      UINT file_time(TEXT_FILE_DATA_FAR);                                                 //06-08-16|0x02bf
    private:                                                                              //06-08-17|0x02d6
      UINT open_project(TEXT_FILE_DATA_FAR);                                              //06-08-17|0x02d6
    private:                                                                              //06-08-17|0x02f1
      UINT read_project(TEXT_FILE_DATA_FAR);                                              //06-08-17|0x02f1
    private:                                                                              //09-03-27|0x0317
      UINT update_task_no(UINT_FAR);                                                      //09-03-27|0x0317
    private:                                                                              //11-06-13|0x0335
      UINT enable_display(void);                                                          //11-06-13|0x0335
    private:                                                                              //07-10-30|0x034c
      UINT uncond_update(void);                                                           //07-10-30|0x034c
    private:                                                                              //11-02-12|0x0364
      UINT set_version(UINT);                                                             //11-02-12|0x0364
    private:                                                                              //06-08-17|0x0379
      UINT text_prepare(void);                                                            //06-08-17|0x0379
    private:                                                                              //11-02-14 |0x038f
      UINT create_report(void);                                                           //11-02-14 |0x038f
    private:                                                                              //06-08-18|0x03a5
      UINT create_library(void);                                                          //06-08-18|0x03a5
    private:                                                                              //06-08-17|0x03bc
      UINT close_project(TEXT_FILE_DATA_FAR);                                             //06-08-17|0x03bc
    public:                                                                               //06-07-14|0x03d1
      UINT macproj_test_reset(void);                                                      //06-07-14|0x03d1
#define MacProjTestReset macro_proj.macproj_test_reset                                    //06-07-14|0x03d1
    public:                                                                               //06-07-14|0x03d3
      UINT macproj_test_read(void);                                                       //06-07-14|0x03d3
#define MacProjTestRead macro_proj.macproj_test_read                                      //06-07-14|0x03d3
    public:                                                                               //06-07-14|0x03d5
      UINT macproj_test_write(void);                                                      //06-07-14|0x03d5
#define MacProjTestWrite macro_proj.macproj_test_write                                    //06-07-14|0x03d5
    public:                                                                               //06-07-14|0x03d7
      UINT macproj_test_report(void);                                                     //06-07-14|0x03d7
#define MacProjTestReport macro_proj.macproj_test_report                                  //06-07-14|0x03d7
    public:                                                                               //06-07-14|0x03df
      MACROPROJ();                                                                        //06-07-14|0x03df
  };                                                                                      //10-29-97|0x03e9
extern class MACROPROJ macro_proj;                                                        //98-12-29|0x03e9
//*******************************************************************************         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
//****                       END OF FILE                                     ****         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
#endif                                                                                    //05-24-97|0x03ea
