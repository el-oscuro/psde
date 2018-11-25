//*****************************************************************************           //06-07-12|0x000b
//*****************************************************************************           //06-07-12|0x000b
//                                                                                        //06-07-12|0x000b
// APPEND DICTIONARY MANAGER                                                              //06-07-12|0x000b
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
#ifndef apnddict_hpp                                                                      //06-07-12|0x000c
#define apnddict_hpp                                                                      //06-07-12|0x000c
//***************************************************************************             //06-07-12|0x0010
//***************************************************************************             //06-07-12|0x0011
//******                                                               ******             //06-07-12|0x0012
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-07-12|0x0013
//******                                                               ******             //06-07-12|0x0014
//***************************************************************************             //06-07-12|0x0015
//***************************************************************************             //06-07-12|0x0016
//***************************************************************************             //06-07-12|0x0019
//***************************************************************************             //06-07-12|0x001a
//******                                                               ******             //06-07-12|0x001b
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-07-12|0x001c
//******                                                               ******             //06-07-12|0x001d
//***************************************************************************             //06-07-12|0x001e
//***************************************************************************             //06-07-12|0x001f
#define UserError 0x0000                                                                  //06-07-12|0x0020
#define BuildError 0x7fff                                                                 //06-07-12|0x0020
#define Display 0x7ffe                                                                    //06-07-12|0x0020
#define KeyBoard 0x7ffd                                                                   //06-07-12|0x0020
#define Success 0xffff                                                                    //06-07-12|0x0020
#define SystemError 0x8000                                                                //06-07-12|0x0020
#define Continue 0x0001                                                                   //06-07-12|0x0020
#define FileDone 0x0002                                                                   //06-07-12|0x0020
#define LineDone 0x0003                                                                   //06-07-12|0x0020
#define Yes 0x0004                                                                        //06-07-12|0x0020
#define No 0x0005                                                                         //06-07-12|0x0020
#define RepeatChar '\x6'                                                                  //06-07-12|0x0020
#define Great 0x0007                                                                      //06-07-12|0x0020
#define Equal 0x0008                                                                      //06-07-12|0x0020
#define Less 0x0009                                                                       //06-07-12|0x0020
#define Zero 0x000a                                                                       //06-07-12|0x0020
#define Minus 0x000b                                                                      //06-07-12|0x0020
//***************************************************************************             //06-07-12|0x0021
#define SystemMsg PcgSystemError("Apnddict", __LINE__);                                   //06-07-12|0x0022
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-07-12|0x0022
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //06-07-12|0x0022
#define BreakFinish(_a) status = Finish(_a); break                                        //06-07-12|0x0023
#define ReturnFinish(_a) return(Finish(_a))                                               //06-07-12|0x0023
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //06-07-12|0x0023
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //06-07-12|0x0023
#define _SwitchErr case UserError: return(UserError)                                      //06-07-12|0x0024
#define _SwitchOk case Success: break                                                     //06-07-12|0x0024
#define _SwitchEnd default: ReturnSystemError                                             //06-07-12|0x0024
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //06-07-12|0x0024
#define _SwitchYes case Yes:      return(Yes)                                             //06-07-12|0x0024
#define _SwitchNo case No:       return(No)                                               //06-07-12|0x0024
#define _SwitchGroup { _SwitchBase; }                                                     //06-07-12|0x0024
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //06-07-12|0x0024
#define _SwitchReturn _SwitchGroup return(Success)                                        //06-07-12|0x0024
#define _SwitchBreak _SwitchGroup break                                                   //06-07-12|0x0024
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //06-07-12|0x0024
//***************************************************************************             //06-07-12|0x0047
//***************************************************************************             //06-07-12|0x0048
//******                                                               ******             //06-07-12|0x0049
//******               GENERAL DEFINITION STATEMENTS                   ******             //06-07-12|0x004a
//******                                                               ******             //06-07-12|0x004b
//***************************************************************************             //06-07-12|0x004c
//***************************************************************************             //06-07-12|0x004d
#define TestSample(i) test_samples[i] = __LINE__                                          //06-07-12|0x004e
#define return_test(j) { TestSample(j);  return(Success); }                               //06-07-12|0x004e
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //06-07-12|0x004e
#define return_no(j) { TestSample(j);  return(No); }                                      //06-07-12|0x004e
#define goto_test(i) { TestSample(i);  goto loop; }                                       //06-07-12|0x004e
#define break_test(i) { TestSample(i);  break; }                                          //06-07-12|0x004e
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //06-07-12|0x004e
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //06-07-12|0x004e
//************************************************************************                //06-07-12|0x004e
#ifndef TestIndex                                                                         //06-07-12|0x004e
#define TestIndex 0                                                                       //06-07-12|0x004e
#endif                                                                                    //06-07-12|0x004e
//------------------------------------------------------------------------                //06-07-12|0x004e
enum {  NoTestSamples = TestIndex };                                                      //06-07-12|0x004e
//------------------------------------------------------------------------                //06-07-12|0x004e
#undef TestIndex                                                                          //06-07-12|0x004e
#define TestIndex NoTestSamples+1                                                         //06-07-12|0x004e
//************************************************************************                //06-07-12|0x004e
//***************************************************************************             //06-07-12|0x004f
//************************************************************************                //06-07-12|0x0050
#define ApndDict dict_append_addr->dict                                                   //06-07-12|0x0050
#define ApndDictAddr &(dict_append_addr->dict)                                            //06-07-12|0x0050
#define ApndHashAddr &(dict_append_addr->hash)                                            //06-07-12|0x0050
#define ApndRecordAddr &(dict_append_addr->record)                                        //06-07-12|0x0050
//**********************************************************************                  //--->    |0x0051
#define DictSearchState ApndDict.search_state                                             //--->    |0x0051
#define DictProcessState ApndDict.process_state                                           //--->    |0x0051
#define DictFileState ApndDict.hash_record.file_state                                     //--->    |0x0051
#define DictRunFlag ApndDict.run_flag                                                     //--->    |0x0051
#define DictStatus ApndDict.status                                                        //--->    |0x0051
#define DictTextPlan ApndDict.text_plan                                                   //--->    |0x0051
#define DictHeaderPlan ApndDict.header_plan                                               //--->    |0x0051
#define DictHash ApndDict.hash                                                            //--->    |0x0051
#define DictTextPosition ApndDict.text_position                                           //--->    |0x0051
#define DictCurrentOffset ApndDict.current_offset                                         //--->    |0x0051
#define DictCurrentBridge ApndDict.current_bridge                                         //--->    |0x0051
#define DictSearchOffset ApndDict.search_offset                                           //--->    |0x0051
#define DictSearchBridge ApndDict.search_bridge                                           //--->    |0x0051
#define DictLowerBridge ApndDict.lower_bridge                                             //--->    |0x0051
#define DictUpperBridge ApndDict.upper_bridge                                             //--->    |0x0051
#define DictHashRecord ApndDict.hash_record                                               //--->    |0x0051
#define DictHeaderRecord ApndDict.header_record                                           //--->    |0x0051
#define DictTextRecord ApndDict.text_record                                               //--->    |0x0051
#define DictFileData ApndDict.file_data                                                   //--->    |0x0051
//----------------------------------------------------------------------                  //--->    |0x0051
#define DictHeaderRecordAddr (SCHAR_FAR) &(ApndDict.header_record)                        //--->    |0x0051
#define DictHashRecordAddr (SCHAR_FAR) &(ApndDict.hash_record)                            //--->    |0x0051
#define DictTextRecordAddr (SCHAR_FAR) &(ApndDict.text_record)                            //--->    |0x0051
//************************************************************************                //--->    |0x0052
#define FileControl DictFileData.file_control                                             //--->    |0x0052
#define FilePosition DictFileData.file_position                                           //--->    |0x0052
#define FileLength DictFileData.file_length                                               //--->    |0x0052
#ifndef TestIndex                                                                         //06-07-12|0x005f
#define TestIndex 0                                                                       //06-07-12|0x005f
#endif                                                                                    //06-07-12|0x005f
//------------------------------------------------------------------------                //06-07-12|0x005f
enum {  apnd_dict_allocate_1 = TestIndex };                                               //06-07-12|0x005f
//------------------------------------------------------------------------                //06-07-12|0x005f
#undef TestIndex                                                                          //06-07-12|0x005f
#define TestIndex apnd_dict_allocate_1+1                                                  //06-07-12|0x005f
//************************************************************************                //06-07-12|0x005f
#ifndef TestIndex                                                                         //06-07-12|0x0077
#define TestIndex 0                                                                       //06-07-12|0x0077
#endif                                                                                    //06-07-12|0x0077
//------------------------------------------------------------------------                //06-07-12|0x0077
enum {  apnd_dict_free_1 = TestIndex };                                                   //06-07-12|0x0077
//------------------------------------------------------------------------                //06-07-12|0x0077
#undef TestIndex                                                                          //06-07-12|0x0077
#define TestIndex apnd_dict_free_1+1                                                      //06-07-12|0x0077
//************************************************************************                //06-07-12|0x0077
#ifndef TestIndex                                                                         //06-09-06|0x0090
#define TestIndex 0                                                                       //06-09-06|0x0090
#endif                                                                                    //06-09-06|0x0090
//------------------------------------------------------------------------                //06-09-06|0x0090
enum {  apnd_dict_name_1 = TestIndex };                                                   //06-09-06|0x0090
//------------------------------------------------------------------------                //06-09-06|0x0090
#undef TestIndex                                                                          //06-09-06|0x0090
#define TestIndex apnd_dict_name_1+1                                                      //06-09-06|0x0090
//************************************************************************                //06-09-06|0x0090
#ifndef TestIndex                                                                         //06-09-06|0x00a9
#define TestIndex 0                                                                       //06-09-06|0x00a9
#endif                                                                                    //06-09-06|0x00a9
//------------------------------------------------------------------------                //06-09-06|0x00a9
enum {  apnd_dict_exists_1 = TestIndex };                                                 //06-09-06|0x00a9
//------------------------------------------------------------------------                //06-09-06|0x00a9
#undef TestIndex                                                                          //06-09-06|0x00a9
#define TestIndex apnd_dict_exists_1+1                                                    //06-09-06|0x00a9
//************************************************************************                //06-09-06|0x00a9
#ifndef TestIndex                                                                         //11-02-26|0x00c1
#define TestIndex 0                                                                       //11-02-26|0x00c1
#endif                                                                                    //11-02-26|0x00c1
//------------------------------------------------------------------------                //11-02-26|0x00c1
enum {  append_dict_get_cert_1 = TestIndex };                                             //11-02-26|0x00c1
//------------------------------------------------------------------------                //11-02-26|0x00c1
#undef TestIndex                                                                          //11-02-26|0x00c1
#define TestIndex append_dict_get_cert_1+1                                                //11-02-26|0x00c1
//************************************************************************                //11-02-26|0x00c1
#ifndef TestIndex                                                                         //06-09-06|0x00db
#define TestIndex 0                                                                       //06-09-06|0x00db
#endif                                                                                    //06-09-06|0x00db
//------------------------------------------------------------------------                //06-09-06|0x00db
enum {  apnd_dict_1 = TestIndex };                                                        //06-09-06|0x00db
//------------------------------------------------------------------------                //06-09-06|0x00db
#undef TestIndex                                                                          //06-09-06|0x00db
#define TestIndex apnd_dict_1+1                                                           //06-09-06|0x00db
//************************************************************************                //06-09-06|0x00db
//*******************************************************************************         //05-24-97|0x011c
//*******************************************************************************         //05-24-97|0x011c
//****                       END OF FILE                                     ****         //05-24-97|0x011c
//*******************************************************************************         //05-24-97|0x011c
//*******************************************************************************         //05-24-97|0x011c
#endif                                                                                    //05-24-97|0x011c
