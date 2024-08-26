#pragma once
#include "CollisionComponent.h"

class CircleCollisionComponent : public CollisionComponent
{
	CLASS_DECLARATION(CircleCollisionComponent)
	CLASS_PROTOTYPE(CircleCollisionComponent)

	void Initialize() override;
	void Update(float dt) override;
	bool CheckCollision(const CollisionComponent* collision) override;

public:
	float radius = 0.0f;
};