#ifndef IPERSIST_H
#define IPERSIST_H

#include "Field.h"
#include <list>
#include "Resolver.h"
#include "Buffer.h"

namespace StiPersist
{

	class IPersist
	{
	public:
		virtual ~IPersist();
		
		virtual void save(std::string destination);
		virtual void load(std::string source);
		
		Data::Buffer* getChunkBuffer(void);
		
	protected:
		IPersist();
		bool isPopulated(void);
		virtual void populateFields(void) = 0;
		virtual void fromFields(void) = 0;
		
		Resolver *resolver;
		std::list<Data::Field*> fields;
	private:
		void _populateFields(void);
		void _fromFields(void);

		bool populated;
		static Resolver *_defaultResolver;
	};

}

#endif