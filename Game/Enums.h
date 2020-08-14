#pragma once
enum class ObservedEvents
{
	gemPickup = 0,
	goldPickup = 1,
	enemyKill = 2,
	playerMove = 3,
	playerShoot = 4
};

enum class CollisionTags
{
	player = 0,
	enemy = 1,
	gem = 2,
	goldBag = 3,
	wall = 4
};