/*
Helios-Ray - A powerful and highly configurable renderer
Copyright (C) 2016  Angelos Gkountis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HELIOS_UTILS_H
#define HELIOS_UTILS_H

#include <scene.h>

class Utils {
public:
    Utils() = delete;

    static void generate_sphere_flake(Scene * sc, const Material &mat, const Vec3 &pos, float radius, float scale, int iter);
};

#endif //HELIOS_UTILS_H
