template<typename T>
List<T>::const_iterator::const_iterator() : current{nullptr} {}  // zero-parameter constructor

template<typename T>
const T & List<T>::const_iterator::operator*() const  {  // operator* returns the reference to the data in its nodes, without modifying
	return retrieve();				// the calling object; the data of this node is not subject to change either
}

// increment/decrement
template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++()  {  // prefix increment operator
	current = current->next;  // move the Node's pointer to next reference
	return *this;
}

template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)  {  // postfix increment operator
	auto copy = *this;  // postfix ones return a copy of original obj, and then increment by 1
	current = current->next;
	return copy;
}

template<typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator--()  {  // prefix decrement operator
	current = current->prev;
	return *this;
}

template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)  {  // postfix decrement operator
	auto copy = *this;
	current = current->prev;
	return *this;
}

// comparison operators
template<typename T>
bool List<T>::const_iterator::operator==( const typename List<T>::const_iterator & rhs ) const  {
	return current == rhs.current;
}  // two iterators are equal only if they refer to the same element !

template<typename T>
bool List<T>::const_iterator::operator!=( const typename List<T>::const_iterator & rhs ) const  {
	return current != rhs.current;
}

template<typename T>
T & List<T>::const_iterator::retrieve() const  {  // returns the referece to the data in current node
	return current->data;
}

template<typename T>  // constructor with initialization list
List<T>::const_iterator::const_iterator( typename List<T>::Node* p ) : current{p} {}  // protected constructor

template<typename T>
List<T>::iterator::iterator() {}  // zero-parameter constructor of derived iterator class, doing nothing

template<typename T>
T & List<T>::iterator::operator*()  {  //extract and return the modifiable reference of the element in Node
	return this->current->data;  // derived class has access to protected member data of its base class
}

template<typename T>
const T & List<T>::iterator::operator*() const  {  // non-modifiable elements' reference
	return this->retrieve();  // must call base version of function retrieve() here !
}

// increment/decrement	
template<typename T>
typename List<T>::iterator & List<T>::iterator::operator++()  {  // increment,prefix
	this->current = this->current->next;  // note, because *current is not a member data of derived class, we use this->current to call base's protected data
	return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int)  {  // postfix increment
	auto copy = *this;
	this->current = this->current->next;
	return copy;
}

