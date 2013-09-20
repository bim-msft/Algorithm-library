#include<stdio.h>
#define DATA_TYPE int
#define N 1005
int HEAP_SIZE;
DATA_TYPE A[N];
DATA_TYPE PARENT(int i);
DATA_TYPE LEFT (int i);
DATA_TYPE RIGHT (int i);
void MAX_HEAPIFY(DATA_TYPE *A,int i);
void BUILD_MAX_HEAP(DATA_TYPE *A,int len);
void HEAP_SORT(DATA_TYPE *A,int len);
int main () {    
    int t,n,i;    
    scanf("%d",&t);    
    while (t--) {        
        scanf("%d",&n);        
        for (i=1;i<=n;i++) scanf("%d",&A[i]);        
        HEAP_SORT(A,n);        
        for (i=1;i<n;i++) printf("%d ",A[i]);        
        printf("%d\n",A[n]);    
    }    
    return 0;
}
DATA_TYPE PARENT(int i) {    
    return (int)(i/2);
}
DATA_TYPE LEFT (int i) {    
    return 2*i;
}
DATA_TYPE RIGHT (int i) {    
    return 2*i+1;
}
void MAX_HEAPIFY(DATA_TYPE *A,int i) {    
    int l,r,largest;    
    DATA_TYPE temp;    
    l = LEFT(i);    
    r = RIGHT(i);    
    if (l<=HEAP_SIZE && A[l]>A[i]) largest = l;    
    else largest = i;    
    if (r<=HEAP_SIZE && A[r]>A[largest]) largest = r;    
    if (largest != i) {        
        temp = A[i];        
        A[i] = A[largest];        
        A[largest] = temp;        
        MAX_HEAPIFY(A,largest);    
    }
}
void BUILD_MAX_HEAP(DATA_TYPE *A,int len) {    
    HEAP_SIZE = len;    
    int i;    
    for (i=(int)(len/2);i>=1;i--) {        
        MAX_HEAPIFY(A,i);    
    }
}
void HEAP_SORT(DATA_TYPE *A,int len) {    
    DATA_TYPE temp;    
    int i;    
    BUILD_MAX_HEAP(A,len);    
    for (i=len;i>=2;i--) {        
        temp = A[1];        
        A[1] = A[i];        
        A[i] = temp;        
        HEAP_SIZE --;        
        MAX_HEAPIFY(A,1);    
    }
}
