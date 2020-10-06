//
// Created by alvaro on 29/9/20.
//

#include "agendaCommon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

AGENDA_ENTRY* createAgendaEntry(char *name, char *surname, char *id, unsigned short age) {
    AGENDA_ENTRY* entry = (AGENDA_ENTRY*) malloc(sizeof(AGENDA_ENTRY));

    entry->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(entry->name, name);
    entry->surname = (char*) malloc((strlen(surname) + 1) * sizeof(char));
    strcpy(entry->surname, surname);
    entry->id = (char*) malloc((strlen(id) + 1) * sizeof(char));
    strcpy(entry->id, id);
    entry->age = age;

    return entry;
}

char *getFullName(AGENDA_ENTRY *entry) {
    size_t fullNameSize = strlen(entry->name) + strlen(entry->surname) + 2;
    char *fullName = malloc(fullNameSize);
    memset(fullName, 0, fullNameSize);

    fullName = strcat(fullName, entry->name);
    fullName = strcat(fullName, " ");
    fullName = strcat(fullName, entry->surname);

    return fullName;
}

int fullNameComparator(const void *p1, const void *p2) {
    AGENDA_ENTRY *entry1 = *(AGENDA_ENTRY **) p1;
    AGENDA_ENTRY *entry2 = *(AGENDA_ENTRY **) p2;

    return fullNameDirectComparator(entry1, entry2);
}

int fullNameDirectComparator(const void *p1, const void *p2) {
    AGENDA_ENTRY *entry1 = (AGENDA_ENTRY *) p1;
    AGENDA_ENTRY *entry2 = (AGENDA_ENTRY *) p2;

    char *fullName1 = getFullName(entry1);
    char *fullName2 = getFullName(entry2);

    int ret = strcmp(fullName1, fullName2);

    free(fullName1);
    free(fullName2);

    return ret;
}

void listEntriesWithComparator(AGENDA_ENTRY **entries, unsigned int entryCount, void * comparator) {
    qsort(entries, entryCount, sizeof(AGENDA_ENTRY*), comparator);

    listEntries(entries, entryCount);
}

int ageComparator(const void *p1, const void *p2) {
    AGENDA_ENTRY *entry1 = *(AGENDA_ENTRY **) p1;
    AGENDA_ENTRY *entry2 = *(AGENDA_ENTRY **) p2;

    return entry1->age - entry2->age;
}

void listEntries(AGENDA_ENTRY **entries, unsigned int entryCount) {
    for (unsigned int i = 0; i < entryCount; i++) {
        AGENDA_ENTRY *entry = entries[i];
        printEntry(entry, i);
    }
    printf("\n\n");
}

void printEntry(AGENDA_ENTRY *entry, unsigned int pos) {
    printf("%i - Name: %s\n\tSurname: %s\n\tID: %s\n\tAge: %hu\n", pos + 1, entry->name, entry->surname, entry->id,
           entry->age);
}

void freeAgendaEntry(AGENDA_ENTRY *entry) {
    free(entry->name);
    free(entry->surname);
    free(entry->id);
    free(entry);
}

void saveEntriesToFile(AGENDA_ENTRY **entries, unsigned int entryCount) {
    FILE *file = fopen("./data.csv", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < entryCount; ++i) {
        AGENDA_ENTRY *entry = entries[i];

        fprintf(file, "%s;%s;%s;%d\n", entry->name, entry->surname, entry->id, entry->age);
    }

    fclose(file);
}
