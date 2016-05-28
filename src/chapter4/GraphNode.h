//
// Created by Francesco Fiduccia on 15/05/16.
//


#ifndef CTCI_GRAPHNODE_H
#define CTCI_GRAPHNODE_H

#include <unordered_set>
#include <memory>
#include <atomic>

using namespace std;

class GraphNode {

private:
    static  atomic_int object_counter;
    int objectId;
    GraphNode();
    unordered_set<shared_ptr<GraphNode>> neighbours;
public:

    GraphNode(const GraphNode &)  = delete;
    GraphNode& operator=(const GraphNode &) = delete;


    unordered_set<shared_ptr<GraphNode>>& getNeighbours();
    virtual ~GraphNode();
    void addNeighbour(shared_ptr<GraphNode> node);
    static unique_ptr<GraphNode> createManaged();
};


#endif //CTCI_GRAPHNODE_H
