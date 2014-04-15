#include "Map.h"
#include "MapIterator.h"

namespace StiPersist
{
	namespace Container
	{
		Map::Map()
		{
			first = nullptr;
		}
		
		Map::~Map() {}
		
		void Map::append(std::string key, IPersist *element)
		{
			MapNode *node = new MapNode(key, element);
			
			append(node);
		}
		
		void Map::append(Map *map)
		{
			MapNode *mfirst = map->getFirst();
			
			if(mfirst != nullptr)
			{
				MapNode *last = getLast();
				if(last != nullptr)
				{
					last->setNext(mfirst);
				}
				else
				{
					first = mfirst;
				}
			}
		}
		
		void Map::append(MapNode *node)
		{
			if(first == nullptr)
			{
				first = node;
			}
			else
			{
				getLast()->setNext(node);
			}
		}
		
		MapNode* Map::get(std::string key)
		{
			MapNode *current = first;
			
			if(current != nullptr)
			{
				while(current != nullptr)
				{
					if(current->getKey() == key)
					{
						return current;
					}
					
					current = current->getNext();
				}
			}
			
			return nullptr;
		}
		
		bool Map::contains(std::string key)
		{
			return (get(key) != nullptr);
		}
		
		MapNode* Map::remove(std::string key)
		{
			MapNode *current = first;
			MapNode *prev = nullptr;
			
			if(current != nullptr)
			{
				while(current != nullptr)
				{
					if(current->getKey() == key)
					{
						if(prev != nullptr)
						{
							prev->setNext(current->getNext());
						}
						else
						{
							first = nullptr;
						}
						
						return current;
					}
					
					prev = current;
					current = current->getNext();
				}
			}
			
		}
		
		MapNode* Map::getFirst(void)
		{
			return first;
		}
		
		MapNode* Map::getLast(void)
		{
			MapNode *current = first;
			
			if(first == nullptr)
			{
				return current;
			}
			else
			{
				while(current->getNext() != nullptr)
				{
					current = current->getNext();
				}
				
				return current;
			}
		}
		
		int Map::size(void)
		{
			int count = 0;
			
			MapNode *current = first;
			
			if(current == nullptr)
			{
				return count;
			}
			
			while(current != nullptr)
			{
				current = current->getNext();
				count++;
			}
			
			return count;
		}
		
		void Map::clear(void)
		{
			//todo
		}
		
		MapIterator* Map::getIterator(void)
		{
			MapIterator *iterator = new MapIterator(this);
			return iterator;
		}
	}
}