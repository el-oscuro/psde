//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
// MACRO-LIBRARY MAIN ENGINE                                                              //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  The purpose of this program as well as instructions regarding its use is              //11-05-28|0x001b
//  defined in the associated manual.                                                     //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  This program is free software; you can redistribute it and/or modify                  //11-05-28|0x001b
//  it under the terms of the GNU General Public License as published by                  //11-05-28|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //11-05-28|0x001b
//  (at your option) any later version.                                                   //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//  This program is distributed in the hope that it will be useful,                       //11-05-28|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //11-05-28|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //11-05-28|0x001b
//  GNU General Public License for more details.                                          //11-05-28|0x001b
//                                                                                        //11-05-28|0x001b
//  You should have received a copy of the GNU General Public License                     //11-05-28|0x001b
//  along with this program; if not, write to the Free Software                           //11-05-28|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //11-05-28|0x001b
//  USA                                                                                   //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//  For further information, please contact Robert Adams:                                 //11-05-28|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //11-05-28|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //11-05-28|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
//*****************************************************************************           //11-05-28|0x001b
#ifndef macproj_hpp                                                                       //06-07-14|0x001c
#define macproj_hpp                                                                       //06-07-14|0x001c
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
//***************************************************************************             //06-07-14|0x003a
#define SystemMsg PcgSystemError("macproj", __LINE__);                                    //06-07-14|0x003b
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-14|0x003b
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-14|0x003b
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-14|0x003c
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-14|0x003c
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-14|0x003c
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-14|0x003c
#define _SwitchErr case UserError: return(UserError)                                      //06-07-14|0x003d
#define _SwitchOk case Success: break                                                     //06-07-14|0x003d
#define _SwitchEnd default: ReturnSystemError                                             //06-07-14|0x003d
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-14|0x003d
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-14|0x003d
#define _SwitchNo case No:       return(No)                                               //06-07-14|0x003d
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-14|0x003d
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-14|0x003d
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-14|0x003d
#define _SwitchBreak _SwitchGroup break                                                   //06-07-14|0x003d
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-14|0x003d
//***************************************************************************             //06-07-14|0x005d
//***************************************************************************             //06-07-14|0x005e
//******                                                               ******             //06-07-14|0x005f
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-14|0x0060
//******                                                               ******             //06-07-14|0x0061
//***************************************************************************             //06-07-14|0x0062
//***************************************************************************             //06-07-14|0x0063
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-14|0x0064
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-14|0x0064
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-14|0x0064
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-14|0x0064
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-14|0x0064
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-14|0x0064
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-14|0x0064
#define break_test(i) { TestSample(i);  break; }                                          //06-07-14|0x0064
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-14|0x0064
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-14|0x0064
//************************************************************************                //06-07-14|0x0064
#ifndef TestIndex                                                                         //06-07-14|0x0064
#define TestIndex 0                                                                       //06-07-14|0x0064
#endif                                                                                    //06-07-14|0x0064
//------------------------------------------------------------------------                //06-07-14|0x0064
enum {  NoTestSamples = TestIndex };                                                      //06-07-14|0x0064
//------------------------------------------------------------------------                //06-07-14|0x0064
#undef TestIndex                                                                          //06-07-14|0x0064
#define TestIndex NoTestSamples+1                                                         //06-07-14|0x0064
//************************************************************************                //06-07-14|0x0064
//***************************************************************************             //06-07-14|0x0065
//**********************************************************************                  //06-07-14|0x0066
#define MacroMacroDevelop macro_project_addr->macro_develop                               //06-07-14|0x0066
#define MacroProjectFile macro_project_addr->project_file                                 //06-07-14|0x0066
#define MacroTokens macro_project_addr->tokens                                            //06-07-14|0x0066
#define MacroWork macro_project_addr->work                                                //06-07-14|0x0066
#define MacroOutTime macro_project_addr->out_time                                         //06-07-14|0x0066
#define MacroExternalTime macro_project_addr->external_time                               //06-07-14|0x0066
#define MacroDevelopState macro_project_addr->develop_state                               //06-07-14|0x0066
#define MacroProcessState macro_project_addr->process_state                               //06-07-14|0x0066
#define MacroPrepareState macro_project_addr->prepare_state                               //06-07-14|0x0066
#define MacroBuildState macro_project_addr->build_state                                   //06-07-14|0x0066
#define MacroRunFlag macro_project_addr->run_flag                                         //06-07-14|0x0066
#define MacroStatus macro_project_addr->status                                            //06-07-14|0x0066
//----------------------------------------------------------------------                  //06-07-14|0x0066
#define MacroBridgeAddr &(macro_project_addr->bridge)                                     //06-07-14|0x0066
#define MacroTokensAddr &(macro_project_addr->tokens)                                     //06-07-14|0x0066
#define MacroWorkAddr &(macro_project_addr->work)                                         //06-07-14|0x0066
#define MacroProjectFileAddr &(macro_project_addr->project_file)                          //06-07-14|0x0066
#define MacroMacroDevelopAddr &(macro_project_addr->macro_develop)                        //06-07-14|0x0066
#define MacroOutTimeAddr &(macro_project_addr->out_time)                                  //06-07-14|0x0066
//**********************************************************************                  //11-02-17|0x0067
#define MacroDevelopStatus MacroMacroDevelop.develop_status                               //11-02-17|0x0067
#define MacroMacroFile MacroMacroDevelop.macro_file                                       //11-02-17|0x0067
#define MacroInTime MacroMacroDevelop.in_time                                             //11-02-17|0x0067
//----------------------------------------------------------------------                  //11-02-17|0x0067
#define MacroMacroFileAddr &(MacroMacroDevelop.macro_file)                                //11-02-17|0x0067
#define MacroInTimeAddr &(MacroMacroDevelop.in_time)                                      //11-02-17|0x0067
//************************************************************************                //06-07-14|0x0068
#define TokensTokenAddr(i) &(MacroTokens.token[i])                                        //06-07-14|0x0068
#define TokensMacroLineNo(i) MacroTokens.token[i].macro_line_no                           //06-07-14|0x0068
#define TokensLineAddr(i) &(MacroTokens.token[i].line[0])                                 //06-07-14|0x0068
#define TokensToken(i) MacroTokens.token[i]                                               //06-07-14|0x0068
#define TokensLine(i) MacroTokens.token[i].line                                           //06-07-14|0x0068
#define TokensLength(i) MacroTokens.token[i].length                                       //06-07-14|0x0068
#define TokensColumn(i) MacroTokens.token[i].column                                       //06-07-14|0x0068
#define TokensHash(i) MacroTokens.token[i].hash                                           //06-07-14|0x0068
#define TokensPosition(i) MacroTokens.token[i].position                                   //06-07-14|0x0068
#define TokensType(i) MacroTokens.token[i].type                                           //06-07-14|0x0068
#define TokensStartCol(i) MacroTokens.token[i].start_col                                  //06-07-14|0x0068
#define TokensStartCall(i) MacroTokens.token[i].start_call                                //06-07-14|0x0068
#define TokensChar(i,j) MacroTokens.token[i].line[j]                                      //06-07-14|0x0068
#define TokensNoTokens MacroTokens.no_tokens                                              //06-07-14|0x0068
#define BridgeChar(i) MacroBridge.line[i]                                                 //06-07-14|0x0069
#define BridgeLine MacroBridge.line[0]                                                    //06-07-14|0x0069
#define BridgeLineAddr &(MacroBridge.line[0])                                             //06-07-14|0x0069
#define BridgeMacroLineNo MacroBridge.macro_line_no                                       //06-07-14|0x0069
#define BridgeType MacroBridge.type                                                       //06-07-14|0x0069
#define BridgeStartCol MacroBridge.start_col                                              //06-07-14|0x0069
#define BridgeStartCall MacroBridge.start_call                                            //06-07-14|0x0069
#define BridgePosition MacroBridge.position                                               //06-07-14|0x0069
#define BridgeLength MacroBridge.length                                                   //06-07-14|0x0069
#define BridgeColumn MacroBridge.column                                                   //06-07-14|0x0069
//**********************************************************************                  //06-07-14|0x0069
#define WorkChar(i) MacroWork.line[i]                                                     //06-07-14|0x006a
#define WorkLine MacroWork.line[0]                                                        //06-07-14|0x006a
#define WorkLineAddr &(MacroWork.line[0])                                                 //06-07-14|0x006a
#define WorkMacroLineNo MacroWork.macro_line_no                                           //06-07-14|0x006a
#define WorkType MacroWork.type                                                           //06-07-14|0x006a
#define WorkStartCol MacroWork.start_col                                                  //06-07-14|0x006a
#define WorkStartCall MacroWork.start_call                                                //06-07-14|0x006a
#define WorkPosition MacroWork.position                                                   //06-07-14|0x006a
#define WorkLength MacroWork.length                                                       //06-07-14|0x006a
#define WorkColumn MacroWork.column                                                       //06-07-14|0x006a
//**********************************************************************                  //06-07-14|0x006a
//************************************************************************                //06-07-14|0x006c
#define InputTokenAddr(i) &(InputAddr->token[i])                                          //06-07-14|0x006c
#define InputMacroLineNo(i) InputAddr->token[i].macro_line_no                             //06-07-14|0x006c
#define InputLineAddr(i) &(InputAddr->token[i].line[0])                                   //06-07-14|0x006c
#define InputToken(i) InputAddr->token[i]                                                 //06-07-14|0x006c
#define InputLine(i) InputAddr->token[i].line                                             //06-07-14|0x006c
#define InputLength(i) InputAddr->token[i].length                                         //06-07-14|0x006c
#define InputColumn(i) InputAddr->token[i].column                                         //06-07-14|0x006c
#define InputHash(i) InputAddr->token[i].hash                                             //06-07-14|0x006c
#define InputPosition(i) InputAddr->token[i].position                                     //06-07-14|0x006c
#define InputType(i) InputAddr->token[i].type                                             //06-07-14|0x006c
#define InputStartCol(i) InputAddr->token[i].start_col                                    //06-07-14|0x006c
#define InputStartCall(i) InputAddr->token[i].start_call                                  //06-07-14|0x006c
#define InputChar(i,j) InputAddr->token[i].line[j]                                        //06-07-14|0x006c
#define InputNoTokens InputAddr->no_tokens                                                //06-07-14|0x006c
#define ProjectDoesNotExist Finish("Project File Does Not Exist")                         //06-07-14|0x006e
#define MacroDoesNotExist Finish("Macro File Does Not Exist")                             //06-07-14|0x006e
#define LibraryDoesNotExist Finish("Subject Library File Does Not Exist")                 //06-07-14|0x006e
#define LibraryConflict Finish("Subject Library Not Released")                            //06-07-14|0x006e
#define AppendDoesNotExist Finish("Append Library File Does Not Exist")                   //06-07-14|0x006e
#define IllegalCommand Finish("Illegal Command")                                          //06-07-14|0x006e
#define IllegalEndOfFile Finish("Illegal End Of File")                                    //06-07-14|0x006e
#define MacProjPrepare macproj_prepare(InputAddr, TaskNoFar)                              //06-07-14|0x006e
#define MacProjBuild macproj_build(InputAddr)                                             //06-07-14|0x006e
#define IfNoTokens1(i) (TokensNoTokens < i)                                               //06-07-14|0x006e
#define IfNoTokens2(i) (TokensNoTokens > i)                                               //06-07-14|0x006e
#define IfNoTokens(i,j) if(IfNoTokens1(i) || IfNoTokens2(j))                              //06-07-14|0x006e
#define CmdTest(i) StrCmp(TokensLineAddr(0),i)                                            //06-07-14|0x006e
#define FileTextPrepare1(i) TextPrepare(TokensTokenAddr(0), i)                            //06-07-14|0x006e
#define FileTextPrepare FileTextPrepare1(TokensTokenAddr(1))                              //06-07-14|0x006e
#define UpdateTaskNo update_task_no(TaskNoFar)                                            //06-07-14|0x006e
#define StrDataCpy(i,j) MemCpy(i,j,sizeof(STRING_DATA))                                   //06-07-14|0x006e
#define EnterProjectName2(i,j) enter_name(MacroProjectFileAddr, i, j)                     //06-07-14|0x006e
#define EnterProjectName1(i) EnterProjectName2(InputAddr, i)                              //06-07-14|0x006e
#define EnterProjectName EnterProjectName1(PMK_EXTENT)                                    //06-07-14|0x006e
#define ProjectFileTime file_time(MacroProjectFileAddr)                                   //06-07-14|0x006e
#define OpenProject open_project(MacroProjectFileAddr)                                    //06-07-14|0x006e
#define ReadProject read_project(MacroProjectFileAddr)                                    //06-07-14|0x006e
#define CloseProject close_project(MacroProjectFileAddr)                                  //06-07-14|0x006e
#define StartParity MacDictStartParity(MacroTokensAddr)                                   //06-07-14|0x006e
#define EnterLibraryName MacDictName(TokensLineAddr(0),    PLB_EXTENT)                    //06-07-14|0x006e
#define LibraryDate MacDictExists(MacroOutTimeAddr)                                       //06-07-14|0x006e
#define EnterMacroName2(i,j) enter_name(MacroMacroFileAddr, i, j)                         //06-07-14|0x006e
#define EnterMacroName1(i) EnterMacroName2(MacroTokensAddr, i)                            //06-07-14|0x006e
#define EnterMacroName EnterMacroName1(MAC_EXTENT)                                        //06-07-14|0x006e
#define MacroFileTime file_time(MacroMacroFileAddr)                                       //06-07-14|0x006e
#define MacroCreateCertify MacCertCreate(InputTokenAddr(0))                               //06-07-14|0x006e
#define MacroInitialCertify MacCertInitial(TokensTokenAddr(2))                            //06-07-14|0x006e
#define EnterAppendName ApndDictName(TokensLineAddr(0),   PLB_EXTENT)                     //06-07-14|0x006e
#define AppendFileTime ApndDictExists(MacroInTimeAddr)                                    //06-07-14|0x006e
#define MacroBeginCert MacCertMacroBegin()                                                //06-07-14|0x006e
#define ProcessMacro PrecmacProcess(MacroMacroDevelopAddr)                                //06-07-14|0x006e
#define AppendLibrary MacDictAppend()                                                     //06-07-14|0x006e
#define ProcessAppend ApndApndDict()                                                      //06-07-14|0x006e
#define ExternalDateTest1 MacroExternalTime > MacroInTime                                 //06-07-14|0x006e
#define ExternalDateTest2 MacroInTime = MacroExternalTime                                 //06-07-14|0x006e
#define ExternalDateTest if(ExternalDateTest1)  ExternalDateTest2                         //06-07-14|0x006e
#define FileInDateExists ((MacroInTime  > 0) ? Yes : No)                                  //06-07-14|0x006e
#define FileOutDateExists ((MacroOutTime > 0) ? Yes : No)                                 //06-07-14|0x006e
#define BasicDateTest1 MacroInTime > MacroOutTime                                         //06-07-14|0x006e
#define BasicDateTest2(i) MacroDevelopState |= i                                          //06-07-14|0x006e
#define BasicDateTest(i) if(BasicDateTest1)   BasicDateTest2(i)                           //06-07-14|0x006e
#define LoadAppendParity MacCertAppend(MacroDevelopStatus)                                //06-07-14|0x006e
#define FileUpdateRequired ((MacroDevelopState  > 0) ? Yes : No)                          //06-07-14|0x006e
#define BeginParityMacro MacCertMacroBegin()                                              //06-07-14|0x006e
#define EndParityMacro MacCertEnd()                                                       //06-07-14|0x006e
#define FinishParityMacro MacCertFinish(MacroDevelopStatus)                               //06-07-14|0x006e
#define InitialFile FileInitialText(TextFileAddr)                                         //06-07-14|0x006e
#define CommitFile FileCommitText(TextFileAddr)                                           //06-07-14|0x006e
#define EnterFileName FileEnterName(InputLineAddr(0), Extent)                             //06-07-14|0x006e
#define CMK_EXTENT ".cmk"                                                                 //06-07-14|0x0070
#define TMK_EXTENT ".tmk"                                                                 //06-07-14|0x0070
#define RPT_EXTENT ".rpt"                                                                 //06-07-14|0x0070
#define PMK_EXTENT ".pmk"                                                                 //06-07-14|0x0070
#define MAC_EXTENT ".mac"                                                                 //06-07-14|0x0070
#define SRC_EXTENT ".src"                                                                 //06-07-14|0x0070
#define PLB_EXTENT ".plb"                                                                 //06-07-14|0x0070
#define DIC_EXTENT ".dic"                                                                 //06-07-14|0x0070
#define MBX_EXTENT ".mbx"                                                                 //06-07-14|0x0070
#define MBC_EXTENT ".mbc"                                                                 //06-07-14|0x0070
#define RAN_EXTENT ".ran"                                                                 //06-07-14|0x0070
#define BUF_OUT_EXTENT ".bfo"                                                             //06-07-14|0x0070
#define BUF_IN_EXTENT ".bfi"                                                              //06-07-14|0x0070
#ifndef TestIndex                                                                         //06-07-14|0x007b
#define TestIndex 0                                                                       //06-07-14|0x007b
#endif                                                                                    //06-07-14|0x007b
//------------------------------------------------------------------------                //06-07-14|0x007b
enum {  macproj_allocate_1 = TestIndex };                                                 //06-07-14|0x007b
//------------------------------------------------------------------------                //06-07-14|0x007b
#undef TestIndex                                                                          //06-07-14|0x007b
#define TestIndex macproj_allocate_1+1                                                    //06-07-14|0x007b
//************************************************************************                //06-07-14|0x007b
#ifndef TestIndex                                                                         //06-07-14|0x0097
#define TestIndex 0                                                                       //06-07-14|0x0097
#endif                                                                                    //06-07-14|0x0097
//------------------------------------------------------------------------                //06-07-14|0x0097
enum {  macproj_free_1 = TestIndex };                                                     //06-07-14|0x0097
//------------------------------------------------------------------------                //06-07-14|0x0097
#undef TestIndex                                                                          //06-07-14|0x0097
#define TestIndex macproj_free_1+1                                                        //06-07-14|0x0097
//************************************************************************                //06-07-14|0x0097
#ifndef TestIndex                                                                         //06-08-16|0x02a4
#define TestIndex 0                                                                       //06-08-16|0x02a4
#endif                                                                                    //06-08-16|0x02a4
//------------------------------------------------------------------------                //06-08-16|0x02a4
enum {  enter_name_1 = TestIndex };                                                       //06-08-16|0x02a4
//------------------------------------------------------------------------                //06-08-16|0x02a4
#undef TestIndex                                                                          //06-08-16|0x02a4
#define TestIndex enter_name_1+1                                                          //06-08-16|0x02a4
//************************************************************************                //06-08-16|0x02a4
#ifndef TestIndex                                                                         //06-08-16|0x02bc
#define TestIndex 0                                                                       //06-08-16|0x02bc
#endif                                                                                    //06-08-16|0x02bc
//------------------------------------------------------------------------                //06-08-16|0x02bc
enum {  file_time_1 = TestIndex };                                                        //06-08-16|0x02bc
//------------------------------------------------------------------------                //06-08-16|0x02bc
#undef TestIndex                                                                          //06-08-16|0x02bc
#define TestIndex file_time_1+1                                                           //06-08-16|0x02bc
//************************************************************************                //06-08-16|0x02bc
#ifndef TestIndex                                                                         //06-08-17|0x02d3
#define TestIndex 0                                                                       //06-08-17|0x02d3
#endif                                                                                    //06-08-17|0x02d3
//------------------------------------------------------------------------                //06-08-17|0x02d3
enum {  open_project_1 = TestIndex };                                                     //06-08-17|0x02d3
//------------------------------------------------------------------------                //06-08-17|0x02d3
#undef TestIndex                                                                          //06-08-17|0x02d3
#define TestIndex open_project_1+1                                                        //06-08-17|0x02d3
//************************************************************************                //06-08-17|0x02d3
#ifndef TestIndex                                                                         //06-08-17|0x02eb
#define TestIndex 0                                                                       //06-08-17|0x02eb
#endif                                                                                    //06-08-17|0x02eb
//------------------------------------------------------------------------                //06-08-17|0x02eb
enum {  read_project_1 = TestIndex };                                                     //06-08-17|0x02eb
//------------------------------------------------------------------------                //06-08-17|0x02eb
#undef TestIndex                                                                          //06-08-17|0x02eb
#define TestIndex read_project_1+1                                                        //06-08-17|0x02eb
//************************************************************************                //06-08-17|0x02eb
#ifndef TestIndex                                                                         //06-08-17|0x02ec
#define TestIndex 0                                                                       //06-08-17|0x02ec
#endif                                                                                    //06-08-17|0x02ec
//------------------------------------------------------------------------                //06-08-17|0x02ec
enum {  read_project_2 = TestIndex };                                                     //06-08-17|0x02ec
//------------------------------------------------------------------------                //06-08-17|0x02ec
#undef TestIndex                                                                          //06-08-17|0x02ec
#define TestIndex read_project_2+1                                                        //06-08-17|0x02ec
//************************************************************************                //06-08-17|0x02ec
#ifndef TestIndex                                                                         //06-08-17|0x02ed
#define TestIndex 0                                                                       //06-08-17|0x02ed
#endif                                                                                    //06-08-17|0x02ed
//------------------------------------------------------------------------                //06-08-17|0x02ed
enum {  read_project_3 = TestIndex };                                                     //06-08-17|0x02ed
//------------------------------------------------------------------------                //06-08-17|0x02ed
#undef TestIndex                                                                          //06-08-17|0x02ed
#define TestIndex read_project_3+1                                                        //06-08-17|0x02ed
//************************************************************************                //06-08-17|0x02ed
#ifndef TestIndex                                                                         //06-08-17|0x02ee
#define TestIndex 0                                                                       //06-08-17|0x02ee
#endif                                                                                    //06-08-17|0x02ee
//------------------------------------------------------------------------                //06-08-17|0x02ee
enum {  read_project_4 = TestIndex };                                                     //06-08-17|0x02ee
//------------------------------------------------------------------------                //06-08-17|0x02ee
#undef TestIndex                                                                          //06-08-17|0x02ee
#define TestIndex read_project_4+1                                                        //06-08-17|0x02ee
//************************************************************************                //06-08-17|0x02ee
#ifndef TestIndex                                                                         //09-03-27|0x0314
#define TestIndex 0                                                                       //09-03-27|0x0314
#endif                                                                                    //09-03-27|0x0314
//------------------------------------------------------------------------                //09-03-27|0x0314
enum {  update_task_no_1 = TestIndex };                                                   //09-03-27|0x0314
//------------------------------------------------------------------------                //09-03-27|0x0314
#undef TestIndex                                                                          //09-03-27|0x0314
#define TestIndex update_task_no_1+1                                                      //09-03-27|0x0314
//************************************************************************                //09-03-27|0x0314
#ifndef TestIndex                                                                         //11-06-13|0x0332
#define TestIndex 0                                                                       //11-06-13|0x0332
#endif                                                                                    //11-06-13|0x0332
//------------------------------------------------------------------------                //11-06-13|0x0332
enum {  enable_display_1 = TestIndex };                                                   //11-06-13|0x0332
//------------------------------------------------------------------------                //11-06-13|0x0332
#undef TestIndex                                                                          //11-06-13|0x0332
#define TestIndex enable_display_1+1                                                      //11-06-13|0x0332
//************************************************************************                //11-06-13|0x0332
#ifndef TestIndex                                                                         //07-10-30|0x0349
#define TestIndex 0                                                                       //07-10-30|0x0349
#endif                                                                                    //07-10-30|0x0349
//------------------------------------------------------------------------                //07-10-30|0x0349
enum {  uncond_update_1 = TestIndex };                                                    //07-10-30|0x0349
//------------------------------------------------------------------------                //07-10-30|0x0349
#undef TestIndex                                                                          //07-10-30|0x0349
#define TestIndex uncond_update_1+1                                                       //07-10-30|0x0349
//************************************************************************                //07-10-30|0x0349
#ifndef TestIndex                                                                         //11-02-12|0x0361
#define TestIndex 0                                                                       //11-02-12|0x0361
#endif                                                                                    //11-02-12|0x0361
//------------------------------------------------------------------------                //11-02-12|0x0361
enum {  set_version_1 = TestIndex };                                                      //11-02-12|0x0361
//------------------------------------------------------------------------                //11-02-12|0x0361
#undef TestIndex                                                                          //11-02-12|0x0361
#define TestIndex set_version_1+1                                                         //11-02-12|0x0361
//************************************************************************                //11-02-12|0x0361
#ifndef TestIndex                                                                         //06-08-17|0x0376
#define TestIndex 0                                                                       //06-08-17|0x0376
#endif                                                                                    //06-08-17|0x0376
//------------------------------------------------------------------------                //06-08-17|0x0376
enum {  text_prepare_1 = TestIndex };                                                     //06-08-17|0x0376
//------------------------------------------------------------------------                //06-08-17|0x0376
#undef TestIndex                                                                          //06-08-17|0x0376
#define TestIndex text_prepare_1+1                                                        //06-08-17|0x0376
//************************************************************************                //06-08-17|0x0376
#ifndef TestIndex                                                                         //11-02-14|0x038c
#define TestIndex 0                                                                       //11-02-14|0x038c
#endif                                                                                    //11-02-14|0x038c
//------------------------------------------------------------------------                //11-02-14|0x038c
enum {  create_report_1 = TestIndex };                                                    //11-02-14|0x038c
//------------------------------------------------------------------------                //11-02-14|0x038c
#undef TestIndex                                                                          //11-02-14|0x038c
#define TestIndex create_report_1+1                                                       //11-02-14|0x038c
//************************************************************************                //11-02-14|0x038c
#ifndef TestIndex                                                                         //06-08-18|0x03a2
#define TestIndex 0                                                                       //06-08-18|0x03a2
#endif                                                                                    //06-08-18|0x03a2
//------------------------------------------------------------------------                //06-08-18|0x03a2
enum {  create_library_1 = TestIndex };                                                   //06-08-18|0x03a2
//------------------------------------------------------------------------                //06-08-18|0x03a2
#undef TestIndex                                                                          //06-08-18|0x03a2
#define TestIndex create_library_1+1                                                      //06-08-18|0x03a2
//************************************************************************                //06-08-18|0x03a2
#ifndef TestIndex                                                                         //06-08-17|0x03b9
#define TestIndex 0                                                                       //06-08-17|0x03b9
#endif                                                                                    //06-08-17|0x03b9
//------------------------------------------------------------------------                //06-08-17|0x03b9
enum {  close_project_1 = TestIndex };                                                    //06-08-17|0x03b9
//------------------------------------------------------------------------                //06-08-17|0x03b9
#undef TestIndex                                                                          //06-08-17|0x03b9
#define TestIndex close_project_1+1                                                       //06-08-17|0x03b9
//************************************************************************                //06-08-17|0x03b9
//*******************************************************************************         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
//****                       END OF FILE                                     ****         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
//*******************************************************************************         //05-24-97|0x03ea
#endif                                                                                    //05-24-97|0x03ea
