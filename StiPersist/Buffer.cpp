#include "Buffer.h"
#include <iostream>
namespace StiPersist
{
	namespace Data
	{
		Buffer::Buffer() {}

		Buffer::~Buffer() {}
	
		void Buffer::append(Chunk *chunk)
		{
			chunks.push_back(chunk);
		}
		
		void Buffer::append(char *data, unsigned int length)
		{
			Chunk *chunk = new Chunk(data, length);
			chunks.push_back(chunk);
		}
		
		/*Chunk* Buffer::getChunk(int index)
		{
			return chunks[index];
		}*/
		
		int Buffer::getChunkCount(void)
		{
			return chunks.size();
		}
		
		
		void Buffer::clear(void)
		{
			std::list<Chunk*>::iterator lit(chunks.begin()), lend(chunks.end());
			for(;lit!=lend;++lit)
			{
				delete (*lit);
			}
			
			chunks.clear();
		}
	
		Chunk* Buffer::getChunk(void)
		{
			unsigned int length = count();
			unsigned int current = 0;
			char *data = new char[length];
			std::list<Chunk*>::iterator lit(chunks.begin()), lend(chunks.end());
			
			for(;lit!=lend;++lit)
			{
				char *c_data = (*lit)->getData();
				unsigned int c_length = (*lit)->getLength();
				
				for(int i=0; i<c_length; i++)
				{
					data[current+i] = c_data[i];
				}
				
				current += c_length;
			}

			Chunk *chunk = new Chunk(data, length);
			return chunk;
		}
		
		unsigned int Buffer::count(void)
		{
			unsigned int length = 0;
			
			std::list<Chunk*>::iterator lit(chunks.begin()), lend(chunks.end());
			for(;lit!=lend;++lit)
			{
				length += (*lit)->getLength();
			}
			
			return length;
		}

	}
}