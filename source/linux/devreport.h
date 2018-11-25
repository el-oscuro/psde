//*****************************************************************************           //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//                                                                                        //11-02-14|0x000b
// VERSION REPORT GENERATOR                                                               //11-02-14|0x000b
//                                                                                        //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//  The purpose of this program as well as instructions regarding its use is              //11-02-14|0x000b
//  defined in the associated manual.                                                     //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//  This program is free software; you can redistribute it and/or modify                  //11-02-14|0x000b
//  it under the terms of the GNU General Public License as published by                  //11-02-14|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //11-02-14|0x000b
//  (at your option) any later version.                                                   //11-02-14|0x000b
//                                                                                        //11-02-14|0x000b
//  This program is distributed in the hope that it will be useful,                       //11-02-14|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //11-02-14|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //11-02-14|0x000b
//  GNU General Public License for more details.                                          //11-02-14|0x000b
//                                                                                        //11-02-14|0x000b
//  You should have received a copy of the GNU General Public License                     //11-02-14|0x000b
//  along with this program; if not, write to the Free Software                           //11-02-14|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //11-02-14|0x000b
//  USA                                                                                   //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//  For further information, please contact Robert Adams:                                 //11-02-14|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //11-02-14|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //11-02-14|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
//*****************************************************************************           //11-02-14|0x000b
#ifndef devreport_h                                                                       //11-02-14|0x000c
#define devreport_h                                                                       //11-02-14|0x000c
//***************************************************************************             //11-02-14|0x0025
//***************************************************************************             //11-02-14|0x0026
//******                                                               ******             //11-02-14|0x0027
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //11-02-14|0x0028
//******                                                               ******             //11-02-14|0x0029
//***************************************************************************             //11-02-14|0x002a
//***************************************************************************             //11-02-14|0x002b
//*******************************************************************************         //11-02-14|0x002c
#ifndef STRING_DATA_Defined                                                               //11-02-14|0x002c
#define STRING_DATA_Defined                                                               //11-02-14|0x002c
//-------------------------------------------------------------------------------         //11-02-14|0x002c
typedef struct {                                                                          //11-02-14|0x002c
  SCHAR   line[257];                                                                      //11-02-14|0x002c
  UINT    macro_line_no;                                                                  //11-02-14|0x002c
  UINT    type;                                                                           //11-02-14|0x002c
  UINT    start_col;                                                                      //11-02-14|0x002c
  UINT    start_call;                                                                     //11-02-14|0x002c
  SINT    length;                                                                         //11-02-14|0x002c
  SINT    position;                                                                       //11-02-14|0x002c
  SINT    column;                                                                         //11-02-14|0x002c
  } STRING_DATA, * STRING_DATA_FAR;                                                       //11-02-14|0x002c
//-------------------------------------------------------------------------------         //11-02-14|0x002c
#endif                                                                                    //11-02-14|0x002c
//*****************************************************************************           //11-02-14|0x002d
#ifndef FILE_CONTROL_Defined                                                              //11-02-14|0x002d
#define FILE_CONTROL_Defined                                                              //11-02-14|0x002d
//-----------------------------------------------------------------------------           //11-02-14|0x002d
typedef struct {                                                                          //11-02-14|0x002d
  UINT    state;                                                                          //11-02-14|0x002d
  SCHAR   name[_MAX_PATH+1];                                                              //11-02-14|0x002d
  FILE *  stream;                                                                         //11-02-14|0x002d
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //11-02-14|0x002d
//-----------------------------------------------------------------------------           //11-02-14|0x002d
#endif                                                                                    //11-02-14|0x002d
//*****************************************************************************           //11-02-14|0x002e
#ifndef TEXT_FILE_DATA_Defined                                                            //11-02-14|0x002e
#define TEXT_FILE_DATA_Defined                                                            //11-02-14|0x002e
//-----------------------------------------------------------------------------           //11-02-14|0x002e
typedef struct {                                                                          //11-02-14|0x002e
  FILE_CONTROL    file_control;                                                           //11-02-14|0x002e
  STRING_DATA     string;                                                                 //11-02-14|0x002e
  UINT            read_state;                                                             //11-02-14|0x002e
  UINT            get_state;                                                              //11-02-14|0x002e
  UINT            put_state;                                                              //11-02-14|0x002e
  UINT            status;                                                                 //11-02-14|0x002e
  UINT            run_flag;                                                               //11-02-14|0x002e
  UINT            line_no;                                                                //11-02-14|0x002e
  SLONG           length;                                                                 //11-02-14|0x002e
  SLONG           next_position;                                                          //11-02-14|0x002e
  } TEXT_FILE_DATA, * TEXT_FILE_DATA_FAR;                                                 //11-02-14|0x002e
//-----------------------------------------------------------------------------           //11-02-14|0x002e
#endif                                                                                    //11-02-14|0x002e
//*******************************************************************************         //10-29-97|0x0036
//*******************************************************************************         //10-29-97|0x0036
// CLASS VERSION_REPORT DEFINITION                                                        //11-02-14|0x0036
//*******************************************************************************         //10-29-97|0x0036
//*******************************************************************************         //10-29-97|0x0036
class VERSION_REPORT {                                                                    //11-02-14|0x0036
//*******************************************************************************         //10-29-97|0x0036
//*******************************************************************************         //10-29-97|0x0036
// CLASS VERSION_REPORT DEFINITION                                                        //11-02-14|0x0036
//*******************************************************************************         //10-29-97|0x0036
//*******************************************************************************         //10-29-97|0x0036
    private:                                                                              //10-27-97|0x003e
      TEXT_FILE_DATA report_file;                                                         //10-27-97|0x003e
    public:                                                                               //11-02-14|0x0057
      UINT report_open(SCHAR_FAR,SCHAR_FAR);                                              //11-02-14|0x0057
#define ReportOpen version_report.report_open                                             //11-02-14|0x0059
    public:                                                                               //11-02-15|0x0090
      UINT report_write(STRING_DATA_FAR);                                                 //11-02-15|0x0090
#define ReportWrite version_report.report_write                                           //11-02-15|0x0092
    public:                                                                               //11-02-15|0x00ba
      UINT report_crlf(void);                                                             //11-02-15|0x00ba
#define ReportCRLF version_report.report_crlf                                             //11-02-15|0x00bb
    public:                                                                               //11-02-17|0x00d9
      UINT report_close(void);                                                            //11-02-17|0x00d9
#define ReportClose version_report.report_close                                           //11-02-17|0x00da
    public:                                                                               //11-02-18|0x00f1
      UINT report_delete(void);                                                           //11-02-18|0x00f1
#define ReportDelete version_report.report_delete                                         //11-02-18|0x00f2
    public:                                                                               //11-02-18|0x0106
      VERSION_REPORT();                                                                   //11-02-18|0x0106
  };                                                                                      //10-29-97|0x010e
extern class VERSION_REPORT version_report;                                               //98-12-29|0x010e
//*******************************************************************************         //05-24-97|0x010f
//*******************************************************************************         //05-24-97|0x010f
//****                       END OF FILE                                     ****         //05-24-97|0x010f
//*******************************************************************************         //05-24-97|0x010f
//*******************************************************************************         //05-24-97|0x010f
#endif                                                                                    //05-24-97|0x010f
