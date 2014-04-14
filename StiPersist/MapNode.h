#ifndef MAPNODE_H
#define MAPNODE_H

#include <string>
#include "IPersist.h"

namespace StiPersist
{
	namespace Container
	{
	
		class MapNode
		{
		public:
			MapNode();
			MapNode(std::string m_key, IPersist *m_element);
			MapNode(std::string m_key, IPersist *m_element, MapNode *m_next);
			
			virtual ~MapNode();
			
			void setNext(MapNode *m_next);
			MapNode* getNext(void);
			
			void setElement(IPersist *m_element);
			IPersist *getElement(void);
			
			void setKey(std::string m_key);
			std::string getKey(void);
			
			bool hasNext(void);
			bool isEmpty(void);
		private:
			std::string key;
			IPersist *element;
			
			MapNode *next;
		};
	
	}

}

#endif