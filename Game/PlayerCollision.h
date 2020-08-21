#pragma once
#include "CollisionBehavior.h"


class PlayerCollision final: public Shining::CollisionBehavior
{
public:
	PlayerCollision() = default;
	virtual ~PlayerCollision() = default;

	virtual void ResolveCollision(Shining::GameObject* const pOwnerObject, const int collidedTag) const noexcept override;
private:
};

