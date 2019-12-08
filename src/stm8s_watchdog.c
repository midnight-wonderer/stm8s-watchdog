// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#include "stm8s_watchdog.h"

#ifndef STM8S_WATCHDOG__RELOAD_VALUE
// default to 500 milliseconds
#define STM8S_WATCHDOG__RELOAD_VALUE 124
#endif

void stm8s_watchdog__setup(void) {
  IWDG->KR = 0xcc;  // start
  IWDG->KR = 0x55;  // unlock
  // Refer to RM0016 section 14.2
  IWDG->PR = 6;                              // divide by 256
  IWDG->RLR = STM8S_WATCHDOG__RELOAD_VALUE;  // reload to 500 milliseconds
  IWDG->KR = 0xaa;                           // reloading
}
