//*****************************************************************************           //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
// PRECEDENCE ANALYSIS STACK                                                              //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  Copyright: 2006 Robert H. Adams                                                       //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  The purpose of this program as well as instructions regarding its use is              //05-14-97|0x001c
//  defined in the associated manual.                                                     //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  This program is free software; you can redistribute it and/or modify                  //05-14-97|0x001c
//  it under the terms of the GNU General Public License as published by                  //05-14-97|0x001c
//  the Free Software Foundation; either version 2 of the License, or                     //05-14-97|0x001c
//  (at your option) any later version.                                                   //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
//  This program is distributed in the hope that it will be useful,                       //05-14-97|0x001c
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //05-14-97|0x001c
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //05-14-97|0x001c
//  GNU General Public License for more details.                                          //05-14-97|0x001c
//                                                                                        //05-14-97|0x001c
//  You should have received a copy of the GNU General Public License                     //05-14-97|0x001c
//  along with this program; if not, write to the Free Software                           //05-14-97|0x001c
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //05-14-97|0x001c
//  USA                                                                                   //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//  For further information, please contact Robert Adams:                                 //05-14-97|0x001c
//     EMail:    robert.adams@whatifwe.com                                                //05-14-97|0x001c
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //05-14-97|0x001c
//  Or visit the website, "www.whatifwe.com".                                             //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
//*****************************************************************************           //05-14-97|0x001c
#ifndef precstck_hpp                                                                      //05-14-97|0x001e
#define precstck_hpp                                                                      //05-14-97|0x001e
//***************************************************************************             //06-07-12|0x0022
//***************************************************************************             //06-07-12|0x0023
//******                                                               ******             //06-07-12|0x0024
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0025
//******                                                               ******             //06-07-12|0x0026
//***************************************************************************             //06-07-12|0x0027
//***************************************************************************             //06-07-12|0x0028
//***************************************************************************             //06-07-12|0x002b
//***************************************************************************             //06-07-12|0x002c
//******                                                               ******             //06-07-12|0x002d
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x002e
//******                                                               ******             //06-07-12|0x002f
//***************************************************************************             //06-07-12|0x0030
//***************************************************************************             //06-07-12|0x0031
#define UserError 0x0000                                                                  //06-07-12|0x0032
#define BuildError 0x7fff                                                                 //06-07-12|0x0032
#define Display 0x7ffe                                                                    //06-07-12|0x0032
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x0032
#define Success 0xffff                                                                    //06-07-12|0x0032
#define SystemError 0x8000                                                                //06-07-12|0x0032
#define Continue 0x0001                                                                   //06-07-12|0x0032
#define FileDone 0x0002                                                                   //06-07-12|0x0032
#define LineDone 0x0003                                                                   //06-07-12|0x0032
#define Yes 0x0004                                                                        //06-07-12|0x0032
#define No 0x0005                                                                         //06-07-12|0x0032
#define RepeatChar '\x6'                                                                  //06-07-12|0x0032
#define Great 0x0007                                                                      //06-07-12|0x0032
#define Equal 0x0008                                                                      //06-07-12|0x0032
#define Less 0x0009                                                                       //06-07-12|0x0032
#define Zero 0x000a                                                                       //06-07-12|0x0032
#define Minus 0x000b                                                                      //06-07-12|0x0032
//***************************************************************************             //06-07-12|0x0033
#define SystemMsg PcgSystemError("precstck", __LINE__);                                   //06-07-12|0x0034
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x0034
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //06-07-12|0x0034
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0035
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0035
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0035
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0035
#define _SwitchErr case UserError: return(UserError)                                      //07-02-25|0x0036
#define _SwitchOk case Success: break                                                     //07-02-25|0x0036
#define _SwitchEnd default: ReturnSystemError                                             //07-02-25|0x0036
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-02-25|0x0036
#define _SwitchYes case Yes:      return(Yes)                                             //07-02-25|0x0036
#define _SwitchNo case No:       return(No)                                               //07-02-25|0x0036
#define _SwitchGroup { _SwitchBase; }                                                     //07-02-25|0x0036
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-02-25|0x0036
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-02-25|0x0036
#define _SwitchBreak _SwitchGroup break                                                   //07-02-25|0x0036
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-02-25|0x0036
//***************************************************************************             //06-07-12|0x0052
//***************************************************************************             //06-07-12|0x0053
//******                                                               ******             //06-07-12|0x0054
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x0055
//******                                                               ******             //06-07-12|0x0056
//***************************************************************************             //06-07-12|0x0057
//***************************************************************************             //06-07-12|0x0058
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x0059
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x0059
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x0059
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x0059
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x0059
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x0059
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x0059
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x0059
//************************************************************************                //06-07-12|0x0059
#ifndef TestIndex                                                                         //06-07-12|0x0059
#define TestIndex 0                                                                       //06-07-12|0x0059
#endif                                                                                    //06-07-12|0x0059
//------------------------------------------------------------------------                //06-07-12|0x0059
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x0059
//------------------------------------------------------------------------                //06-07-12|0x0059
#undef TestIndex                                                                          //06-07-12|0x0059
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x0059
//************************************************************************                //06-07-12|0x0059
#define InputChar(i) InputAddr->line[i]                                                   //07-03-05|0x005b
#define InputLine InputAddr->line[0]                                                      //07-03-05|0x005b
#define InputLineAddr &(InputAddr->line[0])                                               //07-03-05|0x005b
#define InputMacroLineNo InputAddr->macro_line_no                                         //07-03-05|0x005b
#define InputType InputAddr->type                                                         //07-03-05|0x005b
#define InputStartCol InputAddr->start_col                                                //07-03-05|0x005b
#define InputStartCall InputAddr->start_call                                              //07-03-05|0x005b
#define InputPosition InputAddr->position                                                 //07-03-05|0x005b
#define InputLength InputAddr->length                                                     //07-03-05|0x005b
#define InputColumn InputAddr->column                                                     //07-03-05|0x005b
//**********************************************************************                  //07-03-05|0x005b
#define StringChar(i) StringAddr->line[i]                                                 //06-07-12|0x005c
#define StringLine StringAddr->line[0]                                                    //06-07-12|0x005c
#define StringLineAddr &(StringAddr->line[0])                                             //06-07-12|0x005c
#define StringMacroLineNo StringAddr->macro_line_no                                       //06-07-12|0x005c
#define StringType StringAddr->type                                                       //06-07-12|0x005c
#define StringStartCol StringAddr->start_col                                              //06-07-12|0x005c
#define StringStartCall StringAddr->start_call                                            //06-07-12|0x005c
#define StringPosition StringAddr->position                                               //06-07-12|0x005c
#define StringLength StringAddr->length                                                   //06-07-12|0x005c
#define StringColumn StringAddr->column                                                   //06-07-12|0x005c
//**********************************************************************                  //06-07-12|0x005c
//************************************************************************                //06-07-12|0x005d
#define TokensTokenAddr(i) &(TokensAddr->token[i])                                        //06-07-12|0x005d
#define TokensMacroLineNo(i) TokensAddr->token[i].macro_line_no                           //06-07-12|0x005d
#define TokensLineAddr(i) &(TokensAddr->token[i].line[0])                                 //06-07-12|0x005d
#define TokensToken(i) TokensAddr->token[i]                                               //06-07-12|0x005d
#define TokensLine(i) TokensAddr->token[i].line                                           //06-07-12|0x005d
#define TokensLength(i) TokensAddr->token[i].length                                       //06-07-12|0x005d
#define TokensColumn(i) TokensAddr->token[i].column                                       //06-07-12|0x005d
#define TokensHash(i) TokensAddr->token[i].hash                                           //06-07-12|0x005d
#define TokensPosition(i) TokensAddr->token[i].position                                   //06-07-12|0x005d
#define TokensType(i) TokensAddr->token[i].type                                           //06-07-12|0x005d
#define TokensStartCol(i) TokensAddr->token[i].start_col                                  //06-07-12|0x005d
#define TokensStartCall(i) TokensAddr->token[i].start_call                                //06-07-12|0x005d
#define TokensChar(i,j) TokensAddr->token[i].line[j]                                      //06-07-12|0x005d
#define TokensNoTokens TokensAddr->no_tokens                                              //06-07-12|0x005d
//**********************************************************************                  //06-07-12|0x005f
#define StackState stack_addr->state                                                      //06-07-12|0x005f
#define StackStatus stack_addr->status                                                    //06-07-12|0x005f
#define StackRunFlag stack_addr->run_flag                                                 //06-07-12|0x005f
#define StackRelPos stack_addr->rel_pos                                                   //06-07-12|0x005f
#define StackAbsPosSlong stack_addr->abs_pos.slong                                        //06-07-12|0x005f
#define StackAbsPosUlong stack_addr->abs_pos.ulong                                        //06-07-12|0x005f
#define StackAbsPosChar stack_addr->abs_pos.char0                                         //06-07-12|0x005f
#define StackAbsPosUint stack_addr->abs_pos.word0                                         //06-07-12|0x005f
#define StackTotalPos stack_addr->total_pos                                               //06-07-12|0x005f
#define StackMacro stack_addr->macro                                                      //06-07-12|0x005f
#define StackName stack_addr->name                                                        //06-07-12|0x005f
#define StackWork stack_addr->work                                                        //06-07-12|0x005f
#define StackElement stack_addr->element                                                  //06-07-12|0x005f
//************************************************************************                //07-02-26|0x0060
#define MacroTokenAddr(i) &(StackMacro.token[i])                                          //07-02-26|0x0060
#define MacroMacroLineNo(i) StackMacro.token[i].macro_line_no                             //07-02-26|0x0060
#define MacroLineAddr(i) &(StackMacro.token[i].line[0])                                   //07-02-26|0x0060
#define MacroToken(i) StackMacro.token[i]                                                 //07-02-26|0x0060
#define MacroLine(i) StackMacro.token[i].line                                             //07-02-26|0x0060
#define MacroLength(i) StackMacro.token[i].length                                         //07-02-26|0x0060
#define MacroColumn(i) StackMacro.token[i].column                                         //07-02-26|0x0060
#define MacroHash(i) StackMacro.token[i].hash                                             //07-02-26|0x0060
#define MacroPosition(i) StackMacro.token[i].position                                     //07-02-26|0x0060
#define MacroType(i) StackMacro.token[i].type                                             //07-02-26|0x0060
#define MacroStartCol(i) StackMacro.token[i].start_col                                    //07-02-26|0x0060
#define MacroStartCall(i) StackMacro.token[i].start_call                                  //07-02-26|0x0060
#define MacroChar(i,j) StackMacro.token[i].line[j]                                        //07-02-26|0x0060
#define MacroNoTokens StackMacro.no_tokens                                                //07-02-26|0x0060
//************************************************************************                //06-07-12|0x0061
#define NameTokenAddr(i) &(StackName.token[i])                                            //06-07-12|0x0061
#define NameMacroLineNo(i) StackName.token[i].macro_line_no                               //06-07-12|0x0061
#define NameLineAddr(i) &(StackName.token[i].line[0])                                     //06-07-12|0x0061
#define NameToken(i) StackName.token[i]                                                   //06-07-12|0x0061
#define NameLine(i) StackName.token[i].line                                               //06-07-12|0x0061
#define NameLength(i) StackName.token[i].length                                           //06-07-12|0x0061
#define NameColumn(i) StackName.token[i].column                                           //06-07-12|0x0061
#define NameHash(i) StackName.token[i].hash                                               //06-07-12|0x0061
#define NamePosition(i) StackName.token[i].position                                       //06-07-12|0x0061
#define NameType(i) StackName.token[i].type                                               //06-07-12|0x0061
#define NameStartCol(i) StackName.token[i].start_col                                      //06-07-12|0x0061
#define NameStartCall(i) StackName.token[i].start_call                                    //06-07-12|0x0061
#define NameChar(i,j) StackName.token[i].line[j]                                          //06-07-12|0x0061
#define NameNoTokens StackName.no_tokens                                                  //06-07-12|0x0061
//************************************************************************                //06-07-12|0x0062
#define ElementTokenAddr(i) &(StackElement.token[i])                                      //06-07-12|0x0062
#define ElementMacroLineNo(i) StackElement.token[i].macro_line_no                         //06-07-12|0x0062
#define ElementLineAddr(i) &(StackElement.token[i].line[0])                               //06-07-12|0x0062
#define ElementToken(i) StackElement.token[i]                                             //06-07-12|0x0062
#define ElementLine(i) StackElement.token[i].line                                         //06-07-12|0x0062
#define ElementLength(i) StackElement.token[i].length                                     //06-07-12|0x0062
#define ElementColumn(i) StackElement.token[i].column                                     //06-07-12|0x0062
#define ElementHash(i) StackElement.token[i].hash                                         //06-07-12|0x0062
#define ElementPosition(i) StackElement.token[i].position                                 //06-07-12|0x0062
#define ElementType(i) StackElement.token[i].type                                         //06-07-12|0x0062
#define ElementStartCol(i) StackElement.token[i].start_col                                //06-07-12|0x0062
#define ElementStartCall(i) StackElement.token[i].start_call                              //06-07-12|0x0062
#define ElementChar(i,j) StackElement.token[i].line[j]                                    //06-07-12|0x0062
#define ElementNoTokens StackElement.no_tokens                                            //06-07-12|0x0062
//************************************************************************                //07-03-16|0x0063
#define WorkTokenAddr(i) &(StackWork.token[i])                                            //07-03-16|0x0063
#define WorkMacroLineNo(i) StackWork.token[i].macro_line_no                               //07-03-16|0x0063
#define WorkLineAddr(i) &(StackWork.token[i].line[0])                                     //07-03-16|0x0063
#define WorkToken(i) StackWork.token[i]                                                   //07-03-16|0x0063
#define WorkLine(i) StackWork.token[i].line                                               //07-03-16|0x0063
#define WorkLength(i) StackWork.token[i].length                                           //07-03-16|0x0063
#define WorkColumn(i) StackWork.token[i].column                                           //07-03-16|0x0063
#define WorkHash(i) StackWork.token[i].hash                                               //07-03-16|0x0063
#define WorkPosition(i) StackWork.token[i].position                                       //07-03-16|0x0063
#define WorkType(i) StackWork.token[i].type                                               //07-03-16|0x0063
#define WorkStartCol(i) StackWork.token[i].start_col                                      //07-03-16|0x0063
#define WorkStartCall(i) StackWork.token[i].start_call                                    //07-03-16|0x0063
#define WorkChar(i,j) StackWork.token[i].line[j]                                          //07-03-16|0x0063
#define WorkNoTokens StackWork.no_tokens                                                  //07-03-16|0x0063
//*************************************************************************               //07-03-05|0x0067
#define CurrentChar(i) NameChar(1,i)                                                      //07-03-05|0x0067
#define CurrentLength NameLength(1)                                                       //07-03-05|0x0067
#define CurrentLineAddr NameLineAddr(1)                                                   //07-03-05|0x0067
#define CurrentAddr NameTokenAddr(1)                                                      //07-03-05|0x0067
//-------------------------------------------------------------------------               //07-03-05|0x0067
#define StackLevel NameChar(2,0)                                                          //07-03-05|0x0067
#define StackLevelLength NameLength(2)                                                    //07-03-05|0x0067
#define StackLevelType NameType(2)                                                        //07-03-05|0x0067
#define StackLineAddr NameLineAddr(2)                                                     //07-03-05|0x0067
#define StackLevelAddr NameTokenAddr(2)                                                   //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define BasicMacroChar(i) MacroChar(0,i)                                                  //07-03-05|0x0067
#define BasicMacroLength MacroLength(0)                                                   //07-03-05|0x0067
#define BasicMacroLineAddr MacroLineAddr(0)                                               //07-03-05|0x0067
#define BasicMacroAddr MacroTokenAddr(0)                                                  //07-03-05|0x0067
//-------------------------------------------------------------------------               //07-03-05|0x0067
#define MacroNameChar(i) MacroChar(1,i)                                                   //07-03-05|0x0067
#define MacroNameLength MacroLength(1)                                                    //07-03-05|0x0067
#define MacroNameLineAddr MacroLineAddr(1)                                                //07-03-05|0x0067
#define MacroNameAddr MacroTokenAddr(1)                                                   //07-03-05|0x0067
//-------------------------------------------------------------------------               //07-03-05|0x0067
#define MacroDictChar(i) MacroChar(2,i)                                                   //07-03-05|0x0067
#define MacroDictLength MacroLength(2)                                                    //07-03-05|0x0067
#define MacroDictLineAddr MacroLineAddr(2)                                                //07-03-05|0x0067
#define MacroDictAddr MacroTokenAddr(2)                                                   //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define Work1Char(i) WorkChar(1,i)                                                        //07-03-05|0x0067
#define Work1Length WorkLength(1)                                                         //07-03-05|0x0067
#define Work1LineAddr WorkLineAddr(1)                                                     //07-03-05|0x0067
#define Work1Addr WorkTokenAddr(1)                                                        //07-03-05|0x0067
//-------------------------------------------------------------------------               //07-03-05|0x0067
#define Work2Char(i) WorkChar(2,i)                                                        //07-03-05|0x0067
#define Work2Length WorkLength(2)                                                         //07-03-05|0x0067
#define Work2LineAddr WorkLineAddr(2)                                                     //07-03-05|0x0067
#define Work2Addr WorkTokenAddr(2)                                                        //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define StackDictChar(i) ElementChar(1,i)                                                 //07-03-05|0x0067
#define StackDictLength ElementLength(1)                                                  //07-03-05|0x0067
#define StackDictLineAddr ElementLineAddr(1)                                              //07-03-05|0x0067
#define StackDictAddr ElementTokenAddr(1)                                                 //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define InputMacroNameAddr TokensTokenAddr(1)                                             //07-03-05|0x0067
#define InputDictNameAddr TokensTokenAddr(2)                                              //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define CurrentElementAddr ElementTokenAddr(StackRelPos)                                  //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define CopyString(i,j) copy_string(i,j)                                                  //07-03-05|0x0067
#define LoadElement(i) CopyString(CurrentElementAddr, i)                                  //07-03-05|0x0067
#define FetchElement(i) CopyString(i,CurrentElementAddr)                                  //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define TestString(i,j) test_string(i,j)                                                  //07-03-05|0x0067
#define TestElement(i) TestString(CurrentElementAddr, i)                                  //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define TestDictName(i) SrceDictExists(i)                                                 //07-03-05|0x0067
#define TestDictArg1(i) SrceDictTestData(i,1)                                             //07-03-05|0x0067
#define GetDictArg1(i,j) SrceDictGet(i,j,1)                                               //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define LoadStackLvl3 StackLevelType=I_USER_STACK                                         //07-03-05|0x0067
#define LoadStackLvl2 StackLevelLength=1                                                  //07-03-05|0x0067
#define LoadStackLvl1 StackLevel=StackAbsPosChar                                          //07-03-05|0x0067
#define LoadStackLevel LoadStackLvl1; LoadStackLvl2; LoadStackLvl3                        //07-03-05|0x0067
//-------------------------------------------------------------------------               //07-03-05|0x0067
#define TestStackLevel (StackLevel=+StackAbsPosChar) ? Yes : No                           //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define IncrTotalLevel ++StackTotalPos                                                    //07-03-05|0x0067
#define DecrTotalLevel(i) ((StackTotalPos-=i) >= 0) ? Yes : No                            //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define TotallyLevel (StackTotalPos == 0) ? Yes : No                                      //07-03-05|0x0067
//*************************************************************************               //07-03-05|0x0067
#define StackEmptyMsg Finish("Stack Is Empty")                                            //07-03-05|0x0067
#define StackAssignedMsg Finish("Already Assigned")                                       //07-03-05|0x0067
#ifndef TestIndex                                                                         //06-07-12|0x006f
#define TestIndex 0                                                                       //06-07-12|0x006f
#endif                                                                                    //06-07-12|0x006f
//------------------------------------------------------------------------                //06-07-12|0x006f
enum {  stack_allocate_1 = TestIndex };                                                   //06-07-12|0x006f
//------------------------------------------------------------------------                //06-07-12|0x006f
#undef TestIndex                                                                          //06-07-12|0x006f
#define TestIndex stack_allocate_1+1                                                      //06-07-12|0x006f
//************************************************************************                //06-07-12|0x006f
#ifndef TestIndex                                                                         //06-07-12|0x0089
#define TestIndex 0                                                                       //06-07-12|0x0089
#endif                                                                                    //06-07-12|0x0089
//------------------------------------------------------------------------                //06-07-12|0x0089
enum {  stack_free_1 = TestIndex };                                                       //06-07-12|0x0089
//------------------------------------------------------------------------                //06-07-12|0x0089
#undef TestIndex                                                                          //06-07-12|0x0089
#define TestIndex stack_free_1+1                                                          //06-07-12|0x0089
//************************************************************************                //06-07-12|0x0089
#ifndef TestIndex                                                                         //06-12-22|0x00a1
#define TestIndex 0                                                                       //06-12-22|0x00a1
#endif                                                                                    //06-12-22|0x00a1
//------------------------------------------------------------------------                //06-12-22|0x00a1
enum {  initial_1 = TestIndex };                                                          //06-12-22|0x00a1
//------------------------------------------------------------------------                //06-12-22|0x00a1
#undef TestIndex                                                                          //06-12-22|0x00a1
#define TestIndex initial_1+1                                                             //06-12-22|0x00a1
//************************************************************************                //06-12-22|0x00a1
#ifndef TestIndex                                                                         //07-03-05|0x00cd
#define TestIndex 0                                                                       //07-03-05|0x00cd
#endif                                                                                    //07-03-05|0x00cd
//------------------------------------------------------------------------                //07-03-05|0x00cd
enum {  release_1 = TestIndex };                                                          //07-03-05|0x00cd
//------------------------------------------------------------------------                //07-03-05|0x00cd
#undef TestIndex                                                                          //07-03-05|0x00cd
#define TestIndex release_1+1                                                             //07-03-05|0x00cd
//************************************************************************                //07-03-05|0x00cd
#ifndef TestIndex                                                                         //04-10-05|0x00e7
#define TestIndex 0                                                                       //04-10-05|0x00e7
#endif                                                                                    //04-10-05|0x00e7
//------------------------------------------------------------------------                //04-10-05|0x00e7
enum {  macro_begin_1 = TestIndex };                                                      //04-10-05|0x00e7
//------------------------------------------------------------------------                //04-10-05|0x00e7
#undef TestIndex                                                                          //04-10-05|0x00e7
#define TestIndex macro_begin_1+1                                                         //04-10-05|0x00e7
//************************************************************************                //04-10-05|0x00e7
#ifndef TestIndex                                                                         //07-03-19|0x0145
#define TestIndex 0                                                                       //07-03-19|0x0145
#endif                                                                                    //07-03-19|0x0145
//------------------------------------------------------------------------                //07-03-19|0x0145
enum {  register_stack_1 = TestIndex };                                                   //07-03-19|0x0145
//------------------------------------------------------------------------                //07-03-19|0x0145
#undef TestIndex                                                                          //07-03-19|0x0145
#define TestIndex register_stack_1+1                                                      //07-03-19|0x0145
//************************************************************************                //07-03-19|0x0145
#ifndef TestIndex                                                                         //04-10-05|0x01b7
#define TestIndex 0                                                                       //04-10-05|0x01b7
#endif                                                                                    //04-10-05|0x01b7
//------------------------------------------------------------------------                //04-10-05|0x01b7
enum {  macro_end_1 = TestIndex };                                                        //04-10-05|0x01b7
//------------------------------------------------------------------------                //04-10-05|0x01b7
#undef TestIndex                                                                          //04-10-05|0x01b7
#define TestIndex macro_end_1+1                                                           //04-10-05|0x01b7
//************************************************************************                //04-10-05|0x01b7
#ifndef TestIndex                                                                         //04-10-05|0x01dc
#define TestIndex 0                                                                       //04-10-05|0x01dc
#endif                                                                                    //04-10-05|0x01dc
//------------------------------------------------------------------------                //04-10-05|0x01dc
enum {  push_1 = TestIndex };                                                             //04-10-05|0x01dc
//------------------------------------------------------------------------                //04-10-05|0x01dc
#undef TestIndex                                                                          //04-10-05|0x01dc
#define TestIndex push_1+1                                                                //04-10-05|0x01dc
//************************************************************************                //04-10-05|0x01dc
#ifndef TestIndex                                                                         //07-02-25|0x022f
#define TestIndex 0                                                                       //07-02-25|0x022f
#endif                                                                                    //07-02-25|0x022f
//------------------------------------------------------------------------                //07-02-25|0x022f
enum {  pop_1 = TestIndex };                                                              //07-02-25|0x022f
//------------------------------------------------------------------------                //07-02-25|0x022f
#undef TestIndex                                                                          //07-02-25|0x022f
#define TestIndex pop_1+1                                                                 //07-02-25|0x022f
//************************************************************************                //07-02-25|0x022f
#ifndef TestIndex                                                                         //07-03-16|0x0283
#define TestIndex 0                                                                       //07-03-16|0x0283
#endif                                                                                    //07-03-16|0x0283
//------------------------------------------------------------------------                //07-03-16|0x0283
enum {  get_1 = TestIndex };                                                              //07-03-16|0x0283
//------------------------------------------------------------------------                //07-03-16|0x0283
#undef TestIndex                                                                          //07-03-16|0x0283
#define TestIndex get_1+1                                                                 //07-03-16|0x0283
//************************************************************************                //07-03-16|0x0283
#ifndef TestIndex                                                                         //07-09-13|0x02b2
#define TestIndex 0                                                                       //07-09-13|0x02b2
#endif                                                                                    //07-09-13|0x02b2
//------------------------------------------------------------------------                //07-09-13|0x02b2
enum {  stack_level_1 = TestIndex };                                                      //07-09-13|0x02b2
//------------------------------------------------------------------------                //07-09-13|0x02b2
#undef TestIndex                                                                          //07-09-13|0x02b2
#define TestIndex stack_level_1+1                                                         //07-09-13|0x02b2
//************************************************************************                //07-09-13|0x02b2
#ifndef TestIndex                                                                         //06-12-22|0x02e2
#define TestIndex 0                                                                       //06-12-22|0x02e2
#endif                                                                                    //06-12-22|0x02e2
//------------------------------------------------------------------------                //06-12-22|0x02e2
enum {  TestTokensTrue = TestIndex };                                                     //06-12-22|0x02e2
//------------------------------------------------------------------------                //06-12-22|0x02e2
#undef TestIndex                                                                          //06-12-22|0x02e2
#define TestIndex TestTokensTrue+1                                                        //06-12-22|0x02e2
//************************************************************************                //06-12-22|0x02e2
#ifndef TestIndex                                                                         //06-12-22|0x02e3
#define TestIndex 0                                                                       //06-12-22|0x02e3
#endif                                                                                    //06-12-22|0x02e3
//------------------------------------------------------------------------                //06-12-22|0x02e3
enum {  TestTokensFalse = TestIndex };                                                    //06-12-22|0x02e3
//------------------------------------------------------------------------                //06-12-22|0x02e3
#undef TestIndex                                                                          //06-12-22|0x02e3
#define TestIndex TestTokensFalse+1                                                       //06-12-22|0x02e3
//************************************************************************                //06-12-22|0x02e3
#ifndef TestIndex                                                                         //04-10-05|0x030b
#define TestIndex 0                                                                       //04-10-05|0x030b
#endif                                                                                    //04-10-05|0x030b
//------------------------------------------------------------------------                //04-10-05|0x030b
enum {  test_1 = TestIndex };                                                             //04-10-05|0x030b
//------------------------------------------------------------------------                //04-10-05|0x030b
#undef TestIndex                                                                          //04-10-05|0x030b
#define TestIndex test_1+1                                                                //04-10-05|0x030b
//************************************************************************                //04-10-05|0x030b
#ifndef TestIndex                                                                         //05-10-15|0x0349
#define TestIndex 0                                                                       //05-10-15|0x0349
#endif                                                                                    //05-10-15|0x0349
//------------------------------------------------------------------------                //05-10-15|0x0349
enum {  empty_test_1 = TestIndex };                                                       //05-10-15|0x0349
//------------------------------------------------------------------------                //05-10-15|0x0349
#undef TestIndex                                                                          //05-10-15|0x0349
#define TestIndex empty_test_1+1                                                          //05-10-15|0x0349
//************************************************************************                //05-10-15|0x0349
#ifndef TestIndex                                                                         //05-10-15|0x037a
#define TestIndex 0                                                                       //05-10-15|0x037a
#endif                                                                                    //05-10-15|0x037a
//------------------------------------------------------------------------                //05-10-15|0x037a
enum {  all_empty_test_1 = TestIndex };                                                   //05-10-15|0x037a
//------------------------------------------------------------------------                //05-10-15|0x037a
#undef TestIndex                                                                          //05-10-15|0x037a
#define TestIndex all_empty_test_1+1                                                      //05-10-15|0x037a
//************************************************************************                //05-10-15|0x037a
#ifndef TestIndex                                                                         //05-10-15|0x037b
#define TestIndex 0                                                                       //05-10-15|0x037b
#endif                                                                                    //05-10-15|0x037b
//------------------------------------------------------------------------                //05-10-15|0x037b
enum {  all_empty_test_2 = TestIndex };                                                   //05-10-15|0x037b
//------------------------------------------------------------------------                //05-10-15|0x037b
#undef TestIndex                                                                          //05-10-15|0x037b
#define TestIndex all_empty_test_2+1                                                      //05-10-15|0x037b
//************************************************************************                //05-10-15|0x037b
#ifndef TestIndex                                                                         //07-03-03|0x0393
#define TestIndex 0                                                                       //07-03-03|0x0393
#endif                                                                                    //07-03-03|0x0393
//------------------------------------------------------------------------                //07-03-03|0x0393
enum {  tab_string_1 = TestIndex };                                                       //07-03-03|0x0393
//------------------------------------------------------------------------                //07-03-03|0x0393
#undef TestIndex                                                                          //07-03-03|0x0393
#define TestIndex tab_string_1+1                                                          //07-03-03|0x0393
//************************************************************************                //07-03-03|0x0393
#ifndef TestIndex                                                                         //07-03-03|0x03b5
#define TestIndex 0                                                                       //07-03-03|0x03b5
#endif                                                                                    //07-03-03|0x03b5
//------------------------------------------------------------------------                //07-03-03|0x03b5
enum {  tab_data_1 = TestIndex };                                                         //07-03-03|0x03b5
//------------------------------------------------------------------------                //07-03-03|0x03b5
#undef TestIndex                                                                          //07-03-03|0x03b5
#define TestIndex tab_data_1+1                                                            //07-03-03|0x03b5
//************************************************************************                //07-03-03|0x03b5
#ifndef TestIndex                                                                         //07-03-05|0x03d9
#define TestIndex 0                                                                       //07-03-05|0x03d9
#endif                                                                                    //07-03-05|0x03d9
//------------------------------------------------------------------------                //07-03-05|0x03d9
enum {  store_stack_level_1 = TestIndex };                                                //07-03-05|0x03d9
//------------------------------------------------------------------------                //07-03-05|0x03d9
#undef TestIndex                                                                          //07-03-05|0x03d9
#define TestIndex store_stack_level_1+1                                                   //07-03-05|0x03d9
//************************************************************************                //07-03-05|0x03d9
#ifndef TestIndex                                                                         //07-03-03|0x03ed
#define TestIndex 0                                                                       //07-03-03|0x03ed
#endif                                                                                    //07-03-03|0x03ed
//------------------------------------------------------------------------                //07-03-03|0x03ed
enum {  no_tokens_1 = TestIndex };                                                        //07-03-03|0x03ed
//------------------------------------------------------------------------                //07-03-03|0x03ed
#undef TestIndex                                                                          //07-03-03|0x03ed
#define TestIndex no_tokens_1+1                                                           //07-03-03|0x03ed
//************************************************************************                //07-03-03|0x03ed
#ifndef TestIndex                                                                         //07-03-05|0x040b
#define TestIndex 0                                                                       //07-03-05|0x040b
#endif                                                                                    //07-03-05|0x040b
//------------------------------------------------------------------------                //07-03-05|0x040b
enum {  get_elements_1 = TestIndex };                                                     //07-03-05|0x040b
//------------------------------------------------------------------------                //07-03-05|0x040b
#undef TestIndex                                                                          //07-03-05|0x040b
#define TestIndex get_elements_1+1                                                        //07-03-05|0x040b
//************************************************************************                //07-03-05|0x040b
#ifndef TestIndex                                                                         //07-03-03|0x042c
#define TestIndex 0                                                                       //07-03-03|0x042c
#endif                                                                                    //07-03-03|0x042c
//------------------------------------------------------------------------                //07-03-03|0x042c
enum {  add_stack_level_1 = TestIndex };                                                  //07-03-03|0x042c
//------------------------------------------------------------------------                //07-03-03|0x042c
#undef TestIndex                                                                          //07-03-03|0x042c
#define TestIndex add_stack_level_1+1                                                     //07-03-03|0x042c
//************************************************************************                //07-03-03|0x042c
#ifndef TestIndex                                                                         //07-03-03|0x042d
#define TestIndex 0                                                                       //07-03-03|0x042d
#endif                                                                                    //07-03-03|0x042d
//------------------------------------------------------------------------                //07-03-03|0x042d
enum {  add_stack_level_2 = TestIndex };                                                  //07-03-03|0x042d
//------------------------------------------------------------------------                //07-03-03|0x042d
#undef TestIndex                                                                          //07-03-03|0x042d
#define TestIndex add_stack_level_2+1                                                     //07-03-03|0x042d
//************************************************************************                //07-03-03|0x042d
#ifndef TestIndex                                                                         //07-03-03|0x042e
#define TestIndex 0                                                                       //07-03-03|0x042e
#endif                                                                                    //07-03-03|0x042e
//------------------------------------------------------------------------                //07-03-03|0x042e
enum {  add_stack_level_3 = TestIndex };                                                  //07-03-03|0x042e
//------------------------------------------------------------------------                //07-03-03|0x042e
#undef TestIndex                                                                          //07-03-03|0x042e
#define TestIndex add_stack_level_3+1                                                     //07-03-03|0x042e
//************************************************************************                //07-03-03|0x042e
#ifndef TestIndex                                                                         //07-03-03|0x042f
#define TestIndex 0                                                                       //07-03-03|0x042f
#endif                                                                                    //07-03-03|0x042f
//------------------------------------------------------------------------                //07-03-03|0x042f
enum {  add_stack_level_4 = TestIndex };                                                  //07-03-03|0x042f
//------------------------------------------------------------------------                //07-03-03|0x042f
#undef TestIndex                                                                          //07-03-03|0x042f
#define TestIndex add_stack_level_4+1                                                     //07-03-03|0x042f
//************************************************************************                //07-03-03|0x042f
#ifndef TestIndex                                                                         //07-03-03|0x0430
#define TestIndex 0                                                                       //07-03-03|0x0430
#endif                                                                                    //07-03-03|0x0430
//------------------------------------------------------------------------                //07-03-03|0x0430
enum {  add_stack_level_5 = TestIndex };                                                  //07-03-03|0x0430
//------------------------------------------------------------------------                //07-03-03|0x0430
#undef TestIndex                                                                          //07-03-03|0x0430
#define TestIndex add_stack_level_5+1                                                     //07-03-03|0x0430
//************************************************************************                //07-03-03|0x0430
#ifndef TestIndex                                                                         //07-03-03|0x0467
#define TestIndex 0                                                                       //07-03-03|0x0467
#endif                                                                                    //07-03-03|0x0467
//------------------------------------------------------------------------                //07-03-03|0x0467
enum {  copy_string_1 = TestIndex };                                                      //07-03-03|0x0467
//------------------------------------------------------------------------                //07-03-03|0x0467
#undef TestIndex                                                                          //07-03-03|0x0467
#define TestIndex copy_string_1+1                                                         //07-03-03|0x0467
//************************************************************************                //07-03-03|0x0467
#ifndef TestIndex                                                                         //07-03-05|0x0485
#define TestIndex 0                                                                       //07-03-05|0x0485
#endif                                                                                    //07-03-05|0x0485
//------------------------------------------------------------------------                //07-03-05|0x0485
enum {  test_string_1 = TestIndex };                                                      //07-03-05|0x0485
//------------------------------------------------------------------------                //07-03-05|0x0485
#undef TestIndex                                                                          //07-03-05|0x0485
#define TestIndex test_string_1+1                                                         //07-03-05|0x0485
//************************************************************************                //07-03-05|0x0485
#ifndef TestIndex                                                                         //07-03-05|0x0486
#define TestIndex 0                                                                       //07-03-05|0x0486
#endif                                                                                    //07-03-05|0x0486
//------------------------------------------------------------------------                //07-03-05|0x0486
enum {  test_string_2 = TestIndex };                                                      //07-03-05|0x0486
//------------------------------------------------------------------------                //07-03-05|0x0486
#undef TestIndex                                                                          //07-03-05|0x0486
#define TestIndex test_string_2+1                                                         //07-03-05|0x0486
//************************************************************************                //07-03-05|0x0486
//*******************************************************************************         //05-24-97|0x04be
//*******************************************************************************         //05-24-97|0x04be
//****                       END OF FILE                                     ****         //05-24-97|0x04be
//*******************************************************************************         //05-24-97|0x04be
//*******************************************************************************         //05-24-97|0x04be
#endif                                                                                    //05-24-97|0x04be
