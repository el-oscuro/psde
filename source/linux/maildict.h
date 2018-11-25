//*****************************************************************************           //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
// MAILBOX DICTIONARY_MANAGER                                                             //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  The purpose of this program as well as instructions regarding its use is              //09-03-10|0x000b
//  defined in the associated manual.                                                     //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  This program is free software; you can redistribute it and/or modify                  //09-03-10|0x000b
//  it under the terms of the GNU General Public License as published by                  //09-03-10|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //09-03-10|0x000b
//  (at your option) any later version.                                                   //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
//  This program is distributed in the hope that it will be useful,                       //09-03-10|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //09-03-10|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //09-03-10|0x000b
//  GNU General Public License for more details.                                          //09-03-10|0x000b
//                                                                                        //09-03-10|0x000b
//  You should have received a copy of the GNU General Public License                     //09-03-10|0x000b
//  along with this program; if not, write to the Free Software                           //09-03-10|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //09-03-10|0x000b
//  USA                                                                                   //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//  For further information, please contact Robert Adams:                                 //09-03-10|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //09-03-10|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //09-03-10|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
//*****************************************************************************           //09-03-10|0x000b
#ifndef maildict_h                                                                        //09-03-10|0x000c
#define maildict_h                                                                        //09-03-10|0x000c
//***************************************************************************             //09-03-10|0x0028
//***************************************************************************             //09-03-10|0x0029
//******                                                               ******             //09-03-10|0x002a
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //09-03-10|0x002b
//******                                                               ******             //09-03-10|0x002c
//***************************************************************************             //09-03-10|0x002d
//***************************************************************************             //09-03-10|0x002e
//*****************************************************************************           //09-03-10|0x002f
#ifndef FILE_CONTROL_Defined                                                              //09-03-10|0x002f
#define FILE_CONTROL_Defined                                                              //09-03-10|0x002f
//-----------------------------------------------------------------------------           //09-03-10|0x002f
typedef struct {                                                                          //09-03-10|0x002f
  UINT    state;                                                                          //09-03-10|0x002f
  SCHAR   name[_MAX_PATH+1];                                                              //09-03-10|0x002f
  FILE *  stream;                                                                         //09-03-10|0x002f
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //09-03-10|0x002f
//-----------------------------------------------------------------------------           //09-03-10|0x002f
#endif                                                                                    //09-03-10|0x002f
//*******************************************************************************         //09-03-10|0x0030
#ifndef BINARY_FILE_DATA_Defined                                                          //09-03-10|0x0030
#define BINARY_FILE_DATA_Defined                                                          //09-03-10|0x0030
//-------------------------------------------------------------------------------         //09-03-10|0x0030
typedef struct {                                                                          //09-03-10|0x0030
  FILE_CONTROL    file_control;                                                           //09-03-10|0x0030
  SLONG           file_position;                                                          //09-03-10|0x0030
  SLONG           file_length;                                                            //09-03-10|0x0030
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //09-03-10|0x0030
//-------------------------------------------------------------------------------         //09-03-10|0x0030
#endif                                                                                    //09-03-10|0x0030
//***************************************************************************             //09-03-10|0x0031
//*******************************************************************************         //09-03-10|0x0032
#ifndef STRING_DATA_Defined                                                               //09-03-10|0x0032
#define STRING_DATA_Defined                                                               //09-03-10|0x0032
//-------------------------------------------------------------------------------         //09-03-10|0x0032
typedef struct {                                                                          //09-03-10|0x0032
  SCHAR   line[257];                                                                      //09-03-10|0x0032
  UINT    macro_line_no;                                                                  //09-03-10|0x0032
  UINT    type;                                                                           //09-03-10|0x0032
  UINT    start_col;                                                                      //09-03-10|0x0032
  UINT    start_call;                                                                     //09-03-10|0x0032
  SINT    length;                                                                         //09-03-10|0x0032
  SINT    position;                                                                       //09-03-10|0x0032
  SINT    column;                                                                         //09-03-10|0x0032
  } STRING_DATA, * STRING_DATA_FAR;                                                       //09-03-10|0x0032
//-------------------------------------------------------------------------------         //09-03-10|0x0032
#endif                                                                                    //09-03-10|0x0032
//*******************************************************************************         //09-03-10|0x0033
#ifndef TOKENS_Defined                                                                    //09-03-10|0x0033
#define TOKENS_Defined                                                                    //09-03-10|0x0033
//-------------------------------------------------------------------------------         //09-03-10|0x0033
typedef struct {                                                                          //09-03-10|0x0033
  UINT        no_tokens;                                                                  //09-03-10|0x0033
  STRING_DATA token[10];                                                                  //09-03-10|0x0033
  } TOKENS, * TOKENS_FAR;                                                                 //09-03-10|0x0033
//-------------------------------------------------------------------------------         //09-03-10|0x0033
#endif                                                                                    //09-03-10|0x0033
//***************************************************************************             //09-03-10|0x0034
//*******************************************************************************         //09-03-10|0x0035
#ifndef BINARY_FILE_DATA_Defined                                                          //09-03-10|0x0035
#define BINARY_FILE_DATA_Defined                                                          //09-03-10|0x0035
//-------------------------------------------------------------------------------         //09-03-10|0x0035
typedef struct {                                                                          //09-03-10|0x0035
  FILE_CONTROL    file_control;                                                           //09-03-10|0x0035
  SLONG           file_position;                                                          //09-03-10|0x0035
  SLONG           file_length;                                                            //09-03-10|0x0035
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //09-03-10|0x0035
//-------------------------------------------------------------------------------         //09-03-10|0x0035
#endif                                                                                    //09-03-10|0x0035
//*****************************************************************************           //09-03-10|0x0036
#ifndef DICT_TEXT_HEADER_Defined                                                          //09-03-10|0x0036
#define DICT_TEXT_HEADER_Defined                                                          //09-03-10|0x0036
#define TextHeaderSize  sizeof(DICT_TEXT_HEADER)                                          //09-03-10|0x0036
//-----------------------------------------------------------------------------           //09-03-10|0x0036
typedef struct {                                                                          //09-03-10|0x0036
  UINT          type;                                                                     //09-03-10|0x0036
  UINT          length;                                                                   //09-03-10|0x0036
  SLONG         delta_bridge;                                                           //%1|0x0036
  SLONG         delta_offset;                                                             //09-03-10|0x0036
  SLONG         next_position;                                                            //09-03-10|0x0036
  SLONG         header_position;                                                          //09-03-10|0x0036
  SLONG         current_position;                                                         //09-03-10|0x0036
  } DICT_TEXT_HEADER, * DICT_TEXT_HEADER_FAR;                                             //09-03-10|0x0036
//-----------------------------------------------------------------------------           //09-03-10|0x0036
#endif                                                                                    //09-03-10|0x0036
//*******************************************************************************         //09-03-10|0x0037
#ifndef DICT_TEXT_Defined                                                                 //09-03-10|0x0037
#define DICT_TEXT_Defined                                                                 //09-03-10|0x0037
//-------------------------------------------------------------------------------         //09-03-10|0x0037
typedef struct {                                                                          //09-03-10|0x0037
  DICT_TEXT_HEADER  text_header;                                                          //09-03-10|0x0037
  SCHAR             text_char[257];                                                       //09-03-10|0x0037
  } DICT_TEXT, * DICT_TEXT_FAR;                                                           //09-03-10|0x0037
//-------------------------------------------------------------------------------         //09-03-10|0x0037
#endif                                                                                    //09-03-10|0x0037
//*****************************************************************************           //09-03-10|0x0038
#ifndef DICT_HEADER_Defined                                                               //09-03-10|0x0038
#define DICT_HEADER_Defined                                                               //09-03-10|0x0038
//-----------------------------------------------------------------------------           //09-03-10|0x0038
typedef struct {                                                                          //09-03-10|0x0038
  UINT              command;                                                              //09-03-10|0x0038
  SLONG             next_position;                                                        //09-03-10|0x0038
  SLONG             current_position;                                                     //09-03-10|0x0038
  UINT              no_args;                                                              //09-03-10|0x0038
  SLONG             name_position[10];                                                    //09-03-10|0x0038
  UINT              start_col[10];                                                        //09-03-10|0x0038
  UINT              start_call[10];                                                       //09-03-10|0x0038
  UINT              line_no[10];                                                          //09-03-10|0x0038
  } DICT_HEADER, * DICT_HEADER_FAR;                                                       //09-03-10|0x0038
//-----------------------------------------------------------------------------           //09-03-10|0x0038
#endif                                                                                    //09-03-10|0x0038
//*****************************************************************************           //09-03-10|0x0039
#ifndef DICT_HASH_ELEMENT_Defined                                                         //09-03-10|0x0039
#define DICT_HASH_ELEMENT_Defined                                                         //09-03-10|0x0039
#define NoHash    2048                                                                    //09-03-10|0x0039
//-----------------------------------------------------------------------------           //09-03-10|0x0039
typedef struct {                                                                          //09-03-10|0x0039
  SLONG last_bridge;                                                                      //09-03-10|0x0039
  SLONG first_bridge;                                                                     //09-03-10|0x0039
  SLONG last_offset;                                                                      //09-03-10|0x0039
  SLONG first_offset;                                                                     //09-03-10|0x0039
  SLONG first;                                                                            //09-03-10|0x0039
  SLONG last;                                                                             //09-03-10|0x0039
  } HASH_ELEM, * HASH_ELEM_FAR;                                                           //09-03-10|0x0039
//-----------------------------------------------------------------------------           //09-03-10|0x0039
#endif                                                                                    //09-03-10|0x0039
//*****************************************************************************           //09-03-10|0x0039
#ifndef DICT_HASH_Defined                                                                 //09-03-10|0x0039
#define DICT_HASH_Defined                                                                 //09-03-10|0x0039
//-----------------------------------------------------------------------------           //09-03-10|0x0039
typedef struct {                                                                          //09-03-10|0x0039
  UINT            file_state;                                                             //09-03-10|0x0039
  HASH_ELEM       hash_element[NoHash];                                                   //09-03-10|0x0039
  } DICT_HASH, * DICT_HASH_FAR;                                                           //09-03-10|0x0039
#define HashSize  sizeof(DICT_HASH)                                                       //09-03-10|0x0039
//-----------------------------------------------------------------------------           //09-03-10|0x0039
#endif                                                                                    //09-03-10|0x0039
//*******************************************************************************         //09-03-10|0x003a
#ifndef DICT_DATA_Defined                                                                 //09-03-10|0x003a
#define DICT_DATA_Defined                                                                 //09-03-10|0x003a
//-------------------------------------------------------------------------------         //09-03-10|0x003a
typedef struct {                                                                          //09-03-10|0x003a
  UINT              status;                                                               //09-03-10|0x003a
  UINT              run_flag;                                                             //09-03-10|0x003a
  UINT              process_state;                                                        //09-03-10|0x003a
  UINT              search_state;                                                         //09-03-10|0x003a
  SLONG             text_plan;                                                            //09-03-10|0x003a
  SLONG             header_plan;                                                          //09-03-10|0x003a
  ULONG             hash;                                                                 //09-03-10|0x003a
  SLONG             text_position;                                                        //09-03-10|0x003a
  SLONG             current_bridge;                                                       //09-03-10|0x003a
  SLONG             search_bridge;                                                        //09-03-10|0x003a
  SLONG             lower_bridge;                                                         //09-03-10|0x003a
  SLONG             upper_bridge;                                                         //09-03-10|0x003a
  ULONG             current_offset;                                                       //09-03-10|0x003a
  ULONG             search_offset;                                                        //09-03-10|0x003a
  DICT_HASH         hash_record;                                                          //09-03-10|0x003a
  DICT_HEADER       header_record;                                                        //09-03-10|0x003a
  DICT_TEXT         text_record;                                                          //09-03-10|0x003a
  BINARY_FILE_DATA  file_data;                                                            //09-03-10|0x003a
  } DICT_DATA, * DICT_DATA_FAR;                                                           //09-03-10|0x003a
//-------------------------------------------------------------------------------         //09-03-10|0x003a
#endif                                                                                    //09-03-10|0x003a
//*****************************************************************************           //09-03-10|0x003b
#ifndef MAIL_DICT_DATA_Defined                                                            //09-03-10|0x003b
#define MAIL_DICT_DATA_Defined                                                            //09-03-10|0x003b
//-----------------------------------------------------------------------------           //09-03-10|0x003b
typedef struct {                                                                          //09-03-10|0x003b
  UINT              index1;                                                               //09-03-10|0x003b
  DICT_DATA         dict;                                                                 //09-03-10|0x003b
  SCHAR             path[_MAX_PATH+1];                                                    //09-03-10|0x003b
  UINT              index2;                                                               //09-03-10|0x003b
  } MAIL_DICT_CONTROL, * MAIL_DICT_CONTROL_FAR;                                           //09-03-10|0x003b
//-----------------------------------------------------------------------------           //09-03-10|0x003b
typedef struct {                                                                          //09-03-10|0x003b
  MAIL_DICT_CONTROL data;                                                                 //09-03-10|0x003b
  BINARY_FILE_DATA  file;                                                                 //09-03-10|0x003b
  SINT              index;                                                                //09-03-10|0x003b
  ULONG             position;                                                             //09-03-10|0x003b
  ULONG             size;                                                                 //09-03-10|0x003b
  UINT              state;                                                                //09-03-10|0x003b
  } MAIL_DICT_DATA, * MAIL_DICT_DATA_FAR;                                                 //09-03-10|0x003b
//-----------------------------------------------------------------------------           //09-03-10|0x003b
#endif                                                                                    //09-03-10|0x003b
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
// CLASS MAILDICT DEFINITION                                                              //09-03-10|0x0043
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
class MAILDICT {                                                                          //09-03-10|0x0043
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
// CLASS MAILDICT DEFINITION                                                              //09-03-10|0x0043
//*******************************************************************************         //10-29-97|0x0043
//*******************************************************************************         //10-29-97|0x0043
    private:                                                                              //10-27-97|0x004b
      MAIL_DICT_DATA_FAR mail_dict_addr;                                                  //10-27-97|0x004b
    public:                                                                               //09-03-10|0x0072
      UINT mail_dict_allocate(void);                                                      //09-03-10|0x0072
#define MailDictAllocate mail_dict.mail_dict_allocate                                     //09-03-10|0x0073
    public:                                                                               //09-03-10|0x008a
      UINT mail_dict_free(void);                                                          //09-03-10|0x008a
#define MailDictFree mail_dict.mail_dict_free                                             //09-03-10|0x008b
    public:                                                                               //10-01-03|0x00a3
      UINT mail_dict_initial(SCHAR_FAR,SCHAR_FAR);                                        //10-01-03|0x00a3
#define MailDictInitial mail_dict.mail_dict_initial                                       //10-01-03|0x00a5
    public:                                                                               //10-01-03|0x00c5
      UINT mail_dict_name(SINT,SCHAR_FAR);                                                //10-01-03|0x00c5
#define MailDictName mail_dict.mail_dict_name                                             //10-01-03|0x00c7
    public:                                                                               //10-01-03|0x00e2
      UINT mail_dict_name_done(void);                                                     //10-01-03|0x00e2
#define MailDictNameDone mail_dict.mail_dict_name_done                                    //10-01-03|0x00e3
    public:                                                                               //10-01-03|0x00fd
      UINT mail_dict_exists(SINT,ULONG_FAR);                                              //10-01-03|0x00fd
#define MailDictExists mail_dict.mail_dict_exists                                         //10-01-03|0x00ff
    public:                                                                               //10-01-03|0x011d
      UINT mail_dict_date_done(void);                                                     //10-01-03|0x011d
#define MailDictDateDone mail_dict.mail_dict_date_done                                    //10-01-03|0x011e
    public:                                                                               //10-01-03|0x0137
      UINT mail_dict_create(SINT);                                                        //10-01-03|0x0137
#define MailDictCreate mail_dict.mail_dict_create                                         //10-01-03|0x0139
    public:                                                                               //10-01-03|0x0158
      UINT mail_dict_read(SINT);                                                          //10-01-03|0x0158
#define MailDictRead mail_dict.mail_dict_read                                             //10-01-03|0x015a
    public:                                                                               //10-01-03|0x0180
      UINT mail_dict_open(UINT);                                                          //10-01-03|0x0180
#define MailDictOpen mail_dict.mail_dict_open                                             //10-01-03|0x0182
    public:                                                                               //10-01-03|0x019b
      UINT mail_dict_close(UINT);                                                         //10-01-03|0x019b
#define MailDictClose mail_dict.mail_dict_close                                           //10-01-03|0x019d
    public:                                                                               //10-01-19|0x01b8
      UINT mail_dict_task_done(void);                                                     //10-01-19|0x01b8
#define MailDictTaskDone mail_dict.mail_dict_task_done                                    //10-01-19|0x01b9
    public:                                                                               //10-01-19|0x01d6
      UINT mail_dict_finish_project(void);                                                //10-01-19|0x01d6
#define MailDictFinishProject mail_dict.mail_dict_finish_project                          //10-01-19|0x01d7
    public:                                                                               //10-01-03|0x01f2
      UINT mail_dict_complete(UINT);                                                      //10-01-03|0x01f2
#define MailDictComplete mail_dict.mail_dict_complete                                     //10-01-03|0x01f4
    public:                                                                               //10-01-03|0x020e
      UINT mail_dict_publish(UINT);                                                       //10-01-03|0x020e
#define MailDictPublish mail_dict.mail_dict_publish                                       //10-01-03|0x0210
    public:                                                                               //10-01-06|0x0238
      UINT mail_dict_delete(UINT);                                                        //10-01-06|0x0238
#define MailDictDelete mail_dict.mail_dict_delete                                         //10-01-06|0x023a
    public:                                                                               //10-01-03|0x0255
      UINT mail_dict_end(void);                                                           //10-01-03|0x0255
#define MailDictEnd mail_dict.mail_dict_end                                               //10-01-03|0x0256
    public:                                                                               //10-01-03|0x0273
      UINT maildict_add_zip(SINT,TOKENS_FAR);                                             //10-01-03|0x0273
#define MailDictAddZip mail_dict.maildict_add_zip                                         //09-03-11|0x0275
    public:                                                                               //check   |0x029b
      UINT mail_dict_add_po_box(TOKENS_FAR);                                              //check   |0x029b
#define MailDictAddPOBox mail_dict.mail_dict_add_po_box                                   //09-03-11|0x029d
    public:                                                                               //10-01-03|0x02d4
      UINT mail_dict_load_po_box(SINT,TOKENS_FAR);                                        //10-01-03|0x02d4
#define MailDictLoadPOBox mail_dict.mail_dict_load_po_box                                 //09-03-13|0x02d6
    public:                                                                               //10-01-03|0x0314
      UINT mail_dict_empty_po_box(SINT,TOKENS_FAR);                                       //10-01-03|0x0314
#define MailDictEmptyPOBox mail_dict.mail_dict_empty_po_box                               //09-09-17|0x0316
    public:                                                                               //10-01-03|0x0346
      UINT mail_dict_get_mail(SINT,STRING_DATA_FAR,TOKENS_FAR);                           //10-01-03|0x0346
#define MailDictGetMail mail_dict.mail_dict_get_mail                                      //09-03-14|0x0348
    public:                                                                               //10-01-03|0x037e
      UINT mail_dict_zip_exists(SINT,STRING_DATA_FAR);                                    //10-01-03|0x037e
#define MailDictZipExists mail_dict.mail_dict_zip_exists                                  //09-03-17|0x0380
    public:                                                                               //10-01-03|0x03a3
      UINT mail_dict_po_box_exists(SINT,TOKENS_FAR);                                      //10-01-03|0x03a3
#define MailDictPOBoxExists mail_dict.mail_dict_po_box_exists                             //09-03-17|0x03a5
    public:                                                                               //10-01-03|0x03d5
      UINT mail_dict_test_mail(SINT,TOKENS_FAR);                                          //10-01-03|0x03d5
#define MailDictTestMail mail_dict.mail_dict_test_mail                                    //09-03-17|0x03d7
    private:                                                                              //09-03-16|0x040b
      UINT mail_zip_find(STRING_DATA_FAR);                                                //09-03-16|0x040b
    private:                                                                              //09-03-16|0x0435
      UINT mail_po_box_find(STRING_DATA_FAR);                                             //09-03-16|0x0435
    private:                                                                              //09-03-16|0x0466
      UINT mail_get_next(void);                                                           //09-03-16|0x0466
    private:                                                                              //10-01-03|0x0485
      UINT mail_dict_control_read(SINT);                                                  //10-01-03|0x0485
    private:                                                                              //10-01-03|0x04af
      UINT mail_dict_control_write(SINT);                                                 //10-01-03|0x04af
    private:                                                                              //10-01-03|0x04cc
      UINT mail_dict_control_verify(SINT);                                                //10-01-03|0x04cc
    public:                                                                               //09-03-16|0x04e3
      UINT mail_dict_test_reset(void);                                                    //09-03-16|0x04e3
#define MailDictTestReset mail_dict.mail_dict_test_reset                                  //09-03-16|0x04e3
    public:                                                                               //09-03-16|0x04e5
      UINT mail_dict_test_read(void);                                                     //09-03-16|0x04e5
#define MailDictTestRead mail_dict.mail_dict_test_read                                    //09-03-16|0x04e5
    public:                                                                               //09-03-16|0x04e7
      UINT mail_dict_test_write(void);                                                    //09-03-16|0x04e7
#define MailDictTestWrite mail_dict.mail_dict_test_write                                  //09-03-16|0x04e7
    public:                                                                               //09-03-16|0x04e9
      UINT mail_dict_test_report(void);                                                   //09-03-16|0x04e9
#define MailDictTestReport mail_dict.mail_dict_test_report                                //09-03-16|0x04e9
    public:                                                                               //09-03-16|0x04f3
      MAILDICT();                                                                         //09-03-16|0x04f3
  };                                                                                      //10-29-97|0x04fb
extern class MAILDICT mail_dict;                                                          //98-12-29|0x04fb
//*******************************************************************************         //05-24-97|0x04fc
//*******************************************************************************         //05-24-97|0x04fc
//****                       END OF FILE                                     ****         //05-24-97|0x04fc
//*******************************************************************************         //05-24-97|0x04fc
//*******************************************************************************         //05-24-97|0x04fc
#endif                                                                                    //05-24-97|0x04fc
