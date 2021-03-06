#include "ShiningEnginePCH.h"
#include "World.h"
#include "TileComponent.h"

Shining::World::World(const std::string& textureFile, const std::string& tilePlacementsCSV, const int scale, const int tileWidth, const int tileHeight, const int nrColsTexture, const int nrRowsTexture, const int nrColsWorld, const int nrRowsWorld)
	:m_pTileComponent{ nullptr }
	,m_pRenderComponent{new RenderComponent(textureFile, scale)}
{
	m_pTileComponent = new TileComponent(tileWidth, tileHeight, nrColsTexture, nrRowsTexture, nrColsWorld, nrRowsWorld, scale, m_pRenderComponent);
	m_pTileComponent->LoadTiles(tilePlacementsCSV);
}

Shining::World::~World()
{
	delete m_pTileComponent;
	delete m_pRenderComponent;
}

void Shining::World::Update(const float /*timeStep*/)
{
	//unused
}

void Shining::World::Render() const noexcept
{
	m_pTileComponent->Render(glm::vec2{ 0,0 }); //start position
}

void Shining::World::SetCollision() noexcept
{
	m_pTileComponent->SetCollision();
}
