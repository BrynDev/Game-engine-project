#pragma once
#include "Command.h"

class JumpCommand final : public Shining::Command
{
public:
	JumpCommand() = default;
	virtual ~JumpCommand() = default;

	virtual void Execute( Shining::GameObject* const pTargetObject) const noexcept override;
private:
};

