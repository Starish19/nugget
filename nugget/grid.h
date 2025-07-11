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

		coords inverted() {
			return {posY, posX};
		}

		void rotate90(coords rotateAround) {
			*this = *this - rotateAround;

			int temp = posX;
			posX = -posY;
			posY = temp;

			*this = *this + rotateAround;
		}
	};

	struct dimensions {
		int width;
		int Height;
	};

	class grid
	{
	public:
		grid(coords s, dimensions d, int r, int c) : start{s}, Width_Height{d}, rows(r), columns(c) {};
		~grid() {};

		coords getCellPosition(int row, int column);
		dimensions getGridDimensions();
		dimensions getCellDimensions();

	protected:
		coords start;

		dimensions Width_Height;

		int rows;
		int columns;
	};
}