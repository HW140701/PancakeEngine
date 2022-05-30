#include "OrthographicCamera.h"

namespace PancakeEngine
{
	OrthographicCamera::OrthographicCamera()
	{
	}
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, float near_plane, float far_plane)
		:m_Left(left),
		m_Right(right),
		m_Bottom(bottom),
		m_Top(top),
		m_Near(near_plane),
		m_Far(far_plane)
	{
	}
	OrthographicCamera::~OrthographicCamera()
	{
	}
	void OrthographicCamera::HandleMouseMovement(float deltaX, float deltaY)
	{
	}
	void OrthographicCamera::HandleMouseScroll(float delta)
	{
	}
	void OrthographicCamera::HandleKeyboardPress(CameraMovement direction)
	{
	}
	void OrthographicCamera::SetCameraViewSize(int view_width, int view_height)
	{
		m_CameraViewWidth = view_width;
		m_CameraViewHeight = view_height;

		m_Left = 0.0f;
		m_Right = view_width;

		m_Bottom = 0.0f;
		m_Top = view_height;

		m_Near = 0.0f;
		m_Far = 1000.0f;
	}
	glm::mat4 OrthographicCamera::GetProjectMatrix()
	{
		return m_ProjectMatrix;
	}
	glm::mat4 OrthographicCamera::GetViewMatrix()
	{
		m_ViewMatrix = glm::lookAt(m_CameraPosition, m_CameraPosition + m_CameraFrontVector, m_CameraUpVector);
		return m_ViewMatrix;
	}
	void OrthographicCamera::SetOrthographic(float left, float right, float bottom, float top, float near_plane, float far_plane)
	{
		m_Left = left;
		m_Right = right;
		m_Bottom = bottom;
		m_Top = top;
		m_Near = near_plane;
		m_Far = far_plane;

		m_ProjectMatrix = glm::ortho(left, right, bottom, top, near_plane, far_plane);
	}
}