//*****************************************************************************           //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
// MACRO VERSION MANAGER                                                                  //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  The purpose of this program as well as instructions regarding its use is              //11-02-12|0x000b
//  defined in the associated manual.                                                     //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  This program is free software; you can redistribute it and/or modify                  //11-02-12|0x000b
//  it under the terms of the GNU General Public License as published by                  //11-02-12|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //11-02-12|0x000b
//  (at your option) any later version.                                                   //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
//  This program is distributed in the hope that it will be useful,                       //11-02-12|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //11-02-12|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //11-02-12|0x000b
//  GNU General Public License for more details.                                          //11-02-12|0x000b
//                                                                                        //11-02-12|0x000b
//  You should have received a copy of the GNU General Public License                     //11-02-12|0x000b
//  along with this program; if not, write to the Free Software                           //11-02-12|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //11-02-12|0x000b
//  USA                                                                                   //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//  For further information, please contact Robert Adams:                                 //11-02-12|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //11-02-12|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //11-02-12|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
//*****************************************************************************           //11-02-12|0x000b
#ifndef maccert_h                                                                         //11-02-12|0x000c
#define maccert_h                                                                         //11-02-12|0x000c
//***************************************************************************             //11-02-12|0x0028
//***************************************************************************             //11-02-12|0x0029
//******                                                               ******             //11-02-12|0x002a
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //11-02-12|0x002b
//******                                                               ******             //11-02-12|0x002c
//***************************************************************************             //11-02-12|0x002d
//***************************************************************************             //11-02-12|0x002e
//*******************************************************************************         //11-02-12|0x002f
#ifndef STRING_DATA_Defined                                                               //11-02-12|0x002f
#define STRING_DATA_Defined                                                               //11-02-12|0x002f
//-------------------------------------------------------------------------------         //11-02-12|0x002f
typedef struct {                                                                          //11-02-12|0x002f
  SCHAR   line[257];                                                                      //11-02-12|0x002f
  UINT    macro_line_no;                                                                  //11-02-12|0x002f
  UINT    type;                                                                           //11-02-12|0x002f
  UINT    start_col;                                                                      //11-02-12|0x002f
  UINT    start_call;                                                                     //11-02-12|0x002f
  SINT    length;                                                                         //11-02-12|0x002f
  SINT    position;                                                                       //11-02-12|0x002f
  SINT    column;                                                                         //11-02-12|0x002f
  } STRING_DATA, * STRING_DATA_FAR;                                                       //11-02-12|0x002f
//-------------------------------------------------------------------------------         //11-02-12|0x002f
#endif                                                                                    //11-02-12|0x002f
//*******************************************************************************         //11-02-12|0x0030
#ifndef TOKENS_Defined                                                                    //11-02-12|0x0030
#define TOKENS_Defined                                                                    //11-02-12|0x0030
//-------------------------------------------------------------------------------         //11-02-12|0x0030
typedef struct {                                                                          //11-02-12|0x0030
  UINT        no_tokens;                                                                  //11-02-12|0x0030
  STRING_DATA token[10];                                                                  //11-02-12|0x0030
  } TOKENS, * TOKENS_FAR;                                                                 //11-02-12|0x0030
//-------------------------------------------------------------------------------         //11-02-12|0x0030
#endif                                                                                    //11-02-12|0x0030
#ifndef MACRO_CERTIFY_Defined                                                             //11-02-12|0x0031
#define MACRO_CERTIFY_Defined                                                             //11-02-12|0x0031
//-----------------------------------------------------------------------------           //11-02-12|0x0031
typedef struct {                                                                          //11-02-12|0x0031
  STRING_DATA     append;                                                                 //11-02-12|0x0031
  STRING_DATA     previous;                                                               //11-02-12|0x0031
  STRING_DATA     current;                                                                //11-02-12|0x0031
  ULONG           current_time;                                                           //11-02-12|0x0031
  UINT            base_random;                                                            //11-02-12|0x0031
  UINT            global_random;                                                          //11-02-12|0x0031
  UINT            current_random;                                                         //11-02-12|0x0031
  UINT            no_appends;                                                             //11-02-12|0x0031
  UINT            no_macros;                                                              //11-02-12|0x0031
  UINT            no_commands;                                                            //11-02-12|0x0031
  UINT            no_todays;                                                              //11-02-12|0x0031
  UINT            no_arrows;                                                              //11-02-12|0x0031
  } MACRO_CERTIFY, * MACRO_CERTIFY_FAR;                                                   //11-02-12|0x0031
