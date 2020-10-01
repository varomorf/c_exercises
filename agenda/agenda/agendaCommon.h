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

void printEntry(AGENDA_ENTRY *entry, unsigned int pos);

AGENDA_ENTRY* createAgendaEntry(char *name, char *surname, char *id, unsigned short age);
void listEntries(AGENDA_ENTRY **entries, unsigned int entryCount);
void listEntriesWithComparator(AGENDA_ENTRY **entries, unsigned int entryCount, void * comparator);

char *getFullName(AGENDA_ENTRY *entry);
int fullNameDirectComparator(const void *p1, const void *p2);
int fullNameComparator(const void *p1, const void *p2);
int ageComparator(const void *p1, const void *p2);

#endif //AGENDA_AGENDACOMMON_H
