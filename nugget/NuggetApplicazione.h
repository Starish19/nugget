#pragma once
#include "stdafx.h"

namespace nugget {
	class NuggetApplicazione
	{
	public:
		virtual void Start() = 0;
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;
	};

	extern NuggetApplicazione* nugApp;
}