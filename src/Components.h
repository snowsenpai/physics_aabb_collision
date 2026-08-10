#pragma once

#include "Vec2.h"

#include <SFML/Graphics.hpp>

class CTransform
{
public:
	Vec2 pos = { 0.0, 0.0 };
	Vec2 velocity = { 0.0, 0.0 };
	float angle = 0;

	CTransform(const Vec2& p) : pos(p) {}

	CTransform(const Vec2& p, const Vec2& v, float a)
		: pos(p), velocity(v), angle(a) {}
};

class CBoundingBox
{
public:
	Vec2 size = { 0.0f, 0.0f };

	CBoundingBox(Vec2 size)
		: size(size) {}
};

class CBoundingCircle
{
public:
	float radius = 0;
	
	CBoundingCircle(float r)
		: radius(r) {}
};

class CShape
{
public:
	sf::CircleShape circle;

	CShape(float radius, int points, const sf::Color& fill, const sf::Color& outline, float thickness)
		: circle(radius, points)
	{
		circle.setFillColor(fill);
		circle.setOutlineColor(outline);
		circle.setOutlineThickness(thickness);
		circle.setOrigin({ radius, radius });
	}
};

class CInput
{
public:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool shoot = false;

	CInput() {}
};
