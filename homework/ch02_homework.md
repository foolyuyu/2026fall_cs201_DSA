# 第二章作业

### 1

给定一个带头结点的单链表 $L$，设计一个算法将链表中的所有元素原地逆置，要求只使用 $O(1)$ 的额外空间。

```c
// 假设已有结点定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

// 算法函数
void reverse(Node *head) {
	// 为了便于表示，我们在命名规则里面，将旧逻辑中的下一个上一个用Next，Front表示，将新逻辑里面的下一个上一个用next，front表示；
	// 如果进行拆分的话，每次执行的子任务都是：跳转到Next，将这一节点的next修改为Front节点，确定下一个Next
	// 考虑到覆盖情况，每次修改当前结点前，需要保存上一个结点（作为next）和下一个结点进行跳转
	Node *Front = NULL, *now = head->next, *Next; // 跳过带头结点，从真正的第一个节点开始
	// 只有now不为null，即不是链表终点的时候，才修改此处的next指向上一个指针
	while(now) {
		Next = now->next; // 保存下一个结点
		now->next = Front; //把当前结点的next修改为上一个结点的地址，构成倒序
		Front = now; // 保存当前结点为下次修改所用
		now = Next; // 前进一步，这是下一次我要修改的结点
	}
	head->next = Front; // 最后跳出时，now已经是空指针，Front是最后一次处理的结点
}
```
复杂度分析：
	每个数据结点只被访问一次，因此时间复杂度为O(n)，算法只使用了三个指针变量，额外空间复杂度与n无关，故为O(1)

---

### 2

给定一个**不带头结点**的单链表 $L$，其中 `head` 指向第一个数据结点，设计算法找到其中间节点。若节点数为偶数，规定返回两个中间节点中的**后一个**。要求只遍历链表一次。

```c
// 假设已有结点定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

// 算法函数
Node *findMiddle(Node *head) {
	// 使用快慢指针来寻找中间结点
	Node *fast = head, *low = head; // 都以head为起点
	// fast走到null即为遍历的终点
	// A B C D null
	while(fast) {
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			low = low->next;
		}
	}
	return low;
	// 我们具体分析一下，发现刚好凑出来了（）
}
```
复杂度分析：
	快指针每次前进两个结点，慢指针每次前进一个结点，算法只需对链表进行一次遍历，因此时间复杂度为O(n)；只额外使用了两个指针，额外空间复杂度为O(1)

---

### 3

给定两个**无环单链表** $L_1, L_2$，请设计算法判断它们是否相交；若相交，找出它们的第一个公共节点。要求 $O(1)$ 额外空间。

```c
// 假设已有结点定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

// 算法函数
Node *findMerge(Node *head1, Node *head2) {
	// 挨个枚举L1中的指针，和L2里面的进行挨个比对，一样的话就是第一个公共结点
	Node *now1 = head1, *now2 = head2;
	while(now1) {
		while(now2) {
			if (now2 == now1) {
				return now1;
			}
			now2 = now2->next;
		}
		now1 = now1->next;
		now2 = head2;
	}
	return NULL;
}
```
复杂度分析：
	在L1中遍历，并分别和L2中的每一个结点比对，时间复杂度为O(nm)；额外使用了两个指针，空间复杂度为O(1)