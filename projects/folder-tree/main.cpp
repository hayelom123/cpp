#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

void printTree(
    const fs::path &path,
    const std::string &prefix = "",
    bool isLast = true,
    int maxDepth = -1,
    int currentDepth = 0)
{
    if (maxDepth != -1 && currentDepth > maxDepth)
        return;

    std::cout << prefix;

    if (!prefix.empty())
        std::cout << (isLast ? "└── " : "├── ");

    std::cout << path.filename().string() << "\n";

    if (!fs::is_directory(path))
        return;

    std::vector<fs::path> entries;
    for (const auto &entry : fs::directory_iterator(path))
    {
        // Skip hidden files
        std::string name = entry.path().filename().string();
        if (!name.empty() && name[0] == '.')
            continue;

        entries.push_back(entry.path());
    }

    for (size_t i = 0; i < entries.size(); ++i)
    {
        bool last = (i == entries.size() - 1);
        printTree(
            entries[i],
            prefix + (isLast ? "    " : "│   "),
            last,
            maxDepth,
            currentDepth + 1);
    }
}

int main(int argc, char *argv[])
{
    fs::path root = ".";
    int depth = -1;

    if (argc >= 2)
        root = argv[1];

    if (argc == 4 && std::string(argv[2]) == "-L")
        depth = std::stoi(argv[3]);

    if (!fs::exists(root))
    {
        std::cerr << "Path does not exist\n";
        return 1;
    }

    printTree(root, "", true, depth);
    return 0;
}
