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

#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif

#include <math.h>
#include "camera.h"


void Camera::set_target(const Vec3 &target)
{
    this->target = target;
}

const Vec3 &Camera::get_target() const
{
    return target;
}

void Camera::set_fov(float fov, CameraFovType fov_type)
{
    switch (fov_type) {
        case CAM_FOV_RADIANS:
            this->fov = fov;
            break;
        case CAM_FOV_DEGREES:
            this->fov = (float) M_PI * fov / 180.0f;
    }
}

float Camera::get_fov() const
{
    return fov;
}


void Camera::calculate_transformation()
{
    Vec3 camera_dir = target - position;

    camera_dir.normalize();

    /**
     * Assume the up camera vector points towards the positive y axis.
     */
    Vec3 up(0.0f, 1.0f, 0.0f);
    Vec3 right = cross(up, camera_dir);
    right.normalize();

    /**
     * Compute the actual up vector.
     */
    up = cross(camera_dir, right);
    up.normalize();

    /**
     * Create the correct camera matrix.
     */
    transformation = Mat4(right.x, up.x, camera_dir.x, 0,
                          right.y, up.y, camera_dir.y, 0,
                          right.z, up.z, camera_dir.z, 0,
                          0.0f   , 0.0f,    0.0f     , 1);

    Mat4 translation;
    translation.set_column_vector(position.x, position.y, position.z, 1.0f, 3);

    transformation = translation * transformation;
}

const Mat4 &Camera::get_transformation_matrix() const
{
    return transformation;
}
