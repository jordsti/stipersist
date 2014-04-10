#include "Chunk.h"
#include <iostream>
#include "Field.h"
namespace StiPersist
{

	namespace Data
	{
	
		Chunk::Chunk()
		{
			data = 0;
			length = 0;
			clearData = false;
		}
		
		Chunk::Chunk(char *m_data, unsigned int m_length)
		{
			data = m_data;
			length = m_length;
			std::cout << "Chunk : " << length << std::endl;
			clearData = false;
		}
		
		void Chunk::setClearData(bool m_clearData)
		{
			clearData = m_clearData;
		}
		
		bool Chunk::getClearData(void)
		{
			return clearData;
		}
		
		unsigned int Chunk::getLength(void)
		{
			return length;
		}
		
		char* Chunk::getData(void)
		{
			return data;
		}
		
		void Chunk::setData(char *m_data, unsigned int m_length)
		{
			data = m_data;
			length = m_length;
		}
		
		ChunkMarker* Chunk::getMarker(void)
		{
			ChunkMarker *marker = new ChunkMarker();
			marker->length = length;
			return marker;
		}
		
		Chunk::~Chunk()
		{
			if(clearData && data != 0)
			{
				delete data;
			}
		}
	
	
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
			char *data = new char[length];
			
			memcpy(data, text.c_str(), length - 1);
			data[length] = '\0';
			
			Chunk *chunk = new Chunk(data, length);
			chunk->setData(data, length);
			
			return chunk;
		}
	}
	
}