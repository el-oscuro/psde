//*****************************************************************************           //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
// PRECEDENCE SOURCE GENERATOR                                                            //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  The purpose of this program as well as instructions regarding its use is              //05-14-97|0x001e
//  defined in the associated manual.                                                     //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  This program is free software; you can redistribute it and/or modify                  //05-14-97|0x001e
//  it under the terms of the GNU General Public License as published by                  //05-14-97|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //05-14-97|0x001e
//  (at your option) any later version.                                                   //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
//  This program is distributed in the hope that it will be useful,                       //05-14-97|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //05-14-97|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //05-14-97|0x001e
//  GNU General Public License for more details.                                          //05-14-97|0x001e
//                                                                                        //05-14-97|0x001e
//  You should have received a copy of the GNU General Public License                     //05-14-97|0x001e
//  along with this program; if not, write to the Free Software                           //05-14-97|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //05-14-97|0x001e
//  USA                                                                                   //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//  For further information, please contact Robert Adams:                                 //05-14-97|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //05-14-97|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //05-14-97|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
//*****************************************************************************           //05-14-97|0x001e
#ifndef precsrce_hpp                                                                      //05-14-97|0x001f
#define precsrce_hpp                                                                      //05-14-97|0x001f
//***************************************************************************             //06-07-12|0x002b
//***************************************************************************             //06-07-12|0x002c
//******                                                               ******             //06-07-12|0x002d
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x002e
//******                                                               ******             //06-07-12|0x002f
//***************************************************************************             //06-07-12|0x0030
//***************************************************************************             //06-07-12|0x0031
//***************************************************************************             //06-07-12|0x0034
//***************************************************************************             //06-07-12|0x0035
//******                                                               ******             //06-07-12|0x0036
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x0037
//******                                                               ******             //06-07-12|0x0038
//***************************************************************************             //06-07-12|0x0039
//***************************************************************************             //06-07-12|0x003a
#define UserError 0x0000                                                                  //06-07-12|0x003b
#define BuildError 0x7fff                                                                 //06-07-12|0x003b
#define Display 0x7ffe                                                                    //06-07-12|0x003b
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x003b
#define Success 0xffff                                                                    //06-07-12|0x003b
#define SystemError 0x8000                                                                //06-07-12|0x003b
#define Continue 0x0001                                                                   //06-07-12|0x003b
#define FileDone 0x0002                                                                   //06-07-12|0x003b
#define LineDone 0x0003                                                                   //06-07-12|0x003b
#define Yes 0x0004                                                                        //06-07-12|0x003b
#define No 0x0005                                                                         //06-07-12|0x003b
#define RepeatChar '\x6'                                                                  //06-07-12|0x003b
#define Great 0x0007                                                                      //06-07-12|0x003b
#define Equal 0x0008                                                                      //06-07-12|0x003b
#define Less 0x0009                                                                       //06-07-12|0x003b
#define Zero 0x000a                                                                       //06-07-12|0x003b
#define Minus 0x000b                                                                      //06-07-12|0x003b
//***************************************************************************             //06-07-12|0x003c
#define SystemMsg PcgSystemError("precsrce", __LINE__);                                   //06-07-12|0x003d
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x003d
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x003d
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x003e
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x003e
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x003e
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x003e
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x003f
#define _SwitchOk case Success: break                                                     //06-07-12|0x003f
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x003f
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x003f
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x003f
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x003f
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x003f
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x003f
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x003f
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x003f
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x003f
#define RetParm 0                                                                         //07-04-28|0x0040
#define CallParm 1                                                                        //07-04-28|0x0040
#define PermReg 10                                                                        //07-04-28|0x0040
#define OnceReg 36                                                                        //07-04-28|0x0040
#define ProjParm 62                                                                       //07-04-28|0x0040
#define CmdLnParm 72                                                                      //07-04-28|0x0040
#define ErrorParm 82                                                                      //07-04-28|0x0040
//************************************************************************                //07-04-28|0x0040
//***************************************************************************             //06-07-12|0x0061
//***************************************************************************             //06-07-12|0x0062
//******                                                               ******             //06-07-12|0x0063
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0064
//******                                                               ******             //06-07-12|0x0065
//***************************************************************************             //06-07-12|0x0066
//***************************************************************************             //06-07-12|0x0067
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x0068
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x0068
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x0068
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x0068
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-12|0x0068
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-12|0x0068
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x0068
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x0068
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x0068
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x0068
//************************************************************************                //06-07-12|0x0068
#ifndef TestIndex                                                                         //06-07-12|0x0068
#define TestIndex 0                                                                       //06-07-12|0x0068
#endif                                                                                    //06-07-12|0x0068
//------------------------------------------------------------------------                //06-07-12|0x0068
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x0068
//------------------------------------------------------------------------                //06-07-12|0x0068
#undef TestIndex                                                                          //06-07-12|0x0068
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x0068
//************************************************************************                //06-07-12|0x0068
//***************************************************************************             //06-07-12|0x0069
//************************************************************************                //06-07-12|0x006a
#define ProcessCallReturnRunFlag process_addr->call_return_run_flag                       //06-07-12|0x006a
#define ProcessCallReturnStatus process_addr->call_return_status                          //06-07-12|0x006a
#define ProcessCallReturnState process_addr->call_return_state                            //06-07-12|0x006a
#define ProcessProcessCommand process_addr->process_command                               //06-07-12|0x006a
#define ProcessRunFlag process_addr->run_flag                                             //06-07-12|0x006a
#define ProcessStatus process_addr->status                                                //06-07-12|0x006a
#define ProcessDebugCommand process_addr->debug_command                                   //06-07-12|0x006a
#define ProcessFlagState process_addr->flag_state                                         //06-07-12|0x006a
#define ProcessProcessState process_addr->process_state                                   //06-07-12|0x006a
#define ProcessRuleState process_addr->rule_state                                         //06-07-12|0x006a
#define ProcessOutBufferState process_addr->out_buffer_state                              //06-07-12|0x006a
#define ProcessInBufferState process_addr->in_buffer_state                                //06-07-12|0x006a
#define ProcessTokens process_addr->tokens                                                //06-07-12|0x006a
#define ProcessDict process_addr->dict                                                    //06-07-12|0x006a
#define ProcessBuffer process_addr->buffer                                                //06-07-12|0x006a
#define ProcessUtilityBridge process_addr->utility_bridge                                 //06-07-12|0x006a
#define ProcessBridgeName process_addr->bridge_name                                       //06-07-12|0x006a
#define ProcessDebugName process_addr->debug_name                                         //06-07-12|0x006a
#define ProcessMacroName process_addr->macro_name                                         //06-07-12|0x006a
#define ProcessClassName process_addr->class_name                                         //06-07-12|0x006a
#define ProcessResults process_addr->results                                              //06-07-12|0x006a
#define ProcessParmNum process_addr->parm_num                                             //06-07-12|0x006a
#define ProcessResultNum process_addr->result_num                                         //06-07-12|0x006a
//------------------------------------------------------------------------                //06-07-12|0x006a
#define ProcessDictAddr &(process_addr->dict)                                             //06-07-12|0x006a
#define ProcessClassNameAddr &(process_addr->class_name)                                  //06-07-12|0x006a
#define ProcessBridgeNameAddr &(process_addr->bridge_name)                                //06-07-12|0x006a
#define ProcessUtilityBridgeAddr &(process_addr->utility_bridge)                          //06-07-12|0x006a
#define ProcessMacroNameAddr &(process_addr->macro_name)                                  //06-07-12|0x006a
#define ProcessTokensAddr &(process_addr->tokens)                                         //06-07-12|0x006a
#define ProcessResultsAddr &(process_addr->results)                                       //06-07-12|0x006a
#define ProcessBufferAddr &(process_addr->buffer)                                         //06-07-12|0x006a
//************************************************************************                //06-07-12|0x006b
#define TokensTokenAddr(i) &(ProcessTokens.token[i])                                      //06-07-12|0x006b
#define TokensMacroLineNo(i) ProcessTokens.token[i].macro_line_no                         //06-07-12|0x006b
#define TokensLineAddr(i) &(ProcessTokens.token[i].line[0])                               //06-07-12|0x006b
#define TokensToken(i) ProcessTokens.token[i]                                             //06-07-12|0x006b
#define TokensLine(i) ProcessTokens.token[i].line                                         //06-07-12|0x006b
#define TokensLength(i) ProcessTokens.token[i].length                                     //06-07-12|0x006b
#define TokensColumn(i) ProcessTokens.token[i].column                                     //06-07-12|0x006b
#define TokensHash(i) ProcessTokens.token[i].hash                                         //06-07-12|0x006b
#define TokensPosition(i) ProcessTokens.token[i].position                                 //06-07-12|0x006b
#define TokensType(i) ProcessTokens.token[i].type                                         //06-07-12|0x006b
#define TokensStartCol(i) ProcessTokens.token[i].start_col                                //06-07-12|0x006b
#define TokensStartCall(i) ProcessTokens.token[i].start_call                              //06-07-12|0x006b
#define TokensChar(i,j) ProcessTokens.token[i].line[j]                                    //06-07-12|0x006b
#define TokensNoTokens ProcessTokens.no_tokens                                            //06-07-12|0x006b
#define ResultsChar(i) ProcessResults.line[i]                                             //06-07-12|0x006c
#define ResultsLine ProcessResults.line[0]                                                //06-07-12|0x006c
#define ResultsLineAddr &(ProcessResults.line[0])                                         //06-07-12|0x006c
#define ResultsMacroLineNo ProcessResults.macro_line_no                                   //06-07-12|0x006c
#define ResultsType ProcessResults.type                                                   //06-07-12|0x006c
#define ResultsStartCol ProcessResults.start_col                                          //06-07-12|0x006c
#define ResultsStartCall ProcessResults.start_call                                        //06-07-12|0x006c
#define ResultsPosition ProcessResults.position                                           //06-07-12|0x006c
#define ResultsLength ProcessResults.length                                               //06-07-12|0x006c
#define ResultsColumn ProcessResults.column                                               //06-07-12|0x006c
//**********************************************************************                  //06-07-12|0x006c
#define ParmNumChar0 ProcessParmNum.value.char0                                           //06-07-12|0x006d
#define ParmNumByte0 ProcessParmNum.value.byte0                                           //06-07-12|0x006d
#define ParmNumSint0 ProcessParmNum.value.sint0                                           //06-07-12|0x006d
#define ParmNumWord0 ProcessParmNum.value.word0                                           //06-07-12|0x006d
#define ParmNumUlong ProcessParmNum.value.ulong                                           //06-07-12|0x006d
#define ParmNumType ProcessParmNum.type                                                   //06-07-12|0x006d
//**********************************************************************                  //06-07-12|0x006d
#define ResultNumChar0 ProcessResultNum.value.char0                                       //06-07-12|0x006e
#define ResultNumByte0 ProcessResultNum.value.byte0                                       //06-07-12|0x006e
#define ResultNumSint0 ProcessResultNum.value.sint0                                       //06-07-12|0x006e
#define ResultNumWord0 ProcessResultNum.value.word0                                       //06-07-12|0x006e
#define ResultNumUlong ProcessResultNum.value.ulong                                       //06-07-12|0x006e
#define ResultNumType ProcessResultNum.type                                               //06-07-12|0x006e
//**********************************************************************                  //06-07-12|0x006e
#define BridgeChar(i) ProcessBridgeName.line[i]                                           //06-07-14|0x006f
#define BridgeLine ProcessBridgeName.line[0]                                              //06-07-14|0x006f
#define BridgeLineAddr &(ProcessBridgeName.line[0])                                       //06-07-14|0x006f
#define BridgeMacroLineNo ProcessBridgeName.macro_line_no                                 //06-07-14|0x006f
#define BridgeType ProcessBridgeName.type                                                 //06-07-14|0x006f
#define BridgeStartCol ProcessBridgeName.start_col                                        //06-07-14|0x006f
#define BridgeStartCall ProcessBridgeName.start_call                                      //06-07-14|0x006f
#define BridgePosition ProcessBridgeName.position                                         //06-07-14|0x006f
#define BridgeLength ProcessBridgeName.length                                             //06-07-14|0x006f
#define BridgeColumn ProcessBridgeName.column                                             //06-07-14|0x006f
//**********************************************************************                  //06-07-14|0x006f
//---------------------------------------------------------------------------             //06-07-12|0x0070
//**********************************************************************                  //06-07-12|0x0071
#define FileSrcFile ProcessFilesFar->source_file                                          //06-07-12|0x0071
#define FileSrcFileAddr &(ProcessFilesFar->source_file)                                   //06-07-12|0x0071
#define FileSrcLineNo ProcessFilesFar->source_file.line_no                                //06-07-12|0x0071
#define FileSrcFileName &(ProcessFilesFar->source_file.file_control.name[0])              //06-07-12|0x0071
#define FileSrcExtent &(ProcessFilesFar->source_extent[0])                                //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FileMailBoxFileNo ProcessFilesFar->mailbox_file_no                                //06-07-12|0x0071
#define FileMailBoxNoFiles ProcessFilesFar->no_mailbox_files                              //06-07-12|0x0071
#define FileMailBoxName(i) ProcessFilesFar->mailbox_file[i].name                          //06-07-12|0x0071
#define FileMailBoxPath &(ProcessFilesFar->mailbox_path[0])                               //06-07-12|0x0071
#define FileMailBoxStatus(i) ProcessFilesFar->mailbox_file[i].status                      //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FileOutNoFiles ProcessFilesFar->no_output_files                                   //06-07-12|0x0071
#define FileOutFile(i) ProcessFilesFar->output_file[i].file                               //06-07-12|0x0071
#define FileOutFileAddr(i) &(ProcessFilesFar->output_file[i].file)                        //06-07-12|0x0071
#define FileOutLineNo(i) ProcessFilesFar->output_file[i].file.line_no                     //06-07-12|0x0071
#define FileOutStatus(i) ProcessFilesFar->output_file[i].file.status                      //06-07-12|0x0071
#define FileOutFileName(i) &(ProcessFilesFar->output_file[i].file.file_control.name[0])   //06-07-12|0x0071
#define FileOutExtent(i) &(ProcessFilesFar->output_file[i].extent[0])                     //06-07-12|0x0071
#define FileOutPath(i) &(ProcessFilesFar->output_file[i].path[0])                         //06-07-12|0x0071
#define FileOutName &(ProcessFilesFar->output_name[0])                                    //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FileInNoFiles ProcessFilesFar->no_input_files                                     //06-07-12|0x0071
#define FileInFile(i) ProcessFilesFar->input_file[i].file                                 //06-07-12|0x0071
#define FileInFileAddr(i) &(ProcessFilesFar->input_file[i].file)                          //06-07-12|0x0071
#define FileInLineNo(i) ProcessFilesFar->input_file[i].file.line_no                       //06-07-12|0x0071
#define FileInFileName(i) &(ProcessFilesFar->input_file[i].file.file_control.name[0])     //06-07-12|0x0071
#define FileInExtent(i) &(ProcessFilesFar->input_file[i].extent[0])                       //06-07-12|0x0071
#define FileInPath(i) &(ProcessFilesFar->input_file[i].path[0])                           //06-07-12|0x0071
#define FileInName &(ProcessFilesFar->input_name[0])                                      //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FileOutBufferFileSize ProcessFilesFar->out_buffer_file_size                       //06-07-12|0x0071
#define FileOutBufferFile ProcessFilesFar->out_buffer_file                                //06-07-12|0x0071
#define FileOutBufferFileAddr &(ProcessFilesFar->out_buffer_file)                         //06-07-12|0x0071
//---------------------------------------------------------------------------             //07-11-12|0x0072
#define ErrorMacroChar(i) error_macro.line[i]                                             //07-11-12|0x0073
#define ErrorMacroLine error_macro.line[0]                                                //07-11-12|0x0073
#define ErrorMacroLineAddr &(error_macro.line[0])                                         //07-11-12|0x0073
#define ErrorMacroMacroLineNo error_macro.macro_line_no                                   //07-11-12|0x0073
#define ErrorMacroType error_macro.type                                                   //07-11-12|0x0073
#define ErrorMacroStartCol error_macro.start_col                                          //07-11-12|0x0073
#define ErrorMacroStartCall error_macro.start_call                                        //07-11-12|0x0073
#define ErrorMacroPosition error_macro.position                                           //07-11-12|0x0073
#define ErrorMacroLength error_macro.length                                               //07-11-12|0x0073
#define ErrorMacroColumn error_macro.column                                               //07-11-12|0x0073
//**********************************************************************                  //07-11-12|0x0073
#define ErrorNameChar(i) error_name.line[i]                                               //07-11-12|0x0074
#define ErrorNameLine error_name.line[0]                                                  //07-11-12|0x0074
#define ErrorNameLineAddr &(error_name.line[0])                                           //07-11-12|0x0074
#define ErrorNameMacroLineNo error_name.macro_line_no                                     //07-11-12|0x0074
#define ErrorNameType error_name.type                                                     //07-11-12|0x0074
#define ErrorNameStartCol error_name.start_col                                            //07-11-12|0x0074
#define ErrorNameStartCall error_name.start_call                                          //07-11-12|0x0074
#define ErrorNamePosition error_name.position                                             //07-11-12|0x0074
#define ErrorNameLength error_name.length                                                 //07-11-12|0x0074
#define ErrorNameColumn error_name.column                                                 //07-11-12|0x0074
//**********************************************************************                  //07-11-12|0x0074
#define InitialProcess initial_process()                                                  //06-07-12|0x0076
#define ReadSource read_source(ProcessFilesFar)                                           //06-07-12|0x0076
#define InitialStep initial_step()                                                        //06-07-12|0x0076
#define SourceCall source_call(process_addr)                                              //06-07-12|0x0076
#define ProcDebug PrecDbugCmd(process_addr)                                               //06-07-12|0x0076
#define CheckStack check_stack()                                                          //06-07-12|0x0076
#define ReleaseStack StackRelease()                                                       //06-07-12|0x0076
#define ProcTrace PrecDbugTrace(process_addr)                                             //06-07-12|0x0076
#define CopyToken0(i) MemCpy(i, TokensTokenAddr(0), sizeof(STRING_DATA))                  //06-07-12|0x0076
#define CopyToken0Bridge CopyToken0(ProcessBridgeNameAddr)                                //06-07-12|0x0076
#define CopyToken0Macro CopyToken0(ProcessMacroNameAddr)                                  //06-07-12|0x0076
#define GetBridgeName CallBridgeRead(ProcessBridgeNameAddr)                               //06-07-12|0x0076
#define InitialSearch1(i) MacDictInitialBridge(ProcessBridgeNameAddr, i)                  //06-07-12|0x0076
#define FindInitialBridge InitialSearch1(I_INCLUDE_NAME)                                  //06-07-12|0x0076
#define FindBridge(i,j) MacDictFindBridge(ProcessBridgeNameAddr,i,j)                      //06-07-12|0x0076
#define FindIncludeBridge FindBridge(search_offset, I_INCLUDE_NAME)                       //06-07-12|0x0076
#define FindPublicBridge FindBridge(search_offset, I_PUBLIC_NAME)                         //06-07-12|0x0076
#define FindRegionBridge FindBridge(0, I_BRIDGE_NAME)                                     //06-07-12|0x0076
#define NotFoundMsg Finish("Macro Name Not found")                                        //06-07-12|0x0076
#define DupNameMsg Finish("Duplicate Macro Name found")                                   //06-07-12|0x0076
#define PushSrc1(i) CallSrcPush(ProcessTokensAddr, i, 0)                                  //06-07-12|0x0076
#define PushSrc PushSrc1(ProcessBridgeNameAddr)                                           //06-07-12|0x0076
#define GetClassName MacDictGetClass(ProcessClassNameAddr)                                //06-07-12|0x0076
#define CommitSrcFile FileCommitText(FileSrcFileAddr)                                     //06-07-12|0x0076
#define ReadSrcFile FileReadText(ProcessTokensAddr)                                       //06-07-12|0x0076
#define FindEntry MacDictFindName(TokensTokenAddr(0), MC_ENTRY_NAME)                      //06-07-12|0x0076
#define GetCommand MacDictGet(&ProcessTokens, &ProcessProcessCommand)                     //06-07-12|0x0076
#define ProcCommand1(i) PrecOperProcCmd(process_addr, ProcessFilesFar, i)                 //06-07-12|0x0076
#define ProcCommand ProcCommand1(PcgTokenFar)                                             //06-07-12|0x0076
#define ErrorControl (Error_Control==Continue) ? Success:Error_Control                    //06-07-12|0x0076
#ifndef TestIndex                                                                         //06-07-12|0x0082
#define TestIndex 0                                                                       //06-07-12|0x0082
#endif                                                                                    //06-07-12|0x0082
//------------------------------------------------------------------------                //06-07-12|0x0082
enum {  precsrce_allocate_1 = TestIndex };                                                //06-07-12|0x0082
//------------------------------------------------------------------------                //06-07-12|0x0082
#undef TestIndex                                                                          //06-07-12|0x0082
#define TestIndex precsrce_allocate_1+1                                                   //06-07-12|0x0082
//************************************************************************                //06-07-12|0x0082
#ifndef TestIndex                                                                         //06-07-12|0x009e
#define TestIndex 0                                                                       //06-07-12|0x009e
#endif                                                                                    //06-07-12|0x009e
//------------------------------------------------------------------------                //06-07-12|0x009e
enum {  precsrce_free_1 = TestIndex };                                                    //06-07-12|0x009e
//------------------------------------------------------------------------                //06-07-12|0x009e
#undef TestIndex                                                                          //06-07-12|0x009e
#define TestIndex precsrce_free_1+1                                                       //06-07-12|0x009e
//************************************************************************                //06-07-12|0x009e
#ifndef TestIndex                                                                         //06-09-26|0x0175
#define TestIndex 0                                                                       //06-09-26|0x0175
#endif                                                                                    //06-09-26|0x0175
//------------------------------------------------------------------------                //06-09-26|0x0175
enum {  initial_process_1 = TestIndex };                                                  //06-09-26|0x0175
//------------------------------------------------------------------------                //06-09-26|0x0175
#undef TestIndex                                                                          //06-09-26|0x0175
#define TestIndex initial_process_1+1                                                     //06-09-26|0x0175
//************************************************************************                //06-09-26|0x0175
#ifndef TestIndex                                                                         //06-09-26|0x018f
#define TestIndex 0                                                                       //06-09-26|0x018f
#endif                                                                                    //06-09-26|0x018f
//------------------------------------------------------------------------                //06-09-26|0x018f
enum {  read_source_1 = TestIndex };                                                      //06-09-26|0x018f
//------------------------------------------------------------------------                //06-09-26|0x018f
#undef TestIndex                                                                          //06-09-26|0x018f
#define TestIndex read_source_1+1                                                         //06-09-26|0x018f
//************************************************************************                //06-09-26|0x018f
#ifndef TestIndex                                                                         //06-09-26|0x0190
#define TestIndex 0                                                                       //06-09-26|0x0190
#endif                                                                                    //06-09-26|0x0190
//------------------------------------------------------------------------                //06-09-26|0x0190
enum {  read_source_2 = TestIndex };                                                      //06-09-26|0x0190
//------------------------------------------------------------------------                //06-09-26|0x0190
#undef TestIndex                                                                          //06-09-26|0x0190
#define TestIndex read_source_2+1                                                         //06-09-26|0x0190
//************************************************************************                //06-09-26|0x0190
#ifndef TestIndex                                                                         //06-09-26|0x0191
#define TestIndex 0                                                                       //06-09-26|0x0191
#endif                                                                                    //06-09-26|0x0191
//------------------------------------------------------------------------                //06-09-26|0x0191
enum {  read_source_3 = TestIndex };                                                      //06-09-26|0x0191
//------------------------------------------------------------------------                //06-09-26|0x0191
#undef TestIndex                                                                          //06-09-26|0x0191
#define TestIndex read_source_3+1                                                         //06-09-26|0x0191
//************************************************************************                //06-09-26|0x0191
#ifndef TestIndex                                                                         //06-09-26|0x0192
#define TestIndex 0                                                                       //06-09-26|0x0192
#endif                                                                                    //06-09-26|0x0192
//------------------------------------------------------------------------                //06-09-26|0x0192
enum {  read_source_4 = TestIndex };                                                      //06-09-26|0x0192
//------------------------------------------------------------------------                //06-09-26|0x0192
#undef TestIndex                                                                          //06-09-26|0x0192
#define TestIndex read_source_4+1                                                         //06-09-26|0x0192
//************************************************************************                //06-09-26|0x0192
#ifndef TestIndex                                                                         //06-09-26|0x01ba
#define TestIndex 0                                                                       //06-09-26|0x01ba
#endif                                                                                    //06-09-26|0x01ba
//------------------------------------------------------------------------                //06-09-26|0x01ba
enum {  initial_step_1 = TestIndex };                                                     //06-09-26|0x01ba
//------------------------------------------------------------------------                //06-09-26|0x01ba
#undef TestIndex                                                                          //06-09-26|0x01ba
#define TestIndex initial_step_1+1                                                        //06-09-26|0x01ba
//************************************************************************                //06-09-26|0x01ba
#ifndef TestIndex                                                                         //06-10-09|0x01d8
#define TestIndex 0                                                                       //06-10-09|0x01d8
#endif                                                                                    //06-10-09|0x01d8
//------------------------------------------------------------------------                //06-10-09|0x01d8
enum {  check_stack_1 = TestIndex };                                                      //06-10-09|0x01d8
//------------------------------------------------------------------------                //06-10-09|0x01d8
#undef TestIndex                                                                          //06-10-09|0x01d8
#define TestIndex check_stack_1+1                                                         //06-10-09|0x01d8
//************************************************************************                //06-10-09|0x01d8
#ifndef TestIndex                                                                         //06-10-09|0x01d9
#define TestIndex 0                                                                       //06-10-09|0x01d9
#endif                                                                                    //06-10-09|0x01d9
//------------------------------------------------------------------------                //06-10-09|0x01d9
enum {  check_stack_2 = TestIndex };                                                      //06-10-09|0x01d9
//------------------------------------------------------------------------                //06-10-09|0x01d9
#undef TestIndex                                                                          //06-10-09|0x01d9
#define TestIndex check_stack_2+1                                                         //06-10-09|0x01d9
//************************************************************************                //06-10-09|0x01d9
//*******************************************************************************         //05-24-97|0x021e
//*******************************************************************************         //05-24-97|0x021e
//****                       END OF FILE                                     ****         //05-24-97|0x021e
//*******************************************************************************         //05-24-97|0x021e
//*******************************************************************************         //05-24-97|0x021e
#endif                                                                                    //05-24-97|0x021e
