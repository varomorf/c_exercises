cmake_minimum_required(VERSION 3.17)
project(agenda C)

set(CMAKE_C_STANDARD 99)

add_executable(agenda main.c agenda/arrayAgenda.h agenda/arrayAgenda.c agenda/linkedListAgenda.c agenda/linkedListAgenda.h agenda/agendaCommon.h agenda/agendaCommon.c agenda/treeAgenda.h agenda/treeAgenda.c)