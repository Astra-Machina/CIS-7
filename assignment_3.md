***Part 1:***

- ```(M -> H) ^ (S -> C)```
	- "If mathematics is easy, then the homework is done or if it is sunny, then camping is fun."

- ```"Mathematics is easy or camping is fun, as long as it is sunny and the homework  is done."```
	- (S ^ H) -> (M v C) 
	
	
***Part 2:***

```(¬B → ¬A) → ((¬B → A) → B)```

| ¬B | ¬A | ¬B -> ¬A | A | ¬B -> A | B | (¬B -> A) -> B | (¬B → ¬A) → ((¬B → A) → B) |
| --- | --- | --- | --- | --- | --- | --- | --- | 
| T | T | T | F | F | F | T | T | 
| T | F | F | T | T | F | F | T |
| F | T | F | F | T | T | T | T | 
| F | F | T | T | F | T | T | T |

- **Tautology**


```((A → B)∧(B → ¬A)) → A```

| A | B | A -> B | ¬A | B -> ¬A | (A -> B) ^ (B -> ¬A) | ((A -> B)∧(B -> ¬A)) -> A |
| --- | --- | --- | --- | --- | --- | --- |
| T | T | T | F | F | F | T |
| T | F | F | F | T | F | T |
| F | T | T | T | T | T | F |
| F | F | T | T | T | T | F |

- **Neither**


***Part 3:***


```(p ∧ q) → r , p → (q → r )```

(p ^ q) -> r <=> p -> (q -> r)

(p ^ q)' v r <=> p' v (q' v r)		Implication x3

(p' v q') v r <=> p' v (q' v r)		De Morgan

p' v (q' v r) <=> p' v (q' v r)		Associative

```(q ∨ r) → p, (q → p) ∧ (r → p)```

(q v r) → p <=> (q → p) ∧ (r → p)

(q v r)' v p <=> (q' v p) ^ (r' v p)		Implication x3

(q' ^ r') v p <=> (q' v p) ^ (r' v p)		De Morgan

(q' v p) ^ (r' v p) <=> (q' v p) ^ (r' v p)	Associative


***Part 4:***


