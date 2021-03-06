#pragma once
#include "GameObject.h" //Include this here so I don't need to include it in every derived command class

namespace Shining
{
	class GameObject;

	class Command
	{
	public:
		Command();
		virtual ~Command() = default;

		virtual void Execute(Shining::GameObject* const pTargetObject) const noexcept = 0;
		virtual void OnRelease(Shining::GameObject* const pTargetObject) const noexcept = 0;

		void IncreaseReferenceCount() noexcept;
		bool DecreaseReferenceCount() noexcept;
	private:
		int m_ReferenceCount;
	};
}

