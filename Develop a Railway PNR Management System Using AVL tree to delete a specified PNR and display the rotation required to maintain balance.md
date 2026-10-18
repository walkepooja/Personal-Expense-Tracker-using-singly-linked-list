1.Introduction: 
The Railway PNR Management System is a simple C++ project that uses an AVL Tree to manage PNR numbers.
An AVL Tree is a self-balancing Binary Search Tree. It maintains balance after insertion and deletion operations.
This project allows users to insert PNR numbers, delete a specified PNR, and display PNR records in sorted order.
If the tree becomes unbalanced after deletion, it performs the required rotation to maintain balance.

2.Objective:
-To develop a Railway PNR Management System using an AVL Tree.
-To insert PNR numbers into the tree.
-To delete a specified PNR number.
-To maintain the balance of the tree after deletion.
-To display the rotation required to maintain balance.
-To understand AVL Tree operations practically.

3.Feature:
Insert PNR: Add a new PNR number.
Delete PNR: Delete a specified PNR number.
Display PNR: Display all PNR numbers in sorted order.
Balance Factor: Calculate the balance factor of each node.
Automatic Balancing: Balance the tree after deletion.
Rotation Display: Display the rotation performed to maintain balance.
Search PNR: Check whether a PNR number exists in the tree.


5. Algorithm:
Algorithm for Insertion
Start.
Enter the PNR number.
Insert the PNR according to Binary Search Tree rules.
Update the height of the node.
Calculate the balance factor.
Perform the required rotation if the tree becomes unbalanced.
Display the updated tree.
Stop.

6.Technology use in Project:
Data Structure: AVL Tree (Self-Balancing Binary Search Tree)
Concepts Used: Insertion, Deletion, Searching and Tree Traversal.
AVL Rotations: LL, RR, LR and RL rotations.
Compiler: C++ Compiler.
Standard Library: C++ Standard Input/Output (iostream).

7.Flowchart:
Start
↓
Display Menu
↓
Enter Choice
↓
Insert / Delete / Display / Search PNR
↓
Update Tree Height
↓
Calculate Balance Factor
↓
Is the Tree Unbalanced?
Yes: Perform the required rotation.
No: Continue without rotation.
↓
Display Updated Tree
↓
Return to Menu or Exit
↓
Stop

8.Conclusion:
The Railway PNR Management System using an AVL Tree demonstrates how a self-balancing tree can be used to manage PNR numbers efficiently.
The project supports insertion, deletion, and display operations.
After deleting a specified PNR, the system checks the balance factor and performs the required rotation to maintain the AVL Tree properties.
This project helps students understand AVL Tree operations, balance factors, and rotations through a practical C++ application.
