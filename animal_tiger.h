#ifndef ANIMAL_TIGER_H_
#define ANIMAL_TIGER_H_

#include "animal_cat.h"

G_BEGIN_DECLS

#define ANIMAL_TYPE_TIGER animal_tiger_get_type()

G_DECLARE_FINAL_TYPE(AnimalTiger, animal_tiger, ANIMAL, TIGER, AnimalCat)

struct _AnimalTiger
{
    AnimalCat parent;
};

AnimalTiger *animal_tiger_new();

G_END_DECLS

#endif // ANIMAL_TIGER_H_
