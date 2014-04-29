#ifndef BUFFER_H
#define BUFFER_H

#include <list>
#include "Chunk.h"

namespace StiPersist
{
	namespace Data
	{
		/// \class Buffer
		/// \brief Chunk buffer to append all chunk and create a unique chunk
		class Buffer
		{
		public:
			/// \brief Create an empty buffer
			Buffer();

			/// \brief Destructor
			virtual ~Buffer();

			/// \brief Append a Chunk of data
			/// \param chunk Chunk Pointer

			void append(Chunk *chunk);
			/// \brief Append Data
			/// \param data Char Array
			/// \param length Length of the array
			void append(char *data, unsigned int length);

			/// \brief Clearing the memory by deleting the Chunk
			void clear(void);

			//Chunk* getChunk(int index);
			/// \brief Get Chunk Count
			/// \return Chunk Count
			int getChunkCount(void);

			/// \brief Create a new Chunk that combine all chunks
			/// \return Chunk Pointer
			Chunk* getChunk(void);

			bool isAutoClear(void);
			void setAutoClear(bool m_autoClear);

			/// \brief Count the length of the buffer
			/// \return Buffer Length
			unsigned int count(void);
		protected:
			/// \brief Chunks Container
			std::list<Chunk*> chunks;

			bool autoClear;
		};
	}
}

#endif
