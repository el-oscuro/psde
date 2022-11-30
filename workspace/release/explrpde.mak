########################################################################
########################################################################
#####
#####     "MAKE FILE FOR EXPLRPDE"
#####-------------------------------------------------------------------
#####     make -f ./explrpde/LINUX/workspace/explrpde.mak
#####
########################################################################
########################################################################
MAKEFILE=./explrpde/LINUX/workspace/explrpde.mak
COMPILER=g++
LINKER=g++
WORKPATH=./explrpde/LINUX
EXECPATH=$(WORKPATH)/executable
OBJPATH=$(WORKPATH)/objects
SRCPATH=$(WORKPATH)/source/linux
########################################################################
########################################################################
#####
#####     LINK STATEMENT
#####-------------------------------------------------------------------
#####     explrpde
#####
########################################################################
########################################################################
EXE_FILE=$(EXECPATH)/explrpde
#####-------------------------------------------------------------------
OBJ_FILES= \
	$(OBJPATH)/precutil.o \
	$(OBJPATH)/guicomm.o \
	$(OBJPATH)/testproj.o \
	$(OBJPATH)/srcedict.o \
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
	$(OBJPATH)/precsrce.o \
	$(OBJPATH)/precdiag.o \
	$(OBJPATH)/crypto.o \
	$(OBJPATH)/devreport.o \
	$(OBJPATH)/precoper.o \
	$(OBJPATH)/maccert.o \
	$(OBJPATH)/macproj.o \
	$(OBJPATH)/srcproj.o \
	$(OBJPATH)/mainprj.o \
	$(OBJPATH)/explrpde.o
#####-------------------------------------------------------------------
$(EXE_FILE): $(OBJ_FILES) $(MAKEFILE)
	$(LINKER) -o $(EXE_FILE) $(OBJ_FILES)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     explrpde
#####
########################################################################
########################################################################
OBJ_explrpde=$(OBJPATH)/explrpde.o
#####-------------------------------------------------------------------
CPP_explrpde=$(SRCPATH)/explrpde.cpp
#####-------------------------------------------------------------------
HEADER_explrpde= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/mainprj.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/explrpde.h \
	$(SRCPATH)/explrpde.hpp \
	$(SRCPATH)/explrpde.hxx
#####-------------------------------------------------------------------
$(OBJ_explrpde): $(CPP_explrpde) $(HEADER_explrpde) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_explrpde) -c $(CPP_explrpde)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     mainprj
#####
########################################################################
########################################################################
OBJ_mainprj=$(OBJPATH)/mainprj.o
#####-------------------------------------------------------------------
CPP_mainprj=$(SRCPATH)/mainprj.cpp
#####-------------------------------------------------------------------
HEADER_mainprj= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/prime.h \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/apnddict.h \
	$(SRCPATH)/basedict.h \
	$(SRCPATH)/basedictutil.h \
	$(SRCPATH)/basedictproc.h \
	$(SRCPATH)/devproj.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/macproj.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/preccallutil.h \
	$(SRCPATH)/preccallproc.h \
	$(SRCPATH)/precdbug.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/precmac.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/precoper.h \
	$(SRCPATH)/precreg.h \
	$(SRCPATH)/precsrce.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/precstck.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/srcedict.h \
	$(SRCPATH)/srcproj.h \
	$(SRCPATH)/testproj.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/errormail.h \
	$(SRCPATH)/mainprj.h \
	$(SRCPATH)/mainprj.hpp \
	$(SRCPATH)/mainprj.hxx
#####-------------------------------------------------------------------
$(OBJ_mainprj): $(CPP_mainprj) $(HEADER_mainprj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_mainprj) -c $(CPP_mainprj)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     srcproj
#####
########################################################################
########################################################################
OBJ_srcproj=$(OBJPATH)/srcproj.o
#####-------------------------------------------------------------------
CPP_srcproj=$(SRCPATH)/srcproj.cpp
#####-------------------------------------------------------------------
HEADER_srcproj= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/precmac.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/precsrce.h \
	$(SRCPATH)/srcedict.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/srcproj.h \
	$(SRCPATH)/srcproj.hpp \
	$(SRCPATH)/srcproj.hxx
#####-------------------------------------------------------------------
$(OBJ_srcproj): $(CPP_srcproj) $(HEADER_srcproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_srcproj) -c $(CPP_srcproj)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     macproj
#####
########################################################################
########################################################################
OBJ_macproj=$(OBJPATH)/macproj.o
#####-------------------------------------------------------------------
CPP_macproj=$(SRCPATH)/macproj.cpp
#####-------------------------------------------------------------------
HEADER_macproj= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/precmac.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/maccert.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/apnddict.h \
	$(SRCPATH)/devreport.h \
	$(SRCPATH)/macproj.h \
	$(SRCPATH)/macproj.hpp \
	$(SRCPATH)/macproj.hxx
