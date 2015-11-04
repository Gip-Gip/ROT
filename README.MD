DEVELOPMENT IS HALTED UNTIL LASM IS USABLE

#The Roll Of Tape OS

The Roll Of Tape OS(ROT for short) is an in-development OS that's intentions  
are to be flexible, well documented, and contained within one file. This is  
my first attempt at an OS and is guaranteed to be sloppy and basic, but thus is  
why I have put it on GitHub (so it can be improved)!  

#The Idea  
ROT got it's name from the fact that it is entirely contained in one file. The  
reason for this is mostly due to the license it is under, but I also (for some  
reason) believe that it is easier to organize (because linkers are sooo  
complicated :P). Luckily for ~~me~~ us there are #ifdef markers to help build  
different things by just commenting and uncommenting stuff.. yea.. I'm not  
organized at all.  

What I'm aiming for when I finish the basic goals and hurtles of developing ROT  
is a CP/M inspired OS (interpreted EXEs, multitasking, console based) that is  
unbelievably flexible, to the point that if it has a console, ROT will run on it  
(I can have dreams, OK).  

#The Current Features

 * It supports running as an EXE
 * It can print the startup string

#The Soon To Come Features

 * x86 support
 * can print the startup string on x86 machines

#Future Goals

 * Hosted keyboard input
 * x86 keyboard input
 * Hosted disk i/o
 * x86 disk i/o
 * simple interpreted EXE format

#Code Format

The code format ROT is programmed in is as follows:

 * 8-space tabs for indents
 * C89 (no // comments!)
 * when defining functions that have no arguments there is always void  in the  
 parentheses
 * The encoding is in ASCII(aka US-ASCII and ANSI). This is basically UTF-8 -  
 the  last 128 characters
 * No single line must exceed 80 characters in length!

#Testing Environments

 * The hosted (EXE) version is compiled with GCC and tested on Linux
 * The x86 version is compiled with Turbo C and tested on DOS 3.1
