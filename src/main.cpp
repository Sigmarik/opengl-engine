/**
 * @file main.cpp
 * @author Kudryashov Ilya (kudriashov.it@phystech.edu)
 * @brief Main module of the program
 * @version 0.1
 * @date 2023-07-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <unistd.h>

#include <glm/ext/matrix_transform.hpp>

#include "components/misc/rc_head.h"
#include "generation/noise.h"
#include "graphics/gl_debug.h"
#include "graphics/objects/ambient_light.h"
#include "graphics/objects/decal.h"
#include "graphics/objects/model.h"
#include "graphics/objects/point_light.h"
#include "graphics/objects/postprocessor.h"
#include "graphics/objects/scene.h"
#include "graphics/primitives/camera.h"
#include "graphics/primitives/mesh.h"
#include "graphics/primitives/render_frame.h"
#include "graphics/primitives/texture.h"
#include "io/main_io.h"
#include "lib/input/input_controller.h"
#include "logger/debug.h"
#include "logger/logger.h"
#include "logics/components/visual/static_mesh.h"
#include "logics/scene.h"
#include "managers/asset_manager.h"
#include "managers/tick_manager.h"
#include "managers/world_timer.h"
#include "scenes/pool_game.h"
#include "utils/main_utils.h"

#define MAIN

#include "config.h"

int main(const int argc, char** argv) {
    atexit(log_end_program);

    Options options;

    log_init("program_log.html", LOG_THRESHOLD, &errno);
    print_label();

    log_printf(STATUS_REPORTS, "status", "Initializing\n");

    if (argp_parse(&ARG_P, argc, argv, 0, 0, &options) != 0) {
        return EXIT_FAILURE;
    }

    GLFWwindow* window = create_window();

    poll_gl_errors();

    InputController::init(window);

    static PoolGame world;

    Camera* camera = world.get_renderer().get_viewpoint();

    if (camera != nullptr) {
        camera->set_aspect_ratio((float)WINDOW_WIDTH / (float)WINDOW_HEIGHT);
    }

    poll_gl_errors();

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    RenderBundle gbuffers(WINDOW_WIDTH, WINDOW_HEIGHT);

    poll_gl_errors();

    TickManager ticker(
        // Input
        []() { InputController::poll_events(); },

        // Physics
        [](double delta_time) { world.phys_tick(delta_time); },

        // Graphics
        [&gbuffers, window](double delta_time, double subtick_time) {
            world.draw_tick(delta_time, subtick_time);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            world.get_renderer().render(gbuffers);

            poll_gl_errors();

            glfwSwapBuffers(window);
        });

    log_printf(STATUS_REPORTS, "status", "Entering the loop.\n");
    GameLoop::run(ticker, [window]() { return glfwWindowShouldClose(window); });

    poll_gl_errors();

    glfwTerminate();

    return errno == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
