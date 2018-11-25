//*****************************************************************************           //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//                                                                                        //07-04-16|0x000b
// DICTIONARY MANAGER UTILITY                                                             //07-04-16|0x000b
//                                                                                        //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-04-16|0x000b
//  defined in the associated manual.                                                     //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-04-16|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-04-16|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-04-16|0x000b
//  (at your option) any later version.                                                   //07-04-16|0x000b
//                                                                                        //07-04-16|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-04-16|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-04-16|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-04-16|0x000b
//  GNU General Public License for more details.                                          //07-04-16|0x000b
//                                                                                        //07-04-16|0x000b
//  You should have received a copy of the GNU General Public License                     //07-04-16|0x000b
//  along with this program; if not, write to the Free Software                           //07-04-16|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-04-16|0x000b
//  USA                                                                                   //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//  For further information, please contact Robert Adams:                                 //07-04-16|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-04-16|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-04-16|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
//*****************************************************************************           //07-04-16|0x000b
#ifndef basedictutil_hpp                                                                  //07-04-16|0x000c
#define basedictutil_hpp                                                                  //07-04-16|0x000c
//***************************************************************************             //07-04-16|0x0011
//***************************************************************************             //07-04-16|0x0012
//******                                                               ******             //07-04-16|0x0013
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //07-04-16|0x0014
//******                                                               ******             //07-04-16|0x0015
//***************************************************************************             //07-04-16|0x0016
//***************************************************************************             //07-04-16|0x0017
//***************************************************************************             //07-04-16|0x001a
//***************************************************************************             //07-04-16|0x001b
//******                                                               ******             //07-04-16|0x001c
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //07-04-16|0x001d
//******                                                               ******             //07-04-16|0x001e
//***************************************************************************             //07-04-16|0x001f
//***************************************************************************             //07-04-16|0x0020
#define UserError 0x0000                                                                  //07-04-16|0x0021
#define BuildError 0x7fff                                                                 //07-04-16|0x0021
#define Display 0x7ffe                                                                    //07-04-16|0x0021
#define KeyBoard 0x7ffd                                                                   //07-04-16|0x0021
#define Success 0xffff                                                                    //07-04-16|0x0021
#define SystemError 0x8000                                                                //07-04-16|0x0021
#define Continue 0x0001                                                                   //07-04-16|0x0021
#define FileDone 0x0002                                                                   //07-04-16|0x0021
#define LineDone 0x0003                                                                   //07-04-16|0x0021
#define Yes 0x0004                                                                        //07-04-16|0x0021
#define No 0x0005                                                                         //07-04-16|0x0021
#define RepeatChar '\x6'                                                                  //07-04-16|0x0021
#define Great 0x0007                                                                      //07-04-16|0x0021
#define Equal 0x0008                                                                      //07-04-16|0x0021
#define Less 0x0009                                                                       //07-04-16|0x0021
#define Zero 0x000a                                                                       //07-04-16|0x0021
#define Minus 0x000b                                                                      //07-04-16|0x0021
//***************************************************************************             //07-04-16|0x0022
#define SystemMsg PcgSystemError("Basedictutil", __LINE__);                               //07-04-16|0x0023
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-04-16|0x0023
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //07-04-16|0x0023
#define BreakFinish(_a) status = Finish(_a); break                                        //07-04-16|0x0024
#define ReturnFinish(_a) return(Finish(_a))                                               //07-04-16|0x0024
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //07-04-16|0x0024
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //07-04-16|0x0024
#define _SwitchErr case UserError: return(UserError)                                      //07-04-16|0x0025
#define _SwitchOk case Success: break                                                     //07-04-16|0x0025
#define _SwitchEnd default: ReturnSystemError                                             //07-04-16|0x0025
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-04-16|0x0025
#define _SwitchYes case Yes:      return(Yes)                                             //07-04-16|0x0025
#define _SwitchNo case No:       return(No)                                               //07-04-16|0x0025
#define _SwitchGroup { _SwitchBase; }                                                     //07-04-16|0x0025
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-04-16|0x0025
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-04-16|0x0025
#define _SwitchBreak _SwitchGroup break                                                   //07-04-16|0x0025
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-04-16|0x0025
//***************************************************************************             //07-04-16|0x0049
//***************************************************************************             //07-04-16|0x004a
//******                                                               ******             //07-04-16|0x004b
//******               GENERAL DEFINITION STATEMENTS                   ******             //07-04-16|0x004c
//******                                                               ******             //07-04-16|0x004d
//***************************************************************************             //07-04-16|0x004e
//***************************************************************************             //07-04-16|0x004f
#define TestSample(i) test_samples[i] = __LINE__                                          //07-04-16|0x0050
#define return_test(j) { TestSample(j);  return(Success); }                               //07-04-16|0x0050
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //07-04-16|0x0050
#define return_no(j) { TestSample(j);  return(No); }                                      //07-04-16|0x0050
#define goto_test(i) { TestSample(i);  goto loop; }                                       //07-04-16|0x0050
#define break_test(i) { TestSample(i);  break; }                                          //07-04-16|0x0050
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //07-04-16|0x0050
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //07-04-16|0x0050
//************************************************************************                //07-04-16|0x0050
#ifndef TestIndex                                                                         //07-04-16|0x0050
#define TestIndex 0                                                                       //07-04-16|0x0050
#endif                                                                                    //07-04-16|0x0050
//------------------------------------------------------------------------                //07-04-16|0x0050
enum {  NoTestSamples = TestIndex };                                                      //07-04-16|0x0050
//------------------------------------------------------------------------                //07-04-16|0x0050
#undef TestIndex                                                                          //07-04-16|0x0050
#define TestIndex NoTestSamples+1                                                         //07-04-16|0x0050
//************************************************************************                //07-04-16|0x0050
//***************************************************************************             //07-04-16|0x0051
//**********************************************************************                  //07-04-16|0x0052
#define DictSearchState Addr->search_state                                                //07-04-16|0x0052
#define DictProcessState Addr->process_state                                              //07-04-16|0x0052
#define DictFileState Addr->hash_record.file_state                                        //07-04-16|0x0052
#define DictRunFlag Addr->run_flag                                                        //07-04-16|0x0052
#define DictStatus Addr->status                                                           //07-04-16|0x0052
#define DictTextPlan Addr->text_plan                                                      //07-04-16|0x0052
#define DictHeaderPlan Addr->header_plan                                                  //07-04-16|0x0052
#define DictHash Addr->hash                                                               //07-04-16|0x0052
#define DictTextPosition Addr->text_position                                              //07-04-16|0x0052
#define DictCurrentOffset Addr->current_offset                                            //07-04-16|0x0052
#define DictCurrentBridge Addr->current_bridge                                            //07-04-16|0x0052
#define DictSearchOffset Addr->search_offset                                              //07-04-16|0x0052
#define DictSearchBridge Addr->search_bridge                                              //07-04-16|0x0052
#define DictLowerBridge Addr->lower_bridge                                                //07-04-16|0x0052
#define DictUpperBridge Addr->upper_bridge                                                //07-04-16|0x0052
#define DictHashRecord Addr->hash_record                                                  //07-04-16|0x0052
#define DictHeaderRecord Addr->header_record                                              //07-04-16|0x0052
#define DictTextRecord Addr->text_record                                                  //07-04-16|0x0052
#define DictFileData Addr->file_data                                                      //07-04-16|0x0052
//----------------------------------------------------------------------                  //07-04-16|0x0052
#define DictHeaderRecordAddr (SCHAR_FAR) &(Addr->header_record)                           //07-04-16|0x0052
#define DictHashRecordAddr (SCHAR_FAR) &(Addr->hash_record)                               //07-04-16|0x0052
#define DictTextRecordAddr (SCHAR_FAR) &(Addr->text_record)                               //07-04-16|0x0052
//**********************************************************************                  //07-04-16|0x0054
#define HashLastBridge(i) DictHashRecord.hash_element[i].last_bridge                      //07-04-16|0x0054
#define HashFirstBridge(i) DictHashRecord.hash_element[i].first_bridge                    //07-04-16|0x0054
#define HashLastOffset(i) DictHashRecord.hash_element[i].last_offset                      //07-04-16|0x0054
#define HashFirstOffset(i) DictHashRecord.hash_element[i].first_offset                    //07-04-16|0x0054
#define HashFirst(i) DictHashRecord.hash_element[i].first                                 //07-04-16|0x0054
#define HashLast(i) DictHashRecord.hash_element[i].last                                   //07-04-16|0x0054
//----------------------------------------------------------------------                  //07-04-16|0x0054
#define HashElementAddr(i) &(DictHashRecord.hash_element[i])                              //07-04-16|0x0054
#define HashFirstOffsetAddr(i) &(DictHashRecord.hash_element[i].first_offset)             //07-04-16|0x0054
#define HashLastOffsetAddr(i) &(DictHashRecord.hash_element[i].last_offset                //07-04-16|0x0054
#define HashFirstAddr(i) &(DictHashRecord.hash_element[i].first)                          //07-04-16|0x0054
#define HashLastAddr(i) &(DictHashRecord.hash_element[i].last)                            //07-04-16|0x0054
//**********************************************************************                  //07-04-16|0x0055
#define HeaderNextPosition DictHeaderRecord.next_position                                 //07-04-16|0x0055
#define HeaderCurrentPosition DictHeaderRecord.current_position                           //07-04-16|0x0055
#define HeaderNoArgs DictHeaderRecord.no_args                                             //07-04-16|0x0055
#define HeaderNamePosition(i) DictHeaderRecord.name_position[i]                           //07-04-16|0x0055
#define HeaderStartCol(i) DictHeaderRecord.start_col[i]                                   //07-04-16|0x0055
#define HeaderStartCall(i) DictHeaderRecord.start_call[i]                                 //07-04-16|0x0055
#define HeaderLineNo(i) DictHeaderRecord.line_no[i]                                       //07-04-16|0x0055
#define HeaderCommand DictHeaderRecord.command                                            //07-04-16|0x0055
//************************************************************************                //07-04-16|0x0056
#define TextHeader DictTextRecord.text_header                                             //07-04-16|0x0056
#define TextString DictTextRecord.text_char[0]                                            //07-04-16|0x0056
#define TextChar(i) DictTextRecord.text_char[i]                                           //07-04-16|0x0056
//------------------------------------------------------------------------                //07-04-16|0x0056
#define TextHeaderAddr (SCHAR_FAR) &(DictTextRecord.text_header)                          //07-04-16|0x0056
#define TextStringAddr &(DictTextRecord.text_char[0])                                     //07-04-16|0x0056
//************************************************************************                //07-04-16|0x0057
#define FileControl DictFileData.file_control                                             //07-04-16|0x0057
#define FilePosition DictFileData.file_position                                           //07-04-16|0x0057
#define FileLength DictFileData.file_length                                               //07-04-16|0x0057
//************************************************************************                //07-04-16|0x0059
#define TextLength TextHeader.length                                                      //07-04-16|0x0059
#define TextDeltaBridge TextHeader.delta_bridge                                           //07-04-16|0x0059
#define TextDeltaOffset TextHeader.delta_offset                                           //07-04-16|0x0059
#define TextNextPosition TextHeader.next_position                                         //07-04-16|0x0059
#define TextHeaderPosition TextHeader.header_position                                     //07-04-16|0x0059
#define TextCurrentPosition TextHeader.current_position                                   //07-04-16|0x0059
#define TextType TextHeader.type                                                          //07-04-16|0x0059
//***************************************************************************             //07-04-16|0x005a
#define InputChar(i) Input->line[i]                                                       //07-04-16|0x005b
#define InputLine Input->line[0]                                                          //07-04-16|0x005b
#define InputLineAddr &(Input->line[0])                                                   //07-04-16|0x005b
#define InputMacroLineNo Input->macro_line_no                                             //07-04-16|0x005b
#define InputType Input->type                                                             //07-04-16|0x005b
#define InputStartCol Input->start_col                                                    //07-04-16|0x005b
#define InputStartCall Input->start_call                                                  //07-04-16|0x005b
#define InputPosition Input->position                                                     //07-04-16|0x005b
#define InputLength Input->length                                                         //07-04-16|0x005b
#define InputColumn Input->column                                                         //07-04-16|0x005b
//**********************************************************************                  //07-04-16|0x005b
#define OutputChar(i) Output->line[i]                                                     //07-04-16|0x005c
#define OutputLine Output->line[0]                                                        //07-04-16|0x005c
#define OutputLineAddr &(Output->line[0])                                                 //07-04-16|0x005c
#define OutputMacroLineNo Output->macro_line_no                                           //07-04-16|0x005c
#define OutputType Output->type                                                           //07-04-16|0x005c
#define OutputStartCol Output->start_col                                                  //07-04-16|0x005c
#define OutputStartCall Output->start_call                                                //07-04-16|0x005c
#define OutputPosition Output->position                                                   //07-04-16|0x005c
#define OutputLength Output->length                                                       //07-04-16|0x005c
#define OutputColumn Output->column                                                       //07-04-16|0x005c
//**********************************************************************                  //07-04-16|0x005c
//**********************************************************************                  //07-04-16|0x005d
#define InputHashLastBridge(i) InputHashFar->hash_element[i].last_bridge                  //07-04-16|0x005d
#define InputHashFirstBridge(i) InputHashFar->hash_element[i].first_bridge                //07-04-16|0x005d
#define InputHashLastOffset(i) InputHashFar->hash_element[i].last_offset                  //07-04-16|0x005d
#define InputHashFirstOffset(i) InputHashFar->hash_element[i].first_offset                //07-04-16|0x005d
#define InputHashFirst(i) InputHashFar->hash_element[i].first                             //07-04-16|0x005d
#define InputHashLast(i) InputHashFar->hash_element[i].last                               //07-04-16|0x005d
//----------------------------------------------------------------------                  //07-04-16|0x005d
#define InputHashElementAddr(i) &(InputHashFar->hash_element[i])                          //07-04-16|0x005d
#define InputHashFirstOffsetAddr(i) &(InputHashFar->hash_element[i].first_offset)         //07-04-16|0x005d
#define InputHashLastOffsetAddr(i) &(InputHashFar->hash_element[i].last_offset            //07-04-16|0x005d
#define InputHashFirstAddr(i) &(InputHashFar->hash_element[i].first)                      //07-04-16|0x005d
#define InputHashLastAddr(i) &(InputHashFar->hash_element[i].last)                        //07-04-16|0x005d
//************************************************************************                //07-04-16|0x005e
#define RecordSizeUlong RecordFar->size.ulong                                             //07-04-16|0x005e
#define RecordSize RecordFar->size.word0                                                  //07-04-16|0x005e
#define RecordData(i) RecordFar->data[i]                                                  //07-04-16|0x005e
#define RecordDataAddr &(RecordFar->data[0])                                              //07-04-16|0x005e
//***************************************************************************             //07-04-16|0x005f
//********************************************************************                    //07-04-16|0x0060
#define BaseReadHash1(i1) FileReadData(i1,0,sizeof(DICT_HASH))                            //07-04-16|0x0060
#define BaseReadHash BaseReadHash1(DictHashRecordAddr)                                    //07-04-16|0x0060
//--------------------------------------------------------------------                    //07-04-16|0x0060
#define BaseWriteHash2(i2,i3) FileWriteData(0,  i2, i3)                                   //07-04-16|0x0060
#define BaseWriteHash1(i3) BaseWriteHash2(DictHashRecordAddr, i3)                         //07-04-16|0x0060
#define BaseWriteHash BaseWriteHash1(HashSize)                                            //07-04-16|0x0060
//********************************************************************                    //07-04-16|0x0060
#define BaseReadTextHeader2(i2,i3) FileReadData(TextHeaderAddr,i2,i3)                     //07-04-16|0x0060
#define BaseReadTextHeader1(i3) BaseReadTextHeader2(FilePosition,i3)                      //07-04-16|0x0060
#define BaseReadTextHeader BaseReadTextHeader1(TextHeaderSize)                            //07-04-16|0x0060
//--------------------------------------------------------------------                    //07-04-16|0x0060
#define BaseWriteTextHeader2(i2,i3) FileWriteData(FilePosition,i2,i3)                     //07-04-16|0x0060
#define BaseWriteTextHeader1(i3) BaseWriteTextHeader2(TextHeaderAddr,i3)                  //07-04-16|0x0060
#define BaseWriteTextHeader BaseWriteTextHeader1(TextHeaderSize)                          //07-04-16|0x0060
//********************************************************************                    //07-04-16|0x0060
#define BaseReadText2(i2,i3) FileReadData(TextStringAddr,i2,i3)                           //07-04-16|0x0060
#define BaseReadText1(i3) BaseReadText2(FilePosition,i3)                                  //07-04-16|0x0060
#define BaseReadText BaseReadText1(TextLength+1)                                          //07-04-16|0x0060
//----------------------------------------------------------------------                  //07-04-16|0x0060
#define BaseWriteText2(i2,i3) FileWriteData(FilePosition,i2,i3)                           //07-04-16|0x0060
#define BaseWriteText1(i3) BaseWriteText2(TextStringAddr,i3)                              //07-04-16|0x0060
#define BaseWriteText BaseWriteText1(TextLength+1)                                        //07-04-16|0x0060
//********************************************************************                    //07-04-16|0x0060
#define BaseWriteHeader2(i2,i3) FileWriteData(FilePosition,i2,i3)                         //07-04-16|0x0060
#define BaseWriteHeader1(i3) BaseWriteHeader2(DictHeaderRecordAddr,i3)                    //07-04-16|0x0060
#define BaseWriteHeader BaseWriteHeader1(sizeof(DICT_HEADER))                             //07-04-16|0x0060
//----------------------------------------------------------------------                  //07-04-16|0x0060
#define BaseReadHeader2(i2,i3) FileReadData(DictHeaderRecordAddr,i2,i3)                   //07-04-16|0x0060
#define BaseReadHeader1(i3) BaseReadHeader2(FilePosition,i3)                              //07-04-16|0x0060
#define BaseReadHeader BaseReadHeader1(sizeof(DICT_HEADER))                               //07-04-16|0x0060
//********************************************************************                    //07-04-16|0x0060
#define BaseReadRecord2(i2,i3) FileReadData(RecordDataAddr,i2,i3)                         //07-04-16|0x0060
#define BaseReadRecord1(i3) BaseReadRecord2(FilePosition,i3)                              //07-04-16|0x0060
#define BaseReadRecord BaseReadRecord1(RecordSize)                                        //07-04-16|0x0060
//----------------------------------------------------------------------                  //07-04-16|0x0060
#define BaseWriteRecord2(i2,i3) FileWriteData(FileLength,i2,i3)                           //07-04-16|0x0060
#define BaseWriteRecord1(i3) BaseWriteRecord2(RecordDataAddr,i3)                          //07-04-16|0x0060
#define BaseWriteRecord BaseWriteRecord1(RecordSize)                                      //07-04-16|0x0060
//**********************************************************************                  //07-04-16|0x0060
//**********************************************************************                  //07-04-16|0x0060
#ifndef TestIndex                                                                         //07-01-17|0x006a
#define TestIndex 0                                                                       //07-01-17|0x006a
#endif                                                                                    //07-01-17|0x006a
//------------------------------------------------------------------------                //07-01-17|0x006a
enum {  dict_name_1 = TestIndex };                                                        //07-01-17|0x006a
//------------------------------------------------------------------------                //07-01-17|0x006a
#undef TestIndex                                                                          //07-01-17|0x006a
#define TestIndex dict_name_1+1                                                           //07-01-17|0x006a
//************************************************************************                //07-01-17|0x006a
#ifndef TestIndex                                                                         //07-01-17|0x0084
#define TestIndex 0                                                                       //07-01-17|0x0084
#endif                                                                                    //07-01-17|0x0084
//------------------------------------------------------------------------                //07-01-17|0x0084
enum {  dict_exists_1 = TestIndex };                                                      //07-01-17|0x0084
//------------------------------------------------------------------------                //07-01-17|0x0084
#undef TestIndex                                                                          //07-01-17|0x0084
#define TestIndex dict_exists_1+1                                                         //07-01-17|0x0084
//************************************************************************                //07-01-17|0x0084
#ifndef TestIndex                                                                         //07-01-17|0x0085
#define TestIndex 0                                                                       //07-01-17|0x0085
#endif                                                                                    //07-01-17|0x0085
//------------------------------------------------------------------------                //07-01-17|0x0085
enum {  dict_exists_2 = TestIndex };                                                      //07-01-17|0x0085
//------------------------------------------------------------------------                //07-01-17|0x0085
#undef TestIndex                                                                          //07-01-17|0x0085
#define TestIndex dict_exists_2+1                                                         //07-01-17|0x0085
//************************************************************************                //07-01-17|0x0085
#ifndef TestIndex                                                                         //07-01-17|0x00a1
#define TestIndex 0                                                                       //07-01-17|0x00a1
#endif                                                                                    //07-01-17|0x00a1
//------------------------------------------------------------------------                //07-01-17|0x00a1
enum {  initial_process_1 = TestIndex };                                                  //07-01-17|0x00a1
//------------------------------------------------------------------------                //07-01-17|0x00a1
#undef TestIndex                                                                          //07-01-17|0x00a1
#define TestIndex initial_process_1+1                                                     //07-01-17|0x00a1
//************************************************************************                //07-01-17|0x00a1
#ifndef TestIndex                                                                         //07-01-17|0x00be
#define TestIndex 0                                                                       //07-01-17|0x00be
#endif                                                                                    //07-01-17|0x00be
//------------------------------------------------------------------------                //07-01-17|0x00be
enum {  init_hash_1 = TestIndex };                                                        //07-01-17|0x00be
//------------------------------------------------------------------------                //07-01-17|0x00be
#undef TestIndex                                                                          //07-01-17|0x00be
#define TestIndex init_hash_1+1                                                           //07-01-17|0x00be
//************************************************************************                //07-01-17|0x00be
#ifndef TestIndex                                                                         //07-01-17|0x00df
#define TestIndex 0                                                                       //07-01-17|0x00df
#endif                                                                                    //07-01-17|0x00df
//------------------------------------------------------------------------                //07-01-17|0x00df
enum {  create_dict_1 = TestIndex };                                                      //07-01-17|0x00df
//------------------------------------------------------------------------                //07-01-17|0x00df
#undef TestIndex                                                                          //07-01-17|0x00df
#define TestIndex create_dict_1+1                                                         //07-01-17|0x00df
//************************************************************************                //07-01-17|0x00df
#ifndef TestIndex                                                                         //07-01-18|0x00fe
#define TestIndex 0                                                                       //07-01-18|0x00fe
#endif                                                                                    //07-01-18|0x00fe
//------------------------------------------------------------------------                //07-01-18|0x00fe
enum {  append_dict_1 = TestIndex };                                                      //07-01-18|0x00fe
//------------------------------------------------------------------------                //07-01-18|0x00fe
#undef TestIndex                                                                          //07-01-18|0x00fe
#define TestIndex append_dict_1+1                                                         //07-01-18|0x00fe
//************************************************************************                //07-01-18|0x00fe
#ifndef TestIndex                                                                         //07-01-23|0x011d
#define TestIndex 0                                                                       //07-01-23|0x011d
#endif                                                                                    //07-01-23|0x011d
//------------------------------------------------------------------------                //07-01-23|0x011d
enum {  read_dict_1 = TestIndex };                                                        //07-01-23|0x011d
//------------------------------------------------------------------------                //07-01-23|0x011d
#undef TestIndex                                                                          //07-01-23|0x011d
#define TestIndex read_dict_1+1                                                           //07-01-23|0x011d
//************************************************************************                //07-01-23|0x011d
#ifndef TestIndex                                                                         //07-01-18|0x013c
#define TestIndex 0                                                                       //07-01-18|0x013c
#endif                                                                                    //07-01-18|0x013c
//------------------------------------------------------------------------                //07-01-18|0x013c
enum {  read_hash_1 = TestIndex };                                                        //07-01-18|0x013c
//------------------------------------------------------------------------                //07-01-18|0x013c
#undef TestIndex                                                                          //07-01-18|0x013c
#define TestIndex read_hash_1+1                                                           //07-01-18|0x013c
//************************************************************************                //07-01-18|0x013c
#ifndef TestIndex                                                                         //07-01-17|0x0156
#define TestIndex 0                                                                       //07-01-17|0x0156
#endif                                                                                    //07-01-17|0x0156
//------------------------------------------------------------------------                //07-01-17|0x0156
enum {  write_hash_1 = TestIndex };                                                       //07-01-17|0x0156
//------------------------------------------------------------------------                //07-01-17|0x0156
#undef TestIndex                                                                          //07-01-17|0x0156
#define TestIndex write_hash_1+1                                                          //07-01-17|0x0156
//************************************************************************                //07-01-17|0x0156
#ifndef TestIndex                                                                         //07-01-18|0x0175
#define TestIndex 0                                                                       //07-01-18|0x0175
#endif                                                                                    //07-01-18|0x0175
//------------------------------------------------------------------------                //07-01-18|0x0175
enum {  verify_hash_1 = TestIndex };                                                      //07-01-18|0x0175
//------------------------------------------------------------------------                //07-01-18|0x0175
#undef TestIndex                                                                          //07-01-18|0x0175
#define TestIndex verify_hash_1+1                                                         //07-01-18|0x0175
//************************************************************************                //07-01-18|0x0175
#ifndef TestIndex                                                                         //07-01-17|0x01a1
#define TestIndex 0                                                                       //07-01-17|0x01a1
#endif                                                                                    //07-01-17|0x01a1
//------------------------------------------------------------------------                //07-01-17|0x01a1
enum {  plan_1 = TestIndex };                                                             //07-01-17|0x01a1
//------------------------------------------------------------------------                //07-01-17|0x01a1
#undef TestIndex                                                                          //07-01-17|0x01a1
#define TestIndex plan_1+1                                                                //07-01-17|0x01a1
//************************************************************************                //07-01-17|0x01a1
#ifndef TestIndex                                                                         //07-01-17|0x01d3
#define TestIndex 0                                                                       //07-01-17|0x01d3
#endif                                                                                    //07-01-17|0x01d3
//------------------------------------------------------------------------                //07-01-17|0x01d3
enum {  initial_text_1 = TestIndex };                                                     //07-01-17|0x01d3
//------------------------------------------------------------------------                //07-01-17|0x01d3
#undef TestIndex                                                                          //07-01-17|0x01d3
#define TestIndex initial_text_1+1                                                        //07-01-17|0x01d3
//************************************************************************                //07-01-17|0x01d3
#ifndef TestIndex                                                                         //07-01-17|0x01f0
#define TestIndex 0                                                                       //07-01-17|0x01f0
#endif                                                                                    //07-01-17|0x01f0
//------------------------------------------------------------------------                //07-01-17|0x01f0
enum {  load_text_1 = TestIndex };                                                        //07-01-17|0x01f0
//------------------------------------------------------------------------                //07-01-17|0x01f0
#undef TestIndex                                                                          //07-01-17|0x01f0
#define TestIndex load_text_1+1                                                           //07-01-17|0x01f0
//************************************************************************                //07-01-17|0x01f0
#ifndef TestIndex                                                                         //07-01-17|0x021e
#define TestIndex 0                                                                       //07-01-17|0x021e
#endif                                                                                    //07-01-17|0x021e
//------------------------------------------------------------------------                //07-01-17|0x021e
enum {  update_hash_1 = TestIndex };                                                      //07-01-17|0x021e
//------------------------------------------------------------------------                //07-01-17|0x021e
#undef TestIndex                                                                          //07-01-17|0x021e
#define TestIndex update_hash_1+1                                                         //07-01-17|0x021e
//************************************************************************                //07-01-17|0x021e
#ifndef TestIndex                                                                         //07-01-17|0x0240
#define TestIndex 0                                                                       //07-01-17|0x0240
#endif                                                                                    //07-01-17|0x0240
//------------------------------------------------------------------------                //07-01-17|0x0240
enum {  link_header_text_1 = TestIndex };                                                 //07-01-17|0x0240
//------------------------------------------------------------------------                //07-01-17|0x0240
#undef TestIndex                                                                          //07-01-17|0x0240
#define TestIndex link_header_text_1+1                                                    //07-01-17|0x0240
//************************************************************************                //07-01-17|0x0240
#ifndef TestIndex                                                                         //07-01-17|0x025b
#define TestIndex 0                                                                       //07-01-17|0x025b
#endif                                                                                    //07-01-17|0x025b
//------------------------------------------------------------------------                //07-01-17|0x025b
enum {  write_text_header_1 = TestIndex };                                                //07-01-17|0x025b
//------------------------------------------------------------------------                //07-01-17|0x025b
#undef TestIndex                                                                          //07-01-17|0x025b
#define TestIndex write_text_header_1+1                                                   //07-01-17|0x025b
//************************************************************************                //07-01-17|0x025b
#ifndef TestIndex                                                                         //07-01-17|0x0287
#define TestIndex 0                                                                       //07-01-17|0x0287
#endif                                                                                    //07-01-17|0x0287
//------------------------------------------------------------------------                //07-01-17|0x0287
enum {  write_text_1 = TestIndex };                                                       //07-01-17|0x0287
//------------------------------------------------------------------------                //07-01-17|0x0287
#undef TestIndex                                                                          //07-01-17|0x0287
#define TestIndex write_text_1+1                                                          //07-01-17|0x0287
//************************************************************************                //07-01-17|0x0287
#ifndef TestIndex                                                                         //07-01-17|0x02b1
#define TestIndex 0                                                                       //07-01-17|0x02b1
#endif                                                                                    //07-01-17|0x02b1
//------------------------------------------------------------------------                //07-01-17|0x02b1
enum {  initial_header_1 = TestIndex };                                                   //07-01-17|0x02b1
//------------------------------------------------------------------------                //07-01-17|0x02b1
#undef TestIndex                                                                          //07-01-17|0x02b1
#define TestIndex initial_header_1+1                                                      //07-01-17|0x02b1
//************************************************************************                //07-01-17|0x02b1
#ifndef TestIndex                                                                         //07-01-17|0x02d8
#define TestIndex 0                                                                       //07-01-17|0x02d8
#endif                                                                                    //07-01-17|0x02d8
//------------------------------------------------------------------------                //07-01-17|0x02d8
enum {  add_arg_header_1 = TestIndex };                                                   //07-01-17|0x02d8
//------------------------------------------------------------------------                //07-01-17|0x02d8
#undef TestIndex                                                                          //07-01-17|0x02d8
#define TestIndex add_arg_header_1+1                                                      //07-01-17|0x02d8
//************************************************************************                //07-01-17|0x02d8
#ifndef TestIndex                                                                         //07-01-17|0x02f6
#define TestIndex 0                                                                       //07-01-17|0x02f6
#endif                                                                                    //07-01-17|0x02f6
//------------------------------------------------------------------------                //07-01-17|0x02f6
enum {  link_header_next_1 = TestIndex };                                                 //07-01-17|0x02f6
//------------------------------------------------------------------------                //07-01-17|0x02f6
#undef TestIndex                                                                          //07-01-17|0x02f6
#define TestIndex link_header_next_1+1                                                    //07-01-17|0x02f6
//************************************************************************                //07-01-17|0x02f6
#ifndef TestIndex                                                                         //07-01-17|0x0310
#define TestIndex 0                                                                       //07-01-17|0x0310
#endif                                                                                    //07-01-17|0x0310
//------------------------------------------------------------------------                //07-01-17|0x0310
enum {  write_header_1 = TestIndex };                                                     //07-01-17|0x0310
//------------------------------------------------------------------------                //07-01-17|0x0310
#undef TestIndex                                                                          //07-01-17|0x0310
#define TestIndex write_header_1+1                                                        //07-01-17|0x0310
//************************************************************************                //07-01-17|0x0310
#ifndef TestIndex                                                                         //07-01-17|0x033f
#define TestIndex 0                                                                       //07-01-17|0x033f
#endif                                                                                    //07-01-17|0x033f
//------------------------------------------------------------------------                //07-01-17|0x033f
enum {  create_hash_1 = TestIndex };                                                      //07-01-17|0x033f
//------------------------------------------------------------------------                //07-01-17|0x033f
#undef TestIndex                                                                          //07-01-17|0x033f
#define TestIndex create_hash_1+1                                                         //07-01-17|0x033f
//************************************************************************                //07-01-17|0x033f
#ifndef TestIndex                                                                         //07-01-17|0x037b
#define TestIndex 0                                                                       //07-01-17|0x037b
#endif                                                                                    //07-01-17|0x037b
//------------------------------------------------------------------------                //07-01-17|0x037b
enum {  test_hash_1 = TestIndex };                                                        //07-01-17|0x037b
//------------------------------------------------------------------------                //07-01-17|0x037b
#undef TestIndex                                                                          //07-01-17|0x037b
#define TestIndex test_hash_1+1                                                           //07-01-17|0x037b
//************************************************************************                //07-01-17|0x037b
#ifndef TestIndex                                                                         //07-01-17|0x037c
#define TestIndex 0                                                                       //07-01-17|0x037c
#endif                                                                                    //07-01-17|0x037c
//------------------------------------------------------------------------                //07-01-17|0x037c
enum {  test_hash_2 = TestIndex };                                                        //07-01-17|0x037c
//------------------------------------------------------------------------                //07-01-17|0x037c
#undef TestIndex                                                                          //07-01-17|0x037c
#define TestIndex test_hash_2+1                                                           //07-01-17|0x037c
//************************************************************************                //07-01-17|0x037c
#ifndef TestIndex                                                                         //07-01-17|0x039b
#define TestIndex 0                                                                       //07-01-17|0x039b
#endif                                                                                    //07-01-17|0x039b
//------------------------------------------------------------------------                //07-01-17|0x039b
enum {  read_text_header_1 = TestIndex };                                                 //07-01-17|0x039b
//------------------------------------------------------------------------                //07-01-17|0x039b
#undef TestIndex                                                                          //07-01-17|0x039b
#define TestIndex read_text_header_1+1                                                    //07-01-17|0x039b
//************************************************************************                //07-01-17|0x039b
#ifndef TestIndex                                                                         //07-01-17|0x03bc
#define TestIndex 0                                                                       //07-01-17|0x03bc
#endif                                                                                    //07-01-17|0x03bc
//------------------------------------------------------------------------                //07-01-17|0x03bc
enum {  read_text_1 = TestIndex };                                                        //07-01-17|0x03bc
//------------------------------------------------------------------------                //07-01-17|0x03bc
#undef TestIndex                                                                          //07-01-17|0x03bc
#define TestIndex read_text_1+1                                                           //07-01-17|0x03bc
//************************************************************************                //07-01-17|0x03bc
#ifndef TestIndex                                                                         //07-01-17|0x03e7
#define TestIndex 0                                                                       //07-01-17|0x03e7
#endif                                                                                    //07-01-17|0x03e7
//------------------------------------------------------------------------                //07-01-17|0x03e7
enum {  test_name_1 = TestIndex };                                                        //07-01-17|0x03e7
//------------------------------------------------------------------------                //07-01-17|0x03e7
#undef TestIndex                                                                          //07-01-17|0x03e7
#define TestIndex test_name_1+1                                                           //07-01-17|0x03e7
//************************************************************************                //07-01-17|0x03e7
#ifndef TestIndex                                                                         //07-01-17|0x03e8
#define TestIndex 0                                                                       //07-01-17|0x03e8
#endif                                                                                    //07-01-17|0x03e8
//------------------------------------------------------------------------                //07-01-17|0x03e8
enum {  test_name_2 = TestIndex };                                                        //07-01-17|0x03e8
//------------------------------------------------------------------------                //07-01-17|0x03e8
#undef TestIndex                                                                          //07-01-17|0x03e8
#define TestIndex test_name_2+1                                                           //07-01-17|0x03e8
//************************************************************************                //07-01-17|0x03e8
#ifndef TestIndex                                                                         //07-01-18|0x0420
#define TestIndex 0                                                                       //07-01-18|0x0420
#endif                                                                                    //07-01-18|0x0420
//------------------------------------------------------------------------                //07-01-18|0x0420
enum {  next_dict_1 = TestIndex };                                                        //07-01-18|0x0420
//------------------------------------------------------------------------                //07-01-18|0x0420
#undef TestIndex                                                                          //07-01-18|0x0420
#define TestIndex next_dict_1+1                                                           //07-01-18|0x0420
//************************************************************************                //07-01-18|0x0420
#ifndef TestIndex                                                                         //07-01-18|0x0421
#define TestIndex 0                                                                       //07-01-18|0x0421
#endif                                                                                    //07-01-18|0x0421
//------------------------------------------------------------------------                //07-01-18|0x0421
enum {  next_dict_2 = TestIndex };                                                        //07-01-18|0x0421
//------------------------------------------------------------------------                //07-01-18|0x0421
#undef TestIndex                                                                          //07-01-18|0x0421
#define TestIndex next_dict_2+1                                                           //07-01-18|0x0421
//************************************************************************                //07-01-18|0x0421
#ifndef TestIndex                                                                         //07-01-24|0x043f
#define TestIndex 0                                                                       //07-01-24|0x043f
#endif                                                                                    //07-01-24|0x043f
//------------------------------------------------------------------------                //07-01-24|0x043f
enum {  read_header_1 = TestIndex };                                                      //07-01-24|0x043f
//------------------------------------------------------------------------                //07-01-24|0x043f
#undef TestIndex                                                                          //07-01-24|0x043f
#define TestIndex read_header_1+1                                                         //07-01-24|0x043f
//************************************************************************                //07-01-24|0x043f
#ifndef TestIndex                                                                         //07-01-24|0x045f
#define TestIndex 0                                                                       //07-01-24|0x045f
#endif                                                                                    //07-01-24|0x045f
//------------------------------------------------------------------------                //07-01-24|0x045f
enum {  prepare_arg_read_1 = TestIndex };                                                 //07-01-24|0x045f
//------------------------------------------------------------------------                //07-01-24|0x045f
#undef TestIndex                                                                          //07-01-24|0x045f
#define TestIndex prepare_arg_read_1+1                                                    //07-01-24|0x045f
//************************************************************************                //07-01-24|0x045f
#ifndef TestIndex                                                                         //07-01-24|0x047e
#define TestIndex 0                                                                       //07-01-24|0x047e
#endif                                                                                    //07-01-24|0x047e
//------------------------------------------------------------------------                //07-01-24|0x047e
enum {  test_arg_1 = TestIndex };                                                         //07-01-24|0x047e
//------------------------------------------------------------------------                //07-01-24|0x047e
#undef TestIndex                                                                          //07-01-24|0x047e
#define TestIndex test_arg_1+1                                                            //07-01-24|0x047e
//************************************************************************                //07-01-24|0x047e
#ifndef TestIndex                                                                         //07-01-24|0x047f
#define TestIndex 0                                                                       //07-01-24|0x047f
#endif                                                                                    //07-01-24|0x047f
//------------------------------------------------------------------------                //07-01-24|0x047f
enum {  test_arg_2 = TestIndex };                                                         //07-01-24|0x047f
//------------------------------------------------------------------------                //07-01-24|0x047f
#undef TestIndex                                                                          //07-01-24|0x047f
#define TestIndex test_arg_2+1                                                            //07-01-24|0x047f
//************************************************************************                //07-01-24|0x047f
#ifndef TestIndex                                                                         //07-01-24|0x04a1
#define TestIndex 0                                                                       //07-01-24|0x04a1
#endif                                                                                    //07-01-24|0x04a1
//------------------------------------------------------------------------                //07-01-24|0x04a1
enum {  get_arg_1 = TestIndex };                                                          //07-01-24|0x04a1
//------------------------------------------------------------------------                //07-01-24|0x04a1
#undef TestIndex                                                                          //07-01-24|0x04a1
#define TestIndex get_arg_1+1                                                             //07-01-24|0x04a1
//************************************************************************                //07-01-24|0x04a1
#ifndef TestIndex                                                                         //07-01-24|0x04d3
#define TestIndex 0                                                                       //07-01-24|0x04d3
#endif                                                                                    //07-01-24|0x04d3
//------------------------------------------------------------------------                //07-01-24|0x04d3
enum {  arg_update_1 = TestIndex };                                                       //07-01-24|0x04d3
//------------------------------------------------------------------------                //07-01-24|0x04d3
#undef TestIndex                                                                          //07-01-24|0x04d3
#define TestIndex arg_update_1+1                                                          //07-01-24|0x04d3
//************************************************************************                //07-01-24|0x04d3
#ifndef TestIndex                                                                         //07-01-18|0x04f5
#define TestIndex 0                                                                       //07-01-18|0x04f5
#endif                                                                                    //07-01-18|0x04f5
//------------------------------------------------------------------------                //07-01-18|0x04f5
enum {  test_hash_empty_1 = TestIndex };                                                  //07-01-18|0x04f5
//------------------------------------------------------------------------                //07-01-18|0x04f5
#undef TestIndex                                                                          //07-01-18|0x04f5
#define TestIndex test_hash_empty_1+1                                                     //07-01-18|0x04f5
//************************************************************************                //07-01-18|0x04f5
#ifndef TestIndex                                                                         //07-01-18|0x04f6
#define TestIndex 0                                                                       //07-01-18|0x04f6
#endif                                                                                    //07-01-18|0x04f6
//------------------------------------------------------------------------                //07-01-18|0x04f6
enum {  test_hash_empty_2 = TestIndex };                                                  //07-01-18|0x04f6
//------------------------------------------------------------------------                //07-01-18|0x04f6
#undef TestIndex                                                                          //07-01-18|0x04f6
#define TestIndex test_hash_empty_2+1                                                     //07-01-18|0x04f6
//************************************************************************                //07-01-18|0x04f6
#ifndef TestIndex                                                                         //07-01-18|0x0513
#define TestIndex 0                                                                       //07-01-18|0x0513
#endif                                                                                    //07-01-18|0x0513
//------------------------------------------------------------------------                //07-01-18|0x0513
enum {  prep_hash_update_1 = TestIndex };                                                 //07-01-18|0x0513
//------------------------------------------------------------------------                //07-01-18|0x0513
#undef TestIndex                                                                          //07-01-18|0x0513
#define TestIndex prep_hash_update_1+1                                                    //07-01-18|0x0513
//************************************************************************                //07-01-18|0x0513
#ifndef TestIndex                                                                         //07-01-18|0x0514
#define TestIndex 0                                                                       //07-01-18|0x0514
#endif                                                                                    //07-01-18|0x0514
//------------------------------------------------------------------------                //07-01-18|0x0514
enum {  prep_hash_update_2 = TestIndex };                                                 //07-01-18|0x0514
//------------------------------------------------------------------------                //07-01-18|0x0514
#undef TestIndex                                                                          //07-01-18|0x0514
#define TestIndex prep_hash_update_2+1                                                    //07-01-18|0x0514
//************************************************************************                //07-01-18|0x0514
#ifndef TestIndex                                                                         //07-01-18|0x0535
#define TestIndex 0                                                                       //07-01-18|0x0535
#endif                                                                                    //07-01-18|0x0535
//------------------------------------------------------------------------                //07-01-18|0x0535
enum {  update_delta_offset_1 = TestIndex };                                              //07-01-18|0x0535
//------------------------------------------------------------------------                //07-01-18|0x0535
#undef TestIndex                                                                          //07-01-18|0x0535
#define TestIndex update_delta_offset_1+1                                                 //07-01-18|0x0535
//************************************************************************                //07-01-18|0x0535
#ifndef TestIndex                                                                         //07-01-18|0x0536
#define TestIndex 0                                                                       //07-01-18|0x0536
#endif                                                                                    //07-01-18|0x0536
//------------------------------------------------------------------------                //07-01-18|0x0536
enum {  update_delta_offset_2 = TestIndex };                                              //07-01-18|0x0536
//------------------------------------------------------------------------                //07-01-18|0x0536
#undef TestIndex                                                                          //07-01-18|0x0536
#define TestIndex update_delta_offset_2+1                                                 //07-01-18|0x0536
//************************************************************************                //07-01-18|0x0536
#ifndef TestIndex                                                                         //07-01-23|0x0560
#define TestIndex 0                                                                       //07-01-23|0x0560
#endif                                                                                    //07-01-23|0x0560
//------------------------------------------------------------------------                //07-01-23|0x0560
enum {  hash_state_1 = TestIndex };                                                       //07-01-23|0x0560
//------------------------------------------------------------------------                //07-01-23|0x0560
#undef TestIndex                                                                          //07-01-23|0x0560
#define TestIndex hash_state_1+1                                                          //07-01-23|0x0560
//************************************************************************                //07-01-23|0x0560
#ifndef TestIndex                                                                         //07-01-23|0x0561
#define TestIndex 0                                                                       //07-01-23|0x0561
#endif                                                                                    //07-01-23|0x0561
//------------------------------------------------------------------------                //07-01-23|0x0561
enum {  hash_state_2 = TestIndex };                                                       //07-01-23|0x0561
//------------------------------------------------------------------------                //07-01-23|0x0561
#undef TestIndex                                                                          //07-01-23|0x0561
#define TestIndex hash_state_2+1                                                          //07-01-23|0x0561
//************************************************************************                //07-01-23|0x0561
#ifndef TestIndex                                                                         //07-01-23|0x058a
#define TestIndex 0                                                                       //07-01-23|0x058a
#endif                                                                                    //07-01-23|0x058a
//------------------------------------------------------------------------                //07-01-23|0x058a
enum {  copy_hash_1 = TestIndex };                                                        //07-01-23|0x058a
//------------------------------------------------------------------------                //07-01-23|0x058a
#undef TestIndex                                                                          //07-01-23|0x058a
#define TestIndex copy_hash_1+1                                                           //07-01-23|0x058a
//************************************************************************                //07-01-23|0x058a
#ifndef TestIndex                                                                         //07-01-23|0x05a3
#define TestIndex 0                                                                       //07-01-23|0x05a3
#endif                                                                                    //07-01-23|0x05a3
//------------------------------------------------------------------------                //07-01-23|0x05a3
enum {  first_hash_1 = TestIndex };                                                       //07-01-23|0x05a3
//------------------------------------------------------------------------                //07-01-23|0x05a3
#undef TestIndex                                                                          //07-01-23|0x05a3
#define TestIndex first_hash_1+1                                                          //07-01-23|0x05a3
//************************************************************************                //07-01-23|0x05a3
#ifndef TestIndex                                                                         //07-01-23|0x05c3
#define TestIndex 0                                                                       //07-01-23|0x05c3
#endif                                                                                    //07-01-23|0x05c3
//------------------------------------------------------------------------                //07-01-23|0x05c3
enum {  last_hash_1 = TestIndex };                                                        //07-01-23|0x05c3
//------------------------------------------------------------------------                //07-01-23|0x05c3
#undef TestIndex                                                                          //07-01-23|0x05c3
#define TestIndex last_hash_1+1                                                           //07-01-23|0x05c3
//************************************************************************                //07-01-23|0x05c3
#ifndef TestIndex                                                                         //07-01-23|0x05e3
#define TestIndex 0                                                                       //07-01-23|0x05e3
#endif                                                                                    //07-01-23|0x05e3
//------------------------------------------------------------------------                //07-01-23|0x05e3
enum {  connect_text_1 = TestIndex };                                                     //07-01-23|0x05e3
//------------------------------------------------------------------------                //07-01-23|0x05e3
#undef TestIndex                                                                          //07-01-23|0x05e3
#define TestIndex connect_text_1+1                                                        //07-01-23|0x05e3
//************************************************************************                //07-01-23|0x05e3
#ifndef TestIndex                                                                         //07-01-24|0x060f
#define TestIndex 0                                                                       //07-01-24|0x060f
#endif                                                                                    //07-01-24|0x060f
//------------------------------------------------------------------------                //07-01-24|0x060f
enum {  write_record_1 = TestIndex };                                                     //07-01-24|0x060f
//------------------------------------------------------------------------                //07-01-24|0x060f
#undef TestIndex                                                                          //07-01-24|0x060f
#define TestIndex write_record_1+1                                                        //07-01-24|0x060f
//************************************************************************                //07-01-24|0x060f
#ifndef TestIndex                                                                         //07-01-23|0x062f
#define TestIndex 0                                                                       //07-01-23|0x062f
#endif                                                                                    //07-01-23|0x062f
//------------------------------------------------------------------------                //07-01-23|0x062f
enum {  read_record_1 = TestIndex };                                                      //07-01-23|0x062f
//------------------------------------------------------------------------                //07-01-23|0x062f
#undef TestIndex                                                                          //07-01-23|0x062f
#define TestIndex read_record_1+1                                                         //07-01-23|0x062f
//************************************************************************                //07-01-23|0x062f
#ifndef TestIndex                                                                         //07-01-23|0x0630
#define TestIndex 0                                                                       //07-01-23|0x0630
#endif                                                                                    //07-01-23|0x0630
//------------------------------------------------------------------------                //07-01-23|0x0630
enum {  read_record_2 = TestIndex };                                                      //07-01-23|0x0630
//------------------------------------------------------------------------                //07-01-23|0x0630
#undef TestIndex                                                                          //07-01-23|0x0630
#define TestIndex read_record_2+1                                                         //07-01-23|0x0630
//************************************************************************                //07-01-23|0x0630
#ifndef TestIndex                                                                         //07-01-23|0x0659
#define TestIndex 0                                                                       //07-01-23|0x0659
#endif                                                                                    //07-01-23|0x0659
//------------------------------------------------------------------------                //07-01-23|0x0659
enum {  bridge_offset_1 = TestIndex };                                                    //07-01-23|0x0659
//------------------------------------------------------------------------                //07-01-23|0x0659
#undef TestIndex                                                                          //07-01-23|0x0659
#define TestIndex bridge_offset_1+1                                                       //07-01-23|0x0659
//************************************************************************                //07-01-23|0x0659
#ifndef TestIndex                                                                         //07-01-23|0x0683
#define TestIndex 0                                                                       //07-01-23|0x0683
#endif                                                                                    //07-01-23|0x0683
//------------------------------------------------------------------------                //07-01-23|0x0683
enum {  test_bridge_1 = TestIndex };                                                      //07-01-23|0x0683
//------------------------------------------------------------------------                //07-01-23|0x0683
#undef TestIndex                                                                          //07-01-23|0x0683
#define TestIndex test_bridge_1+1                                                         //07-01-23|0x0683
//************************************************************************                //07-01-23|0x0683
#ifndef TestIndex                                                                         //07-01-23|0x0684
#define TestIndex 0                                                                       //07-01-23|0x0684
#endif                                                                                    //07-01-23|0x0684
//------------------------------------------------------------------------                //07-01-23|0x0684
enum {  test_bridge_2 = TestIndex };                                                      //07-01-23|0x0684
//------------------------------------------------------------------------                //07-01-23|0x0684
#undef TestIndex                                                                          //07-01-23|0x0684
#define TestIndex test_bridge_2+1                                                         //07-01-23|0x0684
//************************************************************************                //07-01-23|0x0684
#ifndef TestIndex                                                                         //07-01-18|0x06cb
#define TestIndex 0                                                                       //07-01-18|0x06cb
#endif                                                                                    //07-01-18|0x06cb
//------------------------------------------------------------------------                //07-01-18|0x06cb
enum {  close_dict_1 = TestIndex };                                                       //07-01-18|0x06cb
//------------------------------------------------------------------------                //07-01-18|0x06cb
#undef TestIndex                                                                          //07-01-18|0x06cb
#define TestIndex close_dict_1+1                                                          //07-01-18|0x06cb
//************************************************************************                //07-01-18|0x06cb
#ifndef TestIndex                                                                         //07-01-25|0x06e7
#define TestIndex 0                                                                       //07-01-25|0x06e7
#endif                                                                                    //07-01-25|0x06e7
//------------------------------------------------------------------------                //07-01-25|0x06e7
enum {  delete_dict_1 = TestIndex };                                                      //07-01-25|0x06e7
//------------------------------------------------------------------------                //07-01-25|0x06e7
#undef TestIndex                                                                          //07-01-25|0x06e7
#define TestIndex delete_dict_1+1                                                         //07-01-25|0x06e7
//************************************************************************                //07-01-25|0x06e7
//*******************************************************************************         //05-24-97|0x0721
//*******************************************************************************         //05-24-97|0x0721
//****                       END OF FILE                                     ****         //05-24-97|0x0721
//*******************************************************************************         //05-24-97|0x0721
//*******************************************************************************         //05-24-97|0x0721
#endif                                                                                    //05-24-97|0x0721
