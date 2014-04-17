#include "ListField.h"
#include "ListIterator.h"
namespace StiPersist
{
	namespace Data
	{
		ListField::ListField(std::string m_name)
			: Field(m_name, FT_LIST)
		{
			list = nullptr;
		}
		
		ListField::~ListField() {}
		
		Chunk* ListField::getDataChunk(void)
		{
			Buffer *buffer = new Buffer();
			Container::ListIterator *iterator = list->getIterator();
			ListNodeMarker *marker = new ListNodeMarker();
			
			while(iterator->moveNext())
			{
				IPersist *obj = iterator->getElement();
				
				Buffer *ibuffer = obj->getChunkBuffer();
				
				Chunk *ichunk = ibuffer->getChunk();
				
				marker->length = ichunk->getLength();
				
				char *c_marker = reinterpret_cast<char*>(marker);
				
				Chunk *mchunk = new Chunk(c_marker, sizeof(ListNodeMarker));
				
				buffer->append(mchunk);
				buffer->append(ichunk);
				
			}
			
			return buffer->getChunk();
		}
		
		void ListField::fromDataChunk(Chunk *dataChunk)
		{
			list = new Container::List();
			
			char *data = dataChunk->getData();
			unsigned int length = dataChunk->getLength();
			unsigned int m_length = sizeof(ListNodeMarker);
			unsigned int current = 0;
			ListNodeMarker *marker = new ListNodeMarker();
			
			while(current < length)
			{
				//reading marker
				char *m_data = new char[m_length];
				
				for(int i=0; i<m_length; i++)
				{
					m_data[i] = data[current+i];
				}
				
				current += m_length;
				
				marker = reinterpret_cast<ListNodeMarker*>(m_data);
				
				char *n_data = new char[marker->length];
				
				for(int i=0; i<marker->length; i++)
				{
					n_data[i] = data[current+i];
				}
				
				current += marker->length;
				
				Chunk *nchunk = new Chunk(n_data, marker->length);
				
				FieldsObject *obj = new FieldsObject();
				
				obj->fromChunk(nchunk);
				
				list->append(obj);
			}
			
		}
	
		Container::List* ListField::getList(void)
		{
			return list;
		}
	
		void ListField::setList(Container::List *m_list)
		{
			list = m_list;
		}
	}
}