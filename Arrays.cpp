#include <iostream>
using namespace std;

// Ֆունկցիա գնահատականների տպման համար
void printGrades(int grades[], int n) {
    cout << "Գնահատականներ: ";
    for (int i = 0; i < n; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

// Ֆունկցիա միջին արժեքի հաշվարկի համար
double average(int grades[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += grades[i];
    return (double)sum / n;   // cast to double for decimal result
}


// Ֆունկցիա մաքսիմում և մինիմում գտնելու համար
void findMinMax(int grades[], int n) {
    int max = grades[0], min = grades[0];
    for (int i = 1; i < n; i++) {
        if (grades[i] > max) max = grades[i];
        if (grades[i] < min) min = grades[i];
    }
    cout << "Մաքսիմում = " << max << ", Մինիմում = " << min << endl;
}



// Պղպջակային դասավորում
void bubbleSort(int grades[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                int temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }
    cout << "Դասավորված գնահատականներ (պղպջակային): ";
    printGrades(grades, n);
}



// Դասավորում ընտրությամբ (Selection Sort)
void selectionSort(int grades[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (grades[j] < grades[minIndex]) {
                minIndex = j;
            }
        }
        int temp = grades[minIndex];
        grades[minIndex] = grades[i];
        grades[i] = temp;
    }
    cout << "Դասավորված գնահատականներ (ընտրությամբ): ";
    printGrades(grades, n);
}


// Վերլուծություն ըստ գնահատականների
void analyzeGrades(int grades[], int n) {
    int excellent = 0, good = 0, satisfactory = 0, unsatisfactory = 0;

    for (int i = 0; i < n; i++) {
        if (grades[i] >= 16) excellent++;
        else if (grades[i] >= 12) good++;
        else if (grades[i] >= 8) satisfactory++;
        else unsatisfactory++;
    }

    cout << "Վերլուծություն ըստ գնահատականների:" << endl;
    cout << "Գերազանց (16-20): " << excellent << endl;
    cout << "Լավ (12-15): " << good << endl;
    cout << "Բավարար (8-11): " << satisfactory << endl;
    cout << "Անբավարար (0-7): " << unsatisfactory << endl;
}





int main() {
    int n;
    cout << "Մուտքագրեք ուսանողների քանակը: ";
    cin >> n;

    int* grades = new int[n]; // դինամիկ զանգված
    cout << "Մուտքագրեք " << n << " ուսանողների գնահատականները (0-20): " << endl;
    for(int i = 0; i < n; i++) {
        cin >> grades[i];
    }

    int choice;
    do {
        cout << "\n=== ՄԵՆՅՈՒ ===" << endl;
        cout << "1. Տպել գնահատականները" << endl;
        cout << "2. Միջին արժեք" << endl;
        cout << "3. Մաքսիմում և մինիմում" << endl;
        cout << "4. Դասավորում (պղպջակային)" << endl;
        cout << "5. Դասավորում (ընտրությամբ)" << endl;
        cout << "6. Վերլուծություն ըստ գնահատականների" << endl;
        cout << "0. Ելք" << endl;
        cout << "Ընտրեք գործողությունը: ";
        cin >> choice;

        if(choice == 1) printGrades(grades, n);
        else if(choice == 2) cout << "Միջին արժեքը = " << average(grades, n) << endl;
        else if(choice == 3) findMinMax(grades, n);
        else if(choice == 4) bubbleSort(grades, n);
        else if(choice == 5) selectionSort(grades, n);
        else if(choice == 6) analyzeGrades(grades, n);

    } while(choice != 0);

    delete[] grades; // հիշողության ազատում
    return 0;
}