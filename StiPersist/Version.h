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

	class Version
	{
	public:
		Version();
		Version(VersionStruct *m_version);
		Version(int m_major, int m_minor, int m_revision, int m_build);
		virtual ~Version();
		
		VersionStruct* getStruct();
		void fillStruct(VersionStruct *version);
		
		int getMajor(void);
		int getMinor(void);
		int getRevision(void);
		int getBuild(void);
		
		int compare(VersionStruct *version);
		int compare(Version *version);
		int compare(int m_major, int m_minor, int m_revision, int m_build);
	private:
		int major;
		int minor;
		int revision;
		int build;
	};
}

#endif