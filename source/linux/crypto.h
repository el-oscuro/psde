//*****************************************************************************           //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//                                                                                        //10-03-22|0x000b
// CRYPTOGRAPHIC RESOURCES                                                                //10-03-22|0x000b
//                                                                                        //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//  Copyright: 2006 Robert H. Adams                                                       //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//  The purpose of this program as well as instructions regarding its use is              //10-03-22|0x000b
//  defined in the associated manual.                                                     //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//  This program is free software; you can redistribute it and/or modify                  //10-03-22|0x000b
//  it under the terms of the GNU General Public License as published by                  //10-03-22|0x000b
//  the Free Software Foundation; either version 2 of the License, or                     //10-03-22|0x000b
//  (at your option) any later version.                                                   //10-03-22|0x000b
//                                                                                        //10-03-22|0x000b
//  This program is distributed in the hope that it will be useful,                       //10-03-22|0x000b
//  but WITHOUT ANY WARRANTY; without even the implied warranty of                        //10-03-22|0x000b
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         //10-03-22|0x000b
//  GNU General Public License for more details.                                          //10-03-22|0x000b
//                                                                                        //10-03-22|0x000b
//  You should have received a copy of the GNU General Public License                     //10-03-22|0x000b
//  along with this program; if not, write to the Free Software                           //10-03-22|0x000b
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA., 02110-1301            //10-03-22|0x000b
//  USA                                                                                   //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//  For further information, please contact Robert Adams:                                 //10-03-22|0x000b
//     EMail:    robert.adams@whatifwe.com                                                //10-03-22|0x000b
//     Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA                              //10-03-22|0x000b
//  Or visit the website, "www.whatifwe.com".                                             //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
//*****************************************************************************           //10-03-22|0x000b
#ifndef crypto_h                                                                          //10-03-22|0x000c
#define crypto_h                                                                          //10-03-22|0x000c
//***************************************************************************             //10-03-22|0x0027
//***************************************************************************             //10-03-22|0x0028
//******                                                               ******             //10-03-22|0x0029
//******               REQUIRED TYPEDEF STATEMENTS                     ******             //10-03-22|0x002a
//******                                                               ******             //10-03-22|0x002b
//***************************************************************************             //10-03-22|0x002c
//***************************************************************************             //10-03-22|0x002d
//*****************************************************************************           //10-03-22|0x002e
#ifndef FILE_CONTROL_Defined                                                              //10-03-22|0x002e
#define FILE_CONTROL_Defined                                                              //10-03-22|0x002e
//-----------------------------------------------------------------------------           //10-03-22|0x002e
typedef struct {                                                                          //10-03-22|0x002e
  UINT    state;                                                                          //10-03-22|0x002e
  SCHAR   name[_MAX_PATH+1];                                                              //10-03-22|0x002e
  FILE *  stream;                                                                         //10-03-22|0x002e
  } FILE_CONTROL, * FILE_CONTROL_FAR;                                                     //10-03-22|0x002e
//-----------------------------------------------------------------------------           //10-03-22|0x002e
#endif                                                                                    //10-03-22|0x002e
//*******************************************************************************         //10-03-22|0x002f
#ifndef BINARY_FILE_DATA_Defined                                                          //10-03-22|0x002f
#define BINARY_FILE_DATA_Defined                                                          //10-03-22|0x002f
//-------------------------------------------------------------------------------         //10-03-22|0x002f
typedef struct {                                                                          //10-03-22|0x002f
  FILE_CONTROL    file_control;                                                           //10-03-22|0x002f
  SLONG           file_position;                                                          //10-03-22|0x002f
  SLONG           file_length;                                                            //10-03-22|0x002f
  } BINARY_FILE_DATA, * BINARY_FILE_DATA_FAR;                                             //10-03-22|0x002f
//-------------------------------------------------------------------------------         //10-03-22|0x002f
#endif                                                                                    //10-03-22|0x002f
//***************************************************************************             //10-03-22|0x0030
//*******************************************************************************         //10-03-22|0x0031
#ifndef STRING_DATA_Defined                                                               //10-03-22|0x0031
#define STRING_DATA_Defined                                                               //10-03-22|0x0031
//-------------------------------------------------------------------------------         //10-03-22|0x0031
typedef struct {                                                                          //10-03-22|0x0031
  SCHAR   line[257];                                                                      //10-03-22|0x0031
  UINT    macro_line_no;                                                                  //10-03-22|0x0031
  UINT    type;                                                                           //10-03-22|0x0031
  UINT    start_col;                                                                      //10-03-22|0x0031
  UINT    start_call;                                                                     //10-03-22|0x0031
  SINT    length;                                                                         //10-03-22|0x0031
  SINT    position;                                                                       //10-03-22|0x0031
  SINT    column;                                                                         //10-03-22|0x0031
  } STRING_DATA, * STRING_DATA_FAR;                                                       //10-03-22|0x0031
