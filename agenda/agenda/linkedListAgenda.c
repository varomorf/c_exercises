//
// Created by alvaro on 29/9/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "linkedListAgenda.h"

LIST_AGENDA *createLinkedListAgenda() {
    LIST_AGENDA *agenda = malloc(sizeof(LIST_AGENDA));

    agenda->head = NULL;
    agenda->size = 0;

    return agenda;
}

void addListEntry(LIST_AGENDA *agenda, AGENDA_ENTRY entry) {
    LIST_AGENDA_NODE *node = malloc(sizeof(LIST_AGENDA_NODE));

    node->entry = entry;
    node->next = NULL;

    if (agenda->head == NULL) {
        // there are no entries on the agenda
        agenda->head = node;
        agenda->last = node;
    } else {
        // there are at least one entry
        agenda->last->next = node;
        agenda->last = node;
    }

    agenda->size++;
}

void listListAgendaAsIs(LIST_AGENDA *agenda) {
    printf("Listing agenda as entered:\n");
    LIST_AGENDA_NODE *iterator = agenda->head;

    unsigned int count = 1;
    while (iterator != NULL) {
        AGENDA_ENTRY entry = iterator->entry;
        printf("%i - Name: %s\n\tSurname: %s\n\tID: %s\n\tAge: %hu\n", count, entry.name, entry.surname, entry.id,
               entry.age);

        iterator = iterator->next;
        count++;
    }

    printf("\n\n");
}

AGENDA_ENTRY *getListEntries(LIST_AGENDA *agenda) {
    if (agenda->size == 0) {
        return NULL;
    }

    AGENDA_ENTRY *entries = malloc(agenda->size * sizeof(AGENDA_ENTRY));

    LIST_AGENDA_NODE *current = agenda->head;
    entries[0] = current->entry;
    for (int i = 1; i < agenda->size; ++i) {
        current = current->next;
        entries[i] = current->entry;
    }

    return entries;
}

void listListAgendaAlphabetically(LIST_AGENDA *agenda) {
    printf("Listing agenda alphabetically:\n");

    AGENDA_ENTRY *entries = getListEntries(agenda);
    if (entries == NULL) {
        return;
    }

    listEntriesWithComparator(entries, agenda->size, &fullNameComparator);
}

void listListAgendaByAge(LIST_AGENDA *agenda) {
    printf("Listing agenda by age:\n");

    AGENDA_ENTRY *entries = getListEntries(agenda);
    if (entries == NULL) {
        return;
    }

    listEntriesWithComparator(entries, agenda->size, &ageComparator);
}
