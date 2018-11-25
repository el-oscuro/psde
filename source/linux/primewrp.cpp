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
#define MemCCpy(i1,i2,i3,i4) primewrpCPPmemccpy(i1,i2,i3,i4)                                   /* 0x000d|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x000d|check    */
#define StrRChr(i1,i2)       strrchr(i1,i2)                                                    /* 0x000d|check    */
#define StrCat(i1,i2)        strcat(i1,i2)                                                     /* 0x000d|check    */
#define StrLen(i1)           strlen(i1)                                                        /* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
/*********************************************************************************************//* 0x000d|check    */
SCHAR_ADDR primewrpCPPmemccpy                                                                  /* 0x000d|check    */
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
/*********************************************************************************************//* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
/*****                                                                                   *****//* 0x003c|check    */
/*****                                REQUIRED GLOBAL MEMORY                             *****//* 0x003c|check    */
/*****                                                                                   *****//* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
INSTANCE_ADDRS         instance_addrs;                                                         /* 0x003c|check    */
CLASS_DATA_ADDRS       class_data_addrs;                                                       /* 0x003c|check    */
ERROR_MESSAGES         error_messages;                                                         /* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
/*****                                                                                   *****//* 0x003c|check    */
/*****                                REQUIRED STATIC MEMORY                             *****//* 0x003c|check    */
/*****                                                                                   *****//* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
/*********************************************************************************************//* 0x003c|check    */
static ULONG           WrapperState  = 0xffff;                                                 /* 0x003c|check    */
static INSTANCE_ADDR   __InstanceAddrs;                                                        /* 0x003c|check    */
static INSTANCE_ADDR   __InstanceAddr;                                                         /* 0x003c|check    */
static SLONG           __ExitCode;                                                             /* 0x003c|check    */
static SLONG           __InstanceHandle;                                                       /* 0x003c|check    */
/*********************************************************************************************//* 0x0040|check    */
/*********************************************************************************************//* 0x0041|check    */
/*********                                                                              ******//* 0x0042|check    */
/*********                PrimeConstruct(void)                                          ******//* 0x0043|check    */
/*********                                                                              ******//* 0x0044|check    */
/*********------------------------------------------------------------------------------******//* 0x0045|check    */
/*********                                                                              ******//* 0x0046|check    */
/*********  This routine initializes the simulated classs                               ******//* 0x0047|check    */
/*********                                                                              ******//* 0x0048|check    */
/*********------------------------------------------------------------------------------******//* 0x0049|check    */
/*********  Returns:                                                                    ******//* 0x004a|check    */
/*********      0x0000:         Successful Operation.                                   ******//* 0x004b|check    */
/*********      0xffff:         System Error                                            ******//* 0x004c|check    */
/*********                                                                              ******//* 0x004d|check    */
/*********************************************************************************************//* 0x004e|check    */
/*********************************************************************************************//* 0x004f|check    */
ULONG  PrimeConstruct(void)                                                                    /* 0x0052|check    */
{                                                                                              /* 0x0052|check    */
  MemSet(&error_messages,     0, sizeof(ERROR_MESSAGES));                                      /* 0x0052|check    */
  switch(WrapperState)                                                                         /* 0x0052|check    */
  {                                                                                            /* 0x0052|check    */
    case 0xffff:                                                                               /* 0x0052|check    */
      MemSet(&instance_addrs,     0, sizeof(INSTANCE_ADDRS));                                  /* 0x0052|check    */
      MemSet(&class_data_addrs,   0, sizeof(CLASS_DATA_ADDRS));                                /* 0x0052|check    */
      MemSet(&__InstanceAddr,     0, sizeof(INSTANCE_ADDR));                                   /* 0x0052|check    */
      __InstanceHandle = 0;                                                                    /* 0x0052|check    */
      if(WRAPPER_Construct(&__InstanceAddr, __InstanceHandle))                                 /* 0x0052|check    */
      {                                                                                        /* 0x0052|check    */
        SystemError;                                                                           /* 0x0052|check    */
      }                                                                                        /* 0x0052|check    */
      WrapperState = _InitializedState;                                                        /* 0x0052|check    */
      return(0x0000);                                                                          /* 0x0052|check    */
    default:                                                                                   /* 0x0052|check    */
      SystemError;                                                                             /* 0x0052|check    */
  }                                                                                            /* 0x0052|check    */
}                                                                                              /* 0x0052|check    */
/*********************************************************************************************//* 0x0055|check    */
/*********************************************************************************************//* 0x0056|check    */
/*********                                                                              ******//* 0x0057|check    */
/*********                PrimeOpen(void)                                               ******//* 0x0058|check    */
/*********                                                                              ******//* 0x0059|check    */
/*********------------------------------------------------------------------------------******//* 0x005a|check    */
/*********                                                                              ******//* 0x005b|check    */
/*********  This routine prepares the Prime Number Generator for use by:                ******//* 0x005c|check    */
/*********      1.  Allocating the required Object related memory                       ******//* 0x005d|check    */
/*********      2.  Compute and store all two-byte prime numbers                        ******//* 0x005e|check    */
/*********                                                                              ******//* 0x005f|check    */
/*********------------------------------------------------------------------------------******//* 0x0060|check    */
/*********  Returns:                                                                    ******//* 0x0061|check    */
/*********      0x0000:         Successful Operation.                                   ******//* 0x0062|check    */
/*********      0xffff:         System Failure.                                         ******//* 0x0063|check    */
/*********                                                                              ******//* 0x0064|check    */
/*********************************************************************************************//* 0x0065|check    */
/*********************************************************************************************//* 0x0066|check    */
ULONG  PrimeOpen                                                                               /* 0x0069|check    */
  (                                                                                            /* 0x0069|check    */
    void                                                                                       /* 0x006a|check    */
  )                                                                                            /* 0x006a|check    */
{                                                                                              /* 0x006a|check    */
  switch(WrapperState)                                                                         /* 0x006a|check    */
  {                                                                                            /* 0x006a|check    */
    case _InitializedState:                                                                    /* 0x006a|check    */
      WrapperState = 0xffff;                                                                   /* 0x006a|check    */
/*********************************************************************************************//* 0x006a|check    */
/*****                                                                                   *****//* 0x006a|check    */
/*****                     INSTANCE PM/FL TESTS                                          *****//* 0x006a|check    */
/*****                                                                                   *****//* 0x006a|check    */
/*********************************************************************************************//* 0x006a|check    */
      if((__InstanceHandle >  NoInstances)                         ||                          /* 0x006a|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x006a|check    */
         (__InstanceFirst  == 0)                                   ||                          /* 0x006a|check    */
         (__InstanceLast   == 0)                                   ||                          /* 0x006a|check    */
         (__InstanceSize   == 0)                                   ||                          /* 0x006a|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x006a|check    */
         (__InstanceFirst  != InstanceFirst(__InstanceHandle))     ||                          /* 0x006a|check    */
         (__InstanceLast   != InstanceLast (__InstanceHandle))     ||                          /* 0x006a|check    */
         (__InstanceSize   != InstanceSize (__InstanceHandle)))                                /* 0x006a|check    */
      {                                                                                        /* 0x006a|check    */
        SystemError;                                                                           /* 0x006a|check    */
      }                                                                                        /* 0x006a|check    */
/*********************************************************************************************//* 0x006a|check    */
      auto WRAPPER_CLASS_DATA_ADDR InstanceLink;                                               /* 0x006a|check    */
      InstanceLink = __InstanceLink;                                                           /* 0x006a|check    */
/*********************************************************************************************//* 0x006a|check    */
      if((__InstanceFirst  != __InstanceLink->__class_addr)        ||                          /* 0x006a|check    */
         (__InstanceLast   != __InstanceLink->__last_addr)         ||                          /* 0x006a|check    */
         (__InstanceSize   != __InstanceLink->__class_size))                                   /* 0x006a|check    */
      {                                                                                        /* 0x006a|check    */
        SystemError;                                                                           /* 0x006a|check    */
      }                                                                                        /* 0x006a|check    */
/*********************************************************************************************//* 0x006a|check    */
      if(PrimeGenOpen == 0xffff)                                                               /* 0x006a|check    */
      {                                                                                        /* 0x006a|check    */
        SystemError;                                                                           /* 0x006a|check    */
      }                                                                                        /* 0x006a|check    */
      WrapperState = _ReadyState;                                                              /* 0x006a|check    */
      return(0x0000);                                                                          /* 0x006a|check    */
    default:                                                                                   /* 0x006a|check    */
      WrapperState = 0xffff;                                                                   /* 0x006a|check    */
      MemSet(&error_messages,     0, sizeof(ERROR_MESSAGES));                                  /* 0x006a|check    */
      MemSet (&WRAPPER_cpp_file_name[0],       0, 17);                                         /* 0x006a|check    */
      MemCCpy(&WRAPPER_cpp_file_name[0], "primewrp", 0, 16);                                   /* 0x006a|check    */
      SystemError;                                                                             /* 0x006a|check    */
  }                                                                                            /* 0x006a|check    */
}                                                                                              /* 0x006a|check    */
/*********************************************************************************************//* 0x006f|check    */
/*********************************************************************************************//* 0x0070|check    */
/*********                                                                              ******//* 0x0071|check    */
/*********   PrimeGetPrime(PrimeValueAddr, PrimeIndex)                                  ******//* 0x0072|check    */
/*********                                                                              ******//* 0x0073|check    */
/*********------------------------------------------------------------------------------******//* 0x0074|check    */
/*********                                                                              ******//* 0x0075|check    */
/*********  This routine gets the prime number contained at a specified location        ******//* 0x0076|check    */
/*********  in the prime number table.                                                  ******//* 0x0077|check    */
/*********                                                                              ******//* 0x0078|check    */
/*********------------------------------------------------------------------------------******//* 0x0079|check    */
/*********  Inputs:                                                                     ******//* 0x007a|check    */
/*********                                                                              ******//* 0x007b|check    */
/*********      PrimeIndex:       Index in Prime Number Table                           ******//* 0x007c|check    */
/*********                                                                              ******//* 0x007d|check    */
/*********------------------------------------------------------------------------------******//* 0x007e|check    */
/*********  Output:                                                                     ******//* 0x007f|check    */
/*********      PrimeValueAddr:   Address of unsigned long variable to receive the      ******//* 0x0080|check    */
/*********                        prime number contained in the specified index         ******//* 0x0081|check    */
/*********                        in the Prime Number Table                             ******//* 0x0082|check    */
/*********                                                                              ******//* 0x0083|check    */
/*********------------------------------------------------------------------------------******//* 0x0084|check    */
/*********  Returns:                                                                    ******//* 0x0085|check    */
/*********      Success:          Successful Operation.                                 ******//* 0x0086|check    */
/*********      0xffff:           System Failure.                                       ******//* 0x0087|check    */
/*********                                                                              ******//* 0x0088|check    */
/*********************************************************************************************//* 0x0089|check    */
/*********************************************************************************************//* 0x008a|check    */
ULONG  PrimeGetPrime                                                                           /* 0x008d|check    */
  (                                                                                            /* 0x008d|check    */
    ULONG_ADDR PrimeValueAddr,                                                                 /* 0x008e|check    */
    ULONG PrimeIndex                                                                           /* 0x008f|check    */
  )                                                                                            /* 0x0090|check    */
{                                                                                              /* 0x0090|check    */
  switch(WrapperState)                                                                         /* 0x0090|check    */
  {                                                                                            /* 0x0090|check    */
    case _ReadyState:                                                                          /* 0x0090|check    */
      WrapperState = 0xffff;                                                                   /* 0x0090|check    */
/*********************************************************************************************//* 0x0090|check    */
/*****                                                                                   *****//* 0x0090|check    */
/*****                     INSTANCE PM/FL TESTS                                          *****//* 0x0090|check    */
/*****                                                                                   *****//* 0x0090|check    */
/*********************************************************************************************//* 0x0090|check    */
      if((__InstanceHandle >  NoInstances)                         ||                          /* 0x0090|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0090|check    */
         (__InstanceFirst  == 0)                                   ||                          /* 0x0090|check    */
         (__InstanceLast   == 0)                                   ||                          /* 0x0090|check    */
         (__InstanceSize   == 0)                                   ||                          /* 0x0090|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x0090|check    */
         (__InstanceFirst  != InstanceFirst(__InstanceHandle))     ||                          /* 0x0090|check    */
         (__InstanceLast   != InstanceLast (__InstanceHandle))     ||                          /* 0x0090|check    */
         (__InstanceSize   != InstanceSize (__InstanceHandle)))                                /* 0x0090|check    */
      {                                                                                        /* 0x0090|check    */
        SystemError;                                                                           /* 0x0090|check    */
      }                                                                                        /* 0x0090|check    */
/*********************************************************************************************//* 0x0090|check    */
      auto WRAPPER_CLASS_DATA_ADDR InstanceLink;                                               /* 0x0090|check    */
      InstanceLink = __InstanceLink;                                                           /* 0x0090|check    */
/*********************************************************************************************//* 0x0090|check    */
      if((__InstanceFirst  != __InstanceLink->__class_addr)        ||                          /* 0x0090|check    */
         (__InstanceLast   != __InstanceLink->__last_addr)         ||                          /* 0x0090|check    */
         (__InstanceSize   != __InstanceLink->__class_size))                                   /* 0x0090|check    */
      {                                                                                        /* 0x0090|check    */
        SystemError;                                                                           /* 0x0090|check    */
      }                                                                                        /* 0x0090|check    */
/*********************************************************************************************//* 0x0090|check    */
      {                                                                                        /* 0x0090|check    */
        ULONG prime_number = 0;                                                                /* 0x0090|check    */
        if(0xffff == PrimeGenGetPrime(                                                         /* 0x0090|check    */
              &prime_number,                                                                   /* 0x0090|check    */
              PrimeIndex))                                                                     /* 0x0090|check    */
        {                                                                                      /* 0x0090|check    */
          SystemError;                                                                         /* 0x0090|check    */
        }                                                                                      /* 0x0090|check    */
        *PrimeValueAddr = prime_number;                                                        /* 0x0090|check    */
        }                                                                                      /* 0x0090|check    */
        WrapperState = _ReadyState;                                                            /* 0x0090|check    */
        return(0x0000);                                                                        /* 0x0090|check    */
      default:                                                                                 /* 0x0090|check    */
        WrapperState = 0xffff;                                                                 /* 0x0090|check    */
        MemSet(&error_messages,     0, sizeof(ERROR_MESSAGES));                                /* 0x0090|check    */
        MemSet (&WRAPPER_cpp_file_name[0],       0, 17);                                       /* 0x0090|check    */
        MemCCpy(&WRAPPER_cpp_file_name[0], "primewrp", 0, 16);                                 /* 0x0090|check    */
        SystemError;                                                                           /* 0x0090|check    */
    }                                                                                          /* 0x0090|check    */
  }                                                                                            /* 0x0090|check    */
