#pragma once

namespace nugget {

	class subsystem {
	public:
		virtual void Initalize() = 0;
		virtual void Shutdown() = 0;
	};

}