##### [ 来源 ](http://hzwer.com/8053.html)
格式系本人自己调整

---

$\texttt{\purple{解释与说明}}$

**区间**：数列中连续一段的元素

**区间操作**：将某个区间[a,b]的所有元素进行某种改动的操作

**块**：我们将数列划分成若干个不相交的区间，每个区间称为一个块

**整块**：在一个区间操作时，完整包含于区间的块

**不完整的块**：在一个区间操作时，只有部分包含于区间的块，即区间左右端点所在的两个块

$\texttt{\green{分块入门 1}}$
> **给出一个长为n的数列，以及n个操作，操作涉及区间加法，单点查值。**

这是一道能用许多数据结构优化的经典题，可以用于不同数据结构训练。
数列分块就是把数列中每m个元素打包起来，达到优化算法的目的。
以此题为例，如果我们把每m个元素分为一块，共有n/m块，每次区间加的操作会涉及$O(n/m)$个整块，以及区间两侧两个不完整的块中至多2m个元素。
我们给每个块设置一个加法标记（就是记录这个块中元素一起加了多少），每次操作对每个整块直接$O(1)$标记，而不完整的块由于元素比较少，暴力修改元素的值。
每次询问时返回元素的值加上其所在块的加法标记。

这样每次操作的复杂度是$O(\frac{n}{m})+O(m)$，根据均值不等式，当m取√n时总复杂度最低，为了方便，我们都默认下文的分块大小为$\sqrt{n}$。

$\texttt{\green{分块入门 2}}$
> **给出一个长为n的数列，以及n个操作，操作涉及区间加法，询问区间内小于某个值x的元素个数。**

有了上一题的经验，我们可以发现，数列简单分块问题实际上有三项东西要我们思考：

对于每次区间操作：

 1.**不完整的块**的$O(\sqrt{n})$个元素怎么处理？

 2.$O(\sqrt{n})$个 **整块** 怎么处理？

 3.要预处理什么信息（复杂度不能超过后面的操作）？
 
我们先来思考只有询问操作的情况，不完整的块枚举统计即可；而要在每个整块内寻找小于一个值的元素数，于是我们不得不要求块内元素是有序的，这样就能使用二分法对块内查询，需要预处理时每块做一遍排序，复杂度$O(n~logn)$，每次查询在$\sqrt{n}$个块内二分，以及暴力$2\sqrt{n}$个元素，总复杂度$O(n~logn+n\sqrt{n}~·~log\sqrt{n})$。
可以通过均值不等式计算出更优的分块大小，就不展开讨论了
那么区间加怎么办呢？
套用第一题的方法，维护一个加法标记，略有区别的地方在于，不完整的块修改后可能会使得该块内数字乱序，所以头尾两个不完整块需要重新排序，复杂度分析略。
在加法标记下的询问操作，块外还是暴力，查询小于$（x – 加法标记）$的元素个数，块内用$（x – 加法标记）$作为二分的值即可。

$\texttt{\green{分块入门 3}}$
> **给出一个长为n的数列，以及n个操作，操作涉及区间加法，询问区间内小于某个值x的前驱（比其小的最大元素）。**

$n<=100000$
其实是为了区分暴力和一些常数较大的写法。

接着第二题的解法，其实只要把块内查询的二分稍作修改即可。

不过这题其实想表达：可以在块内维护其它结构使其更具有拓展性，比如放一个 set ，这样如果还有插入、删除元素的操作，会更加的方便。

**分块的调试检测技巧：**

可以生成一些大数据，然后用两份分块大小不同的代码来对拍，还可以根据运行时间尝试调整分块大小，减小常数。