//*****************************************************************************           //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
// DEBUG PROCESSOR                                                                        //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-07-14|0x001f
//  defined in the associated manual.                                                     //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-07-14|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-07-14|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-14|0x001f
//  (at your option) any later version.                                                   //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-07-14|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-14|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-14|0x001f
//  GNU General Public License for more details.                                          //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
//  You should have received a copy of the GNU General Public License                     //06-07-14|0x001f
//  along with this program; if not, write to the Free Software                           //06-07-14|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-14|0x001f
//  USA                                                                                   //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  For further information, please contact Robert Adams:                                 //06-07-14|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-07-14|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-14|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
#ifndef precdbug_h                                                                        //06-07-14|0x0020
#define precdbug_h                                                                        //06-07-14|0x0020
//***************************************************************************             //06-07-14|0x003a
//***************************************************************************             //06-07-14|0x003b
//******                                                               ******             //06-07-14|0x003c
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-14|0x003d
//******                                                               ******             //06-07-14|0x003e
//***************************************************************************             //06-07-14|0x003f
//***************************************************************************             //06-07-14|0x0040
//*******************************************************************************         //06-07-14|0x0041
#ifndef ARITH_DATA_Defined                                                                //06-07-14|0x0041
#define ARITH_DATA_Defined                                                                //06-07-14|0x0041
//-------------------------------------------------------------------------------         //06-07-14|0x0041
typedef struct {                                                                          //06-07-14|0x0041
  WORDS value;                                                                            //06-07-14|0x0041
  UINT  type;                                                                             //06-07-14|0x0041
  } ARITH_DATA, * ARITH_DATA_FAR;                                                         //06-07-14|0x0041
