#ifndef ENGINE_GRAPHICS_BASE_SHADER_H
#define ENGINE_GRAPHICS_BASE_SHADER_H

#include <string>
#include <vector>

#include "EngineUtils/PancakeEngineProjectHeader.h"

namespace PancakeEngine
{
	class Shader
	{
	public:
		Shader();
		Shader(
			const std::string& shader_name, 
			const std::string& vertex_shader_path, 
			const std::string& fragment_shader_path
		);
		Shader(
			const std::string& shader_name,
			const std::string& vertex_shader_path,
			const std::string& fragment_shader_path,
			const std::string& geometry_shader_path
		);
		virtual~Shader();

	public:
		void Use();
		static void UnUse();
		unsigned int GetShaderIndex();
		std::string GetShaderName();

		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
		void SetVec2(const std::string& name, const glm::vec2& value) const;
		void SetVec2(const std::string& name, float x, float y) const;
		void SetVec3(const std::string& name, const glm::vec3& value) const;
		void SetVec3(const std::string& name, float x, float y, float z) const;
		void SetVec4(const std::string& name, const glm::vec4& value) const;
		void SetVec4(const std::string& name, float x, float y, float z, float w);
		void SetMat2(const std::string& name, const glm::mat2& mat) const;
		void SetMat3(const std::string& name, const glm::mat3& mat) const;
		void SetMat4(const std::string& name, const glm::mat4& mat) const;
		void SetMat4Vector(const std::string& name, const std::vector<glm::mat4>& mat4Vector);
		void SetFloatVector(const std::string& name, const std::vector<float>& floatArray, unsigned int length)const;

	private:
		std::string ReadShaderFromFile(const std::string& path);
		void CheckCompileErrors(unsigned int shader, std::string type);

	private:
		unsigned int m_ShaderId;
		std::string m_ShaderName;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_SHADER_H
