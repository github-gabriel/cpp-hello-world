#pragma once

#include <iostream>

template <typename  T>
class DynamicArray{
private:
    T *data;
    int size;
    int capacity; // Capacity um intern mehr Speicher zu allokieren
public:
    DynamicArray();
    DynamicArray(int size);
    ~DynamicArray();
    DynamicArray(const DynamicArray<T> &other); // Kopierkonstruktor überschreiben
    DynamicArray(DynamicArray<T> &&other); // &&otherDynamicArray = 'R-Value', Move Constructor

    int getSize() const;

    T& operator[](int index);
    DynamicArray<T> operator+(const DynamicArray<T> &other);
    DynamicArray<T>& operator=(const DynamicArray<T> &other);
    DynamicArray<T>& operator=(DynamicArray<T> &&other);
};

template <typename  T>
DynamicArray<T>::DynamicArray() {
    size = 10;
    capacity = size;
    data = new T[size];
}

/*
DynamicArray::DynamicArray(int size) : size(size){
    data = new int[size];
}
*/

template <typename  T>
DynamicArray<T>::DynamicArray(int size){
    // (*this).size = size;
    this->size = size;
    capacity = size;
    data = new T[size];
}

template <typename  T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) {
    size = other.size;
    capacity = size;
    data = new T[size]; // neuen dynamischen Speicher erzeugen
    for(int i = 0; i < size; i++){
        data[i] = other.data[i]; // Werte aus der Originalinstanz in den neuen dynamischen Speicher kopieren
    }
}

template <typename  T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &&other) { // Move Constructor
    // Daten werden direkt verschoben, anstatt kopiert
    data = other.data;
    size = other.size;
    capacity = size;
    // Damit Destruktor 'data' nicht für ungültig erklärt bzw. Fehler wirft
    other.data = nullptr;
    std::cout << "Move Constructor wurde aufgerufen! Werte erfolgreich verschoben!" << std::endl;
}

template <typename  T>
DynamicArray<T>::~DynamicArray() {
    delete data;
}

template <typename  T>
int DynamicArray<T>::getSize() const {
    return size;
}

template <typename  T>
T& DynamicArray<T>::operator[](int index) {
    if (index >= size){
        if(index >= capacity){
            int newCapacity = index + 1;
            if(newCapacity < size * 2){
                newCapacity = size * 2;
            }
            T *newData = new T[newCapacity];
            memcpy(newData, data, sizeof(T) * size);
            delete data;
            data = newData;
            capacity = newCapacity;
        }
        size = index + 1;
    }
    return data[index];
}

template <typename  T>
DynamicArray<T> DynamicArray<T>::operator+(const DynamicArray<T> &other) {
    if(size != other.size){
        throw 10;
    }
    DynamicArray retVal(size);
    for(int i = 0; i < size; i++){
        retVal[i] = data[i] + other.data[i]; // Werte werden addiert
    }
    return retVal;
}

template <typename  T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &other) {
    if(&other == this) return *this;
    if(other.size != size){
        delete[] data;
        size = other.size;
        data = new int[size];
    }
    for(int i = 0; i < size;i++){
        data[i] =  other.data[i];
    }
    return *this;
}

template <typename  T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T> &&other) {
    if(&other == this) return *this;
    delete[] data;
    data = other.data;
    size = other.size;
    capacity = size;
    other.data = nullptr;
    return *this;
}