#include "stdafx.h"
#include "grid.h"

nugget::coords nugget::grid::getCellPosition(int row, int column) {
	row = std::min(std::max(row, 0), rows);
	column = std::min(std::max(column, 0), column);
	coords pos = start;
	pos.posX += row * Width_Height.width;
	pos.posY += column * Width_Height.Height;
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

nugget::coords nugget::grid::rotate90(coords currentPos, coords rotateAround) {
	coords vector = rotateAround - currentPos;
	return currentPos + vector.invert();
}