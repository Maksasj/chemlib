#ifndef _CHEMCORE_H_
#define _CHEMCORE_H_


typedef enum Element {
    HYDROGEN = 0,
    HELIUM = 1,
    OXYGEN = 2
} Element;

typedef struct Atom {
    Element element;

    double mass;
    double charge;
} Atom;

typedef struct AtomRecord {
    const char* name;
    const char* symbol;
    const Atom atom;
} AtomRecord;

typedef struct AtomStack {
    Atom atom;
    unsigned int count;
} AtomStack;

#define CHEMLIB_ATOM_REGISTRY_SIZE 3
extern const AtomRecord atomRegistry[CHEMLIB_ATOM_REGISTRY_SIZE];

int chemlib_utils_is_digit(char character);
int chemlib_utils_is_uppercase(char character);
int chemlib_utils_is_lowercase(char character);

Atom* chemlib_create_atom(Element element);
AtomStack* chemlib_create_atom_stack(Element element, unsigned int count);
AtomStack* chemlib_create_atom_stack_from_atom(Atom* atom, unsigned int count);

void chemlib_free_atom(Atom* atom);
void chemlib_free_atom_stack(AtomStack* stack);

Atom* chemlib_parse_atom(char* string);
AtomStack* chemlib_parse_atom_stack_count(char* string, unsigned int count);
AtomStack* chemlib_parse_atom_stack(char* string);

char* chemlib_stringify_atom(Atom* atom);
char* chemlib_stringify_atom_stack(AtomStack* atom);

// void molecule_add_atom(Molecule* molecule, Atom* atom);
//
// void create_atom(Atom* atom, Element element);
//
// void parse_particle(Particle* particle, const char* text);
//
// void free_particle(Particle* particle);

#endif