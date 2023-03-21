#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start=NULL;
struct node *temp=NULL;

void basa_ekle(int sayi){
	struct node *eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=sayi;
	eklenecek->next=start;
	start=eklenecek;
}

void sona_ekle(int sayi){
	struct node *eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=sayi;
	eklenecek->next=NULL;
	if(start==NULL) start=eklenecek;
	else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=eklenecek;
	}
}

void bastan_sil(){
	if(start==NULL) printf("eleman yok");
	else{
		temp=start->next;
		free(start);
		start=temp;
	}
}

void sondan_sil(){
	if(start==NULL) printf("eleman yok");
	else{
		temp=start;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		free(temp->next);
		temp->next=NULL;
	}
}

int adet(){
	int adet=0;
	if(start==NULL) return 0;
	else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
			adet++;
		}
		adet++;
	}
	return adet;
}

int toplam(){
	int toplam=0;
	if(start==NULL) return 0;
	else{
		temp=start;
		while(temp->next!=NULL){
			toplam+=temp->data;
			temp=temp->next;
		}
		toplam+=temp->data;
	}
	return toplam;
}

void yazdir(){
	temp=start;
	while(temp->next!=NULL){
		printf("\n%d",temp->data);
		temp=temp->next;
	}
	printf("\n%d",temp->data);
}







int main(){
	while(1){
		int secim,sayi;
		printf("\nMENU\n");
		printf("1-basa eleman ekle\n");
		printf("2-sona eleman ekle\n");
		printf("3-bastan eleman sil\n");
		printf("4-sondan eleman sil\n");
		printf("5-eleman adeti\n");
		printf("6-eleman toplami\n");
		printf("7-listele\n");
		printf("8-CIKIS\n");
		scanf("%d",&secim);
		
		switch(secim){
			case 1:
				printf("\nsayi girin:"); scanf("%d",&sayi);
				basa_ekle(sayi);
				break;
			
			case 2:
				printf("\nsayi girin:"); scanf("%d",&sayi);
				sona_ekle(sayi);
				break;
			
			case 3:
				bastan_sil();
				break;
		
			case 4:
				sondan_sil();
				break;
			
			case 5:
				printf("adet:%d\n",adet());
				break;
				
			case 6:
				printf("toplam:%d\n",toplam());
				break;
				
			case 7:
				yazdir();
				break;
		
			case 8:	
				return 0;
				break;
			
		}
	}
	
}
