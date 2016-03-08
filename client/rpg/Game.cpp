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
	this->window->draw(cubeTestCollision);
	this->window->draw(monster);
	this->window->draw(Player);
	this->window->display();

}

void Game::deplacement()
{

	auto elapsedTime = moveClock.restart().asSeconds();

	sf::Vector2f last_pos = Player.getPosition();

	windowCollision();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		auto valueMovement = -speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(valueMovement, 0);
		Player.setTextureRect(sf::IntRect(0, 68, 22, 28));
		worldCollision(last_pos);

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		auto valueMovement = +speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(valueMovement, 0);
		Player.setTextureRect(sf::IntRect(0, 116, 22, 28));
		worldCollision(last_pos);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		auto valueMovement = -speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(0, valueMovement);
		Player.setTextureRect(sf::IntRect(0, 164, 22, 28));
		worldCollision(last_pos);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		auto valueMovement = +speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(0, valueMovement);
		Player.setTextureRect(sf::IntRect(0, 20, 22, 28));
		worldCollision(last_pos);
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		speed = 90;
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
		speed = 180;*/
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
	sachiko;
	if (!sachiko.loadFromFile("sachiko.png"))
	{
		// erreur...
	}
	if (!mario.loadFromFile("mario.gif"))
	{
		//erreur
	}
	monster.setTexture(mario);
	Player.setTexture(sachiko);
	Player.setTextureRect(sf::IntRect(0, 20, 22, 28));
	Player.setPosition(window_width / 2, window_height / 2);
	cubeTestCollision = sf::VertexArray(sf::Quads, 4);

	cubeTestCollision[0].position = sf::Vector2f(100, 100);
	cubeTestCollision[1].position = sf::Vector2f(200, 100);
	cubeTestCollision[2].position = sf::Vector2f(200, 200);
	cubeTestCollision[3].position = sf::Vector2f(100, 200);
	cubeTestCollision[0].color = sf::Color::Blue;
	cubeTestCollision[1].color = sf::Color::Green;
	cubeTestCollision[3].color = sf::Color::Red;



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

void Game::windowCollision()
{

	auto playerBoundingBox = Player.getGlobalBounds();

	int stepBack(0);

	if (speed < 180)
	{
		stepBack = 1;
	}
	else
		stepBack = 3;

	auto collisionPos = Player.getPosition();


	if (playerBoundingBox.left < 0)
	{
		Player.setPosition(collisionPos.x + stepBack, collisionPos.y);
	}

	if (playerBoundingBox.left + playerBoundingBox.width > window_width)
	{
		Player.setPosition(collisionPos.x - stepBack, collisionPos.y);
	}

	if (playerBoundingBox.top < 0)
	{
		if (playerBoundingBox.left < 0)
			Player.setPosition(collisionPos.x + stepBack, collisionPos.y + stepBack);
		else if (playerBoundingBox.left + playerBoundingBox.width > window_width)
			Player.setPosition(collisionPos.x - stepBack, collisionPos.y + stepBack);
		else
			Player.setPosition(collisionPos.x, collisionPos.y + stepBack);
	}

	if (playerBoundingBox.top + playerBoundingBox.height > window_height)
	{
		if (playerBoundingBox.left < 0)
			Player.setPosition(collisionPos.x + stepBack, collisionPos.y - stepBack);
		else if (playerBoundingBox.left + playerBoundingBox.width > window_width)
			Player.setPosition(collisionPos.x - stepBack, collisionPos.y - stepBack);
		else
			Player.setPosition(collisionPos.x, collisionPos.y - stepBack);
	}

}

void Game::worldCollision(sf::Vector2f & last_pos)
{
	auto playerBoundingBox = Player.getGlobalBounds();
	auto testCol = cubeTestCollision.getBounds();
	auto monsterCol = monster.getGlobalBounds();

	if (playerBoundingBox.intersects(testCol))
	{
		Player.setPosition(last_pos);
	}
	else if (playerBoundingBox.intersects(monsterCol))
	{
		Player.setPosition(last_pos);
	}
	else
		last_pos = Player.getPosition();


}