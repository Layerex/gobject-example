#ifndef ANIMAL_PREDATOR_H_
#define ANIMAL_PREDATOR_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define ANIMAL_TYPE_PREDATOR animal_predator_get_type()
G_DECLARE_INTERFACE(AnimalPredator, animal_predator, ANIMAL, PREDATOR, GObject)

struct _AnimalPredatorInterface
{
    GTypeInterface parent;
    void (*hunt)(AnimalPredator *);
    void (*eat_meat)(AnimalPredator *, int);
};

void animal_predator_hunt(AnimalPredator *self);

void animal_predator_eat_meat(AnimalPredator *self, int quantity);

G_END_DECLS

#endif // ANIMAL_PREDATOR_H_
