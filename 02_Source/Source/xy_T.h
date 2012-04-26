///-----------------------------------------------------------------
///
/// @file      xy_T.h
/// @author    ruett1
/// Created:   24.04.2012 12:17:13
/// @section   DESCRIPTION
///            Implements a xy point
///
///------------------------------------------------------------------

#ifndef _XY_T_H_
#define _XY_T_H_

class xy_T {
    public:
        double x;
        double y;
        xy_T();                                 // constructor
        xy_T & operator = (const xy_T &p);      // overload assign operator
        bool operator < (const xy_T &p);        // overload operator <
        bool operator > (const xy_T &p);        // overload operator >
};

xy_T::xy_T() {                                  // constructor
    x = 0.0;
    y = 0.0;
}

xy_T & xy_T::operator = (const xy_T &p) {       // assign operator
    if (this != &p) {                           // prevent assignment to itself
        x = p.x;
        y = p.y;
    }
    return *this;
}

bool xy_T::operator < (const xy_T &p) {         // overlaod operator <
    if (x < p.x && y < p.y)
        return true;
    else
        return false;
}

bool xy_T::operator > (const xy_T &p) {         // overlaod operator >
    if (x > p.x && y > p.y)
        return true;
    else
        return false;
}

#endif /* _XY_T_H_ */
