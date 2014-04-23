#ifndef MAPNODE_H
#define MAPNODE_H

#include <string>
#include "INode.h"

namespace StiPersist
{
	namespace Container
	{

		class MapNode :
			public INode
		{
		public:
			MapNode();
			MapNode(std::string m_key, Persistable *m_element);
			MapNode(std::string m_key, Persistable *m_element, MapNode *m_next);

			virtual ~MapNode();

			void setNext(MapNode *m_next);
			MapNode* getNext(void);

			void setElement(Persistable *m_element);
			Persistable *getElement(void);

			template <typename T>
			T* getElement(void)
			{
				return dynamic_cast<T*>(element);
			}

			void setKey(std::string m_key);
			std::string getKey(void);

			bool hasNext(void);
			bool isEmpty(void);
		private:
			std::string key;
			Persistable *element;

			MapNode *next;
		};

	}

}

#endif
