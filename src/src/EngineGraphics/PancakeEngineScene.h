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

		static std::shared_ptr<PancakeEngineScene> GetSingleton();

	public:
		void BeforeRender();
		void Render();
		void AfterRender();

		void Resize(int width, int height);

	private:
		void InitScene();
		void UnInitScene();

		void CreateManager();

	private:
		std::shared_ptr<ShaderManager> m_pShaderManager;
	};
}


#endif // !ENGINE_GRAPHICS_PANCAKE_ENGINE_SCENE_H_
