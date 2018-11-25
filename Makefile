LINKER=/usr/bin/g++
COMPILER=/usr/bin/g++

WORKPATH=/home/adamsmj/explrpde/explrpde/upload/explrpde/LINUX
PRIMEPATH=/home/adamsmj/explrpde/explrpde/upload/explrpde/LINUX
#########################################################################
# 
#    	RELEASE MAKEFILE FOR STANDARD PCG EXECUTABLE
#
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak                 
#########################################################################
# 
#     DEFINE STATEMENTS
# 
#########################################################################
SRCPATH=$(WORKPATH)/source/linux
OBJPATH=$(WORKPATH)/objects/release
EXEPATH=$(WORKPATH)/executable/release
MAKEFILE=$(WORKPATH)/workspace/release/explrpde.mak
#########################################################################
# 
#     LINK STATEMENT
#------------------------------------------------------------------------
# 	explrpde
# 
#########################################################################
EXE_FILE=$(EXEPATH)/explrpde
#------------------------------------------------------------------------
OBJ_FILES= \
	$(OBJPATH)/devreport.o \
	$(OBJPATH)/maccert.o \
	$(OBJPATH)/crypto.o \
	$(OBJPATH)/precsrce.o \
	$(OBJPATH)/precreg.o \
	$(OBJPATH)/precmac.o \
	$(OBJPATH)/macdict.o \
	$(OBJPATH)/devproj.o \
	$(OBJPATH)/preccall.o \
	$(OBJPATH)/apnddict.o \
	$(OBJPATH)/prime.o \
	$(OBJPATH)/maildict.o \
	$(OBJPATH)/errormail.o \
	$(OBJPATH)/prectext.o \
	$(OBJPATH)/precoper.o \
	$(OBJPATH)/precnum.o \
	$(OBJPATH)/precform.o \
	$(OBJPATH)/precfile.o \
	$(OBJPATH)/precdbug.o \
	$(OBJPATH)/preccallutil.o \
	$(OBJPATH)/preccallproc.o \
	$(OBJPATH)/basedict.o \
	$(OBJPATH)/basedictproc.o \
	$(OBJPATH)/basedictutil.o \
	$(OBJPATH)/precstck.o \
	$(OBJPATH)/testproj.o \
	$(OBJPATH)/srcedict.o \
	$(OBJPATH)/srcproj.o \
	$(OBJPATH)/macproj.o \
	$(OBJPATH)/guicomm.o \
	$(OBJPATH)/precutil.o \
	$(OBJPATH)/mainprj.o \
	$(OBJPATH)/precdiag.o \
	$(OBJPATH)/explrpde.o
#------------------------------------------------------------------------
$(EXE_FILE): $(OBJ_FILES) $(MAKEFILE)
	$(LINKER) -o $(EXE_FILE) $(OBJ_FILES)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	devreport
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/debug/explrpde.mak
# 
#########################################################################
OBJ_devreport=$(OBJPATH)/devreport.o
#------------------------------------------------------------------------
CPP_devreport=$(SRCPATH)/devreport.cpp
#------------------------------------------------------------------------
HEADER_devreport= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/devreport.hxx \
	$(SRCPATH)/devreport.hpp \
	$(SRCPATH)/devreport.h
#------------------------------------------------------------------------
$(OBJ_devreport): $(CPP_devreport) $(HEADER_devreport) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_devreport) -c $(CPP_devreport)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	maccert
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/debug/explrpde.mak
# 
#########################################################################
OBJ_maccert=$(OBJPATH)/maccert.o
#------------------------------------------------------------------------
CPP_maccert=$(SRCPATH)/maccert.cpp
#------------------------------------------------------------------------
HEADER_maccert= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/apnddict.h \
	$(SRCPATH)/maccert.hxx \
	$(SRCPATH)/maccert.hpp \
	$(SRCPATH)/maccert.h
#------------------------------------------------------------------------
$(OBJ_maccert): $(CPP_maccert) $(HEADER_maccert) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_maccert) -c $(CPP_maccert)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	crypto
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/debug/explrpde.mak
# 
#########################################################################
OBJ_crypto=$(OBJPATH)/crypto.o
#------------------------------------------------------------------------
CPP_crypto=$(SRCPATH)/crypto.cpp
#------------------------------------------------------------------------
HEADER_crypto= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/crypto.hxx \
	$(SRCPATH)/crypto.hpp \
	$(SRCPATH)/crypto.h
