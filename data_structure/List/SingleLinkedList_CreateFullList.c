
/*
  描述
  单链表整表创建 （头插法）
  随机产生n个元素的值，建立带表头结构的单链线性表L
  
  思路
  1. 声明一结点p和计数器i；
  2. 初始化一空链表L； 
  3. L头结点指向NULL；
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
  
  *L = (LinkList) malloc(sizeof(Node));  //建立带头结点单链表
  (*L)->next = NULL;
  
  //p = *L;
  
  for(i=1;i<=n;i++)
  {
    p=(LinkList)malloc(sizeof(Node));   //要再创建一个空的过渡结点。
    p->data = rand()%100+1;
    p->next = (*L)->next;
    (*L)->next =p;
  }
  
}


/*
  描述：
  尾插法！
  
  思路：
  1. 声明一结点p和计数器i；
  2. 初始化一空链表L； 
  3. L头结点指向NULL；
  4. 循环插入：
     生成新结点赋给p
     随机数值赋给p数据域
     p结点插入头结点与与前一新结点之间
  1. 声明一个结点p和计数器i;
  2. 初始化一空链表L
  3. L头结点指向NULL
  4. 循环插入尾部：
     a. 生成新结点赋给p
     b. 随机数值赋给p数据域；
     c. p结点插入尾部，更新链表指针。
      
*/
//方法1，未验证
Status CreateListTail(Linklist *L, int n)
{
  LinkList p,s;
  int i;
  srand(time(0));
  
  *L= (LinkList*) malloc(sizeof(Node));
  (*L)->next = NULL;
  
  for(i=1;i<=n;i++)
  {
    
    p = (LinkList*)malloc(sizeof(Node));
    p->data = rand()%100 +1;  // 控制在0-100之间
    
    if(i==1)
    {
      (*L)->next = p;
      p->next = NULL;
    }   
    else
    {
      p->next = p; 
      p->next = NULL;
    }
    
  }
     
  return OK;  
}

//方法2.

void CreateListTail(LinkList *L, int n)
{
  LinkList p, r;
  int i;
  srand(time(0));
  *L = (LinkList)malloc(sizeof(Node));
  
  r = *L;   //r此时指向头结点。但NULL还并没有设置。
  
  for(i=0;i<n;i++)
  {
    p = (Node *) malloc(sizeof(Node)); //灵活表示
    p->data = rand()%100 +1;
    r->next = p;
    
    r=p;   // 这是本方法的窍门之处。用2个结点，r串接p之后，在替代为p，p再更新，如此直到循环结束。
  }
  
  r->next = NULL;        //最后才把NULL设定完。

}

