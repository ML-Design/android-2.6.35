cmd_arch/arm/mach-msm/idle-v6.o := arm-eabi-gcc -Wp,-MD,arch/arm/mach-msm/.idle-v6.o.d  -nostdinc -isystem /home/hyunwoo82.park/gb_original/prebuilt/linux-x86/toolchain/arm-eabi-4.4.3/bin/../lib/gcc/arm-eabi/4.4.3/include -I/home/hyunwoo82.park/kernel/kernel/arch/arm/include -Iinclude  -include include/generated/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-msm/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -funwind-tables  -D__LINUX_ARM_ARCH__=6 -march=armv6k -mtune=arm1136j-s -include asm/unified.h -msoft-float -gdwarf-2       -c -o arch/arm/mach-msm/idle-v6.o arch/arm/mach-msm/idle-v6.S

deps_arch/arm/mach-msm/idle-v6.o := \
  arch/arm/mach-msm/idle-v6.S \
    $(wildcard include/config/arch/msm7x27.h) \
    $(wildcard include/config/oprofile.h) \
  /home/hyunwoo82.park/kernel/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/hyunwoo82.park/kernel/kernel/arch/arm/include/asm/linkage.h \
  /home/hyunwoo82.park/kernel/kernel/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/smp.h) \
  /home/hyunwoo82.park/kernel/kernel/arch/arm/include/asm/ptrace.h \
    $(wildcard include/config/cpu/endian/be8.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/hyunwoo82.park/kernel/kernel/arch/arm/include/asm/hwcap.h \

arch/arm/mach-msm/idle-v6.o: $(deps_arch/arm/mach-msm/idle-v6.o)

$(deps_arch/arm/mach-msm/idle-v6.o):
