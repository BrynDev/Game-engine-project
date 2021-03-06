#pragma once
#include "GameObject.h" //include this here so I don't need to do it in all the derived classes

namespace Shining
{

	class CollisionBehavior
	{
	public:
		explicit CollisionBehavior() = default;
		virtual ~CollisionBehavior() = default;

		virtual void ResolveCollision(Shining::GameObject* const pOwnerObject, const int collidedTag) const noexcept = 0;
		virtual void ResolveWorldCollision(Shining::GameObject* const pOwnerObject) const noexcept = 0;
		void IncreaseInstanceCount() noexcept;
		bool DecreaseInstanceCount() noexcept; //returns true if the instance count is 0, the owner object then deletes this
	private:
		int m_InstanceCount;
	};

}

