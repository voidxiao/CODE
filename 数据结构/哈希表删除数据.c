#include<stdio.h>
#include<stdlib.h>

typedef struct link
{
	int data;
	struct link* next;
}Link;

//散列函数
void add(int value, Link** hash);

//取哈希表数据
Link* getHash(Link** hash, int data);

//哈希表删除数据
void rmHash(Link** hash, int data);

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

	//取数据
	Link* data = getHash(hash, 123);
	printf("%p:%d\n", data, data->data);

	//删除数据
	rmHash(hash, 23);



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

//取哈希表数据
Link* getHash(Link** hash, int data)
{
	int mod = data % 10;
	Link* temp = hash[mod];
	if (hash[mod]->data == data)
	{
		return hash[mod];
	}
	else
	{
		while (temp->next)
		{
			if (temp->next->data == data)
			{
				return temp->next;
			}
			else
			{
				temp = temp->next;
			}
		}
		return NULL;
	}
}

//哈希表删除数据
void rmHash(Link** hash, int data)
{
	int mod = data % 10;
	Link* temp = hash[mod];
	if (hash[mod]->data == data)
	{
		hash[mod] = hash[mod]->next;
		free(temp);
	}
	else
	{
		Link* father = temp;
		while (temp->next)
		{
			if (temp->next->data == data)
			{
				if (temp->next->next)
				{
					Link* deleteLink = temp->next;
					father->next = temp->next->next;
					free(deleteLink);
				}
				else
				{
					free(temp->next);
					father->next = NULL;
				}
				return;
			}
			else
			{
				father = temp->next;
				temp = temp->next;
			}
		}
	}
}
