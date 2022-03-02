# 유클리디안 알고리즘
gcd에 대한 정리

# 핵심 아이디어
1. gcd(a,0) = a, a > 0
1. gcd(a,b) = gcd(b, a%b)

> 증명 (a,b가 양수일 경우)
1. a,b의 임의의 약수 c는 b, a%b의 약수다. 
    `a = qb + a%b, cx = qcy + a&b => a&b = c(x- qy`
2. b, a%b의 임의의 약수 d는 a,b의 약수다.
   `a = qb + a%b = dqx + dy = d(qx + y)`

=> 1,2에 의해서 두 집합이 동일하다.

# 확장 유클리디안 알고리즘
1. sa + ta = gcd(a,b) => a, b주어지면 s,t도 구할 수 있다.

> 증명
1. (s1 = 1, s2 = 0, t1 = 0, t2 = 1, r1 = a, r2 = b)
    ```
    s1a + t1b = r1, s2a + t2b = r2

    s3a + t3b = (s1 + qs2)a + (t1 + qt2)b 
              = (s1a + t1b) + q(s2a + t2b) 
              = r1 + qr2 
              = r3
    ```
=> r2가 0이 될 때, 같이 구할 수 있다.