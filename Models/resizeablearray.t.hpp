#ifndef RESIZEABLEARRAY_T_HPP
#define RESIZEABLEARRAY_T_HPP

#include "resizeablearray.h"

template <class Element>
ResizeableArray<Element>::ResizeableArray():elementsCapacity(0), elements(0), numberOfElements(0){}

template <class Element>
ResizeableArray<Element>::ResizeableArray(int elementsCapacity):elementsCapacity(elementsCapacity), numberOfElements(0){
    elements = new Element*[elementsCapacity];
}

template <class Element>
ResizeableArray<Element>::~ResizeableArray(){
    if(elements){
        delete [] elements;
    }
}

template <class Element>
void ResizeableArray<Element>::allocateElements(){
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

    if(oldCapacity > 0){
        delete [] oldElements;
    }
}

template <class Element>
void ResizeableArray<Element>::add(Element* element){
    if(numberOfElements >= elementsCapacity){
        allocateElements();
    }
    elements[numberOfElements] = element;
    numberOfElements++;
}

template <class Element>
void ResizeableArray<Element>::remove(Element* element){
    Element* foundElement = pop(element);
    if(foundElement){
        delete element;
    }
}

template <class Element>
Element* ResizeableArray<Element>::pop(Element* element){
    bool foundElementInElements = false;
    for(int elementIndex = 0; elementIndex < numberOfElements; elementIndex++){
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
void ResizeableArray<Element>::popAll(){
    numberOfElements = 0;
}

template <class Element>
Element* ResizeableArray<Element>::getAt(int index){
    if(index >= 0 && index < numberOfElements){
        return elements[index];
    }
    return 0;
}

template <class Element>
void ResizeableArray<Element>::setAt(Element* element, int index){
    if(index >= 0 && index < numberOfElements){
        elements[index] = element;
    }
}

template <class Element>
int ResizeableArray<Element>::getNumberOfElements(){
    return this->numberOfElements;
}

template <class Element>
void ResizeableArray<Element>::append(ResizeableArray<Element> *resizeableArray){
    for(int elementIndex = 0; elementIndex < resizeableArray->getNumberOfElements(); elementIndex++){
        add(resizeableArray->getAt(elementIndex));
    }
}

#endif // RESIZEABLEARRAY_T_HPP
