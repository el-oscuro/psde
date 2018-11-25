//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
// PRECEDENCE FILE MANAGER                                                                //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  The purpose of this program as well as instructions regarding its use is              //04-01-97|0x001e
//  defined in the associated manual.                                                     //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  This program is free software; you can redistribute it and/or modify                  //04-01-97|0x001e
//  it under the terms of the GNU General Public License as published by                  //04-01-97|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //04-01-97|0x001e
//  (at your option) any later version.                                                   //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//  This program is distributed in the hope that it will be useful,                       //04-01-97|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //04-01-97|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //04-01-97|0x001e
//  GNU General Public License for more details.                                          //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
//  You should have received a copy of the GNU General Public License                     //04-01-97|0x001e
//  along with this program; if not, write to the Free Software                           //04-01-97|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //04-01-97|0x001e
//  USA                                                                                   //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//  For further information, please contact Robert Adams:                                 //04-01-97|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //04-01-97|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //04-01-97|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
#ifndef precfile_h                                                                        //04-01-97|0x0023
#define precfile_h                                                                        //04-01-97|0x0023
//***************************************************************************             //06-07-13|0x0043
//***************************************************************************             //06-07-13|0x0044
//******                                                               ******             //06-07-13|0x0045
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //06-07-13|0x0046
//******                                                               ******             //06-07-13|0x0047
//***************************************************************************             //06-07-13|0x0048
//***************************************************************************             //06-07-13|0x0049
//*****************************************************************************           //06-07-13|0x004a
#ifndef FILE_CONTROL_Defined                                                              //06-07-13|0x004a
#define FILE_CONTROL_Defined                                                              //06-07-13|0x004a
//-----------------------------------------------------------------------------           //06-07-13|0x004a
typedef struct {                                                                          //06-07-13|0x004a
  UINT    state;                                                                          //06-07-13|0x004a
  SCHAR   name[_MAX_PATH+1];                                                              //06-07-13|0x004a
  FILE *  stream;                                                                         //06-07-13|0x004a
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //06-07-13|0x004a
//-----------------------------------------------------------------------------           //06-07-13|0x004a
#endif                                                                                    //06-07-13|0x004a
//***************************************************************************             //06-07-13|0x004b
//*******************************************************************************         //06-07-13|0x004c
#ifndef STRING_DATA_Defined                                                               //06-07-13|0x004c
#define STRING_DATA_Defined                                                               //06-07-13|0x004c
//-------------------------------------------------------------------------------         //06-07-13|0x004c
typedef struct {                                                                          //06-07-13|0x004c
  SCHAR   line[257];                                                                      //06-07-13|0x004c
  UINT    macro_line_no;                                                                  //06-07-13|0x004c
  UINT    type;                                                                           //06-07-13|0x004c
  UINT    start_col;                                                                      //06-07-13|0x004c
  UINT    start_call;                                                                     //06-07-13|0x004c
  SINT    length;                                                                         //06-07-13|0x004c
  SINT    position;                                                                       //06-07-13|0x004c
  SINT    column;                                                                         //06-07-13|0x004c
  } STRING_DATA, * STRING_DATA_FAR;                                                       //06-07-13|0x004c
//-------------------------------------------------------------------------------         //06-07-13|0x004c
#endif                                                                                    //06-07-13|0x004c
//*******************************************************************************         //06-07-13|0x004d
#ifndef TOKENS_Defined                                                                    //06-07-13|0x004d
#define TOKENS_Defined                                                                    //06-07-13|0x004d
//-------------------------------------------------------------------------------         //06-07-13|0x004d
typedef struct {                                                                          //06-07-13|0x004d
  UINT        no_tokens;                                                                  //06-07-13|0x004d
  STRING_DATA token[10];                                                                  //06-07-13|0x004d
  } TOKENS, * TOKENS_FAR;                                                                 //06-07-13|0x004d
//-------------------------------------------------------------------------------         //06-07-13|0x004d
#endif                                                                                    //06-07-13|0x004d
//*******************************************************************************         //06-07-13|0x004e
#ifndef TEXT_DATA_Defined                                                                 //06-07-13|0x004e
#define TEXT_DATA_Defined                                                                 //06-07-13|0x004e
//-------------------------------------------------------------------------------         //06-07-13|0x004e
typedef struct {                                                                          //06-07-13|0x004e
  SLONG           current_position;                                                       //06-07-13|0x004e
  SLONG           next_position;                                                          //06-07-13|0x004e
  TOKENS          arguments;                                                              //06-07-13|0x004e
  } TEXT_DATA, * TEXT_DATA_FAR;                                                           //06-07-13|0x004e
//-------------------------------------------------------------------------------         //06-07-13|0x004e
#endif                                                                                    //06-07-13|0x004e
//*****************************************************************************           //06-07-13|0x004f
#ifndef TEXT_FILE_DATA_Defined                                                            //06-07-13|0x004f
#define TEXT_FILE_DATA_Defined                                                            //06-07-13|0x004f
//-----------------------------------------------------------------------------           //06-07-13|0x004f
typedef struct {                                                                          //06-07-13|0x004f
  FILE_CONTROL    file_control;                                                           //06-07-13|0x004f
  STRING_DATA     string;                                                                 //06-07-13|0x004f
  UINT            read_state;                                                             //06-07-13|0x004f
  UINT            get_state;                                                              //06-07-13|0x004f
  UINT            put_state;                                                              //06-07-13|0x004f
  UINT            status;                                                                 //06-07-13|0x004f
  UINT            run_flag;                                                               //06-07-13|0x004f
  UINT            line_no;                                                                //06-07-13|0x004f
  SLONG           length;                                                                 //06-07-13|0x004f
  SLONG           next_position;                                                          //06-07-13|0x004f
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //06-07-13|0x004f
//-----------------------------------------------------------------------------           //06-07-13|0x004f
#endif                                                                                    //06-07-13|0x004f
//***************************************************************************             //06-07-13|0x0050
//*******************************************************************************         //06-07-13|0x0051
#ifndef BINARY_FILE_DATA_Defined                                                          //06-07-13|0x0051
#define BINARY_FILE_DATA_Defined                                                          //06-07-13|0x0051
//-------------------------------------------------------------------------------         //06-07-13|0x0051
typedef struct {                                                                          //06-07-13|0x0051
  FILE_CONTROL    file_control;                                                           //06-07-13|0x0051
  SLONG           file_position;                                                          //06-07-13|0x0051
  SLONG           file_length;                                                            //06-07-13|0x0051
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //06-07-13|0x0051
//-------------------------------------------------------------------------------         //06-07-13|0x0051
#endif                                                                                    //06-07-13|0x0051
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
// CLASS PRECFILE DEFINITION                                                              //04-01-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
class PRECFILE {                                                                          //04-01-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
// CLASS PRECFILE DEFINITION                                                              //04-01-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
//*******************************************************************************         //10-29-97|0x005a
    private:                                                                              //10-27-97|0x0062
      BINARY_FILE_DATA_FAR binary_file_addr;                                              //10-27-97|0x0062
    private:                                                                              //10-27-97|0x0063
      TEXT_FILE_DATA_FAR text_file_addr;                                                  //10-27-97|0x0063
    private:                                                                              //10-27-97|0x0064
      FILE_CONTROL_FAR file_control_addr;                                                 //10-27-97|0x0064
    private:                                                                              //10-27-97|0x0065
      UINT class_state;                                                                   //10-27-97|0x0065
    private:                                                                              //10-27-97|0x0066
      UINT state;                                                                         //10-27-97|0x0066
    private:                                                                              //10-27-97|0x0067
      UINT status;                                                                        //10-27-97|0x0067
    private:                                                                              //10-27-97|0x0068
      UINT line_no;                                                                       //10-27-97|0x0068
    private:                                                                              //10-27-97|0x0069
      UINT tab;                                                                           //10-27-97|0x0069
    private:                                                                              //10-27-97|0x006a
      UINT no_tokens;                                                                     //10-27-97|0x006a
    private:                                                                              //10-27-97|0x006b
      UINT token_length;                                                                  //10-27-97|0x006b
    private:                                                                              //10-27-97|0x006c
      STRING_DATA_FAR token_addr;                                                         //10-27-97|0x006c
    private:                                                                              //10-27-97|0x006d
      UINT display_flag;                                                                  //10-27-97|0x006d
    private:                                                                              //10-27-97|0x006e
      UINT display_state;                                                                 //10-27-97|0x006e
    private:                                                                              //10-27-97|0x006f
      TOKENS_FAR tokens_addr;                                                             //10-27-97|0x006f
    public:                                                                               //05-02-07|0x0099
      UINT initial_text(TEXT_FILE_DATA_FAR);                                              //05-02-07|0x0099
#define FileInitialText prec_file.initial_text                                            //04-01-97|0x009a
    public:                                                                               //06-09-04|0x00bb
      void set_display_flag(UINT);                                                        //06-09-04|0x00bb
#define SetDisplayFlag prec_file.set_display_flag                                         //06-09-04|0x00bc
    public:                                                                               //09-01-10|0x00de
      void enable_display(void);                                                          //09-01-10|0x00de
#define EnableDisplay prec_file.enable_display                                            //09-01-10|0x00df
    public:                                                                               //09-01-10|0x0111
      void disable_display(void);                                                         //09-01-10|0x0111
#define DisableDisplay prec_file.disable_display                                          //09-01-10|0x0112
    public:                                                                               //08-04-16|0x013f
      void display_on(void);                                                              //08-04-16|0x013f
#define DisplayOn prec_file.display_on                                                    //08-04-16|0x0140
    public:                                                                               //08-04-16|0x016c
      void display_off(void);                                                             //08-04-16|0x016c
#define DisplayOff prec_file.display_off                                                  //08-04-16|0x016d
    public:                                                                               //07-01-30|0x0194
      UINT open_text_state(TEXT_FILE_DATA_FAR);                                           //07-01-30|0x0194
#define FileOpenTextState prec_file.open_text_state                                       //07-01-30|0x0195
    public:                                                                               //05-02-07|0x01ad
      UINT initial_binary(BINARY_FILE_DATA_FAR);                                          //05-02-07|0x01ad
#define FileInitialBinary prec_file.initial_binary                                        //05-01-28|0x01ae
    public:                                                                               //05-02-07|0x01cf
      UINT commit_text(TEXT_FILE_DATA_FAR);                                               //05-02-07|0x01cf
#define FileCommitText prec_file.commit_text                                              //04-11-97|0x01d0
    public:                                                                               //05-02-07|0x01ed
      UINT commit_binary(BINARY_FILE_DATA_FAR);                                           //05-02-07|0x01ed
#define FileCommitBinary prec_file.commit_binary                                          //05-02-01|0x01ee
    public:                                                                               //04-11-97|0x020d
      UINT release(void);                                                                 //04-11-97|0x020d
#define FileRelease prec_file.release                                                     //04-11-97|0x020e
    public:                                                                               //07-03-23|0x022c
      UINT enter_path(SCHAR_FAR);                                                         //07-03-23|0x022c
#define FileEnterPath prec_file.enter_path                                                //07-03-23|0x022d
    public:                                                                               //04-09-97|0x0251
      UINT enter_name(SCHAR_FAR,SCHAR_FAR);                                               //04-09-97|0x0251
#define FileEnterName prec_file.enter_name                                                //04-09-97|0x0252
    public:                                                                               //04-08-06|0x0279
      UINT exists(ULONG_FAR);                                                             //04-08-06|0x0279
#define FileExists prec_file.exists                                                       //04-09-97|0x027a
    public:                                                                               //04-01-97|0x0298
      UINT close(void);                                                                   //04-01-97|0x0298
#define FileClose prec_file.close                                                         //04-01-97|0x0299
    public:                                                                               //06-09-04|0x02b8
      UINT delete_file(void);                                                             //06-09-04|0x02b8
#define FileDelete prec_file.delete_file                                                  //06-09-04|0x02b9
    public:                                                                               //04-09-97|0x02e4
      void set_tab(UINT);                                                                 //04-09-97|0x02e4
#define FileSetTab prec_file.set_tab                                                      //04-09-97|0x02e5
    public:                                                                               //07-08-11|0x02fa
      UINT get_tab(void);                                                                 //07-08-11|0x02fa
#define FileGetTab prec_file.get_tab                                                      //07-08-11|0x02fb
    public:                                                                               //05-01-97|0x0312
      UINT open_text(void);                                                               //05-01-97|0x0312
#define FileOpenText prec_file.open_text                                                  //05-01-97|0x0313
    public:                                                                               //05-01-97|0x033e
      UINT text_read_status(void);                                                        //05-01-97|0x033e
#define FileTextReadStatus prec_file.text_read_status                                     //05-01-97|0x033f
    public:                                                                               //06-07-13|0x0367
      UINT read_text(TOKENS_FAR);                                                         //06-07-13|0x0367
#define FileReadText prec_file.read_text                                                  //05-01-97|0x0368
    public:                                                                               //08-04-18|0x03b0
      UINT test_line_end(SCHAR_FAR);                                                      //08-04-18|0x03b0
#define FileTestLineEnd prec_file.test_line_end                                           //08-04-18|0x03b1
    public:                                                                               //11-02-15|0x03e8
      UINT date_line_end(ULONG_FAR);                                                      //11-02-15|0x03e8
#define FileDateLineEnd prec_file.date_line_end                                           //11-02-15|0x03e9
    public:                                                                               //07-02-02|0x043b
      UINT get_text(STRING_DATA_FAR,UINT);                                                //07-02-02|0x043b
#define FileGetText prec_file.get_text                                                    //07-02-02|0x043c
    public:                                                                               //10-08-19|0x045f
      UINT put_text(STRING_DATA_FAR);                                                     //10-08-19|0x045f
#define FilePutText prec_file.put_text                                                    //10-08-19|0x0460
    public:                                                                               //check   |0x0489
      UINT file_append_text(STRING_DATA_FAR);                                             //check   |0x0489
#define FileAppendText prec_file.file_append_text                                         //check   |0x048a
    public:                                                                               //10-08-19|0x04b3
      UINT put_crlf(void);                                                                //10-08-19|0x04b3
#define FilePutCRLF prec_file.put_crlf                                                    //10-08-19|0x04b4
    public:                                                                               //<----   |0x04dd
      UINT put_dbug(void);                                                                //<----   |0x04dd
#define FilePutDbug prec_file.put_dbug                                                    //<----   |0x04de
    public:                                                                               //06-10-05|0x0507
      UINT create_text(void);                                                             //06-10-05|0x0507
#define FileCreateText prec_file.create_text                                              //check   |0x0508
    private:                                                                              //07-08-11|0x0522
      UINT append_text(void);                                                             //07-08-11|0x0522
    public:                                                                               //10-08-19|0x0539
      UINT write_text(void);                                                              //10-08-19|0x0539
#define FileWriteText prec_file.write_text                                                //check   |0x053a
    private:                                                                              //10-08-19|0x0557
      UINT write_crlf(void);                                                              //10-08-19|0x0557
    private:                                                                              //06-10-05|0x0574
      UINT close_line(void);                                                              //06-10-05|0x0574
    private:                                                                              //07-02-02|0x058f
      UINT get_line(UINT);                                                                //07-02-02|0x058f
    public:                                                                               //check   |0x05be
      UINT read_text_segment(SLONG,STRING_DATA_FAR);                                      //check   |0x05be
#define FileReadTextSegment prec_file.read_text_segment                                   //check   |0x05c0
    private:                                                                              //04-02-97|0x05f6
      UINT read_line(void);                                                               //04-02-97|0x05f6
    private:                                                                              //13-01-17|0x0636
      UINT initial_read_segment(SLONG_FAR);                                               //13-01-17|0x0636
    private:                                                                              //13-02-08|0x064e
      UINT read_segment(SLONG_FAR,SLONG,STRING_DATA_FAR);                                 //13-02-08|0x064e
    private:                                                                              //13-04-25|0x0684
      UINT isolate_segment(SLONG_FAR,SLONG,STRING_DATA_FAR);                              //13-04-25|0x0684
    private:                                                                  //13-02-05|0x06b6
      UINT isolate_special_char(SLONG_FAR,STRING_DATA_FAR);                   //13-02-05|0x06b6
    private:                                                                              //13-02-05|0x06dc
      UINT isolate_text_segment(SLONG_FAR,SLONG,STRING_DATA_FAR);                         //13-02-05|0x06dc
    private:                                                                              //13-02-19|0x0707
      UINT complete_read_segment(SLONG_FAR,STRING_DATA_FAR);                              //13-02-19|0x0707
    private:                                                                              //check   |0x0733
      UINT finish_read_segment(SLONG,STRING_DATA_FAR);                                    //check   |0x0733
    private:                                                                              //13-02-19|0x074c
      UINT finalize_text_segment(SLONG,STRING_DATA_FAR);                                  //13-02-19|0x074c
    private:                                                                              //07-08-11|0x076e
      UINT end_of_textfile(void);                                                         //07-08-11|0x076e
    private:                                                                              //04-02-97|0x078f
      UINT char_test(void);                                                               //04-02-97|0x078f
    private:                                                                              //99-08-12|0x07b8
      UINT process_tab(void);                                                             //99-08-12|0x07b8
    private:                                                                              //07-02-02|0x082f
      int disp_line(UINT);                                                                //07-02-02|0x082f
    private:                                                                              //06-08-29|0x0860
      int initial_read_text(void);                                                        //06-08-29|0x0860
    private:                                                                              //06-08-26|0x0879
      UINT line_test(void);                                                               //06-08-26|0x0879
    private:                                                                              //06-09-04|0x08ac
      UINT first_delim(void);                                                             //06-09-04|0x08ac
    private:                                                                              //06-08-26|0x08d7
      UINT end_test(void);                                                                //06-08-26|0x08d7
    private:                                                                              //07-02-02|0x08ff
      UINT cont_test(void);                                                               //07-02-02|0x08ff
    private:                                                                              //07-02-02|0x092e
      UINT token_type(void);                                                              //07-02-02|0x092e
    private:                                                                              //06-08-26|0x0979
      UINT next_delim(void);                                                              //06-08-26|0x0979
    public:                                                                               //05-01-97|0x09a4
      UINT create_record(void);                                                           //05-01-97|0x09a4
#define FileCreateRecord prec_file.create_record                                          //05-01-97|0x09a5
    public:                                                                               //06-07-27|0x09c4
      UINT append_record(void);                                                           //06-07-27|0x09c4
#define FileAppendRecord prec_file.append_record                                          //06-07-27|0x09c5
    public:                                                                               //05-14-97|0x09e5
      UINT open_record(void);                                                             //05-14-97|0x09e5
#define FileOpenRecord prec_file.open_record                                              //05-14-97|0x09e6
    public:                                                                               //06-06-11|0x0a08
      UINT read_data(SCHAR_FAR,SLONG,SLONG);                                              //06-06-11|0x0a08
#define FileReadData prec_file.read_data                                                  //05-14-97|0x0a09
    public:                                                                               //06-06-11|0x0a2f
      UINT write_data(SLONG,SCHAR_FAR,SLONG);                                             //06-06-11|0x0a2f
#define FileWriteData prec_file.write_data                                                //05-01-97|0x0a30
    private:                                                                              //04-01-97|0x0a56
      UINT class_manager(UINT);                                                           //04-01-97|0x0a56
    private:                                                                              //05-01-97|0x0a8e
      UINT file_manager(UINT);                                                            //05-01-97|0x0a8e
    public:                                                                               //05-04-29|0x0b0d
      void file_reset(void);                                                              //05-04-29|0x0b0d
#define FileReset prec_file.file_reset                                                    //05-04-29|0x0b0e
    public:                                                                               //04-10-18|0x0b23
      UINT precfile_test_reset(void);                                                     //04-10-18|0x0b23
#define PrecFileTestReset prec_file.precfile_test_reset                                   //04-10-18|0x0b23
    public:                                                                               //04-10-18|0x0b25
      UINT precfile_test_read(void);                                                      //04-10-18|0x0b25
#define PrecFileTestRead prec_file.precfile_test_read                                     //04-10-18|0x0b25
    public:                                                                               //04-10-18|0x0b27
      UINT precfile_test_write(void);                                                     //04-10-18|0x0b27
#define PrecFileTestWrite prec_file.precfile_test_write                                   //04-10-18|0x0b27
    public:                                                                               //04-10-18|0x0b29
      UINT precfile_test_report(void);                                                    //04-10-18|0x0b29
#define PrecFileTestReport prec_file.precfile_test_report                                 //04-10-18|0x0b29
    public:                                                                               //04-01-97|0x0b33
      PRECFILE();                                                                         //04-01-97|0x0b33
  };                                                                                      //10-29-97|0x0b42
extern class PRECFILE prec_file;                                                          //98-12-29|0x0b42
//*******************************************************************************         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
//****                       END OF FILE                                     ****         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
//*******************************************************************************         //05-24-97|0x0b43
#endif                                                                                    //05-24-97|0x0b43
