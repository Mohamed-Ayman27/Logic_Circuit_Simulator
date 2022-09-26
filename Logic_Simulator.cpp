//============================================================================
// Name        : Logic_Simulator.cpp
// Author      : Mohammed Ayman
// Version     :
// Copyright   : Your copyright notice
// Description : Logic Simulator
//============================================================================

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;




					/********************Class Node*********************/
class Node
{
private:
	string name;
	int data;
public:
	/********** Constructors **********/
	Node()
	:data(0)
	{

	}
	Node(string arg)
	:name(arg)
	{

	}
	Node(int data)
	:data(data)
	{

	}
	Node(const Node &temp)
	:name(temp.name),data(temp.data)
	{

	}
	/********** Setters and Getters **********/

	void SetData(int val) //Sets The Node Value
	{
		data=val;
	}
	void SetName(string arg) //Sets The Node name
	{
		name=arg;
	}
	int GetValue() //Gets The Node Value
	{
		return data;
	}
	string GetName() //Gets The Node Name
	{
		return name;
	}

	/********** Output Stream **********/

	friend ostream& operator<<(ostream& out, const Node& ob) // Overloading
	{
		out <<ob.name<<": "<<ob.data<<endl;
		return out;
	}

	/********** Methods **********/

		/*It performs as the behavior of The Basic gates*/
	int AND(Node in)
	{
		return data & in.data;
	}
	int OR(Node in)
	{
		return data | in.data;
	}
	int XOR(Node in)
	{
		return data ^ in.data;
	}
};



							/********************Class Gate*********************/
class Gate
{
private:
	Node input1;
	Node input2;
	Node output;
	string operation;
public:
	Gate()
	:input1(),input2(),output()
	{

	}
	Gate(Node Input1,Node Input2)
	:input1(Input1),input2(Input2)
	{

	}

		/*****************************Setters and Getters***********************************/


	/************Set & Get Data & name For Input1***********/

	void SetDataIn1(int data) //Set the input1 Data
	{
		input1.SetData(data);
	}
	void SetnameIn1(const string& name) //Set the input1 Name
	{
		input1.SetName(name);
	}
	int GetDataIn1() //Get the input1 Data
	{
		return input1.GetValue();
	}
	string GetNameIn1() //Get the input1 Name
	{
		return input1.GetName();
	}


	/************Set & Get Data & name For Input2***********/
	void SetDataIn2(int data) //Set the input2 Data
	{
		input2.SetData(data);
	}
	void SetnameIn2(const string& name) //Set the input2 Name
	{
		input2.SetName(name);
	}
	int GetDataIn2() //Get the input2 Data
	{
		return input2.GetValue();
	}
	string GetNameIn2() //Get the input2 Name
	{
		return input2.GetName();
	}

	/************Set & Get Data & name For Output***********/
	void SetDataOut(int data) //Set the Output Data
	{
		output.SetData(data);
	}
	void SetnameOut(const string& name)//Set the Output Name
	{
		output.SetName(name);
	}
	int GetDataOut() //Get the Output Data
	{
		return output.GetValue();
	}
	string GetNameOut() //Get the Output Name
	{
		return output.GetName();
	}

	/*******Set and Get operation*******/
	void SetOp(const string& Op) //Set Operation
	{
		operation=Op;
	}
	string GetOp() //Get Operation
	{
		return operation;
	}

	/*******Get a Whole Node*******/
	Node GetInput1()
	{
		return input1;
	}
	Node GetInput2()
	{
		return input2;
	}
	Node GetOutput()
	{
		return output;
	}
		/*****************************Gate Implementation**********************************/

		/*NOT Gate*/
	int NOT_Gate(Node input1)
	{
		return !(input1.GetValue());
	}
		/******AND, NAND******/
	int AND_Gate(Node input1,Node input2)
	{
		return input1.AND(input2);
	}

	int NAND_Gate(Node input1,Node input2)
	{
		return !(input1.AND(input2));
	}

