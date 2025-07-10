#pragma once

class Tetris : public nugget::NuggetApplicazione
{
	void Start() final;
	void Update(float dt) final;
	void Render() final;

private:
	nugget::grid map = nugget::grid({0,0}, {50,50}, 10, 20);
};