//-------------------------------------------------------------------------------         //10-03-22|0x0031
#endif                                                                                    //10-03-22|0x0031
//*******************************************************************************         //10-03-22|0x0032
#ifndef TOKENS_Defined                                                                    //10-03-22|0x0032
#define TOKENS_Defined                                                                    //10-03-22|0x0032
//-------------------------------------------------------------------------------         //10-03-22|0x0032
typedef struct {                                                                          //10-03-22|0x0032
  UINT        no_tokens;                                                                  //10-03-22|0x0032
  STRING_DATA token[10];                                                                  //10-03-22|0x0032
  } TOKENS, * TOKENS_FAR;                                                                 //10-03-22|0x0032
//-------------------------------------------------------------------------------         //10-03-22|0x0032
#endif                                                                                    //10-03-22|0x0032
//***************************************************************************             //10-03-22|0x0033
//*****************************************************************************           //10-03-22|0x0034
#ifndef CRYPTO_DATA_Defined                                                               //10-03-22|0x0034
#define CRYPTO_DATA_Defined                                                               //10-03-22|0x0034
//-----------------------------------------------------------------------------           //10-03-22|0x0034
typedef struct {                                                                          //10-03-22|0x0034
  ULONG             position;                                                             //10-03-22|0x0034
  UCHAR             random_data[127];                                                     //10-03-22|0x0034
  SINT              bit0_index;                                                           //10-03-22|0x0034
  SINT              bit127_index;                                                         //10-03-22|0x0034
  SINT              load_index;                                                           //10-03-22|0x0034
  SINT              rotator;                                                              //10-03-22|0x0034
  UCHAR             parity;                                                               //10-03-22|0x0034
  UINT              data_state;                                                           //10-03-22|0x0034
  SINT              index;                                                                //10-03-22|0x0034
  UCHAR             chain;                                                                //10-03-22|0x0034
  UCHAR             code_ring;                                                            //10-03-22|0x0034
  } CRYPTO_DATA, * CRYPTO_DATA_FAR;                                                       //10-03-22|0x0034
//-----------------------------------------------------------------------------           //10-03-22|0x0034
#endif                                                                                    //10-03-22|0x0034
//*****************************************************************************           //15-06-16|0x0035
#ifndef CRYPTO_CONTROL_Defined                                                            //15-06-16|0x0035
#define CRYPTO_CONTROL_Defined                                                            //15-06-16|0x0035
typedef struct {                                                                          //15-06-16|0x0035
  CRYPTO_DATA       crypto_data;                                                          //15-06-16|0x0035
  BINARY_FILE_DATA  file;                                                                 //15-06-16|0x0035
  ULONG             size;                                                                 //15-06-16|0x0035
  SINT              index;                                                                //15-06-16|0x0035
  SINT              no_generators;                                                        //15-06-16|0x0035
  UINT              class_state;                                                          //15-06-16|0x0035
  } CRYPTO_CONTROL, * CRYPTO_CONTROL_FAR;                                                 //15-06-16|0x0035
