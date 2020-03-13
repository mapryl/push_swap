cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(libft/includes)
include_directories(includes)

add_executable(push_swap
        sources/insertion_sort.c
        sources/operation_list.c
        sources/parse.c
        sources/sort_utils.c
        sources/stack1.c
        sources/stack2.c
        sources/stack_insertion_sort_utils1.c
        sources/stack_insertion_sort_utils2.c
        sources/stack_sort.c
        sources/stack_sort3.c
        sources/stack_split.c
        sources/two_stacks_1.c
        sources/two_stacks_2.c
        sources/two_stacks_3.c
        sources/two_stacks_4.c
        sources/utils1.c
        sources/utils2.c
        sources/utils3.c
        sources/vector.c
        libft/sources/ft_putstr.c
        libft/sources/ft_strlen.c
        libft/sources/ft_putchar.c
        libft/sources/ft_putnbr.c
        libft/sources/ft_strcmp.c
        libft/sources/get_next_line.c
        libft/sources/ft_strnew.c
        libft/sources/ft_strjoin.c
        libft/sources/ft_strchr.c
        libft/sources/ft_strdup.c
        libft/sources/ft_memdel.c
        libft/sources/ft_bzero.c
        sources/push_swap.c
        libft/sources/ft_atoi.c
        libft/sources/ft_isdigit.c
        libft/sources/ft_isspace.c
        #sources/checker.c
        )
