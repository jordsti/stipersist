#ifndef ARRAYFIELD_H
#define ARRAYFIELD_H

#include "Field.h"
#include "Array.h"

namespace StiPersist
{
	namespace Data
	{
		struct ArrayHeader
		{
			unsigned int length;
		};
		
		struct ArrayNodeMarker
		{
			unsigned int length;
		};
	
		/// \class ArrayField
		/// \brief Field that handle a single dimension array
		class ArrayField :
			public Field
		{
		public:
			/// \brief Constructor
			/// \param m_name Field Name
			ArrayField(std::string m_name);
			
			/// \brief Destructor
			virtual ~ArrayField();
			
			/// \brief Get Data Chunk
			/// \return Data Chunk
			Chunk* getDataChunk(void);
			
			/// \brief Populate field from Data Chunk
			/// \param dataChunk Data Chunk
			void fromDataChunk(Chunk *dataChunk);
			
			/// \brief Set Array
			/// \param m_array Array Pointer
			void setArray(Container::Array *m_array);
			
			/// \brief Get Array
			/// \return Array Pointer
			Container::Array* getArray(void);
			
		private:
			/// \brief Array
			Container::Array *array;
		};
	}
}

#endif