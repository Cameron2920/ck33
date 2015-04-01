#include "resizeablecellarray.h"

ResizeableCellArray::ResizeableCellArray():maxRowCoordinate(0), maxColumnCoordinate(0){}

ResizeableCellArray::ResizeableCellArray(int elementsCapacity):ResizeableArray<Cell>(elementsCapacity),maxRowCoordinate(0), maxColumnCoordinate(0){}

void ResizeableCellArray::add(Cell *cell){
    ResizeableArray<Cell>::add(cell);
    maxRowCoordinate = (cell->getRowCoordinate() > maxRowCoordinate) ? cell->getRowCoordinate() : maxRowCoordinate;
    maxColumnCoordinate = (cell->getColumnCoordinate() > maxRowCoordinate) ? cell->getColumnCoordinate() : maxColumnCoordinate;
}

Cell* ResizeableCellArray::pop(Cell *cell){
    Cell* foundCell = ResizeableArray<Cell>::pop(cell);
    maxRowCoordinate = findMaxColumnCoordinate();
    maxColumnCoordinate = findMaxRowCoordinate();
    return foundCell;
}

int ResizeableCellArray::findMaxColumnCoordinate(){
    int maxCoordinate = 0;
    for(int cellIndex = 0; cellIndex < getNumberOfElements(); cellIndex++){
        maxCoordinate = (getAt(cellIndex)->getColumnCoordinate() > maxCoordinate ? getAt(cellIndex)->getColumnCoordinate() : maxCoordinate);
    }
    return maxCoordinate;
}

int ResizeableCellArray::findMaxRowCoordinate(){
    int maxCoordinate = 0;
    for(int cellIndex = 0; cellIndex < getNumberOfElements(); cellIndex++){
        maxCoordinate = (getAt(cellIndex)->getRowCoordinate() > maxCoordinate ? getAt(cellIndex)->getRowCoordinate() : maxCoordinate);
    }
    return maxCoordinate;
}

Cell* ResizeableCellArray::findByCoordinates(int rowCoordinate, int columnCoordinate){
    for(int cellIndex = 0; cellIndex < getNumberOfElements(); cellIndex++){
        Cell* cell = getAt(cellIndex);
        if(cell->getColumnCoordinate() == columnCoordinate && cell->getRowCoordinate() == rowCoordinate){
            return cell;
        }
    }
    return 0;
}

int ResizeableCellArray::getMaxColumnCoordinate(){
    return maxColumnCoordinate;
}

int ResizeableCellArray::getMaxRowCoordinate(){
    return maxRowCoordinate;
}

void ResizeableCellArray::orderByCoordinates(){
    bool flag = true;
    Cell* tempCell;

    while(flag){
        flag = false;

        for(int cellIndex = 0; cellIndex < getNumberOfElements() - 1; cellIndex++){
            if(getAt(cellIndex)->getRowCoordinate() > getAt(cellIndex + 1)->getRowCoordinate() ||
                    (getAt(cellIndex)->getRowCoordinate() == getAt(cellIndex + 1)->getRowCoordinate() && getAt(cellIndex)->getColumnCoordinate() > getAt(cellIndex + 1)->getColumnCoordinate())){
                flag = true;
                tempCell = getAt(cellIndex);
                setAt(getAt(cellIndex + 1), cellIndex);
                setAt(tempCell, cellIndex + 1);
            }
        }
    }
}
