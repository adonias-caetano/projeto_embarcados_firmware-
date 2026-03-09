idf_component_register(
    SRCS "main.c"
    INCLUDE_DIRS "."
    REQUIRES config_system sensors control display storage serial_cmd
)
