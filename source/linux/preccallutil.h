//*****************************************************************************           //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
// PRECEDENCE CALL STACK UTILITIES                                                        //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//  The purpose of this program as well as instructions regarding its use is              //07-06-29|0x001e
//  defined in the associated manual.                                                     //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//  This program is free software; you can redistribute it and/or modify                  //07-06-29|0x001e
//  it under the terms of the GNU General Public License as published by                  //07-06-29|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //07-06-29|0x001e
//  (at your option) any later version.                                                   //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
//  This program is distributed in the hope that it will be useful,                       //07-06-29|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-06-29|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-06-29|0x001e
//  GNU General Public License for more details.                                          //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
//  You should have received a copy of the GNU General Public License                     //07-06-29|0x001e
//  along with this program; if not, write to the Free Software                           //07-06-29|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-06-29|0x001e
//  USA                                                                                   //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//  For further information, please contact Robert Adams:                                 //07-06-29|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //07-06-29|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-06-29|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
#include "precdiag.h"                                                                     //07-06-29|0x0021
#include "precfile.h"                                                                     //07-06-29|0x0022
#include "guicomm.h"                                                                      //check   |0x0023
#ifndef preccallutil_h                                                                    //07-06-29|0x0026
#define preccallutil_h                                                                    //07-06-29|0x0026
//***************************************************************************             //07-06-29|0x003c
//***************************************************************************             //07-06-29|0x003d
//******                                                               ******             //07-06-29|0x003e
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //07-06-29|0x003f
//******                                                               ******             //07-06-29|0x0040
//***************************************************************************             //07-06-29|0x0041
//***************************************************************************             //07-06-29|0x0042
//*******************************************************************************         //07-06-29|0x0043
#ifndef STRING_DATA_Defined                                                               //07-06-29|0x0043
#define STRING_DATA_Defined                                                               //07-06-29|0x0043
//-------------------------------------------------------------------------------         //07-06-29|0x0043
typedef struct {                                                                          //07-06-29|0x0043
  SCHAR   line[257];                                                                      //07-06-29|0x0043
  UINT    macro_line_no;                                                                  //07-06-29|0x0043
  UINT    type;                                                                           //07-06-29|0x0043
  UINT    start_col;                                                                      //07-06-29|0x0043
  UINT    start_call;                                                                     //07-06-29|0x0043
  SINT    length;                                                                         //07-06-29|0x0043
  SINT    position;                                                                       //07-06-29|0x0043
  SINT    column;                                                                         //07-06-29|0x0043
  } STRING_DATA, * STRING_DATA_FAR;                                                       //07-06-29|0x0043
//-------------------------------------------------------------------------------         //07-06-29|0x0043
#endif                                                                                    //07-06-29|0x0043
//*******************************************************************************         //07-06-29|0x0044
#ifndef TOKENS_Defined                                                                    //07-06-29|0x0044
#define TOKENS_Defined                                                                    //07-06-29|0x0044
//-------------------------------------------------------------------------------         //07-06-29|0x0044
typedef struct {                                                                          //07-06-29|0x0044
  UINT        no_tokens;                                                                  //07-06-29|0x0044
  STRING_DATA token[10];                                                                  //07-06-29|0x0044
  } TOKENS, * TOKENS_FAR;                                                                 //07-06-29|0x0044
