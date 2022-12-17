#include<iostream>
using namespace std;
// khoi tao cau truc node
struct node {
	int data;
	node* next;
};
//tao node moi
node* makenode(int data) {
	node* newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
// day node vao dnah sach
void pushback(node** head, int data) {
	node* newnode = makenode(data);
	node* temp = *head;
	if (*head == NULL) {
		*head = newnode;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newnode;
}
// in ra du lieu danh sach
void duyet(node* head) {
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
//hoan doi node
void swapdata(node* first, node* second) {
	int temp = first->data;
	first->data = second->data;
	second->data = temp;
}
// sap xep theo yeu cau
void sort(node* head) {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	node* tempnext = head->next;
	while (tempnext != NULL)
	{
		if (temp->data > tempnext->data) {
			swapdata(temp, tempnext);
		}
		if (tempnext->next->data > tempnext->data) {
			swapdata(tempnext->next, tempnext);
		}
		temp = temp->next->next;
		tempnext = tempnext->next->next;
	}
}
int main() {
	node* head = NULL;
	int n;
	cout << "nhap vao so luong phan tu mang n  = ";
	cin >> n;
	int i = 0;
	while (i < n)
	{
		int data;
		cout << "nhap data vao mang ";
		cin >> data;
		cin.ignore();
		pushback(&head, data);
		i++;
	}
	duyet(head);
	sort(head);
	duyet(head);
}