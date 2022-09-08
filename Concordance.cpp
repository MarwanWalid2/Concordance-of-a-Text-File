                    ///* Marwan AbdElhameed *///
///* Assignment 3: Computer Engineering Case Study –Concordance of a Text Fil///
#include <iostream>

#include <iomanip>

#include <fstream>

using namespace std;
#define ROW 99999

//functions' prototypes

void createreadfile(int max);
void sorting(int max2, string ptr2[]);

void read() {
    //creating file streams and print error message if they won't open
    string filename;
    cout << "enter name of the file to read from: ";
    cin >> filename;
    ifstream file1;
    file1.open(filename + ".txt", ios:: in );

    //print error message if file does not open
    if (file1.fail()) {
        cerr << "Error opening the file \n";
        exit(0);
    }
     ofstream file2;
    file2.open("read.txt", ios::out);
    if (file2.fail()) {
        cerr << "Error opening the file \n";
        exit(0);
    }

    //declare variables and a dynamic array
    int max;
    char * ptr = new char[ROW];
    char ch;
    for (int i = 0; !file1.eof(); i++) {
        file1.get(ch);
        ptr[i] = ch;
        if (isalpha(ptr[i]) == false) {
            ptr[i] = '\n';

        }
        ptr[i] = tolower(ptr[i]);
        file2 << ptr[i];
        max = i;
    }
    //close files
    file1.close();
    file2.close();
    //call 2nd function
    createreadfile(max);

}
void createreadfile(int max) {
    // create dynamic array of strings and filestream and print error message if it won't open
    string * ptr2 = new string[max];
    ifstream file2;
    int max2;
    file2.open("read.txt", ios:: in );
    //print error message if file does not open
    if (file2.fail()) {
        cerr << "Error opening the file \n";
        exit(0);
    }

    for (int j = 0; !file2.eof(); j++) {

        file2 >> ptr2[j];

        max2 = j;

    }
    sorting(max2, ptr2);
    //close filestream
    file2.close();
}

void sorting(int max, string ptr[]) {

//declare variables
    int index;
    string value;
    for (int j = 0; j < max; j++) {
        index = j;
        value = ptr[j];
        for (int temp = j + 1; temp < max; temp++) {

            if (ptr[temp] < value) {
                value = ptr[temp];
                index = temp;
            }
        }
        ptr[index] = ptr[j];
        ptr[j] = value;

    }

    int * temp = new int[max];
    for (int x = 0; x <= max; x++) {

        temp[x] = 0;
        for (int y = 0; y <= max; y++) {

            if (ptr[x] == ptr[y]) {

                temp[x]++;

            }

        }
    }
    //create a file stream and get the name from the user
    string filename;
    cout << "enter name of the file to save into: ";
    cin>> filename;
    ofstream final;
    final.open(filename + ".txt", ios:: out);
    for (int i = 0; i <= max; i++) {

        if (ptr[i] != ptr[i + 1]) {
            //print final output into the file and print the values to the user
            final << left << setw(15) << ptr[i] << setw(15) << temp[i] << endl;
            cout << left << setw(15) << ptr[i] << setw(15) << temp[i] << endl;

        }

    }
//close file and delete dynamic arrays
final.close();
delete [] ptr;
delete [] temp;
}

//main function
int main() {
    read();

    cout << "done";
    return 0;
}
