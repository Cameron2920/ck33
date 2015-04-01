#ifndef RESIZEABLEARRAY_H
#define RESIZEABLEARRAY_H

template <class Element>
class ResizeableArray {
public:
    ResizeableArray();
    ResizeableArray(int elementsCapacity);
    ~ResizeableArray();
    virtual void add(Element* t);
    void remove(Element* t);
    virtual Element* pop(Element* t);
    void popAll();
    int getNumberOfElements();
    Element* getAt(int index);
    void setAt(Element* element, int index);
    void append(ResizeableArray<Element>* resizeableArray);
    void merge(ResizeableArray<Element>* resizeableArray);
    void merge(Element* t);
    bool containsElement(Element* t);
private:
    Element** elements;
    int numberOfElements;
    int elementsCapacity;
    void allocateElements();
};

#endif // RESIZEABLEARRAY_H
