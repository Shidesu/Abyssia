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
	window = shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(window_width, window_height), window_title));
	window->setKeyRepeatEnabled(true);
	window->setFramerateLimit(frameLimite);
	load();

	Tile::init();

	// A modifier plus tard
	while (window->isOpen())
	{
		sf::Event event;

		deplacement();

		while (window->pollEvent(event))
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
	test();
}

void Game::render()
{
	
	if (window->isOpen()) {
		window->clear();
		//sf::View view(this->window->getSize() / 16);
		//this->window->draw(map);
		window->display();
	}

}

void Game::deplacement()
{

	auto elapsedTime = moveClock.restart().asSeconds();
}

void Game::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
	{
		window->close();
	}

}

shared_ptr<sf::RenderTarget> Game::getWindow() const
{
	return window;
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