#####-------------------------------------------------------------------
$(OBJ_macproj): $(CPP_macproj) $(HEADER_macproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_macproj) -c $(CPP_macproj)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     maccert
#####
########################################################################
########################################################################
OBJ_maccert=$(OBJPATH)/maccert.o
#####-------------------------------------------------------------------
CPP_maccert=$(SRCPATH)/maccert.cpp
#####-------------------------------------------------------------------
HEADER_maccert= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/apnddict.h \
	$(SRCPATH)/maccert.h \
	$(SRCPATH)/maccert.hpp \
	$(SRCPATH)/maccert.hxx
#####-------------------------------------------------------------------
$(OBJ_maccert): $(CPP_maccert) $(HEADER_maccert) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_maccert) -c $(CPP_maccert)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precoper
#####
########################################################################
########################################################################
OBJ_precoper=$(OBJPATH)/precoper.o
#####-------------------------------------------------------------------
CPP_precoper=$(SRCPATH)/precoper.cpp
#####-------------------------------------------------------------------
HEADER_precoper= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precdbug.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/prime.h \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/errormail.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precstck.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/precreg.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/srcedict.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/precoper.h \
	$(SRCPATH)/precoper.hpp \
	$(SRCPATH)/precoper.hxx
#####-------------------------------------------------------------------
$(OBJ_precoper): $(CPP_precoper) $(HEADER_precoper) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precoper) -c $(CPP_precoper)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     devreport
#####
########################################################################
########################################################################
OBJ_devreport=$(OBJPATH)/devreport.o
#####-------------------------------------------------------------------
CPP_devreport=$(SRCPATH)/devreport.cpp
#####-------------------------------------------------------------------
HEADER_devreport= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/devreport.h \
	$(SRCPATH)/devreport.hpp \
	$(SRCPATH)/devreport.hxx
#####-------------------------------------------------------------------
$(OBJ_devreport): $(CPP_devreport) $(HEADER_devreport) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_devreport) -c $(CPP_devreport)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     crypto
#####
########################################################################
########################################################################
OBJ_crypto=$(OBJPATH)/crypto.o
#####-------------------------------------------------------------------
CPP_crypto=$(SRCPATH)/crypto.cpp
#####-------------------------------------------------------------------
HEADER_crypto= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/crypto.h \
	$(SRCPATH)/crypto.hpp \
	$(SRCPATH)/crypto.hxx
#####-------------------------------------------------------------------
$(OBJ_crypto): $(CPP_crypto) $(HEADER_crypto) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_crypto) -c $(CPP_crypto)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precdiag
#####
########################################################################
########################################################################
OBJ_precdiag=$(OBJPATH)/precdiag.o
#####-------------------------------------------------------------------
CPP_precdiag=$(SRCPATH)/precdiag.cpp
#####-------------------------------------------------------------------
HEADER_precdiag= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/preccallutil.h \
	$(SRCPATH)/preccallproc.h \
	$(SRCPATH)/precreg.h \
	$(SRCPATH)/precdiag.h \
	$(SRCPATH)/precdiag.hpp \
	$(SRCPATH)/precdiag.hxx
#####-------------------------------------------------------------------
$(OBJ_precdiag): $(CPP_precdiag) $(HEADER_precdiag) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precdiag) -c $(CPP_precdiag)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precsrce
#####
########################################################################
########################################################################
OBJ_precsrce=$(OBJPATH)/precsrce.o
#####-------------------------------------------------------------------
CPP_precsrce=$(SRCPATH)/precsrce.cpp
#####-------------------------------------------------------------------
HEADER_precsrce= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precsrce.h \
	$(SRCPATH)/precsrce.hpp \
	$(SRCPATH)/precsrce.hxx
#####-------------------------------------------------------------------
$(OBJ_precsrce): $(CPP_precsrce) $(HEADER_precsrce) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precsrce) -c $(CPP_precsrce)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precstck
#####
########################################################################
########################################################################
OBJ_precstck=$(OBJPATH)/precstck.o
#####-------------------------------------------------------------------
CPP_precstck=$(SRCPATH)/precstck.cpp
#####-------------------------------------------------------------------
HEADER_precstck= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precstck.h \
	$(SRCPATH)/precstck.hpp \
	$(SRCPATH)/precstck.hxx
