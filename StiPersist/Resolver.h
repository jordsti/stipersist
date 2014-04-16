#ifndef RESOLVER_H
#define RESOLVER_H

#include "ObjectField.h"
#include "Chunk.h"

namespace StiPersist
{
	/// \class Resolver
	/// \brief Interface to implement if you want to handle custom fields
	class Resolver 
	{
	public:
		/// \brief Destructor
		virtual ~Resolver();
		
		/// \brief Create a field
		/// \param type Field Type ID
		/// \param nameChunk Field Name Chunk
		/// \param dataChunk Field Data Chunk
		/// \return Field Pointer
		virtual Data::Field* getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk) = 0;
		
		/// \brief Build a inner child object field
		/// \param nameChunk Field Name Chunk
		/// \param dataChunk Field Data Chunk
		/// \param parent IPersist Parent Pointer
		virtual void buildObjectField(Data::Chunk *nameChunk, Data::Chunk *dataChunk, IPersist *parent) = 0;
	protected:
	
		/// \brief Constructor
		Resolver();
	};

}

#endif