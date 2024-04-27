// Author: Konstantin Winkel

#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

// cpp includes
#include <math.h>

/* #regions constants */

const long double DEG2RAD = M_PI / 180.0; // rad deg^-1

const long double RAD2DEG = 180.0 / M_PI; // deg rad^-1

const long double G_STAR  = 6.67430e-11; // m^3 kg^-1 s^-2

const long double M_EARTH = 5.9722e24; //kg

const long double MU_EARTH = 3.986004415e14; // kg^3 s^-2

const long double R_EARTH = 6378000; // m

const long double ASTRONOMICAL_UNIT = 149597870700.0; // m

const long double LIGHT_SPEED = 299792458.0; // m s^-1

/* #endregion */

/* #region unit conversion functions */

/* #region distance */

inline long double operator"" _AU(long double au) { return au * ASTRONOMICAL_UNIT; }
inline long double operator"" _AU(long long unsigned int au) { return au * ASTRONOMICAL_UNIT; }

inline long double operator"" _lmin(long double lightminutes) { return lightminutes * LIGHT_SPEED * 60.0; }
inline long double operator"" _lmin(long long unsigned int lightminutes) { return lightminutes * LIGHT_SPEED * 60.0; }

inline long double operator"" _ls(long double lightseconds) { return lightseconds * LIGHT_SPEED; }
inline long double operator"" _ls(long long unsigned int lightseconds) { return lightseconds * LIGHT_SPEED; }

inline long double operator"" _km(long double kilometers) { return kilometers * 1000.0; }
inline long double operator"" _km(long long unsigned int kilometers) { return kilometers * 1000.0; }

inline long double operator"" _m(long double meters) { return meters; }
inline long double operator"" _m(long long unsigned int meters) {return meters; }

inline long double operator"" _cm(long double centimeters) { return centimeters / 100.0; }
inline long double operator"" _cm(long long unsigned int centimeters) { return centimeters / 100.0; }

inline long double operator"" _mm(long double millimeters) { return millimeters / 1000.0; }
inline long double operator"" _mm(long long unsigned int millimeters) { return millimeters / 1000.0; }

/* #endregion */

/* #region time */

inline long double operator"" _h(long double hours) { return hours * 60.0 * 60.0; }
inline long double operator"" _h(long long unsigned int hours) { return hours * 60.0 * 60.0; }

inline long double operator"" _min(long double minutes) { return minutes * 60.0; }
inline long double operator"" _min(long long unsigned int minutes) { return minutes * 60.0; }

inline long double operator"" _s(long double seconds) { return seconds; }
inline long double operator"" _s(long long unsigned int seconds) { return seconds; }

inline long double operator"" _ms(long double milliseconds) { return milliseconds / 1000.0; }
inline long double operator"" _ms(long long unsigned int milliseconds) { return milliseconds / 1000.0; }

inline long double operator"" _ns(long double nanoseconds) { return nanoseconds / (1000.0 * 1000.0); }
inline long double operator"" _ns(long long unsigned int nanoseconds) { return nanoseconds / (1000.0 * 1000.0); }


/* #endregion */

/* #endregion */

/* #region functions*/

void printAllConstants();

/* #endregion */
#endif