#pragma once

#if _DEBUG
#include <vld.h>
#endif

#include <stdio.h>
#include <iostream> // std::cout
#include <sstream> // stringstream
#include <vector>
#include <SDL_Keycode.h>
#include "ControllerInput.h"
#include "Command.h"
#include "State.h"
#include "ShiningEngine.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "StateComponent.h"
#include "PhysicsComponent.h"
#include "TextComponent.h"
#include "CollisionComponent.h"
#include "Scene.h"
#include "Observer.h"
#include "CollisionBehavior.h"
#include "AudioPlayer.h"
#include "SceneManager.h"


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
