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

#ifndef HELIOS_SPHERE_H
#define HELIOS_SPHERE_H

#include "drawable.h"

class Sphere : public Drawable {
protected:
    float radius = 0;

public:
    Sphere() = default;

    Sphere(const Vec3 &position, double radius) : Drawable(position), radius(radius)
    { };

    bool intersect(const Ray &ray, HitPoint *hit_point);
};

#endif //HELIOS_SPHERE_H
