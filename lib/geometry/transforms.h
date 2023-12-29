/**
 * @file transforms.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Geometrical transforms
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __GEOMETRY_TRANSFORMS_H
#define __GEOMETRY_TRANSFORMS_H

#include <glm/vec3.hpp>

glm::vec3 reflect_plane(const glm::vec3& vector, const glm::vec3& normal);

#endif