#####-------------------------------------------------------------------
$(OBJ_precstck): $(CPP_precstck) $(HEADER_precstck) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precstck) -c $(CPP_precstck)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     basedictutil
#####
########################################################################
########################################################################
OBJ_basedictutil=$(OBJPATH)/basedictutil.o
#####-------------------------------------------------------------------
CPP_basedictutil=$(SRCPATH)/basedictutil.cpp
#####-------------------------------------------------------------------
HEADER_basedictutil= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/basedictutil.h \
	$(SRCPATH)/basedictutil.hpp \
	$(SRCPATH)/basedictutil.hxx
#####-------------------------------------------------------------------
$(OBJ_basedictutil): $(CPP_basedictutil) $(HEADER_basedictutil) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_basedictutil) -c $(CPP_basedictutil)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     basedictproc
#####
########################################################################
########################################################################
OBJ_basedictproc=$(OBJPATH)/basedictproc.o
#####-------------------------------------------------------------------
CPP_basedictproc=$(SRCPATH)/basedictproc.cpp
#####-------------------------------------------------------------------
HEADER_basedictproc= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/basedictproc.h \
	$(SRCPATH)/basedictproc.hpp \
	$(SRCPATH)/basedictproc.hxx
#####-------------------------------------------------------------------
$(OBJ_basedictproc): $(CPP_basedictproc) $(HEADER_basedictproc) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_basedictproc) -c $(CPP_basedictproc)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     basedict
#####
########################################################################
########################################################################
OBJ_basedict=$(OBJPATH)/basedict.o
#####-------------------------------------------------------------------
CPP_basedict=$(SRCPATH)/basedict.cpp
#####-------------------------------------------------------------------
HEADER_basedict= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/basedict.h \
	$(SRCPATH)/basedict.hpp \
	$(SRCPATH)/basedict.hxx
#####-------------------------------------------------------------------
$(OBJ_basedict): $(CPP_basedict) $(HEADER_basedict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_basedict) -c $(CPP_basedict)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     preccallproc
#####
########################################################################
########################################################################
OBJ_preccallproc=$(OBJPATH)/preccallproc.o
#####-------------------------------------------------------------------
CPP_preccallproc=$(SRCPATH)/preccallproc.cpp
#####-------------------------------------------------------------------
HEADER_preccallproc= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccallproc.h \
	$(SRCPATH)/preccallproc.hpp \
	$(SRCPATH)/preccallproc.hxx
#####-------------------------------------------------------------------
$(OBJ_preccallproc): $(CPP_preccallproc) $(HEADER_preccallproc) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_preccallproc) -c $(CPP_preccallproc)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     preccallutil
#####
########################################################################
########################################################################
OBJ_preccallutil=$(OBJPATH)/preccallutil.o
#####-------------------------------------------------------------------
CPP_preccallutil=$(SRCPATH)/preccallutil.cpp
#####-------------------------------------------------------------------
HEADER_preccallutil= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccallutil.h \
	$(SRCPATH)/preccallutil.hpp \
	$(SRCPATH)/preccallutil.hxx
#####-------------------------------------------------------------------
$(OBJ_preccallutil): $(CPP_preccallutil) $(HEADER_preccallutil) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_preccallutil) -c $(CPP_preccallutil)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precdbug
#####
########################################################################
########################################################################
OBJ_precdbug=$(OBJPATH)/precdbug.o
#####-------------------------------------------------------------------
CPP_precdbug=$(SRCPATH)/precdbug.cpp
#####-------------------------------------------------------------------
HEADER_precdbug= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precdbug.h \
	$(SRCPATH)/precdbug.hpp \
	$(SRCPATH)/precdbug.hxx
#####-------------------------------------------------------------------
$(OBJ_precdbug): $(CPP_precdbug) $(HEADER_precdbug) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precdbug) -c $(CPP_precdbug)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precfile
#####
########################################################################
########################################################################
OBJ_precfile=$(OBJPATH)/precfile.o
#####-------------------------------------------------------------------
CPP_precfile=$(SRCPATH)/precfile.cpp
#####-------------------------------------------------------------------
HEADER_precfile= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/prechost.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precfile.h \
	$(SRCPATH)/precfile.hpp \
	$(SRCPATH)/precfile.hxx
#####-------------------------------------------------------------------
$(OBJ_precfile): $(CPP_precfile) $(HEADER_precfile) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precfile) -c $(CPP_precfile)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precform
#####
########################################################################
########################################################################
OBJ_precform=$(OBJPATH)/precform.o
#####-------------------------------------------------------------------
CPP_precform=$(SRCPATH)/precform.cpp
#####-------------------------------------------------------------------
HEADER_precform= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precform.h \
	$(SRCPATH)/precform.hpp \
	$(SRCPATH)/precform.hxx
