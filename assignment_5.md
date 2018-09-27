```
Part 1:
```

- *Show that the square root of 2 is irrational.*
	```
	√2 = 1.4142135624
	
	k = a/b
	```
	
- *If n = 25, 100, or 169, then n is a perfect square and is the sum of two perfect squares.*
	```
	5 * 5 = 25, (3 * 3) + (4 * 4) = 25
	
	10 * 10 = 100, (8 * 8) + (6 * 6) = 100
	
	13 * 13 = 169, (12 * 12) + (5 * 5) = 169
	```
- *The sum of two odd integers is even. Hint: By definition, even integers can be expressed as 2n, thus odd integers can be expressed as 	```
	2n + 1*
	
	(2n + 1) + (2n + 1) = 2n
	
	2(2n + 1) = 2n
	
	4n + 2 = 2n
	
	Even = 2n
	```
- *The sum of an even integer and it's square is even*
	```
	2n + (2n)^2 = 2n
	
	2n + 4n^2 = 2n
	
	2n(1 + 2n) = 2n
	
	(Even) * (Odd) = 2n
	
	Even * Odd = Even
	```
- *If n squared is odd, then n is odd*
	```
	n = 2n + 1, n^2 = (2n + 1)^2
	
	n^2 = 4n^2 + 4n + 1
	
	n^2 = 4n(n + 1) + 1
	
	n^2 = 2n + 1
	
	n^2 = Odd
	```
```
Part 2:
```

- *Prove by induction that 1 + 5 + 9 + ... + (4n-3) = n(2n-1)*
	```
	4n - 3 = 2n^2 - n
	
	n = 1, (4(1) - 3) = 2(1)^2 - 1
	
		1 = 1
	
	n = k, 4k - 3 = 2k^2 - k
	
	n = k + 1, 4(k + 1) - 3 = 2(k + 1)^2 - (k + 1))
	
		4k + 1 = 2(k^2 + 2k + 1) - (k + 1)
		
		4k + 1 = 2k^2 + 4k + 2 - k - 1
		
		4k + 1 = 2k^2 + 3k + 1
	
	1 + 5 + 9 + ... + (4k - 3) + (4k + 1) = (2k^2 - k) + (4k + 1)
	
	1 + 5 + 9 + ... + (4k - 3) + (4k + 1) = 2k^2 + 3k + 1
	```
- *Prove that for any positive integer number n, n^3 + 2n is divisible by 3*
	```
	n > 0, (n^3 + 2n) / 3
	
	
	n = 1, (1^3 + 2(1)) / 3 = 1
	
	n = 2, (2^3 + 2(2)) / 3 = 4
	
	n = 3, (3^3 + 2(3)) / 3 = 11
	
	n = k, (k^3 + 2k)
	
	n = k + 1
	
	((k + 1)^3 + 2(k + 1)) 
	
	((k^3 + 3k^2 + 3k + 1) + (2k + 2))
	
	((k^3 + 2k) + (3k^2 + 3k + 3)) 
	
	((k^3 + 2k)) + (3(k^2 + k + 1))
	
	Proof + 3(k^2 + k + 1)
		Second part is divisibly by 3 because it is all multiplied by 3.
	```
- *Prove that for n >= 1, 9^n − 1 is divisible by 8 for all non-negative integers Hint: 4^(3+1) = 4 * 4^3 Hint: If 9^n - 1 = 8m, then 		```
	9^n = 8m + 1*
	
	n = 1, (9^1 - 1) = 8, 8 / 8 = 1
	
	n = 2, (9^2 - 1) = 80, 80 / 8 = 10
	
	n = 3, (9^3 - 1) = 728, 728 / 8 = 91
	
	n = k, (9^k - 1)
	
	n = k + 1, (9^(k + 1) - 1)
		
		(9^k * 9 - 1)
		
		So, (9^k - 1) because 9^k * 9 is simply a higher power of 9^k,
		which is already proven to be divisible by 8.
	```
