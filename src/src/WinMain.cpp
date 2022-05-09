#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineUI/MainWindow.h"

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
	LOG(INFO) << "MainWindow��ʼ���ɹ�";

	// ��������������Ϣѭ��
	CPaintManagerUI::MessageLoop();

	// ���߲����˳������ͷ�COM��
	::CoUninitialize();

	return 0;
}