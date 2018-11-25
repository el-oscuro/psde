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
#ifndef apnddict_h                                                                        //06-07-12|0x000c
#define apnddict_h                                                                        //06-07-12|0x000c
#include "precdiag.h"                                                                     //06-07-12|0x000d
#include "macdict.h"                                                                      //06-07-12|0x000e
#include "basedict.h"                                                                     //06-07-12|0x000f
//***************************************************************************             //06-07-12|0x0025
//***************************************************************************             //06-07-12|0x0026
//******                                                               ******             //06-07-12|0x0027
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-12|0x0028
//******                                                               ******             //06-07-12|0x0029
//***************************************************************************             //06-07-12|0x002a
//***************************************************************************             //06-07-12|0x002b
//*****************************************************************************           //06-07-12|0x002c
#ifndef FILE_CONTROL_Defined                                                              //06-07-12|0x002c
#define FILE_CONTROL_Defined                                                              //06-07-12|0x002c
//-----------------------------------------------------------------------------           //06-07-12|0x002c
typedef struct {                                                                          //06-07-12|0x002c
  UINT    state;                                                                          //06-07-12|0x002c
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-12|0x002c
  FILE *  stream;                                                                         //06-07-12|0x002c
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-12|0x002c
//-----------------------------------------------------------------------------           //06-07-12|0x002c
#endif                                                                                    //06-07-12|0x002c
//***************************************************************************             //06-07-12|0x002d
//*******************************************************************************         //06-07-12|0x002e
#ifndef BINARY_FILE_DATA_Defined                                                          //06-07-12|0x002e
#define BINARY_FILE_DATA_Defined                                                          //06-07-12|0x002e
//-------------------------------------------------------------------------------         //06-07-12|0x002e
typedef struct {                                                                          //06-07-12|0x002e
  FILE_CONTROL    file_control;                                                           //06-07-12|0x002e
  SLONG           file_position;                                                          //06-07-12|0x002e
  SLONG           file_length;                                                            //06-07-12|0x002e
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //06-07-12|0x002e
//-------------------------------------------------------------------------------         //06-07-12|0x002e
#endif                                                                                    //06-07-12|0x002e
//*****************************************************************************           //06-07-12|0x002f
#ifndef DICT_TEXT_HEADER_Defined                                                          //06-07-12|0x002f
#define DICT_TEXT_HEADER_Defined                                                          //06-07-12|0x002f
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //06-07-12|0x002f
//-----------------------------------------------------------------------------           //06-07-12|0x002f
typedef struct {                                                                          //06-07-12|0x002f
  UINT          type;                                                                     //06-07-12|0x002f
  UINT          length;                                                                   //06-07-12|0x002f
  SLONG         delta_bridge;                                                           //%1|0x002f
  SLONG         delta_offset;                                                             //06-07-12|0x002f
  SLONG         next_position;                                                            //06-07-12|0x002f
  SLONG         header_position;                                                          //06-07-12|0x002f
  SLONG         current_position;                                                         //06-07-12|0x002f
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //06-07-12|0x002f
//-----------------------------------------------------------------------------           //06-07-12|0x002f
#endif                                                                                    //06-07-12|0x002f
//*******************************************************************************         //06-07-12|0x0030
#ifndef DICT_TEXT_Defined                                                                 //06-07-12|0x0030
#define DICT_TEXT_Defined                                                                 //06-07-12|0x0030
//-------------------------------------------------------------------------------         //06-07-12|0x0030
typedef struct {                                                                          //06-07-12|0x0030
  DICT_TEXT_HEADER  text_header;                                                          //06-07-12|0x0030
  SCHAR             text_char[257];                                                       //06-07-12|0x0030
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //06-07-12|0x0030
//-------------------------------------------------------------------------------         //06-07-12|0x0030
#endif                                                                                    //06-07-12|0x0030
//*****************************************************************************           //06-07-12|0x0031
#ifndef DICT_HEADER_Defined                                                               //06-07-12|0x0031
#define DICT_HEADER_Defined                                                               //06-07-12|0x0031
//-----------------------------------------------------------------------------           //06-07-12|0x0031
typedef struct {                                                                          //06-07-12|0x0031
  UINT              command;                                                              //06-07-12|0x0031
  SLONG             next_position;                                                        //06-07-12|0x0031
  SLONG             current_position;                                                     //06-07-12|0x0031
  UINT              no_args;                                                              //06-07-12|0x0031
  SLONG             name_position[10];                                                    //06-07-12|0x0031
  UINT              start_col[10];                                                        //06-07-12|0x0031
  UINT              start_call[10];                                                       //06-07-12|0x0031
  UINT              line_no[10];                                                          //06-07-12|0x0031
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //06-07-12|0x0031
//-----------------------------------------------------------------------------           //06-07-12|0x0031
#endif                                                                                    //06-07-12|0x0031
//*****************************************************************************           //06-07-12|0x0032
#ifndef DICT_HASH_ELEMENT_Defined                                                         //06-07-12|0x0032
#define DICT_HASH_ELEMENT_Defined                                                         //06-07-12|0x0032
#define NoHash    2048                                                                    //06-07-12|0x0032
//-----------------------------------------------------------------------------           //06-07-12|0x0032
typedef struct {                                                                          //06-07-12|0x0032
  SLONG last_bridge;                                                                      //06-07-12|0x0032
  SLONG first_bridge;                                                                     //06-07-12|0x0032
  SLONG last_offset;                                                                      //06-07-12|0x0032
  SLONG first_offset;                                                                     //06-07-12|0x0032
  SLONG first;                                                                            //06-07-12|0x0032
  SLONG last;                                                                             //06-07-12|0x0032
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //06-07-12|0x0032
//-----------------------------------------------------------------------------           //06-07-12|0x0032
#endif                                                                                    //06-07-12|0x0032
//*****************************************************************************           //06-07-12|0x0032
#ifndef DICT_HASH_Defined                                                                 //06-07-12|0x0032
#define DICT_HASH_Defined                                                                 //06-07-12|0x0032
//-----------------------------------------------------------------------------           //06-07-12|0x0032
typedef struct {                                                                          //06-07-12|0x0032
  UINT            file_state;                                                             //06-07-12|0x0032
  HASH_ELEM       hash_element[NoHash];                                                   //06-07-12|0x0032
  } DICT_HASH, * DICT_HASH_FAR;                                                           //06-07-12|0x0032
#define HashSize  sizeof(DICT_HASH)                                                       //06-07-12|0x0032
//-----------------------------------------------------------------------------           //06-07-12|0x0032
#endif                                                                                    //06-07-12|0x0032
//*******************************************************************************         //06-07-12|0x0033
#ifndef DICT_DATA_Defined                                                                 //06-07-12|0x0033
#define DICT_DATA_Defined                                                                 //06-07-12|0x0033
//-------------------------------------------------------------------------------         //06-07-12|0x0033
typedef struct {                                                                          //06-07-12|0x0033
  UINT              status;                                                               //06-07-12|0x0033
  UINT              run_flag;                                                             //06-07-12|0x0033
  UINT              process_state;                                                        //06-07-12|0x0033
  UINT              search_state;                                                         //06-07-12|0x0033
  SLONG             text_plan;                                                            //06-07-12|0x0033
  SLONG             header_plan;                                                          //06-07-12|0x0033
  ULONG             hash;                                                                 //06-07-12|0x0033
  SLONG             text_position;                                                        //06-07-12|0x0033
  SLONG             current_bridge;                                                       //06-07-12|0x0033
  SLONG             search_bridge;                                                        //06-07-12|0x0033
  SLONG             lower_bridge;                                                         //06-07-12|0x0033
  SLONG             upper_bridge;                                                         //06-07-12|0x0033
  ULONG             current_offset;                                                       //06-07-12|0x0033
  ULONG             search_offset;                                                        //06-07-12|0x0033
  DICT_HASH         hash_record;                                                          //06-07-12|0x0033
  DICT_HEADER       header_record;                                                        //06-07-12|0x0033
  DICT_TEXT         text_record;                                                          //06-07-12|0x0033
  BINARY_FILE_DATA  file_data;                                                            //06-07-12|0x0033
  } DICT_DATA, * DICT_DATA_FAR;                                                           //06-07-12|0x0033
//-------------------------------------------------------------------------------         //06-07-12|0x0033
#endif                                                                                    //06-07-12|0x0033
//***************************************************************************             //06-07-12|0x0034
//*****************************************************************************           //06-07-12|0x0035
#define DICT_RECORD_SIZE 2048                                                             //06-07-12|0x0035
#ifndef DICT_RECORD_Defined                                                               //06-07-12|0x0035
#define DICT_RECORD_Defined                                                               //06-07-12|0x0035
//-----------------------------------------------------------------------------           //06-07-12|0x0035
typedef struct {                                                                          //06-07-12|0x0035
  WORDS         size;                                                                     //06-07-12|0x0035
  SCHAR         data[DICT_RECORD_SIZE];                                                   //06-07-12|0x0035
  } DICT_RECORD, * DICT_RECORD_FAR;                                                       //06-07-12|0x0035
//-----------------------------------------------------------------------------           //06-07-12|0x0035
#endif                                                                                    //06-07-12|0x0035
//*******************************************************************************         //06-07-12|0x0036
#ifndef DICT_APPEND_Defined                                                               //06-07-12|0x0036
#define DICT_APPEND_Defined                                                               //06-07-12|0x0036
//-------------------------------------------------------------------------------         //06-07-12|0x0036
typedef struct {                                                                          //06-07-12|0x0036
  DICT_DATA      dict;                                                                    //06-07-12|0x0036
  DICT_HASH      hash;                                                                    //06-07-12|0x0036
  DICT_RECORD    record;                                                                  //06-07-12|0x0036
  } DICT_APPEND, * DICT_APPEND_FAR;                                                       //06-07-12|0x0036
//-------------------------------------------------------------------------------         //06-07-12|0x0036
#endif                                                                                    //06-07-12|0x0036
//*******************************************************************************         //10-29-97|0x003e
//*******************************************************************************         //10-29-97|0x003e
// CLASS APPENDDICT DEFINITION                                                            //06-07-12|0x003e
//*******************************************************************************         //10-29-97|0x003e
//*******************************************************************************         //10-29-97|0x003e
class APPENDDICT {                                                                        //06-07-12|0x003e
//*******************************************************************************         //10-29-97|0x003e
//*******************************************************************************         //10-29-97|0x003e
// CLASS APPENDDICT DEFINITION                                                            //06-07-12|0x003e
//*******************************************************************************         //10-29-97|0x003e
//*******************************************************************************         //10-29-97|0x003e
    private:                                                                              //10-27-97|0x0046
      DICT_APPEND_FAR dict_append_addr;                                                   //10-27-97|0x0046
    public:                                                                               //06-07-12|0x0062
      UINT apnd_dict_allocate(void);                                                      //06-07-12|0x0062
#define ApndDictAllocate append_dict.apnd_dict_allocate                                   //06-07-12|0x0063
    public:                                                                               //06-07-12|0x007a
      UINT apnd_dict_free(void);                                                          //06-07-12|0x007a
#define ApndDictFree append_dict.apnd_dict_free                                           //06-07-12|0x007b
    public:                                                                               //06-09-06|0x0093
      UINT apnd_dict_name(SCHAR_FAR,SCHAR_FAR);                                           //06-09-06|0x0093
#define ApndDictName append_dict.apnd_dict_name                                           //06-09-06|0x0095
    public:                                                                               //06-09-06|0x00ac
      UINT apnd_dict_exists(ULONG_FAR);                                                   //06-09-06|0x00ac
#define ApndDictExists append_dict.apnd_dict_exists                                       //06-09-06|0x00ae
    public:                                                                               //11-02-26|0x00c4
      UINT append_dict_get_cert(STRING_DATA_FAR);                                         //11-02-26|0x00c4
#define ApndDictGetCert append_dict.append_dict_get_cert                                  //11-02-26|0x00c6
    public:                                                                               //07-04-27|0x00de
      UINT apnd_dict(void);                                                               //07-04-27|0x00de
#define ApndApndDict append_dict.apnd_dict                                                //06-09-06|0x00e0
    public:                                                                               //06-07-14|0x0102
      UINT apnd_dict_test_reset(void);                                                    //06-07-14|0x0102
#define ApndDictTestReset append_dict.apnd_dict_test_reset                                //06-07-14|0x0102
    public:                                                                               //06-07-14|0x0104
      UINT apnd_dict_test_read(void);                                                     //06-07-14|0x0104
#define ApndDictTestRead append_dict.apnd_dict_test_read                                  //06-07-14|0x0104
    public:                                                                               //06-07-14|0x0106
      UINT apnd_dict_test_write(void);                                                    //06-07-14|0x0106
#define ApndDictTestWrite append_dict.apnd_dict_test_write                                //06-07-14|0x0106
    public:                                                                               //06-07-14|0x0108
      UINT apnd_dict_test_report(void);                                                   //06-07-14|0x0108
#define ApndDictTestReport append_dict.apnd_dict_test_report                              //06-07-14|0x0108
    public:                                                                               //06-07-12|0x0112
      APPENDDICT();                                                                       //06-07-12|0x0112
  };                                                                                      //10-29-97|0x011b
extern class APPENDDICT append_dict;                                                      //98-12-29|0x011b
//*******************************************************************************         //05-24-97|0x011c
//*******************************************************************************         //05-24-97|0x011c
//****                       END OF FILE                                     ****         //05-24-97|0x011c
//*******************************************************************************         //05-24-97|0x011c
//*******************************************************************************         //05-24-97|0x011c
#endif                                                                                    //05-24-97|0x011c
