#include "PersonnageGraph.h"

PersonnageG::PersonnageG()
{
	sachiko;
	if (!sachiko.loadFromFile("sachiko.png"))
	{
		// erreur...
	}

	Player.setTexture(sachiko);
}

PersonnageG::~PersonnageG()
{
}

void PersonnageG::deplacement()
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
	//	worldCollision(last_pos);

	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

		auto valueMovement = +speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(valueMovement, 0);
		Player.setTextureRect(sf::IntRect(0, 116, 22, 28));
	//	worldCollision(last_pos);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		auto valueMovement = -speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(0, valueMovement);
		Player.setTextureRect(sf::IntRect(0, 164, 22, 28));
	//	worldCollision(last_pos);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		auto valueMovement = +speed * elapsedTime;

		valueMovement = (int)round(valueMovement);

		Player.move(0, valueMovement);
		Player.setTextureRect(sf::IntRect(0, 20, 22, 28));
	//	worldCollision(last_pos);
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
	speed = 90;
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
	speed = 180;*/
}

void PersonnageG::windowCollision()
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

void PersonnageG::worldCollision(sf::Vector2f & last_pos)
{
}

/*void PersonnageG::worldCollision(sf::Vector2f & last_pos)
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


}*/
