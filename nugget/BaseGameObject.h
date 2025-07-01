#pragma once
#include "stdafx.h"

//Forward Declarations
class Component;

namespace nugget {
	class GameObject {
	public:
		virtual void Start() {};
		virtual void Input() {};
		virtual void Update(float dt) {};
		virtual void Render() {};

		template <class C>
		C* addComponent() {
			std::unique_ptr<C> ptr = std::make_unique<C>(this);
			m_ComponentList.push_back(std::move(ptr));
			return ptr.get();
		}

		template <class C>
		C* getComponent() {
			const std::type_info getType = typeid(C);

			for (auto& c : m_ComponentList) {
				const std::type_info thisType = typeid(*c);
				if (getType == thisType) {
					return static_cast<C>(c.get());
				}
			}
			return nullptr;
		}

		std::vector<std::unique_ptr<Component>> m_ComponentList;
	};

	
}