#------------------------------------------------------------------------
$(OBJ_crypto): $(CPP_crypto) $(HEADER_crypto) $(MAKEFILE)
	$(COMPILER)  -w -o $(OBJ_crypto) -c $(CPP_crypto)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	basedictutil
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_basedictutil=$(OBJPATH)/basedictutil.o
#------------------------------------------------------------------------
CPP_basedictutil=$(SRCPATH)/basedictutil.cpp
#------------------------------------------------------------------------
HEADER_basedictutil= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/basedictutil.hxx \
	$(SRCPATH)/basedictutil.hpp \
	$(SRCPATH)/basedictutil.h
#------------------------------------------------------------------------
$(OBJ_basedictutil): $(CPP_basedictutil) $(HEADER_basedictutil) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_basedictutil) -c $(CPP_basedictutil)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	basedictproc
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_basedictproc=$(OBJPATH)/basedictproc.o
#------------------------------------------------------------------------
CPP_basedictproc=$(SRCPATH)/basedictproc.cpp
#------------------------------------------------------------------------
HEADER_basedictproc= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/basedictproc.hxx \
	$(SRCPATH)/basedictproc.hpp \
	$(SRCPATH)/basedictproc.h
#------------------------------------------------------------------------
$(OBJ_basedictproc): $(CPP_basedictproc) $(HEADER_basedictproc) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_basedictproc) -c $(CPP_basedictproc)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	basedict
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_basedict=$(OBJPATH)/basedict.o
#------------------------------------------------------------------------
CPP_basedict=$(SRCPATH)/basedict.cpp
#------------------------------------------------------------------------
HEADER_basedict= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/basedict.hxx \
	$(SRCPATH)/basedict.hpp \
	$(SRCPATH)/basedict.h
#------------------------------------------------------------------------
$(OBJ_basedict): $(CPP_basedict) $(HEADER_basedict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_basedict) -c $(CPP_basedict)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	preccallproc
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_preccallproc=$(OBJPATH)/preccallproc.o
#------------------------------------------------------------------------
CPP_preccallproc=$(SRCPATH)/preccallproc.cpp
#------------------------------------------------------------------------
HEADER_preccallproc= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccallproc.hxx \
	$(SRCPATH)/preccallproc.hpp \
	$(SRCPATH)/preccallproc.h
#------------------------------------------------------------------------
$(OBJ_preccallproc): $(CPP_preccallproc) $(HEADER_preccallproc) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_preccallproc) -c $(CPP_preccallproc)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	preccallutil
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_preccallutil=$(OBJPATH)/preccallutil.o
#------------------------------------------------------------------------
CPP_preccallutil=$(SRCPATH)/preccallutil.cpp
#------------------------------------------------------------------------
HEADER_preccallutil= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccallutil.hxx \
	$(SRCPATH)/preccallutil.hpp \
	$(SRCPATH)/preccallutil.h
#------------------------------------------------------------------------
$(OBJ_preccallutil): $(CPP_preccallutil) $(HEADER_preccallutil) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_preccallutil) -c $(CPP_preccallutil)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precdbug
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precdbug=$(OBJPATH)/precdbug.o
#------------------------------------------------------------------------
CPP_precdbug=$(SRCPATH)/precdbug.cpp
#------------------------------------------------------------------------
HEADER_precdbug= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precdbug.hxx \
	$(SRCPATH)/precdbug.hpp \
	$(SRCPATH)/precdbug.h
#------------------------------------------------------------------------
$(OBJ_precdbug): $(CPP_precdbug) $(HEADER_precdbug) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precdbug) -c $(CPP_precdbug)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precfile
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precfile=$(OBJPATH)/precfile.o
#------------------------------------------------------------------------
CPP_precfile=$(SRCPATH)/precfile.cpp
#------------------------------------------------------------------------
HEADER_precfile= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precfile.hxx \
	$(SRCPATH)/precfile.hpp \
	$(SRCPATH)/precfile.h
#------------------------------------------------------------------------
$(OBJ_precfile): $(CPP_precfile) $(HEADER_precfile) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precfile) -c $(CPP_precfile)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precform
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precform=$(OBJPATH)/precform.o
#------------------------------------------------------------------------
CPP_precform=$(SRCPATH)/precform.cpp
#------------------------------------------------------------------------
HEADER_precform= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precform.hxx \
	$(SRCPATH)/precform.hpp \
	$(SRCPATH)/precform.h
