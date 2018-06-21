//Portal.c
#include <stdio.h>
#include <stdlib.h>
#define Max 200005
typedef struct city
{
    int level;
	int vertex;
	struct city *next;
}City;
void BFS(City **cities);
City * new_city(int vertex);
void connect(City *city_start, int start, int end);
int num_of_city;
int main()
{
	int testcase, num_of_portal, num_of_new_portal, start, end;
	scanf("%d", &testcase);
	while(testcase--)
	{
		City * cities[Max], *inverse_cities[Max];
		scanf("%d%d%d", &num_of_city, &num_of_portal, &num_of_new_portal);
		while(num_of_portal--)
		{
			//draft the cities and the inverse ones
			scanf("%d%d", &start, &end);
			connect(cities[start], start, end);
			connect(inverse_cities[end], end, start);	
		}
		BFS(cities);
		BFS(inverse_cities);
		int min_level = INT_MAX;
		for(int i = 1; i <= num_of_city; i++)
				if(cities[i]->level + inverse_cities[i]->level < min_level)
					min_level = cities[i]->level + inverse_cities[i]->level;
		while(num_of_new_portal--)
		{
			scanf("%d%d", &start, &end);
			int temp_level = cities[start]->level + 1 + inverse_cities[end]->level;
			printf("%d\n", temp_level < min_level ? temp_level : min_level);
		}
	}
	return 0;
}
void BFS(City **cities)//due to lack of practice, this part is a little bit  messy
{
	int visited[Max + 1] = {0}, queue[Max], start = 0, end = 1, breadth_end= 1, level = 0;
	visited[1] = 1, queue[0] = 1;//initialize my queue
	while()
	{
		
	}
}
City * new_city(int vertex)
{
	City *new = (City*)malloc(sizeof(City));
	new->level = num_of_city;
	new->vertex = vertex;
	new->next = NULL;
	return new;
}
void connect(City *city_start, int start, int end)
{
	if(!city_start)city_start = new_city(start);
	City * temp = city_start;
	while(temp->next != NULL)temp = temp->next;
	temp->next = new_city(end);
}
