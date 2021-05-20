# define parameters
PARAMETERS_GCC = -m32 -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscore
PARAMETERS_ASM = --32
PARAMETERS_LINKER = -melf_i386

# define .o file names
obj = junk/startk.o \
	  junk/main.o

# define compilation parameters
junk/%.o: src/%.c
	gcc $(PARAMETERS_GCC) -Iinclude -c -o $@ $<

junk/%.o: src/%.s
	as $(PARAMETERS_ASM) -o $@ $<

kernel.bin: link.ld $(obj)
	ld $(PARAMETERS_LINKER) -T $< -o $@ $(obj)

mkimg: kernel.bin
	mkdir img
	mkdir img/boot
	mkdir img/boot/grub
	cp kernel.bin img/boot/
	cp grub.cfg img/boot/grub/
	grub-mkrescue --output=TutOS.img img
	rm -rf img

run:
	qemu-system-x86_64 TutOS.img