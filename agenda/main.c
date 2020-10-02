#include <stdio.h>
#include <stdlib.h>
#include "agenda/arrayAgenda.h"
#include "agenda/linkedListAgenda.h"
#include "agenda/treeAgenda.h"
#include "utils/utils.h"

#define ADD_ENTRY 1
#define REMOVE_ENTRY 2
#define LIST_ALPHABETICALLY 3
#define LIST_BY_AGE 4
#define EXIT 5

int executeForArray();

int executeForList();

int executeForTree();

int getOption();

AGENDA_ENTRY *getAgendaEntryFromUser();

char *getFullNameFromUser();

void removeEntryFromArrayAgenda(ARRAY_AGENDA *agenda);

void removeEntryFromListAgenda(LIST_AGENDA *agenda);

void removeEntryFromTreeAgenda(TREE_AGENDA *agenda);

/*
 * A ver q casi me pasa, que te parece facer en C un programilla de agenda.
 * Para hacerlo simple, los contactos tienen nombre apellido DNI y edad.
 * Tienes q almacenarlos de tres formas distintas: en un array dinámico, en una lista enlazada y en un árbol binario.
 * Si quieres que los datos persistan en disco, wai. Así al arrancar se puede leer de un fichero.
 * Si no na, q te permita meter contactos en consola y te pregunte de qué forma los quieres almacenar en memoria (array lista o árbol)
 * Y luego q te dejé sacar listados, alfabéticos y por edad por ejemplo
 *
 */

int main() {
    printf("Hello and welcome to Zapienda! The \"AI-powered\" agenda.\n\n");
    printf("Which version of the agenda do you want to test out?\n");
    printf("1 - Dynamic array\n");
    printf("2 - Linked list\n");
    printf("3 - Binary tree\n");

    int option = readIntFromStdin();

    switch (option) {
        case 1:
            return executeForArray();
        case 2:
            return executeForList();
        case 3:
            return executeForTree();
        default:
            printf("Wrong option");
            return 1;
    }
}

int executeForArray() {
    printf("**** ARRAY VERSION ****\n\n");
    ARRAY_AGENDA *agenda = createArrayAgenda(2);

    // pre-made data
    addEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    addEntry(agenda, createAgendaEntry("Sara", "Zapico Fernández", "12345679A", 33));
    addEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    addEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));

    int option = getOption();
    while (option != EXIT) {
        switch (option) {
            case ADD_ENTRY:
                addEntry(agenda, getAgendaEntryFromUser());
                break;
            case REMOVE_ENTRY:
                removeEntryFromArrayAgenda(agenda);
                break;
            case LIST_ALPHABETICALLY:
                listAgendaAlphabetically(agenda);
                break;
            case LIST_BY_AGE:
                listAgendaByAge(agenda);
                break;
            default:
                printf("Wrong option");
                return 1;
        }

        option = getOption();
    }

    return 0;
}

int executeForList() {
    printf("**** LINKED LIST VERSION ****\n\n");
    LIST_AGENDA *agenda = createLinkedListAgenda();

    // pre-made data
    addListEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    addListEntry(agenda, createAgendaEntry("Sara", "Zapico Fernández", "12345679A", 33));
    addListEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    addListEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));

    int option = getOption();
    while (option != EXIT) {
        switch (option) {
            case ADD_ENTRY:
                addListEntry(agenda, getAgendaEntryFromUser());
                break;
            case REMOVE_ENTRY:
                removeEntryFromListAgenda(agenda);
                break;
            case LIST_ALPHABETICALLY:
                listListAgendaAlphabetically(agenda);
                break;
            case LIST_BY_AGE:
                listListAgendaByAge(agenda);
                break;
            default:
                printf("Wrong option");
                return 1;
        }

        option = getOption();
    }

    return 0;
}

int executeForTree() {
    printf("**** TREE VERSION ****\n\n");
    TREE_AGENDA *agenda = createTreeAgenda();

    // pre-made data
    addTreeEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    addTreeEntry(agenda, createAgendaEntry("Sara", "Zapico Fernández", "12345679A", 33));
    addTreeEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    addTreeEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));

    int option = getOption();
    while (option != EXIT) {
        switch (option) {
            case ADD_ENTRY:
                addTreeEntry(agenda, getAgendaEntryFromUser());
                break;
            case REMOVE_ENTRY:
                removeEntryFromTreeAgenda(agenda);
                break;
            case LIST_ALPHABETICALLY:
                listTreeAgendaAlphabetically(agenda);
                break;
            case LIST_BY_AGE:
                listTreeAgendaByAge(agenda);
                break;
            default:
                printf("Wrong option");
                return 1;
        }

        option = getOption();
    }

    return 0;
}

void removeEntryFromArrayAgenda(ARRAY_AGENDA *agenda) {
    char *fullNameToRemove = getFullNameFromUser();
    removeEntry(agenda, fullNameToRemove);
    free(fullNameToRemove);
}

void removeEntryFromListAgenda(LIST_AGENDA *agenda) {
    char *fullNameToRemove = getFullNameFromUser();
    removeListEntry(agenda, fullNameToRemove);
    free(fullNameToRemove);
}

void removeEntryFromTreeAgenda(TREE_AGENDA *agenda) {
    char *fullNameToRemove = getFullNameFromUser();
    removeTreeEntry(agenda, fullNameToRemove);
    free(fullNameToRemove);
}

int getOption() {
    printf("Choose an action:\n");
    printf("%d - Add entry\n", ADD_ENTRY);
    printf("%d - Remove entry\n", REMOVE_ENTRY);
    printf("%d - List all entries by name\n", LIST_ALPHABETICALLY);
    printf("%d - List all entries by age\n", LIST_BY_AGE);
    printf("\n");
    printf("%d - EXIT\n", EXIT);

    return readIntFromStdin();
}

AGENDA_ENTRY *getAgendaEntryFromUser() {
    char *nameBuffer, *surnameBuffer, *idBuffer;
    int age;
    printf("Give me the name:\n");
    nameBuffer = readStringFromStdin();
    printf("Give me the surname:\n");
    surnameBuffer = readStringFromStdin();
    printf("Give me the ID:\n");
    idBuffer = readStringFromStdin();
    printf("Give me the age:\n");
    age = readIntFromStdin();

    AGENDA_ENTRY *newEntry = createAgendaEntry(nameBuffer, surnameBuffer, idBuffer, age);

    free(nameBuffer);
    free(surnameBuffer);
    free(idBuffer);

    return newEntry;
}

char *getFullNameFromUser() {
    printf("Enter full name:\n");

    return readStringFromStdin();
}
