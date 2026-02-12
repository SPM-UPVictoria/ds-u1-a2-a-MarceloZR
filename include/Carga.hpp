#ifndef CARGA_HPP
#define CARGA_HPP

template <typename T>
class Carga {
private:
    int x_;
    int y_;
    T q_;

public:
    Carga() : x_(0), y_(0), q_(0) {}

    Carga(int x, int y, T q) : x_(x), y_(y), q_(q) {}

    int getX() const { return x_; }
    int getY() const { return y_; }
    T getQ() const { return q_; }

    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }
    void setQ(T q) { q_ = q; }
};

#endif
