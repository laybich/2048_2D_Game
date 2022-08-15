#ifndef RENDERMASTER_H_INCLUDED
#define RENDERMASTER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Map.h"

class RenderMaster
{
public:
	RenderMaster();

	void finishRender(Map &_map);

	sf::RenderWindow* getWindow();

private:
	sf::RenderWindow m_window;
};

#endif // !RENDERMASTER_H_INCLUDED