// Author: Konstantin Winkel

#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

// own includes
#include "type-definitions.h"

// cpp includes
#include <math.h>

/* #regions constants */

const ld DEG2RAD = M_PI / 180.0; // rad deg^-1

const ld RAD2DEG = 180.0 / M_PI; // deg rad^-1

const ld G_STAR  = 6.67430e-11; // m^3 kg^-1 s^-2

const ld M_EARTH = 5.9722e24; //kg

const ld MU_EARTH = 3.986004415e14; // kg^3 s^-2

const ld R_EARTH = 6378000; // m

const ld ASTRONOMICAL_UNIT = 149597870700.0; // m

const ld LIGHT_SPEED = 299792458.0; // m s^-1

/* #endregion */

/* #region unit conversion functions */

/* #region distance */

inline ld operator"" _AU(ld au) { return au * ASTRONOMICAL_UNIT; }
inline ld operator"" _AU(long long unsigned int au) { return au * ASTRONOMICAL_UNIT; }

inline ld operator"" _lmin(ld lightminutes) { return lightminutes * LIGHT_SPEED * 60.0; }
inline ld operator"" _lmin(long long unsigned int lightminutes) { return lightminutes * LIGHT_SPEED * 60.0; }

inline ld operator"" _ls(ld lightseconds) { return lightseconds * LIGHT_SPEED; }
inline ld operator"" _ls(long long unsigned int lightseconds) { return lightseconds * LIGHT_SPEED; }

inline ld operator"" _km(ld kilometers) { return kilometers * 1000.0; }
inline ld operator"" _km(long long unsigned int kilometers) { return kilometers * 1000.0; }

inline ld operator"" _m(ld meters) { return meters; }
inline ld operator"" _m(long long unsigned int meters) {return meters; }

inline ld operator"" _cm(ld centimeters) { return centimeters / 100.0; }
inline ld operator"" _cm(long long unsigned int centimeters) { return centimeters / 100.0; }

inline ld operator"" _mm(ld millimeters) { return millimeters / 1000.0; }
inline ld operator"" _mm(long long unsigned int millimeters) { return millimeters / 1000.0; }

/* #endregion */

/* #region time */

inline ld operator"" _h(ld hours) { return hours * 60.0 * 60.0; }
inline ld operator"" _h(long long unsigned int hours) { return hours * 60.0 * 60.0; }

inline ld operator"" _min(ld minutes) { return minutes * 60.0; }
inline ld operator"" _min(long long unsigned int minutes) { return minutes * 60.0; }

inline ld operator"" _s(ld seconds) { return seconds; }
inline ld operator"" _s(long long unsigned int seconds) { return seconds; }

inline ld operator"" _ms(ld milliseconds) { return milliseconds / 1000.0; }
inline ld operator"" _ms(long long unsigned int milliseconds) { return milliseconds / 1000.0; }

inline ld operator"" _ns(ld nanoseconds) { return nanoseconds / (1000.0 * 1000.0); }
inline ld operator"" _ns(long long unsigned int nanoseconds) { return nanoseconds / (1000.0 * 1000.0); }


/* #endregion */

/* #endregion */

/* #region functions*/

void printAllConstants();

/* #endregion */
#endif