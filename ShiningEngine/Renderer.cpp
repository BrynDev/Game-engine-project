#include "ShiningEnginePCH.h"
#include "Renderer.h"
#include <SDL.h>
#include "SceneManager.h"
#include "Texture2D.h"

void Shining::Renderer::Init(SDL_Window * window)
{
	m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateRenderer Error: ") + SDL_GetError());
	}
}

void Shining::Renderer::Render() const
{
	SDL_RenderClear(m_Renderer);

	SceneManager::GetInstance().Render();
	
	SDL_RenderPresent(m_Renderer);
}

void Shining::Renderer::Destroy()
{
	if (m_Renderer != nullptr)
	{
		SDL_DestroyRenderer(m_Renderer);
		m_Renderer = nullptr;
	}
}

void Shining::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect) const
{
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), &srcRect, &destRect);
}

void Shining::Renderer::RenderTexture(const Texture2D& texture, const float x, const float y) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(x);
	dst.y = static_cast<int>(y);
	SDL_QueryTexture(texture.GetSDLTexture(), nullptr, nullptr, &dst.w, &dst.h);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

void Shining::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& destRect) const
{
	SDL_Rect dst;
	dst.x = static_cast<int>(destRect.x);
	dst.y = static_cast<int>(destRect.y);
	dst.w = static_cast<int>(destRect.w);
	dst.h = static_cast<int>(destRect.h);
	SDL_RenderCopy(GetSDLRenderer(), texture.GetSDLTexture(), nullptr, &dst);
}

//unable to surpress this warning: https://developercommunity.visualstudio.com/content/problem/724840/no-option-to-suppress-c-code-analysis-warning-c268.html
void Shining::Renderer::RenderTexture(const Texture2D& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect, const float angleDeg, const SDL_RendererFlip& flipFlag) const
{	
	SDL_RenderCopyEx(GetSDLRenderer(), texture.GetSDLTexture(), &srcRect, &destRect, angleDeg, NULL, flipFlag);
}
