/**
 * @file external_level.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Importable level class
 * @version 0.1
 * @date 2024-04-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <glm/mat4x4.hpp>

#include "component_factory.hpp"
#include "scripts/script.h"

struct ExternalLevel final {
    using Factory = ComponentFactory<const glm::mat4&>;

    ExternalLevel(const Factory& factory, const std::vector<Script>& scripts)
        : factory_(factory), scripts_(scripts) {}

    SubcomponentNameMap build(Scene& scene, const glm::mat4& transform) const;

   private:
    Factory factory_;

    std::vector<Script> scripts_;
};
