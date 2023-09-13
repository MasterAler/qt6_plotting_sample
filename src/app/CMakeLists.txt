set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

qt_add_executable (qt6_plotting_sample
    main.cpp
    MainWidget.cpp
    MainWidget.h
    MainWidget.ui
    DataGenerator.h
    DataGenerator.cpp
)

set_target_properties(qt6_plotting_sample PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

target_link_libraries(qt6_plotting_sample PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
