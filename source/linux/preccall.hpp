//*****************************************************************************           //07-06-29|0x001e
//*****************************************************************************           //07-06-29|0x001e
//                                                                                        //07-06-29|0x001e
// PRECEDENCE CALL STACK                                                                  //07-06-29|0x001e
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
#ifndef preccall_hpp                                                                      //07-06-29|0x0026
#define preccall_hpp                                                                      //07-06-29|0x0026
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
#define SystemMsg PcgSystemError("Preccall", __LINE__);                                   //07-06-29|0x0039
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
#define CallGetToken2(i,j) CallProcGetToken(Addr, i, Parm, j)                             //07-06-29|0x0069
#define CallFetchCommandLineToken CallGetToken2(0, 0)                                     //07-06-29|0x0069
#define CallFetchDrivePathToken CallGetToken2(1,  CallDrivePathPos)                       //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestNoTokens2(i,j) CallProcTestNoToken(i, Parm, j)                            //07-06-29|0x0069
#define CallTestCommandNoToken CallTestNoTokens2(0, 0)                                    //07-06-29|0x0069
#define CallTestDrivePathNoToken CallTestNoTokens2(1, CallDrivePathPos)                   //07-06-29|0x0069
#define CallTestSourceNoToken CallTestNoTokens2(2, CallSourcePos)                         //07-06-29|0x0069
#define CallTestMacroNoToken CallTestNoTokens2(2, CallMacroPos)                           //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallGetNoTokens2(i,j) CallProcGetNoTokens(NoParmsFar, i, j)                       //07-06-29|0x0069
#define CallGetSourceNoTokens CallGetNoTokens2(2, CallSourcePos)                          //07-06-29|0x0069
#define CallGetMacroNoTokens CallGetNoTokens2(2, CallMacroPos)                            //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallLoadDrivePathTokens CallProcLoadTokens(1, TokensAddr)                         //07-06-29|0x0069
#define CallLoadSourceMacroTokens CallProcLoadTokens(2, TokensAddr)                       //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallLoadSourceMacroBridge CallProcLoadBridge(2, BridgeAddr)                       //07-06-29|0x0069
#define CallLoadNoIncludes CallProcLoadNoIncludes(2, NoIncludes)                          //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallProcDrivePathPush CallProcFinishPush(1, &CallDrivePathPos)                    //07-06-29|0x0069
#define CallProcSourcePush CallProcFinishPush(2, &CallSourcePos)                          //07-06-29|0x0069
#define CallProcMacroPush CallProcFinishPush(2, &CallMacroPos)                            //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestDrivePath2(i,j) CallProcTestPos(CallDrivePathPos, i, j)                   //07-06-29|0x0069
#define CallTestDrivePath1(j) CallTestDrivePath2(-Offset, j)                              //07-06-29|0x0069
#define TestDPPDrivePathPos CallTestDrivePath1(CallDrivePathPos)                          //07-06-29|0x0069
#define TestDPPSourcePos CallTestDrivePath1(CallSourcePos)                                //07-06-29|0x0069
#define TestDPPMacroPos CallTestDrivePath1(CallMacroPos)                                  //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestSource1(j) CallProcTestPos(CallSourcePos, -1, j)                          //07-06-29|0x0069
#define CallTestSource CallTestSource1(CallPosition)                                      //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallFetchSrcMacToken1(i) CallProcAppendSrcMac(Addr,Parm,i,TypeFar)                //07-06-29|0x0069
#define CallFetchSourceToken CallFetchSrcMacToken1(CallSourcePos)                         //07-06-29|0x0069
#define CallFetchMacroToken CallFetchSrcMacToken1(CallMacroPos)                           //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallDrivePosOk1 CallPosition == CallDrivePathPos                                  //07-06-29|0x0069
#define CallDrivePosOk (CallDrivePosOk1) ? Success : UserError                            //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallDrivePosEchoOk1 CallDrivePathPos == CallEchoPosition(1)                       //07-06-29|0x0069
#define CallDrivePosEchoOk (CallDrivePosOk1) ? Success : UserError                        //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallProcDrivePathPop CallProcPopRead(&CallDrivePathPos, 1, 0)                     //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallSourcePop1(i) CallProcPopRead(&CallSourcePos, 2, i)                           //07-06-29|0x0069
#define CallSourcePop CallSourcePop1(CallDrivePathPos)                                    //07-06-29|0x0069
//----------------------------------------------------------------------                  //07-06-29|0x0069
#define CallMacroPop1(i) CallProcPopRead(&CallMacroPos, 2, i)                             //07-06-29|0x0069
#define CallMacroPop CallMacroPop1(CallDrivePathPos)                                      //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define GetNoIncludes1(i) CallProcGetNoIncludes(NoIncludesFar,i)                          //07-06-29|0x0069
#define GetNoIncludes GetNoIncludes1(CallMacroPos)                                        //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define GetLineNo1(i) CallProcGetLineNo(LineNoAddr, i)                                    //07-06-29|0x0069
#define GetLineNo GetLineNo1(CallMacroPos)                                                //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallFetchBridge(i) CallProcGetBridge(Addr, i)                                     //07-06-29|0x0069
#define CallFetchMacroBridge CallFetchBridge(CallMacroPos)                                //07-06-29|0x0069
#define CallFetchSourceBridge CallFetchBridge(CallSourcePos)                              //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallReturnName(i) CallProcReturnName(Addr, i)                                     //07-06-29|0x0069
#define Call_ReturnSourceName CallReturnName(CallSourcePos)                               //07-06-29|0x0069
#define Call_ReturnMacroName CallReturnName(CallMacroPos)                                 //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define LoadString2(i,j) MemCpy(i, j, sizeof(STRING_DATA))                                //07-06-29|0x0069
#define CallLoadBridge LoadString2(CallBridgeAddr(2), BridgeAddr)                         //07-06-29|0x0069
#define CallLoadReturn LoadString2(CallReturnAddr,    ReturnAddr)                         //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestSourceMacro (CallStackState(2)>3)?4:CallStackState(2)                     //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallFetchReturn CallProcGetReturn(ReturnAddr,  TypeFar)                           //07-06-29|0x0069
#define CallFetchMacroName CallProcGetMacroName(Addr,  -Offset)                           //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallNonEmptyReturn Finish("Non Empty Return")                                     //07-06-29|0x0069
#define CallUnreadReturn Finish("Unread Return")                                          //07-06-29|0x0069
#define CallIllegalReturn Finish("Illegal Return")                                        //07-06-29|0x0069
#define CallEmptyReturn Finish("Empty Return")                                            //07-06-29|0x0069
#define CallIllegalCmd Finish("Illegal Command")                                          //07-06-29|0x0069
#define CallIllegalParm Finish("Illegal Parameter")                                       //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallTestNoTokensParm(i) (CallNoTokens(i)<Parm)?Success:UserError                  //07-06-29|0x0069
#define CallTestSrcMacNoTokens CallTestNoTokensParm(2)                                    //07-06-29|0x0069
#define CallTestDrivePathNoTokens CallTestNoTokensParm(1)                                 //07-06-29|0x0069
#define CallTestCommandLineNoTokens CallTestNoTokensParm(0)                               //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallGetSrcMacNoTokens *NoParmsFar = CallNoTokens(2)-1                             //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define CallChkNoTokens2(i) ((i<1) || (i>9))                                              //07-06-29|0x0069
#define CallChkNoTokens1(i) CallChkNoTokens2(i) ? UserError : Success                     //07-06-29|0x0069
#define CallChkDrivePathNoTokens CallChkNoTokens1(CallNoTokens(1))                        //07-06-29|0x0069
#define CallChkCommandLineNoTokens CallChkNoTokens1(CallNoTokens(0))                      //07-06-29|0x0069
//**********************************************************************                  //07-06-29|0x0069
#define RetParm 0                                                                         //07-06-29|0x006a
#define CallParm 1                                                                        //07-06-29|0x006a
#define PermReg 10                                                                        //07-06-29|0x006a
#define OnceReg 36                                                                        //07-06-29|0x006a
#define ProjParm 62                                                                       //07-06-29|0x006a
#define CmdLnParm 72                                                                      //07-06-29|0x006a
#define ErrorParm 82                                                                      //07-06-29|0x006a
//************************************************************************                //07-06-29|0x006a
#ifndef TestIndex                                                                         //07-06-29|0x0076
#define TestIndex 0                                                                       //07-06-29|0x0076
#endif                                                                                    //07-06-29|0x0076
//------------------------------------------------------------------------                //07-06-29|0x0076
enum {  call_allocate_1 = TestIndex };                                                    //07-06-29|0x0076
//------------------------------------------------------------------------                //07-06-29|0x0076
#undef TestIndex                                                                          //07-06-29|0x0076
#define TestIndex call_allocate_1+1                                                       //07-06-29|0x0076
//************************************************************************                //07-06-29|0x0076
#ifndef TestIndex                                                                         //07-07-05|0x0094
#define TestIndex 0                                                                       //07-07-05|0x0094
#endif                                                                                    //07-07-05|0x0094
//------------------------------------------------------------------------                //07-07-05|0x0094
enum {  call_free_1 = TestIndex };                                                        //07-07-05|0x0094
//------------------------------------------------------------------------                //07-07-05|0x0094
#undef TestIndex                                                                          //07-07-05|0x0094
#define TestIndex call_free_1+1                                                           //07-07-05|0x0094
//************************************************************************                //07-07-05|0x0094
#ifndef TestIndex                                                                         //07-06-29|0x00ae
#define TestIndex 0                                                                       //07-06-29|0x00ae
#endif                                                                                    //07-06-29|0x00ae
//------------------------------------------------------------------------                //07-06-29|0x00ae
enum {  call_initial_1 = TestIndex };                                                     //07-06-29|0x00ae
//------------------------------------------------------------------------                //07-06-29|0x00ae
#undef TestIndex                                                                          //07-06-29|0x00ae
#define TestIndex call_initial_1+1                                                        //07-06-29|0x00ae
//************************************************************************                //07-06-29|0x00ae
#ifndef TestIndex                                                                         //07-06-29|0x00d4
#define TestIndex 0                                                                       //07-06-29|0x00d4
#endif                                                                                    //07-06-29|0x00d4
//------------------------------------------------------------------------                //07-06-29|0x00d4
enum {  copy_cmd_arg_1 = TestIndex };                                                     //07-06-29|0x00d4
//------------------------------------------------------------------------                //07-06-29|0x00d4
#undef TestIndex                                                                          //07-06-29|0x00d4
#define TestIndex copy_cmd_arg_1+1                                                        //07-06-29|0x00d4
//************************************************************************                //07-06-29|0x00d4
#ifndef TestIndex                                                                         //07-07-12|0x0107
#define TestIndex 0                                                                       //07-07-12|0x0107
#endif                                                                                    //07-07-12|0x0107
//------------------------------------------------------------------------                //07-07-12|0x0107
enum {  call_cmd_parm_test_1 = TestIndex };                                               //07-07-12|0x0107
//------------------------------------------------------------------------                //07-07-12|0x0107
#undef TestIndex                                                                          //07-07-12|0x0107
#define TestIndex call_cmd_parm_test_1+1                                                  //07-07-12|0x0107
//************************************************************************                //07-07-12|0x0107
#ifndef TestIndex                                                                         //07-07-05|0x0136
#define TestIndex 0                                                                       //07-07-05|0x0136
#endif                                                                                    //07-07-05|0x0136
//------------------------------------------------------------------------                //07-07-05|0x0136
enum {  call_exit_1 = TestIndex };                                                        //07-07-05|0x0136
//------------------------------------------------------------------------                //07-07-05|0x0136
#undef TestIndex                                                                          //07-07-05|0x0136
#define TestIndex call_exit_1+1                                                           //07-07-05|0x0136
//************************************************************************                //07-07-05|0x0136
#ifndef TestIndex                                                                         //07-06-29|0x015c
#define TestIndex 0                                                                       //07-06-29|0x015c
#endif                                                                                    //07-06-29|0x015c
//------------------------------------------------------------------------                //07-06-29|0x015c
enum {  call_prepush_1 = TestIndex };                                                     //07-06-29|0x015c
//------------------------------------------------------------------------                //07-06-29|0x015c
#undef TestIndex                                                                          //07-06-29|0x015c
#define TestIndex call_prepush_1+1                                                        //07-06-29|0x015c
//************************************************************************                //07-06-29|0x015c
#ifndef TestIndex                                                                         //07-06-29|0x0187
#define TestIndex 0                                                                       //07-06-29|0x0187
#endif                                                                                    //07-06-29|0x0187
//------------------------------------------------------------------------                //07-06-29|0x0187
enum {  copy_src_arg_1 = TestIndex };                                                     //07-06-29|0x0187
//------------------------------------------------------------------------                //07-06-29|0x0187
#undef TestIndex                                                                          //07-06-29|0x0187
#define TestIndex copy_src_arg_1+1                                                        //07-06-29|0x0187
//************************************************************************                //07-06-29|0x0187
#ifndef TestIndex                                                                         //07-07-11|0x01d6
#define TestIndex 0                                                                       //07-07-11|0x01d6
#endif                                                                                    //07-07-11|0x01d6
//------------------------------------------------------------------------                //07-07-11|0x01d6
enum {  call_src_parm_test_1 = TestIndex };                                               //07-07-11|0x01d6
//------------------------------------------------------------------------                //07-07-11|0x01d6
#undef TestIndex                                                                          //07-07-11|0x01d6
#define TestIndex call_src_parm_test_1+1                                                  //07-07-11|0x01d6
//************************************************************************                //07-07-11|0x01d6
#ifndef TestIndex                                                                         //07-06-29|0x0201
#define TestIndex 0                                                                       //07-06-29|0x0201
#endif                                                                                    //07-06-29|0x0201
//------------------------------------------------------------------------                //07-06-29|0x0201
enum {  call_prepop_1 = TestIndex };                                                      //07-06-29|0x0201
//------------------------------------------------------------------------                //07-06-29|0x0201
#undef TestIndex                                                                          //07-06-29|0x0201
#define TestIndex call_prepop_1+1                                                         //07-06-29|0x0201
//************************************************************************                //07-06-29|0x0201
#ifndef TestIndex                                                                         //07-06-30|0x022d
#define TestIndex 0                                                                       //07-06-30|0x022d
#endif                                                                                    //07-06-30|0x022d
//------------------------------------------------------------------------                //07-06-30|0x022d
enum {  call_srcpush_1 = TestIndex };                                                     //07-06-30|0x022d
//------------------------------------------------------------------------                //07-06-30|0x022d
#undef TestIndex                                                                          //07-06-30|0x022d
#define TestIndex call_srcpush_1+1                                                        //07-06-30|0x022d
//************************************************************************                //07-06-30|0x022d
#ifndef TestIndex                                                                         //07-07-05|0x025c
#define TestIndex 0                                                                       //07-07-05|0x025c
#endif                                                                                    //07-07-05|0x025c
//------------------------------------------------------------------------                //07-07-05|0x025c
enum {  call_prelevel_test_1 = TestIndex };                                               //07-07-05|0x025c
//------------------------------------------------------------------------                //07-07-05|0x025c
#undef TestIndex                                                                          //07-07-05|0x025c
#define TestIndex call_prelevel_test_1+1                                                  //07-07-05|0x025c
//************************************************************************                //07-07-05|0x025c
#ifndef TestIndex                                                                         //07-07-05|0x028c
#define TestIndex 0                                                                       //07-07-05|0x028c
#endif                                                                                    //07-07-05|0x028c
//------------------------------------------------------------------------                //07-07-05|0x028c
enum {  call_srcpop_1 = TestIndex };                                                      //07-07-05|0x028c
//------------------------------------------------------------------------                //07-07-05|0x028c
#undef TestIndex                                                                          //07-07-05|0x028c
#define TestIndex call_srcpop_1+1                                                         //07-07-05|0x028c
//************************************************************************                //07-07-05|0x028c
#ifndef TestIndex                                                                         //07-06-30|0x02ba
#define TestIndex 0                                                                       //07-06-30|0x02ba
#endif                                                                                    //07-06-30|0x02ba
//------------------------------------------------------------------------                //07-06-30|0x02ba
enum {  call_push_1 = TestIndex };                                                        //07-06-30|0x02ba
//------------------------------------------------------------------------                //07-06-30|0x02ba
#undef TestIndex                                                                          //07-06-30|0x02ba
#define TestIndex call_push_1+1                                                           //07-06-30|0x02ba
//************************************************************************                //07-06-30|0x02ba
#ifndef TestIndex                                                                         //07-07-03|0x02ed
#define TestIndex 0                                                                       //07-07-03|0x02ed
#endif                                                                                    //07-07-03|0x02ed
//------------------------------------------------------------------------                //07-07-03|0x02ed
enum {  copy_arg_1 = TestIndex };                                                         //07-07-03|0x02ed
//------------------------------------------------------------------------                //07-07-03|0x02ed
#undef TestIndex                                                                          //07-07-03|0x02ed
#define TestIndex copy_arg_1+1                                                            //07-07-03|0x02ed
//************************************************************************                //07-07-03|0x02ed
#ifndef TestIndex                                                                         //07-07-11|0x031f
#define TestIndex 0                                                                       //07-07-11|0x031f
#endif                                                                                    //07-07-11|0x031f
//------------------------------------------------------------------------                //07-07-11|0x031f
enum {  call_parm_test_1 = TestIndex };                                                   //07-07-11|0x031f
//------------------------------------------------------------------------                //07-07-11|0x031f
#undef TestIndex                                                                          //07-07-11|0x031f
#define TestIndex call_parm_test_1+1                                                      //07-07-11|0x031f
//************************************************************************                //07-07-11|0x031f
#ifndef TestIndex                                                                         //07-06-30|0x034b
#define TestIndex 0                                                                       //07-06-30|0x034b
#endif                                                                                    //07-06-30|0x034b
//------------------------------------------------------------------------                //07-06-30|0x034b
enum {  get_no_parms_1 = TestIndex };                                                     //07-06-30|0x034b
//------------------------------------------------------------------------                //07-06-30|0x034b
#undef TestIndex                                                                          //07-06-30|0x034b
#define TestIndex get_no_parms_1+1                                                        //07-06-30|0x034b
//************************************************************************                //07-06-30|0x034b
#ifndef TestIndex                                                                         //07-06-30|0x0377
#define TestIndex 0                                                                       //07-06-30|0x0377
#endif                                                                                    //07-06-30|0x0377
//------------------------------------------------------------------------                //07-06-30|0x0377
enum {  return_store_1 = TestIndex };                                                     //07-06-30|0x0377
//------------------------------------------------------------------------                //07-06-30|0x0377
#undef TestIndex                                                                          //07-06-30|0x0377
#define TestIndex return_store_1+1                                                        //07-06-30|0x0377
//************************************************************************                //07-06-30|0x0377
#ifndef TestIndex                                                                         //07-07-02|0x03a6
#define TestIndex 0                                                                       //07-07-02|0x03a6
#endif                                                                                    //07-07-02|0x03a6
//------------------------------------------------------------------------                //07-07-02|0x03a6
enum {  return_read_1 = TestIndex };                                                      //07-07-02|0x03a6
//------------------------------------------------------------------------                //07-07-02|0x03a6
#undef TestIndex                                                                          //07-07-02|0x03a6
#define TestIndex return_read_1+1                                                         //07-07-02|0x03a6
//************************************************************************                //07-07-02|0x03a6
#ifndef TestIndex                                                                         //07-07-09|0x03dc
#define TestIndex 0                                                                       //07-07-09|0x03dc
#endif                                                                                    //07-07-09|0x03dc
//------------------------------------------------------------------------                //07-07-09|0x03dc
enum {  return_state_1 = TestIndex };                                                     //07-07-09|0x03dc
//------------------------------------------------------------------------                //07-07-09|0x03dc
#undef TestIndex                                                                          //07-07-09|0x03dc
#define TestIndex return_state_1+1                                                        //07-07-09|0x03dc
//************************************************************************                //07-07-09|0x03dc
#ifndef TestIndex                                                                         //07-07-05|0x0408
#define TestIndex 0                                                                       //07-07-05|0x0408
#endif                                                                                    //07-07-05|0x0408
//------------------------------------------------------------------------                //07-07-05|0x0408
enum {  copy_macro_name_1 = TestIndex };                                                  //07-07-05|0x0408
//------------------------------------------------------------------------                //07-07-05|0x0408
#undef TestIndex                                                                          //07-07-05|0x0408
#define TestIndex copy_macro_name_1+1                                                     //07-07-05|0x0408
//************************************************************************                //07-07-05|0x0408
#ifndef TestIndex                                                                         //07-06-30|0x043b
#define TestIndex 0                                                                       //07-06-30|0x043b
#endif                                                                                    //07-06-30|0x043b
//------------------------------------------------------------------------                //07-06-30|0x043b
enum {  get_no_includes_1 = TestIndex };                                                  //07-06-30|0x043b
//------------------------------------------------------------------------                //07-06-30|0x043b
#undef TestIndex                                                                          //07-06-30|0x043b
#define TestIndex get_no_includes_1+1                                                     //07-06-30|0x043b
//************************************************************************                //07-06-30|0x043b
#ifndef TestIndex                                                                         //07-06-30|0x0462
#define TestIndex 0                                                                       //07-06-30|0x0462
#endif                                                                                    //07-06-30|0x0462
//------------------------------------------------------------------------                //07-06-30|0x0462
enum {  call_return_line_no_1 = TestIndex };                                              //07-06-30|0x0462
//------------------------------------------------------------------------                //07-06-30|0x0462
#undef TestIndex                                                                          //07-06-30|0x0462
#define TestIndex call_return_line_no_1+1                                                 //07-06-30|0x0462
//************************************************************************                //07-06-30|0x0462
#ifndef TestIndex                                                                         //07-06-30|0x048b
#define TestIndex 0                                                                       //07-06-30|0x048b
#endif                                                                                    //07-06-30|0x048b
//------------------------------------------------------------------------                //07-06-30|0x048b
enum {  call_pop_1 = TestIndex };                                                         //07-06-30|0x048b
//------------------------------------------------------------------------                //07-06-30|0x048b
#undef TestIndex                                                                          //07-06-30|0x048b
#define TestIndex call_pop_1+1                                                            //07-06-30|0x048b
//************************************************************************                //07-06-30|0x048b
#ifndef TestIndex                                                                         //07-06-30|0x04b3
#define TestIndex 0                                                                       //07-06-30|0x04b3
#endif                                                                                    //07-06-30|0x04b3
//------------------------------------------------------------------------                //07-06-30|0x04b3
enum {  bridge_read_1 = TestIndex };                                                      //07-06-30|0x04b3
//------------------------------------------------------------------------                //07-06-30|0x04b3
#undef TestIndex                                                                          //07-06-30|0x04b3
#define TestIndex bridge_read_1+1                                                         //07-06-30|0x04b3
//************************************************************************                //07-06-30|0x04b3
#ifndef TestIndex                                                                         //07-07-02|0x04da
#define TestIndex 0                                                                       //07-07-02|0x04da
#endif                                                                                    //07-07-02|0x04da
//------------------------------------------------------------------------                //07-07-02|0x04da
enum {  call_return_macro_name_1 = TestIndex };                                           //07-07-02|0x04da
//------------------------------------------------------------------------                //07-07-02|0x04da
#undef TestIndex                                                                          //07-07-02|0x04da
#define TestIndex call_return_macro_name_1+1                                              //07-07-02|0x04da
//************************************************************************                //07-07-02|0x04da
#ifndef TestIndex                                                                         //07-06-30|0x0504
#define TestIndex 0                                                                       //07-06-30|0x0504
#endif                                                                                    //07-06-30|0x0504
//------------------------------------------------------------------------                //07-06-30|0x0504
enum {  call_test_src_1 = TestIndex };                                                    //07-06-30|0x0504
//------------------------------------------------------------------------                //07-06-30|0x0504
#undef TestIndex                                                                          //07-06-30|0x0504
#define TestIndex call_test_src_1+1                                                       //07-06-30|0x0504
//************************************************************************                //07-06-30|0x0504
#ifndef TestIndex                                                                         //07-07-07|0x0538
#define TestIndex 0                                                                       //07-07-07|0x0538
#endif                                                                                    //07-07-07|0x0538
//------------------------------------------------------------------------                //07-07-07|0x0538
enum {  call_reset_macro_1 = TestIndex };                                                 //07-07-07|0x0538
//------------------------------------------------------------------------                //07-07-07|0x0538
#undef TestIndex                                                                          //07-07-07|0x0538
#define TestIndex call_reset_macro_1+1                                                    //07-07-07|0x0538
//************************************************************************                //07-07-07|0x0538
#ifndef TestIndex                                                                         //07-07-05|0x0564
#define TestIndex 0                                                                       //07-07-05|0x0564
#endif                                                                                    //07-07-05|0x0564
//------------------------------------------------------------------------                //07-07-05|0x0564
enum {  call_exit_pop_1 = TestIndex };                                                    //07-07-05|0x0564
//------------------------------------------------------------------------                //07-07-05|0x0564
#undef TestIndex                                                                          //07-07-05|0x0564
#define TestIndex call_exit_pop_1+1                                                       //07-07-05|0x0564
//************************************************************************                //07-07-05|0x0564
//*******************************************************************************         //05-24-97|0x05ac
//*******************************************************************************         //05-24-97|0x05ac
//****                       END OF FILE                                     ****         //05-24-97|0x05ac
//*******************************************************************************         //05-24-97|0x05ac
//*******************************************************************************         //05-24-97|0x05ac
#endif                                                                                    //05-24-97|0x05ac
