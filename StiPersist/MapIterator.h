#ifndef MAPITERATOR_H
#define MAPITERATOR_H

#include "Iterator.h"
#include "Map.h"

namespace StiPersist
{
	namespace Container
	{
		class MapIterator :
			public Iterator
		{
		public:
			MapIterator(Map *m_map);
			virtual ~MapIterator();
			
			bool hasNext(void);
			bool moveNext(void);
			
			std::string getKey(void);
			
			IPersist* getElement(void);
			IteratorType getType(void);
		private:
			Map *map;
			MapNode *current;
			bool started;
		};
	}
}

#endif