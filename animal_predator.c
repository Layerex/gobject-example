#include <stdio.h>

#include "animal_predator.h"

G_DEFINE_INTERFACE(AnimalPredator, animal_predator, G_TYPE_OBJECT)

static void animal_predator_default_init(AnimalPredatorInterface *iface)
{
    printf("The first instance of an object that implements AnimalPredator interface was "
           "created.\n");
}

void animal_predator_hunt(AnimalPredator *self)
{
    g_return_if_fail(ANIMAL_IS_PREDATOR(self));
    AnimalPredatorInterface *iface = ANIMAL_PREDATOR_GET_IFACE(self);
    g_return_if_fail(iface->hunt != NULL);
    iface->hunt(self);
}

void animal_predator_eat_meat(AnimalPredator *self, int quantity)
{
    g_return_if_fail(ANIMAL_IS_PREDATOR(self));
    AnimalPredatorInterface *iface = ANIMAL_PREDATOR_GET_IFACE(self);
    g_return_if_fail(iface->eat_meat != NULL);
    iface->eat_meat(self, quantity);
}
