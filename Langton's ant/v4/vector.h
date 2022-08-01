
#pragma once
#include <cassert>
#include <cstddef>

using namespace std;

template<class T>
class vector_t
{
public:
  vector_t(int = 0, int = 0);

  ~vector_t();
  void init(const T&);
  
  void Destroy ();
  int GetFirst() const { return first_; }
  int GetLast() const { return last_; }
  int GetSize() const { return last_ - first_; }
  void Resize (const int, const int);

  T& operator[](const int);
  T& at(const int);
  vector_t<T> operator=(vector_t<T>& );

  T& GetValue(const int);
  void SetValue(const int, const T);

  private:
  T *V_;
  int size_;
  int first_;
  int last_;
};



template<class T>
vector_t<T>::vector_t(const int inf, const int sup)
{
  assert(inf <= sup);
  first_ = inf;
  last_ = sup;
  size_= sup-inf;
  assert(size_ >= 0);
  V_ = new T[size_];
}


  
template<class T>
vector_t<T>::~vector_t() {

  Destroy ();
}

template<class T>
void
vector_t<T>::Destroy() 
{
  if (V_ != NULL) {
  delete[] V_;
    V_ = NULL;
  }
  size_ = 0;
  first_ = 0;
  last_ = 0;
}


template<class T>
T&
vector_t<T>::operator[](const int i)
{
  return at(i);
}


template<class T>
vector_t<T>
vector_t<T>::operator=(vector_t<T>& w)
{
  return vector_t (w);
}


template<class T>
T&
vector_t<T>::at(const int i)
{
  return V_[(first_*-1)+i];
}


template<class T>
void
vector_t<T>::Resize(const int inf, const int sup)
{
 // Destroy();
  size_ = sup - inf;
  first_ = inf;
  last_ = sup;
  V_ = new T[size_];
}


template<class T>
T&
vector_t<T>::GetValue(const int i)
{
  return V_[i];
}


template<class T>
void
vector_t<T>::SetValue(const int i, const T value)
{
  V_[i] = value;
}