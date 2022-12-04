#ifndef ANIMAL_CAT_H_
#define ANIMAL_CAT_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define ANIMAL_TYPE_CAT animal_cat_get_type()

G_DECLARE_DERIVABLE_TYPE(AnimalCat, animal_cat, ANIMAL, CAT, GObject)

struct _AnimalCatClass
{
    GObjectClass parent_class;
    void (*say_meow)(AnimalCat *self);
};

AnimalCat *animal_cat_new();

void animal_cat_say_meow(AnimalCat *self);

const char *animal_cat_get_name(AnimalCat *self);
void animal_cat_set_name(AnimalCat *self, char *name);

G_END_DECLS

#endif // ANIMAL_CAT_H_
