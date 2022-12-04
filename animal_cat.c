#include "animal_cat.h"

#include <stdio.h>

typedef struct
{
    char *name;
} AnimalCatPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(AnimalCat, animal_cat, G_TYPE_OBJECT)

static void animal_cat_real_say_meow(AnimalCat *self)
{
    AnimalCatPrivate *priv = animal_cat_get_instance_private(self);
    printf("Cat %s says: MEOW!\n", priv->name);
}

typedef enum { PROP_NAME = 1, N_PROPERTIES } AnimalCatProperty;

static GParamSpec *obj_properties[N_PROPERTIES] = {
    NULL,
};

static void animal_cat_set_property(GObject *object, guint property_id, const GValue *value,
                                    GParamSpec *pspec)
{
    AnimalCat *self = ANIMAL_CAT(object);
    AnimalCatPrivate *priv = animal_cat_get_instance_private(self);

    switch ((AnimalCatProperty)property_id) {
    case PROP_NAME:
        g_free(priv->name);
        priv->name = g_value_dup_string(value);
        printf("Cat's name set to %s.\n", priv->name);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

static void animal_cat_get_property(GObject *object, guint property_id, GValue *value,
                                    GParamSpec *pspec)
{
    AnimalCat *self = ANIMAL_CAT(object);
    AnimalCatPrivate *priv = animal_cat_get_instance_private(self);

    switch ((AnimalCatProperty)property_id) {
    case PROP_NAME:
        g_value_set_string(value, priv->name);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
        break;
    }
}

static void animal_cat_finalize(GObject *object)
{
    AnimalCat *self = ANIMAL_CAT(object);
    AnimalCatPrivate *priv = animal_cat_get_instance_private(self);

    printf("Cat %s vanished.\n", priv->name);

    g_free(priv->name);

    G_OBJECT_CLASS(animal_cat_parent_class)->finalize(object);
}

static void animal_cat_class_init(AnimalCatClass *klass)
{
    printf("First instance of AnimalCat was created.\n");

    klass->say_meow = animal_cat_real_say_meow;

    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->set_property = animal_cat_set_property;
    object_class->get_property = animal_cat_get_property;

    obj_properties[PROP_NAME] =
            g_param_spec_string("name", "Name", "Name of a cat", NULL, G_PARAM_READWRITE);

    g_object_class_install_properties(object_class, N_PROPERTIES, obj_properties);

    object_class->finalize = animal_cat_finalize;
}

static void animal_cat_init(AnimalCat *self)
{
    printf("A kitty was born.\n");
}

AnimalCat *animal_cat_new()
{
    return g_object_new(ANIMAL_TYPE_CAT, NULL);
}

void animal_cat_say_meow(AnimalCat *self)
{
    g_return_if_fail(ANIMAL_IS_CAT(self));
    AnimalCatClass *klass = ANIMAL_CAT_GET_CLASS(self);
    klass->say_meow(self);
}

const char *animal_cat_get_name(AnimalCat *self)
{
    g_return_val_if_fail(ANIMAL_IS_CAT(self), NULL);
    GValue val = { 0 };
    g_value_init(&val, G_TYPE_STRING);
    g_object_get_property(G_OBJECT(self), "name", &val);
    return g_value_get_string(&val);
}

void animal_cat_set_name(AnimalCat *self, char *name)
{
    g_return_if_fail(ANIMAL_IS_CAT(self));
    GValue val = { 0 };
    g_value_init(&val, G_TYPE_STRING);
    g_value_set_string(&val, name);
    g_object_set_property(G_OBJECT(self), "name", &val);
}
