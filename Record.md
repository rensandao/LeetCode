### 刷题记录

* 181106 Day1

  144题

* 181107 Day2  雨

  由于隔了很久，今天发现数据结构的一些基本概念又忘记不少。所以又花了一些时间看了`树和二叉树`的基本概念以及基本操作。
  并开始在博客上整理文档，以便加深理解，同时形成系统。

  对于leetcode上的算法题，它的重点放在算法实现上。对于数据的输入以及测试，则是默认提供好的。这不利于自己的编码能力提高。
  所以尽可能地要从头写全代码。包括main(),以及其他的功能函数，都要把基本的轮子写好。整个写程序逻辑是，先打好框架，再写功能实现方法。

  目前的策略调整为：

  1）根据题库顺序选择题，再对应补齐对应的数据结构方面的知识；这意味着刚开始的工作会有很多细节要补，进度会慢。

  2）数据结构重点在于：a. 定义和性质 b.抽象数据类型ADT，包括很多基本操作；这很重要，譬如树或者栈的存储结构的实现。

  3）算法思路，总结分类。

* 181109 Day3 雨转阴

  144题采用栈进行迭代，参考他人。由于涉及基础知识点比较多，所以也花了一整天在补。先做一个整理，同时也是目前来说比较好的方法，姑且称之为`溯源法`。
  譬如本题考查了二叉树，使用栈。那么由此会引出的点有：
  
  1）[树的定义、性质以及存储结构实现](https://www.cnblogs.com/rensandao/p/9925310.html)；进而二叉树的创建，打印等；其中，就二叉树的创建也有顺序和链式的实现方法。
  
  2）为什么想到使用栈？栈的定义、性质以及存储的结构又是怎样？栈的声明与初始化时内存分配问题？
  
  3）树的遍历分为两大类：广度优先（BFS)和深度优先（DFS）。这两种分别是如何实现？
  
  4）深度优先又分为:先序、中序、后序。
  
  5）根据3和4条可以发展成多个题目。这个系列就至少可以达到8个之多。
  
  最后，关于c++基础知识，多看看《c++ primer 4th》 网上暂没找到5th。
  
  综上，前期根据题目涉及的知识点，回溯到相关知识的概念和基本操作。尽可能多地分析为什么，将相关知识点基础弄清楚。再回过头来，解决相关系列的专题。

* 181110 Day4 阴

  今天停留在树的创建方法问题上。写基础文档-树的存储结构之双亲表示法及其变体。

* 181111   双11

  写基础文档——树的存储结构之孩子表示法及扩展。

* 181112 Day5 阴转雨
  
  基础文档——树的存储结构之孩子兄弟表示法。

* 181113 Day6
  
  结构体指针与引用

* 181114 Day7

  花了快两天时间，以问题为导向（溯源法）。从最初的二叉树创建的几种方式开始。引出结构体指针，指针的指针、函数及形参与实参、引用等一系列琐碎的概念。
  
  一直没有串成线。这两天通过《C++ Primer 4th》解决了很多基本语法、概念上的盲点。ps: 这本书在概念等细节部分的描述是很准确到位的，对应的练习题也是很好。
  
* 181115 Day8  小雨

  解决二叉树创建的几种方式代码实现。需整理。

* 181116 Day9　阴有雨

  晚上回来验证测试，比如形参的指针的地址与被调用函数树的root的地址，树在创建时每个结点的地址分配情况等，对二叉树的递归创建底层理解清楚了。需整理。

