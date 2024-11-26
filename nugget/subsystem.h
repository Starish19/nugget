#pragma once

namespace nugget {
	//Base System to Inherit from
	class subsystem {
	public:
		virtual void Initalize() = 0;
		virtual void Shutdown() = 0;
	};

}