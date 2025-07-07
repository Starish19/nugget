#pragma once

class Tetris : public nugget::NuggetApplicazione
{
	void Start() final;
	void Update(float dt) final;
	void Render() final;

	std::unordered_map<std::string, std::unique_ptr<nugget::GameObject>> m_objects;
};

