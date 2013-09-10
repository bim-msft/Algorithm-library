// About the algorithm: http://uranux.com/res/algorithm/AC自动机基础入门.ppt
                        http://hi.baidu.com/nialv7/item/ce1ce015d44a6ba7feded52d
                        http://www.cppblog.com/mythit/archive/2009/04/21/80633.html

// Dynamic mode can be more flexible instead of high speed
// Static mode is more useful on algorithm competition

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

#define DYNAMIC_AC_MOTON

using namespace std;

typedef int Type;

const int char_count = 26;
const char base_char = 'a';

typedef struct __node
{
    Type val;
    char node_data;
    int vis;
    struct __node* next[char_count];
    struct __node* parent;
    struct __node* prefix;
}
Node;

#ifdef DYNAMIC_AC_MOTON
Node* rt;
#endif

#ifdef STATIC_AC_MOTON
const int max_node_count = 500050;
Node node[max_node_count];
Node* rt = &node[0];
int node_count = 1;
#endif

char text[1000100];

void createTree(Node** root)
{
#ifdef DYNAMIC_AC_MOTON
    *root = (Node*)malloc(sizeof(Node));
#endif
    (*root)->val = 0;
    (*root)->parent = NULL;
    (*root)->prefix = NULL;
    (*root)->vis = 0;

    for (int i = 0; i < char_count; i++)
        (*root)->next[i] = NULL;
}

void deleteTree(Node* root)
{
#ifdef DYNAMIC_AC_MOTON
    if (root == NULL)
        return;
    for (int i = 0; i < char_count; i++)
    {
        if (root->next[i] != NULL)
            deleteTree(root->next[i]);
    }
    free(root);
#endif
#ifdef STATIC_AC_MOTON
    node_count = 1;
#endif
}

void insert(Node** root, char* str, int n = -1)
{
    if (n == -1)
        n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if ((*root)->next[str[i] - base_char] == NULL)
        {
#ifdef DYNAMIC_AC_MOTON
            (*root)->next[str[i] - base_char] = (Node*)malloc(sizeof(Node));
#endif
#ifdef STATIC_AC_MOTON
            (*root)->next[str[i] - base_char] = &node[node_count++];
#endif
            (*root)->next[str[i] - base_char]->parent = *root;
            root = &((*root)->next[str[i] - base_char]);
            (*root)->val = 0;
            (*root)->vis = 0;

            for (int j = 0; j < char_count; j++)
                (*root)->next[j] = NULL;
        }
        else
            root = &((*root)->next[str[i] - base_char]);

        (*root)->node_data = str[i];

        if (i == n - 1)
            (*root)->val++;
    }
}

int query(Node* root, char* text, int n = -1)
{
    int count = 0;

    if (n == -1)
        n = strlen(text);

    Node* p = root;
    int pos = 0;

    do
    {
        while (p != NULL && pos < n)
        {
            Node* cnt = p;
            while (cnt != root && !cnt->vis)
            {
                cnt->vis = 1;
                count += cnt->val;
                cnt = cnt->prefix;
            }
            if (p->next[text[pos] - base_char] != NULL)
            {
                p = p->next[text[pos] - base_char];
                pos++;
            }
            else
                p = p->prefix;
        }

        if (p == NULL)
        {
            p = root;
            pos++;
        }
        if (pos == n)
        {
            Node* cnt = p;
            while (cnt != root && !cnt->vis)
            {
                cnt->vis = 1;
                count += cnt->val;
                cnt = cnt->prefix;
            }
        }
    }
    while (pos < n);

    return count;
}

void make_prefix_pointer(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* cnt = q.front();
        q.pop();

        for (int i = 0; i < char_count; i++)
        {
            if (cnt->next[i] != NULL)
                q.push(cnt->next[i]);
        }

        if (cnt == root)
        {
            cnt->prefix = NULL;
            continue;
        }

        if (cnt->parent == root)
        {
            cnt->prefix = root;
            continue;
        }

        Node* pre = cnt->parent->prefix;

        while (pre != NULL)
        {
            if (pre->next[cnt->node_data - base_char] != NULL)
            {
                cnt->prefix = pre->next[cnt->node_data - base_char];
                break;
            }
            else
                pre = pre->prefix;
        }

        if (pre == NULL)
            cnt->prefix = root;
    }
}
