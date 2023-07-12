#include "hash_tables.h"

/**
 * shash_table_create - Creates a hash table
 * @size: The size of the array
 * Return: Returns a pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
	{
		return (NULL);
	}
	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ht->array[i] = NULL;
	}
	return (ht);
}


/**
 * shash_table_set - function that adds an element to the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key. Cannot be an empty string
 * @value: value associated with the key. value must be duplicated
 * Return: 1 if it succeeded, 0 otherwise
*/

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	shash_node_t *new_node = NULL, *element = NULL;

	if (ht == NULL || key == NULL || (strcmp(key, "") == 0))
	{
		return (0);
	}
	index = hash_djb2((const unsigned char *)key) % ht->size;
	element = ht->array[index];

	if (element && strcmp(key, element->key) == 0)
	{
		free(element->value);
		element->value = strdup(value);
		return (1);
	}
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		return (0);
	}
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}


/**
 * shash_table_get - returns the value associated with a key.
 * @ht: hash table
 * @key: key
 * Return: value
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t *current_node = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}
	current_node = ht->array[index];

	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			return (current_node->value);
		}
		current_node = current_node->next;
	}
	return (NULL);
}


/**
 * shash_table_print - prints a hash table
 * @ht: hash table
 * Return: void
*/
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *current_node = NULL;
	int first = 0;

	if (ht == NULL)
	{
		return;
	}
	printf("{");
	first = 1;

	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];

		while (current_node != NULL)
		{
			if (!first)
			{
				printf(", ");
			}
			printf("'%s': '%s'", current_node->key, current_node->value);
			first = 0;

			current_node = current_node->next;
		}
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse order
 * @ht: Pointer to the hash table
 * Return: key/value in reverse order
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
	{
		return;
	}
	printf("{");

	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		printf("'%s': '%s'", node->key, node->value);

		if (node->sprev != NULL)
		{
			printf(", ");
		}
		printf("}\n");
	}
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: Pointer to the hash table
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (ht == NULL)
	{
		return;
	}
	temp = ht->shead;

	while (temp != NULL)
	{
		node = temp->snext;
		free(temp);
		temp = node;
	}
	free(ht);
}
