﻿#include <iostream>
#pragma comment(lib, "../Debug/SP02_LIB.lib")
#include "../SP02_LIB/SP02_LIB.h"

int main()
{
	try
	{
		// инициализация экземпляров COM объекта
		SP02HANDLE h1 = SP02::Init();	
		SP02HANDLE h2 = SP02::Init();

		std::cout << "SP02::Adder::Add(h1, 2, 3) = " << SP02::Adder::Add(h1, 2, 3) << "\n";
		std::cout << "SP02::Adder::Add(h2, 2, 3) = " << SP02::Adder::Add(h2, 2, 3) << "\n";

		std::cout << "SP02::Adder::Sub(h1, 2, 3) = " << SP02::Adder::Sub(h1, 2, 3) << "\n";
		std::cout << "SP02::Adder::Sub(h2, 2, 3) = " << SP02::Adder::Sub(h2, 2, 3) << "\n";

		std::cout << "SP02::Multiplier::Mul(h1, 2, 3) = " << SP02::Multiplier::Mul(h1, 2, 3) << "\n";
		std::cout << "SP02::Multiplier::Mul(h2, 2, 3) = " << SP02::Multiplier::Mul(h2, 2, 3) << "\n";

		std::cout << "SP02::Multiplier::Div(h1, 2, 3) = " << SP02::Multiplier::Div(h1, 2, 3) << "\n";
		std::cout << "SP02::Multiplier::Div(h2, 2, 3) = " << SP02::Multiplier::Div(h2, 2, 3) << "\n";

		// освобождение ресурсов
		SP02::Dispose(h1);
		SP02::Dispose(h2);

	}
	catch (int e) { std::cout << "SP02: error = " << e << "\n"; }

}


