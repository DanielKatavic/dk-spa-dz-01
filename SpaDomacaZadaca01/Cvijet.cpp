#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

// SUNCE //

void Cvijet::set_radijus_sunca(const float radijus)
{
	sunce.setRadius(radijus);
}

void Cvijet::set_pozicija_sunca(const float x, const float y)
{
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(x, y);
}

// TUCAK //

void Cvijet::set_radijus_tucka(const float radijus)
{
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setOutlineColor(sf::Color::Red);

	tucak.setRadius(radijus);
	tucak.setOutlineThickness(radijus/2);

	set_dimenzija_stabiljke(radijus/2, radijus*4);
}

void Cvijet::set_pozicija_tucka(const float x, const float y) 
{
	tucak.setPosition(x, y);
}

// STABILJKA //

void Cvijet::set_dimenzija_stabiljke(const float sirina, const float visina)
{
	set_pozicija_stabiljke(sirina);
	set_pozicija_lista(sirina, visina);
	stabiljka.setFillColor(sf::Color::Green);
	stabiljka.setSize(sf::Vector2f(sirina, visina));
}

void Cvijet::set_pozicija_stabiljke(const float sirina)
{
	stabiljka.setPosition(tucak.getPosition());
	stabiljka.move(tucak.getRadius() - (sirina / 2), tucak.getRadius() * 2 + tucak.getRadius() / 2);
}

// LIST //

void Cvijet::set_pozicija_lista(const float sirina, const float visina)
{
	float x_koordinata = stabiljka.getPosition().x + sirina;
	float y_koordinata = stabiljka.getPosition().y + visina / 2;

	list.setFillColor(sf::Color::Green);
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(x_koordinata, y_koordinata));
	list.setPoint(1, sf::Vector2f(x_koordinata + sirina*3, y_koordinata - visina/5));
	list.setPoint(2, sf::Vector2f(x_koordinata + sirina*7, y_koordinata - visina/7));
	list.setPoint(3, sf::Vector2f(x_koordinata + sirina*3.5f, y_koordinata + visina/14));
}

void Cvijet::draw()
{
	window->draw(sunce);
	window->draw(tucak);
	window->draw(stabiljka);
	window->draw(list);
}
