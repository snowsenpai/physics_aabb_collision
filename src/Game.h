#pragma once

#include "EntityManager.h"
#include "Entity.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <random>

class Game
{
	EntityManager m_entityManager;
	sf::RenderWindow m_window;
	std::shared_ptr<Entity> m_player;
	
	std::random_device m_randomDevice;

	bool m_running = false;
	bool m_drawCollisison = false;

	void init();
	void update();
	void quit();
	void spawnPlayer();
	void spawnEntity();
	void spawnEntities(size_t max);

	
	void sRender();
	void sPlayerInput();
	void sMovement();
	void sCollision();

	template <typename T>
	T rng(T min, T max);

public:
	Game() = default;

	void run();
};