#pragma once
#include "stdafx.h"
#include "BaseComponent.h"

namespace nugget {
	class GameObject {
	public:
		virtual void Start() {for (auto& c : m_ComponentList) c->Start(); }
		virtual void Update(float dt) {for (auto& c : m_ComponentList) c->Update(dt); }

		template <class C>
		C* addComponent() {
			std::unique_ptr<C> ptr = std::make_unique<C>(this);
			C* p = ptr.get();
			m_ComponentList.push_back(std::move(ptr));
			return p;
		}

		template <class C>
		C* getComponent() {
			const std::type_info& getType = typeid(C);

			for (auto& c : m_ComponentList) {
				const std::type_info& thisType = typeid(*c);
				if (getType == thisType) {
					return static_cast<C*>(c.get());
				}
			}
			return nullptr;
		}

		template <class C>
		C* getSubComponent() {
			for (auto& c : m_ComponentList) {
				if (dynamic_cast<C*>(c.get()) != nullptr) {
					return static_cast<C*>(c.get());
				}
			}
		}

		std::vector<std::unique_ptr<Component>> m_ComponentList;
	};

	
}