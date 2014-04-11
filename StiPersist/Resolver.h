#ifndef RESOLVER_H
#define RESOLVER_H

#include "Field.h"
#include "Chunk.h"

namespace StiPersist
{

	class Resolver 
	{
	public:
		virtual ~Resolver();
		virtual Data::Field* getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk) = 0;
	protected:
		Resolver();
	};

}

#endif