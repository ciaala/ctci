
//
// Created by crypt on 23/07/16.
//

#include "DocumentRespaceAlgorithm.h"
#include "DocumentRespaceSolution.h"
#include <queue>
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
        queue<DocumentRespaceSolution *> solutions;
        solutions.push(solution);
        // while there are more
        // while the
        //      front most solution is not at maximum length
        //      front most solution is not at freeSpace 0
        while (!solutions.empty() &&
               (solutions.front()->getPosition() != 30 || solutions.front()->getFreeSpace() != 0)) {
            solution = solutions.front();
            solution->branch();

            cout << "Adding " << solution->getChildren().size() << "branches" << endl;
            for_each(solution->getChildren().begin(), solution->getChildren().end(),
                     [&solutions](auto item) {
                         solutions.push(item.second);
                     }
            );

            cout << "Analyzed: " << *solution;
            solutions.pop();

        }
        ostringstream ost;
        ost << *solution;
        return ost.str();
    }
}