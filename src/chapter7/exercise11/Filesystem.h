//
// Created by crypt on 5/31/2016.
//

#ifndef CTCI_FILESYSTEM_H
#define CTCI_FILESYSTEM_H

#include <string>
#include <vector>

using namespace std;
namespace ctci {
    class FileSystem;

    class Entry;

    class Directory;

    class File;

    class Entry {
    protected:
        FileSystem &fileSystem;
        string name;
        string owner;
        int permission;
    public:
        Entry(FileSystem &filesystem);

        void setPermission(int permission);

        string getName();

    };

    class File : public Entry {
    private :

        unsigned char *bytes;
        size_t length;
    public:
        File(FileSystem &filesystem) : Entry(filesystem) { }

        char *getBytes();

        void setBytes(unsigned char *bytes, size_t length);
    };

    class Directory : public Entry {

        vector<string> list( /*... predicate ... */ );

        void deleteFile(File *file);

        File *createFile(string filePath);
    };

    class FileSystem {
    private:
        char separator;
        string user;
    public:
        FileSystem(string user) : user(user) { };

        static char getSeparator();

        static string joinPath(string prefix, string suffix);

        File *getFile(string path);

        void createFile(string path);

        void deleteFile(string path);

        void createDirectory(string path);

        void deleteDirectory(string path);
    };

}
#endif //CTCI_FILESYSTEM_H
