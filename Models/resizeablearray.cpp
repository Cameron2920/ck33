#include "resizeablearray.h"

ResizeableArray::ResizeableArray():elementsCapacity(0){}

template <class Element>
ResizeableArray::ResizeableArray(int elementsCapacity):elementsCapacity(elementsCapacity){
    elements = new Element*[elementsCapacity];
}

template <class Element>
ResizeableArray::~ResizeableArray(){
    if(this->elements){
        for(int elementsIndex = 0; elementsIndex < numberOfElements; elementsIndex++){
            delete elements[elementsIndex];
        }
        delete [] elements;
    }
}

template <class Element>
void ResizeableArray::allocateElements(){
    int oldCapacity = this->elementsCapacity;
    Element** oldElements = this->elements;

    if(oldCapacity == 0){
        elementsCapacity = 1;
    }
    else{
        elementsCapacity *= 2;
    }
    elements = new Element*[elementsCapacity];

    for(int elementIndex = 0; elementIndex < numberOfElements; elementIndex++){
        elements[elementIndex] = oldElements[elementIndex];
    }
    delete [] oldElements;
}

template <class Element>
void ResizeableArray::add(Element* element){
    if(numberOfElements >= elementsCapacity){
        allocateElements();
    }
    elements[numberOfElements] = element;
    numberOfElements++;
}

template <class Element>
void ResizeableArray::remove(Element* element){
    Element* foundElement = pop(element);
    if(foundElement){
        delete element;
    }
}

template <class Element>
Element* ResizeableArray::pop(Element* element){
    bool foundElementInElements = false;
    for(int elementIndex = 0; elementIndex < numberOfEnemies; elementIndex++){
        if(foundElementInElements){
            elements[elementIndex - 1] = elements[elementIndex];
        }
        else{
            foundElementInElements = (elements[elementIndex] == element);
        }
    }
    if(foundElementInElements){
        numberOfElements--;
        return element;
    }
    return 0;
}

template <class Element>
Element* ResizeableArray::getAt(int index){
    if(index >= 0 && index < numberOfElements){
        return elements[index];
    }
    return 0;
}

int ResizeableArray::getNumberOfElements(){
    return numberOfElements;
}

