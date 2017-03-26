#pragma once

#include <memory>
#include "SFML\System.hpp"

typedef sf::Vector2i Position;

template <typename T>
class pointeur_intelligent {
public:
	typedef std::shared_ptr<T> ps ;
	typedef std::weak_ptr<T> pw;
	typedef std::unique_ptr<T> pu;
};