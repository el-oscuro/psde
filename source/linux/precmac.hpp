//*****************************************************************************           //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
// MACRO ENTRY SUB-SYSTEM                                                                 //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x001d
//  defined in the associated manual.                                                     //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x001d
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x001d
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x001d
//  (at your option) any later version.                                                   //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x001d
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x001d
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x001d
//  GNU General Public License for more details.                                          //06-07-12|0x001d
//                                                                                        //06-07-12|0x001d
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x001d
//  along with this program; if not, write to the Free Software                           //06-07-12|0x001d
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x001d
//  USA                                                                                   //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//  For further information, please contact Robert Adams:                                 //06-07-12|0x001d
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x001d
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x001d
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
//*****************************************************************************           //06-07-12|0x001d
#ifndef precmac_hpp                                                                       //06-07-12|0x001e
#define precmac_hpp                                                                       //06-07-12|0x001e
//***************************************************************************             //06-07-12|0x0028
//***************************************************************************             //06-07-12|0x0029
//******                                                               ******             //06-07-12|0x002a
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x002b
//******                                                               ******             //06-07-12|0x002c
//***************************************************************************             //06-07-12|0x002d
//***************************************************************************             //06-07-12|0x002e
//***************************************************************************             //06-07-12|0x0031
//***************************************************************************             //06-07-12|0x0032
//******                                                               ******             //06-07-12|0x0033
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x0034
//******                                                               ******             //06-07-12|0x0035
//***************************************************************************             //06-07-12|0x0036
//***************************************************************************             //06-07-12|0x0037
#define UserError 0x0000                                                                  //06-07-12|0x0038
#define BuildError 0x7fff                                                                 //06-07-12|0x0038
#define Display 0x7ffe                                                                    //06-07-12|0x0038
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x0038
#define Success 0xffff                                                                    //06-07-12|0x0038
#define SystemError 0x8000                                                                //06-07-12|0x0038
#define Continue 0x0001                                                                   //06-07-12|0x0038
#define FileDone 0x0002                                                                   //06-07-12|0x0038
#define LineDone 0x0003                                                                   //06-07-12|0x0038
#define Yes 0x0004                                                                        //06-07-12|0x0038
#define No 0x0005                                                                         //06-07-12|0x0038
#define RepeatChar '\x6'                                                                  //06-07-12|0x0038
#define Great 0x0007                                                                      //06-07-12|0x0038
#define Equal 0x0008                                                                      //06-07-12|0x0038
#define Less 0x0009                                                                       //06-07-12|0x0038
#define Zero 0x000a                                                                       //06-07-12|0x0038
#define Minus 0x000b                                                                      //06-07-12|0x0038
//***************************************************************************             //06-07-12|0x0039
#define SystemMsg PcgSystemError("precmac", __LINE__);                                    //06-07-12|0x003a
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x003a
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x003a
#define DebugBreakpoint1 Breakpoint("precmac", __LINE__)                                  //<----   |0x003b
#define DebugBreakpoint if(DebugBreakpoint1 != Success) ReturnSystemError                 //<----   |0x003b
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x003c
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x003c
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x003c
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x003c
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x003d
#define _SwitchOk case Success: break                                                     //06-07-12|0x003d
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x003d
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x003d
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x003d
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x003d
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x003d
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x003d
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x003d
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x003d
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x003d
//***************************************************************************             //06-07-12|0x005c
//***************************************************************************             //06-07-12|0x005d
//******                                                               ******             //06-07-12|0x005e
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x005f
//******                                                               ******             //06-07-12|0x0060
//***************************************************************************             //06-07-12|0x0061
//***************************************************************************             //06-07-12|0x0062
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x0063
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x0063
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x0063
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x0063
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-12|0x0063
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-12|0x0063
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x0063
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x0063
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x0063
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x0063
//************************************************************************                //06-07-12|0x0063
#ifndef TestIndex                                                                         //06-07-12|0x0063
#define TestIndex 0                                                                       //06-07-12|0x0063
#endif                                                                                    //06-07-12|0x0063
//------------------------------------------------------------------------                //06-07-12|0x0063
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x0063
//------------------------------------------------------------------------                //06-07-12|0x0063
#undef TestIndex                                                                          //06-07-12|0x0063
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x0063
//************************************************************************                //06-07-12|0x0063
//***************************************************************************             //06-07-12|0x0064
//**********************************************************************                  //06-07-12|0x0065
#define MacroRuleState macro_data_addr->rule_state                                        //06-07-12|0x0065
#define MacroLabelState macro_data_addr->label_state                                      //06-07-12|0x0065
#define MacroControlState macro_data_addr->control_state                                  //06-07-12|0x0065
#define MacroCommandState macro_data_addr->command_state                                  //06-07-12|0x0065
#define MacroProcessState macro_data_addr->process_state                                  //06-07-12|0x0065
#define MacroBridgeState macro_data_addr->bridge_state                                    //06-07-12|0x0065
#define MacroRunFlag macro_data_addr->run_flag                                            //06-07-12|0x0065
#define MacroStatus macro_data_addr->status                                               //06-07-12|0x0065
#define MacroTokens macro_data_addr->tokens                                               //06-07-12|0x0065
#define MacroMacroName macro_data_addr->macro_name                                        //06-07-12|0x0065
#define MacroClassName macro_data_addr->class_name                                        //06-07-12|0x0065
#define MacroUtilityBridge macro_data_addr->utility_bridge                                //06-07-12|0x0065
#define MacroLabel macro_data_addr->label                                                 //06-07-12|0x0065
//----------------------------------------------------------------------                  //06-07-12|0x0065
#define MacroClassNameAddr &(macro_data_addr->class_name)                                 //06-07-12|0x0065
#define MacroUtilityBridgeAddr &(macro_data_addr->utility_bridge)                         //06-07-12|0x0065
#define MacroTokensAddr &(macro_data_addr->tokens)                                        //06-07-12|0x0065
#define MacroMacroNameAddr &(macro_data_addr->macro_name)                                 //06-07-12|0x0065
#define MacroLabelAddr &(macro_data_addr->label)                                          //06-07-12|0x0065
//************************************************************************                //06-07-12|0x0066
#define TokensTokenAddr(i) &(MacroTokens.token[i])                                        //06-07-12|0x0066
#define TokensMacroLineNo(i) MacroTokens.token[i].macro_line_no                           //06-07-12|0x0066
#define TokensLineAddr(i) &(MacroTokens.token[i].line[0])                                 //06-07-12|0x0066
#define TokensToken(i) MacroTokens.token[i]                                               //06-07-12|0x0066
#define TokensLine(i) MacroTokens.token[i].line                                           //06-07-12|0x0066
#define TokensLength(i) MacroTokens.token[i].length                                       //06-07-12|0x0066
#define TokensColumn(i) MacroTokens.token[i].column                                       //06-07-12|0x0066
#define TokensHash(i) MacroTokens.token[i].hash                                           //06-07-12|0x0066
#define TokensPosition(i) MacroTokens.token[i].position                                   //06-07-12|0x0066
#define TokensType(i) MacroTokens.token[i].type                                           //06-07-12|0x0066
#define TokensStartCol(i) MacroTokens.token[i].start_col                                  //06-07-12|0x0066
#define TokensStartCall(i) MacroTokens.token[i].start_call                                //06-07-12|0x0066
#define TokensChar(i,j) MacroTokens.token[i].line[j]                                      //06-07-12|0x0066
#define TokensNoTokens MacroTokens.no_tokens                                              //06-07-12|0x0066
//************************************************************************                //06-07-12|0x0067
#define CopyOutTokenAddr(i) &(MacroCopyOut.token[i])                                      //06-07-12|0x0067
#define CopyOutMacroLineNo(i) MacroCopyOut.token[i].macro_line_no                         //06-07-12|0x0067
#define CopyOutLineAddr(i) &(MacroCopyOut.token[i].line[0])                               //06-07-12|0x0067
#define CopyOutToken(i) MacroCopyOut.token[i]                                             //06-07-12|0x0067
#define CopyOutLine(i) MacroCopyOut.token[i].line                                         //06-07-12|0x0067
#define CopyOutLength(i) MacroCopyOut.token[i].length                                     //06-07-12|0x0067
#define CopyOutColumn(i) MacroCopyOut.token[i].column                                     //06-07-12|0x0067
#define CopyOutHash(i) MacroCopyOut.token[i].hash                                         //06-07-12|0x0067
#define CopyOutPosition(i) MacroCopyOut.token[i].position                                 //06-07-12|0x0067
#define CopyOutType(i) MacroCopyOut.token[i].type                                         //06-07-12|0x0067
#define CopyOutStartCol(i) MacroCopyOut.token[i].start_col                                //06-07-12|0x0067
#define CopyOutStartCall(i) MacroCopyOut.token[i].start_call                              //06-07-12|0x0067
#define CopyOutChar(i,j) MacroCopyOut.token[i].line[j]                                    //06-07-12|0x0067
#define CopyOutNoTokens MacroCopyOut.no_tokens                                            //06-07-12|0x0067
#define MacroNameChar(i) MacroMacroName.line[i]                                           //06-07-12|0x0068
#define MacroNameLine MacroMacroName.line[0]                                              //06-07-12|0x0068
#define MacroNameLineAddr &(MacroMacroName.line[0])                                       //06-07-12|0x0068
#define MacroNameMacroLineNo MacroMacroName.macro_line_no                                 //06-07-12|0x0068
#define MacroNameType MacroMacroName.type                                                 //06-07-12|0x0068
#define MacroNameStartCol MacroMacroName.start_col                                        //06-07-12|0x0068
#define MacroNameStartCall MacroMacroName.start_call                                      //06-07-12|0x0068
#define MacroNamePosition MacroMacroName.position                                         //06-07-12|0x0068
#define MacroNameLength MacroMacroName.length                                             //06-07-12|0x0068
#define MacroNameColumn MacroMacroName.column                                             //06-07-12|0x0068
//**********************************************************************                  //06-07-12|0x0068
#define LabelChar(i) MacroLabel.line[i]                                                   //06-07-12|0x0069
#define LabelLine MacroLabel.line[0]                                                      //06-07-12|0x0069
#define LabelLineAddr &(MacroLabel.line[0])                                               //06-07-12|0x0069
#define LabelMacroLineNo MacroLabel.macro_line_no                                         //06-07-12|0x0069
#define LabelType MacroLabel.type                                                         //06-07-12|0x0069
#define LabelStartCol MacroLabel.start_col                                                //06-07-12|0x0069
#define LabelStartCall MacroLabel.start_call                                              //06-07-12|0x0069
#define LabelPosition MacroLabel.position                                                 //06-07-12|0x0069
#define LabelLength MacroLabel.length                                                     //06-07-12|0x0069
#define LabelColumn MacroLabel.column                                                     //06-07-12|0x0069
//**********************************************************************                  //06-07-12|0x0069
#define ClassNameChar(i) MacroClassName.line[i]                                           //07-05-22|0x006a
#define ClassNameLine MacroClassName.line[0]                                              //07-05-22|0x006a
#define ClassNameLineAddr &(MacroClassName.line[0])                                       //07-05-22|0x006a
#define ClassNameMacroLineNo MacroClassName.macro_line_no                                 //07-05-22|0x006a
#define ClassNameType MacroClassName.type                                                 //07-05-22|0x006a
#define ClassNameStartCol MacroClassName.start_col                                        //07-05-22|0x006a
#define ClassNameStartCall MacroClassName.start_call                                      //07-05-22|0x006a
#define ClassNamePosition MacroClassName.position                                         //07-05-22|0x006a
#define ClassNameLength MacroClassName.length                                             //07-05-22|0x006a
#define ClassNameColumn MacroClassName.column                                             //07-05-22|0x006a
//**********************************************************************                  //07-05-22|0x006a
#define UtilityBridgeChar(i) MacroUtilityBridge.line[i]                                   //07-05-22|0x006b
#define UtilityBridgeLine MacroUtilityBridge.line[0]                                      //07-05-22|0x006b
#define UtilityBridgeLineAddr &(MacroUtilityBridge.line[0])                               //07-05-22|0x006b
#define UtilityBridgeMacroLineNo MacroUtilityBridge.macro_line_no                         //07-05-22|0x006b
#define UtilityBridgeType MacroUtilityBridge.type                                         //07-05-22|0x006b
#define UtilityBridgeStartCol MacroUtilityBridge.start_col                                //07-05-22|0x006b
#define UtilityBridgeStartCall MacroUtilityBridge.start_call                              //07-05-22|0x006b
#define UtilityBridgePosition MacroUtilityBridge.position                                 //07-05-22|0x006b
#define UtilityBridgeLength MacroUtilityBridge.length                                     //07-05-22|0x006b
#define UtilityBridgeColumn MacroUtilityBridge.column                                     //07-05-22|0x006b
//**********************************************************************                  //07-05-22|0x006b
//---------------------------------------------------------------------------             //06-07-12|0x006c
//**********************************************************************                  //11-02-14|0x006d
#define MacroDevelopDevelopStatus MacroDevelopAddr->develop_status                        //11-02-14|0x006d
#define MacroDevelopMacroFile MacroDevelopAddr->macro_file                                //11-02-14|0x006d
#define MacroDevelopInTime MacroDevelopAddr->in_time                                      //11-02-14|0x006d
//----------------------------------------------------------------------                  //11-02-14|0x006d
#define MacroDevelopMacroFileAddr &(MacroDevelopAddr->macro_file)                         //11-02-14|0x006d
#define MacroDevelopInTimeAddr &(MacroDevelopAddr->in_time)                               //11-02-14|0x006d
//**********************************************************************                  //11-02-14|0x006e
#define MacFileFileControl MacroDevelopMacroFile.file_control                             //11-02-14|0x006e
#define MacFileString MacroDevelopMacroFile.string                                        //11-02-14|0x006e
#define MacFileLineNo MacroDevelopMacroFile.line_no                                       //11-02-14|0x006e
#define MacFileLength MacroDevelopMacroFile.length                                        //11-02-14|0x006e
#define MacFileNextPos MacroDevelopMacroFile.next_position                                //11-02-14|0x006e
#define MacFileReadState MacroDevelopMacroFile.read_state                                 //11-02-14|0x006e
#define MacFileGetState MacroDevelopMacroFile.get_state                                   //11-02-14|0x006e
#define MacFilePutState MacroDevelopMacroFile.put_state                                   //11-02-14|0x006e
#define MacFileStatus MacroDevelopMacroFile.status                                        //11-02-14|0x006e
#define MacFileRunFlag MacroDevelopMacroFile.run_flag                                     //11-02-14|0x006e
//----------------------------------------------------------------------                  //11-02-14|0x006e
#define MacFileStringAddr &(MacroDevelopMacroFile.string)                                 //11-02-14|0x006e
//---------------------------------------------------------------------------             //06-07-12|0x006f
#define ReportChar(i) report_line.line[i]                                                 //11-02-14|0x0070
#define ReportLine report_line.line[0]                                                    //11-02-14|0x0070
#define ReportLineAddr &(report_line.line[0])                                             //11-02-14|0x0070
#define ReportMacroLineNo report_line.macro_line_no                                       //11-02-14|0x0070
#define ReportType report_line.type                                                       //11-02-14|0x0070
#define ReportStartCol report_line.start_col                                              //11-02-14|0x0070
#define ReportStartCall report_line.start_call                                            //11-02-14|0x0070
#define ReportPosition report_line.position                                               //11-02-14|0x0070
#define ReportLength report_line.length                                                   //11-02-14|0x0070
#define ReportColumn report_line.column                                                   //11-02-14|0x0070
//**********************************************************************                  //11-02-14|0x0070
#define StrDataCpy(i,j) MemCpy(i,j,sizeof(STRING_DATA))                                   //06-07-12|0x0072
#define OpenMacro open_macro(MacroDevelopAddr)                                            //06-07-12|0x0072
#define ReadMacro read_macro(MacroDevelopAddr)                                            //06-07-12|0x0072
#define CloseMacro close_macro(MacroDevelopAddr)                                          //06-07-12|0x0072
#define CommitMacFile FileCommitText(MacroDevelopMacroFileAddr)                           //06-07-12|0x0072
#define BeginCommand begin_command("_BEGIN", 4)                                           //06-07-12|0x0072
#define PublicCommand begin_command("_PUBLIC", 4)                                         //06-07-12|0x0072
#define PrivateCommand begin_command("_PRIVATE", 4)                                       //06-07-12|0x0072
#define IncludeCommand begin_command("_INCLUDE", 2)                                       //06-07-12|0x0072
#define BeginReport begin_report(MacroDevelopAddr, "REGIONAL MACRO: ")                    //06-07-12|0x0072
#define PublicReport begin_report(MacroDevelopAddr, "PUBLIC MACRO:   ")                   //06-07-12|0x0072
#define PrivateReport begin_report(MacroDevelopAddr, "PRIVATE MACRO:  ")                  //06-07-12|0x0072
#define BasicParity basic_parity(MacroDevelopAddr)                                        //06-07-12|0x0072
#define LoadBridge2(i,j) MacDictLoadBridge(i, j)                                          //06-07-12|0x0072
#define BeginLoadRegion LoadBridge2(MacroMacroNameAddr,I_BRIDGE_NAME)                     //06-07-12|0x0072
#define BeginLoadPublic LoadBridge2(MacroMacroNameAddr,I_PUBLIC_NAME)                     //06-07-12|0x0072
#define BeginLoadInclude LoadBridge2(MacroMacroNameAddr,I_INCLUDE_NAME)                   //06-07-12|0x0072
#define BeginLoadDummy LoadBridge2(MacroMacroNameAddr,I_NAME)                             //06-07-12|0x0072
#define BeginLoadUtility LoadBridge2(MacroUtilityBridgeAddr,I_UTILITY_NAME)               //06-07-12|0x0072
#define Bridge2(i,j) MacDictCheckDupName(i,j)                                             //06-07-12|0x0072
#define Bridge11(i) Bridge2(MacroUtilityBridgeAddr,i)                                     //06-07-12|0x0072
#define Bridge12(i) Bridge2(MacroMacroNameAddr,i)                                         //06-07-12|0x0072
#define FindIncBridge Bridge12(I_INCLUDE_NAME)                                            //06-07-12|0x0072
#define FindUtilBridge Bridge11(I_UTILITY_NAME)                                           //06-07-12|0x0072
#define FindPubBridge Bridge12(I_PUBLIC_NAME)                                             //06-07-12|0x0072
#define BeginLoadCommand begin_load_command(MacroDevelopAddr)                             //06-07-12|0x0072
#define MissingBegin Finish("Missing Begin, Public, Private, Include")                    //06-07-12|0x0072
#define DuplicateName Finish("Duplicate Macro Name")                                      //06-07-12|0x0072
#define IllegalFileEnd Finish("Illegal End of File")                                      //06-07-12|0x0072
#define MissingJump Finish("Missing Conditional Jump")                                    //06-07-12|0x0072
#define MissingLabel Finish("Missing Label")                                              //06-07-12|0x0072
#define IllegalRule Finish("Illegal Rule Command")                                        //06-07-12|0x0072
#define CmdTest(i) StrCmp(TokensLineAddr(0),i)                                            //06-07-12|0x0072
#define TestArgs(i,j) (TokensNoTokens<i) || (TokensNoTokens>j)                            //06-07-12|0x0072
#define MacCopy StrDataCpy(MacroMacroNameAddr,TokensTokenAddr(1))                         //06-07-12|0x0072
#define BeginMacro MacDictLoadName(TokensTokenAddr(1), MC_ENTRY_NAME)                     //06-07-12|0x0072
#define LoadLabel MacDictLoadName(MacroLabelAddr, MC_LABEL_NAME)                          //06-07-12|0x0072
#define MacBridge precmac_bridge(MacroDevelopAddr)                                        //06-07-12|0x0072
#define MacCommand precmac_command(MacroDevelopAddr)                                      //06-07-12|0x0072
#define MacControl precmac_control(MacroDevelopAddr)                                      //06-07-12|0x0072
#define MacLabel precmac_label(MacroDevelopAddr)                                          //06-07-12|0x0072
#define MacRule precmac_rule(MacroDevelopAddr)                                            //06-07-12|0x0072
#define EnterCmd(i) enter_command(MacroDevelopAddr, i)                                    //06-07-12|0x0072
#define EnterCall EnterCmd(I_CALL)                                                        //06-07-12|0x0072
#define LoadLabelCommand load_label_command(MacroDevelopAddr)                             //06-07-12|0x0072
#define LoadLabelName load_label_name(MacroDevelopAddr)                                   //06-07-12|0x0072
#define LoadCmd(i,j,k,l) load_command(MacroDevelopAddr,i,j,k,l)                           //06-07-12|0x0072
#define PremacBreakPnt(i) Breakpoint("precmac", i)                                        //06-07-12|0x0072
#ifndef TestIndex                                                                         //06-09-04|0x007d
#define TestIndex 0                                                                       //06-09-04|0x007d
#endif                                                                                    //06-09-04|0x007d
//------------------------------------------------------------------------                //06-09-04|0x007d
enum {  load_command_1 = TestIndex };                                                     //06-09-04|0x007d
//------------------------------------------------------------------------                //06-09-04|0x007d
#undef TestIndex                                                                          //06-09-04|0x007d
#define TestIndex load_command_1+1                                                        //06-09-04|0x007d
//************************************************************************                //06-09-04|0x007d
#ifndef TestIndex                                                                         //06-09-04|0x007e
#define TestIndex 0                                                                       //06-09-04|0x007e
#endif                                                                                    //06-09-04|0x007e
//------------------------------------------------------------------------                //06-09-04|0x007e
enum {  load_command_2 = TestIndex };                                                     //06-09-04|0x007e
//------------------------------------------------------------------------                //06-09-04|0x007e
#undef TestIndex                                                                          //06-09-04|0x007e
#define TestIndex load_command_2+1                                                        //06-09-04|0x007e
//************************************************************************                //06-09-04|0x007e
#ifndef TestIndex                                                                         //06-07-12|0x00a1
#define TestIndex 0                                                                       //06-07-12|0x00a1
#endif                                                                                    //06-07-12|0x00a1
//------------------------------------------------------------------------                //06-07-12|0x00a1
enum {  precmac_allocate_1 = TestIndex };                                                 //06-07-12|0x00a1
//------------------------------------------------------------------------                //06-07-12|0x00a1
#undef TestIndex                                                                          //06-07-12|0x00a1
#define TestIndex precmac_allocate_1+1                                                    //06-07-12|0x00a1
//************************************************************************                //06-07-12|0x00a1
#ifndef TestIndex                                                                         //06-07-12|0x00c0
#define TestIndex 0                                                                       //06-07-12|0x00c0
#endif                                                                                    //06-07-12|0x00c0
//------------------------------------------------------------------------                //06-07-12|0x00c0
enum {  precmac_free_1 = TestIndex };                                                     //06-07-12|0x00c0
//------------------------------------------------------------------------                //06-07-12|0x00c0
#undef TestIndex                                                                          //06-07-12|0x00c0
#define TestIndex precmac_free_1+1                                                        //06-07-12|0x00c0
//************************************************************************                //06-07-12|0x00c0
#define MacCmd_BEGIN_Error error_command("_BEGIN")                                        //07-04-25|0x016c
#define MacCmd_PUBLIC_Error error_command("_PUBLIC")                                      //07-04-25|0x016e
#define MacCmd_PRIVATE_Error error_command("_PRIVATE")                                    //07-04-25|0x0170
#define MacCmd_INCLUDE_Error error_command("_INCLUDE")                                    //07-05-22|0x0172
#define MacCmd_END end_command(MacroDevelopAddr)                                          //06-12-01|0x0174
#define MacCmdLOAD_BUFFER3(i,j,k) LoadCmd("_LOAD_BUFFER",i,j,k)                           //07-02-17|0x017a
#define MacCmdLOAD_BUFFER2(j,k) MacCmdLOAD_BUFFER3(I_LOAD_BUFFER,j,k)                     //07-02-17|0x017a
#define MacCmdLOAD_BUFFER1(k) MacCmdLOAD_BUFFER2(2,k)                                     //07-02-17|0x017a
#define MacCmd_LOAD_BUFFER MacCmdLOAD_BUFFER1(2)                                          //07-02-17|0x017a
#define MacCmdAPPEND_BUFFER3(i,j,k) LoadCmd("_APPEND_BUFFER",i,j,k)                       //07-09-11|0x017b
#define MacCmdAPPEND_BUFFER2(j,k) MacCmdAPPEND_BUFFER3(I_APPEND_BUFFER,j,k)               //07-09-11|0x017b
#define MacCmdAPPEND_BUFFER1(k) MacCmdAPPEND_BUFFER2(2,k)                                 //07-09-11|0x017b
#define MacCmd_APPEND_BUFFER MacCmdAPPEND_BUFFER1(2)                                      //07-09-11|0x017b
#define MacCmdWRITE_BUFFER3(i,j,k) LoadCmd("_WRITE_BUFFER",i,j,k)                         //07-02-17|0x017c
#define MacCmdWRITE_BUFFER2(j,k) MacCmdWRITE_BUFFER3(I_WRITE_BUFFER,j,k)                  //07-02-17|0x017c
#define MacCmdWRITE_BUFFER1(k) MacCmdWRITE_BUFFER2(2,k)                                   //07-02-17|0x017c
#define MacCmd_WRITE_BUFFER MacCmdWRITE_BUFFER1(2)                                        //07-02-17|0x017c
#define MacCmdWRITE_OUT3(i,j,k) LoadCmd("_WRITE_OUT",i,j,k)                               //08-01-14|0x017e
#define MacCmdWRITE_OUT2(j,k) MacCmdWRITE_OUT3(I_WRITE_OUT,j,k)                           //08-01-14|0x017e
#define MacCmdWRITE_OUT1(k) MacCmdWRITE_OUT2(3,k)                                         //08-01-14|0x017e
#define MacCmd_WRITE_OUT MacCmdWRITE_OUT1(3)                                              //08-01-14|0x017e
#define MacCmdOUT_BASE_NAME3(i,j,k) LoadCmd("_OUT_BASE_NAME",i,j,k)                       //08-01-14|0x0180
#define MacCmdOUT_BASE_NAME2(j,k) MacCmdOUT_BASE_NAME3(I_OUT_BASE_NAME,j,k)               //08-01-14|0x0180
#define MacCmdOUT_BASE_NAME1(k) MacCmdOUT_BASE_NAME2(2,k)                                 //08-01-14|0x0180
#define MacCmd_OUT_BASE_NAME MacCmdOUT_BASE_NAME1(2)                                      //08-01-14|0x0180
#define MacCmdOUT_NAME3(i,j,k) LoadCmd("_OUT_NAME",i,j,k)                                 //08-01-14|0x0181
#define MacCmdOUT_NAME2(j,k) MacCmdOUT_NAME3(I_OUT_NAME,j,k)                              //08-01-14|0x0181
#define MacCmdOUT_NAME1(k) MacCmdOUT_NAME2(3,k)                                           //08-01-14|0x0181
#define MacCmd_OUT_NAME MacCmdOUT_NAME1(3)                                                //08-01-14|0x0181
#define MacCmdOUT_PATH3(i,j,k) LoadCmd("_OUT_PATH",i,j,k)                                 //08-01-14|0x0182
#define MacCmdOUT_PATH2(j,k) MacCmdOUT_PATH3(I_OUT_PATH,j,k)                              //08-01-14|0x0182
#define MacCmdOUT_PATH1(k) MacCmdOUT_PATH2(3,k)                                           //08-01-14|0x0182
#define MacCmd_OUT_PATH MacCmdOUT_PATH1(3)                                                //08-01-14|0x0182
#define MacCmdOUT_EXTENT3(i,j,k) LoadCmd("_OUT_EXTENT",i,j,k)                             //08-01-14|0x0183
#define MacCmdOUT_EXTENT2(j,k) MacCmdOUT_EXTENT3(I_OUT_EXTENT,j,k)                        //08-01-14|0x0183
#define MacCmdOUT_EXTENT1(k) MacCmdOUT_EXTENT2(3,k)                                       //08-01-14|0x0183
#define MacCmd_OUT_EXTENT MacCmdOUT_EXTENT1(3)                                            //08-01-14|0x0183
#define MacCmdOUT_LINE_NO3(i,j,k) LoadCmd("_OUT_LINE_NO",i,j,k)                           //08-01-14|0x0184
#define MacCmdOUT_LINE_NO2(j,k) MacCmdOUT_LINE_NO3(I_OUT_LINE_NO,j,k)                     //08-01-14|0x0184
#define MacCmdOUT_LINE_NO1(k) MacCmdOUT_LINE_NO2(3,k)                                     //08-01-14|0x0184
#define MacCmd_OUT_LINE_NO MacCmdOUT_LINE_NO1(3)                                          //08-01-14|0x0184
#define MacCmdSOURCE_LINE_NO3(i,j,k) LoadCmd("_SOURCE_LINE_NO",i,j,k)                     //06-10-06|0x0186
#define MacCmdSOURCE_LINE_NO2(j,k) MacCmdSOURCE_LINE_NO3(I_SOURCE_LINE_NO,j,k)            //06-10-06|0x0186
#define MacCmdSOURCE_LINE_NO1(k) MacCmdSOURCE_LINE_NO2(2,k)                               //06-10-06|0x0186
#define MacCmd_SOURCE_LINE_NO MacCmdSOURCE_LINE_NO1(2)                                    //06-10-06|0x0186
#define MacCmdSOURCE_NAME3(i,j,k) LoadCmd("_SOURCE_NAME",i,j,k)                           //07-11-01|0x0187
#define MacCmdSOURCE_NAME2(j,k) MacCmdSOURCE_NAME3(I_SOURCE_NAME,j,k)                     //07-11-01|0x0187
#define MacCmdSOURCE_NAME1(k) MacCmdSOURCE_NAME2(2,k)                                     //07-11-01|0x0187
#define MacCmd_SOURCE_NAME MacCmdSOURCE_NAME1(2)                                          //07-11-01|0x0187
#define MacCmdGET_TAB3(i,j,k) LoadCmd("_GET_TAB",i,j,k)                                   //07-09-11|0x0189
#define MacCmdGET_TAB2(j,k) MacCmdGET_TAB3(I_GET_TAB,j,k)                                 //07-09-11|0x0189
#define MacCmdGET_TAB1(k) MacCmdGET_TAB2(2,k)                                             //07-09-11|0x0189
#define MacCmd_GET_TAB MacCmdGET_TAB1(2)                                                  //07-09-11|0x0189
#define MacCmdNO_OUT_FILES3(i,j,k) LoadCmd("_NO_OUT_FILES",i,j,k)                         //07-09-11|0x018a
#define MacCmdNO_OUT_FILES2(j,k) MacCmdNO_OUT_FILES3(I_NO_OUT_FILES,j,k)                  //07-09-11|0x018a
#define MacCmdNO_OUT_FILES1(k) MacCmdNO_OUT_FILES2(2,k)                                   //07-09-11|0x018a
#define MacCmd_NO_OUT_FILES MacCmdNO_OUT_FILES1(2)                                        //07-09-11|0x018a
#define MacCmdREAD_TEXT3(i,j,k) LoadCmd("_READ_TEXT",i,j,k)                               //10-05-16|0x018c
#define MacCmdREAD_TEXT2(j,k) MacCmdREAD_TEXT3(I_READ_TEXT,j,k)                           //10-05-16|0x018c
#define MacCmdREAD_TEXT1(k) MacCmdREAD_TEXT2(3,k)                                         //10-05-16|0x018c
#define MacCmd_READ_TEXT MacCmdREAD_TEXT1(3)                                              //10-05-16|0x018c
#define MacCmdSTATE_READ_TEXT3(i,j,k) LoadCmd("_STATE_READ_TEXT",i,j,k)                   //10-05-16|0x018d
#define MacCmdSTATE_READ_TEXT2(j,k) MacCmdSTATE_READ_TEXT3(I_STATE_READ_TEXT,j,k)         //10-05-16|0x018d
#define MacCmdSTATE_READ_TEXT1(k) MacCmdSTATE_READ_TEXT2(2,k)                             //10-05-16|0x018d
#define MacCmd_STATE_READ_TEXT MacCmdSTATE_READ_TEXT1(2)                                  //10-05-16|0x018d
#define MacCmdTEXT_BASE_NAME3(i,j,k) LoadCmd("_TEXT_BASE_NAME",i,j,k)                     //11-02-14|0x018e
#define MacCmdTEXT_BASE_NAME2(j,k) MacCmdTEXT_BASE_NAME3(I_TEXT_BASE_NAME,j,k)            //11-02-14|0x018e
#define MacCmdTEXT_BASE_NAME1(k) MacCmdTEXT_BASE_NAME2(2,k)                               //11-02-14|0x018e
#define MacCmd_TEXT_BASE_NAME MacCmdTEXT_BASE_NAME1(2)                                    //11-02-14|0x018e
#define MacCmdTEXT_NAME3(i,j,k) LoadCmd("_TEXT_NAME",i,j,k)                               //11-02-14|0x018f
#define MacCmdTEXT_NAME2(j,k) MacCmdTEXT_NAME3(I_TEXT_NAME,j,k)                           //11-02-14|0x018f
#define MacCmdTEXT_NAME1(k) MacCmdTEXT_NAME2(3,k)                                         //11-02-14|0x018f
#define MacCmd_TEXT_NAME MacCmdTEXT_NAME1(3)                                              //11-02-14|0x018f
#define MacCmdTEXT_PATH3(i,j,k) LoadCmd("_TEXT_PATH",i,j,k)                               //11-02-14|0x0190
#define MacCmdTEXT_PATH2(j,k) MacCmdTEXT_PATH3(I_TEXT_PATH,j,k)                           //11-02-14|0x0190
#define MacCmdTEXT_PATH1(k) MacCmdTEXT_PATH2(3,k)                                         //11-02-14|0x0190
#define MacCmd_TEXT_PATH MacCmdTEXT_PATH1(3)                                              //11-02-14|0x0190
#define MacCmdTEXT_EXTENT3(i,j,k) LoadCmd("_TEXT_EXTENT",i,j,k)                           //11-02-14|0x0191
#define MacCmdTEXT_EXTENT2(j,k) MacCmdTEXT_EXTENT3(I_TEXT_EXTENT,j,k)                     //11-02-14|0x0191
#define MacCmdTEXT_EXTENT1(k) MacCmdTEXT_EXTENT2(3,k)                                     //11-02-14|0x0191
#define MacCmd_TEXT_EXTENT MacCmdTEXT_EXTENT1(3)                                          //11-02-14|0x0191
#define MacCmdTEXT_LINE_NO3(i,j,k) LoadCmd("_TEXT_LINE_NO",i,j,k)                         //10-05-16|0x0192
#define MacCmdTEXT_LINE_NO2(j,k) MacCmdTEXT_LINE_NO3(I_TEXT_LINE_NO,j,k)                  //10-05-16|0x0192
#define MacCmdTEXT_LINE_NO1(k) MacCmdTEXT_LINE_NO2(3,k)                                   //10-05-16|0x0192
#define MacCmd_TEXT_LINE_NO MacCmdTEXT_LINE_NO1(3)                                        //10-05-16|0x0192
#define MacCmdNO_TEXT_FILES3(i,j,k) LoadCmd("_NO_TEXT_FILES",i,j,k)                       //13-07-25|0x0193
#define MacCmdNO_TEXT_FILES2(j,k) MacCmdNO_TEXT_FILES3(I_NO_TEXT_FILES,j,k)               //13-07-25|0x0193
#define MacCmdNO_TEXT_FILES1(k) MacCmdNO_TEXT_FILES2(2,k)                                 //13-07-25|0x0193
#define MacCmd_NO_TEXT_FILES MacCmdNO_TEXT_FILES1(2)                                      //13-07-25|0x0193
#define MacCmdREAD_SEGMENT3(i,j,k) LoadCmd("_READ_SEGMENT",i,j,k)                         //13-07-25|0x0195
#define MacCmdREAD_SEGMENT2(j,k) MacCmdREAD_SEGMENT3(I_READ_SEGMENT,j,k)                  //13-07-25|0x0195
#define MacCmdREAD_SEGMENT1(k) MacCmdREAD_SEGMENT2(4,k)                                   //13-07-25|0x0195
#define MacCmd_READ_SEGMENT MacCmdREAD_SEGMENT1(4)                                        //13-07-25|0x0195
#define MacCmdWRITE_SEGMENT3(i,j,k) LoadCmd("_WRITE_SEGMENT",i,j,k)                       //13-07-25|0x0196
#define MacCmdWRITE_SEGMENT2(j,k) MacCmdWRITE_SEGMENT3(I_WRITE_SEGMENT,j,k)               //13-07-25|0x0196
#define MacCmdWRITE_SEGMENT1(k) MacCmdWRITE_SEGMENT2(3,k)                                 //13-07-25|0x0196
#define MacCmd_WRITE_SEGMENT MacCmdWRITE_SEGMENT1(3)                                      //13-07-25|0x0196
#define MacCmdSTORE3(i,j,k) LoadCmd("_STORE",i,j,k)                                       //06-09-04|0x019c
#define MacCmdSTORE2(j,k) MacCmdSTORE3(I_STORE,j,k)                                       //06-09-04|0x019c
#define MacCmdSTORE1(k) MacCmdSTORE2(3,k)                                                 //06-09-04|0x019c
#define MacCmd_STORE MacCmdSTORE1(3)                                                      //06-09-04|0x019c
#define MacCmdCLEAR3(i,j,k) LoadCmd("_CLEAR",i,j,k)                                       //06-09-04|0x019d
#define MacCmdCLEAR2(j,k) MacCmdCLEAR3(I_CLEAR,j,k)                                       //06-09-04|0x019d
#define MacCmdCLEAR1(k) MacCmdCLEAR2(2,k)                                                 //06-09-04|0x019d
#define MacCmd_CLEAR MacCmdCLEAR1(2)                                                      //06-09-04|0x019d
#define MacCmdADD3(i,j,k) LoadCmd("_ADD",i,j,k)                                           //06-09-04|0x01a3
#define MacCmdADD2(j,k) MacCmdADD3(I_ADD,j,k)                                             //06-09-04|0x01a3
#define MacCmdADD1(k) MacCmdADD2(3,k)                                                     //06-09-04|0x01a3
#define MacCmd_ADD MacCmdADD1(3)                                                          //06-09-04|0x01a3
#define MacCmdSUBT3(i,j,k) LoadCmd("_SUBT",i,j,k)                                         //06-09-06|0x01a4
#define MacCmdSUBT2(j,k) MacCmdSUBT3(I_SUBT,j,k)                                          //06-09-06|0x01a4
#define MacCmdSUBT1(k) MacCmdSUBT2(3,k)                                                   //06-09-06|0x01a4
#define MacCmd_SUBT MacCmdSUBT1(3)                                                        //06-09-06|0x01a4
#define MacCmdMULT3(i,j,k) LoadCmd("_MULT",i,j,k)                                         //06-09-06|0x01a5
#define MacCmdMULT2(j,k) MacCmdMULT3(I_MULT,j,k)                                          //06-09-06|0x01a5
#define MacCmdMULT1(k) MacCmdMULT2(3,k)                                                   //06-09-06|0x01a5
#define MacCmd_MULT MacCmdMULT1(3)                                                        //06-09-06|0x01a5
#define MacCmdDIV3(i,j,k) LoadCmd("_DIV",i,j,k)                                           //07-11-01|0x01a6
#define MacCmdDIV2(j,k) MacCmdDIV3(I_DIV,j,k)                                             //07-11-01|0x01a6
#define MacCmdDIV1(k) MacCmdDIV2(3,k)                                                     //07-11-01|0x01a6
#define MacCmd_DIV MacCmdDIV1(3)                                                          //07-11-01|0x01a6
#define MacCmdMOD3(i,j,k) LoadCmd("_MOD",i,j,k)                                           //07-11-01|0x01a7
#define MacCmdMOD2(j,k) MacCmdMOD3(I_MOD,j,k)                                             //07-11-01|0x01a7
#define MacCmdMOD1(k) MacCmdMOD2(3,k)                                                     //07-11-01|0x01a7
#define MacCmd_MOD MacCmdMOD1(3)                                                          //07-11-01|0x01a7
#define MacCmdAND3(i,j,k) LoadCmd("_AND",i,j,k)                                           //07-11-01|0x01a9
#define MacCmdAND2(j,k) MacCmdAND3(I_AND,j,k)                                             //07-11-01|0x01a9
#define MacCmdAND1(k) MacCmdAND2(3,k)                                                     //07-11-01|0x01a9
#define MacCmd_AND MacCmdAND1(3)                                                          //07-11-01|0x01a9
#define MacCmdOR3(i,j,k) LoadCmd("_OR",i,j,k)                                             //07-11-01|0x01aa
#define MacCmdOR2(j,k) MacCmdOR3(I_OR,j,k)                                                //07-11-01|0x01aa
#define MacCmdOR1(k) MacCmdOR2(3,k)                                                       //07-11-01|0x01aa
#define MacCmd_OR MacCmdOR1(3)                                                            //07-11-01|0x01aa
#define MacCmdEXOR3(i,j,k) LoadCmd("_EXOR",i,j,k)                                         //07-11-01|0x01ab
#define MacCmdEXOR2(j,k) MacCmdEXOR3(I_EXOR,j,k)                                          //07-11-01|0x01ab
#define MacCmdEXOR1(k) MacCmdEXOR2(3,k)                                                   //07-11-01|0x01ab
#define MacCmd_EXOR MacCmdEXOR1(3)                                                        //07-11-01|0x01ab
#define MacCmdGET_NO_PARMS3(i,j,k) LoadCmd("_GET_NO_PARMS",i,j,k)                         //07-04-09|0x01b1
#define MacCmdGET_NO_PARMS2(j,k) MacCmdGET_NO_PARMS3(I_GET_NO_PARMS,j,k)                  //07-04-09|0x01b1
#define MacCmdGET_NO_PARMS1(k) MacCmdGET_NO_PARMS2(2,k)                                   //07-04-09|0x01b1
#define MacCmd_GET_NO_PARMS MacCmdGET_NO_PARMS1(2)                                        //07-04-09|0x01b1
#define MacCmdDECIMAL3(i,j,k) LoadCmd("_DECIMAL",i,j,k)                                   //06-11-18|0x01b3
#define MacCmdDECIMAL2(j,k) MacCmdDECIMAL3(I_DECIMAL,j,k)                                 //06-11-18|0x01b3
#define MacCmdDECIMAL1(k) MacCmdDECIMAL2(3,k)                                             //06-11-18|0x01b3
#define MacCmd_DECIMAL MacCmdDECIMAL1(3)                                                  //06-11-18|0x01b3
#define MacCmdPRIME3(i,j,k) LoadCmd("_PRIME",i,j,k)                                       //07-11-01|0x01b5
#define MacCmdPRIME2(j,k) MacCmdPRIME3(I_PRIME,j,k)                                       //07-11-01|0x01b5
#define MacCmdPRIME1(k) MacCmdPRIME2(3,k)                                                 //07-11-01|0x01b5
#define MacCmd_PRIME MacCmdPRIME1(3)                                                      //07-11-01|0x01b5
#define MacCmdLESS3(i,j,k) LoadCmd("_LESS",i,j,k)                                         //06-09-06|0x01bb
#define MacCmdLESS2(j,k) MacCmdLESS3(I_LESS,j,k)                                          //06-09-06|0x01bb
#define MacCmdLESS1(k) MacCmdLESS2(3,k)                                                   //06-09-06|0x01bb
#define MacCmd_LESS MacCmdLESS1(3)                                                        //06-09-06|0x01bb
#define MacCmdEQUAL3(i,j,k) LoadCmd("_EQUAL",i,j,k)                                       //06-09-06|0x01bc
#define MacCmdEQUAL2(j,k) MacCmdEQUAL3(I_EQUAL,j,k)                                       //06-09-06|0x01bc
#define MacCmdEQUAL1(k) MacCmdEQUAL2(3,k)                                                 //06-09-06|0x01bc
#define MacCmd_EQUAL MacCmdEQUAL1(3)                                                      //06-09-06|0x01bc
#define MacCmdGREAT3(i,j,k) LoadCmd("_GREAT",i,j,k)                                       //06-09-06|0x01bd
#define MacCmdGREAT2(j,k) MacCmdGREAT3(I_GREAT,j,k)                                       //06-09-06|0x01bd
#define MacCmdGREAT1(k) MacCmdGREAT2(3,k)                                                 //06-09-06|0x01bd
#define MacCmd_GREAT MacCmdGREAT1(3)                                                      //06-09-06|0x01bd
#define MacCmdSTATE_BYTE3(i,j,k) LoadCmd("_STATE_BYTE",i,j,k)                             //07-11-01|0x01c3
#define MacCmdSTATE_BYTE2(j,k) MacCmdSTATE_BYTE3(I_STATE_BYTE,j,k)                        //07-11-01|0x01c3
#define MacCmdSTATE_BYTE1(k) MacCmdSTATE_BYTE2(2,k)                                       //07-11-01|0x01c3
#define MacCmd_STATE_BYTE MacCmdSTATE_BYTE1(2)                                            //07-11-01|0x01c3
#define MacCmdSTATE_INTEGER3(i,j,k) LoadCmd("_STATE_INTEGER",i,j,k)                       //07-11-01|0x01c4
#define MacCmdSTATE_INTEGER2(j,k) MacCmdSTATE_INTEGER3(I_STATE_INTEGER,j,k)               //07-11-01|0x01c4
#define MacCmdSTATE_INTEGER1(k) MacCmdSTATE_INTEGER2(2,k)                                 //07-11-01|0x01c4
#define MacCmd_STATE_INTEGER MacCmdSTATE_INTEGER1(2)                                      //07-11-01|0x01c4
#define MacCmdSTATE_LONG3(i,j,k) LoadCmd("_STATE_LONG",i,j,k)                             //07-11-01|0x01c5
#define MacCmdSTATE_LONG2(j,k) MacCmdSTATE_LONG3(I_STATE_LONG,j,k)                        //07-11-01|0x01c5
#define MacCmdSTATE_LONG1(k) MacCmdSTATE_LONG2(2,k)                                       //07-11-01|0x01c5
#define MacCmd_STATE_LONG MacCmdSTATE_LONG1(2)                                            //07-11-01|0x01c5
#define MacCmdSTATE_NUMBER3(i,j,k) LoadCmd("_STATE_NUMBER",i,j,k)                         //07-11-01|0x01c6
#define MacCmdSTATE_NUMBER2(j,k) MacCmdSTATE_NUMBER3(I_STATE_NUMBER,j,k)                  //07-11-01|0x01c6
#define MacCmdSTATE_NUMBER1(k) MacCmdSTATE_NUMBER2(2,k)                                   //07-11-01|0x01c6
#define MacCmd_STATE_NUMBER MacCmdSTATE_NUMBER1(2)                                        //07-11-01|0x01c6
#define MacCmdLEAD_BLANKS3(i,j,k) LoadCmd("_LEAD_BLANKS",i,j,k)                           //07-11-01|0x01cc
#define MacCmdLEAD_BLANKS2(j,k) MacCmdLEAD_BLANKS3(I_LEAD_BLANKS,j,k)                     //07-11-01|0x01cc
#define MacCmdLEAD_BLANKS1(k) MacCmdLEAD_BLANKS2(3,k)                                     //07-11-01|0x01cc
#define MacCmd_LEAD_BLANKS MacCmdLEAD_BLANKS1(3)                                          //07-11-01|0x01cc
#define MacCmdSTART_COL3(i,j,k) LoadCmd("_START_COL",i,j,k)                               //06-09-06|0x01cd
#define MacCmdSTART_COL2(j,k) MacCmdSTART_COL3(I_START_COL,j,k)                           //06-09-06|0x01cd
#define MacCmdSTART_COL1(k) MacCmdSTART_COL2(3,k)                                         //06-09-06|0x01cd
#define MacCmd_START_COL MacCmdSTART_COL1(3)                                              //06-09-06|0x01cd
#define MacCmdSTRING_LENGTH3(i,j,k) LoadCmd("_STRING_LENGTH",i,j,k)                       //06-09-06|0x01ce
#define MacCmdSTRING_LENGTH2(j,k) MacCmdSTRING_LENGTH3(I_STRING_LENGTH,j,k)               //06-09-06|0x01ce
#define MacCmdSTRING_LENGTH1(k) MacCmdSTRING_LENGTH2(3,k)                                 //06-09-06|0x01ce
#define MacCmd_STRING_LENGTH MacCmdSTRING_LENGTH1(3)                                      //06-09-06|0x01ce
#define MacCmdBLANKS3(i,j,k) LoadCmd("_BLANKS",i,j,k)                                     //06-09-06|0x01cf
#define MacCmdBLANKS2(j,k) MacCmdBLANKS3(I_BLANKS,j,k)                                    //06-09-06|0x01cf
#define MacCmdBLANKS1(k) MacCmdBLANKS2(3,k)                                               //06-09-06|0x01cf
#define MacCmd_BLANKS MacCmdBLANKS1(3)                                                    //06-09-06|0x01cf
#define MacCmdSTATE_CHAR3(i,j,k) LoadCmd("_STATE_CHAR",i,j,k)                             //07-02-06|0x01d1
#define MacCmdSTATE_CHAR2(j,k) MacCmdSTATE_CHAR3(I_STATE_CHAR,j,k)                        //07-02-06|0x01d1
#define MacCmdSTATE_CHAR1(k) MacCmdSTATE_CHAR2(3,k)                                       //07-02-06|0x01d1
#define MacCmd_STATE_CHAR MacCmdSTATE_CHAR1(3)                                            //07-02-06|0x01d1
#define MacCmdFIRST_CHAR3(i,j,k) LoadCmd("_FIRST_CHAR",i,j,k)                             //07-02-02|0x01d3
#define MacCmdFIRST_CHAR2(j,k) MacCmdFIRST_CHAR3(I_FIRST_CHAR,j,k)                        //07-02-02|0x01d3
#define MacCmdFIRST_CHAR1(k) MacCmdFIRST_CHAR2(4,k)                                       //07-02-02|0x01d3
#define MacCmd_FIRST_CHAR MacCmdFIRST_CHAR1(4)                                            //07-02-02|0x01d3
#define MacCmdLAST_CHAR3(i,j,k) LoadCmd("_LAST_CHAR",i,j,k)                               //06-12-04|0x01d4
#define MacCmdLAST_CHAR2(j,k) MacCmdLAST_CHAR3(I_LAST_CHAR,j,k)                           //06-12-04|0x01d4
#define MacCmdLAST_CHAR1(k) MacCmdLAST_CHAR2(4,k)                                         //06-12-04|0x01d4
#define MacCmd_LAST_CHAR MacCmdLAST_CHAR1(4)                                              //06-12-04|0x01d4
#define MacCmdASCII_VALUE3(i,j,k) LoadCmd("_ASCII_VALUE",i,j,k)                           //07-02-02|0x01d5
#define MacCmdASCII_VALUE2(j,k) MacCmdASCII_VALUE3(I_ASCII_VALUE,j,k)                     //07-02-02|0x01d5
#define MacCmdASCII_VALUE1(k) MacCmdASCII_VALUE2(4,k)                                     //07-02-02|0x01d5
#define MacCmd_ASCII_VALUE MacCmdASCII_VALUE1(4)                                          //07-02-02|0x01d5
#define MacCmdSTRING_BEFORE3(i,j,k) LoadCmd("_STRING_BEFORE",i,j,k)                       //07-02-02|0x01d6
#define MacCmdSTRING_BEFORE2(j,k) MacCmdSTRING_BEFORE3(I_STRING_BEFORE,j,k)               //07-02-02|0x01d6
#define MacCmdSTRING_BEFORE1(k) MacCmdSTRING_BEFORE2(4,k)                                 //07-02-02|0x01d6
#define MacCmd_STRING_BEFORE MacCmdSTRING_BEFORE1(4)                                      //07-02-02|0x01d6
#define MacCmdSTRING_AFTER3(i,j,k) LoadCmd("_STRING_AFTER",i,j,k)                         //07-02-06|0x01d7
#define MacCmdSTRING_AFTER2(j,k) MacCmdSTRING_AFTER3(I_STRING_AFTER,j,k)                  //07-02-06|0x01d7
#define MacCmdSTRING_AFTER1(k) MacCmdSTRING_AFTER2(4,k)                                   //07-02-06|0x01d7
#define MacCmd_STRING_AFTER MacCmdSTRING_AFTER1(4)                                        //07-02-06|0x01d7
#define MacCmdSTRING_LESS3(i,j,k) LoadCmd("_STRING_LESS",i,j,k)                           //06-10-06|0x01dd
#define MacCmdSTRING_LESS2(j,k) MacCmdSTRING_LESS3(I_STRING_LESS,j,k)                     //06-10-06|0x01dd
#define MacCmdSTRING_LESS1(k) MacCmdSTRING_LESS2(3,k)                                     //06-10-06|0x01dd
#define MacCmd_STRING_LESS MacCmdSTRING_LESS1(3)                                          //06-10-06|0x01dd
#define MacCmdSTRING_EQUAL3(i,j,k) LoadCmd("_STRING_EQUAL",i,j,k)                         //06-12-01|0x01de
#define MacCmdSTRING_EQUAL2(j,k) MacCmdSTRING_EQUAL3(I_STRING_EQUAL,j,k)                  //06-12-01|0x01de
#define MacCmdSTRING_EQUAL1(k) MacCmdSTRING_EQUAL2(3,k)                                   //06-12-01|0x01de
#define MacCmd_STRING_EQUAL MacCmdSTRING_EQUAL1(3)                                        //06-12-01|0x01de
#define MacCmdSTRING_GREAT3(i,j,k) LoadCmd("_STRING_GREAT",i,j,k)                         //07-11-01|0x01df
#define MacCmdSTRING_GREAT2(j,k) MacCmdSTRING_GREAT3(I_STRING_GREAT,j,k)                  //07-11-01|0x01df
#define MacCmdSTRING_GREAT1(k) MacCmdSTRING_GREAT2(3,k)                                   //07-11-01|0x01df
#define MacCmd_STRING_GREAT MacCmdSTRING_GREAT1(3)                                        //07-11-01|0x01df
#define MacCmdSTATE_STRING3(i,j,k) LoadCmd("_STATE_STRING",i,j,k)                         //06-11-19|0x01e5
#define MacCmdSTATE_STRING2(j,k) MacCmdSTATE_STRING3(I_STATE_STRING,j,k)                  //06-11-19|0x01e5
#define MacCmdSTATE_STRING1(k) MacCmdSTATE_STRING2(2,k)                                   //06-11-19|0x01e5
#define MacCmd_STATE_STRING MacCmdSTATE_STRING1(2)                                        //06-11-19|0x01e5
#define MacCmdSTATE_NAME3(i,j,k) LoadCmd("_STATE_NAME",i,j,k)                             //06-11-19|0x01e6
#define MacCmdSTATE_NAME2(j,k) MacCmdSTATE_NAME3(I_STATE_NAME,j,k)                        //06-11-19|0x01e6
#define MacCmdSTATE_NAME1(k) MacCmdSTATE_NAME2(2,k)                                       //06-11-19|0x01e6
#define MacCmd_STATE_NAME MacCmdSTATE_NAME1(2)                                            //06-11-19|0x01e6
#define MacCmdLOAD_DICT3(i,j,k) LoadCmd("_LOAD_DICT",i,j,k)                               //06-12-01|0x01ec
#define MacCmdLOAD_DICT2(j,k) MacCmdLOAD_DICT3(I_LOAD_DICT,j,k)                           //06-12-01|0x01ec
#define MacCmdLOAD_DICT1(k) MacCmdLOAD_DICT2(2,k)                                         //06-12-01|0x01ec
#define MacCmd_LOAD_DICT MacCmdLOAD_DICT1(9)                                              //06-12-01|0x01ec
#define MacCmdLOAD_SUBDICT3(i,j,k) LoadCmd("_LOAD_SUBDICT",i,j,k)                         //06-12-01|0x01ed
#define MacCmdLOAD_SUBDICT2(j,k) MacCmdLOAD_SUBDICT3(I_LOAD_SUBDICT,j,k)                  //06-12-01|0x01ed
#define MacCmdLOAD_SUBDICT1(k) MacCmdLOAD_SUBDICT2(3,k)                                   //06-12-01|0x01ed
#define MacCmd_LOAD_SUBDICT MacCmdLOAD_SUBDICT1(9)                                        //06-12-01|0x01ed
#define MacCmdRELOAD_DICT3(i,j,k) LoadCmd("_RELOAD_DICT",i,j,k)                           //06-12-01|0x01ef
#define MacCmdRELOAD_DICT2(j,k) MacCmdRELOAD_DICT3(I_RELOAD_DICT,j,k)                     //06-12-01|0x01ef
#define MacCmdRELOAD_DICT1(k) MacCmdRELOAD_DICT2(2,k)                                     //06-12-01|0x01ef
#define MacCmd_RELOAD_DICT MacCmdRELOAD_DICT1(9)                                          //06-12-01|0x01ef
#define MacCmdRELOAD_SUBDICT3(i,j,k) LoadCmd("_RELOAD_SUBDICT",i,j,k)                     //06-12-01|0x01f0
#define MacCmdRELOAD_SUBDICT2(j,k) MacCmdRELOAD_SUBDICT3(I_RELOAD_SUBDICT,j,k)            //06-12-01|0x01f0
#define MacCmdRELOAD_SUBDICT1(k) MacCmdRELOAD_SUBDICT2(3,k)                               //06-12-01|0x01f0
#define MacCmd_RELOAD_SUBDICT MacCmdRELOAD_SUBDICT1(9)                                    //06-12-01|0x01f0
#define MacCmdGET_DICT3(i,j,k) LoadCmd("_GET_DICT",i,j,k)                                 //06-12-23|0x01f2
#define MacCmdGET_DICT2(j,k) MacCmdGET_DICT3(I_GET_DICT,j,k)                              //06-12-23|0x01f2
#define MacCmdGET_DICT1(k) MacCmdGET_DICT2(4,k)                                           //06-12-23|0x01f2
#define MacCmd_GET_DICT MacCmdGET_DICT1(4)                                                //06-12-23|0x01f2
#define MacCmdGET_SUBDICT3(i,j,k) LoadCmd("_GET_SUBDICT",i,j,k)                           //06-12-01|0x01f3
#define MacCmdGET_SUBDICT2(j,k) MacCmdGET_SUBDICT3(I_GET_SUBDICT,j,k)                     //06-12-01|0x01f3
#define MacCmdGET_SUBDICT1(k) MacCmdGET_SUBDICT2(5,k)                                     //06-12-01|0x01f3
#define MacCmd_GET_SUBDICT MacCmdGET_SUBDICT1(5)                                          //06-12-01|0x01f3
#define MacCmdSTATE_DICT3(i,j,k) LoadCmd("_STATE_DICT",i,j,k)                             //06-11-04|0x01f5
#define MacCmdSTATE_DICT2(j,k) MacCmdSTATE_DICT3(I_STATE_DICT,j,k)                        //06-11-04|0x01f5
#define MacCmdSTATE_DICT1(k) MacCmdSTATE_DICT2(2,k)                                       //06-11-04|0x01f5
#define MacCmd_STATE_DICT MacCmdSTATE_DICT1(2)                                            //06-11-04|0x01f5
#define MacCmdSTATE_SUBDICT3(i,j,k) LoadCmd("_STATE_SUBDICT",i,j,k)                       //06-12-01|0x01f6
#define MacCmdSTATE_SUBDICT2(j,k) MacCmdSTATE_SUBDICT3(I_STATE_SUBDICT,j,k)               //06-12-01|0x01f6
#define MacCmdSTATE_SUBDICT1(k) MacCmdSTATE_SUBDICT2(3,k)                                 //06-12-01|0x01f6
#define MacCmd_STATE_SUBDICT MacCmdSTATE_SUBDICT1(3)                                      //06-12-01|0x01f6
#define MacCmdSTATE_DICT_GET3(i,j,k) LoadCmd("_STATE_DICT_GET",i,j,k)                     //06-10-06|0x01f8
#define MacCmdSTATE_DICT_GET2(j,k) MacCmdSTATE_DICT_GET3(I_STATE_DICT_GET,j,k)            //06-10-06|0x01f8
#define MacCmdSTATE_DICT_GET1(k) MacCmdSTATE_DICT_GET2(3,k)                               //06-10-06|0x01f8
#define MacCmd_STATE_DICT_GET MacCmdSTATE_DICT_GET1(3)                                    //06-10-06|0x01f8
#define MacCmdSTATE_SUBDICT_GET3(i,j,k) LoadCmd("_STATE_SUBDICT_GET",i,j,k)               //09-06-02|0x01f9
#define MacCmdSTATE_SUBDICT_GET2(j,k) MacCmdSTATE_SUBDICT_GET3(I_STATE_SUBDICT_GET,j,k)   //09-06-02|0x01f9
#define MacCmdSTATE_SUBDICT_GET1(k) MacCmdSTATE_SUBDICT_GET2(4,k)                         //09-06-02|0x01f9
#define MacCmd_STATE_SUBDICT_GET MacCmdSTATE_SUBDICT_GET1(4)                              //09-06-02|0x01f9
#define MacCmdGET_POSTOFFICE_NO3(i,j,k) LoadCmd("_GET_POSTOFFICE_NO",i,j,k)               //09-06-02|0x01ff
#define MacCmdGET_POSTOFFICE_NO2(j,k) MacCmdGET_POSTOFFICE_NO3(I_GET_POSTOFFICE_NO,j,k)   //09-06-02|0x01ff
#define MacCmdGET_POSTOFFICE_NO1(k) MacCmdGET_POSTOFFICE_NO2(3,k)                         //09-06-02|0x01ff
#define MacCmd_GET_POSTOFFICE_NO MacCmdGET_POSTOFFICE_NO1(3)                              //09-06-02|0x01ff
#define MacCmdDELETE_POSTOFFICE3(i,j,k) LoadCmd("_DELETE_POSTOFFICE",i,j,k)               //09-03-10|0x0200
#define MacCmdDELETE_POSTOFFICE2(j,k) MacCmdDELETE_POSTOFFICE3(I_DELETE_POSTOFFICE,j,k)   //09-03-10|0x0200
#define MacCmdDELETE_POSTOFFICE1(k) MacCmdDELETE_POSTOFFICE2(2,k)                         //09-03-10|0x0200
#define MacCmd_DELETE_POSTOFFICE MacCmdDELETE_POSTOFFICE1(2)                              //09-03-10|0x0200
#define MacCmdOPEN_POSTOFFICE3(i,j,k) LoadCmd("_OPEN_POSTOFFICE",i,j,k)                   //09-03-11|0x0201
#define MacCmdOPEN_POSTOFFICE2(j,k) MacCmdOPEN_POSTOFFICE3(I_OPEN_POSTOFFICE,j,k)         //09-03-11|0x0201
#define MacCmdOPEN_POSTOFFICE1(k) MacCmdOPEN_POSTOFFICE2(2,k)                             //09-03-11|0x0201
#define MacCmd_OPEN_POSTOFFICE MacCmdOPEN_POSTOFFICE1(2)                                  //09-03-11|0x0201
#define MacCmdCLOSE_POSTOFFICE3(i,j,k) LoadCmd("_CLOSE_POSTOFFICE",i,j,k)                 //09-03-10|0x0202
#define MacCmdCLOSE_POSTOFFICE2(j,k) MacCmdCLOSE_POSTOFFICE3(I_CLOSE_POSTOFFICE,j,k)      //09-03-10|0x0202
#define MacCmdCLOSE_POSTOFFICE1(k) MacCmdCLOSE_POSTOFFICE2(1,k)                           //09-03-10|0x0202
#define MacCmd_CLOSE_POSTOFFICE MacCmdCLOSE_POSTOFFICE1(1)                                //09-03-10|0x0202
#define MacCmdCREATE_POSTOFFICE3(i,j,k) LoadCmd("_CREATE_POSTOFFICE",i,j,k)               //09-03-11|0x0204
#define MacCmdCREATE_POSTOFFICE2(j,k) MacCmdCREATE_POSTOFFICE3(I_CREATE_POSTOFFICE,j,k)   //09-03-11|0x0204
#define MacCmdCREATE_POSTOFFICE1(k) MacCmdCREATE_POSTOFFICE2(2,k)                         //09-03-11|0x0204
#define MacCmd_CREATE_POSTOFFICE MacCmdCREATE_POSTOFFICE1(2)                              //09-03-11|0x0204
#define MacCmdCREATE_PO_BOX3(i,j,k) LoadCmd("_CREATE_PO_BOX",i,j,k)                       //09-06-13|0x0205
#define MacCmdCREATE_PO_BOX2(j,k) MacCmdCREATE_PO_BOX3(I_CREATE_PO_BOX,j,k)               //09-06-13|0x0205
#define MacCmdCREATE_PO_BOX1(k) MacCmdCREATE_PO_BOX2(3,k)                                 //09-06-13|0x0205
#define MacCmd_CREATE_PO_BOX MacCmdCREATE_PO_BOX1(3)                                      //09-06-13|0x0205
#define MacCmdSEND_MAIL3(i,j,k) LoadCmd("_SEND_MAIL",i,j,k)                               //07-11-05|0x0207
#define MacCmdSEND_MAIL2(j,k) MacCmdSEND_MAIL3(I_SEND_MAIL,j,k)                           //07-11-05|0x0207
#define MacCmdSEND_MAIL1(k) MacCmdSEND_MAIL2(4,k)                                         //07-11-05|0x0207
#define MacCmd_SEND_MAIL MacCmdSEND_MAIL1(4)                                              //07-11-05|0x0207
#define MacCmdGET_MAIL3(i,j,k) LoadCmd("_GET_MAIL",i,j,k)                                 //09-09-17|0x0209
#define MacCmdGET_MAIL2(j,k) MacCmdGET_MAIL3(I_GET_MAIL,j,k)                              //09-09-17|0x0209
#define MacCmdGET_MAIL1(k) MacCmdGET_MAIL2(4,k)                                           //09-09-17|0x0209
#define MacCmd_GET_MAIL MacCmdGET_MAIL1(4)                                                //09-09-17|0x0209
#define MacCmdEMPTY_PO_BOX3(i,j,k) LoadCmd("_EMPTY_PO_BOX",i,j,k)                         //09-09-17|0x020a
#define MacCmdEMPTY_PO_BOX2(j,k) MacCmdEMPTY_PO_BOX3(I_EMPTY_PO_BOX,j,k)                  //09-09-17|0x020a
#define MacCmdEMPTY_PO_BOX1(k) MacCmdEMPTY_PO_BOX2(3,k)                                   //09-09-17|0x020a
#define MacCmd_EMPTY_PO_BOX MacCmdEMPTY_PO_BOX1(3)                                        //09-09-17|0x020a
#define MacCmdPOSTOFFICE_EXISTS3(i,j,k) LoadCmd("_POSTOFFICE_EXISTS",i,j,k)               //07-11-05|0x020c
#define MacCmdPOSTOFFICE_EXISTS2(j,k) MacCmdPOSTOFFICE_EXISTS3(I_POSTOFFICE_EXISTS,j,k)   //07-11-05|0x020c
#define MacCmdPOSTOFFICE_EXISTS1(k) MacCmdPOSTOFFICE_EXISTS2(2,k)                         //07-11-05|0x020c
#define MacCmd_POSTOFFICE_EXISTS MacCmdPOSTOFFICE_EXISTS1(2)                              //07-11-05|0x020c
#define MacCmdPO_BOX_EXISTS3(i,j,k) LoadCmd("_PO_BOX_EXISTS",i,j,k)                       //07-11-05|0x020d
#define MacCmdPO_BOX_EXISTS2(j,k) MacCmdPO_BOX_EXISTS3(I_PO_BOX_EXISTS,j,k)               //07-11-05|0x020d
#define MacCmdPO_BOX_EXISTS1(k) MacCmdPO_BOX_EXISTS2(3,k)                                 //07-11-05|0x020d
#define MacCmd_PO_BOX_EXISTS MacCmdPO_BOX_EXISTS1(3)                                      //07-11-05|0x020d
#define MacCmdPO_BOX_EMPTY3(i,j,k) LoadCmd("_PO_BOX_EMPTY",i,j,k)                         //07-11-05|0x020e
#define MacCmdPO_BOX_EMPTY2(j,k) MacCmdPO_BOX_EMPTY3(I_PO_BOX_EMPTY,j,k)                  //07-11-05|0x020e
#define MacCmdPO_BOX_EMPTY1(k) MacCmdPO_BOX_EMPTY2(3,k)                                   //07-11-05|0x020e
#define MacCmd_PO_BOX_EMPTY MacCmdPO_BOX_EMPTY1(3)                                        //07-11-05|0x020e
#define MacCmdASSIGN_STACK3(i,j,k) LoadCmd("_ASSIGN_STACK",i,j,k)                         //07-11-01|0x0214
#define MacCmdASSIGN_STACK2(j,k) MacCmdASSIGN_STACK3(I_ASSIGN_STACK,j,k)                  //07-11-01|0x0214
#define MacCmdASSIGN_STACK1(k) MacCmdASSIGN_STACK2(3,k)                                   //07-11-01|0x0214
#define MacCmd_ASSIGN_STACK MacCmdASSIGN_STACK1(3)                                        //07-11-01|0x0214
#define MacCmdPUSH_TOKEN3(i,j,k) LoadCmd("_PUSH_TOKEN",i,j,k)                             //06-10-06|0x0215
#define MacCmdPUSH_TOKEN2(j,k) MacCmdPUSH_TOKEN3(I_PUSH_TOKEN,j,k)                        //06-10-06|0x0215
#define MacCmdPUSH_TOKEN1(k) MacCmdPUSH_TOKEN2(2,k)                                       //06-10-06|0x0215
#define MacCmd_PUSH_TOKEN MacCmdPUSH_TOKEN1(2)                                            //06-10-06|0x0215
#define MacCmdPOP_TOKEN3(i,j,k) LoadCmd("_POP_TOKEN",i,j,k)                               //06-10-06|0x0216
#define MacCmdPOP_TOKEN2(j,k) MacCmdPOP_TOKEN3(I_POP_TOKEN,j,k)                           //06-10-06|0x0216
#define MacCmdPOP_TOKEN1(k) MacCmdPOP_TOKEN2(2,k)                                         //06-10-06|0x0216
#define MacCmd_POP_TOKEN MacCmdPOP_TOKEN1(2)                                              //06-10-06|0x0216
#define MacCmdGET_STACK_LEVEL3(i,j,k) LoadCmd("_GET_STACK_LEVEL",i,j,k)                   //06-10-06|0x0217
#define MacCmdGET_STACK_LEVEL2(j,k) MacCmdGET_STACK_LEVEL3(I_GET_STACK_LEVEL,j,k)         //06-10-06|0x0217
#define MacCmdGET_STACK_LEVEL1(k) MacCmdGET_STACK_LEVEL2(2,k)                             //06-10-06|0x0217
#define MacCmd_GET_STACK_LEVEL MacCmdGET_STACK_LEVEL1(2)                                  //06-10-06|0x0217
#define MacCmdSTATE_TOKEN3(i,j,k) LoadCmd("_STATE_TOKEN",i,j,k)                           //06-10-06|0x0218
#define MacCmdSTATE_TOKEN2(j,k) MacCmdSTATE_TOKEN3(I_STATE_TOKEN,j,k)                     //06-10-06|0x0218
#define MacCmdSTATE_TOKEN1(k) MacCmdSTATE_TOKEN2(2,k)                                     //06-10-06|0x0218
#define MacCmd_STATE_TOKEN MacCmdSTATE_TOKEN1(2)                                          //06-10-06|0x0218
#define MacCmdGET_TOKEN3(i,j,k) LoadCmd("_GET_TOKEN",i,j,k)                               //06-10-06|0x0219
#define MacCmdGET_TOKEN2(j,k) MacCmdGET_TOKEN3(I_GET_TOKEN,j,k)                           //06-10-06|0x0219
#define MacCmdGET_TOKEN1(k) MacCmdGET_TOKEN2(2,k)                                         //06-10-06|0x0219
#define MacCmd_GET_TOKEN MacCmdGET_TOKEN1(2)                                              //06-10-06|0x0219
#define MacCmdSTATE_STACK3(i,j,k) LoadCmd("_STATE_STACK",i,j,k)                           //06-10-06|0x021a
#define MacCmdSTATE_STACK2(j,k) MacCmdSTATE_STACK3(I_STATE_STACK,j,k)                     //06-10-06|0x021a
#define MacCmdSTATE_STACK1(k) MacCmdSTATE_STACK2(1,k)                                     //06-10-06|0x021a
#define MacCmd_STATE_STACK MacCmdSTATE_STACK1(1)                                          //06-10-06|0x021a
#define MacCmd_JUMP_IF_Error error_command("_JUMP_IF")                                    //06-10-06|0x0220
#define MacCmd_JUMP_IF_NOT_Error error_command("_JUMP_IF_NOT")                            //06-10-06|0x0221
#define MacCmdJUMP_ALWAYS3(i,j,k) LoadCmd("_JUMP_ALWAYS",i,j,k)                           //06-10-06|0x0223
#define MacCmdJUMP_ALWAYS2(j,k) MacCmdJUMP_ALWAYS3(I_JUMP_ALWAYS,j,k)                     //06-10-06|0x0223
#define MacCmdJUMP_ALWAYS1(k) MacCmdJUMP_ALWAYS2(2,k)                                     //06-10-06|0x0223
#define MacCmd_JUMP_ALWAYS MacCmdJUMP_ALWAYS1(2)                                          //06-10-06|0x0223
#define MacCmd_GET_FLAG_Error error_command("_GET_FLAG")                                  //07-12-25|0x0227
#define MacCmdSTATE_FLAG3(i,j,k) LoadCmd("_STATE_FLAG",i,j,k)                             //07-12-25|0x0228
#define MacCmdSTATE_FLAG2(j,k) MacCmdSTATE_FLAG3(I_STATE_FLAG,j,k)                        //07-12-25|0x0228
#define MacCmdSTATE_FLAG1(k) MacCmdSTATE_FLAG2(2,k)                                       //07-12-25|0x0228
#define MacCmd_STATE_FLAG MacCmdSTATE_FLAG1(2)                                            //07-12-25|0x0228
#define MacCmdRULE_START3(i,j,k) LoadCmd("_RULE_START",i,j,k)                             //06-12-23|0x022e
#define MacCmdRULE_START2(j,k) MacCmdRULE_START3(I_RULE_START,j,k)                        //06-12-23|0x022e
#define MacCmdRULE_START1(k) MacCmdRULE_START2(1,k)                                       //06-12-23|0x022e
#define MacCmd_RULE_START MacCmdRULE_START1(1)                                            //06-12-23|0x022e
#define MacCmd_RULE_END_Error error_command("_RULE_END")                                  //06-12-23|0x0230
#define MacCmd_RULE_STATE_Error error_command("_RULE_STATE")                              //06-12-23|0x0231
#define MacCmd_MOVE_Error error_command("_MOVE")                                          //06-12-23|0x0232
#define MacCmd_EMIT_Error error_command("_EMIT")                                          //06-12-23|0x0233
#define MacCmdERROR3(i,j,k) LoadCmd("_ERROR",i,j,k)                                       //07-11-16|0x0239
#define MacCmdERROR2(j,k) MacCmdERROR3(I_ERROR,j,k)                                       //07-11-16|0x0239
#define MacCmdERROR1(k) MacCmdERROR2(1,k)                                                 //07-11-16|0x0239
#define MacCmd_ERROR MacCmdERROR1(2)                                                      //07-11-16|0x0239
#define MacCmdSTATE_ERROR3(i,j,k) LoadCmd("_STATE_ERROR",i,j,k)                           //07-11-17|0x023a
#define MacCmdSTATE_ERROR2(j,k) MacCmdSTATE_ERROR3(I_STATE_ERROR,j,k)                     //07-11-17|0x023a
#define MacCmdSTATE_ERROR1(k) MacCmdSTATE_ERROR2(1,k)                                     //07-11-17|0x023a
#define MacCmd_STATE_ERROR MacCmdSTATE_ERROR1(1)                                          //07-11-17|0x023a
#define MacCmdGET_ERROR_MACRO3(i,j,k) LoadCmd("_GET_ERROR_MACRO",i,j,k)                   //07-11-16|0x023b
#define MacCmdGET_ERROR_MACRO2(j,k) MacCmdGET_ERROR_MACRO3(I_GET_ERROR_MACRO,j,k)         //07-11-16|0x023b
#define MacCmdGET_ERROR_MACRO1(k) MacCmdGET_ERROR_MACRO2(2,k)                             //07-11-16|0x023b
#define MacCmd_GET_ERROR_MACRO MacCmdGET_ERROR_MACRO1(2)                                  //07-11-16|0x023b
#define MacCmdGET_ERROR_TYPE3(i,j,k) LoadCmd("_GET_ERROR_TYPE",i,j,k)                     //07-11-16|0x023c
#define MacCmdGET_ERROR_TYPE2(j,k) MacCmdGET_ERROR_TYPE3(I_GET_ERROR_TYPE,j,k)            //07-11-16|0x023c
#define MacCmdGET_ERROR_TYPE1(k) MacCmdGET_ERROR_TYPE2(2,k)                               //07-11-16|0x023c
#define MacCmd_GET_ERROR_TYPE MacCmdGET_ERROR_TYPE1(2)                                    //07-11-16|0x023c
#define MacCmdDISPLAY3(i,j,k) LoadCmd("_DISPLAY",i,j,k)                                   //07-11-17|0x0242
#define MacCmdDISPLAY2(j,k) MacCmdDISPLAY3(I_DISPLAY,j,k)                                 //07-11-17|0x0242
#define MacCmdDISPLAY1(k) MacCmdDISPLAY2(2,k)                                             //07-11-17|0x0242
#define MacCmd_DISPLAY MacCmdDISPLAY1(2)                                                  //07-11-17|0x0242
#define MacCmdDEBUG_ON3(i,j,k) LoadCmd("_DEBUG_ON",i,j,k)                                 //06-12-01|0x0243
#define MacCmdDEBUG_ON2(j,k) MacCmdDEBUG_ON3(I_DEBUG_ON,j,k)                              //06-12-01|0x0243
#define MacCmdDEBUG_ON1(k) MacCmdDEBUG_ON2(2,k)                                           //06-12-01|0x0243
#define MacCmd_DEBUG_ON MacCmdDEBUG_ON1(2)                                                //06-12-01|0x0243
#define MacCmdGET_PCG_ARG3(i,j,k) LoadCmd("_GET_PCG_ARG",i,j,k)                           //07-11-01|0x0244
#define MacCmdGET_PCG_ARG2(j,k) MacCmdGET_PCG_ARG3(I_GET_PCG_ARG,j,k)                     //07-11-01|0x0244
#define MacCmdGET_PCG_ARG1(k) MacCmdGET_PCG_ARG2(3,k)                                     //07-11-01|0x0244
#define MacCmd_GET_PCG_ARG MacCmdGET_PCG_ARG1(3)                                          //07-11-01|0x0244
#define MacCmdKEYBOARD3(i,j,k) LoadCmd("_KEYBOARD",i,j,k)                                 //07-12-25|0x0245
#define MacCmdKEYBOARD2(j,k) MacCmdKEYBOARD3(I_KEYBOARD,j,k)                              //07-12-25|0x0245
#define MacCmdKEYBOARD1(k) MacCmdKEYBOARD2(2,k)                                           //07-12-25|0x0245
#define MacCmd_KEYBOARD MacCmdKEYBOARD1(2)                                                //07-12-25|0x0245
#define MacCmdCREATE_RANDOM3(i,j,k) LoadCmd("_CREATE_RANDOM",i,j,k)                       //10-03-22|0x024b
#define MacCmdCREATE_RANDOM2(j,k) MacCmdCREATE_RANDOM3(I_CREATE_RANDOM,j,k)               //10-03-22|0x024b
#define MacCmdCREATE_RANDOM1(k) MacCmdCREATE_RANDOM2(2,k)                                 //10-03-22|0x024b
#define MacCmd_CREATE_RANDOM MacCmdCREATE_RANDOM1(2)                                      //10-03-22|0x024b
#define MacCmdRESET_RANDOM3(i,j,k) LoadCmd("_RESET_RANDOM",i,j,k)                         //10-03-22|0x024c
#define MacCmdRESET_RANDOM2(j,k) MacCmdRESET_RANDOM3(I_RESET_RANDOM,j,k)                  //10-03-22|0x024c
#define MacCmdRESET_RANDOM1(k) MacCmdRESET_RANDOM2(2,k)                                   //10-03-22|0x024c
#define MacCmd_RESET_RANDOM MacCmdRESET_RANDOM1(2)                                        //10-03-22|0x024c
#define MacCmdOPEN_RANDOM3(i,j,k) LoadCmd("_OPEN_RANDOM",i,j,k)                           //10-03-22|0x024d
#define MacCmdOPEN_RANDOM2(j,k) MacCmdOPEN_RANDOM3(I_OPEN_RANDOM,j,k)                     //10-03-22|0x024d
#define MacCmdOPEN_RANDOM1(k) MacCmdOPEN_RANDOM2(2,k)                                     //10-03-22|0x024d
#define MacCmd_OPEN_RANDOM MacCmdOPEN_RANDOM1(2)                                          //10-03-22|0x024d
#define MacCmdCLOSE_RANDOM3(i,j,k) LoadCmd("_CLOSE_RANDOM",i,j,k)                         //10-03-22|0x024e
#define MacCmdCLOSE_RANDOM2(j,k) MacCmdCLOSE_RANDOM3(I_CLOSE_RANDOM,j,k)                  //10-03-22|0x024e
#define MacCmdCLOSE_RANDOM1(k) MacCmdCLOSE_RANDOM2(1,k)                                   //10-03-22|0x024e
#define MacCmd_CLOSE_RANDOM MacCmdCLOSE_RANDOM1(1)                                        //10-03-22|0x024e
#define MacCmdLOAD_RANDOM3(i,j,k) LoadCmd("_LOAD_RANDOM",i,j,k)                           //10-03-22|0x024f
#define MacCmdLOAD_RANDOM2(j,k) MacCmdLOAD_RANDOM3(I_LOAD_RANDOM,j,k)                     //10-03-22|0x024f
#define MacCmdLOAD_RANDOM1(k) MacCmdLOAD_RANDOM2(2,k)                                     //10-03-22|0x024f
#define MacCmd_LOAD_RANDOM MacCmdLOAD_RANDOM1(2)                                          //10-03-22|0x024f
#define MacCmdGET_RANDOM3(i,j,k) LoadCmd("_GET_RANDOM",i,j,k)                             //10-03-22|0x0250
#define MacCmdGET_RANDOM2(j,k) MacCmdGET_RANDOM3(I_GET_RANDOM,j,k)                        //10-03-22|0x0250
#define MacCmdGET_RANDOM1(k) MacCmdGET_RANDOM2(3,k)                                       //10-03-22|0x0250
#define MacCmd_GET_RANDOM MacCmdGET_RANDOM1(3)                                            //10-03-22|0x0250
#define MacCmdCOMPUTE_PARITY3(i,j,k) LoadCmd("_COMPUTE_PARITY",i,j,k)                     //10-03-22|0x0251
#define MacCmdCOMPUTE_PARITY2(j,k) MacCmdCOMPUTE_PARITY3(I_COMPUTE_PARITY,j,k)            //10-03-22|0x0251
#define MacCmdCOMPUTE_PARITY1(k) MacCmdCOMPUTE_PARITY2(2,k)                               //10-03-22|0x0251
#define MacCmd_COMPUTE_PARITY MacCmdCOMPUTE_PARITY1(2)                                    //10-03-22|0x0251
#define MacCmdGET_PARITY3(i,j,k) LoadCmd("_GET_PARITY",i,j,k)                             //10-03-23|0x0252
#define MacCmdGET_PARITY2(j,k) MacCmdGET_PARITY3(I_GET_PARITY,j,k)                        //10-03-23|0x0252
#define MacCmdGET_PARITY1(k) MacCmdGET_PARITY2(2,k)                                       //10-03-23|0x0252
#define MacCmd_GET_PARITY MacCmdGET_PARITY1(2)                                            //10-03-23|0x0252
#define MacCmdENCRYPT3(i,j,k) LoadCmd("_ENCRYPT",i,j,k)                                   //10-03-23|0x0253
#define MacCmdENCRYPT2(j,k) MacCmdENCRYPT3(I_ENCRYPT,j,k)                                 //10-03-23|0x0253
#define MacCmdENCRYPT1(k) MacCmdENCRYPT2(3,k)                                             //10-03-23|0x0253
#define MacCmd_ENCRYPT MacCmdENCRYPT1(3)                                                  //10-03-23|0x0253
#define MacCmdDECRYPT3(i,j,k) LoadCmd("_DECRYPT",i,j,k)                                   //check   |0x0254
#define MacCmdDECRYPT2(j,k) MacCmdDECRYPT3(I_DECRYPT,j,k)                                 //check   |0x0254
#define MacCmdDECRYPT1(k) MacCmdDECRYPT2(3,k)                                             //check   |0x0254
#define MacCmd_DECRYPT MacCmdDECRYPT1(3)                                                  //check   |0x0254
#define MacCmdTEST_CLASS3(i,j,k) LoadCmd("_TEST_CLASS",i,j,k)                             //07-07-18|0x025a
#define MacCmdTEST_CLASS2(j,k) MacCmdTEST_CLASS3(I_TEST_CLASS,j,k)                        //07-07-18|0x025a
#define MacCmdTEST_CLASS1(k) MacCmdTEST_CLASS2(2,k)                                       //07-07-18|0x025a
#define MacCmd_TEST_CLASS MacCmdTEST_CLASS1(2)                                            //07-07-18|0x025a
#define MacCmdTEST_PARM3(i,j,k) LoadCmd("_TEST_PARM",i,j,k)                               //07-02-17|0x0261
#define MacCmdTEST_PARM2(j,k) MacCmdTEST_PARM3(I_TEST_PARM,j,k)                           //07-02-17|0x0261
#define MacCmdTEST_PARM1(k) MacCmdTEST_PARM2(2,k)                                         //07-02-17|0x0261
#define MacCmd_TEST_PARM MacCmdTEST_PARM1(2)                                              //07-02-17|0x0261
#define MacCmdTEST_RETURN3(i,j,k) LoadCmd("_TEST_RETURN",i,j,k)                           //07-02-17|0x0262
#define MacCmdTEST_RETURN2(j,k) MacCmdTEST_RETURN3(I_TEST_RETURN,j,k)                     //07-02-17|0x0262
#define MacCmdTEST_RETURN1(k) MacCmdTEST_RETURN2(1,k)                                     //07-02-17|0x0262
#define MacCmd_TEST_RETURN MacCmdTEST_RETURN1(1)                                          //07-02-17|0x0262
#define MacContDEBUG_ON3(i,j,k) LoadCmd("_DEBUG_ON",i,j,k)                                //08-01-09|0x029c
#define MacContDEBUG_ON2(j,k) MacContDEBUG_ON3(I_DEBUG_ON,j,k)                            //08-01-09|0x029c
#define MacContDEBUG_ON1(k) MacContDEBUG_ON2(2,k)                                         //08-01-09|0x029c
#define MacCont_DEBUG_ON MacContDEBUG_ON1(2)                                              //08-01-09|0x029c
#define MacContJUMP_IF3(i,j,k) LoadCmd("_JUMP_IF",i,j,k)                                  //06-09-04|0x02a2
#define MacContJUMP_IF2(j,k) MacContJUMP_IF3(I_JUMP_IF,j,k)                               //06-09-04|0x02a2
#define MacContJUMP_IF1(k) MacContJUMP_IF2(2,k)                                           //06-09-04|0x02a2
#define MacCont_JUMP_IF MacContJUMP_IF1(2)                                                //06-09-04|0x02a2
#define MacContJUMP_IF_NOT3(i,j,k) LoadCmd("_JUMP_IF_NOT",i,j,k)                          //06-09-04|0x02a3
#define MacContJUMP_IF_NOT2(j,k) MacContJUMP_IF_NOT3(I_JUMP_IF_NOT,j,k)                   //06-09-04|0x02a3
#define MacContJUMP_IF_NOT1(k) MacContJUMP_IF_NOT2(2,k)                                   //06-09-04|0x02a3
#define MacCont_JUMP_IF_NOT MacContJUMP_IF_NOT1(2)                                        //06-09-04|0x02a3
#define MacContGET_FLAG3(i,j,k) LoadCmd("_GET_FLAG",i,j,k)                                //check   |0x02a4
#define MacContGET_FLAG2(j,k) MacContGET_FLAG3(I_GET_FLAG,j,k)                            //check   |0x02a4
#define MacContGET_FLAG1(k) MacContGET_FLAG2(2,k)                                         //check   |0x02a4
#define MacCont_GET_FLAG MacContGET_FLAG1(2)                                              //check   |0x02a4
#define MacContCONTINUE_IF3(i,j,k) LoadCmd("_CONTINUE_IF",i,j,k)                          //check   |0x02a6
#define MacContCONTINUE_IF2(j,k) MacContCONTINUE_IF3(I_CONTINUE_IF,j,k)                   //check   |0x02a6
#define MacContCONTINUE_IF1(k) MacContCONTINUE_IF2(1,k)                                   //check   |0x02a6
#define MacCont_CONTINUE_IF MacContCONTINUE_IF1(1)                                        //check   |0x02a6
#define MacContCONTINUE_IF_NOT3(i,j,k) LoadCmd("_CONTINUE_IF_NOT",i,j,k)                  //check   |0x02a7
#define MacContCONTINUE_IF_NOT2(j,k) MacContCONTINUE_IF_NOT3(I_CONTINUE_IF_NOT,j,k)       //check   |0x02a7
#define MacContCONTINUE_IF_NOT1(k) MacContCONTINUE_IF_NOT2(1,k)                           //check   |0x02a7
#define MacCont_CONTINUE_IF_NOT MacContCONTINUE_IF_NOT1(1)                                //check   |0x02a7
#define MacRuleDEBUG_ON3(i,j,k) LoadCmd("_DEBUG_ON",i,j,k)                                //08-01-09|0x030b
#define MacRuleDEBUG_ON2(j,k) MacRuleDEBUG_ON3(I_DEBUG_ON,j,k)                            //08-01-09|0x030b
#define MacRuleDEBUG_ON1(k) MacRuleDEBUG_ON2(2,k)                                         //08-01-09|0x030b
#define MacRule_DEBUG_ON MacRuleDEBUG_ON1(2)                                              //08-01-09|0x030b
#define MacRuleMOVE3(i,j,k) LoadCmd("_MOVE",i,j,k)                                        //06-12-23|0x0311
#define MacRuleMOVE2(j,k) MacRuleMOVE3(I_MOVE,j,k)                                        //06-12-23|0x0311
#define MacRuleMOVE1(k) MacRuleMOVE2(3,k)                                                 //06-12-23|0x0311
#define MacRule_MOVE MacRuleMOVE1(3)                                                      //06-12-23|0x0311
#define MacRuleEMIT3(i,j,k) LoadCmd("_EMIT",i,j,k)                                        //06-12-23|0x0312
#define MacRuleEMIT2(j,k) MacRuleEMIT3(I_EMIT,j,k)                                        //06-12-23|0x0312
#define MacRuleEMIT1(k) MacRuleEMIT2(4,k)                                                 //06-12-23|0x0312
#define MacRule_EMIT MacRuleEMIT1(10)                                                     //06-12-23|0x0312
#define MacRuleRULE_END3(i,j,k) LoadCmd("_RULE_END",i,j,k)                                //06-12-23|0x0314
#define MacRuleRULE_END2(j,k) MacRuleRULE_END3(I_RULE_END,j,k)                            //06-12-23|0x0314
#define MacRuleRULE_END1(k) MacRuleRULE_END2(1,k)                                         //06-12-23|0x0314
#define MacRule_RULE_END MacRuleRULE_END1(1)                                              //06-12-23|0x0314
#define MacRuleRULE_STATE3(i,j,k) LoadCmd("_RULE_STATE",i,j,k)                            //07-02-17|0x0315
#define MacRuleRULE_STATE2(j,k) MacRuleRULE_STATE3(I_RULE_STATE,j,k)                      //07-02-17|0x0315
#define MacRuleRULE_STATE1(k) MacRuleRULE_STATE2(1,k)                                     //07-02-17|0x0315
#define MacRule_RULE_STATE MacRuleRULE_STATE1(1)                                          //07-02-17|0x0315
#ifndef TestIndex                                                                         //06-09-04|0x0333
#define TestIndex 0                                                                       //06-09-04|0x0333
#endif                                                                                    //06-09-04|0x0333
//------------------------------------------------------------------------                //06-09-04|0x0333
enum {  begin_command_1 = TestIndex };                                                    //06-09-04|0x0333
//------------------------------------------------------------------------                //06-09-04|0x0333
#undef TestIndex                                                                          //06-09-04|0x0333
#define TestIndex begin_command_1+1                                                       //06-09-04|0x0333
//************************************************************************                //06-09-04|0x0333
#ifndef TestIndex                                                                         //06-09-04|0x0334
#define TestIndex 0                                                                       //06-09-04|0x0334
#endif                                                                                    //06-09-04|0x0334
//------------------------------------------------------------------------                //06-09-04|0x0334
enum {  begin_command_2 = TestIndex };                                                    //06-09-04|0x0334
//------------------------------------------------------------------------                //06-09-04|0x0334
#undef TestIndex                                                                          //06-09-04|0x0334
#define TestIndex begin_command_2+1                                                       //06-09-04|0x0334
//************************************************************************                //06-09-04|0x0334
#ifndef TestIndex                                                                         //11-02-14|0x0353
#define TestIndex 0                                                                       //11-02-14|0x0353
#endif                                                                                    //11-02-14|0x0353
//------------------------------------------------------------------------                //11-02-14|0x0353
enum {  begin_report_1 = TestIndex };                                                     //11-02-14|0x0353
//------------------------------------------------------------------------                //11-02-14|0x0353
#undef TestIndex                                                                          //11-02-14|0x0353
#define TestIndex begin_report_1+1                                                        //11-02-14|0x0353
//************************************************************************                //11-02-14|0x0353
#ifndef TestIndex                                                                         //11-02-14|0x0354
#define TestIndex 0                                                                       //11-02-14|0x0354
#endif                                                                                    //11-02-14|0x0354
//------------------------------------------------------------------------                //11-02-14|0x0354
enum {  begin_report_2 = TestIndex };                                                     //11-02-14|0x0354
//------------------------------------------------------------------------                //11-02-14|0x0354
#undef TestIndex                                                                          //11-02-14|0x0354
#define TestIndex begin_report_2+1                                                        //11-02-14|0x0354
//************************************************************************                //11-02-14|0x0354
#ifndef TestIndex                                                                         //07-05-22|0x037f
#define TestIndex 0                                                                       //07-05-22|0x037f
#endif                                                                                    //07-05-22|0x037f
//------------------------------------------------------------------------                //07-05-22|0x037f
enum {  utility_bridge_1 = TestIndex };                                                   //07-05-22|0x037f
//------------------------------------------------------------------------                //07-05-22|0x037f
#undef TestIndex                                                                          //07-05-22|0x037f
#define TestIndex utility_bridge_1+1                                                      //07-05-22|0x037f
//************************************************************************                //07-05-22|0x037f
#ifndef TestIndex                                                                         //07-04-25|0x039b
#define TestIndex 0                                                                       //07-04-25|0x039b
#endif                                                                                    //07-04-25|0x039b
//------------------------------------------------------------------------                //07-04-25|0x039b
enum {  begin_load_command_1 = TestIndex };                                               //07-04-25|0x039b
//------------------------------------------------------------------------                //07-04-25|0x039b
#undef TestIndex                                                                          //07-04-25|0x039b
#define TestIndex begin_load_command_1+1                                                  //07-04-25|0x039b
//************************************************************************                //07-04-25|0x039b
#ifndef TestIndex                                                                         //06-09-04|0x03b9
#define TestIndex 0                                                                       //06-09-04|0x03b9
#endif                                                                                    //06-09-04|0x03b9
//------------------------------------------------------------------------                //06-09-04|0x03b9
enum {  end_command_1 = TestIndex };                                                      //06-09-04|0x03b9
//------------------------------------------------------------------------                //06-09-04|0x03b9
#undef TestIndex                                                                          //06-09-04|0x03b9
#define TestIndex end_command_1+1                                                         //06-09-04|0x03b9
//************************************************************************                //06-09-04|0x03b9
#ifndef TestIndex                                                                         //06-09-04|0x03ba
#define TestIndex 0                                                                       //06-09-04|0x03ba
#endif                                                                                    //06-09-04|0x03ba
//------------------------------------------------------------------------                //06-09-04|0x03ba
enum {  end_command_2 = TestIndex };                                                      //06-09-04|0x03ba
//------------------------------------------------------------------------                //06-09-04|0x03ba
#undef TestIndex                                                                          //06-09-04|0x03ba
#define TestIndex end_command_2+1                                                         //06-09-04|0x03ba
//************************************************************************                //06-09-04|0x03ba
#ifndef TestIndex                                                                         //11-02-14|0x03bb
#define TestIndex 0                                                                       //11-02-14|0x03bb
#endif                                                                                    //11-02-14|0x03bb
//------------------------------------------------------------------------                //11-02-14|0x03bb
enum {  end_command_3 = TestIndex };                                                      //11-02-14|0x03bb
//------------------------------------------------------------------------                //11-02-14|0x03bb
#undef TestIndex                                                                          //11-02-14|0x03bb
#define TestIndex end_command_3+1                                                         //11-02-14|0x03bb
//************************************************************************                //11-02-14|0x03bb
#ifndef TestIndex                                                                         //06-09-04|0x0400
#define TestIndex 0                                                                       //06-09-04|0x0400
#endif                                                                                    //06-09-04|0x0400
//------------------------------------------------------------------------                //06-09-04|0x0400
enum {  error_command_1 = TestIndex };                                                    //06-09-04|0x0400
//------------------------------------------------------------------------                //06-09-04|0x0400
#undef TestIndex                                                                          //06-09-04|0x0400
#define TestIndex error_command_1+1                                                       //06-09-04|0x0400
//************************************************************************                //06-09-04|0x0400
#ifndef TestIndex                                                                         //06-09-04|0x041e
#define TestIndex 0                                                                       //06-09-04|0x041e
#endif                                                                                    //06-09-04|0x041e
//------------------------------------------------------------------------                //06-09-04|0x041e
enum {  load_label_command_1 = TestIndex };                                               //06-09-04|0x041e
//------------------------------------------------------------------------                //06-09-04|0x041e
#undef TestIndex                                                                          //06-09-04|0x041e
#define TestIndex load_label_command_1+1                                                  //06-09-04|0x041e
//************************************************************************                //06-09-04|0x041e
#ifndef TestIndex                                                                         //06-09-04|0x041f
#define TestIndex 0                                                                       //06-09-04|0x041f
#endif                                                                                    //06-09-04|0x041f
//------------------------------------------------------------------------                //06-09-04|0x041f
enum {  load_label_command_2 = TestIndex };                                               //06-09-04|0x041f
//------------------------------------------------------------------------                //06-09-04|0x041f
#undef TestIndex                                                                          //06-09-04|0x041f
#define TestIndex load_label_command_2+1                                                  //06-09-04|0x041f
//************************************************************************                //06-09-04|0x041f
#ifndef TestIndex                                                                         //08-01-09|0x0442
#define TestIndex 0                                                                       //08-01-09|0x0442
#endif                                                                                    //08-01-09|0x0442
//------------------------------------------------------------------------                //08-01-09|0x0442
enum {  enter_command_1 = TestIndex };                                                    //08-01-09|0x0442
//------------------------------------------------------------------------                //08-01-09|0x0442
#undef TestIndex                                                                          //08-01-09|0x0442
#define TestIndex enter_command_1+1                                                       //08-01-09|0x0442
//************************************************************************                //08-01-09|0x0442
#ifndef TestIndex                                                                         //08-01-09|0x0443
#define TestIndex 0                                                                       //08-01-09|0x0443
#endif                                                                                    //08-01-09|0x0443
//------------------------------------------------------------------------                //08-01-09|0x0443
enum {  enter_command_2 = TestIndex };                                                    //08-01-09|0x0443
//------------------------------------------------------------------------                //08-01-09|0x0443
#undef TestIndex                                                                          //08-01-09|0x0443
#define TestIndex enter_command_2+1                                                       //08-01-09|0x0443
//************************************************************************                //08-01-09|0x0443
#ifndef TestIndex                                                                         //08-01-09|0x0444
#define TestIndex 0                                                                       //08-01-09|0x0444
#endif                                                                                    //08-01-09|0x0444
//------------------------------------------------------------------------                //08-01-09|0x0444
enum {  enter_command_3 = TestIndex };                                                    //08-01-09|0x0444
//------------------------------------------------------------------------                //08-01-09|0x0444
#undef TestIndex                                                                          //08-01-09|0x0444
#define TestIndex enter_command_3+1                                                       //08-01-09|0x0444
//************************************************************************                //08-01-09|0x0444
#ifndef TestIndex                                                                         //14-12-03|0x0464
#define TestIndex 0                                                                       //14-12-03|0x0464
#endif                                                                                    //14-12-03|0x0464
//------------------------------------------------------------------------                //14-12-03|0x0464
enum {  basic_parity_1 = TestIndex };                                                     //14-12-03|0x0464
//------------------------------------------------------------------------                //14-12-03|0x0464
#undef TestIndex                                                                          //14-12-03|0x0464
#define TestIndex basic_parity_1+1                                                        //14-12-03|0x0464
//************************************************************************                //14-12-03|0x0464
#ifndef TestIndex                                                                         //14-12-03|0x0465
#define TestIndex 0                                                                       //14-12-03|0x0465
#endif                                                                                    //14-12-03|0x0465
//------------------------------------------------------------------------                //14-12-03|0x0465
enum {  basic_parity_2 = TestIndex };                                                     //14-12-03|0x0465
//------------------------------------------------------------------------                //14-12-03|0x0465
#undef TestIndex                                                                          //14-12-03|0x0465
#define TestIndex basic_parity_2+1                                                        //14-12-03|0x0465
//************************************************************************                //14-12-03|0x0465
#ifndef TestIndex                                                                         //14-12-03|0x0466
#define TestIndex 0                                                                       //14-12-03|0x0466
#endif                                                                                    //14-12-03|0x0466
//------------------------------------------------------------------------                //14-12-03|0x0466
enum {  basic_parity_3 = TestIndex };                                                     //14-12-03|0x0466
//------------------------------------------------------------------------                //14-12-03|0x0466
#undef TestIndex                                                                          //14-12-03|0x0466
#define TestIndex basic_parity_3+1                                                        //14-12-03|0x0466
//************************************************************************                //14-12-03|0x0466
#ifndef TestIndex                                                                         //14-12-03|0x0467
#define TestIndex 0                                                                       //14-12-03|0x0467
#endif                                                                                    //14-12-03|0x0467
//------------------------------------------------------------------------                //14-12-03|0x0467
enum {  basic_parity_4 = TestIndex };                                                     //14-12-03|0x0467
//------------------------------------------------------------------------                //14-12-03|0x0467
#undef TestIndex                                                                          //14-12-03|0x0467
#define TestIndex basic_parity_4+1                                                        //14-12-03|0x0467
//************************************************************************                //14-12-03|0x0467
#ifndef TestIndex                                                                         //14-12-03|0x0468
#define TestIndex 0                                                                       //14-12-03|0x0468
#endif                                                                                    //14-12-03|0x0468
//------------------------------------------------------------------------                //14-12-03|0x0468
enum {  basic_parity_5 = TestIndex };                                                     //14-12-03|0x0468
//------------------------------------------------------------------------                //14-12-03|0x0468
#undef TestIndex                                                                          //14-12-03|0x0468
#define TestIndex basic_parity_5+1                                                        //14-12-03|0x0468
//************************************************************************                //14-12-03|0x0468
#ifndef TestIndex                                                                         //06-09-04|0x04d3
#define TestIndex 0                                                                       //06-09-04|0x04d3
#endif                                                                                    //06-09-04|0x04d3
//------------------------------------------------------------------------                //06-09-04|0x04d3
enum {  load_label_name_1 = TestIndex };                                                  //06-09-04|0x04d3
//------------------------------------------------------------------------                //06-09-04|0x04d3
#undef TestIndex                                                                          //06-09-04|0x04d3
#define TestIndex load_label_name_1+1                                                     //06-09-04|0x04d3
//************************************************************************                //06-09-04|0x04d3
#ifndef TestIndex                                                                         //06-09-04|0x04d4
#define TestIndex 0                                                                       //06-09-04|0x04d4
#endif                                                                                    //06-09-04|0x04d4
//------------------------------------------------------------------------                //06-09-04|0x04d4
enum {  load_label_name_2 = TestIndex };                                                  //06-09-04|0x04d4
//------------------------------------------------------------------------                //06-09-04|0x04d4
#undef TestIndex                                                                          //06-09-04|0x04d4
#define TestIndex load_label_name_2+1                                                     //06-09-04|0x04d4
//************************************************************************                //06-09-04|0x04d4
#ifndef TestIndex                                                                         //06-09-04|0x04f8
#define TestIndex 0                                                                       //06-09-04|0x04f8
#endif                                                                                    //06-09-04|0x04f8
//------------------------------------------------------------------------                //06-09-04|0x04f8
enum {  prepare_label_name_1 = TestIndex };                                               //06-09-04|0x04f8
//------------------------------------------------------------------------                //06-09-04|0x04f8
#undef TestIndex                                                                          //06-09-04|0x04f8
#define TestIndex prepare_label_name_1+1                                                  //06-09-04|0x04f8
//************************************************************************                //06-09-04|0x04f8
#ifndef TestIndex                                                                         //06-09-05|0x052c
#define TestIndex 0                                                                       //06-09-05|0x052c
#endif                                                                                    //06-09-05|0x052c
//------------------------------------------------------------------------                //06-09-05|0x052c
enum {  load_dummy_label_1 = TestIndex };                                                 //06-09-05|0x052c
//------------------------------------------------------------------------                //06-09-05|0x052c
#undef TestIndex                                                                          //06-09-05|0x052c
#define TestIndex load_dummy_label_1+1                                                    //06-09-05|0x052c
//************************************************************************                //06-09-05|0x052c
#ifndef TestIndex                                                                         //06-09-04|0x0559
#define TestIndex 0                                                                       //06-09-04|0x0559
#endif                                                                                    //06-09-04|0x0559
//------------------------------------------------------------------------                //06-09-04|0x0559
enum {  open_macro_1 = TestIndex };                                                       //06-09-04|0x0559
//------------------------------------------------------------------------                //06-09-04|0x0559
#undef TestIndex                                                                          //06-09-04|0x0559
#define TestIndex open_macro_1+1                                                          //06-09-04|0x0559
//************************************************************************                //06-09-04|0x0559
#ifndef TestIndex                                                                         //06-09-04|0x0571
#define TestIndex 0                                                                       //06-09-04|0x0571
#endif                                                                                    //06-09-04|0x0571
//------------------------------------------------------------------------                //06-09-04|0x0571
enum {  read_macro_1 = TestIndex };                                                       //06-09-04|0x0571
//------------------------------------------------------------------------                //06-09-04|0x0571
#undef TestIndex                                                                          //06-09-04|0x0571
#define TestIndex read_macro_1+1                                                          //06-09-04|0x0571
//************************************************************************                //06-09-04|0x0571
#ifndef TestIndex                                                                         //06-09-04|0x0572
#define TestIndex 0                                                                       //06-09-04|0x0572
#endif                                                                                    //06-09-04|0x0572
//------------------------------------------------------------------------                //06-09-04|0x0572
enum {  read_macro_2 = TestIndex };                                                       //06-09-04|0x0572
//------------------------------------------------------------------------                //06-09-04|0x0572
#undef TestIndex                                                                          //06-09-04|0x0572
#define TestIndex read_macro_2+1                                                          //06-09-04|0x0572
//************************************************************************                //06-09-04|0x0572
#ifndef TestIndex                                                                         //06-09-04|0x0573
#define TestIndex 0                                                                       //06-09-04|0x0573
#endif                                                                                    //06-09-04|0x0573
//------------------------------------------------------------------------                //06-09-04|0x0573
enum {  read_macro_3 = TestIndex };                                                       //06-09-04|0x0573
//------------------------------------------------------------------------                //06-09-04|0x0573
#undef TestIndex                                                                          //06-09-04|0x0573
#define TestIndex read_macro_3+1                                                          //06-09-04|0x0573
//************************************************************************                //06-09-04|0x0573
#ifndef TestIndex                                                                         //06-09-04|0x0574
#define TestIndex 0                                                                       //06-09-04|0x0574
#endif                                                                                    //06-09-04|0x0574
//------------------------------------------------------------------------                //06-09-04|0x0574
enum {  read_macro_4 = TestIndex };                                                       //06-09-04|0x0574
//------------------------------------------------------------------------                //06-09-04|0x0574
#undef TestIndex                                                                          //06-09-04|0x0574
#define TestIndex read_macro_4+1                                                          //06-09-04|0x0574
//************************************************************************                //06-09-04|0x0574
#ifndef TestIndex                                                                         //06-09-04|0x059a
#define TestIndex 0                                                                       //06-09-04|0x059a
#endif                                                                                    //06-09-04|0x059a
//------------------------------------------------------------------------                //06-09-04|0x059a
enum {  close_macro_1 = TestIndex };                                                      //06-09-04|0x059a
//------------------------------------------------------------------------                //06-09-04|0x059a
#undef TestIndex                                                                          //06-09-04|0x059a
#define TestIndex close_macro_1+1                                                         //06-09-04|0x059a
//************************************************************************                //06-09-04|0x059a
//*******************************************************************************         //05-24-97|0x05c8
//*******************************************************************************         //05-24-97|0x05c8
//****                       END OF FILE                                     ****         //05-24-97|0x05c8
//*******************************************************************************         //05-24-97|0x05c8
//*******************************************************************************         //05-24-97|0x05c8
#endif                                                                                    //05-24-97|0x05c8
