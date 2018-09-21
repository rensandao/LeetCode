
/*
  描述
  单链表整表创建 （头插法）
  随机产生n个元素的值，建立带表头结构的单链线性表L
  
  思路
  1. 声明一结点p和计数器i；
  2. 初始化一空链表L； 
  3. L头结点指向NULL，
  4. 循环插入：
     生成新结点赋给p
     随机数值赋给p数据域
     p结点插入头结点与与前一新结点之间

*/

void CreateListHead(LinkList *L, int n)
{
  LinkList p;
  int i;
  srand(time(0));
  
  *L = (LinkList) malloc(sizeof(Node));
  (*L)->next = NULL;
  
  //p = *L;
  
  for(i=1;i<=n;i++)
  {
    p=(LinkList)malloc(sizeof(Node));   //要在创建个空的过渡结点。
    p->data = rand()%100+1;
    p->next = (*L)->next;
    (*L)->next =p;
  }
  
}
