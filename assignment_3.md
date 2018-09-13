**Part 1:**

- ```(M -> H) ^ (S -> C)```
	- "If mathematics is easy, then the homework is done or if it is sunny, then camping is fun."

- ```"Mathematics is easy or camping is fun, as long as it is sunny and the homework  is done."```
	- (S ^ H) -> (M v C) 
	
	
**Part 2:**

```(¬B → ¬A) → ((¬B → A) → B)```

| ¬B | ¬A | ¬B -> ¬A | A | ¬B -> A | B | (¬B -> A) -> B | (¬B → ¬A) → ((¬B → A) → B) |
| --- | --- | --- | --- | --- | --- | --- | --- | 
| T | T | T | F | F | F | T | T | 
| T | F | F | T | T | F | F | T |
| F | T | F | F | T | T | T | T | 
| F | F | T | T | F | T | T | T |
