#include "stdafx.h"
#include "grid.h"

nugget::grid::grid(coords s, dimensions d, int r, int c) : start{ s }, Width_Height{ d }, rows(r - 1), columns(c - 1) {
};

nugget::coords nugget::grid::getCellPosition(int row, int column) {
	coords pos = start;
	pos += {row* Width_Height.width, column* Width_Height.Height};
	return pos;
}

nugget::dimensions nugget::grid::getGridDimensions() {
	int totalWidth = Width_Height.width * rows;
	int totalHeight = Width_Height.Height * columns;
	return nugget::dimensions{totalWidth, totalHeight};
}

nugget::dimensions nugget::grid::getCellDimensions() {
	return Width_Height;
}

bool nugget::grid::attemptMove(coords from, coords to) {
	if ((from + to) > coords{ rows,columns } || coords{ 0,0 } > (from + to))
		return false;
	else return true;
}

bool nugget::grid::attemptRotate90(coords toRotate, coords rotateAround) {
	toRotate.rotate90(rotateAround);
	if (toRotate > coords{ rows,columns } || coords{ 0,0 } > toRotate)
		return false;
	else return true;
}