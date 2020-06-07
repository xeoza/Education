domains 
	brand, model, class1, color = symbol.
	price = integer.
	
predicates
	car(brand, model, class1, color, price).
	byPrice(brand, model, class1, color, price).
	
clauses
  	car(daewoo, matiz, a, red, 300).
  	car(kia, picanto, a, blue, 350).
  	car(hyundai, accent, b, black, 400).
  	car(volkswagen, polo, b, silver, 410).
  	car(ford, focus, c, sand, 500).
  	car(toyota, corolla, c, sand, 600).
  	car(skoda, octavia, d, green, 610).
  	car(ford, mondeo, d, yellow, 550).
  	car(mercedes, eklasse, e, green, 800).
  	car(audi, a6, e, black, 900).
  	car(audi, a8, f, yellow, 1500).
  	car(porsche, panamera, f, blue, 2000).
  	
  	byPrice(Brand, Model, Class, Color, Cost) :-
    		car(Brand, Model, Class, Color, Price), Price <= Cost.

goal
  	byPrice(Brand, Model, f, Color, 1800).