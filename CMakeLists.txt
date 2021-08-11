cmake_minimum_required(VERSION 3.19)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        ./SRCS_MAN/main.c
        ./SRCS_MAN/push_swap.h ./SRCS_MAN/push_swap.c
        ./SRCS_MAN/sorting.c ./SRCS_MAN/lets_sort.c
        ./SRCS_MAN/stack_ops_single.c ./SRCS_MAN/stack_ops_double.c
        ./SRCS_MAN/stacks_print.c ./SRCS_MAN/modes.c
        ./SRCS_MAN/find.c)

include_directories(libft)

add_executable(push_swap ${SOURCE_FILES})

add_subdirectory(libft)

target_link_libraries(push_swap libft)