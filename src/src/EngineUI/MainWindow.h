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
	virtual LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);	    // ���ڹرպ���
};

#endif // !MAIN_WINDOW_H_
