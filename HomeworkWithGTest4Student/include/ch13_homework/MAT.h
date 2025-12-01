#pragma once

#include <string>
#include <sstream>

/*
    定义二维矩阵模板
*/
template<typename T>
class MAT{
    T** e;        //指向保存矩阵元素的内存
    int r, c;     //矩阵的行数r、列数c
public:
	MAT(int r, int c);						    //矩阵定义,假设输入参数r,c都是＞0的整数
    MAT(const MAT& a);			                //深拷贝构造
	MAT(MAT&& a) noexcept = delete;			    //不允许移动构造
    MAT& operator=(const MAT& a) = delete;		//不允许深拷贝赋值运算
    MAT& operator=(MAT&& a)noexcept = delete;	//不允许移动赋值运算
    MAT operator~()const;				        //矩阵转置
    MAT operator+(const MAT& other) const;		//矩阵相加，如果矩阵不匹配不能相加，抛出字符串异常"can not +""
    MAT operator*(const MAT& other) const;		//矩阵相乘，如果矩阵不匹配不能相乘，抛出字符串异常"can not *""
    T * operator[](int i) const;                //重载[], 参数i为行索引，返回该行对应的一维数组指针，这样可以用[][]来访问MAT的每个元素了,不考虑参数越界情况
    virtual ~MAT() noexcept;                    //析构
    std::string toString() const;               //转换成字符串表示, 用二维矩阵形式显示MAT的内容


};

//注意：类模板的函数实现一定要写在MAT.h头文件里

// 构造函数
template<typename T>
MAT<T>::MAT(int r, int c) : r(r), c(c) {
    // 假设 r 和 c 都是 > 0 的整数
    e = new T*[r]; // 分配 r 个行指针
    for(int i = 0; i < r; ++i) {
        e[i] = new T[c](); // 分配 c 个元素，并使用 () 进行值初始化（T = int/float/double 时初始化为 0）
    }
}

// 深拷贝构造函数
template<typename T>
MAT<T>::MAT(const MAT& a) : r(a.r), c(a.c) {
    e = new T*[r];
    for(int i = 0; i < r; ++i) {
        e[i] = new T[c];
        for(int j = 0; j < c; ++j) {
            e[i][j] = a.e[i][j]; // 拷贝元素
        }
    }
}

// 析构函数
template<typename T>
MAT<T>::~MAT() noexcept {
    if (e != nullptr) {
        for(int i = 0; i < r; ++i) {
            delete[] e[i]; // 释放每一行的一维数组
        }
        delete[] e; // 释放行指针数组
        e = nullptr;
    }
    r = 0;
    c = 0;
}

// 重载 [] 运算符 (行索引访问)
template<typename T>
T * MAT<T>::operator[](int i) const {
    // 不考虑参数越界情况，直接返回第 i 行的指针
    return e[i];
}

// 矩阵转置 (~)
template<typename T>
MAT<T> MAT<T>::operator~() const {
    // 转置后的矩阵行数是原矩阵的列数，列数是原矩阵的行数
    MAT<T> result(c, r); 
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            result.e[j][i] = e[i][j]; // [i][j] -> [j][i]
        }
    }
    return result;
}

// 矩阵相加 (+)
template<typename T>
MAT<T> MAT<T>::operator+(const MAT<T>& other) const {
    // 检查维度是否匹配
    if (r != other.r || c != other.c) {
        throw std::string("can not +");
    }

    MAT<T> result(r, c);

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            result.e[i][j] = e[i][j] + other.e[i][j];
        }
    }
    return result;
}

// 矩阵相乘 (*)
template<typename T>
MAT<T> MAT<T>::operator*(const MAT<T>& other) const {
    // 检查维度是否匹配: 当前矩阵的列数必须等于 other 矩阵的行数
    if (c != other.r) {
        throw std::string("can not *");
    }

    // 结果矩阵的维度是 (this->r) x (other->c)
    MAT<T> result(r, other.c);

    for(int i = 0; i < r; ++i) { // 结果矩阵的行
        for(int j = 0; j < other.c; ++j) { // 结果矩阵的列
            T sum = T(); // 使用 T() 进行值初始化 (例如 int/float 初始化为 0)
            for(int k = 0; k < c; ++k) { // 乘积项的索引
                sum += e[i][k] * other.e[k][j];
            }
            result.e[i][j] = sum;
        }
    }
    return result;
}


//这里帮学生给出实现算了
template<typename T>
std::string MAT<T>::toString() const{
    std::ostringstream oss;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if( j != c -1){
			    oss << e[i][j] << " ";
		    }
		    else{
			    oss << e[i][j];
		    }
        }
        if(i != r -1)
            oss  << std::endl;  //如果不是最后一行，每一行元素输出完，换行  
    }

    return oss.str();
}