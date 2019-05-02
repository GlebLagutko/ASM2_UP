#include <iostream> 

using namespace std;

void NumberOfDigits(int a)
{
	int n;
	int t = 10;
	_asm
	{   mov ecx, 0
		mov eax, a
		mark :
	cdq
		idiv t
		add ecx, 1
		cmp eax, 0
		jne mark
		mov n, ecx
	}
	cout << "NUMBER OF DIGITS: " << n << endl;

}


int FindCountOfBinaryUnits(int x)

{
	int c = 0;
	int z = 0;
	int t = 2;
	_asm {
		mov eax, x
		beg :
		cdq
			idiv t
			add c, edx
			cdq
			cmp eax, z
			jg beg
			jng end_
			end_ :
	}
	wcout << L"Count  = "  << c << endl;
	return c;
}

void FindOddOrEven(int x) {
	int c = 0;
	_asm {
		mov eax, x
		test eax, 1
		jz not_p
		jmp end_
		not_p :
		mov c, eax
			end_ :
	}
	if (c == x) {
		wcout << L"Count - even" << endl;
	}
	else wcout << L"Count - Odd" << endl;
}


void main()
{
	
	int a;
	int c;
	while (true) {
		wcout << L"Input : ";
		wcin >> a;

		NumberOfDigits(a);
		c = FindCountOfBinaryUnits(a);
		FindOddOrEven(c);
	}
	system("Pause");
}