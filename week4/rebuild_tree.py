# Python program to construct tree using 
# inorder and postorder traversals

class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None

# Function to find index of value in arr[start...end]
# The function assumes that value is present in in[]
def search(arr, start, end, value):
    for i in range(start, end + 1):
        if arr[i] == value:
            return i
    return -1

# Recursive function to construct binary tree of size n
# from Inorder traversal in[] and Postorder traversal
# post[]. Initial values of inStrt and inEnd should
# be 0 and n - 1.
def build_util(inorder, postorder, in_start, in_end, post_index):
    if in_start > in_end:
        return None

    # Pick current node from Postorder traversal using
    # postIndex and decrement postIndex
    node = Node(postorder[post_index[0]])
    post_index[0] -= 1

    # If this node has no children then return
    if in_start == in_end:
        return node

    # Else find the index of this node in Inorder traversal
    in_index = search(inorder, in_start, in_end, node.data)

    # Using index in Inorder traversal, construct left and
    # right subtrees
    node.right = build_util(inorder, postorder, in_index + 1, in_end, post_index)
    node.left = build_util(inorder, postorder, in_start, in_index - 1, post_index)

    return node

# This function mainly initializes index of root
# and calls buildUtil()
def buildTree(inorder, postorder):
    n = len(inorder)
    post_index = [n - 1]
    a=build_util(inorder, postorder, 0, n - 1, post_index)
    return a

# Print the preorder of a binary tree
def print_preorder(node):
    if node is None:
        return
    print(node.data, end=" ")
    print_preorder(node.left)
    print_preorder(node.right)

if __name__ == "__main__":
    postorder = ["i", "m", "h", "u", "s", "o", "r", "y", "x", "e"]
    inorder = ['m', 'i', 'u', 'h', 'e', 's', 'r', 'o', 'y', 'x']

    root = buildTree(inorder, postorder)
    print_preorder(root)