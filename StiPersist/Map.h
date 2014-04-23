#ifndef MAP_H
#define MAP_H

#include "MapNode.h"

namespace StiPersist
{
	namespace Container
	{
		class MapIterator;

		class Map
		{
		public:
			Map();
			virtual ~Map();

			void append(std::string key, Persistable *element);
			void append(MapNode *node);
			void append(Map *map);

			MapNode* get(std::string key);
			bool contains(std::string key);

			MapNode* remove(std::string key);

			MapNode* getFirst(void);
			MapNode* getLast(void);

			int size(void);

			void clear(void);

			MapIterator* getIterator(void);

		private:
			MapNode *first;
		};
	}
}

#endif
