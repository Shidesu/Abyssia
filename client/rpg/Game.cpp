#include "Game.h"

using namespace std;
using namespace nlohmann;

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

void testFonct(Personnage const& p)
{
	p.dispPersoType();
}


void Game::test() {
<<<<<<< HEAD
	// vas-y, amuses-toi
}

Game* Game::getInstance() 
{
	return instance;
}

sf::RenderWindow* Game::getWindow() const
{
	return this->window;
=======

	
	// create an empty structure (null)
	json j;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j["pi"] = 3.141;

	// add a Boolean that is stored as bool
	j["happy"] = true;

	// add a string that is stored as std::string
	j["name"] = "Niels";

	// add another null object by passing nullptr
	j["nothing"] = nullptr;

	// add an object inside the object
	j["answer"]["everything"] = 42;

	// add an array that is stored as std::vector (using an initializer list)
	j["list"] = { 1, 0, 2 };

	// add another object (using an initializer list of pairs)
	j["object"] = { { "currency", "USD" },{ "value", 42.99 } };

	// instead, you could also write (which looks very similar to the JSON above)
	json j2 = {
		{ "pi", 3.141 },
		{ "happy", true },
		{ "name", "Niels" },
		{ "nothing", nullptr },
		{ "answer",{
			{ "everything", 42 }
		} },
		{ "list",{ 1, 0, 2 } },
		{ "object",{
			{ "currency", "USD" },
			{ "value", 42.99 }
		} }
	};

	std::string testJSON = j.dump();

	std::cout << testJSON;

	Guerrier Guerrier(100, 50);
	Franz franzdebog("Franz", "Agressif", 100, 100, 0, 50, 100);

	testFonct(Guerrier);
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
>>>>>>> 0e540e9283d334d3142c29ca503ee2feb13f7909
}