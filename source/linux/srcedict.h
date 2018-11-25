//*****************************************************************************           //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
// PRECEDENCE DICTIONARY_MANAGER                                                          //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  The purpose of this program as well as instructions regarding its use is              //07-02-02|0x000b
//  defined in the associated manual.                                                     //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  This program is free software; you can redistribute it and/or modify                  //07-02-02|0x000b
//  it under the terms of the GNU General Public License as published by                  //07-02-02|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //07-02-02|0x000b
//  (at your option) any later version.                                                   //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
//  This program is distributed in the hope that it will be useful,                       //07-02-02|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //07-02-02|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //07-02-02|0x000b
//  GNU General Public License for more details.                                          //07-02-02|0x000b
//                                                                                        //07-02-02|0x000b
//  You should have received a copy of the GNU General Public License                     //07-02-02|0x000b
//  along with this program; if not, write to the Free Software                           //07-02-02|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //07-02-02|0x000b
//  USA                                                                                   //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//  For further information, please contact Robert Adams:                                 //07-02-02|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //07-02-02|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //07-02-02|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
//*****************************************************************************           //07-02-02|0x000b
#ifndef srcedict_h                                                                        //07-02-02|0x000c
#define srcedict_h                                                                        //07-02-02|0x000c
//***************************************************************************             //07-02-03|0x0027
//***************************************************************************             //07-02-03|0x0028
//******                                                               ******             //07-02-03|0x0029
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //07-02-03|0x002a
//******                                                               ******             //07-02-03|0x002b
//***************************************************************************             //07-02-03|0x002c
//***************************************************************************             //07-02-03|0x002d
//*****************************************************************************           //07-02-03|0x002e
#ifndef FILE_CONTROL_Defined                                                              //07-02-03|0x002e
#define FILE_CONTROL_Defined                                                              //07-02-03|0x002e
//-----------------------------------------------------------------------------           //07-02-03|0x002e
typedef struct {                                                                          //07-02-03|0x002e
  UINT    state;                                                                          //07-02-03|0x002e
  SCHAR   name[_MAX_PATH+1];                                                              //07-02-03|0x002e
  FILE *  stream;                                                                         //07-02-03|0x002e
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //07-02-03|0x002e
//-----------------------------------------------------------------------------           //07-02-03|0x002e
#endif                                                                                    //07-02-03|0x002e
//*******************************************************************************         //07-02-03|0x002f
#ifndef BINARY_FILE_DATA_Defined                                                          //07-02-03|0x002f
#define BINARY_FILE_DATA_Defined                                                          //07-02-03|0x002f
//-------------------------------------------------------------------------------         //07-02-03|0x002f
typedef struct {                                                                          //07-02-03|0x002f
  FILE_CONTROL    file_control;                                                           //07-02-03|0x002f
  SLONG           file_position;                                                          //07-02-03|0x002f
  SLONG           file_length;                                                            //07-02-03|0x002f
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-02-03|0x002f
//-------------------------------------------------------------------------------         //07-02-03|0x002f
#endif                                                                                    //07-02-03|0x002f
//***************************************************************************             //07-02-03|0x0030
//*******************************************************************************         //07-02-03|0x0031
#ifndef STRING_DATA_Defined                                                               //07-02-03|0x0031
#define STRING_DATA_Defined                                                               //07-02-03|0x0031
//-------------------------------------------------------------------------------         //07-02-03|0x0031
typedef struct {                                                                          //07-02-03|0x0031
  SCHAR   line[257];                                                                      //07-02-03|0x0031
  UINT    macro_line_no;                                                                  //07-02-03|0x0031
  UINT    type;                                                                           //07-02-03|0x0031
  UINT    start_col;                                                                      //07-02-03|0x0031
  UINT    start_call;                                                                     //07-02-03|0x0031
  SINT    length;                                                                         //07-02-03|0x0031
  SINT    position;                                                                       //07-02-03|0x0031
  SINT    column;                                                                         //07-02-03|0x0031
  } STRING_DATA, * STRING_DATA_FAR;                                                       //07-02-03|0x0031
//-------------------------------------------------------------------------------         //07-02-03|0x0031
#endif                                                                                    //07-02-03|0x0031
//*******************************************************************************         //07-02-03|0x0032
#ifndef TOKENS_Defined                                                                    //07-02-03|0x0032
#define TOKENS_Defined                                                                    //07-02-03|0x0032
//-------------------------------------------------------------------------------         //07-02-03|0x0032
typedef struct {                                                                          //07-02-03|0x0032
  UINT        no_tokens;                                                                  //07-02-03|0x0032
  STRING_DATA token[10];                                                                  //07-02-03|0x0032
  } TOKENS, * TOKENS_FAR;                                                                 //07-02-03|0x0032
//-------------------------------------------------------------------------------         //07-02-03|0x0032
#endif                                                                                    //07-02-03|0x0032
//***************************************************************************             //07-02-03|0x0033
//*******************************************************************************         //07-02-03|0x0034
#ifndef BINARY_FILE_DATA_Defined                                                          //07-02-03|0x0034
#define BINARY_FILE_DATA_Defined                                                          //07-02-03|0x0034
//-------------------------------------------------------------------------------         //07-02-03|0x0034
typedef struct {                                                                          //07-02-03|0x0034
  FILE_CONTROL    file_control;                                                           //07-02-03|0x0034
  SLONG           file_position;                                                          //07-02-03|0x0034
  SLONG           file_length;                                                            //07-02-03|0x0034
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //07-02-03|0x0034
//-------------------------------------------------------------------------------         //07-02-03|0x0034
#endif                                                                                    //07-02-03|0x0034
//*****************************************************************************           //07-02-03|0x0035
#ifndef DICT_TEXT_HEADER_Defined                                                          //07-02-03|0x0035
#define DICT_TEXT_HEADER_Defined                                                          //07-02-03|0x0035
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //07-02-03|0x0035
//-----------------------------------------------------------------------------           //07-02-03|0x0035
typedef struct {                                                                          //07-02-03|0x0035
  UINT          type;                                                                     //07-02-03|0x0035
  UINT          length;                                                                   //07-02-03|0x0035
  SLONG         delta_bridge;                                                           //%1|0x0035
  SLONG         delta_offset;                                                             //07-02-03|0x0035
  SLONG         next_position;                                                            //07-02-03|0x0035
  SLONG         header_position;                                                          //07-02-03|0x0035
  SLONG         current_position;                                                         //07-02-03|0x0035
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //07-02-03|0x0035
//-----------------------------------------------------------------------------           //07-02-03|0x0035
#endif                                                                                    //07-02-03|0x0035
//*******************************************************************************         //07-02-03|0x0036
#ifndef DICT_TEXT_Defined                                                                 //07-02-03|0x0036
#define DICT_TEXT_Defined                                                                 //07-02-03|0x0036
//-------------------------------------------------------------------------------         //07-02-03|0x0036
typedef struct {                                                                          //07-02-03|0x0036
  DICT_TEXT_HEADER  text_header;                                                          //07-02-03|0x0036
  SCHAR             text_char[257];                                                       //07-02-03|0x0036
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //07-02-03|0x0036
//-------------------------------------------------------------------------------         //07-02-03|0x0036
#endif                                                                                    //07-02-03|0x0036
//*****************************************************************************           //07-02-03|0x0037
#ifndef DICT_HEADER_Defined                                                               //07-02-03|0x0037
#define DICT_HEADER_Defined                                                               //07-02-03|0x0037
//-----------------------------------------------------------------------------           //07-02-03|0x0037
typedef struct {                                                                          //07-02-03|0x0037
  UINT              command;                                                              //07-02-03|0x0037
  SLONG             next_position;                                                        //07-02-03|0x0037
  SLONG             current_position;                                                     //07-02-03|0x0037
  UINT              no_args;                                                              //07-02-03|0x0037
  SLONG             name_position[10];                                                    //07-02-03|0x0037
  UINT              start_col[10];                                                        //07-02-03|0x0037
  UINT              start_call[10];                                                       //07-02-03|0x0037
  UINT              line_no[10];                                                          //07-02-03|0x0037
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //07-02-03|0x0037
//-----------------------------------------------------------------------------           //07-02-03|0x0037
#endif                                                                                    //07-02-03|0x0037
//*****************************************************************************           //07-02-03|0x0038
#ifndef DICT_HASH_ELEMENT_Defined                                                         //07-02-03|0x0038
#define DICT_HASH_ELEMENT_Defined                                                         //07-02-03|0x0038
#define NoHash    2048                                                                    //07-02-03|0x0038
//-----------------------------------------------------------------------------           //07-02-03|0x0038
typedef struct {                                                                          //07-02-03|0x0038
  SLONG last_bridge;                                                                      //07-02-03|0x0038
  SLONG first_bridge;                                                                     //07-02-03|0x0038
  SLONG last_offset;                                                                      //07-02-03|0x0038
  SLONG first_offset;                                                                     //07-02-03|0x0038
  SLONG first;                                                                            //07-02-03|0x0038
  SLONG last;                                                                             //07-02-03|0x0038
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //07-02-03|0x0038
//-----------------------------------------------------------------------------           //07-02-03|0x0038
#endif                                                                                    //07-02-03|0x0038
//*****************************************************************************           //07-02-03|0x0038
#ifndef DICT_HASH_Defined                                                                 //07-02-03|0x0038
#define DICT_HASH_Defined                                                                 //07-02-03|0x0038
//-----------------------------------------------------------------------------           //07-02-03|0x0038
typedef struct {                                                                          //07-02-03|0x0038
  UINT            file_state;                                                             //07-02-03|0x0038
  HASH_ELEM       hash_element[NoHash];                                                   //07-02-03|0x0038
  } DICT_HASH, * DICT_HASH_FAR;                                                           //07-02-03|0x0038
#define HashSize  sizeof(DICT_HASH)                                                       //07-02-03|0x0038
//-----------------------------------------------------------------------------           //07-02-03|0x0038
#endif                                                                                    //07-02-03|0x0038
//*******************************************************************************         //07-02-03|0x0039
#ifndef DICT_DATA_Defined                                                                 //07-02-03|0x0039
#define DICT_DATA_Defined                                                                 //07-02-03|0x0039
//-------------------------------------------------------------------------------         //07-02-03|0x0039
typedef struct {                                                                          //07-02-03|0x0039
  UINT              status;                                                               //07-02-03|0x0039
  UINT              run_flag;                                                             //07-02-03|0x0039
  UINT              process_state;                                                        //07-02-03|0x0039
  UINT              search_state;                                                         //07-02-03|0x0039
  SLONG             text_plan;                                                            //07-02-03|0x0039
  SLONG             header_plan;                                                          //07-02-03|0x0039
  ULONG             hash;                                                                 //07-02-03|0x0039
  SLONG             text_position;                                                        //07-02-03|0x0039
  SLONG             current_bridge;                                                       //07-02-03|0x0039
  SLONG             search_bridge;                                                        //07-02-03|0x0039
  SLONG             lower_bridge;                                                         //07-02-03|0x0039
  SLONG             upper_bridge;                                                         //07-02-03|0x0039
  ULONG             current_offset;                                                       //07-02-03|0x0039
  ULONG             search_offset;                                                        //07-02-03|0x0039
  DICT_HASH         hash_record;                                                          //07-02-03|0x0039
  DICT_HEADER       header_record;                                                        //07-02-03|0x0039
  DICT_TEXT         text_record;                                                          //07-02-03|0x0039
  BINARY_FILE_DATA  file_data;                                                            //07-02-03|0x0039
  } DICT_DATA, * DICT_DATA_FAR;                                                           //07-02-03|0x0039
//-------------------------------------------------------------------------------         //07-02-03|0x0039
#endif                                                                                    //07-02-03|0x0039
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
// CLASS SRCEDICT DEFINITION                                                              //07-02-03|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
class SRCEDICT {                                                                          //07-02-03|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
// CLASS SRCEDICT DEFINITION                                                              //07-02-03|0x0041
//*******************************************************************************         //10-29-97|0x0041
//*******************************************************************************         //10-29-97|0x0041
    private:                                                                              //10-27-97|0x0049
      DICT_DATA_FAR dict_addr;                                                            //10-27-97|0x0049
    public:                                                                               //07-01-17|0x0066
      UINT srce_dict_allocate(void);                                                      //07-01-17|0x0066
#define SrceDictAllocate srce_dict.srce_dict_allocate                                     //07-01-17|0x0067
    public:                                                                               //07-01-25|0x007e
      UINT srce_dict_free(void);                                                          //07-01-25|0x007e
#define SrceDictFree srce_dict.srce_dict_free                                             //07-01-25|0x007f
    public:                                                                               //07-01-24|0x0097
      UINT srce_dict_name(SCHAR_FAR,SCHAR_FAR);                                           //07-01-24|0x0097
#define SrceDictName srce_dict.srce_dict_name                                             //07-01-24|0x0099
    public:                                                                               //07-01-24|0x00af
      UINT srce_dict_create(void);                                                        //07-01-24|0x00af
#define SrceDictCreate srce_dict.srce_dict_create                                         //07-01-24|0x00b0
    public:                                                                               //07-01-25|0x00c6
      UINT srce_dict_close(void);                                                         //07-01-25|0x00c6
#define SrceDictClose srce_dict.srce_dict_close                                           //07-01-25|0x00c7
    public:                                                                               //07-01-24|0x00de
      UINT srce_dict_add_entry(TOKENS_FAR);                                               //07-01-24|0x00de
#define SrceDictAdd srce_dict.srce_dict_add_entry                                         //07-01-24|0x00e0
    public:                                                                               //07-02-03|0x0111
      UINT srce_dict_add_sub_entry(TOKENS_FAR);                                           //07-02-03|0x0111
#define SrceDictAddSubEntry srce_dict.srce_dict_add_sub_entry                             //07-02-03|0x0113
    public:                                                                               //07-01-24|0x0155
      UINT srce_dict_update_data(TOKENS_FAR);                                             //07-01-24|0x0155
#define SrceDictUpdate srce_dict.srce_dict_update_data                                    //07-01-24|0x0157
    public:                                                                               //07-02-07|0x0196
      UINT srce_dict_update_sub_entry(TOKENS_FAR);                                        //07-02-07|0x0196
#define SrceDictUpdateSubEntry srce_dict.srce_dict_update_sub_entry                       //07-02-07|0x0198
    public:                                                                               //07-01-24|0x01ca
      UINT srce_dict_get_data(STRING_DATA_FAR,STRING_DATA_FAR,UINT);                      //07-01-24|0x01ca
#define SrceDictGet srce_dict.srce_dict_get_data                                          //07-01-24|0x01cc
    public:                                                                               //07-02-03|0x01f3
      UINT srce_sub_dict_get_data(STRING_DATA_FAR,TOKENS_FAR,UINT);                       //07-02-03|0x01f3
#define SrceSubDictGet srce_dict.srce_sub_dict_get_data                                   //07-02-03|0x01f5
    public:                                                                               //07-02-03|0x021b
      UINT srce_dict_test_data(STRING_DATA_FAR,UINT);                                     //07-02-03|0x021b
#define SrceDictTestData srce_dict.srce_dict_test_data                                    //07-02-03|0x021d
    public:                                                                               //07-03-14|0x0244
      UINT srce_sub_dict_test_data(TOKENS_FAR,UINT);                                      //07-03-14|0x0244
#define SrceSubDictTestData srce_dict.srce_sub_dict_test_data                             //07-03-14|0x0246
    public:                                                                               //07-02-03|0x026c
      UINT srce_dict_exists(STRING_DATA_FAR);                                             //07-02-03|0x026c
#define SrceDictExists srce_dict.srce_dict_exists                                         //07-02-03|0x026e
    public:                                                                               //07-02-05|0x028a
      UINT srce_sub_exists(STRING_DATA_FAR,STRING_DATA_FAR);                              //07-02-05|0x028a
#define SrceSubDictExists srce_dict.srce_sub_exists                                       //07-02-05|0x028c
    private:                                                                              //07-01-24|0x02ab
      UINT srce_dict_find(STRING_DATA_FAR);                                               //07-01-24|0x02ab
    private:                                                                              //07-02-03|0x02d0
      UINT srce_sub_find(STRING_DATA_FAR,STRING_DATA_FAR);                                //07-02-03|0x02d0
    private:                                                                              //07-01-24|0x0309
      UINT srce_get_first(void);                                                          //07-01-24|0x0309
    private:                                                                              //07-01-24|0x0329
      UINT srce_get_next(void);                                                           //07-01-24|0x0329
    public:                                                                               //06-07-14|0x0345
      UINT srcedict_test_reset(void);                                                     //06-07-14|0x0345
#define SrceDictTestReset srce_dict.srcedict_test_reset                                   //06-07-14|0x0345
    public:                                                                               //06-07-14|0x0347
      UINT srcedict_test_read(void);                                                      //06-07-14|0x0347
#define SrceDictTestRead srce_dict.srcedict_test_read                                     //06-07-14|0x0347
    public:                                                                               //06-07-14|0x0349
      UINT srcedict_test_write(void);                                                     //06-07-14|0x0349
#define SrceDictTestWrite srce_dict.srcedict_test_write                                   //06-07-14|0x0349
    public:                                                                               //06-07-14|0x034b
      UINT srcedict_test_report(void);                                                    //06-07-14|0x034b
#define SrceDictTestReport srce_dict.srcedict_test_report                                 //06-07-14|0x034b
    public:                                                                               //04-01-97|0x0355
      SRCEDICT();                                                                         //04-01-97|0x0355
  };                                                                                      //10-29-97|0x035d
extern class SRCEDICT srce_dict;                                                          //98-12-29|0x035d
//*******************************************************************************         //05-24-97|0x035e
//*******************************************************************************         //05-24-97|0x035e
//****                       END OF FILE                                     ****         //05-24-97|0x035e
//*******************************************************************************         //05-24-97|0x035e
//*******************************************************************************         //05-24-97|0x035e
#endif                                                                                    //05-24-97|0x035e
