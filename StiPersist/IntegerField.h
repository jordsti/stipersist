#ifndef INTEGERFIELD_H
#define INTEGERFIELD_H

#include "Field.h"

namespace StiPersist
{
	namespace Data
	{
		struct IntegerStruct
		{
			int value;
		};	
	
		/// \class IntegerField
		/// \brief Interger Field
		class IntegerField :
			public Field
		{
		public:
			/// \brief Integer Byte Length
			static const int INTEGER_LENGTH;
			
			/// \brief Constructor
			/// \param m_name Field Name
			IntegerField(std::string m_name);
			
			/// \brief Destructor
			virtual ~IntegerField();
			
			/// \brief Get Data Chunk
			/// \return Data Chunk Pointer
			Chunk* getDataChunk(void);
			
			/// \brief Set the Field Value from a Data Chunk
			/// \param data Chunk Field Data Chunk
			void fromDataChunk(Chunk *dataChunk);
			
			/// \brief Set Integer Value
			/// \param m_integer Integer value
			void setInteger(int m_integer);
			
			/// \brief Get Integer Value
			/// \return Integer value
			int getInteger(void);
			
		protected:
			/// \brief Integer value
			int integer;
		};
	}
}

#endif