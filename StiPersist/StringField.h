#ifndef STRINGFIELD_H
#define STRINGFIELD_H

#include "Field.h"

namespace StiPersist
{

	namespace Data
	{
		class StringField :
			public Field
		{
		public:
			StringField(std::string m_name);
			virtual ~StringField();
			
			std::string getText(void);
			void setText(std::string m_text);
			
			Chunk* getDataChunk(void);
		protected:
			std::string text;
		};
	}

}

#endif