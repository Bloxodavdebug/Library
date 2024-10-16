#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SOURCES = 100;
const string FILENAME = "library_data.txt";

struct InformationSource {
    string title;
    string author;
    string category;
    string type;
    int year;
};

InformationSource sources[MAX_SOURCES];
int count_ = 0;

void addSource(string title, string author, string category, string type, int year) {
    if (count_ < MAX_SOURCES) {
        sources[count_].title = title;
        sources[count_].author = author;
        sources[count_].category = category;
        sources[count_].type = type;
        sources[count_].year = year;
        count_++;
    }
    else {
        cout << "The library is full!" << endl;
    }
}

void deleteSource(const string& title) {
    for (int i = 0; i < count_; i++) {
        if (sources[i].title == title) {
            sources[i].title = "";
            cout << "Source '" << title << "' deleted." << endl;
            return;
        }
    }
    cout << "Source '" << title << "' not found." << endl;
}

void searchBooks(const string& author, const string& title) {
    bool found = false;
    for (int i = 0; i < count_; i++) {
        if (sources[i].type == "book" and
            (author.empty() || sources[i].author == author) and
            (title.empty() || sources[i].title == title)) {
            cout << "Found Book: Title: " << sources[i].title
                << ", Author: " << sources[i].author
                << ", Category: " << sources[i].category
                << ", Year: " << sources[i].year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found." << endl;
    }
}


void searchMagazines(const string& title, int year) {
    bool found = false;
    for (int i = 0; i < count_; i++) {
        if (sources[i].type == "magazine" and
            (title.empty() || sources[i].title == title) and
            (year == 0 || sources[i].year == year)) {
            cout << "Found Magazine: Title: " << sources[i].title
                << ", Year: " << sources[i].year << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No magazines found." << endl;
    }
}

void viewAllSources() {
    for (int i = 0; i < count_; i++) {
        if (!sources[i].title.empty()) {
            cout << "Index: " << i << " - "
                << "Title: " << sources[i].title
                << ", Author: " << sources[i].author
                << ", Category: " << sources[i].category
                << ", Type: " << sources[i].type
                << ", Year: " << sources[i].year << endl;
        }
    }
}

void searchByIndex(int index) {
    if (index >= 0 and index < count_) {
        cout << "Source at index " << index << ":\n";
        cout << "Title: " << sources[index].title
            << ", Author: " << sources[index].author
            << ", Category: " << sources[index].category
            << ", Type: " << sources[index].type
            << ", Year: " << sources[index].year << endl;
    }
    else {
        cout << "Invalid index. Please enter a value between 0 and " << count_ - 1 << ".\n";
    }
}

void selectBooksByAuthor(const string& author) {
    for (int i = 0; i < count_; i++) {
        if (sources[i].type == "book" and sources[i].author == author) {
            cout << "Title: " << sources[i].title << ", Author: " << sources[i].author << endl;
        }
    }
}

void selectBooksByCategory(const string& category) {
    for (int i = 0; i < count_; i++) {
        if (sources[i].type == "book" and sources[i].category == category) {
            cout << "Title: " << sources[i].title << ", Category: " << sources[i].category << endl;
        }
    }
}

void selectMagazinesByYear(int year) {
    for (int i = 0; i < count_; i++) {
        if (sources[i].type == "magazine" and sources[i].year == year) {
            cout << "Title: " << sources[i].title << ", Year: " << sources[i].year << endl;
        }
    }
}

int countBooksByCategory(const string& category) {
    int bookCount = 0;
    for (int i = 0; i < count_; i++) {
        if (sources[i].type == "book" and sources[i].category == category) {
            bookCount++;
        }
    }
    return bookCount;
}

void saveToFile() {
    ofstream file(FILENAME);
    if (file.is_open()) {
        for (int i = 0; i < count_; i++) {
            if (!sources[i].title.empty()) {
                file << sources[i].title << ";"
                    << sources[i].author << ";"
                    << sources[i].category << ";"
                    << sources[i].type << ";"
                    << sources[i].year << endl;
            }
        }
        file.close();
        cout << "Library data saved to file." << endl;
    }
    else {
        cout << "Error opening file for writing." << endl;
    }
}

void loadFromFile() {
    ifstream file(FILENAME);
    count_ = 0;
    if (file.is_open()) {
        while (getline(file, sources[count_].title, ';') and count_ < MAX_SOURCES) {
            getline(file, sources[count_].author, ';');
            getline(file, sources[count_].category, ';');
            getline(file, sources[count_].type, ';');
            file >> sources[count_].year;
            file.ignore();
            count_++;
        }
        file.close();
        cout << "Library data loaded from file." << endl;
    }
    else {
        cout << "Error opening file for reading." << endl;
    }
}

void SortSources() {
    for (int i = 0; i < count_ - 1; i++) {
        for (int j = 0; j < count_ - i - 1; j++) {
            if (sources[j].type > sources[j + 1].type or (sources[j].type == sources[j + 1].type and sources[j].title > sources[j + 1].title)) {
                swap(sources[j], sources[j + 1]);
            }
        }
    }
}




void displayMenu() {
    cout << R"(
    Library Menu:
    1. View all sources
    2. Add a source
    3. Delete a source
    4. Search for a book
    5. Search for a magazine
    6. Select books by author
    7. Select books by category
    8. Select magazines by year
    9. Count books by category
    10. Search by index
    11. Sort library
    0. Exit
    )";
    cout << "Enter your choice -->  ";
}

int main() {
    loadFromFile();
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nAll sources in the library:\n";
            viewAllSources();
            break;
        }
        case 2: {
            string title, author, category, type;
            int year;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter category: ";
            getline(cin, category);
            cout << "Enter type (book, magazine, newspaper): ";
            getline(cin, type);
            cout << "Enter year: ";
            cin >> year;
            addSource(title, author, category, type, year);
            break;
        }
        case 3: {
            string title;
            cout << "Enter title of the source to delete: ";
            cin.ignore();
            getline(cin, title);
            deleteSource(title);
            break;
        }
        case 4: {
            string author, title;
            cout << "Enter author's name (or leave blank for any): ";
            cin.ignore();
            getline(cin, author);
            cout << "Enter book title (or leave blank for any): ";
            getline(cin, title);
            searchBooks(author, title);
            break;
        }
        case 5: {
            string title;
            int year;
            cout << "Enter magazine title (or leave blank for any): ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter year (0 for any): ";
            cin >> year;
            searchMagazines(title, year);
            break;
        }
        case 6: {
            string author;
            cout << "Enter author's name: ";
            cin.ignore();
            getline(cin, author);
            cout << "\nBooks by " << author << ":\n";
            selectBooksByAuthor(author);
            break;
        }
        case 7: {
            string category;
            cout << "Enter book category: ";
            cin.ignore();
            getline(cin, category);
            cout << "\nBooks in category '" << category << "':\n";
            selectBooksByCategory(category);
            break;
        }
        case 8: {
            int year;
            cout << "Enter year: ";
            cin >> year;
            cout << "\nMagazines from " << year << ":\n";
            selectMagazinesByYear(year);
            break;
        }
        case 9: {
            string category;
            cout << "Enter book category: ";
            cin.ignore();
            getline(cin, category);
            int bookCount = countBooksByCategory(category);
            cout << "There are " << bookCount << " books in category '" << category << "'.\n";
            break;
        }
        case 10: {
            int index;
            cout << "Enter index to search for: ";
            cin >> index;
            searchByIndex(index);
            break;
        }
        case 11: {
            cout << "\nAll sources in the library (sorted):\n";
            SortSources(); 
            viewAllSources(); 
            break;
        }

        case 0:
            cout << "Exiting the program.\n";
            saveToFile();
            break;
        default:
            cout << "Invalid choice \n";
        }
    } while (choice != 0);
}
