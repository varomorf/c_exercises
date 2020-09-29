#include <stdio.h>
#include "agenda/arrayAgenda.h"

/*
 * [14:45, 29/9/2020] Pablo Zapiens: A ver q casi me pasa, que te parece facer en C un programilla de agenda.
 * Para hacerlo simple, los contactos tienen nombre apellido DNI y edad.
 * Tienes q almacenarlos de tres formas distintas: en un array dinámico, en una lista enlazada y en un árbol binario.
 * Si quieres que los datos persistan en disco, wai. Así al arrancar se puede leer de un fichero.
 * Si no na, q te permita meter contactos en consola y te pregunte de qué forma los quieres almacenar en memoria (array lista o árbol)
 * [14:46, 29/9/2020] Pablo Zapiens: Y luego q te dejé sacar listados, alfabéticos y por edad por ejemplo
 *
 */

int main() {
    printf("Hello and welcome to Zapienda! The \"AI-powered\" agenda.\n\n");

    ARRAY_AGENDA *agenda = createArrayAgenda(2);

    addEntry(agenda, createAgendaEntry("Alvaro", "Fernández González", "12345678A", 35));
    addEntry(agenda, createAgendaEntry("Sara", "Zapico Fernández", "12345679A", 33));
    addEntry(agenda, createAgendaEntry("Pablo", "Bravo", "12345680A", 42));
    addEntry(agenda, createAgendaEntry("Migui", "The cat", "12345681A", 1));

    listAgendaAsIs(agenda);
    listAgendaAlphabetically(agenda);
    listAgendaByAge(agenda);

    return 0;
}
