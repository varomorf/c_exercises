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
void listEntries(const AGENDA_ENTRY *entries, unsigned int entryCount);
void listEntriesWithComparator(AGENDA_ENTRY * entries, unsigned int entryCount, void * comparator);

int fullNameComparator(const void *p1, const void *p2);
int ageComparator(const void *p1, const void *p2);

#endif //AGENDA_AGENDACOMMON_H