/*********************************************************************************************//* 0x0095|check    */
/*********************************************************************************************//* 0x0096|check    */
/*********                                                                              ******//* 0x0097|check    */
/*********                PrimeClose                                                    ******//* 0x0098|check    */
/*********                                                                              ******//* 0x0099|check    */
/*********------------------------------------------------------------------------------******//* 0x009a|check    */
/*********                                                                              ******//* 0x009b|check    */
/*********  This routine frees the Object Related memory                                ******//* 0x009c|check    */
/*********                                                                              ******//* 0x009d|check    */
/*********------------------------------------------------------------------------------******//* 0x009e|check    */
/*********  Returns:                                                                    ******//* 0x009f|check    */
/*********      Success:        Successful Operation.                                   ******//* 0x00a0|check    */
/*********      0xffff:         System Failure.                                         ******//* 0x00a1|check    */
/*********                                                                              ******//* 0x00a2|check    */
/*********************************************************************************************//* 0x00a3|check    */
/*********************************************************************************************//* 0x00a4|check    */
  ULONG  PrimeClose                                                                            /* 0x00a7|check     */
    (                                                                                          /* 0x00a7|check     */
      void                                                                                     /* 0x00a8|check     */
    )                                                                                          /* 0x00a8|check     */
  {                                                                                            /* 0x00a8|check     */
    switch(WrapperState)                                                                       /* 0x00a8|check     */
    {                                                                                          /* 0x00a8|check     */
      case _ReadyState:                                                                        /* 0x00a8|check     */
        WrapperState = 0xffff;                                                                 /* 0x00a8|check     */
/*********************************************************************************************//* 0x00a8|check     */
/*****                                                                                   *****//* 0x00a8|check     */
/*****                     INSTANCE PM/FL TESTS                                          *****//* 0x00a8|check     */
/*****                                                                                   *****//* 0x00a8|check     */
/*********************************************************************************************//* 0x00a8|check     */
        if((__InstanceHandle >  NoInstances)                         ||                        /* 0x00a8|check     */
/*****-----------------------------------------------------------------------------------*****//* 0x00a8|check     */
           (__InstanceFirst  == 0)                                   ||                        /* 0x00a8|check     */
           (__InstanceLast   == 0)                                   ||                        /* 0x00a8|check     */
           (__InstanceSize   == 0)                                   ||                        /* 0x00a8|check     */
/*****-----------------------------------------------------------------------------------*****//* 0x00a8|check     */
           (__InstanceFirst  != InstanceFirst(__InstanceHandle))     ||                        /* 0x00a8|check     */
           (__InstanceLast   != InstanceLast (__InstanceHandle))     ||                        /* 0x00a8|check     */
           (__InstanceSize   != InstanceSize (__InstanceHandle)))                              /* 0x00a8|check     */
        {                                                                                      /* 0x00a8|check     */
          SystemError;                                                                         /* 0x00a8|check     */
        }                                                                                      /* 0x00a8|check     */
/*********************************************************************************************//* 0x00a8|check     */
        auto WRAPPER_CLASS_DATA_ADDR InstanceLink;                                             /* 0x00a8|check     */
        InstanceLink = __InstanceLink;                                                         /* 0x00a8|check     */
/*********************************************************************************************//* 0x00a8|check     */
        if((__InstanceFirst  != __InstanceLink->__class_addr)        ||                        /* 0x00a8|check     */
           (__InstanceLast   != __InstanceLink->__last_addr)         ||                        /* 0x00a8|check     */
           (__InstanceSize   != __InstanceLink->__class_size))                                 /* 0x00a8|check     */
        {                                                                                      /* 0x00a8|check     */
          SystemError;                                                                         /* 0x00a8|check     */
        }                                                                                      /* 0x00a8|check     */
/*********************************************************************************************//* 0x00a8|check     */
        if(PrimeGenClose == 0xffff)                                                            /* 0x00a8|check     */
        {                                                                                      /* 0x00a8|check     */
          SystemError;                                                                         /* 0x00a8|check     */
        }                                                                                      /* 0x00a8|check     */
        WrapperState = _InitializedState;                                                      /* 0x00a8|check     */
        return(0x0000);                                                                        /* 0x00a8|check     */
      default:                                                                                 /* 0x00a8|check     */
        WrapperState = 0xffff;                                                                 /* 0x00a8|check     */
        MemSet(&error_messages,     0, sizeof(ERROR_MESSAGES));                                /* 0x00a8|check     */
        MemSet (&WRAPPER_cpp_file_name[0],       0, 17);                                       /* 0x00a8|check     */
        MemCCpy(&WRAPPER_cpp_file_name[0], "primewrp", 0, 16);                                 /* 0x00a8|check     */
        SystemError;                                                                           /* 0x00a8|check     */
    }                                                                                          /* 0x00a8|check     */
  }                                                                                            /* 0x00a8|check     */
