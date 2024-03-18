#include <stdlib.h>
#include <stdio.h>
#include "remove_node.h"

int main() {
	node* head = (node*)malloc(sizeof(node));
	head->data = 3;
	head->next = NULL; // Next i�aret�isini NULL olarak ayarlay�n

	// �kinci d���m� olu�turun ve ba�lay�n
	head->next = (node*)malloc(sizeof(node));
	head->next->data = 5;
	head->next->next = NULL; // Sonraki d���m� NULL olarak ayarlay�n

	// ���nc� d���m� olu�turun ve ba�lay�n
	head->next->next = (node*)malloc(sizeof(node));
	head->next->next->data = 7;
	head->next->next->next = NULL; // Sonraki d���m� NULL olarak ayarlay�n

	// D�rd�nc� d���m� olu�turun ve ba�lay�n
	head->next->next->next = (node*)malloc(sizeof(node));
	head->next->next->next->data = 9;
	head->next->next->next->next = NULL; // Sonraki d���m� NULL olarak ayarlay�n
		listinfo(head);
		int key;
		printf("silmek istediginiz elemani giriniz: \n");
		if (scanf_s("%d", &key) != 1) {
			printf("hatali giris tamsayi girin.\n");
			return 1;
		}

		remove_node(&head, key);
		printf("silinmi� listeniz:\n");
		listinfo(head);
		return 0;
}