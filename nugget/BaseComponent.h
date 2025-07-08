#pragma once

namespace nugget {
	//Forward Declarations
	class GameObject;

	struct Component {
	public:
		Component() {}
		Component(nugget::GameObject* g) : m_GameObject(g) {}
		virtual ~Component() {}

		virtual void Start() = 0;
		virtual void Update(float dt) = 0;

	private:
		const GameObject* m_GameObject;
	};
}