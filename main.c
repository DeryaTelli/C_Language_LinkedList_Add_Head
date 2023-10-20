#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data; 
	struct Node* next; // Node* boyle yaparak pointer yaptim adreslerin icine girmek icin '->' kullanmam gerekecek 
}node;

void write_linkedlist(node* n){
	node* temp =  n ; // node refer to struct Node unutma ve burada baslangic node onemli oldugu icin burada kopyasini olusturup veriyorum 
	while (temp!=NULL){
		printf("%d\n", temp->data );
		temp=temp->next;
	}
	printf("-----------------------------------------\n");
}

struct Node* create_linkedlist(int data){
	node* n=(node*)malloc(sizeof(node));
	n->data = data; 
	n->next = NULL;
	return n; 
}
 void add_node_head_of_linkedlist(struct Node** linkedlist , int data){
 	node* new_linkedlist=create_linkedlist(data); // buradaki data parametre icindeki datadir 
 	new_linkedlist -> next = *linkedlist; // linkedlistin icndeki elemana erismek istedigimiz icin pointer aliyoruz 
 	*linkedlist = new_linkedlist;// bu da bizim yeni linkedlistimizi birinci linkedlist yapiyor 
 }

int main() {

	node* root = create_linkedlist(5);
	write_linkedlist(root);
	add_node_head_of_linkedlist(&root,4);
	add_node_head_of_linkedlist(&root,3);
	write_linkedlist(root);
	
	
	return 0;
 }
