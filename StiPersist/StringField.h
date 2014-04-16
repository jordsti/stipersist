#ifndef STRINGFIELD_H
#define STRINGFIELD_H

#include "Field.h"

namespace StiPersist
{

	namespace Data
	{
		/// \class StringField
		/// \biref String Field
		class StringField :
			public Field
		{
		public:
			/// \brief Constructor
			/// \param m_name Field Name
			StringField(std::string m_name);
			
			/// \brief Destructor
			virtual ~StringField();
			
			/// \brief Get Text Value
			/// \return Text value
			std::string getText(void);
			
			/// \brief Set Text Value
			/// \param m_text Text value
			void setText(std::string m_text);
			
			/// \brief Get Data Chunk
			/// \return Data Chunk Pointer
			Chunk* getDataChunk(void);
		protected:
			
			/// \brief Text value
			std::string text;
		};
	}

}

#endif