#####-------------------------------------------------------------------
$(OBJ_precform): $(CPP_precform) $(HEADER_precform) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precform) -c $(CPP_precform)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precnum
#####
########################################################################
########################################################################
OBJ_precnum=$(OBJPATH)/precnum.o
#####-------------------------------------------------------------------
CPP_precnum=$(SRCPATH)/precnum.cpp
#####-------------------------------------------------------------------
HEADER_precnum= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precnum.h \
	$(SRCPATH)/precnum.hpp \
	$(SRCPATH)/precnum.hxx
#####-------------------------------------------------------------------
$(OBJ_precnum): $(CPP_precnum) $(HEADER_precnum) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precnum) -c $(CPP_precnum)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     prectext
#####
########################################################################
########################################################################
OBJ_prectext=$(OBJPATH)/prectext.o
#####-------------------------------------------------------------------
CPP_prectext=$(SRCPATH)/prectext.cpp
#####-------------------------------------------------------------------
HEADER_prectext= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/prectext.h \
	$(SRCPATH)/prectext.hpp \
	$(SRCPATH)/prectext.hxx
#####-------------------------------------------------------------------
$(OBJ_prectext): $(CPP_prectext) $(HEADER_prectext) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_prectext) -c $(CPP_prectext)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     errormail
#####
########################################################################
########################################################################
OBJ_errormail=$(OBJPATH)/errormail.o
#####-------------------------------------------------------------------
CPP_errormail=$(SRCPATH)/errormail.cpp
#####-------------------------------------------------------------------
HEADER_errormail= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/errormail.h \
	$(SRCPATH)/errormail.hpp \
	$(SRCPATH)/errormail.hxx
#####-------------------------------------------------------------------
$(OBJ_errormail): $(CPP_errormail) $(HEADER_errormail) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_errormail) -c $(CPP_errormail)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     maildict
#####
########################################################################
########################################################################
OBJ_maildict=$(OBJPATH)/maildict.o
#####-------------------------------------------------------------------
CPP_maildict=$(SRCPATH)/maildict.cpp
#####-------------------------------------------------------------------
HEADER_maildict= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/maildict.h \
	$(SRCPATH)/maildict.hpp \
	$(SRCPATH)/maildict.hxx
#####-------------------------------------------------------------------
$(OBJ_maildict): $(CPP_maildict) $(HEADER_maildict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_maildict) -c $(CPP_maildict)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     prime
#####
########################################################################
########################################################################
OBJ_prime=$(OBJPATH)/prime.o
#####-------------------------------------------------------------------
CPP_prime=$(SRCPATH)/prime.cpp
#####-------------------------------------------------------------------
HEADER_prime= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/prime.h \
	$(SRCPATH)/prime.hpp \
	$(SRCPATH)/prime.hxx
#####-------------------------------------------------------------------
$(OBJ_prime): $(CPP_prime) $(HEADER_prime) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_prime) -c $(CPP_prime)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     apnddict
#####
########################################################################
########################################################################
OBJ_apnddict=$(OBJPATH)/apnddict.o
#####-------------------------------------------------------------------
CPP_apnddict=$(SRCPATH)/apnddict.cpp
#####-------------------------------------------------------------------
HEADER_apnddict= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/apnddict.h \
	$(SRCPATH)/apnddict.hpp \
	$(SRCPATH)/apnddict.hxx
#####-------------------------------------------------------------------
$(OBJ_apnddict): $(CPP_apnddict) $(HEADER_apnddict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_apnddict) -c $(CPP_apnddict)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     preccall
#####
########################################################################
########################################################################
OBJ_preccall=$(OBJPATH)/preccall.o
#####-------------------------------------------------------------------
CPP_preccall=$(SRCPATH)/preccall.cpp
#####-------------------------------------------------------------------
HEADER_preccall= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/preccall.h \
	$(SRCPATH)/preccall.hpp \
	$(SRCPATH)/preccall.hxx
#####-------------------------------------------------------------------
$(OBJ_preccall): $(CPP_preccall) $(HEADER_preccall) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_preccall) -c $(CPP_preccall)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     devproj
#####
########################################################################
########################################################################
OBJ_devproj=$(OBJPATH)/devproj.o
#####-------------------------------------------------------------------
CPP_devproj=$(SRCPATH)/devproj.cpp
#####-------------------------------------------------------------------
HEADER_devproj= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/devproj.h \
	$(SRCPATH)/devproj.hpp \
	$(SRCPATH)/devproj.hxx
