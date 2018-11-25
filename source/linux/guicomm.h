//*****************************************************************************           //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//                                                                                        //06-08-29|0x001e
// GRAPHICS USER INTERFACE SUB-SYSTEM                                                     //06-08-29|0x001e
//                                                                                        //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//  Copyright: 2006 Robert H. Adams                                                       //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//  The purpose of this program as well as instructions regarding its use is              //06-08-29|0x001e
//  defined in the associated manual.                                                     //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//  This program is free software; you can redistribute it and/or modify                  //06-08-29|0x001e
//  it under the terms of the GNU General Public License as published by                  //06-08-29|0x001e
//  the Free Software Foundation; either version 2 of the License, or                     //06-08-29|0x001e
//  (at your option) any later version.                                                   //06-08-29|0x001e
//                                                                                        //06-08-29|0x001e
//  This program is distributed in the hope that it will be useful,                       //06-08-29|0x001e
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //06-08-29|0x001e
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //06-08-29|0x001e
//  GNU General Public License for more details.                                          //06-08-29|0x001e
//                                                                                        //06-08-29|0x001e
//  You should have received a copy of the GNU General Public License                     //06-08-29|0x001e
//  along with this program; if not, write to the Free Software                           //06-08-29|0x001e
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //06-08-29|0x001e
//  USA                                                                                   //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//  For further information, please contact Robert Adams:                                 //06-08-29|0x001e
//     EMail:    robert.adams@whatifwe.com                                                //06-08-29|0x001e
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //06-08-29|0x001e
//  Or visit the website, "www.whatifwe.com".                                             //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
//*****************************************************************************           //06-08-29|0x001e
#ifndef guicomm_h                                                                         //06-08-29|0x0021
#define guicomm_h                                                                         //06-08-29|0x0021
//***************************************************************************             //12-05-21|0x003b
//***************************************************************************             //12-05-21|0x003c
//******                                                               ******             //12-05-21|0x003d
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //12-05-21|0x003e
//******                                                               ******             //12-05-21|0x003f
//***************************************************************************             //12-05-21|0x0040
//***************************************************************************             //12-05-21|0x0041
//*******************************************************************************         //12-05-21|0x0042
#ifndef STRING_DATA_Defined                                                               //12-05-21|0x0042
#define STRING_DATA_Defined                                                               //12-05-21|0x0042
//-------------------------------------------------------------------------------         //12-05-21|0x0042
typedef struct {                                                                          //12-05-21|0x0042
  SCHAR   line[257];                                                                      //12-05-21|0x0042
  UINT    macro_line_no;                                                                  //12-05-21|0x0042
  UINT    type;                                                                           //12-05-21|0x0042
  UINT    start_col;                                                                      //12-05-21|0x0042
  UINT    start_call;                                                                     //12-05-21|0x0042
  SINT    length;                                                                         //12-05-21|0x0042
  SINT    position;                                                                       //12-05-21|0x0042
  SINT    column;                                                                         //12-05-21|0x0042
  } STRING_DATA, * STRING_DATA_FAR;                                                       //12-05-21|0x0042
