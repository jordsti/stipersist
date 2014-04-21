#include "ArrayField.h"
#include "Buffer.h"
#include "ArrayIterator.h"
#include "FieldsObject.h"

namespace StiPersist
{
	namespace Data
	{
	
		ArrayField::ArrayField(std::string m_name)
			: Field(m_name, FT_ARRAY)
		{
			array = nullptr;
		}
		
		ArrayField::~ArrayField() {}
		
		Chunk* ArrayField::getDataChunk(void)
		{
			Buffer buffer = Buffer();
			
			ArrayHeader head = ArrayHeader();
			head.length = array->getLength();
			unsigned int h_length = sizeof(ArrayHeader);
			
			ArrayNodeMarker *marker;
			unsigned int m_length = sizeof(ArrayNodeMarker);
			
			char *h_data = reinterpret_cast<char*>(&head);
			
			Chunk *h_chunk = new Chunk(h_data, h_length);
			
			buffer.append(h_chunk);
			
			Container::ArrayIterator *it = array->getIterator();
			
			while(it->moveNext())
			{
				IPersist *obj = it->getElement();
				
				Buffer *ebuffer = obj->getChunkBuffer();
				
				Chunk *dataChunk = ebuffer->getChunk();
				
				marker = new ArrayNodeMarker();
				
				marker->length = dataChunk->getLength();
				
				char *m_data = reinterpret_cast<char*>(marker);
				
				Chunk *mChunk = new Chunk(m_data, m_length);
				
				buffer.append(mChunk);
				buffer.append(dataChunk);
				
				delete ebuffer;
				
			}
			
			return buffer.getChunk();
		}
		
		void ArrayField::fromDataChunk(Chunk *dataChunk)
		{
			unsigned int length = dataChunk->getLength();
			char *data = dataChunk->getData();
			
			unsigned int current = 0;
			unsigned int h_length = sizeof(ArrayHeader);
			unsigned int m_length = sizeof(ArrayNodeMarker);
			
			char *h_data = new char[h_length];
			
			char *m_data = new char[m_length];
			
			for(int i=0; i<h_length; i++)
			{
				h_data[i] = data[current+i];
			}
			
			current += h_length;
			
			ArrayHeader *head = reinterpret_cast<ArrayHeader*>(h_data);
			
			array = new Container::Array(head->length);
			
			for(int i=0; i<head->length; i++)
			{
				//reading marker
				for(int j=0; j<m_length; j++)
				{
					m_data[j] = data[current+j];
				}
				
				current += m_length;
				
				ArrayNodeMarker *marker = reinterpret_cast<ArrayNodeMarker*>(m_data);
				
				unsigned int e_length = marker->length;
				
				//reading data
				char *f_data = new char[e_length];
				
				for(int j=0; j<e_length; j++)
				{
					f_data[j] = data[current+j];
				}
				
				current += e_length;
				
				Chunk *dataChunk = new Chunk(f_data, e_length);
				
				//fieldsobject
				
				
				FieldsObject *obj = new FieldsObject();
				
				obj->fromChunk(dataChunk);
				
				array->append(obj);
			}
			
		}
		
		void ArrayField::setArray(Container::Array *m_array)
		{
			array = m_array;
		}
		
		Container::Array* ArrayField::getArray(void)
		{
			return array;
		}
	
	}
}