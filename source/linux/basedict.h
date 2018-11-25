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
#ifndef basedict_h                                                                        //07-03-21|0x000c
#define basedict_h                                                                        //07-03-21|0x000c
//***************************************************************************             //07-03-21|0x0026
//***************************************************************************             //07-03-21|0x0027
//******                                                               ******             //07-03-21|0x0028
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //07-03-21|0x0029
//******                                                               ******             //07-03-21|0x002a
//***************************************************************************             //07-03-21|0x002b
//***************************************************************************             //07-03-21|0x002c
//*****************************************************************************           //07-03-21|0x002d
#ifndef FILE_CONTROL_Defined                                                              //07-03-21|0x002d
#define FILE_CONTROL_Defined                                                              //07-03-21|0x002d
//-----------------------------------------------------------------------------           //07-03-21|0x002d
typedef struct {                                                                          //07-03-21|0x002d
  UINT    state;                                                                          //07-03-21|0x002d
  SCHAR   name[_MAX_PATH+1];                                                              //07-03-21|0x002d
  FILE *  stream;                                                                         //07-03-21|0x002d
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //07-03-21|0x002d
//-----------------------------------------------------------------------------           //07-03-21|0x002d
#endif                                                                                    //07-03-21|0x002d
//*******************************************************************************         //07-03-21|0x002e
#ifndef BINARY_FILE_DATA_Defined                                                          //07-03-21|0x002e
#define BINARY_FILE_DATA_Defined                                                          //07-03-21|0x002e
//-------------------------------------------------------------------------------         //07-03-21|0x002e
typedef struct {                                                                          //07-03-21|0x002e
  FILE_CONTROL    file_control;                                                           //07-03-21|0x002e
  SLONG           file_position;                                                          //07-03-21|0x002e
  SLONG           file_length;                                                            //07-03-21|0x002e
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-03-21|0x002e
//-------------------------------------------------------------------------------         //07-03-21|0x002e
#endif                                                                                    //07-03-21|0x002e
//***************************************************************************             //07-03-21|0x002f
//*******************************************************************************         //07-03-21|0x0030
#ifndef STRING_DATA_Defined                                                               //07-03-21|0x0030
#define STRING_DATA_Defined                                                               //07-03-21|0x0030
//-------------------------------------------------------------------------------         //07-03-21|0x0030
typedef struct {                                                                          //07-03-21|0x0030
  SCHAR   line[257];                                                                      //07-03-21|0x0030
  UINT    macro_line_no;                                                                  //07-03-21|0x0030
  UINT    type;                                                                           //07-03-21|0x0030
  UINT    start_col;                                                                      //07-03-21|0x0030
  UINT    start_call;                                                                     //07-03-21|0x0030
  SINT    length;                                                                         //07-03-21|0x0030
  SINT    position;                                                                       //07-03-21|0x0030
  SINT    column;                                                                         //07-03-21|0x0030
  } STRING_DATA, * STRING_DATA_FAR;                                                       //07-03-21|0x0030
//-------------------------------------------------------------------------------         //07-03-21|0x0030
#endif                                                                                    //07-03-21|0x0030
//***************************************************************************             //07-03-21|0x0031
//*******************************************************************************         //07-03-21|0x0032
#ifndef BINARY_FILE_DATA_Defined                                                          //07-03-21|0x0032
#define BINARY_FILE_DATA_Defined                                                          //07-03-21|0x0032
//-------------------------------------------------------------------------------         //07-03-21|0x0032
typedef struct {                                                                          //07-03-21|0x0032
  FILE_CONTROL    file_control;                                                           //07-03-21|0x0032
  SLONG           file_position;                                                          //07-03-21|0x0032
  SLONG           file_length;                                                            //07-03-21|0x0032
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-03-21|0x0032
//-------------------------------------------------------------------------------         //07-03-21|0x0032
#endif                                                                                    //07-03-21|0x0032
//*****************************************************************************           //07-03-21|0x0033
#ifndef DICT_TEXT_HEADER_Defined                                                          //07-03-21|0x0033
#define DICT_TEXT_HEADER_Defined                                                          //07-03-21|0x0033
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //07-03-21|0x0033
//-----------------------------------------------------------------------------           //07-03-21|0x0033
typedef struct {                                                                          //07-03-21|0x0033
  UINT          type;                                                                     //07-03-21|0x0033
  UINT          length;                                                                   //07-03-21|0x0033
  SLONG         delta_bridge;                                                           //%1|0x0033
  SLONG         delta_offset;                                                             //07-03-21|0x0033
  SLONG         next_position;                                                            //07-03-21|0x0033
  SLONG         header_position;                                                          //07-03-21|0x0033
  SLONG         current_position;                                                         //07-03-21|0x0033
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //07-03-21|0x0033
//-----------------------------------------------------------------------------           //07-03-21|0x0033
#endif                                                                                    //07-03-21|0x0033
//*******************************************************************************         //07-03-21|0x0034
#ifndef DICT_TEXT_Defined                                                                 //07-03-21|0x0034
#define DICT_TEXT_Defined                                                                 //07-03-21|0x0034
//-------------------------------------------------------------------------------         //07-03-21|0x0034
typedef struct {                                                                          //07-03-21|0x0034
  DICT_TEXT_HEADER  text_header;                                                          //07-03-21|0x0034
  SCHAR             text_char[257];                                                       //07-03-21|0x0034
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //07-03-21|0x0034
//-------------------------------------------------------------------------------         //07-03-21|0x0034
#endif                                                                                    //07-03-21|0x0034
//*****************************************************************************           //07-03-21|0x0035
#ifndef DICT_HEADER_Defined                                                               //07-03-21|0x0035
#define DICT_HEADER_Defined                                                               //07-03-21|0x0035
//-----------------------------------------------------------------------------           //07-03-21|0x0035
typedef struct {                                                                          //07-03-21|0x0035
  UINT              command;                                                              //07-03-21|0x0035
  SLONG             next_position;                                                        //07-03-21|0x0035
  SLONG             current_position;                                                     //07-03-21|0x0035
  UINT              no_args;                                                              //07-03-21|0x0035
  SLONG             name_position[10];                                                    //07-03-21|0x0035
  UINT              start_col[10];                                                        //07-03-21|0x0035
  UINT              start_call[10];                                                       //07-03-21|0x0035
  UINT              line_no[10];                                                          //07-03-21|0x0035
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //07-03-21|0x0035
//-----------------------------------------------------------------------------           //07-03-21|0x0035
#endif                                                                                    //07-03-21|0x0035
//*****************************************************************************           //07-03-21|0x0036
#ifndef DICT_HASH_ELEMENT_Defined                                                         //07-03-21|0x0036
#define DICT_HASH_ELEMENT_Defined                                                         //07-03-21|0x0036
#define NoHash    2048                                                                    //07-03-21|0x0036
//-----------------------------------------------------------------------------           //07-03-21|0x0036
typedef struct {                                                                          //07-03-21|0x0036
  SLONG last_bridge;                                                                      //07-03-21|0x0036
  SLONG first_bridge;                                                                     //07-03-21|0x0036
  SLONG last_offset;                                                                      //07-03-21|0x0036
  SLONG first_offset;                                                                     //07-03-21|0x0036
  SLONG first;                                                                            //07-03-21|0x0036
  SLONG last;                                                                             //07-03-21|0x0036
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //07-03-21|0x0036
//-----------------------------------------------------------------------------           //07-03-21|0x0036
#endif                                                                                    //07-03-21|0x0036
//*****************************************************************************           //07-03-21|0x0036
#ifndef DICT_HASH_Defined                                                                 //07-03-21|0x0036
#define DICT_HASH_Defined                                                                 //07-03-21|0x0036
//-----------------------------------------------------------------------------           //07-03-21|0x0036
typedef struct {                                                                          //07-03-21|0x0036
  UINT            file_state;                                                             //07-03-21|0x0036
  HASH_ELEM       hash_element[NoHash];                                                   //07-03-21|0x0036
  } DICT_HASH, * DICT_HASH_FAR;                                                           //07-03-21|0x0036
#define HashSize  sizeof(DICT_HASH)                                                       //07-03-21|0x0036
//-----------------------------------------------------------------------------           //07-03-21|0x0036
#endif                                                                                    //07-03-21|0x0036
//*******************************************************************************         //07-03-21|0x0037
#ifndef DICT_DATA_Defined                                                                 //07-03-21|0x0037
#define DICT_DATA_Defined                                                                 //07-03-21|0x0037
//-------------------------------------------------------------------------------         //07-03-21|0x0037
typedef struct {                                                                          //07-03-21|0x0037
  UINT              status;                                                               //07-03-21|0x0037
  UINT              run_flag;                                                             //07-03-21|0x0037
  UINT              process_state;                                                        //07-03-21|0x0037
  UINT              search_state;                                                         //07-03-21|0x0037
  SLONG             text_plan;                                                            //07-03-21|0x0037
  SLONG             header_plan;                                                          //07-03-21|0x0037
  ULONG             hash;                                                                 //07-03-21|0x0037
  SLONG             text_position;                                                        //07-03-21|0x0037
  SLONG             current_bridge;                                                       //07-03-21|0x0037
  SLONG             search_bridge;                                                        //07-03-21|0x0037
  SLONG             lower_bridge;                                                         //07-03-21|0x0037
  SLONG             upper_bridge;                                                         //07-03-21|0x0037
  ULONG             current_offset;                                                       //07-03-21|0x0037
  ULONG             search_offset;                                                        //07-03-21|0x0037
  DICT_HASH         hash_record;                                                          //07-03-21|0x0037
  DICT_HEADER       header_record;                                                        //07-03-21|0x0037
  DICT_TEXT         text_record;                                                          //07-03-21|0x0037
  BINARY_FILE_DATA  file_data;                                                            //07-03-21|0x0037
  } DICT_DATA, * DICT_DATA_FAR;                                                           //07-03-21|0x0037
//-------------------------------------------------------------------------------         //07-03-21|0x0037
#endif                                                                                    //07-03-21|0x0037
//***************************************************************************             //07-03-21|0x0038
//*****************************************************************************           //07-03-21|0x0039
#define DICT_RECORD_SIZE 2048                                                             //07-03-21|0x0039
#ifndef DICT_RECORD_Defined                                                               //07-03-21|0x0039
#define DICT_RECORD_Defined                                                               //07-03-21|0x0039
//-----------------------------------------------------------------------------           //07-03-21|0x0039
typedef struct {                                                                          //07-03-21|0x0039
  WORDS         size;                                                                     //07-03-21|0x0039
  SCHAR         data[DICT_RECORD_SIZE];                                                   //07-03-21|0x0039
  } DICT_RECORD, * DICT_RECORD_FAR;                                                       //07-03-21|0x0039
//-----------------------------------------------------------------------------           //07-03-21|0x0039
#endif                                                                                    //07-03-21|0x0039
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
// CLASS BASEDICT DEFINITION                                                              //07-03-21|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
class BASEDICT {                                                                          //07-03-21|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
// CLASS BASEDICT DEFINITION                                                              //07-03-21|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
    public:                                                                               //11-02-26|0x006f
      UINT base_dict_get_cert(DICT_DATA_FAR,STRING_DATA_FAR);                             //11-02-26|0x006f
#define BaseDictGetCert base_dict.base_dict_get_cert                                      //11-02-26|0x0071
    public:                                                                               //07-01-17|0x00b9
      UINT initial_dict(DICT_DATA_FAR,SCHAR_FAR,SCHAR_FAR);                               //07-01-17|0x00b9
#define BaseDictInitial base_dict.initial_dict                                            //07-01-17|0x00bb
    public:                                                                               //07-01-17|0x00d3
      UINT dict_exists(DICT_DATA_FAR,ULONG_FAR);                                          //07-01-17|0x00d3
#define BaseDictExists base_dict.dict_exists                                              //07-01-17|0x00d5
    public:                                                                               //07-01-17|0x00ed
      UINT initial_hash(DICT_DATA_FAR);                                                   //07-01-17|0x00ed
#define BaseDictInitialHash base_dict.initial_hash                                        //07-01-17|0x00ef
    public:                                                                               //07-01-18|0x010a
      UINT append_hash(DICT_DATA_FAR);                                                    //07-01-18|0x010a
#define BaseDictAppendHash base_dict.append_hash                                          //07-01-18|0x010c
    public:                                                                               //09-07-10|0x012b
      UINT append_dict(DICT_DATA_FAR);                                                    //09-07-10|0x012b
#define BaseDictAppendDict base_dict.append_dict                                          //09-07-10|0x012d
    public:                                                                               //07-01-23|0x014a
      UINT read_hash(DICT_DATA_FAR);                                                      //07-01-23|0x014a
#define BaseDictReadHash base_dict.read_hash                                              //07-01-23|0x014c
    public:                                                                               //07-01-17|0x016d
       UINT begin_entry(DICT_DATA_FAR,STRING_DATA_FAR,UINT,UINT);                         //07-01-17|0x016d
#define BaseDictBeginEntry base_dict.begin_entry                                          //07-01-17|0x016f
    public:                                                                               //07-08-22|0x0191
       UINT add_next(DICT_DATA_FAR,STRING_DATA_FAR,UINT,UINT);                            //07-08-22|0x0191
#define BaseDictAddNext base_dict.add_next                                                //07-08-22|0x0193
    public:                                                                               //07-08-22|0x01b9
      UINT add_arg(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                   //07-08-22|0x01b9
#define BaseDictAddArg base_dict.add_arg                                                  //07-01-17|0x01bb
    public:                                                                               //07-08-22|0x01e3
      UINT search(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                    //07-08-22|0x01e3
#define BaseDictSearch base_dict.search                                                   //07-01-24|0x01e5
    public:                                                                               //07-01-23|0x0206
      UINT get_first_cmd(DICT_DATA_FAR,UINT_FAR);                                         //07-01-23|0x0206
#define BaseDictGetFirstCmd base_dict.get_first_cmd                                       //07-01-23|0x0208
    public:                                                                               //07-01-24|0x0231
      UINT get_next_cmd(DICT_DATA_FAR,UINT_FAR);                                          //07-01-24|0x0231
#define BaseDictGetNextCmd base_dict.get_next_cmd                                         //07-01-24|0x0233
    public:                                                                               //07-01-24|0x025e
      UINT test_arg(DICT_DATA_FAR,UINT);                                                  //07-01-24|0x025e
#define BaseDictTestArg base_dict.test_arg                                                //07-01-24|0x0260
    public:                                                                               //07-01-24|0x0286
      UINT get_arg(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                   //07-01-24|0x0286
#define BaseDictGetArg base_dict.get_arg                                                  //07-01-24|0x0288
    public:                                                                               //07-01-24|0x02b0
      UINT arg_update(DICT_DATA_FAR);                                                     //07-01-24|0x02b0
#define BaseDictArgUpdate base_dict.arg_update                                            //07-01-24|0x02b2
    public:                                                                               //07-01-17|0x02d3
      UINT end_entry(DICT_DATA_FAR);                                                      //07-01-17|0x02d3
#define BaseDictEndEntry base_dict.end_entry                                              //07-01-17|0x02d5
    public:                                                                               //07-01-18|0x02ff
      UINT complete(DICT_DATA_FAR);                                                       //07-01-18|0x02ff
#define BaseDictComplete base_dict.complete                                               //07-01-18|0x0301
    public:                                                                               //06-12-08|0x0320
      UINT connect(DICT_DATA_FAR,DICT_HASH_FAR,SLONG);                                    //06-12-08|0x0320
#define BaseDictConnect base_dict.connect                                                 //06-12-08|0x0322
    public:                                                                               //07-01-23|0x0341
      UINT write_record(DICT_DATA_FAR,DICT_RECORD_FAR);                                   //07-01-23|0x0341
#define BaseDictWriteRecord base_dict.write_record                                        //07-01-23|0x0343
    public:                                                                               //07-01-23|0x0363
      UINT read_header(DICT_DATA_FAR,DICT_HASH_FAR);                                      //07-01-23|0x0363
#define BaseDictReadHeader base_dict.read_header                                          //07-01-23|0x0365
    public:                                                                               //07-01-23|0x0382
      UINT read_record(DICT_DATA_FAR,DICT_RECORD_FAR);                                    //07-01-23|0x0382
#define BaseDictReadRecord base_dict.read_record                                          //07-01-23|0x0384
    public:                                                                               //07-08-22|0x03a4
      UINT initial_bridge(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                            //07-08-22|0x03a4
#define BaseDictInitialBridge base_dict.initial_bridge                                    //07-08-22|0x03a6
    public:                                                                               //07-08-22|0x03ca
       UINT bridge(DICT_DATA_FAR,STRING_DATA_FAR,SINT,UINT);                              //07-08-22|0x03ca
#define BaseDictBridge base_dict.bridge                                                   //07-01-23|0x03cc
    public:                                                                               //07-01-18|0x03ef
      UINT close_base(DICT_DATA_FAR);                                                     //07-01-18|0x03ef
#define BaseDictClose base_dict.close_base                                                //07-01-18|0x03f1
    public:                                                                               //07-03-21|0x041c
      UINT close_emergency(DICT_DATA_FAR);                                                //07-03-21|0x041c
#define BaseDictCloseEmergency base_dict.close_emergency                                  //07-03-21|0x041e
    public:                                                                               //07-01-25|0x0436
      UINT delete_dict(DICT_DATA_FAR);                                                    //07-01-25|0x0436
#define BaseDictDeleteDict base_dict.delete_dict                                          //07-01-25|0x0438
    public:                                                                               //07-01-25|0x044a
      UINT basedict_test_reset(void);                                                     //07-01-25|0x044a
#define BaseDictTestReset base_dict.basedict_test_reset                                   //07-01-25|0x044a
    public:                                                                               //07-01-17|0x044c
      UINT basedict_test_read(void);                                                      //07-01-17|0x044c
#define BaseDictTestRead base_dict.basedict_test_read                                     //07-01-17|0x044c
    public:                                                                               //07-03-21|0x044e
      UINT basedict_test_write(void);                                                     //07-03-21|0x044e
#define BaseDictTestWrite base_dict.basedict_test_write                                   //07-03-21|0x044e
    public:                                                                               //07-03-21|0x0450
      UINT basedict_test_report(void);                                                    //07-03-21|0x0450
#define BaseDictTestReport base_dict.basedict_test_report                                 //07-03-21|0x0450
    public:                                                                               //07-01-17|0x045a
      BASEDICT();                                                                         //07-01-17|0x045a
  };                                                                                      //10-29-97|0x0460
extern class BASEDICT base_dict;                                                          //98-12-29|0x0460
//*******************************************************************************         //05-24-97|0x0461
//*******************************************************************************         //05-24-97|0x0461
//****                       END OF FILE                                     ****         //05-24-97|0x0461
//*******************************************************************************         //05-24-97|0x0461
//*******************************************************************************         //05-24-97|0x0461
#endif                                                                                    //05-24-97|0x0461
