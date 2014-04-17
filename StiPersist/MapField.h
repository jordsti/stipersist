#ifndef MAPFIELD_H
#define MAPFIELD_H

#include "Field.h"
#include "Map.h"

namespace StiPersist
{
	namespace Data
	{
		struct MapNodeMarker
		{
			unsigned int length;
			unsigned int keyLength;
		};
	
		class MapField :
			public Field
		{
		public:
			MapField(std::string m_name);
			virtual ~MapField();
			
			Data::Chunk *getDataChunk(void);
			void fromDataChunk(Data::Chunk *dataChunk);
			
			void setMap(Container::Map *m_map);
			Container::Map* getMap(void);
			
		protected:
			Container::Map *map;
		};
	}
}

#endif