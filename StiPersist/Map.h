#ifndef MAP_H
#define MAP_H

#include "MapNode.h"

namespace StiPersist
{
	namespace Container
	{
		class Map
		{
		public:
			Map();
			virtual ~Map();
			
			void append(std::string key, IPersist *element);
			void append(MapNode *node);
			
			MapNode* get(std::string key);
			bool contains(std::string key);
			
			MapNode* remove(std::string key);
			
			MapNode* getFirst(void);
			MapNode* getLast(void);
			
			int size(void);
			
		private:
			MapNode *first;
		};
	}
}

#endif