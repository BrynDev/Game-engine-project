#pragma once
#include "Singleton.h"
#include <string>

namespace Shining
{
	class SoundEffect;

	class AudioPlayer final : public Singleton<AudioPlayer>
	{
	public:
		void PlaySoundEffect(const std::string& fileName) const noexcept;
		const bool IsPlayingSoundEffect() const noexcept;
		void StopAllEffects() const noexcept;
		void SetAllEffectsVolume(const int volume) const noexcept;
	private:
		friend class Singleton<AudioPlayer>;
		AudioPlayer() = default;
	};


}