template<typename T>
typename List<T>::iterator & List<T>::iterator::operator--()  {  // decrement, prefix
	this->current = this->current->prev;
	return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator--(int)  {  // postfix decrement
	auto copy = *this;
	this->current = this->current->prev;
	return *this;
}

template<typename T>
List<T>::iterator::iterator( typename List<T>::Node* p ) : List<T>::const_iterator{p} {}

template<typename T>
// zero-para constructor
List<T>::List()  { init(); }  // call initialization member function

template<typename T>
// destructor
List<T>::~List()  {
	clear();
	delete head;	// release memory
	delete tail;
}

template<typename T>
// copy constructor
List<T>::List( const List<T> & rhs )  {
	init();  // deep copy
	for( auto itr = rhs.begin(); itr != rhs.end(); ++itr )  {
		push_back( *itr );
	}
}

template<typename T>
// move constructor
List<T>::List( List<T> && rhs ) : theSize(rhs.theSize), head{rhs.head}, tail{rhs.tail}  {
// Note: in C++, objects of same class type can have access to each other's private data! Data pretection level is on class level, not object level !
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.tail = nullptr;	// an r-value is eliminated right after instantalized
}

template<typename T>
// copy assignment
const List<T> & List<T>::operator=( const List<T> & rhs )  {
	auto copy = rhs;  // call copy constructor for once
	std::swap( *this, copy );  // swap by reference, not by value
	return *this;
}

template<typename T>	
// move assignment
List<T> & List<T>::operator=( List<T> && rhs )  {
	init();  // clean the data first
	*this = std::move( rhs );
	return *this;
}

template<typename T>
// no automatic type conversion is allowed
List<T>::List( int num, const T & val )  {
	init();
	for( int i = 0; i < num; i++ )  {
		push_back( val );  }
}

template<typename T>
// constructor with element [start, end)
List<T>::List( typename List<T>::const_iterator start, typename List<T>::const_iterator end )  {
	init();
	for( auto itr = start; itr != end; ++itr )  {
		push_back( *itr );  }
}

template<typename T>
// constructor with a copy of each of elements in the initializer_list
List<T>::List( typename std::initializer_list<T> iList )  {
	init();
	for( auto itr = iList.begin(); itr != iList.end(); ++itr )
		push_back( *itr );
}

template<typename T>
// set list to the elements of the initializer list
List<T> & List<T>::operator=( typename std::initializer_list<T> iList )  {
	init();
	for( auto itr = iList.begin(); itr != iList.end(); ++itr )
		push_back( *itr );
	return *this;
}

template<typename T>
// number of elements
int List<T>::size() const  {
	return theSize;
}

template<typename T>
// check if list is empty, namely, no nodes contained except for head, tail
bool List<T>::empty() const  {
	return size() == 0;
}

template<typename T>
// delete all elements
void List<T>::clear()  {
	while( !empty() )  {
		pop_back();
	}
}

template<typename T>
// reverse the order of elements
// wrong idea was displayed with grey text, as follows:
/*void List<T>::reverse()  {
	if( !empty() )  {  // check if empty list, otherwise no need to reverse it
		auto current_ptr = head;  // copy head node where we start swapping pointers from
		std::swap( current_ptr->next, current_ptr->prev );
		do {
			std::swap( current_ptr->prev->next, current_ptr->prev->prev );  // next and prev pointers of Node 1 are swapped by reference !
			current_ptr = current_ptr->prev;  // move forward by one node;
		}while( current_ptr != nullptr );
		std::swap( head->next, head->prev );  // now, the head node becomes tail, because head->prev == nullptr !!
	}
} */
void List<T>::reverse()  {
	if( !empty() ) {
		auto current_ptr = head;
		while( current_ptr != nullptr )  {
			std::swap( current_ptr->next, current_ptr->prev );
			current_ptr = current_ptr->prev;
		}
	}
	std::swap( head, tail );
}

template<typename T>
// reference to the first element
T & List<T>::front()  {
	return *begin();  // List<T>::iterator type
}

template<typename T>
// reference to the first element, withhold perssion to modify
const T & List<T>::front() const  {
	return *begin();  // List<T>::const_iterator type
}

template<typename T>
// reference to the last element
T & List<T>::back()  {
	return *(--end());  // List<T>::iterator type, modifiable *iterator return type
}

template<typename T>
// reference to the last element, withhold perssion to modify
const T & List<T>::back() const  {
	return *(--end());  // List<T>::const_iterator type
}

// data management, push & pop
template<typename T>
void List<T>::push_front( const T & val )  {  // insert to the beginning, alias, insert right after Node* head
	insert( begin(), val );  // insert the node with data == val ahead of begin()	
}

template<typename T>
void List<T>::push_front( T && val )  {  // move version
	insert( begin(), std::move( val ) );
}

template<typename T>
void List<T>::push_back( const T & val )  {  // insert to the end, alias, insert right before Node* tail
	insert( end(), val );  // insert the node with data == val ahead of end()
}

template<typename T>
void List<T>::push_back(T && val )  {  // move version insert_back
	insert( end(), std::move( val ) );
}

template<typename T>
void List<T>::pop_front()  {  // delete the first element
	erase( begin() );
}

template<typename T>
void List<T>::pop_back()  {  // delete the last element
	erase( --end() );
}

template<typename T>
void List<T>::remove( const T & val )  {  // remove all elements with value val
	for( auto itr = begin(); itr != end(); ++itr )  {
		if( *itr == val )
			erase( itr );
	}
}

template<typename T>
template<typename PREDICATE>
void List<T>::remove_if( PREDICATE pred )  {  // remove all elements for which Predicate pred returns true,
	for( auto itr = begin(); itr != end(); ++itr )  {   // pred can take in a function object
		if( pred( *itr ) )
			erase( itr );
	}
}

template<typename T>
// print out all elements. ofc is deliminitor
void List<T>::print( std::ostream & os, char ofc ) const  {
	for( auto itr = begin(); itr != end(); ++itr )  {
		os << *itr << ofc;  }
}

template<typename T>
typename List<T>::iterator List<T>::begin()  {  // returns a copy of iterator that references the begining node
	if( !empty() )  {
		typename List<T>::iterator itr{ head->next };
		return itr;  }
}

template<typename T>
typename List<T>::const_iterator List<T>::begin() const  {
	if( !empty() )  {
		typename List<T>::const_iterator const_itr{ head->next };
		return const_itr;  }
}

template<typename T>
typename List<T>::iterator List<T>::end()  {  // returns a copy of iterator that reference the end node
	typename List<T>::iterator itr{ tail };
	return itr;
}

template<typename T>
typename List<T>::const_iterator List<T>::end() const  {
	typename List<T>::const_iterator const_itr{ tail };
	return const_itr;
}

template<typename T>
typename List<T>::iterator List<T>::insert( typename List<T>::iterator itr, const T & val )  {
	auto* p = itr.current;  // a node pointer p that is a copy of current node
	theSize++;
	auto* nptr = new List<T>::Node{ val, p->prev, p };
	p->prev->next = nptr;
	p->prev = nptr;
	typename List<T>::iterator iter{ nptr };
	return iter;
}

// insert val ahead of itr
template<typename T>
typename List<T>::iterator List<T>::insert( typename List<T>::iterator itr, T && val )  {  // move version
	auto* p = itr.current;
	theSize++;
	auto* nptr = new List<T>::Node{ std::move( val ), p->prev, p };
	p->prev->next = nptr;
	p->prev = nptr;
	typename List<T>::iterator iter{ nptr };
	return iter;
}

template<typename T>
typename List<T>::iterator List<T>::erase( typename List<T>::iterator itr )  {  // erase one element
	auto* p = itr.current;
	typename List<T>::iterator retVal{ p->next };
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	theSize--;
	return retVal;
}

template<typename T>
typename List<T>::iterator List<T>::erase( typename List<T>::iterator start, typename List<T>::iterator end )  {
// erase from start to end, not including end however. Alias, erase [start, end)
	for( auto itr = start; itr != end; )  {
		itr = erase( itr );  }
	return end;
}

template<typename T>
void List<T>::init()  {  // initialization private function
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}

// overloading comparison operator
template<typename T>
bool operator==( const List<T> & lhs, const List<T> & rhs )  {
	bool flag = true;
	if( lhs.size() == rhs.size() )  {
		auto rhs_itr = rhs.begin();
		for( auto lhs_itr = lhs.begin(); lhs_itr !=lhs.end(); ++lhs_itr )  {
			if( *lhs_itr != *rhs_itr )  { flag = false; break; }
			++rhs_itr;
		}
		return flag;
	}
	else
		return false;
}

template<typename T>
bool operator!=( const List<T> & lhs, const List<T> & rhs )  {
	return !( lhs == rhs );
}

// overloading output operator
template<typename T>
std::ostream & operator<<( std::ostream & os, const List<T> & lst )  {
	lst.print( os );
	return os;
}
