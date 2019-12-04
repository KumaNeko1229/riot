#include "entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "position.h"
#include "texture.h"
#include "transform.h"
#include "Collidable.h"

namespace Entity {

	class Wall : ECS::Entity {};

	ECS::EntityIdType createWallEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y);

}