#ifndef ENGINE_GRAPHICS_BASE_ORTHOGRAPHIC_CAMERA_H_
#define ENGINE_GRAPHICS_BASE_ORTHOGRAPHIC_CAMERA_H_

#include "CameraInterface.h"
#include "Object.h"

namespace PancakeEngine
{
	class OrthographicCamera : public Object, CameraInterface
	{
	public:
		OrthographicCamera();
		OrthographicCamera(float left, float right, float bottom, float top, float near_plane, float far_plane);
		virtual~OrthographicCamera();

	public:
		virtual void HandleMouseMovement(float deltaX, float deltaY);
		virtual void HandleMouseScroll(float delta);
		virtual void HandleKeyboardPress(float delta);
		virtual glm::mat4 GetProjectMatrix();
		virtual glm::mat4 GetViewMatrix();

		void SetOrthographic(float left, float right, float bottom, float top, float near_plane, float far_plane);

	private:
		float m_Left;
		float m_Right;
		float m_Bottom;
		float m_Top;
		float m_Near;
		float m_Far;
	};
}

#endif // !ENGINE_GRAPHICS_BASE_ORTHOGRAPHIC_CAMERA_H_