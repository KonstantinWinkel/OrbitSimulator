// Author: Konstantin Winkel

#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

// cpp includes
#include <math.h>

const long double DEG2RAD = M_PI / 180.0;

const long double RAD2DEG = 180.0 / M_PI;

const long double G_STAR  = 6.67430e-11; // m^3 kg^-1 s^-2

const long double M_EARTH = 5.9722e24; //kg

const long double MU_EARTH = 3.986004415e14; // kg^3 s^-2

const long double R_EARTH = 6378000; // m

void printAllConstants();

#endif