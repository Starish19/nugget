#pragma once

namespace nugget {

	struct coords {
		int posX;
		int posY;

		coords operator-(coords b) {
			return coords{ posX - b.posX, posY - b.posY };
		}
		coords operator+(coords b) {
			return coords{ posX + b.posX, posY + b.posY };
		}

		bool operator >(coords b) {
			return posX > b.posX || posY > b.posY;
		}

		void operator +=(coords b) {
			*this = *this + b;
		}

		void operator -=(coords b) {
			*this = *this - b;
		}

		bool operator ==(coords b) {
			return (posX == b.posX && posY == b.posY);
		}

		coords inverted() {
			return {posY, posX};
		}

		coords one() {
			return coords{ posX, posY };
		}

		coords rotate90(coords rotateAround = {0,0}) {
			*this -= rotateAround;

			int temp = posX;
			posX = -posY;
			posY = temp;

			*this += rotateAround;
			return *this;
		}
	};

	struct dimensions {
		int width;
		int Height;
	};

	class grid
	{
	public:
		grid(coords s, dimensions d, int r, int c);
		~grid() {};

		coords getCellPosition(int row, int column);
		dimensions getGridDimensions();
		dimensions getCellDimensions();

		bool attemptRotate90(coords toRotate, coords rotateAround = {0,0});
		bool attemptMove(coords from, coords to);

	protected:
		coords start;

		dimensions Width_Height;

		int rows;
		int columns;
	};
}