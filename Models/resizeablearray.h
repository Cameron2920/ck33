#ifndef RESIZEABLEARRAY_H
#define RESIZEABLEARRAY_H

template <class Element>
class ResizeableArray {
public:
    ResizeableArray();
    ResizeableArray(int elementsCapacity);
    ~ResizeableArray();
    void add(Element* t);
    void remove(Element* t);
    Element* pop(Element* t);
    int getNumberOfElements();
    Element* getAt(int index);
private:
    Element** elements;
    int numberOfElements;
    int elementsCapacity;
    void allocateElements();
};

#endif // RESIZEABLEARRAY_H
