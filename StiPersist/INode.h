#ifndef INODE_H
#define INODE_H

#include "Persistable.h"

namespace StiPersist
{
	namespace Container
	{
		class INode
		{
		public:
			virtual Persistable* getElement(void) = 0;
			virtual void setElement(Persistable *m_element) = 0;
			virtual bool hasNext(void) = 0;
			virtual bool isEmpty(void) = 0;
		};
	}
}

#endif