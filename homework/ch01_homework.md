# 第一章作业

## 1

填空题：

1. $\sum_{i=1}^{n} \frac{1}{i} = \Theta(\underline{\log n})$。
2. $\log(n!) = \Theta(\underline{n\log n})$。
3. $f(n) = \Omega(g(n))$ 且 $f(n) = O(g(n))$ 等价于 $f(n) = \underline{\Theta}(g(n))$。
4. $2026^n = \underline{\Omega}(2025^n)$。（填写 $O$, $\Omega$ 或 $\Theta$）

## 2

```cpp
int cnt = 0;
int i = 1;
while (i <= n) {
    int j = i;
    while (j <= n) {
        cnt++;
        j *= 2;
    }
    i++;
}
```

分析程序，求出程序的时间复杂度（大 $O$ 表示，**给出推导过程**）。
从内层while(j<=n)轮次来进行分析，
第一轮，i从$1$到$n$都能执行，执行$n$次；
第二轮，i从$1$到$\frac{n}{2}$都能执行，执行$\frac{n}{2}$次；
...
以此类推，总执行数为$n+\frac{n}{2}+\frac{n}{4}+\cdots < 2n$
所以时间复杂度为$O(n)$
## 3

求解下列递推式的 $\Theta$ 表示。

1. $T(n) = n^5 \times 3^n + 4^n$。
	因为$$\frac{n^5 3^n}{4^n}=n^5\left(\frac34\right)^n\rightarrow 0$$
	所以当 $n$ 足够大时，有$$n^5 3^n \le 4^n$$于是$$4^n\le T(n)=n^5 3^n+4^n\le 2\cdot4^n$$因此$$T(n)=\Theta(4^n)$$
2. $T(n) = T(n - 1) + \Theta(n)$。
	可得递推式 $T(n) - T(n-1) = \Theta(n)$
	累加得到
	 $$T(n) = \sum_{i=1}^{n} \Theta(i) = \Theta(\sum_{i=1}^{n}i) + T(0) = \Theta(\frac{1}{2}n^2 +\frac{1}{2}n) = \Theta(n^2)$$
	 
3. $T(n) = T(\lfloor n/2 \rfloor) + \Theta(1)$。
	大致由题目可以读出，时间每翻倍一次，$\Theta + 1$
	$T(1) = \Theta(1)$，以此为基准$T(n)$翻倍了$\log_2 n$次
	因此$T(n) = \Theta(1) + \Theta(\log_2 n) = \Theta(\log n)$
	
4. $T(n) = T(n - 1) + \Theta(\log n)$。
	依旧得到递推式 $T(n) - T(n - 1) = \Theta(\log n)$
	累加得到$$T(n) = \Theta(\sum_{i=1}^{n} \log i) + T(0)= \Theta(\log (n!)) = \Theta(n\log n)$$

## 4

1. 证明对任意正实数 $a$ 和 $b$，$a^n = O(b^n)$ 当且仅当 $a \le b$。
	必要性：$a^n = O(b^n)\Rightarrow a \le b$
	由$a^n = O(b^n)$得到存在常数$C \gt 0$和$n_0$，s.t当$n \ge n_0$时：  $$a^n \le Cb^n$$即$$(\frac{a}{b})^n \le C$$若$a \gt b$即$\frac{a}{b} \gt 1$，于是$$(\frac{a}{b})^n \rightarrow \infty$$最终一定超过固定常数C，因此$a \gt b$不成立
	故$a \le b$
	
	充分性：$a^n = O(b^n)\Leftarrow a \le b$
	由$a \le b$可得$\frac{a}{b} \le 1$
	故$(\frac{a}{b})^n \le 1$，即$a^n \le b^n$
	取$O$定义中的常数$C = 1$，便有$a^n = O(b^n)$
	
2. 给定 $T(1) = 1$ 和 $T(n) = 2T(\lfloor n/2 \rfloor) + n$，证明 $T(n) = O(n \log n)$。（提示：考虑数学归纳法）
	 由定义，欲证$T(n) = O(n \log n)$，即证存在常数$C \ge 1$，s.t.$T(n) \le Cn \log_2 n + Cn$
	 当$n = 1$时，$T(1) = 1 \le C$，成立;
	假设对于$\forall m \lt n$，都有：$T(m) \le Cm \log_2 m + Cm$
	令$m = \lfloor \frac{n}{2} \rfloor \le \frac{n}{2}$ 
	则由假设可得$$T(n) = 2T(m) + n \le 2(Cm \log_2 m + Cm) + n \le Cn \log_2 m - Cn + Cn + n \le Cn \log_2 n + Cn$$故假设成立，即证得 $T(n) = O(n \log n)$
	
	 