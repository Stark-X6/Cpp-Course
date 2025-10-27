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