domains
  	ilist = integer*.
  	
predicates
	member(integer, ilist).
	sum(ilist, integer).
	nth(integer, ilist, integer).
	min(ilist, integer).
	max(ilist, integer).
	reverse(ilist, ilist).
	reverse(ilist, ilist, ilist).
	sub_start(ilist, ilist).
	sublist(ilist, ilist).
	delete(ilist, integer, ilist).
	append(ilist, ilist, ilist).
	permutation(ilist, ilist).
	bubble(ilist, ilist).
	insert(integer, integer, ilist, ilist).
	left(ilist, integer, ilist).
	right(ilist, integer, ilist).
	divide(ilist, integer, ilist, ilist).
	qsort(ilist, ilist).
	delete_nth(ilist, integer, ilist).
	%subsection(ilist, ilist, ilist).
	even_pos(ilist, ilist).
	even_num(ilist, ilist). 

clauses
	member(X, [X | _]).
	member(X, [_ | Tail]) :- 
   		 member(X, Tail).
   		 
   	sum([], 0):-!.
	sum([Head|Tail], Sum):-
   		sum(Tail, TailSum),
   		Sum = TailSum + Head.
   			
   	nth(0, [Elem|_], Elem):-!.
	nth(Index, _, _):-
   		Index < 0, !, fail.
	nth(Index, [_|Tail], Elem):-
   		NextIndex = Index - 1,
   		nth(NextIndex, Tail, Elem).
   			
   	min([MinElem], MinElem):-!.
	min([Head|Tail], MinElem):-
   		min(Tail, TailMinElem),
   		TailMinElem < Head, !, 
   		MinElem = TailMinElem;
		MinElem = Head.
		
	max([MaxElem], MaxElem):-!.
	max([Head|Tail], MaxElem):-
   		min(Tail, TailMaxElem),
   		TailMaxElem > Head, !, 
   		MaxElem = TailMaxElem;
		MaxElem = Head.
		
	reverse(List, ReverseList):-
   		reverse(List, [], ReverseList). 

	reverse([], Buffer, Buffer):-! .
	reverse([Head|Tail], Buffer, ReverseList):-
   		reverse(Tail, [Head|Buffer], ReverseList).
   	
   	sub_start([], _):-!.
	sub_start([Head|TailSub], [Head|TailList]):-
   		sub_start(TailSub, TailList).
	
	sublist(Sub, List):-
   		sub_start(Sub, List), !.
	sublist(Sub, [_|Tail]):-
   		sublist(Sub, Tail).
   		
   	delete([], _, []):-!.
	delete([Elem|Tail], Elem, ResultTail):-
   	delete(Tail, Elem, ResultTail), !.
	delete([Head|Tail], Elem, [Head|ResultTail]):-
   		delete(Tail, Elem, ResultTail).
   		
   	append([], List2, List2).
	append([Head|Tail], List2, [Head|TailResult]):-
   		append(Tail, List2, TailResult).
   		
   	permutation([X,Y|T],[Y,X|T]):-
                X > Y,!.
	permutation([X|T],[X|T1]):-
                permutation(T,T1).
	bubble(L,L1):-
     		permutation(L,LL),!, bubble(LL,L1). 
	bubble(L,L).
	
	insert(Elem, 0, List, [Elem|List]).
	insert(Elem, N, [H|T], [H|R]):-
		N1=N-1, 
		insert(Elem, N1, T, R).
		
	%FIXME
	left(List, 0, List):-!.
	left([Head|Tail], N, Result):-
		append(Tail, [Head], X), 
		N1=N-1,
		left(X, N1, Result).
		
		
	 
	right(List, 0, List):-!.
	right([Head|Tail], N, Result):-
		append(Tail, [Head], X),
		N1=N-1, 
		right(X, N1, Result).
		
	divide([], _, [], []):-!.
	divide([Head|Tail], Pivot, [Head|GreaterList], SmallerList):-
  		Head >= Pivot,
  		 !, 
  		divide(Tail, Pivot, GreaterList, SmallerList).
	divide([Head|Tail], Pivot, GreaterList, [Head|SmallerList]):-
  		divide(Tail, Pivot, GreaterList, SmallerList).
		
	qsort([], []).
	qsort([Elem], [Elem]).
	qsort([Pivot|Tail], SortedList):-
  		divide(Tail, Pivot, GreaterList, SmallerList),
  		qsort(GreaterList, SortedGreaterList),
  		qsort(SmallerList, SortedSmallerList),!,
  		append(SortedSmallerList, [Pivot|SortedGreaterList], SortedList).
  	
  	delete_nth([_|Tail], 0, Tail). 	
  	delete_nth([Head|Tail], N, Result) :- 
  		N1=N-1,
  		delete_nth(Tail, N1, X), 
  		append([Head], X, Result).
  		
  	%subsection(List, List, List).
  	%subsection([], List, Res):-!.
  	%subsection([Head|Tail1], [Head|Tail2], Result):-
  		%append([Head], Result, NewResult), 
  		%subsection([Head|Tail1], Tail2, NewResult).  
  
  
  	even_pos([], []) :- !. 
  	even_pos([_|[]], []) :- !.
	even_pos([_, S| Tail], [S| Res]) :- even_pos(Tail, Res), !.
  		
  		
  	even_num([], []) :- !. 
	even_num([Head|Tail], [Head|Res]) :- S = Head mod 2, S = 0, even_num(Tail, Res), !.
	even_num([_|Tail], Res):- even_num(Tail, Res), !.
  	
  	
goal
	%member(7, [1, 2, 3, 5]).
	%sum([1,2,3,4,5], X).
	%nth(2, [1,2,3,4,5], X).
	%max([5,4,3,2,1], X).
	%reverse([1,2,3,5], X).
	%sublist([32,3], [1,2,3,4,5]).
	%delete([1,2,3,1,3,4,5,1,3,1,3,1], 1, X).
	%append([1,2,3], X, [1,2,3,4,5,6]).
	%append(X, [3,4,5], [1,2,3,4,5]).
	%append(X, Y, [1,2,3]).
	
	%bubble([3,4,5,6,7], X).
	%insert(4, 0, [1,2,3,4,5], X).
	%left([1,2,3,4], 2, X).
	%qsort([2,3,1,5,8,9], X).
	%delete_nth([1,2,3,4], 3, X).
	
	%subsection([1,2,3,4,5], [5,4,3,2,1,6,7,8,9], X).
	
	even_pos([4, 2, 3], X).
	
	
	
	
	
	
	

	
