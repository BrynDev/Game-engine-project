#include "IdleState.h"
#include <iostream> //TEST

IdleState::IdleState()
	:State()
{
}

void IdleState::Update(Shining::GameObject* const /*pOwner*/, const float /*timeStep*/) noexcept
{
	//unused function
}

void IdleState::OnEntry(Shining::GameObject* const /*pOwner*/) noexcept
{
	//unused function
	std::cout << "Now idle\n";
}

void IdleState::OnExit(Shining::GameObject* const /*pOwner*/) noexcept
{
	//unused function
}