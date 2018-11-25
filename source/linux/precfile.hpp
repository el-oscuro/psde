//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
// PRECEDENCE FILE MANAGER                                                                //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  The purpose of this program as well as instructions regarding its use is              //04-01-97|0x001e
//  defined in the associated manual.                                                     //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  This program is free software; you can redistribute it and/or modify                  //04-01-97|0x001e
//  it under the terms of the GNU General Public License as published by                  //04-01-97|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //04-01-97|0x001e
//  (at your option) any later version.                                                   //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//  This program is distributed in the hope that it will be useful,                       //04-01-97|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //04-01-97|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //04-01-97|0x001e
//  GNU General Public License for more details.                                          //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//  You should have received a copy of the GNU General Public License                     //04-01-97|0x001e
//  along with this program; if not, write to the Free Software                           //04-01-97|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //04-01-97|0x001e
//  USA                                                                                   //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  For further information, please contact Robert Adams:                                 //04-01-97|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //04-01-97|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //04-01-97|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
#ifndef precfile_hpp                                                                      //04-01-97|0x0023
#define precfile_hpp                                                                      //04-01-97|0x0023
//***************************************************************************             //06-07-13|0x002c
//***************************************************************************             //06-07-13|0x002d
//******                                                               ******             //06-07-13|0x002e
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-13|0x002f
//******                                                               ******             //06-07-13|0x0030
//***************************************************************************             //06-07-13|0x0031
//***************************************************************************             //06-07-13|0x0032
//***************************************************************************             //06-07-13|0x0036
//***************************************************************************             //06-07-13|0x0037
//******                                                               ******             //06-07-13|0x0038
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-13|0x0039
//******                                                               ******             //06-07-13|0x003a
//***************************************************************************             //06-07-13|0x003b
//***************************************************************************             //06-07-13|0x003c
#define UserError 0x0000                                                                  //06-07-13|0x003d
#define BuildError 0x7fff                                                                 //06-07-13|0x003d
#define Display 0x7ffe                                                                    //06-07-13|0x003d
#define KeyBoard 0x7ffd                                                                   //06-07-13|0x003d
#define Success 0xffff                                                                    //06-07-13|0x003d
#define SystemError 0x8000                                                                //06-07-13|0x003d
#define Continue 0x0001                                                                   //06-07-13|0x003d
#define FileDone 0x0002                                                                   //06-07-13|0x003d
#define LineDone 0x0003                                                                   //06-07-13|0x003d
#define Yes 0x0004                                                                        //06-07-13|0x003d
#define No 0x0005                                                                         //06-07-13|0x003d
#define RepeatChar '\x6'                                                                  //06-07-13|0x003d
#define Great 0x0007                                                                      //06-07-13|0x003d
#define Equal 0x0008                                                                      //06-07-13|0x003d
#define Less 0x0009                                                                       //06-07-13|0x003d
#define Zero 0x000a                                                                       //06-07-13|0x003d
#define Minus 0x000b                                                                      //06-07-13|0x003d
//***************************************************************************             //06-07-13|0x003e
#define SystemMsg PcgSystemError("Precfile", __LINE__);                                   //06-07-13|0x003f
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-13|0x003f
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-13|0x003f
#define DebugBreakpoint1 Breakpoint("precfile", __LINE__)                                 //<----   |0x0040
#define DebugBreakpoint if(DebugBreakpoint1 != Success) ReturnSystemError                 //<----   |0x0040
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-13|0x0041
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-13|0x0041
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-13|0x0041
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-13|0x0041
#define _SwitchErr case UserError: return(UserError)                                      //06-07-13|0x0042
#define _SwitchOk case Success: break                                                     //06-07-13|0x0042
#define _SwitchEnd default: ReturnSystemError                                             //06-07-13|0x0042
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-13|0x0042
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-13|0x0042
#define _SwitchNo case No:       return(No)                                               //06-07-13|0x0042
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-13|0x0042
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-13|0x0042
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-13|0x0042
#define _SwitchBreak _SwitchGroup break                                                   //06-07-13|0x0042
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-13|0x0042
//***************************************************************************             //06-07-13|0x0070
//***************************************************************************             //06-07-13|0x0071
//******                                                               ******             //06-07-13|0x0072
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-13|0x0073
//******                                                               ******             //06-07-13|0x0074
//***************************************************************************             //06-07-13|0x0075
//***************************************************************************             //06-07-13|0x0076
#define TestSample(i) test_samples[i] = __LINE__                                          //04-10-22|0x0077
#define return_test(j) { TestSample(j);  return(Success); }                               //04-10-22|0x0077
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //04-10-22|0x0077
#define return_no(j) { TestSample(j);  return(No); }                                      //04-10-22|0x0077
#define return_cont(j) { TestSample(j);  return(Continue); }                              //04-10-22|0x0077
#define return_line(j) { TestSample(j);  return(LineDone); }                              //04-10-22|0x0077
#define goto_test(i) { TestSample(i);  goto loop; }                                       //04-10-22|0x0077
#define break_test(i) { TestSample(i);  break; }                                          //04-10-22|0x0077
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //04-10-22|0x0077
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //04-10-22|0x0077
//************************************************************************                //04-10-22|0x0077
#ifndef TestIndex                                                                         //04-10-22|0x0077
#define TestIndex 0                                                                       //04-10-22|0x0077
#endif                                                                                    //04-10-22|0x0077
//------------------------------------------------------------------------                //04-10-22|0x0077
enum {  NoTestSamples = TestIndex };                                                      //04-10-22|0x0077
//------------------------------------------------------------------------                //04-10-22|0x0077
#undef TestIndex                                                                          //04-10-22|0x0077
#define TestIndex NoTestSamples+1                                                         //04-10-22|0x0077
//************************************************************************                //04-10-22|0x0077
//************************************************************************                //06-07-13|0x0079
#define FileState file_control_addr->state                                                //06-07-13|0x0079
#define FileName file_control_addr->name                                                  //06-07-13|0x0079
#define FileStream file_control_addr->stream                                              //06-07-13|0x0079
//***************************************************************************             //06-07-13|0x007a
//**********************************************************************                  //06-07-13|0x007b
#define TextFileControl text_file_addr->file_control                                      //06-07-13|0x007b
#define TextString text_file_addr->string                                                 //06-07-13|0x007b
#define TextLineNo text_file_addr->line_no                                                //06-07-13|0x007b
#define TextLength text_file_addr->length                                                 //06-07-13|0x007b
#define TextNextPos text_file_addr->next_position                                         //06-07-13|0x007b
#define TextReadState text_file_addr->read_state                                          //06-07-13|0x007b
#define TextGetState text_file_addr->get_state                                            //06-07-13|0x007b
#define TextPutState text_file_addr->put_state                                            //06-07-13|0x007b
#define TextStatus text_file_addr->status                                                 //06-07-13|0x007b
#define TextRunFlag text_file_addr->run_flag                                              //06-07-13|0x007b
//----------------------------------------------------------------------                  //06-07-13|0x007b
#define TextStringAddr &(text_file_addr->string)                                          //06-07-13|0x007b
#define StringChar(i) TextString.line[i]                                                  //12-10-07|0x007c
#define StringLine TextString.line[0]                                                     //12-10-07|0x007c
#define StringLineAddr &(TextString.line[0])                                              //12-10-07|0x007c
#define StringMacroLineNo TextString.macro_line_no                                        //12-10-07|0x007c
#define StringType TextString.type                                                        //12-10-07|0x007c
#define StringStartCol TextString.start_col                                               //12-10-07|0x007c
#define StringStartCall TextString.start_call                                             //12-10-07|0x007c
#define StringPosition TextString.position                                                //12-10-07|0x007c
#define StringLength TextString.length                                                    //12-10-07|0x007c
#define StringColumn TextString.column                                                    //12-10-07|0x007c
//**********************************************************************                  //12-10-07|0x007c
//***************************************************************************             //06-07-13|0x007d
//************************************************************************                //06-07-13|0x007e
#define TokensTokenAddr(i) &(tokens_addr->token[i])                                       //06-07-13|0x007e
#define TokensMacroLineNo(i) tokens_addr->token[i].macro_line_no                          //06-07-13|0x007e
#define TokensLineAddr(i) &(tokens_addr->token[i].line[0])                                //06-07-13|0x007e
#define TokensToken(i) tokens_addr->token[i]                                              //06-07-13|0x007e
#define TokensLine(i) tokens_addr->token[i].line                                          //06-07-13|0x007e
#define TokensLength(i) tokens_addr->token[i].length                                      //06-07-13|0x007e
#define TokensColumn(i) tokens_addr->token[i].column                                      //06-07-13|0x007e
#define TokensHash(i) tokens_addr->token[i].hash                                          //06-07-13|0x007e
#define TokensPosition(i) tokens_addr->token[i].position                                  //06-07-13|0x007e
#define TokensType(i) tokens_addr->token[i].type                                          //06-07-13|0x007e
#define TokensStartCol(i) tokens_addr->token[i].start_col                                 //06-07-13|0x007e
#define TokensStartCall(i) tokens_addr->token[i].start_call                               //06-07-13|0x007e
#define TokensChar(i,j) tokens_addr->token[i].line[j]                                     //06-07-13|0x007e
#define TokensNoTokens tokens_addr->no_tokens                                             //06-07-13|0x007e
#define TokenChar(i) token_addr->line[i]                                                  //06-07-13|0x007f
#define TokenLine token_addr->line[0]                                                     //06-07-13|0x007f
#define TokenLineAddr &(token_addr->line[0])                                              //06-07-13|0x007f
#define TokenMacroLineNo token_addr->macro_line_no                                        //06-07-13|0x007f
#define TokenType token_addr->type                                                        //06-07-13|0x007f
#define TokenStartCol token_addr->start_col                                               //06-07-13|0x007f
#define TokenStartCall token_addr->start_call                                             //06-07-13|0x007f
#define TokenPosition token_addr->position                                                //06-07-13|0x007f
#define TokenLength token_addr->length                                                    //06-07-13|0x007f
#define TokenColumn token_addr->column                                                    //06-07-13|0x007f
//**********************************************************************                  //06-07-13|0x007f
//***************************************************************************             //check   |0x0080
#define StringArgChar(i) StringArgFar->line[i]                                            //check   |0x0081
#define StringArgLine StringArgFar->line[0]                                               //check   |0x0081
#define StringArgLineAddr &(StringArgFar->line[0])                                        //check   |0x0081
#define StringArgMacroLineNo StringArgFar->macro_line_no                                  //check   |0x0081
#define StringArgType StringArgFar->type                                                  //check   |0x0081
#define StringArgStartCol StringArgFar->start_col                                         //check   |0x0081
#define StringArgStartCall StringArgFar->start_call                                       //check   |0x0081
#define StringArgPosition StringArgFar->position                                          //check   |0x0081
#define StringArgLength StringArgFar->length                                              //check   |0x0081
#define StringArgColumn StringArgFar->column                                              //check   |0x0081
//**********************************************************************                  //check   |0x0081
//***************************************************************************             //06-07-13|0x0082
//************************************************************************                //06-07-13|0x0083
#define BinControl binary_file_addr->file_control                                         //06-07-13|0x0083
#define BinPosition binary_file_addr->file_position                                       //06-07-13|0x0083
#define BinLength binary_file_addr->file_length                                           //06-07-13|0x0083
//***************************************************************************             //06-07-13|0x0084
//************************************************************************                //06-09-04|0x0085
#define NamesTokenAddr(i) &(NamesAddr->token[i])                                          //06-09-04|0x0085
#define NamesMacroLineNo(i) NamesAddr->token[i].macro_line_no                             //06-09-04|0x0085
#define NamesLineAddr(i) &(NamesAddr->token[i].line[0])                                   //06-09-04|0x0085
#define NamesToken(i) NamesAddr->token[i]                                                 //06-09-04|0x0085
#define NamesLine(i) NamesAddr->token[i].line                                             //06-09-04|0x0085
#define NamesLength(i) NamesAddr->token[i].length                                         //06-09-04|0x0085
#define NamesColumn(i) NamesAddr->token[i].column                                         //06-09-04|0x0085
#define NamesHash(i) NamesAddr->token[i].hash                                             //06-09-04|0x0085
#define NamesPosition(i) NamesAddr->token[i].position                                     //06-09-04|0x0085
#define NamesType(i) NamesAddr->token[i].type                                             //06-09-04|0x0085
#define NamesStartCol(i) NamesAddr->token[i].start_col                                    //06-09-04|0x0085
#define NamesStartCall(i) NamesAddr->token[i].start_call                                  //06-09-04|0x0085
#define NamesChar(i,j) NamesAddr->token[i].line[j]                                        //06-09-04|0x0085
#define NamesNoTokens NamesAddr->no_tokens                                                //06-09-04|0x0085
//************************************************************************                //06-09-04|0x0086
#define PrefixTokenAddr(i) &(PrefixAddr->token[i])                                        //06-09-04|0x0086
#define PrefixMacroLineNo(i) PrefixAddr->token[i].macro_line_no                           //06-09-04|0x0086
#define PrefixLineAddr(i) &(PrefixAddr->token[i].line[0])                                 //06-09-04|0x0086
#define PrefixToken(i) PrefixAddr->token[i]                                               //06-09-04|0x0086
#define PrefixLine(i) PrefixAddr->token[i].line                                           //06-09-04|0x0086
#define PrefixLength(i) PrefixAddr->token[i].length                                       //06-09-04|0x0086
#define PrefixColumn(i) PrefixAddr->token[i].column                                       //06-09-04|0x0086
#define PrefixHash(i) PrefixAddr->token[i].hash                                           //06-09-04|0x0086
#define PrefixPosition(i) PrefixAddr->token[i].position                                   //06-09-04|0x0086
#define PrefixType(i) PrefixAddr->token[i].type                                           //06-09-04|0x0086
#define PrefixStartCol(i) PrefixAddr->token[i].start_col                                  //06-09-04|0x0086
#define PrefixStartCall(i) PrefixAddr->token[i].start_call                                //06-09-04|0x0086
#define PrefixChar(i,j) PrefixAddr->token[i].line[j]                                      //06-09-04|0x0086
#define PrefixNoTokens PrefixAddr->no_tokens                                              //06-09-04|0x0086
//***************************************************************************             //06-09-04|0x0087
#define MAX_PATH_SIZE 256                                                                 //06-07-13|0x0088
//***************************************************************************             //10-08-19|0x0089
#define BreakCreateText(s) status = create_text(); FileState = s; break                   //10-08-19|0x008a
#define BreakAppendText(s) status = append_text(); FileState = s; break                   //10-08-19|0x008a
#define BreakWriteText(s) status = write_text();  FileState = s; break                    //10-08-19|0x008a
#define BreakWriteCRLF(s) status = write_crlf();  FileState = s; break                    //10-08-19|0x008a
#define BreakCloseLine(s) status = close_line();  FileState = s; break                    //10-08-19|0x008a
#define BreakPutLineExit(s) status = Success;       FileState = s; break                  //10-08-19|0x008a
//*********************************************************************                   //10-08-19|0x008a
#ifndef TestIndex                                                                         //04-10-18|0x0096
#define TestIndex 0                                                                       //04-10-18|0x0096
#endif                                                                                    //04-10-18|0x0096
//------------------------------------------------------------------------                //04-10-18|0x0096
enum {  Initial_1 = TestIndex };                                                          //04-10-18|0x0096
//------------------------------------------------------------------------                //04-10-18|0x0096
#undef TestIndex                                                                          //04-10-18|0x0096
#define TestIndex Initial_1+1                                                             //04-10-18|0x0096
//************************************************************************                //04-10-18|0x0096
#ifndef TestIndex                                                                         //06-09-04|0x00b8
#define TestIndex 0                                                                       //06-09-04|0x00b8
#endif                                                                                    //06-09-04|0x00b8
//------------------------------------------------------------------------                //06-09-04|0x00b8
enum {  set_display_flag_1 = TestIndex };                                                 //06-09-04|0x00b8
//------------------------------------------------------------------------                //06-09-04|0x00b8
#undef TestIndex                                                                          //06-09-04|0x00b8
#define TestIndex set_display_flag_1+1                                                    //06-09-04|0x00b8
//************************************************************************                //06-09-04|0x00b8
#ifndef TestIndex                                                                         //09-01-10|0x00db
#define TestIndex 0                                                                       //09-01-10|0x00db
#endif                                                                                    //09-01-10|0x00db
//------------------------------------------------------------------------                //09-01-10|0x00db
enum {  enable_display_1 = TestIndex };                                                   //09-01-10|0x00db
//------------------------------------------------------------------------                //09-01-10|0x00db
#undef TestIndex                                                                          //09-01-10|0x00db
#define TestIndex enable_display_1+1                                                      //09-01-10|0x00db
//************************************************************************                //09-01-10|0x00db
#ifndef TestIndex                                                                         //09-01-10|0x010e
#define TestIndex 0                                                                       //09-01-10|0x010e
#endif                                                                                    //09-01-10|0x010e
//------------------------------------------------------------------------                //09-01-10|0x010e
enum {  disable_display_1 = TestIndex };                                                  //09-01-10|0x010e
//------------------------------------------------------------------------                //09-01-10|0x010e
#undef TestIndex                                                                          //09-01-10|0x010e
#define TestIndex disable_display_1+1                                                     //09-01-10|0x010e
//************************************************************************                //09-01-10|0x010e
#ifndef TestIndex                                                                         //08-04-16|0x013c
#define TestIndex 0                                                                       //08-04-16|0x013c
#endif                                                                                    //08-04-16|0x013c
//------------------------------------------------------------------------                //08-04-16|0x013c
enum {  display_on_1 = TestIndex };                                                       //08-04-16|0x013c
//------------------------------------------------------------------------                //08-04-16|0x013c
#undef TestIndex                                                                          //08-04-16|0x013c
#define TestIndex display_on_1+1                                                          //08-04-16|0x013c
//************************************************************************                //08-04-16|0x013c
#ifndef TestIndex                                                                         //08-04-16|0x0169
#define TestIndex 0                                                                       //08-04-16|0x0169
#endif                                                                                    //08-04-16|0x0169
//------------------------------------------------------------------------                //08-04-16|0x0169
enum {  display_off_1 = TestIndex };                                                      //08-04-16|0x0169
//------------------------------------------------------------------------                //08-04-16|0x0169
#undef TestIndex                                                                          //08-04-16|0x0169
#define TestIndex display_off_1+1                                                         //08-04-16|0x0169
//************************************************************************                //08-04-16|0x0169
#ifndef TestIndex                                                                         //07-01-30|0x0191
#define TestIndex 0                                                                       //07-01-30|0x0191
#endif                                                                                    //07-01-30|0x0191
//------------------------------------------------------------------------                //07-01-30|0x0191
enum {  open_text_state_1 = TestIndex };                                                  //07-01-30|0x0191
//------------------------------------------------------------------------                //07-01-30|0x0191
#undef TestIndex                                                                          //07-01-30|0x0191
#define TestIndex open_text_state_1+1                                                     //07-01-30|0x0191
//************************************************************************                //07-01-30|0x0191
#ifndef TestIndex                                                                         //05-01-28|0x01aa
#define TestIndex 0                                                                       //05-01-28|0x01aa
#endif                                                                                    //05-01-28|0x01aa
//------------------------------------------------------------------------                //05-01-28|0x01aa
enum {  InitialBinary_1 = TestIndex };                                                    //05-01-28|0x01aa
//------------------------------------------------------------------------                //05-01-28|0x01aa
#undef TestIndex                                                                          //05-01-28|0x01aa
#define TestIndex InitialBinary_1+1                                                       //05-01-28|0x01aa
//************************************************************************                //05-01-28|0x01aa
#ifndef TestIndex                                                                         //04-10-18|0x01cc
#define TestIndex 0                                                                       //04-10-18|0x01cc
#endif                                                                                    //04-10-18|0x01cc
//------------------------------------------------------------------------                //04-10-18|0x01cc
enum {  Commit_1 = TestIndex };                                                           //04-10-18|0x01cc
//------------------------------------------------------------------------                //04-10-18|0x01cc
#undef TestIndex                                                                          //04-10-18|0x01cc
#define TestIndex Commit_1+1                                                              //04-10-18|0x01cc
//************************************************************************                //04-10-18|0x01cc
#ifndef TestIndex                                                                         //05-02-01|0x01ea
#define TestIndex 0                                                                       //05-02-01|0x01ea
#endif                                                                                    //05-02-01|0x01ea
//------------------------------------------------------------------------                //05-02-01|0x01ea
enum {  CommitBinary_1 = TestIndex };                                                     //05-02-01|0x01ea
//------------------------------------------------------------------------                //05-02-01|0x01ea
#undef TestIndex                                                                          //05-02-01|0x01ea
#define TestIndex CommitBinary_1+1                                                        //05-02-01|0x01ea
//************************************************************************                //05-02-01|0x01ea
#ifndef TestIndex                                                                         //04-10-18|0x020a
#define TestIndex 0                                                                       //04-10-18|0x020a
#endif                                                                                    //04-10-18|0x020a
//------------------------------------------------------------------------                //04-10-18|0x020a
enum {  Release_1 = TestIndex };                                                          //04-10-18|0x020a
//------------------------------------------------------------------------                //04-10-18|0x020a
#undef TestIndex                                                                          //04-10-18|0x020a
#define TestIndex Release_1+1                                                             //04-10-18|0x020a
//************************************************************************                //04-10-18|0x020a
#ifndef TestIndex                                                                         //07-03-23|0x0229
#define TestIndex 0                                                                       //07-03-23|0x0229
#endif                                                                                    //07-03-23|0x0229
//------------------------------------------------------------------------                //07-03-23|0x0229
enum {  EnterPath_1 = TestIndex };                                                        //07-03-23|0x0229
//------------------------------------------------------------------------                //07-03-23|0x0229
#undef TestIndex                                                                          //07-03-23|0x0229
#define TestIndex EnterPath_1+1                                                           //07-03-23|0x0229
//************************************************************************                //07-03-23|0x0229
#ifndef TestIndex                                                                         //04-10-18|0x024e
#define TestIndex 0                                                                       //04-10-18|0x024e
#endif                                                                                    //04-10-18|0x024e
//------------------------------------------------------------------------                //04-10-18|0x024e
enum {  EnterName_1 = TestIndex };                                                        //04-10-18|0x024e
//------------------------------------------------------------------------                //04-10-18|0x024e
#undef TestIndex                                                                          //04-10-18|0x024e
#define TestIndex EnterName_1+1                                                           //04-10-18|0x024e
//************************************************************************                //04-10-18|0x024e
#ifndef TestIndex                                                                         //04-10-18|0x0276
#define TestIndex 0                                                                       //04-10-18|0x0276
#endif                                                                                    //04-10-18|0x0276
//------------------------------------------------------------------------                //04-10-18|0x0276
enum {  Exists_1 = TestIndex };                                                           //04-10-18|0x0276
//------------------------------------------------------------------------                //04-10-18|0x0276
#undef TestIndex                                                                          //04-10-18|0x0276
#define TestIndex Exists_1+1                                                              //04-10-18|0x0276
//************************************************************************                //04-10-18|0x0276
#ifndef TestIndex                                                                         //05-02-01|0x0295
#define TestIndex 0                                                                       //05-02-01|0x0295
#endif                                                                                    //05-02-01|0x0295
//------------------------------------------------------------------------                //05-02-01|0x0295
enum {  Close_1 = TestIndex };                                                            //05-02-01|0x0295
//------------------------------------------------------------------------                //05-02-01|0x0295
#undef TestIndex                                                                          //05-02-01|0x0295
#define TestIndex Close_1+1                                                               //05-02-01|0x0295
//************************************************************************                //05-02-01|0x0295
#ifndef TestIndex                                                                         //06-09-04|0x02b5
#define TestIndex 0                                                                       //06-09-04|0x02b5
#endif                                                                                    //06-09-04|0x02b5
//------------------------------------------------------------------------                //06-09-04|0x02b5
enum {  Delete_1 = TestIndex };                                                           //06-09-04|0x02b5
//------------------------------------------------------------------------                //06-09-04|0x02b5
#undef TestIndex                                                                          //06-09-04|0x02b5
#define TestIndex Delete_1+1                                                              //06-09-04|0x02b5
//************************************************************************                //06-09-04|0x02b5
#ifndef TestIndex                                                                         //04-10-18|0x030f
#define TestIndex 0                                                                       //04-10-18|0x030f
#endif                                                                                    //04-10-18|0x030f
//------------------------------------------------------------------------                //04-10-18|0x030f
enum {  OpenText_1 = TestIndex };                                                         //04-10-18|0x030f
//------------------------------------------------------------------------                //04-10-18|0x030f
#undef TestIndex                                                                          //04-10-18|0x030f
#define TestIndex OpenText_1+1                                                            //04-10-18|0x030f
//************************************************************************                //04-10-18|0x030f
#ifndef TestIndex                                                                         //07-08-11|0x033b
#define TestIndex 0                                                                       //07-08-11|0x033b
#endif                                                                                    //07-08-11|0x033b
//------------------------------------------------------------------------                //07-08-11|0x033b
enum {  text_read_status_1 = TestIndex };                                                 //07-08-11|0x033b
//------------------------------------------------------------------------                //07-08-11|0x033b
#undef TestIndex                                                                          //07-08-11|0x033b
#define TestIndex text_read_status_1+1                                                    //07-08-11|0x033b
//************************************************************************                //07-08-11|0x033b
#ifndef TestIndex                                                                         //04-10-18|0x0362
#define TestIndex 0                                                                       //04-10-18|0x0362
#endif                                                                                    //04-10-18|0x0362
//------------------------------------------------------------------------                //04-10-18|0x0362
enum {  ReadText_1 = TestIndex };                                                         //04-10-18|0x0362
//------------------------------------------------------------------------                //04-10-18|0x0362
#undef TestIndex                                                                          //04-10-18|0x0362
#define TestIndex ReadText_1+1                                                            //04-10-18|0x0362
//************************************************************************                //04-10-18|0x0362
#define GetToken PrecformGetToken(token_addr, TextStringAddr)                             //06-07-13|0x0364
#define GetText PrecformGetText(token_addr,  TextStringAddr)                              //06-07-13|0x0364
#define GetString PrecformGetString(token_addr,TextStringAddr)                            //06-07-13|0x0364
#define GetLine get_line(display_flag)                                                    //06-07-13|0x0364
#define LineTest line_test()                                                              //06-07-13|0x0364
#define FirstDelim first_delim()                                                          //06-07-13|0x0364
#define EndTest end_test()                                                                //06-07-13|0x0364
#define ContTest cont_test()                                                              //06-07-13|0x0364
#define TypeToken token_type()                                                            //06-07-13|0x0364
#define NextDelim next_delim()                                                            //06-07-13|0x0364
#define IllegalLineEnd Finish("Illegal Line End")                                         //06-07-13|0x0364
//**********************************************************************                  //06-07-13|0x0364
#ifndef TestIndex                                                                         //08-04-18|0x03ac
#define TestIndex 0                                                                       //08-04-18|0x03ac
#endif                                                                                    //08-04-18|0x03ac
//------------------------------------------------------------------------                //08-04-18|0x03ac
enum {  TestLineEnd_1 = TestIndex };                                                      //08-04-18|0x03ac
//------------------------------------------------------------------------                //08-04-18|0x03ac
#undef TestIndex                                                                          //08-04-18|0x03ac
#define TestIndex TestLineEnd_1+1                                                         //08-04-18|0x03ac
//************************************************************************                //08-04-18|0x03ac
#ifndef TestIndex                                                                         //08-04-18|0x03ad
#define TestIndex 0                                                                       //08-04-18|0x03ad
#endif                                                                                    //08-04-18|0x03ad
//------------------------------------------------------------------------                //08-04-18|0x03ad
enum {  TestLineEnd_2 = TestIndex };                                                      //08-04-18|0x03ad
//------------------------------------------------------------------------                //08-04-18|0x03ad
#undef TestIndex                                                                          //08-04-18|0x03ad
#define TestIndex TestLineEnd_2+1                                                         //08-04-18|0x03ad
//************************************************************************                //08-04-18|0x03ad
#ifndef TestIndex                                                                         //11-02-15|0x03e5
#define TestIndex 0                                                                       //11-02-15|0x03e5
#endif                                                                                    //11-02-15|0x03e5
//------------------------------------------------------------------------                //11-02-15|0x03e5
enum {  DateLineEnd_1 = TestIndex };                                                      //11-02-15|0x03e5
//------------------------------------------------------------------------                //11-02-15|0x03e5
#undef TestIndex                                                                          //11-02-15|0x03e5
#define TestIndex DateLineEnd_1+1                                                         //11-02-15|0x03e5
//************************************************************************                //11-02-15|0x03e5
#ifndef TestIndex                                                                         //07-02-02|0x0438
#define TestIndex 0                                                                       //07-02-02|0x0438
#endif                                                                                    //07-02-02|0x0438
//------------------------------------------------------------------------                //07-02-02|0x0438
enum {  GetText_1 = TestIndex };                                                          //07-02-02|0x0438
//------------------------------------------------------------------------                //07-02-02|0x0438
#undef TestIndex                                                                          //07-02-02|0x0438
#define TestIndex GetText_1+1                                                             //07-02-02|0x0438
//************************************************************************                //07-02-02|0x0438
#ifndef TestIndex                                                                         //10-08-19|0x045c
#define TestIndex 0                                                                       //10-08-19|0x045c
#endif                                                                                    //10-08-19|0x045c
//------------------------------------------------------------------------                //10-08-19|0x045c
enum {  PutText_1 = TestIndex };                                                          //10-08-19|0x045c
//------------------------------------------------------------------------                //10-08-19|0x045c
#undef TestIndex                                                                          //10-08-19|0x045c
#define TestIndex PutText_1+1                                                             //10-08-19|0x045c
//************************************************************************                //10-08-19|0x045c
#ifndef TestIndex                                                                         //check   |0x0486
#define TestIndex 0                                                                       //check   |0x0486
#endif                                                                                    //check   |0x0486
//------------------------------------------------------------------------                //check   |0x0486
enum {  FileAppendText_1 = TestIndex };                                                   //check   |0x0486
//------------------------------------------------------------------------                //check   |0x0486
#undef TestIndex                                                                          //check   |0x0486
#define TestIndex FileAppendText_1+1                                                      //check   |0x0486
//************************************************************************                //check   |0x0486
#ifndef TestIndex                                                                         //10-08-19|0x04b0
#define TestIndex 0                                                                       //10-08-19|0x04b0
#endif                                                                                    //10-08-19|0x04b0
//------------------------------------------------------------------------                //10-08-19|0x04b0
enum {  PutCRLF_1 = TestIndex };                                                          //10-08-19|0x04b0
//------------------------------------------------------------------------                //10-08-19|0x04b0
#undef TestIndex                                                                          //10-08-19|0x04b0
#define TestIndex PutCRLF_1+1                                                             //10-08-19|0x04b0
//************************************************************************                //10-08-19|0x04b0
#ifndef TestIndex                                                                         //<----   |0x04d8
#define TestIndex 0                                                                       //<----   |0x04d8
#endif                                                                                    //<----   |0x04d8
//------------------------------------------------------------------------                //<----   |0x04d8
enum {  PutDbug_1 = TestIndex };                                                          //<----   |0x04d8
//------------------------------------------------------------------------                //<----   |0x04d8
#undef TestIndex                                                                          //<----   |0x04d8
#define TestIndex PutDbug_1+1                                                             //<----   |0x04d8
//************************************************************************                //<----   |0x04d8
#ifndef TestIndex                                                                         //04-10-18|0x0504
#define TestIndex 0                                                                       //04-10-18|0x0504
#endif                                                                                    //04-10-18|0x0504
//------------------------------------------------------------------------                //04-10-18|0x0504
enum {  CreateText_1 = TestIndex };                                                       //04-10-18|0x0504
//------------------------------------------------------------------------                //04-10-18|0x0504
#undef TestIndex                                                                          //04-10-18|0x0504
#define TestIndex CreateText_1+1                                                          //04-10-18|0x0504
//************************************************************************                //04-10-18|0x0504
#ifndef TestIndex                                                                         //07-02-02|0x0520
#define TestIndex 0                                                                       //07-02-02|0x0520
#endif                                                                                    //07-02-02|0x0520
//------------------------------------------------------------------------                //07-02-02|0x0520
enum {  append_text_1 = TestIndex };                                                      //07-02-02|0x0520
//------------------------------------------------------------------------                //07-02-02|0x0520
#undef TestIndex                                                                          //07-02-02|0x0520
#define TestIndex append_text_1+1                                                         //07-02-02|0x0520
//************************************************************************                //07-02-02|0x0520
#ifndef TestIndex                                                                         //10-08-19|0x0537
#define TestIndex 0                                                                       //10-08-19|0x0537
#endif                                                                                    //10-08-19|0x0537
//------------------------------------------------------------------------                //10-08-19|0x0537
enum {  write_text_1 = TestIndex };                                                       //10-08-19|0x0537
//------------------------------------------------------------------------                //10-08-19|0x0537
#undef TestIndex                                                                          //10-08-19|0x0537
#define TestIndex write_text_1+1                                                          //10-08-19|0x0537
//************************************************************************                //10-08-19|0x0537
#ifndef TestIndex                                                                         //10-08-19|0x0555
#define TestIndex 0                                                                       //10-08-19|0x0555
#endif                                                                                    //10-08-19|0x0555
//------------------------------------------------------------------------                //10-08-19|0x0555
enum {  write_crlf_1 = TestIndex };                                                       //10-08-19|0x0555
//------------------------------------------------------------------------                //10-08-19|0x0555
#undef TestIndex                                                                          //10-08-19|0x0555
#define TestIndex write_crlf_1+1                                                          //10-08-19|0x0555
//************************************************************************                //10-08-19|0x0555
#ifndef TestIndex                                                                         //06-10-05|0x0572
#define TestIndex 0                                                                       //06-10-05|0x0572
#endif                                                                                    //06-10-05|0x0572
//------------------------------------------------------------------------                //06-10-05|0x0572
enum {  close_line_1 = TestIndex };                                                       //06-10-05|0x0572
//------------------------------------------------------------------------                //06-10-05|0x0572
#undef TestIndex                                                                          //06-10-05|0x0572
#define TestIndex close_line_1+1                                                          //06-10-05|0x0572
//************************************************************************                //06-10-05|0x0572
#define ReadLine read_line()                                                              //06-07-13|0x058a
#define CharTest char_test()                                                              //06-07-13|0x058a
#define ProcTab process_tab()                                                             //06-07-13|0x058a
#define DispLine disp_line(DisplayFlag)                                                   //06-07-13|0x058a
//**********************************************************************                  //06-07-13|0x058a
#ifndef TestIndex                                                                         //04-10-18|0x058c
#define TestIndex 0                                                                       //04-10-18|0x058c
#endif                                                                                    //04-10-18|0x058c
//------------------------------------------------------------------------                //04-10-18|0x058c
enum {  GetLine_1 = TestIndex };                                                          //04-10-18|0x058c
//------------------------------------------------------------------------                //04-10-18|0x058c
#undef TestIndex                                                                          //04-10-18|0x058c
#define TestIndex GetLine_1+1                                                             //04-10-18|0x058c
//************************************************************************                //04-10-18|0x058c
#ifndef TestIndex                                                                         //check   |0x05b8
#define TestIndex 0                                                                       //check   |0x05b8
#endif                                                                                    //check   |0x05b8
//------------------------------------------------------------------------                //check   |0x05b8
enum {  ReadTextSegment_1 = TestIndex };                                                  //check   |0x05b8
//------------------------------------------------------------------------                //check   |0x05b8
#undef TestIndex                                                                          //check   |0x05b8
#define TestIndex ReadTextSegment_1+1                                                     //check   |0x05b8
//************************************************************************                //check   |0x05b8
#ifndef TestIndex                                                                         //check   |0x05b9
#define TestIndex 0                                                                       //check   |0x05b9
#endif                                                                                    //check   |0x05b9
//------------------------------------------------------------------------                //check   |0x05b9
enum {  ReadTextSegment_2 = TestIndex };                                                  //check   |0x05b9
//------------------------------------------------------------------------                //check   |0x05b9
#undef TestIndex                                                                          //check   |0x05b9
#define TestIndex ReadTextSegment_2+1                                                     //check   |0x05b9
//************************************************************************                //check   |0x05b9
#ifndef TestIndex                                                                         //check   |0x05ba
#define TestIndex 0                                                                       //check   |0x05ba
#endif                                                                                    //check   |0x05ba
//------------------------------------------------------------------------                //check   |0x05ba
enum {  ReadTextSegment_3 = TestIndex };                                                  //check   |0x05ba
//------------------------------------------------------------------------                //check   |0x05ba
#undef TestIndex                                                                          //check   |0x05ba
#define TestIndex ReadTextSegment_3+1                                                     //check   |0x05ba
//************************************************************************                //check   |0x05ba
#ifndef TestIndex                                                                         //check   |0x05bb
#define TestIndex 0                                                                       //check   |0x05bb
#endif                                                                                    //check   |0x05bb
//------------------------------------------------------------------------                //check   |0x05bb
enum {  ReadTextSegment_4 = TestIndex };                                                  //check   |0x05bb
//------------------------------------------------------------------------                //check   |0x05bb
#undef TestIndex                                                                          //check   |0x05bb
#define TestIndex ReadTextSegment_4+1                                                     //check   |0x05bb
//************************************************************************                //check   |0x05bb
#ifndef TestIndex                                                                         //check   |0x05bc
#define TestIndex 0                                                                       //check   |0x05bc
#endif                                                                                    //check   |0x05bc
//------------------------------------------------------------------------                //check   |0x05bc
enum {  ReadTextSegment_5 = TestIndex };                                                  //check   |0x05bc
//------------------------------------------------------------------------                //check   |0x05bc
#undef TestIndex                                                                          //check   |0x05bc
#define TestIndex ReadTextSegment_5+1                                                     //check   |0x05bc
//************************************************************************                //check   |0x05bc
#ifndef TestIndex                                                                         //04-10-18|0x05f4
#define TestIndex 0                                                                       //04-10-18|0x05f4
#endif                                                                                    //04-10-18|0x05f4
//------------------------------------------------------------------------                //04-10-18|0x05f4
enum {  ReadLine_1 = TestIndex };                                                         //04-10-18|0x05f4
//------------------------------------------------------------------------                //04-10-18|0x05f4
#undef TestIndex                                                                          //04-10-18|0x05f4
#define TestIndex ReadLine_1+1                                                            //04-10-18|0x05f4
//************************************************************************                //04-10-18|0x05f4
#ifndef TestIndex                                                                         //13-01-17|0x0634
#define TestIndex 0                                                                       //13-01-17|0x0634
#endif                                                                                    //13-01-17|0x0634
//------------------------------------------------------------------------                //13-01-17|0x0634
enum {  InitialReadSegment_1 = TestIndex };                                               //13-01-17|0x0634
//------------------------------------------------------------------------                //13-01-17|0x0634
#undef TestIndex                                                                          //13-01-17|0x0634
#define TestIndex InitialReadSegment_1+1                                                  //13-01-17|0x0634
//************************************************************************                //13-01-17|0x0634
#ifndef TestIndex                                                                         //12-12-07|0x064c
#define TestIndex 0                                                                       //12-12-07|0x064c
#endif                                                                                    //12-12-07|0x064c
//------------------------------------------------------------------------                //12-12-07|0x064c
enum {  ReadSegment_1 = TestIndex };                                                      //12-12-07|0x064c
//------------------------------------------------------------------------                //12-12-07|0x064c
#undef TestIndex                                                                          //12-12-07|0x064c
#define TestIndex ReadSegment_1+1                                                         //12-12-07|0x064c
//************************************************************************                //12-12-07|0x064c
#ifndef TestIndex                                                                         //13-04-25|0x067e
#define TestIndex 0                                                                       //13-04-25|0x067e
#endif                                                                                    //13-04-25|0x067e
//------------------------------------------------------------------------                //13-04-25|0x067e
enum {  IsolateSegment_1 = TestIndex };                                                   //13-04-25|0x067e
//------------------------------------------------------------------------                //13-04-25|0x067e
#undef TestIndex                                                                          //13-04-25|0x067e
#define TestIndex IsolateSegment_1+1                                                      //13-04-25|0x067e
//************************************************************************                //13-04-25|0x067e
#ifndef TestIndex                                                                         //13-04-25|0x067f
#define TestIndex 0                                                                       //13-04-25|0x067f
#endif                                                                                    //13-04-25|0x067f
//------------------------------------------------------------------------                //13-04-25|0x067f
enum {  IsolateSegment_2 = TestIndex };                                                   //13-04-25|0x067f
//------------------------------------------------------------------------                //13-04-25|0x067f
#undef TestIndex                                                                          //13-04-25|0x067f
#define TestIndex IsolateSegment_2+1                                                      //13-04-25|0x067f
//************************************************************************                //13-04-25|0x067f
#ifndef TestIndex                                                                         //13-04-25|0x0680
#define TestIndex 0                                                                       //13-04-25|0x0680
#endif                                                                                    //13-04-25|0x0680
//------------------------------------------------------------------------                //13-04-25|0x0680
enum {  IsolateSegment_3 = TestIndex };                                                   //13-04-25|0x0680
//------------------------------------------------------------------------                //13-04-25|0x0680
#undef TestIndex                                                                          //13-04-25|0x0680
#define TestIndex IsolateSegment_3+1                                                      //13-04-25|0x0680
//************************************************************************                //13-04-25|0x0680
#ifndef TestIndex                                                                         //13-04-25|0x0681
#define TestIndex 0                                                                       //13-04-25|0x0681
#endif                                                                                    //13-04-25|0x0681
//------------------------------------------------------------------------                //13-04-25|0x0681
enum {  IsolateSegment_4 = TestIndex };                                                   //13-04-25|0x0681
//------------------------------------------------------------------------                //13-04-25|0x0681
#undef TestIndex                                                                          //13-04-25|0x0681
#define TestIndex IsolateSegment_4+1                                                      //13-04-25|0x0681
//************************************************************************                //13-04-25|0x0681
#ifndef TestIndex                                                                         //13-04-25|0x0682
#define TestIndex 0                                                                       //13-04-25|0x0682
#endif                                                                                    //13-04-25|0x0682
//------------------------------------------------------------------------                //13-04-25|0x0682
enum {  IsolateSegment_5 = TestIndex };                                                   //13-04-25|0x0682
//------------------------------------------------------------------------                //13-04-25|0x0682
#undef TestIndex                                                                          //13-04-25|0x0682
#define TestIndex IsolateSegment_5+1                                                      //13-04-25|0x0682
//************************************************************************                //13-04-25|0x0682
#ifndef TestIndex                                                                         //13-01-17|0x06b0
#define TestIndex 0                                                                       //13-01-17|0x06b0
#endif                                                                                    //13-01-17|0x06b0
//------------------------------------------------------------------------                //13-01-17|0x06b0
enum {  IsolateSpecialChar_1 = TestIndex };                                               //13-01-17|0x06b0
//------------------------------------------------------------------------                //13-01-17|0x06b0
#undef TestIndex                                                                          //13-01-17|0x06b0
#define TestIndex IsolateSpecialChar_1+1                                                  //13-01-17|0x06b0
//************************************************************************                //13-01-17|0x06b0
#ifndef TestIndex                                                                         //13-01-17|0x06b1
#define TestIndex 0                                                                       //13-01-17|0x06b1
#endif                                                                                    //13-01-17|0x06b1
//------------------------------------------------------------------------                //13-01-17|0x06b1
enum {  IsolateSpecialChar_2 = TestIndex };                                               //13-01-17|0x06b1
//------------------------------------------------------------------------                //13-01-17|0x06b1
#undef TestIndex                                                                          //13-01-17|0x06b1
#define TestIndex IsolateSpecialChar_2+1                                                  //13-01-17|0x06b1
//************************************************************************                //13-01-17|0x06b1
#ifndef TestIndex                                                                         //13-01-17|0x06b2
#define TestIndex 0                                                                       //13-01-17|0x06b2
#endif                                                                                    //13-01-17|0x06b2
//------------------------------------------------------------------------                //13-01-17|0x06b2
enum {  IsolateSpecialChar_3 = TestIndex };                                               //13-01-17|0x06b2
//------------------------------------------------------------------------                //13-01-17|0x06b2
#undef TestIndex                                                                          //13-01-17|0x06b2
#define TestIndex IsolateSpecialChar_3+1                                                  //13-01-17|0x06b2
//************************************************************************                //13-01-17|0x06b2
#ifndef TestIndex                                                                         //13-01-17|0x06b3
#define TestIndex 0                                                                       //13-01-17|0x06b3
#endif                                                                                    //13-01-17|0x06b3
//------------------------------------------------------------------------                //13-01-17|0x06b3
enum {  IsolateSpecialChar_4 = TestIndex };                                               //13-01-17|0x06b3
//------------------------------------------------------------------------                //13-01-17|0x06b3
#undef TestIndex                                                                          //13-01-17|0x06b3
#define TestIndex IsolateSpecialChar_4+1                                                  //13-01-17|0x06b3
//************************************************************************                //13-01-17|0x06b3
#ifndef TestIndex                                                                         //13-01-17|0x06b4
#define TestIndex 0                                                                       //13-01-17|0x06b4
#endif                                                                                    //13-01-17|0x06b4
//------------------------------------------------------------------------                //13-01-17|0x06b4
enum {  IsolateSpecialChar_5 = TestIndex };                                               //13-01-17|0x06b4
//------------------------------------------------------------------------                //13-01-17|0x06b4
#undef TestIndex                                                                          //13-01-17|0x06b4
#define TestIndex IsolateSpecialChar_5+1                                                  //13-01-17|0x06b4
//************************************************************************                //13-01-17|0x06b4
#ifndef TestIndex                                                                         //13-01-17|0x06d9
#define TestIndex 0                                                                       //13-01-17|0x06d9
#endif                                                                                    //13-01-17|0x06d9
//------------------------------------------------------------------------                //13-01-17|0x06d9
enum {  IsolateTextSegment_1 = TestIndex };                                               //13-01-17|0x06d9
//------------------------------------------------------------------------                //13-01-17|0x06d9
#undef TestIndex                                                                          //13-01-17|0x06d9
#define TestIndex IsolateTextSegment_1+1                                                  //13-01-17|0x06d9
//************************************************************************                //13-01-17|0x06d9
#ifndef TestIndex                                                                         //13-01-17|0x06da
#define TestIndex 0                                                                       //13-01-17|0x06da
#endif                                                                                    //13-01-17|0x06da
//------------------------------------------------------------------------                //13-01-17|0x06da
enum {  IsolateTextSegment_2 = TestIndex };                                               //13-01-17|0x06da
//------------------------------------------------------------------------                //13-01-17|0x06da
#undef TestIndex                                                                          //13-01-17|0x06da
#define TestIndex IsolateTextSegment_2+1                                                  //13-01-17|0x06da
//************************************************************************                //13-01-17|0x06da
#ifndef TestIndex                                                                         //13-01-17|0x0705
#define TestIndex 0                                                                       //13-01-17|0x0705
#endif                                                                                    //13-01-17|0x0705
//------------------------------------------------------------------------                //13-01-17|0x0705
enum {  CompleteReadSegment_1 = TestIndex };                                              //13-01-17|0x0705
//------------------------------------------------------------------------                //13-01-17|0x0705
#undef TestIndex                                                                          //13-01-17|0x0705
#define TestIndex CompleteReadSegment_1+1                                                 //13-01-17|0x0705
//************************************************************************                //13-01-17|0x0705
#ifndef TestIndex                                                                         //13-02-15|0x0731
#define TestIndex 0                                                                       //13-02-15|0x0731
#endif                                                                                    //13-02-15|0x0731
//------------------------------------------------------------------------                //13-02-15|0x0731
enum {  FinishReadSegment_1 = TestIndex };                                                //13-02-15|0x0731
//------------------------------------------------------------------------                //13-02-15|0x0731
#undef TestIndex                                                                          //13-02-15|0x0731
#define TestIndex FinishReadSegment_1+1                                                   //13-02-15|0x0731
//************************************************************************                //13-02-15|0x0731
#ifndef TestIndex                                                                         //13-02-15|0x074a
#define TestIndex 0                                                                       //13-02-15|0x074a
#endif                                                                                    //13-02-15|0x074a
//------------------------------------------------------------------------                //13-02-15|0x074a
enum {  FinalizeTextSegment_1 = TestIndex };                                              //13-02-15|0x074a
//------------------------------------------------------------------------                //13-02-15|0x074a
#undef TestIndex                                                                          //13-02-15|0x074a
#define TestIndex FinalizeTextSegment_1+1                                                 //13-02-15|0x074a
//************************************************************************                //13-02-15|0x074a
#ifndef TestIndex                                                                         //07-08-11|0x076c
#define TestIndex 0                                                                       //07-08-11|0x076c
#endif                                                                                    //07-08-11|0x076c
//------------------------------------------------------------------------                //07-08-11|0x076c
enum {  end_of_textfile_1 = TestIndex };                                                  //07-08-11|0x076c
//------------------------------------------------------------------------                //07-08-11|0x076c
#undef TestIndex                                                                          //07-08-11|0x076c
#define TestIndex end_of_textfile_1+1                                                     //07-08-11|0x076c
//************************************************************************                //07-08-11|0x076c
#ifndef TestIndex                                                                         //04-10-18|0x0789
#define TestIndex 0                                                                       //04-10-18|0x0789
#endif                                                                                    //04-10-18|0x0789
//------------------------------------------------------------------------                //04-10-18|0x0789
enum {  CharTest_1 = TestIndex };                                                         //04-10-18|0x0789
//------------------------------------------------------------------------                //04-10-18|0x0789
#undef TestIndex                                                                          //04-10-18|0x0789
#define TestIndex CharTest_1+1                                                            //04-10-18|0x0789
//************************************************************************                //04-10-18|0x0789
#ifndef TestIndex                                                                         //04-10-18|0x078a
#define TestIndex 0                                                                       //04-10-18|0x078a
#endif                                                                                    //04-10-18|0x078a
//------------------------------------------------------------------------                //04-10-18|0x078a
enum {  CharTest_2 = TestIndex };                                                         //04-10-18|0x078a
//------------------------------------------------------------------------                //04-10-18|0x078a
#undef TestIndex                                                                          //04-10-18|0x078a
#define TestIndex CharTest_2+1                                                            //04-10-18|0x078a
//************************************************************************                //04-10-18|0x078a
#ifndef TestIndex                                                                         //04-10-18|0x078b
#define TestIndex 0                                                                       //04-10-18|0x078b
#endif                                                                                    //04-10-18|0x078b
//------------------------------------------------------------------------                //04-10-18|0x078b
enum {  CharTest_3 = TestIndex };                                                         //04-10-18|0x078b
//------------------------------------------------------------------------                //04-10-18|0x078b
#undef TestIndex                                                                          //04-10-18|0x078b
#define TestIndex CharTest_3+1                                                            //04-10-18|0x078b
//************************************************************************                //04-10-18|0x078b
#ifndef TestIndex                                                                         //04-10-18|0x07b4
#define TestIndex 0                                                                       //04-10-18|0x07b4
#endif                                                                                    //04-10-18|0x07b4
//------------------------------------------------------------------------                //04-10-18|0x07b4
enum {  ProcessTab_1 = TestIndex };                                                       //04-10-18|0x07b4
//------------------------------------------------------------------------                //04-10-18|0x07b4
#undef TestIndex                                                                          //04-10-18|0x07b4
#define TestIndex ProcessTab_1+1                                                          //04-10-18|0x07b4
//************************************************************************                //04-10-18|0x07b4
#ifndef TestIndex                                                                         //04-10-18|0x082c
#define TestIndex 0                                                                       //04-10-18|0x082c
#endif                                                                                    //04-10-18|0x082c
//------------------------------------------------------------------------                //04-10-18|0x082c
enum {  DispLine_1 = TestIndex };                                                         //04-10-18|0x082c
//------------------------------------------------------------------------                //04-10-18|0x082c
#undef TestIndex                                                                          //04-10-18|0x082c
#define TestIndex DispLine_1+1                                                            //04-10-18|0x082c
//************************************************************************                //04-10-18|0x082c
#ifndef TestIndex                                                                         //06-08-29|0x085d
#define TestIndex 0                                                                       //06-08-29|0x085d
#endif                                                                                    //06-08-29|0x085d
//------------------------------------------------------------------------                //06-08-29|0x085d
enum {  InitialReadText_1 = TestIndex };                                                  //06-08-29|0x085d
//------------------------------------------------------------------------                //06-08-29|0x085d
#undef TestIndex                                                                          //06-08-29|0x085d
#define TestIndex InitialReadText_1+1                                                     //06-08-29|0x085d
//************************************************************************                //06-08-29|0x085d
#ifndef TestIndex                                                                         //04-10-18|0x0874
#define TestIndex 0                                                                       //04-10-18|0x0874
#endif                                                                                    //04-10-18|0x0874
//------------------------------------------------------------------------                //04-10-18|0x0874
enum {  LineTest_1 = TestIndex };                                                         //04-10-18|0x0874
//------------------------------------------------------------------------                //04-10-18|0x0874
#undef TestIndex                                                                          //04-10-18|0x0874
#define TestIndex LineTest_1+1                                                            //04-10-18|0x0874
//************************************************************************                //04-10-18|0x0874
#ifndef TestIndex                                                                         //04-10-18|0x0875
#define TestIndex 0                                                                       //04-10-18|0x0875
#endif                                                                                    //04-10-18|0x0875
//------------------------------------------------------------------------                //04-10-18|0x0875
enum {  LineTest_2 = TestIndex };                                                         //04-10-18|0x0875
//------------------------------------------------------------------------                //04-10-18|0x0875
#undef TestIndex                                                                          //04-10-18|0x0875
#define TestIndex LineTest_2+1                                                            //04-10-18|0x0875
//************************************************************************                //04-10-18|0x0875
#ifndef TestIndex                                                                         //04-10-18|0x0876
#define TestIndex 0                                                                       //04-10-18|0x0876
#endif                                                                                    //04-10-18|0x0876
//------------------------------------------------------------------------                //04-10-18|0x0876
enum {  LineTest_3 = TestIndex };                                                         //04-10-18|0x0876
//------------------------------------------------------------------------                //04-10-18|0x0876
#undef TestIndex                                                                          //04-10-18|0x0876
#define TestIndex LineTest_3+1                                                            //04-10-18|0x0876
//************************************************************************                //04-10-18|0x0876
#ifndef TestIndex                                                                         //04-10-18|0x0877
#define TestIndex 0                                                                       //04-10-18|0x0877
#endif                                                                                    //04-10-18|0x0877
//------------------------------------------------------------------------                //04-10-18|0x0877
enum {  LineTest_4 = TestIndex };                                                         //04-10-18|0x0877
//------------------------------------------------------------------------                //04-10-18|0x0877
#undef TestIndex                                                                          //04-10-18|0x0877
#define TestIndex LineTest_4+1                                                            //04-10-18|0x0877
//************************************************************************                //04-10-18|0x0877
#ifndef TestIndex                                                                         //04-10-18|0x08a6
#define TestIndex 0                                                                       //04-10-18|0x08a6
#endif                                                                                    //04-10-18|0x08a6
//------------------------------------------------------------------------                //04-10-18|0x08a6
enum {  FirstDelim_1 = TestIndex };                                                       //04-10-18|0x08a6
//------------------------------------------------------------------------                //04-10-18|0x08a6
#undef TestIndex                                                                          //04-10-18|0x08a6
#define TestIndex FirstDelim_1+1                                                          //04-10-18|0x08a6
//************************************************************************                //04-10-18|0x08a6
#ifndef TestIndex                                                                         //04-10-18|0x08a7
#define TestIndex 0                                                                       //04-10-18|0x08a7
#endif                                                                                    //04-10-18|0x08a7
//------------------------------------------------------------------------                //04-10-18|0x08a7
enum {  FirstDelim_2 = TestIndex };                                                       //04-10-18|0x08a7
//------------------------------------------------------------------------                //04-10-18|0x08a7
#undef TestIndex                                                                          //04-10-18|0x08a7
#define TestIndex FirstDelim_2+1                                                          //04-10-18|0x08a7
//************************************************************************                //04-10-18|0x08a7
#ifndef TestIndex                                                                         //04-10-18|0x08a8
#define TestIndex 0                                                                       //04-10-18|0x08a8
#endif                                                                                    //04-10-18|0x08a8
//------------------------------------------------------------------------                //04-10-18|0x08a8
enum {  FirstDelim_3 = TestIndex };                                                       //04-10-18|0x08a8
//------------------------------------------------------------------------                //04-10-18|0x08a8
#undef TestIndex                                                                          //04-10-18|0x08a8
#define TestIndex FirstDelim_3+1                                                          //04-10-18|0x08a8
//************************************************************************                //04-10-18|0x08a8
#ifndef TestIndex                                                                         //06-08-26|0x08d1
#define TestIndex 0                                                                       //06-08-26|0x08d1
#endif                                                                                    //06-08-26|0x08d1
//------------------------------------------------------------------------                //06-08-26|0x08d1
enum {  EndTest_1 = TestIndex };                                                          //06-08-26|0x08d1
//------------------------------------------------------------------------                //06-08-26|0x08d1
#undef TestIndex                                                                          //06-08-26|0x08d1
#define TestIndex EndTest_1+1                                                             //06-08-26|0x08d1
//************************************************************************                //06-08-26|0x08d1
#ifndef TestIndex                                                                         //06-08-26|0x08d2
#define TestIndex 0                                                                       //06-08-26|0x08d2
#endif                                                                                    //06-08-26|0x08d2
//------------------------------------------------------------------------                //06-08-26|0x08d2
enum {  EndTest_2 = TestIndex };                                                          //06-08-26|0x08d2
//------------------------------------------------------------------------                //06-08-26|0x08d2
#undef TestIndex                                                                          //06-08-26|0x08d2
#define TestIndex EndTest_2+1                                                             //06-08-26|0x08d2
//************************************************************************                //06-08-26|0x08d2
#ifndef TestIndex                                                                         //06-08-26|0x08d3
#define TestIndex 0                                                                       //06-08-26|0x08d3
#endif                                                                                    //06-08-26|0x08d3
//------------------------------------------------------------------------                //06-08-26|0x08d3
enum {  EndTest_3 = TestIndex };                                                          //06-08-26|0x08d3
//------------------------------------------------------------------------                //06-08-26|0x08d3
#undef TestIndex                                                                          //06-08-26|0x08d3
#define TestIndex EndTest_3+1                                                             //06-08-26|0x08d3
//************************************************************************                //06-08-26|0x08d3
#ifndef TestIndex                                                                         //06-08-26|0x08d4
#define TestIndex 0                                                                       //06-08-26|0x08d4
#endif                                                                                    //06-08-26|0x08d4
//------------------------------------------------------------------------                //06-08-26|0x08d4
enum {  EndTest_4 = TestIndex };                                                          //06-08-26|0x08d4
//------------------------------------------------------------------------                //06-08-26|0x08d4
#undef TestIndex                                                                          //06-08-26|0x08d4
#define TestIndex EndTest_4+1                                                             //06-08-26|0x08d4
//************************************************************************                //06-08-26|0x08d4
#ifndef TestIndex                                                                         //05-02-01|0x08fb
#define TestIndex 0                                                                       //05-02-01|0x08fb
#endif                                                                                    //05-02-01|0x08fb
//------------------------------------------------------------------------                //05-02-01|0x08fb
enum {  ContTest_1 = TestIndex };                                                         //05-02-01|0x08fb
//------------------------------------------------------------------------                //05-02-01|0x08fb
#undef TestIndex                                                                          //05-02-01|0x08fb
#define TestIndex ContTest_1+1                                                            //05-02-01|0x08fb
//************************************************************************                //05-02-01|0x08fb
#ifndef TestIndex                                                                         //05-02-01|0x08fc
#define TestIndex 0                                                                       //05-02-01|0x08fc
#endif                                                                                    //05-02-01|0x08fc
//------------------------------------------------------------------------                //05-02-01|0x08fc
enum {  ContTest_2 = TestIndex };                                                         //05-02-01|0x08fc
//------------------------------------------------------------------------                //05-02-01|0x08fc
#undef TestIndex                                                                          //05-02-01|0x08fc
#define TestIndex ContTest_2+1                                                            //05-02-01|0x08fc
//************************************************************************                //05-02-01|0x08fc
#ifndef TestIndex                                                                         //05-02-01|0x08fd
#define TestIndex 0                                                                       //05-02-01|0x08fd
#endif                                                                                    //05-02-01|0x08fd
//------------------------------------------------------------------------                //05-02-01|0x08fd
enum {  ContTest_3 = TestIndex };                                                         //05-02-01|0x08fd
//------------------------------------------------------------------------                //05-02-01|0x08fd
#undef TestIndex                                                                          //05-02-01|0x08fd
#define TestIndex ContTest_3+1                                                            //05-02-01|0x08fd
//************************************************************************                //05-02-01|0x08fd
#ifndef TestIndex                                                                         //04-10-18|0x0924
#define TestIndex 0                                                                       //04-10-18|0x0924
#endif                                                                                    //04-10-18|0x0924
//------------------------------------------------------------------------                //04-10-18|0x0924
enum {  TokenType_1 = TestIndex };                                                        //04-10-18|0x0924
//------------------------------------------------------------------------                //04-10-18|0x0924
#undef TestIndex                                                                          //04-10-18|0x0924
#define TestIndex TokenType_1+1                                                           //04-10-18|0x0924
//************************************************************************                //04-10-18|0x0924
#ifndef TestIndex                                                                         //04-10-18|0x0925
#define TestIndex 0                                                                       //04-10-18|0x0925
#endif                                                                                    //04-10-18|0x0925
//------------------------------------------------------------------------                //04-10-18|0x0925
enum {  TokenType_2 = TestIndex };                                                        //04-10-18|0x0925
//------------------------------------------------------------------------                //04-10-18|0x0925
#undef TestIndex                                                                          //04-10-18|0x0925
#define TestIndex TokenType_2+1                                                           //04-10-18|0x0925
//************************************************************************                //04-10-18|0x0925
#ifndef TestIndex                                                                         //04-10-18|0x0926
#define TestIndex 0                                                                       //04-10-18|0x0926
#endif                                                                                    //04-10-18|0x0926
//------------------------------------------------------------------------                //04-10-18|0x0926
enum {  TokenType_3 = TestIndex };                                                        //04-10-18|0x0926
//------------------------------------------------------------------------                //04-10-18|0x0926
#undef TestIndex                                                                          //04-10-18|0x0926
#define TestIndex TokenType_3+1                                                           //04-10-18|0x0926
//************************************************************************                //04-10-18|0x0926
#ifndef TestIndex                                                                         //04-10-18|0x0927
#define TestIndex 0                                                                       //04-10-18|0x0927
#endif                                                                                    //04-10-18|0x0927
//------------------------------------------------------------------------                //04-10-18|0x0927
enum {  TokenType_4 = TestIndex };                                                        //04-10-18|0x0927
//------------------------------------------------------------------------                //04-10-18|0x0927
#undef TestIndex                                                                          //04-10-18|0x0927
#define TestIndex TokenType_4+1                                                           //04-10-18|0x0927
//************************************************************************                //04-10-18|0x0927
#ifndef TestIndex                                                                         //04-10-18|0x0928
#define TestIndex 0                                                                       //04-10-18|0x0928
#endif                                                                                    //04-10-18|0x0928
//------------------------------------------------------------------------                //04-10-18|0x0928
enum {  TokenType_5 = TestIndex };                                                        //04-10-18|0x0928
//------------------------------------------------------------------------                //04-10-18|0x0928
#undef TestIndex                                                                          //04-10-18|0x0928
#define TestIndex TokenType_5+1                                                           //04-10-18|0x0928
//************************************************************************                //04-10-18|0x0928
#ifndef TestIndex                                                                         //04-10-18|0x0929
#define TestIndex 0                                                                       //04-10-18|0x0929
#endif                                                                                    //04-10-18|0x0929
//------------------------------------------------------------------------                //04-10-18|0x0929
enum {  TokenType_6 = TestIndex };                                                        //04-10-18|0x0929
//------------------------------------------------------------------------                //04-10-18|0x0929
#undef TestIndex                                                                          //04-10-18|0x0929
#define TestIndex TokenType_6+1                                                           //04-10-18|0x0929
//************************************************************************                //04-10-18|0x0929
#ifndef TestIndex                                                                         //04-10-18|0x092a
#define TestIndex 0                                                                       //04-10-18|0x092a
#endif                                                                                    //04-10-18|0x092a
//------------------------------------------------------------------------                //04-10-18|0x092a
enum {  TokenType_7 = TestIndex };                                                        //04-10-18|0x092a
//------------------------------------------------------------------------                //04-10-18|0x092a
#undef TestIndex                                                                          //04-10-18|0x092a
#define TestIndex TokenType_7+1                                                           //04-10-18|0x092a
//************************************************************************                //04-10-18|0x092a
#ifndef TestIndex                                                                         //04-10-18|0x092b
#define TestIndex 0                                                                       //04-10-18|0x092b
#endif                                                                                    //04-10-18|0x092b
//------------------------------------------------------------------------                //04-10-18|0x092b
enum {  TokenType_8 = TestIndex };                                                        //04-10-18|0x092b
//------------------------------------------------------------------------                //04-10-18|0x092b
#undef TestIndex                                                                          //04-10-18|0x092b
#define TestIndex TokenType_8+1                                                           //04-10-18|0x092b
//************************************************************************                //04-10-18|0x092b
#define FlagEnd PrecformFlagEnd(token_addr)                                               //05-02-01|0x0973
#ifndef TestIndex                                                                         //04-10-18|0x0975
#define TestIndex 0                                                                       //04-10-18|0x0975
#endif                                                                                    //04-10-18|0x0975
//------------------------------------------------------------------------                //04-10-18|0x0975
enum {  NextDelim_1 = TestIndex };                                                        //04-10-18|0x0975
//------------------------------------------------------------------------                //04-10-18|0x0975
#undef TestIndex                                                                          //04-10-18|0x0975
#define TestIndex NextDelim_1+1                                                           //04-10-18|0x0975
//************************************************************************                //04-10-18|0x0975
#ifndef TestIndex                                                                         //04-10-18|0x0976
#define TestIndex 0                                                                       //04-10-18|0x0976
#endif                                                                                    //04-10-18|0x0976
//------------------------------------------------------------------------                //04-10-18|0x0976
enum {  NextDelim_2 = TestIndex };                                                        //04-10-18|0x0976
//------------------------------------------------------------------------                //04-10-18|0x0976
#undef TestIndex                                                                          //04-10-18|0x0976
#define TestIndex NextDelim_2+1                                                           //04-10-18|0x0976
//************************************************************************                //04-10-18|0x0976
#ifndef TestIndex                                                                         //04-10-18|0x0977
#define TestIndex 0                                                                       //04-10-18|0x0977
#endif                                                                                    //04-10-18|0x0977
//------------------------------------------------------------------------                //04-10-18|0x0977
enum {  NextDelim_3 = TestIndex };                                                        //04-10-18|0x0977
//------------------------------------------------------------------------                //04-10-18|0x0977
#undef TestIndex                                                                          //04-10-18|0x0977
#define TestIndex NextDelim_3+1                                                           //04-10-18|0x0977
//************************************************************************                //04-10-18|0x0977
#ifndef TestIndex                                                                         //04-10-18|0x09a1
#define TestIndex 0                                                                       //04-10-18|0x09a1
#endif                                                                                    //04-10-18|0x09a1
//------------------------------------------------------------------------                //04-10-18|0x09a1
enum {  CreateRecord_1 = TestIndex };                                                     //04-10-18|0x09a1
//------------------------------------------------------------------------                //04-10-18|0x09a1
#undef TestIndex                                                                          //04-10-18|0x09a1
#define TestIndex CreateRecord_1+1                                                        //04-10-18|0x09a1
//************************************************************************                //04-10-18|0x09a1
#ifndef TestIndex                                                                         //06-07-27|0x09c1
#define TestIndex 0                                                                       //06-07-27|0x09c1
#endif                                                                                    //06-07-27|0x09c1
//------------------------------------------------------------------------                //06-07-27|0x09c1
enum {  AppendRecord_1 = TestIndex };                                                     //06-07-27|0x09c1
//------------------------------------------------------------------------                //06-07-27|0x09c1
#undef TestIndex                                                                          //06-07-27|0x09c1
#define TestIndex AppendRecord_1+1                                                        //06-07-27|0x09c1
//************************************************************************                //06-07-27|0x09c1
#ifndef TestIndex                                                                         //05-02-01|0x09e2
#define TestIndex 0                                                                       //05-02-01|0x09e2
#endif                                                                                    //05-02-01|0x09e2
//------------------------------------------------------------------------                //05-02-01|0x09e2
enum {  OpenRecord_1 = TestIndex };                                                       //05-02-01|0x09e2
//------------------------------------------------------------------------                //05-02-01|0x09e2
#undef TestIndex                                                                          //05-02-01|0x09e2
#define TestIndex OpenRecord_1+1                                                          //05-02-01|0x09e2
//************************************************************************                //05-02-01|0x09e2
#ifndef TestIndex                                                                         //04-10-18|0x0a04
#define TestIndex 0                                                                       //04-10-18|0x0a04
#endif                                                                                    //04-10-18|0x0a04
//------------------------------------------------------------------------                //04-10-18|0x0a04
enum {  ReadData_1 = TestIndex };                                                         //04-10-18|0x0a04
//------------------------------------------------------------------------                //04-10-18|0x0a04
#undef TestIndex                                                                          //04-10-18|0x0a04
#define TestIndex ReadData_1+1                                                            //04-10-18|0x0a04
//************************************************************************                //04-10-18|0x0a04
#ifndef TestIndex                                                                         //04-10-18|0x0a2c
#define TestIndex 0                                                                       //04-10-18|0x0a2c
#endif                                                                                    //04-10-18|0x0a2c
//------------------------------------------------------------------------                //04-10-18|0x0a2c
enum {  WriteData_1 = TestIndex };                                                        //04-10-18|0x0a2c
//------------------------------------------------------------------------                //04-10-18|0x0a2c
#undef TestIndex                                                                          //04-10-18|0x0a2c
#define TestIndex WriteData_1+1                                                           //04-10-18|0x0a2c
//************************************************************************                //04-10-18|0x0a2c
#define ReturnClassSuccessState(i) class_state = i; return(Success)                       //05-02-01|0x0a53
#define ReturnSuccessState(i) FileState = i; return(Success)                              //04-10-18|0x0a8a
//*******************************************************************************         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
//****                       END OF FILE                                     ****         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
#endif                                                                                    //05-24-97|0x0b43
