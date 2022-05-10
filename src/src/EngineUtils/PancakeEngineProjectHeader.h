#ifndef PANCAKE_ENGINE_PROJECT_HEADER_
#define PANCAKE_ENGINE_PROJECT_HEADER_

/*----- Windowsͷ�ļ� -----*/
// Duilib����ͷ�ļ�
#include <SDKDDKVer.h>
#include <afxwin.h>

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
#include <windows.h>

// duilib
#include "UIlib.h"
using namespace DuiLib;

// easylogging++
#include "easylogging++.h"
#define ELPP_THREAD_SAFE

// �Զ��幤����
#include "EngineUtils/PancakeEnginePathUtils.h"
#include "EngineUI/UIControlName.h"
#include "EngineUI/CWndUI.h"

#endif // !PANCAKE_ENGINE_PROJECT_HEADER_
