#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"


class MainWindow : public WindowImplBase
{
public:
	MainWindow();
	virtual~ MainWindow();

public:
	virtual LPCTSTR GetWindowClassName() const;															// 设置程序类名称
	virtual DuiLib::CDuiString GetSkinFile();															// 设置皮肤文件
	virtual CDuiString GetSkinFolder();																    // 设置皮肤文件路径
	virtual void Notify(TNotifyUI& msg);															    // 响应duilib的各种消息
	virtual void InitWindow();                                                                          // 窗口初始化函数
	virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);					// 窗口关闭函数
	virtual LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);											    // 根据xml创建相关控件

public:
	static HWND GetMainWindowHWND();

private:
	void InitControl();
	void ProcessClickMessage(TNotifyUI& msg);
	bool OnTargetOpenGLWindowSizeChanged(void* param);													// 视频窗口大小改变和绘制事件触发函数

private:
	static HWND m_MainWindowHWND;

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
