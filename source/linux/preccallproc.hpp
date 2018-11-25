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
#ifndef preccallproc_hpp                                                                  //07-06-29|0x0026
#define preccallproc_hpp                                                                  //07-06-29|0x0026
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
#define SystemMsg PcgSystemError("PreccallProc", __LINE__);                               //07-06-29|0x0039
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-06-29|0x0039
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //07-06-29|0x0039
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
#define StringDataCopy(i,j) MemCpy(i, j, sizeof(STRING_DATA))                             //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallCreateFile CallUtilCreateFile(Tokens)                                         //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define ResetBuffer3(i) MemSet(i, 0x00, sizeof(CALL_STACK))                               //07-06-29|0x0069
#define ResetBuffer21(i) ResetBuffer3(CallArgsAddr(i))                                    //07-06-29|0x0069
#define ResetBuffer22(i) CallEchoPosition(i) = -1                                         //07-06-29|0x0069
#define ResetBuffer1(i) ResetBuffer21(i); ResetBuffer22(i)                                //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define ResetDrivePathBuffer ResetBuffer1(1)                                              //07-06-29|0x0069
#define ResetSourceMacroBuffer ResetBuffer1(2)                                            //07-06-29|0x0069
#define ResetBasicBuffer ResetBuffer1(BufferNo)                                           //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallLoadTokens2(i,j) MemCpy(CallArgsAddr(BufferNo), i, j)                         //07-06-29|0x0069
#define CallLoadTokens1(j) CallLoadTokens2(Tokens, j)                                     //07-06-29|0x0069
#define CallLoadTokens CallLoadTokens1(sizeof(TOKENS))                                    //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallLoadNoIncludes CallNoIncludes(BufferNo) = NoIncludes                          //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallLoadBridge1(i) StringDataCopy(CallBridgeAddr(BufferNo),i)                     //07-06-29|0x0069
#define CallLoadBridge CallLoadBridge1(BridgeAddr)                                        //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallCopyBufferPos *PositionAddr = CallPosition                                    //07-06-29|0x0069
#define CallResetBufferPos *PositionAddr = -1                                             //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallWriteBuffer CallUtilWriteFile(BufferNo)                                       //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define TestBufferEcho1 CallEchoPosition(BufferNo) == Position                            //07-06-29|0x0069
#define TestBufferEcho (TestBufferEcho1) ? Success : UserError                            //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define TestMacroEcho1 CallEchoPosition(2) == Position                                    //07-06-29|0x0069
#define TestMacroEcho (TestMacroEcho1) ? Success : UserError                              //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestNoTokensParm(i) (Parm<CallNoTokens(i))?Success:UserError                  //07-06-29|0x0069
#define CallTestSrcMacNoTokens CallTestNoTokensParm(2)                                    //07-06-29|0x0069
#define CallTestBufferNoTokens CallTestNoTokensParm(BufferNo)                             //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define TestPosition CallUtilTestPos(Position, -1, CallPosition)                          //07-06-29|0x0069
#define CallDecrPosition CallPosition  -= sizeof(CALL_STACK)                              //07-06-29|0x0069
#define CallDecrOutPos *PositionAddr -= sizeof(CALL_STACK)                                //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestOffsetPos2(i,j) CallUtilTestPos(Test_Position, i, j)                      //07-06-29|0x0069
#define CallTestOffsetPos1(j) CallTestOffsetPos2(Offset, j)                               //07-06-29|0x0069
#define CallTestOffsetPos CallTestOffsetPos1(Position)                                    //07-06-29|0x0069
#define CallTestOutputPos CallTestOffsetPos1(*PositionAddr)                               //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestCurrentPos2(i,j) CallUtilTestPos(Position, i, j)                          //07-06-29|0x0069
#define CallTestCurrentPos CallTestCurrentPos2(-1, CallPosition)                          //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallPopRead CallUtilReadFile(BufferNo, 0)                                         //07-06-29|0x0069
#define CallOffsetRead CallUtilReadFile(3, Offset)                                        //07-06-29|0x0069
#define CallLoadStackState CallStackState(BufferNo) = StackState                          //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallLoadBuffer1 CallLoadToken; CallLoadStackState                                 //07-06-29|0x0069
#define CallLoadBuffer CallLoadBuffer1; CallLoadNoIncludes                                //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallGetNoIncludes2 *NoIncludesFar = CallNoIncludes(2)                             //07-06-29|0x0069
#define CallGetNoIncludes1 (CallGetNoIncludes2) >= 0                                      //07-06-29|0x0069
#define Call_GetNoIncludes (CallGetNoIncludes1) ? Success : UserError                     //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallGetLineNo *LineNoAddr = CallMacroLineNo(2)                                    //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallClearAddrString MemSet(Addr, 0x00, sizeof(STRING_DATA))                       //07-06-29|0x0069
#define CallConCatAddrBridge CallUtilStrCat(Addr, CallBridgeAddr(2))                      //07-06-29|0x0069
#define CallConCatAddrReturn CallUtilStrCat(Addr, CallReturnAddr)                         //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallConCatAddr1(i) CallUtilStrCat(Addr, i)                                        //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallConCatAddrMacro CallConCatAddr1(CallArgAddr(2,0))                             //07-06-29|0x0069
#define CallConCatAddrToken CallConCatAddr1(CallArgAddr(2,Parm))                          //07-06-29|0x0069
#define CallConCatAddrBasic CallConCatAddr1(CallArgAddr(BufferNo,Parm))                   //07-06-29|0x0069
#define CallConCatOffsetMacro CallConCatAddr1(CallArgAddr(3,0))                           //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallUpdateColToken2 AddrStartCall = 1                                             //07-06-29|0x0069
#define CallUpdateColToken1 AddrStartCol  = CallStartCol(2,Parm)                          //07-06-29|0x0069
#define CallUpdateColToken CallUpdateColToken2; CallUpdateColToken1                       //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallChkNoTokens2(i) ((i<1) || (i>10))                                             //07-06-29|0x0069
#define CallChkNoTokens1(i) CallChkNoTokens2(i) ? UserError : Success                     //07-06-29|0x0069
#define CallChkSrcMacNoTokens CallChkNoTokens1(CallNoTokens(2))                           //07-06-29|0x0069
#define CallChkBufferNoTokens CallChkNoTokens1(CallNoTokens(BufferNo))                    //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallBufferStckChk1 (CallStackState(BufferNo) != State)                            //07-06-29|0x0069
#define CallBufferStckChk CallBufferStckChk1 ? UserError : Success                        //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallProcParmNotDefined Finish("Parameter Not Defined")                            //07-06-29|0x0069
#ifndef TestIndex                                                                         //07-06-29|0x0075
#define TestIndex 0                                                                       //07-06-29|0x0075
#endif                                                                                    //07-06-29|0x0075
//------------------------------------------------------------------------                //07-06-29|0x0075
enum {  call_proc_construct_1 = TestIndex };                                              //07-06-29|0x0075
//------------------------------------------------------------------------                //07-06-29|0x0075
#undef TestIndex                                                                          //07-06-29|0x0075
#define TestIndex call_proc_construct_1+1                                                 //07-06-29|0x0075
//************************************************************************                //07-06-29|0x0075
#ifndef TestIndex                                                                         //07-06-29|0x0094
#define TestIndex 0                                                                       //07-06-29|0x0094
#endif                                                                                    //07-06-29|0x0094
//------------------------------------------------------------------------                //07-06-29|0x0094
enum {  callproc_initial_1 = TestIndex };                                                 //07-06-29|0x0094
//------------------------------------------------------------------------                //07-06-29|0x0094
#undef TestIndex                                                                          //07-06-29|0x0094
#define TestIndex callproc_initial_1+1                                                    //07-06-29|0x0094
//************************************************************************                //07-06-29|0x0094
#ifndef TestIndex                                                                         //07-07-05|0x00cf
#define TestIndex 0                                                                       //07-07-05|0x00cf
#endif                                                                                    //07-07-05|0x00cf
//------------------------------------------------------------------------                //07-07-05|0x00cf
enum {  callproc_destroy_file_1 = TestIndex };                                            //07-07-05|0x00cf
//------------------------------------------------------------------------                //07-07-05|0x00cf
#undef TestIndex                                                                          //07-07-05|0x00cf
#define TestIndex callproc_destroy_file_1+1                                               //07-07-05|0x00cf
//************************************************************************                //07-07-05|0x00cf
#ifndef TestIndex                                                                         //07-06-29|0x00f3
#define TestIndex 0                                                                       //07-06-29|0x00f3
#endif                                                                                    //07-06-29|0x00f3
//------------------------------------------------------------------------                //07-06-29|0x00f3
enum {  callproc_get_token_1 = TestIndex };                                               //07-06-29|0x00f3
//------------------------------------------------------------------------                //07-06-29|0x00f3
#undef TestIndex                                                                          //07-06-29|0x00f3
#define TestIndex callproc_get_token_1+1                                                  //07-06-29|0x00f3
//************************************************************************                //07-06-29|0x00f3
#ifndef TestIndex                                                                         //07-07-11|0x0127
#define TestIndex 0                                                                       //07-07-11|0x0127
#endif                                                                                    //07-07-11|0x0127
//------------------------------------------------------------------------                //07-07-11|0x0127
enum {  callproc_test_no_token_1 = TestIndex };                                           //07-07-11|0x0127
//------------------------------------------------------------------------                //07-07-11|0x0127
#undef TestIndex                                                                          //07-07-11|0x0127
#define TestIndex callproc_test_no_token_1+1                                              //07-07-11|0x0127
//************************************************************************                //07-07-11|0x0127
#ifndef TestIndex                                                                         //07-06-30|0x0158
#define TestIndex 0                                                                       //07-06-30|0x0158
#endif                                                                                    //07-06-30|0x0158
//------------------------------------------------------------------------                //07-06-30|0x0158
enum {  callproc_get_no_token_1 = TestIndex };                                            //07-06-30|0x0158
//------------------------------------------------------------------------                //07-06-30|0x0158
#undef TestIndex                                                                          //07-06-30|0x0158
#define TestIndex callproc_get_no_token_1+1                                               //07-06-30|0x0158
//************************************************************************                //07-06-30|0x0158
#ifndef TestIndex                                                                         //07-06-29|0x0187
#define TestIndex 0                                                                       //07-06-29|0x0187
#endif                                                                                    //07-06-29|0x0187
//------------------------------------------------------------------------                //07-06-29|0x0187
enum {  callproc_load_tokens_1 = TestIndex };                                             //07-06-29|0x0187
//------------------------------------------------------------------------                //07-06-29|0x0187
#undef TestIndex                                                                          //07-06-29|0x0187
#define TestIndex callproc_load_tokens_1+1                                                //07-06-29|0x0187
//************************************************************************                //07-06-29|0x0187
#ifndef TestIndex                                                                         //07-06-30|0x01b2
#define TestIndex 0                                                                       //07-06-30|0x01b2
#endif                                                                                    //07-06-30|0x01b2
//------------------------------------------------------------------------                //07-06-30|0x01b2
enum {  callproc_load_bridge_1 = TestIndex };                                             //07-06-30|0x01b2
//------------------------------------------------------------------------                //07-06-30|0x01b2
#undef TestIndex                                                                          //07-06-30|0x01b2
#define TestIndex callproc_load_bridge_1+1                                                //07-06-30|0x01b2
//************************************************************************                //07-06-30|0x01b2
#ifndef TestIndex                                                                         //07-06-30|0x01db
#define TestIndex 0                                                                       //07-06-30|0x01db
#endif                                                                                    //07-06-30|0x01db
//------------------------------------------------------------------------                //07-06-30|0x01db
enum {  callproc_load_noincludes_1 = TestIndex };                                         //07-06-30|0x01db
//------------------------------------------------------------------------                //07-06-30|0x01db
#undef TestIndex                                                                          //07-06-30|0x01db
#define TestIndex callproc_load_noincludes_1+1                                            //07-06-30|0x01db
//************************************************************************                //07-06-30|0x01db
#ifndef TestIndex                                                                         //07-06-29|0x0205
#define TestIndex 0                                                                       //07-06-29|0x0205
#endif                                                                                    //07-06-29|0x0205
//------------------------------------------------------------------------                //07-06-29|0x0205
enum {  callproc_finish_push_1 = TestIndex };                                             //07-06-29|0x0205
//------------------------------------------------------------------------                //07-06-29|0x0205
#undef TestIndex                                                                          //07-06-29|0x0205
#define TestIndex callproc_finish_push_1+1                                                //07-06-29|0x0205
//************************************************************************                //07-06-29|0x0205
#ifndef TestIndex                                                                         //07-06-29|0x0233
#define TestIndex 0                                                                       //07-06-29|0x0233
#endif                                                                                    //07-06-29|0x0233
//------------------------------------------------------------------------                //07-06-29|0x0233
enum {  callproc_pop_read_1 = TestIndex };                                                //07-06-29|0x0233
//------------------------------------------------------------------------                //07-06-29|0x0233
#undef TestIndex                                                                          //07-06-29|0x0233
#define TestIndex callproc_pop_read_1+1                                                   //07-06-29|0x0233
//************************************************************************                //07-06-29|0x0233
#ifndef TestIndex                                                                         //07-07-03|0x0264
#define TestIndex 0                                                                       //07-07-03|0x0264
#endif                                                                                    //07-07-03|0x0264
//------------------------------------------------------------------------                //07-07-03|0x0264
enum {  callproc_test_pos_1 = TestIndex };                                                //07-07-03|0x0264
//------------------------------------------------------------------------                //07-07-03|0x0264
#undef TestIndex                                                                          //07-07-03|0x0264
#define TestIndex callproc_test_pos_1+1                                                   //07-07-03|0x0264
//************************************************************************                //07-07-03|0x0264
#ifndef TestIndex                                                                         //07-07-02|0x0289
#define TestIndex 0                                                                       //07-07-02|0x0289
#endif                                                                                    //07-07-02|0x0289
//------------------------------------------------------------------------                //07-07-02|0x0289
enum {  callproc_apndsrcmac_1 = TestIndex };                                              //07-07-02|0x0289
//------------------------------------------------------------------------                //07-07-02|0x0289
#undef TestIndex                                                                          //07-07-02|0x0289
#define TestIndex callproc_apndsrcmac_1+1                                                 //07-07-02|0x0289
//************************************************************************                //07-07-02|0x0289
#ifndef TestIndex                                                                         //07-07-05|0x02c2
#define TestIndex 0                                                                       //07-07-05|0x02c2
#endif                                                                                    //07-07-05|0x02c2
//------------------------------------------------------------------------                //07-07-05|0x02c2
enum {  callproc_getmacroname_1 = TestIndex };                                            //07-07-05|0x02c2
//------------------------------------------------------------------------                //07-07-05|0x02c2
#undef TestIndex                                                                          //07-07-05|0x02c2
#define TestIndex callproc_getmacroname_1+1                                               //07-07-05|0x02c2
//************************************************************************                //07-07-05|0x02c2
#ifndef TestIndex                                                                         //07-07-02|0x02f2
#define TestIndex 0                                                                       //07-07-02|0x02f2
#endif                                                                                    //07-07-02|0x02f2
//------------------------------------------------------------------------                //07-07-02|0x02f2
enum {  callproc_getreturn_1 = TestIndex };                                               //07-07-02|0x02f2
//------------------------------------------------------------------------                //07-07-02|0x02f2
#undef TestIndex                                                                          //07-07-02|0x02f2
#define TestIndex callproc_getreturn_1+1                                                  //07-07-02|0x02f2
//************************************************************************                //07-07-02|0x02f2
#ifndef TestIndex                                                                         //07-06-30|0x031e
#define TestIndex 0                                                                       //07-06-30|0x031e
#endif                                                                                    //07-06-30|0x031e
//------------------------------------------------------------------------                //07-06-30|0x031e
enum {  get_no_includes_1 = TestIndex };                                                  //07-06-30|0x031e
//------------------------------------------------------------------------                //07-06-30|0x031e
#undef TestIndex                                                                          //07-06-30|0x031e
#define TestIndex get_no_includes_1+1                                                     //07-06-30|0x031e
//************************************************************************                //07-06-30|0x031e
#ifndef TestIndex                                                                         //07-06-30|0x0344
#define TestIndex 0                                                                       //07-06-30|0x0344
#endif                                                                                    //07-06-30|0x0344
//------------------------------------------------------------------------                //07-06-30|0x0344
enum {  callproc_getlineno_1 = TestIndex };                                               //07-06-30|0x0344
//------------------------------------------------------------------------                //07-06-30|0x0344
#undef TestIndex                                                                          //07-06-30|0x0344
#define TestIndex callproc_getlineno_1+1                                                  //07-06-30|0x0344
//************************************************************************                //07-06-30|0x0344
#ifndef TestIndex                                                                         //07-06-30|0x036b
#define TestIndex 0                                                                       //07-06-30|0x036b
#endif                                                                                    //07-06-30|0x036b
//------------------------------------------------------------------------                //07-06-30|0x036b
enum {  callproc_getbridge_1 = TestIndex };                                               //07-06-30|0x036b
//------------------------------------------------------------------------                //07-06-30|0x036b
#undef TestIndex                                                                          //07-06-30|0x036b
#define TestIndex callproc_getbridge_1+1                                                  //07-06-30|0x036b
//************************************************************************                //07-06-30|0x036b
#ifndef TestIndex                                                                         //07-07-02|0x039a
#define TestIndex 0                                                                       //07-07-02|0x039a
#endif                                                                                    //07-07-02|0x039a
//------------------------------------------------------------------------                //07-07-02|0x039a
enum {  callproc_returnname_1 = TestIndex };                                              //07-07-02|0x039a
//------------------------------------------------------------------------                //07-07-02|0x039a
#undef TestIndex                                                                          //07-07-02|0x039a
#define TestIndex callproc_returnname_1+1                                                 //07-07-02|0x039a
//************************************************************************                //07-07-02|0x039a
//*******************************************************************************         //05-24-97|0x03e4
//*******************************************************************************         //05-24-97|0x03e4
//****                       END OF FILE                                     ****         //05-24-97|0x03e4
//*******************************************************************************         //05-24-97|0x03e4
//*******************************************************************************         //05-24-97|0x03e4
#endif                                                                                    //05-24-97|0x03e4
