#include <stdio.h>
#include <stdlib.h>
#include "table.h"
int main()
{
	Key keys[SIZE_TABLE];
	Val values[SIZE_TABLE];
	int size;
	char name[80];
	printf("Print file name\n");
	scanf("%s", name);
	
	FILE *file = fopen(name, "r");
	if (file == NULL)
	{
		printf("File doesnt exist\n");
		return 0;
	}
	
	int i = 0;
	char ch;
	while (i < SIZE_TABLE && fscanf(file, "%d", &keys[i].key) == 1)
	{
		fscanf(file, "%c", &ch);
		getRow(file, values[i].val, sizeof(values[i].val));
		i++;
	}
	fclose(file);
	
	size = i;
	int action;
	do
	{
		printf("Menu\n");
		printf("1) Print\n");
		printf("2) Binary search\n");
		printf("3) Sort\n");
		printf("4) Mix\n");
		printf("5) Reverse\n");
		printf("6) Exit\n");
		printf("Choose the action\n");
		scanf("%d", &action);

		switch (action)
		{
			case 1:
			{
				printTable(keys, values, size);
				break;
			}
			case 2:
			{
				if (!isSorted(keys, size))
					printf("Error. The table was not sorted\n");
				else
				{
					Key key;
					printf("Enter the key: ");
					scanf("%d", &key.key);

					int i = binSearch(keys, values, size, key);

					if (i > -1)
						printf("String found: %s\n", values[i].val);
					else
						printf("String with the key was not found\n");
				}
				break;
			}
			case 3:
			{
				sort(keys, values, size);
				break;
			}
			case 4:
			{
				scramble(keys, values, size);
				break;
			}
			case 5:
			{
				reverse(keys, values, size);
				break;
			}
			case 6: break;

			default:
			{
				printf("Error. Doesnt exist\n");
				break;
			}
		}
	}
	while (action != 6);
return 0;
}