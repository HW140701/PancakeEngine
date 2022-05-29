#ifndef ENGINE_GRAPHICS_MANAGER_SHADER_MANAGER_H
#define ENGINE_GRAPHICS_MANAGER_SHADER_MANAGER_H

#include <string>


#include "EngineGraphics/Base/Shader.h"
#include "EngineGraphics/Base/Object.h"

namespace PancakeEngine
{
	class ShaderManager
	{
	public:
		ShaderManager();
		virtual~ShaderManager();

	public:
		int LoadShader(
			const std::string& shader_name,
			const std::string& vertex_shader_path,
			const std::string& fragment_shader_path
		);

		int LoadShader(
			const std::string& shader_name,
			const std::string& vertex_shader_path,
			const std::string& fragment_shader_path,
			const std::string& geometry_shader_path
		);

		std::shared_ptr<Shader> GetShader(const std::string& shader_name);

		std::shared_ptr<Shader> GetShader(unsigned int shader_index);

		bool UseShader(const std::string& shader_name);

		bool UseShader(unsigned int shader_index);

		void UnUseShader();

	private:
		std::map<std::string, std::shared_ptr<Shader>> m_ShaderMap;
	};
}

#endif // !ENGINE_GRAPHICS_MANAGER_SHADER_MANAGER_H
