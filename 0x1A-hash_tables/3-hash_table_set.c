#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: the hash table to add or update the key/value to
 * @key: the key. Cannot be an empty string
 * @value: value associated with the key. value must be duplicated
 * Return: 1 if it succeeded, 0 otherwise
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_node = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (0);
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		return (0);
	}
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;

	if (ht->array[index] == NULL)
	{
		ht->array[index] = new_node;
	}
	else
	{
		new_node->next = ht->array[index];
		ht->array[index] = new_node;
	}
	return (1);
}
