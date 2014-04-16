#include "Version.h"

namespace StiPersist
{
	Version::Version()
	{
		major = 0;
		minor = 0;
		revision = 0;
		build = 0;
	}
	
	Version::Version(VersionStruct *m_version)
	{
		major = m_version->major;
		minor = m_version->minor;
		revision = m_version->revision;
		build = m_version->build;
	}
	
	Version::Version(int m_major, int m_minor, int m_revision, int m_build)
	{
		major = m_major;
		minor = m_minor;
		revision = m_revision;
		build = m_build;
	}
	
	Version::~Version() {}
	
	VersionStruct* Version::getStruct()
	{
		VersionStruct *version = new VersionStruct();
		
		fillStruct(version);
		
		return version;
	}
	
	void Version::fillStruct(VersionStruct *version)
	{
		version->major = major;
		version->minor = minor;
		version->revision = revision;
		version->build = build;
	}
	
	int Version::getMajor(void)
	{
		return major;
	}
	
	int Version::getMinor(void)
	{
		return minor;
	}
	
	int Version::getRevision(void)
	{
		return revision;
	}
	
	int Version::getBuild(void)
	{
		return build;
	}
	
	int Version::compare(VersionStruct *version)
	{
		return compare(version->major, version->minor, version->revision, version->build);
	}
	
	int Version::compare(Version *version)
	{
		return compare(version->getMajor(), version->getMinor(), version->getRevision(), version->getBuild());
	}
	
	int Version::compare(int m_major, int m_minor, int m_revision, int m_build)
	{
		// 0 same
		// 1 newer
		// -1 older
		
		if(major == m_major)
		{
			if(minor == m_minor)
			{
				if(revision == m_revision)
				{
					if(build == m_build)
					{
						return 0;
					}
					else if(build < m_build)
					{
						return 1;
					}
					else
					{
						return -1;
					}
				}
				else if(revision < m_revision)
				{
					return 1;
				}
				else
				{
					return -1;
				}
			}
			else if(minor < m_minor)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		else if(major < m_major)
		{
			return 1;
		}
		else
		{
			return -1;
		}
		
	}

}