/*****************************************************************************
*  Copyright (C), 2025, 黄泽基 20222121007
*
*  @file    ReToNfa.h
*  @brief   预处理后正则转NFA
*
*  @author  黄泽基
*  @date    2025-4-05
*  @version V1.0.0
*----------------------------------------------------------------------------
*  @note 历史版本  修改人员    修改内容
*  @note V1.0.0   黄泽基     创建文件
*****************************************************************************
*/
#include"common.h"

std::map<int, std::string> CodeMap; //映射表：code：value

//存储正则级别比较
int opPrecedence(char ch) {
    switch (ch) {
    case '|':	// 选择最弱
        return 1;
    case '.':	// 连接中等
        return 2;
    //单目运算符，直接加入就好了
    case'*':	// 闭包
    case'?':	// 可选
        return 3;
    case'(':	// 左括号最低
    case')':
        return 0;
    }
    return -1;
}

bool isOperator(char ch)
{
    return ch == '.' || ch == '|' || ch == '?' || ch == '*';
}
