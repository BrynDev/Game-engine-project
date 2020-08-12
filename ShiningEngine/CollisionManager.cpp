#include "ShiningEnginePCH.h"
#include "CollisionManager.h"
#include <algorithm>


/*bool Shining::CollisionManager::IsColliding(const SDL_Rect& boundingBox, const int currentTag, const int tagToCollideWith) const noexcept
{
	using mapIt = std::multimap<int, CollisionComponent*>::const_iterator;

	
	//AABB collision method
	std::pair<mapIt, mapIt> range{ m_pCollidersByTag.equal_range(tagToCollideWith) };
	if (std::distance(range.first, range.second) == 0) //check if this key exists within the multimap
	{
		//this key is not present in the multimap
		return false;
	}
	for (mapIt it{ range.first }; it != range.second; ++it)
	{
		const SDL_Rect otherBox{ it->second->GetBoundingBox() };
		if (
			boundingBox.x + boundingBox.w >= otherBox.x && //rightA >= leftB
			otherBox.x + otherBox.w >= boundingBox.x && //rightB >= leftA
			boundingBox.y + boundingBox.h >= otherBox.y && //bottomA >= topB
			otherBox.y + otherBox.h >= boundingBox.y //bottomB >= topA
			)
		{
			it->second->ResolveCollision(currentTag); //resolve collision for other object, then return true and resolve collision for the calling object
			return true;
		}
	}
	
	
	return false;
}*/

Shining::CollisionComponent* const Shining::CollisionManager::GetCollidingObject(const SDL_Rect& boundingBox, const int tagToCollideWith) const noexcept
{
	using mapIt = std::multimap<int, CollisionComponent*>::const_iterator;

	//AABB collision method
	std::pair<mapIt, mapIt> range{ m_pCollidersByTag.equal_range(tagToCollideWith) };
	if (std::distance(range.first, range.second) == 0) //check if this key exists within the multimap
	{
		//this key is not present in the multimap
		return nullptr;
	}
	for (mapIt it{ range.first }; it != range.second; ++it)
	{
		const SDL_Rect otherBox{ it->second->GetBoundingBox() };
		if (
			boundingBox.x + boundingBox.w >= otherBox.x && //rightA >= leftB
			otherBox.x + otherBox.w >= boundingBox.x && //rightB >= leftA
			boundingBox.y + boundingBox.h >= otherBox.y && //bottomA >= topB
			otherBox.y + otherBox.h >= boundingBox.y //bottomB >= topA
			)
		{
			//it->second->ResolveCollision(currentTag); //resolve collision for other object, then return true and resolve collision for the calling object
			return it->second;
		}
	}
	return nullptr;
}

void Shining::CollisionManager::RegisterCollisionComponent(CollisionComponent* const pComponent, const int tag) noexcept
{
	//m_pColliders.insert(pComponent);
	m_pCollidersByTag.insert(std::make_pair(tag, pComponent));
}

void Shining::CollisionManager::RemoveCollisionComponent(CollisionComponent* const pComponent, const int tag) noexcept
{
	using mapIt = std::multimap<int, CollisionComponent*>::iterator;
	//get all the elements with this key
	std::pair<mapIt, mapIt> range{ m_pCollidersByTag.equal_range(tag) }; 
	//get the iterator to pComponent from this range
	mapIt toErase{ std::find_if(range.first, range.second, [pComponent](std::pair<int, CollisionComponent*> pair) {
		return (pair.second == pComponent);
		}) };
	//erase the element using the iterator
	if (toErase != m_pCollidersByTag.end())
	{
		m_pCollidersByTag.erase(toErase);
	}
}

void Shining::CollisionManager::Destroy()
{
	//I might not need this function
}