#	$NetBSD: Makefile,v 1.2 2019/01/27 02:08:45 pgoyette Exp $

.include "../Makefile.inc"

.PATH:	${S}/compat/common

KMOD=	compat_60

CPPFLAGS+=	-DCOMPAT_60 -DCOMPAT_70 -DCOMPAT_80

SRCS+=	compat_60_mod.c kern_sa_60.c tty_60.c kern_time_60.c ccd_60.c \
	kern_cpu_60.c

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
CPPFLAGS+=	-DCPU_UCODE

.PATH:	${S}/arch/x86/x86
SRCS+=	compat_60_cpu_ucode.c
.endif

.include <bsd.kmodule.mk>
