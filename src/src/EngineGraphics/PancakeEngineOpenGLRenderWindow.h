#ifndef PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_
#define PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"

class PancakeEngineOpenGLRenderWindow
{
public:
	PancakeEngineOpenGLRenderWindow();
	virtual~ PancakeEngineOpenGLRenderWindow();

	static std::shared_ptr<PancakeEngineOpenGLRenderWindow> GetSingleton();

public:
	LRESULT CALLBACK OpenGLWndDisplayProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // !PANCAKE_ENGINE_OPENGL_RENDER_WINDOW_H_
