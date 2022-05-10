#ifndef PANCAKE_ENGINE_OPENGL_RENDER_H_
#define PANCAKE_ENGINE_OPENGL_RENDER_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"

class PancakeEngineOpenGLRender
{
public:
	PancakeEngineOpenGLRender();
	virtual~ PancakeEngineOpenGLRender();

public:
	void BeforeRender();
	void Render();
	void AfterRender();

private:

};

#endif // !PANCAKE_ENGINE_OPENGL_RENDER_H_
