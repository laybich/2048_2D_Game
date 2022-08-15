#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <SFML/Graphics.hpp>

class Map
{
public:
	Map();

	void setFont(sf::Font &_font);
	void draw(sf::RenderWindow* _Wind);

	void newSquare();
	bool move(short _x, short _y);

private:
	std::string m_stage[4][4];
	sf::RectangleShape m_rectangles[4][4];
	sf::Text m_texts[4][4];
};

#endif // !MAP_H_INCLUDED