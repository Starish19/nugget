#pragma once

class Tetris : public nugget::NuggetApplicazione
{
	void Start() final;
	void Update(float dt) final;
	void Render() final;

private:
	nugget::grid map = nugget::grid(nugget::coords{50,50}, nugget::dimensions{25,25}, 10, 10);
};

