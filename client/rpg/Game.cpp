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

	// A modifier plus tard
	while (this->window->isOpen())
	{
		sf::Event event;
		while (this->window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window->close();
		}

		this->window->clear();
		this->window->display();
	}
}


Game::~Game()
{
}

void Game::start() 
{
	// A commenter lors de la releases
	this->test();
}

void Game::test() 
{
	
	/*Guerrier Guerrier(100);
	Franz franzdebog("Franz", "Agressif", 100, 100, 0, 50, 100);

	Guerrier.dispPersoType();

	cout << franzdebog.getMonsterType() << endl;

	cout << "Le combat commence !" << endl;

	while (Guerrier.isAlive() && franzdebog.isAlive())
	{
		Guerrier.attack(franzdebog, 5);

		cout << "Combat toujours en cours !" << endl;

		franzdebog.attack(Guerrier, 5);

		system("pause");

	}

	system("pause");

	cout << "Il vous reste " << Guerrier.getLife() << " points de vie !!" << endl;
*/}

Game* Game::getInstance() 
{
	return instance;
}

sf::RenderWindow* Game::getWindow() const
{
	return this->window;
}