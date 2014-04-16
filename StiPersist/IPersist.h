#ifndef IPERSIST_H
#define IPERSIST_H

#include "Field.h"
#include <list>
#include <map>
#include "Buffer.h"

namespace StiPersist
{
	class Resolver;

	/// \class IPersist
	/// \brief Class to inherit to handle serialization of your object
	class IPersist
	{
	public:
		/// \brief Destructor
		virtual ~IPersist();
		
		/// \brief Save the object
		/// \param destination Filepath
		virtual void save(std::string destination);
		
		/// \brief Load the object
		/// \param source Filepath
		virtual void load(std::string source);
		
		/// \brief Get Object Chunk Buffer
		/// \return Buffer Pointer
		Data::Buffer* getChunkBuffer(void);
		
		/// \brief Get Child Object by Name
		/// \param childName Child Name
		/// \return IPersist Child Pointer
		IPersist* getChild(std::string childName);
		
		/// \brief Set Default Resolver
		/// \param m_resolver Resolver Pointer
		static void SetDefaultResolver(Resolver *m_resolver);
		
		/// \brief Add a field to the object
		/// \param field Field Pointer
		virtual void addField(Data::Field *field);
		
		/// \brief Method to implement on your object. Apply field to your attributes
		virtual void fromFields(void) = 0;
	protected:
		/// \brief Constructor
		IPersist();
		
		/// \brief Is the field are populated
		/// \return populated
		bool isPopulated(void);
		
		/// \brief Add a Child Object
		/// \param childName Child Name
		/// \param child IPersist Pointer
		virtual void addChild(std::string childName, IPersist *child);
		
		/// \brief Method to implement on your object. Create fields from your attributes
		virtual void populateFields(void) = 0;
		
		/// \brief Field resolver
		Resolver *resolver;
		
		/// \brief Fields
		std::list<Data::Field*> fields;
		
		/// \brief Childs Objects
		std::map<std::string, IPersist*> childs;
	private:
		/// \brief Private populate childs operation
		void _populateChilds(void);
		
		/// \brief Private populate fields operation
		void _populateFields(void);
		
		/// \brief Private from fields operation
		void _fromFields(void);

		/// \brief Is Populated
		bool populated;
		
		/// \brief Default Resolver Pointer
		static Resolver *_defaultResolver;
	};

}

#endif