/*
 * $Id: structs.h,v 1.7 2004/01/23 18:56:43 vixie Exp $
 */

/*
 * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")
 * Copyright (c) 1997,2000 by Internet Software Consortium, Inc.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

typedef	struct _entry {
	bitstr_t	bit_decl(minute, MINUTE_COUNT);
	bitstr_t	bit_decl(hour,   HOUR_COUNT);
	bitstr_t	bit_decl(dom,    DOM_COUNT);
	bitstr_t	bit_decl(month,  MONTH_COUNT);
	bitstr_t	bit_decl(dow,    DOW_COUNT);
	int		flags;
#define	MIN_STAR	0x01
#define	HR_STAR		0x02
#define	DOM_STAR	0x04
#define	DOW_STAR	0x08
#define	WHEN_REBOOT	0x10
} entry;
