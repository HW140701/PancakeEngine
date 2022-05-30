#include "PerspectiveCamera.h"

namespace PancakeEngine
{
	PerspectiveCamera::PerspectiveCamera()
		:m_FovAngle(60.0),
		m_Aspect(1.0),
		m_Near(1.0),
		m_Far(1000.0)
	{

	}
	PerspectiveCamera::PerspectiveCamera(
		const glm::vec3& camera_position, 
		const glm::vec3 world_up,
		float camera_yaw, 
		float camera_pitch
	)
		:m_FovAngle(45.0),
		m_Aspect(1.0),
		m_Near(1.0),
		m_Far(1000.0)
	{
		m_CameraPosition = camera_position;
		m_WorldUpVector = world_up;
		m_Yaw = camera_yaw;
		m_Pitch = camera_pitch;

		UpdateCamera();
	}
	PerspectiveCamera::PerspectiveCamera(
		const glm::vec3& camera_position,
		const glm::vec3 world_up,
		float camera_yaw,
		float camera_pitch,
		float fov_angle,
		float aspect,
		float near_plane,
		float far_plane
	)
		:m_FovAngle(fov_angle),
		m_Aspect(aspect),
		m_Near(near_plane),
		m_Far(far_plane)
	{
		m_CameraPosition = camera_position;
		m_WorldUpVector = world_up;
		m_Yaw = camera_yaw;
		m_Pitch = camera_pitch;

		UpdateCamera();
	}
	PerspectiveCamera::~PerspectiveCamera()
	{
	}
	void PerspectiveCamera::HandleMouseMovement(float delta_x, float delta_y)
	{
		if (fabs(delta_x) > fabs(delta_y))
		{
			m_Pitch += delta_y * m_MouseSensitivity;

			if (m_Pitch > 89.0f)
				m_Pitch = 89.0f;
			if (m_Pitch < -89.0f)
				m_Pitch = -89.0f;
		}
		else
		{
			m_Yaw -= delta_x * m_MouseSensitivity;

			if (m_Yaw > 180.0f)
				m_Yaw = 180.0f;
			if (m_Yaw < -180.0f)
				m_Yaw = -180.0f;
		}
	}
	void PerspectiveCamera::HandleMouseScroll(float delta)
	{
		m_CameraZoom -= (float)delta;
		if (m_CameraZoom < 1.0f)
			m_CameraZoom = 1.0f;
		if (m_CameraZoom > 45.0f)
			m_CameraZoom = 45.0f;

		m_FovAngle = m_CameraZoom;

		m_ProjectMatrix = glm::perspective(glm::radians(m_FovAngle), m_Aspect, m_Near, m_Far);
	}
	void PerspectiveCamera::HandleKeyboardPress(CameraMovement direction)
	{
		switch (direction)
		{
		case CameraMovement::Forward:
			m_CameraPosition += m_CameraFrontVector * m_MovementSpeed;
			break;
		case CameraMovement::Backward:
			m_CameraPosition -= m_CameraFrontVector * m_MovementSpeed;
			break;
		case CameraMovement::Left:
			m_CameraPosition -= m_CameraRightVector * m_MovementSpeed;
			break;
		case CameraMovement::Right:
			m_CameraPosition += m_CameraRightVector * m_MovementSpeed;
			break;
		case CameraMovement::Up:
			m_CameraPosition += m_CameraUpVector * m_MovementSpeed;
			break;
		case CameraMovement::Down:
			m_CameraPosition -= m_CameraUpVector * m_MovementSpeed;
			break;
		default:
			break;
		}
	}
	glm::mat4 PerspectiveCamera::GetProjectMatrix()
	{
		return m_ProjectMatrix;
	}
	glm::mat4 PerspectiveCamera::GetViewMatrix()
	{
		m_ViewMatrix = glm::lookAt(m_CameraPosition, m_CameraPosition + m_CameraFrontVector, m_CameraUpVector);
		return m_ViewMatrix;
	}

	void PerspectiveCamera::SetPerspective(float fov_angle, float aspect, float near_plane, float far_palne)
	{
		m_FovAngle = fov_angle;
		m_Aspect = aspect;
		m_Near = near_plane;
		m_Far = far_palne;

		m_ProjectMatrix = glm::perspective(glm::radians(fov_angle), aspect, near_plane, far_palne);
	}
	void PerspectiveCamera::UpdateCamera()
	{
		// 计算相机向前向量
		glm::vec3 front;
		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_CameraFrontVector = glm::normalize(front);

		// 计算相机向右和向上向量
		m_CameraRightVector = glm::normalize(glm::cross(m_CameraFrontVector, m_WorldUpVector));
		m_CameraUpVector = glm::normalize(glm::cross(m_CameraRightVector, m_CameraFrontVector));
	}
}