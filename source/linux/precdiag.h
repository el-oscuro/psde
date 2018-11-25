//*****************************************************************************           //04-01-97|0x001e
//*****************************************************************************           //04-01-97|0x001e
//                                                                                        //04-01-97|0x001e
// PRECEDENCE DIAGNOSTIC MANAGER                                                          //04-01-97|0x001e
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
#ifndef precdiag_h                                                                        //06-08-23|0x0021
#define precdiag_h                                                                        //06-08-23|0x0021
//*******************************************************************************         //10-29-97|0x0049
//*******************************************************************************         //10-29-97|0x0049
// CLASS PRECDIAG DEFINITION                                                              //04-09-24|0x0049
//*******************************************************************************         //10-29-97|0x0049
//*******************************************************************************         //10-29-97|0x0049
class PRECDIAG {                                                                          //04-09-24|0x0049
//*******************************************************************************         //10-29-97|0x0049
//*******************************************************************************         //10-29-97|0x0049
// CLASS PRECDIAG DEFINITION                                                              //04-09-24|0x0049
//*******************************************************************************         //10-29-97|0x0049
//*******************************************************************************         //10-29-97|0x0049
    private:                                                                              //10-27-97|0x0051
      SCHAR base_name[_MAX_PATH];                                                         //10-27-97|0x0051
    private:                                                                              //10-27-97|0x0052
      SCHAR error_name[_MAX_PATH];                                                        //10-27-97|0x0052
    private:                                                                              //10-27-97|0x0053
      SCHAR test_name[_MAX_PATH];                                                         //10-27-97|0x0053
    private:                                                                              //10-27-97|0x0054
      SCHAR report_name[_MAX_PATH];                                                       //10-27-97|0x0054
    private:                                                                              //10-27-97|0x0055
      SLONG test_read_position;                                                           //10-27-97|0x0055
    private:                                                                              //10-27-97|0x0056
      SLONG test_write_position;                                                          //10-27-97|0x0056
    public:                                                                               //04-09-24|0x0059
      void diagnostic_file_names(SCHAR_FAR);                                              //04-09-24|0x0059
#define DiagnosticFileNames prec_diag.diagnostic_file_names                               //04-09-24|0x005a
    public:                                                                               //07-10-29|0x007f
      ULONG executable_date(void);                                                        //07-10-29|0x007f
#define PcgExecutableDate prec_diag.executable_date                                       //07-10-29|0x0080
    public:                                                                               //04-08-23|0x0094
      void pcg_system_error(SCHAR_FAR,SWORD);                                             //04-08-23|0x0094
#define PcgSystemError prec_diag.pcg_system_error                                         //04-08-23|0x0095
    public:                                                                               //04-10-05|0x00ad
      UINT basic_test_reset(void);                                                        //04-10-05|0x00ad
#define BasicTestReset prec_diag.basic_test_reset                                         //04-10-05|0x00ae
    public:                                                                               //04-09-27|0x00c2
      UINT basic_test_read(UINT_FAR,UINT);                                                //04-09-27|0x00c2
#define BasicTestRead prec_diag.basic_test_read                                           //04-09-27|0x00c3
    public:                                                                               //04-09-27|0x00ed
      UINT basic_test_write(UINT_FAR);                                                    //04-09-27|0x00ed
#define BasicTestWrite prec_diag.basic_test_write                                         //04-09-27|0x00ee
    public:                                                                               //04-09-27|0x010e
      UINT basic_test_report(UINT_FAR,SCHAR_FAR);                                         //04-09-27|0x010e
#define BasicTestReport prec_diag.basic_test_report                                       //04-09-27|0x010f
    public:                                                                               //07-10-29|0x0147
      UINT finish(SCHAR_FAR);                                                             //07-10-29|0x0147
#define Finish prec_diag.finish                                                           //03-29-79|0x0148
    public:                                                                               //08-02-11|0x0166
      UINT intervention_menu(void);                                                       //08-02-11|0x0166
#define InterventionMenu prec_diag.intervention_menu                                      //08-02-11|0x0167
    public:                                                                               //07-02-19|0x0188
      UINT checkout_menu(SCHAR_FAR);                                                      //07-02-19|0x0188
#define CheckoutMenu prec_diag.checkout_menu                                              //07-02-19|0x018a
    public:                                                                               //check   |0x01ab
      UINT trunc_sint_int(SINT_FAR,SWORD);                                                //check   |0x01ab
#define TruncSintInt prec_diag.trunc_sint_int                                             //check   |0x01ad
    public:                                                                               //check   |0x01c8
      UINT trunc_string_size(SINT_FAR,SCHAR_FAR);                                         //check   |0x01c8
#define TruncStringSize prec_diag.trunc_string_size                                       //check   |0x01ca
  };                                                                                      //10-29-97|0x01d8
extern class PRECDIAG prec_diag;                                                          //98-12-29|0x01d8
//*******************************************************************************         //05-24-97|0x01d9
//*******************************************************************************         //05-24-97|0x01d9
//****                       END OF FILE                                     ****         //05-24-97|0x01d9
//*******************************************************************************         //05-24-97|0x01d9
//*******************************************************************************         //05-24-97|0x01d9
#endif                                                                                    //05-24-97|0x01d9
