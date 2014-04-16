#ifndef OBJECTFIELD_H
#define OBJECTFIELD_H

#include "Field.h"
#include "IPersist.h"

namespace StiPersist
{

	namespace Data
	{
		/// \class ObjectField
		/// \brief Child Object Field
		class ObjectField :
			public Field
		{
		public:
			/// \brief Destructor
			/// \param m_name Field Name
			ObjectField(std::string m_name);
			
			/// \brief Destructor
			virtual ~ObjectField();
			
			/// \brief Get Data Chunk
			/// \return Data Chunk Pointer
			Chunk* getDataChunk(void);
			
			/// \brief Set Object Pointer
			/// \param m_object IPersist Pointer
			void setObject(IPersist *m_object);
			
			/// \brief Get Object Pointer
			/// \return IPersist Pointer
			IPersist* getObject(void);
			
		protected:
			/// \brief Object pointer
			IPersist *object;
		};
	}

}

#endif