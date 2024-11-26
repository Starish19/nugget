#pragma once
#include "subsystem.h"

struct Color;

namespace nugget {
	class RenderSystem : public subsystem
	{
	public: 
		virtual int getWidth() = 0;
		virtual int getHeight() = 0;

		virtual void StartDrawing() = 0;
		virtual void FinishDrawing() = 0;
		virtual void Clear(Color color) = 0;
	};
}
