#ifndef _CHEMLIB_CHEMCORE_H_
#define _CHEMLIB_CHEMCORE_H_

#include "chemcore/chemcore.h"

enum ParticleType {
    ATOM,
    MOLECULE
};

enum Element {
    HYDROGEN,
    OXYGEN
};

struct Atom {
    Element element;
    
    double mass;
    double charge;
};

struct AtomStack {
    Atom atom;
    unsigned int count;
};

struct Molecule {
    AtomStack* atoms;
};

struct Particle {
    ParticleType type;
    void* particle;
};

void molecule_add_atom(Molecule* molecule, Atom* atom);

void create_atom(Atom* atom, Element element);

void parse_particle(Particle* particle, const char* text);

void free_particle(Particle* particle);

#endif