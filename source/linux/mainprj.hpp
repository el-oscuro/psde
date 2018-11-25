//*****************************************************************************           //06-07-12|0x0008
//*****************************************************************************           //06-07-12|0x0008
//                                                                                        //06-07-12|0x0008
// PROGRAMMABLE DEVELOPMENT ENVIRONMENT                                                   //06-07-12|0x0008
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
#ifndef mainprj_hpp                                                                       //06-07-12|0x000b
#define mainprj_hpp                                                                       //06-07-12|0x000b
//***************************************************************************             //06-07-12|0x002d
//***************************************************************************             //06-07-12|0x002e
//******                                                               ******             //06-07-12|0x002f
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0030
//******                                                               ******             //06-07-12|0x0031
//***************************************************************************             //06-07-12|0x0032
//***************************************************************************             //06-07-12|0x0033
//***************************************************************************             //06-07-12|0x0036
//***************************************************************************             //06-07-12|0x0037
//******                                                               ******             //06-07-12|0x0038
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x0039
//******                                                               ******             //06-07-12|0x003a
//***************************************************************************             //06-07-12|0x003b
//***************************************************************************             //06-07-12|0x003c
#define UserError 0x0000                                                                  //06-07-12|0x003d
#define BuildError 0x7fff                                                                 //06-07-12|0x003d
#define Display 0x7ffe                                                                    //06-07-12|0x003d
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x003d
#define Success 0xffff                                                                    //06-07-12|0x003d
#define SystemError 0x8000                                                                //06-07-12|0x003d
#define Continue 0x0001                                                                   //06-07-12|0x003d
#define FileDone 0x0002                                                                   //06-07-12|0x003d
#define LineDone 0x0003                                                                   //06-07-12|0x003d
#define Yes 0x0004                                                                        //06-07-12|0x003d
#define No 0x0005                                                                         //06-07-12|0x003d
#define RepeatChar '\x6'                                                                  //06-07-12|0x003d
#define Great 0x0007                                                                      //06-07-12|0x003d
#define Equal 0x0008                                                                      //06-07-12|0x003d
#define Less 0x0009                                                                       //06-07-12|0x003d
#define Zero 0x000a                                                                       //06-07-12|0x003d
#define Minus 0x000b                                                                      //06-07-12|0x003d
//***************************************************************************             //06-07-12|0x003e
#define SystemMsg PcgSystemError("mainprj", __LINE__);                                    //06-07-12|0x003f
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x003f
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-07-12|0x003f
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0040
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0040
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0040
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0040
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0041
#define _SwitchOk case Success: break                                                     //06-07-12|0x0041
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0041
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0041
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0041
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0041
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0041
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0041
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0041
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0041
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0041
//***************************************************************************             //06-07-12|0x0062
//***************************************************************************             //06-07-12|0x0063
//******                                                               ******             //06-07-12|0x0064
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0065
//******                                                               ******             //06-07-12|0x0066
//***************************************************************************             //06-07-12|0x0067
//***************************************************************************             //06-07-12|0x0068
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x0069
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x0069
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x0069
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x0069
#define return_cont(j) { TestSample(j);  return(Continue); }                              //06-07-12|0x0069
#define return_line(j) { TestSample(j);  return(LineDone); }                              //06-07-12|0x0069
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x0069
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x0069
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x0069
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x0069
//************************************************************************                //06-07-12|0x0069
#ifndef TestIndex                                                                         //06-07-12|0x0069
#define TestIndex 0                                                                       //06-07-12|0x0069
#endif                                                                                    //06-07-12|0x0069
//------------------------------------------------------------------------                //06-07-12|0x0069
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x0069
//------------------------------------------------------------------------                //06-07-12|0x0069
#undef TestIndex                                                                          //06-07-12|0x0069
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x0069
//************************************************************************                //06-07-12|0x0069
//***************************************************************************             //06-07-12|0x006a
#define MainProjectName main_base_addr->project_name                                      //06-07-12|0x006b
#define MainProject main_base_addr->project                                               //06-07-12|0x006b
#define MainTokens main_base_addr->tokens                                                 //06-07-12|0x006b
#define MainDrives main_base_addr->drives                                                 //06-07-12|0x006b
#define MainProjectTime main_base_addr->project_time                                      //06-07-12|0x006b
#define MainUpdateTime main_base_addr->update_time                                        //06-07-12|0x006b
#define MainExecTime main_base_addr->exec_time                                            //06-07-12|0x006b
#define MainState main_base_addr->state                                                   //06-07-12|0x006b
#define MainStatus main_base_addr->status                                                 //06-07-12|0x006b
#define MainRunFlag main_base_addr->run_flag                                              //06-07-12|0x006b
#define MainTaskNo main_base_addr->task_no                                                //06-07-12|0x006b
//----------------------------------------------------------------------                  //06-07-12|0x006b
#define MainProjectAddr &(main_base_addr->project)                                        //06-07-12|0x006b
#define MainTokensAddr &(main_base_addr->tokens)                                          //06-07-12|0x006b
#define MainDrivesAddr &(main_base_addr->drives)                                          //06-07-12|0x006b
#define MainProjectTimeAddr &(main_base_addr->project_time)                               //06-07-12|0x006b
#define MainTaskNoAddr &(main_base_addr->task_no)                                         //06-07-12|0x006b
//************************************************************************                //06-07-12|0x006c
#define TokensTokenAddr(i) &(MainTokens.token[i])                                         //06-07-12|0x006c
#define TokensMacroLineNo(i) MainTokens.token[i].macro_line_no                            //06-07-12|0x006c
#define TokensLineAddr(i) &(MainTokens.token[i].line[0])                                  //06-07-12|0x006c
#define TokensToken(i) MainTokens.token[i]                                                //06-07-12|0x006c
#define TokensLine(i) MainTokens.token[i].line                                            //06-07-12|0x006c
#define TokensLength(i) MainTokens.token[i].length                                        //06-07-12|0x006c
#define TokensColumn(i) MainTokens.token[i].column                                        //06-07-12|0x006c
#define TokensHash(i) MainTokens.token[i].hash                                            //06-07-12|0x006c
#define TokensPosition(i) MainTokens.token[i].position                                    //06-07-12|0x006c
#define TokensType(i) MainTokens.token[i].type                                            //06-07-12|0x006c
#define TokensStartCol(i) MainTokens.token[i].start_col                                   //06-07-12|0x006c
#define TokensStartCall(i) MainTokens.token[i].start_call                                 //06-07-12|0x006c
#define TokensChar(i,j) MainTokens.token[i].line[j]                                       //06-07-12|0x006c
#define TokensNoTokens MainTokens.no_tokens                                               //06-07-12|0x006c
//************************************************************************                //06-12-09|0x006d
#define DrivePathTokenAddr(i) &(MainDrives.token[i])                                      //06-12-09|0x006d
#define DrivePathMacroLineNo(i) MainDrives.token[i].macro_line_no                         //06-12-09|0x006d
#define DrivePathLineAddr(i) &(MainDrives.token[i].line[0])                               //06-12-09|0x006d
#define DrivePathToken(i) MainDrives.token[i]                                             //06-12-09|0x006d
#define DrivePathLine(i) MainDrives.token[i].line                                         //06-12-09|0x006d
#define DrivePathLength(i) MainDrives.token[i].length                                     //06-12-09|0x006d
#define DrivePathColumn(i) MainDrives.token[i].column                                     //06-12-09|0x006d
#define DrivePathHash(i) MainDrives.token[i].hash                                         //06-12-09|0x006d
#define DrivePathPosition(i) MainDrives.token[i].position                                 //06-12-09|0x006d
#define DrivePathType(i) MainDrives.token[i].type                                         //06-12-09|0x006d
#define DrivePathStartCol(i) MainDrives.token[i].start_col                                //06-12-09|0x006d
#define DrivePathStartCall(i) MainDrives.token[i].start_call                              //06-12-09|0x006d
#define DrivePathChar(i,j) MainDrives.token[i].line[j]                                    //06-12-09|0x006d
#define DrivePathNoTokens MainDrives.no_tokens                                            //06-12-09|0x006d
//***************************************************************************             //06-07-12|0x006e
#define ProjectDoesNotExist Finish("Project File Does Not Exist")                         //06-07-12|0x006f
#define IllegalCommand Finish("Illegal Command")                                          //06-07-12|0x006f
#define LoadTokenArg(i,j) MemCCpy(TokensLineAddr(i),j,0x00,256)                           //06-07-12|0x006f
#define DisplayLine1(i) GuiWriteLine(i) !=Success                                         //06-07-12|0x006f
#define DisplayLine(i) if(DisplayLine1(i))         ReturnSystemError                      //06-07-12|0x006f
#define AppendLine1(i) GuiAppendLine(i) !=Success                                         //06-07-12|0x006f
#define AppendLine(i) if(AppendLine1(i))          ReturnSystemError                       //06-07-12|0x006f
#define StrDataCpy(i,j) MemCpy(i, j, sizeof(STRING_DATA))                                 //06-07-12|0x006f
#define InitialProjFile FileInitialText(MainProjectAddr)                                  //06-07-12|0x006f
#define EnterProjFileName FileEnterName(MainProjectName,   CMK_EXTENT)                    //06-07-12|0x006f
#define CommitProjFile FileCommitText(MainProjectAddr)                                    //06-07-12|0x006f
#define EnterMailDictName MailDictName(MainProjectName,   DIC_EXTENT)                     //06-07-12|0x006f
#define IfNoTokens1(i) (TokensNoTokens < i)                                               //06-07-12|0x006f
#define IfNoTokens2(i) (TokensNoTokens > i)                                               //06-07-12|0x006f
#define IfNoTokens(i,j) if(IfNoTokens1(i) || IfNoTokens2(j))                              //06-07-12|0x006f
#define CmdTest(i) StrCmp(TokensLineAddr(0),i)                                            //06-07-12|0x006f
#define DevelopProject2(i,j) DevProjProcess(MainTokensAddr, i, j)                         //06-07-12|0x006f
#define DevelopProject1(i) DevelopProject2(MainUpdateTime, i)                             //06-07-12|0x006f
#define DevelopProject DevelopProject1(MainTaskNoAddr)                                    //06-07-12|0x006f
#define TestProject1(i) TestProjProcess(MainTokensAddr, i)                                //06-07-12|0x006f
#define TestProject TestProject1(MainUpdateTime)                                          //06-07-12|0x006f
#define FileTextPrepare TextPrepare(DrivePathTokenAddr(0),TokensTokenAddr(1))             //06-08-08|0x0070
#define CMK_EXTENT ".cmk"                                                                 //06-07-12|0x0072
#define TMK_EXTENT ".tmk"                                                                 //06-07-12|0x0072
#define RPT_EXTENT ".rpt"                                                                 //06-07-12|0x0072
#define PMK_EXTENT ".pmk"                                                                 //06-07-12|0x0072
#define MAC_EXTENT ".mac"                                                                 //06-07-12|0x0072
#define SRC_EXTENT ".src"                                                                 //06-07-12|0x0072
#define PLB_EXTENT ".plb"                                                                 //06-07-12|0x0072
#define DIC_EXTENT ".dic"                                                                 //06-07-12|0x0072
#define MBX_EXTENT ".mbx"                                                                 //06-07-12|0x0072
#define MBC_EXTENT ".mbc"                                                                 //06-07-12|0x0072
#define RAN_EXTENT ".ran"                                                                 //06-07-12|0x0072
#define BUF_OUT_EXTENT ".bfo"                                                             //06-07-12|0x0072
#define BUF_IN_EXTENT ".bfi"                                                              //06-07-12|0x0072
#ifndef TestIndex                                                                         //06-07-12|0x007d
#define TestIndex 0                                                                       //06-07-12|0x007d
#endif                                                                                    //06-07-12|0x007d
//------------------------------------------------------------------------                //06-07-12|0x007d
enum {  main_allocate_1 = TestIndex };                                                    //06-07-12|0x007d
//------------------------------------------------------------------------                //06-07-12|0x007d
#undef TestIndex                                                                          //06-07-12|0x007d
#define TestIndex main_allocate_1+1                                                       //06-07-12|0x007d
//************************************************************************                //06-07-12|0x007d
#ifndef TestIndex                                                                         //06-07-12|0x00a9
#define TestIndex 0                                                                       //06-07-12|0x00a9
#endif                                                                                    //06-07-12|0x00a9
//------------------------------------------------------------------------                //06-07-12|0x00a9
enum {  main_free_1 = TestIndex };                                                        //06-07-12|0x00a9
//------------------------------------------------------------------------                //06-07-12|0x00a9
#undef TestIndex                                                                          //06-07-12|0x00a9
#define TestIndex main_free_1+1                                                           //06-07-12|0x00a9
//************************************************************************                //06-07-12|0x00a9
#ifndef TestIndex                                                                         //06-07-20|0x00d1
#define TestIndex 0                                                                       //06-07-20|0x00d1
#endif                                                                                    //06-07-20|0x00d1
//------------------------------------------------------------------------                //06-07-20|0x00d1
enum {  get_arguments_1 = TestIndex };                                                    //06-07-20|0x00d1
//------------------------------------------------------------------------                //06-07-20|0x00d1
#undef TestIndex                                                                          //06-07-20|0x00d1
#define TestIndex get_arguments_1+1                                                       //06-07-20|0x00d1
//************************************************************************                //06-07-20|0x00d1
#ifndef TestIndex                                                                         //06-09-21|0x0102
#define TestIndex 0                                                                       //06-09-21|0x0102
#endif                                                                                    //06-09-21|0x0102
//------------------------------------------------------------------------                //06-09-21|0x0102
enum {  pcg_success_1 = TestIndex };                                                      //06-09-21|0x0102
//------------------------------------------------------------------------                //06-09-21|0x0102
#undef TestIndex                                                                          //06-09-21|0x0102
#define TestIndex pcg_success_1+1                                                         //06-09-21|0x0102
//************************************************************************                //06-09-21|0x0102
#ifndef TestIndex                                                                         //06-07-12|0x0117
#define TestIndex 0                                                                       //06-07-12|0x0117
#endif                                                                                    //06-07-12|0x0117
//------------------------------------------------------------------------                //06-07-12|0x0117
enum {  pcg_stop_1 = TestIndex };                                                         //06-07-12|0x0117
//------------------------------------------------------------------------                //06-07-12|0x0117
#undef TestIndex                                                                          //06-07-12|0x0117
#define TestIndex pcg_stop_1+1                                                            //06-07-12|0x0117
//************************************************************************                //06-07-12|0x0117
#ifndef TestIndex                                                                         //06-08-08|0x0252
#define TestIndex 0                                                                       //06-08-08|0x0252
#endif                                                                                    //06-08-08|0x0252
//------------------------------------------------------------------------                //06-08-08|0x0252
enum {  enter_project_name_1 = TestIndex };                                               //06-08-08|0x0252
//------------------------------------------------------------------------                //06-08-08|0x0252
#undef TestIndex                                                                          //06-08-08|0x0252
#define TestIndex enter_project_name_1+1                                                  //06-08-08|0x0252
//************************************************************************                //06-08-08|0x0252
#ifndef TestIndex                                                                         //06-08-08|0x026b
#define TestIndex 0                                                                       //06-08-08|0x026b
#endif                                                                                    //06-08-08|0x026b
//------------------------------------------------------------------------                //06-08-08|0x026b
enum {  project_exists_1 = TestIndex };                                                   //06-08-08|0x026b
//------------------------------------------------------------------------                //06-08-08|0x026b
#undef TestIndex                                                                          //06-08-08|0x026b
#define TestIndex project_exists_1+1                                                      //06-08-08|0x026b
//************************************************************************                //06-08-08|0x026b
#ifndef TestIndex                                                                         //06-08-08|0x0296
#define TestIndex 0                                                                       //06-08-08|0x0296
#endif                                                                                    //06-08-08|0x0296
//------------------------------------------------------------------------                //06-08-08|0x0296
enum {  open_project_1 = TestIndex };                                                     //06-08-08|0x0296
//------------------------------------------------------------------------                //06-08-08|0x0296
#undef TestIndex                                                                          //06-08-08|0x0296
#define TestIndex open_project_1+1                                                        //06-08-08|0x0296
//************************************************************************                //06-08-08|0x0296
#ifndef TestIndex                                                                         //06-08-08|0x02ad
#define TestIndex 0                                                                       //06-08-08|0x02ad
#endif                                                                                    //06-08-08|0x02ad
//------------------------------------------------------------------------                //06-08-08|0x02ad
enum {  read_project_1 = TestIndex };                                                     //06-08-08|0x02ad
//------------------------------------------------------------------------                //06-08-08|0x02ad
#undef TestIndex                                                                          //06-08-08|0x02ad
#define TestIndex read_project_1+1                                                        //06-08-08|0x02ad
//************************************************************************                //06-08-08|0x02ad
#ifndef TestIndex                                                                         //06-08-08|0x02ae
#define TestIndex 0                                                                       //06-08-08|0x02ae
#endif                                                                                    //06-08-08|0x02ae
//------------------------------------------------------------------------                //06-08-08|0x02ae
enum {  read_project_2 = TestIndex };                                                     //06-08-08|0x02ae
//------------------------------------------------------------------------                //06-08-08|0x02ae
#undef TestIndex                                                                          //06-08-08|0x02ae
#define TestIndex read_project_2+1                                                        //06-08-08|0x02ae
//************************************************************************                //06-08-08|0x02ae
#ifndef TestIndex                                                                         //06-08-08|0x02af
#define TestIndex 0                                                                       //06-08-08|0x02af
#endif                                                                                    //06-08-08|0x02af
//------------------------------------------------------------------------                //06-08-08|0x02af
enum {  read_project_3 = TestIndex };                                                     //06-08-08|0x02af
//------------------------------------------------------------------------                //06-08-08|0x02af
#undef TestIndex                                                                          //06-08-08|0x02af
#define TestIndex read_project_3+1                                                        //06-08-08|0x02af
//************************************************************************                //06-08-08|0x02af
#ifndef TestIndex                                                                         //06-08-08|0x02b0
#define TestIndex 0                                                                       //06-08-08|0x02b0
#endif                                                                                    //06-08-08|0x02b0
//------------------------------------------------------------------------                //06-08-08|0x02b0
enum {  read_project_4 = TestIndex };                                                     //06-08-08|0x02b0
//------------------------------------------------------------------------                //06-08-08|0x02b0
#undef TestIndex                                                                          //06-08-08|0x02b0
#define TestIndex read_project_4+1                                                        //06-08-08|0x02b0
//************************************************************************                //06-08-08|0x02b0
#ifndef TestIndex                                                                         //08-06-14|0x02db
#define TestIndex 0                                                                       //08-06-14|0x02db
#endif                                                                                    //08-06-14|0x02db
//------------------------------------------------------------------------                //08-06-14|0x02db
enum {  turn_off_display_1 = TestIndex };                                                 //08-06-14|0x02db
//------------------------------------------------------------------------                //08-06-14|0x02db
#undef TestIndex                                                                          //08-06-14|0x02db
#define TestIndex turn_off_display_1+1                                                    //08-06-14|0x02db
//************************************************************************                //08-06-14|0x02db
#ifndef TestIndex                                                                         //08-06-14|0x02f1
#define TestIndex 0                                                                       //08-06-14|0x02f1
#endif                                                                                    //08-06-14|0x02f1
//------------------------------------------------------------------------                //08-06-14|0x02f1
enum {  turn_on_display_1 = TestIndex };                                                  //08-06-14|0x02f1
//------------------------------------------------------------------------                //08-06-14|0x02f1
#undef TestIndex                                                                          //08-06-14|0x02f1
#define TestIndex turn_on_display_1+1                                                     //08-06-14|0x02f1
//************************************************************************                //08-06-14|0x02f1
#ifndef TestIndex                                                                         //06-07-14|0x0307
#define TestIndex 0                                                                       //06-07-14|0x0307
#endif                                                                                    //06-07-14|0x0307
//------------------------------------------------------------------------                //06-07-14|0x0307
enum {  reset_self_test_1 = TestIndex };                                                  //06-07-14|0x0307
//------------------------------------------------------------------------                //06-07-14|0x0307
#undef TestIndex                                                                          //06-07-14|0x0307
#define TestIndex reset_self_test_1+1                                                     //06-07-14|0x0307
//************************************************************************                //06-07-14|0x0307
#ifndef TestIndex                                                                         //06-07-14|0x031d
#define TestIndex 0                                                                       //06-07-14|0x031d
#endif                                                                                    //06-07-14|0x031d
//------------------------------------------------------------------------                //06-07-14|0x031d
enum {  start_self_test_1 = TestIndex };                                                  //06-07-14|0x031d
//------------------------------------------------------------------------                //06-07-14|0x031d
#undef TestIndex                                                                          //06-07-14|0x031d
#define TestIndex start_self_test_1+1                                                     //06-07-14|0x031d
//************************************************************************                //06-07-14|0x031d
#ifndef TestIndex                                                                         //06-07-14|0x0351
#define TestIndex 0                                                                       //06-07-14|0x0351
#endif                                                                                    //06-07-14|0x0351
//------------------------------------------------------------------------                //06-07-14|0x0351
enum {  set_tab_1 = TestIndex };                                                          //06-07-14|0x0351
//------------------------------------------------------------------------                //06-07-14|0x0351
#undef TestIndex                                                                          //06-07-14|0x0351
#define TestIndex set_tab_1+1                                                             //06-07-14|0x0351
//************************************************************************                //06-07-14|0x0351
#ifndef TestIndex                                                                         //12-05-18|0x0370
#define TestIndex 0                                                                       //12-05-18|0x0370
#endif                                                                                    //12-05-18|0x0370
//------------------------------------------------------------------------                //12-05-18|0x0370
enum {  load_report_file_1 = TestIndex };                                                 //12-05-18|0x0370
//------------------------------------------------------------------------                //12-05-18|0x0370
#undef TestIndex                                                                          //12-05-18|0x0370
#define TestIndex load_report_file_1+1                                                    //12-05-18|0x0370
//************************************************************************                //12-05-18|0x0370
#ifndef TestIndex                                                                         //12-05-21|0x0387
#define TestIndex 0                                                                       //12-05-21|0x0387
#endif                                                                                    //12-05-21|0x0387
//------------------------------------------------------------------------                //12-05-21|0x0387
enum {  enable_report_file_1 = TestIndex };                                               //12-05-21|0x0387
//------------------------------------------------------------------------                //12-05-21|0x0387
#undef TestIndex                                                                          //12-05-21|0x0387
#define TestIndex enable_report_file_1+1                                                  //12-05-21|0x0387
//************************************************************************                //12-05-21|0x0387
#ifndef TestIndex                                                                         //12-05-21|0x039d
#define TestIndex 0                                                                       //12-05-21|0x039d
#endif                                                                                    //12-05-21|0x039d
//------------------------------------------------------------------------                //12-05-21|0x039d
enum {  disable_report_file_1 = TestIndex };                                              //12-05-21|0x039d
//------------------------------------------------------------------------                //12-05-21|0x039d
#undef TestIndex                                                                          //12-05-21|0x039d
#define TestIndex disable_report_file_1+1                                                 //12-05-21|0x039d
//************************************************************************                //12-05-21|0x039d
#ifndef TestIndex                                                                         //08-06-14|0x03b3
#define TestIndex 0                                                                       //08-06-14|0x03b3
#endif                                                                                    //08-06-14|0x03b3
//------------------------------------------------------------------------                //08-06-14|0x03b3
enum {  enable_file_time_1 = TestIndex };                                                 //08-06-14|0x03b3
//------------------------------------------------------------------------                //08-06-14|0x03b3
#undef TestIndex                                                                          //08-06-14|0x03b3
#define TestIndex enable_file_time_1+1                                                    //08-06-14|0x03b3
//************************************************************************                //08-06-14|0x03b3
#ifndef TestIndex                                                                         //08-06-14|0x03d0
#define TestIndex 0                                                                       //08-06-14|0x03d0
#endif                                                                                    //08-06-14|0x03d0
//------------------------------------------------------------------------                //08-06-14|0x03d0
enum {  disable_file_time_1 = TestIndex };                                                //08-06-14|0x03d0
//------------------------------------------------------------------------                //08-06-14|0x03d0
#undef TestIndex                                                                          //08-06-14|0x03d0
#define TestIndex disable_file_time_1+1                                                   //08-06-14|0x03d0
//************************************************************************                //08-06-14|0x03d0
#ifndef TestIndex                                                                         //06-08-08|0x03ed
#define TestIndex 0                                                                       //06-08-08|0x03ed
#endif                                                                                    //06-08-08|0x03ed
//------------------------------------------------------------------------                //06-08-08|0x03ed
enum {  drive_path_1 = TestIndex };                                                       //06-08-08|0x03ed
//------------------------------------------------------------------------                //06-08-08|0x03ed
#undef TestIndex                                                                          //06-08-08|0x03ed
#define TestIndex drive_path_1+1                                                          //06-08-08|0x03ed
//************************************************************************                //06-08-08|0x03ed
#ifndef TestIndex                                                                         //06-08-28|0x0407
#define TestIndex 0                                                                       //06-08-28|0x0407
#endif                                                                                    //06-08-28|0x0407
//------------------------------------------------------------------------                //06-08-28|0x0407
enum {  push_project_1 = TestIndex };                                                     //06-08-28|0x0407
//------------------------------------------------------------------------                //06-08-28|0x0407
#undef TestIndex                                                                          //06-08-28|0x0407
#define TestIndex push_project_1+1                                                        //06-08-28|0x0407
//************************************************************************                //06-08-28|0x0407
#ifndef TestIndex                                                                         //06-08-08|0x0424
#define TestIndex 0                                                                       //06-08-08|0x0424
#endif                                                                                    //06-08-08|0x0424
//------------------------------------------------------------------------                //06-08-08|0x0424
enum {  close_project_1 = TestIndex };                                                    //06-08-08|0x0424
//------------------------------------------------------------------------                //06-08-08|0x0424
#undef TestIndex                                                                          //06-08-08|0x0424
#define TestIndex close_project_1+1                                                       //06-08-08|0x0424
//************************************************************************                //06-08-08|0x0424
//*******************************************************************************         //05-24-97|0x0457
//*******************************************************************************         //05-24-97|0x0457
//****                       END OF FILE                                     ****         //05-24-97|0x0457
//*******************************************************************************         //05-24-97|0x0457
//*******************************************************************************         //05-24-97|0x0457
#endif                                                                                    //05-24-97|0x0457
