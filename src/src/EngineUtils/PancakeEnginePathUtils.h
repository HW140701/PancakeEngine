#ifndef PANCAKE_ENGINE_PATH_UTILS_H_
#define PANCAKE_ENGINE_PATH_UTILS_H_

#include <string>

class PancakeEnginePathUtils
{
public:
	// 得到当前程序执行路径
	static std::string GetCurrentProgramDirectory();

	// 得到资源文件夹路径
	static std::string GetResourceDirectory();

	// 得到Duilib的皮肤文件路径
	static std::string GetSkinDirectory();
};

#endif // !PANCAKE_ENGINE_PATH_UTILS_H_
