#include "stdafx.h"
#include<conio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int insert(int[], int);
int remove(int[]);
void display(int[], int, int);

const int siz = 50;
int queue[siz], front = -1, rear = -1;

int main()
{
	int item, res;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		cout << "\n\n\tEnter item for insertion : ";
		cin >> item;
		res = insert(queue, item);
		if (res == -1)
		{
			cout << "\n\n\tOverflow!!!";
			_getch();
			exit(1);
		}
		system("cls");
		cout << "\n\n\tNow the queue (front-to-rear) is :\n";
		display(queue, front, rear);
		cout << "\n\n\tWant to insert more elements(y/n) : ";
		cin >> ch;
	}
	system("cls");
	cout << "\n\n\tNow the deletion begins.........";
	ch = 'y';
	_getch();
	while (ch == 'y' || ch == 'Y')
	{
		res = remove(queue);
		if (res == -1)
		{
			cout << "\n\n\tUnderflow!!!";
			_getch();
			exit(1);
		}
		else
		{
			system("cls");
			cout << "\n\n\tElement deleted is : " << res;
			cout << "\n\n\tNow the queue (front-to-end) is :\n";
			display(queue, front, rear);
		}
		cout << "\n\n\tWant to delete more elements(y/n) : ";
		cin >> ch;
	}
	return 0;
}

int insert(int queue[], int item)
{
	if (rear == siz - 1)
	{
		return -1;
	}
	else if (rear == -1)
	{
		front = rear = 0;
		queue[rear] = item;
	}
	else
	{
		rear++;
		queue[rear] = item;
	}
	return 0;
}

int remove(int queue[])
{
	int ret;
	if (front == -1)
	{
		return -1;
	}
	else
	{
		ret = queue[front];
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
	}
	return ret;
}

void display(int queue[], int front, int rear)
{
	if (front == -1)
	{
		return;
	}
	cout << "\t";
	for (int i = front;i < rear;i++)
	{
		cout << queue[i] << " <-- ";
	}
	cout << queue[rear] << endl;
}