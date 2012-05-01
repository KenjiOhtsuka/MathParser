///-----------------------------------------------------------------
///
/// @file      array.h
/// @author    ruett1
/// Created:   24.04.2012 12:17:13
/// @section   DESCRIPTION
///            Implemention of a xy point array
///
///------------------------------------------------------------------

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "xy_T.h"

class OutOfBound {                              // define an exception class
    public:
        OutOfBound() {}
};

class PointArray {
    private:
        int mySize;
        xy_T *myData;
    public:
        PointArray(int size);                   // constructor
        ~PointArray();                          // destructor
        xy_T & operator [](int index);          // subscript operator
        double min_x();                         // lowest value in the array
        double max_x();                         // highest value in the array
        double min_y();                         // lowest value in the array
        double max_y();                         // highest value in the array
};

PointArray::PointArray(int size) {              // constructor
    if (size > 0) {
        mySize = size;
        myData = new xy_T[size];                // alloc memory for the array
    }
}

PointArray::~PointArray() {                     // destructor
    delete[] myData;                            // deletes each element allocated
}                                               // by the constructor

xy_T & PointArray::operator [](int index) {     // subscript operator
    if ((index < 0) || (index >= mySize))
        throw OutOfBound();                     // throw exception
    return myData[index];                       // ok! return the value
}

double PointArray::min_x() {                    // lowest value in the array
    double val = myData[0].x;
    for (int i = 1; i < mySize; i++) {
        if (myData[i].x < val)                  // save the lower value
            val = myData[i].x;
    }
    return val;                                 // return the value
}

double PointArray::max_x() {                    // highest value in the array
    double val = myData[0].x;
    for (int i = 1; i < mySize; i++) {
        if (myData[i].x > val)                  // save the highest value
            val = myData[i].x;
    }
    return val;                                 // return the value
}

double PointArray::min_y() {                    // lowest value in the array
    double val = myData[0].y;
    for (int i = 1; i < mySize; i++) {
        if (myData[i].y < val)                  // save the lower value
            val = myData[i].y;
    }
    return val;                                 // return the value
}

double PointArray::max_y() {                    // highest value in the array
    double val = myData[0].y;
    for (int i = 1; i < mySize; i++) {
        if (myData[i].y > val)                  // save the highest value
            val = myData[i].y;
    }
    return val;                                 // return the value
}

#endif /* _ARRAY_H_ */
