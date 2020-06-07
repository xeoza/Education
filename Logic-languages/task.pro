predicates
	task(integer, integer, integer, integer, integer, integer, symbol, symbol, symbol,symbol).
  	apply(symbol, integer, integer, integer).

clauses
	task(A, B, C, D, E, F, X1, X2, X3, X4) :- 
  		apply(X1, A, B, R1), 
  		apply(X2, R1, C, R2), 
  		apply(X3, R2, D, R3), 
  		apply(X4, R3, E, Res), Res = F.
	
	apply(Sign, X, Y, R) :- Sign = "-", R = X - Y. 
	apply(Sign, X, Y, R) :-	Sign = "+", R = X + Y.
	apply(Sign, X, Y, R) :-	Sign = "/", R = X / Y.
	apply(Sign, X, Y, R) :-	Sign = "*", R = X * Y.

goal

  task(1, 3, 4, 5, 6, 29, X, Y, Z, T).
