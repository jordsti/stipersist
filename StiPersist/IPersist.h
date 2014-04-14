#ifndef IPERSIST_H
#define IPERSIST_H

#include "Field.h"
#include <list>
#include <map>
#include "Buffer.h"

namespace StiPersist
{
	class Resolver;

	class IPersist
	{
	public:
		virtual ~IPersist();
		
		virtual void save(std::string destination);
		virtual void load(std::string source);
		
		Data::Buffer* getChunkBuffer(void);
		
		IPersist* getChild(std::string childName);
		
		static void SetDefaultResolver(Resolver *m_resolver);
		
		virtual void addField(Data::Field *field);
		
	protected:
		IPersist();
		bool isPopulated(void);
		virtual void addChild(std::string childName, IPersist *child);
		
		virtual void populateFields(void) = 0;
		virtual void fromFields(void) = 0;
		
		Resolver *resolver;
		
		std::list<Data::Field*> fields;
		std::map<std::string, IPersist*> childs;
	private:
		void _populateChilds(void);
		void _populateFields(void);
		void _fromFields(void);

		bool populated;
		static Resolver *_defaultResolver;
	};

}

#endif