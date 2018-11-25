//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
// DEVELOPMENT PROJECT ENGINE                                                             //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x0011
//  defined in the associated manual.                                                     //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x0011
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x0011
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x0011
//  (at your option) any later version.                                                   //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x0011
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x0011
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x0011
//  GNU General Public License for more details.                                          //06-07-12|0x0011
//                                                                                        //06-07-12|0x0011
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x0011
//  along with this program; if not, write to the Free Software                           //06-07-12|0x0011
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x0011
//  USA                                                                                   //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//  For further information, please contact Robert Adams:                                 //06-07-12|0x0011
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x0011
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x0011
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
//*****************************************************************************           //06-07-12|0x0011
#ifndef devproj_hpp                                                                       //06-07-12|0x0012
#define devproj_hpp                                                                       //06-07-12|0x0012
//***************************************************************************             //06-07-12|0x001c
//***************************************************************************             //06-07-12|0x001d
//******                                                               ******             //06-07-12|0x001e
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x001f
//******                                                               ******             //06-07-12|0x0020
//***************************************************************************             //06-07-12|0x0021
//***************************************************************************             //06-07-12|0x0022
//***************************************************************************             //06-07-12|0x0025
//***************************************************************************             //06-07-12|0x0026
//******                                                               ******             //06-07-12|0x0027
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x0028
//******                                                               ******             //06-07-12|0x0029
//***************************************************************************             //06-07-12|0x002a
//***************************************************************************             //06-07-12|0x002b
#define UserError 0x0000                                                                  //06-07-12|0x002c
#define BuildError 0x7fff                                                                 //06-07-12|0x002c
#define Display 0x7ffe                                                                    //06-07-12|0x002c
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x002c
#define Success 0xffff                                                                    //06-07-12|0x002c
#define SystemError 0x8000                                                                //06-07-12|0x002c
#define Continue 0x0001                                                                   //06-07-12|0x002c
#define FileDone 0x0002                                                                   //06-07-12|0x002c
#define LineDone 0x0003                                                                   //06-07-12|0x002c
#define Yes 0x0004                                                                        //06-07-12|0x002c
#define No 0x0005                                                                         //06-07-12|0x002c
#define RepeatChar '\x6'                                                                  //06-07-12|0x002c
#define Great 0x0007                                                                      //06-07-12|0x002c
#define Equal 0x0008                                                                      //06-07-12|0x002c
#define Less 0x0009                                                                       //06-07-12|0x002c
#define Zero 0x000a                                                                       //06-07-12|0x002c
#define Minus 0x000b                                                                      //06-07-12|0x002c
//***************************************************************************             //06-07-12|0x002d
#define SystemMsg PcgSystemError("devproj", __LINE__);                                    //06-07-12|0x002e
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x002e
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x002e
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x002f
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x002f
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x002f
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x002f
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0030
#define _SwitchOk case Success: break                                                     //06-07-12|0x0030
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0030
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0030
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0030
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0030
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0030
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0030
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0030
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0030
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0030
//***************************************************************************             //06-07-12|0x0051
//***************************************************************************             //06-07-12|0x0052
//******                                                               ******             //06-07-12|0x0053
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0054
//******                                                               ******             //06-07-12|0x0055
//***************************************************************************             //06-07-12|0x0056
//***************************************************************************             //06-07-12|0x0057
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x0058
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x0058
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x0058
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x0058
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-12|0x0058
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-12|0x0058
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x0058
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x0058
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x0058
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x0058
//************************************************************************                //06-07-12|0x0058
#ifndef TestIndex                                                                         //06-07-12|0x0058
#define TestIndex 0                                                                       //06-07-12|0x0058
#endif                                                                                    //06-07-12|0x0058
//------------------------------------------------------------------------                //06-07-12|0x0058
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x0058
//------------------------------------------------------------------------                //06-07-12|0x0058
#undef TestIndex                                                                          //06-07-12|0x0058
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x0058
//************************************************************************                //06-07-12|0x0058
//***************************************************************************             //06-07-12|0x0059
//**********************************************************************                  //06-07-12|0x005a
#define DevelopState develop_project_addr->state                                          //06-07-12|0x005a
#define DevelopStatus develop_project_addr->status                                        //06-07-12|0x005a
#define DevelopRunFlag develop_project_addr->run_flag                                     //06-07-12|0x005a
#define DevelopSingleStepFlag develop_project_addr->single_step_flag                      //06-07-12|0x005a
#define DevelopDrives develop_project_addr->drives                                        //06-07-12|0x005a
#define DevelopDevPrjNo develop_project_addr->devprj_no                                   //06-07-12|0x005a
#define DevelopTokens develop_project_addr->tokens                                        //06-07-12|0x005a
#define DevelopMake develop_project_addr->make                                            //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopBasicFileName file_control.name[0]                                         //06-07-12|0x005a
#define DevelopProjectFileName project_file.DevelopBasicFileName                          //06-07-12|0x005a
#define DevelopPastFileName(i) &(develop_project_addr->stack[i].DevelopProjectFileName)   //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopStack develop_project_addr->stack[develop_project_addr->devprj_no]         //06-07-12|0x005a
#define DevelopPreStack develop_project_addr->stack[develop_project_addr->devprj_no - 1]  //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopProjectFile DevelopStack.project_file                                      //06-07-12|0x005a
#define DevelopDisplayState DevelopStack.display_state                                    //06-07-12|0x005a
#define DevelopTaskNo DevelopStack.task_no                                                //06-07-12|0x005a
#define DevelopMainTime DevelopStack.main_time                                            //06-07-12|0x005a
#define DevelopUpdateTime DevelopStack.update_time                                        //06-07-12|0x005a
#define DevelopProjectTime DevelopStack.project_time                                      //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopPreUpdateTime DevelopPreStack.update_time                                  //06-07-12|0x005a
#define DevelopPreTaskNo DevelopPreStack.task_no                                          //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopTaskNoAddr &(DevelopStack.task_no)                                         //06-07-12|0x005a
#define DevelopProjectFileAddr &(DevelopStack.project_file)                               //06-07-12|0x005a
#define DevelopProjectTimeAddr &(DevelopStack.project_time)                               //06-07-12|0x005a
#define DevelopFileName &(DevelopStack.DevelopProjectFileName)                            //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopPreTaskNoAddr &(DevelopPreStack.task_no)                                   //06-07-12|0x005a
//----------------------------------------------------------------------                  //06-07-12|0x005a
#define DevelopTokensAddr &(develop_project_addr->tokens)                                 //06-07-12|0x005a
#define DevelopDrivesAddr &(develop_project_addr->drives)                                 //06-07-12|0x005a
#define DevelopMakeAddr &(develop_project_addr->make)                                     //06-07-12|0x005a
//************************************************************************                //06-11-14|0x005b
#define DrivePathTokenAddr(i) &(DevelopDrives.token[i])                                   //06-11-14|0x005b
#define DrivePathMacroLineNo(i) DevelopDrives.token[i].macro_line_no                      //06-11-14|0x005b
#define DrivePathLineAddr(i) &(DevelopDrives.token[i].line[0])                            //06-11-14|0x005b
#define DrivePathToken(i) DevelopDrives.token[i]                                          //06-11-14|0x005b
#define DrivePathLine(i) DevelopDrives.token[i].line                                      //06-11-14|0x005b
#define DrivePathLength(i) DevelopDrives.token[i].length                                  //06-11-14|0x005b
#define DrivePathColumn(i) DevelopDrives.token[i].column                                  //06-11-14|0x005b
#define DrivePathHash(i) DevelopDrives.token[i].hash                                      //06-11-14|0x005b
#define DrivePathPosition(i) DevelopDrives.token[i].position                              //06-11-14|0x005b
#define DrivePathType(i) DevelopDrives.token[i].type                                      //06-11-14|0x005b
#define DrivePathStartCol(i) DevelopDrives.token[i].start_col                             //06-11-14|0x005b
#define DrivePathStartCall(i) DevelopDrives.token[i].start_call                           //06-11-14|0x005b
#define DrivePathChar(i,j) DevelopDrives.token[i].line[j]                                 //06-11-14|0x005b
#define DrivePathNoTokens DevelopDrives.no_tokens                                         //06-11-14|0x005b
//************************************************************************                //06-07-12|0x005c
#define TokensTokenAddr(i) &(DevelopTokens.token[i])                                      //06-07-12|0x005c
#define TokensMacroLineNo(i) DevelopTokens.token[i].macro_line_no                         //06-07-12|0x005c
#define TokensLineAddr(i) &(DevelopTokens.token[i].line[0])                               //06-07-12|0x005c
#define TokensToken(i) DevelopTokens.token[i]                                             //06-07-12|0x005c
#define TokensLine(i) DevelopTokens.token[i].line                                         //06-07-12|0x005c
#define TokensLength(i) DevelopTokens.token[i].length                                     //06-07-12|0x005c
#define TokensColumn(i) DevelopTokens.token[i].column                                     //06-07-12|0x005c
#define TokensHash(i) DevelopTokens.token[i].hash                                         //06-07-12|0x005c
#define TokensPosition(i) DevelopTokens.token[i].position                                 //06-07-12|0x005c
#define TokensType(i) DevelopTokens.token[i].type                                         //06-07-12|0x005c
#define TokensStartCol(i) DevelopTokens.token[i].start_col                                //06-07-12|0x005c
#define TokensStartCall(i) DevelopTokens.token[i].start_call                              //06-07-12|0x005c
#define TokensChar(i,j) DevelopTokens.token[i].line[j]                                    //06-07-12|0x005c
#define TokensNoTokens DevelopTokens.no_tokens                                            //06-07-12|0x005c
#define MakeNameChar(i) DevelopMake.name[i]                                               //08-12-27|0x005d
#define MakeNameAddr &(DevelopMake.name[0])                                               //08-12-27|0x005d
#define MakeParmsChar(i) DevelopMake.parms[i]                                             //08-12-27|0x005d
#define MakeParmsAddr &(DevelopMake.parms[0])                                             //08-12-27|0x005d
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
#define ProjectDoesNotExist Finish("Project File Does Not Exist")                         //06-07-12|0x0061
#define IllegalCommand Finish("Illegal Command")                                          //06-07-12|0x0061
#define IllegalEndOfFile Finish("Illegal End Of File")                                    //06-07-12|0x0061
#define InitialDevPrjNo DevelopDevPrjNo = 0;                                              //06-07-12|0x0061
#define InitialTaskNo DevelopTaskNo = *TaskNoFar;                                         //06-07-12|0x0061
#define InitialUpdateTime DevelopUpdateTime = MainProjTime;                               //06-07-12|0x0061
#define InitialFileName2(i,j) MemCpy(DevelopDrivesAddr,i,j)                               //06-07-12|0x0061
#define InitialFileName1(j) InitialFileName2(InputTokensFar,j)                            //06-07-12|0x0061
#define InitialFileName InitialFileName1(sizeof(TOKENS))                                  //06-07-12|0x0061
#define IncrDevPrjNo increment_project_no()                                               //06-07-12|0x0061
#define EnterProjectName enter_project_name()                                             //06-07-12|0x0061
#define ProjectExists project_exists()                                                    //06-07-12|0x0061
#define CmdTest(i) StrCmp(TokensLineAddr(0),i)                                            //06-07-12|0x0061
#define DebugPause debug_pause()                                                          //06-07-12|0x0061
#define UpdateTaskNo update_task_no()                                                     //06-07-12|0x0061
#define DevelopLib2(i,j) MacProjProcess(DevelopDrivesAddr, i,j)                           //06-07-12|0x0061
#define DevelopLib1(i) DevelopLib2(DevelopPreUpdateTime, i)                               //06-07-12|0x0061
#define DevelopLib DevelopLib1(DevelopPreTaskNoAddr)                                      //06-07-12|0x0061
#define DecrDevPrjNo decrement_project_no()                                               //06-07-12|0x0061
#define SourceArgs source_args(InputTokensFar)                                            //06-07-12|0x0061
#define DevelopSrce3(i,j,k) SrcProjProcess(DevelopTokensAddr, i, j, k)                    //06-07-12|0x0061
#define DevelopSrce2(i,j) DevelopSrce3(DevelopUpdateTime, i, j)                           //06-07-12|0x0061
#define DevelopSrce1(i) DevelopSrce2(InputTokensFar, i)                                   //06-07-12|0x0061
#define DevelopSrce DevelopSrce1(DevelopPreTaskNoAddr)                                    //06-07-12|0x0061
#define ReturnTaskNo *TaskNoFar = DevelopPreTaskNo;                                       //06-07-12|0x0061
#define IfNoTokens1(i) (TokensNoTokens < i)                                               //06-07-12|0x0061
#define IfNoTokens2(i) (TokensNoTokens > i)                                               //06-07-12|0x0061
#define IfNoTokens(i,j) if(IfNoTokens1(i) || IfNoTokens2(j))                              //06-07-12|0x0061
#define ConfigurePath2(i,j) FileExpandName(DevelopDrivesAddr, i,1,j)                      //06-07-12|0x0061
#define ConfigurePath1(i) ConfigurePath2(InputTokensFar,i)                                //06-07-12|0x0061
#define ConfigurePath ConfigurePath1(DrivePathNoTokens)                                   //06-07-12|0x0061
#define InitialProjFile FileInitialText(DevelopProjectFileAddr)                           //06-07-12|0x0061
#define EnterProjFileName FileEnterName(DrivePathLineAddr(0), PMK_EXTENT)                 //06-07-12|0x0061
#define CommitProjFile FileCommitText(DevelopProjectFileAddr)                             //06-07-12|0x0061
#define CMK_EXTENT ".cmk"                                                                 //06-07-12|0x0063
#define TMK_EXTENT ".tmk"                                                                 //06-07-12|0x0063
#define RPT_EXTENT ".rpt"                                                                 //06-07-12|0x0063
#define PMK_EXTENT ".pmk"                                                                 //06-07-12|0x0063
#define MAC_EXTENT ".mac"                                                                 //06-07-12|0x0063
#define SRC_EXTENT ".src"                                                                 //06-07-12|0x0063
#define PLB_EXTENT ".plb"                                                                 //06-07-12|0x0063
#define DIC_EXTENT ".dic"                                                                 //06-07-12|0x0063
#define MBX_EXTENT ".mbx"                                                                 //06-07-12|0x0063
#define MBC_EXTENT ".mbc"                                                                 //06-07-12|0x0063
#define RAN_EXTENT ".ran"                                                                 //06-07-12|0x0063
#define BUF_OUT_EXTENT ".bfo"                                                             //06-07-12|0x0063
#define BUF_IN_EXTENT ".bfi"                                                              //06-07-12|0x0063
#define FileTextPrepare TextPrepare(DrivePathTokenAddr(0),TokensTokenAddr(1))             //06-07-23|0x0064
#ifndef TestIndex                                                                         //06-07-12|0x0070
#define TestIndex 0                                                                       //06-07-12|0x0070
#endif                                                                                    //06-07-12|0x0070
//------------------------------------------------------------------------                //06-07-12|0x0070
enum {  devproj_allocate_1 = TestIndex };                                                 //06-07-12|0x0070
//------------------------------------------------------------------------                //06-07-12|0x0070
#undef TestIndex                                                                          //06-07-12|0x0070
#define TestIndex devproj_allocate_1+1                                                    //06-07-12|0x0070
//************************************************************************                //06-07-12|0x0070
#ifndef TestIndex                                                                         //06-07-12|0x008b
#define TestIndex 0                                                                       //06-07-12|0x008b
#endif                                                                                    //06-07-12|0x008b
//------------------------------------------------------------------------                //06-07-12|0x008b
enum {  devproj_free_1 = TestIndex };                                                     //06-07-12|0x008b
//------------------------------------------------------------------------                //06-07-12|0x008b
#undef TestIndex                                                                          //06-07-12|0x008b
#define TestIndex devproj_free_1+1                                                        //06-07-12|0x008b
//************************************************************************                //06-07-12|0x008b
#ifndef TestIndex                                                                         //11-12-12|0x01a6
#define TestIndex 0                                                                       //11-12-12|0x01a6
#endif                                                                                    //11-12-12|0x01a6
//------------------------------------------------------------------------                //11-12-12|0x01a6
enum {  increment_project_no_1 = TestIndex };                                             //11-12-12|0x01a6
//------------------------------------------------------------------------                //11-12-12|0x01a6
#undef TestIndex                                                                          //11-12-12|0x01a6
#define TestIndex increment_project_no_1+1                                                //11-12-12|0x01a6
//************************************************************************                //11-12-12|0x01a6
#ifndef TestIndex                                                                         //06-08-09|0x01bc
#define TestIndex 0                                                                       //06-08-09|0x01bc
#endif                                                                                    //06-08-09|0x01bc
//------------------------------------------------------------------------                //06-08-09|0x01bc
enum {  enter_project_name_1 = TestIndex };                                               //06-08-09|0x01bc
//------------------------------------------------------------------------                //06-08-09|0x01bc
#undef TestIndex                                                                          //06-08-09|0x01bc
#define TestIndex enter_project_name_1+1                                                  //06-08-09|0x01bc
//************************************************************************                //06-08-09|0x01bc
#ifndef TestIndex                                                                         //06-08-09|0x01e1
#define TestIndex 0                                                                       //06-08-09|0x01e1
#endif                                                                                    //06-08-09|0x01e1
//------------------------------------------------------------------------                //06-08-09|0x01e1
enum {  project_exists_1 = TestIndex };                                                   //06-08-09|0x01e1
//------------------------------------------------------------------------                //06-08-09|0x01e1
#undef TestIndex                                                                          //06-08-09|0x01e1
#define TestIndex project_exists_1+1                                                      //06-08-09|0x01e1
//************************************************************************                //06-08-09|0x01e1
#ifndef TestIndex                                                                         //06-08-09|0x0209
#define TestIndex 0                                                                       //06-08-09|0x0209
#endif                                                                                    //06-08-09|0x0209
//------------------------------------------------------------------------                //06-08-09|0x0209
enum {  open_project_1 = TestIndex };                                                     //06-08-09|0x0209
//------------------------------------------------------------------------                //06-08-09|0x0209
#undef TestIndex                                                                          //06-08-09|0x0209
#define TestIndex open_project_1+1                                                        //06-08-09|0x0209
//************************************************************************                //06-08-09|0x0209
#ifndef TestIndex                                                                         //06-08-09|0x0220
#define TestIndex 0                                                                       //06-08-09|0x0220
#endif                                                                                    //06-08-09|0x0220
//------------------------------------------------------------------------                //06-08-09|0x0220
enum {  read_project_1 = TestIndex };                                                     //06-08-09|0x0220
//------------------------------------------------------------------------                //06-08-09|0x0220
#undef TestIndex                                                                          //06-08-09|0x0220
#define TestIndex read_project_1+1                                                        //06-08-09|0x0220
//************************************************************************                //06-08-09|0x0220
#ifndef TestIndex                                                                         //06-08-09|0x0221
#define TestIndex 0                                                                       //06-08-09|0x0221
#endif                                                                                    //06-08-09|0x0221
//------------------------------------------------------------------------                //06-08-09|0x0221
enum {  read_project_2 = TestIndex };                                                     //06-08-09|0x0221
//------------------------------------------------------------------------                //06-08-09|0x0221
#undef TestIndex                                                                          //06-08-09|0x0221
#define TestIndex read_project_2+1                                                        //06-08-09|0x0221
//************************************************************************                //06-08-09|0x0221
#ifndef TestIndex                                                                         //06-08-09|0x0222
#define TestIndex 0                                                                       //06-08-09|0x0222
#endif                                                                                    //06-08-09|0x0222
//------------------------------------------------------------------------                //06-08-09|0x0222
enum {  read_project_3 = TestIndex };                                                     //06-08-09|0x0222
//------------------------------------------------------------------------                //06-08-09|0x0222
#undef TestIndex                                                                          //06-08-09|0x0222
#define TestIndex read_project_3+1                                                        //06-08-09|0x0222
//************************************************************************                //06-08-09|0x0222
#ifndef TestIndex                                                                         //06-08-09|0x0223
#define TestIndex 0                                                                       //06-08-09|0x0223
#endif                                                                                    //06-08-09|0x0223
//------------------------------------------------------------------------                //06-08-09|0x0223
enum {  read_project_4 = TestIndex };                                                     //06-08-09|0x0223
//------------------------------------------------------------------------                //06-08-09|0x0223
#undef TestIndex                                                                          //06-08-09|0x0223
#define TestIndex read_project_4+1                                                        //06-08-09|0x0223
//************************************************************************                //06-08-09|0x0223
#ifndef TestIndex                                                                         //07-10-30|0x025b
#define TestIndex 0                                                                       //07-10-30|0x025b
#endif                                                                                    //07-10-30|0x025b
//------------------------------------------------------------------------                //07-10-30|0x025b
enum {  update_always_1 = TestIndex };                                                    //07-10-30|0x025b
//------------------------------------------------------------------------                //07-10-30|0x025b
#undef TestIndex                                                                          //07-10-30|0x025b
#define TestIndex update_always_1+1                                                       //07-10-30|0x025b
//************************************************************************                //07-10-30|0x025b
#ifndef TestIndex                                                                         //08-06-15|0x0274
#define TestIndex 0                                                                       //08-06-15|0x0274
#endif                                                                                    //08-06-15|0x0274
//------------------------------------------------------------------------                //08-06-15|0x0274
enum {  turn_off_display_1 = TestIndex };                                                 //08-06-15|0x0274
//------------------------------------------------------------------------                //08-06-15|0x0274
#undef TestIndex                                                                          //08-06-15|0x0274
#define TestIndex turn_off_display_1+1                                                    //08-06-15|0x0274
//************************************************************************                //08-06-15|0x0274
#ifndef TestIndex                                                                         //08-06-15|0x028a
#define TestIndex 0                                                                       //08-06-15|0x028a
#endif                                                                                    //08-06-15|0x028a
//------------------------------------------------------------------------                //08-06-15|0x028a
enum {  turn_on_display_1 = TestIndex };                                                  //08-06-15|0x028a
//------------------------------------------------------------------------                //08-06-15|0x028a
#undef TestIndex                                                                          //08-06-15|0x028a
#define TestIndex turn_on_display_1+1                                                     //08-06-15|0x028a
//************************************************************************                //08-06-15|0x028a
#ifndef TestIndex                                                                         //08-06-15|0x02a0
#define TestIndex 0                                                                       //08-06-15|0x02a0
#endif                                                                                    //08-06-15|0x02a0
//------------------------------------------------------------------------                //08-06-15|0x02a0
enum {  enable_file_time_1 = TestIndex };                                                 //08-06-15|0x02a0
//------------------------------------------------------------------------                //08-06-15|0x02a0
#undef TestIndex                                                                          //08-06-15|0x02a0
#define TestIndex enable_file_time_1+1                                                    //08-06-15|0x02a0
//************************************************************************                //08-06-15|0x02a0
#ifndef TestIndex                                                                         //08-06-15|0x02bd
#define TestIndex 0                                                                       //08-06-15|0x02bd
#endif                                                                                    //08-06-15|0x02bd
//------------------------------------------------------------------------                //08-06-15|0x02bd
enum {  disable_file_time_1 = TestIndex };                                                //08-06-15|0x02bd
//------------------------------------------------------------------------                //08-06-15|0x02bd
#undef TestIndex                                                                          //08-06-15|0x02bd
#define TestIndex disable_file_time_1+1                                                   //08-06-15|0x02bd
//************************************************************************                //08-06-15|0x02bd
#ifndef TestIndex                                                                         //09-03-27|0x02da
#define TestIndex 0                                                                       //09-03-27|0x02da
#endif                                                                                    //09-03-27|0x02da
//------------------------------------------------------------------------                //09-03-27|0x02da
enum {  update_task_no_1 = TestIndex };                                                   //09-03-27|0x02da
//------------------------------------------------------------------------                //09-03-27|0x02da
#undef TestIndex                                                                          //09-03-27|0x02da
#define TestIndex update_task_no_1+1                                                      //09-03-27|0x02da
//************************************************************************                //09-03-27|0x02da
#ifndef TestIndex                                                                         //11-12-12|0x02db
#define TestIndex 0                                                                       //11-12-12|0x02db
#endif                                                                                    //11-12-12|0x02db
//------------------------------------------------------------------------                //11-12-12|0x02db
enum {  update_task_no_2 = TestIndex };                                                   //11-12-12|0x02db
//------------------------------------------------------------------------                //11-12-12|0x02db
#undef TestIndex                                                                          //11-12-12|0x02db
#define TestIndex update_task_no_2+1                                                      //11-12-12|0x02db
//************************************************************************                //11-12-12|0x02db
#ifndef TestIndex                                                                         //11-12-12|0x02dc
#define TestIndex 0                                                                       //11-12-12|0x02dc
#endif                                                                                    //11-12-12|0x02dc
//------------------------------------------------------------------------                //11-12-12|0x02dc
enum {  update_task_no_3 = TestIndex };                                                   //11-12-12|0x02dc
//------------------------------------------------------------------------                //11-12-12|0x02dc
#undef TestIndex                                                                          //11-12-12|0x02dc
#define TestIndex update_task_no_3+1                                                      //11-12-12|0x02dc
//************************************************************************                //11-12-12|0x02dc
#ifndef TestIndex                                                                         //06-08-09|0x0314
#define TestIndex 0                                                                       //06-08-09|0x0314
#endif                                                                                    //06-08-09|0x0314
//------------------------------------------------------------------------                //06-08-09|0x0314
enum {  drive_path_1 = TestIndex };                                                       //06-08-09|0x0314
//------------------------------------------------------------------------                //06-08-09|0x0314
#undef TestIndex                                                                          //06-08-09|0x0314
#define TestIndex drive_path_1+1                                                          //06-08-09|0x0314
//************************************************************************                //06-08-09|0x0314
#ifndef TestIndex                                                                         //06-08-29|0x032e
#define TestIndex 0                                                                       //06-08-29|0x032e
#endif                                                                                    //06-08-29|0x032e
//------------------------------------------------------------------------                //06-08-29|0x032e
enum {  get_file_name_1 = TestIndex };                                                    //06-08-29|0x032e
//------------------------------------------------------------------------                //06-08-29|0x032e
#undef TestIndex                                                                          //06-08-29|0x032e
#define TestIndex get_file_name_1+1                                                       //06-08-29|0x032e
//************************************************************************                //06-08-29|0x032e
#ifndef TestIndex                                                                         //06-08-29|0x0345
#define TestIndex 0                                                                       //06-08-29|0x0345
#endif                                                                                    //06-08-29|0x0345
//------------------------------------------------------------------------                //06-08-29|0x0345
enum {  develop_push_1 = TestIndex };                                                     //06-08-29|0x0345
//------------------------------------------------------------------------                //06-08-29|0x0345
#undef TestIndex                                                                          //06-08-29|0x0345
#define TestIndex develop_push_1+1                                                        //06-08-29|0x0345
//************************************************************************                //06-08-29|0x0345
#ifndef TestIndex                                                                         //11-12-12|0x035a
#define TestIndex 0                                                                       //11-12-12|0x035a
#endif                                                                                    //11-12-12|0x035a
//------------------------------------------------------------------------                //11-12-12|0x035a
enum {  decrement_project_no_1 = TestIndex };                                             //11-12-12|0x035a
//------------------------------------------------------------------------                //11-12-12|0x035a
#undef TestIndex                                                                          //11-12-12|0x035a
#define TestIndex decrement_project_no_1+1                                                //11-12-12|0x035a
//************************************************************************                //11-12-12|0x035a
#ifndef TestIndex                                                                         //11-12-12|0x035b
#define TestIndex 0                                                                       //11-12-12|0x035b
#endif                                                                                    //11-12-12|0x035b
//------------------------------------------------------------------------                //11-12-12|0x035b
enum {  decrement_project_no_2 = TestIndex };                                             //11-12-12|0x035b
//------------------------------------------------------------------------                //11-12-12|0x035b
#undef TestIndex                                                                          //11-12-12|0x035b
#define TestIndex decrement_project_no_2+1                                                //11-12-12|0x035b
//************************************************************************                //11-12-12|0x035b
#ifndef TestIndex                                                                         //06-08-29|0x0375
#define TestIndex 0                                                                       //06-08-29|0x0375
#endif                                                                                    //06-08-29|0x0375
//------------------------------------------------------------------------                //06-08-29|0x0375
enum {  develop_pop_1 = TestIndex };                                                      //06-08-29|0x0375
//------------------------------------------------------------------------                //06-08-29|0x0375
#undef TestIndex                                                                          //06-08-29|0x0375
#define TestIndex develop_pop_1+1                                                         //06-08-29|0x0375
//************************************************************************                //06-08-29|0x0375
#ifndef TestIndex                                                                         //06-11-14|0x038a
#define TestIndex 0                                                                       //06-11-14|0x038a
#endif                                                                                    //06-11-14|0x038a
//------------------------------------------------------------------------                //06-11-14|0x038a
enum {  source_args_1 = TestIndex };                                                      //06-11-14|0x038a
//------------------------------------------------------------------------                //06-11-14|0x038a
#undef TestIndex                                                                          //06-11-14|0x038a
#define TestIndex source_args_1+1                                                         //06-11-14|0x038a
//************************************************************************                //06-11-14|0x038a
#ifndef TestIndex                                                                         //08-12-27|0x03a3
#define TestIndex 0                                                                       //08-12-27|0x03a3
#endif                                                                                    //08-12-27|0x03a3
//------------------------------------------------------------------------                //08-12-27|0x03a3
enum {  spawn_mame_1 = TestIndex };                                                       //08-12-27|0x03a3
//------------------------------------------------------------------------                //08-12-27|0x03a3
#undef TestIndex                                                                          //08-12-27|0x03a3
#define TestIndex spawn_mame_1+1                                                          //08-12-27|0x03a3
//************************************************************************                //08-12-27|0x03a3
#ifndef TestIndex                                                                         //08-12-27|0x03c5
#define TestIndex 0                                                                       //08-12-27|0x03c5
#endif                                                                                    //08-12-27|0x03c5
//------------------------------------------------------------------------                //08-12-27|0x03c5
enum {  spawn_parms_1 = TestIndex };                                                      //08-12-27|0x03c5
//------------------------------------------------------------------------                //08-12-27|0x03c5
#undef TestIndex                                                                          //08-12-27|0x03c5
#define TestIndex spawn_parms_1+1                                                         //08-12-27|0x03c5
//************************************************************************                //08-12-27|0x03c5
#ifndef TestIndex                                                                         //08-12-27|0x0414
#define TestIndex 0                                                                       //08-12-27|0x0414
#endif                                                                                    //08-12-27|0x0414
//------------------------------------------------------------------------                //08-12-27|0x0414
enum {  make_step_1 = TestIndex };                                                        //08-12-27|0x0414
//------------------------------------------------------------------------                //08-12-27|0x0414
#undef TestIndex                                                                          //08-12-27|0x0414
#define TestIndex make_step_1+1                                                           //08-12-27|0x0414
//************************************************************************                //08-12-27|0x0414
#ifndef TestIndex                                                                         //08-12-27|0x0415
#define TestIndex 0                                                                       //08-12-27|0x0415
#endif                                                                                    //08-12-27|0x0415
//------------------------------------------------------------------------                //08-12-27|0x0415
enum {  make_step_2 = TestIndex };                                                        //08-12-27|0x0415
//------------------------------------------------------------------------                //08-12-27|0x0415
#undef TestIndex                                                                          //08-12-27|0x0415
#define TestIndex make_step_2+1                                                           //08-12-27|0x0415
//************************************************************************                //08-12-27|0x0415
#ifndef TestIndex                                                                         //06-08-09|0x0462
#define TestIndex 0                                                                       //06-08-09|0x0462
#endif                                                                                    //06-08-09|0x0462
//------------------------------------------------------------------------                //06-08-09|0x0462
enum {  close_project_1 = TestIndex };                                                    //06-08-09|0x0462
//------------------------------------------------------------------------                //06-08-09|0x0462
#undef TestIndex                                                                          //06-08-09|0x0462
#define TestIndex close_project_1+1                                                       //06-08-09|0x0462
//************************************************************************                //06-08-09|0x0462
//*******************************************************************************         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
//****                       END OF FILE                                     ****         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
//*******************************************************************************         //05-24-97|0x0492
#endif                                                                                    //05-24-97|0x0492
