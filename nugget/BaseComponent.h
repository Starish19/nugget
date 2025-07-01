#pragma once

//Forward Declarations
class GameObject;

namespace nugget {
	class Component {
	public:
		Component(GameObject* g) : m_GameObject(g) {}
		virtual ~Component() {}

		virtual void Start() = 0;
		virtual void Update() = 0;

	private:
		GameObject* m_GameObject;
	};
}