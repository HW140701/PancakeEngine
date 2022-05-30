#ifndef ENGINE_GRAPGICS_PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_
#define ENGINE_GRAPGICS_PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "PancakeEngineScene.h"

class PancakeEngineOpenGLRenderWindow
{
public:
	PancakeEngineOpenGLRenderWindow();
	virtual~ PancakeEngineOpenGLRenderWindow();

	static std::shared_ptr<PancakeEngineOpenGLRenderWindow> GetSingleton();

public:
	LRESULT CALLBACK OpenGLWndDisplayProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK TempOpenGLWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnDestory(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnLeftButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnLeftButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnRightButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnRightButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnMiddleButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnMiddleButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnMouseWheel(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

	bool InitOpenGLContext(HWND hWnd,bool isUseMsaa = true);
	void UnInitOpenGLContext();
	void UpdateOpenGLRender(HWND hWnd);

private:
	HWND m_HWND;
	HDC m_HDC;
	HGLRC m_HGLRC;

};

#endif // !ENGINE_GRAPGICS_PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_
