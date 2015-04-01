#ifndef RESIZEABLECELLARRAY_H
#define RESIZEABLECELLARRAY_H

#ifdef CELL_H
class Cell;
#else
#include "cell.h"
#endif

#include "resizeablearray.t.hpp"

class ResizeableCellArray : public ResizeableArray<Cell>{
public:
    ResizeableCellArray();
    ResizeableCellArray(int cellsCapacity);
    int getMaxColumnCoordinate();
    int getMaxRowCoordinate();
    virtual void add(Cell *cell);
    virtual Cell* pop(Cell *cell);
    Cell* findByCoordinates(int rowCoordinate, int columnCoordinate);
    void orderByCoordinates();
private:
    int maxRowCoordinate;
    int maxColumnCoordinate;
    int findMaxColumnCoordinate();
    int findMaxRowCoordinate();
};

#endif // RESIZEABLECELLARRAY_H
