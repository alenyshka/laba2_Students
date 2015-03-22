#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct students
{
	struct q
	{
		char *first_name;
		char *surname;
		char *patronymic;
	} full_name;
	union f
	{
		struct a
		{
			int height;
			int weight;
		} min_params;
		struct d
		{
			int height;
			int weight;
			int blood_group;
			int sight;
			int shoe_size;
		}full_params;
	} attributes;
};
void wait_input()
{
	scanf("%*c%*c");
}
void clean_stdin(void)
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int main(int argc, char *argv[])
{
	const int M = 100;
	printf("%d\n", sizeof(struct students));
	printf("%d\n", sizeof(struct q));
	printf("%d\n", sizeof(struct a));
	printf("%d\n", sizeof(struct d));
	printf("%d\n", sizeof(union f));
	if (argc < 2)
	{
		printf("Usage: %s <params_type>\n", argv[0]);
		wait_input();
		return -1;
	}
	int i = 0, N = 0;
	printf("Enter count of students\n");
	scanf("%d", &N);
	while (N < 0 || !N)
	{
		clean_stdin();
		printf("Incorrected input, please try again\n");
		scanf("%d", &N);
	}
	fflush(stdin);
	
	struct students *s = calloc(N, sizeof(struct students));
	for (i = 0; i < N; i++)
	{
		s[i].full_name.first_name = calloc(M, sizeof(char));
		s[i].full_name.surname = calloc(M, sizeof(char));
		s[i].full_name.patronymic = calloc(M, sizeof(char));


		if (!s || !s[i].full_name.first_name || !s[i].full_name.surname || !s[i].full_name.patronymic)
		{
			printf("Memory don't located\n");
			wait_input();
			return 0;
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("Enter surname [%d], name[%d], patronymic [%d] of students\n", i, i, i);
		scanf("%s%s%s", s[i].full_name.surname, s[i].full_name.first_name, s[i].full_name.patronymic);
	}
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif

	for (i = 0; i < N; i++)
	{
		printf("%d . %s %s %s\n", i, s[i].full_name.surname, s[i].full_name.first_name, s[i].full_name.patronymic);
	}
	int option = 0, zn1 = 1, zn2 = 2;
	printf("Enter option (min params - 1, full params - 2)\n");
	scanf("%d", &option);
	while (option < 1 || option > 2)
	{
		clean_stdin();
		printf("Incorrected input\n");
		scanf("%d", &option);
	}
	if (option == 1)
	{

		for (i = 0; i < N; i++)
		{
			printf("Enter weight[%d] and height[%d]\n", i, i);
			scanf("%d%d", &s[i].attributes.min_params.weight, &s[i].attributes.min_params.height);
			while (!s[i].attributes.min_params.weight || !s[i].attributes.min_params.height)
			{
				clean_stdin();
				printf("Incorrected input\n");
				scanf("%d%d", &s[i].attributes.min_params.weight, &s[i].attributes.min_params.height);
			}

		}
		for (i = 0; i < N; i++)
		{
			printf("%s %s %s %d %d\n", s[i].full_name.surname, s[i].full_name.first_name, s[i].full_name.patronymic, s[i].attributes.min_params.weight, s[i].attributes.min_params.height);
		}

	}

	if (option == 2)
	{
		for (i = 0; i < N; i++)
		{
			printf("Enter weight[%d] and height[%d], blood_group[%d], shoe_size[%d], sight[%d]\n", i, i, i, i, i);
			scanf("%d%d%d%d%d",
				&s[i].attributes.full_params.weight,
				&s[i].attributes.full_params.height,
				&s[i].attributes.full_params.blood_group,
				&s[i].attributes.full_params.shoe_size,
				&s[i].attributes.full_params.sight);
			while (!s[i].attributes.full_params.weight
				|| !s[i].attributes.full_params.height
				|| !s[i].attributes.full_params.blood_group
				|| !s[i].attributes.full_params.shoe_size
				|| !s[i].attributes.full_params.sight)
			{
				clean_stdin();
				printf("Incorrected input, please try again\n");
				scanf("%d%d%d%d%d",
					&s[i].attributes.full_params.weight,
					&s[i].attributes.full_params.height,
					&s[i].attributes.full_params.blood_group,
					&s[i].attributes.full_params.shoe_size,
					&s[i].attributes.full_params.sight);
			}
		}

		for (i = 0; i < N; i++)
		{
			printf("%s %s %s %d %d %d %d %d\n",
				s[i].full_name.surname,
				s[i].full_name.first_name,
				s[i].full_name.patronymic,
				s[i].attributes.full_params.weight,
				s[i].attributes.full_params.height,
				s[i].attributes.full_params.blood_group,
				s[i].attributes.full_params.shoe_size,
				s[i].attributes.full_params.sight);
		}
	}
	
	struct students temp;
	char *min_name = calloc(3 * M + 10, sizeof(char));
	char *curr_name = calloc(3 * M + 10, sizeof(char));
	
	int j = 0;
	for (j = 0; j < N; j++)
	{
		sprintf(min_name, "%s %s %s", s[j].full_name.surname, s[j].full_name.first_name, s[j].full_name.patronymic);
		for (i = j; i < N; i++)
		{
			sprintf(curr_name, "%s %s %s", s[i].full_name.surname, s[i].full_name.first_name, s[i].full_name.patronymic);
			if (strcmp(min_name, curr_name) > 0)
			{
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}
	printf("Sort alphabet\n");
	for (i = 0; i < N; i++)
	{
		printf("%s %s %s\n", s[i].full_name.surname, s[i].full_name.first_name, s[i].full_name.patronymic);
	}


	for (i = 0; i < N; i++)
	{
		free(s[i].full_name.first_name);
		s[i].full_name.first_name = NULL;
		free(s[i].full_name.surname);
		s[i].full_name.surname = NULL;
		free(s[i].full_name.patronymic);
		s[i].full_name.patronymic = NULL;
	}

	free(s);
	wait_input();
	return 0;
}

