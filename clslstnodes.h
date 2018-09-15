#pragma once

template<class T>
class clslstnodes
{

private:
	T t_val;

protected:

public:
	clslstnodes();
	~clslstnodes();
	void set_t_val(T inval);
	T get_t_val();
	clslstnodes<T> *ptr_nextNode;
};

//Consructor
template<class T>
clslstnodes<T>::clslstnodes()
{};


//Destructor
template<class T>
clslstnodes<T>::~clslstnodes()
{};

template<class T>
T clslstnodes<T>::get_t_val()
{
	return this->t_val;
};

template<class T>
void clslstnodes<T>::set_t_val(T inval)
{
	this->t_val = inval;
};

