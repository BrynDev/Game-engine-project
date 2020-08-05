#include "MoveState.h"
#include "IdleState.h"


MoveState::MoveState()
	:State()
{
}

void MoveState::Update(Shining::GameObject* const pOwner, const float timeStep) noexcept
{
	Shining::PhysicsComponent* pPhysics{ pOwner->GetComponent<Shining::PhysicsComponent>() };
	pPhysics->MoveOwner(timeStep);
}

void MoveState::OnEntry(Shining::GameObject* const /*pOwner*/) noexcept
{

}

void MoveState::OnExit(Shining::GameObject* const /*pOwner*/) noexcept
{

}