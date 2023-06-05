class Node: 
     def __init__(self, key): 
         self.key = key 
         self.left = None 
         self.right = None 
  
 def insert(root, key): 
     if root is None: 
         return Node(key) 
     if key < root.key: 
         root.left = insert(root.left, key) 
     else: 
         root.right = insert(root.right, key) 
     return root 
  
 def pre_order(root): 
     if root is not None: 
         print(root.key, end=" ") 
         pre_order(root.left) 
         pre_order(root.right) 
  
 def in_order(root): 
     if root is not None: 
         in_order(root.left) 
         print(root.key, end=" ") 
         in_order(root.right) 
  
 def post_order(root): 
     if root is not None: 
         post_order(root.left) 
         post_order(root.right) 
         print(root.key, end=" ") 
  
 # Read the number of test cases 
 num_test_cases = int(input()) 
  
 # Process each test case 
 for case in range(1, num_test_cases + 1): 
     # Read the number of numbers in the set 
     num_numbers = int(input()) 
  
     # Read the numbers and build the BST 
     numbers = list(map(int, input().split())) 
     root = None 
     for number in numbers: 
         root = insert(root, number) 
  
     # Print the test case number 
     print(f"Case {case}:") 
  
     # Print the pre-order traversal 
     print("Pre.: ", end="") 
     pre_order(root) 
     print() 
  
     # Print the in-order traversal 
     print("In..: ", end="") 
     in_order(root) 
     print() 
  
     # Print the post-order traversal 
     print("Post: ", end="") 
     post_order(root) 
     print() 
  
     # Print a blank line after each test case 
     print()