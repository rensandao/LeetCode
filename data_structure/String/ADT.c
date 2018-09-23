// ADT




/*
T为非空串。主串S中第pos个字符之后存在与T相等的子串，则返回第一个子串在S中位置，否则返回0.
*/
int Index(String S, String T, int pos)
{
  int n,m,i;
  String sub;
  if(pos>0)
  {
    n = StrLength(S);
    m = StrLength(T);
    i = pos;
    while(i <= n-m+1)
    {
      SubString(sub,S,i,m);
      if( StrCompare(sub,T)!=0)
        ++i;
      else
        return i;   
    
    }  
  }  
  return 0;
}



