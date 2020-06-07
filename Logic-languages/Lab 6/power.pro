predicates 
	pow_of_2(integer, integer).
	pow_of_2(integer, integer, integer, integer).
	
clauses 
	pow_of_2(Num, Res) :- Num mod 2 = 0, pow_of_2(Num, 1, 0, Res).	
	pow_of_2(Num, CurNum, CurPow, CurPow) :- Num = CurNum, !.
	pow_of_2(Num, CurNum, CurPow, Res) :- CurNum < Num, NewCur = CurNum*2,
				 		NewPow = CurPow+1, 
				 		pow_of_2(Num, NewCur, NewPow, Res), !.

	
goal 
	pow_of_2(4, X).
	
	