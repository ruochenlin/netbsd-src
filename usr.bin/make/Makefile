#	$NetBSD: Makefile,v 1.65 2019/12/19 07:14:07 maxv Exp $
#	@(#)Makefile	5.2 (Berkeley) 12/28/90

PROG=	make
SRCS=	arch.c buf.c compat.c cond.c dir.c for.c hash.c job.c main.c \
	make.c metachar.c parse.c str.c suff.c targ.c trace.c var.c util.c 
SRCS+=  strlist.c
SRCS+=  make_malloc.c
SRCS+=	lstAppend.c lstAtEnd.c lstAtFront.c lstClose.c lstConcat.c \
	lstDatum.c lstDeQueue.c lstDestroy.c lstDupl.c lstEnQueue.c \
	lstFind.c lstFindFrom.c lstFirst.c lstForEach.c lstForEachFrom.c \
	lstInit.c lstInsert.c lstIsAtEnd.c lstIsEmpty.c lstLast.c \
	lstMember.c lstNext.c lstOpen.c lstRemove.c lstReplace.c lstSucc.c
SRCS += lstPrev.c

USE_META ?= yes
.if ${USE_META:tl} != "no"
SRCS+=	meta.c
CPPFLAGS+= -DUSE_META
FILEMON_H ?= ${.CURDIR:H:H}/sys/dev/filemon/filemon.h
.if exists(${FILEMON_H}) && ${FILEMON_H:T} == "filemon.h"
COPTS.meta.c += -DHAVE_FILEMON_H -I${FILEMON_H:H}
.endif
.endif

.PATH:	${.CURDIR}/lst.lib
SUBDIR.roff+=	PSD.doc
.if make(obj) || make(clean)
SUBDIR+= unit-tests
.endif

.include <bsd.prog.mk>
.include <bsd.subdir.mk>

CPPFLAGS+= -DMAKE_NATIVE
COPTS.var.c += -Wno-cast-qual
COPTS.job.c += -Wno-format-nonliteral
COPTS.parse.c += -Wno-format-nonliteral
COPTS.var.c += -Wno-format-nonliteral

.ifdef TOOLDIR
# this is a native netbsd build, 
# use libutil rather than the local emalloc etc.
CPPFLAGS+= -DUSE_EMALLOC
LDADD+=-lutil
DPADD+=${LIBUTIL}
.endif

COPTS.arch.c+=	${GCC_NO_FORMAT_TRUNCATION}
COPTS.dir.c+=	${GCC_NO_FORMAT_TRUNCATION}
COPTS.main.c+=	${GCC_NO_FORMAT_TRUNCATION} ${GCC_NO_STRINGOP_TRUNCATION}
COPTS.meta.c+=	${GCC_NO_FORMAT_TRUNCATION}
COPTS.parse.c+=	${GCC_NO_FORMAT_TRUNCATION}

# A simple unit-test driver to help catch regressions
accept test:
	cd ${.CURDIR}/unit-tests && MAKEFLAGS= ${.MAKE} -r -m / TEST_MAKE=${TEST_MAKE:U${.OBJDIR}/${PROG:T}} ${.TARGET}
