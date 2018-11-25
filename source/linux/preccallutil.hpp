//*****************************************************************************           //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
// PRECEDENCE CALL STACK UTILITIES                                                        //07-06-29|0x001e
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
#ifndef preccallutil_hpp                                                                  //07-06-29|0x0026
#define preccallutil_hpp                                                                  //07-06-29|0x0026
//***************************************************************************             //07-06-29|0x0027
//***************************************************************************             //07-06-29|0x0028
//******                                                               ******             //07-06-29|0x0029
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //07-06-29|0x002a
//******                                                               ******             //07-06-29|0x002b
//***************************************************************************             //07-06-29|0x002c
//***************************************************************************             //07-06-29|0x002d
//***************************************************************************             //07-06-29|0x0030
//***************************************************************************             //07-06-29|0x0031
//******                                                               ******             //07-06-29|0x0032
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //07-06-29|0x0033
//******                                                               ******             //07-06-29|0x0034
//***************************************************************************             //07-06-29|0x0035
//***************************************************************************             //07-06-29|0x0036
#define UserError 0x0000                                                                  //07-06-29|0x0037
#define BuildError 0x7fff                                                                 //07-06-29|0x0037
#define Display 0x7ffe                                                                    //07-06-29|0x0037
#define KeyBoard 0x7ffd                                                                   //07-06-29|0x0037
#define Success 0xffff                                                                    //07-06-29|0x0037
#define SystemError 0x8000                                                                //07-06-29|0x0037
#define Continue 0x0001                                                                   //07-06-29|0x0037
#define FileDone 0x0002                                                                   //07-06-29|0x0037
#define LineDone 0x0003                                                                   //07-06-29|0x0037
#define Yes 0x0004                                                                        //07-06-29|0x0037
#define No 0x0005                                                                         //07-06-29|0x0037
#define RepeatChar '\x6'                                                                  //07-06-29|0x0037
#define Great 0x0007                                                                      //07-06-29|0x0037
#define Equal 0x0008                                                                      //07-06-29|0x0037
#define Less 0x0009                                                                       //07-06-29|0x0037
#define Zero 0x000a                                                                       //07-06-29|0x0037
#define Minus 0x000b                                                                      //07-06-29|0x0037
//***************************************************************************             //07-06-29|0x0038
#define SystemMsg PcgSystemError("PreccallUtil", __LINE__);                               //07-06-29|0x0039
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-06-29|0x0039
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //07-06-29|0x0039
#define BreakFinish(_a) status = Finish(_a); break                                        //07-06-29|0x003a
#define ReturnFinish(_a) return(Finish(_a))                                               //07-06-29|0x003a
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //07-06-29|0x003a
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //07-06-29|0x003a
#define _SwitchErr case UserError: return(UserError)                                      //07-06-29|0x003b
#define _SwitchOk case Success: break                                                     //07-06-29|0x003b
#define _SwitchEnd default: ReturnSystemError                                             //07-06-29|0x003b
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-06-29|0x003b
#define _SwitchYes case Yes:      return(Yes)                                             //07-06-29|0x003b
#define _SwitchNo case No:       return(No)                                               //07-06-29|0x003b
#define _SwitchGroup { _SwitchBase; }                                                     //07-06-29|0x003b
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-06-29|0x003b
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-06-29|0x003b
#define _SwitchBreak _SwitchGroup break                                                   //07-06-29|0x003b
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-06-29|0x003b
//***************************************************************************             //07-06-29|0x005a
//***************************************************************************             //07-06-29|0x005b
//******                                                               ******             //07-06-29|0x005c
//******               GENERAL DEFINITION STATEMENTS                   ******             //07-06-29|0x005d
//******                                                               ******             //07-06-29|0x005e
//***************************************************************************             //07-06-29|0x005f
//***************************************************************************             //07-06-29|0x0060
#define TestSample(i) test_samples[i] = __LINE__                                          //07-06-29|0x0061
#define return_test(j) { TestSample(j);  return(Success); }                               //07-06-29|0x0061
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //07-06-29|0x0061
#define return_no(j) { TestSample(j);  return(No); }                                      //07-06-29|0x0061
#define return_cont(j) { TestSample(j);  return(Continue); }                              //07-06-29|0x0061
#define return_line(j) { TestSample(j);  return(LineDone); }                              //07-06-29|0x0061
#define goto_test(i) { TestSample(i);  goto loop; }                                       //07-06-29|0x0061
#define break_test(i) { TestSample(i);  break; }                                          //07-06-29|0x0061
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //07-06-29|0x0061
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //07-06-29|0x0061
//************************************************************************                //07-06-29|0x0061
#ifndef TestIndex                                                                         //07-06-29|0x0061
#define TestIndex 0                                                                       //07-06-29|0x0061
#endif                                                                                    //07-06-29|0x0061
//------------------------------------------------------------------------                //07-06-29|0x0061
enum {  NoTestSamples = TestIndex };                                                      //07-06-29|0x0061
//------------------------------------------------------------------------                //07-06-29|0x0061
#undef TestIndex                                                                          //07-06-29|0x0061
#define TestIndex NoTestSamples+1                                                         //07-06-29|0x0061
//************************************************************************                //07-06-29|0x0061
//**********************************************************************                  //07-06-29|0x0063
#define CallFile call_data_addr->call_file                                                //07-06-29|0x0063
#define CallPosition call_data_addr->position                                             //07-06-29|0x0063
#define CallDrivePathPos call_data_addr->drive_path_pos                                   //07-06-29|0x0063
#define CallSourcePos call_data_addr->source_pos                                          //07-06-29|0x0063
#define CallMacroPos call_data_addr->macro_pos                                            //07-06-29|0x0063
#define CallDevPos call_data_addr->dev_pos                                                //07-06-29|0x0063
//----------------------------------------------------------------------                  //07-06-29|0x0063
#define CallRunFlag call_data_addr->run_flag                                              //07-06-29|0x0063
#define CallStatus call_data_addr->status                                                 //07-06-29|0x0063
#define CallProcessState call_data_addr->process_state                                    //07-06-29|0x0063
#define CallState call_data_addr->call_state                                              //07-06-29|0x0063
//----------------------------------------------------------------------                  //07-06-29|0x0063
#define CallReturn call_data_addr->call_return                                            //07-06-29|0x0063
#define CallReturnAddr &(call_data_addr->call_return)                                     //07-06-29|0x0063
#define CallReturnChar(i) CallReturn.line[i]                                              //07-06-29|0x0063
#define CallReturnLine CallReturn.line[0]                                                 //07-06-29|0x0063
#define CallReturnLength CallReturn.length                                                //07-06-29|0x0063
#define CallReturnType CallReturn.type                                                    //07-06-29|0x0063
//----------------------------------------------------------------------                  //07-06-29|0x0063
#define CallStack(j) call_data_addr->call_stack[j]                                        //07-06-29|0x0063
#define CallStackAddr(j) &(call_data_addr->call_stack[j])                                 //07-06-29|0x0063
#define CallEchoPosition(j) CallStack(j).echo_position                                    //07-06-29|0x0063
#define CallBridgeAddr(j) &(CallStack(j).call_bridge)                                     //07-06-29|0x0063
#define CallBridgeType(j) CallStack(j).call_bridge.type                                   //07-06-29|0x0063
#define CallNoIncludes(j) CallStack(j).no_includes                                        //07-06-29|0x0063
#define CallStackState(j) CallStack(j).stack_state                                        //07-06-29|0x0063
//----------------------------------------------------------------------                  //07-06-29|0x0063
#define CallArgs(j) CallStack(j).args                                                     //07-06-29|0x0063
#define CallArgsAddr(j) &(CallStack(j).args)                                              //07-06-29|0x0063
//----------------------------------------------------------------------                  //07-06-29|0x0063
#define CallNoTokens(j) CallArgs(j).no_tokens                                             //07-06-29|0x0063
#define CallArg(j,i) CallArgs(j).token[i]                                                 //07-06-29|0x0063
#define CallArgAddr(j,i) &(CallArgs(j).token[i])                                          //07-06-29|0x0063
#define CallTextChar(j,i,k) CallArgs(j).token[i].line[k]                                  //07-06-29|0x0063
#define CallText(j,i) CallArgs(j).token[i].line[0]                                        //07-06-29|0x0063
#define CallLength(j,i) CallArgs(j).token[i].length                                       //07-06-29|0x0063
#define CallType(j,i) CallArgs(j).token[i].type                                           //07-06-29|0x0063
#define CallStartCol(j,i) CallArgs(j).token[i].start_col                                  //07-06-29|0x0063
#define CallStartCall(j,i) CallArgs(j).token[i].start_call                                //07-06-29|0x0063
#define CallMacroLineNo(j) CallArgs(j).token[0].macro_line_no                             //07-06-29|0x0063
//----------------------------------------------------------------------                  //07-06-29|0x0063
#define CallFileAddr &(call_data_addr->call_file)                                         //07-06-29|0x0063
#define AddrChar(i) Addr->line[i]                                                         //07-06-29|0x0064
#define AddrLine Addr->line[0]                                                            //07-06-29|0x0064
#define AddrLineAddr &(Addr->line[0])                                                     //07-06-29|0x0064
#define AddrMacroLineNo Addr->macro_line_no                                               //07-06-29|0x0064
#define AddrType Addr->type                                                               //07-06-29|0x0064
#define AddrStartCol Addr->start_col                                                      //07-06-29|0x0064
#define AddrStartCall Addr->start_call                                                    //07-06-29|0x0064
#define AddrPosition Addr->position                                                       //07-06-29|0x0064
#define AddrLength Addr->length                                                           //07-06-29|0x0064
#define AddrColumn Addr->column                                                           //07-06-29|0x0064
//**********************************************************************                  //07-06-29|0x0064
#define InputChar(i) Input->line[i]                                                       //07-06-29|0x0065
#define InputLine Input->line[0]                                                          //07-06-29|0x0065
#define InputLineAddr &(Input->line[0])                                                   //07-06-29|0x0065
#define InputMacroLineNo Input->macro_line_no                                             //07-06-29|0x0065
#define InputType Input->type                                                             //07-06-29|0x0065
#define InputStartCol Input->start_col                                                    //07-06-29|0x0065
#define InputStartCall Input->start_call                                                  //07-06-29|0x0065
#define InputPosition Input->position                                                     //07-06-29|0x0065
#define InputLength Input->length                                                         //07-06-29|0x0065
#define InputColumn Input->column                                                         //07-06-29|0x0065
//**********************************************************************                  //07-06-29|0x0065
#define OutputChar(i) Output->line[i]                                                     //07-06-29|0x0066
#define OutputLine Output->line[0]                                                        //07-06-29|0x0066
#define OutputLineAddr &(Output->line[0])                                                 //07-06-29|0x0066
#define OutputMacroLineNo Output->macro_line_no                                           //07-06-29|0x0066
#define OutputType Output->type                                                           //07-06-29|0x0066
#define OutputStartCol Output->start_col                                                  //07-06-29|0x0066
#define OutputStartCall Output->start_call                                                //07-06-29|0x0066
#define OutputPosition Output->position                                                   //07-06-29|0x0066
#define OutputLength Output->length                                                       //07-06-29|0x0066
#define OutputColumn Output->column                                                       //07-06-29|0x0066
//**********************************************************************                  //07-06-29|0x0066
//************************************************************************                //07-06-29|0x0067
#define TokensTokenAddr(i) &(Tokens->token[i])                                            //07-06-29|0x0067
#define TokensMacroLineNo(i) Tokens->token[i].macro_line_no                               //07-06-29|0x0067
#define TokensLineAddr(i) &(Tokens->token[i].line[0])                                     //07-06-29|0x0067
#define TokensToken(i) Tokens->token[i]                                                   //07-06-29|0x0067
#define TokensLine(i) Tokens->token[i].line                                               //07-06-29|0x0067
#define TokensLength(i) Tokens->token[i].length                                           //07-06-29|0x0067
#define TokensColumn(i) Tokens->token[i].column                                           //07-06-29|0x0067
#define TokensHash(i) Tokens->token[i].hash                                               //07-06-29|0x0067
#define TokensPosition(i) Tokens->token[i].position                                       //07-06-29|0x0067
#define TokensType(i) Tokens->token[i].type                                               //07-06-29|0x0067
#define TokensStartCol(i) Tokens->token[i].start_col                                      //07-06-29|0x0067
#define TokensStartCall(i) Tokens->token[i].start_call                                    //07-06-29|0x0067
#define TokensChar(i,j) Tokens->token[i].line[j]                                          //07-06-29|0x0067
#define TokensNoTokens Tokens->no_tokens                                                  //07-06-29|0x0067
//**********************************************************************                  //07-06-29|0x0069
#define CallFileInitial FileInitialBinary(CallFileAddr)                                   //07-06-29|0x0069
#define CallFileCommit FileCommitBinary(CallFileAddr)                                     //07-06-29|0x0069
#define CallFileRelease FileRelease()                                                     //07-06-29|0x0069
#define CallFileName FileEnterName(TokensLineAddr(0), ".MST")                             //07-06-29|0x0069
#define CallFileCreate FileCreateRecord()                                                 //07-06-29|0x0069
#define CallFileDelete FileDelete()                                                       //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallFileWrite2(i,j) FileWriteData(CallPosition, i, j)                             //07-06-29|0x0069
#define CallFileWrite1(i) CallFileWrite2(i, sizeof(CALL_STACK))                           //07-06-29|0x0069
#define CallFileWrite(i) CallFileWrite1((SCHAR_FAR) CallStackAddr(i))                     //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallFileRead2(i,j) FileReadData(i, j, sizeof(CALL_STACK))                         //07-06-29|0x0069
#define CallFileRead(i,j) CallFileRead2((SCHAR_FAR) CallStackAddr(i),j)                   //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define StringBasicCopy(i,j) MemCCpy(i, j, 0x00, 256)                                     //07-06-29|0x0069
#define StringDataCopy(i,j) MemCpy(i, j, sizeof(STRING_DATA))                             //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallUnreadReturn Finish("Unread Return")                                          //07-06-29|0x0069
#define CallIllegalReturn Finish("Illegal Return")                                        //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#ifndef TestIndex                                                                         //07-06-29|0x0073
#define TestIndex 0                                                                       //07-06-29|0x0073
#endif                                                                                    //07-06-29|0x0073
//------------------------------------------------------------------------                //07-06-29|0x0073
enum {  call_util_construct_1 = TestIndex };                                              //07-06-29|0x0073
//------------------------------------------------------------------------                //07-06-29|0x0073
#undef TestIndex                                                                          //07-06-29|0x0073
#define TestIndex call_util_construct_1+1                                                 //07-06-29|0x0073
//************************************************************************                //07-06-29|0x0073
#ifndef TestIndex                                                                         //07-06-29|0x008e
#define TestIndex 0                                                                       //07-06-29|0x008e
#endif                                                                                    //07-06-29|0x008e
//------------------------------------------------------------------------                //07-06-29|0x008e
enum {  callutil_create_file_1 = TestIndex };                                             //07-06-29|0x008e
//------------------------------------------------------------------------                //07-06-29|0x008e
#undef TestIndex                                                                          //07-06-29|0x008e
#define TestIndex callutil_create_file_1+1                                                //07-06-29|0x008e
//************************************************************************                //07-06-29|0x008e
#ifndef TestIndex                                                                         //07-06-29|0x00b4
#define TestIndex 0                                                                       //07-06-29|0x00b4
#endif                                                                                    //07-06-29|0x00b4
//------------------------------------------------------------------------                //07-06-29|0x00b4
enum {  callutil_write_file_1 = TestIndex };                                              //07-06-29|0x00b4
//------------------------------------------------------------------------                //07-06-29|0x00b4
#undef TestIndex                                                                          //07-06-29|0x00b4
#define TestIndex callutil_write_file_1+1                                                 //07-06-29|0x00b4
//************************************************************************                //07-06-29|0x00b4
#ifndef TestIndex                                                                         //check   |0x00d6
#define TestIndex 0                                                                       //check   |0x00d6
#endif                                                                                    //check   |0x00d6
//------------------------------------------------------------------------                //check   |0x00d6
enum {  callutil_destroy_file_1 = TestIndex };                                            //check   |0x00d6
//------------------------------------------------------------------------                //check   |0x00d6
#undef TestIndex                                                                          //check   |0x00d6
#define TestIndex callutil_destroy_file_1+1                                               //check   |0x00d6
//************************************************************************                //check   |0x00d6
#ifndef TestIndex                                                                         //07-06-29|0x00f3
#define TestIndex 0                                                                       //07-06-29|0x00f3
#endif                                                                                    //07-06-29|0x00f3
//------------------------------------------------------------------------                //07-06-29|0x00f3
enum {  read_call_file_1 = TestIndex };                                                   //07-06-29|0x00f3
//------------------------------------------------------------------------                //07-06-29|0x00f3
#undef TestIndex                                                                          //07-06-29|0x00f3
#define TestIndex read_call_file_1+1                                                      //07-06-29|0x00f3
//************************************************************************                //07-06-29|0x00f3
#ifndef TestIndex                                                                         //07-06-29|0x0119
#define TestIndex 0                                                                       //07-06-29|0x0119
#endif                                                                                    //07-06-29|0x0119
//------------------------------------------------------------------------                //07-06-29|0x0119
enum {  callutil_strcat_1 = TestIndex };                                                  //07-06-29|0x0119
//------------------------------------------------------------------------                //07-06-29|0x0119
#undef TestIndex                                                                          //07-06-29|0x0119
#define TestIndex callutil_strcat_1+1                                                     //07-06-29|0x0119
//************************************************************************                //07-06-29|0x0119
#ifndef TestIndex                                                                         //07-06-30|0x014a
#define TestIndex 0                                                                       //07-06-30|0x014a
#endif                                                                                    //07-06-30|0x014a
//------------------------------------------------------------------------                //07-06-30|0x014a
enum {  callutil_test_pos_1 = TestIndex };                                                //07-06-30|0x014a
//------------------------------------------------------------------------                //07-06-30|0x014a
#undef TestIndex                                                                          //07-06-30|0x014a
#define TestIndex callutil_test_pos_1+1                                                   //07-06-30|0x014a
//************************************************************************                //07-06-30|0x014a
#ifndef TestIndex                                                                         //07-06-30|0x014b
#define TestIndex 0                                                                       //07-06-30|0x014b
#endif                                                                                    //07-06-30|0x014b
//------------------------------------------------------------------------                //07-06-30|0x014b
enum {  callutil_test_pos_2 = TestIndex };                                                //07-06-30|0x014b
//------------------------------------------------------------------------                //07-06-30|0x014b
#undef TestIndex                                                                          //07-06-30|0x014b
#define TestIndex callutil_test_pos_2+1                                                   //07-06-30|0x014b
//************************************************************************                //07-06-30|0x014b
//*******************************************************************************         //05-24-97|0x0185
//*******************************************************************************         //05-24-97|0x0185
//****                       END OF FILE                                     ****         //05-24-97|0x0185
//*******************************************************************************         //05-24-97|0x0185
//*******************************************************************************         //05-24-97|0x0185
#endif                                                                                    //05-24-97|0x0185
