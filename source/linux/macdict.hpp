//*****************************************************************************           //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//                                                                                        //06-07-12|0x000b
// MACRO DICTIONARY_MANAGER                                                               //06-07-12|0x000b
//                                                                                        //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//  The purpose of this program as well as instructions regarding its use is              //06-07-12|0x000b
//  defined in the associated manual.                                                     //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//  This program is free software; you can redistribute it and/or modify                  //06-07-12|0x000b
//  it under the terms of the GNU General Public License as published by                  //06-07-12|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //06-07-12|0x000b
//  (at your option) any later version.                                                   //06-07-12|0x000b
//                                                                                        //06-07-12|0x000b
//  This program is distributed in the hope that it will be useful,                       //06-07-12|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-07-12|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-07-12|0x000b
//  GNU General Public License for more details.                                          //06-07-12|0x000b
//                                                                                        //06-07-12|0x000b
//  You should have received a copy of the GNU General Public License                     //06-07-12|0x000b
//  along with this program; if not, write to the Free Software                           //06-07-12|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-07-12|0x000b
//  USA                                                                                   //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//  For further information, please contact Robert Adams:                                 //06-07-12|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //06-07-12|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-07-12|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
#ifndef macdict_hpp                                                                       //06-07-12|0x000c
#define macdict_hpp                                                                       //06-07-12|0x000c
//***************************************************************************             //06-07-12|0x0012
//***************************************************************************             //06-07-12|0x0013
//******                                                               ******             //06-07-12|0x0014
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0015
//******                                                               ******             //06-07-12|0x0016
//***************************************************************************             //06-07-12|0x0017
//***************************************************************************             //06-07-12|0x0018
#define CMK_EXTENT ".cmk"                                                                 //11-02-26|0x001b
#define TMK_EXTENT ".tmk"                                                                 //11-02-26|0x001b
#define RPT_EXTENT ".rpt"                                                                 //11-02-26|0x001b
#define PMK_EXTENT ".pmk"                                                                 //11-02-26|0x001b
#define MAC_EXTENT ".mac"                                                                 //11-02-26|0x001b
#define SRC_EXTENT ".src"                                                                 //11-02-26|0x001b
#define PLB_EXTENT ".plb"                                                                 //11-02-26|0x001b
#define DIC_EXTENT ".dic"                                                                 //11-02-26|0x001b
#define MBX_EXTENT ".mbx"                                                                 //11-02-26|0x001b
#define MBC_EXTENT ".mbc"                                                                 //11-02-26|0x001b
#define RAN_EXTENT ".ran"                                                                 //11-02-26|0x001b
#define BUF_EXTENT ".bfo"                                                                 //11-02-26|0x001b
//***************************************************************************             //06-07-12|0x001c
//***************************************************************************             //06-07-12|0x001d
//******                                                               ******             //06-07-12|0x001e
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x001f
//******                                                               ******             //06-07-12|0x0020
//***************************************************************************             //06-07-12|0x0021
//***************************************************************************             //06-07-12|0x0022
#define UserError 0x0000                                                                  //06-07-12|0x0023
#define BuildError 0x7fff                                                                 //06-07-12|0x0023
#define Display 0x7ffe                                                                    //06-07-12|0x0023
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x0023
#define Success 0xffff                                                                    //06-07-12|0x0023
#define SystemError 0x8000                                                                //06-07-12|0x0023
#define Continue 0x0001                                                                   //06-07-12|0x0023
#define FileDone 0x0002                                                                   //06-07-12|0x0023
#define LineDone 0x0003                                                                   //06-07-12|0x0023
#define Yes 0x0004                                                                        //06-07-12|0x0023
#define No 0x0005                                                                         //06-07-12|0x0023
#define RepeatChar '\x6'                                                                  //06-07-12|0x0023
#define Great 0x0007                                                                      //06-07-12|0x0023
#define Equal 0x0008                                                                      //06-07-12|0x0023
#define Less 0x0009                                                                       //06-07-12|0x0023
#define Zero 0x000a                                                                       //06-07-12|0x0023
#define Minus 0x000b                                                                      //06-07-12|0x0023
//***************************************************************************             //06-07-12|0x0024
#define SystemMsg PcgSystemError("Macdict", __LINE__);                                    //06-07-12|0x0025
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x0025
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //06-07-12|0x0025
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0026
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0026
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0026
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0026
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0027
#define _SwitchOk case Success: break                                                     //06-07-12|0x0027
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0027
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0027
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0027
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0027
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0027
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0027
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0027
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0027
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0027
//***************************************************************************             //06-07-12|0x004c
//***************************************************************************             //06-07-12|0x004d
//******                                                               ******             //06-07-12|0x004e
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x004f
//******                                                               ******             //06-07-12|0x0050
//***************************************************************************             //06-07-12|0x0051
//***************************************************************************             //06-07-12|0x0052
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x0053
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x0053
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x0053
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x0053
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x0053
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x0053
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x0053
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x0053
//************************************************************************                //06-07-12|0x0053
#ifndef TestIndex                                                                         //06-07-12|0x0053
#define TestIndex 0                                                                       //06-07-12|0x0053
#endif                                                                                    //06-07-12|0x0053
//------------------------------------------------------------------------                //06-07-12|0x0053
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x0053
//------------------------------------------------------------------------                //06-07-12|0x0053
#undef TestIndex                                                                          //06-07-12|0x0053
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x0053
//************************************************************************                //06-07-12|0x0053
//***************************************************************************             //06-07-12|0x0054
//************************************************************************                //06-07-12|0x0055
#define TokenTokenAddr(i) &(Token->token[i])                                              //06-07-12|0x0055
#define TokenMacroLineNo(i) Token->token[i].macro_line_no                                 //06-07-12|0x0055
#define TokenLineAddr(i) &(Token->token[i].line[0])                                       //06-07-12|0x0055
#define TokenToken(i) Token->token[i]                                                     //06-07-12|0x0055
#define TokenLine(i) Token->token[i].line                                                 //06-07-12|0x0055
#define TokenLength(i) Token->token[i].length                                             //06-07-12|0x0055
#define TokenColumn(i) Token->token[i].column                                             //06-07-12|0x0055
#define TokenHash(i) Token->token[i].hash                                                 //06-07-12|0x0055
#define TokenPosition(i) Token->token[i].position                                         //06-07-12|0x0055
#define TokenType(i) Token->token[i].type                                                 //06-07-12|0x0055
#define TokenStartCol(i) Token->token[i].start_col                                        //06-07-12|0x0055
#define TokenStartCall(i) Token->token[i].start_call                                      //06-07-12|0x0055
#define TokenChar(i,j) Token->token[i].line[j]                                            //06-07-12|0x0055
#define TokenNoTokens Token->no_tokens                                                    //06-07-12|0x0055
#define StringChar(i) String->line[i]                                                     //07-04-27|0x0056
#define StringLine String->line[0]                                                        //07-04-27|0x0056
#define StringLineAddr &(String->line[0])                                                 //07-04-27|0x0056
#define StringMacroLineNo String->macro_line_no                                           //07-04-27|0x0056
#define StringType String->type                                                           //07-04-27|0x0056
#define StringStartCol String->start_col                                                  //07-04-27|0x0056
#define StringStartCall String->start_call                                                //07-04-27|0x0056
#define StringPosition String->position                                                   //07-04-27|0x0056
#define StringLength String->length                                                       //07-04-27|0x0056
#define StringColumn String->column                                                       //07-04-27|0x0056
//**********************************************************************                  //07-04-27|0x0056
#define AddrChar(i) Addr->line[i]                                                         //07-04-27|0x0057
#define AddrLine Addr->line[0]                                                            //07-04-27|0x0057
#define AddrLineAddr &(Addr->line[0])                                                     //07-04-27|0x0057
#define AddrMacroLineNo Addr->macro_line_no                                               //07-04-27|0x0057
#define AddrType Addr->type                                                               //07-04-27|0x0057
#define AddrStartCol Addr->start_col                                                      //07-04-27|0x0057
#define AddrStartCall Addr->start_call                                                    //07-04-27|0x0057
#define AddrPosition Addr->position                                                       //07-04-27|0x0057
#define AddrLength Addr->length                                                           //07-04-27|0x0057
#define AddrColumn Addr->column                                                           //07-04-27|0x0057
//**********************************************************************                  //07-04-27|0x0057
#define WorkChar(i) work.line[i]                                                          //07-04-27|0x0058
#define WorkLine work.line[0]                                                             //07-04-27|0x0058
#define WorkLineAddr &(work.line[0])                                                      //07-04-27|0x0058
#define WorkMacroLineNo work.macro_line_no                                                //07-04-27|0x0058
#define WorkType work.type                                                                //07-04-27|0x0058
#define WorkStartCol work.start_col                                                       //07-04-27|0x0058
#define WorkStartCall work.start_call                                                     //07-04-27|0x0058
#define WorkPosition work.position                                                        //07-04-27|0x0058
#define WorkLength work.length                                                            //07-04-27|0x0058
#define WorkColumn work.column                                                            //07-04-27|0x0058
//**********************************************************************                  //07-04-27|0x0058
#ifndef TestIndex                                                                         //06-07-12|0x0065
#define TestIndex 0                                                                       //06-07-12|0x0065
#endif                                                                                    //06-07-12|0x0065
//------------------------------------------------------------------------                //06-07-12|0x0065
enum {  mac_dict_allocate_1 = TestIndex };                                                //06-07-12|0x0065
//------------------------------------------------------------------------                //06-07-12|0x0065
#undef TestIndex                                                                          //06-07-12|0x0065
#define TestIndex mac_dict_allocate_1+1                                                   //06-07-12|0x0065
//************************************************************************                //06-07-12|0x0065
#ifndef TestIndex                                                                         //06-07-12|0x007d
#define TestIndex 0                                                                       //06-07-12|0x007d
#endif                                                                                    //06-07-12|0x007d
//------------------------------------------------------------------------                //06-07-12|0x007d
enum {  mac_dict_free_1 = TestIndex };                                                    //06-07-12|0x007d
//------------------------------------------------------------------------                //06-07-12|0x007d
#undef TestIndex                                                                          //06-07-12|0x007d
#define TestIndex mac_dict_free_1+1                                                       //06-07-12|0x007d
//************************************************************************                //06-07-12|0x007d
#ifndef TestIndex                                                                         //06-08-18|0x0096
#define TestIndex 0                                                                       //06-08-18|0x0096
#endif                                                                                    //06-08-18|0x0096
//------------------------------------------------------------------------                //06-08-18|0x0096
enum {  mac_dict_name_1 = TestIndex };                                                    //06-08-18|0x0096
//------------------------------------------------------------------------                //06-08-18|0x0096
#undef TestIndex                                                                          //06-08-18|0x0096
#define TestIndex mac_dict_name_1+1                                                       //06-08-18|0x0096
//************************************************************************                //06-08-18|0x0096
#ifndef TestIndex                                                                         //06-08-18|0x00b0
#define TestIndex 0                                                                       //06-08-18|0x00b0
#endif                                                                                    //06-08-18|0x00b0
//------------------------------------------------------------------------                //06-08-18|0x00b0
enum {  mac_dict_exists_1 = TestIndex };                                                  //06-08-18|0x00b0
//------------------------------------------------------------------------                //06-08-18|0x00b0
#undef TestIndex                                                                          //06-08-18|0x00b0
#define TestIndex mac_dict_exists_1+1                                                     //06-08-18|0x00b0
//************************************************************************                //06-08-18|0x00b0
#ifndef TestIndex                                                                         //06-08-18|0x00c8
#define TestIndex 0                                                                       //06-08-18|0x00c8
#endif                                                                                    //06-08-18|0x00c8
//------------------------------------------------------------------------                //06-08-18|0x00c8
enum {  mac_dict_create_1 = TestIndex };                                                  //06-08-18|0x00c8
//------------------------------------------------------------------------                //06-08-18|0x00c8
#undef TestIndex                                                                          //06-08-18|0x00c8
#define TestIndex mac_dict_create_1+1                                                     //06-08-18|0x00c8
//************************************************************************                //06-08-18|0x00c8
#ifndef TestIndex                                                                         //06-09-06|0x00ec
#define TestIndex 0                                                                       //06-09-06|0x00ec
#endif                                                                                    //06-09-06|0x00ec
//------------------------------------------------------------------------                //06-09-06|0x00ec
enum {  mac_dict_open_1 = TestIndex };                                                    //06-09-06|0x00ec
//------------------------------------------------------------------------                //06-09-06|0x00ec
#undef TestIndex                                                                          //06-09-06|0x00ec
#define TestIndex mac_dict_open_1+1                                                       //06-09-06|0x00ec
//************************************************************************                //06-09-06|0x00ec
#ifndef TestIndex                                                                         //06-09-06|0x0109
#define TestIndex 0                                                                       //06-09-06|0x0109
#endif                                                                                    //06-09-06|0x0109
//------------------------------------------------------------------------                //06-09-06|0x0109
enum {  mac_dict_append_1 = TestIndex };                                                  //06-09-06|0x0109
//------------------------------------------------------------------------                //06-09-06|0x0109
#undef TestIndex                                                                          //06-09-06|0x0109
#define TestIndex mac_dict_append_1+1                                                     //06-09-06|0x0109
//************************************************************************                //06-09-06|0x0109
#ifndef TestIndex                                                                         //06-08-18|0x0120
#define TestIndex 0                                                                       //06-08-18|0x0120
#endif                                                                                    //06-08-18|0x0120
//------------------------------------------------------------------------                //06-08-18|0x0120
enum {  mac_dict_close_1 = TestIndex };                                                   //06-08-18|0x0120
//------------------------------------------------------------------------                //06-08-18|0x0120
#undef TestIndex                                                                          //06-08-18|0x0120
#define TestIndex mac_dict_close_1+1                                                      //06-08-18|0x0120
//************************************************************************                //06-08-18|0x0120
#ifndef TestIndex                                                                         //07-03-21|0x0138
#define TestIndex 0                                                                       //07-03-21|0x0138
#endif                                                                                    //07-03-21|0x0138
//------------------------------------------------------------------------                //07-03-21|0x0138
enum {  mac_dict_emergency_close_1 = TestIndex };                                         //07-03-21|0x0138
//------------------------------------------------------------------------                //07-03-21|0x0138
#undef TestIndex                                                                          //07-03-21|0x0138
#define TestIndex mac_dict_emergency_close_1+1                                            //07-03-21|0x0138
//************************************************************************                //07-03-21|0x0138
#ifndef TestIndex                                                                         //06-09-04|0x0150
#define TestIndex 0                                                                       //06-09-04|0x0150
#endif                                                                                    //06-09-04|0x0150
//------------------------------------------------------------------------                //06-09-04|0x0150
enum {  mac_dict_delete_1 = TestIndex };                                                  //06-09-04|0x0150
//------------------------------------------------------------------------                //06-09-04|0x0150
#undef TestIndex                                                                          //06-09-04|0x0150
#define TestIndex mac_dict_delete_1+1                                                     //06-09-04|0x0150
//************************************************************************                //06-09-04|0x0150
#ifndef TestIndex                                                                         //06-08-18|0x0167
#define TestIndex 0                                                                       //06-08-18|0x0167
#endif                                                                                    //06-08-18|0x0167
//------------------------------------------------------------------------                //06-08-18|0x0167
enum {  mac_dict_complete_1 = TestIndex };                                                //06-08-18|0x0167
//------------------------------------------------------------------------                //06-08-18|0x0167
#undef TestIndex                                                                          //06-08-18|0x0167
#define TestIndex mac_dict_complete_1+1                                                   //06-08-18|0x0167
//************************************************************************                //06-08-18|0x0167
#ifndef TestIndex                                                                         //06-11-13|0x0180
#define TestIndex 0                                                                       //06-11-13|0x0180
#endif                                                                                    //06-11-13|0x0180
//------------------------------------------------------------------------                //06-11-13|0x0180
enum {  mac_dict_connect_header_1 = TestIndex };                                          //06-11-13|0x0180
//------------------------------------------------------------------------                //06-11-13|0x0180
#undef TestIndex                                                                          //06-11-13|0x0180
#define TestIndex mac_dict_connect_header_1+1                                             //06-11-13|0x0180
//************************************************************************                //06-11-13|0x0180
#ifndef TestIndex                                                                         //06-11-14|0x0196
#define TestIndex 0                                                                       //06-11-14|0x0196
#endif                                                                                    //06-11-14|0x0196
//------------------------------------------------------------------------                //06-11-14|0x0196
enum {  mac_dict_write_record_1 = TestIndex };                                            //06-11-14|0x0196
//------------------------------------------------------------------------                //06-11-14|0x0196
#undef TestIndex                                                                          //06-11-14|0x0196
#define TestIndex mac_dict_write_record_1+1                                               //06-11-14|0x0196
//************************************************************************                //06-11-14|0x0196
#ifndef TestIndex                                                                         //07-04-27|0x01ac
#define TestIndex 0                                                                       //07-04-27|0x01ac
#endif                                                                                    //07-04-27|0x01ac
//------------------------------------------------------------------------                //07-04-27|0x01ac
enum {  mac_dict_load_class_1 = TestIndex };                                              //07-04-27|0x01ac
//------------------------------------------------------------------------                //07-04-27|0x01ac
#undef TestIndex                                                                          //07-04-27|0x01ac
#define TestIndex mac_dict_load_class_1+1                                                 //07-04-27|0x01ac
//************************************************************************                //07-04-27|0x01ac
#ifndef TestIndex                                                                         //11-02-18|0x01e2
#define TestIndex 0                                                                       //11-02-18|0x01e2
#endif                                                                                    //11-02-18|0x01e2
//------------------------------------------------------------------------                //11-02-18|0x01e2
enum {  mac_dict_load_cert_1 = TestIndex };                                               //11-02-18|0x01e2
//------------------------------------------------------------------------                //11-02-18|0x01e2
#undef TestIndex                                                                          //11-02-18|0x01e2
#define TestIndex mac_dict_load_cert_1+1                                                  //11-02-18|0x01e2
//************************************************************************                //11-02-18|0x01e2
#ifndef TestIndex                                                                         //07-04-27|0x021b
#define TestIndex 0                                                                       //07-04-27|0x021b
#endif                                                                                    //07-04-27|0x021b
//------------------------------------------------------------------------                //07-04-27|0x021b
enum {  mac_dict_load_bridge_1 = TestIndex };                                             //07-04-27|0x021b
//------------------------------------------------------------------------                //07-04-27|0x021b
#undef TestIndex                                                                          //07-04-27|0x021b
#define TestIndex mac_dict_load_bridge_1+1                                                //07-04-27|0x021b
//************************************************************************                //07-04-27|0x021b
#ifndef TestIndex                                                                         //07-04-27|0x0237
#define TestIndex 0                                                                       //07-04-27|0x0237
#endif                                                                                    //07-04-27|0x0237
//------------------------------------------------------------------------                //07-04-27|0x0237
enum {  mac_dict_initial_bridge_1 = TestIndex };                                          //07-04-27|0x0237
//------------------------------------------------------------------------                //07-04-27|0x0237
#undef TestIndex                                                                          //07-04-27|0x0237
#define TestIndex mac_dict_initial_bridge_1+1                                             //07-04-27|0x0237
//************************************************************************                //07-04-27|0x0237
#ifndef TestIndex                                                                         //07-04-27|0x0238
#define TestIndex 0                                                                       //07-04-27|0x0238
#endif                                                                                    //07-04-27|0x0238
//------------------------------------------------------------------------                //07-04-27|0x0238
enum {  mac_dict_initial_bridge_2 = TestIndex };                                          //07-04-27|0x0238
//------------------------------------------------------------------------                //07-04-27|0x0238
#undef TestIndex                                                                          //07-04-27|0x0238
#define TestIndex mac_dict_initial_bridge_2+1                                             //07-04-27|0x0238
//************************************************************************                //07-04-27|0x0238
#ifndef TestIndex                                                                         //06-09-04|0x0263
#define TestIndex 0                                                                       //06-09-04|0x0263
#endif                                                                                    //06-09-04|0x0263
//------------------------------------------------------------------------                //06-09-04|0x0263
enum {  mac_dict_load_macro_1 = TestIndex };                                              //06-09-04|0x0263
//------------------------------------------------------------------------                //06-09-04|0x0263
#undef TestIndex                                                                          //06-09-04|0x0263
#define TestIndex mac_dict_load_macro_1+1                                                 //06-09-04|0x0263
//************************************************************************                //06-09-04|0x0263
#ifndef TestIndex                                                                         //06-09-04|0x027f
#define TestIndex 0                                                                       //06-09-04|0x027f
#endif                                                                                    //06-09-04|0x027f
//------------------------------------------------------------------------                //06-09-04|0x027f
enum {  mac_dict_load_command_1 = TestIndex };                                            //06-09-04|0x027f
//------------------------------------------------------------------------                //06-09-04|0x027f
#undef TestIndex                                                                          //06-09-04|0x027f
#define TestIndex mac_dict_load_command_1+1                                               //06-09-04|0x027f
//************************************************************************                //06-09-04|0x027f
#ifndef TestIndex                                                                         //06-09-04|0x0280
#define TestIndex 0                                                                       //06-09-04|0x0280
#endif                                                                                    //06-09-04|0x0280
//------------------------------------------------------------------------                //06-09-04|0x0280
enum {  mac_dict_load_command_2 = TestIndex };                                            //06-09-04|0x0280
//------------------------------------------------------------------------                //06-09-04|0x0280
#undef TestIndex                                                                          //06-09-04|0x0280
#define TestIndex mac_dict_load_command_2+1                                               //06-09-04|0x0280
//************************************************************************                //06-09-04|0x0280
#ifndef TestIndex                                                                         //06-08-18|0x02ab
#define TestIndex 0                                                                       //06-08-18|0x02ab
#endif                                                                                    //06-08-18|0x02ab
//------------------------------------------------------------------------                //06-08-18|0x02ab
enum {  mac_dict_macro_end_1 = TestIndex };                                               //06-08-18|0x02ab
//------------------------------------------------------------------------                //06-08-18|0x02ab
#undef TestIndex                                                                          //06-08-18|0x02ab
#define TestIndex mac_dict_macro_end_1+1                                                  //06-08-18|0x02ab
//************************************************************************                //06-08-18|0x02ab
#ifndef TestIndex                                                                         //06-09-13|0x02c2
#define TestIndex 0                                                                       //06-09-13|0x02c2
#endif                                                                                    //06-09-13|0x02c2
//------------------------------------------------------------------------                //06-09-13|0x02c2
enum {  mac_dict_find_bridge_1 = TestIndex };                                             //06-09-13|0x02c2
//------------------------------------------------------------------------                //06-09-13|0x02c2
#undef TestIndex                                                                          //06-09-13|0x02c2
#define TestIndex mac_dict_find_bridge_1+1                                                //06-09-13|0x02c2
//************************************************************************                //06-09-13|0x02c2
#ifndef TestIndex                                                                         //06-09-13|0x02c3
#define TestIndex 0                                                                       //06-09-13|0x02c3
#endif                                                                                    //06-09-13|0x02c3
//------------------------------------------------------------------------                //06-09-13|0x02c3
enum {  mac_dict_find_bridge_2 = TestIndex };                                             //06-09-13|0x02c3
//------------------------------------------------------------------------                //06-09-13|0x02c3
#undef TestIndex                                                                          //06-09-13|0x02c3
#define TestIndex mac_dict_find_bridge_2+1                                                //06-09-13|0x02c3
//************************************************************************                //06-09-13|0x02c3
#ifndef TestIndex                                                                         //07-04-27|0x02ee
#define TestIndex 0                                                                       //07-04-27|0x02ee
#endif                                                                                    //07-04-27|0x02ee
//------------------------------------------------------------------------                //07-04-27|0x02ee
enum {  mac_dict_verify_class_1 = TestIndex };                                            //07-04-27|0x02ee
//------------------------------------------------------------------------                //07-04-27|0x02ee
#undef TestIndex                                                                          //07-04-27|0x02ee
#define TestIndex mac_dict_verify_class_1+1                                               //07-04-27|0x02ee
//************************************************************************                //07-04-27|0x02ee
#ifndef TestIndex                                                                         //07-04-27|0x031e
#define TestIndex 0                                                                       //07-04-27|0x031e
#endif                                                                                    //07-04-27|0x031e
//------------------------------------------------------------------------                //07-04-27|0x031e
enum {  mac_dict_get_class_1 = TestIndex };                                               //07-04-27|0x031e
//------------------------------------------------------------------------                //07-04-27|0x031e
#undef TestIndex                                                                          //07-04-27|0x031e
#define TestIndex mac_dict_get_class_1+1                                                  //07-04-27|0x031e
//************************************************************************                //07-04-27|0x031e
#ifndef TestIndex                                                                         //11-02-26|0x035c
#define TestIndex 0                                                                       //11-02-26|0x035c
#endif                                                                                    //11-02-26|0x035c
//------------------------------------------------------------------------                //11-02-26|0x035c
enum {  mac_dict_get_cert_1 = TestIndex };                                                //11-02-26|0x035c
//------------------------------------------------------------------------                //11-02-26|0x035c
#undef TestIndex                                                                          //11-02-26|0x035c
#define TestIndex mac_dict_get_cert_1+1                                                   //11-02-26|0x035c
//************************************************************************                //11-02-26|0x035c
#ifndef TestIndex                                                                         //07-05-24|0x0376
#define TestIndex 0                                                                       //07-05-24|0x0376
#endif                                                                                    //07-05-24|0x0376
//------------------------------------------------------------------------                //07-05-24|0x0376
enum {  mac_dict_check_dup_name_1 = TestIndex };                                          //07-05-24|0x0376
//------------------------------------------------------------------------                //07-05-24|0x0376
#undef TestIndex                                                                          //07-05-24|0x0376
#define TestIndex mac_dict_check_dup_name_1+1                                             //07-05-24|0x0376
//************************************************************************                //07-05-24|0x0376
#ifndef TestIndex                                                                         //07-05-24|0x0377
#define TestIndex 0                                                                       //07-05-24|0x0377
#endif                                                                                    //07-05-24|0x0377
//------------------------------------------------------------------------                //07-05-24|0x0377
enum {  mac_dict_check_dup_name_2 = TestIndex };                                          //07-05-24|0x0377
//------------------------------------------------------------------------                //07-05-24|0x0377
#undef TestIndex                                                                          //07-05-24|0x0377
#define TestIndex mac_dict_check_dup_name_2+1                                             //07-05-24|0x0377
//************************************************************************                //07-05-24|0x0377
#ifndef TestIndex                                                                         //06-09-26|0x0394
#define TestIndex 0                                                                       //06-09-26|0x0394
#endif                                                                                    //06-09-26|0x0394
//------------------------------------------------------------------------                //06-09-26|0x0394
enum {  mac_dict_find_name_1 = TestIndex };                                               //06-09-26|0x0394
//------------------------------------------------------------------------                //06-09-26|0x0394
#undef TestIndex                                                                          //06-09-26|0x0394
#define TestIndex mac_dict_find_name_1+1                                                  //06-09-26|0x0394
//************************************************************************                //06-09-26|0x0394
#ifndef TestIndex                                                                         //06-11-14|0x03bd
#define TestIndex 0                                                                       //06-11-14|0x03bd
#endif                                                                                    //06-11-14|0x03bd
//------------------------------------------------------------------------                //06-11-14|0x03bd
enum {  mac_dict_get_command_1 = TestIndex };                                             //06-11-14|0x03bd
//------------------------------------------------------------------------                //06-11-14|0x03bd
#undef TestIndex                                                                          //06-11-14|0x03bd
#define TestIndex mac_dict_get_command_1+1                                                //06-11-14|0x03bd
//************************************************************************                //06-11-14|0x03bd
#ifndef TestIndex                                                                         //06-11-14|0x03be
#define TestIndex 0                                                                       //06-11-14|0x03be
#endif                                                                                    //06-11-14|0x03be
//------------------------------------------------------------------------                //06-11-14|0x03be
enum {  mac_dict_get_command_2 = TestIndex };                                             //06-11-14|0x03be
//------------------------------------------------------------------------                //06-11-14|0x03be
#undef TestIndex                                                                          //06-11-14|0x03be
#define TestIndex mac_dict_get_command_2+1                                                //06-11-14|0x03be
//************************************************************************                //06-11-14|0x03be
//*******************************************************************************         //05-24-97|0x0406
//*******************************************************************************         //05-24-97|0x0406
//****                       END OF FILE                                     ****         //05-24-97|0x0406
//*******************************************************************************         //05-24-97|0x0406
//*******************************************************************************         //05-24-97|0x0406
#endif                                                                                    //05-24-97|0x0406
