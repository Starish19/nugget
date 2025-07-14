#pragma once
#include "stdafx.h"
#include "BaseGameObject.h"

namespace nugget {
	class NuggetApplicazione;

	class NuggetScene
	{
	public:
		NuggetScene(NuggetApplicazione* app) : m_app(app) {};

		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
		virtual void Close() = 0;

	protected:
		std::unordered_map<std::string, std::unique_ptr<nugget::GameObject>>  m_objects;
		NuggetApplicazione* m_app;
	};
}