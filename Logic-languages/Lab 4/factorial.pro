predicates
  	fact(integer,integer).
  	f(integer,integer,integer,integer).
  	factorial(integer,integer).
  	
clauses

	factorial(X, _) :- X<0, ! ,fail.
	factorial (0, 1) :- !.
	factorial(N, Fact) :- N1=N-1, factorial(N1, Fact1), Fact=N*Fact1.
	
  	fact(N,F):-f(N,F,1,1).
  	f(N,F,N,F):-!.
  	f(N,F,N1,F1):-N11=N1+1,
                      F11=F1*N11,
                      f(N,F,N11,F11).
                      
        
goal
	factorial(5,X).
