#include <iostream>
#include <vector>

#include "Vector.hpp"

int main() {
    
    Vector<double> data = { 1., 2., 3., 4., 5., 6., 7., 8., 9. };

    Vector<int> data32(Vector<double> data2 = { 1.55, 2.32 });

    Vector<double> vec0(data);

    Iterator<double> iterator = vec0.begin();

    try 
	{
        Vector<double> vec(data);
        const Vector<double> vec2(vec);

        Vector<double> vec3 = vec + vec2;
        Vector<double> vec4 = vec3 * 3;
        Vector<double> vec5 = vec4 / 2;
        
        vec = {1, 10, 3, 4, 5, 6, 7, 8, 9};

        vec5[4] = 2;

        Vector<int> vec6 = {2, 3, 4, 5};
        Vector<float> vec7 = {2.5f, 5.f};
        
        Iterator<double> it1 = vec.begin();
        it1++;
        vec2.norm();
        
        if (vec == vec2)
            std::cout << "vec == vec2" << std::endl;

        double sum = vec3*vec4;
        //std::cout << data32 << std::endl;
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
