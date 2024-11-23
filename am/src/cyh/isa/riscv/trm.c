#include <am.h>
#include <riscv.h>
#include <klib.h>

extern char _heap_start;
extern char _pmem_end;
int main(const char *args);
void __am_init_uartlite(void);
void __am_uartlite_putchar(char ch);

_Area _heap = {
  .start = &_heap_start,
  .end = &_pmem_end,
};

void _putc(char ch) {
  __am_uartlite_putchar(ch);
}

#define EXIT_POS 0x40000000
#define EXIT_CODE 0xdeadbeef

void _halt(int code) {
  __asm__ volatile("mv a0, %0" : :"r"(code));
  // exit
  __asm__ volatile("li t0, %0; li t1, %1; sw t1, 0(t0)" : : "i"(EXIT_POS), "i"(EXIT_CODE));

  // should not reach here during simulation
  printf("Exit with code = %d\n", code);

  // should not reach here on FPGA
  while (1);
}

void _trm_init() {
  __am_init_uartlite();
  extern const char __am_mainargs;
  int ret = main(&__am_mainargs);
  _halt(ret);
}
