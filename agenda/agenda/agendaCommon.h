//
// Created by alvaro on 29/9/20.
//

#ifndef AGENDA_AGENDACOMMON_H
#define AGENDA_AGENDACOMMON_H

typedef struct AgendaEntry {
    char *name;
    char *surname;
    char *id;
    unsigned short age;
} AGENDA_ENTRY;

AGENDA_ENTRY createAgendaEntry(char *name, char *surname, char *id, unsigned short age);

#endif //AGENDA_AGENDACOMMON_H
