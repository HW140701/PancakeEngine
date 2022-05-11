#ifndef PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_
#define PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "PancakeEngineOpenGLRender.h"

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

	bool InitOpenGLContext(HWND hWnd,bool isUseMsaa = true);
	void UnInitOpenGLContext();
	void UpdateOpenGLRender(HWND hWnd);

private:
	HWND m_HWND;
	HDC m_HDC;
	HGLRC m_HGLRC;

	std::unique_ptr<PancakeEngineOpenGLRender> m_pPancakeEngineOpenGLRender;
};

#endif // !PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_
