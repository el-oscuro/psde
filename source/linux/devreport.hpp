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
#ifndef devreport_hpp                                                                     //11-02-14|0x000c
#define devreport_hpp                                                                     //11-02-14|0x000c
//***************************************************************************             //11-02-14|0x000f
//***************************************************************************             //11-02-14|0x0010
//******                                                               ******             //11-02-14|0x0011
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //11-02-14|0x0012
//******                                                               ******             //11-02-14|0x0013
//***************************************************************************             //11-02-14|0x0014
//***************************************************************************             //11-02-14|0x0015
#define CMK_EXTENT ".cmk"                                                                 //11-02-14|0x0018
#define TMK_EXTENT ".tmk"                                                                 //11-02-14|0x0018
#define RPT_EXTENT ".rpt"                                                                 //11-02-14|0x0018
#define PMK_EXTENT ".pmk"                                                                 //11-02-14|0x0018
#define MAC_EXTENT ".mac"                                                                 //11-02-14|0x0018
#define SRC_EXTENT ".src"                                                                 //11-02-14|0x0018
#define PLB_EXTENT ".plb"                                                                 //11-02-14|0x0018
#define DIC_EXTENT ".dic"                                                                 //11-02-14|0x0018
#define MBX_EXTENT ".mbx"                                                                 //11-02-14|0x0018
#define MBC_EXTENT ".mbc"                                                                 //11-02-14|0x0018
#define RAN_EXTENT ".ran"                                                                 //11-02-14|0x0018
#define BUF_OUT_EXTENT ".bfo"                                                             //11-02-14|0x0018
#define BUF_IN_EXTENT ".bfi"                                                              //11-02-14|0x0018
//***************************************************************************             //11-02-14|0x0019
//***************************************************************************             //11-02-14|0x001a
//******                                                               ******             //11-02-14|0x001b
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //11-02-14|0x001c
//******                                                               ******             //11-02-14|0x001d
//***************************************************************************             //11-02-14|0x001e
//***************************************************************************             //11-02-14|0x001f
#define UserError 0x0000                                                                  //11-02-14|0x0020
#define BuildError 0x7fff                                                                 //11-02-14|0x0020
#define Display 0x7ffe                                                                    //11-02-14|0x0020
#define KeyBoard 0x7ffd                                                                   //11-02-14|0x0020
#define Success 0xffff                                                                    //11-02-14|0x0020
#define SystemError 0x8000                                                                //11-02-14|0x0020
#define Continue 0x0001                                                                   //11-02-14|0x0020
#define FileDone 0x0002                                                                   //11-02-14|0x0020
#define LineDone 0x0003                                                                   //11-02-14|0x0020
#define Yes 0x0004                                                                        //11-02-14|0x0020
#define No 0x0005                                                                         //11-02-14|0x0020
#define RepeatChar '\x6'                                                                  //11-02-14|0x0020
#define Great 0x0007                                                                      //11-02-14|0x0020
#define Equal 0x0008                                                                      //11-02-14|0x0020
#define Less 0x0009                                                                       //11-02-14|0x0020
#define Zero 0x000a                                                                       //11-02-14|0x0020
#define Minus 0x000b                                                                      //11-02-14|0x0020
//***************************************************************************             //11-02-14|0x0021
#define SystemMsg PcgSystemError("VersionReport", __LINE__);                              //11-02-14|0x0022
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //11-02-14|0x0022
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //11-02-14|0x0022
#define BreakFinish(_a) status = Finish(_a); break                                        //11-02-14|0x0023
#define ReturnFinish(_a) return(Finish(_a))                                               //11-02-14|0x0023
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //11-02-14|0x0023
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //11-02-14|0x0023
#define _SwitchErr case UserError: return(UserError)                                      //11-02-14|0x0024
#define _SwitchOk case Success: break                                                     //11-02-14|0x0024
#define _SwitchEnd default: ReturnSystemError                                             //11-02-14|0x0024
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //11-02-14|0x0024
#define _SwitchYes case Yes:      return(Yes)                                             //11-02-14|0x0024
#define _SwitchNo case No:       return(No)                                               //11-02-14|0x0024
#define _SwitchGroup { _SwitchBase; }                                                     //11-02-14|0x0024
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //11-02-14|0x0024
#define _SwitchReturn _SwitchGroup return(Success)                                        //11-02-14|0x0024
#define _SwitchBreak _SwitchGroup break                                                   //11-02-14|0x0024
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //11-02-14|0x0024
//***************************************************************************             //11-02-14|0x003f
//***************************************************************************             //11-02-14|0x0040
//******                                                               ******             //11-02-18|0x0041
//******               GENERAL DEFINITION STATEMENTS                   ******             //11-02-18|0x0042
//******                                                               ******             //11-02-14|0x0043
//***************************************************************************             //11-02-14|0x0044
//***************************************************************************             //11-02-14|0x0045
#define TestSample(i) test_samples[i] = __LINE__                                          //11-02-14|0x0046
#define return_test(j) { TestSample(j);  return(Success); }                               //11-02-14|0x0046
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //11-02-14|0x0046
#define return_no(j) { TestSample(j);  return(No); }                                      //11-02-14|0x0046
#define return_cont(j) { TestSample(j);  return(Continue); }                              //11-02-14|0x0046
#define return_line(j) { TestSample(j);  return(LineDone); }                              //11-02-14|0x0046
#define goto_test(i) { TestSample(i);  goto loop; }                                       //11-02-14|0x0046
#define break_test(i) { TestSample(i);  break; }                                          //11-02-14|0x0046
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //11-02-14|0x0046
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //11-02-14|0x0046
//************************************************************************                //11-02-14|0x0046
#ifndef TestIndex                                                                         //11-02-14|0x0046
#define TestIndex 0                                                                       //11-02-14|0x0046
#endif                                                                                    //11-02-14|0x0046
//------------------------------------------------------------------------                //11-02-14|0x0046
enum {  NoTestSamples = TestIndex };                                                      //11-02-14|0x0046
//------------------------------------------------------------------------                //11-02-14|0x0046
#undef TestIndex                                                                          //11-02-14|0x0046
#define TestIndex NoTestSamples+1                                                         //11-02-14|0x0046
//************************************************************************                //11-02-14|0x0046
//***************************************************************************             //11-02-14|0x0047
//**********************************************************************                  //11-02-14|0x0048
#define ReportFileControl report_file.file_control                                        //11-02-14|0x0048
#define ReportString report_file.string                                                   //11-02-14|0x0048
#define ReportLineNo report_file.line_no                                                  //11-02-14|0x0048
#define ReportLength report_file.length                                                   //11-02-14|0x0048
#define ReportNextPos report_file.next_position                                           //11-02-14|0x0048
#define ReportReadState report_file.read_state                                            //11-02-14|0x0048
#define ReportGetState report_file.get_state                                              //11-02-14|0x0048
#define ReportPutState report_file.put_state                                              //11-02-14|0x0048
#define ReportStatus report_file.status                                                   //11-02-14|0x0048
#define ReportRunFlag report_file.run_flag                                                //11-02-14|0x0048
//----------------------------------------------------------------------                  //11-02-14|0x0048
#define ReportStringAddr &(report_file.string)                                            //11-02-14|0x0048
//***************************************************************************             //11-02-14|0x0049
#define StringChar(i) string.line[i]                                                      //11-02-14|0x004a
#define StringLine string.line[0]                                                         //11-02-14|0x004a
#define StringLineAddr &(string.line[0])                                                  //11-02-14|0x004a
#define StringMacroLineNo string.macro_line_no                                            //11-02-14|0x004a
#define StringType string.type                                                            //11-02-14|0x004a
#define StringStartCol string.start_col                                                   //11-02-14|0x004a
#define StringStartCall string.start_call                                                 //11-02-14|0x004a
#define StringPosition string.position                                                    //11-02-14|0x004a
#define StringLength string.length                                                        //11-02-14|0x004a
#define StringColumn string.column                                                        //11-02-14|0x004a
//**********************************************************************                  //11-02-14|0x004a
#ifndef TestIndex                                                                         //11-02-14|0x0054
#define TestIndex 0                                                                       //11-02-14|0x0054
#endif                                                                                    //11-02-14|0x0054
//------------------------------------------------------------------------                //11-02-14|0x0054
enum {  report_open_1 = TestIndex };                                                      //11-02-14|0x0054
//------------------------------------------------------------------------                //11-02-14|0x0054
#undef TestIndex                                                                          //11-02-14|0x0054
#define TestIndex report_open_1+1                                                         //11-02-14|0x0054
//************************************************************************                //11-02-14|0x0054
#ifndef TestIndex                                                                         //11-02-15|0x008d
#define TestIndex 0                                                                       //11-02-15|0x008d
#endif                                                                                    //11-02-15|0x008d
//------------------------------------------------------------------------                //11-02-15|0x008d
enum {  report_write_1 = TestIndex };                                                     //11-02-15|0x008d
//------------------------------------------------------------------------                //11-02-15|0x008d
#undef TestIndex                                                                          //11-02-15|0x008d
#define TestIndex report_write_1+1                                                        //11-02-15|0x008d
//************************************************************************                //11-02-15|0x008d
#ifndef TestIndex                                                                         //11-02-15|0x00b7
#define TestIndex 0                                                                       //11-02-15|0x00b7
#endif                                                                                    //11-02-15|0x00b7
//------------------------------------------------------------------------                //11-02-15|0x00b7
enum {  report_crlf_1 = TestIndex };                                                      //11-02-15|0x00b7
//------------------------------------------------------------------------                //11-02-15|0x00b7
#undef TestIndex                                                                          //11-02-15|0x00b7
#define TestIndex report_crlf_1+1                                                         //11-02-15|0x00b7
//************************************************************************                //11-02-15|0x00b7
#ifndef TestIndex                                                                         //11-02-17|0x00d6
#define TestIndex 0                                                                       //11-02-17|0x00d6
#endif                                                                                    //11-02-17|0x00d6
//------------------------------------------------------------------------                //11-02-17|0x00d6
enum {  report_close_1 = TestIndex };                                                     //11-02-17|0x00d6
//------------------------------------------------------------------------                //11-02-17|0x00d6
#undef TestIndex                                                                          //11-02-17|0x00d6
#define TestIndex report_close_1+1                                                        //11-02-17|0x00d6
//************************************************************************                //11-02-17|0x00d6
#ifndef TestIndex                                                                         //11-02-18|0x00ee
#define TestIndex 0                                                                       //11-02-18|0x00ee
#endif                                                                                    //11-02-18|0x00ee
//------------------------------------------------------------------------                //11-02-18|0x00ee
enum {  report_delete_1 = TestIndex };                                                    //11-02-18|0x00ee
//------------------------------------------------------------------------                //11-02-18|0x00ee
#undef TestIndex                                                                          //11-02-18|0x00ee
#define TestIndex report_delete_1+1                                                       //11-02-18|0x00ee
//************************************************************************                //11-02-18|0x00ee
//*******************************************************************************         //05-24-97|0x010f
//*******************************************************************************         //05-24-97|0x010f
//****                       END OF FILE                                     ****         //05-24-97|0x010f
//*******************************************************************************         //05-24-97|0x010f
//*******************************************************************************         //05-24-97|0x010f
#endif                                                                                    //05-24-97|0x010f
