//
// Copyright (c) 2017 The nanoFramework project contributors
// See LICENSE file in the project root for full license information.
//

#ifndef FLASH_LLD_H
#define FLASH_LLD_H

#include "stm32_registry.h"

#if (HAL_USE_STM32_FLASH == TRUE)

///////////////////////////////////////////////////////////////////////////////
// Driver constants.                                                         //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Driver pre-compile time settings.                                         //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Derived constants and error checks.                                       //
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Driver data structures and types.                                         //
///////////////////////////////////////////////////////////////////////////////

// From STMicroelectronics Cube HAL 
// HAL Status structures definition  
typedef struct SMT32FlashDriver {
  
  // pointer to the FLASH Registers 
  FLASH_TypeDef               *flash;

}SMT32FlashDriver;

///////////////////////////////////////////////////////////////////////////////
// Driver macros.                                                            //
///////////////////////////////////////////////////////////////////////////////

// From STMicroelectronics Cube HAL 
#define FLASH                       ((FLASH_TypeDef *) FLASH_R_BASE)
#define HAL_IS_BIT_SET(REG, BIT)    (((REG) & (BIT)) != RESET)
#define FLASH_FLAG_BSY              FLASH_SR_BSY  // FLASH Busy flag

#define F0_SERIES_SECTOR_SIZE       ((uint32_t)0x00001000U)

///////////////////////////////////////////////////////////////////////////////
// External declarations.                                                    //
///////////////////////////////////////////////////////////////////////////////

#if STM32FLASH_USE_FLASH
SMT32FlashDriver STM32FLASH;
#endif

#ifdef __cplusplus
extern "C" {
#endif
  
  void flash_lld_init();
  void flash_lld_readBytes(uint32_t startAddress, uint32_t length, uint8_t* buffer);
  bool flash_lld_write(uint32_t startAddress, uint32_t length, const uint8_t* buffer);
  bool flash_lld_isErased(uint32_t startAddress, uint32_t length);
  bool flash_lld_erase(uint32_t address);
  uint8_t flash_lld_getSector(uint32_t address);

#ifdef __cplusplus
}
#endif

#endif // HAL_USE_STM32_FLASH

#endif // FLASH_LLD_H
