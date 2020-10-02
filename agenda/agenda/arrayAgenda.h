//
// Created by alvaro on 29/9/20.
//

#ifndef AGENDA_ARRAYAGENDA_H
#define AGENDA_ARRAYAGENDA_H

#include "agendaCommon.h"

typedef struct ARRAY_AGENDA {
    AGENDA_ENTRY **entries;
    unsigned int size;
    unsigned int entryCount;
} ARRAY_AGENDA;

void addEntry(ARRAY_AGENDA *agenda, AGENDA_ENTRY *entry);
void removeEntry(ARRAY_AGENDA *agenda, char *fullNameToRemove);

ARRAY_AGENDA* createArrayAgenda(int initialSize);

void listAgendaAlphabetically(ARRAY_AGENDA *agenda);
void listAgendaByAge(ARRAY_AGENDA *agenda);

#endif //AGENDA_ARRAYAGENDA_H
