# highlight

## 全局

- $faster IO$
  - $readi / writei > scanf / printf > cin / cout$
- $vector$ 返回一个元素为$vector$\<$T$>{$x$}，大括号不是~~小括号~~
- 十年OI一场空，不开$long$ $long$见祖宗

## 图论

- $MAXN$ $MAXM$ 分清楚
- 使用 ^1 建立反向边时
  - 边要从偶数开始编号
  - ***空间要开两倍大！！！***
- 网络流
  - 最大流消耗流量，反向边要增加流量
  - $spfa$ 或 $bfs$ 增广路时只增广还有容量的边
  - 最大流一次 $bfs$ 后可以跑多次 $dinic$ ,但费用流一次 $spfa$ 只能 $Update$ 一次
- 割点根要特判($child > 2$)
- 2-SAT 染色用 $scc_i > scc_{i+n}$ ，而不是用 $dfn_i > dfn_{i+n}$

## dp

- 斜率优化手写队列
- 根据条件将dp数组设置初始值

## 线性代数

- 矩阵加速
  - $T=F*T$
  - $mod$ 要写在乘法运算内部
- 高斯消元
  - 用某行的元素消去其他行时不要动当前行

## 线段树

- 四倍空间
- $lazy$ $tag$
  - 记得 $spread$
- $change$ 更新子结点后记得更新当前节点 $data$
- 边界条件为 $l \le seg[node].l \wedge seg[node].r \le r$ , 不是 $seg[node].l == seg[node].r$
