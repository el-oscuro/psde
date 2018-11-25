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
#ifndef basedictproc_hpp                                                                  //07-03-21|0x000c
#define basedictproc_hpp                                                                  //07-03-21|0x000c
//***************************************************************************             //07-03-21|0x0010
//***************************************************************************             //07-03-21|0x0011
//******                                                               ******             //07-03-21|0x0012
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //07-03-21|0x0013
//******                                                               ******             //07-03-21|0x0014
//***************************************************************************             //07-03-21|0x0015
//***************************************************************************             //07-03-21|0x0016
//***************************************************************************             //07-03-21|0x0019
//***************************************************************************             //07-03-21|0x001a
//******                                                               ******             //07-03-21|0x001b
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //07-03-21|0x001c
//******                                                               ******             //07-03-21|0x001d
//***************************************************************************             //07-03-21|0x001e
//***************************************************************************             //07-03-21|0x001f
#define UserError 0x0000                                                                  //07-03-21|0x0020
#define BuildError 0x7fff                                                                 //07-03-21|0x0020
#define Display 0x7ffe                                                                    //07-03-21|0x0020
#define KeyBoard 0x7ffd                                                                   //07-03-21|0x0020
#define Success 0xffff                                                                    //07-03-21|0x0020
#define SystemError 0x8000                                                                //07-03-21|0x0020
#define Continue 0x0001                                                                   //07-03-21|0x0020
#define FileDone 0x0002                                                                   //07-03-21|0x0020
#define LineDone 0x0003                                                                   //07-03-21|0x0020
#define Yes 0x0004                                                                        //07-03-21|0x0020
#define No 0x0005                                                                         //07-03-21|0x0020
#define RepeatChar '\x6'                                                                  //07-03-21|0x0020
#define Great 0x0007                                                                      //07-03-21|0x0020
#define Equal 0x0008                                                                      //07-03-21|0x0020
#define Less 0x0009                                                                       //07-03-21|0x0020
#define Zero 0x000a                                                                       //07-03-21|0x0020
#define Minus 0x000b                                                                      //07-03-21|0x0020
//***************************************************************************             //07-03-21|0x0021
#define SystemMsg PcgSystemError("Basedictproc", __LINE__);                               //07-03-21|0x0022
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //07-03-21|0x0022
#define ReturnSystemAddrError { SystemMsg; SystemError; return(0); }                      //07-03-21|0x0022
#define BreakFinish(_a) status = Finish(_a); break                                        //07-03-21|0x0023
#define ReturnFinish(_a) return(Finish(_a))                                               //07-03-21|0x0023
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //07-03-21|0x0023
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //07-03-21|0x0023
#define _SwitchErr case UserError: return(UserError)                                      //07-03-21|0x0024
#define _SwitchOk case Success: break                                                     //07-03-21|0x0024
#define _SwitchEnd default: ReturnSystemError                                             //07-03-21|0x0024
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //07-03-21|0x0024
#define _SwitchYes case Yes:      return(Yes)                                             //07-03-21|0x0024
#define _SwitchNo case No:       return(No)                                               //07-03-21|0x0024
#define _SwitchGroup { _SwitchBase; }                                                     //07-03-21|0x0024
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //07-03-21|0x0024
#define _SwitchReturn _SwitchGroup return(Success)                                        //07-03-21|0x0024
#define _SwitchBreak _SwitchGroup break                                                   //07-03-21|0x0024
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //07-03-21|0x0024
//***************************************************************************             //07-03-21|0x0048
//***************************************************************************             //07-03-21|0x0049
//******                                                               ******             //07-03-21|0x004a
//******               GENERAL DEFINITION STATEMENTS                   ******             //07-03-21|0x004b
//******                                                               ******             //07-03-21|0x004c
//***************************************************************************             //07-03-21|0x004d
//***************************************************************************             //07-03-21|0x004e
#define TestSample(i) test_samples[i] = __LINE__                                          //07-03-21|0x004f
#define return_test(j) { TestSample(j);  return(Success); }                               //07-03-21|0x004f
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //07-03-21|0x004f
#define return_no(j) { TestSample(j);  return(No); }                                      //07-03-21|0x004f
#define goto_test(i) { TestSample(i);  goto loop; }                                       //07-03-21|0x004f
#define break_test(i) { TestSample(i);  break; }                                          //07-03-21|0x004f
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //07-03-21|0x004f
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //07-03-21|0x004f
//************************************************************************                //07-03-21|0x004f
#ifndef TestIndex                                                                         //07-03-21|0x004f
#define TestIndex 0                                                                       //07-03-21|0x004f
#endif                                                                                    //07-03-21|0x004f
//------------------------------------------------------------------------                //07-03-21|0x004f
enum {  NoTestSamples = TestIndex };                                                      //07-03-21|0x004f
//------------------------------------------------------------------------                //07-03-21|0x004f
#undef TestIndex                                                                          //07-03-21|0x004f
#define TestIndex NoTestSamples+1                                                         //07-03-21|0x004f
//************************************************************************                //07-03-21|0x004f
//***************************************************************************             //07-03-21|0x0050
//**********************************************************************                  //07-03-21|0x0051
#define DictSearchState Addr->search_state                                                //07-03-21|0x0051
#define DictProcessState Addr->process_state                                              //07-03-21|0x0051
#define DictFileState Addr->hash_record.file_state                                        //07-03-21|0x0051
#define DictRunFlag Addr->run_flag                                                        //07-03-21|0x0051
#define DictStatus Addr->status                                                           //07-03-21|0x0051
#define DictTextPlan Addr->text_plan                                                      //07-03-21|0x0051
#define DictHeaderPlan Addr->header_plan                                                  //07-03-21|0x0051
#define DictHash Addr->hash                                                               //07-03-21|0x0051
#define DictTextPosition Addr->text_position                                              //07-03-21|0x0051
#define DictCurrentOffset Addr->current_offset                                            //07-03-21|0x0051
#define DictCurrentBridge Addr->current_bridge                                            //07-03-21|0x0051
#define DictSearchOffset Addr->search_offset                                              //07-03-21|0x0051
#define DictSearchBridge Addr->search_bridge                                              //07-03-21|0x0051
#define DictLowerBridge Addr->lower_bridge                                                //07-03-21|0x0051
#define DictUpperBridge Addr->upper_bridge                                                //07-03-21|0x0051
#define DictHashRecord Addr->hash_record                                                  //07-03-21|0x0051
#define DictHeaderRecord Addr->header_record                                              //07-03-21|0x0051
#define DictTextRecord Addr->text_record                                                  //07-03-21|0x0051
#define DictFileData Addr->file_data                                                      //07-03-21|0x0051
//----------------------------------------------------------------------                  //07-03-21|0x0051
#define DictHeaderRecordAddr (SCHAR_FAR) &(Addr->header_record)                           //07-03-21|0x0051
#define DictHashRecordAddr (SCHAR_FAR) &(Addr->hash_record)                               //07-03-21|0x0051
#define DictTextRecordAddr (SCHAR_FAR) &(Addr->text_record)                               //07-03-21|0x0051
//**********************************************************************                  //07-03-21|0x0053
#define HashLastBridge(i) DictHashRecord.hash_element[i].last_bridge                      //07-03-21|0x0053
#define HashFirstBridge(i) DictHashRecord.hash_element[i].first_bridge                    //07-03-21|0x0053
#define HashLastOffset(i) DictHashRecord.hash_element[i].last_offset                      //07-03-21|0x0053
#define HashFirstOffset(i) DictHashRecord.hash_element[i].first_offset                    //07-03-21|0x0053
#define HashFirst(i) DictHashRecord.hash_element[i].first                                 //07-03-21|0x0053
#define HashLast(i) DictHashRecord.hash_element[i].last                                   //07-03-21|0x0053
//----------------------------------------------------------------------                  //07-03-21|0x0053
#define HashElementAddr(i) &(DictHashRecord.hash_element[i])                              //07-03-21|0x0053
#define HashFirstOffsetAddr(i) &(DictHashRecord.hash_element[i].first_offset)             //07-03-21|0x0053
#define HashLastOffsetAddr(i) &(DictHashRecord.hash_element[i].last_offset                //07-03-21|0x0053
#define HashFirstAddr(i) &(DictHashRecord.hash_element[i].first)                          //07-03-21|0x0053
#define HashLastAddr(i) &(DictHashRecord.hash_element[i].last)                            //07-03-21|0x0053
//**********************************************************************                  //07-03-21|0x0054
#define HeaderNextPosition DictHeaderRecord.next_position                                 //07-03-21|0x0054
#define HeaderCurrentPosition DictHeaderRecord.current_position                           //07-03-21|0x0054
#define HeaderNoArgs DictHeaderRecord.no_args                                             //07-03-21|0x0054
#define HeaderNamePosition(i) DictHeaderRecord.name_position[i]                           //07-03-21|0x0054
#define HeaderStartCol(i) DictHeaderRecord.start_col[i]                                   //07-03-21|0x0054
#define HeaderStartCall(i) DictHeaderRecord.start_call[i]                                 //07-03-21|0x0054
#define HeaderLineNo(i) DictHeaderRecord.line_no[i]                                       //07-03-21|0x0054
#define HeaderCommand DictHeaderRecord.command                                            //07-03-21|0x0054
//************************************************************************                //07-03-21|0x0055
#define TextHeader DictTextRecord.text_header                                             //07-03-21|0x0055
#define TextString DictTextRecord.text_char[0]                                            //07-03-21|0x0055
#define TextChar(i) DictTextRecord.text_char[i]                                           //07-03-21|0x0055
//------------------------------------------------------------------------                //07-03-21|0x0055
#define TextHeaderAddr (SCHAR_FAR) &(DictTextRecord.text_header)                          //07-03-21|0x0055
#define TextStringAddr &(DictTextRecord.text_char[0])                                     //07-03-21|0x0055
//************************************************************************                //07-03-21|0x0056
#define FileControl DictFileData.file_control                                             //07-03-21|0x0056
#define FilePosition DictFileData.file_position                                           //07-03-21|0x0056
#define FileLength DictFileData.file_length                                               //07-03-21|0x0056
//************************************************************************                //07-03-21|0x0058
#define TextLength TextHeader.length                                                      //07-03-21|0x0058
#define TextDeltaBridge TextHeader.delta_bridge                                           //07-03-21|0x0058
#define TextDeltaOffset TextHeader.delta_offset                                           //07-03-21|0x0058
#define TextNextPosition TextHeader.next_position                                         //07-03-21|0x0058
#define TextHeaderPosition TextHeader.header_position                                     //07-03-21|0x0058
#define TextCurrentPosition TextHeader.current_position                                   //07-03-21|0x0058
#define TextType TextHeader.type                                                          //07-03-21|0x0058
//***************************************************************************             //07-03-21|0x0059
#define InputChar(i) Input->line[i]                                                       //07-03-21|0x005a
#define InputLine Input->line[0]                                                          //07-03-21|0x005a
#define InputLineAddr &(Input->line[0])                                                   //07-03-21|0x005a
#define InputMacroLineNo Input->macro_line_no                                             //07-03-21|0x005a
#define InputType Input->type                                                             //07-03-21|0x005a
#define InputStartCol Input->start_col                                                    //07-03-21|0x005a
#define InputStartCall Input->start_call                                                  //07-03-21|0x005a
#define InputPosition Input->position                                                     //07-03-21|0x005a
#define InputLength Input->length                                                         //07-03-21|0x005a
#define InputColumn Input->column                                                         //07-03-21|0x005a
//**********************************************************************                  //07-03-21|0x005a
#define OutputChar(i) Output->line[i]                                                     //07-03-21|0x005b
#define OutputLine Output->line[0]                                                        //07-03-21|0x005b
#define OutputLineAddr &(Output->line[0])                                                 //07-03-21|0x005b
#define OutputMacroLineNo Output->macro_line_no                                           //07-03-21|0x005b
#define OutputType Output->type                                                           //07-03-21|0x005b
#define OutputStartCol Output->start_col                                                  //07-03-21|0x005b
#define OutputStartCall Output->start_call                                                //07-03-21|0x005b
#define OutputPosition Output->position                                                   //07-03-21|0x005b
#define OutputLength Output->length                                                       //07-03-21|0x005b
#define OutputColumn Output->column                                                       //07-03-21|0x005b
//**********************************************************************                  //07-03-21|0x005b
//**********************************************************************                  //07-03-21|0x005c
#define InputHashLastBridge(i) InputHashFar->hash_element[i].last_bridge                  //07-03-21|0x005c
#define InputHashFirstBridge(i) InputHashFar->hash_element[i].first_bridge                //07-03-21|0x005c
#define InputHashLastOffset(i) InputHashFar->hash_element[i].last_offset                  //07-03-21|0x005c
#define InputHashFirstOffset(i) InputHashFar->hash_element[i].first_offset                //07-03-21|0x005c
#define InputHashFirst(i) InputHashFar->hash_element[i].first                             //07-03-21|0x005c
#define InputHashLast(i) InputHashFar->hash_element[i].last                               //07-03-21|0x005c
//----------------------------------------------------------------------                  //07-03-21|0x005c
#define InputHashElementAddr(i) &(InputHashFar->hash_element[i])                          //07-03-21|0x005c
#define InputHashFirstOffsetAddr(i) &(InputHashFar->hash_element[i].first_offset)         //07-03-21|0x005c
#define InputHashLastOffsetAddr(i) &(InputHashFar->hash_element[i].last_offset            //07-03-21|0x005c
#define InputHashFirstAddr(i) &(InputHashFar->hash_element[i].first)                      //07-03-21|0x005c
#define InputHashLastAddr(i) &(InputHashFar->hash_element[i].last)                        //07-03-21|0x005c
//************************************************************************                //07-03-21|0x005d
#define RecordSizeUlong RecordFar->size.ulong                                             //07-03-21|0x005d
#define RecordSize RecordFar->size.word0                                                  //07-03-21|0x005d
#define RecordData(i) RecordFar->data[i]                                                  //07-03-21|0x005d
#define RecordDataAddr &(RecordFar->data[0])                                              //07-03-21|0x005d
//***************************************************************************             //07-03-21|0x005e
//************************************************************************                //07-03-21|0x005f
#define BaseLastBridge Base->last_bridge                                                  //07-03-21|0x005f
#define BaseFirstBridge Base->first_bridge                                                //07-03-21|0x005f
#define BaseLastOffset Base->last_offset                                                  //07-03-21|0x005f
#define BaseFirstOffset Base->first_offset                                                //07-03-21|0x005f
#define BaseFirst Base->first                                                             //07-03-21|0x005f
#define BaseLast Base->last                                                               //07-03-21|0x005f
//************************************************************************                //07-03-21|0x0060
#define ApndLastBridge Apnd->last_bridge                                                  //07-03-21|0x0060
#define ApndFirstBridge Apnd->first_bridge                                                //07-03-21|0x0060
#define ApndLastOffset Apnd->last_offset                                                  //07-03-21|0x0060
#define ApndFirstOffset Apnd->first_offset                                                //07-03-21|0x0060
#define ApndFirst Apnd->first                                                             //07-03-21|0x0060
#define ApndLast Apnd->last                                                               //07-03-21|0x0060
//***************************************************************************             //07-03-21|0x0061
#define DictFileName BaseDictUtilDictName(Addr, Name, Extent)                             //07-03-21|0x0062
#define ProcExistsDict BaseDictUtilExists(Addr, TimeFar)                                  //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcInitProc BaseDictUtilInitProc(Addr)                                           //07-03-21|0x0062
#define ProcInitHash BaseDictUtilInitHash(Addr)                                           //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcCreateDict BaseDictUtilCreateDict(Addr)                                       //07-03-21|0x0062
#define ProcAppendDict BaseDictUtilAppendDict(Addr)                                       //07-03-21|0x0062
#define ProcReadDict BaseDictUtilReadDict(Addr)                                           //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcReadHash BaseDictUtilReadHash(Addr)                                           //07-03-21|0x0062
#define ProcWriteHash BaseDictUtilWriteHash(Addr)                                         //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define TestFileLength ((FileLength >= HashSize) ? Yes : No)                              //07-03-21|0x0062
#define ProcVerifyHash BaseDictUtilVerifyHash(Addr)                                       //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcSearchName BaseDictProcSearch(Addr, Input,  Type)                             //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcPlanNewFirst BaseDictUtilPlan(Addr, 2, Input)                                 //07-03-21|0x0062
#define ProcPlanPrevFirst BaseDictUtilPlan(Addr, 2, 0)                                    //07-03-21|0x0062
#define ProcPlanNewArg BaseDictUtilPlan(Addr, 0, Input)                                   //07-03-21|0x0062
#define ProcPlanNewNext BaseDictUtilPlan(Addr, 3, Input)                                  //07-03-21|0x0062
#define ProcPlanPrevNext BaseDictUtilPlan(Addr, 3, 0)                                     //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcInitialText BaseDictUtilInitialText(Addr)                                     //07-03-21|0x0062
#define ProcLoadText BaseDictUtilLoadText(Addr, Input, Type)                              //07-03-21|0x0062
#define ProcUpdateHash BaseDictUtilUpdateHash(Addr)                                       //07-03-21|0x0062
#define ProcLinkText BaseDictUtilLinkHeaderText(Addr)                                     //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcAppendTextHeader BaseDictUtilWriteTextHeader(Addr,2)                          //07-03-21|0x0062
#define ProcWriteTextHeader BaseDictUtilWriteTextHeader(Addr,1)                           //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcAppendTextString BaseDictUtilWriteText(Addr)                                  //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcInitialHeader BaseDictUtilInitialHeader(Addr,Command)                         //07-03-21|0x0062
#define ProcAddArgHeader BaseDictUtilAddArgHeader(Addr, Input)                            //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcLinkNext BaseDictUtilLinkHeaderNext(Addr)                                     //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcAppendHeader BaseDictUtilWriteHeader(Addr,2)                                  //07-03-21|0x0062
#define ProcWriteHeader BaseDictUtilWriteHeader(Addr,1)                                   //07-03-21|0x0062
#define ProcTestNextHeader ((HeaderNextPosition>=0) ? Yes : No)                           //07-03-21|0x0062
#define ProcTestHeaderText ((TextHeaderPosition>=0) ? Yes : No)                           //07-03-21|0x0062
//--------------------------------------------------------------------                    //07-03-21|0x0062
#define ProcReadHeader(i) BaseDictUtilReadHeader(Addr,i)                                  //07-03-21|0x0062
#define ProcReadFirstHeader ProcReadHeader(TextHeaderPosition)                            //07-03-21|0x0062
#define ProcReadNextHeader ProcReadHeader(HeaderNextPosition)                             //07-03-21|0x0062
//--------------------------------------------------------------------                    //07-03-21|0x0062
#define ProcGetCommand *CommandFar = HeaderCommand                                        //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcPrepArgRead BaseDictUtilPrepareArgRead(Addr,ArgNo)                            //07-03-21|0x0062
#define ProcGetArg BaseDictUtilGetArg(Addr,Output,ArgNo)                                  //07-03-21|0x0062
#define ProcTestArg BaseDictUtilTestArg(Addr,ArgNo)                                       //07-03-21|0x0062
#define ProcUpdateArg BaseDictUtilArgUpdate(Addr)                                         //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcInitHashLoop DictHash = 0                                                     //07-03-21|0x0062
#define ProcTestEmptyHash BaseDictUtilTestHashEmpty(Addr)                                 //07-03-21|0x0062
#define ProcPrepHashUpdate BaseDictUtilPrepHashUpdate(Addr)                               //07-03-21|0x0062
//--------------------------------------------------------------------                    //07-03-21|0x0062
#define ProcDeltaOffset(i) BaseDictUtilUpdateDeltaOffset(Addr, i)                         //07-03-21|0x0062
#define ProcCompDeltaOffset ProcDeltaOffset(-1)                                           //07-03-21|0x0062
#define ProcUpdtDeltaOffset ProcDeltaOffset(Input_Length)                                 //07-03-21|0x0062
//--------------------------------------------------------------------                    //07-03-21|0x0062
#define ProcHashLoopNext (((++DictHash) < NoHash) ? Yes : No)                             //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcHashState2(i,j) BaseDictUtilHashState(DictHash,i,j)                           //07-03-21|0x0062
//--------------------------------------------------------------------                    //07-03-21|0x0062
#define ProcHostHashState1(j) ProcHashState2(&DictHashRecord,j)                           //07-03-21|0x0062
#define ProcHostHashState ProcHostHashState1(FileLength)                                  //07-03-21|0x0062
//--------------------------------------------------------------------                    //07-03-21|0x0062
#define ProcNewHashState1(j) ProcHashState2(InputHashFar,j)                               //07-03-21|0x0062
#define ProcNewHashState ProcNewHashState1(Input_Length)                                  //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcUpdateFirstHash BaseDictUtilFirstHash(Addr,InputHashFar)                      //07-03-21|0x0062
#define ProcUpdateLastHash BaseDictUtilLastHash(Addr,InputHashFar)                        //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcConnectText BaseDictUtilConnectText(Addr,InputHashFar)                        //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcWriteRecord BaseDictUtilWriteRecord(Addr,RecordFar)                           //07-03-21|0x0062
#define ProcReadRecord BaseDictUtilReadRecord(Addr,RecordFar)                             //07-03-21|0x0062
#define ProcCopyHash BaseDictUtilCopyHash(Addr,InputHashFar)                              //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0062
#define ProcCloseDict BaseDictUtilCloseDict(Addr)                                         //07-03-21|0x0062
#define ProcDeleteDict BaseDictUtilDeleteDict(Addr)                                       //07-03-21|0x0062
//**********************************************************************                  //07-03-21|0x0062
//**********************************************************************                  //07-03-21|0x0062
//********************************************************************                    //07-03-21|0x0063
#define ProcCreateHash BaseDictUtilCreateHash(Addr, Input, Type)                          //07-03-21|0x0063
#define ProcTestHash BaseDictUtilTestHash(Addr)                                           //07-03-21|0x0063
#define ProcReadTextHeader BaseDictUtilReadTextHeader(Addr)                               //07-03-21|0x0063
#define ProcReadText BaseDictUtilReadText(Addr)                                           //07-03-21|0x0063
#define ProcTestName BaseDictUtilTestName(Addr, Input, Type)                              //07-03-21|0x0063
#define ProcNextDict BaseDictUtilNextDict(Addr)                                           //07-03-21|0x0063
#define ProcBridgeOffset BaseDictUtilBridgeOffset(Addr, Offset)                           //07-03-21|0x0063
#define ProcTestBridge BaseDictUtilTestBridge(Addr, Input, Type)                          //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcSetBridge1 DictSearchOffset = DictCurrentOffset                               //07-03-21|0x0063
#define ProcSetBridge2 DictSearchBridge = DictCurrentBridge                               //07-03-21|0x0063
#define ProcSetBridge3 found_position   = TextCurrentPosition                             //07-03-21|0x0063
#define ProcSetBridge ProcSetBridge1; ProcSetBridge2; ProcSetBridge3                      //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#define ProcResBridge1 DictCurrentOffset   = DictSearchOffset                             //07-03-21|0x0063
#define ProcResBridge2 DictCurrentBridge   = DictSearchBridge                             //07-03-21|0x0063
#define ProcResBridge3 DictTextPosition    = found_position                               //07-03-21|0x0063
#define ProcRestoreBridge ProcResBridge1; ProcResBridge2; ProcResBridge3                  //07-03-21|0x0063
//********************************************************************                    //07-03-21|0x0063
#ifndef TestIndex                                                                         //07-01-17|0x006e
#define TestIndex 0                                                                       //07-01-17|0x006e
#endif                                                                                    //07-01-17|0x006e
//------------------------------------------------------------------------                //07-01-17|0x006e
enum {  initial_dict_1 = TestIndex };                                                     //07-01-17|0x006e
//------------------------------------------------------------------------                //07-01-17|0x006e
#undef TestIndex                                                                          //07-01-17|0x006e
#define TestIndex initial_dict_1+1                                                        //07-01-17|0x006e
//************************************************************************                //07-01-17|0x006e
#ifndef TestIndex                                                                         //07-01-17|0x0091
#define TestIndex 0                                                                       //07-01-17|0x0091
#endif                                                                                    //07-01-17|0x0091
//------------------------------------------------------------------------                //07-01-17|0x0091
enum {  dict_exists_1 = TestIndex };                                                      //07-01-17|0x0091
//------------------------------------------------------------------------                //07-01-17|0x0091
#undef TestIndex                                                                          //07-01-17|0x0091
#define TestIndex dict_exists_1+1                                                         //07-01-17|0x0091
//************************************************************************                //07-01-17|0x0091
#ifndef TestIndex                                                                         //07-01-17|0x00b0
#define TestIndex 0                                                                       //07-01-17|0x00b0
#endif                                                                                    //07-01-17|0x00b0
//------------------------------------------------------------------------                //07-01-17|0x00b0
enum {  initial_hash_1 = TestIndex };                                                     //07-01-17|0x00b0
//------------------------------------------------------------------------                //07-01-17|0x00b0
#undef TestIndex                                                                          //07-01-17|0x00b0
#define TestIndex initial_hash_1+1                                                        //07-01-17|0x00b0
//************************************************************************                //07-01-17|0x00b0
#ifndef TestIndex                                                                         //07-01-18|0x00d9
#define TestIndex 0                                                                       //07-01-18|0x00d9
#endif                                                                                    //07-01-18|0x00d9
//------------------------------------------------------------------------                //07-01-18|0x00d9
enum {  append_hash_1 = TestIndex };                                                      //07-01-18|0x00d9
//------------------------------------------------------------------------                //07-01-18|0x00d9
#undef TestIndex                                                                          //07-01-18|0x00d9
#define TestIndex append_hash_1+1                                                         //07-01-18|0x00d9
//************************************************************************                //07-01-18|0x00d9
#ifndef TestIndex                                                                         //07-01-23|0x0101
#define TestIndex 0                                                                       //07-01-23|0x0101
#endif                                                                                    //07-01-23|0x0101
//------------------------------------------------------------------------                //07-01-23|0x0101
enum {  read_hash_1 = TestIndex };                                                        //07-01-23|0x0101
//------------------------------------------------------------------------                //07-01-23|0x0101
#undef TestIndex                                                                          //07-01-23|0x0101
#define TestIndex read_hash_1+1                                                           //07-01-23|0x0101
//************************************************************************                //07-01-23|0x0101
#ifndef TestIndex                                                                         //07-01-17|0x012c
#define TestIndex 0                                                                       //07-01-17|0x012c
#endif                                                                                    //07-01-17|0x012c
//------------------------------------------------------------------------                //07-01-17|0x012c
enum {  begin_entry_1 = TestIndex };                                                      //07-01-17|0x012c
//------------------------------------------------------------------------                //07-01-17|0x012c
#undef TestIndex                                                                          //07-01-17|0x012c
#define TestIndex begin_entry_1+1                                                         //07-01-17|0x012c
//************************************************************************                //07-01-17|0x012c
#ifndef TestIndex                                                                         //07-01-17|0x017c
#define TestIndex 0                                                                       //07-01-17|0x017c
#endif                                                                                    //07-01-17|0x017c
//------------------------------------------------------------------------                //07-01-17|0x017c
enum {  add_next_1 = TestIndex };                                                         //07-01-17|0x017c
//------------------------------------------------------------------------                //07-01-17|0x017c
#undef TestIndex                                                                          //07-01-17|0x017c
#define TestIndex add_next_1+1                                                            //07-01-17|0x017c
//************************************************************************                //07-01-17|0x017c
#ifndef TestIndex                                                                         //07-01-17|0x01e1
#define TestIndex 0                                                                       //07-01-17|0x01e1
#endif                                                                                    //07-01-17|0x01e1
//------------------------------------------------------------------------                //07-01-17|0x01e1
enum {  add_arg_1 = TestIndex };                                                          //07-01-17|0x01e1
//------------------------------------------------------------------------                //07-01-17|0x01e1
#undef TestIndex                                                                          //07-01-17|0x01e1
#define TestIndex add_arg_1+1                                                             //07-01-17|0x01e1
//************************************************************************                //07-01-17|0x01e1
#ifndef TestIndex                                                                         //07-01-17|0x022f
#define TestIndex 0                                                                       //07-01-17|0x022f
#endif                                                                                    //07-01-17|0x022f
//------------------------------------------------------------------------                //07-01-17|0x022f
enum {  search_1 = TestIndex };                                                           //07-01-17|0x022f
//------------------------------------------------------------------------                //07-01-17|0x022f
#undef TestIndex                                                                          //07-01-17|0x022f
#define TestIndex search_1+1                                                              //07-01-17|0x022f
//************************************************************************                //07-01-17|0x022f
#ifndef TestIndex                                                                         //07-01-17|0x0230
#define TestIndex 0                                                                       //07-01-17|0x0230
#endif                                                                                    //07-01-17|0x0230
//------------------------------------------------------------------------                //07-01-17|0x0230
enum {  search_2 = TestIndex };                                                           //07-01-17|0x0230
//------------------------------------------------------------------------                //07-01-17|0x0230
#undef TestIndex                                                                          //07-01-17|0x0230
#define TestIndex search_2+1                                                              //07-01-17|0x0230
//************************************************************************                //07-01-17|0x0230
#ifndef TestIndex                                                                         //07-01-23|0x025d
#define TestIndex 0                                                                       //07-01-23|0x025d
#endif                                                                                    //07-01-23|0x025d
//------------------------------------------------------------------------                //07-01-23|0x025d
enum {  get_first_cmd_1 = TestIndex };                                                    //07-01-23|0x025d
//------------------------------------------------------------------------                //07-01-23|0x025d
#undef TestIndex                                                                          //07-01-23|0x025d
#define TestIndex get_first_cmd_1+1                                                       //07-01-23|0x025d
//************************************************************************                //07-01-23|0x025d
#ifndef TestIndex                                                                         //07-01-24|0x0285
#define TestIndex 0                                                                       //07-01-24|0x0285
#endif                                                                                    //07-01-24|0x0285
//------------------------------------------------------------------------                //07-01-24|0x0285
enum {  get_next_cmd_1 = TestIndex };                                                     //07-01-24|0x0285
//------------------------------------------------------------------------                //07-01-24|0x0285
#undef TestIndex                                                                          //07-01-24|0x0285
#define TestIndex get_next_cmd_1+1                                                        //07-01-24|0x0285
//************************************************************************                //07-01-24|0x0285
#ifndef TestIndex                                                                         //07-01-24|0x02b0
#define TestIndex 0                                                                       //07-01-24|0x02b0
#endif                                                                                    //07-01-24|0x02b0
//------------------------------------------------------------------------                //07-01-24|0x02b0
enum {  test_arg_1 = TestIndex };                                                         //07-01-24|0x02b0
//------------------------------------------------------------------------                //07-01-24|0x02b0
#undef TestIndex                                                                          //07-01-24|0x02b0
#define TestIndex test_arg_1+1                                                            //07-01-24|0x02b0
//************************************************************************                //07-01-24|0x02b0
#ifndef TestIndex                                                                         //07-01-24|0x02d4
#define TestIndex 0                                                                       //07-01-24|0x02d4
#endif                                                                                    //07-01-24|0x02d4
//------------------------------------------------------------------------                //07-01-24|0x02d4
enum {  get_arg_1 = TestIndex };                                                          //07-01-24|0x02d4
//------------------------------------------------------------------------                //07-01-24|0x02d4
#undef TestIndex                                                                          //07-01-24|0x02d4
#define TestIndex get_arg_1+1                                                             //07-01-24|0x02d4
//************************************************************************                //07-01-24|0x02d4
#ifndef TestIndex                                                                         //07-01-24|0x02fd
#define TestIndex 0                                                                       //07-01-24|0x02fd
#endif                                                                                    //07-01-24|0x02fd
//------------------------------------------------------------------------                //07-01-24|0x02fd
enum {  arg_update_1 = TestIndex };                                                       //07-01-24|0x02fd
//------------------------------------------------------------------------                //07-01-24|0x02fd
#undef TestIndex                                                                          //07-01-24|0x02fd
#define TestIndex arg_update_1+1                                                          //07-01-24|0x02fd
//************************************************************************                //07-01-24|0x02fd
#ifndef TestIndex                                                                         //07-01-17|0x0321
#define TestIndex 0                                                                       //07-01-17|0x0321
#endif                                                                                    //07-01-17|0x0321
//------------------------------------------------------------------------                //07-01-17|0x0321
enum {  end_entry_1 = TestIndex };                                                        //07-01-17|0x0321
//------------------------------------------------------------------------                //07-01-17|0x0321
#undef TestIndex                                                                          //07-01-17|0x0321
#define TestIndex end_entry_1+1                                                           //07-01-17|0x0321
//************************************************************************                //07-01-17|0x0321
#ifndef TestIndex                                                                         //07-01-18|0x0348
#define TestIndex 0                                                                       //07-01-18|0x0348
#endif                                                                                    //07-01-18|0x0348
//------------------------------------------------------------------------                //07-01-18|0x0348
enum {  complete_1 = TestIndex };                                                         //07-01-18|0x0348
//------------------------------------------------------------------------                //07-01-18|0x0348
#undef TestIndex                                                                          //07-01-18|0x0348
#define TestIndex complete_1+1                                                            //07-01-18|0x0348
//************************************************************************                //07-01-18|0x0348
#ifndef TestIndex                                                                         //07-01-23|0x0377
#define TestIndex 0                                                                       //07-01-23|0x0377
#endif                                                                                    //07-01-23|0x0377
//------------------------------------------------------------------------                //07-01-23|0x0377
enum {  connect_hash_1 = TestIndex };                                                     //07-01-23|0x0377
//------------------------------------------------------------------------                //07-01-23|0x0377
#undef TestIndex                                                                          //07-01-23|0x0377
#define TestIndex connect_hash_1+1                                                        //07-01-23|0x0377
//************************************************************************                //07-01-23|0x0377
#ifndef TestIndex                                                                         //07-01-23|0x039a
#define TestIndex 0                                                                       //07-01-23|0x039a
#endif                                                                                    //07-01-23|0x039a
//------------------------------------------------------------------------                //07-01-23|0x039a
enum {  connect_1 = TestIndex };                                                          //07-01-23|0x039a
//------------------------------------------------------------------------                //07-01-23|0x039a
#undef TestIndex                                                                          //07-01-23|0x039a
#define TestIndex connect_1+1                                                             //07-01-23|0x039a
//************************************************************************                //07-01-23|0x039a
#ifndef TestIndex                                                                         //07-01-23|0x03f3
#define TestIndex 0                                                                       //07-01-23|0x03f3
#endif                                                                                    //07-01-23|0x03f3
//------------------------------------------------------------------------                //07-01-23|0x03f3
enum {  read_record_1 = TestIndex };                                                      //07-01-23|0x03f3
//------------------------------------------------------------------------                //07-01-23|0x03f3
#undef TestIndex                                                                          //07-01-23|0x03f3
#define TestIndex read_record_1+1                                                         //07-01-23|0x03f3
//************************************************************************                //07-01-23|0x03f3
#ifndef TestIndex                                                                         //07-01-23|0x0415
#define TestIndex 0                                                                       //07-01-23|0x0415
#endif                                                                                    //07-01-23|0x0415
//------------------------------------------------------------------------                //07-01-23|0x0415
enum {  write_record_1 = TestIndex };                                                     //07-01-23|0x0415
//------------------------------------------------------------------------                //07-01-23|0x0415
#undef TestIndex                                                                          //07-01-23|0x0415
#define TestIndex write_record_1+1                                                        //07-01-23|0x0415
//************************************************************************                //07-01-23|0x0415
#ifndef TestIndex                                                                         //07-05-11|0x0437
#define TestIndex 0                                                                       //07-05-11|0x0437
#endif                                                                                    //07-05-11|0x0437
//------------------------------------------------------------------------                //07-05-11|0x0437
enum {  initial_bridge_1 = TestIndex };                                                   //07-05-11|0x0437
//------------------------------------------------------------------------                //07-05-11|0x0437
#undef TestIndex                                                                          //07-05-11|0x0437
#define TestIndex initial_bridge_1+1                                                      //07-05-11|0x0437
//************************************************************************                //07-05-11|0x0437
#ifndef TestIndex                                                                         //07-01-23|0x0458
#define TestIndex 0                                                                       //07-01-23|0x0458
#endif                                                                                    //07-01-23|0x0458
//------------------------------------------------------------------------                //07-01-23|0x0458
enum {  bridge_1 = TestIndex };                                                           //07-01-23|0x0458
//------------------------------------------------------------------------                //07-01-23|0x0458
#undef TestIndex                                                                          //07-01-23|0x0458
#define TestIndex bridge_1+1                                                              //07-01-23|0x0458
//************************************************************************                //07-01-23|0x0458
#ifndef TestIndex                                                                         //07-01-18|0x04aa
#define TestIndex 0                                                                       //07-01-18|0x04aa
#endif                                                                                    //07-01-18|0x04aa
//------------------------------------------------------------------------                //07-01-18|0x04aa
enum {  write_hash_1 = TestIndex };                                                       //07-01-18|0x04aa
//------------------------------------------------------------------------                //07-01-18|0x04aa
#undef TestIndex                                                                          //07-01-18|0x04aa
#define TestIndex write_hash_1+1                                                          //07-01-18|0x04aa
//************************************************************************                //07-01-18|0x04aa
#ifndef TestIndex                                                                         //07-01-18|0x04c9
#define TestIndex 0                                                                       //07-01-18|0x04c9
#endif                                                                                    //07-01-18|0x04c9
//------------------------------------------------------------------------                //07-01-18|0x04c9
enum {  close_base_1 = TestIndex };                                                       //07-01-18|0x04c9
//------------------------------------------------------------------------                //07-01-18|0x04c9
#undef TestIndex                                                                          //07-01-18|0x04c9
#define TestIndex close_base_1+1                                                          //07-01-18|0x04c9
//************************************************************************                //07-01-18|0x04c9
#ifndef TestIndex                                                                         //07-01-25|0x04ea
#define TestIndex 0                                                                       //07-01-25|0x04ea
#endif                                                                                    //07-01-25|0x04ea
//------------------------------------------------------------------------                //07-01-25|0x04ea
enum {  delete_dict_1 = TestIndex };                                                      //07-01-25|0x04ea
//------------------------------------------------------------------------                //07-01-25|0x04ea
#undef TestIndex                                                                          //07-01-25|0x04ea
#define TestIndex delete_dict_1+1                                                         //07-01-25|0x04ea
//************************************************************************                //07-01-25|0x04ea
//*******************************************************************************         //05-24-97|0x0519
//*******************************************************************************         //05-24-97|0x0519
//****                       END OF FILE                                     ****         //05-24-97|0x0519
//*******************************************************************************         //05-24-97|0x0519
//*******************************************************************************         //05-24-97|0x0519
#endif                                                                                    //05-24-97|0x0519
