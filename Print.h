#pragma once
#include "Ds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print();//输出栈中的所有元素
void print_begin();//输出开始界面
void print_rules();//输出规则界面
void print_end();////输出平局结束界面
void print_end1();////输出玩家一获胜界面
void print_end2();////输出玩家二获胜界面
void print_now();////输出比赛常在边框
void print_clear();////清理上次存在元素
void print_final();////输出历史记录
void print_recode(int ply1, int ply2);