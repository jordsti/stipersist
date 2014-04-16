#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace StiPersist
{
	namespace Logger
	{
		//brief Debug Mode Boolean
		#ifdef DEBUG
		const bool DebugMode = true;
		#endif
		
		#ifdef RELEASE
		const bool DebugMode = false;
		#endif
	
		//Error, shown in both mode
		/// \brief Error Message, always show
		/// \param message Message
		void Error(std::string message);
		
		//Warning only shown in Debug
		/// \brief Warning Message, only shown in Debug
		/// \param message Message
		void Warning(std::string message);
		
		//Message only shown in Debug
		/// \brief Message, only shown in Debug
		/// \param message Message
		void Message(std::string message);
	}
	
}

#endif