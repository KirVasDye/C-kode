#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct User {
	int id;
	char nickname[51];
	int karma;
} User;

int cmpKarma(const void* a, const void* b) {
	return ((User*)a)->karma - ((User*)b)->karma;
}

int cmpNickname(const void* a, const void* b) {
	return strcmp(((User*)a)->nickname, ((User*)b)->nickname);
}

int main(void) {

	srand(time(NULL));

	unsigned int n;
	printf("Enter kol-vo Users : ");
	scanf("%u", &n);
	User* arr = (User*)malloc(n * sizeof(User)); // Выделение памяти под массив структур

	int i;

	for(i = 0; i < n; i++) {                   // Ввод элементов массива
		arr[i].id = i + 1;
		arr[i].karma = rand() % 100 + 1;
		system("clear");
		printf("%d) Enter name : ", i+1);
		scanf("%s", arr[i].nickname);
		system("clear");
	}

	qsort(arr, n, sizeof(User), cmpKarma);     // Сортировка по карме

	for(i = 0; i < n; i++) {
		printf("%d\t", arr[i].id);
		printf("%s\t", arr[i].nickname);
		printf("%d\n", arr[i].karma);
	}

	qsort(arr, n, sizeof(User), cmpNickname);  // Сортировка по имени

	printf("\n===================================\n");

	for(i = 0; i < n; i++) {
		printf("%d\t", arr[i].id);
		printf("%s\t", arr[i].nickname);
		printf("%d\n", arr[i].karma);
	}

	free(arr);
	arr = NULL;
	return 0;
}
