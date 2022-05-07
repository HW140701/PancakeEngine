#ifndef PANCAKE_ENGINE_PROJECT_HEADER_
#define PANCAKE_ENGINE_PROJECT_HEADER_

/*----- Windows头文件 -----*/
// Duilib所需头文件
#include <SDKDDKVer.h>
#include <afxwin.h>

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料
#include <windows.h>

// duilib
#include "UIlib.h"
using namespace DuiLib;

// 自定义工具类
#include "EngineUtils/PancakeEnginePathUtils.h"
#include "EngineUI/UIControlName.h"

#endif // !PANCAKE_ENGINE_PROJECT_HEADER_
