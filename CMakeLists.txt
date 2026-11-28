cmake_minimum_required(VERSION 3.11)
project (nuklear_tinted
    VERSION 0.0.1
    DESCRIPTION "Tinted Theming Base16, Base24 and Tinted8 Color Styles for Nuklear"
    HOMEPAGE_URL "https://github.com/robloach/nuklear_tinted"
    LANGUAGES C
)

add_library(nuklear_tinted INTERFACE)
target_include_directories(nuklear_tinted INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
