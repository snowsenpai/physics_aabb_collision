#pragma once

#include "Entity.h"
#include "Vec2.h"

#include <memory>

namespace Physics
{
	bool isInside(const Vec2& vectorPos, const std::shared_ptr<Entity> bounds);

	Vec2 getOvelap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);

	Vec2 getPreviousOvelap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);
}