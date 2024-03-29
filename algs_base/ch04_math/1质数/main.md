# 质数

- 定义：在大于1的整数中，如果只包含1和本身两个约数，就被称为质数或素数，否则就是合数（从2开始）

- 试除法($\sqrt n$)

- 质因数分解：枚举n的质因数
    - 消去从2为因子的合数因子 n/2/2/2/2/2/2
    - 消去从3为因子的合数因子 n/3/3/3/3/3/3
    - 4已经被消去了 /2/2 一定是 n % i ！= 0
    - 剩下的就是质数即i一定是质数 if(n % i == 0)
    - 如果枚举完是大于1的，那么i一定是大于根号n的质因子

- 埃式筛法：小于n的所有质数
   - 消去所有2的倍数
   - 消去所有3的倍数
   - 剩下的都是质数
   有 n/log n 个质数
- 线性筛法：小于n的所有质数

   - 只用最小质因子筛掉所有的合数x
     - 当i枚举到x/primer[j]时，x就会被消去
   - 从小到达枚举所有质数
   - 消去枚举质数和自己的乘积
   - 如果 i % primer[j] == 0
     - break
     - primer[j]一定是i的最小质因子
     - primer[j]一定是i*prime[j]的最小质因子
   - 否则
     - primer[j]一定小于i的所有质因子
     - primer[j]一定是i*prime[j]的最小质因子




