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

// easylogging++
#include "easylogging++.h"
#define ELPP_THREAD_SAFE

// glad
#include "glad/glad.h"
#include "glad/glad_wgl.h"

// glm
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/matrix_decompose.hpp"
#include "glm/gtx/euler_angles.hpp"


/*----- std -----*/
#include <string>
#include <memory>
#include <sstream>
#include <vector>


/*----- 自定义工具类 -----*/
#include "EngineUI/UIControlName.h"
#include "EngineUI/CWndUI.h"

#include "EngineUtils/PancakeEnginePathUtils.h"
#include "EngineUtils/WndProcRemapUtil.h"
#include "EngineUtils/Singleton.h"

#endif // !PANCAKE_ENGINE_PROJECT_HEADER_
