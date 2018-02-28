#######################################################################
# sctproc.mk       Defect 92535                           RM 01/30/2004
# AUDIT TRAIL: 6.2
# Renamed sctproc.mk from defect posting to sctproc_linux.mk for 6.2.
# Linux Red Hat 5.0  64-bit Banner 8
# AUDIT TRAIL END 
#######################################################################

include $(ORACLE_HOME)/precomp/lib/env_precomp.mk

#######################################################################
# Following macros may need to be modified for your local environment
#######################################################################

# Set the ENV macro to reflect your hardware platform.  Supported
# UNIX platforms are:
#
#    PLAT_VAX
#    PLAT_SEQUENT
#    PLAT_ATT
#    PLAT_RS6000
#    PLAT_HP
#    PLAT_AVIION
#    PLAT_NCR
#    PLAT_SUN
#    PLAT_UNISYS
#    PLAT_ALPHA
#    PLAT_UNKNOWN
ENV=-DOPSYS_LINUX -DPLAT_80X86

# C compiler name
CC=gcc
CP=g++
LIBVER=

# Stripping executables saves disk space at the expense of losing
# debugging information.  If your C compiler does not support the
# -s switch then comment-out this macro.
# STRIP=-s

# Defining the C macro COLLISION_CHECK forces the inclusion of guaclsn.h.
# Use this only if you are writing code intended for porting to other
# platforms.
# CCHECK=-DCOLLISION_CHECK
SCT_DEBUG=

# Other C options
# CCOPT=-qmaxmem=8192

# Other BANNER objects to be linked into executable
LINKOBJS=

# If a full SQL check is desired, modify here or by overriding on the
# command line.
CHECKOPT=sqlcheck=limited
# CHECKOPT=sqlcheck=full userid=baninst1/u_pick_it

# Some addition Pro*C options
# DBMS= dbms=v7
DBMS= dbms=v8 unsafe_null=yes

# Modify basename command if it is not present in your UNIX path
BASE=`basename $* .o`

# Change these if file locations are non-standard
# lmarinch changed to $ORACLE_HOME/c
GENC=/home/oracle/c
GOBJ=/home/oracle/exe
GINC=/home/oracle/c
GEXE=/home/oracle/exe

#
# Unicode
#
# TMINC=$(BANNER_HOME)/general/c
TMINC=/usr/include:/usr/local/lib
#
# NOTE: On some platforms, -licu-toolutil is -licutoolutil
#
TMOBJSUC = -ltmciuc -licui18n -licudata -licuuc -licutu -licuio
# TMOBJSUC = -ltmciuc -licui18n -licudata -licuuc 
TMCHARSWITCH=_TMUNICODE
LINKTM=$(TMOBJSUC)

#######################################################################
# The following macros should not need to be modified for the
# local environment.
#######################################################################

# Suffixes pseudo-target
.SUFFIXES: .o .c .pc .cpp .tmi

# Compiler flags
#  Certain C compilers may require additional flags to be passed from the
#  command line to provide ansi compliance.
#
#  If you have one of the following systems, please uncomment the line 
#  where ANSI=<flag> is located. Comment out the first ANSI= line.
#
ANSI=
#
#  The following are operating system specific ANSI compliance flags.
#
#   DGUX
#ANSI=-Xc
#
#   HPUX
#ANSI=-Aa
# 
#   Digital UNIX
#ANSI=-std1
#
#   SUNWspro
#ANSI=-Xa

CFLAGS=-I. \
        -I$(GINC) \
        -I$(GENC) \
        -I$(TMINC) \
        -I$(ORACLE_HOME)/precomp/public \
        -I/usr/include/ \
        -D$(TMCHARSWITCH) \
        $(ANSI) $(STRIP) $(CCHECK) $(ENV) $(SCT_DEBUG) 

# ORACLE library directory
LIBHOME=$(ORACLE_HOME)/lib/

# Link flags
#<$(LDFLAGS)
# This is for Oracle 7.2 and higher. 
LDFLAGS=-L$(LIBHOME) -L/usr/lib64 -L/usr/lib -L/usr/local/lib -L/home/oracle/c -L$(EXE_HOME) -L. -L$(TMINC) $(LINKTM)

# Pro*C precompiler
PROC=proc$(EXE_SUFFIX)

