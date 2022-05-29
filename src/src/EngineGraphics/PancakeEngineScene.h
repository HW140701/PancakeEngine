#ifndef ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
#define ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"
#include "EngineGraphics/Manager/ShaderManager.h"

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
		std::shared_ptr<ShaderManager> m_pShaderManager;
	};
}


#endif // !ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
