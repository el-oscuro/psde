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
#ifndef crypto_hpp                                                                        //10-03-22|0x000c
#define crypto_hpp                                                                        //10-03-22|0x000c
//***************************************************************************             //10-03-22|0x0011
//***************************************************************************             //10-03-22|0x0012
//******                                                               ******             //10-03-22|0x0013
//******                   SYSTEM SPECIFIC DEFINITIONS                 ******             //10-03-22|0x0014
//******                                                               ******             //10-03-22|0x0015
//***************************************************************************             //10-03-22|0x0016
//***************************************************************************             //10-03-22|0x0017
#define CMK_EXTENT ".cmk"                                                                 //10-03-22|0x001a
#define TMK_EXTENT ".tmk"                                                                 //10-03-22|0x001a
#define RPT_EXTENT ".rpt"                                                                 //10-03-22|0x001a
#define PMK_EXTENT ".pmk"                                                                 //10-03-22|0x001a
#define MAC_EXTENT ".mac"                                                                 //10-03-22|0x001a
#define SRC_EXTENT ".src"                                                                 //10-03-22|0x001a
#define PLB_EXTENT ".plb"                                                                 //10-03-22|0x001a
#define DIC_EXTENT ".dic"                                                                 //10-03-22|0x001a
#define MBX_EXTENT ".mbx"                                                                 //10-03-22|0x001a
#define MBC_EXTENT ".mbc"                                                                 //10-03-22|0x001a
#define RAN_EXTENT ".ran"                                                                 //10-03-22|0x001a
#define BUF_OUT_EXTENT ".bfo"                                                             //10-03-22|0x001a
#define BUF_IN_EXTENT ".bfi"                                                              //10-03-22|0x001a
//***************************************************************************             //10-03-22|0x001b
//***************************************************************************             //10-03-22|0x001c
//******                                                               ******             //10-03-22|0x001d
//******               ERROR HANDLING SPECIFIC DEFINITIONS             ******             //10-03-22|0x001e
//******                                                               ******             //10-03-22|0x001f
//***************************************************************************             //10-03-22|0x0020
//***************************************************************************             //10-03-22|0x0021
#define UserError 0x0000                                                                  //10-03-22|0x0022
#define BuildError 0x7fff                                                                 //10-03-22|0x0022
#define Display 0x7ffe                                                                    //10-03-22|0x0022
#define KeyBoard 0x7ffd                                                                   //10-03-22|0x0022
#define Success 0xffff                                                                    //10-03-22|0x0022
#define SystemError 0x8000                                                                //10-03-22|0x0022
#define Continue 0x0001                                                                   //10-03-22|0x0022
#define FileDone 0x0002                                                                   //10-03-22|0x0022
#define LineDone 0x0003                                                                   //10-03-22|0x0022
#define Yes 0x0004                                                                        //10-03-22|0x0022
#define No 0x0005                                                                         //10-03-22|0x0022
#define RepeatChar '\x6'                                                                  //10-03-22|0x0022
#define Great 0x0007                                                                      //10-03-22|0x0022
#define Equal 0x0008                                                                      //10-03-22|0x0022
#define Less 0x0009                                                                       //10-03-22|0x0022
#define Zero 0x000a                                                                       //10-03-22|0x0022
#define Minus 0x000b                                                                      //10-03-22|0x0022
//***************************************************************************             //10-03-22|0x0023
#define SystemMsg PcgSystemError("crypto", __LINE__);                                     //10-03-22|0x0024
#define ReturnSystemError { SystemMsg; return(SystemError); }                             //10-03-22|0x0024
#define ReturnSystemAddrError { SystemMsg; return(0); }                                   //10-03-22|0x0024
#define BreakFinish(_a) status = Finish(_a); break                                        //10-03-22|0x0025
#define ReturnFinish(_a) return(Finish(_a))                                               //10-03-22|0x0025
#define ReturnFinishBuild(_a) { Finish(_a);  return(BuildError); }                        //10-03-22|0x0025
#define ReturnFinishAddr(_a) { Finish(_a);  return(0L); }                                 //10-03-22|0x0025
#define _SwitchErr case UserError: return(UserError)                                      //10-03-22|0x0026
#define _SwitchOk case Success: break                                                     //10-03-22|0x0026
#define _SwitchEnd default: ReturnSystemError                                             //10-03-22|0x0026
#define _SwitchBase _SwitchOk; _SwitchErr; _SwitchEnd                                     //10-03-22|0x0026
#define _SwitchYes case Yes:      return(Yes)                                             //10-03-22|0x0026
#define _SwitchNo case No:       return(No)                                               //10-03-22|0x0026
#define _SwitchGroup { _SwitchBase; }                                                     //10-03-22|0x0026
#define _SwitchGotoLoop _SwitchGroup goto loop                                            //10-03-22|0x0026
#define _SwitchReturn _SwitchGroup return(Success)                                        //10-03-22|0x0026
#define _SwitchBreak _SwitchGroup break                                                   //10-03-22|0x0026
#define _SwitchYesNo { _SwitchYes; _SwitchNo; _SwitchErr; _SwitchEnd; }                   //10-03-22|0x0026
//***************************************************************************             //10-03-22|0x0046
//***************************************************************************             //10-03-22|0x0047
//******                                                               ******             //10-03-22|0x0048
//******               GENERAL DEFINITION STATEMENTS                   ******             //10-03-22|0x0049
//******                                                               ******             //10-03-22|0x004a
//***************************************************************************             //10-03-22|0x004b
//***************************************************************************             //10-03-22|0x004c
#define TestSample(i) test_samples[i] = __LINE__                                          //10-03-22|0x004d
#define return_test(j) { TestSample(j);  return(Success); }                               //10-03-22|0x004d
#define return_yes(j) { TestSample(j);  return(Yes); }                                    //10-03-22|0x004d
#define return_no(j) { TestSample(j);  return(No); }                                      //10-03-22|0x004d
#define return_cont(j) { TestSample(j);  return(Continue); }                              //10-03-22|0x004d
#define return_line(j) { TestSample(j);  return(LineDone); }                              //10-03-22|0x004d
#define goto_test(i) { TestSample(i);  goto loop; }                                       //10-03-22|0x004d
#define break_test(i) { TestSample(i);  break; }                                          //10-03-22|0x004d
#define ReturnUserError(i) { TestSample(i);  return(UserError); }                         //10-03-22|0x004d
#define return_state(i,j) { TestSample(i);  state = j;   return(Success); }               //10-03-22|0x004d
//************************************************************************                //10-03-22|0x004d
#ifndef TestIndex                                                                         //10-03-22|0x004d
#define TestIndex 0                                                                       //10-03-22|0x004d
#endif                                                                                    //10-03-22|0x004d
//------------------------------------------------------------------------                //10-03-22|0x004d
enum {  NoTestSamples = TestIndex };                                                      //10-03-22|0x004d
//------------------------------------------------------------------------                //10-03-22|0x004d
#undef TestIndex                                                                          //10-03-22|0x004d
#define TestIndex NoTestSamples+1                                                         //10-03-22|0x004d
//************************************************************************                //10-03-22|0x004d
//***************************************************************************             //10-03-22|0x004e
//**********************************************************************                  //15-06-16|0x004f
#define ArgPosition ArgFar->position                                                      //15-06-16|0x004f
#define ArgRandomData(i) ArgFar->random_data[i]                                           //15-06-16|0x004f
#define ArgBit0Index ArgFar->bit0_index                                                   //15-06-16|0x004f
#define ArgBit126Index ArgFar->bit127_index                                               //15-06-16|0x004f
#define ArgLoadIndex ArgFar->load_index                                                   //15-06-16|0x004f
#define ArgRotator ArgFar->rotator                                                        //15-06-16|0x004f
#define ArgParity ArgFar->parity                                                          //15-06-16|0x004f
#define ArgDataState ArgFar->data_state                                                   //15-06-16|0x004f
#define ArgDataIndex ArgFar->index                                                        //15-06-16|0x004f
#define ArgChain ArgFar->chain                                                            //15-06-16|0x004f
#define ArgCodeRing ArgFar->code_ring                                                     //15-06-16|0x004f
//**********************************************************************                  //15-06-16|0x0050
#define CryptoPosition crypto_addr->crypto_data.position                                  //15-06-16|0x0050
#define CryptoRandomData(i) crypto_addr->crypto_data.random_data[i]                       //15-06-16|0x0050
#define CryptoBit0Index crypto_addr->crypto_data.bit0_index                               //15-06-16|0x0050
#define CryptoBit126Index crypto_addr->crypto_data.bit127_index                           //15-06-16|0x0050
#define CryptoLoadIndex crypto_addr->crypto_data.load_index                               //15-06-16|0x0050
#define CryptoRotator crypto_addr->crypto_data.rotator                                    //15-06-16|0x0050
#define CryptoParity crypto_addr->crypto_data.parity                                      //15-06-16|0x0050
#define CryptoDataState crypto_addr->crypto_data.data_state                               //15-06-16|0x0050
#define CryptoDataIndex crypto_addr->crypto_data.index                                    //15-06-16|0x0050
#define CryptoChain crypto_addr->crypto_data.chain                                        //15-06-16|0x0050
#define CryptoCodeRing crypto_addr->crypto_data.code_ring                                 //15-06-16|0x0050
//----------------------------------------------------------------------                  //15-06-16|0x0051
#define CryptoDataFar &(crypto_addr->crypto_data)                                         //15-06-16|0x0051
#define CryptoSize crypto_addr->size                                                      //15-06-16|0x0051
#define CryptoClassState crypto_addr->class_state                                         //15-06-16|0x0051
#define CryptoIndex crypto_addr->index                                                    //15-06-16|0x0051
#define CryptoNoGenerators crypto_addr->no_generators                                     //15-06-16|0x0051
//----------------------------------------------------------------------                  //15-06-16|0x0051
#define CryptoDataAddr (SCHAR_FAR) &(crypto_addr->crypto_data)                            //15-06-16|0x0051
#define CryptoFileAddr &(crypto_addr->file)                                               //15-06-16|0x0051
//***************************************************************************             //10-03-22|0x0052
#define AddrChar(i) Addr->line[i]                                                         //10-03-22|0x0053
#define AddrLine Addr->line[0]                                                            //10-03-22|0x0053
#define AddrLineAddr &(Addr->line[0])                                                     //10-03-22|0x0053
#define AddrMacroLineNo Addr->macro_line_no                                               //10-03-22|0x0053
#define AddrType Addr->type                                                               //10-03-22|0x0053
#define AddrStartCol Addr->start_col                                                      //10-03-22|0x0053
#define AddrStartCall Addr->start_call                                                    //10-03-22|0x0053
#define AddrPosition Addr->position                                                       //10-03-22|0x0053
#define AddrLength Addr->length                                                           //10-03-22|0x0053
#define AddrColumn Addr->column                                                           //10-03-22|0x0053
//**********************************************************************                  //10-03-22|0x0053
#define InChar(i) In->line[i]                                                             //10-03-22|0x0054
#define InLine In->line[0]                                                                //10-03-22|0x0054
#define InLineAddr &(In->line[0])                                                         //10-03-22|0x0054
#define InMacroLineNo In->macro_line_no                                                   //10-03-22|0x0054
#define InType In->type                                                                   //10-03-22|0x0054
#define InStartCol In->start_col                                                          //10-03-22|0x0054
#define InStartCall In->start_call                                                        //10-03-22|0x0054
#define InPosition In->position                                                           //10-03-22|0x0054
#define InLength In->length                                                               //10-03-22|0x0054
#define InColumn In->column                                                               //10-03-22|0x0054
//**********************************************************************                  //10-03-22|0x0054
#define OutChar(i) Out->line[i]                                                           //10-03-22|0x0055
#define OutLine Out->line[0]                                                              //10-03-22|0x0055
#define OutLineAddr &(Out->line[0])                                                       //10-03-22|0x0055
#define OutMacroLineNo Out->macro_line_no                                                 //10-03-22|0x0055
#define OutType Out->type                                                                 //10-03-22|0x0055
#define OutStartCol Out->start_col                                                        //10-03-22|0x0055
#define OutStartCall Out->start_call                                                      //10-03-22|0x0055
#define OutPosition Out->position                                                         //10-03-22|0x0055
#define OutLength Out->length                                                             //10-03-22|0x0055
#define OutColumn Out->column                                                             //10-03-22|0x0055
//**********************************************************************                  //10-03-22|0x0055
//***************************************************************************             //10-03-22|0x0056
#define RandomDataZero MemSet((UCHAR_FAR) ArgFar, 0x00, sizeof(CRYPTO_DATA))              //15-06-16|0x0057
//***************************************************************************             //15-06-16|0x0058
#define RandomGenerator random_generator(CryptoDataFar)                                   //15-06-16|0x0059
#define InitialRandom initial_random(CryptoDataFar)                                       //15-06-16|0x005a
#define LoadRandom load_random(CryptoDataFar, Addr)                                       //15-06-16|0x005b
//***************************************************************************             //15-06-16|0x005c
#define CRYPTO_CLASS_READY 0                                                              //10-03-22|0x005d
#define CRYPTO_CLASS_OPENED (CRYPTO_CLASS_READY)*1+1                                      //10-03-22|0x005e
//---------------------------------------------------------------------------             //10-03-22|0x005f
#define CRYPTO_DATA_CREATED (CRYPTO_CLASS_OPENED)*1+1                                     //10-03-22|0x0060
#define CRYPTO_DATA_LOAD (CRYPTO_DATA_CREATED)*1+1                                        //10-03-22|0x0061
#define CRYPTO_DATA_READY (CRYPTO_DATA_LOAD)*1+1                                          //10-03-22|0x0062
#define CRYPTO_DATA_RANDOM (CRYPTO_DATA_READY)*1+1                                        //10-03-22|0x0063
#define CRYPTO_DATA_PARITY (CRYPTO_DATA_RANDOM)*1+1                                       //10-03-22|0x0064
#define CRYPTO_DATA_ENCRYPT (CRYPTO_DATA_PARITY)*1+1                                      //10-03-22|0x0065
#define CRYPTO_DATA_DECRYPT (CRYPTO_DATA_ENCRYPT)*1+1                                     //10-03-22|0x0066
#ifndef TestIndex                                                                         //10-03-22|0x0073
#define TestIndex 0                                                                       //10-03-22|0x0073
#endif                                                                                    //10-03-22|0x0073
//------------------------------------------------------------------------                //10-03-22|0x0073
enum {  crypto_allocate_1 = TestIndex };                                                  //10-03-22|0x0073
//------------------------------------------------------------------------                //10-03-22|0x0073
#undef TestIndex                                                                          //10-03-22|0x0073
#define TestIndex crypto_allocate_1+1                                                     //10-03-22|0x0073
//************************************************************************                //10-03-22|0x0073
#ifndef TestIndex                                                                         //10-03-22|0x008b
#define TestIndex 0                                                                       //10-03-22|0x008b
#endif                                                                                    //10-03-22|0x008b
//------------------------------------------------------------------------                //10-03-22|0x008b
enum {  crypto_free_1 = TestIndex };                                                      //10-03-22|0x008b
//------------------------------------------------------------------------                //10-03-22|0x008b
#undef TestIndex                                                                          //10-03-22|0x008b
#define TestIndex crypto_free_1+1                                                         //10-03-22|0x008b
//************************************************************************                //10-03-22|0x008b
#ifndef TestIndex                                                                         //10-03-22|0x00a4
#define TestIndex 0                                                                       //10-03-22|0x00a4
#endif                                                                                    //10-03-22|0x00a4
//------------------------------------------------------------------------                //10-03-22|0x00a4
enum {  crypto_initial_1 = TestIndex };                                                   //10-03-22|0x00a4
//------------------------------------------------------------------------                //10-03-22|0x00a4
#undef TestIndex                                                                          //10-03-22|0x00a4
#define TestIndex crypto_initial_1+1                                                      //10-03-22|0x00a4
//************************************************************************                //10-03-22|0x00a4
#ifndef TestIndex                                                                         //15-06-16|0x00cf
#define TestIndex 0                                                                       //15-06-16|0x00cf
#endif                                                                                    //15-06-16|0x00cf
//------------------------------------------------------------------------                //15-06-16|0x00cf
enum {  basic_random_create_1 = TestIndex };                                              //15-06-16|0x00cf
//------------------------------------------------------------------------                //15-06-16|0x00cf
#undef TestIndex                                                                          //15-06-16|0x00cf
#define TestIndex basic_random_create_1+1                                                 //15-06-16|0x00cf
//************************************************************************                //15-06-16|0x00cf
#ifndef TestIndex                                                                         //10-03-22|0x00e3
#define TestIndex 0                                                                       //10-03-22|0x00e3
#endif                                                                                    //10-03-22|0x00e3
//------------------------------------------------------------------------                //10-03-22|0x00e3
enum {  crypto_create_1 = TestIndex };                                                    //10-03-22|0x00e3
//------------------------------------------------------------------------                //10-03-22|0x00e3
#undef TestIndex                                                                          //10-03-22|0x00e3
#define TestIndex crypto_create_1+1                                                       //10-03-22|0x00e3
//************************************************************************                //10-03-22|0x00e3
#ifndef TestIndex                                                                         //10-03-23|0x0119
#define TestIndex 0                                                                       //10-03-23|0x0119
#endif                                                                                    //10-03-23|0x0119
//------------------------------------------------------------------------                //10-03-23|0x0119
enum {  crypto_reset_1 = TestIndex };                                                     //10-03-23|0x0119
//------------------------------------------------------------------------                //10-03-23|0x0119
#undef TestIndex                                                                          //10-03-23|0x0119
#define TestIndex crypto_reset_1+1                                                        //10-03-23|0x0119
//************************************************************************                //10-03-23|0x0119
#ifndef TestIndex                                                                         //10-03-22|0x014c
#define TestIndex 0                                                                       //10-03-22|0x014c
#endif                                                                                    //10-03-22|0x014c
//------------------------------------------------------------------------                //10-03-22|0x014c
enum {  crypto_open_1 = TestIndex };                                                      //10-03-22|0x014c
//------------------------------------------------------------------------                //10-03-22|0x014c
#undef TestIndex                                                                          //10-03-22|0x014c
#define TestIndex crypto_open_1+1                                                         //10-03-22|0x014c
//************************************************************************                //10-03-22|0x014c
#ifndef TestIndex                                                                         //10-03-22|0x0176
#define TestIndex 0                                                                       //10-03-22|0x0176
#endif                                                                                    //10-03-22|0x0176
//------------------------------------------------------------------------                //10-03-22|0x0176
enum {  crypto_close_1 = TestIndex };                                                     //10-03-22|0x0176
//------------------------------------------------------------------------                //10-03-22|0x0176
#undef TestIndex                                                                          //10-03-22|0x0176
#define TestIndex crypto_close_1+1                                                        //10-03-22|0x0176
//************************************************************************                //10-03-22|0x0176
#ifndef TestIndex                                                                         //15-06-16|0x019b
#define TestIndex 0                                                                       //15-06-16|0x019b
#endif                                                                                    //15-06-16|0x019b
//------------------------------------------------------------------------                //15-06-16|0x019b
enum {  basic_random_load_1 = TestIndex };                                                //15-06-16|0x019b
//------------------------------------------------------------------------                //15-06-16|0x019b
#undef TestIndex                                                                          //15-06-16|0x019b
#define TestIndex basic_random_load_1+1                                                   //15-06-16|0x019b
//************************************************************************                //15-06-16|0x019b
#ifndef TestIndex                                                                         //10-03-22|0x01af
#define TestIndex 0                                                                       //10-03-22|0x01af
#endif                                                                                    //10-03-22|0x01af
//------------------------------------------------------------------------                //10-03-22|0x01af
enum {  crypto_load_1 = TestIndex };                                                      //10-03-22|0x01af
//------------------------------------------------------------------------                //10-03-22|0x01af
#undef TestIndex                                                                          //10-03-22|0x01af
#define TestIndex crypto_load_1+1                                                         //10-03-22|0x01af
//************************************************************************                //10-03-22|0x01af
#ifndef TestIndex                                                                         //15-06-16|0x01d9
#define TestIndex 0                                                                       //15-06-16|0x01d9
#endif                                                                                    //15-06-16|0x01d9
//------------------------------------------------------------------------                //15-06-16|0x01d9
enum {  basic_get_random_1 = TestIndex };                                                 //15-06-16|0x01d9
//------------------------------------------------------------------------                //15-06-16|0x01d9
#undef TestIndex                                                                          //15-06-16|0x01d9
#define TestIndex basic_get_random_1+1                                                    //15-06-16|0x01d9
//************************************************************************                //15-06-16|0x01d9
#ifndef TestIndex                                                                         //10-03-23|0x01fc
#define TestIndex 0                                                                       //10-03-23|0x01fc
#endif                                                                                    //10-03-23|0x01fc
//------------------------------------------------------------------------                //10-03-23|0x01fc
enum {  crypto_get_random_1 = TestIndex };                                                //10-03-23|0x01fc
//------------------------------------------------------------------------                //10-03-23|0x01fc
#undef TestIndex                                                                          //10-03-23|0x01fc
#define TestIndex crypto_get_random_1+1                                                   //10-03-23|0x01fc
//************************************************************************                //10-03-23|0x01fc
#ifndef TestIndex                                                                         //10-03-23|0x0262
#define TestIndex 0                                                                       //10-03-23|0x0262
#endif                                                                                    //10-03-23|0x0262
//------------------------------------------------------------------------                //10-03-23|0x0262
enum {  crypto_compute_parity_1 = TestIndex };                                            //10-03-23|0x0262
//------------------------------------------------------------------------                //10-03-23|0x0262
#undef TestIndex                                                                          //10-03-23|0x0262
#define TestIndex crypto_compute_parity_1+1                                               //10-03-23|0x0262
//************************************************************************                //10-03-23|0x0262
#ifndef TestIndex                                                                         //10-03-23|0x02a9
#define TestIndex 0                                                                       //10-03-23|0x02a9
#endif                                                                                    //10-03-23|0x02a9
//------------------------------------------------------------------------                //10-03-23|0x02a9
enum {  crypto_get_parity_1 = TestIndex };                                                //10-03-23|0x02a9
//------------------------------------------------------------------------                //10-03-23|0x02a9
#undef TestIndex                                                                          //10-03-23|0x02a9
#define TestIndex crypto_get_parity_1+1                                                   //10-03-23|0x02a9
//************************************************************************                //10-03-23|0x02a9
#ifndef TestIndex                                                                         //10-03-23|0x02de
#define TestIndex 0                                                                       //10-03-23|0x02de
#endif                                                                                    //10-03-23|0x02de
//------------------------------------------------------------------------                //10-03-23|0x02de
enum {  crypto_encrypt_1 = TestIndex };                                                   //10-03-23|0x02de
//------------------------------------------------------------------------                //10-03-23|0x02de
#undef TestIndex                                                                          //10-03-23|0x02de
#define TestIndex crypto_encrypt_1+1                                                      //10-03-23|0x02de
//************************************************************************                //10-03-23|0x02de
#ifndef TestIndex                                                                         //10-03-23|0x0342
#define TestIndex 0                                                                       //10-03-23|0x0342
#endif                                                                                    //10-03-23|0x0342
//------------------------------------------------------------------------                //10-03-23|0x0342
enum {  crypto_decrypt_1 = TestIndex };                                                   //10-03-23|0x0342
//------------------------------------------------------------------------                //10-03-23|0x0342
#undef TestIndex                                                                          //10-03-23|0x0342
#define TestIndex crypto_decrypt_1+1                                                      //10-03-23|0x0342
//************************************************************************                //10-03-23|0x0342
#ifndef TestIndex                                                                         //10-03-22|0x03a4
#define TestIndex 0                                                                       //10-03-22|0x03a4
#endif                                                                                    //10-03-22|0x03a4
//------------------------------------------------------------------------                //10-03-22|0x03a4
enum {  crypto_delete_1 = TestIndex };                                                    //10-03-22|0x03a4
//------------------------------------------------------------------------                //10-03-22|0x03a4
#undef TestIndex                                                                          //10-03-22|0x03a4
#define TestIndex crypto_delete_1+1                                                       //10-03-22|0x03a4
//************************************************************************                //10-03-22|0x03a4
#ifndef TestIndex                                                                         //15-06-16|0x03be
#define TestIndex 0                                                                       //15-06-16|0x03be
#endif                                                                                    //15-06-16|0x03be
//------------------------------------------------------------------------                //15-06-16|0x03be
enum {  initial_random_1 = TestIndex };                                                   //15-06-16|0x03be
//------------------------------------------------------------------------                //15-06-16|0x03be
#undef TestIndex                                                                          //15-06-16|0x03be
#define TestIndex initial_random_1+1                                                      //15-06-16|0x03be
//************************************************************************                //15-06-16|0x03be
#ifndef TestIndex                                                                         //15-06-16|0x03da
#define TestIndex 0                                                                       //15-06-16|0x03da
#endif                                                                                    //15-06-16|0x03da
//------------------------------------------------------------------------                //15-06-16|0x03da
enum {  load_random_1 = TestIndex };                                                      //15-06-16|0x03da
//------------------------------------------------------------------------                //15-06-16|0x03da
#undef TestIndex                                                                          //15-06-16|0x03da
#define TestIndex load_random_1+1                                                         //15-06-16|0x03da
//************************************************************************                //15-06-16|0x03da
#ifndef TestIndex                                                                         //15-06-16|0x0418
#define TestIndex 0                                                                       //15-06-16|0x0418
#endif                                                                                    //15-06-16|0x0418
//------------------------------------------------------------------------                //15-06-16|0x0418
enum {  random_generator_1 = TestIndex };                                                 //15-06-16|0x0418
//------------------------------------------------------------------------                //15-06-16|0x0418
#undef TestIndex                                                                          //15-06-16|0x0418
#define TestIndex random_generator_1+1                                                    //15-06-16|0x0418
//************************************************************************                //15-06-16|0x0418
#ifndef TestIndex                                                                         //10-03-23|0x0438
#define TestIndex 0                                                                       //10-03-23|0x0438
#endif                                                                                    //10-03-23|0x0438
//------------------------------------------------------------------------                //10-03-23|0x0438
enum {  crypto_read_1 = TestIndex };                                                      //10-03-23|0x0438
//------------------------------------------------------------------------                //10-03-23|0x0438
#undef TestIndex                                                                          //10-03-23|0x0438
#define TestIndex crypto_read_1+1                                                         //10-03-23|0x0438
//************************************************************************                //10-03-23|0x0438
#ifndef TestIndex                                                                         //10-03-22|0x0463
#define TestIndex 0                                                                       //10-03-22|0x0463
#endif                                                                                    //10-03-22|0x0463
//------------------------------------------------------------------------                //10-03-22|0x0463
enum {  crypto_write_1 = TestIndex };                                                     //10-03-22|0x0463
//------------------------------------------------------------------------                //10-03-22|0x0463
#undef TestIndex                                                                          //10-03-22|0x0463
#define TestIndex crypto_write_1+1                                                        //10-03-22|0x0463
//************************************************************************                //10-03-22|0x0463
//*******************************************************************************         //05-24-97|0x049a
//*******************************************************************************         //05-24-97|0x049a
//****                       END OF FILE                                     ****         //05-24-97|0x049a
//*******************************************************************************         //05-24-97|0x049a
//*******************************************************************************         //05-24-97|0x049a
#endif                                                                                    //05-24-97|0x049a
