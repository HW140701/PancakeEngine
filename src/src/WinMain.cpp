#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineUI/MainWindow.h"

INITIALIZE_EASYLOGGINGPP

void InitEasyLoggintPP()
{
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	//设置最大文件大小
	defaultConf.setGlobally(el::ConfigurationType::MaxLogFileSize, "104857600");
	//是否写入文件
	defaultConf.setGlobally(el::ConfigurationType::ToFile, "true");
	//是否输出控制台
	defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "true");

	defaultConf.setGlobally(el::ConfigurationType::Format, "[%datetime]  [%function]   [%loc]   [%level] : %msg");
	//设置配置文件
	el::Loggers::reconfigureLogger("default", defaultConf);
}

LRESULT CALLBACK OpenGLWndDisplayProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_CREATE:
	{
		break;
	}


	case WM_SIZE:
	{
		break;
	}

	case WM_PAINT:
	{
		break;
	}

	case WM_DESTROY:
	{
		break;
	}

	case WM_LBUTTONDOWN:
	{
		

		break;
	}

	case WM_LBUTTONUP:
	{
		

		break;
	}

	case WM_MOUSEMOVE:
	{
		

		break;
	}

	case WM_RBUTTONDOWN:
	{
		

		break;
	}

	case WM_RBUTTONUP:
	{
		

		break;
	}

	case WM_MBUTTONDOWN:
	{

		break;
	}

	case WM_MBUTTONUP:
	{

		break;
	}

	case WM_MOUSEWHEEL:
	{

		break;
	}

	case WM_KEYDOWN:
	{
		
		break;
	}


	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool MyRegisterOpenGLWnd(TCHAR* szClass, WNDPROC proc)
{
	WNDCLASS wndclass;

	if (GetClassInfo(GetModuleHandle(NULL), szClass, &wndclass))
	{
		return 1;// name already registered - ok if it was us  
	}

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = proc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = GetModuleHandle(NULL);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = NULL;
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClass;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szClass, MB_ICONERROR);
		return false;
	}

	return true;
}


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// 第一步： 实例句柄与渲染类关联
	CPaintManagerUI::SetInstance(hInstance);

	//窗体阴影初始化
	//CWndShadow::Initialize(hInstance);

	// 注册OpenGL窗口消息处理函数
	MyRegisterOpenGLWnd((TCHAR*)("OpenGLWnd"), OpenGLWndDisplayProc);

	// 第二步：初始化COM库, 为加载COM库提供支持
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
	{
		return 0;
	}

	// 第三步：创建窗口类
	MainWindow mainWindow;
	mainWindow.Create(NULL, _T("PancakeEngine"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWindow.CenterWindow();
	::ShowWindow(mainWindow, SW_SHOW);
	LOG(INFO) << "MainWindow初始化成功";

	// 第六步：处理消息循环
	CPaintManagerUI::MessageLoop();

	// 第七步：退出程序并释放COM库
	::CoUninitialize();

	return 0;
}