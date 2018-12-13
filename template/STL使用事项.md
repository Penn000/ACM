# 二分查找

```cpp
lower_bound()   // 第一个大于等于
lower_bound(a.begin(), a.end(), x)     // 返回一个迭代器
lower_bound(a, a+n, x)     // 返回找到元素的指针

upper_bound()   // 第一个大于
```

# 数组去重

 > unique()并没有将重复的元素删除，而是把重复的元素放到数组的最后面藏起来了

```cpp
sort(arr, arr+n);

// 去重前数组需有序
unique(arr, arr+n); // 返回指针
unique(vec.begin(), vec.end()); // 返回迭代器

// 去重后数组长度
int len = unique(arr, arr+n)-arr;
```

# 全排列

```cpp
// int类型next_permutation
int a[3]={1,2,3};
do{
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
}while(next_permutation(a,a+3));

// char类型next_permutation
char ch[205];
cin>>ch;
sort(ch,ch+strlen(ch));
char *first =ch;
char *last=ch+strlen(ch);
do{
    cout<<ch<<endl;
}while(next_permutation(first,last));
```

# 优先队列

```cpp
// 采用默认优先级构造队列
priority_queue<int> pq;

// 最小值优先
priority_queue<int, vector<int>, greater<int> > pq; // 不能写成>>

// 最大值优先
priority_queue<int, vector<int>, less<int> > pq;

// 自定义结构体优先
struct Node{
    int x;

    bool operator< (const Node &node) const{
        return x < node.x;
    }
}
priority_queue<Node> pq;

```