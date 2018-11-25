//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
// TEST PROJECT                                                                           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x0008
//  defined in the associated manual.                                                     //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x0008
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x0008
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x0008
//  (at your option) any later version.                                                   //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x0008
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x0008
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x0008
//  GNU General Public License for more details.                                          //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x0008
//  along with this program; if not, write to the Free Software                           //06-07-12|0x0008
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x0008
//  USA                                                                                   //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//  For further information, please contact Robert Adams:                                 //06-07-12|0x0008
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x0008
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x0008
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
#ifndef testproj_hpp                                                                      //06-07-12|0x000b
#define testproj_hpp                                                                      //06-07-12|0x000b
//***************************************************************************             //06-07-12|0x0019
//***************************************************************************             //06-07-12|0x001a
//******                                                               ******             //06-07-12|0x001b
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x001c
//******                                                               ******             //06-07-12|0x001d
//***************************************************************************             //06-07-12|0x001e
//***************************************************************************             //06-07-12|0x001f
#define CMK_EXTENT ".cmk"                                                                 //06-07-12|0x0022
#define TMK_EXTENT ".tmk"                                                                 //06-07-12|0x0022
#define RPT_EXTENT ".rpt"                                                                 //06-07-12|0x0022
#define PMK_EXTENT ".pmk"                                                                 //06-07-12|0x0022
#define MAC_EXTENT ".mac"                                                                 //06-07-12|0x0022
#define SRC_EXTENT ".src"                                                                 //06-07-12|0x0022
#define PLB_EXTENT ".plb"                                                                 //06-07-12|0x0022
#define DIC_EXTENT ".dic"                                                                 //06-07-12|0x0022
#define MBX_EXTENT ".mbx"                                                                 //06-07-12|0x0022
#define MBC_EXTENT ".mbc"                                                                 //06-07-12|0x0022
#define RAN_EXTENT ".ran"                                                                 //06-07-12|0x0022
#define BUF_OUT_EXTENT ".bfo"                                                             //06-07-12|0x0022
#define BUF_IN_EXTENT ".bfi"                                                              //06-07-12|0x0022
//***************************************************************************             //06-07-12|0x0023
//***************************************************************************             //06-07-12|0x0024
//******                                                               ******             //06-07-12|0x0025
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x0026
//******                                                               ******             //06-07-12|0x0027
//***************************************************************************             //06-07-12|0x0028
//***************************************************************************             //06-07-12|0x0029
#define UserError 0x0000                                                                  //06-07-12|0x002a
#define BuildError 0x7fff                                                                 //06-07-12|0x002a
#define Display 0x7ffe                                                                    //06-07-12|0x002a
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x002a
#define Success 0xffff                                                                    //06-07-12|0x002a
#define SystemError 0x8000                                                                //06-07-12|0x002a
#define Continue 0x0001                                                                   //06-07-12|0x002a
#define FileDone 0x0002                                                                   //06-07-12|0x002a
#define LineDone 0x0003                                                                   //06-07-12|0x002a
#define Yes 0x0004                                                                        //06-07-12|0x002a
#define No 0x0005                                                                         //06-07-12|0x002a
#define RepeatChar '\x6'                                                                  //06-07-12|0x002a
#define Great 0x0007                                                                      //06-07-12|0x002a
#define Equal 0x0008                                                                      //06-07-12|0x002a
#define Less 0x0009                                                                       //06-07-12|0x002a
#define Zero 0x000a                                                                       //06-07-12|0x002a
#define Minus 0x000b                                                                      //06-07-12|0x002a
//***************************************************************************             //06-07-12|0x002b
#define SystemMsg PcgSystemError("testproj", __LINE__);                                   //06-07-12|0x002c
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x002c
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x002c
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x002d
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x002d
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x002d
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x002d
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x002e
#define _SwitchOk case Success: break                                                     //06-07-12|0x002e
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x002e
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x002e
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x002e
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x002e
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x002e
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x002e
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x002e
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x002e
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x002e
//***************************************************************************             //06-07-12|0x0056
//***************************************************************************             //06-07-12|0x0057
//******                                                               ******             //06-07-12|0x0058
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0059
//******                                                               ******             //06-07-12|0x005a
//***************************************************************************             //06-07-12|0x005b
//***************************************************************************             //06-07-12|0x005c
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x005d
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x005d
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x005d
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x005d
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-12|0x005d
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-12|0x005d
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x005d
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x005d
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x005d
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x005d
//************************************************************************                //06-07-12|0x005d
#ifndef TestIndex                                                                         //06-07-12|0x005d
#define TestIndex 0                                                                       //06-07-12|0x005d
#endif                                                                                    //06-07-12|0x005d
//------------------------------------------------------------------------                //06-07-12|0x005d
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x005d
//------------------------------------------------------------------------                //06-07-12|0x005d
#undef TestIndex                                                                          //06-07-12|0x005d
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x005d
//************************************************************************                //06-07-12|0x005d
//***************************************************************************             //06-07-12|0x005e
//************************************************************************                //06-07-12|0x005f
#define InputTokenAddr(i) &(InputTokensFar->token[i])                                     //06-07-12|0x005f
#define InputMacroLineNo(i) InputTokensFar->token[i].macro_line_no                        //06-07-12|0x005f
#define InputLineAddr(i) &(InputTokensFar->token[i].line[0])                              //06-07-12|0x005f
#define InputToken(i) InputTokensFar->token[i]                                            //06-07-12|0x005f
#define InputLine(i) InputTokensFar->token[i].line                                        //06-07-12|0x005f
#define InputLength(i) InputTokensFar->token[i].length                                    //06-07-12|0x005f
#define InputColumn(i) InputTokensFar->token[i].column                                    //06-07-12|0x005f
#define InputHash(i) InputTokensFar->token[i].hash                                        //06-07-12|0x005f
#define InputPosition(i) InputTokensFar->token[i].position                                //06-07-12|0x005f
#define InputType(i) InputTokensFar->token[i].type                                        //06-07-12|0x005f
#define InputStartCol(i) InputTokensFar->token[i].start_col                               //06-07-12|0x005f
#define InputStartCall(i) InputTokensFar->token[i].start_call                             //06-07-12|0x005f
#define InputChar(i,j) InputTokensFar->token[i].line[j]                                   //06-07-12|0x005f
#define InputNoTokens InputTokensFar->no_tokens                                           //06-07-12|0x005f
//***************************************************************************             //06-07-12|0x0060
#define BaseData test_proj_addr->data                                                     //06-07-12|0x0061
#define BaseProject test_proj_addr->project                                               //06-07-12|0x0061
#define BaseReport test_proj_addr->report                                                 //06-07-12|0x0061
#define BaseTokens test_proj_addr->tokens                                                 //06-07-12|0x0061
#define BaseDrivePath test_proj_addr->drive_path                                          //06-07-12|0x0061
#define BaseDisplayFlag test_proj_addr->display_flag                                      //06-07-12|0x0061
#define BaseState test_proj_addr->state                                                   //06-07-12|0x0061
#define BaseRunFlag test_proj_addr->run_flag                                              //06-07-12|0x0061
#define BaseStatus test_proj_addr->status                                                 //06-07-12|0x0061
#define BaseOutput test_proj_addr->output                                                 //06-07-12|0x0061
#define BaseSummary test_proj_addr->summary                                               //06-07-12|0x0061
#define BaseTestTime test_proj_addr->test_time                                            //06-07-12|0x0061
#define BaseTaskNo test_proj_addr->task_no                                                //06-07-12|0x0061
//----------------------------------------------------------------------                  //06-07-12|0x0061
#define BaseDataAddr &(test_proj_addr->data)                                              //06-07-12|0x0061
#define BaseProjectAddr &(test_proj_addr->project)                                        //06-07-12|0x0061
#define BaseReportAddr &(test_proj_addr->report)                                          //06-07-12|0x0061
#define BaseTokensAddr &(test_proj_addr->tokens)                                          //06-07-12|0x0061
#define BaseDrivePathAddr &(test_proj_addr->drive_path)                                   //06-07-12|0x0061
#define BaseOutputAddr &(test_proj_addr->output)                                          //06-07-12|0x0061
#define BaseSummaryAddr &(test_proj_addr->summary)                                        //06-07-12|0x0061
#define BaseTestTimeAddr &(test_proj_addr->test_time)                                     //06-07-12|0x0061
#define BaseTaskNoAddr &(test_proj_addr->task_no)                                         //06-07-12|0x0061
//***************************************************************************             //06-07-12|0x0062
//************************************************************************                //06-07-12|0x0063
#define TokensTokenAddr(i) &(BaseTokens.token[i])                                         //06-07-12|0x0063
#define TokensMacroLineNo(i) BaseTokens.token[i].macro_line_no                            //06-07-12|0x0063
#define TokensLineAddr(i) &(BaseTokens.token[i].line[0])                                  //06-07-12|0x0063
#define TokensToken(i) BaseTokens.token[i]                                                //06-07-12|0x0063
#define TokensLine(i) BaseTokens.token[i].line                                            //06-07-12|0x0063
#define TokensLength(i) BaseTokens.token[i].length                                        //06-07-12|0x0063
#define TokensColumn(i) BaseTokens.token[i].column                                        //06-07-12|0x0063
#define TokensHash(i) BaseTokens.token[i].hash                                            //06-07-12|0x0063
#define TokensPosition(i) BaseTokens.token[i].position                                    //06-07-12|0x0063
#define TokensType(i) BaseTokens.token[i].type                                            //06-07-12|0x0063
#define TokensStartCol(i) BaseTokens.token[i].start_col                                   //06-07-12|0x0063
#define TokensStartCall(i) BaseTokens.token[i].start_call                                 //06-07-12|0x0063
#define TokensChar(i,j) BaseTokens.token[i].line[j]                                       //06-07-12|0x0063
#define TokensNoTokens BaseTokens.no_tokens                                               //06-07-12|0x0063
//************************************************************************                //06-12-09|0x0064
#define DrivePathTokenAddr(i) &(BaseDrivePath.token[i])                                   //06-12-09|0x0064
#define DrivePathMacroLineNo(i) BaseDrivePath.token[i].macro_line_no                      //06-12-09|0x0064
#define DrivePathLineAddr(i) &(BaseDrivePath.token[i].line[0])                            //06-12-09|0x0064
#define DrivePathToken(i) BaseDrivePath.token[i]                                          //06-12-09|0x0064
#define DrivePathLine(i) BaseDrivePath.token[i].line                                      //06-12-09|0x0064
#define DrivePathLength(i) BaseDrivePath.token[i].length                                  //06-12-09|0x0064
#define DrivePathColumn(i) BaseDrivePath.token[i].column                                  //06-12-09|0x0064
#define DrivePathHash(i) BaseDrivePath.token[i].hash                                      //06-12-09|0x0064
#define DrivePathPosition(i) BaseDrivePath.token[i].position                              //06-12-09|0x0064
#define DrivePathType(i) BaseDrivePath.token[i].type                                      //06-12-09|0x0064
#define DrivePathStartCol(i) BaseDrivePath.token[i].start_col                             //06-12-09|0x0064
#define DrivePathStartCall(i) BaseDrivePath.token[i].start_call                           //06-12-09|0x0064
#define DrivePathChar(i,j) BaseDrivePath.token[i].line[j]                                 //06-12-09|0x0064
#define DrivePathNoTokens BaseDrivePath.no_tokens                                         //06-12-09|0x0064
//************************************************************************                //06-07-12|0x0065
#define ReportTokenAddr(i) &(BaseReport.token[i])                                         //06-07-12|0x0065
#define ReportMacroLineNo(i) BaseReport.token[i].macro_line_no                            //06-07-12|0x0065
#define ReportLineAddr(i) &(BaseReport.token[i].line[0])                                  //06-07-12|0x0065
#define ReportToken(i) BaseReport.token[i]                                                //06-07-12|0x0065
#define ReportLine(i) BaseReport.token[i].line                                            //06-07-12|0x0065
#define ReportLength(i) BaseReport.token[i].length                                        //06-07-12|0x0065
#define ReportColumn(i) BaseReport.token[i].column                                        //06-07-12|0x0065
#define ReportHash(i) BaseReport.token[i].hash                                            //06-07-12|0x0065
#define ReportPosition(i) BaseReport.token[i].position                                    //06-07-12|0x0065
#define ReportType(i) BaseReport.token[i].type                                            //06-07-12|0x0065
#define ReportStartCol(i) BaseReport.token[i].start_col                                   //06-07-12|0x0065
#define ReportStartCall(i) BaseReport.token[i].start_call                                 //06-07-12|0x0065
#define ReportChar(i,j) BaseReport.token[i].line[j]                                       //06-07-12|0x0065
#define ReportNoTokens BaseReport.no_tokens                                               //06-07-12|0x0065
#define OutputChar(i) BaseOutput.line[i]                                                  //06-07-12|0x0066
#define OutputLine BaseOutput.line[0]                                                     //06-07-12|0x0066
#define OutputLineAddr &(BaseOutput.line[0])                                              //06-07-12|0x0066
#define OutputMacroLineNo BaseOutput.macro_line_no                                        //06-07-12|0x0066
#define OutputType BaseOutput.type                                                        //06-07-12|0x0066
#define OutputStartCol BaseOutput.start_col                                               //06-07-12|0x0066
#define OutputStartCall BaseOutput.start_call                                             //06-07-12|0x0066
#define OutputPosition BaseOutput.position                                                //06-07-12|0x0066
#define OutputLength BaseOutput.length                                                    //06-07-12|0x0066
#define OutputColumn BaseOutput.column                                                    //06-07-12|0x0066
//**********************************************************************                  //06-07-12|0x0066
#define DataElement(i) BaseData.test_element[i]                                           //06-07-12|0x0067
#define DataThreshold(i) BaseData.test_element[i].threshold                               //06-07-12|0x0067
#define DataTestCount(i) BaseData.test_element[i].test_count                              //06-07-12|0x0067
#define DataTestFlag(i) BaseData.test_element[i].test_flag                                //06-07-12|0x0067
#define DataArmFlag(i) BaseData.test_element[i].arm_flag                                  //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataCryptoFar &BaseData.crypto_data                                               //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataCleanup BaseData.cleanup                                                      //06-07-12|0x0067
#define DataCleanupAddr &(BaseData.cleanup)                                               //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataPrepare BaseData.prepare                                                      //06-07-12|0x0067
#define DataPrepareAddr &(BaseData.prepare)                                               //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataBuild BaseData.build                                                          //06-07-12|0x0067
#define DataBuildAddr &(BaseData.build)                                                   //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataMake BaseData.make                                                            //06-07-12|0x0067
#define DataRun BaseData.run                                                              //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataMakeExit BaseData.make_exit                                                   //06-07-12|0x0067
#define DataMakeExitAddr &(BaseData.make_exit)                                            //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataRunExit BaseData.run_exit                                                     //06-07-12|0x0067
#define DataRunExitAddr &(BaseData.run_exit)                                              //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataRecord BaseData.record                                                        //06-07-12|0x0067
#define DataRecordAddr &(BaseData.record)                                                 //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataErrorMask(i) BaseData.error_mask[i]                                           //06-07-12|0x0067
#define DataResultsAddr &(BaseData.results[0])                                            //06-07-12|0x0067
#define DataErrors BaseData.errors                                                        //06-07-12|0x0067
//----------------------------------------------------------------------                  //06-07-12|0x0067
#define DataNoSamples BaseData.no_samples                                                 //06-07-12|0x0067
#define DataNoSuccess BaseData.no_success                                                 //06-07-12|0x0067
#define DataNoRunDetects BaseData.no_run_detects                                          //06-07-12|0x0067
#define DataNoPrepDetects BaseData.no_prep_detects                                        //06-07-12|0x0067
#define DataNoFailures BaseData.no_failures                                               //06-07-12|0x0067
#define DataNoTests BaseData.no_tests                                                     //06-07-12|0x0067
#define DataBitOffset BaseData.bit_offset                                                 //06-07-12|0x0067
#define DataTypeFlag BaseData.type_flag                                                   //06-07-12|0x0067
#define DataResultsFlag BaseData.results_flag                                             //06-07-12|0x0067
#define DataTestNo BaseData.test_no                                                       //06-07-12|0x0067
//***************************************************************************             //06-07-12|0x0068
//************************************************************************                //06-07-12|0x0069
#define PrepareTokenAddr(i) &(DataPrepare.token[i])                                       //06-07-12|0x0069
#define PrepareMacroLineNo(i) DataPrepare.token[i].macro_line_no                          //06-07-12|0x0069
#define PrepareLineAddr(i) &(DataPrepare.token[i].line[0])                                //06-07-12|0x0069
#define PrepareToken(i) DataPrepare.token[i]                                              //06-07-12|0x0069
#define PrepareLine(i) DataPrepare.token[i].line                                          //06-07-12|0x0069
#define PrepareLength(i) DataPrepare.token[i].length                                      //06-07-12|0x0069
#define PrepareColumn(i) DataPrepare.token[i].column                                      //06-07-12|0x0069
#define PrepareHash(i) DataPrepare.token[i].hash                                          //06-07-12|0x0069
#define PreparePosition(i) DataPrepare.token[i].position                                  //06-07-12|0x0069
#define PrepareType(i) DataPrepare.token[i].type                                          //06-07-12|0x0069
#define PrepareStartCol(i) DataPrepare.token[i].start_col                                 //06-07-12|0x0069
#define PrepareStartCall(i) DataPrepare.token[i].start_call                               //06-07-12|0x0069
#define PrepareChar(i,j) DataPrepare.token[i].line[j]                                     //06-07-12|0x0069
#define PrepareNoTokens DataPrepare.no_tokens                                             //06-07-12|0x0069
//************************************************************************                //06-07-12|0x006a
#define BuildTokenAddr(i) &(DataBuild.token[i])                                           //06-07-12|0x006a
#define BuildMacroLineNo(i) DataBuild.token[i].macro_line_no                              //06-07-12|0x006a
#define BuildLineAddr(i) &(DataBuild.token[i].line[0])                                    //06-07-12|0x006a
#define BuildToken(i) DataBuild.token[i]                                                  //06-07-12|0x006a
#define BuildLine(i) DataBuild.token[i].line                                              //06-07-12|0x006a
#define BuildLength(i) DataBuild.token[i].length                                          //06-07-12|0x006a
#define BuildColumn(i) DataBuild.token[i].column                                          //06-07-12|0x006a
#define BuildHash(i) DataBuild.token[i].hash                                              //06-07-12|0x006a
#define BuildPosition(i) DataBuild.token[i].position                                      //06-07-12|0x006a
#define BuildType(i) DataBuild.token[i].type                                              //06-07-12|0x006a
#define BuildStartCol(i) DataBuild.token[i].start_col                                     //06-07-12|0x006a
#define BuildStartCall(i) DataBuild.token[i].start_call                                   //06-07-12|0x006a
#define BuildChar(i,j) DataBuild.token[i].line[j]                                         //06-07-12|0x006a
#define BuildNoTokens DataBuild.no_tokens                                                 //06-07-12|0x006a
//************************************************************************                //06-07-12|0x006b
#define RecordTokenAddr(i) &(DataRecord.token[i])                                         //06-07-12|0x006b
#define RecordMacroLineNo(i) DataRecord.token[i].macro_line_no                            //06-07-12|0x006b
#define RecordLineAddr(i) &(DataRecord.token[i].line[0])                                  //06-07-12|0x006b
#define RecordToken(i) DataRecord.token[i]                                                //06-07-12|0x006b
#define RecordLine(i) DataRecord.token[i].line                                            //06-07-12|0x006b
#define RecordLength(i) DataRecord.token[i].length                                        //06-07-12|0x006b
#define RecordColumn(i) DataRecord.token[i].column                                        //06-07-12|0x006b
#define RecordHash(i) DataRecord.token[i].hash                                            //06-07-12|0x006b
#define RecordPosition(i) DataRecord.token[i].position                                    //06-07-12|0x006b
#define RecordType(i) DataRecord.token[i].type                                            //06-07-12|0x006b
#define RecordStartCol(i) DataRecord.token[i].start_col                                   //06-07-12|0x006b
#define RecordStartCall(i) DataRecord.token[i].start_call                                 //06-07-12|0x006b
#define RecordChar(i,j) DataRecord.token[i].line[j]                                       //06-07-12|0x006b
#define RecordNoTokens DataRecord.no_tokens                                               //06-07-12|0x006b
//************************************************************************                //06-07-12|0x006c
#define CleanupTokenAddr(i) &(DataCleanup.token[i])                                       //06-07-12|0x006c
#define CleanupMacroLineNo(i) DataCleanup.token[i].macro_line_no                          //06-07-12|0x006c
#define CleanupLineAddr(i) &(DataCleanup.token[i].line[0])                                //06-07-12|0x006c
#define CleanupToken(i) DataCleanup.token[i]                                              //06-07-12|0x006c
#define CleanupLine(i) DataCleanup.token[i].line                                          //06-07-12|0x006c
#define CleanupLength(i) DataCleanup.token[i].length                                      //06-07-12|0x006c
#define CleanupColumn(i) DataCleanup.token[i].column                                      //06-07-12|0x006c
#define CleanupHash(i) DataCleanup.token[i].hash                                          //06-07-12|0x006c
#define CleanupPosition(i) DataCleanup.token[i].position                                  //06-07-12|0x006c
#define CleanupType(i) DataCleanup.token[i].type                                          //06-07-12|0x006c
#define CleanupStartCol(i) DataCleanup.token[i].start_col                                 //06-07-12|0x006c
#define CleanupStartCall(i) DataCleanup.token[i].start_call                               //06-07-12|0x006c
#define CleanupChar(i,j) DataCleanup.token[i].line[j]                                     //06-07-12|0x006c
#define CleanupNoTokens DataCleanup.no_tokens                                             //06-07-12|0x006c
#define MakeNameChar(i) DataMake.name[i]                                                  //06-07-12|0x006d
#define MakeNameAddr &(DataMake.name[0])                                                  //06-07-12|0x006d
#define MakeParmsChar(i) DataMake.parms[i]                                                //06-07-12|0x006d
#define MakeParmsAddr &(DataMake.parms[0])                                                //06-07-12|0x006d
#define RunNameChar(i) DataRun.name[i]                                                    //06-07-12|0x006e
#define RunNameAddr &(DataRun.name[0])                                                    //06-07-12|0x006e
#define RunParmsChar(i) DataRun.parms[i]                                                  //06-07-12|0x006e
#define RunParmsAddr &(DataRun.parms[0])                                                  //06-07-12|0x006e
//***************************************************************************             //06-07-12|0x006f
//************************************************************************                //06-12-09|0x0070
#define PcgTokenAddr(i) &(PcgTokensFar->token[i])                                         //06-12-09|0x0070
#define PcgMacroLineNo(i) PcgTokensFar->token[i].macro_line_no                            //06-12-09|0x0070
#define PcgLineAddr(i) &(PcgTokensFar->token[i].line[0])                                  //06-12-09|0x0070
#define PcgToken(i) PcgTokensFar->token[i]                                                //06-12-09|0x0070
#define PcgLine(i) PcgTokensFar->token[i].line                                            //06-12-09|0x0070
#define PcgLength(i) PcgTokensFar->token[i].length                                        //06-12-09|0x0070
#define PcgColumn(i) PcgTokensFar->token[i].column                                        //06-12-09|0x0070
#define PcgHash(i) PcgTokensFar->token[i].hash                                            //06-12-09|0x0070
#define PcgPosition(i) PcgTokensFar->token[i].position                                    //06-12-09|0x0070
#define PcgType(i) PcgTokensFar->token[i].type                                            //06-12-09|0x0070
#define PcgStartCol(i) PcgTokensFar->token[i].start_col                                   //06-12-09|0x0070
#define PcgStartCall(i) PcgTokensFar->token[i].start_call                                 //06-12-09|0x0070
#define PcgChar(i,j) PcgTokensFar->token[i].line[j]                                       //06-12-09|0x0070
#define PcgNoTokens PcgTokensFar->no_tokens                                               //06-12-09|0x0070
#define ExitCodesNoExitCodes ExitCodesAddr->no_exit_codes                                 //06-12-09|0x0071
#define ExitCodesExitCode(i) ExitCodesAddr->exit_code[i]                                  //06-12-09|0x0071
//***************************************************************************             //06-07-12|0x0072
#define ErrorsMask(i,j) DataErrors.error[i].mask[j]                                       //06-07-12|0x0073
#define ErrorsCount(i) DataErrors.error[i].count                                          //06-07-12|0x0073
#define ErrorsNoErrors DataErrors.no_errors                                               //06-07-12|0x0073
//***************************************************************************             //07-12-28|0x0074
#define ErrorMacroChar(i) error_macro.line[i]                                             //07-12-28|0x0075
#define ErrorMacroLine error_macro.line[0]                                                //07-12-28|0x0075
#define ErrorMacroLineAddr &(error_macro.line[0])                                         //07-12-28|0x0075
#define ErrorMacroMacroLineNo error_macro.macro_line_no                                   //07-12-28|0x0075
#define ErrorMacroType error_macro.type                                                   //07-12-28|0x0075
#define ErrorMacroStartCol error_macro.start_col                                          //07-12-28|0x0075
#define ErrorMacroStartCall error_macro.start_call                                        //07-12-28|0x0075
#define ErrorMacroPosition error_macro.position                                           //07-12-28|0x0075
#define ErrorMacroLength error_macro.length                                               //07-12-28|0x0075
#define ErrorMacroColumn error_macro.column                                               //07-12-28|0x0075
//**********************************************************************                  //07-12-28|0x0075
#define ErrorNameChar(i) error_name.line[i]                                               //07-12-28|0x0076
#define ErrorNameLine error_name.line[0]                                                  //07-12-28|0x0076
#define ErrorNameLineAddr &(error_name.line[0])                                           //07-12-28|0x0076
#define ErrorNameMacroLineNo error_name.macro_line_no                                     //07-12-28|0x0076
#define ErrorNameType error_name.type                                                     //07-12-28|0x0076
#define ErrorNameStartCol error_name.start_col                                            //07-12-28|0x0076
#define ErrorNameStartCall error_name.start_call                                          //07-12-28|0x0076
#define ErrorNamePosition error_name.position                                             //07-12-28|0x0076
#define ErrorNameLength error_name.length                                                 //07-12-28|0x0076
#define ErrorNameColumn error_name.column                                                 //07-12-28|0x0076
//**********************************************************************                  //07-12-28|0x0076
//***************************************************************************             //06-07-12|0x0077
#define ReadProject read_project()                                                        //06-07-12|0x0078
#define DebugPause debug_pause()                                                          //06-07-12|0x0078
#define ProjectDoesNotExist Finish("Project File Does Not Exist")                         //06-07-12|0x0078
#define IllegalFileEnd Finish("Illegal File End")                                         //06-07-12|0x0078
#define IllegalCommand Finish("Illegal Command")                                          //06-07-12|0x0078
#define IllegalTestCondition Finish("Illegal Test Conditions")                            //06-07-12|0x0078
#define SetupRunError Finish("A Planned Run Error was not Tested")                        //06-07-12|0x0078
#define TestSuccessMsg GuiWriteLine("Test Succeeded")                                     //06-07-12|0x0078
#define ExpectedMakeErrorMsg GuiWriteLine("Expected Make Error")                          //06-07-12|0x0078
#define UnexpectedMakeErrorMsg GuiWriteLine("Unexpected Make Error")                      //06-07-12|0x0078
#define UnexpectedMakeOkMsg GuiWriteLine("Unexpected Make Success")                       //06-07-12|0x0078
#define ExpectedRunErrorMsg GuiWriteLine("Expected Run Error")                            //06-07-12|0x0078
#define UnexpectedRunErrorMsg GuiWriteLine("Unexpected Run Error")                        //06-07-12|0x0078
#define UnexpectedRunOkMsg GuiWriteLine("Unexpected Run Success")                         //06-07-12|0x0078
#define EnterProjectName enter_project_name(InputTokensFar)                               //06-07-12|0x0078
#define InitialProjFile FileInitialText(BaseProjectAddr)                                  //06-07-12|0x0078
#define EnterProjFileName FileEnterName(InputLineAddr(0),  TMK_EXTENT)                    //06-07-12|0x0078
#define CommitProjFile FileCommitText(BaseProjectAddr)                                    //06-07-12|0x0078
#define ProjectExists project_exists(MainProjTime)                                        //06-07-12|0x0078
#define IfNoTokens1(i) (TokensNoTokens < i)                                               //06-07-12|0x0078
#define IfNoTokens2(i) (TokensNoTokens > i)                                               //06-07-12|0x0078
#define IfNoTokens(i,j) if(IfNoTokens1(i) || IfNoTokens2(j))                              //06-07-12|0x0078
#define CmdTest(i) StrCmp(TokensLineAddr(0),i)                                            //06-07-12|0x0078
#define TestGenPcgName pcg_name(DataPrepareAddr)                                          //06-07-12|0x0078
#define TestBuildPcgName pcg_name(DataBuildAddr)                                          //06-07-12|0x0078
#define SpawnMakeName spawn_name(MakeNameAddr, 3)                                         //06-07-12|0x0078
#define SpawnMakeArgs spawn_parms(MakeParmsAddr, FirstArg)                                //06-07-12|0x0078
#define SpawnMakeExit spawn_exit_codes(DataMakeExitAddr, 2)                               //06-07-12|0x0078
#define SpawnRunName spawn_name(RunNameAddr, 2)                                           //06-07-12|0x0078
#define SpawnRunArgs spawn_parms(RunParmsAddr, FirstArg)                                  //06-07-12|0x0078
#define SpawnRunExit spawn_exit_codes(DataRunExitAddr, 1)                                 //06-07-12|0x0078
#define RecordPcgName pcg_name(DataRecordAddr)                                            //06-07-12|0x0078
#define ReportPcgName pcg_name(BaseReportAddr)                                            //06-07-12|0x0078
#define TestDoneCond ((++DataTestNo)>DataNoTests) ? Yes : No                              //06-07-12|0x0078
#define PrepareStepMessage progress_message("Prepare Step No:")                           //06-07-12|0x0078
#define BuildStepMessage progress_message("Build Step No:  ")                             //06-07-12|0x0078
#define MakeStepMessage progress_message("Make Step No:   ")                              //06-07-12|0x0078
#define RunStepMessage progress_message("Run Step No:    ")                               //06-07-12|0x0078
#define RecordStepMessage progress_message("Record Step No: ")                            //06-07-12|0x0078
#define BuildStepExists (BuildNoTokens > 0) ? Yes : No                                    //06-07-12|0x0078
#define MakeStepExists (MakeNameChar(0) != 0) ? Yes : No                                  //06-07-12|0x0078
#define RunStepExists (RunNameChar(0) != 0) ? Yes : No                                    //06-07-12|0x0078
#define RecordStepExists (RecordNoTokens > 0) ? Yes : No                                  //06-07-12|0x0078
#define ReportStepExists (ReportNoTokens > 0) ? Yes : No                                  //06-07-12|0x0078
#define ReportErrorsExists (ErrorsNoErrors > 0) ? Yes : No                                //06-07-12|0x0078
#define IncrNoSuccess ++DataNoSuccess                                                     //06-07-12|0x0078
#define IncrNoFailures ++DataNoFailures                                                   //06-07-12|0x0078
#define IncrNoPrepDetects ++DataNoPrepDetects                                             //06-07-12|0x0078
#define IncrNoRunDetects ++DataNoRunDetects                                               //06-07-12|0x0078
#define RecordSuccess record_results("S")                                                 //06-07-12|0x0078
#define RecordMake record_results("M")                                                    //06-07-12|0x0078
#define RecordRun record_results("R")                                                     //06-07-12|0x0078
#define InitialSummaryFile FileInitialText(BaseSummaryAddr)                               //06-07-12|0x0078
#define EnterSummaryFileName FileEnterName(InputLineAddr(0),  RPT_EXTENT)                 //06-07-12|0x0078
#define CommitSummaryFile FileCommitText(BaseSummaryAddr)                                 //06-07-12|0x0078
#define StrDataCpy(i,j) MemCpy(i,j,sizeof(STRING_DATA))                                   //06-07-12|0x0078
#define StrDataClr(i) MemSet(i,0x00,sizeof(STRING_DATA))                                  //06-07-12|0x0078
#define TokenDataCpy(i,j) MemCpy(i,j,sizeof(TOKENS))                                      //06-07-12|0x0078
#define TokenDataClr(i) MemSet(i,0x00,sizeof(TOKENS))                                     //06-07-12|0x0078
#define TokenToInt(i,j) StrToInt(TokensLineAddr(i), j)                                    //06-07-12|0x0078
#define IfTokenToInt(i,j) if(StrToInt(TokensLineAddr(i), j) == 0)                         //06-07-12|0x0078
#define InitialReportFile FileInitialText(BaseSummaryAddr)                                //06-07-12|0x0078
#define CommitReportFile FileCommitText(BaseSummaryAddr)                                  //06-07-12|0x0078
#define ReportActive(i) report_numeric(&header[0], DataTestCount(i))                      //06-07-12|0x0078
#define TestProject(i) DevProjProcess(i,MainProjTime,BaseTaskNoAddr)                      //06-07-12|0x0078
//***************************************************************************             //15-06-16|0x007b
#define InitialRandom BasicRandomCreate(DataCryptoFar)                                    //15-06-16|0x007c
#define LoadRandom BasicRandomLoad(DataCryptoFar, TokensTokenAddr(2))                     //15-06-16|0x007d
#define GetRandom BasicGetRandom(&work, DataCryptoFar)                                    //15-06-16|0x007e
#ifndef TestIndex                                                                         //06-07-12|0x0089
#define TestIndex 0                                                                       //06-07-12|0x0089
#endif                                                                                    //06-07-12|0x0089
//------------------------------------------------------------------------                //06-07-12|0x0089
enum {  test_proj_allocate_1 = TestIndex };                                               //06-07-12|0x0089
//------------------------------------------------------------------------                //06-07-12|0x0089
#undef TestIndex                                                                          //06-07-12|0x0089
#define TestIndex test_proj_allocate_1+1                                                  //06-07-12|0x0089
//************************************************************************                //06-07-12|0x0089
#ifndef TestIndex                                                                         //06-07-12|0x00a4
#define TestIndex 0                                                                       //06-07-12|0x00a4
#endif                                                                                    //06-07-12|0x00a4
//------------------------------------------------------------------------                //06-07-12|0x00a4
enum {  test_proj_free_1 = TestIndex };                                                   //06-07-12|0x00a4
//------------------------------------------------------------------------                //06-07-12|0x00a4
#undef TestIndex                                                                          //06-07-12|0x00a4
#define TestIndex test_proj_free_1+1                                                      //06-07-12|0x00a4
//************************************************************************                //06-07-12|0x00a4
#ifndef TestIndex                                                                         //06-12-09|0x02a6
#define TestIndex 0                                                                       //06-12-09|0x02a6
#endif                                                                                    //06-12-09|0x02a6
//------------------------------------------------------------------------                //06-12-09|0x02a6
enum {  initial_1 = TestIndex };                                                          //06-12-09|0x02a6
//------------------------------------------------------------------------                //06-12-09|0x02a6
#undef TestIndex                                                                          //06-12-09|0x02a6
#define TestIndex initial_1+1                                                             //06-12-09|0x02a6
//************************************************************************                //06-12-09|0x02a6
#ifndef TestIndex                                                                         //06-12-09|0x02be
#define TestIndex 0                                                                       //06-12-09|0x02be
#endif                                                                                    //06-12-09|0x02be
//------------------------------------------------------------------------                //06-12-09|0x02be
enum {  enter_project_name_1 = TestIndex };                                               //06-12-09|0x02be
//------------------------------------------------------------------------                //06-12-09|0x02be
#undef TestIndex                                                                          //06-12-09|0x02be
#define TestIndex enter_project_name_1+1                                                  //06-12-09|0x02be
//************************************************************************                //06-12-09|0x02be
#ifndef TestIndex                                                                         //06-08-09|0x02c8
#define TestIndex 0                                                                       //06-08-09|0x02c8
#endif                                                                                    //06-08-09|0x02c8
//------------------------------------------------------------------------                //06-08-09|0x02c8
enum {  project_exists_1 = TestIndex };                                                   //06-08-09|0x02c8
//------------------------------------------------------------------------                //06-08-09|0x02c8
#undef TestIndex                                                                          //06-08-09|0x02c8
#define TestIndex project_exists_1+1                                                      //06-08-09|0x02c8
//************************************************************************                //06-08-09|0x02c8
#ifndef TestIndex                                                                         //06-12-09|0x02e9
#define TestIndex 0                                                                       //06-12-09|0x02e9
#endif                                                                                    //06-12-09|0x02e9
//------------------------------------------------------------------------                //06-12-09|0x02e9
enum {  open_project_1 = TestIndex };                                                     //06-12-09|0x02e9
//------------------------------------------------------------------------                //06-12-09|0x02e9
#undef TestIndex                                                                          //06-12-09|0x02e9
#define TestIndex open_project_1+1                                                        //06-12-09|0x02e9
//************************************************************************                //06-12-09|0x02e9
#ifndef TestIndex                                                                         //06-12-09|0x02f3
#define TestIndex 0                                                                       //06-12-09|0x02f3
#endif                                                                                    //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
enum {  read_project_1 = TestIndex };                                                     //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
#undef TestIndex                                                                          //06-12-09|0x02f3
#define TestIndex read_project_1+1                                                        //06-12-09|0x02f3
//************************************************************************                //06-12-09|0x02f3
#ifndef TestIndex                                                                         //06-12-09|0x02f3
#define TestIndex 0                                                                       //06-12-09|0x02f3
#endif                                                                                    //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
enum {  read_project_2 = TestIndex };                                                     //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
#undef TestIndex                                                                          //06-12-09|0x02f3
#define TestIndex read_project_2+1                                                        //06-12-09|0x02f3
//************************************************************************                //06-12-09|0x02f3
#ifndef TestIndex                                                                         //06-12-09|0x02f3
#define TestIndex 0                                                                       //06-12-09|0x02f3
#endif                                                                                    //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
enum {  read_project_3 = TestIndex };                                                     //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
#undef TestIndex                                                                          //06-12-09|0x02f3
#define TestIndex read_project_3+1                                                        //06-12-09|0x02f3
//************************************************************************                //06-12-09|0x02f3
#ifndef TestIndex                                                                         //06-12-09|0x02f3
#define TestIndex 0                                                                       //06-12-09|0x02f3
#endif                                                                                    //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
enum {  read_project_4 = TestIndex };                                                     //06-12-09|0x02f3
//------------------------------------------------------------------------                //06-12-09|0x02f3
#undef TestIndex                                                                          //06-12-09|0x02f3
#define TestIndex read_project_4+1                                                        //06-12-09|0x02f3
//************************************************************************                //06-12-09|0x02f3
#ifndef TestIndex                                                                         //06-12-09|0x02fd
#define TestIndex 0                                                                       //06-12-09|0x02fd
#endif                                                                                    //06-12-09|0x02fd
//------------------------------------------------------------------------                //06-12-09|0x02fd
enum {  basic_configure_1 = TestIndex };                                                  //06-12-09|0x02fd
//------------------------------------------------------------------------                //06-12-09|0x02fd
#undef TestIndex                                                                          //06-12-09|0x02fd
#define TestIndex basic_configure_1+1                                                     //06-12-09|0x02fd
//************************************************************************                //06-12-09|0x02fd
#ifndef TestIndex                                                                         //06-12-11|0x0326
#define TestIndex 0                                                                       //06-12-11|0x0326
#endif                                                                                    //06-12-11|0x0326
//------------------------------------------------------------------------                //06-12-11|0x0326
enum {  drive_path_1 = TestIndex };                                                       //06-12-11|0x0326
//------------------------------------------------------------------------                //06-12-11|0x0326
#undef TestIndex                                                                          //06-12-11|0x0326
#define TestIndex drive_path_1+1                                                          //06-12-11|0x0326
//************************************************************************                //06-12-11|0x0326
#ifndef TestIndex                                                                         //06-12-11|0x0330
#define TestIndex 0                                                                       //06-12-11|0x0330
#endif                                                                                    //06-12-11|0x0330
//------------------------------------------------------------------------                //06-12-11|0x0330
enum {  pcg_mame_1 = TestIndex };                                                         //06-12-11|0x0330
//------------------------------------------------------------------------                //06-12-11|0x0330
#undef TestIndex                                                                          //06-12-11|0x0330
#define TestIndex pcg_mame_1+1                                                            //06-12-11|0x0330
//************************************************************************                //06-12-11|0x0330
#ifndef TestIndex                                                                         //06-12-16|0x034c
#define TestIndex 0                                                                       //06-12-16|0x034c
#endif                                                                                    //06-12-16|0x034c
//------------------------------------------------------------------------                //06-12-16|0x034c
enum {  spawn_mame_1 = TestIndex };                                                       //06-12-16|0x034c
//------------------------------------------------------------------------                //06-12-16|0x034c
#undef TestIndex                                                                          //06-12-16|0x034c
#define TestIndex spawn_mame_1+1                                                          //06-12-16|0x034c
//************************************************************************                //06-12-16|0x034c
#ifndef TestIndex                                                                         //06-12-16|0x036e
#define TestIndex 0                                                                       //06-12-16|0x036e
#endif                                                                                    //06-12-16|0x036e
//------------------------------------------------------------------------                //06-12-16|0x036e
enum {  spawn_parms_1 = TestIndex };                                                      //06-12-16|0x036e
//------------------------------------------------------------------------                //06-12-16|0x036e
#undef TestIndex                                                                          //06-12-16|0x036e
#define TestIndex spawn_parms_1+1                                                         //06-12-16|0x036e
//************************************************************************                //06-12-16|0x036e
#ifndef TestIndex                                                                         //06-12-16|0x03b8
#define TestIndex 0                                                                       //06-12-16|0x03b8
#endif                                                                                    //06-12-16|0x03b8
//------------------------------------------------------------------------                //06-12-16|0x03b8
enum {  spawn_exit_codes_1 = TestIndex };                                                 //06-12-16|0x03b8
//------------------------------------------------------------------------                //06-12-16|0x03b8
#undef TestIndex                                                                          //06-12-16|0x03b8
#define TestIndex spawn_exit_codes_1+1                                                    //06-12-16|0x03b8
//************************************************************************                //06-12-16|0x03b8
#ifndef TestIndex                                                                         //06-12-16|0x03b9
#define TestIndex 0                                                                       //06-12-16|0x03b9
#endif                                                                                    //06-12-16|0x03b9
//------------------------------------------------------------------------                //06-12-16|0x03b9
enum {  spawn_exit_codes_2 = TestIndex };                                                 //06-12-16|0x03b9
//------------------------------------------------------------------------                //06-12-16|0x03b9
#undef TestIndex                                                                          //06-12-16|0x03b9
#define TestIndex spawn_exit_codes_2+1                                                    //06-12-16|0x03b9
//************************************************************************                //06-12-16|0x03b9
#ifndef TestIndex                                                                         //06-12-17|0x03e0
#define TestIndex 0                                                                       //06-12-17|0x03e0
#endif                                                                                    //06-12-17|0x03e0
//------------------------------------------------------------------------                //06-12-17|0x03e0
enum {  cleanup_names_1 = TestIndex };                                                    //06-12-17|0x03e0
//------------------------------------------------------------------------                //06-12-17|0x03e0
#undef TestIndex                                                                          //06-12-17|0x03e0
#define TestIndex cleanup_names_1+1                                                       //06-12-17|0x03e0
//************************************************************************                //06-12-17|0x03e0
#ifndef TestIndex                                                                         //06-12-11|0x03fa
#define TestIndex 0                                                                       //06-12-11|0x03fa
#endif                                                                                    //06-12-11|0x03fa
//------------------------------------------------------------------------                //06-12-11|0x03fa
enum {  set_generator_1 = TestIndex };                                                    //06-12-11|0x03fa
//------------------------------------------------------------------------                //06-12-11|0x03fa
#undef TestIndex                                                                          //06-12-11|0x03fa
#define TestIndex set_generator_1+1                                                       //06-12-11|0x03fa
//************************************************************************                //06-12-11|0x03fa
#ifndef TestIndex                                                                         //06-12-09|0x0425
#define TestIndex 0                                                                       //06-12-09|0x0425
#endif                                                                                    //06-12-09|0x0425
//------------------------------------------------------------------------                //06-12-09|0x0425
enum {  close_project_1 = TestIndex };                                                    //06-12-09|0x0425
//------------------------------------------------------------------------                //06-12-09|0x0425
#undef TestIndex                                                                          //06-12-09|0x0425
#define TestIndex close_project_1+1                                                       //06-12-09|0x0425
//************************************************************************                //06-12-09|0x0425
#ifndef TestIndex                                                                         //06-12-12|0x042f
#define TestIndex 0                                                                       //06-12-12|0x042f
#endif                                                                                    //06-12-12|0x042f
//------------------------------------------------------------------------                //06-12-12|0x042f
enum {  cleanup_step_1 = TestIndex };                                                     //06-12-12|0x042f
//------------------------------------------------------------------------                //06-12-12|0x042f
#undef TestIndex                                                                          //06-12-12|0x042f
#define TestIndex cleanup_step_1+1                                                        //06-12-12|0x042f
//************************************************************************                //06-12-12|0x042f
#ifndef TestIndex                                                                         //06-12-17|0x044f
#define TestIndex 0                                                                       //06-12-17|0x044f
#endif                                                                                    //06-12-17|0x044f
//------------------------------------------------------------------------                //06-12-17|0x044f
enum {  basic_cleanup_1 = TestIndex };                                                    //06-12-17|0x044f
//------------------------------------------------------------------------                //06-12-17|0x044f
#undef TestIndex                                                                          //06-12-17|0x044f
#define TestIndex basic_cleanup_1+1                                                       //06-12-17|0x044f
//************************************************************************                //06-12-17|0x044f
#ifndef TestIndex                                                                         //06-12-12|0x0464
#define TestIndex 0                                                                       //06-12-12|0x0464
#endif                                                                                    //06-12-12|0x0464
//------------------------------------------------------------------------                //06-12-12|0x0464
enum {  generate_test_1 = TestIndex };                                                    //06-12-12|0x0464
//------------------------------------------------------------------------                //06-12-12|0x0464
#undef TestIndex                                                                          //06-12-12|0x0464
#define TestIndex generate_test_1+1                                                       //06-12-12|0x0464
//************************************************************************                //06-12-12|0x0464
#ifndef TestIndex                                                                         //06-12-12|0x04ef
#define TestIndex 0                                                                       //06-12-12|0x04ef
#endif                                                                                    //06-12-12|0x04ef
//------------------------------------------------------------------------                //06-12-12|0x04ef
enum {  progress_message_1 = TestIndex };                                                 //06-12-12|0x04ef
//------------------------------------------------------------------------                //06-12-12|0x04ef
#undef TestIndex                                                                          //06-12-12|0x04ef
#define TestIndex progress_message_1+1                                                    //06-12-12|0x04ef
//************************************************************************                //06-12-12|0x04ef
#ifndef TestIndex                                                                         //06-12-12|0x0506
#define TestIndex 0                                                                       //06-12-12|0x0506
#endif                                                                                    //06-12-12|0x0506
//------------------------------------------------------------------------                //06-12-12|0x0506
enum {  pcg_push_1 = TestIndex };                                                         //06-12-12|0x0506
//------------------------------------------------------------------------                //06-12-12|0x0506
#undef TestIndex                                                                          //06-12-12|0x0506
#define TestIndex pcg_push_1+1                                                            //06-12-12|0x0506
//************************************************************************                //06-12-12|0x0506
#ifndef TestIndex                                                                         //06-12-16|0x053f
#define TestIndex 0                                                                       //06-12-16|0x053f
#endif                                                                                    //06-12-16|0x053f
//------------------------------------------------------------------------                //06-12-16|0x053f
enum {  exit_test_1 = TestIndex };                                                        //06-12-16|0x053f
//------------------------------------------------------------------------                //06-12-16|0x053f
#undef TestIndex                                                                          //06-12-16|0x053f
#define TestIndex exit_test_1+1                                                           //06-12-16|0x053f
//************************************************************************                //06-12-16|0x053f
#ifndef TestIndex                                                                         //06-12-16|0x0540
#define TestIndex 0                                                                       //06-12-16|0x0540
#endif                                                                                    //06-12-16|0x0540
//------------------------------------------------------------------------                //06-12-16|0x0540
enum {  exit_test_2 = TestIndex };                                                        //06-12-16|0x0540
//------------------------------------------------------------------------                //06-12-16|0x0540
#undef TestIndex                                                                          //06-12-16|0x0540
#define TestIndex exit_test_2+1                                                           //06-12-16|0x0540
//************************************************************************                //06-12-16|0x0540
#ifndef TestIndex                                                                         //06-12-16|0x0541
#define TestIndex 0                                                                       //06-12-16|0x0541
#endif                                                                                    //06-12-16|0x0541
//------------------------------------------------------------------------                //06-12-16|0x0541
enum {  exit_test_3 = TestIndex };                                                        //06-12-16|0x0541
//------------------------------------------------------------------------                //06-12-16|0x0541
#undef TestIndex                                                                          //06-12-16|0x0541
#define TestIndex exit_test_3+1                                                           //06-12-16|0x0541
//************************************************************************                //06-12-16|0x0541
#ifndef TestIndex                                                                         //06-12-16|0x0584
#define TestIndex 0                                                                       //06-12-16|0x0584
#endif                                                                                    //06-12-16|0x0584
//------------------------------------------------------------------------                //06-12-16|0x0584
enum {  make_step_1 = TestIndex };                                                        //06-12-16|0x0584
//------------------------------------------------------------------------                //06-12-16|0x0584
#undef TestIndex                                                                          //06-12-16|0x0584
#define TestIndex make_step_1+1                                                           //06-12-16|0x0584
//************************************************************************                //06-12-16|0x0584
#ifndef TestIndex                                                                         //06-12-16|0x0585
#define TestIndex 0                                                                       //06-12-16|0x0585
#endif                                                                                    //06-12-16|0x0585
//------------------------------------------------------------------------                //06-12-16|0x0585
enum {  make_step_2 = TestIndex };                                                        //06-12-16|0x0585
//------------------------------------------------------------------------                //06-12-16|0x0585
#undef TestIndex                                                                          //06-12-16|0x0585
#define TestIndex make_step_2+1                                                           //06-12-16|0x0585
//************************************************************************                //06-12-16|0x0585
#ifndef TestIndex                                                                         //06-12-16|0x0586
#define TestIndex 0                                                                       //06-12-16|0x0586
#endif                                                                                    //06-12-16|0x0586
//------------------------------------------------------------------------                //06-12-16|0x0586
enum {  make_step_3 = TestIndex };                                                        //06-12-16|0x0586
//------------------------------------------------------------------------                //06-12-16|0x0586
#undef TestIndex                                                                          //06-12-16|0x0586
#define TestIndex make_step_3+1                                                           //06-12-16|0x0586
//************************************************************************                //06-12-16|0x0586
#ifndef TestIndex                                                                         //06-12-16|0x05a6
#define TestIndex 0                                                                       //06-12-16|0x05a6
#endif                                                                                    //06-12-16|0x05a6
//------------------------------------------------------------------------                //06-12-16|0x05a6
enum {  run_step_1 = TestIndex };                                                         //06-12-16|0x05a6
//------------------------------------------------------------------------                //06-12-16|0x05a6
#undef TestIndex                                                                          //06-12-16|0x05a6
#define TestIndex run_step_1+1                                                            //06-12-16|0x05a6
//************************************************************************                //06-12-16|0x05a6
#ifndef TestIndex                                                                         //06-12-16|0x05a7
#define TestIndex 0                                                                       //06-12-16|0x05a7
#endif                                                                                    //06-12-16|0x05a7
//------------------------------------------------------------------------                //06-12-16|0x05a7
enum {  run_step_2 = TestIndex };                                                         //06-12-16|0x05a7
//------------------------------------------------------------------------                //06-12-16|0x05a7
#undef TestIndex                                                                          //06-12-16|0x05a7
#define TestIndex run_step_2+1                                                            //06-12-16|0x05a7
//************************************************************************                //06-12-16|0x05a7
#ifndef TestIndex                                                                         //06-12-16|0x05a8
#define TestIndex 0                                                                       //06-12-16|0x05a8
#endif                                                                                    //06-12-16|0x05a8
//------------------------------------------------------------------------                //06-12-16|0x05a8
enum {  run_step_3 = TestIndex };                                                         //06-12-16|0x05a8
//------------------------------------------------------------------------                //06-12-16|0x05a8
#undef TestIndex                                                                          //06-12-16|0x05a8
#define TestIndex run_step_3+1                                                            //06-12-16|0x05a8
//************************************************************************                //06-12-16|0x05a8
#ifndef TestIndex                                                                         //06-12-15|0x05c8
#define TestIndex 0                                                                       //06-12-15|0x05c8
#endif                                                                                    //06-12-15|0x05c8
//------------------------------------------------------------------------                //06-12-15|0x05c8
enum {  record_results_1 = TestIndex };                                                   //06-12-15|0x05c8
//------------------------------------------------------------------------                //06-12-15|0x05c8
#undef TestIndex                                                                          //06-12-15|0x05c8
#define TestIndex record_results_1+1                                                      //06-12-15|0x05c8
//************************************************************************                //06-12-15|0x05c8
#ifndef TestIndex                                                                         //06-12-15|0x05c9
#define TestIndex 0                                                                       //06-12-15|0x05c9
#endif                                                                                    //06-12-15|0x05c9
//------------------------------------------------------------------------                //06-12-15|0x05c9
enum {  record_results_2 = TestIndex };                                                   //06-12-15|0x05c9
//------------------------------------------------------------------------                //06-12-15|0x05c9
#undef TestIndex                                                                          //06-12-15|0x05c9
#define TestIndex record_results_2+1                                                      //06-12-15|0x05c9
//************************************************************************                //06-12-15|0x05c9
#ifndef TestIndex                                                                         //06-12-15|0x05ca
#define TestIndex 0                                                                       //06-12-15|0x05ca
#endif                                                                                    //06-12-15|0x05ca
//------------------------------------------------------------------------                //06-12-15|0x05ca
enum {  record_results_3 = TestIndex };                                                   //06-12-15|0x05ca
//------------------------------------------------------------------------                //06-12-15|0x05ca
#undef TestIndex                                                                          //06-12-15|0x05ca
#define TestIndex record_results_3+1                                                      //06-12-15|0x05ca
//************************************************************************                //06-12-15|0x05ca
#ifndef TestIndex                                                                         //06-12-16|0x060a
#define TestIndex 0                                                                       //06-12-16|0x060a
#endif                                                                                    //06-12-16|0x060a
//------------------------------------------------------------------------                //06-12-16|0x060a
enum {  prep_active_bits_1 = TestIndex };                                                 //06-12-16|0x060a
//------------------------------------------------------------------------                //06-12-16|0x060a
#undef TestIndex                                                                          //06-12-16|0x060a
#define TestIndex prep_active_bits_1+1                                                    //06-12-16|0x060a
//************************************************************************                //06-12-16|0x060a
#ifndef TestIndex                                                                         //06-12-16|0x060b
#define TestIndex 0                                                                       //06-12-16|0x060b
#endif                                                                                    //06-12-16|0x060b
//------------------------------------------------------------------------                //06-12-16|0x060b
enum {  prep_active_bits_2 = TestIndex };                                                 //06-12-16|0x060b
//------------------------------------------------------------------------                //06-12-16|0x060b
#undef TestIndex                                                                          //06-12-16|0x060b
#define TestIndex prep_active_bits_2+1                                                    //06-12-16|0x060b
//************************************************************************                //06-12-16|0x060b
#ifndef TestIndex                                                                         //06-12-16|0x060c
#define TestIndex 0                                                                       //06-12-16|0x060c
#endif                                                                                    //06-12-16|0x060c
//------------------------------------------------------------------------                //06-12-16|0x060c
enum {  prep_active_bits_3 = TestIndex };                                                 //06-12-16|0x060c
//------------------------------------------------------------------------                //06-12-16|0x060c
#undef TestIndex                                                                          //06-12-16|0x060c
#define TestIndex prep_active_bits_3+1                                                    //06-12-16|0x060c
//************************************************************************                //06-12-16|0x060c
#ifndef TestIndex                                                                         //06-12-16|0x060d
#define TestIndex 0                                                                       //06-12-16|0x060d
#endif                                                                                    //06-12-16|0x060d
//------------------------------------------------------------------------                //06-12-16|0x060d
enum {  prep_active_bits_4 = TestIndex };                                                 //06-12-16|0x060d
//------------------------------------------------------------------------                //06-12-16|0x060d
#undef TestIndex                                                                          //06-12-16|0x060d
#define TestIndex prep_active_bits_4+1                                                    //06-12-16|0x060d
//************************************************************************                //06-12-16|0x060d
#ifndef TestIndex                                                                         //06-12-16|0x063e
#define TestIndex 0                                                                       //06-12-16|0x063e
#endif                                                                                    //06-12-16|0x063e
//------------------------------------------------------------------------                //06-12-16|0x063e
enum {  previous_error_1 = TestIndex };                                                   //06-12-16|0x063e
//------------------------------------------------------------------------                //06-12-16|0x063e
#undef TestIndex                                                                          //06-12-16|0x063e
#define TestIndex previous_error_1+1                                                      //06-12-16|0x063e
//************************************************************************                //06-12-16|0x063e
#ifndef TestIndex                                                                         //06-12-16|0x063f
#define TestIndex 0                                                                       //06-12-16|0x063f
#endif                                                                                    //06-12-16|0x063f
//------------------------------------------------------------------------                //06-12-16|0x063f
enum {  previous_error_2 = TestIndex };                                                   //06-12-16|0x063f
//------------------------------------------------------------------------                //06-12-16|0x063f
#undef TestIndex                                                                          //06-12-16|0x063f
#define TestIndex previous_error_2+1                                                      //06-12-16|0x063f
//************************************************************************                //06-12-16|0x063f
#ifndef TestIndex                                                                         //06-12-16|0x0662
#define TestIndex 0                                                                       //06-12-16|0x0662
#endif                                                                                    //06-12-16|0x0662
//------------------------------------------------------------------------                //06-12-16|0x0662
enum {  new_error_1 = TestIndex };                                                        //06-12-16|0x0662
//------------------------------------------------------------------------                //06-12-16|0x0662
#undef TestIndex                                                                          //06-12-16|0x0662
#define TestIndex new_error_1+1                                                           //06-12-16|0x0662
//************************************************************************                //06-12-16|0x0662
#ifndef TestIndex                                                                         //06-12-16|0x0663
#define TestIndex 0                                                                       //06-12-16|0x0663
#endif                                                                                    //06-12-16|0x0663
//------------------------------------------------------------------------                //06-12-16|0x0663
enum {  new_error_2 = TestIndex };                                                        //06-12-16|0x0663
//------------------------------------------------------------------------                //06-12-16|0x0663
#undef TestIndex                                                                          //06-12-16|0x0663
#define TestIndex new_error_2+1                                                           //06-12-16|0x0663
//************************************************************************                //06-12-16|0x0663
#ifndef TestIndex                                                                         //06-12-15|0x0683
#define TestIndex 0                                                                       //06-12-15|0x0683
#endif                                                                                    //06-12-15|0x0683
//------------------------------------------------------------------------                //06-12-15|0x0683
enum {  enter_summary_name_1 = TestIndex };                                               //06-12-15|0x0683
//------------------------------------------------------------------------                //06-12-15|0x0683
#undef TestIndex                                                                          //06-12-15|0x0683
#define TestIndex enter_summary_name_1+1                                                  //06-12-15|0x0683
//************************************************************************                //06-12-15|0x0683
#ifndef TestIndex                                                                         //06-12-15|0x068d
#define TestIndex 0                                                                       //06-12-15|0x068d
#endif                                                                                    //06-12-15|0x068d
//------------------------------------------------------------------------                //06-12-15|0x068d
enum {  report_summaries_1 = TestIndex };                                                 //06-12-15|0x068d
//------------------------------------------------------------------------                //06-12-15|0x068d
#undef TestIndex                                                                          //06-12-15|0x068d
#define TestIndex report_summaries_1+1                                                    //06-12-15|0x068d
//************************************************************************                //06-12-15|0x068d
#ifndef TestIndex                                                                         //06-12-15|0x06b6
#define TestIndex 0                                                                       //06-12-15|0x06b6
#endif                                                                                    //06-12-15|0x06b6
//------------------------------------------------------------------------                //06-12-15|0x06b6
enum {  report_active_1 = TestIndex };                                                    //06-12-15|0x06b6
//------------------------------------------------------------------------                //06-12-15|0x06b6
#undef TestIndex                                                                          //06-12-15|0x06b6
#define TestIndex report_active_1+1                                                       //06-12-15|0x06b6
//************************************************************************                //06-12-15|0x06b6
#ifndef TestIndex                                                                         //06-12-15|0x06b7
#define TestIndex 0                                                                       //06-12-15|0x06b7
#endif                                                                                    //06-12-15|0x06b7
//------------------------------------------------------------------------                //06-12-15|0x06b7
enum {  report_active_2 = TestIndex };                                                    //06-12-15|0x06b7
//------------------------------------------------------------------------                //06-12-15|0x06b7
#undef TestIndex                                                                          //06-12-15|0x06b7
#define TestIndex report_active_2+1                                                       //06-12-15|0x06b7
//************************************************************************                //06-12-15|0x06b7
#ifndef TestIndex                                                                         //06-12-15|0x06b8
#define TestIndex 0                                                                       //06-12-15|0x06b8
#endif                                                                                    //06-12-15|0x06b8
//------------------------------------------------------------------------                //06-12-15|0x06b8
enum {  report_active_3 = TestIndex };                                                    //06-12-15|0x06b8
//------------------------------------------------------------------------                //06-12-15|0x06b8
#undef TestIndex                                                                          //06-12-15|0x06b8
#define TestIndex report_active_3+1                                                       //06-12-15|0x06b8
//************************************************************************                //06-12-15|0x06b8
#ifndef TestIndex                                                                         //06-12-15|0x06b9
#define TestIndex 0                                                                       //06-12-15|0x06b9
#endif                                                                                    //06-12-15|0x06b9
//------------------------------------------------------------------------                //06-12-15|0x06b9
enum {  report_active_4 = TestIndex };                                                    //06-12-15|0x06b9
//------------------------------------------------------------------------                //06-12-15|0x06b9
#undef TestIndex                                                                          //06-12-15|0x06b9
#define TestIndex report_active_4+1                                                       //06-12-15|0x06b9
//************************************************************************                //06-12-15|0x06b9
#ifndef TestIndex                                                                         //06-12-17|0x06f2
#define TestIndex 0                                                                       //06-12-17|0x06f2
#endif                                                                                    //06-12-17|0x06f2
//------------------------------------------------------------------------                //06-12-17|0x06f2
enum {  report_error_1 = TestIndex };                                                     //06-12-17|0x06f2
//------------------------------------------------------------------------                //06-12-17|0x06f2
#undef TestIndex                                                                          //06-12-17|0x06f2
#define TestIndex report_error_1+1                                                        //06-12-17|0x06f2
//************************************************************************                //06-12-17|0x06f2
#ifndef TestIndex                                                                         //06-12-17|0x06f3
#define TestIndex 0                                                                       //06-12-17|0x06f3
#endif                                                                                    //06-12-17|0x06f3
//------------------------------------------------------------------------                //06-12-17|0x06f3
enum {  report_error_2 = TestIndex };                                                     //06-12-17|0x06f3
//------------------------------------------------------------------------                //06-12-17|0x06f3
#undef TestIndex                                                                          //06-12-17|0x06f3
#define TestIndex report_error_2+1                                                        //06-12-17|0x06f3
//************************************************************************                //06-12-17|0x06f3
#ifndef TestIndex                                                                         //06-12-17|0x06f4
#define TestIndex 0                                                                       //06-12-17|0x06f4
#endif                                                                                    //06-12-17|0x06f4
//------------------------------------------------------------------------                //06-12-17|0x06f4
enum {  report_error_3 = TestIndex };                                                     //06-12-17|0x06f4
//------------------------------------------------------------------------                //06-12-17|0x06f4
#undef TestIndex                                                                          //06-12-17|0x06f4
#define TestIndex report_error_3+1                                                        //06-12-17|0x06f4
//************************************************************************                //06-12-17|0x06f4
#ifndef TestIndex                                                                         //06-12-17|0x06f5
#define TestIndex 0                                                                       //06-12-17|0x06f5
#endif                                                                                    //06-12-17|0x06f5
//------------------------------------------------------------------------                //06-12-17|0x06f5
enum {  report_error_4 = TestIndex };                                                     //06-12-17|0x06f5
//------------------------------------------------------------------------                //06-12-17|0x06f5
#undef TestIndex                                                                          //06-12-17|0x06f5
#define TestIndex report_error_4+1                                                        //06-12-17|0x06f5
//************************************************************************                //06-12-17|0x06f5
#ifndef TestIndex                                                                         //06-12-17|0x06f6
#define TestIndex 0                                                                       //06-12-17|0x06f6
#endif                                                                                    //06-12-17|0x06f6
//------------------------------------------------------------------------                //06-12-17|0x06f6
enum {  report_error_5 = TestIndex };                                                     //06-12-17|0x06f6
//------------------------------------------------------------------------                //06-12-17|0x06f6
#undef TestIndex                                                                          //06-12-17|0x06f6
#define TestIndex report_error_5+1                                                        //06-12-17|0x06f6
//************************************************************************                //06-12-17|0x06f6
#ifndef TestIndex                                                                         //06-12-15|0x0740
#define TestIndex 0                                                                       //06-12-15|0x0740
#endif                                                                                    //06-12-15|0x0740
//------------------------------------------------------------------------                //06-12-15|0x0740
enum {  report_title_1 = TestIndex };                                                     //06-12-15|0x0740
//------------------------------------------------------------------------                //06-12-15|0x0740
#undef TestIndex                                                                          //06-12-15|0x0740
#define TestIndex report_title_1+1                                                        //06-12-15|0x0740
//************************************************************************                //06-12-15|0x0740
#ifndef TestIndex                                                                         //06-12-17|0x0765
#define TestIndex 0                                                                       //06-12-17|0x0765
#endif                                                                                    //06-12-17|0x0765
//------------------------------------------------------------------------                //06-12-17|0x0765
enum {  report_line_1 = TestIndex };                                                      //06-12-17|0x0765
//------------------------------------------------------------------------                //06-12-17|0x0765
#undef TestIndex                                                                          //06-12-17|0x0765
#define TestIndex report_line_1+1                                                         //06-12-17|0x0765
//************************************************************************                //06-12-17|0x0765
#ifndef TestIndex                                                                         //06-12-15|0x078b
#define TestIndex 0                                                                       //06-12-15|0x078b
#endif                                                                                    //06-12-15|0x078b
//------------------------------------------------------------------------                //06-12-15|0x078b
enum {  report_numeric_1 = TestIndex };                                                   //06-12-15|0x078b
//------------------------------------------------------------------------                //06-12-15|0x078b
#undef TestIndex                                                                          //06-12-15|0x078b
#define TestIndex report_numeric_1+1                                                      //06-12-15|0x078b
//************************************************************************                //06-12-15|0x078b
//*******************************************************************************         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
//****                       END OF FILE                                     ****         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
//*******************************************************************************         //05-24-97|0x07c7
#endif                                                                                    //05-24-97|0x07c7
