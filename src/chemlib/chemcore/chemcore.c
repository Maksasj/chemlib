#include "chemcore.h"

AtomRecord atomRegistry[2] = {
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

Atom chemlib_create_atom(Element element) {
    return atomRegistry[element].atom;
}

AtomStack chemlib_create_atom_stack(Element element, unsigned int count) {
    AtomStack stack = {
        .atom = chemlib_create_atom(element),
        .count = count
    };

    return stack;
}
