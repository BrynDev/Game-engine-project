#pragma once
#include "State.h"
class BagWarningState final : public Shining::State
{
public:
	BagWarningState();
	virtual ~BagWarningState() = default;

	virtual void Update(Shining::GameObject* const pOwner, const float timeStep) noexcept override;
	virtual void OnEntry(Shining::GameObject* const pOwner) noexcept override;
	virtual void OnExit(Shining::GameObject* const pOwner) noexcept override;
private:
	int m_FallDelayTimerMs;
};

