#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Free memory allocated for a dog structure
 * @d: Pointer to a dog structure
 */
void free_dog(dog_t *d)
{
	if (d)
		{
		free(d->name);
		free(d->owner);
		free(d);
		}
}

