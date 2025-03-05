include $(AM_HOME)/am/arch/isa/riscv64.mk

AM_SRCS := cyh/isa/riscv/trm.c \
           cyh/common/mainargs.S \
           noop/isa/riscv/perf.c \
           noop/common/uartlite.c \
           nemu/isa/riscv/cte.c \
           nemu/isa/riscv/trap.S \
           nemu/isa/riscv/cte64.c \
           nemu/isa/riscv/mtime.S \
           nemu/isa/riscv/vme.c \
           cyh/common/ioe.c \
           noop/common/input.c \
           noop/common/timer.c \
           noop/isa/riscv/instr.c \
           cyh/isa/riscv/mpe.c \
           cyh/isa/riscv/clint.c \
           cyh/isa/riscv/pmp.c \
           cyh/isa/riscv/plic.c \
           cyh/isa/riscv/pma.c \
           cyh/isa/riscv/cache.c \
           cyh/isa/riscv/boot/start.S \

CFLAGS  += -I$(AM_HOME)/am/src/nemu/include -I$(AM_HOME)/am/src/cyh/include -DISA_H=\"riscv.h\"

ASFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/cyh/common/mainargs.S

LDFLAGS += -L $(AM_HOME)/am/src/cyh/ldscript
LDFLAGS += -T $(AM_HOME)/am/src/cyh/isa/riscv/boot/loader64.ld

image:
	@echo + LD "->" $(BINARY_REL).elf
	@$(LD) $(LDFLAGS) --gc-sections -o $(BINARY).elf --start-group $(LINK_FILES) --end-group
	@$(OBJDUMP) -d $(BINARY).elf > $(BINARY).txt
	@echo + OBJCOPY "->" $(BINARY_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(BINARY).elf $(BINARY).bin

#run:
#	$(MAKE) -C $(NOOP_HOME) emu-run IMAGE="$(BINARY).bin" DATAWIDTH=64
