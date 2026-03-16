#include <core/logger.h>
#include <core/asserts.h>

// TODO: test
# include <core/application.h>

int main(void) {
    // Application configuration.
    application_config config;
    config.start_pos_x = 100;
    config.start_pos_y = 100;
    config.start_width = 1280;
    config.start_height = 720;
    config.name = "Magicae Ludum Engine Testbed";

    application_create(&config);

    application_run();

    return 0;
}