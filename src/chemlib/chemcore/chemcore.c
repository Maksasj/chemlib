#include "chemcore.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const AtomRecord atomRegistry[2] = {
    [HYDROGEN] = {
        .name = "hydrogen",
        .symbol = "H",
        .atom = {
            .element = HYDROGEN,
            .mass = 0.0,
            .charge = 1.0
        }
    },
    [OXYGEN] = {
        .name = "oxygen",
        .symbol = "O",
        .atom = {
                .element = OXYGEN,
                .mass = 0.0,
                .charge = 1.0
        }
    }
};

Atom* chemlib_create_atom(Element element) {
    Atom* atom = (Atom*) malloc(sizeof(Atom));

    *atom = atomRegistry[element].atom;

    return atom;
}

AtomStack* chemlib_create_atom_stack(Element element, unsigned int count) {
    AtomStack* stack = (AtomStack*) malloc(sizeof(AtomStack));

    stack->atom = atomRegistry[element].atom;
    stack->count = count;

    return stack;
}

void chemlib_free_atom(Atom* atom) {
    free(atom);
}
void chemlib_free_atom_stack(AtomStack* stack) {
    free(stack);
}

char* chemlib_stringify_atom(Atom* atom) {
    const AtomRecord* record = &atomRegistry[atom->element];

    char* string = (char*) malloc(strlen(record->symbol) + 1);
    strcpy(string, record->symbol);

    return string;
}

char* chemlib_stringify_atom_stack(AtomStack* stack) {
    if(stack->count <= 1)
        return chemlib_stringify_atom(&stack->atom);

    const AtomRecord* record = &atomRegistry[stack->atom.element];

    unsigned int length = strlen(record->symbol) + 1;

    char number[11] = { '\0' };
    sprintf(number, "%u", stack->count);
    length += strlen(number);

    char* string = (char*) malloc(length);

    strcpy(string, record->symbol);
    strcat(string, number);

    return string;
}