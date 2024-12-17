#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct Node* insertAtBegining(struct Node* head, int new_data)
{
    struct Node* new_node = createNode(new_data);
    new_node->next = head;
    return new_node;
}

void printList(struct Node* head)
{
    struct Node* curr = head;
    while (curr != NULL)
    {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* insertAtTheEnd(struct Node* head, int new_data)
{
    struct Node* new_node = createNode(new_data);
    if (head == NULL)
    {
        return new_node;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct Node* insertAtASpecificPosition(struct Node* head, int pos, int new_data)
{
    if (pos < 1)
    {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1)
    {
        return insertAtBegining(head, new_data);
    }
    struct Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Position out of bounds!\n");
        return head;
    }
    struct Node* new_node = createNode(new_data);
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}
struct Node* insertAfterASpecificNode(struct Node* head,int key,int new_data)
{
    struct Node* curr = head;
    while(curr!=NULL)
    {
        if(curr->data==key)
            break;
        curr=curr->next;
    }
    if(curr==NULL)
    {
        printf("Node with key %d not found\n",key);
        return head;
    }
    struct Node* new_node = createNode(new_data);
    new_node->next=curr->next;
    curr->next=new_node;
    return head;
}

int main()
{
    struct Node* head = NULL;
    int n, data, pos,key;

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtBegining(head, data);
    }
    printf("Linked List after creation:");
    printList(head);

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    head = insertAtBegining(head, data);
    printf("Linked List after inserting at the beginning:");
    printList(head);

    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    head = insertAtTheEnd(head, data);
    printf("Linked list after inserting at the end:");
    printList(head);

    printf("Enter position to insert at: ");
    scanf("%d", &pos);
    printf("Enter data to insert at position %d: ", pos);
    scanf("%d", &data);
    head = insertAtASpecificPosition(head, pos, data);
    printf("Linked list after inserting at position %d:", pos);
    printList(head);

    printf("Enter the key after which to insert:");
    scanf("%d",&key);
    printf("Enter data to insert after key %d:",key);
    scanf("%d",&data);
    head = insertAfterASpecificNode(head,key,data);
    printf("Linked list after inserting after key %d:",key);
    printList(head);
    return 0;
}
