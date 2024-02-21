#include "test_shared.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    TEST_CASE {
        Atom* atom = chemlib_parse_atom("=");

        ensure(atom == NULL);
    }

    TEST_CASE {
        Atom* atom = chemlib_parse_atom("000000");

        ensure(atom == NULL);
    }

    TEST_CASE {
        Atom* atom = chemlib_parse_atom("HHHHHHH");

        ensure(atom == NULL);
    }

    TEST_CASE {
        Atom* atom = chemlib_parse_atom("Hz");

        ensure(atom == NULL);
    }

    TEST_CASE {
        Atom* atom = chemlib_parse_atom("H");

        ensure(atom->element == HYDROGEN);
        ensure(atom->mass == 0.0);
        ensure(atom->charge == 1.0);

        chemlib_free_atom(atom);
    }

    TEST_CASE {
        Atom* atom = chemlib_parse_atom("O");

        ensure(atom->element == OXYGEN);
        ensure(atom->mass == 0.0);
        ensure(atom->charge == 1.0);

        chemlib_free_atom(atom);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("H2");

        ensure(stack != NULL);

        ensure(stack->atom.element == HYDROGEN);
        ensure(stack->count == 2);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("H4294967295");

        ensure(stack != NULL);

        ensure(stack->atom.element == HYDROGEN);
        ensure(stack->count == 4294967295);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("O16");

        ensure(stack != NULL);

        ensure(stack->atom.element == OXYGEN);
        ensure(stack->count == 16);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("He16");

        ensure(stack != NULL);

        ensure(stack->atom.element == HELIUM);
        ensure(stack->count == 16);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("He");

        ensure(stack != NULL);

        ensure(stack->atom.element == HELIUM);
        ensure(stack->count == 1);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("H");

        ensure(stack != NULL);

        ensure(stack->atom.element == HYDROGEN);
        ensure(stack->count == 1);

        chemlib_free_atom_stack(stack);
    }

    TEST_CASE {
        AtomStack* stack = chemlib_parse_atom_stack("O2");

        ensure(stack != NULL);

        ensure(stack->atom.element == OXYGEN);
        ensure(stack->count == 2);

        chemlib_free_atom_stack(stack);
    }

    return 0;
}