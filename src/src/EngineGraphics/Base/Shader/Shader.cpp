#include "Shader.h"

#include <fstream>
#include <sstream>

#include "EngineUtils/PancakeEngineProjectHeader.h"

namespace PancakeEngine
{
	Shader::Shader()
		:m_ShaderId(-1)
	{

	}
	Shader::Shader(
		const std::string& shader_name, 
		const std::string& vertex_shader_path, 
		const std::string& fragment_shader_path)
		:m_ShaderId(-1)
	{
		// 1 从文件中读取顶点着色器和片段着色器源码
		std::string vertex_shader_code;
		std::string fragment_shader_code;
		vertex_shader_code = ReadShaderFromFile(vertex_shader_path);
		fragment_shader_code = ReadShaderFromFile(fragment_shader_path);
		const char* vertext_shader_code_char = vertex_shader_code.c_str();
		const char* fragment_shader_code_char = fragment_shader_code.c_str();

		// 2 编译shader
		unsigned int vertex_shader_id;
		unsigned int fragment_shader_id;

		vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader_id, 1, &vertext_shader_code_char, nullptr);
		glCompileShader(vertex_shader_id);
		CheckCompileErrors(vertex_shader_id, "VERTEX");

		fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader_id, 1, &fragment_shader_code_char, nullptr);
		glCompileShader(fragment_shader_id);
		CheckCompileErrors(fragment_shader_id, "FRAGMENT");

		// 3 创建着色器程序
		m_ShaderId = glCreateProgram();
		glAttachShader(m_ShaderId, vertex_shader_id);
		glAttachShader(m_ShaderId, fragment_shader_id);
		glLinkProgram(m_ShaderId);
		CheckCompileErrors(m_ShaderId, "PROGRAM");

		// 4 删除着色器
		glDeleteShader(vertex_shader_id);
		glDeleteShader(fragment_shader_id);
	}
	Shader::Shader(
		const std::string& shader_name, 
		const std::string& vertex_shader_path, 
		const std::string& fragment_shader_path, 
		const std::string& geometry_shader_path)
	{
		// 1 从文件中读取顶点着色器和片段着色器源码
		std::string vertex_shader_code;
		vertex_shader_code = ReadShaderFromFile(vertex_shader_path);
		const char* vertext_shader_code_char = vertex_shader_code.c_str();

		std::string fragment_shader_code;
		fragment_shader_code = ReadShaderFromFile(fragment_shader_path);
		const char* fragment_shader_code_char = fragment_shader_code.c_str();

		std::string geometry_shader_code;
		geometry_shader_code = ReadShaderFromFile(geometry_shader_path);
		const char* geometry_shader_code_char = geometry_shader_code.c_str();

		// 2 编译shader
		unsigned int vertex_shader_id;
		unsigned int fragment_shader_id;
		unsigned int geometry_shader_id;

		vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader_id, 1, &vertext_shader_code_char, nullptr);
		glCompileShader(vertex_shader_id);
		CheckCompileErrors(vertex_shader_id, "VERTEX");

		fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader_id, 1, &fragment_shader_code_char, nullptr);
		glCompileShader(fragment_shader_id);
		CheckCompileErrors(fragment_shader_id, "FRAGMENT");

		geometry_shader_id = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry_shader_id, 1, &geometry_shader_code_char, nullptr);
		glCompileShader(geometry_shader_id);
		CheckCompileErrors(geometry_shader_id, "GEOMETRY");

		// 3 创建着色器程序
		m_ShaderId = glCreateProgram();
		glAttachShader(m_ShaderId, vertex_shader_id);
		glAttachShader(m_ShaderId, fragment_shader_id);
		glAttachShader(m_ShaderId, geometry_shader_id);
		glLinkProgram(m_ShaderId);
		CheckCompileErrors(m_ShaderId, "PROGRAM");

		// 4 删除着色器
		glDeleteShader(vertex_shader_id);
		glDeleteShader(fragment_shader_id);
		glDeleteShader(geometry_shader_id);
	}
	Shader::~Shader()
	{
	}

	void Shader::Use()
	{
		glUseProgram(m_ShaderId);
	}

	void Shader::UnUse()
	{
		glUseProgram(0);
	}

	unsigned int Shader::GetShaderIndex()
	{
		return m_ShaderId;
	}

	std::string Shader::GetShaderName()
	{
		return m_ShaderName;
	}

	void Shader::SetBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(m_ShaderId, name.c_str()), static_cast<int>(value));
	}

	void Shader::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(m_ShaderId, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(m_ShaderId, name.c_str()), value);
	}

	void Shader::SetVec2(const std::string& name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, &value[0]);
	}

	void Shader::SetVec2(const std::string& name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(m_ShaderId, name.c_str()), x, y);
	}

	void Shader::SetVec3(const std::string& name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, &value[0]);
	}

	void Shader::SetVec3(const std::string& name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(m_ShaderId, name.c_str()), x, y, z);
	}

	void Shader::SetVec4(const std::string& name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, &value[0]);
	}

	void Shader::SetVec4(const std::string& name, float x, float y, float z, float w)
	{
		glUniform4f(glGetUniformLocation(m_ShaderId, name.c_str()), x, y, z, w);
	}

	void Shader::SetMat2(const std::string& name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	void Shader::SetMat3(const std::string& name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	void Shader::SetMat4(const std::string& name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	void Shader::SetMat4Vector(const std::string& name, const std::vector<glm::mat4>& mat4Vector)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderId, name.c_str()), mat4Vector.size(), GL_FALSE, glm::value_ptr(mat4Vector[0]));
	}

	void Shader::SetFloatVector(const std::string& name, const std::vector<float>& floatArray, unsigned int length) const
	{
		glUniform4fv(glGetUniformLocation(m_ShaderId, name.c_str()), length, floatArray.data());
	}

	std::string Shader::ReadShaderFromFile(const std::string& path)
	{
		std::string code;
		std::ifstream file;

		// 读取着色器文件
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			file.open(path);
			if (!file.is_open())
			{
				LOG(ERROR) << "Shader: Read shader file" << path << "is failed" << std::endl;

				return code;
			}
			std::stringstream stream;
			stream << file.rdbuf();
			file.close();
			code = stream.str();
		}
		catch (std::ifstream::failure e)
		{
			LOG(ERROR) << "Shader: Read shader file" << path << "is failed" << std::endl;
		}

		return code;
	}
	void Shader::CheckCompileErrors(unsigned int shader, std::string type)
	{
		GLint success;
		GLchar infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				LOG(ERROR) << "ERROR::SHADER_COMPILATION_ERROR of type: "
					<< type << "\n" << infoLog
					<< "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				LOG(ERROR) << "ERROR::PROGRAM_LINKING_ERROR of type: "
					<< type << "\n" << infoLog
					<< "\n -- --------------------------------------------------- -- "
					<< std::endl;
			}
		}
	}
}