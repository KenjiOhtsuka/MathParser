///-----------------------------------------------------------------
///
/// @file      xy_T.h
/// @author    ruett1
/// Created:   24.04.2012 12:17:13
/// @section   DESCRIPTION
///            Implemention of a xy point
///
///------------------------------------------------------------------

#ifndef _XY_T_H_
#define _XY_T_H_

class xy_T {
    public:
        double x;                               // x axis value
        double y;                               // y axis value
        xy_T();                                 // constructor
        xy_T & operator = (const xy_T &p);      // overload assign operator
        bool operator < (const xy_T &p);        // overload operator <
        bool operator > (const xy_T &p);        // overload operator >
};

xy_T::xy_T() {                                  // constructor
    x = 0.0;                                    // set x and y to 0
    y = 0.0;
}

xy_T & xy_T::operator = (const xy_T &p) {       // assign operator
    if (this != &p) {                           // prevent assignment to itself
        x = p.x;                                // copy x and y value
        y = p.y;
    }
    return *this;
}

bool xy_T::operator < (const xy_T &p) {         // overlaod operator <
    if (x < p.x && y < p.y)                     // only if x and y are lesser
        return true;                            // return true
    else
        return false;
}

bool xy_T::operator > (const xy_T &p) {         // overlaod operator >
    if (x > p.x && y > p.y)                     // only if x and y are bigger
        return true;                            // return true
    else
        return false;
}

#endif /* _XY_T_H_ */
