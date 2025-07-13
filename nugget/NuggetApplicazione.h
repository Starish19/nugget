#pragma once
#include "stdafx.h"
#include "BaseGameObject.h"

namespace nugget {
	typedef std::unordered_map<std::string, std::unique_ptr<nugget::GameObject>> objectList;

	class NuggetApplicazione
	{
	public:
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;

	protected:
	objectList m_objects;
	};

	extern NuggetApplicazione* nugApp;
}