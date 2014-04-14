#ifndef RESOLVER_H
#define RESOLVER_H

#include "ObjectField.h"
#include "Chunk.h"

namespace StiPersist
{
	class Resolver 
	{
	public:
		virtual ~Resolver();
		virtual Data::Field* getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk) = 0;
		virtual void buildObjectField(Data::Chunk *nameChunk, Data::Chunk *dataChunk, IPersist *parent) = 0;
	protected:
		Resolver();
	};

}

#endif