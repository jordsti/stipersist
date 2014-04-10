#ifndef CHUNKBUILDER_H
#define CHUNKBUILDER_H

#include "Chunk.h"
#include <string>

namespace StiPersist
{

	namespace Data
	{
		struct FieldMarker;
		
		Chunk* ChunkFromString(std::string text);
		Chunk* ChunkFromFieldMarker(FieldMarker *marker);
	}

}

#endif