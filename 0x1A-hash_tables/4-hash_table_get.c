#include "hash_tables.h"

/**
 * hash_table_get - returns the value associated with a key.
 * @ht: hash table
 * @key: key
 * Return: value
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *current_node = NULL;

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
