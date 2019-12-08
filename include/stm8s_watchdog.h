// Copyright (c) 2019 Sarun Rattanasiri
// under the 3-Clause BSD License
// https://opensource.org/licenses/BSD-3-Clause

#ifndef __STM8S_WATCHDOG_H
#define __STM8S_WATCHDOG_H

#include <stdint.h>
#include "stm8s.h"
#include "stm8s_iwdg.h"

void stm8s_watchdog__setup(void);

#define stm8s_watchdog__refresh() \
  do {                            \
    IWDG->KR = 0xaa;              \
  } while (0)

#endif
