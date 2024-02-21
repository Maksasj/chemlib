#include "test_shared.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    TEST_CASE {
        Atom* atom = chemlib_create_atom(HYDROGEN);

        ensure(atom->element == HYDROGEN);
        ensure(atom->mass == 0.0);
        ensure(atom->charge == 1.0);

        chemlib_free_atom(atom);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_create_atom_stack(HYDROGEN, 2);

        ensure(stack->count == 2);

        ensure(stack->atom.element == HYDROGEN);
        ensure(stack->atom.mass == 0.0);
        ensure(stack->atom.charge == 1.0);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        Atom* atom = chemlib_create_atom(HYDROGEN);

        char* string = chemlib_stringify_atom(atom);

        ensure(strcmp(string, "H") == 0);

        free(string);
        chemlib_free_atom(atom);
    }

    TEST_CASE {
        Atom* atom = chemlib_create_atom(OXYGEN);

        char* string = chemlib_stringify_atom(atom);

        ensure(strcmp(string, "O") == 0);

        free(string);
        chemlib_free_atom(atom);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_create_atom_stack(HYDROGEN, 2);

        char* string = chemlib_stringify_atom_stack(stack);

        ensure(strcmp(string, "H2") == 0);

        free(string);
        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_create_atom_stack(OXYGEN, 512);

        char* string = chemlib_stringify_atom_stack(stack);

        ensure(strcmp(string, "O512") == 0);

        free(string);
        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_create_atom_stack(HYDROGEN, 4294967295);

        char* string = chemlib_stringify_atom_stack(stack);

        ensure(strcmp(string, "H4294967295") == 0);

        free(string);
        chemlib_free_atom_stack(stack);
    }

    return 0;
}