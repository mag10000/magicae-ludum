#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "game_types.h"

// Externally-defined function to create a game.
extern b8 create_game(game* out_game);

/**
 * The main entry point of the application.
 */
int main(void) {

    // Request the game instance from the application.
    game game_inst;
    if (!create_game(&game_inst)) {
        KFATAL("Could not create game!");
        return -1;
    }

    // Ensure the function pointers exist.
    if (!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        KFATAL("The game's function pointers must be assigned!");
        return -2;
    }

    // Video: https://www.youtube.com/watch?v=jEbqCf-MsZs&list=PLv8Ddw9K0JPg1BEO-RS-0MYs423cvLVtj&index=8
    // Timestamp : 32:17
    // Commit : https://github.com/travisvroman/kohi/commit/24e2a8a09314969464931cbdb2840b4677f8dee3#diff-acf2b772f2fcba16a166c4da48913db9d9243fe40eae4321d9670a5a7b12bbc0

    application_create(&config);

    application_run();

    // Application configuration.
    application_config config;
    config.start_pos_x = 100;
    config.start_pos_y = 100;
    config.start_width = 1280;
    config.start_height = 720;
    config.name = "Magicae Ludum Engine";

    return 0;
}