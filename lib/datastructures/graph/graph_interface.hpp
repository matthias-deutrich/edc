//
// Created by Matthias Deutrich on 13.07.23.
//

#ifndef EDC_FORK_GRAPH_INTERFACE_HPP
#define EDC_FORK_GRAPH_INTERFACE_HPP

#include <iterator>

namespace Graph {

// TODO rework iterators using concepts

template <typename V, typename E> class AbstractGraph {
public:
    // TODO check whether these general tags allow for efficient code
    using VIter = std::iterator<std::forward_iterator_tag, V>;
    using VIterConst = std::iterator<std::forward_iterator_tag, const V>;
    using EIter = std::iterator<std::forward_iterator_tag, E>;
    using EIterConst = std::iterator<std::forward_iterator_tag, const E>;

    class Edges {
    private:
        EIter begin_iter;
        EIter end_iter;
        EIterConst cbegin_iter;
        EIterConst cend_iter;
    public:
        EIter begin() {return begin_iter;}
        EIter end() {return end_iter;}
        EIterConst cbegin() {return cbegin_iter;}
        EIterConst cend() {return cend_iter;}
        [[nodiscard]] unsigned size() const {return end_iter - begin_iter;}
    };

    virtual ~AbstractGraph() = default;
    virtual VIter begin() = 0;
    virtual VIter end() = 0;
    virtual VIterConst cbegin() = 0;
    virtual VIterConst cend() = 0;
    virtual Edges edges() = 0;
    virtual Edges neighbors(V v) = 0;
    [[nodiscard]] unsigned size() const {cend() - cbegin();}
    unsigned degree(V v) const {return neighbors(v).size();}
};

template <typename V, typename E, typename VData, typename EData>
class AbstractDataGraph: virtual public AbstractGraph<V, E> {
public:
    virtual ~AbstractDataGraph() = default;
    virtual inline VData data(V v) = 0;
    virtual inline VData cdata(V v) const = 0;
    virtual inline EData data(E e) = 0;
    virtual inline EData cdata(E e) const = 0;
};

template <typename V, typename E>
class AbstractSubGraph : virtual public AbstractGraph<V, E> {
public:

};

} // AbstractGraph

#endif //EDC_FORK_GRAPH_INTERFACE_HPP
