char rotEdition[] = "ROT testing 1.2.2015 \"Talking Potato\"\n"; /* The version
format for ROT is release.successful build.year

THIS SOURCE FILE'S TABS ARE 8 SPACES IN LENGTH!

The Public File License

Copyright Charles "Gip-Gip" Thompson, September 20th, 2015

In this case, a file is a group of digital data that can be transferred and
used.

The copyright holder of the file (filename) has declared that the file and
everything taken from it, unless stated otherwise, is free for any use by any
one, with the exception of preventing the free use of the unmodified file
and/or the unmodified file's derivatives, including but not limited
to patenting and/or claiming further copyright on the unmodified file and/or
the unmodified file's derivatives.

THE FILE (filename) IS PROVIDED WITHOUT ANY WARRANTY OR GUARANTEE AT ALL. THE
AUTHOR(S) ARE NOT LIABLE FOR CLAIMS, DAMAGES, OR REALLY ANYTHING ELSE IN
CONNECTION TO THIS FILE, UNLESS EXPLICITLY STATED OTHERWISE.

			      About Roll Of Tape
			     ====================

Roll Of Tape OS (ROT OS for short) is an operating system programmed in C that
is made to be infinitely flex able, well documented, and contained within a
single file. Since the entirety of ROT is contained inside rot.c, there are
different sections within this file to mark what is what.

				   SECTIONS
				  ==========

ARCHITECTURE CONFIGURATION - The architecture ROT will be built for

DATA TYPES - A bunch of definitions that tell ROT how to handle data and other
things

GLOBAL VARIABLES - Variables that are used no matter what

HOST CODE - Code used if the "HOSTED" option is uncommented

ROT CORE - The heart of ROT

 */

/* ////////////////////////////////////////////////////////////////////////////
ARCHITECTURE CONFIGURATION=====================================================
//////////////////////////////////////////////////////////////////////////// */

#define HOSTED 1 /* Compile the source as an executable that you can run */

/* ////////////////////////////////////////////////////////////////////////////
DATA TYPES=====================================================================
//////////////////////////////////////////////////////////////////////////// */

#define BA 256 /* The Byta unit, 256 bytes */
#define KB 1024 /* The KiloByte unit, 1024 bytes */

#define MAINTYPE int /* The type that main returns */
#define GENINT int /* General interger */
#define RAMINT long unsigned int /* RAM integer, for storing addresses */

#ifndef bool
#define bool char
#endif

#ifndef true
#define true 0
#endif

#ifndef false
#define false 1
#endif

/* ////////////////////////////////////////////////////////////////////////////
GLOBAL VARIABLES===============================================================
//////////////////////////////////////////////////////////////////////////// */

char *openRAM; /* The pointer to open RAM (RAM not occupied by ROT) */
RAMINT sizeOfRAM = 0;/* The size of RAM */

/* ////////////////////////////////////////////////////////////////////////////
HOST CODE======================================================================
//////////////////////////////////////////////////////////////////////////// */

#ifdef HOSTED
#include <stdio.h>
#include <stdlib.h>

void print(void *__str__, char __mod__)
{
	if(__mod__ == 's')
	{
		printf("%s", __str__);
	}
	else if(__mod__ == 'c')
	{
		char *__out__ = __str__;
		printf("%c", *(__out__));
	}
	else if(__mod__ == 'd')
	{
		int *__out__ = __str__;
		printf("%d", *(__out__));
	}
}

bool detectHardware()
{
	return true;
}

#endif

/* ////////////////////////////////////////////////////////////////////////////
ROT CORE=======================================================================
//////////////////////////////////////////////////////////////////////////// */

void limbo( void )
{
	while( 1 == 1 )
	{
		/* Do nothing (hence the name limbo)! */
	}
}

MAINTYPE main( void )
{
	if(detectHardware() == false)
	{
		limbo(); /* If there is no I/O hardware, go to limbo... */
	}
	print(rotEdition, 's');
	#ifdef HOSTED /* If the hosted option is uncommented, let's return */
	return 0;
	#else /* But if not, time to enter limbo! */
	limbo();
	#endif
}
