#ifndef FLOATFIELD_H
#define FLOATFIELD_H

#include "Field.h"

namespace StiPersist
{

	namespace Data
	{
		struct FloatStruct
		{
			float value;
		};
	
		/// \class FloatField
		/// \brief Float Field
		class FloatField : 
			public Field
		{
		public:
			/// \brief Constructor
			/// \param m_name Field Name
			FloatField(std::string m_name);
			
			/// \brief Destructor
			virtual ~FloatField();
			
			/// \brief Get Data Chunk
			/// \return Data Chunk Pointer
			Chunk* getDataChunk();
		
			/// \brief Set Float Value
			/// \param m_value Float value
			void setFloat(float m_value);
			
			/// \brief Get Float Value
			/// \return Float value
			float getFloat(void);
		protected:
			/// \brief Float Value
			float value;
		};
	
	}

}

#endif