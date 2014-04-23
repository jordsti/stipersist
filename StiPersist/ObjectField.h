#ifndef OBJECTFIELD_H
#define OBJECTFIELD_H

#include "Field.h"
#include "Persistable.h"

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
			
			void fromDataChunk(Chunk *dataChunk);
			
			/// \brief Set Object Pointer
			/// \param m_object IPersist Pointer
			void setObject(Persistable *m_object);
			
			/// \brief Get Object Pointer
			/// \return IPersist Pointer
			Persistable* getObject(void);
			
		protected:
			/// \brief Object pointer
			Persistable *object;
		};
	}

}

#endif