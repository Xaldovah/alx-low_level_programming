#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 * Return: void
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *current_node = NULL;
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
