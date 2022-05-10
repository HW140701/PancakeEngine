#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"


class MainWindow : public WindowImplBase
{
public:
	MainWindow();
	virtual~ MainWindow();

public:
	virtual LPCTSTR GetWindowClassName() const;															// ���ó���������
	virtual DuiLib::CDuiString GetSkinFile();															// ����Ƥ���ļ�
	virtual CDuiString GetSkinFolder();																    // ����Ƥ���ļ�·��
	virtual void Notify(TNotifyUI& msg);															    // ��Ӧduilib�ĸ�����Ϣ
	virtual void InitWindow();                                                                          // ���ڳ�ʼ������
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);					// ���ڹرպ���
	virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);											    // ����xml������ؿؼ�


private:
	void InitControl();
	void ProcessClickMessage(TNotifyUI& msg);
	bool OnTargetOpenGLWindowSizeChanged(void* param);													// ��Ƶ���ڴ�С�ı�ͻ����¼���������

private:
	CHorizontalLayoutUI* m_pOpenGLWindowHorizontalLayout;

	CButtonUI* m_pMinBtn;
	CButtonUI* m_pMaxBtn;
	CButtonUI* m_pCloseBtn;
	CButtonUI* m_pRestoreBtn;
	CButtonUI* m_pFileBtn;

	CMenuWnd* m_pFileMenu;
	CStdStringPtrMap m_MenuInfos;

	CWndUI* m_pOpenGLWindow;
	HWND m_OpenGLWindowHWND;
};

#endif // !MAIN_WINDOW_H_
