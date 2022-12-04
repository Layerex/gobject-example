#include "animal_tiger.h"
#include "animal_predator.h"

#include <stdio.h>

static void animal_tiger_predator_interface_init(AnimalPredatorInterface *iface);

G_DEFINE_TYPE_WITH_CODE(AnimalTiger, animal_tiger, ANIMAL_TYPE_CAT,
                        G_IMPLEMENT_INTERFACE(ANIMAL_TYPE_PREDATOR,
                                              animal_tiger_predator_interface_init))

static void animal_tiger_cat_say_meow(AnimalCat *parent)
{
    AnimalTiger* self = ANIMAL_TIGER(parent);
    g_return_if_fail(ANIMAL_IS_TIGER(self));
    printf("Tiger %s says: GRRR!\n", animal_cat_get_name(parent));
}

static void animal_tiger_class_init(AnimalTigerClass *klass)
{
    printf("First instance of AnimalTiger was created.\n");
    AnimalCatClass *parent_class = ANIMAL_CAT_CLASS(klass);
    parent_class->say_meow = animal_tiger_cat_say_meow;
}

static void animal_tiger_init(AnimalTiger *self)
{
    printf("A tiger cub was born.\n");
}

static void animal_tiger_predator_hunt(AnimalPredator *self)
{
    g_return_if_fail(ANIMAL_IS_TIGER(self));
    printf("Tiger hunts. Beware!\n");
}

static void animal_tiger_predator_eat_meat(AnimalPredator *self, int quantity)
{
    g_return_if_fail(ANIMAL_IS_TIGER(self));
    printf("Tiger eats %d chunks of meat.\n", quantity);
}

static void animal_tiger_predator_interface_init(AnimalPredatorInterface *iface)
{
    iface->hunt = animal_tiger_predator_hunt;
    iface->eat_meat = animal_tiger_predator_eat_meat;
}

AnimalTiger *animal_tiger_new()
{
    return g_object_new(ANIMAL_TYPE_TIGER, NULL);
}