//-------------------------------------------------------------------------------         //06-07-14|0x0041
#endif                                                                                    //06-07-14|0x0041
//*******************************************************************************         //06-07-14|0x0042
#ifndef STRING_DATA_Defined                                                               //06-07-14|0x0042
#define STRING_DATA_Defined                                                               //06-07-14|0x0042
//-------------------------------------------------------------------------------         //06-07-14|0x0042
typedef struct {                                                                          //06-07-14|0x0042
  SCHAR   line[257];                                                                      //06-07-14|0x0042
  UINT    macro_line_no;                                                                  //06-07-14|0x0042
  UINT    type;                                                                           //06-07-14|0x0042
  UINT    start_col;                                                                      //06-07-14|0x0042
  UINT    start_call;                                                                     //06-07-14|0x0042
  SINT    length;                                                                         //06-07-14|0x0042
  SINT    position;                                                                       //06-07-14|0x0042
  SINT    column;                                                                         //06-07-14|0x0042
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-14|0x0042
//-------------------------------------------------------------------------------         //06-07-14|0x0042
#endif                                                                                    //06-07-14|0x0042
//*******************************************************************************         //06-07-14|0x0043
#ifndef TOKENS_Defined                                                                    //06-07-14|0x0043
#define TOKENS_Defined                                                                    //06-07-14|0x0043
//-------------------------------------------------------------------------------         //06-07-14|0x0043
typedef struct {                                                                          //06-07-14|0x0043
  UINT        no_tokens;                                                                  //06-07-14|0x0043
  STRING_DATA token[10];                                                                  //06-07-14|0x0043
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-14|0x0043
//-------------------------------------------------------------------------------         //06-07-14|0x0043
#endif                                                                                    //06-07-14|0x0043
#ifndef PROCESS_DATA_Defined                                                              //06-07-14|0x0044
#define PROCESS_DATA_Defined                                                              //06-07-14|0x0044
//-------------------------------------------------------------------------------         //06-07-14|0x0044
typedef struct {                                                                          //06-07-14|0x0044
  UINT          call_return_status;                                                       //06-07-14|0x0044
  UINT          call_return_run_flag;                                                     //06-07-14|0x0044
  UINT          call_return_state;                                                        //06-07-14|0x0044
  UINT          process_command;                                                          //06-07-14|0x0044
  UINT          debug_command;                                                            //06-07-14|0x0044
  SINT          out_buffer_state;                                                         //06-07-14|0x0044
  SINT          in_buffer_state;                                                          //06-07-14|0x0044
  SINT          flag_state;                                                               //06-07-14|0x0044
  SINT          rule_state;                                                               //06-07-14|0x0044
  UINT          process_state;                                                            //06-07-14|0x0044
  UINT          run_flag;                                                                 //06-07-14|0x0044
  UINT          status;                                                                   //06-07-14|0x0044
  STRING_DATA   class_name;                                                               //06-07-14|0x0044
  STRING_DATA   bridge_name;                                                              //06-07-14|0x0044
  STRING_DATA   buffer;                                                                   //06-07-14|0x0044
  STRING_DATA   utility_bridge;                                                           //06-07-14|0x0044
  STRING_DATA   macro_name;                                                               //06-07-14|0x0044
  STRING_DATA   debug_name;                                                               //06-07-14|0x0044
  STRING_DATA   results;                                                                  //06-07-14|0x0044
  TOKENS        dict;                                                                     //06-07-14|0x0044
  TOKENS        tokens;                                                                   //06-07-14|0x0044
  ARITH_DATA    parm_num;                                                                 //06-07-14|0x0044
  ARITH_DATA    result_num;                                                               //06-07-14|0x0044
  } PROCESS_DATA, * PROCESS_DATA_FAR;                                                     //06-07-14|0x0044
//-------------------------------------------------------------------------------         //06-07-14|0x0044
#endif                                                                                    //06-07-14|0x0044
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
// CLASS PRECDBUG DEFINITION                                                              //06-07-14|0x004c
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
class PRECDBUG {                                                                          //06-07-14|0x004c
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
// CLASS PRECDBUG DEFINITION                                                              //06-07-14|0x004c
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
    private:                                                                              //10-27-97|0x004f
      UINT DebugState;                                                                    //10-27-97|0x004f
    private:                                                                              //10-27-97|0x0050
      UINT MenuState;                                                                     //10-27-97|0x0050
    private:                                                                              //10-27-97|0x0051
      UINT Status;                                                                        //10-27-97|0x0051
    private:                                                                              //10-27-97|0x0052
      UINT RunFlag;                                                                       //10-27-97|0x0052
    public:                                                                               //06-09-26|0x0071
      UINT dbug_command(PROCESS_DATA_FAR);                                                //06-09-26|0x0071
#define PrecDbugCmd prec_dbug.dbug_command                                                //06-09-26|0x0073
    public:                                                                               //06-11-06|0x00c9
      UINT menu_cmd(void);                                                                //06-11-06|0x00c9
#define PrecMenuCmd prec_dbug.menu_cmd                                                    //06-11-06|0x00ca
    private:                                                                              //06-10-01|0x00ec
      UINT debug_message(PROCESS_DATA_FAR);                                               //06-10-01|0x00ec
    public:                                                                               //06-10-01|0x0107
      UINT debug_trace(PROCESS_DATA_FAR);                                                 //06-10-01|0x0107
#define PrecDbugTrace prec_dbug.debug_trace                                               //06-10-01|0x0109
    private:                                                                              //06-10-01|0x0143
      UINT command_arg(PROCESS_DATA_FAR);                                                 //06-10-01|0x0143
    private:                                                                              //06-10-02|0x0169
      UINT display_results(PROCESS_DATA_FAR);                                             //06-10-02|0x0169
    private:                                                                              //06-10-02|0x0184
      UINT display_flag(PROCESS_DATA_FAR);                                                //06-10-02|0x0184
    private:                                                                              //06-11-06|0x01a6
      UINT debug_pause(PROCESS_DATA_FAR);                                                 //06-11-06|0x01a6
    private:                                                                              //06-11-06|0x01c6
      UINT menu_pause(void);                                                              //06-11-06|0x01c6
    public:                                                                               //<----   |0x0204
      UINT breakpoint(SCHAR_FAR,SWORD);                                                   //<----   |0x0204
#define Breakpoint prec_dbug.breakpoint                                                   //<----   |0x0206
    public:                                                                               //06-07-14|0x0222
      UINT precdbug_test_reset(void);                                                     //06-07-14|0x0222
#define PrecDbugTestReset prec_dbug.precdbug_test_reset                                   //06-07-14|0x0222
    public:                                                                               //06-07-14|0x0224
      UINT precdbug_test_read(void);                                                      //06-07-14|0x0224
#define PrecDbugTestRead prec_dbug.precdbug_test_read                                     //06-07-14|0x0224
    public:                                                                               //06-07-14|0x0226
      UINT precdbug_test_write(void);                                                     //06-07-14|0x0226
#define PrecDbugTestWrite prec_dbug.precdbug_test_write                                   //06-07-14|0x0226
    public:                                                                               //06-07-14|0x0228
      UINT precdbug_test_report(void);                                                    //06-07-14|0x0228
#define PrecDbugTestReport prec_dbug.precdbug_test_report                                 //06-07-14|0x0228
    public:                                                                               //06-07-14|0x0230
      PRECDBUG();                                                                         //06-07-14|0x0230
  };                                                                                      //10-29-97|0x023b
extern class PRECDBUG prec_dbug;                                                          //98-12-29|0x023b
//*******************************************************************************         //05-24-97|0x023c
//*******************************************************************************         //05-24-97|0x023c
//****                       END OF FILE                                     ****         //05-24-97|0x023c
//*******************************************************************************         //05-24-97|0x023c
//*******************************************************************************         //05-24-97|0x023c
#endif                                                                                    //05-24-97|0x023c