#------------------------------------------------------------------------
$(OBJ_precform): $(CPP_precform) $(HEADER_precform) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precform) -c $(CPP_precform)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precnum
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precnum=$(OBJPATH)/precnum.o
#------------------------------------------------------------------------
CPP_precnum=$(SRCPATH)/precnum.cpp
#------------------------------------------------------------------------
HEADER_precnum= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precnum.hxx \
	$(SRCPATH)/precnum.hpp \
	$(SRCPATH)/precnum.h
#------------------------------------------------------------------------
$(OBJ_precnum): $(CPP_precnum) $(HEADER_precnum) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precnum) -c $(CPP_precnum)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precoper
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precoper=$(OBJPATH)/precoper.o
#------------------------------------------------------------------------
CPP_precoper=$(SRCPATH)/precoper.cpp
#------------------------------------------------------------------------
HEADER_precoper= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precoper.hxx \
	$(SRCPATH)/precoper.hpp \
	$(SRCPATH)/precoper.h
#------------------------------------------------------------------------
$(OBJ_precoper): $(CPP_precoper) $(HEADER_precoper) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precoper) -c $(CPP_precoper)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	prectext
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_prectext=$(OBJPATH)/prectext.o
#------------------------------------------------------------------------
CPP_prectext=$(SRCPATH)/prectext.cpp
#------------------------------------------------------------------------
HEADER_prectext= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/prectext.hxx \
	$(SRCPATH)/prectext.hpp \
	$(SRCPATH)/prectext.h
#------------------------------------------------------------------------
$(OBJ_prectext): $(CPP_prectext) $(HEADER_prectext) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_prectext) -c $(CPP_prectext)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	errormail
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_errormail=$(OBJPATH)/errormail.o
#------------------------------------------------------------------------
CPP_errormail=$(SRCPATH)/errormail.cpp
#------------------------------------------------------------------------
HEADER_errormail= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/errormail.hxx \
	$(SRCPATH)/errormail.hpp \
	$(SRCPATH)/errormail.h
#------------------------------------------------------------------------
$(OBJ_errormail): $(CPP_errormail) $(HEADER_errormail) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_errormail) -c $(CPP_errormail)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	maildict
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_maildict=$(OBJPATH)/maildict.o
#------------------------------------------------------------------------
CPP_maildict=$(SRCPATH)/maildict.cpp
#------------------------------------------------------------------------
HEADER_maildict= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/maildict.hxx \
	$(SRCPATH)/maildict.hpp \
	$(SRCPATH)/maildict.h
#------------------------------------------------------------------------
$(OBJ_maildict): $(CPP_maildict) $(HEADER_maildict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_maildict) -c $(CPP_maildict)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	prime
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_prime=$(OBJPATH)/prime.o
#------------------------------------------------------------------------
CPP_prime=$(SRCPATH)/prime.cpp
#------------------------------------------------------------------------
HEADER_prime= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/prime.hxx \
	$(SRCPATH)/prime.hpp \
	$(SRCPATH)/prime.h
#------------------------------------------------------------------------
$(OBJ_prime): $(CPP_prime) $(HEADER_prime) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_prime) -c $(CPP_prime)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	apnddict
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_apnddict=$(OBJPATH)/apnddict.o
#------------------------------------------------------------------------
CPP_apnddict=$(SRCPATH)/apnddict.cpp
#------------------------------------------------------------------------
HEADER_apnddict= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/apnddict.hxx \
	$(SRCPATH)/apnddict.hpp \
	$(SRCPATH)/apnddict.h
#------------------------------------------------------------------------
$(OBJ_apnddict): $(CPP_apnddict) $(HEADER_apnddict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_apnddict) -c $(CPP_apnddict)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	preccall
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_preccall=$(OBJPATH)/preccall.o
#------------------------------------------------------------------------
CPP_preccall=$(SRCPATH)/preccall.cpp
#------------------------------------------------------------------------
HEADER_preccall= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccall.hxx \
	$(SRCPATH)/preccall.hpp \
	$(SRCPATH)/preccall.h
#------------------------------------------------------------------------
$(OBJ_preccall): $(CPP_preccall) $(HEADER_preccall) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_preccall) -c $(CPP_preccall)

#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	devproj
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_devproj=$(OBJPATH)/devproj.o
#------------------------------------------------------------------------
CPP_devproj=$(SRCPATH)/devproj.cpp
#------------------------------------------------------------------------
HEADER_devproj= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/devproj.hxx \
	$(SRCPATH)/devproj.hpp \
	$(SRCPATH)/devproj.h
