**Part 1:**

p -> q <=> q' -> p'

q' -> p'
(q')' v p'      Implication
q v p'          Double Negation
p' v q          Commutative
p -> q          Implication

p -> q <=> p -> q



(p -> r) ^ (q -> r) <=> (p v q) -> r

(p -> r) ^ (q -> r)
(p' v r) ^ (q' v r)     Implication x2
(p' ^ q') v r           Distributive
(p' ^ q')' -> r         Impication
((p')' v (q')') -> r    De Morgan
(p v q) -> r            Double Negation

(p v q) -> r <=> (p v q) -> r



(Ǝx)A(x) ^ (Ǝx)B(x) -> (Ǝx)(A(x) ^ B(x))

x is a phone.
A(x) => x is an Android phone, B(x) => x is an Apple Phone

Some phones are Android and some phones are Apple, and some phones are both Android and Apple.
--Not True.
