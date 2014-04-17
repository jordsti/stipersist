#ifndef BOOLFIELD_H
#define BOOLFIELD_H

#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		const char BF_TRUE = 0x01;
		const char BF_FALSE = 0x00;
	
		class BoolField :
			public Field
		{
		public:
			BoolField(std::string m_name);
			virtual ~BoolField();
			
			Chunk* getDataChunk(void);
			
			/// \brief Set the Field Value from a Data Chunk
			/// \param data Chunk Field Data Chunk
			void fromDataChunk(Chunk *dataChunk);
			
			void setBool(bool m_value);
			bool getBool(void);
			
			static char GetCharValue(bool value);
			static bool GetBoolValue(char value);
			
		protected:
		
			bool value;
		};
	
	}
}

#endif