# Pro*C precompiler flags
PROFLAGS=ireclen=132 oreclen=132 lines=y select_error=no hold_cursor=no \
          release_cursor=no maxopencursors=255 maxliteral=160 ltype=none \
          code=ansi_c char_map=string \
        code=ansi_c char_map=string utf16_char=db_charset \
        include=$(GINC)/ \
        include=$(GENC)/\
        include=$(TMINC)/ \
        include=/usr/include/ \
        define=$(TMCHARSWITCH) \
        $(DBMS) $(CHECKOPT)

# All BANNER .o files to be linked
LOBJS=$(GOBJ)/guastdf.o $(GOBJ)/guarpfe.o $(GOBJ)/guaorac2.o $(GOBJ)/guanlsl.o $(LINKOBJS)

#######################################################################
# Rules for building BANNER modules
#######################################################################

# Rules for building SCT support code objects

genobjs: $(GOBJ)/guastdf.o $(GOBJ)/guarpfe.o $(GOBJ)/guaorac2.o $(GOBJ)/guanlsl.o

$(GOBJ)/guastdf.o:
		 $(CC) $(CFLAGS) -c $(GENC)/guastdf.cpp
		 mv guastdf.o $(GOBJ)/guastdf.o
		 chmod 644 $(GOBJ)/guastdf.o

$(GOBJ)/guarpfe.o:
		 $(CC) $(CFLAGS) -c $(GENC)/guarpfe.c
		 mv guarpfe.o $(GOBJ)/guarpfe.o
		 chmod 644 $(GOBJ)/guarpfe.o

$(GOBJ)/guaorac2.o:
		 $(PROC) iname=guaorac2.pc $(PROFLAGS)
		 $(CC) $(CFLAGS) -c guaorac2.c
		 mv guaorac2.o $(GOBJ)/guaorac2.o
		 rm guaorac2.c
		 chmod 644 $(GOBJ)/guaorac2.o

$(GOBJ)/guanlsl.o:
		 $(PROC) iname=guanlsl.pc $(PROFLAGS)
		 $(CC) $(CFLAGS) -c guanlsl.c
		 mv guanlsl.o $(GOBJ)/guanlsl.o
		 rm guanlsl.c
		 chmod 644 $(GOBJ)/guanlsl.o

# Rule for building guaprpf

guaprpf:
		 $(CC) $(CFLAGS) guaprpf.c -c $(CCOPT)
		 $(CP) guaprpf.o -o guaprpf $(GOBJ)/guastdf.o $(GOBJ)/guarpfe.o $(LDFLAGS) $(CCOPT)
		 - mv guaprpf $(GEXE)/guaprpf
		 - rm -f guaprpf.o

# Rules for building a Pro*C executable from a .pc or .c source file

.pc:
		 $(PROC) iname=$*.pc $(PROFLAGS) oname=$*.c
		 $(CC) $(CFLAGS) $*.c -c $(CCOPT)
		 $(CP) $(CFLAGS) $*.o -o $* $(LOBJS) $(LDFLAGS) $(LLIBCLNTSH) $(CCOPT)
		 - mv $* $(GEXE)/$*
		 - rm -f $*.[co]

.c:
		 $(CC) $(CFLAGS) $*.c -c $(CCOPT)
		 $(CP) $(CFLAGS) $*.o -o $* $(LOBJS) $(LDFLAGS) $(CCOPT)
		 - mv $* $(GEXE)/$*
		 - rm -f $*.o

# Rule for building an object file from a .pc source file

.pc.o:
		 $(PROC) iname=$(BASE).pc $(PROFLAGS)
		 $(CC) $(CFLAGS) -c $(BASE).c $(CCOPT)
		 - mv $(BASE).o $(GEXE)/$(BASE).o
		 - rm -f $*.c
		 chmod 644 $(GEXE)/$(BASE).o

# Rule for building a plain C program into an object file

.c.o:
		 $(CC) $(CFLAGS) -c $(BASE).c $(CCOPT)
		 - mv $(BASE).o $(GOBJ)/$(BASE).o
		 chmod 644 $(GOBJ)/$(BASE).o
.cpp:
		echo "CPP "
		$(CP) $(CFLAGS) $*.cpp -o $* $(LOBJS) $(LDFLAGS) $(LLIBS) $(CCOPT)
		- mv $* $(GEXE)/$*
		- rm -f $*.o

