//
//  main.cpp
//  OOPDS assignment 1
//
//  Created by hizhatt on 12/01/2019.
//  Copyright © 2019 hizhatt. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string fileName = "Batch.txt"; // To make it easy to change the input file name.

//typedef char *ArrayPtr; // User defined type ArrayPtr for dynamic 2d char array using pointer.

// Shape superclass
class Shape {
        int x0,y0,xMax, yMax;
    public:
        void setX0(int x){x0 = x;} // Setter
        void setY0(int y){y0 = y;}
        int getX0(){return x0;} // Getter
        int getY0(){return y0;}
        int getXmax(){return xMax;}
        int getYmax(){return yMax;}
        virtual int getB(){return 0;}
        virtual int getH(){return 0;}
        virtual void print() = 0; // pure virtual, not Shape is an abstract.
};

// Triangle subclass
class Triangle : public Shape {
        int h;
    public:
        Triangle(int h = 0){this->h = h;}
        void setH(int h){this->h = h;} // Setter
        int getH(){return h;} // Getter
        int getB(){return h*2-1;} // Return the base which is h*2-1
        void print();
        void printIn();
};

void Triangle::print(){
    cout << "\nThis triangle has the height of " << h << endl;
    for(int i = 0; i <= h; i++){
        for(int j = i; j < h; j++){
         cout << "  ";
        }
        //for loop to display star equal to row number
        for(int j = 0; j < (2 * i - 1); j++){
         cout << "T ";
        }
        cout << endl;
        }
}

// W I P
/*void Triangle::printIn(Box &b){
    for(int i = 1, k = 0; i <= h; ++i, k = 0){
        for(int space = 1; space <= h-i; ++space){
            b[][] = '.';
        }
        while(k != 2*i-1){
            b[][] = 'T';
            cout << "T ";
            ++k;
        }
        cout << endl;
    }
}*/

// Square subclass
class Square : public Shape {
        int s;
    public:
        Square(int s = 0){this->s = s;}
        void setS(int s){this->s = s;} // Setter
        int getS(){return s;} // Getter
        void print();
};

void Square::print(){
    cout << "\nThis square has the side of " << s << endl;
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= s; ++j) {
            cout << "S ";
        }
        cout << endl;
    }
}

// Rectangle subclass
class Rectangle : public Shape {
        int h, w;
    public:
        Rectangle(int h, int w){this->h = h; this->w = w;}
        void setW(int w){this->w = w;} // Setter
        void setH(int h){this->h = h;}
        int getW(){return w;} // Getter
        int getH(){return h;}
        void print();
};

void Rectangle::print(){
    cout << "\nThis rectangle has the height of " << h <<  " and width of " << w << endl;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cout << "R ";
        }
        cout << endl;
    }
}


/*
// Box class
class Box {
char box[40][40] = {0}; // Since we know the max size is 40, we can use static array. Muahahaha!
int boxRow, boxColumn;
public:
    Box (int a = 0, int b = 0) { // a is row, b is column
        // Create the box
        boxRow = a;
        boxColumn = b;
}
    void fillBox(){
    for (int i=0; i < boxRow; i++)
        for (int j=0; j < boxColumn; j++)
            box[i][j] = '.';
    }

    void printBox () {
        cout << "\nDisplaying the box of " << boxRow << " X " << boxColumn << " :\n";
        for (int i = 0; i < boxRow; i++){
            for (int j = 0; j < boxColumn; j++)
                cout << box[i][j] << " ";
            cout << endl;
        }
    }

    // W I P
      void insertShape(Shape *sh){
        int

    }

};
*/



