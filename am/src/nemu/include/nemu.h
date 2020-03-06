#ifndef __NEMU_H__
#define __NEMU_H__

#include <klib-macros.h>

#include ISA_H // "x86.h", "mips32.h", ...

#ifdef __ARCH_X86_NEMU
# define SERIAL_PORT  0x3f8
# define KBD_ADDR     0x60
# define RTC_ADDR     0x48
# define SCREEN_ADDR  0x100
# define SYNC_ADDR    0x104
# define FB_ADDR      0xa0000000
#elif defined(__ARCH_RISCV32_NOOP)
# define KBD_ADDR     0x40900000
# define RTC_ADDR     0x40700000
# define SCREEN_ADDR  0x40800000
# define SYNC_ADDR    0x40800004
# define FB_ADDR      0x40000000
#elif defined(__ARCH_RISCV64_NOOP)
# define KBD_ADDR     0x40900000
# define RTC_ADDR     0x4070bff8
# define SCREEN_ADDR  0x40800000
# define SYNC_ADDR    0x40800004
# define FB_ADDR      0x40000000
#else
# define SERIAL_PORT  0xa10003f8
# define KBD_ADDR     0xa1000060
# define RTC_ADDR     0xa1000048
# define SCREEN_ADDR  0xa1000100
# define SYNC_ADDR    0xa1000104
# define FB_ADDR      0xa0000000
#endif

#define PGSIZE    4096

#define MMIO_BASE 0xa0000000
#define MMIO_SIZE 0x10000000

extern char _pmem_start, _pmem_end;

#define NEMU_PADDR_SPACE \
  RANGE(&_pmem_start, &_pmem_end), \
  RANGE(0xa0000000, 0xa0000000 + 0x80000), /* vmem */ \
  RANGE(0xa1000000, 0xa1000000 + 0x1000)   /* serial, rtc, screen, keyboard */

#endif
