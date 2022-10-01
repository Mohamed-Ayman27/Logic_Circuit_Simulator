# Logic_Circuit_Simulator
It's a Code implemented using C++, Which simulates the behavior of logic gates and gets the output of any compinational Logic circuit you enter.
It was implemented using OOP mainly the concepts of Overloading and Friend functions.

![1663849924-3d2f3d0659-Picture2](https://user-images.githubusercontent.com/69655655/192331330-0cf20aff-94f9-4f64-aeb0-a8904736e1fe.png)

* Class *Node* has the following Specifications:

      - Default and non-default Constructor.
      - Provide setters and getters.
      - Overload the operator ostream << to print the node information.
      - Create methods called AND() / OR() / XOR() to perform the logical operation between two nodes objects.
------------------------------------------------------------------------------------------------------------------------------------------------  
* Class *Gate* has the following methods:

      - Default and non-default Constructors.
      - Provide getters and setters for its nodes.
      - Implement the gate types AND / OR / NAND / NOR / XOR / XNOR / NOT.
      - function simulateGate() returns the logic value of the gate according to its type.  
----------------------------------------------------------------------------------------------------------------------------------------------
      
![image](https://user-images.githubusercontent.com/69655655/192333702-516690d6-f589-4eb9-a483-8b5c7c3d5f5e.png)
------------------------------------------------------------------------------------------------------------------------------------------------
* Class *Simulator* which accpets all types of gates then calculate circuits’ outputs, It has the following specifications:

       - array of pointers to Gate and array of pointers to Node.
       - Method postGate() accepts a pointer to a created gate to insert it into the array.
       - Method postNode() accepts a pointer to a created node to insert it into the array.
       - Method FindNode() accepts a string node's name to find it in the container and return its address.
       - Method startSimulate() start the simulation for each gate by looping over the gates container
------------------------------------------------------------------------------------------------------------------------------------------------
Class called "GateGenerator" that generates the nodes and all sepcified gates from the input then post them to the simulator.

* Class *GateGenerator* should have the following specifications:

       - Function parseInput() reads the inputs and parses each keyword ("SIM"/"OUT",..) to the appropriate logic.
       - Function createNode() creates a node and return its address.
       - Function createGate() creates a (AND,OR,...) gates according to the input and return its address, it is advisable to use a factory function to have better practice on polymorphic objects.
