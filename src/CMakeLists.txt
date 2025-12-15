add_library(app OBJECT)

target_sources(app PRIVATE 
    main.cpp
    init.cpp
    display.cpp
    spi.cpp
    interrupt.cpp
)

target_include_directories(app PRIVATE
    ${PROJECT_SOURCE_DIR}/vendor/
)