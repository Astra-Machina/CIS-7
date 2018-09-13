***Part 1:***

- ```(M -> H) ^ (S -> C)```
	- "If mathematics is easy, then the homework is done or if it is sunny, then camping is fun."

- ```"Mathematics is easy or camping is fun, as long as it is sunny and the homework  is done."```
	- (S ^ H) -> (M v C) 
	
	
***Part 2:***

```
(¬B → ¬A) → ((¬B → A) → B)
```

| ¬B | ¬A | ¬B -> ¬A | A | ¬B -> A | B | (¬B -> A) -> B | (¬B → ¬A) → ((¬B → A) → B) |
| --- | --- | --- | --- | --- | --- | --- | --- | 
| T | T | T | F | F | F | T | T | 
| T | F | F | T | T | F | F | T |
| F | T | F | F | T | T | T | T | 
| F | F | T | T | F | T | T | T |

- **Tautology**


```
((A → B)∧(B → ¬A)) → A
```

| A | B | A -> B | ¬A | B -> ¬A | (A -> B) ^ (B -> ¬A) | ((A -> B)∧(B -> ¬A)) -> A |
| --- | --- | --- | --- | --- | --- | --- |
| T | T | T | F | F | F | T |
| T | F | F | F | T | F | T |
| F | T | T | T | T | T | F |
| F | F | T | T | T | T | F |

- **Neither**


***Part 3:***


```
(p ∧ q) → r , p → (q → r )
```

(p ^ q) -> r <=> p -> (q -> r)

(p ^ q)' v r <=> p' v (q' v r)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Implication x3*

(p' v q') v r <=> p' v (q' v r)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*De Morgan*

p' v (q' v r) <=> p' v (q' v r)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Associative*

```
(q ∨ r) → p, (q → p) ∧ (r → p)
```

(q v r) → p <=> (q → p) ∧ (r → p)

(q v r)' v p <=> (q' v p) ^ (r' v p)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Implication x3*

(q' ^ r') v p <=> (q' v p) ^ (r' v p)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*De Morgan*

(q' v p) ^ (r' v p) <=> (q' v p) ^ (r' v p)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Associative*


***Part 4:***


```
Let Loves(x,y) mean “x loves y,” Traveler(x) mean “x is a traveler,”
City(x) mean “x is a city,” Lives(x,y) mean “x lives in y.”
```

- Translate into English: ∃x∀y∀z(City(x) ∧ Traveler(y) ∧ Lives(z,x)) → (Loves(y,x) ∧ ¬Loves(z,x))
	- "If there is a traveler, all residents, and all cities, then all travelers love all cities, and all residents do not love all of their cities."

- Translate into Predicate Logic: “No traveler loves the city they live in.”
	- ∀x∀y ((Traveler(x) ^ City(y) ^ Lives(x,y)) -> ¬Loves(x,y))
	

***Extra Credit:***


```
Assuming: p → (q ∧ r), s → r , r → p
Prove: s → q.
```
s		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Assumption*

s -> r		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*MPP*

r 		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Identity*

r -> p		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Premise*

p		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*MPP*

p -> (q ^ r)	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Premise*

q ^ r		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*MPP*

q		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Identity*

s -> q		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Implication*


```
Assuming: ¬(r ∨ s), ¬p → s, p → q. 
Prove: q
```
¬(r v s)	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Assumption*

¬r ^ ¬s		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*De Morgan*

¬s		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Identity*

¬p -> s		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Premise*

p -> ¬s		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*MTT*

p		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Identity*

p -> q		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*Premise*

q		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;*MPP*



