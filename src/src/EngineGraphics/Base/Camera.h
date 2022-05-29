#ifndef ENGINE_GRAPHICS_BASE_CAMERA_INTERFACE_H_
#define ENGINE_GRAPHICS_BASE_CAMERA_INTERFACE_H_

namespace PancakeEngine
{
	class Camera
	{
	public:
		Camera();
		virtual~Camera();

	public:
		void SetPerspective(float angle, float aspect, float nearPlane, float farPlane);

	};
}


#endif // !ENGINE_GRAPHICS_BASE_CAMERA_INTERFACE_H_
