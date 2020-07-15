#pragma once
#include "Transform.h"

namespace Shining
{
	class GameObject;
	class Texture2D;
	class Font;
	//types need to be declared here, otherwise they are not recognized as namespace members
	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;

		virtual void Update(const float timeStep) = 0;
		virtual void Render(const glm::vec3& pos) = 0;

		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;
	private:
	};
}

