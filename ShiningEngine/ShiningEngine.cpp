#include "ShiningEnginePCH.h"
#include "ShiningEngine.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "GameObject.h"
#include "Scene.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include <vector>

#include <iostream> //for test

using namespace std;
using namespace std::chrono;

void Shining::ShiningEngine::Run()
{
	//Initialize();

	//LoadDemoScene();

	Renderer& renderer = Renderer::GetInstance();
	SceneManager& sceneManager = SceneManager::GetInstance();
	InputManager& input = InputManager::GetInstance();

	float realTimeElapsed{}; //this var can be [0,1] in case of small workload, integer instead of float means that elapsedTime can be 0 ms which is never accurate 		
	auto prevTime{ high_resolution_clock::now() };

	bool doContinue{ true };
	while (doContinue) //game loop
	{
		const auto currentTime = high_resolution_clock::now();
		const duration<float, milli> deltaTime{ currentTime - prevTime };
		prevTime = currentTime;
		realTimeElapsed += deltaTime.count();
		doContinue = input.ProcessInput(); //detect quit & take input

		//fixed update step, variable rendering
		while (realTimeElapsed >= MsPerFrame)
		{				
			sceneManager.Update(MsPerFrame); //update game objects
			realTimeElapsed -= MsPerFrame;
			/*for (int i{}; i < 10000; ++i)
			{
				double* pDouble{ new double{5.0} };
				delete pDouble;
			}*/
				
		}
		renderer.Render(); //render game objects
		//TODO: interpolate rendering based on leftover of realTimeElapsed
	}

	Cleanup();
}

Shining::ShiningEngine::ShiningEngine()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");
}

void Shining::ShiningEngine::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void Shining::ShiningEngine::LoadDemoScene() const
{
	Scene& scene = SceneManager::GetInstance().CreateScene("Demo");

	Shining::GameObject* pBackground{ new Shining::GameObject()};
	pBackground->AddComponent(new RenderComponent("background.jpg"));
	scene.Add(pBackground);

	Shining::GameObject* pLogo{ new Shining::GameObject() };
	pLogo->AddComponent(new RenderComponent("logo.png"));
	pLogo->SetPosition(216, 180);
	scene.Add(pLogo);

	Shining::GameObject* pText{ new Shining::GameObject() };
	pText->AddComponent(new TextComponent("Programming 4 Assignment", "Lingua.otf", SDL_Color{255, 255, 255}, 36));
	pText->SetPosition(80, 20);
	scene.Add(pText);

	Shining::GameObject* pCounter{ new Shining::GameObject() };
	pCounter->AddComponent(new TextComponent("00 FPS", "Lingua.otf", SDL_Color{ 255, 255, 50 }, 17));
	pCounter->AddComponent(new FPSComponent(pCounter));
	pCounter->SetPosition(15, 15);
	scene.Add(pCounter);

	//this game object is supposed to be initialized in Game.cpp but I had issues getting that to work, so I do it here to demonstrate
	/*Shining::GameObject* pTestCharacter{ new Shining::GameObject() };
	pTestCharacter->AddComponent(new RenderComponent{ "Bub.png", 2, 100, 2, 4 });
	pTestCharacter->SetPosition(200, 100);
	scene.Add(pTestCharacter);*/
}

void Shining::ShiningEngine::RegisterPlayerCharacter(GameObject* pPlayerCharacter) noexcept
{
	InputManager::GetInstance().RegisterPlayerCharacter(pPlayerCharacter);
}

void Shining::ShiningEngine::AddCommand(Command* pCommandToAdd, const unsigned int virtualKey, const ControllerInput controllerInput) noexcept
{
	Shining::InputManager::GetInstance().AddCommand(pCommandToAdd, virtualKey, controllerInput);
}

Shining::Scene& Shining::ShiningEngine::CreateScene(const std::string& name)
{
	return SceneManager::GetInstance().CreateScene(name);
}

void Shining::ShiningEngine::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
	SceneManager::GetInstance().Destroy();
	ResourceManager::GetInstance().Destroy();
}