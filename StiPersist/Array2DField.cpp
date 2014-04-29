#include "Array2DField.h"
#include "Buffer.h"
#include "FieldsObject.h"
namespace StiPersist
{
	namespace Data
	{
		Array2DField::Array2DField(std::string m_name)
			: Field(m_name, FT_ARRAY2D)
		{
			array = new Container::Array2D();
		}

		Array2DField::~Array2DField() {}

		Chunk* Array2DField::getDataChunk(void)
		{
			Buffer buffer = Buffer();

			Array2DHeader head = Array2DHeader();
			head.ilength = array->getiLength();
			head.jlength = array->getjLength();

			Array2DNodeMarker marker = Array2DNodeMarker();
			unsigned int m_length = sizeof(Array2DNodeMarker);

			unsigned int h_length = sizeof(Array2DHeader);
			char *h_data = reinterpret_cast<char*>(&head);

			Chunk *h_chunk = new Chunk(h_data, h_length);

			buffer.append(h_chunk);

			for(int i=0; i<head.ilength; i++)
			{
				for(int j=0; j<head.jlength; j++)
				{
					Buffer *dbuffer = array->get(i, j)->getChunkBuffer();
					Chunk *dataChunk = dbuffer->getChunk();

					unsigned int n_length = dataChunk->getLength();

					marker.length = n_length;

					char *m_data = reinterpret_cast<char*>(&marker);

					Chunk *m_chunk = new Chunk(m_data, m_length);

					buffer.append(m_chunk);
					buffer.append(dataChunk);

					delete dbuffer;
				}
			}

			return buffer.getChunk();
		}

		void Array2DField::fromDataChunk(Chunk *dataChunk)
		{
			unsigned int length = dataChunk->getLength();
			char *data = dataChunk->getData();

			Array2DHeader *head = new Array2DHeader();
			unsigned int h_length = sizeof(Array2DHeader);

			char *h_data = new char[h_length];

			Array2DNodeMarker *marker = new Array2DNodeMarker();
			unsigned int m_length = sizeof(Array2DNodeMarker);

			char *m_data = new char[m_length];

			unsigned int current = 0;

			//reading header
			for(int i=0; i<h_length; i++)
			{
				h_data[i] = data[current+i];
			}

			head = reinterpret_cast<Array2DHeader*>(h_data);

			current += h_length;

			array = new Container::Array2D(head->ilength, head->jlength);

			//reading node

			for(int i=0; i<array->getiLength(); i++)
			{
				for(int j=0; j<array->getjLength(); j++)
				{
					//reading marker
					for(int k=0; k<m_length; k++)
					{
						m_data[k] = data[current+k];
					}

					marker = reinterpret_cast<Array2DNodeMarker*>(m_data);

					current += m_length;

					//reading data

					char *n_data = new char[marker->length];

					for(int k=0; k<marker->length; k++)
					{
						n_data[k] = data[current+k];
					}

					current += marker->length;

					Chunk *dataChunk = new Chunk(n_data, marker->length);

					FieldsObject *obj = new FieldsObject();

					obj->fromChunk(dataChunk);

					array->append(i, obj);
				}
			}

			//creating objects fields

			delete head;
			delete marker;
		}

		void Array2DField::setArray(Container::Array2D *m_array)
		{
			array = m_array;
		}

		Container::Array2D* Array2DField::getArray(void)
		{
			return array;
		}

	}

}
