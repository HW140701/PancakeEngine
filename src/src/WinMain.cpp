#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineUI/MainWindow.h"


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// ��һ���� ʵ���������Ⱦ�����
	CPaintManagerUI::SetInstance(hInstance);

	//������Ӱ��ʼ��
	//CWndShadow::Initialize(hInstance);

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

	// ��������������Ϣѭ��
	CPaintManagerUI::MessageLoop();

	// ���߲����˳������ͷ�COM��
	::CoUninitialize();

	return 0;
}