#ifndef CHUNK_H
#define CHUNK_H

#include <string>

namespace StiPersist
{

	namespace Data
	{
		struct FieldMarker;
	
		struct ChunkMarker {
			unsigned int length;
		};
	
		/// \class Chunk
		/// \brief Chunk of data. Specified by Length and a Char Array
		class Chunk
		{
		public:
			/// \brief Create an empty Chunk
			Chunk();
			/// \brief Create a Chunk of Data
			/// \param m_data Char Array Pointer
			/// \param m_length Length of the Array
			Chunk(char *m_data, unsigned int m_length);
			
			/// \brief Set clear data parameter
			/// \param m_clearData Clear Data
			void setClearData(bool m_clearData);
			/// \brief Get clear data parameter
			/// \return Clear Data
			bool getClearData(void);
			
			/// \brief Get Chunk Data Length
			/// \return Data Length
			unsigned int getLength(void);
			
			/// \brief Get Data
			/// \return Char Array Pointer
			char* getData(void);
		
			/// \brief Set Chunk Data
			/// \param m_data Char Array Pointer
			/// \param m_length Array Length
			void setData(char *m_data, unsigned int m_length);
			
			/// \brief Create a ChunkMarker [not used]
			/// \return Chunk Marker
			ChunkMarker* getMarker(void);
			
			/// \brief Destructor
			virtual ~Chunk();
			
			/// \brief Generate a string with Chunk Data
			/// \return Generated String
			std::string toString(void);
			
			/// \brief Create a Chunk from a String
			/// \param text String to convert
			/// \return Chunk from the string
			static Chunk* FromString(std::string text);
			/// \brief Create a Chunk from a Field Marker
			/// \param marker Field Marker
			/// \return Chunk from the Field Marker
			static Chunk* FromFieldMarker(FieldMarker *marker);
			/// \brief Create a Chunk from a Chunk Marker [not used]
			/// \param marker Chunk Marker
			/// \return Chunk from the Chunk Marker
			static Chunk* FromChunkMarker(ChunkMarker *marker);
		private:
		
			/// \brief Clear Data
			bool clearData;
			/// \brief Char Array Pointer
			char *data;
			/// \brief Char Array Length
			unsigned int length;
		};
		
	}

}

#endif