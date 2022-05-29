#include "ShaderManager.h"

namespace PancakeEngine
{
	ShaderManager::ShaderManager()
	{
	}
	ShaderManager::~ShaderManager()
	{
	}
	int ShaderManager::LoadShader(
		const std::string& shader_name, 
		const std::string& vertex_shader_path, 
		const std::string& fragment_shader_path
	)
	{
		if (m_ShaderMap.find(shader_name) == m_ShaderMap.end())
		{
			return -1;
		}

		int ret_vector_shader_index = -1;
		std::shared_ptr<Shader> p_shader = std::make_shared<Shader>(shader_name, vertex_shader_path, fragment_shader_path);
		if (p_shader != nullptr)
		{
			m_ShaderMap[shader_name] = p_shader;
			ret_vector_shader_index = p_shader->GetShaderIndex();
		}

		return ret_vector_shader_index;
	}
	int ShaderManager::LoadShader(
		const std::string& shader_name, 
		const std::string& vertex_shader_path, 
		const std::string& fragment_shader_path, 
		const std::string& geometry_shader_path
	)
	{
		if (m_ShaderMap.find(shader_name) == m_ShaderMap.end())
		{
			return -1;
		}

		int ret_vector_shader_index = -1;
		std::shared_ptr<Shader> p_shader = std::make_shared<Shader>(shader_name, vertex_shader_path, fragment_shader_path,geometry_shader_path);
		if (p_shader != nullptr)
		{
			m_ShaderMap[shader_name] = p_shader;
			ret_vector_shader_index = p_shader->GetShaderIndex();
		}

		return ret_vector_shader_index;
	}
	std::shared_ptr<Shader> ShaderManager::GetShader(const std::string& shader_name)
	{
		if (m_ShaderMap.find(shader_name) == m_ShaderMap.end())
			return nullptr;

		return m_ShaderMap[shader_name];
	}
	std::shared_ptr<Shader> ShaderManager::GetShader(unsigned int shader_index)
	{
		std::map<std::string, std::shared_ptr<Shader>>::iterator iter = m_ShaderMap.begin();

		while (iter != m_ShaderMap.end())
		{
			if ((iter->second)->GetShaderIndex() == shader_index)
			{
				return iter->second;
			}

			iter++;
		}

		return nullptr;
	}
	bool ShaderManager::UseShader(const std::string& shader_name)
	{
		if (m_ShaderMap.find(shader_name) == m_ShaderMap.end())
			return false;

		m_ShaderMap[shader_name]->Use();

		return true;
	}
	bool ShaderManager::UseShader(unsigned int shader_index)
	{
		std::map<std::string, std::shared_ptr<Shader>>::iterator iter = m_ShaderMap.begin();

		while (iter != m_ShaderMap.end())
		{
			if ((iter->second)->GetShaderIndex() == shader_index)
			{
				iter->second->Use();

				return true;
			}

			iter++;
		}

		return false;
	}
	void ShaderManager::UnUseShader()
	{
		Shader::UnUse();
	}
}