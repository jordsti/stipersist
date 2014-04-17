#ifndef DOUBLEFIELD_H
#define DOUBLEFIELD_H

#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		struct DoubleStruct
		{
			double value;
		};
	
		class DoubleField :
			public Field
		{
		public:
			DoubleField(std::string m_name);
			virtual ~DoubleField();
			
			Chunk *getDataChunk(void);
			
			void setDouble(double m_value);
			double getDouble(void);
			
			/// \brief Set the Field Value from a Data Chunk
			/// \param data Chunk Field Data Chunk
			void fromDataChunk(Chunk *dataChunk);
	
		protected:
			double value;
		
		};
	}
}

#endif