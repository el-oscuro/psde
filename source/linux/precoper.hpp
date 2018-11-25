//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
// OPERATION GENERATOR                                                                    //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  Copyright: 2006 Robert H. Adams                                                       //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  The purpose of this program as well as instructions regarding its use is              //06-07-14|0x000c
//  defined in the associated manual.                                                     //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  This program is free software; you can redistribute it and/or modify                  //06-07-14|0x000c
//  it under the terms of the GNU General Public License as published by                  //06-07-14|0x000c
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-14|0x000c
//  (at your option) any later version.                                                   //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//  This program is distributed in the hope that it will be useful,                       //06-07-14|0x000c
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-14|0x000c
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-14|0x000c
//  GNU General Public License for more details.                                          //06-07-14|0x000c
//                                                                                        //06-07-14|0x000c
//  You should have received a copy of the GNU General Public License                     //06-07-14|0x000c
//  along with this program; if not, write to the Free Software                           //06-07-14|0x000c
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-14|0x000c
//  USA                                                                                   //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//  For further information, please contact Robert Adams:                                 //06-07-14|0x000c
//     EMail:    robert.adams@whatifwe.com                                                //06-07-14|0x000c
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-14|0x000c
//  Or visit the website, "www.whatifwe.com".                                             //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
//*****************************************************************************           //06-07-14|0x000c
#ifndef precoper_hpp                                                                      //06-07-14|0x000d
#define precoper_hpp                                                                      //06-07-14|0x000d
//***************************************************************************             //06-07-14|0x0029
//***************************************************************************             //06-07-14|0x002a
//******                                                               ******             //06-07-14|0x002b
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-14|0x002c
//******                                                               ******             //06-07-14|0x002d
//***************************************************************************             //06-07-14|0x002e
//***************************************************************************             //06-07-14|0x002f
//***************************************************************************             //06-07-14|0x0032
//***************************************************************************             //06-07-14|0x0033
//******                                                               ******             //06-07-14|0x0034
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-14|0x0035
//******                                                               ******             //06-07-14|0x0036
//***************************************************************************             //06-07-14|0x0037
//***************************************************************************             //06-07-14|0x0038
#define UserError 0x0000                                                                  //06-07-14|0x0039
#define BuildError 0x7fff                                                                 //06-07-14|0x0039
#define Display 0x7ffe                                                                    //06-07-14|0x0039
#define KeyBoard 0x7ffd                                                                   //06-07-14|0x0039
#define Success 0xffff                                                                    //06-07-14|0x0039
#define SystemError 0x8000                                                                //06-07-14|0x0039
#define Continue 0x0001                                                                   //06-07-14|0x0039
#define FileDone 0x0002                                                                   //06-07-14|0x0039
#define LineDone 0x0003                                                                   //06-07-14|0x0039
#define Yes 0x0004                                                                        //06-07-14|0x0039
#define No 0x0005                                                                         //06-07-14|0x0039
#define RepeatChar '\x6'                                                                  //06-07-14|0x0039
#define Great 0x0007                                                                      //06-07-14|0x0039
#define Equal 0x0008                                                                      //06-07-14|0x0039
#define Less 0x0009                                                                       //06-07-14|0x0039
#define Zero 0x000a                                                                       //06-07-14|0x0039
#define Minus 0x000b                                                                      //06-07-14|0x0039
#define RetParm 0                                                                         //09-03-11|0x003a
#define CallParm 1                                                                        //09-03-11|0x003a
#define PermReg 10                                                                        //09-03-11|0x003a
#define OnceReg 36                                                                        //09-03-11|0x003a
#define ProjParm 62                                                                       //09-03-11|0x003a
#define CmdLnParm 72                                                                      //09-03-11|0x003a
#define ErrorParm 82                                                                      //09-03-11|0x003a
//************************************************************************                //09-03-11|0x003a
//***************************************************************************             //06-07-14|0x003b
#define SystemMsg PcgSystemError("precoper", __LINE__);                                   //06-07-14|0x003c
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-14|0x003c
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-14|0x003c
#define DebugBreakpoint1 Breakpoint("precoper", __LINE__)                                 //<----   |0x003d
#define DebugBreakpoint if(DebugBreakpoint1 != Success) ReturnSystemError                 //<----   |0x003d
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-14|0x003e
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-14|0x003e
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-14|0x003e
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-14|0x003e
#define _SwitchErr case UserError: return(UserError)                                      //06-07-14|0x003f
#define _SwitchOk case Success: break                                                     //06-07-14|0x003f
#define _SwitchEnd default: ReturnSystemError                                             //06-07-14|0x003f
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-14|0x003f
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-14|0x003f
#define _SwitchNo case No:       return(No)                                               //06-07-14|0x003f
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-14|0x003f
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-14|0x003f
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-14|0x003f
#define _SwitchBreak _SwitchGroup break                                                   //06-07-14|0x003f
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-14|0x003f
//***************************************************************************             //06-07-14|0x0058
//***************************************************************************             //06-07-14|0x0059
//******                                                               ******             //06-07-14|0x005a
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-14|0x005b
//******                                                               ******             //06-07-14|0x005c
//***************************************************************************             //06-07-14|0x005d
//***************************************************************************             //06-07-14|0x005e
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-14|0x005f
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-14|0x005f
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-14|0x005f
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-14|0x005f
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-14|0x005f
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-14|0x005f
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-14|0x005f
#define break_test(i) { TestSample(i);  break; }                                          //06-07-14|0x005f
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-14|0x005f
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-14|0x005f
//************************************************************************                //06-07-14|0x005f
#ifndef TestIndex                                                                         //06-07-14|0x005f
#define TestIndex 0                                                                       //06-07-14|0x005f
#endif                                                                                    //06-07-14|0x005f
//------------------------------------------------------------------------                //06-07-14|0x005f
enum {  NoTestSamples = TestIndex };                                                      //06-07-14|0x005f
//------------------------------------------------------------------------                //06-07-14|0x005f
#undef TestIndex                                                                          //06-07-14|0x005f
#define TestIndex NoTestSamples+1                                                         //06-07-14|0x005f
//************************************************************************                //06-07-14|0x005f
//***************************************************************************             //06-07-14|0x0060
//************************************************************************                //06-07-14|0x0061
#define ProcessCallReturnRunFlag ProcessDataFar->call_return_run_flag                     //06-07-14|0x0061
#define ProcessCallReturnStatus ProcessDataFar->call_return_status                        //06-07-14|0x0061
#define ProcessCallReturnState ProcessDataFar->call_return_state                          //06-07-14|0x0061
#define ProcessProcessCommand ProcessDataFar->process_command                             //06-07-14|0x0061
#define ProcessRunFlag ProcessDataFar->run_flag                                           //06-07-14|0x0061
#define ProcessStatus ProcessDataFar->status                                              //06-07-14|0x0061
#define ProcessDebugCommand ProcessDataFar->debug_command                                 //06-07-14|0x0061
#define ProcessFlagState ProcessDataFar->flag_state                                       //06-07-14|0x0061
#define ProcessProcessState ProcessDataFar->process_state                                 //06-07-14|0x0061
#define ProcessRuleState ProcessDataFar->rule_state                                       //06-07-14|0x0061
#define ProcessOutBufferState ProcessDataFar->out_buffer_state                            //06-07-14|0x0061
#define ProcessInBufferState ProcessDataFar->in_buffer_state                              //06-07-14|0x0061
#define ProcessTokens ProcessDataFar->tokens                                              //06-07-14|0x0061
#define ProcessDict ProcessDataFar->dict                                                  //06-07-14|0x0061
#define ProcessBuffer ProcessDataFar->buffer                                              //06-07-14|0x0061
#define ProcessUtilityBridge ProcessDataFar->utility_bridge                               //06-07-14|0x0061
#define ProcessBridgeName ProcessDataFar->bridge_name                                     //06-07-14|0x0061
#define ProcessDebugName ProcessDataFar->debug_name                                       //06-07-14|0x0061
#define ProcessMacroName ProcessDataFar->macro_name                                       //06-07-14|0x0061
#define ProcessClassName ProcessDataFar->class_name                                       //06-07-14|0x0061
#define ProcessResults ProcessDataFar->results                                            //06-07-14|0x0061
#define ProcessParmNum ProcessDataFar->parm_num                                           //06-07-14|0x0061
#define ProcessResultNum ProcessDataFar->result_num                                       //06-07-14|0x0061
//------------------------------------------------------------------------                //06-07-14|0x0061
#define ProcessDictAddr &(ProcessDataFar->dict)                                           //06-07-14|0x0061
#define ProcessClassNameAddr &(ProcessDataFar->class_name)                                //06-07-14|0x0061
#define ProcessBridgeNameAddr &(ProcessDataFar->bridge_name)                              //06-07-14|0x0061
#define ProcessUtilityBridgeAddr &(ProcessDataFar->utility_bridge)                        //06-07-14|0x0061
#define ProcessMacroNameAddr &(ProcessDataFar->macro_name)                                //06-07-14|0x0061
#define ProcessTokensAddr &(ProcessDataFar->tokens)                                       //06-07-14|0x0061
#define ProcessResultsAddr &(ProcessDataFar->results)                                     //06-07-14|0x0061
#define ProcessBufferAddr &(ProcessDataFar->buffer)                                       //06-07-14|0x0061
//************************************************************************                //09-03-11|0x0062
#define TokensTokenAddr(i) &(ProcessTokens.token[i])                                      //09-03-11|0x0062
#define TokensMacroLineNo(i) ProcessTokens.token[i].macro_line_no                         //09-03-11|0x0062
#define TokensLineAddr(i) &(ProcessTokens.token[i].line[0])                               //09-03-11|0x0062
#define TokensToken(i) ProcessTokens.token[i]                                             //09-03-11|0x0062
#define TokensLine(i) ProcessTokens.token[i].line                                         //09-03-11|0x0062
#define TokensLength(i) ProcessTokens.token[i].length                                     //09-03-11|0x0062
#define TokensColumn(i) ProcessTokens.token[i].column                                     //09-03-11|0x0062
#define TokensHash(i) ProcessTokens.token[i].hash                                         //09-03-11|0x0062
#define TokensPosition(i) ProcessTokens.token[i].position                                 //09-03-11|0x0062
#define TokensType(i) ProcessTokens.token[i].type                                         //09-03-11|0x0062
#define TokensStartCol(i) ProcessTokens.token[i].start_col                                //09-03-11|0x0062
#define TokensStartCall(i) ProcessTokens.token[i].start_call                              //09-03-11|0x0062
#define TokensChar(i,j) ProcessTokens.token[i].line[j]                                    //09-03-11|0x0062
#define TokensNoTokens ProcessTokens.no_tokens                                            //09-03-11|0x0062
//************************************************************************                //09-03-11|0x0063
#define DictTokenAddr(i) &(ProcessDict.token[i])                                          //09-03-11|0x0063
#define DictMacroLineNo(i) ProcessDict.token[i].macro_line_no                             //09-03-11|0x0063
#define DictLineAddr(i) &(ProcessDict.token[i].line[0])                                   //09-03-11|0x0063
#define DictToken(i) ProcessDict.token[i]                                                 //09-03-11|0x0063
#define DictLine(i) ProcessDict.token[i].line                                             //09-03-11|0x0063
#define DictLength(i) ProcessDict.token[i].length                                         //09-03-11|0x0063
#define DictColumn(i) ProcessDict.token[i].column                                         //09-03-11|0x0063
#define DictHash(i) ProcessDict.token[i].hash                                             //09-03-11|0x0063
#define DictPosition(i) ProcessDict.token[i].position                                     //09-03-11|0x0063
#define DictType(i) ProcessDict.token[i].type                                             //09-03-11|0x0063
#define DictStartCol(i) ProcessDict.token[i].start_col                                    //09-03-11|0x0063
#define DictStartCall(i) ProcessDict.token[i].start_call                                  //09-03-11|0x0063
#define DictChar(i,j) ProcessDict.token[i].line[j]                                        //09-03-11|0x0063
#define DictNoTokens ProcessDict.no_tokens                                                //09-03-11|0x0063
#define ResultsChar(i) ProcessResults.line[i]                                             //06-07-14|0x0064
#define ResultsLine ProcessResults.line[0]                                                //06-07-14|0x0064
#define ResultsLineAddr &(ProcessResults.line[0])                                         //06-07-14|0x0064
#define ResultsMacroLineNo ProcessResults.macro_line_no                                   //06-07-14|0x0064
#define ResultsType ProcessResults.type                                                   //06-07-14|0x0064
#define ResultsStartCol ProcessResults.start_col                                          //06-07-14|0x0064
#define ResultsStartCall ProcessResults.start_call                                        //06-07-14|0x0064
#define ResultsPosition ProcessResults.position                                           //06-07-14|0x0064
#define ResultsLength ProcessResults.length                                               //06-07-14|0x0064
#define ResultsColumn ProcessResults.column                                               //06-07-14|0x0064
//**********************************************************************                  //06-07-14|0x0064
#define BridgeChar(i) ProcessBridgeName.line[i]                                           //06-07-14|0x0065
#define BridgeLine ProcessBridgeName.line[0]                                              //06-07-14|0x0065
#define BridgeLineAddr &(ProcessBridgeName.line[0])                                       //06-07-14|0x0065
#define BridgeMacroLineNo ProcessBridgeName.macro_line_no                                 //06-07-14|0x0065
#define BridgeType ProcessBridgeName.type                                                 //06-07-14|0x0065
#define BridgeStartCol ProcessBridgeName.start_col                                        //06-07-14|0x0065
#define BridgeStartCall ProcessBridgeName.start_call                                      //06-07-14|0x0065
#define BridgePosition ProcessBridgeName.position                                         //06-07-14|0x0065
#define BridgeLength ProcessBridgeName.length                                             //06-07-14|0x0065
#define BridgeColumn ProcessBridgeName.column                                             //06-07-14|0x0065
//**********************************************************************                  //06-07-14|0x0065
#define BufferChar(i) ProcessBuffer.line[i]                                               //06-07-14|0x0066
#define BufferLine ProcessBuffer.line[0]                                                  //06-07-14|0x0066
#define BufferLineAddr &(ProcessBuffer.line[0])                                           //06-07-14|0x0066
#define BufferMacroLineNo ProcessBuffer.macro_line_no                                     //06-07-14|0x0066
#define BufferType ProcessBuffer.type                                                     //06-07-14|0x0066
#define BufferStartCol ProcessBuffer.start_col                                            //06-07-14|0x0066
#define BufferStartCall ProcessBuffer.start_call                                          //06-07-14|0x0066
#define BufferPosition ProcessBuffer.position                                             //06-07-14|0x0066
#define BufferLength ProcessBuffer.length                                                 //06-07-14|0x0066
#define BufferColumn ProcessBuffer.column                                                 //06-07-14|0x0066
//**********************************************************************                  //06-07-14|0x0066
#define ClassNameChar(i) ProcessClassName.line[i]                                         //06-07-14|0x0067
#define ClassNameLine ProcessClassName.line[0]                                            //06-07-14|0x0067
#define ClassNameLineAddr &(ProcessClassName.line[0])                                     //06-07-14|0x0067
#define ClassNameMacroLineNo ProcessClassName.macro_line_no                               //06-07-14|0x0067
#define ClassNameType ProcessClassName.type                                               //06-07-14|0x0067
#define ClassNameStartCol ProcessClassName.start_col                                      //06-07-14|0x0067
#define ClassNameStartCall ProcessClassName.start_call                                    //06-07-14|0x0067
#define ClassNamePosition ProcessClassName.position                                       //06-07-14|0x0067
#define ClassNameLength ProcessClassName.length                                           //06-07-14|0x0067
#define ClassNameColumn ProcessClassName.column                                           //06-07-14|0x0067
//**********************************************************************                  //06-07-14|0x0067
#define UtilityBridgeChar(i) ProcessUtilityBridge.line[i]                                 //09-03-11|0x0068
#define UtilityBridgeLine ProcessUtilityBridge.line[0]                                    //09-03-11|0x0068
#define UtilityBridgeLineAddr &(ProcessUtilityBridge.line[0])                             //09-03-11|0x0068
#define UtilityBridgeMacroLineNo ProcessUtilityBridge.macro_line_no                       //09-03-11|0x0068
#define UtilityBridgeType ProcessUtilityBridge.type                                       //09-03-11|0x0068
#define UtilityBridgeStartCol ProcessUtilityBridge.start_col                              //09-03-11|0x0068
#define UtilityBridgeStartCall ProcessUtilityBridge.start_call                            //09-03-11|0x0068
#define UtilityBridgePosition ProcessUtilityBridge.position                               //09-03-11|0x0068
#define UtilityBridgeLength ProcessUtilityBridge.length                                   //09-03-11|0x0068
#define UtilityBridgeColumn ProcessUtilityBridge.column                                   //09-03-11|0x0068
//**********************************************************************                  //09-03-11|0x0068
#define DebugNameChar(i) ProcessDebugName.line[i]                                         //06-12-19|0x0069
#define DebugNameLine ProcessDebugName.line[0]                                            //06-12-19|0x0069
#define DebugNameLineAddr &(ProcessDebugName.line[0])                                     //06-12-19|0x0069
#define DebugNameMacroLineNo ProcessDebugName.macro_line_no                               //06-12-19|0x0069
#define DebugNameType ProcessDebugName.type                                               //06-12-19|0x0069
#define DebugNameStartCol ProcessDebugName.start_col                                      //06-12-19|0x0069
#define DebugNameStartCall ProcessDebugName.start_call                                    //06-12-19|0x0069
#define DebugNamePosition ProcessDebugName.position                                       //06-12-19|0x0069
#define DebugNameLength ProcessDebugName.length                                           //06-12-19|0x0069
#define DebugNameColumn ProcessDebugName.column                                           //06-12-19|0x0069
//**********************************************************************                  //06-12-19|0x0069
#define MacroNameChar(i) ProcessMacroName.line[i]                                         //09-03-11|0x006a
#define MacroNameLine ProcessMacroName.line[0]                                            //09-03-11|0x006a
#define MacroNameLineAddr &(ProcessMacroName.line[0])                                     //09-03-11|0x006a
#define MacroNameMacroLineNo ProcessMacroName.macro_line_no                               //09-03-11|0x006a
#define MacroNameType ProcessMacroName.type                                               //09-03-11|0x006a
#define MacroNameStartCol ProcessMacroName.start_col                                      //09-03-11|0x006a
#define MacroNameStartCall ProcessMacroName.start_call                                    //09-03-11|0x006a
#define MacroNamePosition ProcessMacroName.position                                       //09-03-11|0x006a
#define MacroNameLength ProcessMacroName.length                                           //09-03-11|0x006a
#define MacroNameColumn ProcessMacroName.column                                           //09-03-11|0x006a
//**********************************************************************                  //09-03-11|0x006a
#define ParmNumChar0 ProcessParmNum.value.char0                                           //06-07-14|0x006b
#define ParmNumByte0 ProcessParmNum.value.byte0                                           //06-07-14|0x006b
#define ParmNumSint0 ProcessParmNum.value.sint0                                           //06-07-14|0x006b
#define ParmNumWord0 ProcessParmNum.value.word0                                           //06-07-14|0x006b
#define ParmNumUlong ProcessParmNum.value.ulong                                           //06-07-14|0x006b
#define ParmNumType ProcessParmNum.type                                                   //06-07-14|0x006b
//**********************************************************************                  //06-07-14|0x006b
#define ResultNumChar0 ProcessResultNum.value.char0                                       //06-07-14|0x006c
#define ResultNumByte0 ProcessResultNum.value.byte0                                       //06-07-14|0x006c
#define ResultNumSint0 ProcessResultNum.value.sint0                                       //06-07-14|0x006c
#define ResultNumWord0 ProcessResultNum.value.word0                                       //06-07-14|0x006c
#define ResultNumUlong ProcessResultNum.value.ulong                                       //06-07-14|0x006c
#define ResultNumType ProcessResultNum.type                                               //06-07-14|0x006c
//**********************************************************************                  //06-07-14|0x006c
//---------------------------------------------------------------------------             //06-07-14|0x006d
//************************************************************************                //06-12-19|0x006e
#define PcgTokenAddr(i) &(PcgTokenFar->token[i])                                          //06-12-19|0x006e
#define PcgMacroLineNo(i) PcgTokenFar->token[i].macro_line_no                             //06-12-19|0x006e
#define PcgLineAddr(i) &(PcgTokenFar->token[i].line[0])                                   //06-12-19|0x006e
#define PcgToken(i) PcgTokenFar->token[i]                                                 //06-12-19|0x006e
#define PcgLine(i) PcgTokenFar->token[i].line                                             //06-12-19|0x006e
#define PcgLength(i) PcgTokenFar->token[i].length                                         //06-12-19|0x006e
#define PcgColumn(i) PcgTokenFar->token[i].column                                         //06-12-19|0x006e
#define PcgHash(i) PcgTokenFar->token[i].hash                                             //06-12-19|0x006e
#define PcgPosition(i) PcgTokenFar->token[i].position                                     //06-12-19|0x006e
#define PcgType(i) PcgTokenFar->token[i].type                                             //06-12-19|0x006e
#define PcgStartCol(i) PcgTokenFar->token[i].start_col                                    //06-12-19|0x006e
#define PcgStartCall(i) PcgTokenFar->token[i].start_call                                  //06-12-19|0x006e
#define PcgChar(i,j) PcgTokenFar->token[i].line[j]                                        //06-12-19|0x006e
#define PcgNoTokens PcgTokenFar->no_tokens                                                //06-12-19|0x006e
//---------------------------------------------------------------------------             //06-07-14|0x006f
#define StringChar(i) StringFar->line[i]                                                  //06-07-14|0x0070
#define StringLine StringFar->line[0]                                                     //06-07-14|0x0070
#define StringLineAddr &(StringFar->line[0])                                              //06-07-14|0x0070
#define StringMacroLineNo StringFar->macro_line_no                                        //06-07-14|0x0070
#define StringType StringFar->type                                                        //06-07-14|0x0070
#define StringStartCol StringFar->start_col                                               //06-07-14|0x0070
#define StringStartCall StringFar->start_call                                             //06-07-14|0x0070
#define StringPosition StringFar->position                                                //06-07-14|0x0070
#define StringLength StringFar->length                                                    //06-07-14|0x0070
#define StringColumn StringFar->column                                                    //06-07-14|0x0070
//**********************************************************************                  //06-07-14|0x0070
//---------------------------------------------------------------------------             //06-07-14|0x0071
//**********************************************************************                  //06-07-14|0x0072
#define FileSrcFile ProcessFilesFar->source_file                                          //06-07-14|0x0072
#define FileSrcFileAddr &(ProcessFilesFar->source_file)                                   //06-07-14|0x0072
#define FileSrcLineNo ProcessFilesFar->source_file.line_no                                //06-07-14|0x0072
#define FileSrcFileName &(ProcessFilesFar->source_file.file_control.name[0])              //06-07-14|0x0072
#define FileSrcExtent &(ProcessFilesFar->source_extent[0])                                //06-07-14|0x0072
//----------------------------------------------------------------------                  //06-07-14|0x0072
//----------------------------------------------------------------------                  //06-07-14|0x0072
#define FileMailBoxFileNo ProcessFilesFar->mailbox_file_no                                //06-07-14|0x0072
#define FileMailBoxNoFiles ProcessFilesFar->no_mailbox_files                              //06-07-14|0x0072
#define FileMailBoxName(i) ProcessFilesFar->mailbox_file[i].name                          //06-07-14|0x0072
#define FileMailBoxPath &(ProcessFilesFar->mailbox_path[0])                               //06-07-14|0x0072
#define FileMailBoxStatus(i) ProcessFilesFar->mailbox_file[i].status                      //06-07-14|0x0072
//----------------------------------------------------------------------                  //06-07-14|0x0072
#define FileOutNoFiles ProcessFilesFar->no_output_files                                   //06-07-14|0x0072
#define FileOutFile(i) ProcessFilesFar->output_file[i].file                               //06-07-14|0x0072
#define FileOutFileAddr(i) &(ProcessFilesFar->output_file[i].file)                        //06-07-14|0x0072
#define FileOutLineNo(i) ProcessFilesFar->output_file[i].file.line_no                     //06-07-14|0x0072
#define FileOutStatus(i) ProcessFilesFar->output_file[i].file.status                      //06-07-14|0x0072
#define FileOutFileName(i) &(ProcessFilesFar->output_file[i].file.file_control.name[0])   //06-07-14|0x0072
#define FileOutExtent(i) &(ProcessFilesFar->output_file[i].extent[0])                     //06-07-14|0x0072
#define FileOutPath(i) &(ProcessFilesFar->output_file[i].path[0])                         //06-07-14|0x0072
#define FileOutName &(ProcessFilesFar->output_name[0])                                    //06-07-14|0x0072
//----------------------------------------------------------------------                  //06-07-14|0x0072
#define FileInNoFiles ProcessFilesFar->no_input_files                                     //06-07-14|0x0072
#define FileInFile(i) ProcessFilesFar->input_file[i].file                                 //06-07-14|0x0072
#define FileInFileAddr(i) &(ProcessFilesFar->input_file[i].file)                          //06-07-14|0x0072
#define FileInLineNo(i) ProcessFilesFar->input_file[i].file.line_no                       //06-07-14|0x0072
#define FileInFileName(i) &(ProcessFilesFar->input_file[i].file.file_control.name[0])     //06-07-14|0x0072
#define FileInExtent(i) &(ProcessFilesFar->input_file[i].extent[0])                       //06-07-14|0x0072
#define FileInPath(i) &(ProcessFilesFar->input_file[i].path[0])                           //06-07-14|0x0072
#define FileInName &(ProcessFilesFar->input_name[0])                                      //06-07-14|0x0072
//----------------------------------------------------------------------                  //06-07-14|0x0072
#define FileOutBufferFileSize ProcessFilesFar->out_buffer_file_size                       //06-07-14|0x0072
#define FileOutBufferFile ProcessFilesFar->out_buffer_file                                //06-07-14|0x0072
#define FileOutBufferFileAddr &(ProcessFilesFar->out_buffer_file)                         //06-07-14|0x0072
#define MailBoxNameChar(i) mail_box_addr->line[i]                                         //09-06-02|0x0073
#define MailBoxNameLine mail_box_addr->line[0]                                            //09-06-02|0x0073
#define MailBoxNameLineAddr &(mail_box_addr->line[0])                                     //09-06-02|0x0073
#define MailBoxNameMacroLineNo mail_box_addr->macro_line_no                               //09-06-02|0x0073
#define MailBoxNameType mail_box_addr->type                                               //09-06-02|0x0073
#define MailBoxNameStartCol mail_box_addr->start_col                                      //09-06-02|0x0073
#define MailBoxNameStartCall mail_box_addr->start_call                                    //09-06-02|0x0073
#define MailBoxNamePosition mail_box_addr->position                                       //09-06-02|0x0073
#define MailBoxNameLength mail_box_addr->length                                           //09-06-02|0x0073
#define MailBoxNameColumn mail_box_addr->column                                           //09-06-02|0x0073
//**********************************************************************                  //09-06-02|0x0073
//***************************************************************************             //06-07-14|0x0074
#define PrecBreakPoint1(j) Breakpoint("precoper", j)                                      //06-07-14|0x0075
#define PrecBreakPoint(j) if(PrecBreakPoint1(j) != Success) ReturnSystemError             //06-07-14|0x0075
#define DebugManager(j) debug_manager(ProcessDataFar, j)                                  //06-07-14|0x0075
#define CheckoutPause(j) checkout_pause(ProcessDataFar, j)                                //06-07-14|0x0075
#define StringBasicCopy(i,j) MemCCpy(i, j, 0x00, 256)                                     //06-07-14|0x0075
#define StringDataCopy(i,j) MemCpy(i, j, sizeof(STRING_DATA))                             //06-07-14|0x0075
#define StringTooLong ReturnFinish("String Too Long")                                     //06-07-14|0x0075
#define StrDataClr(j) MemSet(j,0x00,sizeof(STRING_DATA))                                  //06-07-14|0x0075
#define StrDataCpy(i,j) MemCpy(i,j,sizeof(STRING_DATA))                                   //06-07-14|0x0075
#define StringComp StrCmp(ResultsLineAddr, TokensLineAddr(2))                             //06-07-14|0x0075
#define TextRegIn TextReadReg(ProcessResultsAddr,TokensTokenAddr(1))                      //06-07-14|0x0075
#define ResultRegOut TextStoreReg(TokensTokenAddr(1),ProcessResultsAddr)                  //06-07-14|0x0075
#define BufferRegOut TextStoreReg(TokensTokenAddr(1),ProcessBufferAddr)                   //06-07-14|0x0075
#define ClearRegIn TextClearReg(TokensTokenAddr(1))                                       //06-07-14|0x0075
#define NumTextIn(j) NumericTextIn(&(ProcessParmNum), TokensTokenAddr(j))                 //06-07-14|0x0075
#define NumResultsIn NumericTextIn(&(ProcessResultNum),ProcessResultsAddr)                //06-07-14|0x0075
#define NumResultOut NumericOut(ProcessResultsAddr, &ProcessResultNum)                    //06-07-14|0x0075
#define StringInReg string_in_reg(ProcessDataFar)                                         //06-07-14|0x0075
#define StringIn2 string_in_2(ProcessDataFar)                                             //06-07-14|0x0075
#define BasicRegStore basic_reg_store(ProcessDataFar)                                     //06-07-14|0x0075
#define BasicStrngType basic_string_type(ProcessDataFar)                                  //06-07-14|0x0075
#define StringNumIn2 string_numeric_in_2(ProcessDataFar)                                  //06-07-14|0x0075
#define StringNumIn3(i) string_numeric_in_3(ProcessDataFar,i)                             //06-07-14|0x0075
#define StringNumIn4 string_numeric_in_4(ProcessDataFar)                                  //06-07-14|0x0075
#define FindChar2 find_char(TokensTokenAddr(1), ParmNumByte0)                             //06-07-14|0x0075
#define FindChar3 find_char(TokensTokenAddr(2), ParmNumByte0)                             //06-07-14|0x0075
#define NumericInData numeric_in_data(ProcessDataFar)                                     //06-07-14|0x0075
#define NumericIn2 numeric_in_2(ProcessDataFar)                                           //06-07-14|0x0075
#define NumericInReg numeric_in_reg(ProcessDataFar)                                       //06-07-14|0x0075
#define NumericRegOut numeric_reg_out(ProcessDataFar)                                     //06-07-14|0x0075
#define DictIn(i) dict_in(ProcessDataFar,i)                                               //06-07-14|0x0075
#define DictAddEntry SrceDictAdd(ProcessDictAddr)                                         //06-07-14|0x0075
#define DictAddSub SrceDictAddSubEntry(ProcessDictAddr)                                   //06-07-14|0x0075
#define DictUpdateEntry SrceDictUpdate(ProcessDictAddr)                                   //06-07-14|0x0075
#define DictUpdateSub SrceDictUpdateSubEntry(ProcessDictAddr)                             //06-07-14|0x0075
#define DictGetData1(i) SrceDictGet(ProcessResultsAddr, DictTokenAddr(2),i)               //06-07-14|0x0075
#define DictGetData DictGetData1(ParmNumWord0)                                            //06-07-14|0x0075
#define DictGetSub2(i,j) SrceSubDictGet(ProcessResultsAddr,i,j)                           //06-07-14|0x0075
#define DictGetSub1(i) DictGetSub2(ProcessDictAddr,i)                                     //06-07-14|0x0075
#define DictGetSub DictGetSub1(ParmNumWord0)                                              //06-07-14|0x0075
#define DictExists SrceDictExists(DictTokenAddr(1))                                       //06-07-14|0x0075
#define SubDictExist1(i) SrceSubDictExists(DictTokenAddr(1),i)                            //06-07-14|0x0075
#define SubDictExists SubDictExist1(DictTokenAddr(2))                                     //06-07-14|0x0075
#define DictDataExists SrceDictTestData(DictTokenAddr(1),   ParmNumWord0)                 //06-07-14|0x0075
#define SubDataExists SrceSubDictTestData(ProcessDictAddr,    ParmNumWord0)               //06-07-14|0x0075
#define MailGetFileNo get_postoffice_no(ProcessDataFar, ProcessFilesFar)                  //06-07-14|0x0075
#define MailOpen open_mailbox(ProcessDataFar, ProcessFilesFar)                            //06-07-14|0x0075
#define MailAddZip create_postoffice(ProcessDataFar, ProcessFilesFar)                     //06-07-14|0x0075
#define MailAddPOBox create_po_box(ProcessDataFar, ProcessFilesFar)                       //06-07-14|0x0075
#define MailLoadPOBox send_mail(ProcessDataFar, ProcessFilesFar)                          //06-07-14|0x0075
#define MailEmptyPOBox empty_po_box(ProcessDataFar, ProcessFilesFar)                      //06-07-14|0x0075
#define MailGet get_mail(ProcessDataFar,  ProcessFilesFar)                                //06-07-14|0x0075
#define MailZipExists postoffice_exists(ProcessDataFar,  ProcessFilesFar)                 //06-07-14|0x0075
#define MailPOBoxExists po_box_exists(ProcessDataFar,  ProcessFilesFar)                   //06-07-14|0x0075
#define MailTestMail po_box_empty(ProcessDataFar,  ProcessFilesFar)                       //06-07-14|0x0075
#define MailClose close_mailbox(ProcessDataFar, ProcessFilesFar)                          //06-07-14|0x0075
#define MailDelete delete_postoffice(ProcessDataFar, ProcessFilesFar)                     //06-07-14|0x0075
#define LoadBuffer load_buffer(ProcessDataFar,ProcessFilesFar)                            //06-07-14|0x0075
#define AppendBuffer append_buffer(ProcessDataFar,ProcessFilesFar)                        //06-07-14|0x0075
#define CommitOut(i) FileCommitText(FileOutFileAddr(i))                                   //06-07-14|0x0075
#define WriteText(i) FilePutText(i)                                                       //06-07-14|0x0075
#define WriteCRLF FilePutCRLF()                                                           //06-07-14|0x0075
#define WriteDbug FilePutDbug()                                                           //06-07-14|0x0075
#define WriteOut write_output(ProcessDataFar,ProcessFilesFar)                             //06-07-14|0x0075
#define WriteBuffer write_buffer(ProcessDataFar,ProcessFilesFar)                          //06-07-14|0x0075
#define FileName(i) MemCCpy(ResultsLineAddr,i,0x00,256)                                   //06-07-14|0x0075
#define GetReturnName CallReturnMacroName(ProcessMacroNameAddr)                           //06-07-14|0x0075
#define FindLabel MacDictFindName(ProcessResultsAddr, MC_LABEL_NAME)                      //06-07-14|0x0075
#define Bridge3(i,j,k) MacDictFindBridge(i,j,k)                                           //06-07-14|0x0075
#define Bridge21(i,j) Bridge3(ProcessUtilityBridgeAddr,i,j)                               //06-07-14|0x0075
#define Bridge22(i,j) Bridge3(TokensTokenAddr(0),i,j)                                     //06-07-14|0x0075
#define Bridge23(i,j) Bridge3(ProcessBridgeNameAddr,i,j)                                  //06-07-14|0x0075
#define Bridge24(i,j) Bridge3(TokensTokenAddr(1),i,j)                                     //06-07-14|0x0075
#define Bridge25(i,j) Bridge3(ProcessClassNameAddr,i,j)                                   //06-07-14|0x0075
#define FindUtilBridge Bridge21(0,I_UTILITY_NAME)                                         //06-07-14|0x0075
#define FindPubBridge Bridge22(search_offset,I_PUBLIC_NAME)                               //06-07-14|0x0075
#define FindRegBridge Bridge22(0,I_BRIDGE_NAME)                                           //06-07-14|0x0075
#define FindCallInc Bridge22(search_offset,I_INCLUDE_NAME)                                //06-07-14|0x0075
#define FindReturnInc Bridge23(search_offset,I_INCLUDE_NAME)                              //06-07-14|0x0075
#define FindRetBridge Bridge23(search_offset,BridgeType)                                  //06-07-14|0x0075
#define FindTestClass Bridge24(0,I_CLASS_BRIDGE)                                          //06-07-14|0x0075
#define FindResetClass Bridge25(0,I_CLASS_BRIDGE)                                         //06-07-14|0x0075
#define CpyUtlBridge1(i) StrDataCpy(ProcessBridgeNameAddr,i)                              //06-07-14|0x0075
#define CopyUtilBridge CpyUtlBridge1(ProcessUtilityBridgeAddr)                            //06-07-14|0x0075
#define FetchNoParms GetNoParms(&ResultNumWord0)                                          //06-07-14|0x0075
#define TestParmExist TextTestParm(TokensTokenAddr(1))                                    //06-07-14|0x0075
#define TestReturn PrecReturnState()                                                      //06-07-14|0x0075
#define FindEntry MacDictFindName(TokensTokenAddr(0), MC_ENTRY_NAME)                      //06-07-14|0x0075
#define MacroCall execute_call(ProcessDataFar)                                            //06-07-14|0x0075
#define MacroReturn execute_return(ProcessDataFar)                                        //06-07-14|0x0075
#define ReadKeyBoard GuiReadLine(ResultsLineAddr, 255)                                    //06-07-14|0x0075
#define BeginStack1(i) StackMacroBegin(i,ProcessClassNameAddr)                            //06-07-14|0x0075
#define BeginStack BeginStack1(ProcessMacroNameAddr)                                      //06-07-14|0x0075
#define AssignStack1(i) StackRegisterStack(i,ProcessClassNameAddr)                        //06-07-14|0x0075
#define AssignStack AssignStack1(ProcessTokensAddr)                                       //06-07-14|0x0075
#define CopyToken0(i) StrDataCpy(i, TokensTokenAddr(0))                                   //06-07-14|0x0075
#define CopyToBridge CopyToken0(ProcessBridgeNameAddr)                                    //06-07-14|0x0075
#define CopyToMacro CopyToken0(ProcessMacroNameAddr)                                      //06-07-14|0x0075
#define UtilBridgeName utility_bridge(ProcessDataFar)                                     //06-07-14|0x0075
#define MacroNameMsg Finish(TokensLineAddr(0))                                            //06-07-14|0x0075
#define NotFoundMsg Finish("Macro Name Not found")                                        //06-07-14|0x0075
#define DupNameMsg Finish("Duplicate Macro Name found")                                   //06-07-14|0x0075
#define NoArgMsg Finish("Incorrect Number of Macro Parameters")                           //06-07-14|0x0075
#define MacroPush1(i) CallPush(ProcessTokensAddr, ProcessBridgeNameAddr, i)               //06-07-14|0x0075
#define MacroPush MacroPush1(no_includes)                                                 //06-07-14|0x0075
#define GetClassName MacDictGetClass(ProcessClassNameAddr)                                //06-07-14|0x0075
#define GetNoIncludes CallGetNoIncludes(&no_includes)                                     //06-07-14|0x0075
#define GetRetLineNo CallReturnLineNo(&return_line_no)                                    //06-07-14|0x0075
#define GetBridgeName CallBridgeRead(ProcessBridgeNameAddr)                               //06-07-14|0x0075
#define PrepRetLabel1(i) return_label(ProcessDataFar, i)                                  //06-07-14|0x0075
#define PrepRetLabel PrepRetLabel1(return_line_no)                                        //06-07-14|0x0075
#define PrepClassLabel PrepRetLabel1(TokensMacroLineNo(0))                                //06-07-14|0x0075
#define LimitTest1 (ResultNumWord0 < ParmNumWord0) ? -1 : 0                               //06-07-14|0x0075
#define LimitTest (ResultNumWord0 > ParmNumWord0) ?  1 : LimitTest1                       //06-07-14|0x0075
#define ZeroNumParm2 ParmNumUlong = 0                                                     //06-07-14|0x0075
#define ZeroNumParm1 ParmNumType  = 0                                                     //06-07-14|0x0075
#define ZeroNumParm ZeroNumParm2; ZeroNumParm1                                            //06-07-14|0x0075
#define IncludesTest ((--no_includes) >= 0) ? Yes : No                                    //06-07-14|0x0075
#define DebugOn debug_on(ProcessDataFar, TokensTokenAddr(1))                              //06-07-14|0x0075
#define CreateRandom CryptoCreate(&ResultNumWord0)                                        //06-07-14|0x0075
#define ResetRandom CryptoReset(ParmNumWord0)                                             //06-07-14|0x0075
#define OpenRandom CryptoOpen(ParmNumWord0)                                               //06-07-14|0x0075
#define LoadRandom CryptoLoad(TokensTokenAddr(1))                                         //06-07-14|0x0075
#define GetRandom CryptoGetRandom(ProcessResultsAddr, ParmNumWord0)                       //06-07-14|0x0075
#define ComputeParity CryptoComputeParity(TokensTokenAddr(1))                             //06-07-14|0x0075
#define GetParity CryptoGetParity(&ResultNumByte0)                                        //06-07-14|0x0075
#define Encrypt CryptoEncrypt(ProcessResultsAddr,TokensTokenAddr(2))                      //06-07-14|0x0075
#define Decrypt CryptoDecrypt(ProcessResultsAddr,TokensTokenAddr(2))                      //06-07-14|0x0075
#define CommitOutBuf FileCommitBinary(&FileOutBufferFile)                                 //06-07-14|0x0075
#define WriteBuf2(i,j) FileWriteData(FileOutBufferFileSize,i,j)                           //06-07-14|0x0075
#define WriteBufNum WriteBuf2((SCHAR_FAR)(&ResultNumChar0), 1)                            //06-07-14|0x0075
#define WriteBufStr WriteBuf2(ResultsLineAddr, ResultsLength)                             //06-07-14|0x0075
#define ReadBuffer2(i,j) FileReadData(BufferLineAddr,i,j)                                 //06-07-14|0x0075
#define ReadBuffer ReadBuffer2(position, BufferLength)                                    //06-07-14|0x0075
#define CommitIn(i) FileCommitText(FileInFileAddr(i))                                     //06-07-14|0x0075
#define CommitInBuf FileCommitText(&FileInBufferFile)                                     //06-07-14|0x0075
#define WriteInBufStr FileWriteText()                                                     //06-07-14|0x0075
#define CMK_EXTENT ".cmk"                                                                 //09-03-11|0x0076
#define TMK_EXTENT ".tmk"                                                                 //09-03-11|0x0076
#define RPT_EXTENT ".rpt"                                                                 //09-03-11|0x0076
#define PMK_EXTENT ".pmk"                                                                 //09-03-11|0x0076
#define MAC_EXTENT ".mac"                                                                 //09-03-11|0x0076
#define SRC_EXTENT ".src"                                                                 //09-03-11|0x0076
#define PLB_EXTENT ".plb"                                                                 //09-03-11|0x0076
#define DIC_EXTENT ".dic"                                                                 //09-03-11|0x0076
#define MBX_EXTENT ".mbx"                                                                 //09-03-11|0x0076
#define MBC_EXTENT ".mbc"                                                                 //09-03-11|0x0076
#define RAN_EXTENT ".ran"                                                                 //09-03-11|0x0076
#define BUF_OUT_EXTENT ".bfo"                                                             //09-03-11|0x0076
#define BUF_IN_EXTENT ".bfi"                                                              //09-03-11|0x0076
//***************************************************************************             //<----   |0x0077
#define BUFFER_READY 0                                                                    //<----   |0x0078
#define BUFFER_OUT_APPEND (BUFFER_READY)*1+1                                              //<----   |0x0079
#define BUFFER_OUT_WRITE (BUFFER_OUT_APPEND)*1+1                                          //<----   |0x007a
#define BUFFER_IN_GET (BUFFER_OUT_WRITE)*1+1                                              //<----   |0x007b
#define BUFFER_IN_END (BUFFER_IN_GET)*1+1                                                 //<----   |0x007c
#ifndef TestIndex                                                                         //06-09-26|0x009b
#define TestIndex 0                                                                       //06-09-26|0x009b
#endif                                                                                    //06-09-26|0x009b
//------------------------------------------------------------------------                //06-09-26|0x009b
enum {  _BEGIN_1 = TestIndex };                                                           //06-09-26|0x009b
//------------------------------------------------------------------------                //06-09-26|0x009b
#undef TestIndex                                                                          //06-09-26|0x009b
#define TestIndex _BEGIN_1+1                                                              //06-09-26|0x009b
//************************************************************************                //06-09-26|0x009b
#ifndef TestIndex                                                                         //06-09-28|0x00a0
#define TestIndex 0                                                                       //06-09-28|0x00a0
#endif                                                                                    //06-09-28|0x00a0
//------------------------------------------------------------------------                //06-09-28|0x00a0
enum {  _END_1 = TestIndex };                                                             //06-09-28|0x00a0
//------------------------------------------------------------------------                //06-09-28|0x00a0
#undef TestIndex                                                                          //06-09-28|0x00a0
#define TestIndex _END_1+1                                                                //06-09-28|0x00a0
//************************************************************************                //06-09-28|0x00a0
#ifndef TestIndex                                                                         //07-04-09|0x00aa
#define TestIndex 0                                                                       //07-04-09|0x00aa
#endif                                                                                    //07-04-09|0x00aa
//------------------------------------------------------------------------                //07-04-09|0x00aa
enum {  _GET_NO_PARMS_1 = TestIndex };                                                    //07-04-09|0x00aa
//------------------------------------------------------------------------                //07-04-09|0x00aa
#undef TestIndex                                                                          //07-04-09|0x00aa
#define TestIndex _GET_NO_PARMS_1+1                                                       //07-04-09|0x00aa
//************************************************************************                //07-04-09|0x00aa
#ifndef TestIndex                                                                         //06-09-30|0x00af
#define TestIndex 0                                                                       //06-09-30|0x00af
#endif                                                                                    //06-09-30|0x00af
//------------------------------------------------------------------------                //06-09-30|0x00af
enum {  _TEST_PARM_1 = TestIndex };                                                       //06-09-30|0x00af
//------------------------------------------------------------------------                //06-09-30|0x00af
#undef TestIndex                                                                          //06-09-30|0x00af
#define TestIndex _TEST_PARM_1+1                                                          //06-09-30|0x00af
//************************************************************************                //06-09-30|0x00af
#ifndef TestIndex                                                                         //06-09-26|0x00b3
#define TestIndex 0                                                                       //06-09-26|0x00b3
#endif                                                                                    //06-09-26|0x00b3
//------------------------------------------------------------------------                //06-09-26|0x00b3
enum {  _CALL_1 = TestIndex };                                                            //06-09-26|0x00b3
//------------------------------------------------------------------------                //06-09-26|0x00b3
#undef TestIndex                                                                          //06-09-26|0x00b3
#define TestIndex _CALL_1+1                                                               //06-09-26|0x00b3
//************************************************************************                //06-09-26|0x00b3
#ifndef TestIndex                                                                         //07-02-17|0x00b8
#define TestIndex 0                                                                       //07-02-17|0x00b8
#endif                                                                                    //07-02-17|0x00b8
//------------------------------------------------------------------------                //07-02-17|0x00b8
enum {  _TEST_RETURN_1 = TestIndex };                                                     //07-02-17|0x00b8
//------------------------------------------------------------------------                //07-02-17|0x00b8
#undef TestIndex                                                                          //07-02-17|0x00b8
#define TestIndex _TEST_RETURN_1+1                                                        //07-02-17|0x00b8
//************************************************************************                //07-02-17|0x00b8
#ifndef TestIndex                                                                         //06-09-28|0x00c5
#define TestIndex 0                                                                       //06-09-28|0x00c5
#endif                                                                                    //06-09-28|0x00c5
//------------------------------------------------------------------------                //06-09-28|0x00c5
enum {  _JUMP_IF_1 = TestIndex };                                                         //06-09-28|0x00c5
//------------------------------------------------------------------------                //06-09-28|0x00c5
#undef TestIndex                                                                          //06-09-28|0x00c5
#define TestIndex _JUMP_IF_1+1                                                            //06-09-28|0x00c5
//************************************************************************                //06-09-28|0x00c5
#ifndef TestIndex                                                                         //06-09-29|0x00cb
#define TestIndex 0                                                                       //06-09-29|0x00cb
#endif                                                                                    //06-09-29|0x00cb
//------------------------------------------------------------------------                //06-09-29|0x00cb
enum {  _JUMP_IF_NOT_1 = TestIndex };                                                     //06-09-29|0x00cb
//------------------------------------------------------------------------                //06-09-29|0x00cb
#undef TestIndex                                                                          //06-09-29|0x00cb
#define TestIndex _JUMP_IF_NOT_1+1                                                        //06-09-29|0x00cb
//************************************************************************                //06-09-29|0x00cb
#ifndef TestIndex                                                                         //06-09-28|0x00d1
#define TestIndex 0                                                                       //06-09-28|0x00d1
#endif                                                                                    //06-09-28|0x00d1
//------------------------------------------------------------------------                //06-09-28|0x00d1
enum {  _JUMP_ALWAYS_1 = TestIndex };                                                     //06-09-28|0x00d1
//------------------------------------------------------------------------                //06-09-28|0x00d1
#undef TestIndex                                                                          //06-09-28|0x00d1
#define TestIndex _JUMP_ALWAYS_1+1                                                        //06-09-28|0x00d1
//************************************************************************                //06-09-28|0x00d1
#ifndef TestIndex                                                                         //08-01-09|0x00d7
#define TestIndex 0                                                                       //08-01-09|0x00d7
#endif                                                                                    //08-01-09|0x00d7
//------------------------------------------------------------------------                //08-01-09|0x00d7
enum {  _LABEL_1 = TestIndex };                                                           //08-01-09|0x00d7
//------------------------------------------------------------------------                //08-01-09|0x00d7
#undef TestIndex                                                                          //08-01-09|0x00d7
#define TestIndex _LABEL_1+1                                                              //08-01-09|0x00d7
//************************************************************************                //08-01-09|0x00d7
#ifndef TestIndex                                                                         //07-07-18|0x00db
#define TestIndex 0                                                                       //07-07-18|0x00db
#endif                                                                                    //07-07-18|0x00db
//------------------------------------------------------------------------                //07-07-18|0x00db
enum {  _TEST_CLASS_1 = TestIndex };                                                      //07-07-18|0x00db
//------------------------------------------------------------------------                //07-07-18|0x00db
#undef TestIndex                                                                          //07-07-18|0x00db
#define TestIndex _TEST_CLASS_1+1                                                         //07-07-18|0x00db
//************************************************************************                //07-07-18|0x00db
#ifndef TestIndex                                                                         //07-12-25|0x00e1
#define TestIndex 0                                                                       //07-12-25|0x00e1
#endif                                                                                    //07-12-25|0x00e1
//------------------------------------------------------------------------                //07-12-25|0x00e1
enum {  _GET_FLAG_1 = TestIndex };                                                        //07-12-25|0x00e1
//------------------------------------------------------------------------                //07-12-25|0x00e1
#undef TestIndex                                                                          //07-12-25|0x00e1
#define TestIndex _GET_FLAG_1+1                                                           //07-12-25|0x00e1
//************************************************************************                //07-12-25|0x00e1
#ifndef TestIndex                                                                         //07-12-25|0x00e6
#define TestIndex 0                                                                       //07-12-25|0x00e6
#endif                                                                                    //07-12-25|0x00e6
//------------------------------------------------------------------------                //07-12-25|0x00e6
enum {  _STATE_FLAG_1 = TestIndex };                                                      //07-12-25|0x00e6
//------------------------------------------------------------------------                //07-12-25|0x00e6
#undef TestIndex                                                                          //07-12-25|0x00e6
#define TestIndex _STATE_FLAG_1+1                                                         //07-12-25|0x00e6
//************************************************************************                //07-12-25|0x00e6
#ifndef TestIndex                                                                         //check   |0x00ec
#define TestIndex 0                                                                       //check   |0x00ec
#endif                                                                                    //check   |0x00ec
//------------------------------------------------------------------------                //check   |0x00ec
enum {  _CONTINUE_IF_1 = TestIndex };                                                     //check   |0x00ec
//------------------------------------------------------------------------                //check   |0x00ec
#undef TestIndex                                                                          //check   |0x00ec
#define TestIndex _CONTINUE_IF_1+1                                                        //check   |0x00ec
//************************************************************************                //check   |0x00ec
#ifndef TestIndex                                                                         //check   |0x00f0
#define TestIndex 0                                                                       //check   |0x00f0
#endif                                                                                    //check   |0x00f0
//------------------------------------------------------------------------                //check   |0x00f0
enum {  _CONTINUE_IF_NOT_1 = TestIndex };                                                 //check   |0x00f0
//------------------------------------------------------------------------                //check   |0x00f0
#undef TestIndex                                                                          //check   |0x00f0
#define TestIndex _CONTINUE_IF_NOT_1+1                                                    //check   |0x00f0
//************************************************************************                //check   |0x00f0
#ifndef TestIndex                                                                         //07-03-19|0x00fd
#define TestIndex 0                                                                       //07-03-19|0x00fd
#endif                                                                                    //07-03-19|0x00fd
//------------------------------------------------------------------------                //07-03-19|0x00fd
enum {  _ASSIGN_STACK_1 = TestIndex };                                                    //07-03-19|0x00fd
//------------------------------------------------------------------------                //07-03-19|0x00fd
#undef TestIndex                                                                          //07-03-19|0x00fd
#define TestIndex _ASSIGN_STACK_1+1                                                       //07-03-19|0x00fd
//************************************************************************                //07-03-19|0x00fd
#ifndef TestIndex                                                                         //06-12-21|0x0103
#define TestIndex 0                                                                       //06-12-21|0x0103
#endif                                                                                    //06-12-21|0x0103
//------------------------------------------------------------------------                //06-12-21|0x0103
enum {  _PUSH_TOKEN_1 = TestIndex };                                                      //06-12-21|0x0103
//------------------------------------------------------------------------                //06-12-21|0x0103
#undef TestIndex                                                                          //06-12-21|0x0103
#define TestIndex _PUSH_TOKEN_1+1                                                         //06-12-21|0x0103
//************************************************************************                //06-12-21|0x0103
#ifndef TestIndex                                                                         //06-12-22|0x0109
#define TestIndex 0                                                                       //06-12-22|0x0109
#endif                                                                                    //06-12-22|0x0109
//------------------------------------------------------------------------                //06-12-22|0x0109
enum {  _POP_TOKEN_1 = TestIndex };                                                       //06-12-22|0x0109
//------------------------------------------------------------------------                //06-12-22|0x0109
#undef TestIndex                                                                          //06-12-22|0x0109
#define TestIndex _POP_TOKEN_1+1                                                          //06-12-22|0x0109
//************************************************************************                //06-12-22|0x0109
#ifndef TestIndex                                                                         //07-09-13|0x0114
#define TestIndex 0                                                                       //07-09-13|0x0114
#endif                                                                                    //07-09-13|0x0114
//------------------------------------------------------------------------                //07-09-13|0x0114
enum {  _GET_STACK_LEVEL_1 = TestIndex };                                                 //07-09-13|0x0114
//------------------------------------------------------------------------                //07-09-13|0x0114
#undef TestIndex                                                                          //07-09-13|0x0114
#define TestIndex _GET_STACK_LEVEL_1+1                                                    //07-09-13|0x0114
//************************************************************************                //07-09-13|0x0114
#ifndef TestIndex                                                                         //07-03-28|0x011c
#define TestIndex 0                                                                       //07-03-28|0x011c
#endif                                                                                    //07-03-28|0x011c
//------------------------------------------------------------------------                //07-03-28|0x011c
enum {  _STATE_TOKEN_1 = TestIndex };                                                     //07-03-28|0x011c
//------------------------------------------------------------------------                //07-03-28|0x011c
#undef TestIndex                                                                          //07-03-28|0x011c
#define TestIndex _STATE_TOKEN_1+1                                                        //07-03-28|0x011c
//************************************************************************                //07-03-28|0x011c
#ifndef TestIndex                                                                         //07-03-16|0x0124
#define TestIndex 0                                                                       //07-03-16|0x0124
#endif                                                                                    //07-03-16|0x0124
//------------------------------------------------------------------------                //07-03-16|0x0124
enum {  _GET_TOKEN_1 = TestIndex };                                                       //07-03-16|0x0124
//------------------------------------------------------------------------                //07-03-16|0x0124
#undef TestIndex                                                                          //07-03-16|0x0124
#define TestIndex _GET_TOKEN_1+1                                                          //07-03-16|0x0124
//************************************************************************                //07-03-16|0x0124
#ifndef TestIndex                                                                         //07-09-13|0x012a
#define TestIndex 0                                                                       //07-09-13|0x012a
#endif                                                                                    //07-09-13|0x012a
//------------------------------------------------------------------------                //07-09-13|0x012a
enum {  _STATE_STACK_1 = TestIndex };                                                     //07-09-13|0x012a
//------------------------------------------------------------------------                //07-09-13|0x012a
#undef TestIndex                                                                          //07-09-13|0x012a
#define TestIndex _STATE_STACK_1+1                                                        //07-09-13|0x012a
//************************************************************************                //07-09-13|0x012a
#ifndef TestIndex                                                                         //06-12-21|0x0139
#define TestIndex 0                                                                       //06-12-21|0x0139
#endif                                                                                    //06-12-21|0x0139
//------------------------------------------------------------------------                //06-12-21|0x0139
enum {  _RULE_START_1 = TestIndex };                                                      //06-12-21|0x0139
//------------------------------------------------------------------------                //06-12-21|0x0139
#undef TestIndex                                                                          //06-12-21|0x0139
#define TestIndex _RULE_START_1+1                                                         //06-12-21|0x0139
//************************************************************************                //06-12-21|0x0139
#ifndef TestIndex                                                                         //06-12-22|0x013e
#define TestIndex 0                                                                       //06-12-22|0x013e
#endif                                                                                    //06-12-22|0x013e
//------------------------------------------------------------------------                //06-12-22|0x013e
enum {  _RULE_END_1 = TestIndex };                                                        //06-12-22|0x013e
//------------------------------------------------------------------------                //06-12-22|0x013e
#undef TestIndex                                                                          //06-12-22|0x013e
#define TestIndex _RULE_END_1+1                                                           //06-12-22|0x013e
//************************************************************************                //06-12-22|0x013e
#ifndef TestIndex                                                                         //07-02-07|0x0147
#define TestIndex 0                                                                       //07-02-07|0x0147
#endif                                                                                    //07-02-07|0x0147
//------------------------------------------------------------------------                //07-02-07|0x0147
enum {  _RULE_STATE_1 = TestIndex };                                                      //07-02-07|0x0147
//------------------------------------------------------------------------                //07-02-07|0x0147
#undef TestIndex                                                                          //07-02-07|0x0147
#define TestIndex _RULE_STATE_1+1                                                         //07-02-07|0x0147
//************************************************************************                //07-02-07|0x0147
#ifndef TestIndex                                                                         //06-12-22|0x0150
#define TestIndex 0                                                                       //06-12-22|0x0150
#endif                                                                                    //06-12-22|0x0150
//------------------------------------------------------------------------                //06-12-22|0x0150
enum {  _MOVE_1 = TestIndex };                                                            //06-12-22|0x0150
//------------------------------------------------------------------------                //06-12-22|0x0150
#undef TestIndex                                                                          //06-12-22|0x0150
#define TestIndex _MOVE_1+1                                                               //06-12-22|0x0150
//************************************************************************                //06-12-22|0x0150
#ifndef TestIndex                                                                         //06-12-22|0x015a
#define TestIndex 0                                                                       //06-12-22|0x015a
#endif                                                                                    //06-12-22|0x015a
//------------------------------------------------------------------------                //06-12-22|0x015a
enum {  _EMIT_1 = TestIndex };                                                            //06-12-22|0x015a
//------------------------------------------------------------------------                //06-12-22|0x015a
#undef TestIndex                                                                          //06-12-22|0x015a
#define TestIndex _EMIT_1+1                                                               //06-12-22|0x015a
//************************************************************************                //06-12-22|0x015a
#ifndef TestIndex                                                                         //06-09-28|0x016c
#define TestIndex 0                                                                       //06-09-28|0x016c
#endif                                                                                    //06-09-28|0x016c
//------------------------------------------------------------------------                //06-09-28|0x016c
enum {  _STORE_1 = TestIndex };                                                           //06-09-28|0x016c
//------------------------------------------------------------------------                //06-09-28|0x016c
#undef TestIndex                                                                          //06-09-28|0x016c
#define TestIndex _STORE_1+1                                                              //06-09-28|0x016c
//************************************************************************                //06-09-28|0x016c
#ifndef TestIndex                                                                         //06-09-29|0x0171
#define TestIndex 0                                                                       //06-09-29|0x0171
#endif                                                                                    //06-09-29|0x0171
//------------------------------------------------------------------------                //06-09-29|0x0171
enum {  _CLEAR_1 = TestIndex };                                                           //06-09-29|0x0171
//------------------------------------------------------------------------                //06-09-29|0x0171
#undef TestIndex                                                                          //06-09-29|0x0171
#define TestIndex _CLEAR_1+1                                                              //06-09-29|0x0171
//************************************************************************                //06-09-29|0x0171
#ifndef TestIndex                                                                         //06-09-29|0x017e
#define TestIndex 0                                                                       //06-09-29|0x017e
#endif                                                                                    //06-09-29|0x017e
//------------------------------------------------------------------------                //06-09-29|0x017e
enum {  _ADD_1 = TestIndex };                                                             //06-09-29|0x017e
//------------------------------------------------------------------------                //06-09-29|0x017e
#undef TestIndex                                                                          //06-09-29|0x017e
#define TestIndex _ADD_1+1                                                                //06-09-29|0x017e
//************************************************************************                //06-09-29|0x017e
#ifndef TestIndex                                                                         //06-10-05|0x0184
#define TestIndex 0                                                                       //06-10-05|0x0184
#endif                                                                                    //06-10-05|0x0184
//------------------------------------------------------------------------                //06-10-05|0x0184
enum {  _SUBT_1 = TestIndex };                                                            //06-10-05|0x0184
//------------------------------------------------------------------------                //06-10-05|0x0184
#undef TestIndex                                                                          //06-10-05|0x0184
#define TestIndex _SUBT_1+1                                                               //06-10-05|0x0184
//************************************************************************                //06-10-05|0x0184
#ifndef TestIndex                                                                         //06-10-06|0x018a
#define TestIndex 0                                                                       //06-10-06|0x018a
#endif                                                                                    //06-10-06|0x018a
//------------------------------------------------------------------------                //06-10-06|0x018a
enum {  _MULT_1 = TestIndex };                                                            //06-10-06|0x018a
//------------------------------------------------------------------------                //06-10-06|0x018a
#undef TestIndex                                                                          //06-10-06|0x018a
#define TestIndex _MULT_1+1                                                               //06-10-06|0x018a
//************************************************************************                //06-10-06|0x018a
#ifndef TestIndex                                                                         //07-07-27|0x0190
#define TestIndex 0                                                                       //07-07-27|0x0190
#endif                                                                                    //07-07-27|0x0190
//------------------------------------------------------------------------                //07-07-27|0x0190
enum {  _DIV_1 = TestIndex };                                                             //07-07-27|0x0190
//------------------------------------------------------------------------                //07-07-27|0x0190
#undef TestIndex                                                                          //07-07-27|0x0190
#define TestIndex _DIV_1+1                                                                //07-07-27|0x0190
//************************************************************************                //07-07-27|0x0190
#ifndef TestIndex                                                                         //07-09-07|0x0196
#define TestIndex 0                                                                       //07-09-07|0x0196
#endif                                                                                    //07-09-07|0x0196
//------------------------------------------------------------------------                //07-09-07|0x0196
enum {  _MOD_1 = TestIndex };                                                             //07-09-07|0x0196
//------------------------------------------------------------------------                //07-09-07|0x0196
#undef TestIndex                                                                          //07-09-07|0x0196
#define TestIndex _MOD_1+1                                                                //07-09-07|0x0196
//************************************************************************                //07-09-07|0x0196
#ifndef TestIndex                                                                         //07-09-17|0x019c
#define TestIndex 0                                                                       //07-09-17|0x019c
#endif                                                                                    //07-09-17|0x019c
//------------------------------------------------------------------------                //07-09-17|0x019c
enum {  _AND_1 = TestIndex };                                                             //07-09-17|0x019c
//------------------------------------------------------------------------                //07-09-17|0x019c
#undef TestIndex                                                                          //07-09-17|0x019c
#define TestIndex _AND_1+1                                                                //07-09-17|0x019c
//************************************************************************                //07-09-17|0x019c
#ifndef TestIndex                                                                         //07-09-17|0x01a2
#define TestIndex 0                                                                       //07-09-17|0x01a2
#endif                                                                                    //07-09-17|0x01a2
//------------------------------------------------------------------------                //07-09-17|0x01a2
enum {  _OR_1 = TestIndex };                                                              //07-09-17|0x01a2
//------------------------------------------------------------------------                //07-09-17|0x01a2
#undef TestIndex                                                                          //07-09-17|0x01a2
#define TestIndex _OR_1+1                                                                 //07-09-17|0x01a2
//************************************************************************                //07-09-17|0x01a2
#ifndef TestIndex                                                                         //07-09-17|0x01a8
#define TestIndex 0                                                                       //07-09-17|0x01a8
#endif                                                                                    //07-09-17|0x01a8
//------------------------------------------------------------------------                //07-09-17|0x01a8
enum {  _EXOR_1 = TestIndex };                                                            //07-09-17|0x01a8
//------------------------------------------------------------------------                //07-09-17|0x01a8
#undef TestIndex                                                                          //07-09-17|0x01a8
#define TestIndex _EXOR_1+1                                                               //07-09-17|0x01a8
//************************************************************************                //07-09-17|0x01a8
#ifndef TestIndex                                                                         //06-10-06|0x01b7
#define TestIndex 0                                                                       //06-10-06|0x01b7
#endif                                                                                    //06-10-06|0x01b7
//------------------------------------------------------------------------                //06-10-06|0x01b7
enum {  _LESS_1 = TestIndex };                                                            //06-10-06|0x01b7
//------------------------------------------------------------------------                //06-10-06|0x01b7
#undef TestIndex                                                                          //06-10-06|0x01b7
#define TestIndex _LESS_1+1                                                               //06-10-06|0x01b7
//************************************************************************                //06-10-06|0x01b7
#ifndef TestIndex                                                                         //06-10-06|0x01bd
#define TestIndex 0                                                                       //06-10-06|0x01bd
#endif                                                                                    //06-10-06|0x01bd
//------------------------------------------------------------------------                //06-10-06|0x01bd
enum {  _EQUAL_1 = TestIndex };                                                           //06-10-06|0x01bd
//------------------------------------------------------------------------                //06-10-06|0x01bd
#undef TestIndex                                                                          //06-10-06|0x01bd
#define TestIndex _EQUAL_1+1                                                              //06-10-06|0x01bd
//************************************************************************                //06-10-06|0x01bd
#ifndef TestIndex                                                                         //06-10-05|0x01c3
#define TestIndex 0                                                                       //06-10-05|0x01c3
#endif                                                                                    //06-10-05|0x01c3
//------------------------------------------------------------------------                //06-10-05|0x01c3
enum {  _GREAT_1 = TestIndex };                                                           //06-10-05|0x01c3
//------------------------------------------------------------------------                //06-10-05|0x01c3
#undef TestIndex                                                                          //06-10-05|0x01c3
#define TestIndex _GREAT_1+1                                                              //06-10-05|0x01c3
//************************************************************************                //06-10-05|0x01c3
#ifndef TestIndex                                                                         //07-03-28|0x01d2
#define TestIndex 0                                                                       //07-03-28|0x01d2
#endif                                                                                    //07-03-28|0x01d2
//------------------------------------------------------------------------                //07-03-28|0x01d2
enum {  _STATE_NUMBER_1 = TestIndex };                                                    //07-03-28|0x01d2
//------------------------------------------------------------------------                //07-03-28|0x01d2
#undef TestIndex                                                                          //07-03-28|0x01d2
#define TestIndex _STATE_NUMBER_1+1                                                       //07-03-28|0x01d2
//************************************************************************                //07-03-28|0x01d2
#ifndef TestIndex                                                                         //07-09-18|0x01d8
#define TestIndex 0                                                                       //07-09-18|0x01d8
#endif                                                                                    //07-09-18|0x01d8
//------------------------------------------------------------------------                //07-09-18|0x01d8
enum {  _STATE_BYTE_1 = TestIndex };                                                      //07-09-18|0x01d8
//------------------------------------------------------------------------                //07-09-18|0x01d8
#undef TestIndex                                                                          //07-09-18|0x01d8
#define TestIndex _STATE_BYTE_1+1                                                         //07-09-18|0x01d8
//************************************************************************                //07-09-18|0x01d8
#ifndef TestIndex                                                                         //07-09-18|0x01de
#define TestIndex 0                                                                       //07-09-18|0x01de
#endif                                                                                    //07-09-18|0x01de
//------------------------------------------------------------------------                //07-09-18|0x01de
enum {  _STATE_INTEGER_1 = TestIndex };                                                   //07-09-18|0x01de
//------------------------------------------------------------------------                //07-09-18|0x01de
#undef TestIndex                                                                          //07-09-18|0x01de
#define TestIndex _STATE_INTEGER_1+1                                                      //07-09-18|0x01de
//************************************************************************                //07-09-18|0x01de
#ifndef TestIndex                                                                         //07-09-18|0x01e4
#define TestIndex 0                                                                       //07-09-18|0x01e4
#endif                                                                                    //07-09-18|0x01e4
//------------------------------------------------------------------------                //07-09-18|0x01e4
enum {  _STATE_LONG_1 = TestIndex };                                                      //07-09-18|0x01e4
//------------------------------------------------------------------------                //07-09-18|0x01e4
#undef TestIndex                                                                          //07-09-18|0x01e4
#define TestIndex _STATE_LONG_1+1                                                         //07-09-18|0x01e4
//************************************************************************                //07-09-18|0x01e4
#ifndef TestIndex                                                                         //07-09-18|0x01f3
#define TestIndex 0                                                                       //07-09-18|0x01f3
#endif                                                                                    //07-09-18|0x01f3
//------------------------------------------------------------------------                //07-09-18|0x01f3
enum {  _PRIME_1 = TestIndex };                                                           //07-09-18|0x01f3
//------------------------------------------------------------------------                //07-09-18|0x01f3
#undef TestIndex                                                                          //07-09-18|0x01f3
#define TestIndex _PRIME_1+1                                                              //07-09-18|0x01f3
//************************************************************************                //07-09-18|0x01f3
#ifndef TestIndex                                                                         //06-11-19|0x01f9
#define TestIndex 0                                                                       //06-11-19|0x01f9
#endif                                                                                    //06-11-19|0x01f9
//------------------------------------------------------------------------                //06-11-19|0x01f9
enum {  _DECIMAL_1 = TestIndex };                                                         //06-11-19|0x01f9
//------------------------------------------------------------------------                //06-11-19|0x01f9
#undef TestIndex                                                                          //06-11-19|0x01f9
#define TestIndex _DECIMAL_1+1                                                            //06-11-19|0x01f9
//************************************************************************                //06-11-19|0x01f9
#ifndef TestIndex                                                                         //07-11-05|0x0208
#define TestIndex 0                                                                       //07-11-05|0x0208
#endif                                                                                    //07-11-05|0x0208
//------------------------------------------------------------------------                //07-11-05|0x0208
enum {  _STRING_LESS_1 = TestIndex };                                                     //07-11-05|0x0208
//------------------------------------------------------------------------                //07-11-05|0x0208
#undef TestIndex                                                                          //07-11-05|0x0208
#define TestIndex _STRING_LESS_1+1                                                        //07-11-05|0x0208
//************************************************************************                //07-11-05|0x0208
#ifndef TestIndex                                                                         //06-10-09|0x020f
#define TestIndex 0                                                                       //06-10-09|0x020f
#endif                                                                                    //06-10-09|0x020f
//------------------------------------------------------------------------                //06-10-09|0x020f
enum {  _STRING_EQUAL_1 = TestIndex };                                                    //06-10-09|0x020f
//------------------------------------------------------------------------                //06-10-09|0x020f
#undef TestIndex                                                                          //06-10-09|0x020f
#define TestIndex _STRING_EQUAL_1+1                                                       //06-10-09|0x020f
//************************************************************************                //06-10-09|0x020f
#ifndef TestIndex                                                                         //07-11-05|0x0216
#define TestIndex 0                                                                       //07-11-05|0x0216
#endif                                                                                    //07-11-05|0x0216
//------------------------------------------------------------------------                //07-11-05|0x0216
enum {  _STRING_GREAT_1 = TestIndex };                                                    //07-11-05|0x0216
//------------------------------------------------------------------------                //07-11-05|0x0216
#undef TestIndex                                                                          //07-11-05|0x0216
#define TestIndex _STRING_GREAT_1+1                                                       //07-11-05|0x0216
//************************************************************************                //07-11-05|0x0216
#ifndef TestIndex                                                                         //06-11-19|0x0225
#define TestIndex 0                                                                       //06-11-19|0x0225
#endif                                                                                    //06-11-19|0x0225
//------------------------------------------------------------------------                //06-11-19|0x0225
enum {  _STATE_STRING_1 = TestIndex };                                                    //06-11-19|0x0225
//------------------------------------------------------------------------                //06-11-19|0x0225
#undef TestIndex                                                                          //06-11-19|0x0225
#define TestIndex _STATE_STRING_1+1                                                       //06-11-19|0x0225
//************************************************************************                //06-11-19|0x0225
#ifndef TestIndex                                                                         //06-11-19|0x022d
#define TestIndex 0                                                                       //06-11-19|0x022d
#endif                                                                                    //06-11-19|0x022d
//------------------------------------------------------------------------                //06-11-19|0x022d
enum {  _STATE_NAME_1 = TestIndex };                                                      //06-11-19|0x022d
//------------------------------------------------------------------------                //06-11-19|0x022d
#undef TestIndex                                                                          //06-11-19|0x022d
#define TestIndex _STATE_NAME_1+1                                                         //06-11-19|0x022d
//************************************************************************                //06-11-19|0x022d
#ifndef TestIndex                                                                         //07-02-02|0x023d
#define TestIndex 0                                                                       //07-02-02|0x023d
#endif                                                                                    //07-02-02|0x023d
//------------------------------------------------------------------------                //07-02-02|0x023d
enum {  _STRING_BEFORE_1 = TestIndex };                                                   //07-02-02|0x023d
//------------------------------------------------------------------------                //07-02-02|0x023d
#undef TestIndex                                                                          //07-02-02|0x023d
#define TestIndex _STRING_BEFORE_1+1                                                      //07-02-02|0x023d
//************************************************************************                //07-02-02|0x023d
#ifndef TestIndex                                                                         //07-02-06|0x0244
#define TestIndex 0                                                                       //07-02-06|0x0244
#endif                                                                                    //07-02-06|0x0244
//------------------------------------------------------------------------                //07-02-06|0x0244
enum {  _STRING_AFTER_1 = TestIndex };                                                    //07-02-06|0x0244
//------------------------------------------------------------------------                //07-02-06|0x0244
#undef TestIndex                                                                          //07-02-06|0x0244
#define TestIndex _STRING_AFTER_1+1                                                       //07-02-06|0x0244
//************************************************************************                //07-02-06|0x0244
#ifndef TestIndex                                                                         //06-12-12|0x024b
#define TestIndex 0                                                                       //06-12-12|0x024b
#endif                                                                                    //06-12-12|0x024b
//------------------------------------------------------------------------                //06-12-12|0x024b
enum {  _ASCII_VALUE_1 = TestIndex };                                                     //06-12-12|0x024b
//------------------------------------------------------------------------                //06-12-12|0x024b
#undef TestIndex                                                                          //06-12-12|0x024b
#define TestIndex _ASCII_VALUE_1+1                                                        //06-12-12|0x024b
//************************************************************************                //06-12-12|0x024b
#ifndef TestIndex                                                                         //07-02-06|0x0252
#define TestIndex 0                                                                       //07-02-06|0x0252
#endif                                                                                    //07-02-06|0x0252
//------------------------------------------------------------------------                //07-02-06|0x0252
enum {  _STATE_CHAR_1 = TestIndex };                                                      //07-02-06|0x0252
//------------------------------------------------------------------------                //07-02-06|0x0252
#undef TestIndex                                                                          //07-02-06|0x0252
#define TestIndex _STATE_CHAR_1+1                                                         //07-02-06|0x0252
//************************************************************************                //07-02-06|0x0252
#ifndef TestIndex                                                                         //07-02-02|0x0258
#define TestIndex 0                                                                       //07-02-02|0x0258
#endif                                                                                    //07-02-02|0x0258
//------------------------------------------------------------------------                //07-02-02|0x0258
enum {  _FIRST_CHAR_1 = TestIndex };                                                      //07-02-02|0x0258
//------------------------------------------------------------------------                //07-02-02|0x0258
#undef TestIndex                                                                          //07-02-02|0x0258
#define TestIndex _FIRST_CHAR_1+1                                                         //07-02-02|0x0258
//************************************************************************                //07-02-02|0x0258
#ifndef TestIndex                                                                         //07-11-05|0x025f
#define TestIndex 0                                                                       //07-11-05|0x025f
#endif                                                                                    //07-11-05|0x025f
//------------------------------------------------------------------------                //07-11-05|0x025f
enum {  _LAST_CHAR_1 = TestIndex };                                                       //07-11-05|0x025f
//------------------------------------------------------------------------                //07-11-05|0x025f
#undef TestIndex                                                                          //07-11-05|0x025f
#define TestIndex _LAST_CHAR_1+1                                                          //07-11-05|0x025f
//************************************************************************                //07-11-05|0x025f
#ifndef TestIndex                                                                         //06-10-05|0x0266
#define TestIndex 0                                                                       //06-10-05|0x0266
#endif                                                                                    //06-10-05|0x0266
//------------------------------------------------------------------------                //06-10-05|0x0266
enum {  _STRING_LENGTH_1 = TestIndex };                                                   //06-10-05|0x0266
//------------------------------------------------------------------------                //06-10-05|0x0266
#undef TestIndex                                                                          //06-10-05|0x0266
#define TestIndex _STRING_LENGTH_1+1                                                      //06-10-05|0x0266
//************************************************************************                //06-10-05|0x0266
#ifndef TestIndex                                                                         //07-02-07|0x026d
#define TestIndex 0                                                                       //07-02-07|0x026d
#endif                                                                                    //07-02-07|0x026d
//------------------------------------------------------------------------                //07-02-07|0x026d
enum {  _LEAD_BLANKS_1 = TestIndex };                                                     //07-02-07|0x026d
//------------------------------------------------------------------------                //07-02-07|0x026d
#undef TestIndex                                                                          //07-02-07|0x026d
#define TestIndex _LEAD_BLANKS_1+1                                                        //07-02-07|0x026d
//************************************************************************                //07-02-07|0x026d
#ifndef TestIndex                                                                         //06-10-05|0x0274
#define TestIndex 0                                                                       //06-10-05|0x0274
#endif                                                                                    //06-10-05|0x0274
//------------------------------------------------------------------------                //06-10-05|0x0274
enum {  _BLANKS_1 = TestIndex };                                                          //06-10-05|0x0274
//------------------------------------------------------------------------                //06-10-05|0x0274
#undef TestIndex                                                                          //06-10-05|0x0274
#define TestIndex _BLANKS_1+1                                                             //06-10-05|0x0274
//************************************************************************                //06-10-05|0x0274
#ifndef TestIndex                                                                         //06-10-04|0x027b
#define TestIndex 0                                                                       //06-10-04|0x027b
#endif                                                                                    //06-10-04|0x027b
//------------------------------------------------------------------------                //06-10-04|0x027b
enum {  _START_COL_1 = TestIndex };                                                       //06-10-04|0x027b
//------------------------------------------------------------------------                //06-10-04|0x027b
#undef TestIndex                                                                          //06-10-04|0x027b
#define TestIndex _START_COL_1+1                                                          //06-10-04|0x027b
//************************************************************************                //06-10-04|0x027b
#ifndef TestIndex                                                                         //06-09-29|0x028a
#define TestIndex 0                                                                       //06-09-29|0x028a
#endif                                                                                    //06-09-29|0x028a
//------------------------------------------------------------------------                //06-09-29|0x028a
enum {  _LOAD_DICT_1 = TestIndex };                                                       //06-09-29|0x028a
//------------------------------------------------------------------------                //06-09-29|0x028a
#undef TestIndex                                                                          //06-09-29|0x028a
#define TestIndex _LOAD_DICT_1+1                                                          //06-09-29|0x028a
//************************************************************************                //06-09-29|0x028a
#ifndef TestIndex                                                                         //06-11-08|0x028f
#define TestIndex 0                                                                       //06-11-08|0x028f
#endif                                                                                    //06-11-08|0x028f
//------------------------------------------------------------------------                //06-11-08|0x028f
enum {  _LOAD_SUBDICT_1 = TestIndex };                                                    //06-11-08|0x028f
//------------------------------------------------------------------------                //06-11-08|0x028f
#undef TestIndex                                                                          //06-11-08|0x028f
#define TestIndex _LOAD_SUBDICT_1+1                                                       //06-11-08|0x028f
//************************************************************************                //06-11-08|0x028f
#ifndef TestIndex                                                                         //06-12-22|0x0295
#define TestIndex 0                                                                       //06-12-22|0x0295
#endif                                                                                    //06-12-22|0x0295
//------------------------------------------------------------------------                //06-12-22|0x0295
enum {  _RELOAD_DICT_1 = TestIndex };                                                     //06-12-22|0x0295
//------------------------------------------------------------------------                //06-12-22|0x0295
#undef TestIndex                                                                          //06-12-22|0x0295
#define TestIndex _RELOAD_DICT_1+1                                                        //06-12-22|0x0295
//************************************************************************                //06-12-22|0x0295
#ifndef TestIndex                                                                         //06-11-08|0x029a
#define TestIndex 0                                                                       //06-11-08|0x029a
#endif                                                                                    //06-11-08|0x029a
//------------------------------------------------------------------------                //06-11-08|0x029a
enum {  _RELOAD_SUBDICT_1 = TestIndex };                                                  //06-11-08|0x029a
//------------------------------------------------------------------------                //06-11-08|0x029a
#undef TestIndex                                                                          //06-11-08|0x029a
#define TestIndex _RELOAD_SUBDICT_1+1                                                     //06-11-08|0x029a
//************************************************************************                //06-11-08|0x029a
#ifndef TestIndex                                                                         //06-12-22|0x02a0
#define TestIndex 0                                                                       //06-12-22|0x02a0
#endif                                                                                    //06-12-22|0x02a0
//------------------------------------------------------------------------                //06-12-22|0x02a0
enum {  _GET_DICT_1 = TestIndex };                                                        //06-12-22|0x02a0
//------------------------------------------------------------------------                //06-12-22|0x02a0
#undef TestIndex                                                                          //06-12-22|0x02a0
#define TestIndex _GET_DICT_1+1                                                           //06-12-22|0x02a0
//************************************************************************                //06-12-22|0x02a0
#ifndef TestIndex                                                                         //06-11-08|0x02a6
#define TestIndex 0                                                                       //06-11-08|0x02a6
#endif                                                                                    //06-11-08|0x02a6
//------------------------------------------------------------------------                //06-11-08|0x02a6
enum {  _GET_SUBDICT_1 = TestIndex };                                                     //06-11-08|0x02a6
//------------------------------------------------------------------------                //06-11-08|0x02a6
#undef TestIndex                                                                          //06-11-08|0x02a6
#define TestIndex _GET_SUBDICT_1+1                                                        //06-11-08|0x02a6
//************************************************************************                //06-11-08|0x02a6
#ifndef TestIndex                                                                         //06-09-28|0x02ad
#define TestIndex 0                                                                       //06-09-28|0x02ad
#endif                                                                                    //06-09-28|0x02ad
//------------------------------------------------------------------------                //06-09-28|0x02ad
enum {  _STATE_DICT_1 = TestIndex };                                                      //06-09-28|0x02ad
//------------------------------------------------------------------------                //06-09-28|0x02ad
#undef TestIndex                                                                          //06-09-28|0x02ad
#define TestIndex _STATE_DICT_1+1                                                         //06-09-28|0x02ad
//************************************************************************                //06-09-28|0x02ad
#ifndef TestIndex                                                                         //06-11-08|0x02b2
#define TestIndex 0                                                                       //06-11-08|0x02b2
#endif                                                                                    //06-11-08|0x02b2
//------------------------------------------------------------------------                //06-11-08|0x02b2
enum {  _STATE_SUBDICT_1 = TestIndex };                                                   //06-11-08|0x02b2
//------------------------------------------------------------------------                //06-11-08|0x02b2
#undef TestIndex                                                                          //06-11-08|0x02b2
#define TestIndex _STATE_SUBDICT_1+1                                                      //06-11-08|0x02b2
//************************************************************************                //06-11-08|0x02b2
#ifndef TestIndex                                                                         //07-02-03|0x02b8
#define TestIndex 0                                                                       //07-02-03|0x02b8
#endif                                                                                    //07-02-03|0x02b8
//------------------------------------------------------------------------                //07-02-03|0x02b8
enum {  _STATE_DICT_GET_1 = TestIndex };                                                  //07-02-03|0x02b8
//------------------------------------------------------------------------                //07-02-03|0x02b8
#undef TestIndex                                                                          //07-02-03|0x02b8
#define TestIndex _STATE_DICT_GET_1+1                                                     //07-02-03|0x02b8
//************************************************************************                //07-02-03|0x02b8
#ifndef TestIndex                                                                         //06-11-08|0x02bd
#define TestIndex 0                                                                       //06-11-08|0x02bd
#endif                                                                                    //06-11-08|0x02bd
//------------------------------------------------------------------------                //06-11-08|0x02bd
enum {  _STATE_SUBDICT_GET_1 = TestIndex };                                               //06-11-08|0x02bd
//------------------------------------------------------------------------                //06-11-08|0x02bd
#undef TestIndex                                                                          //06-11-08|0x02bd
#define TestIndex _STATE_SUBDICT_GET_1+1                                                  //06-11-08|0x02bd
//************************************************************************                //06-11-08|0x02bd
#ifndef TestIndex                                                                         //09-06-02|0x02cb
#define TestIndex 0                                                                       //09-06-02|0x02cb
#endif                                                                                    //09-06-02|0x02cb
//------------------------------------------------------------------------                //09-06-02|0x02cb
enum {  _GET_POSTOFFICE_NO_1 = TestIndex };                                               //09-06-02|0x02cb
//------------------------------------------------------------------------                //09-06-02|0x02cb
#undef TestIndex                                                                          //09-06-02|0x02cb
#define TestIndex _GET_POSTOFFICE_NO_1+1                                                  //09-06-02|0x02cb
//************************************************************************                //09-06-02|0x02cb
#ifndef TestIndex                                                                         //09-03-11|0x02d2
#define TestIndex 0                                                                       //09-03-11|0x02d2
#endif                                                                                    //09-03-11|0x02d2
//------------------------------------------------------------------------                //09-03-11|0x02d2
enum {  _DELETE_POSTOFFICE_1 = TestIndex };                                               //09-03-11|0x02d2
//------------------------------------------------------------------------                //09-03-11|0x02d2
#undef TestIndex                                                                          //09-03-11|0x02d2
#define TestIndex _DELETE_POSTOFFICE_1+1                                                  //09-03-11|0x02d2
//************************************************************************                //09-03-11|0x02d2
#ifndef TestIndex                                                                         //09-03-10|0x02d7
#define TestIndex 0                                                                       //09-03-10|0x02d7
#endif                                                                                    //09-03-10|0x02d7
//------------------------------------------------------------------------                //09-03-10|0x02d7
enum {  _OPEN_POSTOFFICE_1 = TestIndex };                                                 //09-03-10|0x02d7
//------------------------------------------------------------------------                //09-03-10|0x02d7
#undef TestIndex                                                                          //09-03-10|0x02d7
#define TestIndex _OPEN_POSTOFFICE_1+1                                                    //09-03-10|0x02d7
//************************************************************************                //09-03-10|0x02d7
#ifndef TestIndex                                                                         //09-03-27|0x02db
#define TestIndex 0                                                                       //09-03-27|0x02db
#endif                                                                                    //09-03-27|0x02db
//------------------------------------------------------------------------                //09-03-27|0x02db
enum {  _CREATE_POSTOFFICE_1 = TestIndex };                                               //09-03-27|0x02db
//------------------------------------------------------------------------                //09-03-27|0x02db
#undef TestIndex                                                                          //09-03-27|0x02db
#define TestIndex _CREATE_POSTOFFICE_1+1                                                  //09-03-27|0x02db
//************************************************************************                //09-03-27|0x02db
#ifndef TestIndex                                                                         //07-11-05|0x02df
#define TestIndex 0                                                                       //07-11-05|0x02df
#endif                                                                                    //07-11-05|0x02df
//------------------------------------------------------------------------                //07-11-05|0x02df
enum {  _CREATE_PO_BOX_1 = TestIndex };                                                   //07-11-05|0x02df
//------------------------------------------------------------------------                //07-11-05|0x02df
#undef TestIndex                                                                          //07-11-05|0x02df
#define TestIndex _CREATE_PO_BOX_1+1                                                      //07-11-05|0x02df
//************************************************************************                //07-11-05|0x02df
#ifndef TestIndex                                                                         //07-11-05|0x02e4
#define TestIndex 0                                                                       //07-11-05|0x02e4
#endif                                                                                    //07-11-05|0x02e4
//------------------------------------------------------------------------                //07-11-05|0x02e4
enum {  _SEND_MAIL_1 = TestIndex };                                                       //07-11-05|0x02e4
//------------------------------------------------------------------------                //07-11-05|0x02e4
#undef TestIndex                                                                          //07-11-05|0x02e4
#define TestIndex _SEND_MAIL_1+1                                                          //07-11-05|0x02e4
//************************************************************************                //07-11-05|0x02e4
#ifndef TestIndex                                                                         //09-09-17|0x02e8
#define TestIndex 0                                                                       //09-09-17|0x02e8
#endif                                                                                    //09-09-17|0x02e8
//------------------------------------------------------------------------                //09-09-17|0x02e8
enum {  _EMPTY_PO_BOX_1 = TestIndex };                                                    //09-09-17|0x02e8
//------------------------------------------------------------------------                //09-09-17|0x02e8
#undef TestIndex                                                                          //09-09-17|0x02e8
#define TestIndex _EMPTY_PO_BOX_1+1                                                       //09-09-17|0x02e8
//************************************************************************                //09-09-17|0x02e8
#ifndef TestIndex                                                                         //07-11-05|0x02ed
#define TestIndex 0                                                                       //07-11-05|0x02ed
#endif                                                                                    //07-11-05|0x02ed
//------------------------------------------------------------------------                //07-11-05|0x02ed
enum {  _GET_MAIL_1 = TestIndex };                                                        //07-11-05|0x02ed
//------------------------------------------------------------------------                //07-11-05|0x02ed
#undef TestIndex                                                                          //07-11-05|0x02ed
#define TestIndex _GET_MAIL_1+1                                                           //07-11-05|0x02ed
//************************************************************************                //07-11-05|0x02ed
#ifndef TestIndex                                                                         //07-11-05|0x02f3
#define TestIndex 0                                                                       //07-11-05|0x02f3
#endif                                                                                    //07-11-05|0x02f3
//------------------------------------------------------------------------                //07-11-05|0x02f3
enum {  _POSTOFFICE_EXISTS_1 = TestIndex };                                               //07-11-05|0x02f3
//------------------------------------------------------------------------                //07-11-05|0x02f3
#undef TestIndex                                                                          //07-11-05|0x02f3
#define TestIndex _POSTOFFICE_EXISTS_1+1                                                  //07-11-05|0x02f3
//************************************************************************                //07-11-05|0x02f3
#ifndef TestIndex                                                                         //07-11-05|0x02f7
#define TestIndex 0                                                                       //07-11-05|0x02f7
#endif                                                                                    //07-11-05|0x02f7
//------------------------------------------------------------------------                //07-11-05|0x02f7
enum {  _PO_BOX_EXISTS_1 = TestIndex };                                                   //07-11-05|0x02f7
//------------------------------------------------------------------------                //07-11-05|0x02f7
#undef TestIndex                                                                          //07-11-05|0x02f7
#define TestIndex _PO_BOX_EXISTS_1+1                                                      //07-11-05|0x02f7
//************************************************************************                //07-11-05|0x02f7
#ifndef TestIndex                                                                         //07-11-05|0x02fb
#define TestIndex 0                                                                       //07-11-05|0x02fb
#endif                                                                                    //07-11-05|0x02fb
//------------------------------------------------------------------------                //07-11-05|0x02fb
enum {  _PO_BOX_EMPTY_1 = TestIndex };                                                    //07-11-05|0x02fb
//------------------------------------------------------------------------                //07-11-05|0x02fb
#undef TestIndex                                                                          //07-11-05|0x02fb
#define TestIndex _PO_BOX_EMPTY_1+1                                                       //07-11-05|0x02fb
//************************************************************************                //07-11-05|0x02fb
#ifndef TestIndex                                                                         //09-03-11|0x0300
#define TestIndex 0                                                                       //09-03-11|0x0300
#endif                                                                                    //09-03-11|0x0300
//------------------------------------------------------------------------                //09-03-11|0x0300
enum {  _CLOSE_POSTOFFICE_1 = TestIndex };                                                //09-03-11|0x0300
//------------------------------------------------------------------------                //09-03-11|0x0300
#undef TestIndex                                                                          //09-03-11|0x0300
#define TestIndex _CLOSE_POSTOFFICE_1+1                                                   //09-03-11|0x0300
//************************************************************************                //09-03-11|0x0300
#ifndef TestIndex                                                                         //07-09-11|0x030a
#define TestIndex 0                                                                       //07-09-11|0x030a
#endif                                                                                    //07-09-11|0x030a
//------------------------------------------------------------------------                //07-09-11|0x030a
enum {  _NO_OUT_FILES_1 = TestIndex };                                                    //07-09-11|0x030a
//------------------------------------------------------------------------                //07-09-11|0x030a
#undef TestIndex                                                                          //07-09-11|0x030a
#define TestIndex _NO_OUT_FILES_1+1                                                       //07-09-11|0x030a
//************************************************************************                //07-09-11|0x030a
#ifndef TestIndex                                                                         //06-10-05|0x030f
#define TestIndex 0                                                                       //06-10-05|0x030f
#endif                                                                                    //06-10-05|0x030f
//------------------------------------------------------------------------                //06-10-05|0x030f
enum {  _WRITE_OUT_1 = TestIndex };                                                       //06-10-05|0x030f
//------------------------------------------------------------------------                //06-10-05|0x030f
#undef TestIndex                                                                          //06-10-05|0x030f
#define TestIndex _WRITE_OUT_1+1                                                          //06-10-05|0x030f
//************************************************************************                //06-10-05|0x030f
#ifndef TestIndex                                                                         //13-07-25|0x0315
#define TestIndex 0                                                                       //13-07-25|0x0315
#endif                                                                                    //13-07-25|0x0315
//------------------------------------------------------------------------                //13-07-25|0x0315
enum {  _WRITE_SEGMENT_1 = TestIndex };                                                   //13-07-25|0x0315
//------------------------------------------------------------------------                //13-07-25|0x0315
#undef TestIndex                                                                          //13-07-25|0x0315
#define TestIndex _WRITE_SEGMENT_1+1                                                      //13-07-25|0x0315
//************************************************************************                //13-07-25|0x0315
#ifndef TestIndex                                                                         //07-02-03|0x031b
#define TestIndex 0                                                                       //07-02-03|0x031b
#endif                                                                                    //07-02-03|0x031b
//------------------------------------------------------------------------                //07-02-03|0x031b
enum {  _LOAD_BUFFER_1 = TestIndex };                                                     //07-02-03|0x031b
//------------------------------------------------------------------------                //07-02-03|0x031b
#undef TestIndex                                                                          //07-02-03|0x031b
#define TestIndex _LOAD_BUFFER_1+1                                                        //07-02-03|0x031b
//************************************************************************                //07-02-03|0x031b
#ifndef TestIndex                                                                         //07-09-11|0x031f
#define TestIndex 0                                                                       //07-09-11|0x031f
#endif                                                                                    //07-09-11|0x031f
//------------------------------------------------------------------------                //07-09-11|0x031f
enum {  _APPEND_BUFFER_1 = TestIndex };                                                   //07-09-11|0x031f
//------------------------------------------------------------------------                //07-09-11|0x031f
#undef TestIndex                                                                          //07-09-11|0x031f
#define TestIndex _APPEND_BUFFER_1+1                                                      //07-09-11|0x031f
//************************************************************************                //07-09-11|0x031f
#ifndef TestIndex                                                                         //07-02-03|0x0323
#define TestIndex 0                                                                       //07-02-03|0x0323
#endif                                                                                    //07-02-03|0x0323
//------------------------------------------------------------------------                //07-02-03|0x0323
enum {  _WRITE_BUFFER_1 = TestIndex };                                                    //07-02-03|0x0323
//------------------------------------------------------------------------                //07-02-03|0x0323
#undef TestIndex                                                                          //07-02-03|0x0323
#define TestIndex _WRITE_BUFFER_1+1                                                       //07-02-03|0x0323
//************************************************************************                //07-02-03|0x0323
#ifndef TestIndex                                                                         //08-01-14|0x0329
#define TestIndex 0                                                                       //08-01-14|0x0329
#endif                                                                                    //08-01-14|0x0329
//------------------------------------------------------------------------                //08-01-14|0x0329
enum {  _OUT_BASE_NAME_1 = TestIndex };                                                   //08-01-14|0x0329
//------------------------------------------------------------------------                //08-01-14|0x0329
#undef TestIndex                                                                          //08-01-14|0x0329
#define TestIndex _OUT_BASE_NAME_1+1                                                      //08-01-14|0x0329
//************************************************************************                //08-01-14|0x0329
#ifndef TestIndex                                                                         //08-01-14|0x032f
#define TestIndex 0                                                                       //08-01-14|0x032f
#endif                                                                                    //08-01-14|0x032f
//------------------------------------------------------------------------                //08-01-14|0x032f
enum {  _OUT_NAME_1 = TestIndex };                                                        //08-01-14|0x032f
//------------------------------------------------------------------------                //08-01-14|0x032f
#undef TestIndex                                                                          //08-01-14|0x032f
#define TestIndex _OUT_NAME_1+1                                                           //08-01-14|0x032f
//************************************************************************                //08-01-14|0x032f
#ifndef TestIndex                                                                         //08-01-14|0x0336
#define TestIndex 0                                                                       //08-01-14|0x0336
#endif                                                                                    //08-01-14|0x0336
//------------------------------------------------------------------------                //08-01-14|0x0336
enum {  _OUT_PATH_1 = TestIndex };                                                        //08-01-14|0x0336
//------------------------------------------------------------------------                //08-01-14|0x0336
#undef TestIndex                                                                          //08-01-14|0x0336
#define TestIndex _OUT_PATH_1+1                                                           //08-01-14|0x0336
//************************************************************************                //08-01-14|0x0336
#ifndef TestIndex                                                                         //08-01-14|0x033d
#define TestIndex 0                                                                       //08-01-14|0x033d
#endif                                                                                    //08-01-14|0x033d
//------------------------------------------------------------------------                //08-01-14|0x033d
enum {  _OUT_EXTENT_1 = TestIndex };                                                      //08-01-14|0x033d
//------------------------------------------------------------------------                //08-01-14|0x033d
#undef TestIndex                                                                          //08-01-14|0x033d
#define TestIndex _OUT_EXTENT_1+1                                                         //08-01-14|0x033d
//************************************************************************                //08-01-14|0x033d
#ifndef TestIndex                                                                         //07-09-11|0x0344
#define TestIndex 0                                                                       //07-09-11|0x0344
#endif                                                                                    //07-09-11|0x0344
//------------------------------------------------------------------------                //07-09-11|0x0344
enum {  _OUT_LINE_NO_1 = TestIndex };                                                     //07-09-11|0x0344
//------------------------------------------------------------------------                //07-09-11|0x0344
#undef TestIndex                                                                          //07-09-11|0x0344
#define TestIndex _OUT_LINE_NO_1+1                                                        //07-09-11|0x0344
//************************************************************************                //07-09-11|0x0344
#ifndef TestIndex                                                                         //06-10-03|0x0354
#define TestIndex 0                                                                       //06-10-03|0x0354
#endif                                                                                    //06-10-03|0x0354
//------------------------------------------------------------------------                //06-10-03|0x0354
enum {  _SOURCE_LINE_NO_1 = TestIndex };                                                  //06-10-03|0x0354
//------------------------------------------------------------------------                //06-10-03|0x0354
#undef TestIndex                                                                          //06-10-03|0x0354
#define TestIndex _SOURCE_LINE_NO_1+1                                                     //06-10-03|0x0354
//************************************************************************                //06-10-03|0x0354
#ifndef TestIndex                                                                         //07-09-19|0x0359
#define TestIndex 0                                                                       //07-09-19|0x0359
#endif                                                                                    //07-09-19|0x0359
//------------------------------------------------------------------------                //07-09-19|0x0359
enum {  _SOURCE_NAME_1 = TestIndex };                                                     //07-09-19|0x0359
//------------------------------------------------------------------------                //07-09-19|0x0359
#undef TestIndex                                                                          //07-09-19|0x0359
#define TestIndex _SOURCE_NAME_1+1                                                        //07-09-19|0x0359
//************************************************************************                //07-09-19|0x0359
#ifndef TestIndex                                                                         //10-03-22|0x0367
#define TestIndex 0                                                                       //10-03-22|0x0367
#endif                                                                                    //10-03-22|0x0367
//------------------------------------------------------------------------                //10-03-22|0x0367
enum {  _CREATE_RANDOM_1 = TestIndex };                                                   //10-03-22|0x0367
//------------------------------------------------------------------------                //10-03-22|0x0367
#undef TestIndex                                                                          //10-03-22|0x0367
#define TestIndex _CREATE_RANDOM_1+1                                                      //10-03-22|0x0367
//************************************************************************                //10-03-22|0x0367
#ifndef TestIndex                                                                         //10-03-23|0x036c
#define TestIndex 0                                                                       //10-03-23|0x036c
#endif                                                                                    //10-03-23|0x036c
//------------------------------------------------------------------------                //10-03-23|0x036c
enum {  _RESET_RANDOM_1 = TestIndex };                                                    //10-03-23|0x036c
//------------------------------------------------------------------------                //10-03-23|0x036c
#undef TestIndex                                                                          //10-03-23|0x036c
#define TestIndex _RESET_RANDOM_1+1                                                       //10-03-23|0x036c
//************************************************************************                //10-03-23|0x036c
#ifndef TestIndex                                                                         //10-03-22|0x0370
#define TestIndex 0                                                                       //10-03-22|0x0370
#endif                                                                                    //10-03-22|0x0370
//------------------------------------------------------------------------                //10-03-22|0x0370
enum {  _OPEN_RANDOM_1 = TestIndex };                                                     //10-03-22|0x0370
//------------------------------------------------------------------------                //10-03-22|0x0370
#undef TestIndex                                                                          //10-03-22|0x0370
#define TestIndex _OPEN_RANDOM_1+1                                                        //10-03-22|0x0370
//************************************************************************                //10-03-22|0x0370
#ifndef TestIndex                                                                         //10-03-22|0x0374
#define TestIndex 0                                                                       //10-03-22|0x0374
#endif                                                                                    //10-03-22|0x0374
//------------------------------------------------------------------------                //10-03-22|0x0374
enum {  _CLOSE_RANDOM_1 = TestIndex };                                                    //10-03-22|0x0374
//------------------------------------------------------------------------                //10-03-22|0x0374
#undef TestIndex                                                                          //10-03-22|0x0374
#define TestIndex _CLOSE_RANDOM_1+1                                                       //10-03-22|0x0374
//************************************************************************                //10-03-22|0x0374
#ifndef TestIndex                                                                         //10-03-22|0x0379
#define TestIndex 0                                                                       //10-03-22|0x0379
#endif                                                                                    //10-03-22|0x0379
//------------------------------------------------------------------------                //10-03-22|0x0379
enum {  _LOAD_RANDOM_1 = TestIndex };                                                     //10-03-22|0x0379
//------------------------------------------------------------------------                //10-03-22|0x0379
#undef TestIndex                                                                          //10-03-22|0x0379
#define TestIndex _LOAD_RANDOM_1+1                                                        //10-03-22|0x0379
//************************************************************************                //10-03-22|0x0379
#ifndef TestIndex                                                                         //10-03-23|0x037d
#define TestIndex 0                                                                       //10-03-23|0x037d
#endif                                                                                    //10-03-23|0x037d
//------------------------------------------------------------------------                //10-03-23|0x037d
enum {  _GET_RANDOM_1 = TestIndex };                                                      //10-03-23|0x037d
//------------------------------------------------------------------------                //10-03-23|0x037d
#undef TestIndex                                                                          //10-03-23|0x037d
#define TestIndex _GET_RANDOM_1+1                                                         //10-03-23|0x037d
//************************************************************************                //10-03-23|0x037d
#ifndef TestIndex                                                                         //10-03-23|0x0383
#define TestIndex 0                                                                       //10-03-23|0x0383
#endif                                                                                    //10-03-23|0x0383
//------------------------------------------------------------------------                //10-03-23|0x0383
enum {  _COMPUTE_PARITY_1 = TestIndex };                                                  //10-03-23|0x0383
//------------------------------------------------------------------------                //10-03-23|0x0383
#undef TestIndex                                                                          //10-03-23|0x0383
#define TestIndex _COMPUTE_PARITY_1+1                                                     //10-03-23|0x0383
//************************************************************************                //10-03-23|0x0383
#ifndef TestIndex                                                                         //10-03-23|0x0387
#define TestIndex 0                                                                       //10-03-23|0x0387
#endif                                                                                    //10-03-23|0x0387
//------------------------------------------------------------------------                //10-03-23|0x0387
enum {  _GET_PARITY_1 = TestIndex };                                                      //10-03-23|0x0387
//------------------------------------------------------------------------                //10-03-23|0x0387
#undef TestIndex                                                                          //10-03-23|0x0387
#define TestIndex _GET_PARITY_1+1                                                         //10-03-23|0x0387
//************************************************************************                //10-03-23|0x0387
#ifndef TestIndex                                                                         //10-03-23|0x038d
#define TestIndex 0                                                                       //10-03-23|0x038d
#endif                                                                                    //10-03-23|0x038d
//------------------------------------------------------------------------                //10-03-23|0x038d
enum {  _ENCRYPT_1 = TestIndex };                                                         //10-03-23|0x038d
//------------------------------------------------------------------------                //10-03-23|0x038d
#undef TestIndex                                                                          //10-03-23|0x038d
#define TestIndex _ENCRYPT_1+1                                                            //10-03-23|0x038d
//************************************************************************                //10-03-23|0x038d
#ifndef TestIndex                                                                         //10-03-23|0x0392
#define TestIndex 0                                                                       //10-03-23|0x0392
#endif                                                                                    //10-03-23|0x0392
//------------------------------------------------------------------------                //10-03-23|0x0392
enum {  _DECRYPT_1 = TestIndex };                                                         //10-03-23|0x0392
//------------------------------------------------------------------------                //10-03-23|0x0392
#undef TestIndex                                                                          //10-03-23|0x0392
#define TestIndex _DECRYPT_1+1                                                            //10-03-23|0x0392
//************************************************************************                //10-03-23|0x0392
#ifndef TestIndex                                                                         //06-09-29|0x03a0
#define TestIndex 0                                                                       //06-09-29|0x03a0
#endif                                                                                    //06-09-29|0x03a0
//------------------------------------------------------------------------                //06-09-29|0x03a0
enum {  _GET_TAB_1 = TestIndex };                                                         //06-09-29|0x03a0
//------------------------------------------------------------------------                //06-09-29|0x03a0
#undef TestIndex                                                                          //06-09-29|0x03a0
#define TestIndex _GET_TAB_1+1                                                            //06-09-29|0x03a0
//************************************************************************                //06-09-29|0x03a0
#ifndef TestIndex                                                                         //10-05-16|0x03ae
#define TestIndex 0                                                                       //10-05-16|0x03ae
#endif                                                                                    //10-05-16|0x03ae
//------------------------------------------------------------------------                //10-05-16|0x03ae
enum {  _READ_TEXT_1 = TestIndex };                                                       //10-05-16|0x03ae
//------------------------------------------------------------------------                //10-05-16|0x03ae
#undef TestIndex                                                                          //10-05-16|0x03ae
#define TestIndex _READ_TEXT_1+1                                                          //10-05-16|0x03ae
//************************************************************************                //10-05-16|0x03ae
#ifndef TestIndex                                                                         //10-05-15|0x03b4
#define TestIndex 0                                                                       //10-05-15|0x03b4
#endif                                                                                    //10-05-15|0x03b4
//------------------------------------------------------------------------                //10-05-15|0x03b4
enum {  _STATE_READ_TEXT_1 = TestIndex };                                                 //10-05-15|0x03b4
//------------------------------------------------------------------------                //10-05-15|0x03b4
#undef TestIndex                                                                          //10-05-15|0x03b4
#define TestIndex _STATE_READ_TEXT_1+1                                                    //10-05-15|0x03b4
//************************************************************************                //10-05-15|0x03b4
#ifndef TestIndex                                                                         //10-05-16|0x03ba
#define TestIndex 0                                                                       //10-05-16|0x03ba
#endif                                                                                    //10-05-16|0x03ba
//------------------------------------------------------------------------                //10-05-16|0x03ba
enum {  _NO_TEXT_FILES_1 = TestIndex };                                                   //10-05-16|0x03ba
//------------------------------------------------------------------------                //10-05-16|0x03ba
#undef TestIndex                                                                          //10-05-16|0x03ba
#define TestIndex _NO_TEXT_FILES_1+1                                                      //10-05-16|0x03ba
//************************************************************************                //10-05-16|0x03ba
#ifndef TestIndex                                                                         //10-05-16|0x03bf
#define TestIndex 0                                                                       //10-05-16|0x03bf
#endif                                                                                    //10-05-16|0x03bf
//------------------------------------------------------------------------                //10-05-16|0x03bf
enum {  _TEXT_BASE_NAME_1 = TestIndex };                                                  //10-05-16|0x03bf
//------------------------------------------------------------------------                //10-05-16|0x03bf
#undef TestIndex                                                                          //10-05-16|0x03bf
#define TestIndex _TEXT_BASE_NAME_1+1                                                     //10-05-16|0x03bf
//************************************************************************                //10-05-16|0x03bf
#ifndef TestIndex                                                                         //10-05-16|0x03c5
#define TestIndex 0                                                                       //10-05-16|0x03c5
#endif                                                                                    //10-05-16|0x03c5
//------------------------------------------------------------------------                //10-05-16|0x03c5
enum {  _TEXT_NAME_1 = TestIndex };                                                       //10-05-16|0x03c5
//------------------------------------------------------------------------                //10-05-16|0x03c5
#undef TestIndex                                                                          //10-05-16|0x03c5
#define TestIndex _TEXT_NAME_1+1                                                          //10-05-16|0x03c5
//************************************************************************                //10-05-16|0x03c5
#ifndef TestIndex                                                                         //10-05-16|0x03cc
#define TestIndex 0                                                                       //10-05-16|0x03cc
#endif                                                                                    //10-05-16|0x03cc
//------------------------------------------------------------------------                //10-05-16|0x03cc
enum {  _TEXT_PATH_1 = TestIndex };                                                       //10-05-16|0x03cc
//------------------------------------------------------------------------                //10-05-16|0x03cc
#undef TestIndex                                                                          //10-05-16|0x03cc
#define TestIndex _TEXT_PATH_1+1                                                          //10-05-16|0x03cc
//************************************************************************                //10-05-16|0x03cc
#ifndef TestIndex                                                                         //10-05-16|0x03d3
#define TestIndex 0                                                                       //10-05-16|0x03d3
#endif                                                                                    //10-05-16|0x03d3
//------------------------------------------------------------------------                //10-05-16|0x03d3
enum {  _TEXT_EXTENT_1 = TestIndex };                                                     //10-05-16|0x03d3
//------------------------------------------------------------------------                //10-05-16|0x03d3
#undef TestIndex                                                                          //10-05-16|0x03d3
#define TestIndex _TEXT_EXTENT_1+1                                                        //10-05-16|0x03d3
//************************************************************************                //10-05-16|0x03d3
#ifndef TestIndex                                                                         //10-05-16|0x03da
#define TestIndex 0                                                                       //10-05-16|0x03da
#endif                                                                                    //10-05-16|0x03da
//------------------------------------------------------------------------                //10-05-16|0x03da
enum {  _TEXT_LINE_NO_1 = TestIndex };                                                    //10-05-16|0x03da
//------------------------------------------------------------------------                //10-05-16|0x03da
#undef TestIndex                                                                          //10-05-16|0x03da
#define TestIndex _TEXT_LINE_NO_1+1                                                       //10-05-16|0x03da
//************************************************************************                //10-05-16|0x03da
#ifndef TestIndex                                                                         //check   |0x03e1
#define TestIndex 0                                                                       //check   |0x03e1
#endif                                                                                    //check   |0x03e1
//------------------------------------------------------------------------                //check   |0x03e1
enum {  _READ_SEGMENT_1 = TestIndex };                                                    //check   |0x03e1
//------------------------------------------------------------------------                //check   |0x03e1
#undef TestIndex                                                                          //check   |0x03e1
#define TestIndex _READ_SEGMENT_1+1                                                       //check   |0x03e1
//************************************************************************                //check   |0x03e1
#ifndef TestIndex                                                                         //07-12-26|0x03f0
#define TestIndex 0                                                                       //07-12-26|0x03f0
#endif                                                                                    //07-12-26|0x03f0
//------------------------------------------------------------------------                //07-12-26|0x03f0
enum {  _ERROR_1 = TestIndex };                                                           //07-12-26|0x03f0
//------------------------------------------------------------------------                //07-12-26|0x03f0
#undef TestIndex                                                                          //07-12-26|0x03f0
#define TestIndex _ERROR_1+1                                                              //07-12-26|0x03f0
//************************************************************************                //07-12-26|0x03f0
#ifndef TestIndex                                                                         //07-11-17|0x03f4
#define TestIndex 0                                                                       //07-11-17|0x03f4
#endif                                                                                    //07-11-17|0x03f4
//------------------------------------------------------------------------                //07-11-17|0x03f4
enum {  _STATE_ERROR_1 = TestIndex };                                                     //07-11-17|0x03f4
//------------------------------------------------------------------------                //07-11-17|0x03f4
#undef TestIndex                                                                          //07-11-17|0x03f4
#define TestIndex _STATE_ERROR_1+1                                                        //07-11-17|0x03f4
//************************************************************************                //07-11-17|0x03f4
#ifndef TestIndex                                                                         //07-11-16|0x03fa
#define TestIndex 0                                                                       //07-11-16|0x03fa
#endif                                                                                    //07-11-16|0x03fa
//------------------------------------------------------------------------                //07-11-16|0x03fa
enum {  _GET_ERROR_MACRO_1 = TestIndex };                                                 //07-11-16|0x03fa
//------------------------------------------------------------------------                //07-11-16|0x03fa
#undef TestIndex                                                                          //07-11-16|0x03fa
#define TestIndex _GET_ERROR_MACRO_1+1                                                    //07-11-16|0x03fa
//************************************************************************                //07-11-16|0x03fa
#ifndef TestIndex                                                                         //07-11-16|0x03ff
#define TestIndex 0                                                                       //07-11-16|0x03ff
#endif                                                                                    //07-11-16|0x03ff
//------------------------------------------------------------------------                //07-11-16|0x03ff
enum {  _GET_ERROR_TYPE_1 = TestIndex };                                                  //07-11-16|0x03ff
//------------------------------------------------------------------------                //07-11-16|0x03ff
#undef TestIndex                                                                          //07-11-16|0x03ff
#define TestIndex _GET_ERROR_TYPE_1+1                                                     //07-11-16|0x03ff
//************************************************************************                //07-11-16|0x03ff
#ifndef TestIndex                                                                         //06-10-01|0x040d
#define TestIndex 0                                                                       //06-10-01|0x040d
#endif                                                                                    //06-10-01|0x040d
//------------------------------------------------------------------------                //06-10-01|0x040d
enum {  _DEBUG_ON_1 = TestIndex };                                                        //06-10-01|0x040d
//------------------------------------------------------------------------                //06-10-01|0x040d
#undef TestIndex                                                                          //06-10-01|0x040d
#define TestIndex _DEBUG_ON_1+1                                                           //06-10-01|0x040d
//************************************************************************                //06-10-01|0x040d
#ifndef TestIndex                                                                         //06-10-06|0x041b
#define TestIndex 0                                                                       //06-10-06|0x041b
#endif                                                                                    //06-10-06|0x041b
//------------------------------------------------------------------------                //06-10-06|0x041b
enum {  _DISPLAY_1 = TestIndex };                                                         //06-10-06|0x041b
//------------------------------------------------------------------------                //06-10-06|0x041b
#undef TestIndex                                                                          //06-10-06|0x041b
#define TestIndex _DISPLAY_1+1                                                            //06-10-06|0x041b
//************************************************************************                //06-10-06|0x041b
#ifndef TestIndex                                                                         //06-12-25|0x0420
#define TestIndex 0                                                                       //06-12-25|0x0420
#endif                                                                                    //06-12-25|0x0420
//------------------------------------------------------------------------                //06-12-25|0x0420
enum {  _KEYBOARD_1 = TestIndex };                                                        //06-12-25|0x0420
//------------------------------------------------------------------------                //06-12-25|0x0420
#undef TestIndex                                                                          //06-12-25|0x0420
#define TestIndex _KEYBOARD_1+1                                                           //06-12-25|0x0420
//************************************************************************                //06-12-25|0x0420
#ifndef TestIndex                                                                         //06-12-12|0x042c
#define TestIndex 0                                                                       //06-12-12|0x042c
#endif                                                                                    //06-12-12|0x042c
//------------------------------------------------------------------------                //06-12-12|0x042c
enum {  _GET_PCG_ARG_1 = TestIndex };                                                     //06-12-12|0x042c
//------------------------------------------------------------------------                //06-12-12|0x042c
#undef TestIndex                                                                          //06-12-12|0x042c
#define TestIndex _GET_PCG_ARG_1+1                                                        //06-12-12|0x042c
//************************************************************************                //06-12-12|0x042c
#ifndef TestIndex                                                                         //07-05-18|0x0440
#define TestIndex 0                                                                       //07-05-18|0x0440
#endif                                                                                    //07-05-18|0x0440
//------------------------------------------------------------------------                //07-05-18|0x0440
enum {  call_initial_1 = TestIndex };                                                     //07-05-18|0x0440
//------------------------------------------------------------------------                //07-05-18|0x0440
#undef TestIndex                                                                          //07-05-18|0x0440
#define TestIndex call_initial_1+1                                                        //07-05-18|0x0440
//************************************************************************                //07-05-18|0x0440
#ifndef TestIndex                                                                         //07-05-24|0x05ee
#define TestIndex 0                                                                       //07-05-24|0x05ee
#endif                                                                                    //07-05-24|0x05ee
//------------------------------------------------------------------------                //07-05-24|0x05ee
enum {  utility_bridge_1 = TestIndex };                                                   //07-05-24|0x05ee
//------------------------------------------------------------------------                //07-05-24|0x05ee
#undef TestIndex                                                                          //07-05-24|0x05ee
#define TestIndex utility_bridge_1+1                                                      //07-05-24|0x05ee
//************************************************************************                //07-05-24|0x05ee
#ifndef TestIndex                                                                         //07-05-18|0x0609
#define TestIndex 0                                                                       //07-05-18|0x0609
#endif                                                                                    //07-05-18|0x0609
//------------------------------------------------------------------------                //07-05-18|0x0609
enum {  return_label_1 = TestIndex };                                                     //07-05-18|0x0609
//------------------------------------------------------------------------                //07-05-18|0x0609
#undef TestIndex                                                                          //07-05-18|0x0609
#define TestIndex return_label_1+1                                                        //07-05-18|0x0609
//************************************************************************                //07-05-18|0x0609
#ifndef TestIndex                                                                         //08-01-09|0x062a
#define TestIndex 0                                                                       //08-01-09|0x062a
#endif                                                                                    //08-01-09|0x062a
//------------------------------------------------------------------------                //08-01-09|0x062a
enum {  auto_debug_on_1 = TestIndex };                                                    //08-01-09|0x062a
//------------------------------------------------------------------------                //08-01-09|0x062a
#undef TestIndex                                                                          //08-01-09|0x062a
#define TestIndex auto_debug_on_1+1                                                       //08-01-09|0x062a
//************************************************************************                //08-01-09|0x062a
#ifndef TestIndex                                                                         //08-01-09|0x062b
#define TestIndex 0                                                                       //08-01-09|0x062b
#endif                                                                                    //08-01-09|0x062b
//------------------------------------------------------------------------                //08-01-09|0x062b
enum {  auto_debug_on_2 = TestIndex };                                                    //08-01-09|0x062b
//------------------------------------------------------------------------                //08-01-09|0x062b
#undef TestIndex                                                                          //08-01-09|0x062b
#define TestIndex auto_debug_on_2+1                                                       //08-01-09|0x062b
//************************************************************************                //08-01-09|0x062b
#ifndef TestIndex                                                                         //08-01-08|0x0658
#define TestIndex 0                                                                       //08-01-08|0x0658
#endif                                                                                    //08-01-08|0x0658
//------------------------------------------------------------------------                //08-01-08|0x0658
enum {  debug_on_1 = TestIndex };                                                         //08-01-08|0x0658
//------------------------------------------------------------------------                //08-01-08|0x0658
#undef TestIndex                                                                          //08-01-08|0x0658
#define TestIndex debug_on_1+1                                                            //08-01-08|0x0658
//************************************************************************                //08-01-08|0x0658
#ifndef TestIndex                                                                         //08-01-08|0x0659
#define TestIndex 0                                                                       //08-01-08|0x0659
#endif                                                                                    //08-01-08|0x0659
//------------------------------------------------------------------------                //08-01-08|0x0659
enum {  debug_on_2 = TestIndex };                                                         //08-01-08|0x0659
//------------------------------------------------------------------------                //08-01-08|0x0659
#undef TestIndex                                                                          //08-01-08|0x0659
#define TestIndex debug_on_2+1                                                            //08-01-08|0x0659
//************************************************************************                //08-01-08|0x0659
#ifndef TestIndex                                                                         //08-01-08|0x067c
#define TestIndex 0                                                                       //08-01-08|0x067c
#endif                                                                                    //08-01-08|0x067c
//------------------------------------------------------------------------                //08-01-08|0x067c
enum {  basic_debug_on_1 = TestIndex };                                                   //08-01-08|0x067c
//------------------------------------------------------------------------                //08-01-08|0x067c
#undef TestIndex                                                                          //08-01-08|0x067c
#define TestIndex basic_debug_on_1+1                                                      //08-01-08|0x067c
//************************************************************************                //08-01-08|0x067c
#ifndef TestIndex                                                                         //08-01-08|0x067d
#define TestIndex 0                                                                       //08-01-08|0x067d
#endif                                                                                    //08-01-08|0x067d
//------------------------------------------------------------------------                //08-01-08|0x067d
enum {  basic_debug_on_2 = TestIndex };                                                   //08-01-08|0x067d
//------------------------------------------------------------------------                //08-01-08|0x067d
#undef TestIndex                                                                          //08-01-08|0x067d
#define TestIndex basic_debug_on_2+1                                                      //08-01-08|0x067d
//************************************************************************                //08-01-08|0x067d
#ifndef TestIndex                                                                         //08-01-08|0x067e
#define TestIndex 0                                                                       //08-01-08|0x067e
#endif                                                                                    //08-01-08|0x067e
//------------------------------------------------------------------------                //08-01-08|0x067e
enum {  basic_debug_on_3 = TestIndex };                                                   //08-01-08|0x067e
//------------------------------------------------------------------------                //08-01-08|0x067e
#undef TestIndex                                                                          //08-01-08|0x067e
#define TestIndex basic_debug_on_3+1                                                      //08-01-08|0x067e
//************************************************************************                //08-01-08|0x067e
#ifndef TestIndex                                                                         //06-09-28|0x06ae
#define TestIndex 0                                                                       //06-09-28|0x06ae
#endif                                                                                    //06-09-28|0x06ae
//------------------------------------------------------------------------                //06-09-28|0x06ae
enum {  label_prepare_1 = TestIndex };                                                    //06-09-28|0x06ae
//------------------------------------------------------------------------                //06-09-28|0x06ae
#undef TestIndex                                                                          //06-09-28|0x06ae
#define TestIndex label_prepare_1+1                                                       //06-09-28|0x06ae
//************************************************************************                //06-09-28|0x06ae
#ifndef TestIndex                                                                         //07-05-18|0x06e1
#define TestIndex 0                                                                       //07-05-18|0x06e1
#endif                                                                                    //07-05-18|0x06e1
//------------------------------------------------------------------------                //07-05-18|0x06e1
enum {  class_search_1 = TestIndex };                                                     //07-05-18|0x06e1
//------------------------------------------------------------------------                //07-05-18|0x06e1
#undef TestIndex                                                                          //07-05-18|0x06e1
#define TestIndex class_search_1+1                                                        //07-05-18|0x06e1
//************************************************************************                //07-05-18|0x06e1
#ifndef TestIndex                                                                         //07-05-18|0x06e2
#define TestIndex 0                                                                       //07-05-18|0x06e2
#endif                                                                                    //07-05-18|0x06e2
//------------------------------------------------------------------------                //07-05-18|0x06e2
enum {  class_search_2 = TestIndex };                                                     //07-05-18|0x06e2
//------------------------------------------------------------------------                //07-05-18|0x06e2
#undef TestIndex                                                                          //07-05-18|0x06e2
#define TestIndex class_search_2+1                                                        //07-05-18|0x06e2
//************************************************************************                //07-05-18|0x06e2
#ifndef TestIndex                                                                         //07-05-18|0x06e3
#define TestIndex 0                                                                       //07-05-18|0x06e3
#endif                                                                                    //07-05-18|0x06e3
//------------------------------------------------------------------------                //07-05-18|0x06e3
enum {  class_search_3 = TestIndex };                                                     //07-05-18|0x06e3
//------------------------------------------------------------------------                //07-05-18|0x06e3
#undef TestIndex                                                                          //07-05-18|0x06e3
#define TestIndex class_search_3+1                                                        //07-05-18|0x06e3
//************************************************************************                //07-05-18|0x06e3
#ifndef TestIndex                                                                         //07-05-04|0x070c
#define TestIndex 0                                                                       //07-05-04|0x070c
#endif                                                                                    //07-05-04|0x070c
//------------------------------------------------------------------------                //07-05-04|0x070c
enum {  dict_in_1 = TestIndex };                                                          //07-05-04|0x070c
//------------------------------------------------------------------------                //07-05-04|0x070c
#undef TestIndex                                                                          //07-05-04|0x070c
#define TestIndex dict_in_1+1                                                             //07-05-04|0x070c
//************************************************************************                //07-05-04|0x070c
#ifndef TestIndex                                                                         //09-03-19|0x0739
#define TestIndex 0                                                                       //09-03-19|0x0739
#endif                                                                                    //09-03-19|0x0739
//------------------------------------------------------------------------                //09-03-19|0x0739
enum {  string_in_reg_1 = TestIndex };                                                    //09-03-19|0x0739
//------------------------------------------------------------------------                //09-03-19|0x0739
#undef TestIndex                                                                          //09-03-19|0x0739
#define TestIndex string_in_reg_1+1                                                       //09-03-19|0x0739
//************************************************************************                //09-03-19|0x0739
#ifndef TestIndex                                                                         //06-11-19|0x0755
#define TestIndex 0                                                                       //06-11-19|0x0755
#endif                                                                                    //06-11-19|0x0755
//------------------------------------------------------------------------                //06-11-19|0x0755
enum {  numeric_in_data_1 = TestIndex };                                                  //06-11-19|0x0755
//------------------------------------------------------------------------                //06-11-19|0x0755
#undef TestIndex                                                                          //06-11-19|0x0755
#define TestIndex numeric_in_data_1+1                                                     //06-11-19|0x0755
//************************************************************************                //06-11-19|0x0755
#ifndef TestIndex                                                                         //10-08-27|0x0771
#define TestIndex 0                                                                       //10-08-27|0x0771
#endif                                                                                    //10-08-27|0x0771
//------------------------------------------------------------------------                //10-08-27|0x0771
enum {  write_crlf_1 = TestIndex };                                                       //10-08-27|0x0771
//------------------------------------------------------------------------                //10-08-27|0x0771
#undef TestIndex                                                                          //10-08-27|0x0771
#define TestIndex write_crlf_1+1                                                          //10-08-27|0x0771
//************************************************************************                //10-08-27|0x0771
#ifndef TestIndex                                                                         //10-08-27|0x0772
#define TestIndex 0                                                                       //10-08-27|0x0772
#endif                                                                                    //10-08-27|0x0772
//------------------------------------------------------------------------                //10-08-27|0x0772
enum {  write_crlf_2 = TestIndex };                                                       //10-08-27|0x0772
//------------------------------------------------------------------------                //10-08-27|0x0772
#undef TestIndex                                                                          //10-08-27|0x0772
#define TestIndex write_crlf_2+1                                                          //10-08-27|0x0772
//************************************************************************                //10-08-27|0x0772
#ifndef TestIndex                                                                         //10-08-27|0x079d
#define TestIndex 0                                                                       //10-08-27|0x079d
#endif                                                                                    //10-08-27|0x079d
//------------------------------------------------------------------------                //10-08-27|0x079d
enum {  write_output_1 = TestIndex };                                                     //10-08-27|0x079d
//------------------------------------------------------------------------                //10-08-27|0x079d
#undef TestIndex                                                                          //10-08-27|0x079d
#define TestIndex write_output_1+1                                                        //10-08-27|0x079d
//************************************************************************                //10-08-27|0x079d
#ifndef TestIndex                                                                         //10-08-27|0x079e
#define TestIndex 0                                                                       //10-08-27|0x079e
#endif                                                                                    //10-08-27|0x079e
//------------------------------------------------------------------------                //10-08-27|0x079e
enum {  write_output_2 = TestIndex };                                                     //10-08-27|0x079e
//------------------------------------------------------------------------                //10-08-27|0x079e
#undef TestIndex                                                                          //10-08-27|0x079e
#define TestIndex write_output_2+1                                                        //10-08-27|0x079e
//************************************************************************                //10-08-27|0x079e
#ifndef TestIndex                                                                         //10-08-27|0x079f
#define TestIndex 0                                                                       //10-08-27|0x079f
#endif                                                                                    //10-08-27|0x079f
//------------------------------------------------------------------------                //10-08-27|0x079f
enum {  write_output_3 = TestIndex };                                                     //10-08-27|0x079f
//------------------------------------------------------------------------                //10-08-27|0x079f
#undef TestIndex                                                                          //10-08-27|0x079f
#define TestIndex write_output_3+1                                                        //10-08-27|0x079f
//************************************************************************                //10-08-27|0x079f
#ifndef TestIndex                                                                         //13-07-25|0x07be
#define TestIndex 0                                                                       //13-07-25|0x07be
#endif                                                                                    //13-07-25|0x07be
//------------------------------------------------------------------------                //13-07-25|0x07be
enum {  segment_out_1 = TestIndex };                                                      //13-07-25|0x07be
//------------------------------------------------------------------------                //13-07-25|0x07be
#undef TestIndex                                                                          //13-07-25|0x07be
#define TestIndex segment_out_1+1                                                         //13-07-25|0x07be
//************************************************************************                //13-07-25|0x07be
#ifndef TestIndex                                                                         //13-07-25|0x07bf
#define TestIndex 0                                                                       //13-07-25|0x07bf
#endif                                                                                    //13-07-25|0x07bf
//------------------------------------------------------------------------                //13-07-25|0x07bf
enum {  segment_out_2 = TestIndex };                                                      //13-07-25|0x07bf
//------------------------------------------------------------------------                //13-07-25|0x07bf
#undef TestIndex                                                                          //13-07-25|0x07bf
#define TestIndex segment_out_2+1                                                         //13-07-25|0x07bf
//************************************************************************                //13-07-25|0x07bf
#ifndef TestIndex                                                                         //13-07-25|0x07c0
#define TestIndex 0                                                                       //13-07-25|0x07c0
#endif                                                                                    //13-07-25|0x07c0
//------------------------------------------------------------------------                //13-07-25|0x07c0
enum {  segment_out_3 = TestIndex };                                                      //13-07-25|0x07c0
//------------------------------------------------------------------------                //13-07-25|0x07c0
#undef TestIndex                                                                          //13-07-25|0x07c0
#define TestIndex segment_out_3+1                                                         //13-07-25|0x07c0
//************************************************************************                //13-07-25|0x07c0
#ifndef TestIndex                                                                         //check   |0x0812
#define TestIndex 0                                                                       //check   |0x0812
#endif                                                                                    //check   |0x0812
//------------------------------------------------------------------------                //check   |0x0812
enum {  segment_in_1 = TestIndex };                                                       //check   |0x0812
//------------------------------------------------------------------------                //check   |0x0812
#undef TestIndex                                                                          //check   |0x0812
#define TestIndex segment_in_1+1                                                          //check   |0x0812
//************************************************************************                //check   |0x0812
#ifndef TestIndex                                                                         //check   |0x0813
#define TestIndex 0                                                                       //check   |0x0813
#endif                                                                                    //check   |0x0813
//------------------------------------------------------------------------                //check   |0x0813
enum {  segment_in_2 = TestIndex };                                                       //check   |0x0813
//------------------------------------------------------------------------                //check   |0x0813
#undef TestIndex                                                                          //check   |0x0813
#define TestIndex segment_in_2+1                                                          //check   |0x0813
//************************************************************************                //check   |0x0813
#ifndef TestIndex                                                                         //check   |0x0814
#define TestIndex 0                                                                       //check   |0x0814
#endif                                                                                    //check   |0x0814
//------------------------------------------------------------------------                //check   |0x0814
enum {  segment_in_3 = TestIndex };                                                       //check   |0x0814
//------------------------------------------------------------------------                //check   |0x0814
#undef TestIndex                                                                          //check   |0x0814
#define TestIndex segment_in_3+1                                                          //check   |0x0814
//************************************************************************                //check   |0x0814
#ifndef TestIndex                                                                         //10-08-31|0x083e
#define TestIndex 0                                                                       //10-08-31|0x083e
#endif                                                                                    //10-08-31|0x083e
//------------------------------------------------------------------------                //10-08-31|0x083e
enum {  buffer_out_utility_1 = TestIndex };                                               //10-08-31|0x083e
//------------------------------------------------------------------------                //10-08-31|0x083e
#undef TestIndex                                                                          //10-08-31|0x083e
#define TestIndex buffer_out_utility_1+1                                                  //10-08-31|0x083e
//************************************************************************                //10-08-31|0x083e
#ifndef TestIndex                                                                         //10-08-31|0x083f
#define TestIndex 0                                                                       //10-08-31|0x083f
#endif                                                                                    //10-08-31|0x083f
//------------------------------------------------------------------------                //10-08-31|0x083f
enum {  buffer_out_utility_2 = TestIndex };                                               //10-08-31|0x083f
//------------------------------------------------------------------------                //10-08-31|0x083f
#undef TestIndex                                                                          //10-08-31|0x083f
#define TestIndex buffer_out_utility_2+1                                                  //10-08-31|0x083f
//************************************************************************                //10-08-31|0x083f
#ifndef TestIndex                                                                         //10-08-31|0x0840
#define TestIndex 0                                                                       //10-08-31|0x0840
#endif                                                                                    //10-08-31|0x0840
//------------------------------------------------------------------------                //10-08-31|0x0840
enum {  buffer_out_utility_3 = TestIndex };                                               //10-08-31|0x0840
//------------------------------------------------------------------------                //10-08-31|0x0840
#undef TestIndex                                                                          //10-08-31|0x0840
#define TestIndex buffer_out_utility_3+1                                                  //10-08-31|0x0840
//************************************************************************                //10-08-31|0x0840
#ifndef TestIndex                                                                         //10-08-31|0x0882
#define TestIndex 0                                                                       //10-08-31|0x0882
#endif                                                                                    //10-08-31|0x0882
//------------------------------------------------------------------------                //10-08-31|0x0882
enum {  load_buffer_1 = TestIndex };                                                      //10-08-31|0x0882
//------------------------------------------------------------------------                //10-08-31|0x0882
#undef TestIndex                                                                          //10-08-31|0x0882
#define TestIndex load_buffer_1+1                                                         //10-08-31|0x0882
//************************************************************************                //10-08-31|0x0882
#ifndef TestIndex                                                                         //10-08-31|0x0883
#define TestIndex 0                                                                       //10-08-31|0x0883
#endif                                                                                    //10-08-31|0x0883
//------------------------------------------------------------------------                //10-08-31|0x0883
enum {  load_buffer_2 = TestIndex };                                                      //10-08-31|0x0883
//------------------------------------------------------------------------                //10-08-31|0x0883
#undef TestIndex                                                                          //10-08-31|0x0883
#define TestIndex load_buffer_2+1                                                         //10-08-31|0x0883
//************************************************************************                //10-08-31|0x0883
#ifndef TestIndex                                                                         //10-08-31|0x08a8
#define TestIndex 0                                                                       //10-08-31|0x08a8
#endif                                                                                    //10-08-31|0x08a8
//------------------------------------------------------------------------                //10-08-31|0x08a8
enum {  append_buffer_1 = TestIndex };                                                    //10-08-31|0x08a8
//------------------------------------------------------------------------                //10-08-31|0x08a8
#undef TestIndex                                                                          //10-08-31|0x08a8
#define TestIndex append_buffer_1+1                                                       //10-08-31|0x08a8
//************************************************************************                //10-08-31|0x08a8
#ifndef TestIndex                                                                         //10-08-31|0x08a9
#define TestIndex 0                                                                       //10-08-31|0x08a9
#endif                                                                                    //10-08-31|0x08a9
//------------------------------------------------------------------------                //10-08-31|0x08a9
enum {  append_buffer_2 = TestIndex };                                                    //10-08-31|0x08a9
//------------------------------------------------------------------------                //10-08-31|0x08a9
#undef TestIndex                                                                          //10-08-31|0x08a9
#define TestIndex append_buffer_2+1                                                       //10-08-31|0x08a9
//************************************************************************                //10-08-31|0x08a9
#ifndef TestIndex                                                                         //10-09-01|0x08ce
#define TestIndex 0                                                                       //10-09-01|0x08ce
#endif                                                                                    //10-09-01|0x08ce
//------------------------------------------------------------------------                //10-09-01|0x08ce
enum {  write_buffer_1 = TestIndex };                                                     //10-09-01|0x08ce
//------------------------------------------------------------------------                //10-09-01|0x08ce
#undef TestIndex                                                                          //10-09-01|0x08ce
#define TestIndex write_buffer_1+1                                                        //10-09-01|0x08ce
//************************************************************************                //10-09-01|0x08ce
#ifndef TestIndex                                                                         //10-09-01|0x08cf
#define TestIndex 0                                                                       //10-09-01|0x08cf
#endif                                                                                    //10-09-01|0x08cf
//------------------------------------------------------------------------                //10-09-01|0x08cf
enum {  write_buffer_2 = TestIndex };                                                     //10-09-01|0x08cf
//------------------------------------------------------------------------                //10-09-01|0x08cf
#undef TestIndex                                                                          //10-09-01|0x08cf
#define TestIndex write_buffer_2+1                                                        //10-09-01|0x08cf
//************************************************************************                //10-09-01|0x08cf
#ifndef TestIndex                                                                         //06-09-29|0x0904
#define TestIndex 0                                                                       //06-09-29|0x0904
#endif                                                                                    //06-09-29|0x0904
//------------------------------------------------------------------------                //06-09-29|0x0904
enum {  numeric_in_2_1 = TestIndex };                                                     //06-09-29|0x0904
//------------------------------------------------------------------------                //06-09-29|0x0904
#undef TestIndex                                                                          //06-09-29|0x0904
#define TestIndex numeric_in_2_1+1                                                        //06-09-29|0x0904
//************************************************************************                //06-09-29|0x0904
#ifndef TestIndex                                                                         //06-10-09|0x0925
#define TestIndex 0                                                                       //06-10-09|0x0925
#endif                                                                                    //06-10-09|0x0925
//------------------------------------------------------------------------                //06-10-09|0x0925
enum {  string_in_2_1 = TestIndex };                                                      //06-10-09|0x0925
//------------------------------------------------------------------------                //06-10-09|0x0925
#undef TestIndex                                                                          //06-10-09|0x0925
#define TestIndex string_in_2_1+1                                                         //06-10-09|0x0925
//************************************************************************                //06-10-09|0x0925
#ifndef TestIndex                                                                         //09-03-19|0x0940
#define TestIndex 0                                                                       //09-03-19|0x0940
#endif                                                                                    //09-03-19|0x0940
//------------------------------------------------------------------------                //09-03-19|0x0940
enum {  string_numeric_in_2_1 = TestIndex };                                              //09-03-19|0x0940
//------------------------------------------------------------------------                //09-03-19|0x0940
#undef TestIndex                                                                          //09-03-19|0x0940
#define TestIndex string_numeric_in_2_1+1                                                 //09-03-19|0x0940
//************************************************************************                //09-03-19|0x0940
#ifndef TestIndex                                                                         //06-09-29|0x095c
#define TestIndex 0                                                                       //06-09-29|0x095c
#endif                                                                                    //06-09-29|0x095c
//------------------------------------------------------------------------                //06-09-29|0x095c
enum {  string_numeric_in_3_1 = TestIndex };                                              //06-09-29|0x095c
//------------------------------------------------------------------------                //06-09-29|0x095c
#undef TestIndex                                                                          //06-09-29|0x095c
#define TestIndex string_numeric_in_3_1+1                                                 //06-09-29|0x095c
//************************************************************************                //06-09-29|0x095c
#ifndef TestIndex                                                                         //09-03-19|0x0978
#define TestIndex 0                                                                       //09-03-19|0x0978
#endif                                                                                    //09-03-19|0x0978
//------------------------------------------------------------------------                //09-03-19|0x0978
enum {  string_numeric_in_4_1 = TestIndex };                                              //09-03-19|0x0978
//------------------------------------------------------------------------                //09-03-19|0x0978
#undef TestIndex                                                                          //09-03-19|0x0978
#define TestIndex string_numeric_in_4_1+1                                                 //09-03-19|0x0978
//************************************************************************                //09-03-19|0x0978
#ifndef TestIndex                                                                         //09-03-19|0x0994
#define TestIndex 0                                                                       //09-03-19|0x0994
#endif                                                                                    //09-03-19|0x0994
//------------------------------------------------------------------------                //09-03-19|0x0994
enum {  basic_reg_store_1 = TestIndex };                                                  //09-03-19|0x0994
//------------------------------------------------------------------------                //09-03-19|0x0994
#undef TestIndex                                                                          //09-03-19|0x0994
#define TestIndex basic_reg_store_1+1                                                     //09-03-19|0x0994
//************************************************************************                //09-03-19|0x0994
#ifndef TestIndex                                                                         //09-03-19|0x09b1
#define TestIndex 0                                                                       //09-03-19|0x09b1
#endif                                                                                    //09-03-19|0x09b1
//------------------------------------------------------------------------                //09-03-19|0x09b1
enum {  find_char_1 = TestIndex };                                                        //09-03-19|0x09b1
//------------------------------------------------------------------------                //09-03-19|0x09b1
#undef TestIndex                                                                          //09-03-19|0x09b1
#define TestIndex find_char_1+1                                                           //09-03-19|0x09b1
//************************************************************************                //09-03-19|0x09b1
#ifndef TestIndex                                                                         //09-03-19|0x09b2
#define TestIndex 0                                                                       //09-03-19|0x09b2
#endif                                                                                    //09-03-19|0x09b2
//------------------------------------------------------------------------                //09-03-19|0x09b2
enum {  find_char_2 = TestIndex };                                                        //09-03-19|0x09b2
//------------------------------------------------------------------------                //09-03-19|0x09b2
#undef TestIndex                                                                          //09-03-19|0x09b2
#define TestIndex find_char_2+1                                                           //09-03-19|0x09b2
//************************************************************************                //09-03-19|0x09b2
#ifndef TestIndex                                                                         //06-09-28|0x09d7
#define TestIndex 0                                                                       //06-09-28|0x09d7
#endif                                                                                    //06-09-28|0x09d7
//------------------------------------------------------------------------                //06-09-28|0x09d7
enum {  string_type_1 = TestIndex };                                                      //06-09-28|0x09d7
//------------------------------------------------------------------------                //06-09-28|0x09d7
#undef TestIndex                                                                          //06-09-28|0x09d7
#define TestIndex string_type_1+1                                                         //06-09-28|0x09d7
//************************************************************************                //06-09-28|0x09d7
#ifndef TestIndex                                                                         //06-09-28|0x09d8
#define TestIndex 0                                                                       //06-09-28|0x09d8
#endif                                                                                    //06-09-28|0x09d8
//------------------------------------------------------------------------                //06-09-28|0x09d8
enum {  string_type_2 = TestIndex };                                                      //06-09-28|0x09d8
//------------------------------------------------------------------------                //06-09-28|0x09d8
#undef TestIndex                                                                          //06-09-28|0x09d8
#define TestIndex string_type_2+1                                                         //06-09-28|0x09d8
//************************************************************************                //06-09-28|0x09d8
#ifndef TestIndex                                                                         //06-09-28|0x09d9
#define TestIndex 0                                                                       //06-09-28|0x09d9
#endif                                                                                    //06-09-28|0x09d9
//------------------------------------------------------------------------                //06-09-28|0x09d9
enum {  string_type_3 = TestIndex };                                                      //06-09-28|0x09d9
//------------------------------------------------------------------------                //06-09-28|0x09d9
#undef TestIndex                                                                          //06-09-28|0x09d9
#define TestIndex string_type_3+1                                                         //06-09-28|0x09d9
//************************************************************************                //06-09-28|0x09d9
#ifndef TestIndex                                                                         //06-09-29|0x09fb
#define TestIndex 0                                                                       //06-09-29|0x09fb
#endif                                                                                    //06-09-29|0x09fb
//------------------------------------------------------------------------                //06-09-29|0x09fb
enum {  numeric_reg_out_1 = TestIndex };                                                  //06-09-29|0x09fb
//------------------------------------------------------------------------                //06-09-29|0x09fb
#undef TestIndex                                                                          //06-09-29|0x09fb
#define TestIndex numeric_reg_out_1+1                                                     //06-09-29|0x09fb
//************************************************************************                //06-09-29|0x09fb
#ifndef TestIndex                                                                         //09-06-02|0x0a11
#define TestIndex 0                                                                       //09-06-02|0x0a11
#endif                                                                                    //09-06-02|0x0a11
//------------------------------------------------------------------------                //09-06-02|0x0a11
enum {  get_postoffice_no_1 = TestIndex };                                                //09-06-02|0x0a11
//------------------------------------------------------------------------                //09-06-02|0x0a11
#undef TestIndex                                                                          //09-06-02|0x0a11
#define TestIndex get_postoffice_no_1+1                                                   //09-06-02|0x0a11
//************************************************************************                //09-06-02|0x0a11
#ifndef TestIndex                                                                         //09-03-11|0x0a3b
#define TestIndex 0                                                                       //09-03-11|0x0a3b
#endif                                                                                    //09-03-11|0x0a3b
//------------------------------------------------------------------------                //09-03-11|0x0a3b
enum {  delete_postoffice_1 = TestIndex };                                                //09-03-11|0x0a3b
//------------------------------------------------------------------------                //09-03-11|0x0a3b
#undef TestIndex                                                                          //09-03-11|0x0a3b
#define TestIndex delete_postoffice_1+1                                                   //09-03-11|0x0a3b
//************************************************************************                //09-03-11|0x0a3b
#ifndef TestIndex                                                                         //09-03-11|0x0a3c
#define TestIndex 0                                                                       //09-03-11|0x0a3c
#endif                                                                                    //09-03-11|0x0a3c
//------------------------------------------------------------------------                //09-03-11|0x0a3c
enum {  delete_postoffice_3 = TestIndex };                                                //09-03-11|0x0a3c
//------------------------------------------------------------------------                //09-03-11|0x0a3c
#undef TestIndex                                                                          //09-03-11|0x0a3c
#define TestIndex delete_postoffice_3+1                                                   //09-03-11|0x0a3c
//************************************************************************                //09-03-11|0x0a3c
#ifndef TestIndex                                                                         //09-03-11|0x0a3d
#define TestIndex 0                                                                       //09-03-11|0x0a3d
#endif                                                                                    //09-03-11|0x0a3d
//------------------------------------------------------------------------                //09-03-11|0x0a3d
enum {  delete_postoffice_4 = TestIndex };                                                //09-03-11|0x0a3d
//------------------------------------------------------------------------                //09-03-11|0x0a3d
#undef TestIndex                                                                          //09-03-11|0x0a3d
#define TestIndex delete_postoffice_4+1                                                   //09-03-11|0x0a3d
//************************************************************************                //09-03-11|0x0a3d
#ifndef TestIndex                                                                         //09-03-11|0x0a3e
#define TestIndex 0                                                                       //09-03-11|0x0a3e
#endif                                                                                    //09-03-11|0x0a3e
//------------------------------------------------------------------------                //09-03-11|0x0a3e
enum {  delete_postoffice_5 = TestIndex };                                                //09-03-11|0x0a3e
//------------------------------------------------------------------------                //09-03-11|0x0a3e
#undef TestIndex                                                                          //09-03-11|0x0a3e
#define TestIndex delete_postoffice_5+1                                                   //09-03-11|0x0a3e
//************************************************************************                //09-03-11|0x0a3e
#ifndef TestIndex                                                                         //09-03-11|0x0a7a
#define TestIndex 0                                                                       //09-03-11|0x0a7a
#endif                                                                                    //09-03-11|0x0a7a
//------------------------------------------------------------------------                //09-03-11|0x0a7a
enum {  open_mailbox_1 = TestIndex };                                                     //09-03-11|0x0a7a
//------------------------------------------------------------------------                //09-03-11|0x0a7a
#undef TestIndex                                                                          //09-03-11|0x0a7a
#define TestIndex open_mailbox_1+1                                                        //09-03-11|0x0a7a
//************************************************************************                //09-03-11|0x0a7a
#ifndef TestIndex                                                                         //09-03-11|0x0a7b
#define TestIndex 0                                                                       //09-03-11|0x0a7b
#endif                                                                                    //09-03-11|0x0a7b
//------------------------------------------------------------------------                //09-03-11|0x0a7b
enum {  open_mailbox_2 = TestIndex };                                                     //09-03-11|0x0a7b
//------------------------------------------------------------------------                //09-03-11|0x0a7b
#undef TestIndex                                                                          //09-03-11|0x0a7b
#define TestIndex open_mailbox_2+1                                                        //09-03-11|0x0a7b
//************************************************************************                //09-03-11|0x0a7b
#ifndef TestIndex                                                                         //09-03-11|0x0a7c
#define TestIndex 0                                                                       //09-03-11|0x0a7c
#endif                                                                                    //09-03-11|0x0a7c
//------------------------------------------------------------------------                //09-03-11|0x0a7c
enum {  open_mailbox_3 = TestIndex };                                                     //09-03-11|0x0a7c
//------------------------------------------------------------------------                //09-03-11|0x0a7c
#undef TestIndex                                                                          //09-03-11|0x0a7c
#define TestIndex open_mailbox_3+1                                                        //09-03-11|0x0a7c
//************************************************************************                //09-03-11|0x0a7c
#ifndef TestIndex                                                                         //09-03-11|0x0a7d
#define TestIndex 0                                                                       //09-03-11|0x0a7d
#endif                                                                                    //09-03-11|0x0a7d
//------------------------------------------------------------------------                //09-03-11|0x0a7d
enum {  open_mailbox_4 = TestIndex };                                                     //09-03-11|0x0a7d
//------------------------------------------------------------------------                //09-03-11|0x0a7d
#undef TestIndex                                                                          //09-03-11|0x0a7d
#define TestIndex open_mailbox_4+1                                                        //09-03-11|0x0a7d
//************************************************************************                //09-03-11|0x0a7d
#ifndef TestIndex                                                                         //09-03-10|0x0ac3
#define TestIndex 0                                                                       //09-03-10|0x0ac3
#endif                                                                                    //09-03-10|0x0ac3
//------------------------------------------------------------------------                //09-03-10|0x0ac3
enum {  create_postoffice_1 = TestIndex };                                                //09-03-10|0x0ac3
//------------------------------------------------------------------------                //09-03-10|0x0ac3
#undef TestIndex                                                                          //09-03-10|0x0ac3
#define TestIndex create_postoffice_1+1                                                   //09-03-10|0x0ac3
//************************************************************************                //09-03-10|0x0ac3
#ifndef TestIndex                                                                         //09-03-10|0x0ac4
#define TestIndex 0                                                                       //09-03-10|0x0ac4
#endif                                                                                    //09-03-10|0x0ac4
//------------------------------------------------------------------------                //09-03-10|0x0ac4
enum {  create_postoffice_2 = TestIndex };                                                //09-03-10|0x0ac4
//------------------------------------------------------------------------                //09-03-10|0x0ac4
#undef TestIndex                                                                          //09-03-10|0x0ac4
#define TestIndex create_postoffice_2+1                                                   //09-03-10|0x0ac4
//************************************************************************                //09-03-10|0x0ac4
#ifndef TestIndex                                                                         //09-03-11|0x0af5
#define TestIndex 0                                                                       //09-03-11|0x0af5
#endif                                                                                    //09-03-11|0x0af5
//------------------------------------------------------------------------                //09-03-11|0x0af5
enum {  create_po_box_1 = TestIndex };                                                    //09-03-11|0x0af5
//------------------------------------------------------------------------                //09-03-11|0x0af5
#undef TestIndex                                                                          //09-03-11|0x0af5
#define TestIndex create_po_box_1+1                                                       //09-03-11|0x0af5
//************************************************************************                //09-03-11|0x0af5
#ifndef TestIndex                                                                         //09-03-11|0x0af6
#define TestIndex 0                                                                       //09-03-11|0x0af6
#endif                                                                                    //09-03-11|0x0af6
//------------------------------------------------------------------------                //09-03-11|0x0af6
enum {  create_po_box_2 = TestIndex };                                                    //09-03-11|0x0af6
//------------------------------------------------------------------------                //09-03-11|0x0af6
#undef TestIndex                                                                          //09-03-11|0x0af6
#define TestIndex create_po_box_2+1                                                       //09-03-11|0x0af6
//************************************************************************                //09-03-11|0x0af6
#ifndef TestIndex                                                                         //09-03-13|0x0b27
#define TestIndex 0                                                                       //09-03-13|0x0b27
#endif                                                                                    //09-03-13|0x0b27
//------------------------------------------------------------------------                //09-03-13|0x0b27
enum {  send_mail_1 = TestIndex };                                                        //09-03-13|0x0b27
//------------------------------------------------------------------------                //09-03-13|0x0b27
#undef TestIndex                                                                          //09-03-13|0x0b27
#define TestIndex send_mail_1+1                                                           //09-03-13|0x0b27
//************************************************************************                //09-03-13|0x0b27
#ifndef TestIndex                                                                         //09-03-13|0x0b28
#define TestIndex 0                                                                       //09-03-13|0x0b28
#endif                                                                                    //09-03-13|0x0b28
//------------------------------------------------------------------------                //09-03-13|0x0b28
enum {  send_mail_2 = TestIndex };                                                        //09-03-13|0x0b28
//------------------------------------------------------------------------                //09-03-13|0x0b28
#undef TestIndex                                                                          //09-03-13|0x0b28
#define TestIndex send_mail_2+1                                                           //09-03-13|0x0b28
//************************************************************************                //09-03-13|0x0b28
#ifndef TestIndex                                                                         //09-09-17|0x0b5a
#define TestIndex 0                                                                       //09-09-17|0x0b5a
#endif                                                                                    //09-09-17|0x0b5a
//------------------------------------------------------------------------                //09-09-17|0x0b5a
enum {  empty_po_box_1 = TestIndex };                                                     //09-09-17|0x0b5a
//------------------------------------------------------------------------                //09-09-17|0x0b5a
#undef TestIndex                                                                          //09-09-17|0x0b5a
#define TestIndex empty_po_box_1+1                                                        //09-09-17|0x0b5a
//************************************************************************                //09-09-17|0x0b5a
#ifndef TestIndex                                                                         //09-09-17|0x0b5b
#define TestIndex 0                                                                       //09-09-17|0x0b5b
#endif                                                                                    //09-09-17|0x0b5b
//------------------------------------------------------------------------                //09-09-17|0x0b5b
enum {  empty_po_box_2 = TestIndex };                                                     //09-09-17|0x0b5b
//------------------------------------------------------------------------                //09-09-17|0x0b5b
#undef TestIndex                                                                          //09-09-17|0x0b5b
#define TestIndex empty_po_box_2+1                                                        //09-09-17|0x0b5b
//************************************************************************                //09-09-17|0x0b5b
#ifndef TestIndex                                                                         //09-03-16|0x0b8d
#define TestIndex 0                                                                       //09-03-16|0x0b8d
#endif                                                                                    //09-03-16|0x0b8d
//------------------------------------------------------------------------                //09-03-16|0x0b8d
enum {  get_mail_1 = TestIndex };                                                         //09-03-16|0x0b8d
//------------------------------------------------------------------------                //09-03-16|0x0b8d
#undef TestIndex                                                                          //09-03-16|0x0b8d
#define TestIndex get_mail_1+1                                                            //09-03-16|0x0b8d
//************************************************************************                //09-03-16|0x0b8d
#ifndef TestIndex                                                                         //09-03-16|0x0b8e
#define TestIndex 0                                                                       //09-03-16|0x0b8e
#endif                                                                                    //09-03-16|0x0b8e
//------------------------------------------------------------------------                //09-03-16|0x0b8e
enum {  get_mail_2 = TestIndex };                                                         //09-03-16|0x0b8e
//------------------------------------------------------------------------                //09-03-16|0x0b8e
#undef TestIndex                                                                          //09-03-16|0x0b8e
#define TestIndex get_mail_2+1                                                            //09-03-16|0x0b8e
//************************************************************************                //09-03-16|0x0b8e
#ifndef TestIndex                                                                         //09-03-16|0x0b8f
#define TestIndex 0                                                                       //09-03-16|0x0b8f
#endif                                                                                    //09-03-16|0x0b8f
//------------------------------------------------------------------------                //09-03-16|0x0b8f
enum {  get_mail_3 = TestIndex };                                                         //09-03-16|0x0b8f
//------------------------------------------------------------------------                //09-03-16|0x0b8f
#undef TestIndex                                                                          //09-03-16|0x0b8f
#define TestIndex get_mail_3+1                                                            //09-03-16|0x0b8f
//************************************************************************                //09-03-16|0x0b8f
#ifndef TestIndex                                                                         //09-03-17|0x0bc2
#define TestIndex 0                                                                       //09-03-17|0x0bc2
#endif                                                                                    //09-03-17|0x0bc2
//------------------------------------------------------------------------                //09-03-17|0x0bc2
enum {  postoffice_exists_1 = TestIndex };                                                //09-03-17|0x0bc2
//------------------------------------------------------------------------                //09-03-17|0x0bc2
#undef TestIndex                                                                          //09-03-17|0x0bc2
#define TestIndex postoffice_exists_1+1                                                   //09-03-17|0x0bc2
//************************************************************************                //09-03-17|0x0bc2
#ifndef TestIndex                                                                         //09-03-17|0x0bc3
#define TestIndex 0                                                                       //09-03-17|0x0bc3
#endif                                                                                    //09-03-17|0x0bc3
//------------------------------------------------------------------------                //09-03-17|0x0bc3
enum {  postoffice_exists_2 = TestIndex };                                                //09-03-17|0x0bc3
//------------------------------------------------------------------------                //09-03-17|0x0bc3
#undef TestIndex                                                                          //09-03-17|0x0bc3
#define TestIndex postoffice_exists_2+1                                                   //09-03-17|0x0bc3
//************************************************************************                //09-03-17|0x0bc3
#ifndef TestIndex                                                                         //09-03-17|0x0bc4
#define TestIndex 0                                                                       //09-03-17|0x0bc4
#endif                                                                                    //09-03-17|0x0bc4
//------------------------------------------------------------------------                //09-03-17|0x0bc4
enum {  postoffice_exists_3 = TestIndex };                                                //09-03-17|0x0bc4
//------------------------------------------------------------------------                //09-03-17|0x0bc4
#undef TestIndex                                                                          //09-03-17|0x0bc4
#define TestIndex postoffice_exists_3+1                                                   //09-03-17|0x0bc4
//************************************************************************                //09-03-17|0x0bc4
#ifndef TestIndex                                                                         //09-03-17|0x0bc5
#define TestIndex 0                                                                       //09-03-17|0x0bc5
#endif                                                                                    //09-03-17|0x0bc5
//------------------------------------------------------------------------                //09-03-17|0x0bc5
enum {  postoffice_exists_4 = TestIndex };                                                //09-03-17|0x0bc5
//------------------------------------------------------------------------                //09-03-17|0x0bc5
#undef TestIndex                                                                          //09-03-17|0x0bc5
#define TestIndex postoffice_exists_4+1                                                   //09-03-17|0x0bc5
//************************************************************************                //09-03-17|0x0bc5
#ifndef TestIndex                                                                         //09-03-17|0x0bfb
#define TestIndex 0                                                                       //09-03-17|0x0bfb
#endif                                                                                    //09-03-17|0x0bfb
//------------------------------------------------------------------------                //09-03-17|0x0bfb
enum {  po_box_exists_1 = TestIndex };                                                    //09-03-17|0x0bfb
//------------------------------------------------------------------------                //09-03-17|0x0bfb
#undef TestIndex                                                                          //09-03-17|0x0bfb
#define TestIndex po_box_exists_1+1                                                       //09-03-17|0x0bfb
//************************************************************************                //09-03-17|0x0bfb
#ifndef TestIndex                                                                         //09-03-17|0x0bfc
#define TestIndex 0                                                                       //09-03-17|0x0bfc
#endif                                                                                    //09-03-17|0x0bfc
//------------------------------------------------------------------------                //09-03-17|0x0bfc
enum {  po_box_exists_2 = TestIndex };                                                    //09-03-17|0x0bfc
//------------------------------------------------------------------------                //09-03-17|0x0bfc
#undef TestIndex                                                                          //09-03-17|0x0bfc
#define TestIndex po_box_exists_2+1                                                       //09-03-17|0x0bfc
//************************************************************************                //09-03-17|0x0bfc
#ifndef TestIndex                                                                         //09-03-17|0x0bfd
#define TestIndex 0                                                                       //09-03-17|0x0bfd
#endif                                                                                    //09-03-17|0x0bfd
//------------------------------------------------------------------------                //09-03-17|0x0bfd
enum {  po_box_exists_3 = TestIndex };                                                    //09-03-17|0x0bfd
//------------------------------------------------------------------------                //09-03-17|0x0bfd
#undef TestIndex                                                                          //09-03-17|0x0bfd
#define TestIndex po_box_exists_3+1                                                       //09-03-17|0x0bfd
//************************************************************************                //09-03-17|0x0bfd
#ifndef TestIndex                                                                         //09-03-17|0x0bfe
#define TestIndex 0                                                                       //09-03-17|0x0bfe
#endif                                                                                    //09-03-17|0x0bfe
//------------------------------------------------------------------------                //09-03-17|0x0bfe
enum {  po_box_exists_4 = TestIndex };                                                    //09-03-17|0x0bfe
//------------------------------------------------------------------------                //09-03-17|0x0bfe
#undef TestIndex                                                                          //09-03-17|0x0bfe
#define TestIndex po_box_exists_4+1                                                       //09-03-17|0x0bfe
//************************************************************************                //09-03-17|0x0bfe
#ifndef TestIndex                                                                         //09-03-17|0x0c34
#define TestIndex 0                                                                       //09-03-17|0x0c34
#endif                                                                                    //09-03-17|0x0c34
//------------------------------------------------------------------------                //09-03-17|0x0c34
enum {  po_box_empty_1 = TestIndex };                                                     //09-03-17|0x0c34
//------------------------------------------------------------------------                //09-03-17|0x0c34
#undef TestIndex                                                                          //09-03-17|0x0c34
#define TestIndex po_box_empty_1+1                                                        //09-03-17|0x0c34
//************************************************************************                //09-03-17|0x0c34
#ifndef TestIndex                                                                         //09-03-17|0x0c35
#define TestIndex 0                                                                       //09-03-17|0x0c35
#endif                                                                                    //09-03-17|0x0c35
//------------------------------------------------------------------------                //09-03-17|0x0c35
enum {  po_box_empty_2 = TestIndex };                                                     //09-03-17|0x0c35
//------------------------------------------------------------------------                //09-03-17|0x0c35
#undef TestIndex                                                                          //09-03-17|0x0c35
#define TestIndex po_box_empty_2+1                                                        //09-03-17|0x0c35
//************************************************************************                //09-03-17|0x0c35
#ifndef TestIndex                                                                         //09-03-17|0x0c36
#define TestIndex 0                                                                       //09-03-17|0x0c36
#endif                                                                                    //09-03-17|0x0c36
//------------------------------------------------------------------------                //09-03-17|0x0c36
enum {  po_box_empty_3 = TestIndex };                                                     //09-03-17|0x0c36
//------------------------------------------------------------------------                //09-03-17|0x0c36
#undef TestIndex                                                                          //09-03-17|0x0c36
#define TestIndex po_box_empty_3+1                                                        //09-03-17|0x0c36
//************************************************************************                //09-03-17|0x0c36
#ifndef TestIndex                                                                         //09-03-17|0x0c37
#define TestIndex 0                                                                       //09-03-17|0x0c37
#endif                                                                                    //09-03-17|0x0c37
//------------------------------------------------------------------------                //09-03-17|0x0c37
enum {  po_box_empty_4 = TestIndex };                                                     //09-03-17|0x0c37
//------------------------------------------------------------------------                //09-03-17|0x0c37
#undef TestIndex                                                                          //09-03-17|0x0c37
#define TestIndex po_box_empty_4+1                                                        //09-03-17|0x0c37
//************************************************************************                //09-03-17|0x0c37
#ifndef TestIndex                                                                         //09-03-11|0x0c6d
#define TestIndex 0                                                                       //09-03-11|0x0c6d
#endif                                                                                    //09-03-11|0x0c6d
//------------------------------------------------------------------------                //09-03-11|0x0c6d
enum {  close_mailbox_1 = TestIndex };                                                    //09-03-11|0x0c6d
//------------------------------------------------------------------------                //09-03-11|0x0c6d
#undef TestIndex                                                                          //09-03-11|0x0c6d
#define TestIndex close_mailbox_1+1                                                       //09-03-11|0x0c6d
//************************************************************************                //09-03-11|0x0c6d
#ifndef TestIndex                                                                         //09-03-11|0x0c6e
#define TestIndex 0                                                                       //09-03-11|0x0c6e
#endif                                                                                    //09-03-11|0x0c6e
//------------------------------------------------------------------------                //09-03-11|0x0c6e
enum {  close_mailbox_2 = TestIndex };                                                    //09-03-11|0x0c6e
//------------------------------------------------------------------------                //09-03-11|0x0c6e
#undef TestIndex                                                                          //09-03-11|0x0c6e
#define TestIndex close_mailbox_2+1                                                       //09-03-11|0x0c6e
//************************************************************************                //09-03-11|0x0c6e
#ifndef TestIndex                                                                         //06-09-26|0x0ca3
#define TestIndex 0                                                                       //06-09-26|0x0ca3
#endif                                                                                    //06-09-26|0x0ca3
//------------------------------------------------------------------------                //06-09-26|0x0ca3
enum {  debug_manager_11 = TestIndex };                                                   //06-09-26|0x0ca3
//------------------------------------------------------------------------                //06-09-26|0x0ca3
#undef TestIndex                                                                          //06-09-26|0x0ca3
#define TestIndex debug_manager_11+1                                                      //06-09-26|0x0ca3
//************************************************************************                //06-09-26|0x0ca3
#ifndef TestIndex                                                                         //06-09-26|0x0ca4
#define TestIndex 0                                                                       //06-09-26|0x0ca4
#endif                                                                                    //06-09-26|0x0ca4
//------------------------------------------------------------------------                //06-09-26|0x0ca4
enum {  debug_manager_12 = TestIndex };                                                   //06-09-26|0x0ca4
//------------------------------------------------------------------------                //06-09-26|0x0ca4
#undef TestIndex                                                                          //06-09-26|0x0ca4
#define TestIndex debug_manager_12+1                                                      //06-09-26|0x0ca4
//************************************************************************                //06-09-26|0x0ca4
#ifndef TestIndex                                                                         //06-09-26|0x0ca5
#define TestIndex 0                                                                       //06-09-26|0x0ca5
#endif                                                                                    //06-09-26|0x0ca5
//------------------------------------------------------------------------                //06-09-26|0x0ca5
enum {  debug_manager_13 = TestIndex };                                                   //06-09-26|0x0ca5
//------------------------------------------------------------------------                //06-09-26|0x0ca5
#undef TestIndex                                                                          //06-09-26|0x0ca5
#define TestIndex debug_manager_13+1                                                      //06-09-26|0x0ca5
//************************************************************************                //06-09-26|0x0ca5
#ifndef TestIndex                                                                         //06-09-26|0x0ca6
#define TestIndex 0                                                                       //06-09-26|0x0ca6
#endif                                                                                    //06-09-26|0x0ca6
//------------------------------------------------------------------------                //06-09-26|0x0ca6
enum {  debug_manager_21 = TestIndex };                                                   //06-09-26|0x0ca6
//------------------------------------------------------------------------                //06-09-26|0x0ca6
#undef TestIndex                                                                          //06-09-26|0x0ca6
#define TestIndex debug_manager_21+1                                                      //06-09-26|0x0ca6
//************************************************************************                //06-09-26|0x0ca6
#ifndef TestIndex                                                                         //06-09-26|0x0ca7
#define TestIndex 0                                                                       //06-09-26|0x0ca7
#endif                                                                                    //06-09-26|0x0ca7
//------------------------------------------------------------------------                //06-09-26|0x0ca7
enum {  debug_manager_22 = TestIndex };                                                   //06-09-26|0x0ca7
//------------------------------------------------------------------------                //06-09-26|0x0ca7
#undef TestIndex                                                                          //06-09-26|0x0ca7
#define TestIndex debug_manager_22+1                                                      //06-09-26|0x0ca7
//************************************************************************                //06-09-26|0x0ca7
//*******************************************************************************         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
//****                       END OF FILE                                     ****         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
//*******************************************************************************         //05-24-97|0x0d1a
#endif                                                                                    //05-24-97|0x0d1a
