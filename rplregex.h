/*
** Copyright (c) 2016, Cyrille Lefevre <cyrille.lefevre-regs@laposte.net>.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 
**   1. Redistributions of source code must retain the above copyright
**      notice, this list of conditions and the following disclaimer.
**   2. Redistributions in binary form must reproduce the above copyright
**      notice, this list of conditions and the following disclaimer in the
**      documentation and/or other materials provided with the distribution.
**
** THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
** PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS
** BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
** OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
** BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
** OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef _RPLREGEX_H_
#define _RPLREGEX_H_

#ifdef HAVE_REGEX
#include <regex.h>
#define REGEXP_T	regexp_t
typedef struct {
	regex_t preg;
	int cflags;
	const char *string;
	regmatch_t *pmatch;
} regexp_t;
#else
#include "regexp.h"
#define REGEXP_T	regexp
#ifndef REG_NOMATCH
#define REG_NOMATCH	1
#endif
#ifndef REG_ESUBREG
#define REG_ESUBREG	6
#endif
#ifndef REG_ESPACE
#define REG_ESPACE	12
#endif
#endif

void rpl_regfree(REGEXP_T **_prog);
int rpl_regcomp(REGEXP_T **_prog, const char *regex, int cflags);
int rpl_regexec(REGEXP_T * const *_prog, const char *string);
int rpl_regsub(REGEXP_T * const *_prog, const char *source, char *dest, size_t size);
char *rpl_regerror(int error, REGEXP_T * const *_prog);

#endif /* !_RPLREGEX_H_ */
