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
	this->window->draw(Player);
	this->window->display();
}

void Game::deplacement()
{
	
	auto elapsedTime = moveClock.restart().asSeconds();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		auto valueMovement =- speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(valueMovement, 0);
		Player.setTexture(marioLeft);

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{		
		auto valueMovement =+ speed * elapsedTime;
		
		valueMovement = (int)round(valueMovement);
				
		Player.move(valueMovement, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		auto valueMovement =- speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(0, valueMovement);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		auto valueMovement = +speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(0, valueMovement);
		Player.setTexture(marioFace);
	}
}

void Game::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::Closed)
	{
		this->window->close();
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::Escape)
			Player.setPosition(0, 0);
	}
}

sf::RenderWindow* Game::getWindow() const
{
	return this->window;
}

void Game::load()
{
	marioFace;
	if (!marioFace.loadFromFile("mario.gif"))
	{
		// erreur...
	}
	marioLeft;
	if (!marioLeft.loadFromFile("mario_gauche.gif"))
	{
		//erreur...
	}

	Player.setTexture(marioFace);
	Player.setPosition(0, 0);
}

void Game::test()
{
	Guerrier Guerrier(100);
	Franz franzdebog("Franzdebog", "Agressif", 100, 100, 20, 50, Entity::entityType::Ennemy, 100);
	Franz franz2("Franz", "ini", 100, 100, 20, 50, Entity::entityType::Ennemy, 100);

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
