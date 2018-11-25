//*****************************************************************************           //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
// PDE TEXT EXPRESSION ROUTINES                                                           //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  Copyright: 2006 Robert H. Adams                                                       //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  The purpose of this program as well as instructions regarding its use is              //06-09-29|0x001f
//  defined in the associated manual.                                                     //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  This program is free software; you can redistribute it and/or modify                  //06-09-29|0x001f
//  it under the terms of the GNU General Public License as published by                  //06-09-29|0x001f
//  the Free Software Foundation; either version 2 of the License, or                     //06-09-29|0x001f
//  (at your option) any later version.                                                   //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
//  This program is distributed in the hope that it will be useful,                       //06-09-29|0x001f
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-09-29|0x001f
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-09-29|0x001f
//  GNU General Public License for more details.                                          //06-09-29|0x001f
//                                                                                        //06-09-29|0x001f
//  You should have received a copy of the GNU General Public License                     //06-09-29|0x001f
//  along with this program; if not, write to the Free Software                           //06-09-29|0x001f
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-09-29|0x001f
//  USA                                                                                   //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//  For further information, please contact Robert Adams:                                 //06-09-29|0x001f
//     EMail:    robert.adams@whatifwe.com                                                //06-09-29|0x001f
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-09-29|0x001f
//  Or visit the website, "www.whatifwe.com".                                             //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
//*****************************************************************************           //06-09-29|0x001f
#ifndef prectext_hpp                                                                      //05-14-97|0x0022
#define prectext_hpp                                                                      //05-14-97|0x0022
//***************************************************************************             //06-09-29|0x0028
//***************************************************************************             //06-09-29|0x0029
//******                                                               ******             //06-09-29|0x002a
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-09-29|0x002b
//******                                                               ******             //06-09-29|0x002c
//***************************************************************************             //06-09-29|0x002d
//***************************************************************************             //06-09-29|0x002e
//***************************************************************************             //06-09-29|0x0031
//***************************************************************************             //06-09-29|0x0032
//******                                                               ******             //06-09-29|0x0033
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-09-29|0x0034
//******                                                               ******             //06-09-29|0x0035
//***************************************************************************             //06-09-29|0x0036
//***************************************************************************             //06-09-29|0x0037
#define UserError 0x0000                                                                  //06-09-29|0x0038
#define BuildError 0x7fff                                                                 //06-09-29|0x0038
#define Display 0x7ffe                                                                    //06-09-29|0x0038
#define KeyBoard 0x7ffd                                                                   //06-09-29|0x0038
#define Success 0xffff                                                                    //06-09-29|0x0038
#define SystemError 0x8000                                                                //06-09-29|0x0038
#define Continue 0x0001                                                                   //06-09-29|0x0038
#define FileDone 0x0002                                                                   //06-09-29|0x0038
#define LineDone 0x0003                                                                   //06-09-29|0x0038
#define Yes 0x0004                                                                        //06-09-29|0x0038
#define No 0x0005                                                                         //06-09-29|0x0038
#define RepeatChar '\x6'                                                                  //06-09-29|0x0038
#define Great 0x0007                                                                      //06-09-29|0x0038
#define Equal 0x0008                                                                      //06-09-29|0x0038
#define Less 0x0009                                                                       //06-09-29|0x0038
#define Zero 0x000a                                                                       //06-09-29|0x0038
#define Minus 0x000b                                                                      //06-09-29|0x0038
//***************************************************************************             //06-09-29|0x0039
#define SystemMsg PcgSystemError("prectext", __LINE__);                                   //06-09-29|0x003a
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-09-29|0x003a
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //06-09-29|0x003a
#define _SwitchErr case UserError: return(UserError)                                      //06-09-29|0x003b
#define _SwitchOk case Success: break                                                     //06-09-29|0x003b
#define _SwitchEnd default: ReturnSystemError                                             //06-09-29|0x003b
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-09-29|0x003b
#define _SwitchYes case Yes:      return(Yes)                                             //06-09-29|0x003b
#define _SwitchNo case No:       return(No)                                               //06-09-29|0x003b
#define _SwitchGroup { _SwitchBase; }                                                     //06-09-29|0x003b
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-09-29|0x003b
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-09-29|0x003b
#define _SwitchBreak _SwitchGroup break                                                   //06-09-29|0x003b
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-09-29|0x003b
#define BreakFinish(_a) status = Finish(_a); break                                        //06-09-29|0x003c
#define ReturnFinish(_a) return(Finish(_a))                                               //06-09-29|0x003c
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-09-29|0x003c
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-09-29|0x003c
//***************************************************************************             //06-09-29|0x0050
//***************************************************************************             //06-09-29|0x0051
//******                                                               ******             //06-09-29|0x0052
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-09-29|0x0053
//******                                                               ******             //06-09-29|0x0054
//***************************************************************************             //06-09-29|0x0055
//***************************************************************************             //06-09-29|0x0056
#define TestSample(i) test_samples[i] = __LINE__                                          //06-09-29|0x0057
#define return_test(j) { TestSample(j);  return(Success); }                               //06-09-29|0x0057
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-09-29|0x0057
#define return_no(j) { TestSample(j);  return(No); }                                      //06-09-29|0x0057
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-09-29|0x0057
#define break_test(i) { TestSample(i);  break; }                                          //06-09-29|0x0057
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-09-29|0x0057
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-09-29|0x0057
//************************************************************************                //06-09-29|0x0057
#ifndef TestIndex                                                                         //06-09-29|0x0057
#define TestIndex 0                                                                       //06-09-29|0x0057
#endif                                                                                    //06-09-29|0x0057
//------------------------------------------------------------------------                //06-09-29|0x0057
enum {  NoTestSamples = TestIndex };                                                      //06-09-29|0x0057
//------------------------------------------------------------------------                //06-09-29|0x0057
#undef TestIndex                                                                          //06-09-29|0x0057
#define TestIndex NoTestSamples+1                                                         //06-09-29|0x0057
//************************************************************************                //06-09-29|0x0057
#define RetParm 0                                                                         //06-09-29|0x0059
#define CallParm 1                                                                        //06-09-29|0x0059
#define PermReg 10                                                                        //06-09-29|0x0059
#define OnceReg 36                                                                        //06-09-29|0x0059
#define ProjParm 62                                                                       //06-09-29|0x0059
#define CmdLnParm 72                                                                      //06-09-29|0x0059
#define ErrorParm 82                                                                      //06-09-29|0x0059
//************************************************************************                //06-09-29|0x0059
#define AddrChar(i) Addr->line[i]                                                         //06-09-29|0x005b
#define AddrLine Addr->line[0]                                                            //06-09-29|0x005b
#define AddrLineAddr &(Addr->line[0])                                                     //06-09-29|0x005b
#define AddrMacroLineNo Addr->macro_line_no                                               //06-09-29|0x005b
#define AddrType Addr->type                                                               //06-09-29|0x005b
#define AddrStartCol Addr->start_col                                                      //06-09-29|0x005b
#define AddrStartCall Addr->start_call                                                    //06-09-29|0x005b
#define AddrPosition Addr->position                                                       //06-09-29|0x005b
#define AddrLength Addr->length                                                           //06-09-29|0x005b
#define AddrColumn Addr->column                                                           //06-09-29|0x005b
//**********************************************************************                  //06-09-29|0x005b
#define SourceChar(i) Source->line[i]                                                     //06-09-29|0x005c
#define SourceLine Source->line[0]                                                        //06-09-29|0x005c
#define SourceLineAddr &(Source->line[0])                                                 //06-09-29|0x005c
#define SourceMacroLineNo Source->macro_line_no                                           //06-09-29|0x005c
#define SourceType Source->type                                                           //06-09-29|0x005c
#define SourceStartCol Source->start_col                                                  //06-09-29|0x005c
#define SourceStartCall Source->start_call                                                //06-09-29|0x005c
#define SourcePosition Source->position                                                   //06-09-29|0x005c
#define SourceLength Source->length                                                       //06-09-29|0x005c
#define SourceColumn Source->column                                                       //06-09-29|0x005c
//**********************************************************************                  //06-09-29|0x005c
//************************************************************************                //06-09-29|0x005d
#define TokenTokenAddr(i) &(TokenAddr->token[i])                                          //06-09-29|0x005d
#define TokenMacroLineNo(i) TokenAddr->token[i].macro_line_no                             //06-09-29|0x005d
#define TokenLineAddr(i) &(TokenAddr->token[i].line[0])                                   //06-09-29|0x005d
#define TokenToken(i) TokenAddr->token[i]                                                 //06-09-29|0x005d
#define TokenLine(i) TokenAddr->token[i].line                                             //06-09-29|0x005d
#define TokenLength(i) TokenAddr->token[i].length                                         //06-09-29|0x005d
#define TokenColumn(i) TokenAddr->token[i].column                                         //06-09-29|0x005d
#define TokenHash(i) TokenAddr->token[i].hash                                             //06-09-29|0x005d
#define TokenPosition(i) TokenAddr->token[i].position                                     //06-09-29|0x005d
#define TokenType(i) TokenAddr->token[i].type                                             //06-09-29|0x005d
#define TokenStartCol(i) TokenAddr->token[i].start_col                                    //06-09-29|0x005d
#define TokenStartCall(i) TokenAddr->token[i].start_call                                  //06-09-29|0x005d
#define TokenChar(i,j) TokenAddr->token[i].line[j]                                        //06-09-29|0x005d
#define TokenNoTokens TokenAddr->no_tokens                                                //06-09-29|0x005d
#define CaseNameName case 256 * I_NAME   + I_NAME                                         //06-09-29|0x005f
#define CaseTokenName case 256 * I_TOKEN  + I_NAME                                        //06-09-29|0x005f
#define CaseStringName case 256 * I_STRING + I_NAME                                       //06-09-29|0x005f
#define CaseNameToken case 256 * I_NAME   + I_TOKEN                                       //06-09-29|0x005f
#define CaseTokenToken case 256 * I_TOKEN  + I_TOKEN                                      //06-09-29|0x005f
#define CaseStringToken case 256 * I_STRING + I_TOKEN                                     //06-09-29|0x005f
#define CaseNameString case 256 * I_NAME   + I_STRING                                     //06-09-29|0x005f
#define CaseTokenString case 256 * I_TOKEN  + I_STRING                                    //06-09-29|0x005f
#define CaseStringString case 256 * I_STRING + I_STRING                                   //06-09-29|0x005f
//************************************************************************                //06-09-29|0x005f
#ifndef TestIndex                                                                         //06-09-29|0x0069
#define TestIndex 0                                                                       //06-09-29|0x0069
#endif                                                                                    //06-09-29|0x0069
//------------------------------------------------------------------------                //06-09-29|0x0069
enum {  clear_reg_1 = TestIndex };                                                        //06-09-29|0x0069
//------------------------------------------------------------------------                //06-09-29|0x0069
#undef TestIndex                                                                          //06-09-29|0x0069
#define TestIndex clear_reg_1+1                                                           //06-09-29|0x0069
//************************************************************************                //06-09-29|0x0069
#ifndef TestIndex                                                                         //06-09-30|0x008a
#define TestIndex 0                                                                       //06-09-30|0x008a
#endif                                                                                    //06-09-30|0x008a
//------------------------------------------------------------------------                //06-09-30|0x008a
enum {  test_parm_1 = TestIndex };                                                        //06-09-30|0x008a
//------------------------------------------------------------------------                //06-09-30|0x008a
#undef TestIndex                                                                          //06-09-30|0x008a
#define TestIndex test_parm_1+1                                                           //06-09-30|0x008a
//************************************************************************                //06-09-30|0x008a
#ifndef TestIndex                                                                         //06-09-30|0x008b
#define TestIndex 0                                                                       //06-09-30|0x008b
#endif                                                                                    //06-09-30|0x008b
//------------------------------------------------------------------------                //06-09-30|0x008b
enum {  test_parm_2 = TestIndex };                                                        //06-09-30|0x008b
//------------------------------------------------------------------------                //06-09-30|0x008b
#undef TestIndex                                                                          //06-09-30|0x008b
#define TestIndex test_parm_2+1                                                           //06-09-30|0x008b
//************************************************************************                //06-09-30|0x008b
#ifndef TestIndex                                                                         //06-09-30|0x008c
#define TestIndex 0                                                                       //06-09-30|0x008c
#endif                                                                                    //06-09-30|0x008c
//------------------------------------------------------------------------                //06-09-30|0x008c
enum {  test_parm_3 = TestIndex };                                                        //06-09-30|0x008c
//------------------------------------------------------------------------                //06-09-30|0x008c
#undef TestIndex                                                                          //06-09-30|0x008c
#define TestIndex test_parm_3+1                                                           //06-09-30|0x008c
//************************************************************************                //06-09-30|0x008c
#ifndef TestIndex                                                                         //06-09-30|0x008d
#define TestIndex 0                                                                       //06-09-30|0x008d
#endif                                                                                    //06-09-30|0x008d
//------------------------------------------------------------------------                //06-09-30|0x008d
enum {  test_parm_4 = TestIndex };                                                        //06-09-30|0x008d
//------------------------------------------------------------------------                //06-09-30|0x008d
#undef TestIndex                                                                          //06-09-30|0x008d
#define TestIndex test_parm_4+1                                                           //06-09-30|0x008d
//************************************************************************                //06-09-30|0x008d
#ifndef TestIndex                                                                         //06-09-28|0x00be
#define TestIndex 0                                                                       //06-09-28|0x00be
#endif                                                                                    //06-09-28|0x00be
//------------------------------------------------------------------------                //06-09-28|0x00be
enum {  store_reg_1 = TestIndex };                                                        //06-09-28|0x00be
//------------------------------------------------------------------------                //06-09-28|0x00be
#undef TestIndex                                                                          //06-09-28|0x00be
#define TestIndex store_reg_1+1                                                           //06-09-28|0x00be
//************************************************************************                //06-09-28|0x00be
#ifndef TestIndex                                                                         //06-09-28|0x00bf
#define TestIndex 0                                                                       //06-09-28|0x00bf
#endif                                                                                    //06-09-28|0x00bf
//------------------------------------------------------------------------                //06-09-28|0x00bf
enum {  store_reg_2 = TestIndex };                                                        //06-09-28|0x00bf
//------------------------------------------------------------------------                //06-09-28|0x00bf
#undef TestIndex                                                                          //06-09-28|0x00bf
#define TestIndex store_reg_2+1                                                           //06-09-28|0x00bf
//************************************************************************                //06-09-28|0x00bf
#ifndef TestIndex                                                                         //06-09-29|0x00e7
#define TestIndex 0                                                                       //06-09-29|0x00e7
#endif                                                                                    //06-09-29|0x00e7
//------------------------------------------------------------------------                //06-09-29|0x00e7
enum {  read_reg_1 = TestIndex };                                                         //06-09-29|0x00e7
//------------------------------------------------------------------------                //06-09-29|0x00e7
#undef TestIndex                                                                          //06-09-29|0x00e7
#define TestIndex read_reg_1+1                                                            //06-09-29|0x00e7
//************************************************************************                //06-09-29|0x00e7
#ifndef TestIndex                                                                         //06-07-22|0x0106
#define TestIndex 0                                                                       //06-07-22|0x0106
#endif                                                                                    //06-07-22|0x0106
//------------------------------------------------------------------------                //06-07-22|0x0106
enum {  prepare_tokens_1 = TestIndex };                                                   //06-07-22|0x0106
//------------------------------------------------------------------------                //06-07-22|0x0106
#undef TestIndex                                                                          //06-07-22|0x0106
#define TestIndex prepare_tokens_1+1                                                      //06-07-22|0x0106
//************************************************************************                //06-07-22|0x0106
#ifndef TestIndex                                                                         //04-11-14|0x012b
#define TestIndex 0                                                                       //04-11-14|0x012b
#endif                                                                                    //04-11-14|0x012b
//------------------------------------------------------------------------                //04-11-14|0x012b
enum {  text_prepare_1 = TestIndex };                                                     //04-11-14|0x012b
//------------------------------------------------------------------------                //04-11-14|0x012b
#undef TestIndex                                                                          //04-11-14|0x012b
#define TestIndex text_prepare_1+1                                                        //04-11-14|0x012b
//************************************************************************                //04-11-14|0x012b
#ifndef TestIndex                                                                         //04-10-05|0x0143
#define TestIndex 0                                                                       //04-10-05|0x0143
#endif                                                                                    //04-10-05|0x0143
//------------------------------------------------------------------------                //04-10-05|0x0143
enum {  AssembleText1 = TestIndex };                                                      //04-10-05|0x0143
//------------------------------------------------------------------------                //04-10-05|0x0143
#undef TestIndex                                                                          //04-10-05|0x0143
#define TestIndex AssembleText1+1                                                         //04-10-05|0x0143
//************************************************************************                //04-10-05|0x0143
#ifndef TestIndex                                                                         //04-10-05|0x0144
#define TestIndex 0                                                                       //04-10-05|0x0144
#endif                                                                                    //04-10-05|0x0144
//------------------------------------------------------------------------                //04-10-05|0x0144
enum {  AssembleText2 = TestIndex };                                                      //04-10-05|0x0144
//------------------------------------------------------------------------                //04-10-05|0x0144
#undef TestIndex                                                                          //04-10-05|0x0144
#define TestIndex AssembleText2+1                                                         //04-10-05|0x0144
//************************************************************************                //04-10-05|0x0144
#ifndef TestIndex                                                                         //04-10-05|0x0145
#define TestIndex 0                                                                       //04-10-05|0x0145
#endif                                                                                    //04-10-05|0x0145
//------------------------------------------------------------------------                //04-10-05|0x0145
enum {  AssembleText3 = TestIndex };                                                      //04-10-05|0x0145
//------------------------------------------------------------------------                //04-10-05|0x0145
#undef TestIndex                                                                          //04-10-05|0x0145
#define TestIndex AssembleText3+1                                                         //04-10-05|0x0145
//************************************************************************                //04-10-05|0x0145
#ifndef TestIndex                                                                         //04-10-05|0x0146
#define TestIndex 0                                                                       //04-10-05|0x0146
#endif                                                                                    //04-10-05|0x0146
//------------------------------------------------------------------------                //04-10-05|0x0146
enum {  AssembleText5 = TestIndex };                                                      //04-10-05|0x0146
//------------------------------------------------------------------------                //04-10-05|0x0146
#undef TestIndex                                                                          //04-10-05|0x0146
#define TestIndex AssembleText5+1                                                         //04-10-05|0x0146
//************************************************************************                //04-10-05|0x0146
#ifndef TestIndex                                                                         //04-10-05|0x0147
#define TestIndex 0                                                                       //04-10-05|0x0147
#endif                                                                                    //04-10-05|0x0147
//------------------------------------------------------------------------                //04-10-05|0x0147
enum {  AssembleText6 = TestIndex };                                                      //04-10-05|0x0147
//------------------------------------------------------------------------                //04-10-05|0x0147
#undef TestIndex                                                                          //04-10-05|0x0147
#define TestIndex AssembleText6+1                                                         //04-10-05|0x0147
//************************************************************************                //04-10-05|0x0147
#ifndef TestIndex                                                                         //04-10-05|0x0187
#define TestIndex 0                                                                       //04-10-05|0x0187
#endif                                                                                    //04-10-05|0x0187
//------------------------------------------------------------------------                //04-10-05|0x0187
enum {  ArgumentCopy1 = TestIndex };                                                      //04-10-05|0x0187
//------------------------------------------------------------------------                //04-10-05|0x0187
#undef TestIndex                                                                          //04-10-05|0x0187
#define TestIndex ArgumentCopy1+1                                                         //04-10-05|0x0187
//************************************************************************                //04-10-05|0x0187
#ifndef TestIndex                                                                         //04-10-05|0x0188
#define TestIndex 0                                                                       //04-10-05|0x0188
#endif                                                                                    //04-10-05|0x0188
//------------------------------------------------------------------------                //04-10-05|0x0188
enum {  ArgumentCopy2 = TestIndex };                                                      //04-10-05|0x0188
//------------------------------------------------------------------------                //04-10-05|0x0188
#undef TestIndex                                                                          //04-10-05|0x0188
#define TestIndex ArgumentCopy2+1                                                         //04-10-05|0x0188
//************************************************************************                //04-10-05|0x0188
#ifndef TestIndex                                                                         //04-10-05|0x0189
#define TestIndex 0                                                                       //04-10-05|0x0189
#endif                                                                                    //04-10-05|0x0189
//------------------------------------------------------------------------                //04-10-05|0x0189
enum {  ArgumentCopy3 = TestIndex };                                                      //04-10-05|0x0189
//------------------------------------------------------------------------                //04-10-05|0x0189
#undef TestIndex                                                                          //04-10-05|0x0189
#define TestIndex ArgumentCopy3+1                                                         //04-10-05|0x0189
//************************************************************************                //04-10-05|0x0189
#ifndef TestIndex                                                                         //04-10-05|0x018a
#define TestIndex 0                                                                       //04-10-05|0x018a
#endif                                                                                    //04-10-05|0x018a
//------------------------------------------------------------------------                //04-10-05|0x018a
enum {  ArgumentCopy4 = TestIndex };                                                      //04-10-05|0x018a
//------------------------------------------------------------------------                //04-10-05|0x018a
#undef TestIndex                                                                          //04-10-05|0x018a
#define TestIndex ArgumentCopy4+1                                                         //04-10-05|0x018a
//************************************************************************                //04-10-05|0x018a
#ifndef TestIndex                                                                         //04-10-05|0x018b
#define TestIndex 0                                                                       //04-10-05|0x018b
#endif                                                                                    //04-10-05|0x018b
//------------------------------------------------------------------------                //04-10-05|0x018b
enum {  ArgumentCopy5 = TestIndex };                                                      //04-10-05|0x018b
//------------------------------------------------------------------------                //04-10-05|0x018b
#undef TestIndex                                                                          //04-10-05|0x018b
#define TestIndex ArgumentCopy5+1                                                         //04-10-05|0x018b
//************************************************************************                //04-10-05|0x018b
#ifndef TestIndex                                                                         //04-10-05|0x018c
#define TestIndex 0                                                                       //04-10-05|0x018c
#endif                                                                                    //04-10-05|0x018c
//------------------------------------------------------------------------                //04-10-05|0x018c
enum {  ArgumentCopy6 = TestIndex };                                                      //04-10-05|0x018c
//------------------------------------------------------------------------                //04-10-05|0x018c
#undef TestIndex                                                                          //04-10-05|0x018c
#define TestIndex ArgumentCopy6+1                                                         //04-10-05|0x018c
//************************************************************************                //04-10-05|0x018c
#ifndef TestIndex                                                                         //05-04-06|0x01d4
#define TestIndex 0                                                                       //05-04-06|0x01d4
#endif                                                                                    //05-04-06|0x01d4
//------------------------------------------------------------------------                //05-04-06|0x01d4
enum {  GetParm_1 = TestIndex };                                                          //05-04-06|0x01d4
//------------------------------------------------------------------------                //05-04-06|0x01d4
#undef TestIndex                                                                          //05-04-06|0x01d4
#define TestIndex GetParm_1+1                                                             //05-04-06|0x01d4
//************************************************************************                //05-04-06|0x01d4
#ifndef TestIndex                                                                         //05-06-06|0x0201
#define TestIndex 0                                                                       //05-06-06|0x0201
#endif                                                                                    //05-06-06|0x0201
//------------------------------------------------------------------------                //05-06-06|0x0201
enum {  check_type_1 = TestIndex };                                                       //05-06-06|0x0201
//------------------------------------------------------------------------                //05-06-06|0x0201
#undef TestIndex                                                                          //05-06-06|0x0201
#define TestIndex check_type_1+1                                                          //05-06-06|0x0201
//************************************************************************                //05-06-06|0x0201
//*******************************************************************************         //05-24-97|0x023f
//*******************************************************************************         //05-24-97|0x023f
//****                       END OF FILE                                     ****         //05-24-97|0x023f
//*******************************************************************************         //05-24-97|0x023f
//*******************************************************************************         //05-24-97|0x023f
#endif                                                                                    //05-24-97|0x023f
