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
#ifndef basedictproc_h                                                                    //07-03-21|0x000c
#define basedictproc_h                                                                    //07-03-21|0x000c
//***************************************************************************             //07-03-21|0x0025
//***************************************************************************             //07-03-21|0x0026
//******                                                               ******             //07-03-21|0x0027
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //07-03-21|0x0028
//******                                                               ******             //07-03-21|0x0029
//***************************************************************************             //07-03-21|0x002a
//***************************************************************************             //07-03-21|0x002b
//*****************************************************************************           //07-03-21|0x002c
#ifndef FILE_CONTROL_Defined                                                              //07-03-21|0x002c
#define FILE_CONTROL_Defined                                                              //07-03-21|0x002c
//-----------------------------------------------------------------------------           //07-03-21|0x002c
typedef struct {                                                                          //07-03-21|0x002c
  UINT    state;                                                                          //07-03-21|0x002c
  SCHAR   name[_MAX_PATH+1];                                                              //07-03-21|0x002c
  FILE *  stream;                                                                         //07-03-21|0x002c
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //07-03-21|0x002c
//-----------------------------------------------------------------------------           //07-03-21|0x002c
#endif                                                                                    //07-03-21|0x002c
//*******************************************************************************         //07-03-21|0x002d
#ifndef BINARY_FILE_DATA_Defined                                                          //07-03-21|0x002d
#define BINARY_FILE_DATA_Defined                                                          //07-03-21|0x002d
//-------------------------------------------------------------------------------         //07-03-21|0x002d
typedef struct {                                                                          //07-03-21|0x002d
  FILE_CONTROL    file_control;                                                           //07-03-21|0x002d
  SLONG           file_position;                                                          //07-03-21|0x002d
  SLONG           file_length;                                                            //07-03-21|0x002d
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-03-21|0x002d
//-------------------------------------------------------------------------------         //07-03-21|0x002d
#endif                                                                                    //07-03-21|0x002d
//***************************************************************************             //07-03-21|0x002e
//*******************************************************************************         //07-03-21|0x002f
#ifndef STRING_DATA_Defined                                                               //07-03-21|0x002f
#define STRING_DATA_Defined                                                               //07-03-21|0x002f
//-------------------------------------------------------------------------------         //07-03-21|0x002f
typedef struct {                                                                          //07-03-21|0x002f
  SCHAR   line[257];                                                                      //07-03-21|0x002f
  UINT    macro_line_no;                                                                  //07-03-21|0x002f
  UINT    type;                                                                           //07-03-21|0x002f
  UINT    start_col;                                                                      //07-03-21|0x002f
  UINT    start_call;                                                                     //07-03-21|0x002f
  SINT    length;                                                                         //07-03-21|0x002f
  SINT    position;                                                                       //07-03-21|0x002f
  SINT    column;                                                                         //07-03-21|0x002f
  } STRING_DATA, * STRING_DATA_FAR;                                                       //07-03-21|0x002f
//-------------------------------------------------------------------------------         //07-03-21|0x002f
#endif                                                                                    //07-03-21|0x002f
//***************************************************************************             //07-03-21|0x0030
//*******************************************************************************         //07-03-21|0x0031
#ifndef BINARY_FILE_DATA_Defined                                                          //07-03-21|0x0031
#define BINARY_FILE_DATA_Defined                                                          //07-03-21|0x0031
//-------------------------------------------------------------------------------         //07-03-21|0x0031
typedef struct {                                                                          //07-03-21|0x0031
  FILE_CONTROL    file_control;                                                           //07-03-21|0x0031
  SLONG           file_position;                                                          //07-03-21|0x0031
  SLONG           file_length;                                                            //07-03-21|0x0031
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-03-21|0x0031
//-------------------------------------------------------------------------------         //07-03-21|0x0031
#endif                                                                                    //07-03-21|0x0031
//*****************************************************************************           //07-03-21|0x0032
#ifndef DICT_TEXT_HEADER_Defined                                                          //07-03-21|0x0032
#define DICT_TEXT_HEADER_Defined                                                          //07-03-21|0x0032
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //07-03-21|0x0032
//-----------------------------------------------------------------------------           //07-03-21|0x0032
typedef struct {                                                                          //07-03-21|0x0032
  UINT          type;                                                                     //07-03-21|0x0032
  UINT          length;                                                                   //07-03-21|0x0032
  SLONG         delta_bridge;                                                           //%1|0x0032
  SLONG         delta_offset;                                                             //07-03-21|0x0032
  SLONG         next_position;                                                            //07-03-21|0x0032
  SLONG         header_position;                                                          //07-03-21|0x0032
  SLONG         current_position;                                                         //07-03-21|0x0032
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //07-03-21|0x0032
//-----------------------------------------------------------------------------           //07-03-21|0x0032
#endif                                                                                    //07-03-21|0x0032
//*******************************************************************************         //07-03-21|0x0033
#ifndef DICT_TEXT_Defined                                                                 //07-03-21|0x0033
#define DICT_TEXT_Defined                                                                 //07-03-21|0x0033
//-------------------------------------------------------------------------------         //07-03-21|0x0033
typedef struct {                                                                          //07-03-21|0x0033
  DICT_TEXT_HEADER  text_header;                                                          //07-03-21|0x0033
  SCHAR             text_char[257];                                                       //07-03-21|0x0033
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //07-03-21|0x0033
//-------------------------------------------------------------------------------         //07-03-21|0x0033
#endif                                                                                    //07-03-21|0x0033
//*****************************************************************************           //07-03-21|0x0034
#ifndef DICT_HEADER_Defined                                                               //07-03-21|0x0034
#define DICT_HEADER_Defined                                                               //07-03-21|0x0034
//-----------------------------------------------------------------------------           //07-03-21|0x0034
typedef struct {                                                                          //07-03-21|0x0034
  UINT              command;                                                              //07-03-21|0x0034
  SLONG             next_position;                                                        //07-03-21|0x0034
  SLONG             current_position;                                                     //07-03-21|0x0034
  UINT              no_args;                                                              //07-03-21|0x0034
  SLONG             name_position[10];                                                    //07-03-21|0x0034
  UINT              start_col[10];                                                        //07-03-21|0x0034
  UINT              start_call[10];                                                       //07-03-21|0x0034
  UINT              line_no[10];                                                          //07-03-21|0x0034
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //07-03-21|0x0034
//-----------------------------------------------------------------------------           //07-03-21|0x0034
#endif                                                                                    //07-03-21|0x0034
//*****************************************************************************           //07-03-21|0x0035
#ifndef DICT_HASH_ELEMENT_Defined                                                         //07-03-21|0x0035
#define DICT_HASH_ELEMENT_Defined                                                         //07-03-21|0x0035
#define NoHash    2048                                                                    //07-03-21|0x0035
//-----------------------------------------------------------------------------           //07-03-21|0x0035
typedef struct {                                                                          //07-03-21|0x0035
  SLONG last_bridge;                                                                      //07-03-21|0x0035
  SLONG first_bridge;                                                                     //07-03-21|0x0035
  SLONG last_offset;                                                                      //07-03-21|0x0035
  SLONG first_offset;                                                                     //07-03-21|0x0035
  SLONG first;                                                                            //07-03-21|0x0035
  SLONG last;                                                                             //07-03-21|0x0035
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //07-03-21|0x0035
//-----------------------------------------------------------------------------           //07-03-21|0x0035
#endif                                                                                    //07-03-21|0x0035
//*****************************************************************************           //07-03-21|0x0035
#ifndef DICT_HASH_Defined                                                                 //07-03-21|0x0035
#define DICT_HASH_Defined                                                                 //07-03-21|0x0035
//-----------------------------------------------------------------------------           //07-03-21|0x0035
typedef struct {                                                                          //07-03-21|0x0035
  UINT            file_state;                                                             //07-03-21|0x0035
  HASH_ELEM       hash_element[NoHash];                                                   //07-03-21|0x0035
  } DICT_HASH, * DICT_HASH_FAR;                                                           //07-03-21|0x0035
#define HashSize  sizeof(DICT_HASH)                                                       //07-03-21|0x0035
//-----------------------------------------------------------------------------           //07-03-21|0x0035
#endif                                                                                    //07-03-21|0x0035
//*******************************************************************************         //07-03-21|0x0036
#ifndef DICT_DATA_Defined                                                                 //07-03-21|0x0036
#define DICT_DATA_Defined                                                                 //07-03-21|0x0036
//-------------------------------------------------------------------------------         //07-03-21|0x0036
typedef struct {                                                                          //07-03-21|0x0036
  UINT              status;                                                               //07-03-21|0x0036
  UINT              run_flag;                                                             //07-03-21|0x0036
  UINT              process_state;                                                        //07-03-21|0x0036
  UINT              search_state;                                                         //07-03-21|0x0036
  SLONG             text_plan;                                                            //07-03-21|0x0036
  SLONG             header_plan;                                                          //07-03-21|0x0036
  ULONG             hash;                                                                 //07-03-21|0x0036
  SLONG             text_position;                                                        //07-03-21|0x0036
  SLONG             current_bridge;                                                       //07-03-21|0x0036
  SLONG             search_bridge;                                                        //07-03-21|0x0036
  SLONG             lower_bridge;                                                         //07-03-21|0x0036
  SLONG             upper_bridge;                                                         //07-03-21|0x0036
  ULONG             current_offset;                                                       //07-03-21|0x0036
  ULONG             search_offset;                                                        //07-03-21|0x0036
  DICT_HASH         hash_record;                                                          //07-03-21|0x0036
  DICT_HEADER       header_record;                                                        //07-03-21|0x0036
  DICT_TEXT         text_record;                                                          //07-03-21|0x0036
  BINARY_FILE_DATA  file_data;                                                            //07-03-21|0x0036
  } DICT_DATA, * DICT_DATA_FAR;                                                           //07-03-21|0x0036
//-------------------------------------------------------------------------------         //07-03-21|0x0036
#endif                                                                                    //07-03-21|0x0036
//***************************************************************************             //07-03-21|0x0037
//*****************************************************************************           //07-03-21|0x0038
#define DICT_RECORD_SIZE 2048                                                             //07-03-21|0x0038
#ifndef DICT_RECORD_Defined                                                               //07-03-21|0x0038
#define DICT_RECORD_Defined                                                               //07-03-21|0x0038
//-----------------------------------------------------------------------------           //07-03-21|0x0038
typedef struct {                                                                          //07-03-21|0x0038
  WORDS         size;                                                                     //07-03-21|0x0038
  SCHAR         data[DICT_RECORD_SIZE];                                                   //07-03-21|0x0038
  } DICT_RECORD, * DICT_RECORD_FAR;                                                       //07-03-21|0x0038
//-----------------------------------------------------------------------------           //07-03-21|0x0038
#endif                                                                                    //07-03-21|0x0038
//*******************************************************************************         //10-29-97|0x0040
//*******************************************************************************         //10-29-97|0x0040
// CLASS BASEDICTPROC DEFINITION                                                          //07-03-21|0x0040
//*******************************************************************************         //10-29-97|0x0040
//*******************************************************************************         //10-29-97|0x0040
class BASEDICTPROC {                                                                      //07-03-21|0x0040
//*******************************************************************************         //10-29-97|0x0040
//*******************************************************************************         //10-29-97|0x0040
// CLASS BASEDICTPROC DEFINITION                                                          //07-03-21|0x0040
//*******************************************************************************         //10-29-97|0x0040
//*******************************************************************************         //10-29-97|0x0040
    public:                                                                               //07-01-17|0x0071
      UINT initial_dict(DICT_DATA_FAR,SCHAR_FAR,SCHAR_FAR);                               //07-01-17|0x0071
#define BaseDictProcInitial base_dict_proc.initial_dict                                   //07-01-17|0x0073
    public:                                                                               //07-01-17|0x0094
      UINT dict_exists(DICT_DATA_FAR,ULONG_FAR);                                          //07-01-17|0x0094
#define BaseDictProcExists base_dict_proc.dict_exists                                     //07-01-17|0x0096
    public:                                                                               //07-01-17|0x00b3
      UINT initial_hash(DICT_DATA_FAR);                                                   //07-01-17|0x00b3
#define BaseDictProcInitialHash base_dict_proc.initial_hash                               //07-01-17|0x00b5
    public:                                                                               //07-01-18|0x00dc
      UINT append_hash(DICT_DATA_FAR);                                                    //07-01-18|0x00dc
#define BaseDictProcAppendHash base_dict_proc.append_hash                                 //07-01-18|0x00de
    public:                                                                               //07-01-23|0x0104
      UINT read_hash(DICT_DATA_FAR);                                                      //07-01-23|0x0104
#define BaseDictProcReadHash base_dict_proc.read_hash                                     //07-01-23|0x0106
    public:                                                                               //07-08-21|0x012f
       UINT begin_entry(DICT_DATA_FAR,STRING_DATA_FAR,UINT,UINT);                         //07-08-21|0x012f
#define BaseDictProcBeginEntry base_dict_proc.begin_entry                                 //07-08-21|0x0131
    public:                                                                               //07-08-21|0x017f
       UINT add_next(DICT_DATA_FAR,STRING_DATA_FAR,UINT,UINT);                            //07-08-21|0x017f
#define BaseDictProcAddNext base_dict_proc.add_next                                       //07-01-17|0x0181
    public:                                                                               //07-08-21|0x01e4
      UINT add_arg(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                   //07-08-21|0x01e4
#define BaseDictProcAddArg base_dict_proc.add_arg                                         //07-01-17|0x01e6
    public:                                                                               //07-08-21|0x0233
      UINT search(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                    //07-08-21|0x0233
#define BaseDictProcSearch base_dict_proc.search                                          //07-01-17|0x0235
    public:                                                                               //07-01-23|0x0260
      UINT get_first_cmd(DICT_DATA_FAR,UINT_FAR);                                         //07-01-23|0x0260
#define BaseDictProcGetFirstCmd base_dict_proc.get_first_cmd                              //07-01-23|0x0262
    public:                                                                               //07-01-24|0x0288
      UINT get_next_cmd(DICT_DATA_FAR,UINT_FAR);                                          //07-01-24|0x0288
#define BaseDictProcGetNextCmd base_dict_proc.get_next_cmd                                //07-01-24|0x028a
    public:                                                                               //07-01-24|0x02b3
      UINT test_arg(DICT_DATA_FAR,UINT);                                                  //07-01-24|0x02b3
#define BaseDictProcTestArg base_dict_proc.test_arg                                       //07-01-24|0x02b5
    public:                                                                               //07-01-24|0x02d7
      UINT get_arg(DICT_DATA_FAR,STRING_DATA_FAR,UINT);                                   //07-01-24|0x02d7
#define BaseDictProcGetArg base_dict_proc.get_arg                                         //07-01-24|0x02d9
    public:                                                                               //07-01-24|0x0300
      UINT arg_update(DICT_DATA_FAR);                                                     //07-01-24|0x0300
#define BaseDictProcArgUpdate base_dict_proc.arg_update                                   //07-01-24|0x0302
    public:                                                                               //07-01-17|0x0324
      UINT end_entry(DICT_DATA_FAR);                                                      //07-01-17|0x0324
#define BaseDictProcEndEntry base_dict_proc.end_entry                                     //07-01-17|0x0326
    public:                                                                               //07-01-18|0x034b
      UINT complete(DICT_DATA_FAR);                                                       //07-01-18|0x034b
#define BaseDictProcComplete base_dict_proc.complete                                      //07-01-18|0x034d
    public:                                                                               //07-01-23|0x037a
      UINT connect_hash(DICT_DATA_FAR,DICT_HASH_FAR);                                     //07-01-23|0x037a
#define BaseDictProcConnectHash base_dict_proc.connect_hash                               //07-01-23|0x037c
    public:                                                                               //07-01-23|0x039d
      UINT connect(DICT_DATA_FAR,DICT_HASH_FAR,SLONG);                                    //07-01-23|0x039d
#define BaseDictProcConnect base_dict_proc.connect                                        //07-01-23|0x039f
    public:                                                                               //07-01-23|0x03f6
      UINT read_record(DICT_DATA_FAR,DICT_RECORD_FAR);                                    //07-01-23|0x03f6
#define BaseDictProcReadRecord base_dict_proc.read_record                                 //07-01-23|0x03f8
    public:                                                                               //07-01-23|0x0418
      UINT write_record(DICT_DATA_FAR,DICT_RECORD_FAR);                                   //07-01-23|0x0418
#define BaseDictProcWriteRecord base_dict_proc.write_record                               //07-01-23|0x041a
    public:                                                                               //07-05-11|0x043a
      UINT initial_bridge(DICT_DATA_FAR);                                                 //07-05-11|0x043a
#define BaseDictProcInitialBridge base_dict_proc.initial_bridge                           //07-05-11|0x043c
    public:                                                                               //07-05-11|0x045b
       UINT bridge(DICT_DATA_FAR,STRING_DATA_FAR,SINT,UINT);                              //07-05-11|0x045b
#define BaseDictProcBridge base_dict_proc.bridge                                          //07-01-23|0x045d
    public:                                                                               //07-01-18|0x04ad
      UINT write_hash(DICT_DATA_FAR);                                                     //07-01-18|0x04ad
#define BaseDictProcWriteHash base_dict_proc.write_hash                                   //07-01-18|0x04af
    public:                                                                               //07-01-18|0x04cc
      UINT close_base(DICT_DATA_FAR);                                                     //07-01-18|0x04cc
#define BaseDictProcClose base_dict_proc.close_base                                       //07-01-18|0x04ce
    public:                                                                               //07-01-25|0x04ed
      UINT delete_dict(DICT_DATA_FAR);                                                    //07-01-25|0x04ed
#define BaseDictProcDeleteDict base_dict_proc.delete_dict                                 //07-01-25|0x04ef
    public:                                                                               //07-01-25|0x0502
      UINT basedict_test_reset(void);                                                     //07-01-25|0x0502
#define BaseDictProcTestReset base_dict_proc.basedict_test_reset                          //07-01-25|0x0502
    public:                                                                               //07-01-17|0x0504
      UINT basedict_test_read(void);                                                      //07-01-17|0x0504
#define BaseDictProcTestRead base_dict_proc.basedict_test_read                            //07-01-17|0x0504
    public:                                                                               //07-03-21|0x0506
      UINT basedict_test_write(void);                                                     //07-03-21|0x0506
#define BaseDictProcTestWrite base_dict_proc.basedict_test_write                          //07-03-21|0x0506
    public:                                                                               //07-03-21|0x0508
      UINT basedict_test_report(void);                                                    //07-03-21|0x0508
#define BaseDictProcTestReport base_dict_proc.basedict_test_report                        //07-03-21|0x0508
    public:                                                                               //07-01-17|0x0512
      BASEDICTPROC();                                                                     //07-01-17|0x0512
  };                                                                                      //10-29-97|0x0518
extern class BASEDICTPROC base_dict_proc;                                                 //98-12-29|0x0518
//*******************************************************************************         //05-24-97|0x0519
//*******************************************************************************         //05-24-97|0x0519
//****                       END OF FILE                                     ****         //05-24-97|0x0519
//*******************************************************************************         //05-24-97|0x0519
//*******************************************************************************         //05-24-97|0x0519
#endif                                                                                    //05-24-97|0x0519
