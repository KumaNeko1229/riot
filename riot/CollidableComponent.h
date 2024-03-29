#pragma once

#include <functional>
#include <unordered_set>
#include <vector>
#include <d3dx9math.h>
#include <algorithm>
#include "CollisionType.h"
#include "Component.h"
#include "Manager.h"

namespace Component {

	struct Collidable : ECS::Component {
		float radius;
		std::vector<D3DXVECTOR2> corners;

		CollisionUtil::CollisionType collisionType;

		std::unordered_set<ECS::EntityIdType> collidingWith;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onEnter =
			[](ECS::Manager* manager, ECS::EntityIdType entityId) {};

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId, float frameTime)> onStay =
			[](ECS::Manager* manager, ECS::EntityIdType entityId, float frameTime) {};

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onExit =
			[](ECS::Manager* manager, ECS::EntityIdType entityId) {};

		D3DXVECTOR2 getCenter();
		// Sorts vectors in order of: top left, top right, bottom left, bottom right
		std::vector<D3DXVECTOR2> getSortedCorners();
	};

}