/*********************************************************************************************//* 0x00ad|check    */
/*********************************************************************************************//* 0x00ae|check    */
/*********                                                                              ******//* 0x00af|check    */
/*********                PrimeErrorReport(MessageAddr, MessageNo)                      ******//* 0x00b0|check    */
/*********                                                                              ******//* 0x00b1|check    */
/*********------------------------------------------------------------------------------******//* 0x00b2|check    */
/*********                                                                              ******//* 0x00b3|check    */
/*********  This routine places the specified error message into the String Array       ******//* 0x00b4|check    */
/*********                                                                              ******//* 0x00b5|check    */
/*********------------------------------------------------------------------------------******//* 0x00b6|check    */
/*********                                                                              ******//* 0x00b7|check    */
/*********  Input Parameter:                                                            ******//* 0x00b8|check    */
/*********      1)  MessageNo:  The message number (0 -- first one received)            ******//* 0x00b9|check    */
/*********                                                                              ******//* 0x00ba|check    */
/*********------------------------------------------------------------------------------******//* 0x00bb|check    */
/*********                                                                              ******//* 0x00bc|check    */
/*********  Output Parameter::                                                          ******//* 0x00bd|check    */
/*********      1)  MessageAddr: The address of the character array to store the        ******//* 0x00be|check    */
/*********                       message. This string must have at least 32 bytes.      ******//* 0x00bf|check    */
/*********------------------------------------------------------------------------------******//* 0x00c0|check    */
/*********  Returns:                                                                    ******//* 0x00c1|check    */
/*********      0x0000:         Successful Operation.                                   ******//* 0x00c2|check    */
/*********      0xffff:         Specified Message does not exist                        ******//* 0x00c3|check    */
/*********                                                                              ******//* 0x00c4|check    */
/*********************************************************************************************//* 0x00c5|check    */
/*********************************************************************************************//* 0x00c6|check    */
  ULONG PrimeErrorReport                                                                       /* 0x00c9|check    */
    (                                                                                          /* 0x00c9|check    */
      SCHAR_ADDR       MessageAddr,                                                            /* 0x00c9|check    */
      ULONG            MessageNo                                                               /* 0x00c9|check    */
    )                                                                                          /* 0x00c9|check    */
  {                                                                                            /* 0x00c9|check    */
    ULONG  flag = 0xffff;                                                                      /* 0x00c9|check    */
/*********************************************************************************************//* 0x00c9|check    */
/*********************************************************************************************//* 0x00c9|check    */
    if(MessageNo < NoErrorMessages)                                                            /* 0x00c9|check    */
    {                                                                                          /* 0x00c9|check    */
      sprintf(MessageAddr,  "%16s, %d",                                                        /* 0x00c9|check    */
               ErrorFileNameAddr(MessageNo),                                                   /* 0x00c9|check    */
               ErrorLineNo(MessageNo));                                                        /* 0x00c9|check    */
      flag = 0x0000;                                                                           /* 0x00c9|check    */
    }                                                                                          /* 0x00c9|check    */
    return(flag);                                                                              /* 0x00c9|check    */
  }                                                                                            /* 0x00c9|check    */
