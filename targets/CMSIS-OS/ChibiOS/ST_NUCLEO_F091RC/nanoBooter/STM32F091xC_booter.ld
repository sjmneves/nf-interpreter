/*
//
// Copyright (c) 2017 The nanoFramework project contributors
// Portions Copyright (c) 2006..2015 Giovanni Di Sirio.  All rights reserved.
// See LICENSE file in the project root for full license information.
//
*/


/*
 * STM32F091xC memory setup.
 */
MEMORY
{
    flash       : org = 0x08000000, len = 16k     /* space reserved for nanoBooter (1st eight sectors 0x08000000 to 0x08004000)*/
    deployment  : org = 0x00000000, len = 0       /* space reserved for application deployment */
    ramvt       : org = 0x00000000, len = 0       /* initial RAM address is reserved for a copy of the vector table */
    ram0        : org = 0x20000000, len = 32k
    ram1        : org = 0x00000000, len = 0
    ram2        : org = 0x00000000, len = 0
    ram3        : org = 0x00000000, len = 0
    ram4        : org = 0x00000000, len = 0
    ram5        : org = 0x00000000, len = 0
    ram6        : org = 0x00000000, len = 0
    ram7        : org = 0x00000000, len = 0
}

/* RAM region to be used for Main stack. This stack accommodates the processing
   of all exceptions and interrupts*/
REGION_ALIAS("MAIN_STACK_RAM", ram0);

/* RAM region to be used for the process stack. This is the stack used by
   the main() function.*/
REGION_ALIAS("PROCESS_STACK_RAM", ram0);

/* RAM region to be used for data segment.*/
REGION_ALIAS("DATA_RAM", ram0);

/* RAM region to be used for BSS segment.*/
REGION_ALIAS("BSS_RAM", ram0);

/* RAM region to be used for the default heap.*/
REGION_ALIAS("HEAP_RAM", ram0);

/* RAM region to be used for the nanoFramework CLR managed heap.*/
REGION_ALIAS("CLR_MANAGED_HEAP_RAM", ram0);

INCLUDE rules.ld
