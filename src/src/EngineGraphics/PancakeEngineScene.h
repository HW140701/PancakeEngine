#ifndef ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
#define ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"

namespace PancakeEngine
{
	class PancakeEngineScene
	{
	public:
		PancakeEngineScene();
		virtual~PancakeEngineScene();

	public:
		void BeforeRender();
		void Render();
		void AfterRender();

	private:

	};
}


#endif // !ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
