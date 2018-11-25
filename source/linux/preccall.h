//*****************************************************************************           //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
// PRECEDENCE CALL STACK                                                                  //07-06-29|0x001e
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
#include "preccallproc.h"                                                                 //07-06-29|0x0021
#include "precdiag.h"                                                                     //07-06-29|0x0022
#include "precreg.h"                                                                      //07-06-29|0x0023
#ifndef preccall_h                                                                        //07-06-29|0x0026
#define preccall_h                                                                        //07-06-29|0x0026
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
  TOKENS      args;                                                                       //07-06-29|0x0047
  STRING_DATA call_bridge;                                                                //07-06-29|0x0047
  SINT        no_includes;                                                                //07-06-29|0x0047
  UINT        stack_state;                                                                //07-06-29|0x0047
  SLONG       echo_position;                                                              //07-06-29|0x0047
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
  SLONG             drive_path_pos;                                                       //07-06-29|0x0048
  } CALL_DATA, * CALL_DATA_FAR;                                                           //07-06-29|0x0048
//-----------------------------------------------------------------------------           //07-06-29|0x0048
#endif                                                                                    //07-06-29|0x0048
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
// CLASS PRECCALL DEFINITION                                                              //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
class PRECCALL {                                                                          //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
// CLASS PRECCALL DEFINITION                                                              //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
    private:                                                                              //10-27-97|0x0058
      CALL_DATA_FAR call_data_addr;                                                       //10-27-97|0x0058
    public:                                                                               //07-06-29|0x0079
      UINT call_allocate(void);                                                           //07-06-29|0x0079
#define CallAllocate prec_call.call_allocate                                              //07-06-29|0x007b
    public:                                                                               //07-07-05|0x0097
      UINT call_free(void);                                                               //07-07-05|0x0097
#define CallFree prec_call.call_free                                                      //07-07-05|0x0098
    public:                                                                               //07-06-29|0x00b1
      UINT call_initial(TOKENS_FAR);                                                      //07-06-29|0x00b1
#define CallInitial prec_call.call_initial                                                //07-06-29|0x00b4
    public:                                                                               //07-06-29|0x00d7
      UINT copy_cmd_arg(STRING_DATA_FAR,UINT);                                            //07-06-29|0x00d7
#define CopyCmdArg prec_call.copy_cmd_arg                                                 //07-06-29|0x00da
    public:                                                                               //07-07-12|0x010a
      UINT call_cmd_parm_test(UINT);                                                      //07-07-12|0x010a
#define CallCmdParmTest prec_call.call_cmd_parm_test                                      //07-07-12|0x010d
    public:                                                                               //07-07-05|0x0139
      UINT call_exit(void);                                                               //07-07-05|0x0139
#define CallExit prec_call.call_exit                                                      //07-07-05|0x013b
    public:                                                                               //07-06-29|0x015f
      UINT call_prepush(TOKENS_FAR);                                                      //07-06-29|0x015f
#define CallPrePush prec_call.call_prepush                                                //07-06-29|0x0162
    public:                                                                               //07-06-29|0x018c
      UINT copy_src_arg(STRING_DATA_FAR,UINT,UINT_FAR);                                   //07-06-29|0x018c
#define CopySrcArg prec_call.copy_src_arg                                                 //07-06-29|0x018f
    public:                                                                               //07-07-11|0x01d9
      UINT call_src_parm_test(UINT);                                                      //07-07-11|0x01d9
#define CallSrcParmTest prec_call.call_src_parm_test                                      //07-07-11|0x01dc
    public:                                                                               //07-06-29|0x0204
      UINT call_prepop(void);                                                             //07-06-29|0x0204
#define CallPrePop prec_call.call_prepop                                                  //07-06-29|0x0206
    public:                                                                               //07-06-30|0x0230
      UINT call_srcpush(TOKENS_FAR,STRING_DATA_FAR,SINT);                                 //07-06-30|0x0230
#define CallSrcPush prec_call.call_srcpush                                                //07-06-30|0x0233
    public:                                                                               //07-07-05|0x025f
      UINT call_prelevel_test(SINT);                                                      //07-07-05|0x025f
#define CallPreLeveltest prec_call.call_prelevel_test                                     //07-07-05|0x0262
    public:                                                                               //07-07-05|0x028f
      UINT call_srcpop(void);                                                             //07-07-05|0x028f
#define CallSrcPop prec_call.call_srcpop                                                  //07-07-05|0x0291
    public:                                                                               //07-06-30|0x02bd
      UINT call_push(TOKENS_FAR,STRING_DATA_FAR,SINT);                                    //07-06-30|0x02bd
#define CallPush prec_call.call_push                                                      //07-06-30|0x02c0
    public:                                                                               //07-07-03|0x02f0
      UINT copy_arg(STRING_DATA_FAR,UINT,UINT_FAR);                                       //07-07-03|0x02f0
#define CallCopyArg prec_call.copy_arg                                                    //07-07-03|0x02f3
    public:                                                                               //07-07-11|0x0322
      UINT call_parm_test(UINT);                                                          //07-07-11|0x0322
#define CallParmTest prec_call.call_parm_test                                             //07-07-11|0x0325
    public:                                                                               //07-06-30|0x034e
      UINT get_no_parms(UINT_FAR);                                                        //07-06-30|0x034e
#define GetNoParms prec_call.get_no_parms                                                 //07-06-30|0x0351
    public:                                                                               //07-06-30|0x037a
      UINT return_store(STRING_DATA_FAR);                                                 //07-06-30|0x037a
#define CallReturnStore prec_call.return_store                                            //07-06-30|0x037d
    public:                                                                               //07-07-02|0x03a9
      UINT return_read(STRING_DATA_FAR,UINT_FAR);                                         //07-07-02|0x03a9
#define PrecReturnRead prec_call.return_read                                              //07-07-02|0x03ac
    public:                                                                               //07-07-09|0x03df
      UINT call_return_state(void);                                                       //07-07-09|0x03df
#define PrecReturnState prec_call.call_return_state                                       //07-07-09|0x03e0
    public:                                                                               //07-07-05|0x040d
      UINT copy_macro_name(STRING_DATA_FAR,SINT);                                         //07-07-05|0x040d
#define CallCopyMacroName prec_call.copy_macro_name                                       //07-07-05|0x0410
    public:                                                                               //07-06-30|0x043e
      UINT get_no_includes(SINT_FAR);                                                     //07-06-30|0x043e
#define CallGetNoIncludes prec_call.get_no_includes                                       //07-06-30|0x043f
    public:                                                                               //07-06-30|0x0465
      UINT call_return_line_no(UINT_FAR);                                                 //07-06-30|0x0465
#define CallReturnLineNo prec_call.call_return_line_no                                    //07-06-30|0x0468
    public:                                                                               //07-06-30|0x048e
      UINT call_pop(void);                                                                //07-06-30|0x048e
#define CallPop prec_call.call_pop                                                        //07-06-30|0x0490
    public:                                                                               //07-06-30|0x04b6
      UINT bridge_read(STRING_DATA_FAR);                                                  //07-06-30|0x04b6
#define CallBridgeRead prec_call.bridge_read                                              //07-06-30|0x04b9
    public:                                                                               //07-07-02|0x04df
      UINT call_return_macro_name(STRING_DATA_FAR);                                       //07-07-02|0x04df
#define CallReturnMacroName prec_call.call_return_macro_name                              //07-07-02|0x04e2
    public:                                                                               //07-06-30|0x0506
      UINT call_test_src(void);                                                           //07-06-30|0x0506
#define CallTestSrc prec_call.call_test_src                                               //07-06-30|0x0508
    public:                                                                               //07-07-07|0x053b
      UINT call_reset_macro(void);                                                        //07-07-07|0x053b
#define CallResetMacro prec_call.call_reset_macro                                         //07-07-07|0x053d
    public:                                                                               //07-07-05|0x0567
      UINT call_exit_pop(void);                                                           //07-07-05|0x0567
#define CallExitPop prec_call.call_exit_pop                                               //07-07-05|0x0569
    public:                                                                               //07-07-06|0x0593
      UINT preccall_test_reset(void);                                                     //07-07-06|0x0593
#define PrecCallTestReset prec_call.preccall_test_reset                                   //07-07-06|0x0593
    public:                                                                               //07-07-06|0x0595
      UINT preccall_test_read(void);                                                      //07-07-06|0x0595
#define PrecCallTestRead prec_call.preccall_test_read                                     //07-07-06|0x0595
    public:                                                                               //07-07-06|0x0597
      UINT preccall_test_write(void);                                                     //07-07-06|0x0597
#define PrecCallTestWrite prec_call.preccall_test_write                                   //07-07-06|0x0597
    public:                                                                               //07-07-06|0x0599
      UINT preccall_test_report(void);                                                    //07-07-06|0x0599
#define PrecCallTestReport prec_call.preccall_test_report                                 //07-07-06|0x0599
    public:                                                                               //07-06-29|0x05a1
      PRECCALL();                                                                         //07-06-29|0x05a1
  };                                                                                      //10-29-97|0x05ab
extern class PRECCALL prec_call;                                                          //98-12-29|0x05ab
//*******************************************************************************         //05-24-97|0x05ac
//*******************************************************************************         //05-24-97|0x05ac
//****                       END OF FILE                                     ****         //05-24-97|0x05ac
//*******************************************************************************         //05-24-97|0x05ac
//*******************************************************************************         //05-24-97|0x05ac
#endif                                                                                    //05-24-97|0x05ac
