#ifndef ENGINE_GRAPHICS_BASE_DATA_STRUCTURE_H_
#define ENGINE_GRAPHICS_BASE_DATA_STRUCTURE_H_

#include "EngineUtils/PancakeEngineProjectHeader.h"

static const glm::vec3 CameraWorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
static const glm::vec3 CameraLocalFront = glm::vec3(0.0f, 0.0f, -1.0f);
static const glm::vec3 CameraLocalUp = glm::vec3(0.0f, 1.0f, 0.0f);
static const glm::vec3 CameraLocalRight = glm::vec3(1.0f, 0.0f, 0.0f);
static const float CameraYaw = -90.0f;
static const float CameraPitch = 0.0f;
static const float CameraSensitivity = 0.1f;
static const float CameraSpeed = 2.5f;
static const float CameraZoom = 45.0f;

#endif // !ENGINE_GRAPHICS_BASE_DATA_STRUCTURE_H_