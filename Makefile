cc=gcc
ccargs=-c -ffreestanding -O2 -Wall -Wextra
ld=gcc
ldargs=-shared -ffreestanding -O2 -nostdlib

all-x86:	ind/rot_main.c \
			ind/rot_log.c \
			x86/rot_linkscript.ld \
			x86/rot_bootstrap.asm \
			x86/rot_videoManager.c \
			x86/rot_video.h \
			x86/rot_terminal.c

	$(cc) $(ccargs) -o x86/rot_main.o ind/rot_main.c
	$(cc) $(ccargs) -o x86/rot_log.o ind/rot_log.c

	nasm -felf32 -o x86/rot_bootstrap.o x86/rot_bootstrap.asm

	$(cc) $(ccargs) -o x86/rot_videoManager.o x86/rot_videoManager.c
	$(cc) $(ccargs) -o x86/rot_terminal.o x86/rot_terminal.c

	$(ld) $(ldargs) -T x86/rot_linkscript.ld -o x86/rot.bin \
		x86/rot_main.o \
		x86/rot_log.o \
		x86/rot_bootstrap.o \
		x86/rot_videoManager.o \
		x86/rot_terminal.o

cd-grub-x86:	x86/rot.bin \
				grub/boot/grub/grub.cfg

	cp x86/rot.bin grub/boot/rot.bin
	grub-mkrescue -o x86/rot.iso grub
	rm grub/boot/rot.bin
