#ifndef PANCAKE_ENGINE_PATH_UTILS_H_
#define PANCAKE_ENGINE_PATH_UTILS_H_

#include <string>

class PancakeEnginePathUtils
{
public:
	// �õ���ǰ����ִ��·��
	static std::string GetCurrentProgramDirectory();

	// �õ���Դ�ļ���·��
	static std::string GetResourceDirectory();

	// �õ�Duilib��Ƥ���ļ�·��
	static std::string GetSkinDirectory();
};

#endif // !PANCAKE_ENGINE_PATH_UTILS_H_