#------------------------------------------------------------------------
$(OBJ_devproj): $(CPP_devproj) $(HEADER_devproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_devproj) -c $(CPP_devproj)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	macdict
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_macdict=$(OBJPATH)/macdict.o
#------------------------------------------------------------------------
CPP_macdict=$(SRCPATH)/macdict.cpp
#------------------------------------------------------------------------
HEADER_macdict= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/macdict.hxx \
	$(SRCPATH)/macdict.hpp \
	$(SRCPATH)/macdict.h
#------------------------------------------------------------------------
$(OBJ_macdict): $(CPP_macdict) $(HEADER_macdict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_macdict) -c $(CPP_macdict)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precmac
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precmac=$(OBJPATH)/precmac.o
#------------------------------------------------------------------------
CPP_precmac=$(SRCPATH)/precmac.cpp
#------------------------------------------------------------------------
HEADER_precmac= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precmac.hxx \
	$(SRCPATH)/precmac.hpp \
	$(SRCPATH)/precmac.h
#------------------------------------------------------------------------
$(OBJ_precmac): $(CPP_precmac) $(HEADER_precmac) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precmac) -c $(CPP_precmac)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precreg
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precreg=$(OBJPATH)/precreg.o
#------------------------------------------------------------------------
CPP_precreg=$(SRCPATH)/precreg.cpp
#------------------------------------------------------------------------
HEADER_precreg= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precreg.hxx \
	$(SRCPATH)/precreg.hpp \
	$(SRCPATH)/precreg.h
#------------------------------------------------------------------------
$(OBJ_precreg): $(CPP_precreg) $(HEADER_precreg) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precreg) -c $(CPP_precreg)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precsrce
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precsrce=$(OBJPATH)/precsrce.o
#------------------------------------------------------------------------
CPP_precsrce=$(SRCPATH)/precsrce.cpp
#------------------------------------------------------------------------
HEADER_precsrce= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precsrce.hxx \
	$(SRCPATH)/precsrce.hpp \
	$(SRCPATH)/precsrce.h
#------------------------------------------------------------------------
$(OBJ_precsrce): $(CPP_precsrce) $(HEADER_precsrce) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precsrce) -c $(CPP_precsrce)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precstck
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precstck=$(OBJPATH)/precstck.o
#------------------------------------------------------------------------
CPP_precstck=$(SRCPATH)/precstck.cpp
#------------------------------------------------------------------------
HEADER_precstck= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precstck.hxx \
	$(SRCPATH)/precstck.hpp \
	$(SRCPATH)/precstck.h
#------------------------------------------------------------------------
$(OBJ_precstck): $(CPP_precstck) $(HEADER_precstck) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precstck) -c $(CPP_precstck)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	macproj
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_macproj=$(OBJPATH)/macproj.o
#------------------------------------------------------------------------
CPP_macproj=$(SRCPATH)/macproj.cpp
#------------------------------------------------------------------------
HEADER_macproj= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/macproj.hxx \
	$(SRCPATH)/macproj.hpp \
	$(SRCPATH)/macproj.h
#------------------------------------------------------------------------
$(OBJ_macproj): $(CPP_macproj) $(HEADER_macproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_macproj) -c $(CPP_macproj)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	srcedict
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_srcedict=$(OBJPATH)/srcedict.o
#------------------------------------------------------------------------
CPP_srcedict=$(SRCPATH)/srcedict.cpp
#------------------------------------------------------------------------
HEADER_srcedict= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/srcedict.hxx \
	$(SRCPATH)/srcedict.hpp \
	$(SRCPATH)/srcedict.h
#------------------------------------------------------------------------
$(OBJ_srcedict): $(CPP_srcedict) $(HEADER_srcedict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_srcedict) -c $(CPP_srcedict)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	srcproj
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_srcproj=$(OBJPATH)/srcproj.o
#------------------------------------------------------------------------
CPP_srcproj=$(SRCPATH)/srcproj.cpp
#------------------------------------------------------------------------
HEADER_srcproj= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/precmac.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/srcedict.hxx \
	$(SRCPATH)/precsrce.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/srcproj.hxx \
	$(SRCPATH)/srcproj.hpp \
	$(SRCPATH)/srcproj.h
