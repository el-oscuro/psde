//*****************************************************************************           //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
// MAILBOX DICTIONARY_MANAGER                                                             //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  The purpose of this program as well as instructions regarding its use is              //09-03-10|0x000b
//  defined in the associated manual.                                                     //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  This program is free software; you can redistribute it and/or modify                  //09-03-10|0x000b
//  it under the terms of the GNU General Public License as published by                  //09-03-10|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //09-03-10|0x000b
//  (at your option) any later version.                                                   //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
//  This program is distributed in the hope that it will be useful,                       //09-03-10|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //09-03-10|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //09-03-10|0x000b
//  GNU General Public License for more details.                                          //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
//  You should have received a copy of the GNU General Public License                     //09-03-10|0x000b
//  along with this program; if not, write to the Free Software                           //09-03-10|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //09-03-10|0x000b
//  USA                                                                                   //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  For further information, please contact Robert Adams:                                 //09-03-10|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //09-03-10|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //09-03-10|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
#ifndef maildict_hpp                                                                      //09-03-10|0x000c
#define maildict_hpp                                                                      //09-03-10|0x000c
//***************************************************************************             //09-03-10|0x0012
//***************************************************************************             //09-03-10|0x0013
//******                                                               ******             //09-03-10|0x0014
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //09-03-10|0x0015
//******                                                               ******             //09-03-10|0x0016
//***************************************************************************             //09-03-10|0x0017
//***************************************************************************             //09-03-10|0x0018
#define CMK_EXTENT ".cmk"                                                                 //10-01-03|0x001b
#define TMK_EXTENT ".tmk"                                                                 //10-01-03|0x001b
#define RPT_EXTENT ".rpt"                                                                 //10-01-03|0x001b
#define PMK_EXTENT ".pmk"                                                                 //10-01-03|0x001b
#define MAC_EXTENT ".mac"                                                                 //10-01-03|0x001b
#define SRC_EXTENT ".src"                                                                 //10-01-03|0x001b
#define PLB_EXTENT ".plb"                                                                 //10-01-03|0x001b
#define DIC_EXTENT ".dic"                                                                 //10-01-03|0x001b
#define MBX_EXTENT ".mbx"                                                                 //10-01-03|0x001b
#define MBC_EXTENT ".mbc"                                                                 //10-01-03|0x001b
#define RAN_EXTENT ".ran"                                                                 //10-01-03|0x001b
#define BUF_OUT_EXTENT ".bfo"                                                             //10-01-03|0x001b
#define BUF_IN_EXTENT ".bfi"                                                              //10-01-03|0x001b
//***************************************************************************             //09-03-10|0x001c
//***************************************************************************             //09-03-10|0x001d
//******                                                               ******             //09-03-10|0x001e
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //09-03-10|0x001f
//******                                                               ******             //09-03-10|0x0020
//***************************************************************************             //09-03-10|0x0021
//***************************************************************************             //09-03-10|0x0022
#define UserError 0x0000                                                                  //09-03-10|0x0023
#define BuildError 0x7fff                                                                 //09-03-10|0x0023
#define Display 0x7ffe                                                                    //09-03-10|0x0023
#define KeyBoard 0x7ffd                                                                   //09-03-10|0x0023
#define Success 0xffff                                                                    //09-03-10|0x0023
#define SystemError 0x8000                                                                //09-03-10|0x0023
#define Continue 0x0001                                                                   //09-03-10|0x0023
#define FileDone 0x0002                                                                   //09-03-10|0x0023
#define LineDone 0x0003                                                                   //09-03-10|0x0023
#define Yes 0x0004                                                                        //09-03-10|0x0023
#define No 0x0005                                                                         //09-03-10|0x0023
#define RepeatChar '\x6'                                                                  //09-03-10|0x0023
#define Great 0x0007                                                                      //09-03-10|0x0023
#define Equal 0x0008                                                                      //09-03-10|0x0023
#define Less 0x0009                                                                       //09-03-10|0x0023
#define Zero 0x000a                                                                       //09-03-10|0x0023
#define Minus 0x000b                                                                      //09-03-10|0x0023
//***************************************************************************             //09-03-10|0x0024
#define SystemMsg PcgSystemError("Maildict", __LINE__);                                   //09-03-10|0x0025
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //09-03-10|0x0025
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //09-03-10|0x0025
#define BreakFinish(_a) status = Finish(_a); break                                        //09-03-10|0x0026
#define ReturnFinish(_a) return(Finish(_a))                                               //09-03-10|0x0026
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //09-03-10|0x0026
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //09-03-10|0x0026
#define _SwitchErr case UserError: return(UserError)                                      //09-03-10|0x0027
#define _SwitchOk case Success: break                                                     //09-03-10|0x0027
#define _SwitchEnd default: ReturnSystemError                                             //09-03-10|0x0027
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //09-03-10|0x0027
#define _SwitchYes case Yes:      return(Yes)                                             //09-03-10|0x0027
#define _SwitchNo case No:       return(No)                                               //09-03-10|0x0027
#define _SwitchGroup { _SwitchBase; }                                                     //09-03-10|0x0027
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //09-03-10|0x0027
#define _SwitchReturn _SwitchGroup return(Success)                                        //09-03-10|0x0027
#define _SwitchBreak _SwitchGroup break                                                   //09-03-10|0x0027
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //09-03-10|0x0027
//***************************************************************************             //09-03-10|0x004c
//***************************************************************************             //09-03-10|0x004d
//******                                                               ******             //09-03-10|0x004e
//******               GENERAL DEFINITION STATEMENTS                   ******             //09-03-10|0x004f
//******                                                               ******             //09-03-10|0x0050
//***************************************************************************             //09-03-10|0x0051
//***************************************************************************             //09-03-10|0x0052
#define TestSample(i) test_samples[i] = __LINE__                                          //09-03-10|0x0053
#define return_test(j) { TestSample(j);  return(Success); }                               //09-03-10|0x0053
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //09-03-10|0x0053
#define return_no(j) { TestSample(j);  return(No); }                                      //09-03-10|0x0053
#define return_cont(j) { TestSample(j);  return(Continue); }                              //09-03-10|0x0053
#define return_line(j) { TestSample(j);  return(LineDone); }                              //09-03-10|0x0053
#define goto_test(i) { TestSample(i);  goto loop; }                                       //09-03-10|0x0053
#define break_test(i) { TestSample(i);  break; }                                          //09-03-10|0x0053
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //09-03-10|0x0053
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //09-03-10|0x0053
//************************************************************************                //09-03-10|0x0053
#ifndef TestIndex                                                                         //09-03-10|0x0053
#define TestIndex 0                                                                       //09-03-10|0x0053
#endif                                                                                    //09-03-10|0x0053
//------------------------------------------------------------------------                //09-03-10|0x0053
enum {  NoTestSamples = TestIndex };                                                      //09-03-10|0x0053
//------------------------------------------------------------------------                //09-03-10|0x0053
#undef TestIndex                                                                          //09-03-10|0x0053
#define TestIndex NoTestSamples+1                                                         //09-03-10|0x0053
//************************************************************************                //09-03-10|0x0053
//***************************************************************************             //09-03-10|0x0054
//**********************************************************************                  //09-03-10|0x0055
#define MailDict mail_dict_addr->data.dict                                                //09-03-10|0x0055
#define MailIndex1 mail_dict_addr->data.index1                                            //09-03-10|0x0055
#define MailIndex2 mail_dict_addr->data.index2                                            //09-03-10|0x0055
#define MailPath mail_dict_addr->data.path                                                //09-03-10|0x0055
#define MailControl mail_dict_addr->data                                                  //09-03-10|0x0055
#define MailFile mail_dict_addr->file                                                     //09-03-10|0x0055
#define MailIndex mail_dict_addr->index                                                   //09-03-10|0x0055
#define MailPosition mail_dict_addr->position                                             //09-03-10|0x0055
#define MailSize mail_dict_addr->size                                                     //09-03-10|0x0055
#define MailState mail_dict_addr->state                                                   //09-03-10|0x0055
//----------------------------------------------------------------------                  //09-03-10|0x0055
#define MailDataAddr (SCHAR_FAR) &(mail_dict_addr->data)                                  //09-03-10|0x0055
#define MailDictAddr &(mail_dict_addr->data.dict)                                         //09-03-10|0x0055
#define MailFileAddr &(mail_dict_addr->file)                                              //09-03-10|0x0055
#define MailPathAddr &(mail_dict_addr->data.path[0])                                      //09-03-10|0x0055
//***************************************************************************             //09-03-10|0x0056
//************************************************************************                //09-03-10|0x0057
#define TokenTokenAddr(i) &(Token->token[i])                                              //09-03-10|0x0057
#define TokenMacroLineNo(i) Token->token[i].macro_line_no                                 //09-03-10|0x0057
#define TokenLineAddr(i) &(Token->token[i].line[0])                                       //09-03-10|0x0057
#define TokenToken(i) Token->token[i]                                                     //09-03-10|0x0057
#define TokenLine(i) Token->token[i].line                                                 //09-03-10|0x0057
#define TokenLength(i) Token->token[i].length                                             //09-03-10|0x0057
#define TokenColumn(i) Token->token[i].column                                             //09-03-10|0x0057
#define TokenHash(i) Token->token[i].hash                                                 //09-03-10|0x0057
#define TokenPosition(i) Token->token[i].position                                         //09-03-10|0x0057
#define TokenType(i) Token->token[i].type                                                 //09-03-10|0x0057
#define TokenStartCol(i) Token->token[i].start_col                                        //09-03-10|0x0057
#define TokenStartCall(i) Token->token[i].start_call                                      //09-03-10|0x0057
#define TokenChar(i,j) Token->token[i].line[j]                                            //09-03-10|0x0057
#define TokenNoTokens Token->no_tokens                                                    //09-03-10|0x0057
#define NameChar(i) Name->line[i]                                                         //09-03-10|0x0058
#define NameLine Name->line[0]                                                            //09-03-10|0x0058
#define NameLineAddr &(Name->line[0])                                                     //09-03-10|0x0058
#define NameMacroLineNo Name->macro_line_no                                               //09-03-10|0x0058
#define NameType Name->type                                                               //09-03-10|0x0058
#define NameStartCol Name->start_col                                                      //09-03-10|0x0058
#define NameStartCall Name->start_call                                                    //09-03-10|0x0058
#define NamePosition Name->position                                                       //09-03-10|0x0058
#define NameLength Name->length                                                           //09-03-10|0x0058
#define NameColumn Name->column                                                           //09-03-10|0x0058
//**********************************************************************                  //09-03-10|0x0058
#define ClassMacroChar(i) ClassMacro->line[i]                                             //09-03-10|0x0059
#define ClassMacroLine ClassMacro->line[0]                                                //09-03-10|0x0059
#define ClassMacroLineAddr &(ClassMacro->line[0])                                         //09-03-10|0x0059
#define ClassMacroMacroLineNo ClassMacro->macro_line_no                                   //09-03-10|0x0059
#define ClassMacroType ClassMacro->type                                                   //09-03-10|0x0059
#define ClassMacroStartCol ClassMacro->start_col                                          //09-03-10|0x0059
#define ClassMacroStartCall ClassMacro->start_call                                        //09-03-10|0x0059
#define ClassMacroPosition ClassMacro->position                                           //09-03-10|0x0059
#define ClassMacroLength ClassMacro->length                                               //09-03-10|0x0059
#define ClassMacroColumn ClassMacro->column                                               //09-03-10|0x0059
//**********************************************************************                  //09-03-10|0x0059
#define AddrChar(i) Addr->line[i]                                                         //09-03-10|0x005a
#define AddrLine Addr->line[0]                                                            //09-03-10|0x005a
#define AddrLineAddr &(Addr->line[0])                                                     //09-03-10|0x005a
#define AddrMacroLineNo Addr->macro_line_no                                               //09-03-10|0x005a
#define AddrType Addr->type                                                               //09-03-10|0x005a
#define AddrStartCol Addr->start_col                                                      //09-03-10|0x005a
#define AddrStartCall Addr->start_call                                                    //09-03-10|0x005a
#define AddrPosition Addr->position                                                       //09-03-10|0x005a
#define AddrLength Addr->length                                                           //09-03-10|0x005a
#define AddrColumn Addr->column                                                           //09-03-10|0x005a
//**********************************************************************                  //09-03-10|0x005a
#define WorkChar(i) work.line[i]                                                          //09-03-10|0x005b
#define WorkLine work.line[0]                                                             //09-03-10|0x005b
#define WorkLineAddr &(work.line[0])                                                      //09-03-10|0x005b
#define WorkMacroLineNo work.macro_line_no                                                //09-03-10|0x005b
#define WorkType work.type                                                                //09-03-10|0x005b
#define WorkStartCol work.start_col                                                       //09-03-10|0x005b
#define WorkStartCall work.start_call                                                     //09-03-10|0x005b
#define WorkPosition work.position                                                        //09-03-10|0x005b
#define WorkLength work.length                                                            //09-03-10|0x005b
#define WorkColumn work.column                                                            //09-03-10|0x005b
//**********************************************************************                  //09-03-10|0x005b
//***************************************************************************             //09-03-10|0x005c
#define START_STATE 0                                                                     //10-01-03|0x005d
#define ADD_MAIL_BOX_NAME (START_STATE)*1+1                                               //10-01-03|0x005e
#define MAIL_BOX_FILE_DATE (ADD_MAIL_BOX_NAME)*1+1                                        //10-01-03|0x005f
#define MAIL_BOX_FILE_READY (MAIL_BOX_FILE_DATE)*1+1                                      //10-01-03|0x0060
#define MAIL_BOX_FILE_OPENED (MAIL_BOX_FILE_READY)*1+1                                    //10-01-03|0x0061
#define MAIL_BOX_FILE_FINISHED (MAIL_BOX_FILE_OPENED)*1+1                                 //10-01-03|0x0062
#ifndef TestIndex                                                                         //09-03-10|0x006f
#define TestIndex 0                                                                       //09-03-10|0x006f
#endif                                                                                    //09-03-10|0x006f
//------------------------------------------------------------------------                //09-03-10|0x006f
enum {  mail_dict_allocate_1 = TestIndex };                                               //09-03-10|0x006f
//------------------------------------------------------------------------                //09-03-10|0x006f
#undef TestIndex                                                                          //09-03-10|0x006f
#define TestIndex mail_dict_allocate_1+1                                                  //09-03-10|0x006f
//************************************************************************                //09-03-10|0x006f
#ifndef TestIndex                                                                         //09-03-10|0x0087
#define TestIndex 0                                                                       //09-03-10|0x0087
#endif                                                                                    //09-03-10|0x0087
//------------------------------------------------------------------------                //09-03-10|0x0087
enum {  mail_dict_free_1 = TestIndex };                                                   //09-03-10|0x0087
//------------------------------------------------------------------------                //09-03-10|0x0087
#undef TestIndex                                                                          //09-03-10|0x0087
#define TestIndex mail_dict_free_1+1                                                      //09-03-10|0x0087
//************************************************************************                //09-03-10|0x0087
#ifndef TestIndex                                                                         //10-01-03|0x00a0
#define TestIndex 0                                                                       //10-01-03|0x00a0
#endif                                                                                    //10-01-03|0x00a0
//------------------------------------------------------------------------                //10-01-03|0x00a0
enum {  mail_dict_initial_1 = TestIndex };                                                //10-01-03|0x00a0
//------------------------------------------------------------------------                //10-01-03|0x00a0
#undef TestIndex                                                                          //10-01-03|0x00a0
#define TestIndex mail_dict_initial_1+1                                                   //10-01-03|0x00a0
//************************************************************************                //10-01-03|0x00a0
#ifndef TestIndex                                                                         //10-01-03|0x00c2
#define TestIndex 0                                                                       //10-01-03|0x00c2
#endif                                                                                    //10-01-03|0x00c2
//------------------------------------------------------------------------                //10-01-03|0x00c2
enum {  mail_dict_name_1 = TestIndex };                                                   //10-01-03|0x00c2
//------------------------------------------------------------------------                //10-01-03|0x00c2
#undef TestIndex                                                                          //10-01-03|0x00c2
#define TestIndex mail_dict_name_1+1                                                      //10-01-03|0x00c2
//************************************************************************                //10-01-03|0x00c2
#ifndef TestIndex                                                                         //10-01-03|0x00df
#define TestIndex 0                                                                       //10-01-03|0x00df
#endif                                                                                    //10-01-03|0x00df
//------------------------------------------------------------------------                //10-01-03|0x00df
enum {  mail_dict_name_done_1 = TestIndex };                                              //10-01-03|0x00df
//------------------------------------------------------------------------                //10-01-03|0x00df
#undef TestIndex                                                                          //10-01-03|0x00df
#define TestIndex mail_dict_name_done_1+1                                                 //10-01-03|0x00df
//************************************************************************                //10-01-03|0x00df
#ifndef TestIndex                                                                         //10-01-03|0x00fa
#define TestIndex 0                                                                       //10-01-03|0x00fa
#endif                                                                                    //10-01-03|0x00fa
//------------------------------------------------------------------------                //10-01-03|0x00fa
enum {  mail_dict_exists_1 = TestIndex };                                                 //10-01-03|0x00fa
//------------------------------------------------------------------------                //10-01-03|0x00fa
#undef TestIndex                                                                          //10-01-03|0x00fa
#define TestIndex mail_dict_exists_1+1                                                    //10-01-03|0x00fa
//************************************************************************                //10-01-03|0x00fa
#ifndef TestIndex                                                                         //10-01-03|0x011a
#define TestIndex 0                                                                       //10-01-03|0x011a
#endif                                                                                    //10-01-03|0x011a
//------------------------------------------------------------------------                //10-01-03|0x011a
enum {  mail_dict_date_done_1 = TestIndex };                                              //10-01-03|0x011a
//------------------------------------------------------------------------                //10-01-03|0x011a
#undef TestIndex                                                                          //10-01-03|0x011a
#define TestIndex mail_dict_date_done_1+1                                                 //10-01-03|0x011a
//************************************************************************                //10-01-03|0x011a
#ifndef TestIndex                                                                         //10-01-03|0x0134
#define TestIndex 0                                                                       //10-01-03|0x0134
#endif                                                                                    //10-01-03|0x0134
//------------------------------------------------------------------------                //10-01-03|0x0134
enum {  mail_dict_create_1 = TestIndex };                                                 //10-01-03|0x0134
//------------------------------------------------------------------------                //10-01-03|0x0134
#undef TestIndex                                                                          //10-01-03|0x0134
#define TestIndex mail_dict_create_1+1                                                    //10-01-03|0x0134
//************************************************************************                //10-01-03|0x0134
#ifndef TestIndex                                                                         //10-01-03|0x0155
#define TestIndex 0                                                                       //10-01-03|0x0155
#endif                                                                                    //10-01-03|0x0155
//------------------------------------------------------------------------                //10-01-03|0x0155
enum {  mail_dict_read_1 = TestIndex };                                                   //10-01-03|0x0155
//------------------------------------------------------------------------                //10-01-03|0x0155
#undef TestIndex                                                                          //10-01-03|0x0155
#define TestIndex mail_dict_read_1+1                                                      //10-01-03|0x0155
//************************************************************************                //10-01-03|0x0155
#ifndef TestIndex                                                                         //10-01-03|0x017d
#define TestIndex 0                                                                       //10-01-03|0x017d
#endif                                                                                    //10-01-03|0x017d
//------------------------------------------------------------------------                //10-01-03|0x017d
enum {  mail_dict_open_1 = TestIndex };                                                   //10-01-03|0x017d
//------------------------------------------------------------------------                //10-01-03|0x017d
#undef TestIndex                                                                          //10-01-03|0x017d
#define TestIndex mail_dict_open_1+1                                                      //10-01-03|0x017d
//************************************************************************                //10-01-03|0x017d
#ifndef TestIndex                                                                         //10-01-03|0x0198
#define TestIndex 0                                                                       //10-01-03|0x0198
#endif                                                                                    //10-01-03|0x0198
//------------------------------------------------------------------------                //10-01-03|0x0198
enum {  mail_dict_close_1 = TestIndex };                                                  //10-01-03|0x0198
//------------------------------------------------------------------------                //10-01-03|0x0198
#undef TestIndex                                                                          //10-01-03|0x0198
#define TestIndex mail_dict_close_1+1                                                     //10-01-03|0x0198
//************************************************************************                //10-01-03|0x0198
#ifndef TestIndex                                                                         //10-01-19|0x01b5
#define TestIndex 0                                                                       //10-01-19|0x01b5
#endif                                                                                    //10-01-19|0x01b5
//------------------------------------------------------------------------                //10-01-19|0x01b5
enum {  mail_dict_task_done_1 = TestIndex };                                              //10-01-19|0x01b5
//------------------------------------------------------------------------                //10-01-19|0x01b5
#undef TestIndex                                                                          //10-01-19|0x01b5
#define TestIndex mail_dict_task_done_1+1                                                 //10-01-19|0x01b5
//************************************************************************                //10-01-19|0x01b5
#ifndef TestIndex                                                                         //10-01-19|0x01d1
#define TestIndex 0                                                                       //10-01-19|0x01d1
#endif                                                                                    //10-01-19|0x01d1
//------------------------------------------------------------------------                //10-01-19|0x01d1
enum {  mail_dict_finish_project_1 = TestIndex };                                         //10-01-19|0x01d1
//------------------------------------------------------------------------                //10-01-19|0x01d1
#undef TestIndex                                                                          //10-01-19|0x01d1
#define TestIndex mail_dict_finish_project_1+1                                            //10-01-19|0x01d1
//************************************************************************                //10-01-19|0x01d1
#ifndef TestIndex                                                                         //10-01-03|0x01ed
#define TestIndex 0                                                                       //10-01-03|0x01ed
#endif                                                                                    //10-01-03|0x01ed
//------------------------------------------------------------------------                //10-01-03|0x01ed
enum {  mail_dict_complete_1 = TestIndex };                                               //10-01-03|0x01ed
//------------------------------------------------------------------------                //10-01-03|0x01ed
#undef TestIndex                                                                          //10-01-03|0x01ed
#define TestIndex mail_dict_complete_1+1                                                  //10-01-03|0x01ed
//************************************************************************                //10-01-03|0x01ed
#ifndef TestIndex                                                                         //10-01-03|0x020b
#define TestIndex 0                                                                       //10-01-03|0x020b
#endif                                                                                    //10-01-03|0x020b
//------------------------------------------------------------------------                //10-01-03|0x020b
enum {  mail_dict_publish_1 = TestIndex };                                                //10-01-03|0x020b
//------------------------------------------------------------------------                //10-01-03|0x020b
#undef TestIndex                                                                          //10-01-03|0x020b
#define TestIndex mail_dict_publish_1+1                                                   //10-01-03|0x020b
//************************************************************************                //10-01-03|0x020b
#ifndef TestIndex                                                                         //10-01-06|0x0235
#define TestIndex 0                                                                       //10-01-06|0x0235
#endif                                                                                    //10-01-06|0x0235
//------------------------------------------------------------------------                //10-01-06|0x0235
enum {  mail_dict_delete_1 = TestIndex };                                                 //10-01-06|0x0235
//------------------------------------------------------------------------                //10-01-06|0x0235
#undef TestIndex                                                                          //10-01-06|0x0235
#define TestIndex mail_dict_delete_1+1                                                    //10-01-06|0x0235
//************************************************************************                //10-01-06|0x0235
#ifndef TestIndex                                                                         //10-01-03|0x0252
#define TestIndex 0                                                                       //10-01-03|0x0252
#endif                                                                                    //10-01-03|0x0252
//------------------------------------------------------------------------                //10-01-03|0x0252
enum {  mail_dict_end_1 = TestIndex };                                                    //10-01-03|0x0252
//------------------------------------------------------------------------                //10-01-03|0x0252
#undef TestIndex                                                                          //10-01-03|0x0252
#define TestIndex mail_dict_end_1+1                                                       //10-01-03|0x0252
//************************************************************************                //10-01-03|0x0252
#ifndef TestIndex                                                                         //09-03-11|0x026f
#define TestIndex 0                                                                       //09-03-11|0x026f
#endif                                                                                    //09-03-11|0x026f
//------------------------------------------------------------------------                //09-03-11|0x026f
enum {  maildict_add_zip_1 = TestIndex };                                                 //09-03-11|0x026f
//------------------------------------------------------------------------                //09-03-11|0x026f
#undef TestIndex                                                                          //09-03-11|0x026f
#define TestIndex maildict_add_zip_1+1                                                    //09-03-11|0x026f
//************************************************************************                //09-03-11|0x026f
#ifndef TestIndex                                                                         //09-03-11|0x0270
#define TestIndex 0                                                                       //09-03-11|0x0270
#endif                                                                                    //09-03-11|0x0270
//------------------------------------------------------------------------                //09-03-11|0x0270
enum {  maildict_add_zip_2 = TestIndex };                                                 //09-03-11|0x0270
//------------------------------------------------------------------------                //09-03-11|0x0270
#undef TestIndex                                                                          //09-03-11|0x0270
#define TestIndex maildict_add_zip_2+1                                                    //09-03-11|0x0270
//************************************************************************                //09-03-11|0x0270
#ifndef TestIndex                                                                         //09-03-11|0x0295
#define TestIndex 0                                                                       //09-03-11|0x0295
#endif                                                                                    //09-03-11|0x0295
//------------------------------------------------------------------------                //09-03-11|0x0295
enum {  mail_dict_add_po_box_1 = TestIndex };                                             //09-03-11|0x0295
//------------------------------------------------------------------------                //09-03-11|0x0295
#undef TestIndex                                                                          //09-03-11|0x0295
#define TestIndex mail_dict_add_po_box_1+1                                                //09-03-11|0x0295
//************************************************************************                //09-03-11|0x0295
#ifndef TestIndex                                                                         //09-03-11|0x0296
#define TestIndex 0                                                                       //09-03-11|0x0296
#endif                                                                                    //09-03-11|0x0296
//------------------------------------------------------------------------                //09-03-11|0x0296
enum {  mail_dict_add_po_box_3 = TestIndex };                                             //09-03-11|0x0296
//------------------------------------------------------------------------                //09-03-11|0x0296
#undef TestIndex                                                                          //09-03-11|0x0296
#define TestIndex mail_dict_add_po_box_3+1                                                //09-03-11|0x0296
//************************************************************************                //09-03-11|0x0296
#ifndef TestIndex                                                                         //09-03-11|0x0297
#define TestIndex 0                                                                       //09-03-11|0x0297
#endif                                                                                    //09-03-11|0x0297
//------------------------------------------------------------------------                //09-03-11|0x0297
enum {  mail_dict_add_po_box_4 = TestIndex };                                             //09-03-11|0x0297
//------------------------------------------------------------------------                //09-03-11|0x0297
#undef TestIndex                                                                          //09-03-11|0x0297
#define TestIndex mail_dict_add_po_box_4+1                                                //09-03-11|0x0297
//************************************************************************                //09-03-11|0x0297
#ifndef TestIndex                                                                         //09-03-11|0x0298
#define TestIndex 0                                                                       //09-03-11|0x0298
#endif                                                                                    //09-03-11|0x0298
//------------------------------------------------------------------------                //09-03-11|0x0298
enum {  mail_dict_add_po_box_5 = TestIndex };                                             //09-03-11|0x0298
//------------------------------------------------------------------------                //09-03-11|0x0298
#undef TestIndex                                                                          //09-03-11|0x0298
#define TestIndex mail_dict_add_po_box_5+1                                                //09-03-11|0x0298
//************************************************************************                //09-03-11|0x0298
#ifndef TestIndex                                                                         //09-03-13|0x02cd
#define TestIndex 0                                                                       //09-03-13|0x02cd
#endif                                                                                    //09-03-13|0x02cd
//------------------------------------------------------------------------                //09-03-13|0x02cd
enum {  mail_dict_load_po_box_1 = TestIndex };                                            //09-03-13|0x02cd
//------------------------------------------------------------------------                //09-03-13|0x02cd
#undef TestIndex                                                                          //09-03-13|0x02cd
#define TestIndex mail_dict_load_po_box_1+1                                               //09-03-13|0x02cd
//************************************************************************                //09-03-13|0x02cd
#ifndef TestIndex                                                                         //09-03-13|0x02ce
#define TestIndex 0                                                                       //09-03-13|0x02ce
#endif                                                                                    //09-03-13|0x02ce
//------------------------------------------------------------------------                //09-03-13|0x02ce
enum {  mail_dict_load_po_box_2 = TestIndex };                                            //09-03-13|0x02ce
//------------------------------------------------------------------------                //09-03-13|0x02ce
#undef TestIndex                                                                          //09-03-13|0x02ce
#define TestIndex mail_dict_load_po_box_2+1                                               //09-03-13|0x02ce
//************************************************************************                //09-03-13|0x02ce
#ifndef TestIndex                                                                         //09-03-13|0x02cf
#define TestIndex 0                                                                       //09-03-13|0x02cf
#endif                                                                                    //09-03-13|0x02cf
//------------------------------------------------------------------------                //09-03-13|0x02cf
enum {  mail_dict_load_po_box_3 = TestIndex };                                            //09-03-13|0x02cf
//------------------------------------------------------------------------                //09-03-13|0x02cf
#undef TestIndex                                                                          //09-03-13|0x02cf
#define TestIndex mail_dict_load_po_box_3+1                                               //09-03-13|0x02cf
//************************************************************************                //09-03-13|0x02cf
#ifndef TestIndex                                                                         //09-03-13|0x02d0
#define TestIndex 0                                                                       //09-03-13|0x02d0
#endif                                                                                    //09-03-13|0x02d0
//------------------------------------------------------------------------                //09-03-13|0x02d0
enum {  mail_dict_load_po_box_4 = TestIndex };                                            //09-03-13|0x02d0
//------------------------------------------------------------------------                //09-03-13|0x02d0
#undef TestIndex                                                                          //09-03-13|0x02d0
#define TestIndex mail_dict_load_po_box_4+1                                               //09-03-13|0x02d0
//************************************************************************                //09-03-13|0x02d0
#ifndef TestIndex                                                                         //09-03-13|0x02d1
#define TestIndex 0                                                                       //09-03-13|0x02d1
#endif                                                                                    //09-03-13|0x02d1
//------------------------------------------------------------------------                //09-03-13|0x02d1
enum {  mail_dict_load_po_box_5 = TestIndex };                                            //09-03-13|0x02d1
//------------------------------------------------------------------------                //09-03-13|0x02d1
#undef TestIndex                                                                          //09-03-13|0x02d1
#define TestIndex mail_dict_load_po_box_5+1                                               //09-03-13|0x02d1
//************************************************************************                //09-03-13|0x02d1
#ifndef TestIndex                                                                         //09-09-17|0x030f
#define TestIndex 0                                                                       //09-09-17|0x030f
#endif                                                                                    //09-09-17|0x030f
//------------------------------------------------------------------------                //09-09-17|0x030f
enum {  mail_dict_empty_po_box_1 = TestIndex };                                           //09-09-17|0x030f
//------------------------------------------------------------------------                //09-09-17|0x030f
#undef TestIndex                                                                          //09-09-17|0x030f
#define TestIndex mail_dict_empty_po_box_1+1                                              //09-09-17|0x030f
//************************************************************************                //09-09-17|0x030f
#ifndef TestIndex                                                                         //09-09-17|0x0310
#define TestIndex 0                                                                       //09-09-17|0x0310
#endif                                                                                    //09-09-17|0x0310
//------------------------------------------------------------------------                //09-09-17|0x0310
enum {  mail_dict_empty_po_box_2 = TestIndex };                                           //09-09-17|0x0310
//------------------------------------------------------------------------                //09-09-17|0x0310
#undef TestIndex                                                                          //09-09-17|0x0310
#define TestIndex mail_dict_empty_po_box_2+1                                              //09-09-17|0x0310
//************************************************************************                //09-09-17|0x0310
#ifndef TestIndex                                                                         //09-09-17|0x0311
#define TestIndex 0                                                                       //09-09-17|0x0311
#endif                                                                                    //09-09-17|0x0311
//------------------------------------------------------------------------                //09-09-17|0x0311
enum {  mail_dict_empty_po_box_3 = TestIndex };                                           //09-09-17|0x0311
//------------------------------------------------------------------------                //09-09-17|0x0311
#undef TestIndex                                                                          //09-09-17|0x0311
#define TestIndex mail_dict_empty_po_box_3+1                                              //09-09-17|0x0311
//************************************************************************                //09-09-17|0x0311
#ifndef TestIndex                                                                         //09-03-14|0x0341
#define TestIndex 0                                                                       //09-03-14|0x0341
#endif                                                                                    //09-03-14|0x0341
//------------------------------------------------------------------------                //09-03-14|0x0341
enum {  mail_dict_get_mail_1 = TestIndex };                                               //09-03-14|0x0341
//------------------------------------------------------------------------                //09-03-14|0x0341
#undef TestIndex                                                                          //09-03-14|0x0341
#define TestIndex mail_dict_get_mail_1+1                                                  //09-03-14|0x0341
//************************************************************************                //09-03-14|0x0341
#ifndef TestIndex                                                                         //09-03-14|0x0342
#define TestIndex 0                                                                       //09-03-14|0x0342
#endif                                                                                    //09-03-14|0x0342
//------------------------------------------------------------------------                //09-03-14|0x0342
enum {  mail_dict_get_mail_3 = TestIndex };                                               //09-03-14|0x0342
//------------------------------------------------------------------------                //09-03-14|0x0342
#undef TestIndex                                                                          //09-03-14|0x0342
#define TestIndex mail_dict_get_mail_3+1                                                  //09-03-14|0x0342
//************************************************************************                //09-03-14|0x0342
#ifndef TestIndex                                                                         //09-03-14|0x0343
#define TestIndex 0                                                                       //09-03-14|0x0343
#endif                                                                                    //09-03-14|0x0343
//------------------------------------------------------------------------                //09-03-14|0x0343
enum {  mail_dict_get_mail_4 = TestIndex };                                               //09-03-14|0x0343
//------------------------------------------------------------------------                //09-03-14|0x0343
#undef TestIndex                                                                          //09-03-14|0x0343
#define TestIndex mail_dict_get_mail_4+1                                                  //09-03-14|0x0343
//************************************************************************                //09-03-14|0x0343
#ifndef TestIndex                                                                         //09-03-17|0x0379
#define TestIndex 0                                                                       //09-03-17|0x0379
#endif                                                                                    //09-03-17|0x0379
//------------------------------------------------------------------------                //09-03-17|0x0379
enum {  mail_dict_zip_exists_1 = TestIndex };                                             //09-03-17|0x0379
//------------------------------------------------------------------------                //09-03-17|0x0379
#undef TestIndex                                                                          //09-03-17|0x0379
#define TestIndex mail_dict_zip_exists_1+1                                                //09-03-17|0x0379
//************************************************************************                //09-03-17|0x0379
#ifndef TestIndex                                                                         //09-03-17|0x037a
#define TestIndex 0                                                                       //09-03-17|0x037a
#endif                                                                                    //09-03-17|0x037a
//------------------------------------------------------------------------                //09-03-17|0x037a
enum {  mail_dict_zip_exists_2 = TestIndex };                                             //09-03-17|0x037a
//------------------------------------------------------------------------                //09-03-17|0x037a
#undef TestIndex                                                                          //09-03-17|0x037a
#define TestIndex mail_dict_zip_exists_2+1                                                //09-03-17|0x037a
//************************************************************************                //09-03-17|0x037a
#ifndef TestIndex                                                                         //09-03-17|0x037b
#define TestIndex 0                                                                       //09-03-17|0x037b
#endif                                                                                    //09-03-17|0x037b
//------------------------------------------------------------------------                //09-03-17|0x037b
enum {  mail_dict_zip_exists_3 = TestIndex };                                             //09-03-17|0x037b
//------------------------------------------------------------------------                //09-03-17|0x037b
#undef TestIndex                                                                          //09-03-17|0x037b
#define TestIndex mail_dict_zip_exists_3+1                                                //09-03-17|0x037b
//************************************************************************                //09-03-17|0x037b
#ifndef TestIndex                                                                         //09-03-17|0x039e
#define TestIndex 0                                                                       //09-03-17|0x039e
#endif                                                                                    //09-03-17|0x039e
//------------------------------------------------------------------------                //09-03-17|0x039e
enum {  mail_dict_po_box_exists_1 = TestIndex };                                          //09-03-17|0x039e
//------------------------------------------------------------------------                //09-03-17|0x039e
#undef TestIndex                                                                          //09-03-17|0x039e
#define TestIndex mail_dict_po_box_exists_1+1                                             //09-03-17|0x039e
//************************************************************************                //09-03-17|0x039e
#ifndef TestIndex                                                                         //09-03-17|0x039f
#define TestIndex 0                                                                       //09-03-17|0x039f
#endif                                                                                    //09-03-17|0x039f
//------------------------------------------------------------------------                //09-03-17|0x039f
enum {  mail_dict_po_box_exists_2 = TestIndex };                                          //09-03-17|0x039f
//------------------------------------------------------------------------                //09-03-17|0x039f
#undef TestIndex                                                                          //09-03-17|0x039f
#define TestIndex mail_dict_po_box_exists_2+1                                             //09-03-17|0x039f
//************************************************************************                //09-03-17|0x039f
#ifndef TestIndex                                                                         //09-03-17|0x03a0
#define TestIndex 0                                                                       //09-03-17|0x03a0
#endif                                                                                    //09-03-17|0x03a0
//------------------------------------------------------------------------                //09-03-17|0x03a0
enum {  mail_dict_po_box_exists_3 = TestIndex };                                          //09-03-17|0x03a0
//------------------------------------------------------------------------                //09-03-17|0x03a0
#undef TestIndex                                                                          //09-03-17|0x03a0
#define TestIndex mail_dict_po_box_exists_3+1                                             //09-03-17|0x03a0
//************************************************************************                //09-03-17|0x03a0
#ifndef TestIndex                                                                         //09-03-17|0x03cf
#define TestIndex 0                                                                       //09-03-17|0x03cf
#endif                                                                                    //09-03-17|0x03cf
//------------------------------------------------------------------------                //09-03-17|0x03cf
enum {  mail_dict_test_mail_1 = TestIndex };                                              //09-03-17|0x03cf
//------------------------------------------------------------------------                //09-03-17|0x03cf
#undef TestIndex                                                                          //09-03-17|0x03cf
#define TestIndex mail_dict_test_mail_1+1                                                 //09-03-17|0x03cf
//************************************************************************                //09-03-17|0x03cf
#ifndef TestIndex                                                                         //09-03-17|0x03d0
#define TestIndex 0                                                                       //09-03-17|0x03d0
#endif                                                                                    //09-03-17|0x03d0
//------------------------------------------------------------------------                //09-03-17|0x03d0
enum {  mail_dict_test_mail_2 = TestIndex };                                              //09-03-17|0x03d0
//------------------------------------------------------------------------                //09-03-17|0x03d0
#undef TestIndex                                                                          //09-03-17|0x03d0
#define TestIndex mail_dict_test_mail_2+1                                                 //09-03-17|0x03d0
//************************************************************************                //09-03-17|0x03d0
#ifndef TestIndex                                                                         //09-03-17|0x03d1
#define TestIndex 0                                                                       //09-03-17|0x03d1
#endif                                                                                    //09-03-17|0x03d1
//------------------------------------------------------------------------                //09-03-17|0x03d1
enum {  mail_dict_test_mail_3 = TestIndex };                                              //09-03-17|0x03d1
//------------------------------------------------------------------------                //09-03-17|0x03d1
#undef TestIndex                                                                          //09-03-17|0x03d1
#define TestIndex mail_dict_test_mail_3+1                                                 //09-03-17|0x03d1
//************************************************************************                //09-03-17|0x03d1
#ifndef TestIndex                                                                         //09-03-17|0x03d2
#define TestIndex 0                                                                       //09-03-17|0x03d2
#endif                                                                                    //09-03-17|0x03d2
//------------------------------------------------------------------------                //09-03-17|0x03d2
enum {  mail_dict_test_mail_4 = TestIndex };                                              //09-03-17|0x03d2
//------------------------------------------------------------------------                //09-03-17|0x03d2
#undef TestIndex                                                                          //09-03-17|0x03d2
#define TestIndex mail_dict_test_mail_4+1                                                 //09-03-17|0x03d2
//************************************************************************                //09-03-17|0x03d2
#ifndef TestIndex                                                                         //09-03-16|0x0407
#define TestIndex 0                                                                       //09-03-16|0x0407
#endif                                                                                    //09-03-16|0x0407
//------------------------------------------------------------------------                //09-03-16|0x0407
enum {  mail_zip_find_1 = TestIndex };                                                    //09-03-16|0x0407
//------------------------------------------------------------------------                //09-03-16|0x0407
#undef TestIndex                                                                          //09-03-16|0x0407
#define TestIndex mail_zip_find_1+1                                                       //09-03-16|0x0407
//************************************************************************                //09-03-16|0x0407
#ifndef TestIndex                                                                         //09-03-16|0x0408
#define TestIndex 0                                                                       //09-03-16|0x0408
#endif                                                                                    //09-03-16|0x0408
//------------------------------------------------------------------------                //09-03-16|0x0408
enum {  mail_zip_find_2 = TestIndex };                                                    //09-03-16|0x0408
//------------------------------------------------------------------------                //09-03-16|0x0408
#undef TestIndex                                                                          //09-03-16|0x0408
#define TestIndex mail_zip_find_2+1                                                       //09-03-16|0x0408
//************************************************************************                //09-03-16|0x0408
#ifndef TestIndex                                                                         //09-03-16|0x0431
#define TestIndex 0                                                                       //09-03-16|0x0431
#endif                                                                                    //09-03-16|0x0431
//------------------------------------------------------------------------                //09-03-16|0x0431
enum {  mail_po_box_find_1 = TestIndex };                                                 //09-03-16|0x0431
//------------------------------------------------------------------------                //09-03-16|0x0431
#undef TestIndex                                                                          //09-03-16|0x0431
#define TestIndex mail_po_box_find_1+1                                                    //09-03-16|0x0431
//************************************************************************                //09-03-16|0x0431
#ifndef TestIndex                                                                         //09-03-16|0x0432
#define TestIndex 0                                                                       //09-03-16|0x0432
#endif                                                                                    //09-03-16|0x0432
//------------------------------------------------------------------------                //09-03-16|0x0432
enum {  mail_po_box_find_2 = TestIndex };                                                 //09-03-16|0x0432
//------------------------------------------------------------------------                //09-03-16|0x0432
#undef TestIndex                                                                          //09-03-16|0x0432
#define TestIndex mail_po_box_find_2+1                                                    //09-03-16|0x0432
//************************************************************************                //09-03-16|0x0432
#ifndef TestIndex                                                                         //09-03-16|0x0462
#define TestIndex 0                                                                       //09-03-16|0x0462
#endif                                                                                    //09-03-16|0x0462
//------------------------------------------------------------------------                //09-03-16|0x0462
enum {  mail_get_next_1 = TestIndex };                                                    //09-03-16|0x0462
//------------------------------------------------------------------------                //09-03-16|0x0462
#undef TestIndex                                                                          //09-03-16|0x0462
#define TestIndex mail_get_next_1+1                                                       //09-03-16|0x0462
//************************************************************************                //09-03-16|0x0462
#ifndef TestIndex                                                                         //09-03-16|0x0463
#define TestIndex 0                                                                       //09-03-16|0x0463
#endif                                                                                    //09-03-16|0x0463
//------------------------------------------------------------------------                //09-03-16|0x0463
enum {  mail_get_next_2 = TestIndex };                                                    //09-03-16|0x0463
//------------------------------------------------------------------------                //09-03-16|0x0463
#undef TestIndex                                                                          //09-03-16|0x0463
#define TestIndex mail_get_next_2+1                                                       //09-03-16|0x0463
//************************************************************************                //09-03-16|0x0463
#ifndef TestIndex                                                                         //10-01-03|0x0482
#define TestIndex 0                                                                       //10-01-03|0x0482
#endif                                                                                    //10-01-03|0x0482
//------------------------------------------------------------------------                //10-01-03|0x0482
enum {  mail_dict_control_read_1 = TestIndex };                                           //10-01-03|0x0482
//------------------------------------------------------------------------                //10-01-03|0x0482
#undef TestIndex                                                                          //10-01-03|0x0482
#define TestIndex mail_dict_control_read_1+1                                              //10-01-03|0x0482
//************************************************************************                //10-01-03|0x0482
#ifndef TestIndex                                                                         //10-01-03|0x04ac
#define TestIndex 0                                                                       //10-01-03|0x04ac
#endif                                                                                    //10-01-03|0x04ac
//------------------------------------------------------------------------                //10-01-03|0x04ac
enum {  mail_dict_control_write_1 = TestIndex };                                          //10-01-03|0x04ac
//------------------------------------------------------------------------                //10-01-03|0x04ac
#undef TestIndex                                                                          //10-01-03|0x04ac
#define TestIndex mail_dict_control_write_1+1                                             //10-01-03|0x04ac
//************************************************************************                //10-01-03|0x04ac
#ifndef TestIndex                                                                         //10-01-03|0x04c9
#define TestIndex 0                                                                       //10-01-03|0x04c9
#endif                                                                                    //10-01-03|0x04c9
//------------------------------------------------------------------------                //10-01-03|0x04c9
enum {  mail_dict_control_verify_1 = TestIndex };                                         //10-01-03|0x04c9
//------------------------------------------------------------------------                //10-01-03|0x04c9
#undef TestIndex                                                                          //10-01-03|0x04c9
#define TestIndex mail_dict_control_verify_1+1                                            //10-01-03|0x04c9
//************************************************************************                //10-01-03|0x04c9
//*******************************************************************************         //05-24-97|0x04fc
//*******************************************************************************         //05-24-97|0x04fc
//****                       END OF FILE                                     ****         //05-24-97|0x04fc
//*******************************************************************************         //05-24-97|0x04fc
//*******************************************************************************         //05-24-97|0x04fc
#endif                                                                                    //05-24-97|0x04fc
