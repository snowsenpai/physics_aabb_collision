#include "Components.h"
#include "Physics.h"
#include "Entity.h"
#include "Vec2.h"

#include <cstdlib>
#include <cassert>
#include <memory>

namespace Physics
{
	bool isInside(const Vec2& vectorPos, const std::shared_ptr<Entity> entity)
	{
		assert(entity->hasComponent<CTransform>() && "Entity must have CTransfrom component");
		assert(entity->hasComponent<CBoundingBox>() && "Entity must have CBoundingBox component");

		auto entityPos = entity->getComponent<CTransform>().value().pos;
		auto entityHalfBox = entity->getComponent<CBoundingBox>().value().halfSize;

		// bounding box sides
		float a = entityPos.x - entityHalfBox.x, //right
			b = entityPos.x + entityHalfBox.x, //left
			c = entityPos.y + entityHalfBox.y, //bottom
			d = entityPos.y - entityHalfBox.y; //top

		bool xInside = vectorPos.x > a && vectorPos.x < b;
		bool yInside = vectorPos.y < c && vectorPos.y >d;

		return xInside && yInside;
	}

	Vec2 getOvelap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
	{
		assert(a->hasComponent<CTransform>() && "Entity a must have CTransfrom component");
		assert(b->hasComponent<CTransform>() && "Entity b must have CTransfrom component");

		assert(a->hasComponent<CBoundingBox>() && "Entity a must have CBoundingBox component");
		assert(a->hasComponent<CBoundingBox>() && "Entity b must have CBoundingBox component");

		// return the overlap rectangle size of the bounding boxes of entity a and b
		Vec2 aPos = a->getComponent<CTransform>().value().pos;
		Vec2 bPos = b->getComponent<CTransform>().value().pos;

		Vec2 aHalfSize = a->getComponent<CBoundingBox>().value().halfSize;
		Vec2 bHalfSize = b->getComponent<CBoundingBox>().value().halfSize;

		Vec2 delta = { std::abs(aPos.x - bPos.x), std::abs(aPos.y - bPos.y) };

		// positive if x overlap
		float xOverLap = aHalfSize.x + bHalfSize.x - delta.x;
		// positive if y overlap.
		float yOverLap = aHalfSize.y + bHalfSize.y - delta.y;

		return Vec2(xOverLap, yOverLap);
	}

	Vec2 getPreviousOvelap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b)
	{
		assert(a->hasComponent<CTransform>() && "Entity a must have CTransfrom component");
		assert(b->hasComponent<CTransform>() && "Entity b must have CTransfrom component");

		assert(a->hasComponent<CBoundingBox>() && "Entity a must have CBoundingBox component");
		assert(a->hasComponent<CBoundingBox>() && "Entity b must have CBoundingBox component");

		// return the overlap rectangle size of the bounding boxes of entity a and b
		Vec2 aPos = a->getComponent<CTransform>().value().prevPos;
		Vec2 bPos = b->getComponent<CTransform>().value().prevPos;

		Vec2 aHalfSize = a->getComponent<CBoundingBox>().value().halfSize;
		Vec2 bHalfSize = b->getComponent<CBoundingBox>().value().halfSize;

		Vec2 delta = { std::abs(aPos.x - bPos.x), std::abs(aPos.y - bPos.y) };

		// positive if x overlap
		float xOverLap = aHalfSize.x + bHalfSize.x - delta.x;
		// positive if y overlap.
		float yOverLap = aHalfSize.y + bHalfSize.y - delta.y;

		return Vec2(xOverLap, yOverLap);
	}
}