/* salsa20.h
 *
 * The Salsa20 stream cipher.
 */

/* nettle, low-level cryptographics library
 *
 * Copyright (C) 2012 Simon Josefsson
 * Copyright (C) 2001 Niels Möller
 *  
 * The nettle library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 * 
 * The nettle library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with the nettle library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */
 
#ifndef NETTLE_SALSA20_H_INCLUDED
#define NETTLE_SALSA20_H_INCLUDED

#include "nettle-types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Name mangling */
#define salsa20_set_key nettle_salsa20_set_key
#define salsa20_set_iv nettle_salsa20_set_iv
#define salsa20_crypt nettle_salsa20_crypt

/* Minimum and maximum keysizes, and a reasonable default. In
 * octets.*/
#define SALSA20_MIN_KEY_SIZE 16
#define SALSA20_MAX_KEY_SIZE 32
#define SALSA20_KEY_SIZE 32

#define SALSA20_IV_SIZE 8

struct salsa20_ctx
{
    uint32_t input[16];
};

void
salsa20_set_key(struct salsa20_ctx *ctx,
		unsigned length, const uint8_t *key);

void
salsa20_set_iv(struct salsa20_ctx *ctx,
	       unsigned length, const uint8_t *iv);

void
salsa20_crypt(struct salsa20_ctx *ctx,
	      unsigned length, uint8_t *dst,
	      const uint8_t *src);

#ifdef __cplusplus
}
#endif

#endif /* NETTLE_SALSA20_H_INCLUDED */