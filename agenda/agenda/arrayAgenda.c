//
// Created by alvaro on 29/9/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "arrayAgenda.h"

static const int ARRAY_AGENDA_INCR = 1;

void listWithComparator(ARRAY_AGENDA * agenda, void * comparator) {
    // don't want to modify the original array, so we create a new array for holding the entries' addresses
    AGENDA_ENTRY* entries[agenda->entryCount];
    for (int i = 0; i < agenda->entryCount; ++i) {
        entries[i] = agenda->entries[i];
    }

    listEntriesWithComparator(entries, agenda->size, comparator);
}

void addEntry(ARRAY_AGENDA *agenda, AGENDA_ENTRY *entry) {
    if (agenda->entryCount == agenda->size) {
        // Agenda is full -> grow array by reallocate memory
        unsigned int newSize = agenda->size + ARRAY_AGENDA_INCR;
        agenda->entries = realloc(agenda->entries, newSize * sizeof(AGENDA_ENTRY*));
        agenda->size = newSize;
    }

    agenda->entries[agenda->entryCount] = entry;
    agenda->entryCount++;
}

void removeEntryAt(ARRAY_AGENDA *agenda, unsigned int pos) {
    // pre-conditions
    if(agenda->size == 0 || pos < 0 || pos >= agenda->size){
        return;
    }

    // free the memory for the entry
    freeAgendaEntry(agenda->entries[pos]);

    for (unsigned int i = pos; i < agenda->size - 1; ++i) {
        // overwrite the entries from pos with the values one position later
        agenda->entries[i] = agenda->entries[i+1];
    }

    // remove one from the counter to avoid overstepping
    agenda->entryCount--;
}

ARRAY_AGENDA *createArrayAgenda(int initialSize) {
    ARRAY_AGENDA *agenda = malloc(sizeof(ARRAY_AGENDA));

    agenda->size = initialSize;
    agenda->entries = (AGENDA_ENTRY **) malloc(initialSize * sizeof(AGENDA_ENTRY*));
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
