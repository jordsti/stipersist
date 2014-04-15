#ifndef INODE_H
#define INODE_H

#include "IPersist.h"

namespace StiPersist
{
	namespace Container
	{
		class INode
		{
		public:
			virtual IPersist* getElement(void) = 0;
			virtual void setElement(IPersist *m_element) = 0;
			virtual bool hasNext(void) = 0;
			virtual bool isEmpty(void) = 0;
		};
	}
}

#endif