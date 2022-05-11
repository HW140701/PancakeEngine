#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineUI/MainWindow.h"
#include "EngineGraphics/PancakeEngineOpenGLRenderWindow.h"

INITIALIZE_EASYLOGGINGPP

void InitEasyLoggintPP()
{
	el::Configurations defaultConf;
	defaultConf.setToDefault();
	//��������ļ���С
	defaultConf.setGlobally(el::ConfigurationType::MaxLogFileSize, "104857600");
	//�Ƿ�д���ļ�
	defaultConf.setGlobally(el::ConfigurationType::ToFile, "true");
	//�Ƿ��������̨
	defaultConf.setGlobally(el::ConfigurationType::ToStandardOutput, "true");

	defaultConf.setGlobally(el::ConfigurationType::Format, "[%datetime]  [%function]   [%loc]   [%level] : %msg");
	//���������ļ�
	el::Loggers::reconfigureLogger("default", defaultConf);
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
	// ��һ���� ʵ���������Ⱦ�����
	CPaintManagerUI::SetInstance(hInstance);

	// ע��OpenGL���ڻص�����
	WNDPROC openGLWindowProc = MakeObjectInstance(PancakeEngineOpenGLRenderWindow::GetSingleton().get(), &PancakeEngineOpenGLRenderWindow::OpenGLWndDisplayProc);
	WNDPROC tempOpenGLWindowProc = MakeObjectInstance(PancakeEngineOpenGLRenderWindow::GetSingleton().get(), &PancakeEngineOpenGLRenderWindow::TempOpenGLWindowProc);

	MyRegisterOpenGLWnd((TCHAR*)("OpenGLWindow"), openGLWindowProc);
	MyRegisterOpenGLWnd((TCHAR*)("TempOpenGLWindow"), tempOpenGLWindowProc);


	// �ڶ�������ʼ��COM��, Ϊ����COM���ṩ֧��
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
	{
		return 0;
	}

	// ������������������
	MainWindow mainWindow;
	mainWindow.Create(NULL, _T("PancakeEngine"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWindow.CenterWindow();
	::ShowWindow(mainWindow, SW_SHOW);
	LOG(INFO) << "MainWindow��ʼ���ɹ�";

	// ��������������Ϣѭ��
	CPaintManagerUI::MessageLoop();

	// ���߲����˳������ͷ�COM��
	::CoUninitialize();

	// �ͷ�WndProc
	FreeObjectInstance(openGLWindowProc);
	FreeObjectInstance(tempOpenGLWindowProc);

	return 0;
}