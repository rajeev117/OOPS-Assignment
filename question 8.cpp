
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Book {
    std::string name;
    std::string author;
};

std::vector<Book> read_books(const std::string& file_path) {
    std::vector<Book> books;
    std::ifstream file(file_path);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, author;
        std::getline(ss, name, ',');
        std::getline(ss, author, ',');

        books.push_back({name, author});
    }

    return books;
}

void sort_books_by_author(std::vector<Book>& books) {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.author < b.author;
    });
}

void write_books(const std::string& file_path, const std::vector<Book>& books) {
    std::ofstream file(file_path);
    for (const auto& book : books) {
        file << book.name << "," << book.author << "\n";
    }
}

int main() {
    std::string input_file = "C:\\Users\\Rajeev\\Downloads\\books.txt";
    std::string output_file = "C:\\Users\\Rajeev\\Downloads\\sorted_books.txt";

    std::vector<Book> books = read_books(input_file);
    sort_books_by_author(books);
    write_books(output_file, books);

    return 0;
}