// MAIN FUNCTION
int main() {

    int tempRow = 0, tempColumn = 0;
    int attemps = 0;
    int noOfTriangle = 0, tempHeightTri1 = 0, tempHeightTri2 = 0, tempHeightTri3 = 0 ;
    int noOfSquare = 0, tempSide1 = 0, tempSide2 = 0, tempSide3 = 0;
    int noOfRectangle = 0, tempHeightRec1 = 0, tempWidth1 = 0, tempHeightRec2 = 0, tempWidth2 = 0, tempHeightRec3 = 0, tempWidth3 = 0 ;
    srand(time(NULL));
    vector<Shape*> vecShape;

    // Gathering data from Batch file
    ifstream inputFile;
    inputFile.open(fileName);
    if (inputFile.is_open()) {
        cout << "File is succesfully opened \n";
        inputFile >> tempRow >> tempColumn >> attemps >> noOfTriangle;
        // Triangle is 0 or 1
        if (noOfTriangle == 0 || noOfTriangle == 1){
            inputFile >> tempHeightTri1 >> noOfSquare;
            if (noOfSquare == 0 || noOfSquare == 1){ // Triangle is 1
                inputFile >> tempSide1 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else if (noOfSquare == 2){ // Triangle is 1
                inputFile >> tempSide1 >> tempSide2 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else if (noOfSquare == 3){ // Triangle is 1
                inputFile >> tempSide1 >> tempSide2 >> tempSide3 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else
                cout << "Error: Please have only 3 or less squares...\n";
        }
        //Triangle is 2
        else if (noOfTriangle == 2){
            inputFile >> tempHeightTri1 >> tempHeightTri2 >> noOfSquare;
            if (noOfSquare == 0 || noOfSquare == 1){ // Triangle is 2
                inputFile >> tempSide1 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else if (noOfSquare == 2){ // Triangle is 2
                inputFile >> tempSide1 >> tempSide2 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else if (noOfSquare == 3){ // Triangle is 2
                inputFile >> tempSide1 >> tempSide2 >> tempSide3 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else
                cout << "Error: Please have only 3 or less squares...\n";
        }
        // Triangle is 3
        else if (noOfTriangle == 3){
            inputFile >> tempHeightTri1 >> tempHeightTri2 >> tempHeightTri3 >> noOfSquare;
            if (noOfSquare == 0 || noOfSquare == 1){ // Triangle is 2
                inputFile >> tempSide1 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else if (noOfSquare == 2){ // Triangle is 3
                inputFile >> tempSide1 >> tempSide2 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else if (noOfSquare == 3){ // Triangle is 3
                inputFile >> tempSide1 >> tempSide2 >> tempSide3 >> noOfRectangle;
                if (noOfRectangle == 0 || noOfRectangle == 1)
                    inputFile >> tempHeightRec1 >> tempWidth1;
                else if (noOfRectangle == 2)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2;
                else if (noOfRectangle == 3)
                    inputFile >> tempHeightRec1 >> tempWidth1 >> tempHeightRec2 >> tempWidth2 >> tempHeightRec3 >> tempWidth3;
                else
                    cout << "Error: Please have only 3 or less rectangles...\n";
            }
            else
                cout << "Error: Please have only 3 or less squares...\n";
        }
        else
            cout << "Error: Please have only 3 or less triangles...\n";

        inputFile.close();

        cout << "No. of row is     : " << tempRow << endl << "No. of column is  : " << tempColumn << endl << "No. of attempts is: " << attemps << endl;
    }
    else {
        cout << "File to open the file! \n";
    }

    // Shapes from Batch file

    // Creating triangle(s)
    if (noOfTriangle == 0)
        cout << "No triangle from Batch file.\n";
    else if (noOfTriangle == 1){
        Shape *t1 = new Triangle(tempHeightTri1);
        vecShape.push_back(t1);
        t1->print();
    }
    else if (noOfTriangle == 2){
        Shape *t1 = new Triangle(tempHeightTri1);
        vecShape.push_back(t1);
        t1->print();
        Shape *t2 = new Triangle(tempHeightTri2);
        vecShape.push_back(t2);
        t2->print();
    }
    else if (noOfTriangle == 3){
        Shape *t1 = new Triangle(tempHeightTri1);
        vecShape.push_back(t1);
        t1->print();
        Shape *t2 = new Triangle(tempHeightTri2);
        vecShape.push_back(t2);
        t2->print();
        Shape *t3 = new Triangle(tempHeightTri3);
        vecShape.push_back(t3);
        t3->print();
    }
    // Creating square(s)
    if (noOfSquare == 0)
        cout << "No square from Batch file.\n";
    else if (noOfSquare == 1){
        Shape *s1 = new Square(tempSide1);
        vecShape.push_back(s1);
        s1->print();
    }
    else if (noOfSquare == 2){
        Shape *s1 = new Square(tempSide1);
        vecShape.push_back(s1);
        s1->print();
        Shape *s2 = new Square(tempSide2);
        vecShape.push_back(s2);
        s2->print();
    }
    else if (noOfSquare == 3){
        Shape *s1 = new Square(tempSide1);
        vecShape.push_back(s1);
        s1->print();
        Shape *s2 = new Square(tempSide2);
        vecShape.push_back(s2);
        s2->print();
        Shape *s3 = new Square(tempSide3);
        vecShape.push_back(s3);
        s3->print();
    }

    // Creating rectangle(s)
    if (noOfRectangle == 0)
        cout << "No rectangle from Batch file.\n";
    else if (noOfRectangle == 1){
        Shape *r1 = new Rectangle(tempHeightRec1, tempWidth1);
        vecShape.push_back(r1);
        r1->print();
    }
    else if (noOfRectangle == 2){
        Shape *r1 = new Rectangle(tempHeightRec1, tempWidth1);
        vecShape.push_back(r1);
        r1->print();
        Shape *r2 = new Rectangle(tempHeightRec2, tempWidth2);
        vecShape.push_back(r2);
        r2->print();
    }
    else if (noOfRectangle == 3){
        Shape *r1 = new Rectangle(tempHeightRec1, tempWidth1);
        vecShape.push_back(r1);
        r1->print();
        Shape *r2 = new Rectangle(tempHeightRec2, tempWidth2);
        vecShape.push_back(r2);
        r2->print();
        Shape *r3 = new Rectangle(tempHeightRec3, tempWidth3);
        vecShape.push_back(r3);
        r3->print();
    }


    // Creating the box object with row and column data
    char box[40][40] = {' '};
    // Fill box with dots
    for (int i=0; i < tempRow; i++)
        for (int j=0; j < tempColumn; j++)
            box[i][j] = '.';
    // Printing out the box
    cout << "\nThis is the requested box.";
    cout << "\nDisplaying the box of " << tempRow << " X " << tempColumn << " :\n";
        for (int i = 0; i < tempRow; i++){
            for (int j = 0; j < tempColumn; j++)
                cout << box[i][j] << " ";
            cout << endl;
        }
    // Fitting shapes into it
    cout << vecShape.at(0)->getH() << endl << vecShape.at(0)->getB() << endl;

    box[0][2] = 'H';
    box[1][1] = 'H';
    box[1][2] = 'H';
    box[1][3] = 'H';
    box[2][0] = 'H';
    box[2][1] = 'H';
    box[2][2] = 'H';
    box[2][3] = 'H';
    box[2][4] = 'H';

    /*
    for (int i = 0, j, k, l; i < 3; i++){
        for (j = 0; j < 2 ; j++){
            box[i][j] = '.';
            cout << "Hello\n";
        }
        for (k = j+1; k < 1; k++)
            box[i][k] = 'T';

        for (l = k+1; l < 2; l++)
            box[i][l] = '.';

    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            box[i][j] = '.';
        }
        for(int j = 0; j < (2 * i - 1); j++){
            box[i][j] = 'T';
        }
        cout << endl;
        }
*/
    // Display again
    cout << "\nDisplaying the box of " << tempRow << " X " << tempColumn << " :\n";
        for (int i = 0; i < tempRow; i++){
            for (int j = 0; j < tempColumn; j++)
                cout << box[i][j] << " ";
            cout << endl;
        }

    // Hello!
    cout << "\nEnd of program." << endl;
    return 0;
}
