//*****************************************************************************           //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//                                                                                        //07-06-29|0x001f
// PRECEDENCE CALL STACK PROCESS                                                          //07-06-29|0x001f
//                                                                                        //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//  The purpose of this program as well as instructions regarding its use is              //07-06-29|0x001f
//  defined in the associated manual.                                                     //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//  This program is free software; you can redistribute it and/or modify                  //07-06-29|0x001f
//  it under the terms of the GNU General Public License as published by                  //07-06-29|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //07-06-29|0x001f
//  (at your option) any later version.                                                   //07-06-29|0x001f
//                                                                                        //07-06-29|0x001f
//  This program is distributed in the hope that it will be useful,                       //07-06-29|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-06-29|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-06-29|0x001f
//  GNU General Public License for more details.                                          //07-06-29|0x001f
//                                                                                        //07-06-29|0x001f
//  You should have received a copy of the GNU General Public License                     //07-06-29|0x001f
//  along with this program; if not, write to the Free Software                           //07-06-29|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-06-29|0x001f
//  USA                                                                                   //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//  For further information, please contact Robert Adams:                                 //07-06-29|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //07-06-29|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-06-29|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
//*****************************************************************************           //07-06-29|0x001f
#include "preccallutil.h"                                                                 //07-06-29|0x0022
#include "precdiag.h"                                                                     //07-06-29|0x0023
#ifndef preccallproc_h                                                                    //07-06-29|0x0026
#define preccallproc_h                                                                    //07-06-29|0x0026
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
// CLASS PRECCALL_PROC DEFINITION                                                         //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
class PRECCALL_PROC {                                                                     //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
// CLASS PRECCALL_PROC DEFINITION                                                         //07-06-29|0x0050
//*******************************************************************************         //10-29-97|0x0050
//*******************************************************************************         //10-29-97|0x0050
    private:                                                                              //10-27-97|0x0058
      CALL_DATA_FAR call_data_addr;                                                       //10-27-97|0x0058
    public:                                                                               //07-06-29|0x0078
      UINT call_proc_construct(CALL_DATA_FAR);                                            //07-06-29|0x0078
#define CallProcConstruct preccall_proc.call_proc_construct                               //07-06-29|0x007b
    public:                                                                               //07-06-29|0x0097
      UINT callproc_initial(TOKENS_FAR);                                                  //07-06-29|0x0097
#define CallProcInitial preccall_proc.callproc_initial                                    //07-06-29|0x009a
    public:                                                                               //07-07-05|0x00d2
      UINT callproc_destroy_file(void);                                                   //07-07-05|0x00d2
#define CallProcDestroyFile preccall_proc.callproc_destroy_file                           //07-07-05|0x00d4
    public:                                                                               //07-06-29|0x00f7
       UINT callproc_get_token(STRING_DATA_FAR,UINT,UINT,SLONG);                          //07-06-29|0x00f7
#define CallProcGetToken preccall_proc.callproc_get_token                                 //07-06-29|0x00fa
    public:                                                                               //07-07-11|0x012b
      UINT callproc_test_no_token(UINT,UINT,SLONG);                                       //07-07-11|0x012b
#define CallProcTestNoToken preccall_proc.callproc_test_no_token                          //07-07-11|0x012e
    public:                                                                              //07-06-30|0x015c
      UINT callproc_get_no_tokens(UINT_FAR,UINT,SLONG);                                  //07-06-30|0x015c
#define CallProcGetNoTokens preccall_proc.callproc_get_no_tokens                          //07-06-30|0x015f
    public:                                                                               //07-06-29|0x018a
      UINT callproc_load_tokens(UINT,TOKENS_FAR);                                         //07-06-29|0x018a
#define CallProcLoadTokens preccall_proc.callproc_load_tokens                             //07-06-29|0x018d
    public:                                                                               //07-06-30|0x01b5
      UINT callproc_load_bridge(UINT,STRING_DATA_FAR);                                    //07-06-30|0x01b5
#define CallProcLoadBridge preccall_proc.callproc_load_bridge                             //07-06-30|0x01b8
    public:                                                                               //07-06-30|0x01de
      UINT callproc_load_noincludes(UINT,SINT);                                           //07-06-30|0x01de
#define CallProcLoadNoIncludes preccall_proc.callproc_load_noincludes                     //07-06-30|0x01e1
    public:                                                                               //07-06-29|0x0208
      UINT callproc_finish_push(UINT,SLONG_FAR);                                          //07-06-29|0x0208
#define CallProcFinishPush preccall_proc.callproc_finish_push                             //07-06-29|0x020b
    public:                                                                               //07-06-29|0x0236
      UINT callproc_pop_read(SLONG_FAR,UINT,SLONG);                                       //07-06-29|0x0236
#define CallProcPopRead preccall_proc.callproc_pop_read                                   //07-06-29|0x0239
    public:                                                                               //07-07-03|0x0269
      UINT callproc_test_pos(SLONG,SLONG,SLONG);                                          //07-07-03|0x0269
#define CallProcTestPos preccall_proc.callproc_test_pos                                   //07-07-03|0x026c
    public:                                                                               //07-07-02|0x028c
       UINT callproc_apndsrcmac(STRING_DATA_FAR,UINT,SLONG,UINT_FAR);                     //07-07-02|0x028c
#define CallProcAppendSrcMac preccall_proc.callproc_apndsrcmac                            //07-07-02|0x028f
    public:                                                                               //07-07-05|0x02c7
      UINT callproc_getmacroname(STRING_DATA_FAR,SINT);                                   //07-07-05|0x02c7
#define CallProcGetMacroName preccall_proc.callproc_getmacroname                          //07-07-05|0x02ca
    public:                                                                               //07-07-02|0x02f5
      UINT callproc_getreturn(STRING_DATA_FAR,UINT_FAR);                                  //07-07-02|0x02f5
#define CallProcGetReturn preccall_proc.callproc_getreturn                                //07-07-02|0x02f8
    public:                                                                               //07-06-30|0x0321
      UINT callproc_getnoincludes(SINT_FAR,SLONG);                                        //07-06-30|0x0321
#define CallProcGetNoIncludes preccall_proc.callproc_getnoincludes                        //07-06-30|0x0323
    public:                                                                               //07-06-30|0x0347
      UINT callproc_getlineno(UINT_FAR,SLONG);                                            //07-06-30|0x0347
#define CallProcGetLineNo preccall_proc.callproc_getlineno                                //07-06-30|0x0349
    public:                                                                               //07-06-30|0x036e
      UINT callproc_getbridge(STRING_DATA_FAR,SLONG);                                     //07-06-30|0x036e
#define CallProcGetBridge preccall_proc.callproc_getbridge                                //07-06-30|0x0371
    public:                                                                               //07-07-02|0x039f
      UINT callproc_returnname(STRING_DATA_FAR,SLONG);                                    //07-07-02|0x039f
#define CallProcReturnName preccall_proc.callproc_returnname                              //07-07-02|0x03a2
    public:                                                                               //06-07-14|0x03cb
      UINT preccall_test_reset(void);                                                     //06-07-14|0x03cb
#define PrecCallProcTestReset preccall_proc.preccall_test_reset                           //06-07-14|0x03cb
    public:                                                                               //06-07-14|0x03cd
      UINT preccall_test_read(void);                                                      //06-07-14|0x03cd
#define PrecCallProcTestRead preccall_proc.preccall_test_read                             //06-07-14|0x03cd
    public:                                                                               //06-07-14|0x03cf
      UINT preccall_test_write(void);                                                     //06-07-14|0x03cf
#define PrecCallProcTestWrite preccall_proc.preccall_test_write                           //06-07-14|0x03cf
    public:                                                                               //06-07-14|0x03d1
      UINT preccall_test_report(void);                                                    //06-07-14|0x03d1
#define PrecCallProcTestReport preccall_proc.preccall_test_report                         //06-07-14|0x03d1
    public:                                                                               //07-06-29|0x03d9
      PRECCALL_PROC();                                                                    //07-06-29|0x03d9
  };                                                                                      //10-29-97|0x03e3
extern class PRECCALL_PROC preccall_proc;                                                 //98-12-29|0x03e3
//*******************************************************************************         //05-24-97|0x03e4
//*******************************************************************************         //05-24-97|0x03e4
//****                       END OF FILE                                     ****         //05-24-97|0x03e4
//*******************************************************************************         //05-24-97|0x03e4
//*******************************************************************************         //05-24-97|0x03e4
#endif                                                                                    //05-24-97|0x03e4
