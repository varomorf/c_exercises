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

void removeListEntryAt(LIST_AGENDA *agenda, unsigned int pos) {
    // pre-conditions
    if (agenda->size == 0 || pos < 0 || pos >= agenda->size) {
        return;
    }

    LIST_AGENDA_NODE *nodeToDelete;
    if (pos == 0) {
        //special case when deleting the head node
        nodeToDelete = agenda->head;
        agenda->head = agenda->head->next;
    } else {
        // iterate over the list to find the node previous to the node being deleted
        LIST_AGENDA_NODE *iterator = agenda->head;
        for (unsigned int i = 1; i < pos; ++i) {
            iterator = iterator->next;
        }

        nodeToDelete = iterator->next;
        //special case when deleting the last node (we need to move the last pointer to the previous node)
        if (pos == agenda->size - 1) {
            agenda->last = iterator;
            iterator->next = NULL;
        } else {
            // point the next to the next next (which will make the node to be deleted parent-less)
            iterator->next = nodeToDelete->next;
        }
    }

    free(nodeToDelete);
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
