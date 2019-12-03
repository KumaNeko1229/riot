#include "Player.h"

namespace Entity {

ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics) {
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

	// Create animatable component
	Component::Animatable animatableComponent = Component::Animatable();
	animatableComponent.columns = 4;
	animatableComponent.rows = 2;
	animatableComponent.startFrame = 1;
	animatableComponent.endFrame = 8;
	animatableComponent.currentFrame = 1;
	animatableComponent.frameDelay = 0.2f;
	animatableComponent.frameTimeLeft = 0.2f;

	// Create position component
	Component::Position positionComponent = Component::Position();

	// Create the physics component
	Component::Physics physicsComponent = Component::Physics();

	Component::Attack attackComponent = Component::Attack();

	// Add the components
	manager->addComponent<Component::Texture>(playerId, textureComponent);
	manager->addComponent<Component::Transform>(playerId, transformComponent);
	manager->addComponent<Component::Animatable>(playerId, animatableComponent);
	manager->addComponent<Component::Position>(playerId, positionComponent);
	manager->addComponent<Component::Physics>(playerId, physicsComponent);
	manager->addComponent<Component::Attack>(playerId, attackComponent);

	return playerId;
}

}