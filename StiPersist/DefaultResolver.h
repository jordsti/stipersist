#ifndef DEFAULTRESOLVER_H
#define DEFAULTRESOLVER_H

#include "Resolver.h"

namespace StiPersist
{
	class DefaultResolver :
		public Resolver
	{
	public:
		DefaultResolver();
		virtual ~DefaultResolver();
		Data::Field* getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk);
	};


}

#endif