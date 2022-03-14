#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int Det(int a[10][10],int n)
{
	if (n == 2)
	{
		return(a[0][0] * a[1][1] - a[0][1] * a[1][0]);
	}
	else
	{
		int det=0;
		int C[10][10];
		for (int x = 0; x < n;x++)
		{
			int t = 0;
			for (int i = 1;i < n;i++)
			{
				int z=0;
				for (int j = 0;j < n;j++)
				{
					if (j == x)
						continue;
					C[t][z] = a[i][j];
					z += 1;
				}
				t += 1;
			}
			det = det + (pow(-1, x)) * a[0][x] * Det(C, (n - 1));
		}
	return det;
	}
}
int main()
{
	int x;
	int y;
	int z, t;
	int Z, T;
	int A[10][10];
	int B[10][10];
	int res[10][10]{};//this is for showing the result of product of matrices A and B
	int op;
	int UserInput;
	cout << "insert the size of 2d matrix 'A' then click Enter:\n";

	cin >> z >> t;

	for (x = 0;x < z;x++)
	{
		for (y = 0;y < t;y++)
		{
			cout << "Enter The element: ";
			cin >> UserInput;
			A[x][y] = UserInput;
		}
	}
	cout << "Insert the size of 2d matrix 'B' then click Enter:\n";

	cin >> Z >> T;
	for (x = 0;x < Z;x++)
	{
		for (y = 0;y < T;y++)
		{
			cout << "Enter The element: ";
			cin >> UserInput;
			B[x][y] = UserInput;
		}
	}
	cout << "Enter your operation: ";
	cin >> op;
	switch (op)
	{
	case 1:// convering A to B

		for (x = 0;x < Z;x++)
		{
			for (y = 0;y < T;y++)
			{
				B[x][y] = A[x][y];
			}
		}
		break;


	case 2:// converting B to A
		
		for (x = 0;x < z;x++)
		{
			for (y = 0;y < t;y++)
			{
				A[x][y] = B[x][y];
			}
		}
		break;

	case 3://sum of A and B
		
		for (x = 0;x < z;x++)
		{
			for (y = 0;y < t;y++)
			{
				A[x][y] = A[x][y] + B[x][y];
			}
		}
		break;
	case 4://submission of a and b
	
		for (x = 0;x < z;x++)
		{
			for (y = 0;y < t;y++)
			{
				A[x][y] = A[x][y] - B[x][y];
			}
		}
		break;
	case 5:// product of A and B
		if (t == Z)
		{

			for (x = 0;x < z;x++)//te'dad e radif A*B= te'dad e radif ha e A
			{
				for (y = 0;y < T;y++)//andaze sotoon ha e A*B= te'dad e soton ha e B
				{
					for (int i = 0;i < t;i++)
					{
						res[x][y] += A[x][i] * B[i][y];
					}
					cout << res[x][y] << ' ';
				}
				cout << '\n';
			}
		}
		else cout << "invalid operation\n";
		return 0;
	case 6: //determinant
		char K;
		cout << "Whath matrix do you want to get the determinant? ";
		cin >> K;
		if (K=='A')
		{
			cout << "determinant matrix A is: " << Det(A, z);
		}
		else if(K=='B')
		{
			cout << "determinant matrix B is: " << Det(B, Z);
		}
		
		else
		{
			cout << "invalid input or determinant can't be operated!";
		}
			return 0;
	case 7://product a number into the A matrix
		
		int a;
		cout << "Enter the Coefficient\n";
		cin >> a;
		for (x = 0;x < z;x++)
		{
			for (y = 0;y < t;y++)
			{
				A[x][y] = a * A[x][y];
			}
		}
		break;


	default: 
		{
		cout << "This operation has not identified!";
			return 0;
		}

	}

	cout << "Which matrix should be result: \n";
	char Re;
	cin >> Re;
	switch (Re)
	{
	case 'A':
		cout << "The 'A' matrix is:\n";

		for (x = 0;x < z;x++)
		{
			for (y = 0;y < t;y++)
			{
				cout << A[x][y] << ' ';
			}
			cout << '\n';
		}
		break;
	case'B':
		cout << "The 'B' matrix is:\n";
		for (x = 0;x < z;x++)
		{
			for (y = 0;y < t;y++)
			{
				cout << B[x][z] << ' ';
			}
			cout << '\n';
		}
		break;
	default:
	{
		cout << "unknown user input";
		return 0;
	}
	}

	return 0;
}