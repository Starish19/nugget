#pragma once
#include "stdafx.h"
#include "BaseGameObject.h"

namespace nugget {
	class NuggetApplicazione
	{
	public:
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;

	std::unordered_map<std::string, std::unique_ptr<GameObject>> m_objects;
	};

	extern NuggetApplicazione* nugApp;
}