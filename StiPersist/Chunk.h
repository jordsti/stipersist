#ifndef CHUNK_H
#define CHUNK_H

#include <string>

namespace StiPersist
{

	namespace Data
	{
		struct FieldMarker;
	
		struct ChunkMarker {
			unsigned int length;
		};
	
		class Chunk
		{
		public:
			Chunk();
			Chunk(char *m_data, unsigned int m_length);
			
			void setClearData(bool m_clearData);
			bool getClearData(void);
			
			unsigned int getLength(void);
			
			char* getData(void);
		
			void setData(char *m_data, unsigned int m_length);
			
			ChunkMarker* getMarker(void);
			
			virtual ~Chunk();
			
			std::string toString(void);
			
			static Chunk* FromString(std::string text);
			static Chunk* FromFieldMarker(FieldMarker *marker);
			static Chunk* FromChunkMarker(ChunkMarker *marker);
		private:
			bool clearData;
			char *data;
			unsigned int length;
		};
		
	}

}

#endif