#ifndef DL_LIST_H
#define DL_LIST_H

#include <iostream>
#include <initializer_list>
#include <memory>

namespace mylist { 
template<typename T> // не шаблон 
class BaseList {
	protected:
		int theSize; // все убрать 
		struct Node { 
			T data;
			std::shared_ptr<Node> prev; 
			std::shared_ptr<Node> next; 

			Node( const T & d = T{}, std::shared_ptr<Node> p = nullptr, std::shared_ptr<Node> n = nullptr)
			:data{d}, prev{p}, next{n} {}

			Node( T && d, std::shared_ptr<Node> p = nullptr, std::shared_ptr<Node> n = nullptr)
			:data{std::move(d)}, prev{p}, next{n} {}
		};  // the current number of nodes, except for the head and tail, in this, in *this class 
		std::shared_ptr<Node> head;  // head node
	public:
		int size() const;
		// check if list is empty, namely, no nodes contained except for head, tail
		bool empty() const;
		// delete all elements
		void clear();
		// reverse the order of elements};
};

template<typename T>
class List : public BaseList {
	private:
		void init();  // initialization private function	
		std::shared_ptr<Node> tail;  // tail node
	public: 
		class const_iterator {
			public:
				const_iterator();  // zero-parameter constructor
				const T & operator*() const;  // operator* returns the reference to the data  
				const_iterator & operator++();  // prefix increment operator
				const_iterator operator++(int);  // postfix increment operator
			// postfix ones return a copy of original obj, and then increment by 1
				const_iterator & operator--();  // prefix decrement operator
				const_iterator operator--(int);  // postfix decrement operator
			// comparison operators
				bool operator==( const const_iterator & rhs ) const;
				bool operator!=( const const_iterator & rhs ) const;
			protected:
				std::weak_ptr<Node> current;  // the current node this const_iterator points to
				T & retrieve() const;  // returns the referece to the data in current node
				const_iterator( std::weak_ptr<Node> p );  // protected constructor
				friend class List<T>;
				// the class List<T> can have access to const_iterator's protected data
		};
		class iterator : public const_iterator {
			public:
				iterator();
				T & operator*();
				const T & operator*() const;
			// increment/decrement	
				iterator & operator++();
				iterator operator++(int);
				iterator & operator--();
				iterator operator--(int);
			protected:
				iterator( std::weak_ptr<Node> p);
				friend class List<T>;
		};

	public:  
		// zero-para constructor
		List();
		// destructor
		~List();
		// copy constructor
		List( const List<T> & rhs );
		// move constructor
		List( List<T> && rhs );
		// copy assignment
		const List<T> & operator=( const List<T> & rhs );
		// move assignment
		List & operator=( List<T> && rhs );
		// no automatic type conversion is allowed
		explicit List( int num, const T & val = T{} );
		// constructor with element [start, end)
		List( const_iterator start, const_iterator end );
		// constructor with a copy of each of elements in the initializer_list
		List( std::initializer_list<T> iList );
		// set list to the elements of the initializer list
		List & operator=( std::initializer_list<T> iList );
	// more member functions
		// number of elements
		
		void reverse();
		// reference to the first element
		T & front();
		// reference to the first element, withhold perssion to modify
		const T & front() const;
		// reference to the last element
		T & back();
		// reference to the last element, withhold perssion to modify
		const T & back() const;
		
		void push_front( const T & val );
		// insert to the beginning, alias, insert right after Node* head
		void push_front( T && val );
		// move version insert
		void push_back( const T & val );
		// insert to the end, alias, insert right before Node* tail
		void push_back(T && val );
		// move version insert_back
		void pop_front();
		// delete the first element
		void pop_back();
		// delete the last element

		void remove( const T & val );
		// remove all elements with value val

		template<typename PREDICATE>
		void remove_if( PREDICATE pred );  // remove all elements for which Predicate pred
						   // returns true, pred can take in a function object

		// print out all elements. ofc is deliminitor
		void print( std::ostream & os, char ofc = ' ' ) const;

		iterator begin();  // returns a copy of iterator that references the begining node
		const_iterator begin() const;
		iterator end();  // returns a copy of iterator that reference the end node
		const_iterator end() const;
		iterator insert( iterator itr, const T & val );
		// insert val ahead of itr
		iterator insert( iterator itr, T && val );  // move version
		iterator erase( iterator itr );  // erase one element
		iterator erase( iterator start, iterator end );
		// erase from start to end, not including end however. Alias, erase [start, end)


}; // end of List() defination

// overloading comparison operator
template<typename T>
bool operator==( const List<T> & lhs, const List<T> & rhs );

template<typename T>
bool operator!=( const List<T> & lhs, const List<T> & rhs );

// overloading output operator
template<typename T>
std::ostream & operator<<( std::ostream & os, const List<T> & lst );
// include the implementation file down here
#include "List.hpp"	// integrate the implementation file to head file as a whole
} // end of namespace mylist
#endif
