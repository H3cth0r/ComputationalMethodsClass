/*
===================================================
Name:   Héctor Miranda García
ID:     A01658845
Date:   03/03/2022
===================================================
This is a simple Graphclass, that I'll be using for
implementing some DFA's. 
===================================================
*/


#ifndef GRAPH_CLASS
#define GRAPHT_CLASS

#include <iostream>

#include <list>
#include <vector>
#include <string>
#include <map>

class Node{
    private:
    protected:
    public:
        std::string state_name = NULL;

        Node * ptr_condition_one;
        std::string condition_one;
        
        Node * ptr_condition_two;
        std::string condition_two;

        Node(){}
        Node(const Node & s);
        Node(std::string t_state_name){
            this->state_name = t_state_name;
        }

        // Node(std::string t_state_name, Node * t_ptr_condition_one, std::string t_condition_one, Node * t_ptr_condition_two, std::string t_condition_two){
        //     this->state_name = t_state_name;
        //     this->ptr_condition_one = t_ptr_condition_one;
        //     this->condition_one = t_condition_one;
        //     this->ptr_condition_two = t_ptr_condition_two;
        //     this->condition_two = t_condition_two;
        // }
        Node&operator = (const Node&s);

};


bool check_list_length(std::vector<std::string> & list_states, std::vector<std::string> & list_conditions_one, std::vector<std::string> & list_conditions_two){
    if((list_states.size() == list_conditions_one.size())&&(list_states.size() == list_conditions_two.size())) return true;
    return false;
};


class Graph{
    private:
    protected:
    public:
        std::map<std::string, Node*> graph_map;
        std::vector<std::string> list_states_vector;

        Graph(std::vector<std::string> list_states, std::vector<std::string> list_conditions_one, std::vector<std::string> list_conditions_two){
            list_states_vector = list_states;
            if(check_list_length(list_states, list_conditions_one, list_conditions_two) == false){
                std::cout << "Error list size" << std::endl;
                std::exit(0);
            }
            // Here we are creating a hashmap to create the node.
            for(int i = 0; i < list_states.size(); i++){
                // std::cout << list_states.size() << "\n" ;
                graph_map.insert(std::make_pair(list_states[i], new Node(list_states[i])));
                std::cout << "-> "<< i << "\n";
            }

            // Here we'll be setting the pointers to condition.
            for(int i = 0; i < list_states.size(); i++){
                graph_map[list_states[i]]->ptr_condition_one = graph_map[list_conditions_one[i]];
                graph_map[list_states[i]]->ptr_condition_two = graph_map[list_conditions_two[i]];
            }
        }

        void print(){
            for(int i = 0; i < list_states_vector.size(); i++){
                std::cout << "Name: " << graph_map[list_states_vector[i]]->state_name << "\n";
                std::cout << "Condition_one: " << graph_map[list_states_vector[i]]->ptr_condition_one->state_name << "\n";
                std::cout << "Condition_two: " << graph_map[list_states_vector[i]]->ptr_condition_two->state_name << "\n";
                std::cout << "===================================================" << "\n";
            }
        }

};



#endif