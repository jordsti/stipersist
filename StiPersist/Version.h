#ifndef VERSION_H
#define VERSION_H

namespace StiPersist
{

	struct VersionStruct
	{
		int major;
		int minor;
		int revision;
		int build;
	};
	
	/// \class Version
	/// \brief Version Object to verify if a serialized object is compatible
	class Version
	{
	public:
		/// \brief Constructor
		Version();
		
		/// \brief Constructor
		/// \param m_version Version Struct Pointer
		Version(VersionStruct *m_version);
		
		/// \brief Constructor
		/// \param m_major Major
		/// \param m_minor Minor
		/// \param m_revision Revision
		/// \param m_build Build Number
		Version(int m_major, int m_minor, int m_revision, int m_build);
		
		/// \brief Destructor
		virtual ~Version();
		
		/// \brief Get a new Version Struct Pointer
		/// \return Version Struct Pointer
		VersionStruct* getStruct();
		
		/// \brief Fill Version Struct
		/// \param version Version Struct Pointer
		void fillStruct(VersionStruct *version);
		
		/// \brief Get Major Version
		/// \return Major
		int getMajor(void);
		
		/// \brief Get Minor Version
		/// \return Minor
		int getMinor(void);
		
		/// \brief Get Revision Number
		/// \return Revision
		int getRevision(void);
		
		/// \brief Get Build Number
		/// \return Build Number
		int getBuild(void);
		
		/// \brief Compare with another version
		/// \param version Version Struct Pointer
		/// \return 0 if the same, -1 version is older and 1 version is newer
		int compare(VersionStruct *version);
		
		/// \brief Compare with another version
		/// \param version Version Pointer
		/// \return 0 if the same, -1 version is older and 1 version is newer
		int compare(Version *version);
		
		/// \brief Compare with another version
		/// \param m_major Major
		/// \param m_minor Minor
		/// \param m_revision Revision
		/// \param m_build Build Number
		/// \return 0 if the same, -1 version is older and 1 version is newer
		int compare(int m_major, int m_minor, int m_revision, int m_build);
		
	private:
	    /// \brief Major
		int major;
		
		/// \brief Minor
		int minor;
		
		/// \brief Revision
		int revision;
		
		/// \brief Build Number
		int build;
	};
}

#endif