#include "Map.h"
#include <map>

std::map<int, sf::Color> colors;

Map::Map()
{
	for (int i = 0, marginY = 0; i < 4; i++, marginY += 10)
		for (int j = 0, marginX = 0; j < 4; j++, marginX += 10)
		{
			m_stage[i][j] = "0";
			m_rectangles[i][j].setFillColor(sf::Color::Black);
			m_rectangles[i][j].setSize(sf::Vector2f(106.25f, 106.25f));
			m_rectangles[i][j].setPosition(sf::Vector2f(j * 106.25f + marginX, i * 106.25f + marginY));
		}

	m_stage[rand() % 4][rand() % 4] = "2";
	m_stage[rand() % 4][rand() % 4] = "2";

	colors[2] = sf::Color(238, 228, 218);
	colors[4] = sf::Color(239, 224, 190);
	colors[8] = sf::Color(242, 177, 121);
	colors[16] = sf::Color(245, 149, 99);
	colors[32] = sf::Color(246, 124, 95);
	colors[64] = sf::Color(246, 94, 59);
	colors[128] = sf::Color(237, 207, 114);
	colors[256] = sf::Color(237, 204, 97);
	colors[512] = sf::Color(237, 200, 80);
	colors[1024] = sf::Color(238, 228, 218);
	colors[2048] = sf::Color(238, 228, 218);
}

void Map::setFont(sf::Font& _font)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			m_texts[i][j].setString(m_stage[i][j]);
			m_texts[i][j].setFont(_font);
			m_texts[i][j].setStyle(sf::Text::Bold);
			m_texts[i][j].setCharacterSize(40);
			m_texts[i][j].setColor(sf::Color(119, 110, 101));
		}
}

void Map::draw(sf::RenderWindow* _Wind)
{
	for (int i = 0, marginY = 0; i < 4; i++, marginY += 10)
		for (int j = 0, marginX = 0; j < 4; j++, marginX += 10)
		{
			if (m_stage[i][j] != "0")
			{
				m_rectangles[i][j].setFillColor(colors[std::stoi(m_stage[i][j])]);
				m_texts[i][j].setColor(std::stoi(m_stage[i][j]) > 4 ? sf::Color(249, 246, 242) : sf::Color(119, 110, 101));				m_texts[i][j].setPosition(sf::Vector2f(j * 106.25f + 53.125f - m_texts[i][j].getLocalBounds().width / 2, i * 106.25f + m_texts[i][j].getLocalBounds().height));
				m_texts[i][j].setPosition(sf::Vector2f(j * 106.25f + 53.125f - m_texts[i][j].getLocalBounds().width / 2 + marginX, i * 106.25f + m_texts[i][j].getLocalBounds().height + marginY));
				_Wind->draw(m_rectangles[i][j]);
				_Wind->draw(m_texts[i][j]);
			}
		}
}

bool Map::move(short _x, short _y)
{
	int iterations = 0;
	while (true)
	{
		int iterations2 = 0;

		for (int i = _y < 0 ? 1 : 0; i < (_y > 0 ? 3 : 4); i++)
			for (int j = _x < 0 ? 1 : 0; j < (_x > 0 ? 3 : 4); j++)
			{
				if (m_stage[i + _y][j + _x] != m_stage[i][j] && m_stage[i + _y][j + _x] == "0")
				{
					m_stage[i + _y][j + _x] = m_stage[i][j];
					m_texts[i + _y][j + _x].setString(m_texts[i][j].getString());

					m_stage[i][j] = "0";
					m_texts[i][j].setString("0");
					iterations2++;
				}

				else if (m_stage[i][j] == m_stage[i + _y][j + _x] && m_stage[i][j] != "0")
				{
					m_stage[i + _y][j + _x] = std::to_string(std::stoi(m_stage[i][j]) + std::stoi(m_stage[i + _y][j + _x]));
					m_texts[i + _y][j + _x].setString(m_stage[i + _y][j + _x]);

					m_stage[i][j] = "0";
					m_texts[i][j].setString("0");
					iterations2++;
				}
			}

		if (!iterations2) break;
		else iterations++;
	}

	return iterations;
}

void Map::newSquare()
{
	while (true)
	{
		int randX = rand() % 4, randY = rand() % 4;

		if (m_stage[randX][randY] == "0")
		{
			m_stage[randX][randY] = "2";
			m_texts[randX][randY].setString("2");
			break;
		}
	}
}