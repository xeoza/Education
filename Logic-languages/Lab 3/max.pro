domains
	i = integer.
	
predicates
  	max1(i, i, i).
  	max2(i, i, i).
  	max3(i, i, i).
  	
  	max3a(i, i, i, i).
  	max3b(i, i, i, i).
  	
clauses	
	max1(X,Y,X):- X >= Y.
	max1(X,Y,Y):- X < Y.
	
  	max2(X, Y, X):- X >= Y, !.
	max2(_, Y, Y).
	
	max3(X, Y, Res) :- X >= Y, Res = X, ! ; Res = Y.
	
	max3a(X, Y, Z, X):- X >= Y, X >= Z.
	max3a(X, Y, Z, Y):- Y >= X, Y >= Z.
	max3a(X, Y, Z, Z):- Z >= X, Z >= Y.
	
	max3b(X, Y, Z, X):- X > Y, X > Z, !.
	max3b(_, Y, Z, Y):- Y >= Z, !.
	max3b(_, _, Z, Z). 

		
goal
	max3(3, 2, A).
