cmake_minimum_required(VERSION 3.11)
project (nuklear_base16
    VERSION 0.0.1
    DESCRIPTION "Base16 Color Styles for Nuklear"
    HOMEPAGE_URL "https://github.com/robloach/nuklear_base16"
    LANGUAGES C
)

add_library(nuklear_base16 INTERFACE)
target_include_directories(nuklear_base16 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
