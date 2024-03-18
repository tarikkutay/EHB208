#include <stdlib.h>
#include "remove_node.h"

void listinfo(node* head) {
	int i = 1;
	while (head != NULL) {
		printf("%d. Dugumunun Adresi = %p \n", i, head);
		printf("%d. Dugumunun verisi = %d \n", i, head->data);
		printf("%d. Dugumunun Bagli Oldugu Dugumun Adresi= %p\n\n", i, head->next);
		head = head->next;
		i++;
	}
}
void remove_node(node* head, int key) {
	if (head == NULL) {
		printf("listede eleman yok\n");
		return;
	}
	node* temp = head;//�imdi bir ge�ici d���m olu�turduk bunu gezdirece�iz
//ilk k�s�mdaki key ve data uyu�ursa 
	if (head ->data == key)
	{
		head = head->next;
		free(temp);
		//ilk k�s�mdaysa e�er key tempe gerek kalmadan headi headin nextine e�itle ilk nodeu sil
	}
	else if (temp->next == NULL)
	{
		printf("silmek istedi�in veri diye bir �ey yok masmalesef\n");
		return;
		//NULL BULURSA HATA MESAJI �IKART
	}
	//��MD� ORTALARDA ARAMA YAPACA�IZ
	else
	{
		while (temp->next->data != key)
		{
			if (temp->next -> next == NULL) {
				printf("silmek istedi�in veri yok\n");
				return head;
				//yine tek d���m var bu sefer head d�nd�r�l�r
			}
			temp->next->next;
			//bir sonraki d���me ge� ta ki null olana dek
		}
		node* temp2 = temp->next;
		temp->next = temp->next->next;
		free(temp2);
		//elimizde 8 5 7 ve 4 l�k liste varsa ben 7 yi ar�yorsam tempimi 5'in nextine 
		//kadar gezdiririm ve 5->next = temp olur ard�ndan bir temp 2 yapar�m bu da 4
		//kaybolmamas� i�in bu temp2 = temp->next olur ard�ndan 5in nextini 4 e baglar�m;
		//temp->next = temp->next->next
		//free(temp2)yapar bitiririm
	}
}