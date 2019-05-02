
#include <iostream>

using namespace std;

const int First = 1;
const int Second = 4;
const int Third = 9;

void FirstTask(int a, int b)
{
	int x;
	int t = 5;
	__asm
	{
		mov eax, a
		mov ebx,b
		cmp ebx, eax
		cdq
		JG mark1
		JZ mark2
		mul a
		mul a
		sub eax,t
		idiv ebx
		mov x , eax
		JMP _end
	
		mark1 :
		mov eax,b
		mov ebx,a
		mov edx,0
		idiv ebx
		mov x,eax
		JMP _end

		mark2 :
		mov x,4
		_end :
	}
	wcout << "x = " << x << endl;
}

int main()
{
	int a;
	int b;
	wcout << L"A = ";
	wcin >> a;
	wcout << L"B = ";
	wcin >> b;
	FirstTask(a, b);
	system("pause");
}