//-----------------------------------------------------------------------------           //11-02-12|0x0031
#endif                                                                                    //11-02-12|0x0031
//*******************************************************************************         //10-29-97|0x0039
//*******************************************************************************         //10-29-97|0x0039
// CLASS MAC_CERT DEFINITION                                                              //11-02-12|0x0039
//*******************************************************************************         //10-29-97|0x0039
//*******************************************************************************         //10-29-97|0x0039
class MAC_CERT {                                                                          //11-02-12|0x0039
//*******************************************************************************         //10-29-97|0x0039
//*******************************************************************************         //10-29-97|0x0039
// CLASS MAC_CERT DEFINITION                                                              //11-02-12|0x0039
//*******************************************************************************         //10-29-97|0x0039
//*******************************************************************************         //10-29-97|0x0039
    private:                                                                              //10-27-97|0x0041
      MACRO_CERTIFY mac_cert_data;                                                        //10-27-97|0x0041
    public:                                                                               //11-02-19|0x005e
      UINT mac_cert_create(STRING_DATA_FAR);                                              //11-02-19|0x005e
#define MacCertCreate mac_cert.mac_cert_create                                            //11-02-19|0x0060
    public:                                                                               //11-02-12|0x0075
      UINT mac_cert_initial(STRING_DATA_FAR);                                             //11-02-12|0x0075
#define MacCertInitial mac_cert.mac_cert_initial                                          //11-02-12|0x0077
    public:                                                                               //11-02-14|0x009c
      UINT mac_cert_delete(void);                                                         //11-02-14|0x009c
#define MacCertDelete mac_cert.mac_cert_delete                                            //11-02-14|0x009d
    public:                                                                               //11-02-19|0x00b3
      UINT mac_cert_get_prev(void);                                                       //11-02-19|0x00b3
#define MacCertGetPrev mac_cert.mac_cert_get_prev                                         //11-02-19|0x00b4
    public:                                                                               //11-02-22|0x00cc
      UINT mac_cert_append(UINT);                                                         //11-02-22|0x00cc
#define MacCertAppend mac_cert.mac_cert_append                                            //11-02-22|0x00ce
    public:                                                                               //11-02-13|0x010c
      UINT mac_cert_macro_begin(void);                                                    //11-02-13|0x010c
#define MacCertMacroBegin mac_cert.mac_cert_macro_begin                                   //11-02-13|0x010e
    public:                                                                               //11-02-15|0x0138
      UINT mac_cert_parity_command(TOKENS_FAR);                                           //11-02-15|0x0138
#define MacCertParityCommand mac_cert.mac_cert_parity_command                             //11-02-15|0x013a
    public:                                                                               //11-02-18|0x015d
      UINT mac_cert_parity_arrow(void);                                                   //11-02-18|0x015d
#define MacCertParityArrow mac_cert.mac_cert_parity_arrow                                 //11-02-18|0x015e
    public:                                                                               //11-02-15|0x0181
      UINT mac_cert_parity_time(ULONG);                                                   //11-02-15|0x0181
#define MacCertParityTime mac_cert.mac_cert_parity_time                                   //11-02-15|0x0183
    public:                                                                               //11-02-15|0x01b5
      void mac_cert_report(UINT_FAR,UINT_FAR,UINT_FAR);                                   //11-02-15|0x01b5
#define MacCertReport mac_cert.mac_cert_report                                            //11-02-15|0x01b7
    public:                                                                               //11-02-17|0x01d3
      UINT mac_cert_end(void);                                                            //11-02-17|0x01d3
#define MacCertEnd mac_cert.mac_cert_end                                                  //11-02-17|0x01d4
    public:                                                                               //11-02-14|0x01fb
      UINT mac_cert_finish(UINT);                                                         //11-02-14|0x01fb
#define MacCertFinish mac_cert.mac_cert_finish                                            //11-02-14|0x01fd
    private:                                                                              //11-02-25|0x023a
      UINT prepare_string(UCHAR,UINT);                                                    //11-02-25|0x023a
    private:                                                                              //11-02-25|0x0265
      UINT read_parity(UCHAR_FAR,STRING_DATA_FAR);                                        //11-02-25|0x0265
    private:                                                                              //11-02-26|0x0291
      UINT read_version(UINT_FAR,STRING_DATA_FAR);                                        //11-02-26|0x0291
    public:                                                                               //11-02-14|0x02b5
      MAC_CERT();                                                                         //11-02-14|0x02b5
  };                                                                                      //10-29-97|0x02bf
extern class MAC_CERT mac_cert;                                                           //98-12-29|0x02bf
//*******************************************************************************         //05-24-97|0x02c0
//*******************************************************************************         //05-24-97|0x02c0
//****                       END OF FILE                                     ****         //05-24-97|0x02c0
//*******************************************************************************         //05-24-97|0x02c0
//*******************************************************************************         //05-24-97|0x02c0
#endif                                                                                    //05-24-97|0x02c0