		/******OR, NOR******/
	int OR_Gate(Node input1,Node input2)
	{
		return input1.OR(input2);
	}

	int NOR_Gate(Node input1,Node input2)
	{
		return !(input1.OR(input2));
	}

		/*****XOR, XNOR*****/
	int XOR_Gate(Node input1,Node input2)
	{
		return input1.XOR(input2);
	}

	int XNOR_Gate(Node input1,Node input2)
	{
		return !(input1.XOR(input2));
	}

	/*****************************Gate Implementation**********************************/
	int simulateGate(Gate &gate) //Takes a Gate and according to it's value we perform
								//The gate i entered
	{
		if(gate.operation=="AND")
		{
			 gate.output.SetData(AND_Gate(gate.input1, gate.input2));
		}
		else if(gate.operation=="NAND")
		{
			 gate.output.SetData(NAND_Gate(gate.input1, gate.input2));
		}
		else if(gate.operation=="OR")
		{
			 gate.output.SetData(OR_Gate(gate.input1, gate.input2));
		}
		else if(gate.operation=="NOR")
		{
			 gate.output.SetData(NOR_Gate(gate.input1, gate.input2));
		}
		else if(gate.operation=="XOR")
		{
			 gate.output.SetData(XOR_Gate(gate.input1, gate.input2));
		}
		else if(gate.operation=="XNOR")
		{
			 gate.output.SetData(XNOR_Gate(gate.input1, gate.input2));
		}
		else if(gate.operation=="NOT")
		{
			 gate.output.SetData(NOT_Gate(gate.input1));
		}
		else // a Default Case
		{
						/*****Do Nothing*****/
		}
		return gate.output.GetValue();
	}
};



					/********************Class Simulator*********************/

class Simulator
{
private:
	Simulator(){}
	/*
	 *static Simulator* instance;
	 */
public:
	vector<Node*>nodes;
	vector<Gate*>gates;

	/*
	 *instance=NULL;
	 *instance()
	 *{
	 *	if(!instance){
	 *	instance=new Simulator();
	 *	}
	 *	return instance;
	 *}
	 *
	 */
	static Simulator& Singleton() 	//For one time object call of this class
	{
		static Simulator sim;
		return sim;
	}

		/***********Pushing into the Vectors*************/
	void postGate(Gate *gate_ptr) // Adds a new Gate to the GateVector
	{
		gates.push_back(gate_ptr);
	}
	void postNode(Node *node_ptr) //Adds a new Node to the NodeVector
	{
		nodes.push_back(node_ptr);

	}

		/*************Search*****************/
	int FindNode(string NodeName) //Find a node at a specific location
	{
		int location=0;

		for(auto Count: nodes) //Loop Over the Whole Vector
		{
			if((*Count).GetName()==NodeName)
			{
				return location;
			}
			location++;
		}
		return -1;
	}
		/**************Start the Simulation****************/
	void startSimulator(Simulator &Sim)
	{
		int SimData;
		string SimName;
		/*
		 * The Function is looping over every Gate
		 * And every Node in each Gate and assigns
		 * each Node Name to it's Value
		 *
		 */
		for(auto k:gates) /*External loop to get the right output
		 	 	 	 	   *Else on some cases the output doesn't come out right
		 	 	 	 	   */
		{
			SimData=(*k).simulateGate(*k);
			SimName=(*k).GetNameOut();
			for(auto i:gates)
			{
				if((*i).GetNameIn1()==SimName)
				{
					(*i).SetDataIn1(SimData);
				}

				else if((*i).GetNameIn2()==SimName)
				{
					(*i).SetDataIn2(SimData);
				}

				else if((*i).GetNameOut()==SimName)
				{
					(*i).SetDataOut(SimData);
				}

				else
				{
					/***Do Nothing***/
				}

			}
		}
	}


