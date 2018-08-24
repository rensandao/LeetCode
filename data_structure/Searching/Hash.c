/* Hash Searching method using c language */

/* 1.定义hash表结构 */

#define SUCCESS 1
#define UNSUCESS 0
#define HASHSIZE 12   /* hash表固定长度 */
#define NULLKEY -32768
typedef struct
{
  int *elem;
  int count;
}HashTable;
int m = 0;

/* 2.初始化hash表 */

Status InitHashTable(HashTable *H)
{
  m = HASHSIZE;
  H->count = m;
  H->elem = (int*)malloc(m*sizeof(int));
  for(int i=0;i<m;i++)
    H->elem[i] = NULLKEY;
  
  return OK;
}

/* 3.构造hash函数 */

int Hash(int key)
{
  return (key % m);                 /* 除留余数法 */
}

/* 4.初始化后，利用hash函数往hash表的插入key。这里就要考虑hash表冲突问题*/

void InsertHash(HashTable *H, int key)
{
  int addr = Hash(key);             
  while(H->elem(addr) != NULLKEY)   /* 如果要插入的表的位置已经有数据了，则冲突，启动冲突机制 */
    addr = (addr+1) % m;            /* 开放定址法，也可以采用其他方法 */
  H->elem[addr] = key;              /* 直到有空位，再插入*/
}

/* hash表数据存储完成后，第二步就是要查找记录 searching key */

Status SearchHash(HashTable H, int key, int *addr)
{
  *addr = Hash(key);               /*求得hash函数转换后的地址*/
  while(H.elem[*addr] != key)      /* 根据地址去hash表中找值，如果不相等；则有可能放在表的其他位置*/
  {
    *addr = (*addr+1) % m;         /*采用存储数据步骤中同样的方法，开放定址法的线性探测来继续搜索*/
    if (H.elem[*addr] == NULLKEY || *addr == Hash(key) )
    {
      return UNSUCCESS;           /* 关键字不存在*/
    }  
  }
  
  return SUCCESS;
}
















