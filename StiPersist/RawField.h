#ifndef RAWFIELD_H
#define RAWFIELD_H

#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		class RawField
			: public Field
		{
		public:
			RawField(std::string m_name);
			virtual ~RawField();
			
			Chunk* getDataChunk(void);
			void fromDataChunk(Chunk *dataChunk);
			
			void setData(char *m_data, unsigned int m_length);
			unsigned int getLength(void);
			char* getData(void);
			
		protected:
			unsigned int length;
			char *data;
		};
	}
}

#endif