#The Public File License (see https://github.com/Gip-Gip/PFL for info)

#Copyright Charles Thompson, January 29th, 2016

#In this case, a file is a named group of digital data that can be
#transferred and used.

#The copyright holder of the file Makefile has declared that the file
#and everything taken from it, unless stated otherwise, is free for any
#use by any one, with the exception of preventing the free use of the
#unmodified file, including but not limited to patenting and/or claiming
#further copyright on the unmodified file.

#THE FILE Makefile IS PROVIDED WITHOUT ANY WARRANTY OR GUARANTEE AT ALL
#THE AUTHOR IS NOT LIABLE FOR CLAIMS, DAMAGES, OR REALLY ANYTHING ELSE IN
#CONNECTION TO THIS FILE, UNLESS EXPLICITLY STATED OTHERWISE.

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
