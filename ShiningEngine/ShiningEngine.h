#pragma once
struct SDL_Window;

namespace Shining
{
	class Scene;
	class GameObject;

	class ShiningEngine
	{
	public:
		ShiningEngine(const std::string& windowName, const int windowWidth, const int windowHeight);
		void Initialize(const std::string& windowName, const int windowWidth, const int windowHeight);
		void Cleanup();
		void Run();

		//Delegate function calls to classes that aren't accessible from the game project
		void RegisterPlayerCharacter(GameObject* pPlayerCharacter) noexcept;
		//void AddCommand(Command* pCommandToAdd, const unsigned int virtualKey, const ControllerInput controllerInput) noexcept;
		//void SetNoInputCommand(Command* pCommand) noexcept; //Command to execute when no keys are pressed

		ShiningEngine(const ShiningEngine& other) = delete;
		ShiningEngine& operator=(const ShiningEngine& rhs) = delete;
		ShiningEngine(ShiningEngine&& other) = delete;
		ShiningEngine& operator=(ShiningEngine&& rhs) = delete;
	private:
		static const int MsPerFrame = 16;
		SDL_Window* m_Window{};
	};
}