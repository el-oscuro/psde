//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
// MAILBOX DICTIONARY_MANAGER                                                             //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-11-09|0x000b
//  defined in the associated manual.                                                     //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-11-09|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-11-09|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-11-09|0x000b
//  (at your option) any later version.                                                   //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-11-09|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-11-09|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-11-09|0x000b
//  GNU General Public License for more details.                                          //07-11-09|0x000b
//                                                                                        //07-11-09|0x000b
//  You should have received a copy of the GNU General Public License                     //07-11-09|0x000b
//  along with this program; if not, write to the Free Software                           //07-11-09|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-11-09|0x000b
//  USA                                                                                   //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//  For further information, please contact Robert Adams:                                 //07-11-09|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-11-09|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-11-09|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
//*****************************************************************************           //07-11-09|0x000b
#ifndef errormail_hpp                                                                     //07-11-09|0x000c
#define errormail_hpp                                                                     //07-11-09|0x000c
//***************************************************************************             //07-11-09|0x000e
//***************************************************************************             //07-11-09|0x000f
//******                                                               ******             //07-11-09|0x0010
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //07-11-09|0x0011
//******                                                               ******             //07-11-09|0x0012
//***************************************************************************             //07-11-09|0x0013
//***************************************************************************             //07-11-09|0x0014
//***************************************************************************             //07-11-09|0x0017
//***************************************************************************             //07-11-09|0x0018
//******                                                               ******             //07-11-09|0x0019
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //07-11-09|0x001a
//******                                                               ******             //07-11-09|0x001b
//***************************************************************************             //07-11-09|0x001c
//***************************************************************************             //07-11-09|0x001d
#define UserError 0x0000                                                                  //07-11-09|0x001e
#define BuildError 0x7fff                                                                 //07-11-09|0x001e
#define Display 0x7ffe                                                                    //07-11-09|0x001e
#define KeyBoard 0x7ffd                                                                   //07-11-09|0x001e
#define Success 0xffff                                                                    //07-11-09|0x001e
#define SystemError 0x8000                                                                //07-11-09|0x001e
#define Continue 0x0001                                                                   //07-11-09|0x001e
#define FileDone 0x0002                                                                   //07-11-09|0x001e
#define LineDone 0x0003                                                                   //07-11-09|0x001e
#define Yes 0x0004                                                                        //07-11-09|0x001e
#define No 0x0005                                                                         //07-11-09|0x001e
#define RepeatChar '\x6'                                                                  //07-11-09|0x001e
#define Great 0x0007                                                                      //07-11-09|0x001e
#define Equal 0x0008                                                                      //07-11-09|0x001e
#define Less 0x0009                                                                       //07-11-09|0x001e
#define Zero 0x000a                                                                       //07-11-09|0x001e
#define Minus 0x000b                                                                      //07-11-09|0x001e
//***************************************************************************             //07-11-09|0x001f
#define SystemMsg PcgSystemError("ErrorMail", __LINE__);                                  //07-11-09|0x0020
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-11-09|0x0020
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //07-11-09|0x0020
#define BreakFinish(_a) status = Finish(_a); break                                        //07-11-09|0x0021
#define ReturnFinish(_a) return(Finish(_a))                                               //07-11-09|0x0021
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //07-11-09|0x0021
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //07-11-09|0x0021
#define _SwitchErr case UserError: return(UserError)                                      //07-11-09|0x0022
#define _SwitchOk case Success: break                                                     //07-11-09|0x0022
#define _SwitchEnd default: ReturnSystemError                                             //07-11-09|0x0022
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-11-09|0x0022
#define _SwitchYes case Yes:      return(Yes)                                             //07-11-09|0x0022
#define _SwitchNo case No:       return(No)                                               //07-11-09|0x0022
#define _SwitchGroup { _SwitchBase; }                                                     //07-11-09|0x0022
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-11-09|0x0022
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-11-09|0x0022
#define _SwitchBreak _SwitchGroup break                                                   //07-11-09|0x0022
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-11-09|0x0022
//***************************************************************************             //07-11-09|0x003c
//***************************************************************************             //07-11-09|0x003d
//******                                                               ******             //07-11-09|0x003e
//******               GENERAL DEFINITION STATEMENTS                   ******             //07-11-09|0x003f
//******                                                               ******             //07-11-09|0x0040
//***************************************************************************             //07-11-09|0x0041
//***************************************************************************             //07-11-09|0x0042
#define TestSample(i) test_samples[i] = __LINE__                                          //07-11-09|0x0043
#define return_test(j) { TestSample(j);  return(Success); }                               //07-11-09|0x0043
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //07-11-09|0x0043
#define return_no(j) { TestSample(j);  return(No); }                                      //07-11-09|0x0043
#define goto_test(i) { TestSample(i);  goto loop; }                                       //07-11-09|0x0043
#define break_test(i) { TestSample(i);  break; }                                          //07-11-09|0x0043
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //07-11-09|0x0043
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //07-11-09|0x0043
//************************************************************************                //07-11-09|0x0043
#ifndef TestIndex                                                                         //07-11-09|0x0043
#define TestIndex 0                                                                       //07-11-09|0x0043
#endif                                                                                    //07-11-09|0x0043
//------------------------------------------------------------------------                //07-11-09|0x0043
enum {  NoTestSamples = TestIndex };                                                      //07-11-09|0x0043
//------------------------------------------------------------------------                //07-11-09|0x0043
#undef TestIndex                                                                          //07-11-09|0x0043
#define TestIndex NoTestSamples+1                                                         //07-11-09|0x0043
//************************************************************************                //07-11-09|0x0043
//***************************************************************************             //07-11-09|0x0044
//************************************************************************                //07-11-09|0x0045
#define TokensTokenAddr(i) &(error_tokens.token[i])                                       //07-11-09|0x0045
#define TokensMacroLineNo(i) error_tokens.token[i].macro_line_no                          //07-11-09|0x0045
#define TokensLineAddr(i) &(error_tokens.token[i].line[0])                                //07-11-09|0x0045
#define TokensToken(i) error_tokens.token[i]                                              //07-11-09|0x0045
#define TokensLine(i) error_tokens.token[i].line                                          //07-11-09|0x0045
#define TokensLength(i) error_tokens.token[i].length                                      //07-11-09|0x0045
#define TokensColumn(i) error_tokens.token[i].column                                      //07-11-09|0x0045
#define TokensHash(i) error_tokens.token[i].hash                                          //07-11-09|0x0045
#define TokensPosition(i) error_tokens.token[i].position                                  //07-11-09|0x0045
#define TokensType(i) error_tokens.token[i].type                                          //07-11-09|0x0045
#define TokensStartCol(i) error_tokens.token[i].start_col                                 //07-11-09|0x0045
#define TokensStartCall(i) error_tokens.token[i].start_call                               //07-11-09|0x0045
#define TokensChar(i,j) error_tokens.token[i].line[j]                                     //07-11-09|0x0045
#define TokensNoTokens error_tokens.no_tokens                                             //07-11-09|0x0045
#define AddrChar(i) Addr->line[i]                                                         //07-11-09|0x0046
#define AddrLine Addr->line[0]                                                            //07-11-09|0x0046
#define AddrLineAddr &(Addr->line[0])                                                     //07-11-09|0x0046
#define AddrMacroLineNo Addr->macro_line_no                                               //07-11-09|0x0046
#define AddrType Addr->type                                                               //07-11-09|0x0046
#define AddrStartCol Addr->start_col                                                      //07-11-09|0x0046
#define AddrStartCall Addr->start_call                                                    //07-11-09|0x0046
#define AddrPosition Addr->position                                                       //07-11-09|0x0046
#define AddrLength Addr->length                                                           //07-11-09|0x0046
#define AddrColumn Addr->column                                                           //07-11-09|0x0046
//**********************************************************************                  //07-11-09|0x0046
#ifndef TestIndex                                                                         //07-11-12|0x0050
#define TestIndex 0                                                                       //07-11-12|0x0050
#endif                                                                                    //07-11-12|0x0050
//------------------------------------------------------------------------                //07-11-12|0x0050
enum {  errormail_add_macro_1 = TestIndex };                                              //07-11-12|0x0050
//------------------------------------------------------------------------                //07-11-12|0x0050
#undef TestIndex                                                                          //07-11-12|0x0050
#define TestIndex errormail_add_macro_1+1                                                 //07-11-12|0x0050
//************************************************************************                //07-11-12|0x0050
#ifndef TestIndex                                                                         //07-11-12|0x006d
#define TestIndex 0                                                                       //07-11-12|0x006d
#endif                                                                                    //07-11-12|0x006d
//------------------------------------------------------------------------                //07-11-12|0x006d
enum {  errormail_add_error_1 = TestIndex };                                              //07-11-12|0x006d
//------------------------------------------------------------------------                //07-11-12|0x006d
#undef TestIndex                                                                          //07-11-12|0x006d
#define TestIndex errormail_add_error_1+1                                                 //07-11-12|0x006d
//************************************************************************                //07-11-12|0x006d
#ifndef TestIndex                                                                         //07-11-17|0x008b
#define TestIndex 0                                                                       //07-11-17|0x008b
#endif                                                                                    //07-11-17|0x008b
//------------------------------------------------------------------------                //07-11-17|0x008b
enum {  errormail_test_error_1 = TestIndex };                                             //07-11-17|0x008b
//------------------------------------------------------------------------                //07-11-17|0x008b
#undef TestIndex                                                                          //07-11-17|0x008b
#define TestIndex errormail_test_error_1+1                                                //07-11-17|0x008b
//************************************************************************                //07-11-17|0x008b
#ifndef TestIndex                                                                         //07-11-17|0x008c
#define TestIndex 0                                                                       //07-11-17|0x008c
#endif                                                                                    //07-11-17|0x008c
//------------------------------------------------------------------------                //07-11-17|0x008c
enum {  errormail_test_error_2 = TestIndex };                                             //07-11-17|0x008c
//------------------------------------------------------------------------                //07-11-17|0x008c
#undef TestIndex                                                                          //07-11-17|0x008c
#define TestIndex errormail_test_error_2+1                                                //07-11-17|0x008c
//************************************************************************                //07-11-17|0x008c
#ifndef TestIndex                                                                         //07-11-17|0x008d
#define TestIndex 0                                                                       //07-11-17|0x008d
#endif                                                                                    //07-11-17|0x008d
//------------------------------------------------------------------------                //07-11-17|0x008d
enum {  errormail_test_error_3 = TestIndex };                                             //07-11-17|0x008d
//------------------------------------------------------------------------                //07-11-17|0x008d
#undef TestIndex                                                                          //07-11-17|0x008d
#define TestIndex errormail_test_error_3+1                                                //07-11-17|0x008d
//************************************************************************                //07-11-17|0x008d
#ifndef TestIndex                                                                         //07-11-16|0x00a8
#define TestIndex 0                                                                       //07-11-16|0x00a8
#endif                                                                                    //07-11-16|0x00a8
//------------------------------------------------------------------------                //07-11-16|0x00a8
enum {  errormail_read_macro_1 = TestIndex };                                             //07-11-16|0x00a8
//------------------------------------------------------------------------                //07-11-16|0x00a8
#undef TestIndex                                                                          //07-11-16|0x00a8
#define TestIndex errormail_read_macro_1+1                                                //07-11-16|0x00a8
//************************************************************************                //07-11-16|0x00a8
#ifndef TestIndex                                                                         //07-11-16|0x00c5
#define TestIndex 0                                                                       //07-11-16|0x00c5
#endif                                                                                    //07-11-16|0x00c5
//------------------------------------------------------------------------                //07-11-16|0x00c5
enum {  errormail_read_error_1 = TestIndex };                                             //07-11-16|0x00c5
//------------------------------------------------------------------------                //07-11-16|0x00c5
#undef TestIndex                                                                          //07-11-16|0x00c5
#define TestIndex errormail_read_error_1+1                                                //07-11-16|0x00c5
//************************************************************************                //07-11-16|0x00c5
//*******************************************************************************         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
//****                       END OF FILE                                     ****         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
//*******************************************************************************         //05-24-97|0x00fd
#endif                                                                                    //05-24-97|0x00fd