//-------------------------------------------------------------------------------         //07-06-29|0x0044
#endif                                                                                    //07-06-29|0x0044
//*****************************************************************************           //07-06-29|0x0045
#ifndef FILE_CONTROL_Defined                                                              //07-06-29|0x0045
#define FILE_CONTROL_Defined                                                              //07-06-29|0x0045
//-----------------------------------------------------------------------------           //07-06-29|0x0045
typedef struct {                                                                          //07-06-29|0x0045
  UINT    state;                                                                          //07-06-29|0x0045
  SCHAR   name[_MAX_PATH+1];                                                              //07-06-29|0x0045
  FILE *  stream;                                                                         //07-06-29|0x0045
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //07-06-29|0x0045
//-----------------------------------------------------------------------------           //07-06-29|0x0045
#endif                                                                                    //07-06-29|0x0045
//*******************************************************************************         //07-06-29|0x0046
#ifndef BINARY_FILE_DATA_Defined                                                          //07-06-29|0x0046
#define BINARY_FILE_DATA_Defined                                                          //07-06-29|0x0046
//-------------------------------------------------------------------------------         //07-06-29|0x0046
typedef struct {                                                                          //07-06-29|0x0046
  FILE_CONTROL    file_control;                                                           //07-06-29|0x0046
  SLONG           file_position;                                                          //07-06-29|0x0046
  SLONG           file_length;                                                            //07-06-29|0x0046
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-06-29|0x0046
//-------------------------------------------------------------------------------         //07-06-29|0x0046
#endif                                                                                    //07-06-29|0x0046
//*****************************************************************************           //07-06-29|0x0047
#ifndef CALL_STACK_Defined                                                                //07-06-29|0x0047
#define CALL_STACK_Defined                                                                //07-06-29|0x0047
typedef struct {                                                                          //07-06-29|0x0047
  TOKENS          args;                                                                   //07-06-29|0x0047
  STRING_DATA     call_bridge;                                                            //07-06-29|0x0047
  SINT            no_includes;                                                            //07-06-29|0x0047
  UINT            stack_state;                                                            //07-06-29|0x0047
  SLONG           echo_position;                                                          //07-06-29|0x0047
  } CALL_STACK, * CALL_STACK_FAR;                                                         //07-06-29|0x0047
//-----------------------------------------------------------------------------           //07-06-29|0x0047
#endif                                                                                    //07-06-29|0x0047
//*****************************************************************************           //07-06-29|0x0048
#ifndef CALL_DATA_Defined                                                                 //07-06-29|0x0048
#define CALL_DATA_Defined                                                                 //07-06-29|0x0048
//-----------------------------------------------------------------------------           //07-06-29|0x0048
typedef struct {                                                                          //07-06-29|0x0048
  BINARY_FILE_DATA  call_file;                                                            //07-06-29|0x0048
  CALL_STACK        call_stack[4];                                                        //07-06-29|0x0048
  STRING_DATA       call_return;                                                          //07-06-29|0x0048
  UINT              run_flag;                                                             //07-06-29|0x0048
  UINT              status;                                                               //07-06-29|0x0048
  UINT              call_state;                                                           //07-06-29|0x0048
  UINT              process_state;                                                        //07-06-29|0x0048
  SLONG             position;                                                             //07-06-29|0x0048
  SLONG             macro_pos;                                                            //07-06-29|0x0048
  SLONG             source_pos;                                                           //07-06-29|0x0048
  SLONG             dev_pos;                                                              //07-06-29|0x0048
  SLONG             drive_path_pos;                                                       //07-06-29|0x0048
  } CALL_DATA, * CALL_DATA_FAR;                                                           //07-06-29|0x0048
//-----------------------------------------------------------------------------           //07-06-29|0x0048
#endif                                                                                    //07-06-29|0x0048
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
// CLASS PRECCALL_UTIL DEFINITION                                                         //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
class PRECCALL_UTIL {                                                                     //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
// CLASS PRECCALL_UTIL DEFINITION                                                         //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
    private:                                                                              //10-27-97|0x0058
      CALL_DATA_FAR call_data_addr;                                                       //10-27-97|0x0058
    public:                                                                               //07-06-29|0x0076
      UINT call_util_construct(CALL_DATA_FAR);                                            //07-06-29|0x0076
#define CallUtilConstruct preccall_util.call_util_construct                               //07-06-29|0x0079
    public:                                                                               //07-06-29|0x0091
      UINT callutil_create_file(TOKENS_FAR);                                              //07-06-29|0x0091
#define CallUtilCreateFile preccall_util.callutil_create_file                             //07-06-29|0x0094
    public:                                                                               //07-06-29|0x00b7
      UINT callutil_write_file(UINT);                                                     //07-06-29|0x00b7
#define CallUtilWriteFile preccall_util.callutil_write_file                               //07-06-29|0x00ba
    public:                                                                               //check   |0x00d9
      UINT callutil_destroy_file(void);                                                   //check   |0x00d9
#define CallUtilDestroyFile preccall_util.callutil_destroy_file                           //check   |0x00db
    public:                                                                               //07-06-29|0x00f6
      UINT callutil_read_file(UINT,SLONG);                                                //07-06-29|0x00f6
#define CallUtilReadFile preccall_util.callutil_read_file                                 //07-06-29|0x00f9
    public:                                                                               //07-06-29|0x011e
      UINT callutil_strcat(STRING_DATA_FAR,STRING_DATA_FAR);                              //07-06-29|0x011e
#define CallUtilStrCat preccall_util.callutil_strcat                                      //07-06-29|0x0121
    public:                                                                               //07-06-30|0x0150
      UINT callutil_test_pos(SLONG,SLONG,SLONG);                                          //07-06-30|0x0150
#define CallUtilTestPos preccall_util.callutil_test_pos                                   //07-06-30|0x0153
    public:                                                                               //07-06-30|0x016c
      UINT callutil_test_reset(void);                                                     //07-06-30|0x016c
#define PrecCallUtilTestReset preccall_util.callutil_test_reset                           //07-06-30|0x016c
    public:                                                                               //07-06-30|0x016e
      UINT callutil_test_read(void);                                                      //07-06-30|0x016e
#define PrecCallUtilTestRead preccall_util.callutil_test_read                             //07-06-30|0x016e
    public:                                                                               //07-06-30|0x0170
      UINT callutil_test_write(void);                                                     //07-06-30|0x0170
#define PrecCallUtilTestWrite preccall_util.callutil_test_write                           //07-06-30|0x0170
    public:                                                                               //07-06-30|0x0172
      UINT callutil_test_report(void);                                                    //07-06-30|0x0172
#define PrecCallUtilTestReport preccall_util.callutil_test_report                         //07-06-30|0x0172
    public:                                                                               //07-06-29|0x017a
      PRECCALL_UTIL();                                                                    //07-06-29|0x017a
  };                                                                                      //10-29-97|0x0184
extern class PRECCALL_UTIL preccall_util;                                                 //98-12-29|0x0184
//*******************************************************************************         //05-24-97|0x0185
//*******************************************************************************         //05-24-97|0x0185
//****                       END OF FILE                                     ****         //05-24-97|0x0185
//*******************************************************************************         //05-24-97|0x0185
//*******************************************************************************         //05-24-97|0x0185
#endif                                                                                    //05-24-97|0x0185
