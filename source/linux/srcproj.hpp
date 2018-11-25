//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
// LIBRARY-SOURCE MAIN ENGINE                                                             //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x001b
//  defined in the associated manual.                                                     //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x001b
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x001b
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x001b
//  (at your option) any later version.                                                   //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x001b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x001b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x001b
//  GNU General Public License for more details.                                          //06-07-12|0x001b
//                                                                                        //06-07-12|0x001b
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x001b
//  along with this program; if not, write to the Free Software                           //06-07-12|0x001b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x001b
//  USA                                                                                   //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//  For further information, please contact Robert Adams:                                 //06-07-12|0x001b
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x001b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x001b
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
//*****************************************************************************           //06-07-12|0x001b
#ifndef srcproj_hpp                                                                       //06-07-12|0x001c
#define srcproj_hpp                                                                       //06-07-12|0x001c
//***************************************************************************             //06-07-12|0x002c
//***************************************************************************             //06-07-12|0x002d
//***************************************************************************             //06-07-12|0x002e
//******                                                               ******             //06-07-12|0x002f
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0030
//******                                                               ******             //06-07-12|0x0031
//***************************************************************************             //06-07-12|0x0032
//***************************************************************************             //06-07-12|0x0033
#define CMK_EXTENT ".cmk"                                                                 //06-07-12|0x0034
#define TMK_EXTENT ".tmk"                                                                 //06-07-12|0x0034
#define RPT_EXTENT ".rpt"                                                                 //06-07-12|0x0034
#define PMK_EXTENT ".pmk"                                                                 //06-07-12|0x0034
#define MAC_EXTENT ".mac"                                                                 //06-07-12|0x0034
#define SRC_EXTENT ".src"                                                                 //06-07-12|0x0034
#define PLB_EXTENT ".plb"                                                                 //06-07-12|0x0034
#define DIC_EXTENT ".dic"                                                                 //06-07-12|0x0034
#define MBX_EXTENT ".mbx"                                                                 //06-07-12|0x0034
#define MBC_EXTENT ".mbc"                                                                 //06-07-12|0x0034
#define RAN_EXTENT ".ran"                                                                 //06-07-12|0x0034
#define BUF_OUT_EXTENT ".bfo"                                                             //06-07-12|0x0034
#define BUF_IN_EXTENT ".bfi"                                                              //06-07-12|0x0034
//***************************************************************************             //06-07-12|0x0037
//***************************************************************************             //06-07-12|0x0038
//******                                                               ******             //06-07-12|0x0039
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x003a
//******                                                               ******             //06-07-12|0x003b
//***************************************************************************             //06-07-12|0x003c
//***************************************************************************             //06-07-12|0x003d
#define UserError 0x0000                                                                  //06-07-12|0x003e
#define BuildError 0x7fff                                                                 //06-07-12|0x003e
#define Display 0x7ffe                                                                    //06-07-12|0x003e
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x003e
#define Success 0xffff                                                                    //06-07-12|0x003e
#define SystemError 0x8000                                                                //06-07-12|0x003e
#define Continue 0x0001                                                                   //06-07-12|0x003e
#define FileDone 0x0002                                                                   //06-07-12|0x003e
#define LineDone 0x0003                                                                   //06-07-12|0x003e
#define Yes 0x0004                                                                        //06-07-12|0x003e
#define No 0x0005                                                                         //06-07-12|0x003e
#define RepeatChar '\x6'                                                                  //06-07-12|0x003e
#define Great 0x0007                                                                      //06-07-12|0x003e
#define Equal 0x0008                                                                      //06-07-12|0x003e
#define Less 0x0009                                                                       //06-07-12|0x003e
#define Zero 0x000a                                                                       //06-07-12|0x003e
#define Minus 0x000b                                                                      //06-07-12|0x003e
//***************************************************************************             //06-07-12|0x003f
#define SystemMsg PcgSystemError("srcproj", __LINE__);                                    //06-07-12|0x0040
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x0040
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x0040
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0041
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0041
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0041
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0041
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0042
#define _SwitchOk case Success: break                                                     //06-07-12|0x0042
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0042
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0042
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0042
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0042
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0042
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0042
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0042
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0042
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0042
//***************************************************************************             //06-07-12|0x0064
//***************************************************************************             //06-07-12|0x0065
//******                                                               ******             //06-07-12|0x0066
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0067
//******                                                               ******             //06-07-12|0x0068
//***************************************************************************             //06-07-12|0x0069
//***************************************************************************             //06-07-12|0x006a
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x006b
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x006b
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x006b
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x006b
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-12|0x006b
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-12|0x006b
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x006b
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x006b
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x006b
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x006b
//************************************************************************                //06-07-12|0x006b
#ifndef TestIndex                                                                         //06-07-12|0x006b
#define TestIndex 0                                                                       //06-07-12|0x006b
#endif                                                                                    //06-07-12|0x006b
//------------------------------------------------------------------------                //06-07-12|0x006b
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x006b
//------------------------------------------------------------------------                //06-07-12|0x006b
#undef TestIndex                                                                          //06-07-12|0x006b
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x006b
//************************************************************************                //06-07-12|0x006b
//***************************************************************************             //06-07-12|0x006c
//************************************************************************                //06-07-12|0x006d
#define SourceState source_project_addr->state                                            //06-07-12|0x006d
#define SourceStatus source_project_addr->status                                          //06-07-12|0x006d
#define SourceRunFlag source_project_addr->run_flag                                       //06-07-12|0x006d
#define SourceErrorControl source_project_addr->error_control                             //06-07-12|0x006d
#define SourceProjectFile source_project_addr->project_file                               //06-07-12|0x006d
#define SourceFiles source_project_addr->files                                            //06-07-12|0x006d
#define SourceWork source_project_addr->work                                              //06-07-12|0x006d
#define SourceLibName source_project_addr->lib_name                                       //06-07-12|0x006d
#define SourceTokens source_project_addr->tokens                                          //06-07-12|0x006d
#define SourceArguments source_project_addr->arguments                                    //06-07-12|0x006d
#define SourceOutTime source_project_addr->out_time                                       //06-07-12|0x006d
#define SourceInTime source_project_addr->in_time                                         //06-07-12|0x006d
//------------------------------------------------------------------------                //06-07-12|0x006d
#define SourceTokensAddr &(source_project_addr->tokens)                                   //06-07-12|0x006d
#define SourceArgumentsAddr &(source_project_addr->arguments)                             //06-07-12|0x006d
#define SourceProjectFileAddr &(source_project_addr->project_file)                        //06-07-12|0x006d
#define SourceWorkAddr &(source_project_addr->work)                                       //06-07-12|0x006d
#define SourceLibNameAddr &(source_project_addr->lib_name)                                //06-07-12|0x006d
#define SourceFilesAddr &(source_project_addr->files)                                     //06-07-12|0x006d
#define SourceOutTimeAddr &(source_project_addr->out_time)                                //06-07-12|0x006d
#define SourceInTimeAddr &(source_project_addr->in_time)                                  //06-07-12|0x006d
#define SourceBridgeAddr &(source_project_addr->bridge)                                   //06-07-12|0x006d
#define LibNameChar(i) SourceLibName.line[i]                                              //06-07-12|0x006e
#define LibNameLine SourceLibName.line[0]                                                 //06-07-12|0x006e
#define LibNameLineAddr &(SourceLibName.line[0])                                          //06-07-12|0x006e
#define LibNameMacroLineNo SourceLibName.macro_line_no                                    //06-07-12|0x006e
#define LibNameType SourceLibName.type                                                    //06-07-12|0x006e
#define LibNameStartCol SourceLibName.start_col                                           //06-07-12|0x006e
#define LibNameStartCall SourceLibName.start_call                                         //06-07-12|0x006e
#define LibNamePosition SourceLibName.position                                            //06-07-12|0x006e
#define LibNameLength SourceLibName.length                                                //06-07-12|0x006e
#define LibNameColumn SourceLibName.column                                                //06-07-12|0x006e
//**********************************************************************                  //06-07-12|0x006e
#define BridgeChar(i) SourceBridge.line[i]                                                //06-07-12|0x006f
#define BridgeLine SourceBridge.line[0]                                                   //06-07-12|0x006f
#define BridgeLineAddr &(SourceBridge.line[0])                                            //06-07-12|0x006f
#define BridgeMacroLineNo SourceBridge.macro_line_no                                      //06-07-12|0x006f
#define BridgeType SourceBridge.type                                                      //06-07-12|0x006f
#define BridgeStartCol SourceBridge.start_col                                             //06-07-12|0x006f
#define BridgeStartCall SourceBridge.start_call                                           //06-07-12|0x006f
#define BridgePosition SourceBridge.position                                              //06-07-12|0x006f
#define BridgeLength SourceBridge.length                                                  //06-07-12|0x006f
#define BridgeColumn SourceBridge.column                                                  //06-07-12|0x006f
//**********************************************************************                  //06-07-12|0x006f
#define WorkChar(i) SourceWork.line[i]                                                    //06-07-12|0x0070
#define WorkLine SourceWork.line[0]                                                       //06-07-12|0x0070
#define WorkLineAddr &(SourceWork.line[0])                                                //06-07-12|0x0070
#define WorkMacroLineNo SourceWork.macro_line_no                                          //06-07-12|0x0070
#define WorkType SourceWork.type                                                          //06-07-12|0x0070
#define WorkStartCol SourceWork.start_col                                                 //06-07-12|0x0070
#define WorkStartCall SourceWork.start_call                                               //06-07-12|0x0070
#define WorkPosition SourceWork.position                                                  //06-07-12|0x0070
#define WorkLength SourceWork.length                                                      //06-07-12|0x0070
#define WorkColumn SourceWork.column                                                      //06-07-12|0x0070
//**********************************************************************                  //06-07-12|0x0070
//**********************************************************************                  //06-07-12|0x0071
#define FilesSrcFile SourceFiles.source_file                                              //06-07-12|0x0071
#define FilesSrcFileAddr &(SourceFiles.source_file)                                       //06-07-12|0x0071
#define FilesSrcLineNo SourceFiles.source_file.line_no                                    //06-07-12|0x0071
#define FilesSrcFileName &(SourceFiles.source_file.file_control.name[0])                  //06-07-12|0x0071
#define FilesSrcExtent &(SourceFiles.source_extent[0])                                    //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FilesMailBoxFileNo SourceFiles.mailbox_file_no                                    //06-07-12|0x0071
#define FilesMailBoxNoFiles SourceFiles.no_mailbox_files                                  //06-07-12|0x0071
#define FilesMailBoxName(i) SourceFiles.mailbox_file[i].name                              //06-07-12|0x0071
#define FilesMailBoxPath &(SourceFiles.mailbox_path[0])                                   //06-07-12|0x0071
#define FilesMailBoxStatus(i) SourceFiles.mailbox_file[i].status                          //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FilesOutNoFiles SourceFiles.no_output_files                                       //06-07-12|0x0071
#define FilesOutFile(i) SourceFiles.output_file[i].file                                   //06-07-12|0x0071
#define FilesOutFileAddr(i) &(SourceFiles.output_file[i].file)                            //06-07-12|0x0071
#define FilesOutLineNo(i) SourceFiles.output_file[i].file.line_no                         //06-07-12|0x0071
#define FilesOutStatus(i) SourceFiles.output_file[i].file.status                          //06-07-12|0x0071
#define FilesOutFileName(i) &(SourceFiles.output_file[i].file.file_control.name[0])       //06-07-12|0x0071
#define FilesOutExtent(i) &(SourceFiles.output_file[i].extent[0])                         //06-07-12|0x0071
#define FilesOutPath(i) &(SourceFiles.output_file[i].path[0])                             //06-07-12|0x0071
#define FilesOutName &(SourceFiles.output_name[0])                                        //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FilesInNoFiles SourceFiles.no_input_files                                         //06-07-12|0x0071
#define FilesInFile(i) SourceFiles.input_file[i].file                                     //06-07-12|0x0071
#define FilesInFileAddr(i) &(SourceFiles.input_file[i].file)                              //06-07-12|0x0071
#define FilesInLineNo(i) SourceFiles.input_file[i].file.line_no                           //06-07-12|0x0071
#define FilesInFileName(i) &(SourceFiles.input_file[i].file.file_control.name[0])         //06-07-12|0x0071
#define FilesInExtent(i) &(SourceFiles.input_file[i].extent[0])                           //06-07-12|0x0071
#define FilesInPath(i) &(SourceFiles.input_file[i].path[0])                               //06-07-12|0x0071
#define FilesInName &(SourceFiles.input_name[0])                                          //06-07-12|0x0071
//----------------------------------------------------------------------                  //06-07-12|0x0071
#define FilesOutBufferFileSize SourceFiles.out_buffer_file_size                           //06-07-12|0x0071
#define FilesOutBufferFile SourceFiles.out_buffer_file                                    //06-07-12|0x0071
#define FilesOutBufferFileAddr &(SourceFiles.out_buffer_file)                             //06-07-12|0x0071
//************************************************************************                //06-07-12|0x0072
#define TokensTokenAddr(i) &(SourceTokens.token[i])                                       //06-07-12|0x0072
#define TokensMacroLineNo(i) SourceTokens.token[i].macro_line_no                          //06-07-12|0x0072
#define TokensLineAddr(i) &(SourceTokens.token[i].line[0])                                //06-07-12|0x0072
#define TokensToken(i) SourceTokens.token[i]                                              //06-07-12|0x0072
#define TokensLine(i) SourceTokens.token[i].line                                          //06-07-12|0x0072
#define TokensLength(i) SourceTokens.token[i].length                                      //06-07-12|0x0072
#define TokensColumn(i) SourceTokens.token[i].column                                      //06-07-12|0x0072
#define TokensHash(i) SourceTokens.token[i].hash                                          //06-07-12|0x0072
#define TokensPosition(i) SourceTokens.token[i].position                                  //06-07-12|0x0072
#define TokensType(i) SourceTokens.token[i].type                                          //06-07-12|0x0072
#define TokensStartCol(i) SourceTokens.token[i].start_col                                 //06-07-12|0x0072
#define TokensStartCall(i) SourceTokens.token[i].start_call                               //06-07-12|0x0072
#define TokensChar(i,j) SourceTokens.token[i].line[j]                                     //06-07-12|0x0072
#define TokensNoTokens SourceTokens.no_tokens                                             //06-07-12|0x0072
//************************************************************************                //06-07-12|0x0073
#define ArgumentsTokenAddr(i) &(SourceArguments.token[i])                                 //06-07-12|0x0073
#define ArgumentsMacroLineNo(i) SourceArguments.token[i].macro_line_no                    //06-07-12|0x0073
#define ArgumentsLineAddr(i) &(SourceArguments.token[i].line[0])                          //06-07-12|0x0073
#define ArgumentsToken(i) SourceArguments.token[i]                                        //06-07-12|0x0073
#define ArgumentsLine(i) SourceArguments.token[i].line                                    //06-07-12|0x0073
#define ArgumentsLength(i) SourceArguments.token[i].length                                //06-07-12|0x0073
#define ArgumentsColumn(i) SourceArguments.token[i].column                                //06-07-12|0x0073
#define ArgumentsHash(i) SourceArguments.token[i].hash                                    //06-07-12|0x0073
#define ArgumentsPosition(i) SourceArguments.token[i].position                            //06-07-12|0x0073
#define ArgumentsType(i) SourceArguments.token[i].type                                    //06-07-12|0x0073
#define ArgumentsStartCol(i) SourceArguments.token[i].start_col                           //06-07-12|0x0073
#define ArgumentsStartCall(i) SourceArguments.token[i].start_call                         //06-07-12|0x0073
#define ArgumentsChar(i,j) SourceArguments.token[i].line[j]                               //06-07-12|0x0073
#define ArgumentsNoTokens SourceArguments.no_tokens                                       //06-07-12|0x0073
//************************************************************************                //06-07-12|0x0075
#define InputTokenAddr(i) &(InputAddr->token[i])                                          //06-07-12|0x0075
#define InputMacroLineNo(i) InputAddr->token[i].macro_line_no                             //06-07-12|0x0075
#define InputLineAddr(i) &(InputAddr->token[i].line[0])                                   //06-07-12|0x0075
#define InputToken(i) InputAddr->token[i]                                                 //06-07-12|0x0075
#define InputLine(i) InputAddr->token[i].line                                             //06-07-12|0x0075
#define InputLength(i) InputAddr->token[i].length                                         //06-07-12|0x0075
#define InputColumn(i) InputAddr->token[i].column                                         //06-07-12|0x0075
#define InputHash(i) InputAddr->token[i].hash                                             //06-07-12|0x0075
#define InputPosition(i) InputAddr->token[i].position                                     //06-07-12|0x0075
#define InputType(i) InputAddr->token[i].type                                             //06-07-12|0x0075
#define InputStartCol(i) InputAddr->token[i].start_col                                    //06-07-12|0x0075
#define InputStartCall(i) InputAddr->token[i].start_call                                  //06-07-12|0x0075
#define InputChar(i,j) InputAddr->token[i].line[j]                                        //06-07-12|0x0075
#define InputNoTokens InputAddr->no_tokens                                                //06-07-12|0x0075
#define OutChar(i) OutFar->line[i]                                                        //06-07-12|0x0076
#define OutLine OutFar->line[0]                                                           //06-07-12|0x0076
#define OutLineAddr &(OutFar->line[0])                                                    //06-07-12|0x0076
#define OutMacroLineNo OutFar->macro_line_no                                              //06-07-12|0x0076
#define OutType OutFar->type                                                              //06-07-12|0x0076
#define OutStartCol OutFar->start_col                                                     //06-07-12|0x0076
#define OutStartCall OutFar->start_call                                                   //06-07-12|0x0076
#define OutPosition OutFar->position                                                      //06-07-12|0x0076
#define OutLength OutFar->length                                                          //06-07-12|0x0076
#define OutColumn OutFar->column                                                          //06-07-12|0x0076
//**********************************************************************                  //06-07-12|0x0076
#define InChar(i) InFar->line[i]                                                          //06-07-12|0x0077
#define InLine InFar->line[0]                                                             //06-07-12|0x0077
#define InLineAddr &(InFar->line[0])                                                      //06-07-12|0x0077
#define InMacroLineNo InFar->macro_line_no                                                //06-07-12|0x0077
#define InType InFar->type                                                                //06-07-12|0x0077
#define InStartCol InFar->start_col                                                       //06-07-12|0x0077
#define InStartCall InFar->start_call                                                     //06-07-12|0x0077
#define InPosition InFar->position                                                        //06-07-12|0x0077
#define InLength InFar->length                                                            //06-07-12|0x0077
#define InColumn InFar->column                                                            //06-07-12|0x0077
//**********************************************************************                  //06-07-12|0x0077
#define MailBoxNameChar(i) mail_box_addr->line[i]                                         //09-06-29|0x0078
#define MailBoxNameLine mail_box_addr->line[0]                                            //09-06-29|0x0078
#define MailBoxNameLineAddr &(mail_box_addr->line[0])                                     //09-06-29|0x0078
#define MailBoxNameMacroLineNo mail_box_addr->macro_line_no                               //09-06-29|0x0078
#define MailBoxNameType mail_box_addr->type                                               //09-06-29|0x0078
#define MailBoxNameStartCol mail_box_addr->start_col                                      //09-06-29|0x0078
#define MailBoxNameStartCall mail_box_addr->start_call                                    //09-06-29|0x0078
#define MailBoxNamePosition mail_box_addr->position                                       //09-06-29|0x0078
#define MailBoxNameLength mail_box_addr->length                                           //09-06-29|0x0078
#define MailBoxNameColumn mail_box_addr->column                                           //09-06-29|0x0078
//**********************************************************************                  //09-06-29|0x0078
#define StrDataCpy(i,j) MemCpy(i,j,sizeof(STRING_DATA))                                   //06-07-12|0x007a
#define TokensDataCpy(i,j) MemCpy(i,j,sizeof(TOKENS))                                     //06-07-12|0x007a
#define TokensDataClr(i) MemSet(i,0x00,sizeof(TOKENS))                                    //06-07-12|0x007a
#define ZeroFiles1(i) MemSet(i, 0x00, sizeof(PROCESS_FILES))                              //06-07-12|0x007a
#define ZeroFiles ZeroFiles1(SourceFilesAddr)                                             //06-07-12|0x007a
#define ProjectDoesNotExist Finish("Project File Does Not Exist")                         //06-07-12|0x007a
#define LibraryDoesNotExist Finish("Library File Does Not Exist")                         //06-07-12|0x007a
#define SourceDoesNotExist Finish("Source File Does Not Exist")                           //06-07-12|0x007a
#define TextDoesNotExist Finish("Text File Does Not Exist")                               //06-07-12|0x007a
#define IllegalCommand Finish("Illegal Command")                                          //06-07-12|0x007a
#define IllegalNoArgs Finish("Illegal Number of Arguments")                               //06-07-12|0x007a
#define IllegalEndFile Finish("Illegal End Of File")                                      //06-07-12|0x007a
#define EnterProjectName2(i,j) enter_name(SourceProjectFileAddr, i, j)                    //06-07-12|0x007a
#define EnterProjectName1(i) EnterProjectName2(InputTokenAddr(0), i)                      //06-07-12|0x007a
#define EnterProjectName EnterProjectName1(PMK_EXTENT)                                    //06-07-12|0x007a
#define ProjectFileTime file_time(SourceProjectFileAddr)                                  //06-07-12|0x007a
#define CreateMailbox2(i,j) MailDictInitial(i, j)                                         //06-07-12|0x007a
#define CreateMailbox1(i) CreateMailbox2(InputLineAddr(0), i)                             //06-07-12|0x007a
#define CreateMailbox CreateMailbox1(MBC_EXTENT)                                          //06-07-12|0x007a
#define FileDateExists ((SourceInTime > 0) ? Yes : No)                                    //06-07-12|0x007a
#define FileDateRecent3 SourceInTime > SourceOutTime                                      //06-07-12|0x007a
#define FileDateRecent2 SourceInTime == SourceOutTime                                     //06-07-12|0x007a
#define FileDateRecent1 ((FileDateRecent2) ? 0 : -1)                                      //06-07-12|0x007a
#define FileDateRecent ((FileDateRecent3) ? 1 : FileDateRecent1)                          //06-07-12|0x007a
#define OpenProject open_project(SourceProjectFileAddr)                                   //06-07-12|0x007a
#define ReadProject read_project(SourceProjectFileAddr)                                   //06-07-12|0x007a
#define CloseProject close_project(SourceProjectFileAddr)                                 //06-07-12|0x007a
#define IfNoTokens1(i) (TokensNoTokens < i)                                               //06-07-12|0x007a
#define IfNoTokens2(i) (TokensNoTokens > i)                                               //06-07-12|0x007a
#define IfNoTokens(i,j) if(IfNoTokens1(i) || IfNoTokens2(j))                              //06-07-12|0x007a
#define CmdTest(i) StrCmp(TokensLineAddr(0),i)                                            //06-07-12|0x007a
#define DefaultError error_control("_DEFAULT_ERROR", Continue)                            //06-07-12|0x007a
#define ErrorToUser error_control("_USER_ERROR", UserError)                               //06-07-12|0x007a
#define ErrorToBuild error_control("_BUILD_ERROR", BuildError)                            //06-07-12|0x007a
#define FileTextPrepare1(i,j) TextPrepare(TokensTokenAddr(i-1), j)                        //06-07-12|0x007a
#define FileTextPrepare(i) FileTextPrepare1(i,TokensTokenAddr(i))                         //06-07-12|0x007a
#define UpdateTaskNo update_task_no(TaskNoFar)                                            //06-07-12|0x007a
#define EnterLibraryName MacDictName(TokensLineAddr(0),    PLB_EXTENT)                    //06-07-12|0x007a
#define LibraryDate MacDictExists(SourceInTimeAddr)                                       //06-07-12|0x007a
#define EnterSrcFileName2(i,j) enter_name(FilesSrcFileAddr, i, j)                         //06-07-12|0x007a
#define EnterSrcFileName1(i) EnterSrcFileName2(TokensTokenAddr(0), i)                     //06-07-12|0x007a
#define EnterSrcFileName EnterSrcFileName1(FilesSrcExtent)                                //06-07-12|0x007a
#define SourceFileTime file_time(FilesSrcFileAddr)                                        //06-07-12|0x007a
#define OpenSource open_project(FilesSrcFileAddr)                                         //06-07-12|0x007a
#define CloseSource close_project(FilesSrcFileAddr)                                       //06-07-12|0x007a
#define EnterTxtFileName1(i) enter_input_names(i)                                         //06-07-12|0x007a
#define EnterTxtFileName EnterTxtFileName1(TokensTokenAddr(2))                            //06-07-12|0x007a
#define FileExtentExists (((FilesInNoFiles) != 0) ? Yes : No)                             //06-07-12|0x007a
#define TextFileNameExists1(i) ((TokensNoTokens == 3) ? Yes : i)                          //06-07-12|0x007a
#define TextFileNameExists2 ((TokensNoTokens == 2) ? No  : UserError)                     //06-07-12|0x007a
#define TextFileNameExists TextFileNameExists1(TextFileNameExists2)                       //06-07-12|0x007a
#define TextFileTime input_file_times()                                                   //06-07-12|0x007a
#define OpenText open_input_files()                                                       //06-07-12|0x007a
#define CloseText close_text()                                                            //06-07-12|0x007a
#define CommitInputFile(i) FileCommitText(FilesInFileAddr(i))                             //06-07-12|0x007a
#define EnterDictFileName1(i) SrceDictName(TokensLineAddr(0), i)                          //06-07-12|0x007a
#define EnterDictFileName EnterDictFileName1(DIC_EXTENT)                                  //06-07-12|0x007a
#define InitialCryptofile1(i) CryptoInitial(TokensLineAddr(0), i)                         //06-07-12|0x007a
#define InitialCryptofile InitialCryptofile1(RAN_EXTENT)                                  //06-07-12|0x007a
#define InitialOutBufferfile2(i,j) initial_buf_out(&FilesOutBufferFile, i, j)             //06-07-12|0x007a
#define InitialOutBufferfile1(i) InitialOutBufferfile2(TokensTokenAddr(0),i)              //06-07-12|0x007a
#define InitialOutBufferfile InitialOutBufferfile1(BUF_OUT_EXTENT)                        //06-07-12|0x007a
#define InitialInBufferfile2(i,j) initial_buf_in(&FilesInBufferFile, i, j)                //06-07-12|0x007a
#define InitialInBufferfile1(i) InitialInBufferfile2(TokensTokenAddr(0),i)                //06-07-12|0x007a
#define InitialInBufferfile InitialInBufferfile1(BUF_IN_EXTENT)                           //06-07-12|0x007a
#define CloseOutBufferFile close_buffer_out(&FilesOutBufferFile)                          //06-07-12|0x007a
#define CloseInBufferFile close_buffer_in(&FilesInBufferFile)                             //06-07-12|0x007a
#define ProcessSource2(i,j) PrecsrceProcess(SourceFilesAddr, i, j)                        //06-07-12|0x007a
#define ProcessSource1(j) ProcessSource2(PcgTokenFar, j)                                  //06-07-12|0x007a
#define ProcessSource ProcessSource1(SourceErrorControl)                                  //06-07-12|0x007a
#define LoadArguments1(j) TokensDataCpy(SourceArgumentsAddr, j)                           //06-07-12|0x007a
#define LoadArguments LoadArguments1(SourceTokensAddr)                                    //06-07-12|0x007a
#define ClearArguments TokensDataClr(SourceArgumentsAddr)                                 //06-07-12|0x007a
#define InitialFile FileInitialText(TextFileAddr)                                         //06-07-12|0x007a
#define CommitFile FileCommitText(TextFileAddr)                                           //06-07-12|0x007a
#define EnterFileName FileEnterName(InLineAddr, Extent)                                   //06-07-12|0x007a
#define InitialOutFile(i) FileInitialText(FilesOutFileAddr(i))                            //06-07-12|0x007a
#define CommitOutFile(i) FileCommitText(FilesOutFileAddr(i))                              //06-07-12|0x007a
#define GetOutputName2(i,j) MemCCpy(i,j,0x00, _MAX_PATH)                                  //06-07-12|0x007a
#define GetOutputName1(i) GetOutputName2(i,TokensLineAddr(1))                             //06-07-12|0x007a
#define GetOutputName GetOutputName1(FilesOutName)                                        //06-07-12|0x007a
#define EnterOutPath(i) FileEnterPath(FilesOutPath(i))                                    //06-07-12|0x007a
#define EnterOutFileName1(i) FileEnterName(FilesOutName, i)                               //06-07-12|0x007a
#define EnterOutFileName(i) EnterOutFileName1(FilesOutExtent(i))                          //06-07-12|0x007a
#define OpenStateOutFile(i) FileOpenTextState(FilesOutFileAddr(i))                        //06-07-12|0x007a
#define CloseOutFiles close_output()                                                      //06-07-12|0x007a
#define InitialTextFile(i) FileInitialText(FilesInFileAddr(i))                            //06-07-12|0x007a
#define CommitTextFile(i) FileCommitText(FilesInFileAddr(i))                              //06-07-12|0x007a
#define EnterTextPath(i) FileEnterPath(FilesInPath(i))                                    //06-07-12|0x007a
#define EnterTextFileName1(i) FileEnterName(FilesInName, i)                               //06-07-12|0x007a
#define EnterTextFileName(i) EnterTextFileName1(FilesInExtent(i))                         //06-07-12|0x007a
#define LoadPostOffice load_mailbox(POSTOFFICE_FILE)                                      //06-07-12|0x007a
#define LoadMailBox load_mailbox(MAILBOX_FILE)                                            //06-07-12|0x007a
#define MailBoxDates mailbox_dates()                                                      //06-07-12|0x007a
#define MailBoxTest (FilesMailBoxNoFiles > 0) ? Yes : No                                  //06-07-12|0x007a
#define TestOutStatus test_output_status()                                                //06-07-12|0x007a
#define MsgTest GuiTestEmpty()                                                            //06-07-12|0x007a
#ifndef TestIndex                                                                         //06-07-12|0x0086
#define TestIndex 0                                                                       //06-07-12|0x0086
#endif                                                                                    //06-07-12|0x0086
//------------------------------------------------------------------------                //06-07-12|0x0086
enum {  srcproj_allocate_1 = TestIndex };                                                 //06-07-12|0x0086
//------------------------------------------------------------------------                //06-07-12|0x0086
#undef TestIndex                                                                          //06-07-12|0x0086
#define TestIndex srcproj_allocate_1+1                                                    //06-07-12|0x0086
//************************************************************************                //06-07-12|0x0086
#ifndef TestIndex                                                                         //06-07-12|0x00a2
#define TestIndex 0                                                                       //06-07-12|0x00a2
#endif                                                                                    //06-07-12|0x00a2
//------------------------------------------------------------------------                //06-07-12|0x00a2
enum {  srcproj_free_1 = TestIndex };                                                     //06-07-12|0x00a2
//------------------------------------------------------------------------                //06-07-12|0x00a2
#undef TestIndex                                                                          //06-07-12|0x00a2
#define TestIndex srcproj_free_1+1                                                        //06-07-12|0x00a2
//************************************************************************                //06-07-12|0x00a2
#ifndef TestIndex                                                                         //10-05-15|0x02ca
#define TestIndex 0                                                                       //10-05-15|0x02ca
#endif                                                                                    //10-05-15|0x02ca
//------------------------------------------------------------------------                //10-05-15|0x02ca
enum {  enter_input_names_1 = TestIndex };                                                //10-05-15|0x02ca
//------------------------------------------------------------------------                //10-05-15|0x02ca
#undef TestIndex                                                                          //10-05-15|0x02ca
#define TestIndex enter_input_names_1+1                                                   //10-05-15|0x02ca
//************************************************************************                //10-05-15|0x02ca
#ifndef TestIndex                                                                         //06-09-11|0x02ee
#define TestIndex 0                                                                       //06-09-11|0x02ee
#endif                                                                                    //06-09-11|0x02ee
//------------------------------------------------------------------------                //06-09-11|0x02ee
enum {  enter_name_1 = TestIndex };                                                       //06-09-11|0x02ee
//------------------------------------------------------------------------                //06-09-11|0x02ee
#undef TestIndex                                                                          //06-09-11|0x02ee
#define TestIndex enter_name_1+1                                                          //06-09-11|0x02ee
//************************************************************************                //06-09-11|0x02ee
#ifndef TestIndex                                                                         //<----   |0x0306
#define TestIndex 0                                                                       //<----   |0x0306
#endif                                                                                    //<----   |0x0306
//------------------------------------------------------------------------                //<----   |0x0306
enum {  initial_buf_out_1 = TestIndex };                                                  //<----   |0x0306
//------------------------------------------------------------------------                //<----   |0x0306
#undef TestIndex                                                                          //<----   |0x0306
#define TestIndex initial_buf_out_1+1                                                     //<----   |0x0306
//************************************************************************                //<----   |0x0306
#ifndef TestIndex                                                                         //<----   |0x031f
#define TestIndex 0                                                                       //<----   |0x031f
#endif                                                                                    //<----   |0x031f
//------------------------------------------------------------------------                //<----   |0x031f
enum {  close_buffer_out_1 = TestIndex };                                                 //<----   |0x031f
//------------------------------------------------------------------------                //<----   |0x031f
#undef TestIndex                                                                          //<----   |0x031f
#define TestIndex close_buffer_out_1+1                                                    //<----   |0x031f
//************************************************************************                //<----   |0x031f
#ifndef TestIndex                                                                         //10-05-15|0x0338
#define TestIndex 0                                                                       //10-05-15|0x0338
#endif                                                                                    //10-05-15|0x0338
//------------------------------------------------------------------------                //10-05-15|0x0338
enum {  input_file_times_1 = TestIndex };                                                 //10-05-15|0x0338
//------------------------------------------------------------------------                //10-05-15|0x0338
#undef TestIndex                                                                          //10-05-15|0x0338
#define TestIndex input_file_times_1+1                                                    //10-05-15|0x0338
//************************************************************************                //10-05-15|0x0338
#ifndef TestIndex                                                                         //06-09-11|0x0358
#define TestIndex 0                                                                       //06-09-11|0x0358
#endif                                                                                    //06-09-11|0x0358
//------------------------------------------------------------------------                //06-09-11|0x0358
enum {  file_time_1 = TestIndex };                                                        //06-09-11|0x0358
//------------------------------------------------------------------------                //06-09-11|0x0358
#undef TestIndex                                                                          //06-09-11|0x0358
#define TestIndex file_time_1+1                                                           //06-09-11|0x0358
//************************************************************************                //06-09-11|0x0358
#ifndef TestIndex                                                                         //10-05-15|0x036f
#define TestIndex 0                                                                       //10-05-15|0x036f
#endif                                                                                    //10-05-15|0x036f
//------------------------------------------------------------------------                //10-05-15|0x036f
enum {  open_input_files_1 = TestIndex };                                                 //10-05-15|0x036f
//------------------------------------------------------------------------                //10-05-15|0x036f
#undef TestIndex                                                                          //10-05-15|0x036f
#define TestIndex open_input_files_1+1                                                    //10-05-15|0x036f
//************************************************************************                //10-05-15|0x036f
#ifndef TestIndex                                                                         //06-09-12|0x038a
#define TestIndex 0                                                                       //06-09-12|0x038a
#endif                                                                                    //06-09-12|0x038a
//------------------------------------------------------------------------                //06-09-12|0x038a
enum {  open_project_1 = TestIndex };                                                     //06-09-12|0x038a
//------------------------------------------------------------------------                //06-09-12|0x038a
#undef TestIndex                                                                          //06-09-12|0x038a
#define TestIndex open_project_1+1                                                        //06-09-12|0x038a
//************************************************************************                //06-09-12|0x038a
#ifndef TestIndex                                                                         //06-09-12|0x03a9
#define TestIndex 0                                                                       //06-09-12|0x03a9
#endif                                                                                    //06-09-12|0x03a9
//------------------------------------------------------------------------                //06-09-12|0x03a9
enum {  read_project_1 = TestIndex };                                                     //06-09-12|0x03a9
//------------------------------------------------------------------------                //06-09-12|0x03a9
#undef TestIndex                                                                          //06-09-12|0x03a9
#define TestIndex read_project_1+1                                                        //06-09-12|0x03a9
//************************************************************************                //06-09-12|0x03a9
#ifndef TestIndex                                                                         //06-09-12|0x03aa
#define TestIndex 0                                                                       //06-09-12|0x03aa
#endif                                                                                    //06-09-12|0x03aa
//------------------------------------------------------------------------                //06-09-12|0x03aa
enum {  read_project_2 = TestIndex };                                                     //06-09-12|0x03aa
//------------------------------------------------------------------------                //06-09-12|0x03aa
#undef TestIndex                                                                          //06-09-12|0x03aa
#define TestIndex read_project_2+1                                                        //06-09-12|0x03aa
//************************************************************************                //06-09-12|0x03aa
#ifndef TestIndex                                                                         //06-09-12|0x03ab
#define TestIndex 0                                                                       //06-09-12|0x03ab
#endif                                                                                    //06-09-12|0x03ab
//------------------------------------------------------------------------                //06-09-12|0x03ab
enum {  read_project_3 = TestIndex };                                                     //06-09-12|0x03ab
//------------------------------------------------------------------------                //06-09-12|0x03ab
#undef TestIndex                                                                          //06-09-12|0x03ab
#define TestIndex read_project_3+1                                                        //06-09-12|0x03ab
//************************************************************************                //06-09-12|0x03ab
#ifndef TestIndex                                                                         //06-09-12|0x03ac
#define TestIndex 0                                                                       //06-09-12|0x03ac
#endif                                                                                    //06-09-12|0x03ac
//------------------------------------------------------------------------                //06-09-12|0x03ac
enum {  read_project_4 = TestIndex };                                                     //06-09-12|0x03ac
//------------------------------------------------------------------------                //06-09-12|0x03ac
#undef TestIndex                                                                          //06-09-12|0x03ac
#define TestIndex read_project_4+1                                                        //06-09-12|0x03ac
//************************************************************************                //06-09-12|0x03ac
#ifndef TestIndex                                                                         //06-09-12|0x03d2
#define TestIndex 0                                                                       //06-09-12|0x03d2
#endif                                                                                    //06-09-12|0x03d2
//------------------------------------------------------------------------                //06-09-12|0x03d2
enum {  text_prepare_1 = TestIndex };                                                     //06-09-12|0x03d2
//------------------------------------------------------------------------                //06-09-12|0x03d2
#undef TestIndex                                                                          //06-09-12|0x03d2
#define TestIndex text_prepare_1+1                                                        //06-09-12|0x03d2
//************************************************************************                //06-09-12|0x03d2
#ifndef TestIndex                                                                         //09-03-27|0x03ef
#define TestIndex 0                                                                       //09-03-27|0x03ef
#endif                                                                                    //09-03-27|0x03ef
//------------------------------------------------------------------------                //09-03-27|0x03ef
enum {  update_task_no_1 = TestIndex };                                                   //09-03-27|0x03ef
//------------------------------------------------------------------------                //09-03-27|0x03ef
#undef TestIndex                                                                          //09-03-27|0x03ef
#define TestIndex update_task_no_1+1                                                      //09-03-27|0x03ef
//************************************************************************                //09-03-27|0x03ef
#ifndef TestIndex                                                                         //06-09-13|0x040d
#define TestIndex 0                                                                       //06-09-13|0x040d
#endif                                                                                    //06-09-13|0x040d
//------------------------------------------------------------------------                //06-09-13|0x040d
enum {  open_library_1 = TestIndex };                                                     //06-09-13|0x040d
//------------------------------------------------------------------------                //06-09-13|0x040d
#undef TestIndex                                                                          //06-09-13|0x040d
#define TestIndex open_library_1+1                                                        //06-09-13|0x040d
//************************************************************************                //06-09-13|0x040d
#ifndef TestIndex                                                                         //06-09-13|0x0423
#define TestIndex 0                                                                       //06-09-13|0x0423
#endif                                                                                    //06-09-13|0x0423
//------------------------------------------------------------------------                //06-09-13|0x0423
enum {  load_srce_extent_1 = TestIndex };                                                 //06-09-13|0x0423
//------------------------------------------------------------------------                //06-09-13|0x0423
#undef TestIndex                                                                          //06-09-13|0x0423
#define TestIndex load_srce_extent_1+1                                                    //06-09-13|0x0423
//************************************************************************                //06-09-13|0x0423
#ifndef TestIndex                                                                         //07-03-23|0x043d
#define TestIndex 0                                                                       //07-03-23|0x043d
#endif                                                                                    //07-03-23|0x043d
//------------------------------------------------------------------------                //07-03-23|0x043d
enum {  load_out_path_ext_1 = TestIndex };                                                //07-03-23|0x043d
//------------------------------------------------------------------------                //07-03-23|0x043d
#undef TestIndex                                                                          //07-03-23|0x043d
#define TestIndex load_out_path_ext_1+1                                                   //07-03-23|0x043d
//************************************************************************                //07-03-23|0x043d
#ifndef TestIndex                                                                         //09-03-10|0x0460
#define TestIndex 0                                                                       //09-03-10|0x0460
#endif                                                                                    //09-03-10|0x0460
//------------------------------------------------------------------------                //09-03-10|0x0460
enum {  load_mailbox_1 = TestIndex };                                                     //09-03-10|0x0460
//------------------------------------------------------------------------                //09-03-10|0x0460
#undef TestIndex                                                                          //09-03-10|0x0460
#define TestIndex load_mailbox_1+1                                                        //09-03-10|0x0460
//************************************************************************                //09-03-10|0x0460
#ifndef TestIndex                                                                         //09-03-10|0x04ab
#define TestIndex 0                                                                       //09-03-10|0x04ab
#endif                                                                                    //09-03-10|0x04ab
//------------------------------------------------------------------------                //09-03-10|0x04ab
enum {  mailbox_dates_1 = TestIndex };                                                    //09-03-10|0x04ab
//------------------------------------------------------------------------                //09-03-10|0x04ab
#undef TestIndex                                                                          //09-03-10|0x04ab
#define TestIndex mailbox_dates_1+1                                                       //09-03-10|0x04ab
//************************************************************************                //09-03-10|0x04ab
#ifndef TestIndex                                                                         //09-03-10|0x04ac
#define TestIndex 0                                                                       //09-03-10|0x04ac
#endif                                                                                    //09-03-10|0x04ac
//------------------------------------------------------------------------                //09-03-10|0x04ac
enum {  mailbox_dates_3 = TestIndex };                                                    //09-03-10|0x04ac
//------------------------------------------------------------------------                //09-03-10|0x04ac
#undef TestIndex                                                                          //09-03-10|0x04ac
#define TestIndex mailbox_dates_3+1                                                       //09-03-10|0x04ac
//************************************************************************                //09-03-10|0x04ac
#ifndef TestIndex                                                                         //09-03-10|0x04ad
#define TestIndex 0                                                                       //09-03-10|0x04ad
#endif                                                                                    //09-03-10|0x04ad
//------------------------------------------------------------------------                //09-03-10|0x04ad
enum {  mailbox_dates_4 = TestIndex };                                                    //09-03-10|0x04ad
//------------------------------------------------------------------------                //09-03-10|0x04ad
#undef TestIndex                                                                          //09-03-10|0x04ad
#define TestIndex mailbox_dates_4+1                                                       //09-03-10|0x04ad
//************************************************************************                //09-03-10|0x04ad
#ifndef TestIndex                                                                         //09-03-10|0x04ae
#define TestIndex 0                                                                       //09-03-10|0x04ae
#endif                                                                                    //09-03-10|0x04ae
//------------------------------------------------------------------------                //09-03-10|0x04ae
enum {  mailbox_dates_5 = TestIndex };                                                    //09-03-10|0x04ae
//------------------------------------------------------------------------                //09-03-10|0x04ae
#undef TestIndex                                                                          //09-03-10|0x04ae
#define TestIndex mailbox_dates_5+1                                                       //09-03-10|0x04ae
//************************************************************************                //09-03-10|0x04ae
#ifndef TestIndex                                                                         //09-03-10|0x04af
#define TestIndex 0                                                                       //09-03-10|0x04af
#endif                                                                                    //09-03-10|0x04af
//------------------------------------------------------------------------                //09-03-10|0x04af
enum {  mailbox_dates_6 = TestIndex };                                                    //09-03-10|0x04af
//------------------------------------------------------------------------                //09-03-10|0x04af
#undef TestIndex                                                                          //09-03-10|0x04af
#define TestIndex mailbox_dates_6+1                                                       //09-03-10|0x04af
//************************************************************************                //09-03-10|0x04af
#ifndef TestIndex                                                                         //07-06-06|0x050f
#define TestIndex 0                                                                       //07-06-06|0x050f
#endif                                                                                    //07-06-06|0x050f
//------------------------------------------------------------------------                //07-06-06|0x050f
enum {  error_control_1 = TestIndex };                                                    //07-06-06|0x050f
//------------------------------------------------------------------------                //07-06-06|0x050f
#undef TestIndex                                                                          //07-06-06|0x050f
#define TestIndex error_control_1+1                                                       //07-06-06|0x050f
//************************************************************************                //07-06-06|0x050f
#ifndef TestIndex                                                                         //07-06-06|0x0510
#define TestIndex 0                                                                       //07-06-06|0x0510
#endif                                                                                    //07-06-06|0x0510
//------------------------------------------------------------------------                //07-06-06|0x0510
enum {  error_control_2 = TestIndex };                                                    //07-06-06|0x0510
//------------------------------------------------------------------------                //07-06-06|0x0510
#undef TestIndex                                                                          //07-06-06|0x0510
#define TestIndex error_control_2+1                                                       //07-06-06|0x0510
//************************************************************************                //07-06-06|0x0510
#ifndef TestIndex                                                                         //10-05-15|0x0527
#define TestIndex 0                                                                       //10-05-15|0x0527
#endif                                                                                    //10-05-15|0x0527
//------------------------------------------------------------------------                //10-05-15|0x0527
enum {  load_in_path_ext_1 = TestIndex };                                                 //10-05-15|0x0527
//------------------------------------------------------------------------                //10-05-15|0x0527
#undef TestIndex                                                                          //10-05-15|0x0527
#define TestIndex load_in_path_ext_1+1                                                    //10-05-15|0x0527
//************************************************************************                //10-05-15|0x0527
#ifndef TestIndex                                                                         //06-09-13|0x054a
#define TestIndex 0                                                                       //06-09-13|0x054a
#endif                                                                                    //06-09-13|0x054a
//------------------------------------------------------------------------                //06-09-13|0x054a
enum {  uncond_update_1 = TestIndex };                                                    //06-09-13|0x054a
//------------------------------------------------------------------------                //06-09-13|0x054a
#undef TestIndex                                                                          //06-09-13|0x054a
#define TestIndex uncond_update_1+1                                                       //06-09-13|0x054a
//************************************************************************                //06-09-13|0x054a
#ifndef TestIndex                                                                         //06-09-25|0x0561
#define TestIndex 0                                                                       //06-09-25|0x0561
#endif                                                                                    //06-09-25|0x0561
//------------------------------------------------------------------------                //06-09-25|0x0561
enum {  output_names_1 = TestIndex };                                                     //06-09-25|0x0561
//------------------------------------------------------------------------                //06-09-25|0x0561
#undef TestIndex                                                                          //06-09-25|0x0561
#define TestIndex output_names_1+1                                                        //06-09-25|0x0561
//************************************************************************                //06-09-25|0x0561
#ifndef TestIndex                                                                         //07-01-30|0x0580
#define TestIndex 0                                                                       //07-01-30|0x0580
#endif                                                                                    //07-01-30|0x0580
//------------------------------------------------------------------------                //07-01-30|0x0580
enum {  output_dates_1 = TestIndex };                                                     //07-01-30|0x0580
//------------------------------------------------------------------------                //07-01-30|0x0580
#undef TestIndex                                                                          //07-01-30|0x0580
#define TestIndex output_dates_1+1                                                        //07-01-30|0x0580
//************************************************************************                //07-01-30|0x0580
#ifndef TestIndex                                                                         //07-01-30|0x0581
#define TestIndex 0                                                                       //07-01-30|0x0581
#endif                                                                                    //07-01-30|0x0581
//------------------------------------------------------------------------                //07-01-30|0x0581
enum {  output_dates_2 = TestIndex };                                                     //07-01-30|0x0581
//------------------------------------------------------------------------                //07-01-30|0x0581
#undef TestIndex                                                                          //07-01-30|0x0581
#define TestIndex output_dates_2+1                                                        //07-01-30|0x0581
//************************************************************************                //07-01-30|0x0581
#ifndef TestIndex                                                                         //06-09-26|0x05a0
#define TestIndex 0                                                                       //06-09-26|0x05a0
#endif                                                                                    //06-09-26|0x05a0
//------------------------------------------------------------------------                //06-09-26|0x05a0
enum {  push_call_1 = TestIndex };                                                        //06-09-26|0x05a0
//------------------------------------------------------------------------                //06-09-26|0x05a0
#undef TestIndex                                                                          //06-09-26|0x05a0
#define TestIndex push_call_1+1                                                           //06-09-26|0x05a0
//************************************************************************                //06-09-26|0x05a0
#ifndef TestIndex                                                                         //06-09-30|0x05c5
#define TestIndex 0                                                                       //06-09-30|0x05c5
#endif                                                                                    //06-09-30|0x05c5
//------------------------------------------------------------------------                //06-09-30|0x05c5
enum {  pop_call_1 = TestIndex };                                                         //06-09-30|0x05c5
//------------------------------------------------------------------------                //06-09-30|0x05c5
#undef TestIndex                                                                          //06-09-30|0x05c5
#define TestIndex pop_call_1+1                                                            //06-09-30|0x05c5
//************************************************************************                //06-09-30|0x05c5
#ifndef TestIndex                                                                         //06-09-30|0x05c6
#define TestIndex 0                                                                       //06-09-30|0x05c6
#endif                                                                                    //06-09-30|0x05c6
//------------------------------------------------------------------------                //06-09-30|0x05c6
enum {  pop_call_2 = TestIndex };                                                         //06-09-30|0x05c6
//------------------------------------------------------------------------                //06-09-30|0x05c6
#undef TestIndex                                                                          //06-09-30|0x05c6
#define TestIndex pop_call_2+1                                                            //06-09-30|0x05c6
//************************************************************************                //06-09-30|0x05c6
#ifndef TestIndex                                                                         //06-09-30|0x05c7
#define TestIndex 0                                                                       //06-09-30|0x05c7
#endif                                                                                    //06-09-30|0x05c7
//------------------------------------------------------------------------                //06-09-30|0x05c7
enum {  pop_call_3 = TestIndex };                                                         //06-09-30|0x05c7
//------------------------------------------------------------------------                //06-09-30|0x05c7
#undef TestIndex                                                                          //06-09-30|0x05c7
#define TestIndex pop_call_3+1                                                            //06-09-30|0x05c7
//************************************************************************                //06-09-30|0x05c7
#ifndef TestIndex                                                                         //06-09-12|0x05ec
#define TestIndex 0                                                                       //06-09-12|0x05ec
#endif                                                                                    //06-09-12|0x05ec
//------------------------------------------------------------------------                //06-09-12|0x05ec
enum {  close_project_1 = TestIndex };                                                    //06-09-12|0x05ec
//------------------------------------------------------------------------                //06-09-12|0x05ec
#undef TestIndex                                                                          //06-09-12|0x05ec
#define TestIndex close_project_1+1                                                       //06-09-12|0x05ec
//************************************************************************                //06-09-12|0x05ec
#ifndef TestIndex                                                                         //08-04-18|0x0623
#define TestIndex 0                                                                       //08-04-18|0x0623
#endif                                                                                    //08-04-18|0x0623
//------------------------------------------------------------------------                //08-04-18|0x0623
enum {  close_output_1 = TestIndex };                                                     //08-04-18|0x0623
//------------------------------------------------------------------------                //08-04-18|0x0623
#undef TestIndex                                                                          //08-04-18|0x0623
#define TestIndex close_output_1+1                                                        //08-04-18|0x0623
//************************************************************************                //08-04-18|0x0623
#ifndef TestIndex                                                                         //08-04-18|0x0624
#define TestIndex 0                                                                       //08-04-18|0x0624
#endif                                                                                    //08-04-18|0x0624
//------------------------------------------------------------------------                //08-04-18|0x0624
enum {  close_output_2 = TestIndex };                                                     //08-04-18|0x0624
//------------------------------------------------------------------------                //08-04-18|0x0624
#undef TestIndex                                                                          //08-04-18|0x0624
#define TestIndex close_output_2+1                                                        //08-04-18|0x0624
//************************************************************************                //08-04-18|0x0624
#ifndef TestIndex                                                                         //08-04-18|0x0625
#define TestIndex 0                                                                       //08-04-18|0x0625
#endif                                                                                    //08-04-18|0x0625
//------------------------------------------------------------------------                //08-04-18|0x0625
enum {  close_output_3 = TestIndex };                                                     //08-04-18|0x0625
//------------------------------------------------------------------------                //08-04-18|0x0625
#undef TestIndex                                                                          //08-04-18|0x0625
#define TestIndex close_output_3+1                                                        //08-04-18|0x0625
//************************************************************************                //08-04-18|0x0625
#ifndef TestIndex                                                                         //10-05-15|0x0648
#define TestIndex 0                                                                       //10-05-15|0x0648
#endif                                                                                    //10-05-15|0x0648
//------------------------------------------------------------------------                //10-05-15|0x0648
enum {  close_text_1 = TestIndex };                                                       //10-05-15|0x0648
//------------------------------------------------------------------------                //10-05-15|0x0648
#undef TestIndex                                                                          //10-05-15|0x0648
#define TestIndex close_text_1+1                                                          //10-05-15|0x0648
//************************************************************************                //10-05-15|0x0648
#ifndef TestIndex                                                                         //10-01-03|0x0664
#define TestIndex 0                                                                       //10-01-03|0x0664
#endif                                                                                    //10-01-03|0x0664
//------------------------------------------------------------------------                //10-01-03|0x0664
enum {  mailbox_finish_1 = TestIndex };                                                   //10-01-03|0x0664
//------------------------------------------------------------------------                //10-01-03|0x0664
#undef TestIndex                                                                          //10-01-03|0x0664
#define TestIndex mailbox_finish_1+1                                                      //10-01-03|0x0664
//************************************************************************                //10-01-03|0x0664
#ifndef TestIndex                                                                         //10-01-03|0x0665
#define TestIndex 0                                                                       //10-01-03|0x0665
#endif                                                                                    //10-01-03|0x0665
//------------------------------------------------------------------------                //10-01-03|0x0665
enum {  mailbox_finish_2 = TestIndex };                                                   //10-01-03|0x0665
//------------------------------------------------------------------------                //10-01-03|0x0665
#undef TestIndex                                                                          //10-01-03|0x0665
#define TestIndex mailbox_finish_2+1                                                      //10-01-03|0x0665
//************************************************************************                //10-01-03|0x0665
#ifndef TestIndex                                                                         //10-01-03|0x0666
#define TestIndex 0                                                                       //10-01-03|0x0666
#endif                                                                                    //10-01-03|0x0666
//------------------------------------------------------------------------                //10-01-03|0x0666
enum {  mailbox_finish_3 = TestIndex };                                                   //10-01-03|0x0666
//------------------------------------------------------------------------                //10-01-03|0x0666
#undef TestIndex                                                                          //10-01-03|0x0666
#define TestIndex mailbox_finish_3+1                                                      //10-01-03|0x0666
//************************************************************************                //10-01-03|0x0666
#ifndef TestIndex                                                                         //10-01-03|0x0667
#define TestIndex 0                                                                       //10-01-03|0x0667
#endif                                                                                    //10-01-03|0x0667
//------------------------------------------------------------------------                //10-01-03|0x0667
enum {  mailbox_finish_4 = TestIndex };                                                   //10-01-03|0x0667
//------------------------------------------------------------------------                //10-01-03|0x0667
#undef TestIndex                                                                          //10-01-03|0x0667
#define TestIndex mailbox_finish_4+1                                                      //10-01-03|0x0667
//************************************************************************                //10-01-03|0x0667
#ifndef TestIndex                                                                         //10-01-03|0x0668
#define TestIndex 0                                                                       //10-01-03|0x0668
#endif                                                                                    //10-01-03|0x0668
//------------------------------------------------------------------------                //10-01-03|0x0668
enum {  mailbox_finish_5 = TestIndex };                                                   //10-01-03|0x0668
//------------------------------------------------------------------------                //10-01-03|0x0668
#undef TestIndex                                                                          //10-01-03|0x0668
#define TestIndex mailbox_finish_5+1                                                      //10-01-03|0x0668
//************************************************************************                //10-01-03|0x0668
#ifndef TestIndex                                                                         //10-01-03|0x0669
#define TestIndex 0                                                                       //10-01-03|0x0669
#endif                                                                                    //10-01-03|0x0669
//------------------------------------------------------------------------                //10-01-03|0x0669
enum {  mailbox_finish_6 = TestIndex };                                                   //10-01-03|0x0669
//------------------------------------------------------------------------                //10-01-03|0x0669
#undef TestIndex                                                                          //10-01-03|0x0669
#define TestIndex mailbox_finish_6+1                                                      //10-01-03|0x0669
//************************************************************************                //10-01-03|0x0669
#ifndef TestIndex                                                                         //10-01-03|0x066a
#define TestIndex 0                                                                       //10-01-03|0x066a
#endif                                                                                    //10-01-03|0x066a
//------------------------------------------------------------------------                //10-01-03|0x066a
enum {  mailbox_finish_7 = TestIndex };                                                   //10-01-03|0x066a
//------------------------------------------------------------------------                //10-01-03|0x066a
#undef TestIndex                                                                          //10-01-03|0x066a
#define TestIndex mailbox_finish_7+1                                                      //10-01-03|0x066a
//************************************************************************                //10-01-03|0x066a
#ifndef TestIndex                                                                         //10-01-03|0x066b
#define TestIndex 0                                                                       //10-01-03|0x066b
#endif                                                                                    //10-01-03|0x066b
//------------------------------------------------------------------------                //10-01-03|0x066b
enum {  mailbox_finish_8 = TestIndex };                                                   //10-01-03|0x066b
//------------------------------------------------------------------------                //10-01-03|0x066b
#undef TestIndex                                                                          //10-01-03|0x066b
#define TestIndex mailbox_finish_8+1                                                      //10-01-03|0x066b
//************************************************************************                //10-01-03|0x066b
#ifndef TestIndex                                                                         //10-01-03|0x06be
#define TestIndex 0                                                                       //10-01-03|0x06be
#endif                                                                                    //10-01-03|0x06be
//------------------------------------------------------------------------                //10-01-03|0x06be
enum {  mailbox_complete_1 = TestIndex };                                                 //10-01-03|0x06be
//------------------------------------------------------------------------                //10-01-03|0x06be
#undef TestIndex                                                                          //10-01-03|0x06be
#define TestIndex mailbox_complete_1+1                                                    //10-01-03|0x06be
//************************************************************************                //10-01-03|0x06be
#ifndef TestIndex                                                                         //10-01-03|0x06bf
#define TestIndex 0                                                                       //10-01-03|0x06bf
#endif                                                                                    //10-01-03|0x06bf
//------------------------------------------------------------------------                //10-01-03|0x06bf
enum {  mailbox_complete_2 = TestIndex };                                                 //10-01-03|0x06bf
//------------------------------------------------------------------------                //10-01-03|0x06bf
#undef TestIndex                                                                          //10-01-03|0x06bf
#define TestIndex mailbox_complete_2+1                                                    //10-01-03|0x06bf
//************************************************************************                //10-01-03|0x06bf
#ifndef TestIndex                                                                         //10-01-03|0x06c0
#define TestIndex 0                                                                       //10-01-03|0x06c0
#endif                                                                                    //10-01-03|0x06c0
//------------------------------------------------------------------------                //10-01-03|0x06c0
enum {  mailbox_complete_3 = TestIndex };                                                 //10-01-03|0x06c0
//------------------------------------------------------------------------                //10-01-03|0x06c0
#undef TestIndex                                                                          //10-01-03|0x06c0
#define TestIndex mailbox_complete_3+1                                                    //10-01-03|0x06c0
//************************************************************************                //10-01-03|0x06c0
#ifndef TestIndex                                                                         //10-01-03|0x06c1
#define TestIndex 0                                                                       //10-01-03|0x06c1
#endif                                                                                    //10-01-03|0x06c1
//------------------------------------------------------------------------                //10-01-03|0x06c1
enum {  mailbox_complete_4 = TestIndex };                                                 //10-01-03|0x06c1
//------------------------------------------------------------------------                //10-01-03|0x06c1
#undef TestIndex                                                                          //10-01-03|0x06c1
#define TestIndex mailbox_complete_4+1                                                    //10-01-03|0x06c1
//************************************************************************                //10-01-03|0x06c1
#ifndef TestIndex                                                                         //10-01-03|0x06c2
#define TestIndex 0                                                                       //10-01-03|0x06c2
#endif                                                                                    //10-01-03|0x06c2
//------------------------------------------------------------------------                //10-01-03|0x06c2
enum {  mailbox_complete_5 = TestIndex };                                                 //10-01-03|0x06c2
//------------------------------------------------------------------------                //10-01-03|0x06c2
#undef TestIndex                                                                          //10-01-03|0x06c2
#define TestIndex mailbox_complete_5+1                                                    //10-01-03|0x06c2
//************************************************************************                //10-01-03|0x06c2
#ifndef TestIndex                                                                         //10-01-03|0x06c3
#define TestIndex 0                                                                       //10-01-03|0x06c3
#endif                                                                                    //10-01-03|0x06c3
//------------------------------------------------------------------------                //10-01-03|0x06c3
enum {  mailbox_complete_6 = TestIndex };                                                 //10-01-03|0x06c3
//------------------------------------------------------------------------                //10-01-03|0x06c3
#undef TestIndex                                                                          //10-01-03|0x06c3
#define TestIndex mailbox_complete_6+1                                                    //10-01-03|0x06c3
//************************************************************************                //10-01-03|0x06c3
//*******************************************************************************         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
//****                       END OF FILE                                     ****         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
//*******************************************************************************         //05-24-97|0x072c
#endif                                                                                    //05-24-97|0x072c
