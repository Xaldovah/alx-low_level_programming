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

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
	{
		return (NULL);
	}
	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);

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


#include "hash_tables.h"

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
	shash_node_t *new_node = NULL;

	if (ht == NULL || key == NULL || strcmp(key) == 0 || value == NULL)
	{
		return (0);
	}
	index = hash_djb2((const unsigned char *)key) % ht->size;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node);
		return (0);
	}
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
	shash_node_t *head = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}
	index = hash_djb2((unsigned char *)key) % ht->size;

	if (ht->array[index] != NULL)
	{
		head = ht->array[index];

		while (head != NULL)
		{
			if (strcmp(head->key, key) == 0)
			{
				break;
			}
			head = head->next;
		}
	}
	else
	{
		return (NULL);
	}
	return (head->value);
}
