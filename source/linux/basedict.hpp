//*****************************************************************************           //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//                                                                                        //07-03-21|0x000b
// PRECEDENCE DICTIONARY_MANAGER                                                          //07-03-21|0x000b
//                                                                                        //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-03-21|0x000b
//  defined in the associated manual.                                                     //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-03-21|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-03-21|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-03-21|0x000b
//  (at your option) any later version.                                                   //07-03-21|0x000b
//                                                                                        //07-03-21|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-03-21|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-03-21|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-03-21|0x000b
//  GNU General Public License for more details.                                          //07-03-21|0x000b
//                                                                                        //07-03-21|0x000b
//  You should have received a copy of the GNU General Public License                     //07-03-21|0x000b
//  along with this program; if not, write to the Free Software                           //07-03-21|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-03-21|0x000b
//  USA                                                                                   //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//  For further information, please contact Robert Adams:                                 //07-03-21|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-03-21|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-03-21|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
//*****************************************************************************           //07-03-21|0x000b
#ifndef basedict_hpp                                                                      //07-03-21|0x000c
#define basedict_hpp                                                                      //07-03-21|0x000c
//***************************************************************************             //07-03-21|0x0011
//***************************************************************************             //07-03-21|0x0012
//******                                                               ******             //07-03-21|0x0013
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //07-03-21|0x0014
//******                                                               ******             //07-03-21|0x0015
//***************************************************************************             //07-03-21|0x0016
//***************************************************************************             //07-03-21|0x0017
//***************************************************************************             //07-03-21|0x001a
//***************************************************************************             //07-03-21|0x001b
//******                                                               ******             //07-03-21|0x001c
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //07-03-21|0x001d
//******                                                               ******             //07-03-21|0x001e
//***************************************************************************             //07-03-21|0x001f
//***************************************************************************             //07-03-21|0x0020
#define UserError 0x0000                                                                  //07-03-21|0x0021
#define BuildError 0x7fff                                                                 //07-03-21|0x0021
#define Display 0x7ffe                                                                    //07-03-21|0x0021
#define KeyBoard 0x7ffd                                                                   //07-03-21|0x0021
#define Success 0xffff                                                                    //07-03-21|0x0021
#define SystemError 0x8000                                                                //07-03-21|0x0021
#define Continue 0x0001                                                                   //07-03-21|0x0021
#define FileDone 0x0002                                                                   //07-03-21|0x0021
#define LineDone 0x0003                                                                   //07-03-21|0x0021
#define Yes 0x0004                                                                        //07-03-21|0x0021
#define No 0x0005                                                                         //07-03-21|0x0021
#define RepeatChar '\x6'                                                                  //07-03-21|0x0021
#define Great 0x0007                                                                      //07-03-21|0x0021
#define Equal 0x0008                                                                      //07-03-21|0x0021
#define Less 0x0009                                                                       //07-03-21|0x0021
#define Zero 0x000a                                                                       //07-03-21|0x0021
#define Minus 0x000b                                                                      //07-03-21|0x0021
//***************************************************************************             //07-03-21|0x0022
#define SystemMsg PcgSystemError("Basedict", __LINE__);                                   //07-03-21|0x0023
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-03-21|0x0023
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //07-03-21|0x0023
#define BreakFinish(_a) status = Finish(_a); break                                        //07-03-21|0x0024
#define ReturnFinish(_a) return(Finish(_a))                                               //07-03-21|0x0024
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //07-03-21|0x0024
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //07-03-21|0x0024
#define _SwitchErr case UserError: return(UserError)                                      //07-03-21|0x0025
#define _SwitchOk case Success: break                                                     //07-03-21|0x0025
#define _SwitchEnd default: ReturnSystemError                                             //07-03-21|0x0025
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-03-21|0x0025
#define _SwitchYes case Yes:      return(Yes)                                             //07-03-21|0x0025
#define _SwitchNo case No:       return(No)                                               //07-03-21|0x0025
#define _SwitchGroup { _SwitchBase; }                                                     //07-03-21|0x0025
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-03-21|0x0025
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-03-21|0x0025
#define _SwitchBreak _SwitchGroup break                                                   //07-03-21|0x0025
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-03-21|0x0025
//***************************************************************************             //07-03-21|0x0049
//***************************************************************************             //07-03-21|0x004a
//******                                                               ******             //07-03-21|0x004b
//******               GENERAL DEFINITION STATEMENTS                   ******             //07-03-21|0x004c
//******                                                               ******             //07-03-21|0x004d
//***************************************************************************             //07-03-21|0x004e
//***************************************************************************             //07-03-21|0x004f
#define TestSample(i) test_samples[i] = __LINE__                                          //07-03-21|0x0050
#define return_test(j) { TestSample(j);  return(Success); }                               //07-03-21|0x0050
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //07-03-21|0x0050
#define return_no(j) { TestSample(j);  return(No); }                                      //07-03-21|0x0050
#define goto_test(i) { TestSample(i);  goto loop; }                                       //07-03-21|0x0050
#define break_test(i) { TestSample(i);  break; }                                          //07-03-21|0x0050
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //07-03-21|0x0050
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //07-03-21|0x0050
//************************************************************************                //07-03-21|0x0050
#ifndef TestIndex                                                                         //07-03-21|0x0050
#define TestIndex 0                                                                       //07-03-21|0x0050
#endif                                                                                    //07-03-21|0x0050
//------------------------------------------------------------------------                //07-03-21|0x0050
enum {  NoTestSamples = TestIndex };                                                      //07-03-21|0x0050
//------------------------------------------------------------------------                //07-03-21|0x0050
#undef TestIndex                                                                          //07-03-21|0x0050
#define TestIndex NoTestSamples+1                                                         //07-03-21|0x0050
//************************************************************************                //07-03-21|0x0050
//***************************************************************************             //07-03-21|0x0051
//**********************************************************************                  //07-03-21|0x0052
#define DictSearchState Addr->search_state                                                //07-03-21|0x0052
#define DictProcessState Addr->process_state                                              //07-03-21|0x0052
#define DictFileState Addr->hash_record.file_state                                        //07-03-21|0x0052
#define DictRunFlag Addr->run_flag                                                        //07-03-21|0x0052
#define DictStatus Addr->status                                                           //07-03-21|0x0052
#define DictTextPlan Addr->text_plan                                                      //07-03-21|0x0052
#define DictHeaderPlan Addr->header_plan                                                  //07-03-21|0x0052
#define DictHash Addr->hash                                                               //07-03-21|0x0052
#define DictTextPosition Addr->text_position                                              //07-03-21|0x0052
#define DictCurrentOffset Addr->current_offset                                            //07-03-21|0x0052
#define DictCurrentBridge Addr->current_bridge                                            //07-03-21|0x0052
#define DictSearchOffset Addr->search_offset                                              //07-03-21|0x0052
#define DictSearchBridge Addr->search_bridge                                              //07-03-21|0x0052
#define DictLowerBridge Addr->lower_bridge                                                //07-03-21|0x0052
#define DictUpperBridge Addr->upper_bridge                                                //07-03-21|0x0052
#define DictHashRecord Addr->hash_record                                                  //07-03-21|0x0052
#define DictHeaderRecord Addr->header_record                                              //07-03-21|0x0052
#define DictTextRecord Addr->text_record                                                  //07-03-21|0x0052
#define DictFileData Addr->file_data                                                      //07-03-21|0x0052
//----------------------------------------------------------------------                  //07-03-21|0x0052
#define DictHeaderRecordAddr (SCHAR_FAR) &(Addr->header_record)                           //07-03-21|0x0052
#define DictHashRecordAddr (SCHAR_FAR) &(Addr->hash_record)                               //07-03-21|0x0052
#define DictTextRecordAddr (SCHAR_FAR) &(Addr->text_record)                               //07-03-21|0x0052
//**********************************************************************                  //07-03-21|0x0054
#define HashLastBridge(i) DictHashRecord.hash_element[i].last_bridge                      //07-03-21|0x0054
#define HashFirstBridge(i) DictHashRecord.hash_element[i].first_bridge                    //07-03-21|0x0054
#define HashLastOffset(i) DictHashRecord.hash_element[i].last_offset                      //07-03-21|0x0054
#define HashFirstOffset(i) DictHashRecord.hash_element[i].first_offset                    //07-03-21|0x0054
#define HashFirst(i) DictHashRecord.hash_element[i].first                                 //07-03-21|0x0054
#define HashLast(i) DictHashRecord.hash_element[i].last                                   //07-03-21|0x0054
//----------------------------------------------------------------------                  //07-03-21|0x0054
#define HashElementAddr(i) &(DictHashRecord.hash_element[i])                              //07-03-21|0x0054
#define HashFirstOffsetAddr(i) &(DictHashRecord.hash_element[i].first_offset)             //07-03-21|0x0054
#define HashLastOffsetAddr(i) &(DictHashRecord.hash_element[i].last_offset                //07-03-21|0x0054
#define HashFirstAddr(i) &(DictHashRecord.hash_element[i].first)                          //07-03-21|0x0054
#define HashLastAddr(i) &(DictHashRecord.hash_element[i].last)                            //07-03-21|0x0054
//**********************************************************************                  //07-03-21|0x0055
#define HeaderNextPosition DictHeaderRecord.next_position                                 //07-03-21|0x0055
#define HeaderCurrentPosition DictHeaderRecord.current_position                           //07-03-21|0x0055
#define HeaderNoArgs DictHeaderRecord.no_args                                             //07-03-21|0x0055
#define HeaderNamePosition(i) DictHeaderRecord.name_position[i]                           //07-03-21|0x0055
#define HeaderStartCol(i) DictHeaderRecord.start_col[i]                                   //07-03-21|0x0055
#define HeaderStartCall(i) DictHeaderRecord.start_call[i]                                 //07-03-21|0x0055
#define HeaderLineNo(i) DictHeaderRecord.line_no[i]                                       //07-03-21|0x0055
#define HeaderCommand DictHeaderRecord.command                                            //07-03-21|0x0055
//************************************************************************                //07-03-21|0x0056
#define TextHeader DictTextRecord.text_header                                             //07-03-21|0x0056
#define TextString DictTextRecord.text_char[0]                                            //07-03-21|0x0056
#define TextChar(i) DictTextRecord.text_char[i]                                           //07-03-21|0x0056
//------------------------------------------------------------------------                //07-03-21|0x0056
#define TextHeaderAddr (SCHAR_FAR) &(DictTextRecord.text_header)                          //07-03-21|0x0056
#define TextStringAddr &(DictTextRecord.text_char[0])                                     //07-03-21|0x0056
//************************************************************************                //07-03-21|0x0057
#define FileControl DictFileData.file_control                                             //07-03-21|0x0057
#define FilePosition DictFileData.file_position                                           //07-03-21|0x0057
#define FileLength DictFileData.file_length                                               //07-03-21|0x0057
//************************************************************************                //07-03-21|0x0059
#define TextLength TextHeader.length                                                      //07-03-21|0x0059
#define TextDeltaBridge TextHeader.delta_bridge                                           //07-03-21|0x0059
#define TextDeltaOffset TextHeader.delta_offset                                           //07-03-21|0x0059
#define TextNextPosition TextHeader.next_position                                         //07-03-21|0x0059
#define TextHeaderPosition TextHeader.header_position                                     //07-03-21|0x0059
#define TextCurrentPosition TextHeader.current_position                                   //07-03-21|0x0059
#define TextType TextHeader.type                                                          //07-03-21|0x0059
//***************************************************************************             //07-03-21|0x005a
#define InputChar(i) Input->line[i]                                                       //07-03-21|0x005b
#define InputLine Input->line[0]                                                          //07-03-21|0x005b
#define InputLineAddr &(Input->line[0])                                                   //07-03-21|0x005b
#define InputMacroLineNo Input->macro_line_no                                             //07-03-21|0x005b
#define InputType Input->type                                                             //07-03-21|0x005b
#define InputStartCol Input->start_col                                                    //07-03-21|0x005b
#define InputStartCall Input->start_call                                                  //07-03-21|0x005b
#define InputPosition Input->position                                                     //07-03-21|0x005b
#define InputLength Input->length                                                         //07-03-21|0x005b
#define InputColumn Input->column                                                         //07-03-21|0x005b
//**********************************************************************                  //07-03-21|0x005b
#define OutputChar(i) Output->line[i]                                                     //07-03-21|0x005c
#define OutputLine Output->line[0]                                                        //07-03-21|0x005c
#define OutputLineAddr &(Output->line[0])                                                 //07-03-21|0x005c
#define OutputMacroLineNo Output->macro_line_no                                           //07-03-21|0x005c
#define OutputType Output->type                                                           //07-03-21|0x005c
#define OutputStartCol Output->start_col                                                  //07-03-21|0x005c
#define OutputStartCall Output->start_call                                                //07-03-21|0x005c
#define OutputPosition Output->position                                                   //07-03-21|0x005c
#define OutputLength Output->length                                                       //07-03-21|0x005c
#define OutputColumn Output->column                                                       //07-03-21|0x005c
//**********************************************************************                  //07-03-21|0x005c
//**********************************************************************                  //07-03-21|0x005d
#define InputHashLastBridge(i) InputHashFar->hash_element[i].last_bridge                  //07-03-21|0x005d
#define InputHashFirstBridge(i) InputHashFar->hash_element[i].first_bridge                //07-03-21|0x005d
#define InputHashLastOffset(i) InputHashFar->hash_element[i].last_offset                  //07-03-21|0x005d
#define InputHashFirstOffset(i) InputHashFar->hash_element[i].first_offset                //07-03-21|0x005d
#define InputHashFirst(i) InputHashFar->hash_element[i].first                             //07-03-21|0x005d
#define InputHashLast(i) InputHashFar->hash_element[i].last                               //07-03-21|0x005d
//----------------------------------------------------------------------                  //07-03-21|0x005d
#define InputHashElementAddr(i) &(InputHashFar->hash_element[i])                          //07-03-21|0x005d
#define InputHashFirstOffsetAddr(i) &(InputHashFar->hash_element[i].first_offset)         //07-03-21|0x005d
#define InputHashLastOffsetAddr(i) &(InputHashFar->hash_element[i].last_offset            //07-03-21|0x005d
#define InputHashFirstAddr(i) &(InputHashFar->hash_element[i].first)                      //07-03-21|0x005d
#define InputHashLastAddr(i) &(InputHashFar->hash_element[i].last)                        //07-03-21|0x005d
//************************************************************************                //07-03-21|0x005e
#define RecordSizeUlong RecordFar->size.ulong                                             //07-03-21|0x005e
#define RecordSize RecordFar->size.word0                                                  //07-03-21|0x005e
#define RecordData(i) RecordFar->data[i]                                                  //07-03-21|0x005e
#define RecordDataAddr &(RecordFar->data[0])                                              //07-03-21|0x005e
//***************************************************************************             //07-03-21|0x005f
//************************************************************************                //07-03-21|0x0060
#define BaseLastBridge Base->last_bridge                                                  //07-03-21|0x0060
#define BaseFirstBridge Base->first_bridge                                                //07-03-21|0x0060
#define BaseLastOffset Base->last_offset                                                  //07-03-21|0x0060
#define BaseFirstOffset Base->first_offset                                                //07-03-21|0x0060
#define BaseFirst Base->first                                                             //07-03-21|0x0060
#define BaseLast Base->last                                                               //07-03-21|0x0060
//************************************************************************                //07-03-21|0x0061
#define ApndLastBridge Apnd->last_bridge                                                  //07-03-21|0x0061
#define ApndFirstBridge Apnd->first_bridge                                                //07-03-21|0x0061
#define ApndLastOffset Apnd->last_offset                                                  //07-03-21|0x0061
#define ApndFirstOffset Apnd->first_offset                                                //07-03-21|0x0061
#define ApndFirst Apnd->first                                                             //07-03-21|0x0061
#define ApndLast Apnd->last                                                               //07-03-21|0x0061
//***************************************************************************             //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0063
#define VersionError2 Finish("File Corrupt / Version Error")                              //07-03-21|0x0063
#define VersionError1 VersionError2 != UserError                                          //07-03-21|0x0063
#define VersionError if(VersionError1)             ReturnSystemError                      //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcInitialDict BaseDictProcInitial(Addr, Name, Extent)                           //07-03-21|0x0063
#define ProcDictExists BaseDictProcExists(Addr, TimeFar)                                  //07-03-21|0x0063
#define ProcInitialHash BaseDictProcInitialHash(Addr)                                     //07-03-21|0x0063
#define ProcHashAppend BaseDictProcAppendHash(Addr)                                       //07-03-21|0x0063
#define ProcHashRead BaseDictProcReadHash(Addr)                                           //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcCreateFirst1(i) BaseDictProcBeginEntry(Addr, Input, Command, i)               //07-03-21|0x0063
#define ProcCreateFirst ProcCreateFirst1(Type)                                            //07-03-21|0x0063
//--------------------------------------------------------------------                    //07-03-21|0x0063
#define ProcCreateNext1(i) BaseDictProcAddNext(Addr,  Input, Command, i)                  //07-03-21|0x0063
#define ProcCreateNext ProcCreateNext1(Type)                                              //07-03-21|0x0063
//--------------------------------------------------------------------                    //07-03-21|0x0063
#define ProcAddArg BaseDictProcAddArg(Addr, Input,  Type)                                 //07-03-21|0x0063
#define ProcSearchName BaseDictProcSearch(Addr, Input,  Type)                             //07-03-21|0x0063
#define ProcGetFirstCommand BaseDictProcGetFirstCmd(Addr, CommandFar)                     //07-03-21|0x0063
#define ProcGetNextCommand BaseDictProcGetNextCmd(Addr, CommandFar)                       //07-03-21|0x0063
#define ProcTestArgument BaseDictProcTestArg(Addr, ArgNo)                                 //07-03-21|0x0063
#define ProcGetArgument BaseDictProcGetArg(Addr, Output, ArgNo)                           //07-03-21|0x0063
#define ProcUpdateArg BaseDictProcArgUpdate(Addr)                                         //07-03-21|0x0063
#define ProcEntryEnd BaseDictProcEndEntry(Addr)                                           //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcDictComp BaseDictProcComplete(Addr)                                           //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcConnect2(i,j) BaseDictProcConnect(Addr,i,j)                                   //07-03-21|0x0063
#define ProcConnect1(j) ProcConnect2(InputHashFar,j)                                      //07-03-21|0x0063
#define ProcConnect ProcConnect1(Input_Length)                                            //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcAppend BaseDictProcWriteRecord(Addr, RecordFar)                               //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcCopyHash BaseDictProcConnectHash(Addr, InputHashFar)                          //07-03-21|0x0063
#define ProcConnectRead BaseDictProcReadRecord(Addr, RecordFar)                           //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcBridgeSearch(i) BaseDictProcBridge(Addr, Input, i, Type)                      //07-03-21|0x0063
#define ProcBridgeInitial BaseDictProcInitialBridge(Addr)                                 //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcWriteHash BaseDictProcWriteHash(Addr)                                         //07-03-21|0x0063
#define ProcCloseDict BaseDictProcClose(Addr)                                             //07-03-21|0x0063
#define ProcDeleteDict BaseDictProcDeleteDict(Addr)                                       //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#ifndef TestIndex                                                                         //11-02-26|0x006c
#define TestIndex 0                                                                       //11-02-26|0x006c
#endif                                                                                    //11-02-26|0x006c
//------------------------------------------------------------------------                //11-02-26|0x006c
enum {  base_dict_get_cert_1 = TestIndex };                                               //11-02-26|0x006c
//------------------------------------------------------------------------                //11-02-26|0x006c
#undef TestIndex                                                                          //11-02-26|0x006c
#define TestIndex base_dict_get_cert_1+1                                                  //11-02-26|0x006c
//************************************************************************                //11-02-26|0x006c
#ifndef TestIndex                                                                         //07-01-17|0x00b6
#define TestIndex 0                                                                       //07-01-17|0x00b6
#endif                                                                                    //07-01-17|0x00b6
//------------------------------------------------------------------------                //07-01-17|0x00b6
enum {  initial_dict_1 = TestIndex };                                                     //07-01-17|0x00b6
//------------------------------------------------------------------------                //07-01-17|0x00b6
#undef TestIndex                                                                          //07-01-17|0x00b6
#define TestIndex initial_dict_1+1                                                        //07-01-17|0x00b6
//************************************************************************                //07-01-17|0x00b6
#ifndef TestIndex                                                                         //07-01-17|0x00d0
#define TestIndex 0                                                                       //07-01-17|0x00d0
#endif                                                                                    //07-01-17|0x00d0
//------------------------------------------------------------------------                //07-01-17|0x00d0
enum {  dict_exists_1 = TestIndex };                                                      //07-01-17|0x00d0
//------------------------------------------------------------------------                //07-01-17|0x00d0
#undef TestIndex                                                                          //07-01-17|0x00d0
#define TestIndex dict_exists_1+1                                                         //07-01-17|0x00d0
//************************************************************************                //07-01-17|0x00d0
#ifndef TestIndex                                                                         //07-01-17|0x00ea
#define TestIndex 0                                                                       //07-01-17|0x00ea
#endif                                                                                    //07-01-17|0x00ea
//------------------------------------------------------------------------                //07-01-17|0x00ea
enum {  initial_hash_1 = TestIndex };                                                     //07-01-17|0x00ea
//------------------------------------------------------------------------                //07-01-17|0x00ea
#undef TestIndex                                                                          //07-01-17|0x00ea
#define TestIndex initial_hash_1+1                                                        //07-01-17|0x00ea
//************************************************************************                //07-01-17|0x00ea
#ifndef TestIndex                                                                         //07-01-18|0x0107
#define TestIndex 0                                                                       //07-01-18|0x0107
#endif                                                                                    //07-01-18|0x0107
//------------------------------------------------------------------------                //07-01-18|0x0107
enum {  append_hash_1 = TestIndex };                                                      //07-01-18|0x0107
//------------------------------------------------------------------------                //07-01-18|0x0107
#undef TestIndex                                                                          //07-01-18|0x0107
#define TestIndex append_hash_1+1                                                         //07-01-18|0x0107
//************************************************************************                //07-01-18|0x0107
#ifndef TestIndex                                                                         //09-07-10|0x0128
#define TestIndex 0                                                                       //09-07-10|0x0128
#endif                                                                                    //09-07-10|0x0128
//------------------------------------------------------------------------                //09-07-10|0x0128
enum {  append_dict_1 = TestIndex };                                                      //09-07-10|0x0128
//------------------------------------------------------------------------                //09-07-10|0x0128
#undef TestIndex                                                                          //09-07-10|0x0128
#define TestIndex append_dict_1+1                                                         //09-07-10|0x0128
//************************************************************************                //09-07-10|0x0128
#ifndef TestIndex                                                                         //07-01-23|0x0147
#define TestIndex 0                                                                       //07-01-23|0x0147
#endif                                                                                    //07-01-23|0x0147
//------------------------------------------------------------------------                //07-01-23|0x0147
enum {  read_hash_1 = TestIndex };                                                        //07-01-23|0x0147
//------------------------------------------------------------------------                //07-01-23|0x0147
#undef TestIndex                                                                          //07-01-23|0x0147
#define TestIndex read_hash_1+1                                                           //07-01-23|0x0147
//************************************************************************                //07-01-23|0x0147
#ifndef TestIndex                                                                         //07-01-17|0x016a
#define TestIndex 0                                                                       //07-01-17|0x016a
#endif                                                                                    //07-01-17|0x016a
//------------------------------------------------------------------------                //07-01-17|0x016a
enum {  begin_entry_1 = TestIndex };                                                      //07-01-17|0x016a
//------------------------------------------------------------------------                //07-01-17|0x016a
#undef TestIndex                                                                          //07-01-17|0x016a
#define TestIndex begin_entry_1+1                                                         //07-01-17|0x016a
//************************************************************************                //07-01-17|0x016a
#ifndef TestIndex                                                                         //07-01-17|0x018e
#define TestIndex 0                                                                       //07-01-17|0x018e
#endif                                                                                    //07-01-17|0x018e
//------------------------------------------------------------------------                //07-01-17|0x018e
enum {  add_next_1 = TestIndex };                                                         //07-01-17|0x018e
//------------------------------------------------------------------------                //07-01-17|0x018e
#undef TestIndex                                                                          //07-01-17|0x018e
#define TestIndex add_next_1+1                                                            //07-01-17|0x018e
//************************************************************************                //07-01-17|0x018e
#ifndef TestIndex                                                                         //07-01-17|0x01b6
#define TestIndex 0                                                                       //07-01-17|0x01b6
#endif                                                                                    //07-01-17|0x01b6
//------------------------------------------------------------------------                //07-01-17|0x01b6
enum {  add_arg_1 = TestIndex };                                                          //07-01-17|0x01b6
//------------------------------------------------------------------------                //07-01-17|0x01b6
#undef TestIndex                                                                          //07-01-17|0x01b6
#define TestIndex add_arg_1+1                                                             //07-01-17|0x01b6
//************************************************************************                //07-01-17|0x01b6
#ifndef TestIndex                                                                         //07-01-24|0x01e0
#define TestIndex 0                                                                       //07-01-24|0x01e0
#endif                                                                                    //07-01-24|0x01e0
//------------------------------------------------------------------------                //07-01-24|0x01e0
enum {  search_1 = TestIndex };                                                           //07-01-24|0x01e0
//------------------------------------------------------------------------                //07-01-24|0x01e0
#undef TestIndex                                                                          //07-01-24|0x01e0
#define TestIndex search_1+1                                                              //07-01-24|0x01e0
//************************************************************************                //07-01-24|0x01e0
#ifndef TestIndex                                                                         //07-01-23|0x0203
#define TestIndex 0                                                                       //07-01-23|0x0203
#endif                                                                                    //07-01-23|0x0203
//------------------------------------------------------------------------                //07-01-23|0x0203
enum {  get_first_cmd_1 = TestIndex };                                                    //07-01-23|0x0203
//------------------------------------------------------------------------                //07-01-23|0x0203
#undef TestIndex                                                                          //07-01-23|0x0203
#define TestIndex get_first_cmd_1+1                                                       //07-01-23|0x0203
//************************************************************************                //07-01-23|0x0203
#ifndef TestIndex                                                                         //07-01-24|0x022e
#define TestIndex 0                                                                       //07-01-24|0x022e
#endif                                                                                    //07-01-24|0x022e
//------------------------------------------------------------------------                //07-01-24|0x022e
enum {  get_next_cmd_1 = TestIndex };                                                     //07-01-24|0x022e
//------------------------------------------------------------------------                //07-01-24|0x022e
#undef TestIndex                                                                          //07-01-24|0x022e
#define TestIndex get_next_cmd_1+1                                                        //07-01-24|0x022e
//************************************************************************                //07-01-24|0x022e
#ifndef TestIndex                                                                         //07-01-24|0x025b
#define TestIndex 0                                                                       //07-01-24|0x025b
#endif                                                                                    //07-01-24|0x025b
//------------------------------------------------------------------------                //07-01-24|0x025b
enum {  test_arg_1 = TestIndex };                                                         //07-01-24|0x025b
//------------------------------------------------------------------------                //07-01-24|0x025b
#undef TestIndex                                                                          //07-01-24|0x025b
#define TestIndex test_arg_1+1                                                            //07-01-24|0x025b
//************************************************************************                //07-01-24|0x025b
#ifndef TestIndex                                                                         //07-01-24|0x0283
#define TestIndex 0                                                                       //07-01-24|0x0283
#endif                                                                                    //07-01-24|0x0283
//------------------------------------------------------------------------                //07-01-24|0x0283
enum {  get_arg_1 = TestIndex };                                                          //07-01-24|0x0283
//------------------------------------------------------------------------                //07-01-24|0x0283
#undef TestIndex                                                                          //07-01-24|0x0283
#define TestIndex get_arg_1+1                                                             //07-01-24|0x0283
//************************************************************************                //07-01-24|0x0283
#ifndef TestIndex                                                                         //07-01-24|0x02ad
#define TestIndex 0                                                                       //07-01-24|0x02ad
#endif                                                                                    //07-01-24|0x02ad
//------------------------------------------------------------------------                //07-01-24|0x02ad
enum {  arg_update_1 = TestIndex };                                                       //07-01-24|0x02ad
//------------------------------------------------------------------------                //07-01-24|0x02ad
#undef TestIndex                                                                          //07-01-24|0x02ad
#define TestIndex arg_update_1+1                                                          //07-01-24|0x02ad
//************************************************************************                //07-01-24|0x02ad
#ifndef TestIndex                                                                         //07-01-17|0x02d0
#define TestIndex 0                                                                       //07-01-17|0x02d0
#endif                                                                                    //07-01-17|0x02d0
//------------------------------------------------------------------------                //07-01-17|0x02d0
enum {  end_entry_1 = TestIndex };                                                        //07-01-17|0x02d0
//------------------------------------------------------------------------                //07-01-17|0x02d0
#undef TestIndex                                                                          //07-01-17|0x02d0
#define TestIndex end_entry_1+1                                                           //07-01-17|0x02d0
//************************************************************************                //07-01-17|0x02d0
#ifndef TestIndex                                                                         //07-01-18|0x02fc
#define TestIndex 0                                                                       //07-01-18|0x02fc
#endif                                                                                    //07-01-18|0x02fc
//------------------------------------------------------------------------                //07-01-18|0x02fc
enum {  complete_1 = TestIndex };                                                         //07-01-18|0x02fc
//------------------------------------------------------------------------                //07-01-18|0x02fc
#undef TestIndex                                                                          //07-01-18|0x02fc
#define TestIndex complete_1+1                                                            //07-01-18|0x02fc
//************************************************************************                //07-01-18|0x02fc
#ifndef TestIndex                                                                         //07-08-22|0x031d
#define TestIndex 0                                                                       //07-08-22|0x031d
#endif                                                                                    //07-08-22|0x031d
//------------------------------------------------------------------------                //07-08-22|0x031d
enum {  connect_1 = TestIndex };                                                          //07-08-22|0x031d
//------------------------------------------------------------------------                //07-08-22|0x031d
#undef TestIndex                                                                          //07-08-22|0x031d
#define TestIndex connect_1+1                                                             //07-08-22|0x031d
//************************************************************************                //07-08-22|0x031d
#ifndef TestIndex                                                                         //07-01-23|0x033e
#define TestIndex 0                                                                       //07-01-23|0x033e
#endif                                                                                    //07-01-23|0x033e
//------------------------------------------------------------------------                //07-01-23|0x033e
enum {  write_record_1 = TestIndex };                                                     //07-01-23|0x033e
//------------------------------------------------------------------------                //07-01-23|0x033e
#undef TestIndex                                                                          //07-01-23|0x033e
#define TestIndex write_record_1+1                                                        //07-01-23|0x033e
//************************************************************************                //07-01-23|0x033e
#ifndef TestIndex                                                                         //07-01-23|0x0360
#define TestIndex 0                                                                       //07-01-23|0x0360
#endif                                                                                    //07-01-23|0x0360
//------------------------------------------------------------------------                //07-01-23|0x0360
enum {  read_header_1 = TestIndex };                                                      //07-01-23|0x0360
//------------------------------------------------------------------------                //07-01-23|0x0360
#undef TestIndex                                                                          //07-01-23|0x0360
#define TestIndex read_header_1+1                                                         //07-01-23|0x0360
//************************************************************************                //07-01-23|0x0360
#ifndef TestIndex                                                                         //07-01-23|0x037f
#define TestIndex 0                                                                       //07-01-23|0x037f
#endif                                                                                    //07-01-23|0x037f
//------------------------------------------------------------------------                //07-01-23|0x037f
enum {  read_record_1 = TestIndex };                                                      //07-01-23|0x037f
//------------------------------------------------------------------------                //07-01-23|0x037f
#undef TestIndex                                                                          //07-01-23|0x037f
#define TestIndex read_record_1+1                                                         //07-01-23|0x037f
//************************************************************************                //07-01-23|0x037f
#ifndef TestIndex                                                                         //07-08-22|0x03a1
#define TestIndex 0                                                                       //07-08-22|0x03a1
#endif                                                                                    //07-08-22|0x03a1
//------------------------------------------------------------------------                //07-08-22|0x03a1
enum {  initial_bridge_1 = TestIndex };                                                   //07-08-22|0x03a1
//------------------------------------------------------------------------                //07-08-22|0x03a1
#undef TestIndex                                                                          //07-08-22|0x03a1
#define TestIndex initial_bridge_1+1                                                      //07-08-22|0x03a1
//************************************************************************                //07-08-22|0x03a1
#ifndef TestIndex                                                                         //07-01-23|0x03c7
#define TestIndex 0                                                                       //07-01-23|0x03c7
#endif                                                                                    //07-01-23|0x03c7
//------------------------------------------------------------------------                //07-01-23|0x03c7
enum {  bridge_1 = TestIndex };                                                           //07-01-23|0x03c7
//------------------------------------------------------------------------                //07-01-23|0x03c7
#undef TestIndex                                                                          //07-01-23|0x03c7
#define TestIndex bridge_1+1                                                              //07-01-23|0x03c7
//************************************************************************                //07-01-23|0x03c7
#ifndef TestIndex                                                                         //07-01-18|0x03ec
#define TestIndex 0                                                                       //07-01-18|0x03ec
#endif                                                                                    //07-01-18|0x03ec
//------------------------------------------------------------------------                //07-01-18|0x03ec
enum {  close_base_1 = TestIndex };                                                       //07-01-18|0x03ec
//------------------------------------------------------------------------                //07-01-18|0x03ec
#undef TestIndex                                                                          //07-01-18|0x03ec
#define TestIndex close_base_1+1                                                          //07-01-18|0x03ec
//************************************************************************                //07-01-18|0x03ec
#ifndef TestIndex                                                                         //07-03-21|0x0419
#define TestIndex 0                                                                       //07-03-21|0x0419
#endif                                                                                    //07-03-21|0x0419
//------------------------------------------------------------------------                //07-03-21|0x0419
enum {  close_emergency_1 = TestIndex };                                                  //07-03-21|0x0419
//------------------------------------------------------------------------                //07-03-21|0x0419
#undef TestIndex                                                                          //07-03-21|0x0419
#define TestIndex close_emergency_1+1                                                     //07-03-21|0x0419
//************************************************************************                //07-03-21|0x0419
#ifndef TestIndex                                                                         //07-01-25|0x0433
#define TestIndex 0                                                                       //07-01-25|0x0433
#endif                                                                                    //07-01-25|0x0433
//------------------------------------------------------------------------                //07-01-25|0x0433
enum {  delete_dict_1 = TestIndex };                                                      //07-01-25|0x0433
//------------------------------------------------------------------------                //07-01-25|0x0433
#undef TestIndex                                                                          //07-01-25|0x0433
#define TestIndex delete_dict_1+1                                                         //07-01-25|0x0433
//************************************************************************                //07-01-25|0x0433
//*******************************************************************************         //05-24-97|0x0461
//*******************************************************************************         //05-24-97|0x0461
//****                       END OF FILE                                     ****         //05-24-97|0x0461
//*******************************************************************************         //05-24-97|0x0461
//*******************************************************************************         //05-24-97|0x0461
#endif                                                                                    //05-24-97|0x0461
