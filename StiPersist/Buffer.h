#ifndef BUFFER_H
#define BUFFER_H

#include <list>
#include "Chunk.h"

namespace StiPersist
{
	namespace Data
	{
		class Buffer
		{
		public:
			Buffer();
			virtual ~Buffer();
		
			void append(Chunk *chunk);
			void append(char *data, unsigned int length);
			
			void clear(void);
		
			Chunk* getChunk(void);
			unsigned int count(void);
		protected:
			std::list<Chunk*> chunks;
		};
	}
}

#endif