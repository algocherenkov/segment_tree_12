#pragma once
#include <vector>


class SegmentTreeSum
{
public:
    void add(long long item, size_t pos);
    void buildTree();
    long long getSum(int l, int r);
    void setSize(size_t size) { m_buff.resize(size); }
private:
    std::vector<long long> m_buff;
};
