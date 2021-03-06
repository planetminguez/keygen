/*
 * Copyright (c) 2004 Beeyond Software Holding BV
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*!\file SecretKeySpec.h
 * \ingroup CXX_CRYPTO_SPEC_m
 */

#ifndef _CLASS_SECRETKEYSPEC_H
#define _CLASS_SECRETKEYSPEC_H

#ifdef __cplusplus

#include "beecrypt/c++/array.h"
using beecrypt::array;
using beecrypt::bytearray;
#include "beecrypt/c++/security/spec/KeySpec.h"
using beecrypt::security::spec::KeySpec;
#include "beecrypt/c++/crypto/SecretKey.h"
using beecrypt::crypto::SecretKey;

namespace beecrypt {
	namespace crypto {
		namespace spec {
			/*!\ingroup CXX_CRYPTO_SPEC_m
			 */
			class BEECRYPTCXXAPI SecretKeySpec : public beecrypt::security::spec::KeySpec, public beecrypt::crypto::SecretKey
			{
			private:
				bytearray _data;
				String _algo;

			public:
				SecretKeySpec(const byte* data, size_t offset, size_t length, const String& algorithm);
				SecretKeySpec(const bytearray& b, const String& algorithm);
				virtual ~SecretKeySpec();

				virtual const String& getAlgorithm() const throw ();
				virtual const String* getFormat() const throw ();
				virtual const bytearray* getEncoded() const throw ();

				bool operator==(const Key& compare) const throw ();
			};
		}
	}
}

#endif

#endif
