class Node:
    def __init__(self,num):
        self.num=num
        self.left=None
        self.right=None
class Bin_tree():
    def __init__(self):
        self.root=None

    def preorder(self,node):
        if node==None:
            return
        print(node.num)
        self.preorder(node.left)
        self.preorder(node.right)

    def inorder(self,node):
        if node==None:
            return
        else:
            self.inorder(node.left)
            print(node.num)
            self.inorder(node.right)

    def postorder(self,node):
        if node==None:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.num)

hw4=Bin_tree()
n1=Node(15)
n2=Node(1)
n3=Node(37)
n4=Node(61)
n5=Node(26)
n6=Node(59)
n7=Node(48)

hw4.root=n1
n1.left=n2
n1.right=n3
n2.left=n4
n2.right=n5
n3.left=n6
n3.right=n7

print('Preorder Traverse\n')
hw4.preorder(hw4.root)

print('Inorder Traverse\n')
hw4.inorder(hw4.root)

print('Postorder Traverse\n')
hw4.postorder(hw4.root)