	void WholeSimOut() //Prints out the output of all Nodes
	{
		string st;
		for(auto x : gates)
		{
			size_t found = st.find((*x).GetNameIn1());
			// if not found
			if(found == string::npos)
			{
				cout<<(*x).GetInput1();
				st+=(*x).GetNameIn1();
			}

			found=st.find((*x).GetNameIn2());
			// if not found
			if(found == string::npos)
			{
				cout<<(*x).GetInput2();
				st+=(*x).GetNameIn2();
			}

			found=st.find((*x).GetNameOut());
			// if not found
			if(found == string::npos)
			{
				cout<<(*x).GetOutput();
				st+=(*x).GetNameOut();
			}
		}
	}

	void NodeSimOut(string St) //Prints only the node sent to it
	{
		for(auto x : gates)
		{
			if((*x).GetNameIn1()==St)
				cout<<(*x).GetInput1();
			else if((*x).GetNameIn2()==St)
				cout<<(*x).GetInput2();
			else if((*x).GetNameOut()==St)
				cout<<(*x).GetOutput();
		}
	}
};



class GateGenrator
{
public:

	void Update(Simulator& Sim) //Function that updates the value of gate nodes after input
	{
		for(auto x:Sim.gates)
		{
			for(auto y:Sim.nodes)
			{
				if((*y).GetName()==(*x).GetNameIn1())
				{
					(*x).SetDataIn1((*y).GetValue());
				}
				else if((*y).GetName()==(*x).GetNameIn2())
				{
					(*x).SetDataIn2((*y).GetValue());
				}
			}
		}
	}

	Gate* createGate(string GateType,Simulator &sim) //Create a gate of the basic gates and push it to vector
	{
		Gate *g=new Gate();
		string input,output;
		(*g).SetOp(GateType);

		bool isNot=false;
		if(GateType=="NOT")	// if NOT gate this it has only 1 input
			isNot=true;

		cin>>input;
		(*g).SetnameIn1(input);

		if(!isNot)		// if gate is not a NOT gate this is has 2 inputs
		{
			cin>>input;
			(*g).SetnameIn2(input);
		}

		cin>>output;
		(*g).SetnameOut(output);

		return g;

	}

	Node* createNode(string name) // Function That creates a Node and returns it's address
	{
		return new Node(name);
	}

	Node* SET(Simulator Sim) //Sets the specific node according to given value
	{
		int location=-1;

		string name;
		int data;

		cin>>name;
		cin>>data;

		Node* node=new Node();

		location=Sim.FindNode(name);

		if(location==-1)//Not Present before
		{
			(*node).SetData(data);
			(*node).SetName(name);
		}
		else
		{
			Sim.nodes.at(location)->SetData(data);
			delete node;
			return nullptr;
		}

		return node;
	}


	void parseInput(Simulator &Sim)//reads the inputs and parses each keyword ("SIM"/"OUT",..)\
	   	   	   	   	   	   	   	   	 to the appropriate logic.
	{
		string obj;
		cin>>obj;
		while(obj!="SIM")
		{
			 if(obj!="SET" && obj!="OUT") // So it's a gate and we create a gate and post it\
										 	 in the vector
			{
				Sim.postGate(createGate(obj,Sim));
			}
			 if(obj=="SET")
			{
				Node *Test=SET(Sim);
				if(Test==nullptr)
				{
					cin>>obj;
					continue;
				}
				else
				{
					Sim.postNode(Test);
					Update(Sim);
				}
			}
			cin>>obj;
		}

		Sim.startSimulator(Sim); //Input: SIM

			/*Output*/
		cin>>obj;
		string obj2;

		while(obj=="OUT")
		{
			cin>>obj2;
			if(obj2=="ALL")
			{
				Sim.WholeSimOut();
				break;
			}
			else
			{
				Sim.NodeSimOut(obj2);
			}

			cin>>obj2;
		}
	}


};

void start()
{
	Simulator& Sim= Simulator::Singleton();
	GateGenrator GenerateGate;
	GenerateGate.parseInput(Sim);
}


int main() {

	start();

	return 0;
}
