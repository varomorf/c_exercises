#include <stdio.h>
#include "agenda/arrayAgenda.h"
#include "agenda/linkedListAgenda.h"

void executeForArray();

void executeForList();

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

    printf("**** ARRAY VERSION ****\n\n");
    executeForArray();
    printf("**** LINKED LIST VERSION ****\n\n");
    executeForList();

    return 0;
}

void executeForArray() {
    ARRAY_AGENDA *agenda = createArrayAgenda(2);

    addEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    addEntry(agenda, createAgendaEntry("Sara", "Zapico Fernández", "12345679A", 33));
    addEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    addEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));

    listAgendaAsIs(agenda);
    listAgendaAlphabetically(agenda);
    listAgendaByAge(agenda);

    removeEntryAt(agenda, 2);
    listAgendaAsIs(agenda);
    addEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    listAgendaAsIs(agenda);
}

void executeForList() {
    LIST_AGENDA *agenda = createLinkedListAgenda();

    addListEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    addListEntry(agenda, createAgendaEntry("Sara", "Zapico Fernández", "12345679A", 33));
    addListEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    addListEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));

    listListAgendaAsIs(agenda);
    listListAgendaAlphabetically(agenda);
    listListAgendaByAge(agenda);

    printf("Removal tests *****\n\n");

    removeListEntryAt(agenda, 3);
    listListAgendaAsIs(agenda);
    addListEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));
    listListAgendaAsIs(agenda);
    removeListEntryAt(agenda, 2);
    listListAgendaAsIs(agenda);
    addListEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    listListAgendaAsIs(agenda);
    removeListEntryAt(agenda, 0);
    listListAgendaAsIs(agenda);
    addListEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    listListAgendaAsIs(agenda);
}
