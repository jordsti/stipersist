#ifndef PERSISTABLE_H
#define PERSISTABLE_H

#include "Field.h"
#include <list>
#include <map>
#include "Buffer.h"

namespace StiPersist
{
	class Resolver;

	/// \class Persistable
	/// \brief Class to inherit to handle serialization of your object
	class Persistable
	{
	public:
		/// \brief Destructor
		virtual ~Persistable();
		
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
		/// \return Persistable Child Pointer
		Persistable* getChild(std::string childName);
		
		/// \brief Set Default Resolver
		/// \param m_resolver Resolver Pointer
		static void SetDefaultResolver(Resolver *m_resolver);
		
		/// \brief Add a field to the object
		/// \param field Field Pointer
		virtual void addField(Data::Field *field);
		
		/// \brief Method to implement on your object. Apply field to your attributes
		virtual void fromFields(void) = 0;
	
		Data::Field* getField(std::string fname);
		
		template <typename T>
		T* getField(std::string fname)
		{
			return dynamic_cast<T*>(getField(fname));
		}

		
	protected:
		/// \brief Constructor
		Persistable();
		
		
		/// \brief Is the field are populated
		/// \return populated
		bool isPopulated(void);
		
		/// \brief Add a Child Object
		/// \param childName Child Name
		/// \param child Persistable Pointer
		virtual void addChild(std::string childName, Persistable *child);
		
		/// \brief Method to implement on your object. Create fields from your attributes
		virtual void populateFields(void) = 0;
		
		/// \brief Field resolver
		Resolver *resolver;
		
		/// \brief Fields
		std::list<Data::Field*> fields;
		
		/// \brief Childs Objects
		std::map<std::string, Persistable*> childs;
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