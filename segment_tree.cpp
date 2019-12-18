#include "segment_tree.h"
#include <cassert>
#include <cmath>
#include <climits>

const int INF = INT_MAX;

void SegmentTreeSum::add(long long item, size_t pos)
{
    assert((pos - 1) < m_buff.size());
    m_buff[pos - 1] = item;
}

void SegmentTreeSum::buildTree()
{
    assert(m_buff.size() > 1);
    // размер, доведённый до степени двойки
    unsigned int n = 2*(1 << (static_cast<int>(std::log(m_buff.size() - 1)) + 1));
    m_buff.resize(2*n, 0);

    // инициализируем листы
    for (size_t i = n; i < 2 * n; i++)
        m_buff[i] = m_buff[i - n];

    // и все остальные вершины
    for (size_t i = n - 1; i > 0; i--)
        m_buff[i] = m_buff[2 * i] + m_buff[2 * i + 1];
}

long long SegmentTreeSum::getSum(int l, int r)
{
    long long ans = 0;
    size_t n = m_buff.size() / 2;
    l += n - 1;
    r += n - 1;
    while (l <= r)
    {
        // если l - правый сын своего родителя,
        // учитываем его фундаментальный отрезок
        if (l & 1)
            ans = ans + m_buff[static_cast<size_t>(l)];
        // если r - левый сын своего родителя,
        // учитываем его фундаментальный отрезок
        if (!(r & 1))
            ans = ans + m_buff[static_cast<size_t>(r)];
        // сдвигаем указатели на уровень выше
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return ans;
}
