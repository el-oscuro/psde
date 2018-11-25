//*****************************************************************************           //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
// DEBUG PROCESSOR                                                                        //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-07-14|0x001f
//  defined in the associated manual.                                                     //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-07-14|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-07-14|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-14|0x001f
//  (at your option) any later version.                                                   //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-07-14|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-14|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-14|0x001f
//  GNU General Public License for more details.                                          //06-07-14|0x001f
//                                                                                        //06-07-14|0x001f
//  You should have received a copy of the GNU General Public License                     //06-07-14|0x001f
//  along with this program; if not, write to the Free Software                           //06-07-14|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-14|0x001f
//  USA                                                                                   //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//  For further information, please contact Robert Adams:                                 //06-07-14|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-07-14|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-14|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
//*****************************************************************************           //06-07-14|0x001f
#ifndef precdbug_hpp                                                                      //06-07-14|0x0020
#define precdbug_hpp                                                                      //06-07-14|0x0020
//***************************************************************************             //06-07-14|0x0025
//***************************************************************************             //06-07-14|0x0026
//******                                                               ******             //06-07-14|0x0027
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-14|0x0028
//******                                                               ******             //06-07-14|0x0029
//***************************************************************************             //06-07-14|0x002a
//***************************************************************************             //06-07-14|0x002b
//***************************************************************************             //06-07-14|0x002e
//***************************************************************************             //06-07-14|0x002f
//******                                                               ******             //06-07-14|0x0030
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-14|0x0031
//******                                                               ******             //06-07-14|0x0032
//***************************************************************************             //06-07-14|0x0033
//***************************************************************************             //06-07-14|0x0034
#define UserError 0x0000                                                                  //06-07-14|0x0035
#define BuildError 0x7fff                                                                 //06-07-14|0x0035
#define Display 0x7ffe                                                                    //06-07-14|0x0035
#define KeyBoard 0x7ffd                                                                   //06-07-14|0x0035
#define Success 0xffff                                                                    //06-07-14|0x0035
#define SystemError 0x8000                                                                //06-07-14|0x0035
#define Continue 0x0001                                                                   //06-07-14|0x0035
#define FileDone 0x0002                                                                   //06-07-14|0x0035
#define LineDone 0x0003                                                                   //06-07-14|0x0035
#define Yes 0x0004                                                                        //06-07-14|0x0035
#define No 0x0005                                                                         //06-07-14|0x0035
#define RepeatChar '\x6'                                                                  //06-07-14|0x0035
#define Great 0x0007                                                                      //06-07-14|0x0035
#define Equal 0x0008                                                                      //06-07-14|0x0035
#define Less 0x0009                                                                       //06-07-14|0x0035
#define Zero 0x000a                                                                       //06-07-14|0x0035
#define Minus 0x000b                                                                      //06-07-14|0x0035
//***************************************************************************             //06-07-14|0x0036
#define SystemMsg PcgSystemError("precdbug", __LINE__);                                   //06-07-14|0x0037
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-14|0x0037
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-14|0x0037
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-14|0x0038
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-14|0x0038
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-14|0x0038
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-14|0x0038
#define _SwitchErr case UserError: return(UserError)                                      //06-07-14|0x0039
#define _SwitchOk case Success: break                                                     //06-07-14|0x0039
#define _SwitchEnd default: ReturnSystemError                                             //06-07-14|0x0039
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-14|0x0039
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-14|0x0039
#define _SwitchNo case No:       return(No)                                               //06-07-14|0x0039
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-14|0x0039
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-14|0x0039
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-14|0x0039
#define _SwitchBreak _SwitchGroup break                                                   //06-07-14|0x0039
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-14|0x0039
//***************************************************************************             //06-07-14|0x0053
//***************************************************************************             //06-07-14|0x0054
//******                                                               ******             //06-07-14|0x0055
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-14|0x0056
//******                                                               ******             //06-07-14|0x0057
//***************************************************************************             //06-07-14|0x0058
//***************************************************************************             //06-07-14|0x0059
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-14|0x005a
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-14|0x005a
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-14|0x005a
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-14|0x005a
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-14|0x005a
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-14|0x005a
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-14|0x005a
#define break_test(i) { TestSample(i);  break; }                                          //06-07-14|0x005a
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-14|0x005a
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-14|0x005a
//************************************************************************                //06-07-14|0x005a
#ifndef TestIndex                                                                         //06-07-14|0x005a
#define TestIndex 0                                                                       //06-07-14|0x005a
#endif                                                                                    //06-07-14|0x005a
//------------------------------------------------------------------------                //06-07-14|0x005a
enum {  NoTestSamples = TestIndex };                                                      //06-07-14|0x005a
//------------------------------------------------------------------------                //06-07-14|0x005a
#undef TestIndex                                                                          //06-07-14|0x005a
#define TestIndex NoTestSamples+1                                                         //06-07-14|0x005a
//************************************************************************                //06-07-14|0x005a
//***************************************************************************             //06-07-14|0x005b
//************************************************************************                //06-07-14|0x005c
#define ProcessCallReturnRunFlag ProcessDataFar->call_return_run_flag                     //06-07-14|0x005c
#define ProcessCallReturnStatus ProcessDataFar->call_return_status                        //06-07-14|0x005c
#define ProcessCallReturnState ProcessDataFar->call_return_state                          //06-07-14|0x005c
#define ProcessProcessCommand ProcessDataFar->process_command                             //06-07-14|0x005c
#define ProcessRunFlag ProcessDataFar->run_flag                                           //06-07-14|0x005c
#define ProcessStatus ProcessDataFar->status                                              //06-07-14|0x005c
#define ProcessDebugCommand ProcessDataFar->debug_command                                 //06-07-14|0x005c
#define ProcessFlagState ProcessDataFar->flag_state                                       //06-07-14|0x005c
#define ProcessProcessState ProcessDataFar->process_state                                 //06-07-14|0x005c
#define ProcessRuleState ProcessDataFar->rule_state                                       //06-07-14|0x005c
#define ProcessOutBufferState ProcessDataFar->out_buffer_state                            //06-07-14|0x005c
#define ProcessInBufferState ProcessDataFar->in_buffer_state                              //06-07-14|0x005c
#define ProcessTokens ProcessDataFar->tokens                                              //06-07-14|0x005c
#define ProcessDict ProcessDataFar->dict                                                  //06-07-14|0x005c
#define ProcessBuffer ProcessDataFar->buffer                                              //06-07-14|0x005c
#define ProcessUtilityBridge ProcessDataFar->utility_bridge                               //06-07-14|0x005c
#define ProcessBridgeName ProcessDataFar->bridge_name                                     //06-07-14|0x005c
#define ProcessDebugName ProcessDataFar->debug_name                                       //06-07-14|0x005c
#define ProcessMacroName ProcessDataFar->macro_name                                       //06-07-14|0x005c
#define ProcessClassName ProcessDataFar->class_name                                       //06-07-14|0x005c
#define ProcessResults ProcessDataFar->results                                            //06-07-14|0x005c
#define ProcessParmNum ProcessDataFar->parm_num                                           //06-07-14|0x005c
#define ProcessResultNum ProcessDataFar->result_num                                       //06-07-14|0x005c
//------------------------------------------------------------------------                //06-07-14|0x005c
#define ProcessDictAddr &(ProcessDataFar->dict)                                           //06-07-14|0x005c
#define ProcessClassNameAddr &(ProcessDataFar->class_name)                                //06-07-14|0x005c
#define ProcessBridgeNameAddr &(ProcessDataFar->bridge_name)                              //06-07-14|0x005c
#define ProcessUtilityBridgeAddr &(ProcessDataFar->utility_bridge)                        //06-07-14|0x005c
#define ProcessMacroNameAddr &(ProcessDataFar->macro_name)                                //06-07-14|0x005c
#define ProcessTokensAddr &(ProcessDataFar->tokens)                                       //06-07-14|0x005c
#define ProcessResultsAddr &(ProcessDataFar->results)                                     //06-07-14|0x005c
#define ProcessBufferAddr &(ProcessDataFar->buffer)                                       //06-07-14|0x005c
#define DebugNameChar(i) ProcessDebugName.line[i]                                         //06-07-14|0x005d
#define DebugNameLine ProcessDebugName.line[0]                                            //06-07-14|0x005d
#define DebugNameLineAddr &(ProcessDebugName.line[0])                                     //06-07-14|0x005d
#define DebugNameMacroLineNo ProcessDebugName.macro_line_no                               //06-07-14|0x005d
#define DebugNameType ProcessDebugName.type                                               //06-07-14|0x005d
#define DebugNameStartCol ProcessDebugName.start_col                                      //06-07-14|0x005d
#define DebugNameStartCall ProcessDebugName.start_call                                    //06-07-14|0x005d
#define DebugNamePosition ProcessDebugName.position                                       //06-07-14|0x005d
#define DebugNameLength ProcessDebugName.length                                           //06-07-14|0x005d
#define DebugNameColumn ProcessDebugName.column                                           //06-07-14|0x005d
//**********************************************************************                  //06-07-14|0x005d
//************************************************************************                //06-07-14|0x005e
#define TokensTokenAddr(i) &(ProcessTokens.token[i])                                      //06-07-14|0x005e
#define TokensMacroLineNo(i) ProcessTokens.token[i].macro_line_no                         //06-07-14|0x005e
#define TokensLineAddr(i) &(ProcessTokens.token[i].line[0])                               //06-07-14|0x005e
#define TokensToken(i) ProcessTokens.token[i]                                             //06-07-14|0x005e
#define TokensLine(i) ProcessTokens.token[i].line                                         //06-07-14|0x005e
#define TokensLength(i) ProcessTokens.token[i].length                                     //06-07-14|0x005e
#define TokensColumn(i) ProcessTokens.token[i].column                                     //06-07-14|0x005e
#define TokensHash(i) ProcessTokens.token[i].hash                                         //06-07-14|0x005e
#define TokensPosition(i) ProcessTokens.token[i].position                                 //06-07-14|0x005e
#define TokensType(i) ProcessTokens.token[i].type                                         //06-07-14|0x005e
#define TokensStartCol(i) ProcessTokens.token[i].start_col                                //06-07-14|0x005e
#define TokensStartCall(i) ProcessTokens.token[i].start_call                              //06-07-14|0x005e
#define TokensChar(i,j) ProcessTokens.token[i].line[j]                                    //06-07-14|0x005e
#define TokensNoTokens ProcessTokens.no_tokens                                            //06-07-14|0x005e
#define ResultsChar(i) ProcessResults.line[i]                                             //06-07-14|0x005f
#define ResultsLine ProcessResults.line[0]                                                //06-07-14|0x005f
#define ResultsLineAddr &(ProcessResults.line[0])                                         //06-07-14|0x005f
#define ResultsMacroLineNo ProcessResults.macro_line_no                                   //06-07-14|0x005f
#define ResultsType ProcessResults.type                                                   //06-07-14|0x005f
#define ResultsStartCol ProcessResults.start_col                                          //06-07-14|0x005f
#define ResultsStartCall ProcessResults.start_call                                        //06-07-14|0x005f
#define ResultsPosition ProcessResults.position                                           //06-07-14|0x005f
#define ResultsLength ProcessResults.length                                               //06-07-14|0x005f
#define ResultsColumn ProcessResults.column                                               //06-07-14|0x005f
//**********************************************************************                  //06-07-14|0x005f
//---------------------------------------------------------------------------             //06-07-14|0x0060
#define StringChar(i) StringFar->line[i]                                                  //06-07-14|0x0061
#define StringLine StringFar->line[0]                                                     //06-07-14|0x0061
#define StringLineAddr &(StringFar->line[0])                                              //06-07-14|0x0061
#define StringMacroLineNo StringFar->macro_line_no                                        //06-07-14|0x0061
#define StringType StringFar->type                                                        //06-07-14|0x0061
#define StringStartCol StringFar->start_col                                               //06-07-14|0x0061
#define StringStartCall StringFar->start_call                                             //06-07-14|0x0061
#define StringPosition StringFar->position                                                //06-07-14|0x0061
#define StringLength StringFar->length                                                    //06-07-14|0x0061
#define StringColumn StringFar->column                                                    //06-07-14|0x0061
//**********************************************************************                  //06-07-14|0x0061
#define TraceChar(i) trace.line[i]                                                        //06-07-14|0x0062
#define TraceLine trace.line[0]                                                           //06-07-14|0x0062
#define TraceLineAddr &(trace.line[0])                                                    //06-07-14|0x0062
#define TraceMacroLineNo trace.macro_line_no                                              //06-07-14|0x0062
#define TraceType trace.type                                                              //06-07-14|0x0062
#define TraceStartCol trace.start_col                                                     //06-07-14|0x0062
#define TraceStartCall trace.start_call                                                   //06-07-14|0x0062
#define TracePosition trace.position                                                      //06-07-14|0x0062
#define TraceLength trace.length                                                          //06-07-14|0x0062
#define TraceColumn trace.column                                                          //06-07-14|0x0062
//**********************************************************************                  //06-07-14|0x0062
//***************************************************************************             //06-07-14|0x0063
#define DbugCommand ProcessDebugCommand                                                   //06-07-14|0x0064
#define DebugMessage debug_message(ProcessDataFar)                                        //06-07-14|0x0064
#define DebugTrace PrecDbugTrace(ProcessDataFar)                                          //06-07-14|0x0064
#define CommandArg command_arg(ProcessDataFar)                                            //06-07-14|0x0064
#define DisplayResults display_results(ProcessDataFar)                                    //06-07-14|0x0064
#define DisplayFlag display_flag(ProcessDataFar)                                          //06-07-14|0x0064
#define DebugPause debug_pause(ProcessDataFar)                                            //06-07-14|0x0064
#define DispMenu1 "\nR-Run, X-Stop, N-Step:  Depress Key Then Enter\n"                    //06-07-14|0x0064
#define DispMenu GuiWriteLine(DispMenu1)                                                  //06-07-14|0x0064
#define MenuPause menu_pause()                                                            //06-07-14|0x0064
#ifndef TestIndex                                                                         //06-10-01|0x00e9
#define TestIndex 0                                                                       //06-10-01|0x00e9
#endif                                                                                    //06-10-01|0x00e9
//------------------------------------------------------------------------                //06-10-01|0x00e9
enum {  debug_message_1 = TestIndex };                                                    //06-10-01|0x00e9
//------------------------------------------------------------------------                //06-10-01|0x00e9
#undef TestIndex                                                                          //06-10-01|0x00e9
#define TestIndex debug_message_1+1                                                       //06-10-01|0x00e9
//************************************************************************                //06-10-01|0x00e9
#ifndef TestIndex                                                                         //06-10-01|0x0104
#define TestIndex 0                                                                       //06-10-01|0x0104
#endif                                                                                    //06-10-01|0x0104
//------------------------------------------------------------------------                //06-10-01|0x0104
enum {  debug_trace_1 = TestIndex };                                                      //06-10-01|0x0104
//------------------------------------------------------------------------                //06-10-01|0x0104
#undef TestIndex                                                                          //06-10-01|0x0104
#define TestIndex debug_trace_1+1                                                         //06-10-01|0x0104
//************************************************************************                //06-10-01|0x0104
#ifndef TestIndex                                                                         //06-10-01|0x0140
#define TestIndex 0                                                                       //06-10-01|0x0140
#endif                                                                                    //06-10-01|0x0140
//------------------------------------------------------------------------                //06-10-01|0x0140
enum {  command_arg_1 = TestIndex };                                                      //06-10-01|0x0140
//------------------------------------------------------------------------                //06-10-01|0x0140
#undef TestIndex                                                                          //06-10-01|0x0140
#define TestIndex command_arg_1+1                                                         //06-10-01|0x0140
//************************************************************************                //06-10-01|0x0140
#ifndef TestIndex                                                                         //06-10-02|0x0166
#define TestIndex 0                                                                       //06-10-02|0x0166
#endif                                                                                    //06-10-02|0x0166
//------------------------------------------------------------------------                //06-10-02|0x0166
enum {  display_results_1 = TestIndex };                                                  //06-10-02|0x0166
//------------------------------------------------------------------------                //06-10-02|0x0166
#undef TestIndex                                                                          //06-10-02|0x0166
#define TestIndex display_results_1+1                                                     //06-10-02|0x0166
//************************************************************************                //06-10-02|0x0166
#ifndef TestIndex                                                                         //06-10-02|0x0181
#define TestIndex 0                                                                       //06-10-02|0x0181
#endif                                                                                    //06-10-02|0x0181
//------------------------------------------------------------------------                //06-10-02|0x0181
enum {  display_flag_1 = TestIndex };                                                     //06-10-02|0x0181
//------------------------------------------------------------------------                //06-10-02|0x0181
#undef TestIndex                                                                          //06-10-02|0x0181
#define TestIndex display_flag_1+1                                                        //06-10-02|0x0181
//************************************************************************                //06-10-02|0x0181
#ifndef TestIndex                                                                         //06-11-06|0x01a1
#define TestIndex 0                                                                       //06-11-06|0x01a1
#endif                                                                                    //06-11-06|0x01a1
//------------------------------------------------------------------------                //06-11-06|0x01a1
enum {  debug_pause_1 = TestIndex };                                                      //06-11-06|0x01a1
//------------------------------------------------------------------------                //06-11-06|0x01a1
#undef TestIndex                                                                          //06-11-06|0x01a1
#define TestIndex debug_pause_1+1                                                         //06-11-06|0x01a1
//************************************************************************                //06-11-06|0x01a1
#ifndef TestIndex                                                                         //06-11-06|0x01c1
#define TestIndex 0                                                                       //06-11-06|0x01c1
#endif                                                                                    //06-11-06|0x01c1
//------------------------------------------------------------------------                //06-11-06|0x01c1
enum {  menu_pause_1 = TestIndex };                                                       //06-11-06|0x01c1
//------------------------------------------------------------------------                //06-11-06|0x01c1
#undef TestIndex                                                                          //06-11-06|0x01c1
#define TestIndex menu_pause_1+1                                                          //06-11-06|0x01c1
//************************************************************************                //06-11-06|0x01c1
//*******************************************************************************         //05-24-97|0x023c
//*******************************************************************************         //05-24-97|0x023c
//****                       END OF FILE                                     ****         //05-24-97|0x023c
//*******************************************************************************         //05-24-97|0x023c
//*******************************************************************************         //05-24-97|0x023c
#endif                                                                                    //05-24-97|0x023c
