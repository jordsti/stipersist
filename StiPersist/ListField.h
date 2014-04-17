#ifndef LISTFIELD_H
#define LISTFIELD_H

#include "FieldsObject.h"
#include "List.h"

namespace StiPersist
{
	namespace Data
	{
		struct ListNodeMarker
		{
			unsigned int length;
		};
	
		class ListField :
			public Field
		{
		public:
			ListField(std::string m_name);
			virtual ~ListField();
			
			Chunk* getDataChunk(void);
			void fromDataChunk(Chunk *dataChunk);
		
			Container::List* getList(void);
			void setList(Container::List *m_list);
		
		protected:
			Container::List *list;
		};
	}

}

#endif