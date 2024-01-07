#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &src); //std::stack does not have a public copy constructor, so this line will cause a compilation error.
		MutantStack &operator=(MutantStack const &src);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

};

#include "MutantStack.tpp"

#endif

/*

typedef typename std::stack<T>::container_type::iterator iterator;
This line is defining a type alias named iterator that corresponds to the 
iterator type of the underlying container of std::stack<T>. Here’s a breakdown:

std::stack<T>::container_type: 
This is the type of the underlying container used by std::stack<T>. 
By default, this is std::deque<T>, but it could be any type that satisfies 
the requirements for a stack (provides back, push_back, and pop_back).

std::stack<T>::container_type::iterator: 
This is the iterator type for the underlying container of std::stack<T>.

typedef typename ... iterator;: 
This defines iterator as an alias for the iterator type of the underlying container 
of std::stack<T>. The typename keyword is necessary because 
std::stack<T>::container_type::iterator is a dependent type - 
it depends on the template parameter T.

*/