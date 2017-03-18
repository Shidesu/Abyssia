/*
Dernière Modification : 06/03/2016 à 01:20
*/

#include "Game.h"

using namespace std;
/*using namespace nlohmann;*/

Game *Game::instance = NULL;

Game::Game()
{
	if (this->instance != NULL) {
		throw "Une seule instance de Game autorisée";
	}

	this->instance = this;

	// First let init the window
	this->initWindow();
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(this->window_width, this->window_height), this->window_title);
	this->window->setKeyRepeatEnabled(true);
	this->window->setFramerateLimit(frameLimite);
	load();

	Tile::init();

	// A modifier plus tard
	while (this->window->isOpen())
	{
		sf::Event event;

		deplacement();

		while (this->window->pollEvent(event))
		{
			handleEvent(event);
		}

		render();
	}
}

Game* Game::getInstance()
{
	return instance;
}

Game::~Game()
{
}

void Game::start()
{
	// A commenter lors de la releases
	this->test();
}

void Game::render()
{
	this->window->clear();
	//this->window->draw(map);
	this->window->display();

}

void Game::deplacement()
{

	auto elapsedTime = moveClock.restart().asSeconds();
}

void Game::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
	{
		this->window->close();
	}

}

sf::RenderWindow* Game::getWindow() const
{
	return this->window;
}

int Game::load()
{

	// on crée la tilemap avec le niveau précédemment défini
	/*
	if (!map->load("tileset.png", sf::Vector2u(17, 17), level, 6, 1))
		return -1;
		*/



	return 0;

}

void Game::test()
{
}

void Game::windowCollision(sf::Vector2f & last_position)
{

}

void Game::worldCollision(sf::Vector2f & last_pos)
{

}