#include <bits/stdc++.h>
#include <chrono>

using namespace std;

typedef struct treenode
{
    float freq;
    char data;
    struct treenode *left, *right;
} treenode;

typedef struct node
{
    treenode *data;
    struct node *next;
} node;

node *insert(node *, treenode *);
treenode *create();
void encode();
void decode(treenode *);

int n = 0;
char alphabets[30];
char codes[30][10];

void preorder(treenode *p, int i, char word[])
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
        {
            word[i] = 0;
            printf("\n%c --- %s", p->data, word);
            alphabets[n] = p->data;
            strcpy(codes[n++], word);
        }
        word[i] = '0';
        preorder(p->left, i + 1, word);
        word[i] = '1';
        preorder(p->right, i + 1, word);
    }
}

node *insert(node *head, treenode *t)
{
    node *p, *q;
    p = (node *)malloc(sizeof(node));
    p->data = t;
    p->next = NULL;
    if (head == NULL)
        return p;
    if (t->freq < head->data->freq)
    {
        p->next = head;
        return p;
    }
    q = head;
    while (q->next != NULL && t->freq > q->next->data->freq)
        q = q->next;
    p->next = q->next;
    q->next = p;
    return head;
}

void encode()
{
    char word[30];
    int i, j;
    cout << "\n Enter a Message : ";
    cin >> word;
    cout << "\n Encoded Message = ";
    for (i = 0; word[i] != '\0'; i++)
    {
        for (j = 0; alphabets[j] != word[i] && j < n; j++);
        if (j < n)
            cout << codes[j];
    }
    cout << endl;
}

treenode *create()
{
    treenode *p, *t1, *t2;
    node *head;
    int n, i;
    char x;
    float probability;
    head = NULL;
    cout << "\nEnter No. of alphabets :";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n Enter alphabet :";
        cin >> x;
        cout << "\nEnter frequency :";
        cin >> probability;
        p = (treenode *)malloc(sizeof(treenode));
        p->left = p->right = NULL;
        p->data = x;
        p->freq = probability;
        head = insert(head, p);
    }
    for (i = 1; i < n; i++)
    {
        t1 = head->data;
        t2 = head->next->data;
        head = head->next->next;
        p = (treenode *)malloc(sizeof(treenode));
        p->left = t1;
        p->right = t2;
        p->freq = t1->freq + t2->freq;
        head = insert(head, p);
    }

    return head->data;
}

void decode(treenode *p)
{
    char word[90];
    int i;
    treenode *q;
    cout << "\nEnter an Encoded message : ";
    cin >> word;
    q = p;
    i = 0;
    cout << "\nDecoded Message = ";
    while (word[i] != '\0')
    {
        if (word[i] == '0')
            q = q->left;
        else
            q = q->right;
        if (q->left == NULL && q->right == NULL)
        {
            printf("%c", q->data);
            q = p;
        }
        i++;
    }
    cout << endl;
}

int main()
{
    int op;
    char word[10];
    treenode *root = NULL;
    bool exitFlag = false; // Flag to exit the loop

    do
    {
        cout << "\n1)Create Huffman Tree";
        cout << "\n2)Encode a Message ";
        cout << "\n3)Decode a message ";
        cout << "\n4)Exit"; // Add "Exit" option
        cout << "\nEnter Your Choice : ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            auto start = chrono::high_resolution_clock::now();
            root = create();
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
            cout << "Time taken to create Huffman Tree: " << duration.count() << " milliseconds" << endl;
            cout << "\nPrefix codes : \n";
            preorder(root, 0, word);
            break;
        }
        case 2:
        {
            auto start = chrono::high_resolution_clock::now();
            encode();
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
            cout << "Time taken to encode a message: " << duration.count() << " milliseconds" << endl;
            break;
        }
        case 3:
        {
            auto start = chrono::high_resolution_clock::now();
            decode(root);
            auto stop = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
            cout << "Time taken to decode a message: " << duration.count() << " milliseconds" << endl;
            break;
        }
        case 4: // Add a case for "Exit"
            exitFlag = true; // Set the exit flag to true
            break;
        }
    } while (!exitFlag);

    return 0;
}
