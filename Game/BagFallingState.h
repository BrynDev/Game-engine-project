#pragma once
#include "State.h"

class BagFallingState final : public Shining::State
{
public:
	explicit BagFallingState() = default;
	virtual ~BagFallingState() = default;

	virtual void Update(Shining::GameObject* const pOwner, const float timeStep) noexcept override;
	virtual void OnEntry(Shining::GameObject* const pOwner) noexcept override;
	virtual void OnExit(Shining::GameObject* const pOwner) noexcept override;

private:
};

