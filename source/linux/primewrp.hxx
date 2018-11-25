/*********************************************************************************************//* 0x0002|check    */
/*********************************************************************************************//* 0x0003|check    */
/*********                                                                              ******//* 0x0004|check    */
/*********                         PRIME GENERATOR WRAPPER SOURCE                       ******//* 0x0005|check    */
/*********                                                                              ******//* 0x0006|check    */
/*********************************************************************************************//* 0x0007|check    */
/*********************************************************************************************//* 0x0008|check    */
/*****                Copyright: 2006 Robert H. Adams                                    *****//* 0x0009|check    */
/*********************************************************************************************//* 0x0009|check    */
/*********************************************************************************************//* 0x0009|check    */
/*****           The purpose of this program as well as instructions regarding           *****//* 0x0009|check    */
/*****           its use is defined in the associated manual.                            *****//* 0x0009|check    */
/*********************************************************************************************//* 0x0009|check    */
/*********************************************************************************************//* 0x0009|check    */
/*****           This program is free software; you can redistribute it and/or           *****//* 0x0009|check    */
/*****           modify it under the terms of the GNU General Public License             *****//* 0x0009|check    */
/*****           as published by the Free Software Foundation; either version 2          *****//* 0x0009|check    */
/*****           of the License, or(at your option) any later version.                   *****//* 0x0009|check    */
/*****                                                                                   *****//* 0x0009|check    */
/*****           This program is distributed in the hope that it will be useful,         *****//* 0x0009|check    */
/*****           but WITHOUT ANY WARRANTY; without even the implied warranty of          *****//* 0x0009|check    */
/*****           MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *****//* 0x0009|check    */
/*****           GNU General Public License for more details.                            *****//* 0x0009|check    */
/*****                                                                                   *****//* 0x0009|check    */
/*****           You should have received a copy of the GNU General Public               *****//* 0x0009|check    */
/*****           License along with this program; if not, write to the Free              *****//* 0x0009|check    */
/*****           Software Foundation, Inc., 51 Franklin Street, Fifth Floor,             *****//* 0x0009|check    */
/*****           Boston, MA., 02110-1301USA                                              *****//* 0x0009|check    */
/*********************************************************************************************//* 0x0009|check    */
/*****           For further information, please contact Robert Adams:                   *****//* 0x0009|check    */
/*****               EMail:    robert.adams@whatifwe.com                                 *****//* 0x0009|check    */
/*****               Mail:     PO Box 156, Sun Valley, Ca. 91353-0155, USA               *****//* 0x0009|check    */
/*****           Or visit the website, "www.whatifwe.com".                               *****//* 0x0009|check    */
/*********************************************************************************************//* 0x000a|check    */
/*********************************************************************************************//* 0x000b|check    */
#ifndef  primewrp_hxx                                                                          /* 0x000d|check    */
#define  primewrp_hxx                                                                          /* 0x000d|check    */
/*********************************************************************************************//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*****                                                                                   *****//* 0x0029|check    */
/*****                   GLOBAL GENETICS INITIALIZATION                                  *****//* 0x0029|check    */
/*****                                                                                   *****//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
#define GLOBALCOEFFINDEX 66                                                                    /* 0x0029|check    */
#define GLOBALCONSTINDEX 440                                                                   /* 0x0029|check    */
#define GlobalStep(i)              (0x04f5*i+0x0c07)%GlobalMax                                 /* 0x0029|check    */
#define GlobalValue 335                                                                        /* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*****                                                                                   *****//* 0x0029|check    */
/*****                   GLOBAL GENETICS                                                 *****//* 0x0029|check    */
/*****                                                                                   *****//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
enum                                                                                           /* 0x0029|check    */
{                                                                                              /* 0x0029|check    */
  WRAPPER_GLOBALLOCALBASE = GlobalValue                                                        /* 0x0029|check    */
};                                                                                             /* 0x0029|check    */
#undef  GlobalValue                                                                            /* 0x0029|check    */
#define GlobalValue GlobalStep(WRAPPER_GLOBALLOCALBASE)                                        /* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
enum                                                                                           /* 0x002a|check    */
{                                                                                              /* 0x002a|check    */
  WRAPPER_InitializedState = GlobalValue                                                       /* 0x002a|check    */
};                                                                                             /* 0x002a|check    */
#undef  GlobalValue                                                                            /* 0x002a|check    */
#define GlobalValue GlobalStep(WRAPPER_InitializedState)                                       /* 0x002a|check    */
/*********************************************************************************************//* 0x002a|check    */
enum                                                                                           /* 0x002b|check    */
{                                                                                              /* 0x002b|check    */
  WRAPPER_ReadyState = GlobalValue                                                             /* 0x002b|check    */
};                                                                                             /* 0x002b|check    */
#undef  GlobalValue                                                                            /* 0x002b|check    */
#define GlobalValue GlobalStep(WRAPPER_ReadyState)                                             /* 0x002b|check    */
/*********************************************************************************************//* 0x002b|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#endif                                                                                         /* 0x00e5|check    */
