//
// Created by Francesco Fiduccia on 15/05/16.
//
#include <iostream>
#include <memory>
#include "GraphNode.h"

shared_ptr<GraphNode> getRoot();

shared_ptr<GraphNode> getPtr();

using namespace std;

atomic_int GraphNode::object_counter = {0};

GraphNode::~GraphNode() {
    cout << "Destroying: " << this->objectId << endl;
}

unordered_set<shared_ptr<GraphNode>> &GraphNode::getNeighbours() {

    return this->neighbours;
}


void GraphNode::addNeighbour(shared_ptr<GraphNode> node) {
    this->neighbours.insert(node);
}


int testGraphNode() {

    shared_ptr<GraphNode> root = getRoot();
    return root->getNeighbours().size() == 1 ? 0 : 1;
}

shared_ptr<GraphNode> getRoot() {
    shared_ptr<GraphNode> root = GraphNode::createManaged();

    root->addNeighbour(GraphNode::createManaged());
    root->addNeighbour(GraphNode::createManaged());
    root->addNeighbour(GraphNode::createManaged());
    root->addNeighbour(GraphNode::createManaged());
    root->addNeighbour(GraphNode::createManaged());
    return root;
}

GraphNode::GraphNode() {
    this->objectId = this->object_counter++;
}

unique_ptr<GraphNode> GraphNode::createManaged() {

    return unique_ptr<GraphNode>(new GraphNode());
}

