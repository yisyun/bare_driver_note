TARGET := led
CROSS_COMPILE := arm-linux-gnueabihf-

CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)ld
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump

INCDIRS 		:=	reg \
					modules/clk \
					modules/led \
					modules/delay

SRCDIRS 		:=	project \
					modules/clk \
					modules/led \
					modules/delay
#設定gcc include變數
INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))
#設定obj/*.o變數
SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
SFILENDIR		:= $(notdir  $(SFILES))
CFILENDIR		:= $(notdir  $(CFILES))
SOBJS			:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS			:= $(SOBJS) $(COBJS) 

VPATH			:= $(SRCDIRS)

.PHONY: clean

$(TARGET).bin:$(OBJS)
	@echo $(OBJS)
	$(LD) -Timx6ul.lds -o $(TARGET).elf $^
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS) : obj/%.o : %.S
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<
	
$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -nostdlib -c -O2 $(INCLUDE) -o $@ $<
	
clean:
	rm -rf *.o $(TARGET).bin $(TARGET).elf $(TARGET).dis $(SOBJS) $(COBJS)
	
	
