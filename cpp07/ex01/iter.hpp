#ifndef ITER_HPP
# define ITER_HPP

// template <typename T>
// void iter(T* arr, unsigned int size, void (*func)(T&))
// {
// 	for (unsigned int i = 0; i < size; i++)
// 		func(arr[i]);
// }

template <typename T>
void iter(T* arr, unsigned int size, void (*func)(const T&))
{
	for (unsigned int i = 0; i < size; i++)
		func(arr[i]);
}

#endif
