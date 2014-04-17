#ifndef FIELD_H
#define FIELD_H

#include "Chunk.h"
#include <string>

namespace StiPersist
{
	namespace Data
	{
		struct FieldMarker {
			int type;
			int nameLength;
			int dataLength;
		};
	
		enum FieldType {
			//undefined..
			FT_UNDEFINED = -1024,
			//numeric fields
			FT_INTEGER = 1,
			FT_UINTEGER = 2,
			FT_FLOAT = 3,
			FT_DOUBLE = 4,
			//simple field
			FT_BOOL = 64,
			FT_RAW = 128,
			//string fields
			FT_STRING = 1024,
			//complex field
			FT_OBJECT = 2048,
			FT_LIST = 2049,
			FT_MAP = 2050,
			//End of file
			FT_EOF = 4096
		};
		
		struct FieldInfo {
			FieldType type;
			std::string name;
		};
	
		/// \class Field
		/// \brief Abstract class to implement to handle a type of field
		class Field
		{
		public:
			/// \brief Destructor
			virtual ~Field();
			
			/// \brief Get Name Chunk
			/// \return Name Chunk Pointer
			Chunk* getNameChunk(void);
			
			/// \brief Get Data Chunk [Pure Virtual]
			/// \return Data Chunk Pointer
			virtual Chunk* getDataChunk(void) = 0;
			
			/// \brief Set Field value from Data Chunk [Pure Virtual]
			/// \param dataChunk Field Data Chunk
			virtual void fromDataChunk(Chunk *dataChunk) = 0;
			
			/// \brief Get Field Type
			/// \return Type ID
			int getType(void);
			
			/// \brief Get Field Name
			/// \return Name
			std::string getName(void);
			
			/// \brief Get Field Marker
			/// \return Field Marker Pointer
			FieldMarker* getMarker(void);
			
			/// \brief Update Field Marker
			/// \param marker Field Marker Pointer
			void updateMarker(FieldMarker *marker);
		protected:
			/// \brief Constructor
			Field();
			
			/// \brief Constructor
			/// \param m_name Field Name
			/// \param m_type Field Type
			Field(std::string m_name, int m_type);
			
			/// \brief Field Name
			std::string name;
			
			/// \brief Type ID
			int type;
		};
		
		template <typename T>
		T* CreateField(std::string fname)
		{
			T* tfield = new T(fname);
			
			return tfield;
		}
	}
}

#endif