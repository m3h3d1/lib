---
title: Extgcd (extended Euclidean algorithm)
documentation_of: ./extgcd.hpp
---

# extgcd

```
T extgcd(T a, T b, T &x, T &y)
```

for $\gcd(a, b)$ returns $(x, y)$. Contains integer solutions that satisfy $ax + by = \gcd(a, b)$. If multiple integer solutions are possible, the one with the smallest $\|x\| + \|y\|$ is stored.


## Constraint

- $1 \leq a, b$

## Complexity

- $O(\log {\min(a, b)})$