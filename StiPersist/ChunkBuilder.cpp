#include "ChunkBuilder.h"
#include "Field.h"

#include <iostream>

namespace StiPersist
{

	namespace Data
	{
		Chunk* ChunkFromFieldMarker(FieldMarker *marker)
		{
			unsigned int length = sizeof(FieldMarker);
			char *data = reinterpret_cast<char*>(marker);
			
			Chunk *chunk = new Chunk(data, length);
			return chunk;
		}
	
		Chunk* ChunkFromString(std::string text)
		{
			unsigned int length = text.size() + 1;
			std::cout << length << std::endl;
			char *data = new char[length];
			memcpy(data, text.c_str(), length - 1);
			data[length] = '\0';
			std::cout << "--2--" <<std::endl;
			Chunk *chunk = new Chunk(data, length);
			std::cout << "--3--" <<std::endl;
			return chunk;
		}
	}

}