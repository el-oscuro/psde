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
#ifndef basedictutil_h                                                                    //07-04-16|0x000c
#define basedictutil_h                                                                    //07-04-16|0x000c
//***************************************************************************             //07-04-16|0x0026
//***************************************************************************             //07-04-16|0x0027
//******                                                               ******             //07-04-16|0x0028
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //07-04-16|0x0029
//******                                                               ******             //07-04-16|0x002a
//***************************************************************************             //07-04-16|0x002b
//***************************************************************************             //07-04-16|0x002c
//*****************************************************************************           //07-04-16|0x002d
#ifndef FILE_CONTROL_Defined                                                              //07-04-16|0x002d
#define FILE_CONTROL_Defined                                                              //07-04-16|0x002d
//-----------------------------------------------------------------------------           //07-04-16|0x002d
typedef struct {                                                                          //07-04-16|0x002d
  UINT    state;                                                                          //07-04-16|0x002d
  SCHAR   name[_MAX_PATH+1];                                                              //07-04-16|0x002d
  FILE *  stream;                                                                         //07-04-16|0x002d
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //07-04-16|0x002d
//-----------------------------------------------------------------------------           //07-04-16|0x002d
#endif                                                                                    //07-04-16|0x002d
//*******************************************************************************         //07-04-16|0x002e
#ifndef BINARY_FILE_DATA_Defined                                                          //07-04-16|0x002e
#define BINARY_FILE_DATA_Defined                                                          //07-04-16|0x002e
//-------------------------------------------------------------------------------         //07-04-16|0x002e
typedef struct {                                                                          //07-04-16|0x002e
  FILE_CONTROL    file_control;                                                           //07-04-16|0x002e
  SLONG           file_position;                                                          //07-04-16|0x002e
  SLONG           file_length;                                                            //07-04-16|0x002e
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-04-16|0x002e
//-------------------------------------------------------------------------------         //07-04-16|0x002e
#endif                                                                                    //07-04-16|0x002e
//***************************************************************************             //07-04-16|0x002f
//*******************************************************************************         //07-04-16|0x0030
#ifndef STRING_DATA_Defined                                                               //07-04-16|0x0030
#define STRING_DATA_Defined                                                               //07-04-16|0x0030
//-------------------------------------------------------------------------------         //07-04-16|0x0030
typedef struct {                                                                          //07-04-16|0x0030
  SCHAR   line[257];                                                                      //07-04-16|0x0030
  UINT    macro_line_no;                                                                  //07-04-16|0x0030
  UINT    type;                                                                           //07-04-16|0x0030
  UINT    start_col;                                                                      //07-04-16|0x0030
  UINT    start_call;                                                                     //07-04-16|0x0030
  SINT    length;                                                                         //07-04-16|0x0030
  SINT    position;                                                                       //07-04-16|0x0030
  SINT    column;                                                                         //07-04-16|0x0030
  } STRING_DATA, * STRING_DATA_FAR;                                                       //07-04-16|0x0030
//-------------------------------------------------------------------------------         //07-04-16|0x0030
#endif                                                                                    //07-04-16|0x0030
//***************************************************************************             //07-04-16|0x0031
//*******************************************************************************         //07-04-16|0x0032
#ifndef BINARY_FILE_DATA_Defined                                                          //07-04-16|0x0032
#define BINARY_FILE_DATA_Defined                                                          //07-04-16|0x0032
//-------------------------------------------------------------------------------         //07-04-16|0x0032
typedef struct {                                                                          //07-04-16|0x0032
  FILE_CONTROL    file_control;                                                           //07-04-16|0x0032
  SLONG           file_position;                                                          //07-04-16|0x0032
  SLONG           file_length;                                                            //07-04-16|0x0032
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-04-16|0x0032
//-------------------------------------------------------------------------------         //07-04-16|0x0032
#endif                                                                                    //07-04-16|0x0032
//*****************************************************************************           //07-04-16|0x0033
#ifndef DICT_TEXT_HEADER_Defined                                                          //07-04-16|0x0033
#define DICT_TEXT_HEADER_Defined                                                          //07-04-16|0x0033
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //07-04-16|0x0033
//-----------------------------------------------------------------------------           //07-04-16|0x0033
typedef struct {                                                                          //07-04-16|0x0033
  UINT          type;                                                                     //07-04-16|0x0033
  UINT          length;                                                                   //07-04-16|0x0033
  SLONG         delta_bridge;                                                           //%1|0x0033
  SLONG         delta_offset;                                                             //07-04-16|0x0033
  SLONG         next_position;                                                            //07-04-16|0x0033
  SLONG         header_position;                                                          //07-04-16|0x0033
  SLONG         current_position;                                                         //07-04-16|0x0033
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //07-04-16|0x0033
//-----------------------------------------------------------------------------           //07-04-16|0x0033
#endif                                                                                    //07-04-16|0x0033
//*******************************************************************************         //07-04-16|0x0034
#ifndef DICT_TEXT_Defined                                                                 //07-04-16|0x0034
#define DICT_TEXT_Defined                                                                 //07-04-16|0x0034
//-------------------------------------------------------------------------------         //07-04-16|0x0034
typedef struct {                                                                          //07-04-16|0x0034
  DICT_TEXT_HEADER  text_header;                                                          //07-04-16|0x0034
  SCHAR             text_char[257];                                                       //07-04-16|0x0034
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //07-04-16|0x0034
//-------------------------------------------------------------------------------         //07-04-16|0x0034
#endif                                                                                    //07-04-16|0x0034
//*****************************************************************************           //07-04-16|0x0035
#ifndef DICT_HEADER_Defined                                                               //07-04-16|0x0035
#define DICT_HEADER_Defined                                                               //07-04-16|0x0035
//-----------------------------------------------------------------------------           //07-04-16|0x0035
typedef struct {                                                                          //07-04-16|0x0035
  UINT              command;                                                              //07-04-16|0x0035
  SLONG             next_position;                                                        //07-04-16|0x0035
  SLONG             current_position;                                                     //07-04-16|0x0035
  UINT              no_args;                                                              //07-04-16|0x0035
  SLONG             name_position[10];                                                    //07-04-16|0x0035
  UINT              start_col[10];                                                        //07-04-16|0x0035
  UINT              start_call[10];                                                       //07-04-16|0x0035
  UINT              line_no[10];                                                          //07-04-16|0x0035
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //07-04-16|0x0035
//-----------------------------------------------------------------------------           //07-04-16|0x0035
#endif                                                                                    //07-04-16|0x0035
//*****************************************************************************           //07-04-16|0x0036
#ifndef DICT_HASH_ELEMENT_Defined                                                         //07-04-16|0x0036
#define DICT_HASH_ELEMENT_Defined                                                         //07-04-16|0x0036
#define NoHash    2048                                                                    //07-04-16|0x0036
//-----------------------------------------------------------------------------           //07-04-16|0x0036
typedef struct {                                                                          //07-04-16|0x0036
  SLONG last_bridge;                                                                      //07-04-16|0x0036
  SLONG first_bridge;                                                                     //07-04-16|0x0036
  SLONG last_offset;                                                                      //07-04-16|0x0036
  SLONG first_offset;                                                                     //07-04-16|0x0036
  SLONG first;                                                                            //07-04-16|0x0036
  SLONG last;                                                                             //07-04-16|0x0036
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //07-04-16|0x0036
//-----------------------------------------------------------------------------           //07-04-16|0x0036
#endif                                                                                    //07-04-16|0x0036
//*****************************************************************************           //07-04-16|0x0036
#ifndef DICT_HASH_Defined                                                                 //07-04-16|0x0036
#define DICT_HASH_Defined                                                                 //07-04-16|0x0036
//-----------------------------------------------------------------------------           //07-04-16|0x0036
typedef struct {                                                                          //07-04-16|0x0036
  UINT            file_state;                                                             //07-04-16|0x0036
  HASH_ELEM       hash_element[NoHash];                                                   //07-04-16|0x0036
  } DICT_HASH, * DICT_HASH_FAR;                                                           //07-04-16|0x0036
#define HashSize  sizeof(DICT_HASH)                                                       //07-04-16|0x0036
//-----------------------------------------------------------------------------           //07-04-16|0x0036
#endif                                                                                    //07-04-16|0x0036
//*******************************************************************************         //07-04-16|0x0037
#ifndef DICT_DATA_Defined                                                                 //07-04-16|0x0037
#define DICT_DATA_Defined                                                                 //07-04-16|0x0037
//-------------------------------------------------------------------------------         //07-04-16|0x0037
typedef struct {                                                                          //07-04-16|0x0037
  UINT              status;                                                               //07-04-16|0x0037
  UINT              run_flag;                                                             //07-04-16|0x0037
  UINT              process_state;                                                        //07-04-16|0x0037
  UINT              search_state;                                                         //07-04-16|0x0037
  SLONG             text_plan;                                                            //07-04-16|0x0037
  SLONG             header_plan;                                                          //07-04-16|0x0037
  ULONG             hash;                                                                 //07-04-16|0x0037
  SLONG             text_position;                                                        //07-04-16|0x0037
  SLONG             current_bridge;                                                       //07-04-16|0x0037
  SLONG             search_bridge;                                                        //07-04-16|0x0037
  SLONG             lower_bridge;                                                         //07-04-16|0x0037
  SLONG             upper_bridge;                                                         //07-04-16|0x0037
  ULONG             current_offset;                                                       //07-04-16|0x0037
  ULONG             search_offset;                                                        //07-04-16|0x0037
  DICT_HASH         hash_record;                                                          //07-04-16|0x0037
  DICT_HEADER       header_record;                                                        //07-04-16|0x0037
  DICT_TEXT         text_record;                                                          //07-04-16|0x0037
  BINARY_FILE_DATA  file_data;                                                            //07-04-16|0x0037
  } DICT_DATA, * DICT_DATA_FAR;                                                           //07-04-16|0x0037
//-------------------------------------------------------------------------------         //07-04-16|0x0037
#endif                                                                                    //07-04-16|0x0037
//***************************************************************************             //07-04-16|0x0038
//*****************************************************************************           //07-04-16|0x0039
#define DICT_RECORD_SIZE 2048                                                             //07-04-16|0x0039
#ifndef DICT_RECORD_Defined                                                               //07-04-16|0x0039
#define DICT_RECORD_Defined                                                               //07-04-16|0x0039
//-----------------------------------------------------------------------------           //07-04-16|0x0039
typedef struct {                                                                          //07-04-16|0x0039
  WORDS         size;                                                                     //07-04-16|0x0039
  SCHAR         data[DICT_RECORD_SIZE];                                                   //07-04-16|0x0039
  } DICT_RECORD, * DICT_RECORD_FAR;                                                       //07-04-16|0x0039
//-----------------------------------------------------------------------------           //07-04-16|0x0039
#endif                                                                                    //07-04-16|0x0039
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
// CLASS BASEDICTUTIL DEFINITION                                                          //07-04-16|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
class BASEDICTUTIL {                                                                      //07-04-16|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
// CLASS BASEDICTUTIL DEFINITION                                                          //07-04-16|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
    public:                                                                               //07-01-17|0x006d
      UINT dict_name(DICT_DATA_FAR,SCHAR_FAR,SCHAR_FAR);                                  //07-01-17|0x006d
#define BaseDictUtilDictName base_dict_util.dict_name                                     //07-01-17|0x006f
    public:                                                                               //07-01-17|0x0088
      UINT dict_exists(DICT_DATA_FAR,ULONG_FAR);                                          //07-01-17|0x0088
#define BaseDictUtilExists base_dict_util.dict_exists                                     //07-01-17|0x008a
    public:                                                                               //07-01-17|0x00a4
      void initial_process(DICT_DATA_FAR);                                                //07-01-17|0x00a4
#define BaseDictUtilInitProc base_dict_util.initial_process                               //07-01-17|0x00a6
    public:                                                                               //07-01-17|0x00c1
      void init_hash(DICT_DATA_FAR);                                                      //07-01-17|0x00c1
#define BaseDictUtilInitHash base_dict_util.init_hash                                     //07-01-17|0x00c3
    public:                                                                               //07-01-17|0x00e2
      UINT create_dict(DICT_DATA_FAR);                                                    //07-01-17|0x00e2
#define BaseDictUtilCreateDict base_dict_util.create_dict                                 //07-01-17|0x00e4
    public:                                                                               //07-01-18|0x0101
      UINT append_dict(DICT_DATA_FAR);                                                    //07-01-18|0x0101
#define BaseDictUtilAppendDict base_dict_util.append_dict                                 //07-01-18|0x0103
    public:                                                                               //07-01-23|0x0120
      UINT read_dict(DICT_DATA_FAR);                                                      //07-01-23|0x0120
#define BaseDictUtilReadDict base_dict_util.read_dict                                     //07-01-23|0x0122
    public:                                                                               //07-01-18|0x013f
      UINT read_hash(DICT_DATA_FAR);                                                      //07-01-18|0x013f
#define BaseDictUtilReadHash base_dict_util.read_hash                                     //07-01-18|0x0141
    public:                                                                               //07-01-17|0x0159
      UINT write_hash(DICT_DATA_FAR);                                                     //07-01-17|0x0159
#define BaseDictUtilWriteHash base_dict_util.write_hash                                   //07-01-17|0x015b
    public:                                                                               //07-01-18|0x0178
      UINT verify_hash(DICT_DATA_FAR);                                                    //07-01-18|0x0178
#define BaseDictUtilVerifyHash base_dict_util.verify_hash                                 //07-01-18|0x017a
    public:                                                                               //07-01-17|0x01a4
      UINT plan(DICT_DATA_FAR,SLONG,STRING_DATA_FAR);                                     //07-01-17|0x01a4
#define BaseDictUtilPlan base_dict_util.plan                                              //07-01-17|0x01a6
    public:                                                                               //07-01-17|0x01d6
      UINT initial_text(DICT_DATA_FAR);                                                   //07-01-17|0x01d6
#define BaseDictUtilInitialText base_dict_util.initial_text                               //07-01-17|0x01d8
    public:                                                                               //07-04-20|0x01f3
      UINT load_text(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                 //07-04-20|0x01f3
#define BaseDictUtilLoadText base_dict_util.load_text                                     //07-04-20|0x01f5
    public:                                                                               //07-01-17|0x0221
      UINT update_hash(DICT_DATA_FAR);                                                    //07-01-17|0x0221
#define BaseDictUtilUpdateHash base_dict_util.update_hash                                 //07-01-17|0x0223
    public:                                                                               //07-01-17|0x0243
      UINT link_header_text(DICT_DATA_FAR);                                               //07-01-17|0x0243
#define BaseDictUtilLinkHeaderText base_dict_util.link_header_text                        //07-01-17|0x0245
    public:                                                                               //07-01-17|0x025e
      UINT write_text_header(DICT_DATA_FAR,UINT);                                         //07-01-17|0x025e
#define BaseDictUtilWriteTextHeader base_dict_util.write_text_header                      //07-01-17|0x0260
    public:                                                                               //07-01-17|0x028a
      UINT write_text(DICT_DATA_FAR);                                                     //07-01-17|0x028a
#define BaseDictUtilWriteText base_dict_util.write_text                                   //07-01-17|0x028c
    public:                                                                               //07-09-21|0x02b4
      UINT initial_header(DICT_DATA_FAR,UINT);                                            //07-09-21|0x02b4
#define BaseDictUtilInitialHeader base_dict_util.initial_header                           //07-01-17|0x02b6
    public:                                                                               //07-01-17|0x02db
      UINT add_arg_header(DICT_DATA_FAR,STRING_DATA_FAR);                                 //07-01-17|0x02db
#define BaseDictUtilAddArgHeader base_dict_util.add_arg_header                            //07-01-17|0x02dd
    public:                                                                               //07-01-17|0x02f9
      UINT link_header_next(DICT_DATA_FAR);                                               //07-01-17|0x02f9
#define BaseDictUtilLinkHeaderNext base_dict_util.link_header_next                        //07-01-17|0x02fb
    public:                                                                               //07-01-17|0x0313
      UINT write_header(DICT_DATA_FAR,UINT);                                              //07-01-17|0x0313
#define BaseDictUtilWriteHeader base_dict_util.write_header                               //07-01-17|0x0315
    public:                                                                               //07-04-20|0x0342
      UINT create_hash(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                               //07-04-20|0x0342
#define BaseDictUtilCreateHash base_dict_util.create_hash                                 //07-01-17|0x0344
    public:                                                                               //07-01-17|0x037f
      UINT test_hash(DICT_DATA_FAR);                                                      //07-01-17|0x037f
#define BaseDictUtilTestHash base_dict_util.test_hash                                     //07-01-17|0x0381
    public:                                                                               //07-01-17|0x039e
      UINT read_text_header(DICT_DATA_FAR);                                               //07-01-17|0x039e
#define BaseDictUtilReadTextHeader base_dict_util.read_text_header                        //07-01-17|0x03a0
    public:                                                                               //07-01-17|0x03bf
      UINT read_text(DICT_DATA_FAR);                                                      //07-01-17|0x03bf
#define BaseDictUtilReadText base_dict_util.read_text                                     //07-01-17|0x03c1
    public:                                                                               //07-04-20|0x03eb
      UINT test_name(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                 //07-04-20|0x03eb
#define BaseDictUtilTestName base_dict_util.test_name                                     //07-01-17|0x03ed
    public:                                                                               //07-01-18|0x0424
      UINT next_dict(DICT_DATA_FAR);                                                      //07-01-18|0x0424
#define BaseDictUtilNextDict base_dict_util.next_dict                                     //07-01-18|0x0426
    public:                                                                               //07-01-24|0x0442
      UINT read_header(DICT_DATA_FAR,SLONG);                                              //07-01-24|0x0442
#define BaseDictUtilReadHeader base_dict_util.read_header                                 //07-01-24|0x0444
    public:                                                                               //07-01-24|0x0462
      UINT prepare_arg_read(DICT_DATA_FAR,UINT);                                          //07-01-24|0x0462
#define BaseDictUtilPrepareArgRead base_dict_util.prepare_arg_read                        //07-01-24|0x0464
    public:                                                                               //07-01-24|0x0482
      UINT test_arg(DICT_DATA_FAR,UINT);                                                  //07-01-24|0x0482
#define BaseDictUtilTestArg base_dict_util.test_arg                                       //07-01-24|0x0484
    public:                                                                               //07-01-24|0x04a4
      UINT get_arg(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                   //07-01-24|0x04a4
#define BaseDictUtilGetArg base_dict_util.get_arg                                         //07-01-24|0x04a6
    public:                                                                               //07-01-24|0x04d6
      UINT arg_update(DICT_DATA_FAR);                                                     //07-01-24|0x04d6
#define BaseDictUtilArgUpdate base_dict_util.arg_update                                   //07-01-24|0x04d8
    public:                                                                               //07-01-18|0x04f9
      UINT test_hash_empty(DICT_DATA_FAR);                                                //07-01-18|0x04f9
#define BaseDictUtilTestHashEmpty base_dict_util.test_hash_empty                          //07-01-18|0x04fb
    public:                                                                               //07-01-18|0x0517
      UINT prep_hash_update(DICT_DATA_FAR);                                               //07-01-18|0x0517
#define BaseDictUtilPrepHashUpdate base_dict_util.prep_hash_update                        //07-01-18|0x0519
    public:                                                                               //07-01-18|0x0539
      UINT update_delta_offset(DICT_DATA_FAR,SLONG);                                      //07-01-18|0x0539
#define BaseDictUtilUpdateDeltaOffset base_dict_util.update_delta_offset                  //07-01-18|0x053b
    public:                                                                               //07-01-23|0x0564
      UINT hash_state(ULONG,DICT_HASH_FAR,SLONG);                                         //07-01-23|0x0564
#define BaseDictUtilHashState base_dict_util.hash_state                                   //07-01-23|0x0566
    public:                                                                               //07-01-23|0x058d
      UINT copy_hash_(DICT_DATA_FAR,DICT_HASH_FAR);                                       //07-01-23|0x058d
#define BaseDictUtilCopyHash base_dict_util.copy_hash_                                    //07-01-23|0x058f
    public:                                                                               //07-01-23|0x05a6
      UINT first_hash(DICT_DATA_FAR,DICT_HASH_FAR);                                       //07-01-23|0x05a6
#define BaseDictUtilFirstHash base_dict_util.first_hash                                   //07-01-23|0x05a8
    public:                                                                               //07-01-23|0x05c6
      UINT last_hash(DICT_DATA_FAR,DICT_HASH_FAR);                                        //07-01-23|0x05c6
#define BaseDictUtilLastHash base_dict_util.last_hash                                     //07-01-23|0x05c8
    public:                                                                               //07-01-23|0x05e6
      UINT connect_text(DICT_DATA_FAR,DICT_HASH_FAR);                                     //07-01-23|0x05e6
#define BaseDictUtilConnectText base_dict_util.connect_text                               //07-01-23|0x05e8
    public:                                                                               //07-01-24|0x0612
      UINT write_record(DICT_DATA_FAR,DICT_RECORD_FAR);                                   //07-01-24|0x0612
#define BaseDictUtilWriteRecord base_dict_util.write_record                               //07-01-24|0x0614
    public:                                                                               //07-01-23|0x0633
      UINT read_record(DICT_DATA_FAR,DICT_RECORD_FAR);                                    //07-01-23|0x0633
#define BaseDictUtilReadRecord base_dict_util.read_record                                 //07-01-23|0x0635
    public:                                                                               //07-01-23|0x065c
      UINT bridge_offset(DICT_DATA_FAR,SINT);                                             //07-01-23|0x065c
#define BaseDictUtilBridgeOffset base_dict_util.bridge_offset                             //07-01-23|0x065e
    public:                                                                               //07-04-20|0x0687
      UINT test_bridge(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                               //07-04-20|0x0687
#define BaseDictUtilTestBridge base_dict_util.test_bridge                                 //07-01-23|0x0689
    public:                                                                               //07-01-18|0x06ce
      UINT close_dict(DICT_DATA_FAR);                                                     //07-01-18|0x06ce
#define BaseDictUtilCloseDict base_dict_util.close_dict                                   //07-01-18|0x06d0
    public:                                                                               //07-01-25|0x06ea
      UINT delete_dict(DICT_DATA_FAR);                                                    //07-01-25|0x06ea
#define BaseDictUtilDeleteDict base_dict_util.delete_dict                                 //07-01-25|0x06ec
    public:                                                                               //07-01-25|0x070a
      UINT basedictutil_test_reset(void);                                                 //07-01-25|0x070a
#define BaseDictUtilTestReset base_dict_util.basedictutil_test_reset                      //07-01-25|0x070a
    public:                                                                               //07-01-25|0x070c
      UINT basedictutil_test_read(void);                                                  //07-01-25|0x070c
#define BaseDictUtilTestRead base_dict_util.basedictutil_test_read                        //07-01-25|0x070c
    public:                                                                               //07-01-25|0x070e
      UINT basedictutil_test_write(void);                                                 //07-01-25|0x070e
#define BaseDictUtilTestWrite base_dict_util.basedictutil_test_write                      //07-01-25|0x070e
    public:                                                                               //07-01-25|0x0710
      UINT basedictutil_test_report(void);                                                //07-01-25|0x0710
#define BaseDictUtilTestReport base_dict_util.basedictutil_test_report                    //07-01-25|0x0710
    public:                                                                               //07-01-17|0x071a
      BASEDICTUTIL();                                                                     //07-01-17|0x071a
  };                                                                                      //10-29-97|0x0720
extern class BASEDICTUTIL base_dict_util;                                                 //98-12-29|0x0720
//*******************************************************************************         //05-24-97|0x0721
//*******************************************************************************         //05-24-97|0x0721
//****                       END OF FILE                                     ****         //05-24-97|0x0721
//*******************************************************************************         //05-24-97|0x0721
//*******************************************************************************         //05-24-97|0x0721
#endif                                                                                    //05-24-97|0x0721
