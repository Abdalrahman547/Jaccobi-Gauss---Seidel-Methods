#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define en "\n"

void MaxAbsolute(double arrAbs[3], double& MaxAbsolute)
{
    MaxAbsolute = abs(arrAbs[0]);

    if (abs(arrAbs[1]) > MaxAbsolute)
        MaxAbsolute = abs(arrAbs[1]);

    else if (abs(arrAbs[2]) > MaxAbsolute)
        MaxAbsolute = abs(arrAbs[2]);
}

void Jaccobi(int Iterations, double x, double y, double z, double arrAbsX[], double arrAbsY[], double arrAbsZ[], double arrTotalAbs[])

{

    double MaxAbsX, MaxAbsY, MaxAbsZ;

    MaxAbsolute(arrAbsX, MaxAbsX);
    MaxAbsolute(arrAbsY, MaxAbsY);
    MaxAbsolute(arrAbsZ, MaxAbsZ);

    for (int i = 0; i < Iterations; i++)
    {
        double newX = (1.0 / arrAbsX[0]) * (arrTotalAbs[0] - (arrAbsY[0] * y + arrAbsZ[0] * z));
        double newY = (1.0 / arrAbsY[1]) * (arrTotalAbs[1] - (arrAbsX[1] * x + arrAbsZ[1] * z));
        double newZ = (1.0 / arrAbsZ[2]) * (arrTotalAbs[2] - (arrAbsX[2] * x + arrAbsY[2] * y));



        // cout << "When i =  " << i  << ":\n";
        // cout << "\n=====================\n";
        // cout << "Xi+1 = " << newX << ", Yi+1 = " << newY << ", Zi+1 = " << newZ << endl;
        if (i == 0)
        {
            cout << setw(10) << "i" << setw(15) << "Xi+1" << setw(15) << "Yi+1" << setw(15) << "Zi+1" << setw(15) << "Eax" << setw(15) << "Eay" << setw(15) << "Eaz" << endl;

        }
        double approximateErrorX = abs((newX - x) / newX);
        double approximateErrorY = abs((newY - y) / newY);
        double approximateErrorZ = abs((newZ - z) / newZ);
        cout << setw(10) << i << setw(15) << newX << setw(15) << newY << setw(15) << newZ << setw(15) << approximateErrorX << setw(15) << approximateErrorY << setw(15) << approximateErrorZ << endl;



        x = newX;
        y = newY;
        z = newZ;
    }
}
void Gauss_Seidel(int Iterations, double x, double y, double z, double arrAbsX[], double arrAbsY[], double arrAbsZ[], double arrTotalAbs[])

{
    double MaxAbsX, MaxAbsY, MaxAbsZ;

    MaxAbsolute(arrAbsX, MaxAbsX);
    MaxAbsolute(arrAbsY, MaxAbsY);
    MaxAbsolute(arrAbsZ, MaxAbsZ);

    for (int i = 0; i < Iterations; i++)
    {
        double newX = (1.0 / arrAbsX[0]) * (arrTotalAbs[0] - (arrAbsY[0] * y + arrAbsZ[0] * z));
        double newY = (1.0 / arrAbsY[1]) * (arrTotalAbs[1] - (arrAbsX[1] * newX + arrAbsZ[1] * z));
        double newZ = (1.0 / arrAbsZ[2]) * (arrTotalAbs[2] - (arrAbsX[2] * newX + arrAbsY[2] * newY));


        // cout << "When i =  " << i  << ":\n";
        // cout << "\n=====================\n";
        // cout << "Xi+1 = " << newX << ", Yi+1 = " << newY << ", Zi+1 = " << newZ << endl;
        if (i == 0)
        {
            cout << setw(10) << "i" << setw(15) << "Xi+1" << setw(15) << "Yi+1" << setw(15) << "Zi+1" << setw(15) << "Eax" << setw(15) << "Eay" << setw(15) << "Eaz" << endl;

        }
        double approximateErrorX = abs((newX - x) / newX);
        double approximateErrorY = abs((newY - y) / newY);
        double approximateErrorZ = abs((newZ - z) / newZ);
        cout << setw(10) << i << setw(15) << newX << setw(15) << newY << setw(15) << newZ << setw(15) << approximateErrorX << setw(15) << approximateErrorY << setw(15) << approximateErrorZ << endl;



        x = newX;
        y = newY;
        z = newZ;
    }
}
int main()


{
    int choise;
    cout << "Choose The Method\n";
    cout << "[1]Jaccobi method\n";
    cout << "[2]Gauss - Seidel method\n";
    cin >> choise;
    if (choise == 1)
    {
        int Iterations;
        cout << "Enter number of iterations : ";
        cin >> Iterations;

        double x, y, z;
        cout << "Enter initial values of x, y and z respectivly\n";
        cin >> x >> y >> z;

        double arrAbsX[3];
        double arrAbsY[3];
        double arrAbsZ[3];
        double arrTotalAbs[3];

        double Q1, Q2, Q3;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter absolute values of x, y, z, and total absoulte\n";
            cin >> arrAbsX[i] >> arrAbsY[i] >> arrAbsZ[i] >> arrTotalAbs[i];
        }

        Jaccobi(Iterations, x, y, z, arrAbsX, arrAbsY, arrAbsZ, arrTotalAbs);


    }
    else if (choise == 2) {
        int Iterations;
        cout << "Enter number of iterations : ";
        cin >> Iterations;

        double x, y, z;
        cout << "Enter initial values of x, y and z respectivly\n";
        cin >> x >> y >> z;

        double arrAbsX[3];
        double arrAbsY[3];
        double arrAbsZ[3];
        double arrTotalAbs[3];

        double Q1, Q2, Q3;

        for (int i = 0; i < 3; i++)
        {
            cout << "Enter absolute values of x, y, z, and total absoulte\n";
            cin >> arrAbsX[i] >> arrAbsY[i] >> arrAbsZ[i] >> arrTotalAbs[i];
        }

        Gauss_Seidel(Iterations, x, y, z, arrAbsX, arrAbsY, arrAbsZ, arrTotalAbs);

    }

    return 0;
}

