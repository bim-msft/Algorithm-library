// Use malloc and node struct to make the tree dynamic
// Notice the usage of secondary pointer

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef int Type;

const int char_count = 26;
const char base_char = 'a';

typedef struct __node
{
    Type val;
    struct __node* next[char_count];
}
Node;

Node* rt;

void createTree(Node** root)
{
    *root = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < char_count; i++)
    {
        (*root)->val = 0;
        (*root)->next[i] = NULL;
    }
}

void deleteTree(Node* root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < char_count; i++)
    {
        if (root->next[i] != NULL)
            deleteTree(root->next[i]);
    }
    free(root);
}

void insert(Node** root, char* str, int n = -1)
{
    if (n == -1)
        n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if ((*root)->next[str[i] - base_char] == NULL)
        {
            (*root)->next[str[i] - base_char] = (Node*)malloc(sizeof(Node));
            root = &((*root)->next[str[i] - base_char]);
            for (int j = 0; j < char_count; j++)
            {
                (*root)->val = 0;
                (*root)->next[j] = NULL;
            }
        }
        else
            root = &((*root)->next[str[i] - base_char]);

        if (i == n - 1)
            (*root)->val = 1;
    }
}

int query(Node* root, char* str, int n = -1)
{
    if (n == -1)
        n = strlen(str);

    int word_flag = 0;
    for (int i = 0; i < n; i++)
    {
        word_flag = 0;
        if (root->next[str[i] - base_char] != NULL)
        {
            root = root->next[str[i] - base_char];
            if (root->val == 1)
                word_flag = 1;
        }
        else
            break;

        if (word_flag && i == n - 1)
            return 1;
    }
    return 0;
}

int main()
{
    createTree(&rt);
    insert(&rt, "hello");
    printf("%d\n", query(rt, "hello"));
    printf("%d\n", query(rt, "hard"));
    printf("%d\n", query(rt, "he"));
    deleteTree(rt);
    return 0;
}
