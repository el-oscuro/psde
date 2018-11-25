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
#ifndef macdict_h                                                                         //06-07-12|0x000c
#define macdict_h                                                                         //06-07-12|0x000c
//***************************************************************************             //06-07-12|0x0028
//***************************************************************************             //06-07-12|0x0029
//******                                                               ******             //06-07-12|0x002a
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x002b
//******                                                               ******             //06-07-12|0x002c
//***************************************************************************             //06-07-12|0x002d
//***************************************************************************             //06-07-12|0x002e
//*****************************************************************************           //06-07-12|0x002f
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x002f
#define FILE_CONTROL_Defined                                                              //06-07-12|0x002f
//-----------------------------------------------------------------------------           //06-07-12|0x002f
typedef struct {                                                                          //06-07-12|0x002f
  UINT    state;                                                                          //06-07-12|0x002f
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x002f
  FILE *  stream;                                                                         //06-07-12|0x002f
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x002f
//-----------------------------------------------------------------------------           //06-07-12|0x002f
#endif                                                                                    //06-07-12|0x002f
//*******************************************************************************         //06-07-12|0x0030
#ifndef BINARY_FILE_DATA_Defined                                                          //06-07-12|0x0030
#define BINARY_FILE_DATA_Defined                                                          //06-07-12|0x0030
//-------------------------------------------------------------------------------         //06-07-12|0x0030
typedef struct {                                                                          //06-07-12|0x0030
  FILE_CONTROL    file_control;                                                           //06-07-12|0x0030
  SLONG           file_position;                                                          //06-07-12|0x0030
  SLONG           file_length;                                                            //06-07-12|0x0030
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //06-07-12|0x0030
//-------------------------------------------------------------------------------         //06-07-12|0x0030
#endif                                                                                    //06-07-12|0x0030
//***************************************************************************             //06-07-12|0x0031
//*******************************************************************************         //06-07-12|0x0032
#ifndef STRING_DATA_Defined                                                               //06-07-12|0x0032
#define STRING_DATA_Defined                                                               //06-07-12|0x0032
//-------------------------------------------------------------------------------         //06-07-12|0x0032
typedef struct {                                                                          //06-07-12|0x0032
  SCHAR   line[257];                                                                      //06-07-12|0x0032
  UINT    macro_line_no;                                                                  //06-07-12|0x0032
  UINT    type;                                                                           //06-07-12|0x0032
  UINT    start_col;                                                                      //06-07-12|0x0032
  UINT    start_call;                                                                     //06-07-12|0x0032
  SINT    length;                                                                         //06-07-12|0x0032
  SINT    position;                                                                       //06-07-12|0x0032
  SINT    column;                                                                         //06-07-12|0x0032
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-12|0x0032
//-------------------------------------------------------------------------------         //06-07-12|0x0032
#endif                                                                                    //06-07-12|0x0032
//*******************************************************************************         //06-07-12|0x0033
#ifndef TOKENS_Defined                                                                    //06-07-12|0x0033
#define TOKENS_Defined                                                                    //06-07-12|0x0033
//-------------------------------------------------------------------------------         //06-07-12|0x0033
typedef struct {                                                                          //06-07-12|0x0033
  UINT        no_tokens;                                                                  //06-07-12|0x0033
  STRING_DATA token[10];                                                                  //06-07-12|0x0033
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-12|0x0033
//-------------------------------------------------------------------------------         //06-07-12|0x0033
#endif                                                                                    //06-07-12|0x0033
//***************************************************************************             //06-07-12|0x0034
//*****************************************************************************           //06-07-12|0x0035
#ifndef DICT_TEXT_HEADER_Defined                                                          //06-07-12|0x0035
#define DICT_TEXT_HEADER_Defined                                                          //06-07-12|0x0035
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //06-07-12|0x0035
//-----------------------------------------------------------------------------           //06-07-12|0x0035
typedef struct {                                                                          //06-07-12|0x0035
  UINT          type;                                                                     //06-07-12|0x0035
  UINT          length;                                                                   //06-07-12|0x0035
  SLONG         delta_bridge;                                                           //%1|0x0035
  SLONG         delta_offset;                                                             //06-07-12|0x0035
  SLONG         next_position;                                                            //06-07-12|0x0035
  SLONG         header_position;                                                          //06-07-12|0x0035
  SLONG         current_position;                                                         //06-07-12|0x0035
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //06-07-12|0x0035
//-----------------------------------------------------------------------------           //06-07-12|0x0035
#endif                                                                                    //06-07-12|0x0035
//*******************************************************************************         //06-07-12|0x0036
#ifndef DICT_TEXT_Defined                                                                 //06-07-12|0x0036
#define DICT_TEXT_Defined                                                                 //06-07-12|0x0036
//-------------------------------------------------------------------------------         //06-07-12|0x0036
typedef struct {                                                                          //06-07-12|0x0036
  DICT_TEXT_HEADER  text_header;                                                          //06-07-12|0x0036
  SCHAR             text_char[257];                                                       //06-07-12|0x0036
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //06-07-12|0x0036
//-------------------------------------------------------------------------------         //06-07-12|0x0036
#endif                                                                                    //06-07-12|0x0036
//*****************************************************************************           //06-07-12|0x0037
#ifndef DICT_HEADER_Defined                                                               //06-07-12|0x0037
#define DICT_HEADER_Defined                                                               //06-07-12|0x0037
//-----------------------------------------------------------------------------           //06-07-12|0x0037
typedef struct {                                                                          //06-07-12|0x0037
  UINT              command;                                                              //06-07-12|0x0037
  SLONG             next_position;                                                        //06-07-12|0x0037
  SLONG             current_position;                                                     //06-07-12|0x0037
  UINT              no_args;                                                              //06-07-12|0x0037
  SLONG             name_position[10];                                                    //06-07-12|0x0037
  UINT              start_col[10];                                                        //06-07-12|0x0037
  UINT              start_call[10];                                                       //06-07-12|0x0037
  UINT              line_no[10];                                                          //06-07-12|0x0037
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //06-07-12|0x0037
//-----------------------------------------------------------------------------           //06-07-12|0x0037
#endif                                                                                    //06-07-12|0x0037
//*****************************************************************************           //06-07-12|0x0038
#ifndef DICT_HASH_ELEMENT_Defined                                                         //06-07-12|0x0038
#define DICT_HASH_ELEMENT_Defined                                                         //06-07-12|0x0038
#define NoHash    2048                                                                    //06-07-12|0x0038
//-----------------------------------------------------------------------------           //06-07-12|0x0038
typedef struct {                                                                          //06-07-12|0x0038
  SLONG last_bridge;                                                                      //06-07-12|0x0038
  SLONG first_bridge;                                                                     //06-07-12|0x0038
  SLONG last_offset;                                                                      //06-07-12|0x0038
  SLONG first_offset;                                                                     //06-07-12|0x0038
  SLONG first;                                                                            //06-07-12|0x0038
  SLONG last;                                                                             //06-07-12|0x0038
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //06-07-12|0x0038
//-----------------------------------------------------------------------------           //06-07-12|0x0038
#endif                                                                                    //06-07-12|0x0038
//*****************************************************************************           //06-07-12|0x0038
#ifndef DICT_HASH_Defined                                                                 //06-07-12|0x0038
#define DICT_HASH_Defined                                                                 //06-07-12|0x0038
//-----------------------------------------------------------------------------           //06-07-12|0x0038
typedef struct {                                                                          //06-07-12|0x0038
  UINT            file_state;                                                             //06-07-12|0x0038
  HASH_ELEM       hash_element[NoHash];                                                   //06-07-12|0x0038
  } DICT_HASH, * DICT_HASH_FAR;                                                           //06-07-12|0x0038
#define HashSize  sizeof(DICT_HASH)                                                       //06-07-12|0x0038
//-----------------------------------------------------------------------------           //06-07-12|0x0038
#endif                                                                                    //06-07-12|0x0038
//*******************************************************************************         //06-07-12|0x0039
#ifndef DICT_DATA_Defined                                                                 //06-07-12|0x0039
#define DICT_DATA_Defined                                                                 //06-07-12|0x0039
//-------------------------------------------------------------------------------         //06-07-12|0x0039
typedef struct {                                                                          //06-07-12|0x0039
  UINT              status;                                                               //06-07-12|0x0039
  UINT              run_flag;                                                             //06-07-12|0x0039
  UINT              process_state;                                                        //06-07-12|0x0039
  UINT              search_state;                                                         //06-07-12|0x0039
  SLONG             text_plan;                                                            //06-07-12|0x0039
  SLONG             header_plan;                                                          //06-07-12|0x0039
  ULONG             hash;                                                                 //06-07-12|0x0039
  SLONG             text_position;                                                        //06-07-12|0x0039
  SLONG             current_bridge;                                                       //06-07-12|0x0039
  SLONG             search_bridge;                                                        //06-07-12|0x0039
  SLONG             lower_bridge;                                                         //06-07-12|0x0039
  SLONG             upper_bridge;                                                         //06-07-12|0x0039
  ULONG             current_offset;                                                       //06-07-12|0x0039
  ULONG             search_offset;                                                        //06-07-12|0x0039
  DICT_HASH         hash_record;                                                          //06-07-12|0x0039
  DICT_HEADER       header_record;                                                        //06-07-12|0x0039
  DICT_TEXT         text_record;                                                          //06-07-12|0x0039
  BINARY_FILE_DATA  file_data;                                                            //06-07-12|0x0039
  } DICT_DATA, * DICT_DATA_FAR;                                                           //06-07-12|0x0039
//-------------------------------------------------------------------------------         //06-07-12|0x0039
#endif                                                                                    //06-07-12|0x0039
//***************************************************************************             //06-07-12|0x003a
//*****************************************************************************           //06-07-12|0x003b
#define DICT_RECORD_SIZE 2048                                                             //06-07-12|0x003b
#ifndef DICT_RECORD_Defined                                                               //06-07-12|0x003b
#define DICT_RECORD_Defined                                                               //06-07-12|0x003b
//-----------------------------------------------------------------------------           //06-07-12|0x003b
typedef struct {                                                                          //06-07-12|0x003b
  WORDS         size;                                                                     //06-07-12|0x003b
  SCHAR         data[DICT_RECORD_SIZE];                                                   //06-07-12|0x003b
  } DICT_RECORD, * DICT_RECORD_FAR;                                                       //06-07-12|0x003b
//-----------------------------------------------------------------------------           //06-07-12|0x003b
#endif                                                                                    //06-07-12|0x003b
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
// CLASS MACDICT DEFINITION                                                               //06-07-12|0x0043
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
class MACDICT {                                                                           //06-07-12|0x0043
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
// CLASS MACDICT DEFINITION                                                               //06-07-12|0x0043
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
    private:                                                                              //10-27-97|0x004b
      DICT_DATA_FAR dict_addr;                                                            //10-27-97|0x004b
    public:                                                                               //06-07-12|0x0068
      UINT mac_dict_allocate(void);                                                       //06-07-12|0x0068
#define MacDictAllocate mac_dict.mac_dict_allocate                                        //06-07-12|0x0069
    public:                                                                              //06-07-12|0x0080
      UINT mac_dict_free(void);                                                          //06-07-12|0x0080
#define MacDictFree mac_dict.mac_dict_free                                               //06-07-12|0x0081
    public:                                                                               //06-08-18|0x0099
      UINT mac_dict_name(SCHAR_FAR,SCHAR_FAR);                                            //06-08-18|0x0099
#define MacDictName mac_dict.mac_dict_name                                                //06-08-18|0x009b
    public:                                                                               //06-08-18|0x00b3
      UINT mac_dict_exists(ULONG_FAR);                                                    //06-08-18|0x00b3
#define MacDictExists mac_dict.mac_dict_exists                                            //06-08-18|0x00b5
    public:                                                                               //06-08-18|0x00cb
      UINT mac_dict_create(STRING_DATA_FAR);                                              //06-08-18|0x00cb
#define MacDictCreate mac_dict.mac_dict_create                                            //06-08-18|0x00cd
    public:                                                                               //06-09-06|0x00ef
      UINT mac_dict_open(STRING_DATA_FAR);                                                //06-09-06|0x00ef
#define MacDictOpen mac_dict.mac_dict_open                                                //06-09-06|0x00f1
    public:                                                                               //06-09-06|0x010c
      UINT mac_dict_append(void);                                                         //06-09-06|0x010c
#define MacDictAppend mac_dict.mac_dict_append                                            //06-09-06|0x010d
    public:                                                                               //06-08-18|0x0123
      UINT mac_dict_close(void);                                                          //06-08-18|0x0123
#define MacDictClose mac_dict.mac_dict_close                                              //06-08-18|0x0124
    public:                                                                               //07-03-21|0x013b
      UINT mac_dict_emergency_close(void);                                                //07-03-21|0x013b
#define MacDictEmergencyClose mac_dict.mac_dict_emergency_close                           //07-03-21|0x013c
    public:                                                                               //06-09-04|0x0153
      UINT mac_dict_delete(void);                                                         //06-09-04|0x0153
#define MacDictDelete mac_dict.mac_dict_delete                                            //06-09-04|0x0154
    public:                                                                               //06-08-18|0x016a
      UINT mac_dict_complete(void);                                                       //06-08-18|0x016a
#define MacDictComplete mac_dict.mac_dict_complete                                        //06-08-18|0x016b
    public:                                                                               //07-01-23|0x0183
      UINT mac_dict_connect_header(DICT_HASH_FAR,SLONG);                                  //07-01-23|0x0183
#define MacDictConnectHeader mac_dict.mac_dict_connect_header                             //06-11-13|0x0185
    public:                                                                               //06-11-14|0x0199
      UINT mac_dict_write_record(DICT_RECORD_FAR);                                        //06-11-14|0x0199
#define MacDictWriteRecord mac_dict.mac_dict_write_record                                 //06-11-14|0x019b
    public:                                                                               //07-04-27|0x01af
      UINT mac_dict_load_class(STRING_DATA_FAR);                                          //07-04-27|0x01af
#define MacDictLoadClass mac_dict.mac_dict_load_class                                     //07-04-27|0x01b1
    public:                                                                               //11-02-18|0x01e5
      UINT mac_dict_load_cert(STRING_DATA_FAR);                                           //11-02-18|0x01e5
#define MacDictLoadCert mac_dict.mac_dict_load_cert                                       //11-02-18|0x01e7
    public:                                                                               //07-05-24|0x021e
      UINT mac_dict_load_bridge(STRING_DATA_FAR,UINT);                                    //07-05-24|0x021e
#define MacDictLoadBridge mac_dict.mac_dict_load_bridge                                   //07-04-27|0x0220
    public:                                                                               //07-05-24|0x023b
      UINT mac_dict_initial_bridge(STRING_DATA_FAR,UINT);                                 //07-05-24|0x023b
#define MacDictInitialBridge mac_dict.mac_dict_initial_bridge                             //07-05-24|0x023d
    public:                                                                               //06-09-04|0x0266
      UINT mac_dict_load_name(STRING_DATA_FAR,UINT);                                      //06-09-04|0x0266
#define MacDictLoadName mac_dict.mac_dict_load_name                                       //06-09-04|0x0268
    public:                                                                               //06-09-04|0x0283
      UINT mac_dict_load_command(TOKENS_FAR,UINT);                                        //06-09-04|0x0283
#define MacDictLoadCommand mac_dict.mac_dict_load_command                                 //06-09-04|0x0285
    public:                                                                               //06-08-18|0x02ae
      UINT mac_dict_macro_end(void);                                                      //06-08-18|0x02ae
#define MacDictMacroEnd mac_dict.mac_dict_macro_end                                       //06-08-18|0x02af
    public:                                                                               //07-05-24|0x02c6
      UINT mac_dict_find_bridge(STRING_DATA_FAR,SINT,UINT);                               //07-05-24|0x02c6
#define MacDictFindBridge mac_dict.mac_dict_find_bridge                                   //06-09-13|0x02c8
    public:                                                                               //07-04-27|0x02f1
      UINT mac_dict_verify_class(STRING_DATA_FAR);                                        //07-04-27|0x02f1
#define MacDictVerifyClass mac_dict.mac_dict_verify_class                                 //07-04-27|0x02f3
    public:                                                                               //07-04-27|0x0321
      UINT mac_dict_get_class(STRING_DATA_FAR);                                           //07-04-27|0x0321
#define MacDictGetClass mac_dict.mac_dict_get_class                                       //07-04-27|0x0323
    public:                                                                               //11-02-26|0x035f
      UINT mac_dict_get_cert(STRING_DATA_FAR);                                            //11-02-26|0x035f
#define MacDictGetCert mac_dict.mac_dict_get_cert                                         //11-02-26|0x0361
    public:                                                                               //07-05-24|0x037a
      UINT mac_dict_check_dup_name(STRING_DATA_FAR,UINT);                                 //07-05-24|0x037a
#define MacDictCheckDupName mac_dict.mac_dict_check_dup_name                              //07-05-24|0x037c
    public:                                                                               //06-09-26|0x0397
      UINT mac_dict_find_name(STRING_DATA_FAR,UINT);                                      //06-09-26|0x0397
#define MacDictFindName mac_dict.mac_dict_find_name                                       //06-09-26|0x0399
    public:                                                                               //06-11-14|0x03c1
      UINT mac_dict_get_command(TOKENS_FAR,UINT_FAR);                                     //06-11-14|0x03c1
#define MacDictGet mac_dict.mac_dict_get_command                                          //06-11-14|0x03c3
    public:                                                                               //06-07-14|0x03ed
      UINT macdict_test_reset(void);                                                      //06-07-14|0x03ed
#define MacDictTestReset mac_dict.macdict_test_reset                                      //06-07-14|0x03ed
    public:                                                                               //06-07-14|0x03ef
      UINT macdict_test_read(void);                                                       //06-07-14|0x03ef
#define MacDictTestRead mac_dict.macdict_test_read                                        //06-07-14|0x03ef
    public:                                                                               //06-07-14|0x03f1
      UINT macdict_test_write(void);                                                      //06-07-14|0x03f1
#define MacDictTestWrite mac_dict.macdict_test_write                                      //06-07-14|0x03f1
    public:                                                                               //06-07-14|0x03f3
      UINT macdict_test_report(void);                                                     //06-07-14|0x03f3
#define MacDictTestReport mac_dict.macdict_test_report                                    //06-07-14|0x03f3
    public:                                                                               //04-01-97|0x03fd
      MACDICT();                                                                          //04-01-97|0x03fd
  };                                                                                      //10-29-97|0x0405
extern class MACDICT mac_dict;                                                            //98-12-29|0x0405
//*******************************************************************************         //05-24-97|0x0406
//*******************************************************************************         //05-24-97|0x0406
//****                       END OF FILE                                     ****         //05-24-97|0x0406
//*******************************************************************************         //05-24-97|0x0406
//*******************************************************************************         //05-24-97|0x0406
#endif                                                                                    //05-24-97|0x0406
