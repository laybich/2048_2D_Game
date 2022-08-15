#include "RenderMaster.h"

RenderMaster::RenderMaster()
{
	
}

void RenderMaster::finishRender(Map &_map)
{
	m_window.clear(sf::Color(187, 173, 160));

	_map.draw(&m_window);

	m_window.display();
}

sf::RenderWindow* RenderMaster::getWindow()
{
	return &m_window;
}