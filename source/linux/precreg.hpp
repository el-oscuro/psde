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
#ifndef precreg_hpp                                                                       //06-07-12|0x0020
#define precreg_hpp                                                                       //06-07-12|0x0020
//***************************************************************************             //06-07-12|0x0024
//***************************************************************************             //06-07-12|0x0025
//******                                                               ******             //06-07-12|0x0026
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0027
//******                                                               ******             //06-07-12|0x0028
//***************************************************************************             //06-07-12|0x0029
//***************************************************************************             //06-07-12|0x002a
//***************************************************************************             //06-07-12|0x002d
//***************************************************************************             //06-07-12|0x002e
//******                                                               ******             //06-07-12|0x002f
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x0030
//******                                                               ******             //06-07-12|0x0031
//***************************************************************************             //06-07-12|0x0032
//***************************************************************************             //06-07-12|0x0033
#define UserError 0x0000                                                                  //06-07-12|0x0034
#define BuildError 0x7fff                                                                 //06-07-12|0x0034
#define Display 0x7ffe                                                                    //06-07-12|0x0034
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x0034
#define Success 0xffff                                                                    //06-07-12|0x0034
#define SystemError 0x8000                                                                //06-07-12|0x0034
#define Continue 0x0001                                                                   //06-07-12|0x0034
#define FileDone 0x0002                                                                   //06-07-12|0x0034
#define LineDone 0x0003                                                                   //06-07-12|0x0034
#define Yes 0x0004                                                                        //06-07-12|0x0034
#define No 0x0005                                                                         //06-07-12|0x0034
#define RepeatChar '\x6'                                                                  //06-07-12|0x0034
#define Great 0x0007                                                                      //06-07-12|0x0034
#define Equal 0x0008                                                                      //06-07-12|0x0034
#define Less 0x0009                                                                       //06-07-12|0x0034
#define Zero 0x000a                                                                       //06-07-12|0x0034
#define Minus 0x000b                                                                      //06-07-12|0x0034
//***************************************************************************             //06-07-12|0x0035
#define SystemMsg PcgSystemError("precreg", __LINE__);                                    //06-07-12|0x0036
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x0036
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //06-07-12|0x0036
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0037
#define _SwitchOk case Success: break                                                     //06-07-12|0x0037
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0037
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0037
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0037
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0037
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0037
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0037
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0037
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0037
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0037
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0038
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0038
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0038
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0038
//***************************************************************************             //06-07-12|0x0055
//***************************************************************************             //06-07-12|0x0056
//******                                                               ******             //06-07-12|0x0057
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0058
//******                                                               ******             //06-07-12|0x0059
//***************************************************************************             //06-07-12|0x005a
//***************************************************************************             //06-07-12|0x005b
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x005c
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x005c
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x005c
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x005c
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x005c
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x005c
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x005c
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x005c
//************************************************************************                //06-07-12|0x005c
#ifndef TestIndex                                                                         //06-07-12|0x005c
#define TestIndex 0                                                                       //06-07-12|0x005c
#endif                                                                                    //06-07-12|0x005c
//------------------------------------------------------------------------                //06-07-12|0x005c
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x005c
//------------------------------------------------------------------------                //06-07-12|0x005c
#undef TestIndex                                                                          //06-07-12|0x005c
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x005c
//************************************************************************                //06-07-12|0x005c
#define RetParm 0                                                                         //06-07-12|0x005e
#define CallParm 1                                                                        //06-07-12|0x005e
#define PermReg 10                                                                        //06-07-12|0x005e
#define OnceReg 36                                                                        //06-07-12|0x005e
#define ProjParm 62                                                                       //06-07-12|0x005e
#define CmdLnParm 72                                                                      //06-07-12|0x005e
#define ErrorParm 82                                                                      //06-07-12|0x005e
//************************************************************************                //06-07-12|0x005e
//************************************************************************                //07-02-13|0x0060
#define MacroTokenAddr(i) &(macro.token[i])                                               //07-02-13|0x0060
#define MacroMacroLineNo(i) macro.token[i].macro_line_no                                  //07-02-13|0x0060
#define MacroLineAddr(i) &(macro.token[i].line[0])                                        //07-02-13|0x0060
#define MacroToken(i) macro.token[i]                                                      //07-02-13|0x0060
#define MacroLine(i) macro.token[i].line                                                  //07-02-13|0x0060
#define MacroLength(i) macro.token[i].length                                              //07-02-13|0x0060
#define MacroColumn(i) macro.token[i].column                                              //07-02-13|0x0060
#define MacroHash(i) macro.token[i].hash                                                  //07-02-13|0x0060
#define MacroPosition(i) macro.token[i].position                                          //07-02-13|0x0060
#define MacroType(i) macro.token[i].type                                                  //07-02-13|0x0060
#define MacroStartCol(i) macro.token[i].start_col                                         //07-02-13|0x0060
#define MacroStartCall(i) macro.token[i].start_call                                       //07-02-13|0x0060
#define MacroChar(i,j) macro.token[i].line[j]                                             //07-02-13|0x0060
#define MacroNoTokens macro.no_tokens                                                     //07-02-13|0x0060
#define InputChar(i) Input->line[i]                                                       //07-02-13|0x0061
#define InputLine Input->line[0]                                                          //07-02-13|0x0061
#define InputLineAddr &(Input->line[0])                                                   //07-02-13|0x0061
#define InputMacroLineNo Input->macro_line_no                                             //07-02-13|0x0061
#define InputType Input->type                                                             //07-02-13|0x0061
#define InputStartCol Input->start_col                                                    //07-02-13|0x0061
#define InputStartCall Input->start_call                                                  //07-02-13|0x0061
#define InputPosition Input->position                                                     //07-02-13|0x0061
#define InputLength Input->length                                                         //07-02-13|0x0061
#define InputColumn Input->column                                                         //07-02-13|0x0061
//**********************************************************************                  //07-02-13|0x0061
#define FlagsChar(i) flags.line[i]                                                        //07-02-13|0x0062
#define FlagsLine flags.line[0]                                                           //07-02-13|0x0062
#define FlagsLineAddr &(flags.line[0])                                                    //07-02-13|0x0062
#define FlagsMacroLineNo flags.macro_line_no                                              //07-02-13|0x0062
#define FlagsType flags.type                                                              //07-02-13|0x0062
#define FlagsStartCol flags.start_col                                                     //07-02-13|0x0062
#define FlagsStartCall flags.start_call                                                   //07-02-13|0x0062
#define FlagsPosition flags.position                                                      //07-02-13|0x0062
#define FlagsLength flags.length                                                          //07-02-13|0x0062
#define FlagsColumn flags.column                                                          //07-02-13|0x0062
//**********************************************************************                  //07-02-13|0x0062
#define AddrChar(i) addr->line[i]                                                         //06-07-12|0x0063
#define AddrLine addr->line[0]                                                            //06-07-12|0x0063
#define AddrLineAddr &(addr->line[0])                                                     //06-07-12|0x0063
#define AddrMacroLineNo addr->macro_line_no                                               //06-07-12|0x0063
#define AddrType addr->type                                                               //06-07-12|0x0063
#define AddrStartCol addr->start_col                                                      //06-07-12|0x0063
#define AddrStartCall addr->start_call                                                    //06-07-12|0x0063
#define AddrPosition addr->position                                                       //06-07-12|0x0063
#define AddrLength addr->length                                                           //06-07-12|0x0063
#define AddrColumn addr->column                                                           //06-07-12|0x0063
//**********************************************************************                  //06-07-12|0x0063
#define WorkChar(i) Work->line[i]                                                         //06-07-12|0x0064
#define WorkLine Work->line[0]                                                            //06-07-12|0x0064
#define WorkLineAddr &(Work->line[0])                                                     //06-07-12|0x0064
#define WorkMacroLineNo Work->macro_line_no                                               //06-07-12|0x0064
#define WorkType Work->type                                                               //06-07-12|0x0064
#define WorkStartCol Work->start_col                                                      //06-07-12|0x0064
#define WorkStartCall Work->start_call                                                    //06-07-12|0x0064
#define WorkPosition Work->position                                                       //06-07-12|0x0064
#define WorkLength Work->length                                                           //06-07-12|0x0064
#define WorkColumn Work->column                                                           //06-07-12|0x0064
//**********************************************************************                  //06-07-12|0x0064
#ifndef TestIndex                                                                         //06-07-12|0x006c
#define TestIndex 0                                                                       //06-07-12|0x006c
#endif                                                                                    //06-07-12|0x006c
//------------------------------------------------------------------------                //06-07-12|0x006c
enum {  reg_allocate_1 = TestIndex };                                                     //06-07-12|0x006c
//------------------------------------------------------------------------                //06-07-12|0x006c
#undef TestIndex                                                                          //06-07-12|0x006c
#define TestIndex reg_allocate_1+1                                                        //06-07-12|0x006c
//************************************************************************                //06-07-12|0x006c
#ifndef TestIndex                                                                         //06-07-12|0x0084
#define TestIndex 0                                                                       //06-07-12|0x0084
#endif                                                                                    //06-07-12|0x0084
//------------------------------------------------------------------------                //06-07-12|0x0084
enum {  reg_free_1 = TestIndex };                                                         //06-07-12|0x0084
//------------------------------------------------------------------------                //06-07-12|0x0084
#undef TestIndex                                                                          //06-07-12|0x0084
#define TestIndex reg_free_1+1                                                            //06-07-12|0x0084
//************************************************************************                //06-07-12|0x0084
#ifndef TestIndex                                                                         //07-02-13|0x009e
#define TestIndex 0                                                                       //07-02-13|0x009e
#endif                                                                                    //07-02-13|0x009e
//------------------------------------------------------------------------                //07-02-13|0x009e
enum {  reg_initial_1 = TestIndex };                                                      //07-02-13|0x009e
//------------------------------------------------------------------------                //07-02-13|0x009e
#undef TestIndex                                                                          //07-02-13|0x009e
#define TestIndex reg_initial_1+1                                                         //07-02-13|0x009e
//************************************************************************                //07-02-13|0x009e
#ifndef TestIndex                                                                         //07-02-13|0x00b9
#define TestIndex 0                                                                       //07-02-13|0x00b9
#endif                                                                                    //07-02-13|0x00b9
//------------------------------------------------------------------------                //07-02-13|0x00b9
enum {  reg_save_1 = TestIndex };                                                         //07-02-13|0x00b9
//------------------------------------------------------------------------                //07-02-13|0x00b9
#undef TestIndex                                                                          //07-02-13|0x00b9
#define TestIndex reg_save_1+1                                                            //07-02-13|0x00b9
//************************************************************************                //07-02-13|0x00b9
#ifndef TestIndex                                                                         //07-02-13|0x010e
#define TestIndex 0                                                                       //07-02-13|0x010e
#endif                                                                                    //07-02-13|0x010e
//------------------------------------------------------------------------                //07-02-13|0x010e
enum {  reg_restore_1 = TestIndex };                                                      //07-02-13|0x010e
//------------------------------------------------------------------------                //07-02-13|0x010e
#undef TestIndex                                                                          //07-02-13|0x010e
#define TestIndex reg_restore_1+1                                                         //07-02-13|0x010e
//************************************************************************                //07-02-13|0x010e
#ifndef TestIndex                                                                         //07-02-13|0x010f
#define TestIndex 0                                                                       //07-02-13|0x010f
#endif                                                                                    //07-02-13|0x010f
//------------------------------------------------------------------------                //07-02-13|0x010f
enum {  reg_restore_2 = TestIndex };                                                      //07-02-13|0x010f
//------------------------------------------------------------------------                //07-02-13|0x010f
#undef TestIndex                                                                          //07-02-13|0x010f
#define TestIndex reg_restore_2+1                                                         //07-02-13|0x010f
//************************************************************************                //07-02-13|0x010f
#ifndef TestIndex                                                                         //06-09-28|0x0164
#define TestIndex 0                                                                       //06-09-28|0x0164
#endif                                                                                    //06-09-28|0x0164
//------------------------------------------------------------------------                //06-09-28|0x0164
enum {  reg_store_1 = TestIndex };                                                        //06-09-28|0x0164
//------------------------------------------------------------------------                //06-09-28|0x0164
#undef TestIndex                                                                          //06-09-28|0x0164
#define TestIndex reg_store_1+1                                                           //06-09-28|0x0164
//************************************************************************                //06-09-28|0x0164
#ifndef TestIndex                                                                         //06-09-28|0x018d
#define TestIndex 0                                                                       //06-09-28|0x018d
#endif                                                                                    //06-09-28|0x018d
//------------------------------------------------------------------------                //06-09-28|0x018d
enum {  reg_read_1 = TestIndex };                                                         //06-09-28|0x018d
//------------------------------------------------------------------------                //06-09-28|0x018d
#undef TestIndex                                                                          //06-09-28|0x018d
#define TestIndex reg_read_1+1                                                            //06-09-28|0x018d
//************************************************************************                //06-09-28|0x018d
#ifndef TestIndex                                                                         //06-09-29|0x01bc
#define TestIndex 0                                                                       //06-09-29|0x01bc
#endif                                                                                    //06-09-29|0x01bc
//------------------------------------------------------------------------                //06-09-29|0x01bc
enum {  reg_clear_1 = TestIndex };                                                        //06-09-29|0x01bc
//------------------------------------------------------------------------                //06-09-29|0x01bc
#undef TestIndex                                                                          //06-09-29|0x01bc
#define TestIndex reg_clear_1+1                                                           //06-09-29|0x01bc
//************************************************************************                //06-09-29|0x01bc
#ifndef TestIndex                                                                         //07-03-21|0x01da
#define TestIndex 0                                                                       //07-03-21|0x01da
#endif                                                                                    //07-03-21|0x01da
//------------------------------------------------------------------------                //07-03-21|0x01da
enum {  dict_name_1 = TestIndex };                                                        //07-03-21|0x01da
//------------------------------------------------------------------------                //07-03-21|0x01da
#undef TestIndex                                                                          //07-03-21|0x01da
#define TestIndex dict_name_1+1                                                           //07-03-21|0x01da
//************************************************************************                //07-03-21|0x01da
#ifndef TestIndex                                                                         //06-09-28|0x01fb
#define TestIndex 0                                                                       //06-09-28|0x01fb
#endif                                                                                    //06-09-28|0x01fb
//------------------------------------------------------------------------                //06-09-28|0x01fb
enum {  reg_addr_1 = TestIndex };                                                         //06-09-28|0x01fb
//------------------------------------------------------------------------                //06-09-28|0x01fb
#undef TestIndex                                                                          //06-09-28|0x01fb
#define TestIndex reg_addr_1+1                                                            //06-09-28|0x01fb
//************************************************************************                //06-09-28|0x01fb
#ifndef TestIndex                                                                         //06-09-28|0x01fc
#define TestIndex 0                                                                       //06-09-28|0x01fc
#endif                                                                                    //06-09-28|0x01fc
//------------------------------------------------------------------------                //06-09-28|0x01fc
enum {  reg_addr_2 = TestIndex };                                                         //06-09-28|0x01fc
//------------------------------------------------------------------------                //06-09-28|0x01fc
#undef TestIndex                                                                          //06-09-28|0x01fc
#define TestIndex reg_addr_2+1                                                            //06-09-28|0x01fc
//************************************************************************                //06-09-28|0x01fc
#ifndef TestIndex                                                                         //06-09-28|0x01fd
#define TestIndex 0                                                                       //06-09-28|0x01fd
#endif                                                                                    //06-09-28|0x01fd
//------------------------------------------------------------------------                //06-09-28|0x01fd
enum {  reg_addr_3 = TestIndex };                                                         //06-09-28|0x01fd
//------------------------------------------------------------------------                //06-09-28|0x01fd
#undef TestIndex                                                                          //06-09-28|0x01fd
#define TestIndex reg_addr_3+1                                                            //06-09-28|0x01fd
//************************************************************************                //06-09-28|0x01fd
//*******************************************************************************         //05-24-97|0x023e
//*******************************************************************************         //05-24-97|0x023e
//****                       END OF FILE                                     ****         //05-24-97|0x023e
//*******************************************************************************         //05-24-97|0x023e
//*******************************************************************************         //05-24-97|0x023e
#endif                                                                                    //05-24-97|0x023e
