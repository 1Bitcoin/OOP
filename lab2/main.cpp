#include <iostream>
#include <vector>

#include "Vector.hpp"

int main() {
    
    Vector<double> data = { 1., 2., 3., 4., 5., 6., 7., 8., 9. };

    Vector<int> test2(5);
	Vector<int> test3 = { 1, 5, 6, 7, 8 };

    Vector<int> test4 = { 1, 228, 6, 7, 8 };

    Vector<int> test(4);

    test2 = test4;

	std::cout << "Resize \n";

	auto begin = test4.begin();
	auto end = test4.end();

	test4.resize(1);

	for (auto a : test4)
	{
		std::cout << " " << a << "\n";
	}

	std::cout << "From std::vector to Vector: \n";

	std::vector<int> v = { 7, 5, 16, 8 };

	test = v;

	std::cout << "isEmpty?: \n";
	std::cout << test.is_empty() << "\n";

	std::cout << "True?: \n";
	bool a = test2 >= test3;
	std::cout << a << "\n";

	/////////////
	Vector<int> vec(std::vector<int> { 227, 125, 1612 });

	Vector<int> vec2({1, 2, 3});

	std::cout << "Collinear?: \n";
	std::cout << vec.collinear(vec2) << "\n";

	std::cout << vec << "\n";

	std::cout << test << "\n";

    std::cout << "From array: \n";
    double arr[5] = {5, 1, 7, 4, 0};
    Vector<double> v4(5, arr);
    std::cout << v4 << "\n";

    //Vector<int> data32(Vector<double> data2 = { 1.55, 2.32 });

    Vector<double> vec0(data);

    Iterator<double> iterator = vec0.begin();

    Vector<int> test1 = {555, 2228, 11537};
	const Vector<int> test12 = { 22568, 2228, 1137 };

	IteratorConst<int> iterator12(test12);
	IteratorConst<int> iterator122 = test12.end();

	IteratorConst<int> iterator1232(test1);

	IteratorConst<int> iterator12323 = test1.cbegin();

	Iterator<int> iterator3(test3);
	Iterator<int> iterator3_copy(iterator3);

	iterator3++;

	iterator3_copy = iterator3 - 1;

	std::cout << "Test iter++: \n";
	std::cout << *iterator3_copy << "\n";


	IteratorConst<int> iterator12324 = test12.end();
	iterator1232 += 2;
	iterator12323 = iterator1232 - 1;

	std::cout << "Test iter+=: \n";
	std::cout << *iterator1232 << "\n";

	std::cout << "Test iter-int: \n";
	std::cout << *iterator12323 << "\n";

	std::cout << "Test cend: \n";
	std::cout << *iterator12324 << "\n";

    Iterator<int> iterator1 = test1.begin();

    std::cout << *iterator1;

    try
	{
        Vector<double> vec(data);
        const Vector<double> vec2(vec);

        Vector<double> vec3 = vec + vec2;
        Vector<double> vec4 = vec3 * 3;
        Vector<double> vec5 = vec4 / 2;
        
        vec = {1, 10, 3, 4, 5, 6, 7, 8, 9};

		Vector<int> test3 = { -1, -5, -6, -7, -8 };
		Vector<int> testing = { -1, -5, -6, -7, -8 };
		Vector<int> testing2 = { -1, -5, -6, -7, -8 };

		Vector<int> temp = test3.add_vector_with_assigment(testing);
		Vector<int> temp1 = test3.substract_vector_with_assigment(testing);
		//test3.make_vector_negative();

		std::cout << "\nTest add: \n";
		std::cout << temp << "\n";

		std::cout << "\nTest substract: \n";
		std::cout << temp1 << "\n";

		std::cout << "\nmultiply_to_number: \n";
		std::cout << testing2.multiply_to_number(-1) << "\n";

		std::cout << "\nmultiply_to_number_with_assigment: \n";
		std::cout << testing2.multiply_to_number(-1) << "\n";

        vec5[4] = 2;

        Vector<int> vec6 = {2, 3, 4, 5};
        Vector<float> vec7 = {2.5f, 5.f};
        
        Iterator<double> it1 = vec.begin();
        it1++;
        test1.norm();
        
        if (vec == vec2)
            std::cout << "vec == vec2" << std::endl;

        double sum = vec3*vec4;

        std::cout << std::endl << "Sum = " << sum << "\n" << vec << vec2 << vec3 << vec4 << vec5 << vec6 << vec7 << "\n" << "\nIterator 1 on: " << *it1 << "\n" << std::endl;

        *it1 = 100;

        std::cout << "vec after iterator modification: " << vec << std::endl;

        std::cout << std::endl << "Printing vec using iterators:";

        for (auto a : vec)
        {
            std::cout << " " << a;
        }

        std::cout << std::endl;

        // weak_ptr test, reassign iterator to scoped vector
        iterator = vec.begin();
    } 
	catch (const CommonError &error) 
	{
        std::cout << "Error occured: " << error.what() << std::endl;
    } 
	catch (const std::exception &error) 
	{
        std::cout << "STL error occured: " << error.what() << std::endl;
    } 
	catch (...) 
	{
        std::cout << "Unknown error occured" << std::endl;
    }


    std::cout << "\nErrors test: " << "\n" << std::endl;


    try 
	{
        std::cout << *iterator;
    } 
	catch (const CommonError &error) 
	{
        std::cout << "Error occured: " << error.what() << std::endl;
    } 
	catch (const std::exception &error) 
	{
        std::cout << "STL error occured: " << error.what() << std::endl;
    } 
	catch (...) 
	{
        std::cout << "Unknown error occured" << std::endl;
    }

    try 
	{
        Vector<double> vec(data);
        Vector<double> vec2(vec);

        vec2.resize(10);
        Vector<double> vec3 = vec + vec2;
    } 
	catch (const CommonError &error) 
	{
        std::cout << "Error occured: " << error.what() << std::endl;
    } 
	catch (const std::exception &error) 
	{
        std::cout << "STL error occured: " << error.what() << std::endl;
    } 
	catch (...) {
        std::cout << "Unknown error occured" << std::endl;
    }

    return 0;
}
