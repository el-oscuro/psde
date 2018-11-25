//*****************************************************************************           //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
// NUMERICAL MANAGEMENT ROUTINES                                                          //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-09-28|0x001f
//  defined in the associated manual.                                                     //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-09-28|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-09-28|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-09-28|0x001f
//  (at your option) any later version.                                                   //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-09-28|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-09-28|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-09-28|0x001f
//  GNU General Public License for more details.                                          //06-09-28|0x001f
//                                                                                        //06-09-28|0x001f
//  You should have received a copy of the GNU General Public License                     //06-09-28|0x001f
//  along with this program; if not, write to the Free Software                           //06-09-28|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-09-28|0x001f
//  USA                                                                                   //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//  For further information, please contact Robert Adams:                                 //06-09-28|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-09-28|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-09-28|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
//*****************************************************************************           //06-09-28|0x001f
#ifndef precnum_hpp                                                                       //06-09-28|0x0020
#define precnum_hpp                                                                       //06-09-28|0x0020
//***************************************************************************             //06-09-28|0x0026
//***************************************************************************             //06-09-28|0x0027
//******                                                               ******             //06-09-29|0x0028
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-09-29|0x0029
//******                                                               ******             //06-09-29|0x002a
//***************************************************************************             //06-09-29|0x002b
//***************************************************************************             //06-09-29|0x002c
//***************************************************************************             //06-09-29|0x002e
//***************************************************************************             //06-09-29|0x002f
//******                                                               ******             //06-09-29|0x0030
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-09-29|0x0031
//******                                                               ******             //06-09-29|0x0032
//***************************************************************************             //06-09-29|0x0033
//***************************************************************************             //06-09-29|0x0034
#define UserError 0x0000                                                                  //06-09-29|0x0035
#define BuildError 0x7fff                                                                 //06-09-29|0x0035
#define Display 0x7ffe                                                                    //06-09-29|0x0035
#define KeyBoard 0x7ffd                                                                   //06-09-29|0x0035
#define Success 0xffff                                                                    //06-09-29|0x0035
#define SystemError 0x8000                                                                //06-09-29|0x0035
#define Continue 0x0001                                                                   //06-09-29|0x0035
#define FileDone 0x0002                                                                   //06-09-29|0x0035
#define LineDone 0x0003                                                                   //06-09-29|0x0035
#define Yes 0x0004                                                                        //06-09-29|0x0035
#define No 0x0005                                                                         //06-09-29|0x0035
#define RepeatChar '\x6'                                                                  //06-09-29|0x0035
#define Great 0x0007                                                                      //06-09-29|0x0035
#define Equal 0x0008                                                                      //06-09-29|0x0035
#define Less 0x0009                                                                       //06-09-29|0x0035
#define Zero 0x000a                                                                       //06-09-29|0x0035
#define Minus 0x000b                                                                      //06-09-29|0x0035
//***************************************************************************             //06-09-29|0x0036
#define SystemMsg PcgSystemError("precnum", __LINE__);                                    //06-09-29|0x0037
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-09-29|0x0037
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //06-09-29|0x0037
#define _SwitchErr case UserError: return(UserError)                                      //06-09-29|0x0038
#define _SwitchOk case Success: break                                                     //06-09-29|0x0038
#define _SwitchEnd default: ReturnSystemError                                             //06-09-29|0x0038
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-09-29|0x0038
#define _SwitchYes case Yes:      return(Yes)                                             //06-09-29|0x0038
#define _SwitchNo case No:       return(No)                                               //06-09-29|0x0038
#define _SwitchGroup { _SwitchBase; }                                                     //06-09-29|0x0038
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-09-29|0x0038
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-09-29|0x0038
#define _SwitchBreak _SwitchGroup break                                                   //06-09-29|0x0038
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-09-29|0x0038
#define BreakFinish(_a) status = Finish(_a); break                                        //06-09-29|0x0039
#define ReturnFinish(_a) return(Finish(_a))                                               //06-09-29|0x0039
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-09-29|0x0039
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-09-29|0x0039
//***************************************************************************             //06-09-29|0x004d
//***************************************************************************             //06-09-29|0x004e
//******                                                               ******             //06-09-29|0x004f
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-09-29|0x0050
//******                                                               ******             //06-09-29|0x0051
//***************************************************************************             //06-09-29|0x0052
//***************************************************************************             //06-09-29|0x0053
#define TestSample(i) test_samples[i] = __LINE__                                          //06-09-29|0x0054
#define return_test(j) { TestSample(j);  return(Success); }                               //06-09-29|0x0054
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-09-29|0x0054
#define return_no(j) { TestSample(j);  return(No); }                                      //06-09-29|0x0054
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-09-29|0x0054
#define break_test(i) { TestSample(i);  break; }                                          //06-09-29|0x0054
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-09-29|0x0054
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-09-29|0x0054
//************************************************************************                //06-09-29|0x0054
#ifndef TestIndex                                                                         //06-09-29|0x0054
#define TestIndex 0                                                                       //06-09-29|0x0054
#endif                                                                                    //06-09-29|0x0054
//------------------------------------------------------------------------                //06-09-29|0x0054
enum {  NoTestSamples = TestIndex };                                                      //06-09-29|0x0054
//------------------------------------------------------------------------                //06-09-29|0x0054
#undef TestIndex                                                                          //06-09-29|0x0054
#define TestIndex NoTestSamples+1                                                         //06-09-29|0x0054
//************************************************************************                //06-09-29|0x0054
#define AddrChar(i) Addr->line[i]                                                         //06-09-29|0x0056
#define AddrLine Addr->line[0]                                                            //06-09-29|0x0056
#define AddrLineAddr &(Addr->line[0])                                                     //06-09-29|0x0056
#define AddrMacroLineNo Addr->macro_line_no                                               //06-09-29|0x0056
#define AddrType Addr->type                                                               //06-09-29|0x0056
#define AddrStartCol Addr->start_col                                                      //06-09-29|0x0056
#define AddrStartCall Addr->start_call                                                    //06-09-29|0x0056
#define AddrPosition Addr->position                                                       //06-09-29|0x0056
#define AddrLength Addr->length                                                           //06-09-29|0x0056
#define AddrColumn Addr->column                                                           //06-09-29|0x0056
//**********************************************************************                  //06-09-29|0x0056
#define WorkChar(i) work.line[i]                                                          //06-09-29|0x0057
#define WorkLine work.line[0]                                                             //06-09-29|0x0057
#define WorkLineAddr &(work.line[0])                                                      //06-09-29|0x0057
#define WorkMacroLineNo work.macro_line_no                                                //06-09-29|0x0057
#define WorkType work.type                                                                //06-09-29|0x0057
#define WorkStartCol work.start_col                                                       //06-09-29|0x0057
#define WorkStartCall work.start_call                                                     //06-09-29|0x0057
#define WorkPosition work.position                                                        //06-09-29|0x0057
#define WorkLength work.length                                                            //06-09-29|0x0057
#define WorkColumn work.column                                                            //06-09-29|0x0057
//**********************************************************************                  //06-09-29|0x0057
#define SourceChar(i) Source->line[i]                                                     //06-09-29|0x0058
#define SourceLine Source->line[0]                                                        //06-09-29|0x0058
#define SourceLineAddr &(Source->line[0])                                                 //06-09-29|0x0058
#define SourceMacroLineNo Source->macro_line_no                                           //06-09-29|0x0058
#define SourceType Source->type                                                           //06-09-29|0x0058
#define SourceStartCol Source->start_col                                                  //06-09-29|0x0058
#define SourceStartCall Source->start_call                                                //06-09-29|0x0058
#define SourcePosition Source->position                                                   //06-09-29|0x0058
#define SourceLength Source->length                                                       //06-09-29|0x0058
#define SourceColumn Source->column                                                       //06-09-29|0x0058
//**********************************************************************                  //06-09-29|0x0058
#define NumInChar0 NumIn->value.char0                                                     //06-09-29|0x0059
#define NumInByte0 NumIn->value.byte0                                                     //06-09-29|0x0059
#define NumInWord0 NumIn->value.word0                                                     //06-09-29|0x0059
#define NumInUlong NumIn->value.ulong                                                     //06-09-29|0x0059
#define NumInType NumIn->type                                                             //06-09-29|0x0059
//************************************************************************                //06-09-29|0x0059
#define NumOutChar0 NumOut->value.char0                                                   //06-09-29|0x005a
#define NumOutByte0 NumOut->value.byte0                                                   //06-09-29|0x005a
#define NumOutWord0 NumOut->value.word0                                                   //06-09-29|0x005a
#define NumOutUlong NumOut->value.ulong                                                   //06-09-29|0x005a
#define NumOutType NumOut->type                                                           //06-09-29|0x005a
//************************************************************************                //06-09-29|0x005a
#ifndef TestIndex                                                                         //04-10-05|0x0062
#define TestIndex 0                                                                       //04-10-05|0x0062
#endif                                                                                    //04-10-05|0x0062
//------------------------------------------------------------------------                //04-10-05|0x0062
enum {  numeric_text_in1 = TestIndex };                                                   //04-10-05|0x0062
//------------------------------------------------------------------------                //04-10-05|0x0062
#undef TestIndex                                                                          //04-10-05|0x0062
#define TestIndex numeric_text_in1+1                                                      //04-10-05|0x0062
//************************************************************************                //04-10-05|0x0062
#ifndef TestIndex                                                                         //04-10-05|0x0063
#define TestIndex 0                                                                       //04-10-05|0x0063
#endif                                                                                    //04-10-05|0x0063
//------------------------------------------------------------------------                //04-10-05|0x0063
enum {  numeric_text_in2 = TestIndex };                                                   //04-10-05|0x0063
//------------------------------------------------------------------------                //04-10-05|0x0063
#undef TestIndex                                                                          //04-10-05|0x0063
#define TestIndex numeric_text_in2+1                                                      //04-10-05|0x0063
//************************************************************************                //04-10-05|0x0063
#ifndef TestIndex                                                                         //04-10-05|0x0064
#define TestIndex 0                                                                       //04-10-05|0x0064
#endif                                                                                    //04-10-05|0x0064
//------------------------------------------------------------------------                //04-10-05|0x0064
enum {  numeric_text_in3 = TestIndex };                                                   //04-10-05|0x0064
//------------------------------------------------------------------------                //04-10-05|0x0064
#undef TestIndex                                                                          //04-10-05|0x0064
#define TestIndex numeric_text_in3+1                                                      //04-10-05|0x0064
//************************************************************************                //04-10-05|0x0064
#ifndef TestIndex                                                                         //04-10-05|0x0065
#define TestIndex 0                                                                       //04-10-05|0x0065
#endif                                                                                    //04-10-05|0x0065
//------------------------------------------------------------------------                //04-10-05|0x0065
enum {  numeric_text_in4 = TestIndex };                                                   //04-10-05|0x0065
//------------------------------------------------------------------------                //04-10-05|0x0065
#undef TestIndex                                                                          //04-10-05|0x0065
#define TestIndex numeric_text_in4+1                                                      //04-10-05|0x0065
//************************************************************************                //04-10-05|0x0065
#ifndef TestIndex                                                                         //04-10-05|0x0066
#define TestIndex 0                                                                       //04-10-05|0x0066
#endif                                                                                    //04-10-05|0x0066
//------------------------------------------------------------------------                //04-10-05|0x0066
enum {  numeric_text_in5 = TestIndex };                                                   //04-10-05|0x0066
//------------------------------------------------------------------------                //04-10-05|0x0066
#undef TestIndex                                                                          //04-10-05|0x0066
#define TestIndex numeric_text_in5+1                                                      //04-10-05|0x0066
//************************************************************************                //04-10-05|0x0066
#ifndef TestIndex                                                                         //04-10-05|0x0067
#define TestIndex 0                                                                       //04-10-05|0x0067
#endif                                                                                    //04-10-05|0x0067
//------------------------------------------------------------------------                //04-10-05|0x0067
enum {  numeric_text_in6 = TestIndex };                                                   //04-10-05|0x0067
//------------------------------------------------------------------------                //04-10-05|0x0067
#undef TestIndex                                                                          //04-10-05|0x0067
#define TestIndex numeric_text_in6+1                                                      //04-10-05|0x0067
//************************************************************************                //04-10-05|0x0067
#ifndef TestIndex                                                                         //04-10-05|0x009c
#define TestIndex 0                                                                       //04-10-05|0x009c
#endif                                                                                    //04-10-05|0x009c
//------------------------------------------------------------------------                //04-10-05|0x009c
enum {  numeric_out_1 = TestIndex };                                                      //04-10-05|0x009c
//------------------------------------------------------------------------                //04-10-05|0x009c
#undef TestIndex                                                                          //04-10-05|0x009c
#define TestIndex numeric_out_1+1                                                         //04-10-05|0x009c
//************************************************************************                //04-10-05|0x009c
#ifndef TestIndex                                                                         //04-10-05|0x009d
#define TestIndex 0                                                                       //04-10-05|0x009d
#endif                                                                                    //04-10-05|0x009d
//------------------------------------------------------------------------                //04-10-05|0x009d
enum {  numeric_out_2 = TestIndex };                                                      //04-10-05|0x009d
//------------------------------------------------------------------------                //04-10-05|0x009d
#undef TestIndex                                                                          //04-10-05|0x009d
#define TestIndex numeric_out_2+1                                                         //04-10-05|0x009d
//************************************************************************                //04-10-05|0x009d
#ifndef TestIndex                                                                         //04-10-05|0x009e
#define TestIndex 0                                                                       //04-10-05|0x009e
#endif                                                                                    //04-10-05|0x009e
//------------------------------------------------------------------------                //04-10-05|0x009e
enum {  numeric_out_3 = TestIndex };                                                      //04-10-05|0x009e
//------------------------------------------------------------------------                //04-10-05|0x009e
#undef TestIndex                                                                          //04-10-05|0x009e
#define TestIndex numeric_out_3+1                                                         //04-10-05|0x009e
//************************************************************************                //04-10-05|0x009e
//*******************************************************************************         //05-24-97|0x0120
//*******************************************************************************         //05-24-97|0x0120
//****                       END OF FILE                                     ****         //05-24-97|0x0120
//*******************************************************************************         //05-24-97|0x0120
//*******************************************************************************         //05-24-97|0x0120
#endif                                                                                    //05-24-97|0x0120
