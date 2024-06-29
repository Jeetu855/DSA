Evert element on left sub tree of a node is smaller than it and every element on right sub tree is greater than it

- No duplicates
- Inorder of BST gives sorted order
- Number of BST for 'n' nodes : 2nCn/(n+1)

Searching is BST

Average searching time complexity : O(logn)
Worst case searching time complexity : O(n) : for skewed tree

For inserting in a BST we need a tailing pointer

Creating BST = O(nlogn)
Insert : O(n) to insert n elements
Search : O(logn)

To delete a node, need to modify parents pointer
Search for the key, if found, then if key has no child, parents link becomes nullptr
If key to delete has a child, then the child takes its place
To delete root, find its inorder predecessor and inorder successor, to delete root, it will be replaced by either of the two
This is a lot simpler because the inorder predecessor and successor are generally leaf nodes so no need to modify entire tree
To find inorder predecessor, go to left subtree first, then right right right till we reach leaf node

Time to delete : O(logn)
Modification : O(logn)

We can generate BST if we are given preorder or postorder since the inorder of BST is sorted sequence

