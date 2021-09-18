set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )

add_library(qcgaugewidget SHARED
        include/qcswitchwidget.h
        src/qcswitchwidget.cpp
        )

target_include_directories(qcgaugewidget
        PUBLIC
        include
        PRIVATE
        include/qcgaugewidget
        )

target_compile_definitions(qcgaugewidget
        PRIVATE
        QGV_EXPORT
        )

target_link_libraries(qcgaugewidget
        PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

add_library(QcGaugeWidget ALIAS qcgaugewidget)

install(TARGETS qcgaugewidget LIBRARY
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
        )
