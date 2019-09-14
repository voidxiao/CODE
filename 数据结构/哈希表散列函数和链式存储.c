#include<stdio.h>
#include<stdlib.h>

typedef struct link
{
	int data;
	struct link* next;
}Link;

//散列函数
void add(int value, Link** hash);

int main(void)
{
	int temp[] = { 11, 32, 22, 21, 31, 50, 53, 23, 15, 25, 52, 111, 122, 123 };
	int num = sizeof(temp) / 4;
	Link** hash = (Link**)malloc(sizeof(Link**) * 10);
	for (int i = 0; i < 10; i++)
	{
		hash[i] = NULL;
	}

	for (int i = 0; i < num; i++)
	{
		add(temp[i], hash);
	}


	system("pause");
	return 0;
}

//散列函数
void add(int value, Link** hash)
{
	if (hash[value % 10])
	{
		Link* Ptemp = hash[value % 10];
		Link* temp = (Link*)malloc(sizeof(Link));
		temp->data = value;
		temp->next = NULL;
		while (Ptemp)
		{
			if (Ptemp->next)
			{
				Ptemp = Ptemp->next;
			}
			else
			{
				Ptemp->next = temp;
				break;
			}
		}
	}
	else
	{
		Link* temp = (Link*)malloc(sizeof(Link));
		temp->data = value;
		temp->next = NULL;
		hash[value % 10] = temp;
	}
}
