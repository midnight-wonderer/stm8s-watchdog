# STM8S Watchdog

## What is it?

It is an opinionated firmware for utilizing IWDG (independent watchdog) of STM8 devices.

## What's opinionated about this firmware?

STM8 devices have two kinds of watchdog, WWDG (window watchdog), and IWDG (independent watchdog). The author of the firmware ruled out the usage of WWDG because it hides potential software bugs. Watchdogs are not a solution to solve software bugs; no one should rely on them for such use cases. Besides, who needs two watchdogs anyway.  
For this firmware, the "watchdog" always means IWDG.

The firmware shipped with sane defaults. No option for you to choose. The watchdog always has a timeout period of 500 milliseconds. Just set it up and refresh the it frequently.

## Which devices are supported by this firmware?

See the readme of [the underlying headers for the list of supported devices](https://github.com/the-cave/stm8s-header/blob/sdcc-patched/README.md#currently-supported-targets).

## Dependencies

* [STM8S header](https://github.com/the-cave/stm8s-header)

## How to use the library?

- First, adding this library and its dependencies to your project.  
You can accomplish this in numerous ways depends on your setup. The opinionated way to do it is by using the [git submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) and the [Universal STM8 Builder](https://github.com/midnight-wonderer/universal-stm8-builder).
- Include the firmware header to where you wanted to use the firmware
  ~~~c
  #include "stm8s_watchdog.h"
  ~~~
- Start the watchdog
  ~~~c
  stm8s_watchdog__setup();
  ~~~
- Refresh it frequently to prevent the reset signal. (Probably in the main loop)
  ~~~c
  stm8s_watchdog__refresh();
  ~~~

## Using other timeout value

If you are not OK with 500 milliseconds, you can tweak the value of `IWDG_RLR` by setting the value in `STM8S_WATCHDOG__RELOAD_VALUE` at compile time.
The resolution of selectable periods is 4ms nonetheless.  
T = 4ms * (IWDG_RLR + 1)  
The default `IWDG_RLR` value is 124.

## License

STM8S Watchdog is released under the [BSD 3-Clause License](LICENSE.md). :tada:
