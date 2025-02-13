objs := start.o led.o
objs_as := led_as.o

led.bin:$(objs)
	arm-linux-gnueabihf-ld -Timx6ul.lds -o led.elf $^
	arm-linux-gnueabihf-objcopy -O binary -S led.elf $@
	arm-linux-gnueabihf-objdump -D -m arm led.elf > led.dis

led_as.bin:$(objs_as)
	arm-linux-gnueabihf-ld -Ttext 0x87800000 -o led.elf $^
	arm-linux-gnueabihf-objcopy -O binary -S led.elf $@
	arm-linux-gnueabihf-objdump -D -m arm led.elf > led.dis

%.o:%.s
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<
	
%.o:%.S
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<
	
%.o:%.c
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<
	
clean:
	rm -rf *.o led.bin led.elf led.dis led_as.bin led_as.elf \
	led_as.dis
	
	
