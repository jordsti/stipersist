#ifndef ARRAY2DFIELD_H
#define ARRAY2DFIELD_H

#include "Field.h"
#include "Array2D.h"

namespace StiPersist
{
	namespace Data
	{
		struct Array2DHeader {
			unsigned int ilength;
			unsigned int jlength;
		};
		
		struct Array2DNodeMarker {
			unsigned int length;
		};
	
		/// \class Array2DField
		/// \brief Field to serialize a Array2D
		class Array2DField
			: public Field
		{
		public:
			/// \brief Constructor
			/// \param m_name Field Name
			Array2DField(std::string m_name);
			
			/// \brief Destructor
			virtual ~Array2DField();
			
			/// \brief Get Data Chunk
			/// \return Data Chunk
			Chunk *getDataChunk(void);
			
			/// \brief Get Data From Chunk
			/// \param dataChunk Data Chunk
			void fromDataChunk(Chunk *dataChunk);
			
			/// \brief Set the Array2D
			/// \param m_array Array2D Pointer
			void setArray(Container::Array2D *m_array);
			
			/// \brief Get the Array2D
			/// \return Array2D Pointer
			Container::Array2D *getArray(void);
			
		protected:
			/// \brief Array2D
			Container::Array2D *array;
		};
	}
}

#endif