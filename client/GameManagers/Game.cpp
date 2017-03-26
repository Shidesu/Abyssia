/*
Dernière Modification : 06/03/2016 à 01:20
*/

#include "Game.h"

using namespace std;
/*using namespace nlohmann;*/

Game::ps Game::instance;
bool Game::isLaunched = false;

Game::ps Game::create()
{
	if (Game::isLaunched) {
		throw "Une seule instance de Game autorisée";
	}
	Game::instance = Game::ps(new Game());
	Game::isLaunched = true;
	// First let init the window
	Game::instance->initWindow();

	Game::isLaunched = false;
	return Game::instance;
}

Game::Game()
{
	if (Game::isLaunched) {
		throw "Une seule instance de Game autorisée";
	}
}

void Game::initWindow()
{
	this->window = shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(this->window_width, this->window_height), this->window_title));
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

Game::ps Game::getInstance()
{
	return Game::instance;
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

shared_ptr<sf::RenderWindow> Game::getWindow() const
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
	Franz franz("Franz", "Franzini");
	cout << "lol"<< endl;
	system("pause");

}

void Game::windowCollision(sf::Vector2f & last_position)
{

}

void Game::worldCollision(sf::Vector2f & last_pos)
{

}