/*********************************************************************************************//* 0x00ce|check    */
/*********************************************************************************************//* 0x00cf|check    */
/*********                                                                              ******//* 0x00d0|check    */
/*********                PrimeDestruct(void)                                           ******//* 0x00d1|check    */
/*********                                                                              ******//* 0x00d2|check    */
/*********------------------------------------------------------------------------------******//* 0x00d3|check    */
/*********                                                                              ******//* 0x00d4|check    */
/*********  This routine completes memory cleanup                                       ******//* 0x00d5|check    */
/*********                                                                              ******//* 0x00d6|check    */
/*********------------------------------------------------------------------------------******//* 0x00d7|check    */
/*********  Returns:                                                                    ******//* 0x00d8|check    */
/*********      0x0000:         Successful Operation.                                   ******//* 0x00d9|check    */
/*********      0xffff:         System Error                                            ******//* 0x00da|check    */
/*********                                                                              ******//* 0x00db|check    */
/*********************************************************************************************//* 0x00dc|check    */
/*********************************************************************************************//* 0x00dd|check    */
  ULONG  PrimeDestruct(void)                                                                   /* 0x00e0|check    */
  {                                                                                            /* 0x00e0|check    */
    switch(WrapperState)                                                                       /* 0x00e0|check    */
    {                                                                                          /* 0x00e0|check    */
      case _InitializedState:                                                                  /* 0x00e0|check    */
        WrapperState = 0xffff;                                                                 /* 0x00e0|check    */
/*********************************************************************************************//* 0x00e0|check    */
/*****                                                                                   *****//* 0x00e0|check    */
/*****                     INSTANCE PM/FL TESTS                                          *****//* 0x00e0|check    */
/*****                                                                                   *****//* 0x00e0|check    */
/*********************************************************************************************//* 0x00e0|check    */
        if((__InstanceHandle >  NoInstances)                         ||                        /* 0x00e0|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e0|check    */
           (__InstanceFirst  == 0)                                   ||                        /* 0x00e0|check    */
           (__InstanceLast   == 0)                                   ||                        /* 0x00e0|check    */
           (__InstanceSize   == 0)                                   ||                        /* 0x00e0|check    */
/*****-----------------------------------------------------------------------------------*****//* 0x00e0|check    */
           (__InstanceFirst  != InstanceFirst(__InstanceHandle))     ||                        /* 0x00e0|check    */
           (__InstanceLast   != InstanceLast (__InstanceHandle))     ||                        /* 0x00e0|check    */
           (__InstanceSize   != InstanceSize (__InstanceHandle)))                              /* 0x00e0|check    */
        {                                                                                      /* 0x00e0|check    */
          SystemError;                                                                         /* 0x00e0|check    */
        }                                                                                      /* 0x00e0|check    */
/*********************************************************************************************//* 0x00e0|check    */
        auto WRAPPER_CLASS_DATA_ADDR InstanceLink;                                             /* 0x00e0|check    */
        InstanceLink = __InstanceLink;                                                         /* 0x00e0|check    */
/*********************************************************************************************//* 0x00e0|check    */
        if((__InstanceFirst  != __InstanceLink->__class_addr)        ||                        /* 0x00e0|check    */
           (__InstanceLast   != __InstanceLink->__last_addr)         ||                        /* 0x00e0|check    */
           (__InstanceSize   != __InstanceLink->__class_size))                                 /* 0x00e0|check    */
        {                                                                                      /* 0x00e0|check    */
          SystemError;                                                                         /* 0x00e0|check    */
        }                                                                                      /* 0x00e0|check    */
        if(WRAPPER_Destruct(&__InstanceAddr, __InstanceHandle))                                /* 0x00e0|check    */
        {                                                                                      /* 0x00e0|check    */
          SystemError;                                                                         /* 0x00e0|check    */
        }                                                                                      /* 0x00e0|check    */
        return(0x0000);                                                                        /* 0x00e0|check    */
      default:                                                                                 /* 0x00e0|check    */
        WrapperState = 0xffff;                                                                 /* 0x00e0|check    */
        MemSet (&WRAPPER_cpp_file_name[0],       0, 17);                                       /* 0x00e0|check    */
        MemCCpy(&WRAPPER_cpp_file_name[0], "primewrp", 0, 16);                                 /* 0x00e0|check    */
        MemSet(&error_messages,     0, sizeof(ERROR_MESSAGES));                                /* 0x00e0|check    */
        SystemError;                                                                           /* 0x00e0|check    */
    }                                                                                          /* 0x00e0|check    */
  }                                                                                            /* 0x00e0|check    */
