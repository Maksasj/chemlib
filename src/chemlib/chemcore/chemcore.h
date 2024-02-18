#ifndef _CHEMCORE_H_
#define _CHEMCORE_H_

typedef enum ParticleType {
    ATOM,
    MOLECULE
} ParticleType;

typedef enum Element {
    HYDROGEN = 0,
    OXYGEN = 1
} Element;

typedef struct Atom {
    Element element;

    double mass;
    double charge;
} Atom;

typedef struct AtomRecord {
    const char* name;
    const char* symbol;

    Atom atom;
} AtomRecord;

typedef struct AtomStack {
    Atom atom;
    unsigned int count;
} AtomStack;

typedef struct Molecule {
    AtomStack* atoms;

    unsigned int atomStackCount;
} Molecule;

extern AtomRecord atomRegistry[2];

Atom chemlib_create_atom(Element element);
AtomStack chemlib_create_atom_stack(Element element, unsigned int count);

// void molecule_add_atom(Molecule* molecule, Atom* atom);
//
// void create_atom(Atom* atom, Element element);
//
// void parse_particle(Particle* particle, const char* text);
//
// void free_particle(Particle* particle);

#endif