//-------------------------------------------------------------------------------         //12-05-21|0x0042
#endif                                                                                    //12-05-21|0x0042
//*****************************************************************************           //12-05-21|0x0043
#ifndef FILE_CONTROL_Defined                                                              //12-05-21|0x0043
#define FILE_CONTROL_Defined                                                              //12-05-21|0x0043
//-----------------------------------------------------------------------------           //12-05-21|0x0043
typedef struct {                                                                          //12-05-21|0x0043
  UINT    state;                                                                          //12-05-21|0x0043
  SCHAR   name[_MAX_PATH+1];                                                              //12-05-21|0x0043
  FILE *  stream;                                                                         //12-05-21|0x0043
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //12-05-21|0x0043
//-----------------------------------------------------------------------------           //12-05-21|0x0043
#endif                                                                                    //12-05-21|0x0043
//*****************************************************************************           //12-05-21|0x0044
#ifndef TEXT_FILE_DATA_Defined                                                            //12-05-21|0x0044
#define TEXT_FILE_DATA_Defined                                                            //12-05-21|0x0044
//-----------------------------------------------------------------------------           //12-05-21|0x0044
typedef struct {                                                                          //12-05-21|0x0044
  FILE_CONTROL    file_control;                                                           //12-05-21|0x0044
  STRING_DATA     string;                                                                 //12-05-21|0x0044
  UINT            read_state;                                                             //12-05-21|0x0044
  UINT            get_state;                                                              //12-05-21|0x0044
  UINT            put_state;                                                              //12-05-21|0x0044
  UINT            status;                                                                 //12-05-21|0x0044
  UINT            run_flag;                                                               //12-05-21|0x0044
  UINT            line_no;                                                                //12-05-21|0x0044
  SLONG           length;                                                                 //12-05-21|0x0044
  SLONG           next_position;                                                          //12-05-21|0x0044
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //12-05-21|0x0044
//-----------------------------------------------------------------------------           //12-05-21|0x0044
#endif                                                                                    //12-05-21|0x0044
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
// CLASS GUICOMM DEFINITION                                                               //06-08-29|0x004c
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
class GUICOMM {                                                                           //06-08-29|0x004c
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
// CLASS GUICOMM DEFINITION                                                               //06-08-29|0x004c
//*******************************************************************************         //10-29-97|0x004c
//*******************************************************************************         //10-29-97|0x004c
#define BufferSize 8192                                                                   //12-05-21|0x004d
    private:                                                                              //10-27-97|0x004e
      SINT report_flag;                                                                   //10-27-97|0x004e
    private:                                                                              //10-27-97|0x004f
      SCHAR buffer[BufferSize+1];                                                         //10-27-97|0x004f
    private:                                                                              //10-27-97|0x0050
      TEXT_FILE_DATA report_file;                                                         //10-27-97|0x0050
    private:                                                                              //10-27-97|0x0051
      STRING_DATA report_string;                                                          //10-27-97|0x0051
    public:                                                                               //12-05-18|0x0064
      UINT load_name(STRING_DATA_FAR);                                                    //12-05-18|0x0064
#define GuiLoadName gui_comm.load_name                                                    //12-05-18|0x0065
    public:                                                                               //12-05-18|0x00a9
      void enable_file(void);                                                             //12-05-18|0x00a9
#define GuiEnableFile gui_comm.enable_file                                                //12-05-18|0x00aa
    public:                                                                               //12-05-21|0x00bb
      void disable_file(void);                                                            //12-05-21|0x00bb
#define GuiDisableFile gui_comm.disable_file                                              //12-05-21|0x00bc
    public:                                                                               //06-10-01|0x00cd
      UINT write_line(SCHAR_FAR);                                                         //06-10-01|0x00cd
#define GuiWriteLine gui_comm.write_line                                                  //06-10-01|0x00ce
    public:                                                                               //06-10-02|0x00e2
      UINT write_keybrd(SCHAR_FAR);                                                       //06-10-02|0x00e2
#define GuiWriteKeybrd gui_comm.write_keybrd                                              //06-10-02|0x00e3
    public:                                                                               //06-10-01|0x00f6
      UINT append_line(SCHAR_FAR);                                                        //06-10-01|0x00f6
#define GuiAppendLine gui_comm.append_line                                                //06-10-01|0x00f7
    public:                                                                               //07-03-23|0x0113
      UINT test_empty(void);                                                              //07-03-23|0x0113
#define GuiTestEmpty gui_comm.test_empty                                                  //07-03-23|0x0114
    public:                                                                               //06-08-29|0x0123
      UINT read_line(SCHAR_FAR,ULONG);                                                    //06-08-29|0x0123
#define GuiReadLine gui_comm.read_line                                                    //06-08-29|0x0124
    private:                                                                              //12-05-21|0x0148
      UINT write_report(SCHAR_FAR,ULONG);                                                 //12-05-21|0x0148
    public:                                                                               //12-05-21|0x017a
      UINT close_report(void);                                                            //12-05-21|0x017a
#define GuiCloseReport gui_comm.close_report                                              //12-05-21|0x017b
    private:                                                                              //12-05-21|0x0196
      UINT delete_menu(void);                                                             //12-05-21|0x0196
    public:                                                                               //12-05-21|0x01b2
      GUICOMM();                                                                          //12-05-21|0x01b2
  };                                                                                      //10-29-97|0x01b8
extern class GUICOMM gui_comm;                                                            //98-12-29|0x01b8
//*******************************************************************************         //05-24-97|0x01b9
//*******************************************************************************         //05-24-97|0x01b9
//****                       END OF FILE                                     ****         //05-24-97|0x01b9
//*******************************************************************************         //05-24-97|0x01b9
//*******************************************************************************         //05-24-97|0x01b9
#endif                                                                                    //05-24-97|0x01b9
