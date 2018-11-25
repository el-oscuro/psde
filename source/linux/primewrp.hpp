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
#ifndef  primewrp_hpp                                                                          /* 0x000d|check    */
#define  primewrp_hpp                                                                          /* 0x000d|check    */
/*********************************************************************************************//* 0x0022|check    */
/*********************************************************************************************//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****                   LOCAL TYPEDEF STATEMENTS                                        *****//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*********************************************************************************************//* 0x0022|check    */
/*********************************************************************************************//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****                  INSTANCE_ADDRS STRUCTURE TYPEDEF                                 *****//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
typedef struct                                                                                 /* 0x0022|check    */
{                                                                                              /* 0x0022|check    */
  INSTANCE_ADDR                                           instances[NoInstances+1];            /* 0x0022|check    */
} INSTANCE_ADDRS, * INSTANCE_ADDRS_ADDR;                                                       /* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****                  CLASS_DATA_ADDRS STRUCTURE TYPEDEF                               *****//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
typedef struct                                                                                 /* 0x0022|check    */
{                                                                                              /* 0x0022|check    */
  INSTANCE_ADDR                                           class_data[NoClasses+1];             /* 0x0022|check    */
} CLASS_DATA_ADDRS, * CLASS_DATA_ADDRS_ADDR;                                                   /* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****                    STRING_CONSTANT STRUCTURE TYPEDEF                              *****//* 0x0022|check    */
/*****                                                                                   *****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0022|check    */
typedef struct                                                                                 /* 0x0022|check    */
{                                                                                              /* 0x0022|check    */
  SLONG                                               STRING_CONSTANT_MAX_SIZE;                /* 0x0022|check    */
  SLONG                                               STRING_CONSTANT_SIZE;                    /* 0x0022|check    */
  SLONG                                               STRING_CONSTANT_POS;                     /* 0x0022|check    */
  SLONG                                               STRING_CONSTANT_INDEX;                   /* 0x0022|check    */
  SCHAR                                               STRING_CONSTANT_CHAR[129];               /* 0x0022|check    */
} STRING_CONSTANT, * STRING_CONSTANT_ADDR;                                                     /* 0x0022|check    */
/*********************************************************************************************//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*****                                                                                   *****//* 0x0029|check    */
/*****                   GENETICS LOCAL GENERATOR DEFINES                                *****//* 0x0029|check    */
/*****                                                                                   *****//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
/*********************************************************************************************//* 0x0029|check    */
#define LOCALMAX                       0x1000                                                  /* 0x0029|check    */
#define LOCALCOEFFINDEX                23                                                      /* 0x0029|check    */
#define LOCALCONSTINDEX                45                                                      /* 0x0029|check    */
#define LOCALSEED                      1201                                                    /* 0x0029|check    */
/*********************************************************************************************//* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
/*****                                                                                   *****//* 0x0032|check    */
/*****                   GLOBAL VARIABLES                                                *****//* 0x0032|check    */
/*****                                                                                   *****//* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
extern INSTANCE_ADDRS                                instance_addrs;                           /* 0x0032|check    */
#define Instance(i1)                            instance_addrs.instances[i1]                   /* 0x0032|check    */
#define InstanceFirst(i1)                       Instance(i1).instance_first                    /* 0x0032|check    */
#define InstanceLast(i1)                        Instance(i1).instance_last                     /* 0x0032|check    */
#define InstanceSize(i1)                        Instance(i1).instance_size                     /* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
extern CLASS_DATA_ADDRS                              class_data_addrs;                         /* 0x0032|check    */
#define ClassData(i1)                           class_data_addrs.class_data[i1]                /* 0x0032|check    */
#define ClassDataFirst(i1)                      ClassData(i1).instance_first                   /* 0x0032|check    */
#define ClassDataLast(i1)                       ClassData(i1).instance_last                    /* 0x0032|check    */
#define ClassDataSize(i1)                       ClassData(i1).instance_size                    /* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
extern ERROR_MESSAGES                                error_messages;                           /* 0x0032|check    */
#define NoErrorMessages                         error_messages.no_error_messages               /* 0x0032|check    */
#define ErrorMessage(i1)                        error_messages.error_message[i1]               /* 0x0032|check    */
#define ErrorFileNameAddr(i1)                   ErrorMessage(i1).error_file_name_addr          /* 0x0032|check    */
#define ErrorLineNo(i1)                         ErrorMessage(i1).error_line_no                 /* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
/*****                                                                                   *****//* 0x0032|check    */
/*****                   PRIVATE SUB-CLASS DEFINE STATEMENTS                             *****//* 0x0032|check    */
/*****                                                                                   *****//* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
/*********************************************************************************************//* 0x0032|check    */
#define SubRout(N,R)                      N##_##R                                              /* 0x0032|check    */
#define SubRoutA(N)                       N##__Addr                                            /* 0x0032|check    */
#define SubRoutH(N)                       N##_WRAPPER__Handle+__InstanceHandle                 /* 0x0032|check    */
#define SubRout0(R,N)                         R(SubRoutA(N),SubRoutH(N))                       /* 0x0032|check    */
#define SubRout1(R,N,P1)                      R(SubRoutA(N),SubRoutH(N),P1)                    /* 0x0032|check    */
#define SubRout2(R,N,P1,P2)                   R(SubRoutA(N),SubRoutH(N),P1,P2)                 /* 0x0032|check    */
#define SubRout3(R,N,P1,P2,P3)                R(SubRoutA(N),SubRoutH(N),P1,P2,P3)              /* 0x0032|check    */
#define SubRout4(R,N,P1,P2,P3,P4)             R(SubRoutA(N),SubRoutH(N),P1,P2,P3,P4)           /* 0x0032|check    */
#define SubRout5(R,N,P1,P2,P3,P4,P5)          R(SubRoutA(N),SubRoutH(N),P1,P2,P3,P4,P5)        /* 0x0032|check    */
/*********************************************************************************************//* 0x0033|check    */
#define _PrimeGen(P0)                          SubRout(PRIME,P0)                               /* 0x0033|check    */
#define _PrimeGen0(P0)                         SubRout0(_PrimeGen(P0),PrimeGen)                /* 0x0033|check    */
#define _PrimeGen1(P0,P1)                      SubRout1(_PrimeGen(P0),PrimeGen,P1)             /* 0x0033|check    */
#define _PrimeGen2(P0,P1,P2)                   SubRout2(_PrimeGen(P0),PrimeGen,P1,P2)          /* 0x0033|check    */
#define _PrimeGen3(P0,P1,P2,P3)                SubRout3(_PrimeGen(P0),PrimeGen,P1,P2,P3)       /* 0x0033|check    */
#define _PrimeGen4(P0,P1,P2,P3,P4)             SubRout4(_PrimeGen(P0),PrimeGen,P1,P2,P3,P4)    /* 0x0033|check    */
#define _PrimeGen5(P0,P1,P2,P3,P4,P5)          SubRout5(_PrimeGen(P0),PrimeGen,P1,P2,P3,P4,P5) /* 0x0033|check    */
/*********************************************************************************************//* 0x0033|check    */
#define PrimeGenOpen                             _PrimeGen0(Open)                              /* 0x0033|check    */
#define PrimeGenClose                            _PrimeGen0(Close)                             /* 0x0033|check    */
#define PrimeGenGetPrime(P1,P2)                  _PrimeGen2(GetPrime,P1,P2)                    /* 0x0033|check    */
#define PrimeGenPrimeSuccess                     _PrimeGen(PrimeSuccess)                       /* 0x0033|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*****                                                                                   *****//* 0x00e4|check    */
/*****                   ERROR ROUTINE DEFINES                                           *****//* 0x00e4|check    */
/*****                                                                                   *****//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
ULONG WRAPPER_System_Error                                                                     /* 0x00e4|check    */
  (                                                                                            /* 0x00e4|check    */
    USHORT             LineNo                                                                  /* 0x00e4|check    */
  );                                                                                           /* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
#define SystemError                return(WRAPPER_System_Error(__LINE__));                     /* 0x00e4|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                       CLASS INSTANCE LINKAGE DEFINES                              *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define __InstanceFirst                  (__InstanceAddr.instance_first)                       /* 0x00e5|check    */
#define __InstanceLast                   (__InstanceAddr.instance_last)                        /* 0x00e5|check    */
#define __InstanceSize                   (__InstanceAddr.instance_size)                        /* 0x00e5|check    */
#define __InstanceAddrFirst              (__InstanceAddrAddr->instance_first)                  /* 0x00e5|check    */
#define __InstanceAddrLast               (__InstanceAddrAddr->instance_last)                   /* 0x00e5|check    */
#define __InstanceAddrSize               (__InstanceAddrAddr->instance_size)                   /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
#define __ClassSize                 sizeof(WRAPPER_CLASS_DATA)                                 /* 0x00e5|check    */
#define __InstanceLink                   ((WRAPPER_CLASS_DATA_ADDR) __InstanceFirst)           /* 0x00e5|check    */
#define __InstanceAddrLink               ((WRAPPER_CLASS_DATA_ADDR) __InstanceAddrFirst)       /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                       CLASS INSTANCE ELEMENTS DEFINES                             *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define PrimeGen__Addr              __InstanceLink->__PrimeGen__Addr                           /* 0x0033|check    */
#define PrimeGen__Addr__Addr        __InstanceAddrLink->__PrimeGen__Addr                       /* 0x0033|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                       CLASS DATA LINKAGE DEFINES                                  *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define __ClassLinkFirst(U)             U.instance_first                                       /* 0x00e5|check    */
#define __ClassLinkLast(U)              U.instance_last                                        /* 0x00e5|check    */
#define __ClassLinkSize(U)              U.instance_size                                        /* 0x00e5|check    */
#define __ClassDataLink(i,j)            ((i##_ADDR) (ClassDataFirst(j##_Handle)))              /* 0x00e5|check    */
#define __ClassDataFirst(i,j)           __ClassDataLink(i,j)->i##_first                        /* 0x00e5|check    */
#define __ClassDataSize(i,j)            __ClassDataLink(i,j)->i##_size                         /* 0x00e5|check    */
#define __ClassDataCount(i,j)           __ClassDataLink(i,j)->i##_count                        /* 0x00e5|check    */
#define __ClassDataBase(i,j)            __ClassDataLink(i,j)->i##_base                         /* 0x00e5|check    */
#define __ClassDataLast(i,j)            __ClassDataLink(i,j)->i##_last                         /* 0x00e5|check    */
#define __ClassData_Size(i)             sizeof(i)                                              /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                   GENETICS DEFINES                                                *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define NOLOCALTOKENS          0x0003                                                          /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define GLOBALLOCALBASE        WRAPPER_GLOBALLOCALBASE                                         /* 0x00e5|check    */
#define _GLOBALLOCALBASE       0x260b                                                          /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define InitializedState       WRAPPER_InitializedState                                        /* 0x00e5|check    */
#define _InitializedState      0x63f5                                                          /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#define ReadyState             WRAPPER_ReadyState                                              /* 0x00e5|check    */
#define _ReadyState            0x116f                                                          /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
#endif                                                                                         /* 0x00e5|check    */
