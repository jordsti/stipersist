#ifndef IPERSIST_H
#define IPERSIST_H

#include "Field.h"
#include <list>
#include "Resolver.h"

namespace StiPersist
{

	class IPersist
	{
	public:
		virtual ~IPersist();
		
		virtual void save(std::string destination);
		virtual void load(std::string source);
	protected:
		IPersist();
		bool isPopulated(void);
		virtual void populateFields(void) = 0;
		virtual void fromFields(void) = 0;
		
		void _populateFields(void);
		void _fromFields(void);
		
		std::list<Data::Field*> fields;
	private:
		Resolver *resolver;
		bool populated;
	
	};

}

#endif