#include "MapIterator.h"

namespace StiPersist
{
	namespace Container
	{
		MapIterator::MapIterator(Map *m_map)
		{
			map = m_map;
			current = nullptr;
			started = false;
		}

		MapIterator::~MapIterator() {}

		bool MapIterator::hasNext(void)
		{
			if(current != nullptr)
			{
				return current->hasNext();
			}

			return false;
		}

		bool MapIterator::moveNext(void)
		{
			if(!started)
			{
				started = true;
				MapNode *node = map->getFirst();

				if(node != nullptr)
				{
					current = node;
					return true;
				}
				else
				{
					return false;
				}
			}

			if(current != nullptr && current->hasNext())
			{
				current = current->getNext();
				return true;
			}

			return false;
		}

		std::string MapIterator::getKey(void)
		{
			if(current != nullptr)
			{
				return current->getKey();
			}

			return "";
		}

		Persistable* MapIterator::getElement(void)
		{
			if(current != nullptr)
			{
				return current->getElement();
			}

			return nullptr;
		}

		IteratorType MapIterator::getType(void)
		{
			return IT_MAP;
		}
	}
}
