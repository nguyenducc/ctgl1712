#include<iostream>
#include<set>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* makenode(int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void pushback(node** head, int data) {
    node* temp = *head;
    node* newnode = makenode(data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

bool check(node* head) {
    node* temp = head;
    // tao ra set roi chen cac node vao set , thuan tien cho viec kiem tra voi do phuc tap O(log n)
    set<node*> st;
    while (temp != NULL)
    {
        if (st.count(temp)!=0) {
            return true;
        }
        else {
            // chen cac nut vao set st
            st.insert(temp);
            temp = temp->next;
        }

    }
    return false;

}

int main() {
    node* head = NULL;
    for (int i = 0; i < 5; i++) {
        pushback(&head, i);
    }
    //head->next->next->next = head;
    if (check(head) == true)
    {
        cout << "found";
    }
    else {
        cout << "not found";
    }
}
