#include "Application.h"
#include <SFML/Graphics.hpp>

Application::Application(std::string&&name)
{
	m_masterRenderer.getWindow()->create(sf::VideoMode(455, 455), name);
	m_font.loadFromFile("Arial.ttf");
	m_map.setFont(m_font);
}

void Application::runLoop()
{
	while (m_masterRenderer.getWindow()->isOpen())
	{
		sf::Event ev;

		while (m_masterRenderer.getWindow()->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				m_masterRenderer.getWindow()->close();
			if (ev.type == sf::Event::KeyPressed)
				switch (ev.key.code)
				{
				case sf::Keyboard::Escape:
					m_masterRenderer.getWindow()->close();
					break;
				case sf::Keyboard::Left:
					if(m_map.move(-1, 0)) m_map.newSquare();
					break;
				case sf::Keyboard::Right:
					if(m_map.move(1, 0)) m_map.newSquare();
					break;
				case sf::Keyboard::Up:
					if(m_map.move(0, -1)) m_map.newSquare();
					break;
				case sf::Keyboard::Down:
					if(m_map.move(0, 1)) m_map.newSquare();
					break;
				}
		}

		m_masterRenderer.finishRender(m_map);
	}
}