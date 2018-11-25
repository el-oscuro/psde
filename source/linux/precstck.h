//*****************************************************************************           //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
// PRECEDENCE ANALYSIS STACK                                                              //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  Copyright: 2006 Robert H. Adams                                                       //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  The purpose of this program as well as instructions regarding its use is              //05-14-97|0x001c
//  defined in the associated manual.                                                     //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  This program is free software; you can redistribute it and/or modify                  //05-14-97|0x001c
//  it under the terms of the GNU General Public License as published by                  //05-14-97|0x001c
//  the Free Software Foundation; either version 2 of the License, or                     //05-14-97|0x001c
//  (at your option) any later version.                                                   //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
//  This program is distributed in the hope that it will be useful,                       //05-14-97|0x001c
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //05-14-97|0x001c
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //05-14-97|0x001c
//  GNU General Public License for more details.                                          //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
//  You should have received a copy of the GNU General Public License                     //05-14-97|0x001c
//  along with this program; if not, write to the Free Software                           //05-14-97|0x001c
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //05-14-97|0x001c
//  USA                                                                                   //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  For further information, please contact Robert Adams:                                 //05-14-97|0x001c
//     EMail:    robert.adams@whatifwe.com                                                //05-14-97|0x001c
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //05-14-97|0x001c
//  Or visit the website, "www.whatifwe.com".                                             //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
#ifndef precstck_h                                                                        //05-14-97|0x001e
#define precstck_h                                                                        //05-14-97|0x001e
//***************************************************************************             //06-07-12|0x0037
//***************************************************************************             //06-07-12|0x0038
//******                                                               ******             //06-07-12|0x0039
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x003a
//******                                                               ******             //06-07-12|0x003b
//***************************************************************************             //06-07-12|0x003c
//***************************************************************************             //06-07-12|0x003d
//*******************************************************************************         //06-07-12|0x003e
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x003e
#define STRING_DATA_Defined                                                               //06-07-12|0x003e
//-------------------------------------------------------------------------------         //06-07-12|0x003e
typedef struct {                                                                          //06-07-12|0x003e
  SCHAR   line[257];                                                                      //06-07-12|0x003e
  UINT    macro_line_no;                                                                  //06-07-12|0x003e
  UINT    type;                                                                           //06-07-12|0x003e
  UINT    start_col;                                                                      //06-07-12|0x003e
  UINT    start_call;                                                                     //06-07-12|0x003e
  SINT    length;                                                                         //06-07-12|0x003e
  SINT    position;                                                                       //06-07-12|0x003e
  SINT    column;                                                                         //06-07-12|0x003e
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x003e
//-------------------------------------------------------------------------------         //06-07-12|0x003e
#endif                                                                                    //06-07-12|0x003e
//*******************************************************************************         //06-07-12|0x003f
#ifndef TOKENS_Defined                                                                    //06-07-12|0x003f
#define TOKENS_Defined                                                                    //06-07-12|0x003f
//-------------------------------------------------------------------------------         //06-07-12|0x003f
typedef struct {                                                                          //06-07-12|0x003f
  UINT        no_tokens;                                                                  //06-07-12|0x003f
  STRING_DATA token[10];                                                                  //06-07-12|0x003f
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x003f
//-------------------------------------------------------------------------------         //06-07-12|0x003f
#endif                                                                                    //06-07-12|0x003f
//*****************************************************************************           //06-07-12|0x0040
#ifndef STACK_Defined                                                                     //06-07-12|0x0040
#define STACK_Defined                                                                     //06-07-12|0x0040
//-----------------------------------------------------------------------------           //06-07-12|0x0040
typedef struct {                                                                          //06-07-12|0x0040
  UINT        state;                                                                      //06-07-12|0x0040
  UINT        status;                                                                     //06-07-12|0x0040
  UINT        run_flag;                                                                   //06-07-12|0x0040
  WORDS       abs_pos;                                                                    //06-07-12|0x0040
  ULONG       rel_pos;                                                                    //06-07-12|0x0040
  SLONG       total_pos;                                                                  //06-07-12|0x0040
  TOKENS      macro;                                                                      //06-07-12|0x0040
  TOKENS      name;                                                                       //06-07-12|0x0040
  TOKENS      work;                                                                       //06-07-12|0x0040
  TOKENS      element;                                                                    //06-07-12|0x0040
  } STACK, * STACK_FAR;                                                                   //06-07-12|0x0040
//-----------------------------------------------------------------------------           //06-07-12|0x0040
#endif                                                                                    //06-07-12|0x0040
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
// CLASS PRECSTACK DEFINITION                                                             //05-14-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
class PRECSTACK {                                                                         //05-14-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
// CLASS PRECSTACK DEFINITION                                                             //05-14-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
//*******************************************************************************         //10-29-97|0x0048
    private:                                                                              //10-27-97|0x0051
      STACK_FAR stack_addr;                                                               //10-27-97|0x0051
    public:                                                                               //06-07-12|0x0072
      UINT stack_allocate(void);                                                          //06-07-12|0x0072
#define PrecStackAllocate prec_stack.stack_allocate                                       //06-07-12|0x0073
    public:                                                                               //06-07-12|0x008c
      UINT stack_free(void);                                                              //06-07-12|0x008c
#define PrecStackFree prec_stack.stack_free                                               //06-07-12|0x008d
    public:                                                                               //05-14-97|0x00a4
      UINT initial(void);                                                                 //05-14-97|0x00a4
#define StackInitial prec_stack.initial                                                   //05-14-97|0x00a5
    public:                                                                               //05-14-97|0x00d0
      UINT release(void);                                                                 //05-14-97|0x00d0
#define StackRelease prec_stack.release                                                   //05-14-97|0x00d1
    public:                                                                               //11-05-30|0x00ea
      UINT macro_begin(STRING_DATA_FAR,STRING_DATA_FAR);                                  //11-05-30|0x00ea
#define StackMacroBegin prec_stack.macro_begin                                            //11-05-30|0x00ec
    public:                                                                               //07-05-05|0x0148
      UINT register_stack(TOKENS_FAR,STRING_DATA_FAR);                                    //07-05-05|0x0148
#define StackRegisterStack prec_stack.register_stack                                      //07-05-05|0x014a
    public:                                                                               //07-02-26|0x01ba
      UINT macro_end(void);                                                               //07-02-26|0x01ba
#define StackMacroEnd prec_stack.macro_end                                                //07-02-26|0x01bb
    public:                                                                               //05-14-97|0x01e2
      UINT push(STRING_DATA_FAR);                                                         //05-14-97|0x01e2
#define StackPush prec_stack.push                                                         //05-14-97|0x01e3
    public:                                                                               //07-02-25|0x0232
      UINT pop(UINT);                                                                     //07-02-25|0x0232
#define StackPop prec_stack.pop                                                           //05-14-97|0x0233
    public:                                                                               //07-03-16|0x0285
      UINT get(STRING_DATA_FAR);                                                          //07-03-16|0x0285
#define StackGet prec_stack.get                                                           //07-03-16|0x0286
    public:                                                                               //07-09-13|0x02b5
      UINT stack_level(ULONG_FAR);                                                        //07-09-13|0x02b5
#define StackStackLevel prec_stack.stack_level                                            //07-09-13|0x02b7
    public:                                                                               //06-12-22|0x02e5
      UINT test_tokens(SINT,TOKENS_FAR);                                                  //06-12-22|0x02e5
#define StackTestTokens prec_stack.test_tokens                                            //06-12-22|0x02e6
    public:                                                                               //06-12-22|0x030e
      UINT test(SINT,STRING_DATA_FAR);                                                    //06-12-22|0x030e
#define StackTest prec_stack.test                                                         //05-14-97|0x030f
    public:                                                                               //05-10-15|0x034c
      UINT empty_test(void);                                                              //05-10-15|0x034c
#define StackEmptyTest prec_stack.empty_test                                              //05-10-15|0x034d
    public:                                                                               //05-10-15|0x037e
      UINT all_empty_test(void);                                                          //05-10-15|0x037e
#define StackAllEmptyTest prec_stack.all_empty_test                                       //05-10-15|0x037f
    private:                                                                              //07-03-03|0x0396
      UINT tab_string(STRING_DATA_FAR,SCHAR_FAR);                                         //07-03-03|0x0396
    private:                                                                              //07-03-03|0x03b8
      UINT tab_data(STRING_DATA_FAR,STRING_DATA_FAR);                                     //07-03-03|0x03b8
    private:                                                                              //07-03-05|0x03dc
      UINT store_stack_level(void);                                                       //07-03-05|0x03dc
    private:                                                                              //07-03-03|0x03f0
      UINT no_tokens(void);                                                               //07-03-03|0x03f0
    private:                                                                              //07-03-05|0x040e
      UINT get_elements(void);                                                            //07-03-05|0x040e
    private:                                                                              //07-03-03|0x0433
      UINT add_stack_level(SLONG);                                                        //07-03-03|0x0433
    private:                                                                              //07-03-03|0x046a
      UINT copy_string(STRING_DATA_FAR,STRING_DATA_FAR);                                  //07-03-03|0x046a
    private:                                                                              //07-03-05|0x0489
      UINT test_string(STRING_DATA_FAR,STRING_DATA_FAR);                                  //07-03-05|0x0489
    public:                                                                               //04-10-05|0x04a8
      UINT precstck_test_reset(void);                                                     //04-10-05|0x04a8
#define PrecStckTestReset prec_stack.precstck_test_reset                                  //04-10-05|0x04a8
    public:                                                                               //04-09-27|0x04aa
      UINT precstck_test_read(void);                                                      //04-09-27|0x04aa
#define PrecStckTestRead prec_stack.precstck_test_read                                    //04-09-27|0x04aa
    public:                                                                               //04-09-27|0x04ac
      UINT precstck_test_write(void);                                                     //04-09-27|0x04ac
#define PrecStckTestWrite prec_stack.precstck_test_write                                  //04-09-27|0x04ac
    public:                                                                               //04-09-27|0x04ae
      UINT precstck_test_report(void);                                                    //04-09-27|0x04ae
#define PrecStckTestReport prec_stack.precstck_test_report                                //04-09-27|0x04ae
    public:                                                                               //05-14-97|0x04b6
      PRECSTACK();                                                                        //05-14-97|0x04b6
  };                                                                                      //10-29-97|0x04bd
extern class PRECSTACK prec_stack;                                                        //98-12-29|0x04bd
//*******************************************************************************         //05-24-97|0x04be
//*******************************************************************************         //05-24-97|0x04be
//****                       END OF FILE                                     ****         //05-24-97|0x04be
//*******************************************************************************         //05-24-97|0x04be
//*******************************************************************************         //05-24-97|0x04be
#endif                                                                                    //05-24-97|0x04be
