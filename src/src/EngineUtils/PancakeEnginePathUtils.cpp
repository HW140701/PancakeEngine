#include "PancakeEnginePathUtils.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

#include<Windows.h>

#elif defined(linux) || defined(__linux)

#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

#endif // WINDOWS


#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
static HMODULE GetSelfModuleHandle()
{
	MEMORY_BASIC_INFORMATION mbi;
	return (
		(::VirtualQuery(GetSelfModuleHandle, &mbi, sizeof(mbi)) != 0)
		? (HMODULE)mbi.AllocationBase : NULL
		);
}

std::string PancakeEnginePathUtils::GetCurrentProgramDirectory()
{
	std::string strCurrentPath = "";
	char curDirector[260] = { 0 };
	GetModuleFileName(GetSelfModuleHandle(), curDirector, 260);
	strCurrentPath = curDirector;

	size_t nameStart = strCurrentPath.rfind("\\");
	strCurrentPath = strCurrentPath.substr(0, nameStart + 1);
	return strCurrentPath;
}

#elif defined(linux) || defined(__linux)
std::string PancakeEnginePathUtils::GetCurrentProgramDirectory()
{
	std::string strCurrentPath = "";
	char szCurWorkPath[256];
	memset(szCurWorkPath, '\0', 256);
	int nRet = readlink("/proc/self/exe", szCurWorkPath, 256);
	if (nRet > 256 || nRet < 0)
	{
		return strCurrentPath;
	}

	for (int i = nRet; i > 0; i--)
	{
		if (szCurWorkPath[i] == '/' || szCurWorkPath[i] == '\\')
		{
			szCurWorkPath[i] = '\0';
			break;
		}
	}

	strCurrentPath = szCurWorkPath;

	return strCurrentPath;
}
#endif


std::string PancakeEnginePathUtils::GetResourceDirectory()
{
#ifdef _DEBUG
	return GetCurrentProgramDirectory() + "../../../../resource/";
#else
	return GetCurrentProgramDirectory() + "./resource/";
#endif // DEBUG	
}

std::string PancakeEnginePathUtils::GetSkinDirectory()
{
#ifdef _DEBUG
	return "../../../.././resource/skin/";
#else
	return "./resource/skin/";
#endif // DEBUG	
}
