#ifndef DEFAULTRESOLVER_H
#define DEFAULTRESOLVER_H

#include "Resolver.h"

namespace StiPersist
{
	class Persistable;

	/// \class DefaultResolver
	/// \brief Default implementation of the Resolver. Used by Persistable
	class DefaultResolver :
		public Resolver
	{
	public:
		/// \brief Constructor
		DefaultResolver();
		
		/// \brief Destructor
		virtual ~DefaultResolver();
		
		virtual bool isHandled(Data::FieldType type);
		
		/// \brief Create a Field from Chunks
		/// \param type Type ID
		/// \param nameChunk Chunk of the Field Name
		/// \param dataChunk Chunk of the Field Data
		/// \return Generated Field Pointer
		virtual Data::Field* getField(int type, Data::Chunk *nameChunk, Data::Chunk *dataChunk);
		
		/// \brief Build a Object Field from Chunks
		/// \param nameChunk Chunk of the Field Name
		/// \param dataChunk Chunk of the Field Data
		/// \param parent Persistable Parent that contains child objects
		virtual void buildObjectField(Data::Chunk *nameChunk, Data::Chunk *dataChunk, Persistable *parent);
	};


}

#endif