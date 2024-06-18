Tree is nodes + edges
if there are 'n' nodes then there will be 'n-1' edges since each node has an edge coming to it except root

binary tree : every node can have maximum of 2 children, not more than that, can have less than 2 children

Number of binary tree using 'N' nodes
unlabelled : (2nCn) / (n+1)  (catlan number)
number of tree with maximum height is 2^(n-1)
for 'N' = 3, number of tree with maximum height is 2^2 = 4
for 'N' = 4, number of tree with maximum height is 2^3 = 8


|Number of Nodes | (2nCn)/(n+1)|
|----------------|-------------|
|       0        |     1       |  
|       1        |     1       |  
|       2        |     2       |  
|       3        |     5       |  
|       4        |     14      |  
|       5        |     42      |  
|       6        |     142     |   

Another trick lets say for 'N' = 6
multiply the values from N = 0 to N = 5
T(6) = 1*42 + 1*14 + 2*5 + 5*2 + 14*1 + 42*1 = 142
T(6) = T(0)*T(5) + T(1)*T(4) + T(2)*T(3) + T(3)*T(2) + T(4)*T(1) + T(5)*T(0)
T(n) = 	$\sum_{i = 1}^{n} T(i-1)*T(i)$   
This is the reucrssive formula
And we get the same answer

labelled : [ (2nCn) / (n+1) ] * n!
first part for shapes, second part for filling

---

#### Height vs Node

minimum nodes = height + 1  (this occusrs when tree is skewed)
maximum nodes = 2^(height+1) - 1 (this occurs when tree is complete binary tree)
proof for maximum nodes
height 0 has 1 node   = 2^0
height 1 has 2 nodes  =2^1  
height 2 has 4 nodes  =2^2
height 3 has 8 nodes  =2^3

ar+ar^2+ar^3  this is geometric progression

sum of numbers in geometric progression = a(r^[k+1] - 1) / (r-1)
a = 1, r=2 
(2^(h+1) - 1) / 2-1 = 2^(h+1) - 1

---

#### Internal nodes vs External Nodes

Number of nodes with degree(0) = number of nodes with degree(2) + 1

#### Strict Binary Tree/ Complete Binary Tree/Proper Binary Tree

A node can have either 0 children or exactly 2 children, cannot have 1 child

##### Height vs Node is Strict Binary Tree

minimum number of nodes = 2*h + 1
maximum numnber of nodes = 2^(h+1) - 1


##### Internal Nodes vs External Nodes of Strict Binary Tree

external nodes = internal nodes + 1


#### m-ary Trees 

'm' here is the maximum degree of a node


Strict m-ary Trees

Strictly have a degree of 'm'

#### Anaylis of Strict m-ary Trees

minimum number of nodes = m*h + 1
maximum number of nodes = (m^(h+1) - 1) / (m-1)

number of external nodes = (m - 1) * number of internal nodes + 1

#### Binary Tree Representation

- Array Representation
- Linked Representation

##### Array Representation

Array indexing start from 1 onwards
For storing binary tree in array we need 2 things 
1) All the elements
2) Relationship between those elements

Elements can be stored in array but how can we maintain the relationship
The index can help to describe relationsip

| Elements |  A  |  B |   C |   D |   E |   F |   G |
|----------|-----|----|-----|-----|-----|-----|-----|
|Index     | 1   |  2 |  3  |   4 |  5  |  6  |  7  |     
|L-Child   | 2   |  4 |  6  |     |     |     |     |   
|R-Child   | 3   |  5 |  7  |     |     |     |     |

Left child at 2*x   (x is index of parent)
Right Child at 2*x + 1 (x is index of parent)

Parent of any node is at floor x/2 (x is index of parent)

Can be Dynamic and can be static

##### Linked Representation of Binary Tree

struct Node{
    struct Node * lchild;
    int data;
    struct Node * rchild;
};

We dont say linked list representation we say linked representation because tree is non linear data structure

Dynamic cause created in heap
n nodes then n+1 null pointers(all leaf nodes have 2 null pointers in binary tree)


#### Full vs Complete Binary Tree

Full Binary Tree : Binary tree of height 'h' having maximum number of nodes 

Complete Binary Tree : Filled from left to right
No blank spaces between elements in array representation
If height is 'h' then till 'h-1' it is full, last level filled left to right

**Full binary tree is always a complete binary tree but not vice-versa**

#### Tree Traversals

Preorder : visit node -> preorder left subtree -> preorder right subtree
Inorder : inorder left subtree -> visit node -> inorder right sub tree
Postorder : postorder left subtree -> postorder right subtree -> visit node
Levelorder : level by level 



