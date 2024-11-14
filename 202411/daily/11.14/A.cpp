#include <iostream>
// using namespace std;
template <typename T>
inline void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != '-')
        ;
    if (ch == '-')
        f = -f, ch = getchar();
    while (!feof(stdin) && isdigit(ch)) {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p) {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x;
int a1, b1, c1, d1, e1, f1, g1, h1, i1, j1, k1, l1, m1, n1, o1, p1, q1, r1, s1,
    t1, u1, v1, w1, x1;
bool Check()
{
    if (a != b || b != c || c != d)
        return false;
    if (e != f || f != g || g != h)
        return false;
    if (i != j || j != k || k != l)
        return false;
    if (m != n || n != o || o != p)
        return false;
    if (q != r || r != s || s != t)
        return false;
    if (u != v || v != w || w != x)
        return false;
    return true;
}
const int ROT_R = 1;
const int ROT_r = 2;
const int ROT_U = 3;
const int ROT_u = 4;
const int ROT_F = 5;
const int ROT_f = 6;
void Attempt(int m)
{
    a1 = a, b1 = b, c1 = c, d1 = d, e1 = e, f1 = f, g1 = g, h1 = h, i1 = i,
    j1 = j, k1 = k, l1 = l, m1 = m, n1 = n, o1 = o, p1 = p, q1 = q, r1 = r,
    s1 = s, t1 = t, u1 = u, v1 = v, w1 = w, x1 = x;
    switch (m) {
        case ROT_R:
            b = f1, d = h1, f = j1, h = l1, j = n1, l = p1, n = b1, p = d1;
            return;
        case ROT_r:
            f = b1, h = d1, j = f1, l = h1, n = j1, p = l1, b = n1, d = p1;
            return;
        case ROT_U:
            e = r1, f = t1, w = e1, u = f1, p = w1, o = u1, r = p1, t = o1;
            return;
        case ROT_u:
            r = e1, t = f1, e = w1, f = u1, w = p1, u = o1, p = r1, o = t1;
            return;
        case ROT_F:
            w = c1, x = d1, j = w1, i = x1, s = j1, t = i1, c = s1, d = t1;
            return;
        case ROT_f:
            c = w1, d = x1, w = j1, x = i1, s = c1, t = d1, j = s1, i = t1;
            return;
        default:
            return;
    }
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    readi(T);
    while (T--) {
        readi(a);
        readi(b);
        readi(c);
        readi(d);
        readi(e);
        readi(f);
        readi(g);
        readi(h);
        readi(i);
        readi(j);
        readi(k);
        readi(l);
        readi(m);
        readi(n);
        readi(o);
        readi(p);
        readi(q);
        readi(r);
        readi(s);
        readi(t);
        readi(u);
        readi(v);
        readi(w);
        readi(x);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_F);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_f);
        Attempt(ROT_f);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_F);
        Attempt(ROT_U);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_u);
        Attempt(ROT_u);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_U);
        Attempt(ROT_R);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_r);
        Attempt(ROT_r);
        if (Check()) {
            puts("YES");
            continue;
        }
        Attempt(ROT_R);
        puts("NO");
    }
    return 0;
}