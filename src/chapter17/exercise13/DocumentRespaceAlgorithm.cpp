
//
// Created by crypt on 23/07/16.
//

#include "DocumentRespaceAlgorithm.h"
#include "DocumentRespaceSolution.h"
#include <stack>
#include <sstream>

namespace exercise17_13 {
//    const string DocumentRespaceAlgorithm::SNONE = "";

    string DocumentRespaceAlgorithm::respace(const string &document) {
        /*
            int spaces = INT32_MAX;
            DocumentRespaceSolution *solution = new DocumentRespaceSolution(document, dictionary);
            //DocumentRespaceSolution best(document);
            bool solutionIsLast = false;
            while (spaces != 0 && !solutionIsLast) {

                buildSolution(solution);
                if (debug) {
                    cout << *solution << endl;
                }
                solutionIsLast = solution->freeSpace != spaces && spaces < INT32_MAX;

                if (spaces > solution->freeSpace) {
                    // delete best;
                    //best = *solution;
                    spaces = solution->freeSpace;
                    cout << "IMPROVEMENT" << endl;
                    cout << *solution << endl;
                    cout << endl;
                } else {
                    //    delete solution;
                }

                // solution = new DocumentRespaceSolution(document);
            }
            */

        DocumentRespaceSolution *solution = new DocumentRespaceSolution(document, dictionary);
        DocumentRespaceSolution *best = nullptr;
        stack<DocumentRespaceSolution *> solutions;
        solutions.push(solution);
        // while there are more
        // while the
        //      best solution is not at maximum length
        //      best most solution is not at freeSpace 0
        while (!solutions.empty() && (best == nullptr || (best->getFreeSpace() > 0))) {
            solution = solutions.top();
            solutions.pop();

            if ((solution->getPosition() == document.length()) &&
                (best == nullptr || best->getFreeSpace() > solution->getFreeSpace())) {
                best = solution;
            } else {
                solution->branch();
                // cout << "Adding " << solution->getChildren().size() << " branches" << endl;
                if (best == nullptr) {
                    for_each(solution->getChildren().begin(), solution->getChildren().end(),
                             [&solutions](auto item) {
                                 solutions.push(item.second);
                             });
                } else {
                    for_each(solution->getChildren().begin(), solution->getChildren().end(),
                             [&solutions, &best](auto item) {
                                 if (item.second->getFreeSpace() < best->getFreeSpace()) {
                                     solutions.push(item.second);
                                 }
                             });
                }
            }
        }
        ostringstream ost;
        if (best != nullptr) {
            ost << *best;
        }
        return ost.str();
    }

}