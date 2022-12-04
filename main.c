#include "animal_cat.h"
#include "animal_predator.h"
#include "animal_tiger.h"

int main(int argc, char **argv)
{
    AnimalTiger *tiger = animal_tiger_new();
    animal_cat_say_meow(ANIMAL_CAT(tiger));
    animal_cat_set_name(ANIMAL_CAT(tiger), "Barsik");
    animal_cat_say_meow(ANIMAL_CAT(tiger));
    animal_predator_hunt(ANIMAL_PREDATOR(tiger));
    animal_predator_eat_meat(ANIMAL_PREDATOR(tiger), 39);
    g_object_unref(tiger);
}
