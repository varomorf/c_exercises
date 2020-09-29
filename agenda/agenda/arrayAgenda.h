//
// Created by alvaro on 29/9/20.
//

#ifndef AGENDA_ARRAYAGENDA_H
#define AGENDA_ARRAYAGENDA_H

typedef struct AgendaEntry {
    char *name;
    char *surname;
    char *id;
    unsigned short age;
} AGENDA_ENTRY;

typedef struct ARRAY_AGENDA {
    AGENDA_ENTRY *entries;
    unsigned int size;
    unsigned int entryCount;
} ARRAY_AGENDA;

AGENDA_ENTRY createAgendaEntry(char *name, char *surname, char *id, unsigned short age);

void addEntry(ARRAY_AGENDA *agenda, AGENDA_ENTRY entry);

ARRAY_AGENDA* createArrayAgenda(int initialSize);

void listAgendaAsIs(ARRAY_AGENDA *agenda);
void listAgendaAlphabetically(ARRAY_AGENDA *agenda);
void listAgendaByAge(ARRAY_AGENDA *agenda);

#endif //AGENDA_ARRAYAGENDA_H
