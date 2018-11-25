//*****************************************************************************           //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//                                                                                        //06-07-12|0x001f
// PRECEDENCE REGISTERS                                                                   //06-07-12|0x001f
//                                                                                        //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x001f
//  defined in the associated manual.                                                     //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x001f
//  (at your option) any later version.                                                   //06-07-12|0x001f
//                                                                                        //06-07-12|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x001f
//  GNU General Public License for more details.                                          //06-07-12|0x001f
//                                                                                        //06-07-12|0x001f
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x001f
//  along with this program; if not, write to the Free Software                           //06-07-12|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x001f
//  USA                                                                                   //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//  For further information, please contact Robert Adams:                                 //06-07-12|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
//*****************************************************************************           //06-07-12|0x001f
#ifndef precreg_h                                                                         //06-07-12|0x0020
#define precreg_h                                                                         //06-07-12|0x0020
//***************************************************************************             //06-07-12|0x0039
//***************************************************************************             //06-07-12|0x003a
//******                                                               ******             //06-07-12|0x003b
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x003c
//******                                                               ******             //06-07-12|0x003d
//***************************************************************************             //06-07-12|0x003e
//***************************************************************************             //06-07-12|0x003f
//*******************************************************************************         //06-07-12|0x0040
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x0040
#define STRING_DATA_Defined                                                               //06-07-12|0x0040
//-------------------------------------------------------------------------------         //06-07-12|0x0040
typedef struct {                                                                          //06-07-12|0x0040
  SCHAR   line[257];                                                                      //06-07-12|0x0040
  UINT    macro_line_no;                                                                  //06-07-12|0x0040
  UINT    type;                                                                           //06-07-12|0x0040
  UINT    start_col;                                                                      //06-07-12|0x0040
  UINT    start_call;                                                                     //06-07-12|0x0040
  SINT    length;                                                                         //06-07-12|0x0040
  SINT    position;                                                                       //06-07-12|0x0040
  SINT    column;                                                                         //06-07-12|0x0040
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x0040
//-------------------------------------------------------------------------------         //06-07-12|0x0040
#endif                                                                                    //06-07-12|0x0040
//*******************************************************************************         //07-02-13|0x0041
#ifndef TOKENS_Defined                                                                    //07-02-13|0x0041
#define TOKENS_Defined                                                                    //07-02-13|0x0041
//-------------------------------------------------------------------------------         //07-02-13|0x0041
typedef struct {                                                                          //07-02-13|0x0041
  UINT        no_tokens;                                                                  //07-02-13|0x0041
  STRING_DATA token[10];                                                                  //07-02-13|0x0041
  } TOKENS, * TOKENS_FAR;                                                                 //07-02-13|0x0041
//-------------------------------------------------------------------------------         //07-02-13|0x0041
#endif                                                                                    //07-02-13|0x0041
//*******************************************************************************         //06-07-12|0x0042
#ifndef REGISTERS_Defined                                                                 //06-07-12|0x0042
#define REGISTERS_Defined                                                                 //06-07-12|0x0042
//-------------------------------------------------------------------------------         //06-07-12|0x0042
typedef struct {                                                                          //06-07-12|0x0042
  STRING_DATA global[26];                                                                 //06-07-12|0x0042
  STRING_DATA local[26];                                                                  //06-07-12|0x0042
  } REGISTERS, * REGISTERS_FAR;                                                           //06-07-12|0x0042
//-------------------------------------------------------------------------------         //06-07-12|0x0042
#endif                                                                                    //06-07-12|0x0042
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
// CLASS PRECREG DEFINITION                                                               //06-07-12|0x004a
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
class PRECREG {                                                                           //06-07-12|0x004a
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
// CLASS PRECREG DEFINITION                                                               //06-07-12|0x004a
//*******************************************************************************         //10-29-97|0x004a
//*******************************************************************************         //10-29-97|0x004a
    private:                                                                              //10-27-97|0x0052
      REGISTERS_FAR register_addr;                                                        //10-27-97|0x0052
    private:                                                                              //10-27-97|0x0053
      TOKENS macro;                                                                       //10-27-97|0x0053
    private:                                                                              //10-27-97|0x0054
      UINT StackLevel;                                                                    //10-27-97|0x0054
    public:                                                                               //06-07-12|0x006f
      UINT reg_allocate(void);                                                            //06-07-12|0x006f
#define PrecRegAllocate prec_reg.reg_allocate                                             //06-07-12|0x0070
    public:                                                                               //06-07-12|0x0087
      UINT reg_free(void);                                                                //06-07-12|0x0087
#define PrecRegFree prec_reg.reg_free                                                     //06-07-12|0x0088
    public:                                                                               //07-02-13|0x00a1
      UINT reg_initial(void);                                                             //07-02-13|0x00a1
#define PrecRegInitial prec_reg.reg_initial                                               //07-02-13|0x00a2
    public:                                                                               //07-05-04|0x00bc
      UINT reg_save(void);                                                                //07-05-04|0x00bc
#define PrecRegSave prec_reg.reg_save                                                     //07-05-04|0x00bd
    public:                                                                               //07-04-28|0x0112
      UINT reg_restore(void);                                                             //07-04-28|0x0112
#define PrecRegRestore prec_reg.reg_restore                                               //07-02-13|0x0113
    public:                                                                               //06-09-28|0x0167
      UINT reg_store(UINT,STRING_DATA_FAR);                                               //06-09-28|0x0167
#define PrecRegStore prec_reg.reg_store                                                   //06-09-28|0x0168
    public:                                                                               //06-09-28|0x0190
      UINT reg_read(STRING_DATA_FAR,UINT,UINT_FAR);                                       //06-09-28|0x0190
#define PrecRegRead prec_reg.reg_read                                                     //06-09-28|0x0191
    public:                                                                               //06-09-29|0x01bf
      UINT reg_clear(UINT);                                                               //06-09-29|0x01bf
#define PrecRegClear prec_reg.reg_clear                                                   //06-09-29|0x01c0
    private:                                                                              //check  |0x01dd
      UINT dict_name(SCHAR,UINT);                                                         //check  |0x01dd
    private:                                                                              //98-03-28|0x0200
      STRING_DATA_FAR reg_addr(UINT);                                                     //98-03-28|0x0200
    public:                                                                               //06-07-14|0x0225
      UINT precreg_test_reset(void);                                                      //06-07-14|0x0225
#define PrecRegTestReset prec_reg.precreg_test_reset                                      //06-07-14|0x0225
    public:                                                                               //06-07-14|0x0227
      UINT precreg_test_read(void);                                                       //06-07-14|0x0227
#define PrecRegTestRead prec_reg.precreg_test_read                                        //06-07-14|0x0227
    public:                                                                               //06-07-14|0x0229
      UINT precreg_test_write(void);                                                      //06-07-14|0x0229
#define PrecRegTestWrite prec_reg.precreg_test_write                                      //06-07-14|0x0229
    public:                                                                               //06-07-14|0x022b
      UINT precreg_test_report(void);                                                     //06-07-14|0x022b
#define PrecRegTestReport prec_reg.precreg_test_report                                    //06-07-14|0x022b
    public:                                                                               //06-07-12|0x0233
      PRECREG();                                                                          //06-07-12|0x0233
  };                                                                                      //10-29-97|0x023d
extern class PRECREG prec_reg;                                                            //98-12-29|0x023d
//*******************************************************************************         //05-24-97|0x023e
//*******************************************************************************         //05-24-97|0x023e
//****                       END OF FILE                                     ****         //05-24-97|0x023e
//*******************************************************************************         //05-24-97|0x023e
//*******************************************************************************         //05-24-97|0x023e
#endif                                                                                    //05-24-97|0x023e