//-----------------------------------------------------------------------------           //15-06-16|0x0035
#endif                                                                                    //15-06-16|0x0035
//*******************************************************************************         //10-29-97|0x003d
//*******************************************************************************         //10-29-97|0x003d
// CLASS CRYPTO DEFINITION                                                                //10-03-22|0x003d
//*******************************************************************************         //10-29-97|0x003d
//*******************************************************************************         //10-29-97|0x003d
class CRYPTO {                                                                            //10-03-22|0x003d
//*******************************************************************************         //10-29-97|0x003d
//*******************************************************************************         //10-29-97|0x003d
// CLASS CRYPTO DEFINITION                                                                //10-03-22|0x003d
//*******************************************************************************         //10-29-97|0x003d
//*******************************************************************************         //10-29-97|0x003d
    private:                                                                              //10-27-97|0x0045
      CRYPTO_CONTROL_FAR crypto_addr;                                                     //10-27-97|0x0045
    public:                                                                               //10-03-22|0x0076
      UINT crypto_allocate(void);                                                         //10-03-22|0x0076
#define CryptoAllocate crypto_resource.crypto_allocate                                    //10-03-22|0x0077
    public:                                                                               //10-03-22|0x008e
      UINT crypto_free(void);                                                             //10-03-22|0x008e
#define CryptoFree crypto_resource.crypto_free                                            //10-03-22|0x008f
    public:                                                                               //10-03-22|0x00a7
      UINT crypto_initial(SCHAR_FAR,SCHAR_FAR);                                           //10-03-22|0x00a7
#define CryptoInitial crypto_resource.crypto_initial                                      //10-03-22|0x00a9
    public:                                                                               //15-06-16|0x00d2
      void basic_random_create(CRYPTO_DATA_FAR);                                          //15-06-16|0x00d2
#define BasicRandomCreate crypto_resource.basic_random_create                             //15-06-16|0x00d3
    public:                                                                               //10-03-22|0x00e6
      UINT crypto_create(UINT_FAR);                                                       //10-03-22|0x00e6
#define CryptoCreate crypto_resource.crypto_create                                        //10-03-22|0x00e7
    public:                                                                               //10-03-23|0x011c
      UINT crypto_reset(UINT);                                                            //10-03-23|0x011c
#define CryptoReset crypto_resource.crypto_reset                                          //10-03-23|0x011d
    public:                                                                               //10-03-22|0x014f
      UINT crypto_open(UINT);                                                             //10-03-22|0x014f
#define CryptoOpen crypto_resource.crypto_open                                            //10-03-22|0x0150
    public:                                                                               //10-03-22|0x0179
      UINT crypto_close(void);                                                            //10-03-22|0x0179
#define CryptoClose crypto_resource.crypto_close                                          //10-03-22|0x017a
    public:                                                                               //15-06-16|0x019e
      UINT basic_random_load(CRYPTO_DATA_FAR,STRING_DATA_FAR);                            //15-06-16|0x019e
#define BasicRandomLoad crypto_resource.basic_random_load                                 //15-06-16|0x01a0
    public:                                                                               //10-03-22|0x01b2
      UINT crypto_load(STRING_DATA_FAR);                                                  //10-03-22|0x01b2
#define CryptoLoad crypto_resource.crypto_load                                            //10-03-22|0x01b4
    public:                                                                               //15-06-16|0x01dc
      UINT basic_get_random(UCHAR_FAR,CRYPTO_DATA_FAR);                                   //15-06-16|0x01dc
#define BasicGetRandom crypto_resource.basic_get_random                                   //15-06-16|0x01de
    public:                                                                               //10-03-23|0x01ff
      UINT crypto_get_random(STRING_DATA_FAR,UINT);                                       //10-03-23|0x01ff
#define CryptoGetRandom crypto_resource.crypto_get_random                                 //10-03-23|0x0201
    public:                                                                               //10-03-23|0x0265
      UINT crypto_compute_parity(STRING_DATA_FAR);                                        //10-03-23|0x0265
#define CryptoComputeParity crypto_resource.crypto_compute_parity                         //10-03-23|0x0267
    public:                                                                               //10-03-23|0x02ac
      UINT crypto_get_parity(UCHAR_FAR);                                                  //10-03-23|0x02ac
#define CryptoGetParity crypto_resource.crypto_get_parity                                 //10-03-23|0x02ae
    public:                                                                               //10-03-23|0x02e1
      UINT crypto_encrypt(STRING_DATA_FAR,STRING_DATA_FAR);                               //10-03-23|0x02e1
#define CryptoEncrypt crypto_resource.crypto_encrypt                                      //10-03-23|0x02e3
    public:                                                                               //10-03-23|0x0345
      UINT crypto_decrypt(STRING_DATA_FAR,STRING_DATA_FAR);                               //10-03-23|0x0345
#define CryptoDecrypt crypto_resource.crypto_decrypt                                      //10-03-23|0x0347
    public:                                                                               //10-03-22|0x03a7
      UINT crypto_delete(void);                                                           //10-03-22|0x03a7
#define CryptoDelete crypto_resource.crypto_delete                                        //10-03-22|0x03a8
    private:                                                                              //15-06-16|0x03c1
      void initial_random(CRYPTO_DATA_FAR);                                               //15-06-16|0x03c1
    private:                                                                              //15-06-16|0x03dd
      UINT load_random(CRYPTO_DATA_FAR,STRING_DATA_FAR);                                  //15-06-16|0x03dd
    private:                                                                              //15-06-16|0x041b
      UCHAR random_generator(CRYPTO_DATA_FAR);                                            //15-06-16|0x041b
    private:                                                                              //10-03-23|0x043b
      UINT crypto_read(SINT);                                                             //10-03-23|0x043b
    private:                                                                              //10-03-22|0x0466
      UINT crypto_write(SINT);                                                            //10-03-22|0x0466
    public:                                                                               //10-03-22|0x0481
      UINT crypto_test_reset(void);                                                       //10-03-22|0x0481
#define CryptoTestReset crypto_resource.crypto_test_reset                                 //10-03-22|0x0481
    public:                                                                               //10-03-22|0x0483
      UINT crypto_test_read(void);                                                        //10-03-22|0x0483
#define CryptoTestRead crypto_resource.crypto_test_read                                   //10-03-22|0x0483
    public:                                                                               //10-03-22|0x0485
      UINT crypto_test_write(void);                                                       //10-03-22|0x0485
#define CryptoTestWrite crypto_resource.crypto_test_write                                 //10-03-22|0x0485
    public:                                                                               //10-03-22|0x0487
      UINT crypto_test_report(void);                                                      //10-03-22|0x0487
#define CryptoTestReport crypto_resource.crypto_test_report                               //10-03-22|0x0487
    public:                                                                               //10-03-22|0x0491
      CRYPTO();                                                                           //10-03-22|0x0491
  };                                                                                      //10-29-97|0x0499
extern class CRYPTO crypto_resource;                                                      //98-12-29|0x0499
//*******************************************************************************         //05-24-97|0x049a
//*******************************************************************************         //05-24-97|0x049a
//****                       END OF FILE                                     ****         //05-24-97|0x049a
//*******************************************************************************         //05-24-97|0x049a
//*******************************************************************************         //05-24-97|0x049a
#endif                                                                                    //05-24-97|0x049a
