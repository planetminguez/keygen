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

/*!\file DHPrivateKeyImpl.h
 * \ingroup CXX_PROVIDER_m
 */

#ifndef _CLASS_DHPRIVATEKEYIMPL_H
#define _CLASS_DHPRIVATEKEYIMPL_H

#ifdef __cplusplus

#include "beecrypt/c++/crypto/interfaces/DHPrivateKey.h"
using beecrypt::crypto::interfaces::DHPrivateKey;
#include "beecrypt/c++/crypto/spec/DHParameterSpec.h"
using beecrypt::crypto::spec::DHParameterSpec;
#include "beecrypt/c++/lang/Cloneable.h"
using beecrypt::lang::Cloneable;
#include "beecrypt/c++/lang/Object.h"
using beecrypt::lang::Object;

using beecrypt::bytearray;
using beecrypt::crypto::interfaces::DHParams;
using beecrypt::lang::String;

namespace beecrypt {
	namespace provider {
		class DHPrivateKeyImpl : public beecrypt::lang::Object, public beecrypt::crypto::interfaces::DHPrivateKey, public beecrypt::lang::Cloneable
		{
		private:
			DHParameterSpec* _params;
			mpnumber _x;
			mutable bytearray* _enc;

		public:
			DHPrivateKeyImpl(const DHPrivateKey&);
			DHPrivateKeyImpl(const DHPrivateKeyImpl&);
			DHPrivateKeyImpl(const DHParams&, const mpnumber&);
			DHPrivateKeyImpl(const dhparam&, const mpnumber&);
			DHPrivateKeyImpl(const mpbarrett&, const mpnumber&, const mpnumber&);
			virtual ~DHPrivateKeyImpl();

			virtual DHPrivateKeyImpl* clone() const throw ();

			virtual bool equals(const Object& compare) const throw ();

			virtual const DHParams& getParams() const throw ();
			virtual const mpnumber& getX() const throw ();

			virtual const bytearray* getEncoded() const;

			virtual const String& getAlgorithm() const throw ();
			virtual const String* getFormat() const throw ();
		};
	}
}

#endif

#endif
