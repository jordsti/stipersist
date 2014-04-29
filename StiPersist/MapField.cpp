#include "MapField.h"
#include "MapIterator.h"
#include "Resolver.h"
#include "FieldsObject.h"

namespace StiPersist
{
	namespace Data
	{
		MapField::MapField(std::string m_name)
			: Field(m_name, FT_MAP)
		{
			map = nullptr;
		}

		MapField::~MapField() {}

		Chunk* MapField::getDataChunk(void)
		{
			Buffer buffer = Buffer();
			MapNodeMarker *marker = new MapNodeMarker();
			Container::MapIterator *iterator = map->getIterator();

			while(iterator->moveNext())
			{
				Chunk *keyChunk = Chunk::FromString(iterator->getKey());

				Buffer *ibuffer = iterator->getElement()->getChunkBuffer();

				Chunk *dataChunk = ibuffer->getChunk();

				marker->length = dataChunk->getLength();
				marker->keyLength = keyChunk->getLength();

				char *m_data = reinterpret_cast<char*>(marker);

				Data::Chunk *mchunk = new Data::Chunk(m_data, sizeof(MapNodeMarker));

				buffer.append(mchunk);
				buffer.append(keyChunk);
				buffer.append(dataChunk);

                delete ibuffer;
			}

			return buffer.getChunk();
		}

		void MapField::fromDataChunk(Data::Chunk *dataChunk)
		{
			map = new Container::Map();
			MapNodeMarker *marker = new MapNodeMarker();
			unsigned int length = dataChunk->getLength();
			char *data = dataChunk->getData();
			unsigned int m_length = sizeof(MapNodeMarker);
			unsigned int current = 0;

			while(current < length)
			{
				//reading marker
				char *m_data = new char[m_length];

				for(int i=0; i<m_length; i++)
				{
					m_data[i] = data[current+i];
				}

				current += m_length;

				marker = reinterpret_cast<MapNodeMarker*>(m_data);

				//reading key
				char *k_data = new char[marker->keyLength];

				for(int i=0; i<marker->keyLength; i++)
				{
					k_data[i] = data[current+i];
				}

				current += marker->keyLength;

				//reading data chunk

				char *f_data = new char[marker->length];

				for(int i=0; i<marker->length; i++)
				{
					f_data[i] = data[current+i];
				}

				current += marker->length;

				//creating fields objects, assign fields, push node

				Chunk *keyChunk = new Chunk(k_data, marker->keyLength);
				Chunk *dataChunk = new Chunk(f_data, marker->length);

				std::string key = keyChunk->toString();

				FieldsObject *obj = new FieldsObject();
				obj->fromChunk(dataChunk);

				map->append(key, obj);
			}

		}

		void MapField::setMap(Container::Map *m_map)
		{
			map = m_map;
		}

		Container::Map* MapField::getMap(void)
		{
			return map;
		}
	}
}
