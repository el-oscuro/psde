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
#ifndef guicomm_hpp                                                                       //06-08-29|0x0021
#define guicomm_hpp                                                                       //06-08-29|0x0021
//***************************************************************************             //06-08-29|0x0027
//***************************************************************************             //06-08-29|0x0028
//******                                                               ******             //06-08-29|0x0029
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //06-08-29|0x002a
//******                                                               ******             //06-08-29|0x002b
//***************************************************************************             //06-08-29|0x002c
//***************************************************************************             //06-08-29|0x002d
//***************************************************************************             //06-08-29|0x0030
//***************************************************************************             //06-08-29|0x0031
//******                                                               ******             //06-08-29|0x0032
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //06-08-29|0x0033
//******                                                               ******             //06-08-29|0x0034
//***************************************************************************             //06-08-29|0x0035
//***************************************************************************             //06-08-29|0x0036
#define UserError 0x0000                                                                  //06-08-29|0x0037
#define BuildError 0x7fff                                                                 //06-08-29|0x0037
#define Display 0x7ffe                                                                    //06-08-29|0x0037
#define KeyBoard 0x7ffd                                                                   //06-08-29|0x0037
#define Success 0xffff                                                                    //06-08-29|0x0037
#define SystemError 0x8000                                                                //06-08-29|0x0037
#define Continue 0x0001                                                                   //06-08-29|0x0037
#define FileDone 0x0002                                                                   //06-08-29|0x0037
#define LineDone 0x0003                                                                   //06-08-29|0x0037
#define Yes 0x0004                                                                        //06-08-29|0x0037
#define No 0x0005                                                                         //06-08-29|0x0037
#define RepeatChar '\x6'                                                                  //06-08-29|0x0037
#define Great 0x0007                                                                      //06-08-29|0x0037
#define Equal 0x0008                                                                      //06-08-29|0x0037
#define Less 0x0009                                                                       //06-08-29|0x0037
#define Zero 0x000a                                                                       //06-08-29|0x0037
#define Minus 0x000b                                                                      //06-08-29|0x0037
//***************************************************************************             //06-08-29|0x0038
#define SystemMsg PcgSystemError("guicomm", __LINE__);                                    //06-08-29|0x0039
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //06-08-29|0x0039
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //06-08-29|0x0039
#define _SwitchErr case UserError: return(UserError)                                      //12-05-21|0x003a
#define _SwitchOk case Success: break                                                     //12-05-21|0x003a
#define _SwitchEnd default: ReturnSystemError                                             //12-05-21|0x003a
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //12-05-21|0x003a
#define _SwitchYes case Yes:      return(Yes)                                             //12-05-21|0x003a
#define _SwitchNo case No:       return(No)                                               //12-05-21|0x003a
#define _SwitchGroup { _SwitchBase; }                                                     //12-05-21|0x003a
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //12-05-21|0x003a
#define _SwitchReturn _SwitchGroup return(Success)                                        //12-05-21|0x003a
#define _SwitchBreak _SwitchGroup break                                                   //12-05-21|0x003a
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //12-05-21|0x003a
//***************************************************************************             //12-05-21|0x0052
//***************************************************************************             //12-05-21|0x0053
//******                                                               ******             //12-05-21|0x0054
//******               GENERAL DEFINITION STATEMENTS                   ******             //12-05-21|0x0055
//******                                                               ******             //12-05-21|0x0056
//***************************************************************************             //12-05-21|0x0057
//***************************************************************************             //12-05-21|0x0058
#define ReportNameChar(i) report_name->line[i]                                            //12-05-21|0x0059
#define ReportNameLine report_name->line[0]                                               //12-05-21|0x0059
#define ReportNameLineAddr &(report_name->line[0])                                        //12-05-21|0x0059
#define ReportNameMacroLineNo report_name->macro_line_no                                  //12-05-21|0x0059
#define ReportNameType report_name->type                                                  //12-05-21|0x0059
#define ReportNameStartCol report_name->start_col                                         //12-05-21|0x0059
#define ReportNameStartCall report_name->start_call                                       //12-05-21|0x0059
#define ReportNamePosition report_name->position                                          //12-05-21|0x0059
#define ReportNameLength report_name->length                                              //12-05-21|0x0059
#define ReportNameColumn report_name->column                                              //12-05-21|0x0059
//**********************************************************************                  //12-05-21|0x0059
#define ReportStringChar(i) report_string.line[i]                                         //12-05-21|0x005a
#define ReportStringLine report_string.line[0]                                            //12-05-21|0x005a
#define ReportStringLineAddr &(report_string.line[0])                                     //12-05-21|0x005a
#define ReportStringMacroLineNo report_string.macro_line_no                               //12-05-21|0x005a
#define ReportStringType report_string.type                                               //12-05-21|0x005a
#define ReportStringStartCol report_string.start_col                                      //12-05-21|0x005a
#define ReportStringStartCall report_string.start_call                                    //12-05-21|0x005a
#define ReportStringPosition report_string.position                                       //12-05-21|0x005a
#define ReportStringLength report_string.length                                           //12-05-21|0x005a
#define ReportStringColumn report_string.column                                           //12-05-21|0x005a
//**********************************************************************                  //12-05-21|0x005a
//**********************************************************************                  //12-05-21|0x005b
#define ReportFileFileControl report_file.file_control                                    //12-05-21|0x005b
#define ReportFileString report_file.string                                               //12-05-21|0x005b
#define ReportFileLineNo report_file.line_no                                              //12-05-21|0x005b
#define ReportFileLength report_file.length                                               //12-05-21|0x005b
#define ReportFileNextPos report_file.next_position                                       //12-05-21|0x005b
#define ReportFileReadState report_file.read_state                                        //12-05-21|0x005b
#define ReportFileGetState report_file.get_state                                          //12-05-21|0x005b
#define ReportFilePutState report_file.put_state                                          //12-05-21|0x005b
#define ReportFileStatus report_file.status                                               //12-05-21|0x005b
#define ReportFileRunFlag report_file.run_flag                                            //12-05-21|0x005b
//----------------------------------------------------------------------                  //12-05-21|0x005b
#define ReportFileStringAddr &(report_file.string)                                        //12-05-21|0x005b
#define CMK_EXTENT ".cmk"                                                                 //12-05-21|0x005c
#define TMK_EXTENT ".tmk"                                                                 //12-05-21|0x005c
#define RPT_EXTENT ".rpt"                                                                 //12-05-21|0x005c
#define PMK_EXTENT ".pmk"                                                                 //12-05-21|0x005c
#define MAC_EXTENT ".mac"                                                                 //12-05-21|0x005c
#define SRC_EXTENT ".src"                                                                 //12-05-21|0x005c
#define PLB_EXTENT ".plb"                                                                 //12-05-21|0x005c
#define DIC_EXTENT ".dic"                                                                 //12-05-21|0x005c
#define MBX_EXTENT ".mbx"                                                                 //12-05-21|0x005c
#define MBC_EXTENT ".mbc"                                                                 //12-05-21|0x005c
#define RAN_EXTENT ".ran"                                                                 //12-05-21|0x005c
#define BUF_OUT_EXTENT ".bfo"                                                             //12-05-21|0x005c
#define BUF_IN_EXTENT ".bfi"                                                              //12-05-21|0x005c
//*******************************************************************************         //05-24-97|0x01b9
//*******************************************************************************         //05-24-97|0x01b9
//****                       END OF FILE                                     ****         //05-24-97|0x01b9
//*******************************************************************************         //05-24-97|0x01b9
//*******************************************************************************         //05-24-97|0x01b9
#endif                                                                                    //05-24-97|0x01b9
