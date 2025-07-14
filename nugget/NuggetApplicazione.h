#pragma once
#include "stdafx.h"
#include "subsystem.h"
#include "NuggetScene.h"

namespace nugget {
	class NuggetApplicazione : public subsystem
	{
	public:
		virtual void Update(float dt) = 0;
		virtual void Render() = 0;

		template <class S>
		S* addScene(std::string sceneName) {
			std::unique_ptr<S> ptr = std::make_unique<S>(this);
			S* p = ptr.get();
			m_scenes[sceneName] = std::move(ptr);
			return p;
		}

		void switchScene(std::string sceneName) {
			if (m_scenes.find(sceneName) != m_scenes.end()) {
				current_scene->Close();
				current_scene = m_scenes[sceneName].get();
			}
		}
		

	protected:
	std::unordered_map<std::string, std::unique_ptr<NuggetScene>> m_scenes;
	NuggetScene* current_scene;
	};

	extern NuggetApplicazione* nugApp;
}