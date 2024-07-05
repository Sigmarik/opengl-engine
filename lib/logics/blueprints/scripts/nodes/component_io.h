/**
 * @file component_io.h
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Nodes for component interaction.
 * @version 0.1
 * @date 2024-06-08
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include <memory>

#include "logics/blueprints/scripts/node.h"

namespace nodes {

struct OutputMethod : public Script::Node {
    OutputMethod(ChildReference object, ChildReference method);

    virtual bool refresh(Node*) override;

   private:
    ChildReference object_;
    ChildReference method_;

    SceneComponent::Channel::Listener update_listener_{};
};

struct InputMethod : public Script::Node {
    InputMethod(ChildReference object, ChildReference method,
                ChildReference value);

    virtual bool refresh(Node* initiator) override;

   private:
    ChildReference object_;
    ChildReference method_;
    ChildReference value_;

    SceneComponent::Channel output_;
}

};  // namespace nodes