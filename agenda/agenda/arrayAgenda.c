//
// Created by alvaro on 29/9/20.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrayAgenda.h"

static const int ARRAY_AGENDA_INCR = 1;

void listEntries(const AGENDA_ENTRY *entries, unsigned int entryCount);

char *getFullName(AGENDA_ENTRY *entry) {
    char *fullName = malloc(strlen(entry->name) + strlen(entry->surname) + 2);

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

void listWithComparator(ARRAY_AGENDA * agenda, void * comparator) {
    // don't want to modify the original array, so we create a new array for holding the entries' addresses
    AGENDA_ENTRY entries[agenda->entryCount];
    for (int i = 0; i < agenda->entryCount; ++i) {
        entries[i] = agenda->entries[i];
    }

    qsort(entries, agenda->entryCount, sizeof(AGENDA_ENTRY), comparator);

    listEntries(entries, agenda->entryCount);
}

int ageComparator(const void *p1, const void *p2) {
    AGENDA_ENTRY *entry1 = (AGENDA_ENTRY *) p1;
    AGENDA_ENTRY *entry2 = (AGENDA_ENTRY *) p2;

    return entry1->age - entry2->age;
}

void addEntry(ARRAY_AGENDA *agenda, const AGENDA_ENTRY entry) {
    if (agenda->entryCount == agenda->size) {
        // Agenda is full -> grow array by reallocate memory
        unsigned int newSize = agenda->size + ARRAY_AGENDA_INCR;
        agenda->entries = realloc(agenda->entries, newSize * sizeof(AGENDA_ENTRY));
        agenda->size = newSize;
    }

    agenda->entries[agenda->entryCount] = entry;
    agenda->entryCount++;
}

ARRAY_AGENDA *createArrayAgenda(int initialSize) {
    ARRAY_AGENDA *agenda = malloc(sizeof(ARRAY_AGENDA));

    agenda->size = initialSize;
    agenda->entries = (AGENDA_ENTRY *) malloc(initialSize * sizeof(AGENDA_ENTRY));
    agenda->entryCount = 0;

    return agenda;
}

void listAgendaAsIs(ARRAY_AGENDA *agenda) {
    printf("Listing agenda as entered:\n");
    listEntries(agenda->entries, agenda->entryCount);
}

void listAgendaAlphabetically(ARRAY_AGENDA *agenda) {
    printf("Listing agenda alphabetically:\n");
    listWithComparator(agenda, &fullNameComparator);
}

void listAgendaByAge(ARRAY_AGENDA *agenda) {
    printf("Listing agenda by age:\n");
    listWithComparator(agenda, &ageComparator);
}

void listEntries(const AGENDA_ENTRY *entries, unsigned int entryCount) {
    for (int i = 0; i < entryCount; i++) {
        AGENDA_ENTRY entry = entries[i];
        printf("%i - Name: %s\n\tSurname: %s\n\tID: %s\n\tAge: %hu\n", i + 1, entry.name, entry.surname, entry.id,
               entry.age);
    }
    printf("\n\n");
}