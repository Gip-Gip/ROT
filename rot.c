/* THIS SOURCE FILE'S TABS ARE 8 SPACES IN LENGTH!

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

CONFIGURATION - Where people can configure what parts of the code are actually
used by commenting (adding a /* to the start of the line) or uncommenting
(removing the /* at the start of the line) an option you will be using.
**NOTE** that most options are not compatible with each other. It will usually
tell you if you need to comment out another option to get this one to work.

DATA TYPES - A bunch of definitions that tell ROT how to handle data and other
things

GLOBAL VARIABLES - Variables that are used no matter what

HOST CODE - Code used if the "HOSTED" option is uncommented

ROT CORE - The heart of ROT

*/

/* ////////////////////////////////////////////////////////////////////////////
CONFIGURATION==================================================================
//////////////////////////////////////////////////////////////////////////// */

#define HOSTED 1 /* Compile the source as an executable that you can run */

/* ////////////////////////////////////////////////////////////////////////////
DATA TYPES=====================================================================
//////////////////////////////////////////////////////////////////////////// */

#define BA 256 /* The Byta unit, 256 bytes */
#define KB 1024 /* The KiloByte unit, 1024 bytes */

#define MAINTYPE int /* The type that main returns */
#define GENINT int /* General interger */
#define RAMINT long unsigned int /* RAM interger, for storing addresses */

/* ////////////////////////////////////////////////////////////////////////////
GLOBAL VARIABLES===============================================================
//////////////////////////////////////////////////////////////////////////// */

char *openRAM; /* The pointer to open RAM (RAM not occupied by ROT) */
RAMINT sizeOfRAM = 0;/* The size of RAM */

/* ////////////////////////////////////////////////////////////////////////////
HOST CODE======================================================================
//////////////////////////////////////////////////////////////////////////// */

#ifdef HOSTED
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
	#ifdef HOSTED /* If the hosted option is uncommented, let's return */
	return 0;
	#else /* But if not, time to enter limbo! */
	limbo();
	#endif
}
