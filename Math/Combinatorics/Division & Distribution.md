# Division & Distribution in Combinatorics

## Master Table

|  Index | Objects       | Groups / Recipients  | Restriction                             |                                                                          Formula |
| -----: | ------------- | -------------------- | --------------------------------------- | -------------------------------------------------------------------------------: |
| **A1** | **Distinct**  | **Labelled** \(k\)   | No restriction                          |                                                                    $\boxed{k^n}$ |
| **A2** | Distinct      | Labelled \(k\)       | Non-empty                               |                                                               $\boxed{k!S(n,k)}$ |
| **A3** | Distinct      | Labelled \(k\)       | Atmost 1                                |                                                     $\boxed{\dfrac{k!}{(k-n)!}}$ |
| **A4** | Distinct      | Labelled \(k\)       | Exactly \(r\)                           |                                       $\boxed{\dfrac{n!}{(r!)^k}}$, where $n=kr$ |
| **A5** | Distinct      | Labelled \(k\)       | Prescribed sizes \(n_1,n_2,\ldots,n_k\) |                                        $\boxed{\dfrac{n!}{n_1!n_2!\cdots n_k!}}$ |
| **A6** | Distinct      | Labelled \(k\)       | Exactly \(r\) empty                     |                                             $\boxed{\binom{k}{r}(k-r)!S(n,k-r)}$ |
| **B1** | **Distinct**  | **Unlabelled** \(k\) | Non-empty                               |                                                                 $\boxed{S(n,k)}$ |
| **B2** | Distinct      | Unlabelled \(k\)     | Prescribed sizes                        |             $\boxed{\dfrac{n!}{\left(\prod n_i!\right)\left(\prod m_j!\right)}}$ |
| **C1** | **Identical** | **Labelled** \(k\)   | No restriction                          |                                                     $\boxed{\binom{n+k-1}{k-1}}$ |
| **C2** | Identical     | Labelled \(k\)       | Non-empty                               |                                                       $\boxed{\binom{n-1}{k-1}}$ |
| **C3** | Identical     | Labelled \(k\)       | Exactly \(r\)                           |                                     $\boxed{1}$ if $n=kr$, otherwise $\boxed{0}$ |
| **C4** | Identical     | Labelled \(k\)       | Atmost \(r\)                            | $\boxed{\displaystyle\sum_{j=0}^{k}(-1)^j\binom{k}{j}\binom{n-j(r+1)+k-1}{k-1}}$ |
| **D1** | **Identical** | **Unlabelled** \(k\) | Exactly \(k\) non-empty groups          |                                                                 $\boxed{p_k(n)}$ |
| **D2** | Identical     | Unlabelled           | No restriction on number of groups      |                                                                   $\boxed{p(n)}$ |

---

## Notation

| Symbol               | Meaning                                                                                                                                  |
| -------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| $n$                  | Number of objects                                                                                                                        |
| $k$                  | Number of groups / recipients                                                                                                            |
| $r$                  | Number of objects per group/recipient in an **Exactly \(r\)** condition, or the bound in **Atmost \(r\)** / **Atleast \(r\)** conditions |
| $S(n,k)$             | **Stirling number of the second kind** — number of ways to divide $n$ distinct objects into $k$ non-empty unlabelled groups              |
| $p_k(n)$             | Number of **integer partitions** of $n$ into exactly $k$ positive parts                                                                  |
| $p(n)$               | Total number of integer partitions of $n$                                                                                                |
| $n_1,n_2,\ldots,n_k$ | Prescribed group/recipient sizes, with $n_1+n_2+\cdots+n_k=n$                                                                            |
| $m_j$                | Number of groups having the same size; used to correct overcounting when groups are unlabelled                                           |

---

## Important Relationships

### Division ↔ Distribution

For $n$ distinct objects divided into $k$ non-empty groups:

$$
\boxed{\text{Division} = S(n,k)}
$$

Labelling those $k$ groups gives:

$$
\boxed{\text{Distribution} = k!S(n,k)}
$$

Therefore:

$$
\boxed{\text{Distribution} = k!\times\text{Division}}
$$

**provided all $k$ groups are non-empty.**

---

## Stirling Number Formula

The Stirling number of the second kind satisfies:

$$
\boxed{S(n,k)=kS(n-1,k)+S(n-1,k-1)}
$$

and has the explicit formula:

$$
\boxed{
S(n,k)=
\frac{1}{k!}
\sum_{i=0}^{k}
(-1)^i
\binom{k}{i}
(k-i)^n
}
$$

Hence:

$$
\boxed{
k!S(n,k)=
\sum_{i=0}^{k}
(-1)^i
\binom{k}{i}
(k-i)^n
}
$$

---

## The Four Fundamental Worlds

Almost every Division & Distribution problem falls into one of these four categories:

|                       | Labelled Groups / Recipients     | Unlabelled Groups                 |
| --------------------- | -------------------------------- | --------------------------------- |
| **Distinct Objects**  | Assignments / Functions          | Set Partitions / Stirling Numbers |
| **Identical Objects** | Integer Solutions / Stars & Bars | Integer Partitions                |

### In short

$$
\boxed{
\begin{array}{c|c}
\text{Situation} & \text{Main Tool}\\
\hline
\text{Distinct + Labelled} & \text{Functions, Inclusion-Exclusion, Multinomial}\\
\text{Distinct + Unlabelled} & \text{Stirling Numbers}\\
\text{Identical + Labelled} & \text{Stars and Bars}\\
\text{Identical + Unlabelled} & \text{Integer Partitions}
\end{array}
}
$$

---

## Terminology

Use the following standard restriction terminology:

* **No restriction** — groups may be empty and may contain any number of objects.
* **Non-empty** — every group contains at least one object.
* **Atmost 1** — every group contains at most one object.
* **Exactly 1** — every group contains exactly one object.
* **Atleast \(r\)** — every group contains at least \(r\) objects.
* **Atmost \(r\)** — every group contains at most \(r\) objects.
* **Exactly \(r\)** — every group contains exactly \(r\) objects.
* **Prescribed sizes** — each group has a specified size $n_1,n_2,\ldots,n_k$.
* **Exactly \(r\) empty** — exactly \(r\) groups/recipients receive no objects.
