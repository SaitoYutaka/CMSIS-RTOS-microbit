CC = arm-none-eabi-gcc
TARGET_ARCH = -mcpu=cortex-m0
CFLAGS = -D__CORTEX_M0 -D__CMSIS_RTOS -DARMCM0 -DNRF51 -mthumb -mabi=aapcs \
-Wall -O0 -g -mfloat-abi=soft -ffunction-sections -fdata-sections -fno-strict-aliasing -fomit-frame-pointer \
-fno-builtin --short-enums
MCPU=cortex-m0
INCDIR =-I ../CMSIS_5/CMSIS/RTOS/RTX/INC/ \
-I ../CMSIS_5/CMSIS/RTOS/RTX/UserCodeTemplates/ \
-I ../CMSIS_5/CMSIS/Core/Include/ \
-I ../nrfx/ \
-I ../nrfx/templates/ \
-I ../nrfx/mdk/ \
-I ../nrfx/hal/

LDFLAGS = -mthumb -mabi=aapcs
LDFLAGS += -mcpu=cortex-m0
LDFLAGS += -Wl,--gc-sections
LDFLAGS += --specs=nano.specs -lc -lnosys -nostdlib

OBJS = \
../newlib-cygwin/build/arm-none-eabi/thumb/v6-m/libgloss/arm/crt0.o \
RTX_Conf_CM.o \
main.o \
gcc_startup_nrf51.o \
system_nrf51.o \
SVC_Table.o \
HAL_CM.o \
HAL_CM0.o \
rt_CMSIS.o \
rt_Mailbox.o \
rt_MemBox.o \
rt_System.o \
rt_Robin.o \
rt_Event.o \
rt_List.o \
rt_Memory.o \
rt_Mutex.o \
rt_Task.o \
rt_Timer.o \
rt_Time.o \
rt_Semaphore.o \

all : main.hex

main.hex : main.elf
	arm-none-eabi-objcopy main.elf main.hex -O ihex

main.elf : $(OBJS)
	arm-none-eabi-gcc $(LDFLAGS) -T ../nrfx/mdk/nrf51_xxab.ld -L ../nrfx/mdk/ -L ../newlib-cygwin/build/arm-none-eabi/thumb/v6-m/newlib -o main.elf $(OBJS)

HAL_CM0.o : ../CMSIS_5/CMSIS/RTOS/RTX/SRC/GCC/HAL_CM0.S
	$(CC) -c -g -mcpu=$(MCPU) -o $@ $<

RTX_Conf_CM.o : ../CMSIS_5/CMSIS/RTOS/RTX/Templates/RTX_Conf_CM.c
	$(CC) $(TARGET_ARCH) $(INCDIR) $(CFLAGS) -o $@ -c $<

gcc_startup_nrf51.o : ../nrfx/mdk/gcc_startup_nrf51.S
	$(CC) -c -g -mcpu=$(MCPU) -o $@ $<

system_nrf51.o : ../nrfx/mdk/system_nrf51.c
	$(CC) $(TARGET_ARCH) $(INCDIR) $(CFLAGS) -o $@ -c $<

SVC_Table.o : ../CMSIS_5/CMSIS/RTOS/RTX/SRC/GCC/SVC_Table.S
	$(CC) -c -g -mcpu=$(MCPU) -o $@ $<

%.o: ../CMSIS_5/CMSIS/RTOS/RTX/SRC/%.c
	$(CC) $(TARGET_ARCH) $(INCDIR) $(CFLAGS) -o $@ -c $<

main.o : main.c
	$(CC) $(TARGET_ARCH) $(INCDIR) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.hex
	rm -f *.o
	rm -f *.elf

