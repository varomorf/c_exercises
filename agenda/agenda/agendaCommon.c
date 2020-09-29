//
// Created by alvaro on 29/9/20.
//

#include "agendaCommon.h"

AGENDA_ENTRY createAgendaEntry(char *name, char *surname, char *id, unsigned short age) {
    AGENDA_ENTRY entry;

    entry.name = name;
    entry.surname = surname;
    entry.id = id;
    entry.age = age;

    return entry;
}