#include "PlayerEntity.h"

namespace Entity {

ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics, int x, int y) {
	ECS::EntityIdType playerId = manager->createEntity<Player>();

	// Create the components
	// Create texture Component
	Component::Texture textureComponent = Component::Texture();
	if (!textureComponent.loadTexture(graphics, PLAYER_IMAGE))
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error loading player entity texture"));
	}
	textureComponent.visible = true;

	// Create transform component
	Component::Transform transformComponent = Component::Transform();
	transformComponent.angle = PI / 2.0f;

	// Create animatable component
	Component::Animatable animatableComponent = Component::Animatable();
	animatableComponent.columns = 2;
	animatableComponent.rows = 4;
	animatableComponent.startFrame = 7;
	animatableComponent.endFrame = 7;
	animatableComponent.currentFrame = 7;
	animatableComponent.frameDelay = 0.2f;
	animatableComponent.frameTimeLeft = 0.2f;

	// Create position component
	Component::Position positionComponent = Component::Position();
	positionComponent.x = x * tileWidth;
	positionComponent.y = y * tileHeight;

	// Create the physics component
	Component::Physics physicsComponent = Component::Physics();

	// Create the attack component
	Component::Attack attackComponent = Component::Attack();
	attackComponent.interval = 0.1;

	// Create the collision component
	int playerWidth = textureComponent.totalWidth / animatableComponent.columns;
	int playerHeight = textureComponent.totalHeight / animatableComponent.rows;
	Component::Collidable collidableComponent = Component::Collidable();
	std::vector<D3DXVECTOR2> corners = {
		{(float) x * tileWidth, (float) y * tileHeight},
		{(float) x * tileWidth + playerWidth, (float) y * tileHeight},
		{(float) x * tileWidth, (float) y * tileHeight + playerHeight},
		{(float) x * tileWidth + playerWidth, (float) y * tileHeight + playerHeight}
	};
	collidableComponent.collisionType = CollisionUtil::CollisionType::AABB;
	collidableComponent.corners = corners;

	// Create the damage component
	Component::Damage damageComponent = Component::Damage();
	damageComponent.health = 20;

	// Add the components
	manager->addComponent<Component::Texture>(playerId, textureComponent);
	manager->addComponent<Component::Transform>(playerId, transformComponent);
	manager->addComponent<Component::Collidable>(playerId, collidableComponent);
	manager->addComponent<Component::Animatable>(playerId, animatableComponent);
	manager->addComponent<Component::Position>(playerId, positionComponent);
	manager->addComponent<Component::Physics>(playerId, physicsComponent);
	manager->addComponent<Component::Attack>(playerId, attackComponent);
	manager->addComponent<Component::Damage>(playerId, damageComponent);

	return playerId;
}

}