#------------------------------------------------------------------------
$(OBJ_srcproj): $(CPP_srcproj) $(HEADER_srcproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_srcproj) -c $(CPP_srcproj)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	testproj
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_testproj=$(OBJPATH)/testproj.o
#------------------------------------------------------------------------
CPP_testproj=$(SRCPATH)/testproj.cpp
#------------------------------------------------------------------------
HEADER_testproj= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/testproj.hxx \
	$(SRCPATH)/testproj.hpp \
	$(SRCPATH)/testproj.h
#------------------------------------------------------------------------
$(OBJ_testproj): $(CPP_testproj) $(HEADER_testproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_testproj) -c $(CPP_testproj)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	mainprj
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_mainprj=$(OBJPATH)/mainprj.o
#------------------------------------------------------------------------
CPP_mainprj=$(SRCPATH)/mainprj.cpp
#------------------------------------------------------------------------
HEADER_mainprj= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/apnddict.h \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/basedict.h \
	$(SRCPATH)/basedictutil.h \
	$(SRCPATH)/basedictproc.h \
	$(SRCPATH)/devproj.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/preccallproc.h \
	$(SRCPATH)/preccallutil.h \
	$(SRCPATH)/precdbug.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/precmac.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/precoper.h \
	$(SRCPATH)/precreg.h \
	$(SRCPATH)/precsrce.h \
	$(SRCPATH)/precstck.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/srcedict.h \
	$(SRCPATH)/srcproj.h \
	$(SRCPATH)/testproj.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/errormail.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/mainprj.hxx \
	$(SRCPATH)/mainprj.hpp \
	$(SRCPATH)/mainprj.h
#------------------------------------------------------------------------
$(OBJ_mainprj): $(CPP_mainprj) $(HEADER_mainprj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_mainprj) -c $(CPP_mainprj)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precutil
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precutil=$(OBJPATH)/precutil.o
#------------------------------------------------------------------------
CPP_precutil=$(SRCPATH)/precutil.cpp
#------------------------------------------------------------------------
HEADER_precutil= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.hxx \
	$(SRCPATH)/precutil.hpp \
	$(SRCPATH)/precutil.h
#------------------------------------------------------------------------
$(OBJ_precutil): $(CPP_precutil) $(HEADER_precutil) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precutil) -c $(CPP_precutil)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	guicomm
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_guicomm=$(OBJPATH)/guicomm.o
#------------------------------------------------------------------------
CPP_guicomm=$(SRCPATH)/guicomm.cpp
#------------------------------------------------------------------------
HEADER_guicomm= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/guicomm.hxx \
	$(SRCPATH)/guicomm.hpp \
	$(SRCPATH)/guicomm.h
#------------------------------------------------------------------------
$(OBJ_guicomm): $(CPP_guicomm) $(HEADER_guicomm) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_guicomm) -c $(CPP_guicomm)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	precdiag
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_precdiag=$(OBJPATH)/precdiag.o
#------------------------------------------------------------------------
CPP_precdiag=$(SRCPATH)/precdiag.cpp
#------------------------------------------------------------------------
HEADER_precdiag= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/preccallutil.h \
	$(SRCPATH)/preccallproc.h \
	$(SRCPATH)/precreg.h \
	$(SRCPATH)/precdiag.hxx \
	$(SRCPATH)/precdiag.hpp \
	$(SRCPATH)/precdiag.h
#------------------------------------------------------------------------
$(OBJ_precdiag): $(CPP_precdiag) $(HEADER_precdiag) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precdiag) -c $(CPP_precdiag)
#########################################################################
# 
#     COMPILE STATEMENT
#------------------------------------------------------------------------
# 	explrpde
#------------------------------------------------------------------------
#  make -f /home/robert/explrpde/workspace/release/explrpde.mak
# 
#########################################################################
OBJ_explrpde=$(OBJPATH)/explrpde.o
#------------------------------------------------------------------------
CPP_explrpde=$(SRCPATH)/explrpde.cpp
#------------------------------------------------------------------------
HEADER_explrpde= \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/mainprj.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/explrpde.hxx \
	$(SRCPATH)/explrpde.hpp \
	$(SRCPATH)/explrpde.h
#------------------------------------------------------------------------
$(OBJ_explrpde): $(CPP_explrpde) $(HEADER_explrpde) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_explrpde) -c $(CPP_explrpde)
#########################################################################
#########################################################################
clean:
	rm -rf explrpde *.o
install:	
	cp $(EXEPATH)/explrpde `dirname $(LINKER)`

