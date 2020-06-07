predicates
	fibonacci(integer, integer).

clauses
	fibonacci(1,1):-!.
	fibonacci(2,1):-!.
	fibonacci(I,R):- I>2, I1=I-1, I2=I-2, fibonacci(I1,M), fibonacci(I2,N), R=N+M.
goal
	fibonacci(10, X).
