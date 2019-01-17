#ifndef __ARCH_H__
#define __ARCH_H__

#include <am.h>

#define PMEM_SIZE (128 * 1024 * 1024)
#define PGSIZE    4096

struct _Context {
  struct _Protect *prot;
  uint32_t gpr[31];
  uint32_t lo, hi;
  uint32_t cause, status, epc;
};

#define GPR1 gpr[4]
#define GPR2 gpr[5]
#define GPR3 gpr[6]
#define GPR4 gpr[7]
#define GPRx gpr[2]

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif
