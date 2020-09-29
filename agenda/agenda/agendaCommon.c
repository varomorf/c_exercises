//
// Created by alvaro on 29/9/20.
//

#include "agendaCommon.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

AGENDA_ENTRY createAgendaEntry(char *name, char *surname, char *id, unsigned short age) {
    AGENDA_ENTRY entry;

    entry.name = name;
    entry.surname = surname;
    entry.id = id;
    entry.age = age;

    return entry;
}

char *getFullName(AGENDA_ENTRY *entry) {
    char *fullName = malloc(strlen(entry->name) + strlen(entry->surname) + 2);
    fullName[0] = '\0';

    fullName = strcat(fullName, entry->name);
    fullName = strcat(fullName, " ");
    fullName = strcat(fullName, entry->surname);
    fullName = strcat(fullName, "\0");

    return fullName;
}

int fullNameComparator(const void *p1, const void *p2) {
    AGENDA_ENTRY *entry1 = (AGENDA_ENTRY *) p1;
    AGENDA_ENTRY *entry2 = (AGENDA_ENTRY *) p2;

    char *fullName1 = getFullName(entry1);
    char *fullName2 = getFullName(entry2);

    int ret = strcmp(fullName1, fullName2);

    free(fullName1);
    free(fullName2);

    return ret;
}

void listEntriesWithComparator(AGENDA_ENTRY * entries, unsigned int entryCount, void * comparator) {
    qsort(entries, entryCount, sizeof(AGENDA_ENTRY), comparator);

    listEntries(entries, entryCount);
}

int ageComparator(const void *p1, const void *p2) {
    AGENDA_ENTRY *entry1 = (AGENDA_ENTRY *) p1;
    AGENDA_ENTRY *entry2 = (AGENDA_ENTRY *) p2;

    return entry1->age - entry2->age;
}

void listEntries(const AGENDA_ENTRY *entries, unsigned int entryCount) {
    for (int i = 0; i < entryCount; i++) {
        AGENDA_ENTRY entry = entries[i];
        printf("%i - Name: %s\n\tSurname: %s\n\tID: %s\n\tAge: %hu\n", i + 1, entry.name, entry.surname, entry.id,
               entry.age);
    }
    printf("\n\n");
}