#####-------------------------------------------------------------------
$(OBJ_devproj): $(CPP_devproj) $(HEADER_devproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_devproj) -c $(CPP_devproj)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     macdict
#####
########################################################################
########################################################################
OBJ_macdict=$(OBJPATH)/macdict.o
#####-------------------------------------------------------------------
CPP_macdict=$(SRCPATH)/macdict.cpp
#####-------------------------------------------------------------------
HEADER_macdict= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/macdict.h \
	$(SRCPATH)/macdict.hpp \
	$(SRCPATH)/macdict.hxx
#####-------------------------------------------------------------------
$(OBJ_macdict): $(CPP_macdict) $(HEADER_macdict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_macdict) -c $(CPP_macdict)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precmac
#####
########################################################################
########################################################################
OBJ_precmac=$(OBJPATH)/precmac.o
#####-------------------------------------------------------------------
CPP_precmac=$(SRCPATH)/precmac.cpp
#####-------------------------------------------------------------------
HEADER_precmac= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/global.hxx \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precmac.h \
	$(SRCPATH)/precmac.hpp \
	$(SRCPATH)/precmac.hxx
#####-------------------------------------------------------------------
$(OBJ_precmac): $(CPP_precmac) $(HEADER_precmac) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precmac) -c $(CPP_precmac)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precreg
#####
########################################################################
########################################################################
OBJ_precreg=$(OBJPATH)/precreg.o
#####-------------------------------------------------------------------
CPP_precreg=$(SRCPATH)/precreg.cpp
#####-------------------------------------------------------------------
HEADER_precreg= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precreg.h \
	$(SRCPATH)/precreg.hpp \
	$(SRCPATH)/precreg.hxx
#####-------------------------------------------------------------------
$(OBJ_precreg): $(CPP_precreg) $(HEADER_precreg) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precreg) -c $(CPP_precreg)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     srcedict
#####
########################################################################
########################################################################
OBJ_srcedict=$(OBJPATH)/srcedict.o
#####-------------------------------------------------------------------
CPP_srcedict=$(SRCPATH)/srcedict.cpp
#####-------------------------------------------------------------------
HEADER_srcedict= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/srcedict.h \
	$(SRCPATH)/srcedict.hpp \
	$(SRCPATH)/srcedict.hxx
#####-------------------------------------------------------------------
$(OBJ_srcedict): $(CPP_srcedict) $(HEADER_srcedict) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_srcedict) -c $(CPP_srcedict)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     testproj
#####
########################################################################
########################################################################
OBJ_testproj=$(OBJPATH)/testproj.o
#####-------------------------------------------------------------------
CPP_testproj=$(SRCPATH)/testproj.cpp
#####-------------------------------------------------------------------
HEADER_testproj= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/testproj.h \
	$(SRCPATH)/testproj.hpp \
	$(SRCPATH)/testproj.hxx
#####-------------------------------------------------------------------
$(OBJ_testproj): $(CPP_testproj) $(HEADER_testproj) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_testproj) -c $(CPP_testproj)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     guicomm
#####
########################################################################
########################################################################
OBJ_guicomm=$(OBJPATH)/guicomm.o
#####-------------------------------------------------------------------
CPP_guicomm=$(SRCPATH)/guicomm.cpp
#####-------------------------------------------------------------------
HEADER_guicomm= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/guicomm.h \
	$(SRCPATH)/guicomm.hpp \
	$(SRCPATH)/guicomm.hxx
#####-------------------------------------------------------------------
$(OBJ_guicomm): $(CPP_guicomm) $(HEADER_guicomm) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_guicomm) -c $(CPP_guicomm)
########################################################################
########################################################################
#####
#####     COMPILER STATEMENT
#####-------------------------------------------------------------------
#####     precutil
#####
########################################################################
########################################################################
OBJ_precutil=$(OBJPATH)/precutil.o
#####-------------------------------------------------------------------
CPP_precutil=$(SRCPATH)/precutil.cpp
#####-------------------------------------------------------------------
HEADER_precutil= \
	$(SRCPATH)/robert.h \
	$(SRCPATH)/typecast.h \
	$(SRCPATH)/precutil.h \
	$(SRCPATH)/precutil.hpp \
	$(SRCPATH)/precutil.hxx
#####-------------------------------------------------------------------
$(OBJ_precutil): $(CPP_precutil) $(HEADER_precutil) $(MAKEFILE)
	$(COMPILER) -w -o $(OBJ_precutil) -c $(CPP_precutil)
