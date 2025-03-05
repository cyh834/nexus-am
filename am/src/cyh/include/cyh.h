#ifndef __CYH_H__
#define __CYH_H__

#include <am.h>
#include <xsextra.h>
#include <klib.h>
#include <klib-macros.h>

#include ISA_H // "x86.h", "mips32.h", ...

//# define RTC_ADDR     0x3800bff8
//# define SCREEN_ADDR  0x40001000
//# define SYNC_ADDR    0x40001004
//# define FB_ADDR      0x50000000
#define MAX_INTERNAL_INTR 10UL
#define MAX_EXTERNAL_INTR      64UL
#define INTR_GEN_ADDR          (0x40070000UL)
#define INTR_RANDOM            (INTR_GEN_ADDR + (MAX_EXTERNAL_INTR / 8))
#define INTR_RANDOM_MASK       (INTR_GEN_ADDR + (MAX_EXTERNAL_INTR / 8) * 2)
#define PLIC_BASE_ADDR         (0x3c000000UL)


#endif
