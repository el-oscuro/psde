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
#include <stdlib.h>                                                                            /* 0x000d|check    */
#include <stdio.h>                                                                             /* 0x000d|check    */
#include <memory.h>                                                                            /* 0x000d|check    */
#include <string.h>                                                                            /* 0x000d|check    */
#include <time.h>                                                                              /* 0x000d|check    */
#include <sys/stat.h>                                                                          /* 0x000d|check    */
#include <unistd.h>                                                                            /* 0x000d|check    */
#define _MAX_PATH  256                                                                         /* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
#include "prime.h"                                                                             /* 0x000d|check    */
#include "primewrp.h"                                                                          /* 0x000d|check    */
#include "primewrp.hxx"                                                                        /* 0x000d|check    */
#include "prime.hxx"                                                                           /* 0x000d|check    */
#include "primewrp.hpp"                                                                        /* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
#define MemSet(i1,i2,i3)     memset(i1,i2,i3)                                                  /* 0x000d|check    */
#define MemCCpy(i1,i2,i3,i4) primewrpCXXmemccpy(i1,i2,i3,i4)                                   /* 0x000d|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x000d|check    */
#define StrRChr(i1,i2)       strrchr(i1,i2)                                                    /* 0x000d|check    */
#define StrCat(i1,i2)        strcat(i1,i2)                                                     /* 0x000d|check    */
#define StrLen(i1)           strlen(i1)                                                        /* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
SCHAR_ADDR primewrpCXXmemccpy                                                                  /* 0x000d|check    */
  (                                                                                            /* 0x000d|check    */
    SCHAR_ADDR OutAddr,                                                                        /* 0x000d|check    */
    SCHAR_ADDR InAddr,                                                                         /* 0x000d|check    */
    SCHAR      EndByte,                                                                        /* 0x000d|check    */
    SLONG      MaxSize                                                                         /* 0x000d|check    */
  )                                                                                            /* 0x000d|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x000d|check    */
{                                                                                              /* 0x000d|check    */
  while(MaxSize > 0)                                                                           /* 0x000d|check    */
  {                                                                                            /* 0x000d|check    */
    *OutAddr = *InAddr;                                                                        /* 0x000d|check    */
    if(*InAddr == EndByte)                                                                     /* 0x000d|check    */
    {                                                                                          /* 0x000d|check    */
      return(InAddr);                                                                          /* 0x000d|check    */
    }                                                                                          /* 0x000d|check    */
    ++InAddr;                                                                                  /* 0x000d|check    */
    ++OutAddr;                                                                                 /* 0x000d|check    */
    --MaxSize;                                                                                 /* 0x000d|check    */
  }                                                                                            /* 0x000d|check    */
  return(0);                                                                                   /* 0x000d|check    */
}                                                                                              /* 0x000d|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*****                                                                                   *****//* 0x00e4|check    */
/*****                     ERROR HANDLER                                                 *****//* 0x00e4|check    */
/*****                                                                                   *****//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
ULONG WRAPPER_System_Error                                                                     /* 0x00e4|check    */
  (                                                                                            /* 0x00e4|check    */
    USHORT             LineNo                                                                  /* 0x00e4|check    */
  )                                                                                            /* 0x00e4|check    */
{                                                                                              /* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
/*********************************************************************************************//* 0x00e4|check    */
  if(NoErrorMessages < 64)                                                                     /* 0x00e4|check    */
  {                                                                                            /* 0x00e4|check    */
    ErrorFileNameAddr(NoErrorMessages) = &WRAPPER_cpp_file_name[0];                            /* 0x00e4|check    */
    ErrorLineNo(NoErrorMessages)       = LineNo;                                               /* 0x00e4|check    */
    ++NoErrorMessages;                                                                         /* 0x00e4|check    */
  }                                                                                            /* 0x00e4|check    */
  return(0xffff);                                                                              /* 0x00e4|check    */
}                                                                                              /* 0x00e4|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     SOURCE FILE NAME                                              *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
SCHAR WRAPPER_cpp_file_name[17];                                                               /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     CONSTRUCTOR                                                   *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
ULONG WRAPPER_Construct                                                                        /* 0x00e5|check    */
  (                                                                                            /* 0x00e5|check    */
    INSTANCE_ADDR_ADDR __InstanceAddrAddr,                                                     /* 0x00e5|check    */
    ULONG              __InstanceHandle                                                        /* 0x00e5|check    */
  )                                                                                            /* 0x00e5|check    */
{                                                                                              /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     INITIAL ERROR ROUTINE                                         *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  MemSet (&WRAPPER_cpp_file_name[0], 0, 17);                                                   /* 0x00e5|check    */
  MemCCpy(&WRAPPER_cpp_file_name[0], "primewrp",  0, 16);                                      /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     CONSTRUCTOR PM/FL TESTS                                       *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  if((__InstanceHandle                  >  NoInstances) ||                                     /* 0x00e5|check    */
     (__InstanceAddrFirst               != 0)           ||                                     /* 0x00e5|check    */
     (__InstanceAddrLast                != 0)           ||                                     /* 0x00e5|check    */
     (__InstanceAddrSize                != 0)           ||                                     /* 0x00e5|check    */
     (InstanceFirst(__InstanceHandle)   != 0)           ||                                     /* 0x00e5|check    */
     (InstanceLast (__InstanceHandle)   != 0)           ||                                     /* 0x00e5|check    */
     (InstanceSize (__InstanceHandle)   != 0))                                                 /* 0x00e5|check    */
  {                                                                                            /* 0x00e5|check    */
    SystemError;                                                                               /* 0x00e5|check    */
  }                                                                                            /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     ALLOCATE CLASS INSTANCE STRUCTURE                             *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  __InstanceAddrFirst = (UCHAR_ADDR) malloc(__ClassSize);                                      /* 0x00e5|check    */
  if(__InstanceAddrFirst == 0)                                                                 /* 0x00e5|check    */
  {                                                                                            /* 0x00e5|check    */
    SystemError;                                                                               /* 0x00e5|check    */
  }                                                                                            /* 0x00e5|check    */
  MemSet(__InstanceAddrFirst, 0, __ClassSize);                                                 /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
  __InstanceAddrLast        = __InstanceAddrFirst + __ClassSize;                               /* 0x00e5|check    */
  __InstanceAddrSize        = __ClassSize;                                                     /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  auto WRAPPER_CLASS_DATA_ADDR InstanceLink;                                                   /* 0x00e5|check    */
  InstanceLink = __InstanceAddrLink;                                                           /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  InstanceLink->__class_addr   = __InstanceAddrFirst;                                          /* 0x00e5|check    */
  InstanceLink->__last_addr    = __InstanceAddrLast;                                           /* 0x00e5|check    */
  InstanceLink->__class_size   = __ClassSize;                                                  /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
  InstanceFirst(__InstanceHandle)    = __InstanceAddrFirst;                                    /* 0x00e5|check    */
  InstanceLast (__InstanceHandle)    = __InstanceAddrLast;                                     /* 0x00e5|check    */
  InstanceSize (__InstanceHandle)    = __ClassSize;                                            /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     SUB-CLASS CONSTRUCTION                                        *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  if(PRIME_Construct(&PrimeGen__Addr__Addr,                                                    /* 0x00e5|check    */
                  __InstanceHandle+PrimeGen_WRAPPER__Handle))                                  /* 0x00e5|check    */
  {                                                                                            /* 0x00e5|check    */
    SystemError;                                                                               /* 0x00e5|check    */
  }                                                                                            /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  return(0x0000);                                                                              /* 0x00e5|check    */
}                                                                                              /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     DESTRUCTOR                                                    *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
ULONG WRAPPER_Destruct                                                                         /* 0x00e5|check    */
  (                                                                                            /* 0x00e5|check    */
    INSTANCE_ADDR_ADDR     __InstanceAddrAddr,                                                 /* 0x00e5|check    */
    ULONG                  __InstanceHandle                                                    /* 0x00e5|check    */
  )                                                                                            /* 0x00e5|check    */
{                                                                                              /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     DESTROCTOR PMFL                                               *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
    if((__InstanceHandle     >  NoInstances)                      ||                           /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
       (__InstanceAddrFirst  == 0)                                ||                           /* 0x00e5|check    */
       (__InstanceAddrLast   == 0)                                ||                           /* 0x00e5|check    */
       (__InstanceAddrSize   == 0)                                ||                           /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
        (__InstanceAddrFirst != InstanceFirst(__InstanceHandle))  ||                           /* 0x00e5|check    */
        (__InstanceAddrLast  != InstanceLast (__InstanceHandle))  ||                           /* 0x00e5|check    */
        (__InstanceAddrSize  != InstanceSize (__InstanceHandle)))                              /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
    {                                                                                          /* 0x00e5|check    */
      SystemError;                                                                             /* 0x00e5|check    */
    }                                                                                          /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  auto WRAPPER_CLASS_DATA_ADDR InstanceLink;                                                   /* 0x00e5|check    */
  InstanceLink = __InstanceAddrLink;                                                           /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  if((__InstanceAddrFirst != InstanceLink->__class_addr) ||                                    /* 0x00e5|check    */
     (__InstanceAddrLast  != InstanceLink->__last_addr)  ||                                    /* 0x00e5|check    */
     (__InstanceAddrSize  != InstanceLink->__class_size))                                      /* 0x00e5|check    */
  {                                                                                            /* 0x00e5|check    */
    SystemError;                                                                               /* 0x00e5|check    */
  }                                                                                            /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     SUB-CLASS DESTRUCTION                                         *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  if(PRIME_Destruct(&PrimeGen__Addr__Addr,                                                     /* 0x00e5|check    */
                __InstanceHandle+PrimeGen_WRAPPER__Handle))                                    /* 0x00e5|check    */
  {                                                                                            /* 0x00e5|check    */
    SystemError;                                                                               /* 0x00e5|check    */
  }                                                                                            /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*****                     FREE CLASS INSTANCE STRUCTURE                                 *****//* 0x00e5|check    */
/*****                                                                                   *****//* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  free(__InstanceAddrFirst);                                                                   /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
  InstanceFirst(__InstanceHandle)  = 0;                                                        /* 0x00e5|check    */
  InstanceLast (__InstanceHandle)  = 0;                                                        /* 0x00e5|check    */
  InstanceSize (__InstanceHandle)  = 0;                                                        /* 0x00e5|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e5|check    */
  __InstanceAddrFirst              = 0;                                                        /* 0x00e5|check    */
  __InstanceAddrLast               = 0;                                                        /* 0x00e5|check    */
  __InstanceAddrSize               = 0;                                                        /* 0x00e5|check    */
/*********************************************************************************************//* 0x00e5|check    */
  return(0x0000);                                                                              /* 0x00e5|check    */
}                                                                                              /* 0x00e5|check    */
