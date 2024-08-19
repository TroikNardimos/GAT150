#pragma once
#include "Components/Component.h"

class PlayerComponent : public Component
{
public:
	CLASS_DECLARATION(PlayerComponent);

	virtual void Initialize() override;
	virtual void Update(float dt) override;

public:
	float speed{ 0 };
};