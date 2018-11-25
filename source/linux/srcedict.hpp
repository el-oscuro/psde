//*****************************************************************************           //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
// PRECEDENCE DICTIONARY_MANAGER                                                          //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-02-02|0x000b
//  defined in the associated manual.                                                     //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-02-02|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-02-02|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-02-02|0x000b
//  (at your option) any later version.                                                   //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-02-02|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-02-02|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-02-02|0x000b
//  GNU General Public License for more details.                                          //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
//  You should have received a copy of the GNU General Public License                     //07-02-02|0x000b
//  along with this program; if not, write to the Free Software                           //07-02-02|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-02-02|0x000b
//  USA                                                                                   //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  For further information, please contact Robert Adams:                                 //07-02-02|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-02-02|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-02-02|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
#ifndef srcedict_hpp                                                                      //07-02-02|0x000c
#define srcedict_hpp                                                                      //07-02-02|0x000c
//***************************************************************************             //07-02-03|0x0012
//***************************************************************************             //07-02-03|0x0013
//******                                                               ******             //07-02-03|0x0014
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //07-02-03|0x0015
//******                                                               ******             //07-02-03|0x0016
//***************************************************************************             //07-02-03|0x0017
//***************************************************************************             //07-02-03|0x0018
//***************************************************************************             //07-02-03|0x001b
//***************************************************************************             //07-02-03|0x001c
//******                                                               ******             //07-02-03|0x001d
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //07-02-03|0x001e
//******                                                               ******             //07-02-03|0x001f
//***************************************************************************             //07-02-03|0x0020
//***************************************************************************             //07-02-03|0x0021
#define UserError 0x0000                                                                  //07-02-03|0x0022
#define BuildError 0x7fff                                                                 //07-02-03|0x0022
#define Display 0x7ffe                                                                    //07-02-03|0x0022
#define KeyBoard 0x7ffd                                                                   //07-02-03|0x0022
#define Success 0xffff                                                                    //07-02-03|0x0022
#define SystemError 0x8000                                                                //07-02-03|0x0022
#define Continue 0x0001                                                                   //07-02-03|0x0022
#define FileDone 0x0002                                                                   //07-02-03|0x0022
#define LineDone 0x0003                                                                   //07-02-03|0x0022
#define Yes 0x0004                                                                        //07-02-03|0x0022
#define No 0x0005                                                                         //07-02-03|0x0022
#define RepeatChar '\x6'                                                                  //07-02-03|0x0022
#define Great 0x0007                                                                      //07-02-03|0x0022
#define Equal 0x0008                                                                      //07-02-03|0x0022
#define Less 0x0009                                                                       //07-02-03|0x0022
#define Zero 0x000a                                                                       //07-02-03|0x0022
#define Minus 0x000b                                                                      //07-02-03|0x0022
//***************************************************************************             //07-02-03|0x0023
#define SystemMsg PcgSystemError("Srcedict", __LINE__);                                   //07-02-03|0x0024
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-02-03|0x0024
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //07-02-03|0x0024
#define BreakFinish(_a) status = Finish(_a); break                                        //07-02-03|0x0025
#define ReturnFinish(_a) return(Finish(_a))                                               //07-02-03|0x0025
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //07-02-03|0x0025
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //07-02-03|0x0025
#define _SwitchErr case UserError: return(UserError)                                      //07-02-03|0x0026
#define _SwitchOk case Success: break                                                     //07-02-03|0x0026
#define _SwitchEnd default: ReturnSystemError                                             //07-02-03|0x0026
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-02-03|0x0026
#define _SwitchYes case Yes:      return(Yes)                                             //07-02-03|0x0026
#define _SwitchNo case No:       return(No)                                               //07-02-03|0x0026
#define _SwitchGroup { _SwitchBase; }                                                     //07-02-03|0x0026
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-02-03|0x0026
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-02-03|0x0026
#define _SwitchBreak _SwitchGroup break                                                   //07-02-03|0x0026
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-02-03|0x0026
//***************************************************************************             //07-02-03|0x004a
//***************************************************************************             //07-02-03|0x004b
//******                                                               ******             //07-02-03|0x004c
//******               GENERAL DEFINITION STATEMENTS                   ******             //07-02-03|0x004d
//******                                                               ******             //07-02-03|0x004e
//***************************************************************************             //07-02-03|0x004f
//***************************************************************************             //07-02-03|0x0050
#define TestSample(i) test_samples[i] = __LINE__                                          //07-02-03|0x0051
#define return_test(j) { TestSample(j);  return(Success); }                               //07-02-03|0x0051
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //07-02-03|0x0051
#define return_no(j) { TestSample(j);  return(No); }                                      //07-02-03|0x0051
#define goto_test(i) { TestSample(i);  goto loop; }                                       //07-02-03|0x0051
#define break_test(i) { TestSample(i);  break; }                                          //07-02-03|0x0051
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //07-02-03|0x0051
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //07-02-03|0x0051
//************************************************************************                //07-02-03|0x0051
#ifndef TestIndex                                                                         //07-02-03|0x0051
#define TestIndex 0                                                                       //07-02-03|0x0051
#endif                                                                                    //07-02-03|0x0051
//------------------------------------------------------------------------                //07-02-03|0x0051
enum {  NoTestSamples = TestIndex };                                                      //07-02-03|0x0051
//------------------------------------------------------------------------                //07-02-03|0x0051
#undef TestIndex                                                                          //07-02-03|0x0051
#define TestIndex NoTestSamples+1                                                         //07-02-03|0x0051
//************************************************************************                //07-02-03|0x0051
//***************************************************************************             //07-02-03|0x0052
//************************************************************************                //07-02-03|0x0053
#define TokenTokenAddr(i) &(Token->token[i])                                              //07-02-03|0x0053
#define TokenMacroLineNo(i) Token->token[i].macro_line_no                                 //07-02-03|0x0053
#define TokenLineAddr(i) &(Token->token[i].line[0])                                       //07-02-03|0x0053
#define TokenToken(i) Token->token[i]                                                     //07-02-03|0x0053
#define TokenLine(i) Token->token[i].line                                                 //07-02-03|0x0053
#define TokenLength(i) Token->token[i].length                                             //07-02-03|0x0053
#define TokenColumn(i) Token->token[i].column                                             //07-02-03|0x0053
#define TokenHash(i) Token->token[i].hash                                                 //07-02-03|0x0053
#define TokenPosition(i) Token->token[i].position                                         //07-02-03|0x0053
#define TokenType(i) Token->token[i].type                                                 //07-02-03|0x0053
#define TokenStartCol(i) Token->token[i].start_col                                        //07-02-03|0x0053
#define TokenStartCall(i) Token->token[i].start_call                                      //07-02-03|0x0053
#define TokenChar(i,j) Token->token[i].line[j]                                            //07-02-03|0x0053
#define TokenNoTokens Token->no_tokens                                                    //07-02-03|0x0053
#define NameChar(i) Name->line[i]                                                         //07-02-03|0x0054
#define NameLine Name->line[0]                                                            //07-02-03|0x0054
#define NameLineAddr &(Name->line[0])                                                     //07-02-03|0x0054
#define NameMacroLineNo Name->macro_line_no                                               //07-02-03|0x0054
#define NameType Name->type                                                               //07-02-03|0x0054
#define NameStartCol Name->start_col                                                      //07-02-03|0x0054
#define NameStartCall Name->start_call                                                    //07-02-03|0x0054
#define NamePosition Name->position                                                       //07-02-03|0x0054
#define NameLength Name->length                                                           //07-02-03|0x0054
#define NameColumn Name->column                                                           //07-02-03|0x0054
//**********************************************************************                  //07-02-03|0x0054
#define AddrChar(i) Addr->line[i]                                                         //07-02-03|0x0055
#define AddrLine Addr->line[0]                                                            //07-02-03|0x0055
#define AddrLineAddr &(Addr->line[0])                                                     //07-02-03|0x0055
#define AddrMacroLineNo Addr->macro_line_no                                               //07-02-03|0x0055
#define AddrType Addr->type                                                               //07-02-03|0x0055
#define AddrStartCol Addr->start_col                                                      //07-02-03|0x0055
#define AddrStartCall Addr->start_call                                                    //07-02-03|0x0055
#define AddrPosition Addr->position                                                       //07-02-03|0x0055
#define AddrLength Addr->length                                                           //07-02-03|0x0055
#define AddrColumn Addr->column                                                           //07-02-03|0x0055
//**********************************************************************                  //07-02-03|0x0055
#define WorkChar(i) work.line[i]                                                          //07-02-03|0x0056
#define WorkLine work.line[0]                                                             //07-02-03|0x0056
#define WorkLineAddr &(work.line[0])                                                      //07-02-03|0x0056
#define WorkMacroLineNo work.macro_line_no                                                //07-02-03|0x0056
#define WorkType work.type                                                                //07-02-03|0x0056
#define WorkStartCol work.start_col                                                       //07-02-03|0x0056
#define WorkStartCall work.start_call                                                     //07-02-03|0x0056
#define WorkPosition work.position                                                        //07-02-03|0x0056
#define WorkLength work.length                                                            //07-02-03|0x0056
#define WorkColumn work.column                                                            //07-02-03|0x0056
//**********************************************************************                  //07-02-03|0x0056
#ifndef TestIndex                                                                         //07-01-17|0x0063
#define TestIndex 0                                                                       //07-01-17|0x0063
#endif                                                                                    //07-01-17|0x0063
//------------------------------------------------------------------------                //07-01-17|0x0063
enum {  srce_dict_allocate_1 = TestIndex };                                               //07-01-17|0x0063
//------------------------------------------------------------------------                //07-01-17|0x0063
#undef TestIndex                                                                          //07-01-17|0x0063
#define TestIndex srce_dict_allocate_1+1                                                  //07-01-17|0x0063
//************************************************************************                //07-01-17|0x0063
#ifndef TestIndex                                                                         //07-01-25|0x007b
#define TestIndex 0                                                                       //07-01-25|0x007b
#endif                                                                                    //07-01-25|0x007b
//------------------------------------------------------------------------                //07-01-25|0x007b
enum {  srce_dict_free_1 = TestIndex };                                                   //07-01-25|0x007b
//------------------------------------------------------------------------                //07-01-25|0x007b
#undef TestIndex                                                                          //07-01-25|0x007b
#define TestIndex srce_dict_free_1+1                                                      //07-01-25|0x007b
//************************************************************************                //07-01-25|0x007b
#ifndef TestIndex                                                                         //07-01-24|0x0094
#define TestIndex 0                                                                       //07-01-24|0x0094
#endif                                                                                    //07-01-24|0x0094
//------------------------------------------------------------------------                //07-01-24|0x0094
enum {  srce_dict_name_1 = TestIndex };                                                   //07-01-24|0x0094
//------------------------------------------------------------------------                //07-01-24|0x0094
#undef TestIndex                                                                          //07-01-24|0x0094
#define TestIndex srce_dict_name_1+1                                                      //07-01-24|0x0094
//************************************************************************                //07-01-24|0x0094
#ifndef TestIndex                                                                         //07-01-24|0x00ac
#define TestIndex 0                                                                       //07-01-24|0x00ac
#endif                                                                                    //07-01-24|0x00ac
//------------------------------------------------------------------------                //07-01-24|0x00ac
enum {  srce_dict_create_1 = TestIndex };                                                 //07-01-24|0x00ac
//------------------------------------------------------------------------                //07-01-24|0x00ac
#undef TestIndex                                                                          //07-01-24|0x00ac
#define TestIndex srce_dict_create_1+1                                                    //07-01-24|0x00ac
//************************************************************************                //07-01-24|0x00ac
#ifndef TestIndex                                                                         //07-01-25|0x00c3
#define TestIndex 0                                                                       //07-01-25|0x00c3
#endif                                                                                    //07-01-25|0x00c3
//------------------------------------------------------------------------                //07-01-25|0x00c3
enum {  srce_dict_close_1 = TestIndex };                                                  //07-01-25|0x00c3
//------------------------------------------------------------------------                //07-01-25|0x00c3
#undef TestIndex                                                                          //07-01-25|0x00c3
#define TestIndex srce_dict_close_1+1                                                     //07-01-25|0x00c3
//************************************************************************                //07-01-25|0x00c3
#ifndef TestIndex                                                                         //07-01-24|0x00da
#define TestIndex 0                                                                       //07-01-24|0x00da
#endif                                                                                    //07-01-24|0x00da
//------------------------------------------------------------------------                //07-01-24|0x00da
enum {  srce_dict_add_entry_1 = TestIndex };                                              //07-01-24|0x00da
//------------------------------------------------------------------------                //07-01-24|0x00da
#undef TestIndex                                                                          //07-01-24|0x00da
#define TestIndex srce_dict_add_entry_1+1                                                 //07-01-24|0x00da
//************************************************************************                //07-01-24|0x00da
#ifndef TestIndex                                                                         //07-01-24|0x00db
#define TestIndex 0                                                                       //07-01-24|0x00db
#endif                                                                                    //07-01-24|0x00db
//------------------------------------------------------------------------                //07-01-24|0x00db
enum {  srce_dict_add_entry_2 = TestIndex };                                              //07-01-24|0x00db
//------------------------------------------------------------------------                //07-01-24|0x00db
#undef TestIndex                                                                          //07-01-24|0x00db
#define TestIndex srce_dict_add_entry_2+1                                                 //07-01-24|0x00db
//************************************************************************                //07-01-24|0x00db
#ifndef TestIndex                                                                         //07-02-03|0x010b
#define TestIndex 0                                                                       //07-02-03|0x010b
#endif                                                                                    //07-02-03|0x010b
//------------------------------------------------------------------------                //07-02-03|0x010b
enum {  srce_dict_add_sub_entry_2 = TestIndex };                                          //07-02-03|0x010b
//------------------------------------------------------------------------                //07-02-03|0x010b
#undef TestIndex                                                                          //07-02-03|0x010b
#define TestIndex srce_dict_add_sub_entry_2+1                                             //07-02-03|0x010b
//************************************************************************                //07-02-03|0x010b
#ifndef TestIndex                                                                         //07-02-03|0x010c
#define TestIndex 0                                                                       //07-02-03|0x010c
#endif                                                                                    //07-02-03|0x010c
//------------------------------------------------------------------------                //07-02-03|0x010c
enum {  srce_dict_add_sub_entry_3 = TestIndex };                                          //07-02-03|0x010c
//------------------------------------------------------------------------                //07-02-03|0x010c
#undef TestIndex                                                                          //07-02-03|0x010c
#define TestIndex srce_dict_add_sub_entry_3+1                                             //07-02-03|0x010c
//************************************************************************                //07-02-03|0x010c
#ifndef TestIndex                                                                         //07-02-03|0x010d
#define TestIndex 0                                                                       //07-02-03|0x010d
#endif                                                                                    //07-02-03|0x010d
//------------------------------------------------------------------------                //07-02-03|0x010d
enum {  srce_dict_add_sub_entry_4 = TestIndex };                                          //07-02-03|0x010d
//------------------------------------------------------------------------                //07-02-03|0x010d
#undef TestIndex                                                                          //07-02-03|0x010d
#define TestIndex srce_dict_add_sub_entry_4+1                                             //07-02-03|0x010d
//************************************************************************                //07-02-03|0x010d
#ifndef TestIndex                                                                         //07-02-03|0x010e
#define TestIndex 0                                                                       //07-02-03|0x010e
#endif                                                                                    //07-02-03|0x010e
//------------------------------------------------------------------------                //07-02-03|0x010e
enum {  srce_dict_add_sub_entry_5 = TestIndex };                                          //07-02-03|0x010e
//------------------------------------------------------------------------                //07-02-03|0x010e
#undef TestIndex                                                                          //07-02-03|0x010e
#define TestIndex srce_dict_add_sub_entry_5+1                                             //07-02-03|0x010e
//************************************************************************                //07-02-03|0x010e
#ifndef TestIndex                                                                         //07-01-24|0x0151
#define TestIndex 0                                                                       //07-01-24|0x0151
#endif                                                                                    //07-01-24|0x0151
//------------------------------------------------------------------------                //07-01-24|0x0151
enum {  srce_dict_update_data_1 = TestIndex };                                            //07-01-24|0x0151
//------------------------------------------------------------------------                //07-01-24|0x0151
#undef TestIndex                                                                          //07-01-24|0x0151
#define TestIndex srce_dict_update_data_1+1                                               //07-01-24|0x0151
//************************************************************************                //07-01-24|0x0151
#ifndef TestIndex                                                                         //07-01-24|0x0152
#define TestIndex 0                                                                       //07-01-24|0x0152
#endif                                                                                    //07-01-24|0x0152
//------------------------------------------------------------------------                //07-01-24|0x0152
enum {  srce_dict_update_data_2 = TestIndex };                                            //07-01-24|0x0152
//------------------------------------------------------------------------                //07-01-24|0x0152
#undef TestIndex                                                                          //07-01-24|0x0152
#define TestIndex srce_dict_update_data_2+1                                               //07-01-24|0x0152
//************************************************************************                //07-01-24|0x0152
#ifndef TestIndex                                                                         //07-02-07|0x0191
#define TestIndex 0                                                                       //07-02-07|0x0191
#endif                                                                                    //07-02-07|0x0191
//------------------------------------------------------------------------                //07-02-07|0x0191
enum {  srce_dict_update_sub_entry_2 = TestIndex };                                       //07-02-07|0x0191
//------------------------------------------------------------------------                //07-02-07|0x0191
#undef TestIndex                                                                          //07-02-07|0x0191
#define TestIndex srce_dict_update_sub_entry_2+1                                          //07-02-07|0x0191
//************************************************************************                //07-02-07|0x0191
#ifndef TestIndex                                                                         //07-02-07|0x0192
#define TestIndex 0                                                                       //07-02-07|0x0192
#endif                                                                                    //07-02-07|0x0192
//------------------------------------------------------------------------                //07-02-07|0x0192
enum {  srce_dict_update_sub_entry_3 = TestIndex };                                       //07-02-07|0x0192
//------------------------------------------------------------------------                //07-02-07|0x0192
#undef TestIndex                                                                          //07-02-07|0x0192
#define TestIndex srce_dict_update_sub_entry_3+1                                          //07-02-07|0x0192
//************************************************************************                //07-02-07|0x0192
#ifndef TestIndex                                                                         //07-02-07|0x0193
#define TestIndex 0                                                                       //07-02-07|0x0193
#endif                                                                                    //07-02-07|0x0193
//------------------------------------------------------------------------                //07-02-07|0x0193
enum {  srce_dict_update_sub_entry_4 = TestIndex };                                       //07-02-07|0x0193
//------------------------------------------------------------------------                //07-02-07|0x0193
#undef TestIndex                                                                          //07-02-07|0x0193
#define TestIndex srce_dict_update_sub_entry_4+1                                          //07-02-07|0x0193
//************************************************************************                //07-02-07|0x0193
#ifndef TestIndex                                                                         //07-01-24|0x01c5
#define TestIndex 0                                                                       //07-01-24|0x01c5
#endif                                                                                    //07-01-24|0x01c5
//------------------------------------------------------------------------                //07-01-24|0x01c5
enum {  srce_dict_get_data_1 = TestIndex };                                               //07-01-24|0x01c5
//------------------------------------------------------------------------                //07-01-24|0x01c5
#undef TestIndex                                                                          //07-01-24|0x01c5
#define TestIndex srce_dict_get_data_1+1                                                  //07-01-24|0x01c5
//************************************************************************                //07-01-24|0x01c5
#ifndef TestIndex                                                                         //07-01-24|0x01c6
#define TestIndex 0                                                                       //07-01-24|0x01c6
#endif                                                                                    //07-01-24|0x01c6
//------------------------------------------------------------------------                //07-01-24|0x01c6
enum {  srce_dict_get_data_2 = TestIndex };                                               //07-01-24|0x01c6
//------------------------------------------------------------------------                //07-01-24|0x01c6
#undef TestIndex                                                                          //07-01-24|0x01c6
#define TestIndex srce_dict_get_data_2+1                                                  //07-01-24|0x01c6
//************************************************************************                //07-01-24|0x01c6
#ifndef TestIndex                                                                         //07-01-24|0x01c7
#define TestIndex 0                                                                       //07-01-24|0x01c7
#endif                                                                                    //07-01-24|0x01c7
//------------------------------------------------------------------------                //07-01-24|0x01c7
enum {  srce_dict_get_data_3 = TestIndex };                                               //07-01-24|0x01c7
//------------------------------------------------------------------------                //07-01-24|0x01c7
#undef TestIndex                                                                          //07-01-24|0x01c7
#define TestIndex srce_dict_get_data_3+1                                                  //07-01-24|0x01c7
//************************************************************************                //07-01-24|0x01c7
#ifndef TestIndex                                                                         //07-02-03|0x01ee
#define TestIndex 0                                                                       //07-02-03|0x01ee
#endif                                                                                    //07-02-03|0x01ee
//------------------------------------------------------------------------                //07-02-03|0x01ee
enum {  srce_sub_dict_get_data_2 = TestIndex };                                           //07-02-03|0x01ee
//------------------------------------------------------------------------                //07-02-03|0x01ee
#undef TestIndex                                                                          //07-02-03|0x01ee
#define TestIndex srce_sub_dict_get_data_2+1                                              //07-02-03|0x01ee
//************************************************************************                //07-02-03|0x01ee
#ifndef TestIndex                                                                         //07-02-03|0x01ef
#define TestIndex 0                                                                       //07-02-03|0x01ef
#endif                                                                                    //07-02-03|0x01ef
//------------------------------------------------------------------------                //07-02-03|0x01ef
enum {  srce_sub_dict_get_data_3 = TestIndex };                                           //07-02-03|0x01ef
//------------------------------------------------------------------------                //07-02-03|0x01ef
#undef TestIndex                                                                          //07-02-03|0x01ef
#define TestIndex srce_sub_dict_get_data_3+1                                              //07-02-03|0x01ef
//************************************************************************                //07-02-03|0x01ef
#ifndef TestIndex                                                                         //07-02-03|0x01f0
#define TestIndex 0                                                                       //07-02-03|0x01f0
#endif                                                                                    //07-02-03|0x01f0
//------------------------------------------------------------------------                //07-02-03|0x01f0
enum {  srce_sub_dict_get_data_4 = TestIndex };                                           //07-02-03|0x01f0
//------------------------------------------------------------------------                //07-02-03|0x01f0
#undef TestIndex                                                                          //07-02-03|0x01f0
#define TestIndex srce_sub_dict_get_data_4+1                                              //07-02-03|0x01f0
//************************************************************************                //07-02-03|0x01f0
#ifndef TestIndex                                                                         //07-02-03|0x0217
#define TestIndex 0                                                                       //07-02-03|0x0217
#endif                                                                                    //07-02-03|0x0217
//------------------------------------------------------------------------                //07-02-03|0x0217
enum {  srce_dict_test_data_1 = TestIndex };                                              //07-02-03|0x0217
//------------------------------------------------------------------------                //07-02-03|0x0217
#undef TestIndex                                                                          //07-02-03|0x0217
#define TestIndex srce_dict_test_data_1+1                                                 //07-02-03|0x0217
//************************************************************************                //07-02-03|0x0217
#ifndef TestIndex                                                                         //07-02-03|0x0218
#define TestIndex 0                                                                       //07-02-03|0x0218
#endif                                                                                    //07-02-03|0x0218
//------------------------------------------------------------------------                //07-02-03|0x0218
enum {  srce_dict_test_data_2 = TestIndex };                                              //07-02-03|0x0218
//------------------------------------------------------------------------                //07-02-03|0x0218
#undef TestIndex                                                                          //07-02-03|0x0218
#define TestIndex srce_dict_test_data_2+1                                                 //07-02-03|0x0218
//************************************************************************                //07-02-03|0x0218
#ifndef TestIndex                                                                         //07-03-14|0x023f
#define TestIndex 0                                                                       //07-03-14|0x023f
#endif                                                                                    //07-03-14|0x023f
//------------------------------------------------------------------------                //07-03-14|0x023f
enum {  srce_sub_dict_test_data_2 = TestIndex };                                          //07-03-14|0x023f
//------------------------------------------------------------------------                //07-03-14|0x023f
#undef TestIndex                                                                          //07-03-14|0x023f
#define TestIndex srce_sub_dict_test_data_2+1                                             //07-03-14|0x023f
//************************************************************************                //07-03-14|0x023f
#ifndef TestIndex                                                                         //07-03-14|0x0240
#define TestIndex 0                                                                       //07-03-14|0x0240
#endif                                                                                    //07-03-14|0x0240
//------------------------------------------------------------------------                //07-03-14|0x0240
enum {  srce_sub_dict_test_data_3 = TestIndex };                                          //07-03-14|0x0240
//------------------------------------------------------------------------                //07-03-14|0x0240
#undef TestIndex                                                                          //07-03-14|0x0240
#define TestIndex srce_sub_dict_test_data_3+1                                             //07-03-14|0x0240
//************************************************************************                //07-03-14|0x0240
#ifndef TestIndex                                                                         //07-03-14|0x0241
#define TestIndex 0                                                                       //07-03-14|0x0241
#endif                                                                                    //07-03-14|0x0241
//------------------------------------------------------------------------                //07-03-14|0x0241
enum {  srce_sub_dict_test_data_4 = TestIndex };                                          //07-03-14|0x0241
//------------------------------------------------------------------------                //07-03-14|0x0241
#undef TestIndex                                                                          //07-03-14|0x0241
#define TestIndex srce_sub_dict_test_data_4+1                                             //07-03-14|0x0241
//************************************************************************                //07-03-14|0x0241
#ifndef TestIndex                                                                         //07-02-03|0x0268
#define TestIndex 0                                                                       //07-02-03|0x0268
#endif                                                                                    //07-02-03|0x0268
//------------------------------------------------------------------------                //07-02-03|0x0268
enum {  srce_dict_exists_1 = TestIndex };                                                 //07-02-03|0x0268
//------------------------------------------------------------------------                //07-02-03|0x0268
#undef TestIndex                                                                          //07-02-03|0x0268
#define TestIndex srce_dict_exists_1+1                                                    //07-02-03|0x0268
//************************************************************************                //07-02-03|0x0268
#ifndef TestIndex                                                                         //07-02-03|0x0269
#define TestIndex 0                                                                       //07-02-03|0x0269
#endif                                                                                    //07-02-03|0x0269
//------------------------------------------------------------------------                //07-02-03|0x0269
enum {  srce_dict_exists_2 = TestIndex };                                                 //07-02-03|0x0269
//------------------------------------------------------------------------                //07-02-03|0x0269
#undef TestIndex                                                                          //07-02-03|0x0269
#define TestIndex srce_dict_exists_2+1                                                    //07-02-03|0x0269
//************************************************************************                //07-02-03|0x0269
#ifndef TestIndex                                                                         //07-02-05|0x0286
#define TestIndex 0                                                                       //07-02-05|0x0286
#endif                                                                                    //07-02-05|0x0286
//------------------------------------------------------------------------                //07-02-05|0x0286
enum {  srce_sub_exists_1 = TestIndex };                                                  //07-02-05|0x0286
//------------------------------------------------------------------------                //07-02-05|0x0286
#undef TestIndex                                                                          //07-02-05|0x0286
#define TestIndex srce_sub_exists_1+1                                                     //07-02-05|0x0286
//************************************************************************                //07-02-05|0x0286
#ifndef TestIndex                                                                         //07-02-05|0x0287
#define TestIndex 0                                                                       //07-02-05|0x0287
#endif                                                                                    //07-02-05|0x0287
//------------------------------------------------------------------------                //07-02-05|0x0287
enum {  srce_sub_exists_2 = TestIndex };                                                  //07-02-05|0x0287
//------------------------------------------------------------------------                //07-02-05|0x0287
#undef TestIndex                                                                          //07-02-05|0x0287
#define TestIndex srce_sub_exists_2+1                                                     //07-02-05|0x0287
//************************************************************************                //07-02-05|0x0287
#ifndef TestIndex                                                                         //07-01-24|0x02a7
#define TestIndex 0                                                                       //07-01-24|0x02a7
#endif                                                                                    //07-01-24|0x02a7
//------------------------------------------------------------------------                //07-01-24|0x02a7
enum {  srce_dict_find_1 = TestIndex };                                                   //07-01-24|0x02a7
//------------------------------------------------------------------------                //07-01-24|0x02a7
#undef TestIndex                                                                          //07-01-24|0x02a7
#define TestIndex srce_dict_find_1+1                                                      //07-01-24|0x02a7
//************************************************************************                //07-01-24|0x02a7
#ifndef TestIndex                                                                         //07-01-24|0x02a8
#define TestIndex 0                                                                       //07-01-24|0x02a8
#endif                                                                                    //07-01-24|0x02a8
//------------------------------------------------------------------------                //07-01-24|0x02a8
enum {  srce_dict_find_2 = TestIndex };                                                   //07-01-24|0x02a8
//------------------------------------------------------------------------                //07-01-24|0x02a8
#undef TestIndex                                                                          //07-01-24|0x02a8
#define TestIndex srce_dict_find_2+1                                                      //07-01-24|0x02a8
//************************************************************************                //07-01-24|0x02a8
#ifndef TestIndex                                                                         //07-02-03|0x02cb
#define TestIndex 0                                                                       //07-02-03|0x02cb
#endif                                                                                    //07-02-03|0x02cb
//------------------------------------------------------------------------                //07-02-03|0x02cb
enum {  srce_sub_find_1 = TestIndex };                                                    //07-02-03|0x02cb
//------------------------------------------------------------------------                //07-02-03|0x02cb
#undef TestIndex                                                                          //07-02-03|0x02cb
#define TestIndex srce_sub_find_1+1                                                       //07-02-03|0x02cb
//************************************************************************                //07-02-03|0x02cb
#ifndef TestIndex                                                                         //07-02-03|0x02cc
#define TestIndex 0                                                                       //07-02-03|0x02cc
#endif                                                                                    //07-02-03|0x02cc
//------------------------------------------------------------------------                //07-02-03|0x02cc
enum {  srce_sub_find_2 = TestIndex };                                                    //07-02-03|0x02cc
//------------------------------------------------------------------------                //07-02-03|0x02cc
#undef TestIndex                                                                          //07-02-03|0x02cc
#define TestIndex srce_sub_find_2+1                                                       //07-02-03|0x02cc
//************************************************************************                //07-02-03|0x02cc
#ifndef TestIndex                                                                         //07-02-03|0x02cd
#define TestIndex 0                                                                       //07-02-03|0x02cd
#endif                                                                                    //07-02-03|0x02cd
//------------------------------------------------------------------------                //07-02-03|0x02cd
enum {  srce_sub_find_3 = TestIndex };                                                    //07-02-03|0x02cd
//------------------------------------------------------------------------                //07-02-03|0x02cd
#undef TestIndex                                                                          //07-02-03|0x02cd
#define TestIndex srce_sub_find_3+1                                                       //07-02-03|0x02cd
//************************************************************************                //07-02-03|0x02cd
#ifndef TestIndex                                                                         //07-01-24|0x0306
#define TestIndex 0                                                                       //07-01-24|0x0306
#endif                                                                                    //07-01-24|0x0306
//------------------------------------------------------------------------                //07-01-24|0x0306
enum {  srce_get_first_1 = TestIndex };                                                   //07-01-24|0x0306
//------------------------------------------------------------------------                //07-01-24|0x0306
#undef TestIndex                                                                          //07-01-24|0x0306
#define TestIndex srce_get_first_1+1                                                      //07-01-24|0x0306
//************************************************************************                //07-01-24|0x0306
#ifndef TestIndex                                                                         //07-01-24|0x0325
#define TestIndex 0                                                                       //07-01-24|0x0325
#endif                                                                                    //07-01-24|0x0325
//------------------------------------------------------------------------                //07-01-24|0x0325
enum {  srce_get_next_1 = TestIndex };                                                    //07-01-24|0x0325
//------------------------------------------------------------------------                //07-01-24|0x0325
#undef TestIndex                                                                          //07-01-24|0x0325
#define TestIndex srce_get_next_1+1                                                       //07-01-24|0x0325
//************************************************************************                //07-01-24|0x0325
#ifndef TestIndex                                                                         //07-01-24|0x0326
#define TestIndex 0                                                                       //07-01-24|0x0326
#endif                                                                                    //07-01-24|0x0326
//------------------------------------------------------------------------                //07-01-24|0x0326
enum {  srce_get_next_2 = TestIndex };                                                    //07-01-24|0x0326
//------------------------------------------------------------------------                //07-01-24|0x0326
#undef TestIndex                                                                          //07-01-24|0x0326
#define TestIndex srce_get_next_2+1                                                       //07-01-24|0x0326
//************************************************************************                //07-01-24|0x0326
//*******************************************************************************         //05-24-97|0x035e
//*******************************************************************************         //05-24-97|0x035e
//****                       END OF FILE                                     ****         //05-24-97|0x035e
//*******************************************************************************         //05-24-97|0x035e
//*******************************************************************************         //05-24-97|0x035e
#endif                                                                                    //05-24-97|0x035e
