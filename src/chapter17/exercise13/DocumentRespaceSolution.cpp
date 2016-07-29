//
// Created by crypt on 23/07/16.
//

#include "DocumentRespaceSolution.h"

namespace exercise17_13 {


    void DocumentRespaceSolution::branch() {
        if (!this->children.empty()) {
            cerr << "Unexpected extra-call to branch" << endl;
        } else {
            long diff = this->document.length() - this->position;
            //  unsigned int proposedLength = 1;

            for (unsigned long i = 0; i < dictionary.size(); i++) {
                //const string &str = dictionary.at(i);
                const string *str = &dictionary.at(i);
                //unsigned long length = str.length();
                unsigned long long length = str->length();
                if (length <= diff && document.compare(position, length, *str) == 0) {

                    DocumentRespaceSolution *branch = duplicate(str);
                    /*
                        new DocumentRespaceSolution(document, dictionary);
                        branch->words.insert(this->words.begin(), this->words.end());
                        branch->words.emplace(this->position, str);
                        branch->position = this->position + length;
                     */
                    cout << "Emplacing: { pos: " << position << ", str: " << *str << " }" << endl;
                    this->children.emplace(str, branch);
                    //position += length;
                }
            }
            if (position <= document.length()) {

                string skip_character(1, document.at(position));


                const string *str = &skip_character;
                cout << "Skipping: { pos: " << position << ", str: " << *str << " }" << endl;
                DocumentRespaceSolution *branch = duplicate();
                branch->position = this->getPosition() + 1;
                /*
                    new DocumentRespaceSolution(document, dictionary);
                    branch->words.insert(this->words.begin(), this->words.end());
                    branch->words.emplace(this->position, skip_character);
                    branch->position = this->position + skip_character.length();
                 */
                branch->freeSpace = this->freeSpace + 1;
                this->children.emplace(str, branch);
            }
        }
    }

    ostream &operator<<(ostream &ost, const DocumentRespaceSolution &solution) {
        ost << "DocumentRespaceSolution { " << endl;
        ost << "\tfreeSpace: " << solution.freeSpace << "/" << solution.document.size() << "," << endl;
        ost << "\tdocument: " << solution.document << "," << endl;
        vector<unsigned long> positions;
        positions.reserve(solution.words.size());
        for_each(solution.words.begin(), solution.words.end(),
                 [&positions](auto &item) {
                     positions.emplace_back(item.first);

                 });
        sort(positions.begin(), positions.end());
        for_each(positions.begin(), positions.end(),
                 [&solution, &ost](auto &item) {
                     string match = solution.words.at(item);
                     ost << "\t" << item << ": " << match << endl;
                 });

        ost << "}" << endl;

        return ost;
    }

    DocumentRespaceSolution::DocumentRespaceSolution(const string &document, const vector<string> &dictionary)
            : document(document), freeSpace(0), dictionary(dictionary), position(0) {

    }

    unsigned int DocumentRespaceSolution::getFreeSpace() const {
        return freeSpace;
    }

    const unordered_map<const string *, DocumentRespaceSolution *> &DocumentRespaceSolution::getChildren() const {
        return children;
    }


    DocumentRespaceSolution *DocumentRespaceSolution::duplicate(const string *str) {
        DocumentRespaceSolution *solution = new DocumentRespaceSolution(document, dictionary);
        solution->words.insert(this->words.begin(), this->words.end());
        if (str != nullptr) {
            solution->words.emplace(this->position, *str);
            solution->position = this->position + str->length();
        }
        return solution;
    }

    unsigned long DocumentRespaceSolution::getPosition() const {
        return position;
    }
}
