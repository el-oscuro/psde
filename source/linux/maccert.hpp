//*****************************************************************************           //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
// MACRO VERSION MANAGER                                                                  //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  The purpose of this program as well as instructions regarding its use is              //11-02-12|0x000b
//  defined in the associated manual.                                                     //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  This program is free software; you can redistribute it and/or modify                  //11-02-12|0x000b
//  it under the terms of the GNU General Public License as published by                  //11-02-12|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //11-02-12|0x000b
//  (at your option) any later version.                                                   //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
//  This program is distributed in the hope that it will be useful,                       //11-02-12|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //11-02-12|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //11-02-12|0x000b
//  GNU General Public License for more details.                                          //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
//  You should have received a copy of the GNU General Public License                     //11-02-12|0x000b
//  along with this program; if not, write to the Free Software                           //11-02-12|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //11-02-12|0x000b
//  USA                                                                                   //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  For further information, please contact Robert Adams:                                 //11-02-12|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //11-02-12|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //11-02-12|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
#ifndef maccert_hpp                                                                       //11-02-12|0x000c
#define maccert_hpp                                                                       //11-02-12|0x000c
//***************************************************************************             //11-02-12|0x0012
//***************************************************************************             //11-02-12|0x0013
//******                                                               ******             //11-02-12|0x0014
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //11-02-12|0x0015
//******                                                               ******             //11-02-12|0x0016
//***************************************************************************             //11-02-12|0x0017
//***************************************************************************             //11-02-12|0x0018
#define CMK_EXTENT ".cmk"                                                                 //11-02-12|0x001b
#define TMK_EXTENT ".tmk"                                                                 //11-02-12|0x001b
#define RPT_EXTENT ".rpt"                                                                 //11-02-12|0x001b
#define PMK_EXTENT ".pmk"                                                                 //11-02-12|0x001b
#define MAC_EXTENT ".mac"                                                                 //11-02-12|0x001b
#define SRC_EXTENT ".src"                                                                 //11-02-12|0x001b
#define PLB_EXTENT ".plb"                                                                 //11-02-12|0x001b
#define DIC_EXTENT ".dic"                                                                 //11-02-12|0x001b
#define MBX_EXTENT ".mbx"                                                                 //11-02-12|0x001b
#define MBC_EXTENT ".mbc"                                                                 //11-02-12|0x001b
#define RAN_EXTENT ".ran"                                                                 //11-02-12|0x001b
#define BUF_OUT_EXTENT ".bfo"                                                             //11-02-12|0x001b
#define BUF_IN_EXTENT ".bfi"                                                              //11-02-12|0x001b
//***************************************************************************             //11-02-12|0x001c
//***************************************************************************             //11-02-12|0x001d
//******                                                               ******             //11-02-12|0x001e
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //11-02-12|0x001f
//******                                                               ******             //11-02-12|0x0020
//***************************************************************************             //11-02-12|0x0021
//***************************************************************************             //11-02-12|0x0022
#define UserError 0x0000                                                                  //11-02-12|0x0023
#define BuildError 0x7fff                                                                 //11-02-12|0x0023
#define Display 0x7ffe                                                                    //11-02-12|0x0023
#define KeyBoard 0x7ffd                                                                   //11-02-12|0x0023
#define Success 0xffff                                                                    //11-02-12|0x0023
#define SystemError 0x8000                                                                //11-02-12|0x0023
#define Continue 0x0001                                                                   //11-02-12|0x0023
#define FileDone 0x0002                                                                   //11-02-12|0x0023
#define LineDone 0x0003                                                                   //11-02-12|0x0023
#define Yes 0x0004                                                                        //11-02-12|0x0023
#define No 0x0005                                                                         //11-02-12|0x0023
#define RepeatChar '\x6'                                                                  //11-02-12|0x0023
#define Great 0x0007                                                                      //11-02-12|0x0023
#define Equal 0x0008                                                                      //11-02-12|0x0023
#define Less 0x0009                                                                       //11-02-12|0x0023
#define Zero 0x000a                                                                       //11-02-12|0x0023
#define Minus 0x000b                                                                      //11-02-12|0x0023
//***************************************************************************             //11-02-12|0x0024
#define SystemMsg PcgSystemError("MacCert", __LINE__);                                    //11-02-12|0x0025
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //11-02-12|0x0025
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //11-02-12|0x0025
#define BreakFinish(_a) status = Finish(_a); break                                        //11-02-12|0x0026
#define ReturnFinish(_a) return(Finish(_a))                                               //11-02-12|0x0026
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //11-02-12|0x0026
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //11-02-12|0x0026
#define _SwitchErr case UserError: return(UserError)                                      //11-02-12|0x0027
#define _SwitchOk case Success: break                                                     //11-02-12|0x0027
#define _SwitchEnd default: ReturnSystemError                                             //11-02-12|0x0027
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //11-02-12|0x0027
#define _SwitchYes case Yes:      return(Yes)                                             //11-02-12|0x0027
#define _SwitchNo case No:       return(No)                                               //11-02-12|0x0027
#define _SwitchGroup { _SwitchBase; }                                                     //11-02-12|0x0027
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //11-02-12|0x0027
#define _SwitchReturn _SwitchGroup return(Success)                                        //11-02-12|0x0027
#define _SwitchBreak _SwitchGroup break                                                   //11-02-12|0x0027
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //11-02-12|0x0027
//***************************************************************************             //11-02-12|0x0042
//***************************************************************************             //11-02-12|0x0043
//******                                                               ******             //11-02-12|0x0044
//******               GENERAL DEFINITION STATEMENTS                   ******             //11-02-12|0x0045
//******                                                               ******             //11-02-12|0x0046
//***************************************************************************             //11-02-12|0x0047
//***************************************************************************             //11-02-12|0x0048
#define TestSample(i) test_samples[i] = __LINE__                                          //11-02-12|0x0049
#define return_test(j) { TestSample(j);  return(Success); }                               //11-02-12|0x0049
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //11-02-12|0x0049
#define return_no(j) { TestSample(j);  return(No); }                                      //11-02-12|0x0049
#define return_cont(j) { TestSample(j);  return(Continue); }                              //11-02-12|0x0049
#define return_line(j) { TestSample(j);  return(LineDone); }                              //11-02-12|0x0049
#define goto_test(i) { TestSample(i);  goto loop; }                                       //11-02-12|0x0049
#define break_test(i) { TestSample(i);  break; }                                          //11-02-12|0x0049
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //11-02-12|0x0049
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //11-02-12|0x0049
//************************************************************************                //11-02-12|0x0049
#ifndef TestIndex                                                                         //11-02-12|0x0049
#define TestIndex 0                                                                       //11-02-12|0x0049
#endif                                                                                    //11-02-12|0x0049
//------------------------------------------------------------------------                //11-02-12|0x0049
enum {  NoTestSamples = TestIndex };                                                      //11-02-12|0x0049
//------------------------------------------------------------------------                //11-02-12|0x0049
#undef TestIndex                                                                          //11-02-12|0x0049
#define TestIndex NoTestSamples+1                                                         //11-02-12|0x0049
//************************************************************************                //11-02-12|0x0049
//***************************************************************************             //11-02-12|0x004a
//**********************************************************************                  //11-02-12|0x004b
#define MacCertPrevious mac_cert_data.previous                                            //11-02-12|0x004b
#define MacCertCAppend mac_cert_data.append                                               //11-02-12|0x004b
#define MacCertCurrent mac_cert_data.current                                              //11-02-12|0x004b
#define MacCertCurrentTime mac_cert_data.current_time                                     //11-02-12|0x004b
#define MacCertBaseRandom mac_cert_data.base_random                                       //11-02-12|0x004b
#define MacCertGlobalRandom mac_cert_data.global_random                                   //11-02-12|0x004b
#define MacCertCurrentRandom mac_cert_data.current_random                                 //11-02-12|0x004b
#define MacCertNoAppends mac_cert_data.no_appends                                         //11-02-12|0x004b
#define MacCertNoMacros mac_cert_data.no_macros                                           //11-02-12|0x004b
#define MacCertNoCommands mac_cert_data.no_commands                                       //11-02-12|0x004b
#define MacCertNoTodays mac_cert_data.no_todays                                           //11-02-12|0x004b
#define MacCertNoArrows mac_cert_data.no_arrows                                           //11-02-12|0x004b
//----------------------------------------------------------------------                  //11-02-12|0x004b
#define MacCertPreviousAddr &(mac_cert_data.previous)                                     //11-02-12|0x004b
#define MacCertCurrentAddr &(mac_cert_data.current)                                       //11-02-12|0x004b
#define PreviousChar(i) MacCertPrevious.line[i]                                           //11-02-12|0x004c
#define PreviousLine MacCertPrevious.line[0]                                              //11-02-12|0x004c
#define PreviousLineAddr &(MacCertPrevious.line[0])                                       //11-02-12|0x004c
#define PreviousMacroLineNo MacCertPrevious.macro_line_no                                 //11-02-12|0x004c
#define PreviousType MacCertPrevious.type                                                 //11-02-12|0x004c
#define PreviousStartCol MacCertPrevious.start_col                                        //11-02-12|0x004c
#define PreviousStartCall MacCertPrevious.start_call                                      //11-02-12|0x004c
#define PreviousPosition MacCertPrevious.position                                         //11-02-12|0x004c
#define PreviousLength MacCertPrevious.length                                             //11-02-12|0x004c
#define PreviousColumn MacCertPrevious.column                                             //11-02-12|0x004c
//**********************************************************************                  //11-02-12|0x004c
#define CurrentChar(i) MacCertCurrent.line[i]                                             //11-02-12|0x004d
#define CurrentLine MacCertCurrent.line[0]                                                //11-02-12|0x004d
#define CurrentLineAddr &(MacCertCurrent.line[0])                                         //11-02-12|0x004d
#define CurrentMacroLineNo MacCertCurrent.macro_line_no                                   //11-02-12|0x004d
#define CurrentType MacCertCurrent.type                                                   //11-02-12|0x004d
#define CurrentStartCol MacCertCurrent.start_col                                          //11-02-12|0x004d
#define CurrentStartCall MacCertCurrent.start_call                                        //11-02-12|0x004d
#define CurrentPosition MacCertCurrent.position                                           //11-02-12|0x004d
#define CurrentLength MacCertCurrent.length                                               //11-02-12|0x004d
#define CurrentColumn MacCertCurrent.column                                               //11-02-12|0x004d
//**********************************************************************                  //11-02-12|0x004d
//***************************************************************************             //11-02-12|0x004e
//************************************************************************                //11-02-12|0x004f
#define TokenTokenAddr(i) &(Token->token[i])                                              //11-02-12|0x004f
#define TokenMacroLineNo(i) Token->token[i].macro_line_no                                 //11-02-12|0x004f
#define TokenLineAddr(i) &(Token->token[i].line[0])                                       //11-02-12|0x004f
#define TokenToken(i) Token->token[i]                                                     //11-02-12|0x004f
#define TokenLine(i) Token->token[i].line                                                 //11-02-12|0x004f
#define TokenLength(i) Token->token[i].length                                             //11-02-12|0x004f
#define TokenColumn(i) Token->token[i].column                                             //11-02-12|0x004f
#define TokenHash(i) Token->token[i].hash                                                 //11-02-12|0x004f
#define TokenPosition(i) Token->token[i].position                                         //11-02-12|0x004f
#define TokenType(i) Token->token[i].type                                                 //11-02-12|0x004f
#define TokenStartCol(i) Token->token[i].start_col                                        //11-02-12|0x004f
#define TokenStartCall(i) Token->token[i].start_call                                      //11-02-12|0x004f
#define TokenChar(i,j) Token->token[i].line[j]                                            //11-02-12|0x004f
#define TokenNoTokens Token->no_tokens                                                    //11-02-12|0x004f
#define StringChar(i) String->line[i]                                                     //11-02-12|0x0050
#define StringLine String->line[0]                                                        //11-02-12|0x0050
#define StringLineAddr &(String->line[0])                                                 //11-02-12|0x0050
#define StringMacroLineNo String->macro_line_no                                           //11-02-12|0x0050
#define StringType String->type                                                           //11-02-12|0x0050
#define StringStartCol String->start_col                                                  //11-02-12|0x0050
#define StringStartCall String->start_call                                                //11-02-12|0x0050
#define StringPosition String->position                                                   //11-02-12|0x0050
#define StringLength String->length                                                       //11-02-12|0x0050
#define StringColumn String->column                                                       //11-02-12|0x0050
//**********************************************************************                  //11-02-12|0x0050
#define WorkChar(i) work.line[i]                                                          //11-02-12|0x0051
#define WorkLine work.line[0]                                                             //11-02-12|0x0051
#define WorkLineAddr &(work.line[0])                                                      //11-02-12|0x0051
#define WorkMacroLineNo work.macro_line_no                                                //11-02-12|0x0051
#define WorkType work.type                                                                //11-02-12|0x0051
#define WorkStartCol work.start_col                                                       //11-02-12|0x0051
#define WorkStartCall work.start_call                                                     //11-02-12|0x0051
#define WorkPosition work.position                                                        //11-02-12|0x0051
#define WorkLength work.length                                                            //11-02-12|0x0051
#define WorkColumn work.column                                                            //11-02-12|0x0051
//**********************************************************************                  //11-02-12|0x0051
#ifndef TestIndex                                                                         //11-02-19|0x005b
#define TestIndex 0                                                                       //11-02-19|0x005b
#endif                                                                                    //11-02-19|0x005b
//------------------------------------------------------------------------                //11-02-19|0x005b
enum {  mac_cert_create_1 = TestIndex };                                                  //11-02-19|0x005b
//------------------------------------------------------------------------                //11-02-19|0x005b
#undef TestIndex                                                                          //11-02-19|0x005b
#define TestIndex mac_cert_create_1+1                                                     //11-02-19|0x005b
//************************************************************************                //11-02-19|0x005b
#ifndef TestIndex                                                                         //11-02-19|0x0072
#define TestIndex 0                                                                       //11-02-19|0x0072
#endif                                                                                    //11-02-19|0x0072
//------------------------------------------------------------------------                //11-02-19|0x0072
enum {  mac_cert_initial_1 = TestIndex };                                                 //11-02-19|0x0072
//------------------------------------------------------------------------                //11-02-19|0x0072
#undef TestIndex                                                                          //11-02-19|0x0072
#define TestIndex mac_cert_initial_1+1                                                    //11-02-19|0x0072
//************************************************************************                //11-02-19|0x0072
#ifndef TestIndex                                                                         //11-02-14|0x0099
#define TestIndex 0                                                                       //11-02-14|0x0099
#endif                                                                                    //11-02-14|0x0099
//------------------------------------------------------------------------                //11-02-14|0x0099
enum {  mac_cert_delete_1 = TestIndex };                                                  //11-02-14|0x0099
//------------------------------------------------------------------------                //11-02-14|0x0099
#undef TestIndex                                                                          //11-02-14|0x0099
#define TestIndex mac_cert_delete_1+1                                                     //11-02-14|0x0099
//************************************************************************                //11-02-14|0x0099
#ifndef TestIndex                                                                         //11-02-19|0x00b0
#define TestIndex 0                                                                       //11-02-19|0x00b0
#endif                                                                                    //11-02-19|0x00b0
//------------------------------------------------------------------------                //11-02-19|0x00b0
enum {  mac_cert_get_prev_1 = TestIndex };                                                //11-02-19|0x00b0
//------------------------------------------------------------------------                //11-02-19|0x00b0
#undef TestIndex                                                                          //11-02-19|0x00b0
#define TestIndex mac_cert_get_prev_1+1                                                   //11-02-19|0x00b0
//************************************************************************                //11-02-19|0x00b0
#ifndef TestIndex                                                                         //11-02-22|0x00c7
#define TestIndex 0                                                                       //11-02-22|0x00c7
#endif                                                                                    //11-02-22|0x00c7
//------------------------------------------------------------------------                //11-02-22|0x00c7
enum {  mac_cert_append_1 = TestIndex };                                                  //11-02-22|0x00c7
//------------------------------------------------------------------------                //11-02-22|0x00c7
#undef TestIndex                                                                          //11-02-22|0x00c7
#define TestIndex mac_cert_append_1+1                                                     //11-02-22|0x00c7
//************************************************************************                //11-02-22|0x00c7
#ifndef TestIndex                                                                         //11-02-22|0x00c8
#define TestIndex 0                                                                       //11-02-22|0x00c8
#endif                                                                                    //11-02-22|0x00c8
//------------------------------------------------------------------------                //11-02-22|0x00c8
enum {  mac_cert_append_2 = TestIndex };                                                  //11-02-22|0x00c8
//------------------------------------------------------------------------                //11-02-22|0x00c8
#undef TestIndex                                                                          //11-02-22|0x00c8
#define TestIndex mac_cert_append_2+1                                                     //11-02-22|0x00c8
//************************************************************************                //11-02-22|0x00c8
#ifndef TestIndex                                                                         //11-02-22|0x00c9
#define TestIndex 0                                                                       //11-02-22|0x00c9
#endif                                                                                    //11-02-22|0x00c9
//------------------------------------------------------------------------                //11-02-22|0x00c9
enum {  mac_cert_append_3 = TestIndex };                                                  //11-02-22|0x00c9
//------------------------------------------------------------------------                //11-02-22|0x00c9
#undef TestIndex                                                                          //11-02-22|0x00c9
#define TestIndex mac_cert_append_3+1                                                     //11-02-22|0x00c9
//************************************************************************                //11-02-22|0x00c9
#ifndef TestIndex                                                                         //11-02-13|0x0109
#define TestIndex 0                                                                       //11-02-13|0x0109
#endif                                                                                    //11-02-13|0x0109
//------------------------------------------------------------------------                //11-02-13|0x0109
enum {  mac_cert_macro_begin_1 = TestIndex };                                             //11-02-13|0x0109
//------------------------------------------------------------------------                //11-02-13|0x0109
#undef TestIndex                                                                          //11-02-13|0x0109
#define TestIndex mac_cert_macro_begin_1+1                                                //11-02-13|0x0109
//************************************************************************                //11-02-13|0x0109
#ifndef TestIndex                                                                         //11-02-15|0x0135
#define TestIndex 0                                                                       //11-02-15|0x0135
#endif                                                                                    //11-02-15|0x0135
//------------------------------------------------------------------------                //11-02-15|0x0135
enum {  mac_cert_parity_command_1 = TestIndex };                                          //11-02-15|0x0135
//------------------------------------------------------------------------                //11-02-15|0x0135
#undef TestIndex                                                                          //11-02-15|0x0135
#define TestIndex mac_cert_parity_command_1+1                                             //11-02-15|0x0135
//************************************************************************                //11-02-15|0x0135
#ifndef TestIndex                                                                         //11-02-18|0x015a
#define TestIndex 0                                                                       //11-02-18|0x015a
#endif                                                                                    //11-02-18|0x015a
//------------------------------------------------------------------------                //11-02-18|0x015a
enum {  mac_cert_parity_arrow_1 = TestIndex };                                            //11-02-18|0x015a
//------------------------------------------------------------------------                //11-02-18|0x015a
#undef TestIndex                                                                          //11-02-18|0x015a
#define TestIndex mac_cert_parity_arrow_1+1                                               //11-02-18|0x015a
//************************************************************************                //11-02-18|0x015a
#ifndef TestIndex                                                                         //11-02-15|0x017e
#define TestIndex 0                                                                       //11-02-15|0x017e
#endif                                                                                    //11-02-15|0x017e
//------------------------------------------------------------------------                //11-02-15|0x017e
enum {  mac_cert_parity_time_1 = TestIndex };                                             //11-02-15|0x017e
//------------------------------------------------------------------------                //11-02-15|0x017e
#undef TestIndex                                                                          //11-02-15|0x017e
#define TestIndex mac_cert_parity_time_1+1                                                //11-02-15|0x017e
//************************************************************************                //11-02-15|0x017e
#ifndef TestIndex                                                                         //11-02-17|0x01d0
#define TestIndex 0                                                                       //11-02-17|0x01d0
#endif                                                                                    //11-02-17|0x01d0
//------------------------------------------------------------------------                //11-02-17|0x01d0
enum {  mac_cert_end_1 = TestIndex };                                                     //11-02-17|0x01d0
//------------------------------------------------------------------------                //11-02-17|0x01d0
#undef TestIndex                                                                          //11-02-17|0x01d0
#define TestIndex mac_cert_end_1+1                                                        //11-02-17|0x01d0
//************************************************************************                //11-02-17|0x01d0
#ifndef TestIndex                                                                         //11-02-14|0x01f6
#define TestIndex 0                                                                       //11-02-14|0x01f6
#endif                                                                                    //11-02-14|0x01f6
//------------------------------------------------------------------------                //11-02-14|0x01f6
enum {  mac_cert_finish_1 = TestIndex };                                                  //11-02-14|0x01f6
//------------------------------------------------------------------------                //11-02-14|0x01f6
#undef TestIndex                                                                          //11-02-14|0x01f6
#define TestIndex mac_cert_finish_1+1                                                     //11-02-14|0x01f6
//************************************************************************                //11-02-14|0x01f6
#ifndef TestIndex                                                                         //11-02-14|0x01f7
#define TestIndex 0                                                                       //11-02-14|0x01f7
#endif                                                                                    //11-02-14|0x01f7
//------------------------------------------------------------------------                //11-02-14|0x01f7
enum {  mac_cert_finish_2 = TestIndex };                                                  //11-02-14|0x01f7
//------------------------------------------------------------------------                //11-02-14|0x01f7
#undef TestIndex                                                                          //11-02-14|0x01f7
#define TestIndex mac_cert_finish_2+1                                                     //11-02-14|0x01f7
//************************************************************************                //11-02-14|0x01f7
#ifndef TestIndex                                                                         //11-02-14|0x01f8
#define TestIndex 0                                                                       //11-02-14|0x01f8
#endif                                                                                    //11-02-14|0x01f8
//------------------------------------------------------------------------                //11-02-14|0x01f8
enum {  mac_cert_finish_3 = TestIndex };                                                  //11-02-14|0x01f8
//------------------------------------------------------------------------                //11-02-14|0x01f8
#undef TestIndex                                                                          //11-02-14|0x01f8
#define TestIndex mac_cert_finish_3+1                                                     //11-02-14|0x01f8
//************************************************************************                //11-02-14|0x01f8
#ifndef TestIndex                                                                         //11-02-25|0x0237
#define TestIndex 0                                                                       //11-02-25|0x0237
#endif                                                                                    //11-02-25|0x0237
//------------------------------------------------------------------------                //11-02-25|0x0237
enum {  prepare_string_1 = TestIndex };                                                   //11-02-25|0x0237
//------------------------------------------------------------------------                //11-02-25|0x0237
#undef TestIndex                                                                          //11-02-25|0x0237
#define TestIndex prepare_string_1+1                                                      //11-02-25|0x0237
//************************************************************************                //11-02-25|0x0237
#ifndef TestIndex                                                                         //11-02-25|0x0262
#define TestIndex 0                                                                       //11-02-25|0x0262
#endif                                                                                    //11-02-25|0x0262
//------------------------------------------------------------------------                //11-02-25|0x0262
enum {  read_parity_1 = TestIndex };                                                      //11-02-25|0x0262
//------------------------------------------------------------------------                //11-02-25|0x0262
#undef TestIndex                                                                          //11-02-25|0x0262
#define TestIndex read_parity_1+1                                                         //11-02-25|0x0262
//************************************************************************                //11-02-25|0x0262
#ifndef TestIndex                                                                         //11-02-26|0x028e
#define TestIndex 0                                                                       //11-02-26|0x028e
#endif                                                                                    //11-02-26|0x028e
//------------------------------------------------------------------------                //11-02-26|0x028e
enum {  read_version_1 = TestIndex };                                                     //11-02-26|0x028e
//------------------------------------------------------------------------                //11-02-26|0x028e
#undef TestIndex                                                                          //11-02-26|0x028e
#define TestIndex read_version_1+1                                                        //11-02-26|0x028e
//************************************************************************                //11-02-26|0x028e
//*******************************************************************************         //05-24-97|0x02c0
//*******************************************************************************         //05-24-97|0x02c0
//****                       END OF FILE                                     ****         //05-24-97|0x02c0
//*******************************************************************************         //05-24-97|0x02c0
//*******************************************************************************         //05-24-97|0x02c0
#endif                                                                                    //05-24-97|0x02c0