* 181117 Day10 阴有雨

  对之前内容部分整理:[二叉树的创建，指针与引用的使用](https://www.cnblogs.com/rensandao/p/9973412.html)。
  
* 181118 Day11　雨

  Morris遍历图解

* 181119 Day12-17
  
  morris代码(ps:近期由于弄课程项目，不能分配好精力）
  
* 181125 Day18-31

* 181209 

  间隔实际较长，重新熟悉并理顺二叉树的创建，以及先序遍历递归->用栈实现的思路，并做了[*思路记录*](https://github.com/rensandao/LeetCode/tree/master/144.%20Binary%20Tree%20Preorder%20Traversal)。
	
* 181219

  第094中序遍历 用栈，思路分析与参看代码；第145后序遍历思路分析。开始暴做，是很难有参考思路的。前中后序的操作的都不同。
  
* 181211

  第145后序遍历代码。
  
* 181211

  145思路1-2-3
  
* 181212

* 181213

  [145. Binary Tree Postorder Traversal 用栈的方法，4种方式。](https://github.com/rensandao/LeetCode/blob/master/145.%20Binary%20Tree%20Postorder%20Traversal/solution.h)
  
 * 181214  晴
 
   [102. Binary Tree Level Order Traversal](https://github.com/rensandao/LeetCode/tree/master/102.%20Binary%20Tree%20Level%20Order%20Traversal)
 
   第一种迭代方法，用到了``队列queue结构的知识点（或者deque的用法）``；第二种用到了递归方法，其中对vector容器的操作比较特别，但很好。
  
  * 181215 中雨
  
    [107. Binary Tree Level Order Traversal II](https://github.com/rensandao/LeetCode/blob/master/107.%20Binary%20Tree%20Level%20Order%20Traversal%20II/BinaryTreeLevelOrderTraversalII.cpp) 
    
	两种思路：迭代和递归的方法。主要就是参照102题的两种方法，主要修改部分在对每一层结点的存储方式，用到vector::insert(),和std::inverse()。
  
  * 181216  阴转晴
  
    [103. Binary Tree Zigzag Level Order Traversal](https://github.com/rensandao/LeetCode/blob/master/103.%20Binary%20Tree%20Zigzag%20Level%20Order%20Traversal/BinaryTreeZigzagLevelOrderTraversal.cpp)
  
    写了第一种方法，递归方法。也是根据102题的递归思路进行代码修改。添加了的每层的判断条件，以确定vector的插入方式。用到push_back和insert方法。
  
    第二种方法: 迭代+static 标记（也是用于判别层数，再确定插入方式）。but，提交多次没有ac,但是重新测试那组input，结果却是ok的。然后提交又显示不一
	致。
	
    上述两种插入方式都用到insert()方法，强调的是在单个元素插入时就确定位置；也可以采用整体reverse()的方法，比如将从左右正序插入完的vector反转。
  
  * 181217
  
    1. 基于103题method3：基于method2的修改，使用reverse()方法，设置bool 标记。
	2. 对103题一直不能AC的method2修改为：将while()内部的static 变量改为，放到while()循环体外面的全局变量，其他不变，可以AC。
  
  * 181218
  
  	[099 Recover Binary Tree] 利用morris没有理解清楚，如何在morris算法进行数据的交换。重新做了morris方法，重做了[094 中序遍历morris实现](https://github.com/rensandao/LeetCode/blob/master/094%20Binary%20Tree%20Inorder%20Traversal/solution.h)
	
	
  * 181219
  
  	[144 二叉树前序遍历morris实现](https://github.com/rensandao/LeetCode/blob/master/144.%20Binary%20Tree%20Preorder%20Traversal/BinaryTreePreorderTraversal.cpp)
	
 	Attention： 敲代码出错查半天，其实是程序中 ‘=’ 写成‘==’
	
	知识点： [NULL与nullptr的区别](https://www.cnblogs.com/malecrab/p/5569707.html)
	
	morris后序遍历和99题未理清楚。??
	
	[100 Same Tree](https://github.com/rensandao/LeetCode/blob/master/100.%20Same%20Tree/solution.h)
	
  * 181220
   
    [101 Symmetric Tree](https://github.com/rensandao/LeetCode/blob/master/101.%20Symmetric%20Tree/SymmetricTree.cpp)递归和迭代两条思路，其中迭代循环可以利用栈或队列或双栈或双队列。
	
	100题和101题都用递归和迭代两种思路。关键要知道怎么找到`最小问题核`并解答。
	
	[110 Balanced Binary Tree](https://github.com/rensandao/LeetCode/blob/master/110.%20Balanced%20Binary%20Tree/BalancedBinaryTree.cpp)
  	
	110题一时半会写不出来。因为找不到递归的`最小问题核`。
  
  
  
  
  
  
  
  
  
  


