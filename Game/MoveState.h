#pragma once
#include "State.h"

class MoveState : public Shining::State
{
public:
	explicit MoveState() = default;
	virtual ~MoveState() = default;
	virtual void Update(Shining::GameObject* const pOwner, const float timeStep) noexcept override;
	virtual void OnEntry(Shining::GameObject* const pOwner) noexcept override;
	virtual void OnExit(Shining::GameObject* const pOwner) noexcept override;
private:
};

