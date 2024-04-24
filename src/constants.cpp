// Author: Konstantin Winkel

// own includes
#include "constants.h"

// cpp includes
#include <iostream>

void printAllConstants() {
    std::cout << "DEG2RAD: " << DEG2RAD << " rad deg^-1" << std::endl;
    std::cout << "RAD2DEG: " << RAD2DEG << " deg rad^-1" << std::endl;
    std::cout << "G_STAR: " << G_STAR << "m^3 kg^-1 s^-2" << std::endl;
    std::cout << "M_EARTH: " << M_EARTH << " kg" << std::endl;
    std::cout << "MU_EARTH: " << MU_EARTH << " kg^3 s^-2" << std::endl;
    std::cout << "R_EARTH: " << R_EARTH << " m" << std::endl;
    std::cout << "ASTRONOMICAL_UNIT: " << ASTRONOMICAL_UNIT << " m" << std::endl;
    std::cout << "LIGHT_SPEED: " << LIGHT_SPEED << " m s^-1" << std::endl;
}