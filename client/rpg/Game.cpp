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
	Guerrier Guerrier(100);
	Franz franzdebog("Franzdebog", "Agressif", 100, 100, 20, 50, 100);
	Franz franz2("Franz", "ini", 100, 100, 20, 50, 100 );

	Guerrier.dispPersoType();

	cout << franzdebog.getMonsterType() << endl;
	cout << franzdebog.getMonsterType() << endl;

	cout << "Deux Franz agressifs viennent de se jeter sur vous !!!" << endl;

	cout << "Le combat commence !" << endl;

	while (Guerrier.isAlive() && franzdebog.isAlive() | franz2.isAlive())
	{
		Guerrier.attack(franzdebog, 22, Damages::DamagesType::Brute);
		franzdebog.attack(Guerrier, 5, Damages::DamagesType::Physical);
		Guerrier.attack(franz2, 11, Damages::DamagesType::Magic);
		franz2.attack(Guerrier, 10, Damages::DamagesType::Physical);
		Guerrier.attack(franz2, 10, Damages::DamagesType::Physical);

		cout << "Combat toujours en cours !" << endl;

		franzdebog.attack(Guerrier, 5, Damages::DamagesType::Physical);

		system("pause");

	}

	system("pause");

	cout << "Il vous reste " << Guerrier.getLife() << " points de vie !!" << endl;
}

Game* Game::getInstance() 
{
	return instance;
}

sf::RenderWindow* Game::getWindow() const
{
	return this->window;
}