#ifndef APLICATION_H_INCLUDED
#define APLICATION_H_INCLUDED

#include "RenderMaster.h"
#include "Map.h"

class Application
{
public:
	Application(std::string&&name);

	void runLoop();

private:
	sf::Font m_font;
	RenderMaster m_masterRenderer;
	Map m_map;
};

#endif // !APLICATION_H_INCLUDED