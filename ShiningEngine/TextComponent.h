#pragma once
#include "Component.h"
#include <SDL.h>

class Texture2D;
class Font;
namespace Shining
{
	class TextComponent final : public Shining::Component
	{
	public:
		TextComponent(const std::string& text, const std::string& fontName, const SDL_Color& color, const int size);
		virtual ~TextComponent();

		virtual void Render(const glm::vec3& pos) /*const*/ override;
		virtual void Update() override;
		void SetText(const std::string& newText);

		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;
	private:
		Shining::Texture2D* m_pTexture;
		const Shining::Font* m_pFont;
		std::string m_Text;
		const SDL_Color m_Color;
		bool m_NeedsUpdate;
	};
}

