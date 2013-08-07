// time.c
// Last Modified by Winder on Aug. 15 2001

#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;
mapping *lunarfete = ({
	([	"month" :  1, "day" :  1, "name" : RED"����"NOR]),
	([	"month" :  1, "day" : 15, "name" : RED"Ԫ����"NOR]),
	([	"month" :  5, "day" :  5, "name" : GRN"�����"NOR]),
	([	"month" :  7, "day" :  7, "name" : CYN"��Ϧ���ɽ�"NOR]),
	([	"month" :  8, "day" : 15, "name" : CYN"�����"NOR]),
	([	"month" :  9, "day" :  9, "name" : MAG"������"NOR]),
	([	"month" : 12, "day" :  8, "name" : BLU"���˽�"NOR]),
	([	"month" : 12, "day" : 23, "name" : RED"С��"NOR]),
	([	"month" : 12, "day" : 30, "name" : RED"��Ϧ"NOR]),
});
mapping *solarfete = ({
	([	"month" :  1, "day" :  1, "name" : RED"Ԫ��"NOR]),
	([	"month" :  2, "day" : 14, "name" : MAG"���˽�"NOR]),
	([	"month" :  3, "day" :  5, "name" : RED"ѧ�׷������"NOR]),
	([	"month" :  3, "day" :  8, "name" : YEL"���ʸ�Ů��"NOR]),
	([	"month" :  3, "day" : 12, "name" : GRN"ֲ����"NOR]),
	([	"month" :  3, "day" : 15, "name" : YEL"������Ȩ����"NOR]),
	([	"month" :  3, "day" : 23, "name" : YEL"����������"NOR]),
	([	"month" :  3, "day" : 31, "name" : YEL"��ȫ������"NOR]),
	([	"month" :  4, "day" :  1, "name" : GRN"���˽�"NOR]),
	([	"month" :  4, "day" :  5, "name" : CYN"������"NOR]),
	([	"month" :  4, "day" :  6, "name" : RED"���Ŵ�ѧУ��"NOR]),
	([	"month" :  4, "day" :  7, "name" : CYN"����������"NOR]),
	([	"month" :  4, "day" :  9, "name" : CYN"Ү��������"NOR]),
	([	"month" :  4, "day" : 12, "name" : CYN"���������һ"NOR]),
	([	"month" :  4, "day" : 22, "name" : CYN"���������"NOR]),
	([	"month" :  5, "day" :  1, "name" : WHT"�����Ͷ���"NOR]),
	([	"month" :  5, "day" :  4, "name" : GRN"�й������"NOR]),
	([	"month" :  5, "day" :  8, "name" : GRN"���ʺ�ʮ����"NOR]),
	([	"month" :  5, "day" : 10, "name" : HIR"ĸ�׽�"NOR]),
	([	"month" :  5, "day" : 12, "name" : GRN"���ʻ�ʿ��"NOR]),
	([	"month" :  5, "day" : 15, "name" : GRN"���ʼ�ͥ��"NOR]),
	([	"month" :  5, "day" : 17, "name" : GRN"���������"NOR]),
	([	"month" :  5, "day" : 19, "name" : GRN"ȫ��������"NOR]),
	([	"month" :  5, "day" : 26, "name" : HIY"����"NOR]),
	([	"month" :  5, "day" : 31, "name" : GRN"����������"NOR]),
	([	"month" :  6, "day" :  1, "name" : MAG"���ʶ�ͯ��"NOR]),
	([	"month" :  6, "day" :  5, "name" : MAG"���绷����"NOR]),
	([	"month" :  6, "day" :  6, "name" : MAG"ȫ��������"NOR]),
	([	"month" :  6, "day" : 21, "name" : HIG"���׽�"NOR]),
	([	"month" :  6, "day" : 25, "name" : MAG"ȫ��������"NOR]),
	([	"month" :  6, "day" : 26, "name" : MAG"���ʽ�����"NOR]),
	([	"month" :  7, "day" :  1, "name" : RED"�й�������"NOR]),
	([	"month" :  7, "day" :  1, "name" : HIR"��ۻع���"NOR]),
	([	"month" :  7, "day" :  1, "name" : HIY"���罨����"NOR]),
	([	"month" :  7, "day" :  7, "name" : RED"��ս������"NOR]),
	([	"month" :  7, "day" : 11, "name" : GRN"�����˿���"NOR]),
	([	"month" :  8, "day" :  1, "name" : GRN"������"NOR]),
	([	"month" :  9, "day" :  8, "name" : YEL"����ɨä��"NOR]),
	([	"month" :  9, "day" :  8, "name" : YEL"�����������Ž���"NOR]),
	([	"month" :  9, "day" : 10, "name" : YEL"�й���ʦ��"NOR]),
	([	"month" :  9, "day" : 16, "name" : HIG"���ʺ�ƽ��"NOR]),
	([	"month" :  9, "day" : 20, "name" : YEL"�й�������"NOR]),
	([	"month" :  9, "day" : 27, "name" : YEL"����������"NOR]),
	([	"month" : 10, "day" :  1, "name" : RED"�й������"NOR]),
	([	"month" : 10, "day" :  1, "name" : RED"�������ֽ�"NOR]),
	([	"month" : 10, "day" :  5, "name" : RED"����ס����"NOR]),
	([	"month" : 10, "day" :  9, "name" : RED"����������"NOR]),
	([	"month" : 10, "day" : 14, "name" : RED"�����׼��"NOR]),
	([	"month" : 10, "day" : 16, "name" : RED"������ʳ��"NOR]),
	([	"month" : 10, "day" : 24, "name" : RED"���Ϲ���"NOR]),
	([	"month" : 10, "day" : 31, "name" : RED"�����ڼ���"NOR]),
	([	"month" : 11, "day" :  1, "name" : HIB"��ʥ��"NOR]),
	([	"month" : 11, "day" : 17, "name" : HIY"����ѧ����"NOR]),
	([	"month" : 11, "day" : 25, "name" : HIY"�ж���"NOR]),
	([	"month" : 12, "day" :  5, "name" : BLU"����־Ը��Ա��"NOR]),
	([	"month" : 12, "day" : 10, "name" : BLU"������Ȩ��"NOR]),
	([	"month" : 12, "day" : 20, "name" : HIG"���Żع���"NOR]),
	([	"month" : 12, "day" : 24, "name" : BLU"ʥ��ҹ"NOR]),
	([	"month" : 12, "day" : 25, "name" : BLU"ʥ����"NOR]),
});
mixed LunarCal = ({ 
	({ 23,  3, 2, 17, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0 }),  /* 1936 */ 
	({ 41,  0, 4, 23, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 }), 
	({ 30,  7, 5, 28, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1 }), 
	({ 49,  0, 6, 33, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }), 
	({ 38,  0, 0, 38, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }),  /* 1940 */ 
	({ 26,  6, 2, 44, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0 }), 
	({ 45,  0, 3, 49, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 35,  0, 4, 54, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }), 
	({ 24,  4, 5, 59, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 }),  /* 1944 */ 
	({ 43,  0, 0,  5, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }), 
	({ 32,  0, 1, 10, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1 }), 
	({ 21,  2, 2, 15, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }), 
	({ 40,  0, 3, 20, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }),  /* 1948 */ 
	({ 28,  7, 5, 26, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }), 
	({ 47,  0, 6, 31, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1 }), 
	({ 36,  0, 0, 36, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 26,  5, 1, 41, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }),  /* 1952 */ 
	({ 44,  0, 3, 47, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1 }), 
	({ 33,  0, 4, 52, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0 }), 
	({ 23,  3, 5, 57, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }), 
	({ 42,  0, 6,  2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }),  /* 1956 */ 
	({ 30,  8, 1,  8, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 48,  0, 2, 13, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 38,  0, 3, 18, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }), 
	({ 27,  6, 4, 23, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0 }),  /* 1960 */ 
	({ 45,  0, 6, 29, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 }), 
	({ 35,  0, 0, 34, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }), 
	({ 24,  4, 1, 39, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 }), 
	({ 43,  0, 2, 44, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 }),  /* 1964 */ 
	({ 32,  0, 4, 50, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 }), 
	({ 20,  3, 5, 55, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }), 
	({ 39,  0, 6,  0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 29,  7, 0,  5, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 }),  /* 1968 */ 
	({ 47,  0, 2, 11, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }), 
	({ 36,  0, 3, 16, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 }), 
	({ 26,  5, 4, 21, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1 }), 
	({ 45,  0, 5, 26, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 }),  /* 1972 */ 
	({ 33,  0, 0, 32, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1 }), 
	({ 22,  4, 1, 37, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 }), 
	({ 41,  0, 2, 42, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1 }), 
	({ 30,  8, 3, 47, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 }),  /* 1976 */ 
	({ 48,  0, 5, 53, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1 }), 
	({ 37,  0, 6, 58, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }), 
	({ 27,  6, 0,  3, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 }), 
	({ 46,  0, 1,  8, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0 }),  /* 1980 */ 
	({ 35,  0, 3, 14, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1 }), 
	({ 24,  4, 4, 19, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 }), 
	({ 43,  0, 5, 24, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 }), 
	({ 32, 10, 6, 29, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1 }),  /* 1984 */ 
	({ 50,  0, 1, 35, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 }), 
	({ 39,  0, 2, 40, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1 }), 
	({ 28,  6, 3, 45, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0 }), 
	({ 47,  0, 4, 50, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }),  /* 1988 */ 
	({ 36,  0, 6, 56, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0 }), 
	({ 26,  5, 0,  1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1 }), 
	({ 45,  0, 1,  6, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0 }), 
	({ 34,  0, 2, 11, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0 }),  /* 1992 */ 
	({ 22,  3, 4, 17, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 }), 
	({ 40,  0, 5, 22, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 }), 
	({ 30,  8, 6, 27, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1 }), 
	({ 49,  0, 0, 32, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1 }),  /* 1996 */ 
	({ 37,  0, 2, 38, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }), 
	({ 27,  5, 3, 43, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1 }), 
	({ 46,  0, 4, 48, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1 }), 
	({ 35,  0, 5, 53, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1 }),  /* 2000 */ 
	({ 23,  4, 0, 59, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }), 
	({ 42,  0, 1,  4, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }), 
	({ 31,  0, 2,  9, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0 }), 
	({ 21,  2, 3, 14, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 }),  /* 2004 */ 
	({ 39,  0, 5, 20, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 }), 
	({ 28,  7, 6, 25, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1 }), 
	({ 48,  0, 0, 30, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }), 
	({ 37,  0, 1, 35, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1 }),  /* 2008 */ 
	({ 25,  5, 3, 41, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }), 
	({ 44,  0, 4, 46, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 }), 
	({ 33,  0, 5, 51, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }), 
	({ 22,  4, 6, 56, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }),  /* 2012 */ 
	({ 40,  0, 1,  2, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 30,  9, 2,  7, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }), 
	({ 49,  0, 3, 12, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1 }), 
	({ 38,  0, 4, 17, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0 }),  /* 2016 */ 
	({ 27,  6, 6, 23, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1 }), 
	({ 46,  0, 0, 28, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0 }), 
	({ 35,  0, 1, 33, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }), 
	({ 24,  4, 2, 38, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1 }),  /* 2020 */ 
	({ 42,  0, 4, 44, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }), 
	({ 31,  0, 5, 49, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0 }), 
	({ 21,  2, 6, 54, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }), 
	({ 40,  0, 0, 59, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1 }),  /* 2024 */ 
	({ 28,  6, 2,  5, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 }), 
	({ 47,  0, 3, 10, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1 }), 
	({ 36,  0, 4, 15, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1 }), 
	({ 25,  5, 5, 20, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0 }),  /* 2028 */ 
	({ 43,  0, 0, 26, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 }), 
	({ 32,  0, 1, 31, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0 }), 
	({ 22,  3, 2, 36, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 }) 
}); 
#define FIRSTYEAR 1936
#define LASTYEAR FIRSTYEAR+sizeof(LunarCal)-1
int *SolarCal = ({ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }); 
mixed SolarDays = ({ 
	({ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, 396 }), 
	({ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366, 397 }) 
}); 
int Source, SolarYear, SolarMonth, SolarDate; 
int LunarYear, LunarMonth, LunarDate, Weekday, Gan, Zhi;
static string *sym_tian=({ "��","��","��","��","��","��","��","��","��","��" });
static string *sym_di=({ "��","��","��","î","��","��","��","δ","��","��","��","��" }); 
string lunar(string arg);
void prepare();

int main(object me, string arg)
{
	mixed *now;
	int t, d, h, m, s, i;
	string time;

	if (arg)
	{
		string yy,mm,dd;
		sscanf(arg, "%d-%d-%d", yy, mm, dd);
		write( "��������� "+HIC"�Ƶ���"+lunar(yy+" "+mm+" "+dd+NOR));
		return 1;
	}
	now = localtime(time());
	t = uptime();
	s = t % 60; t /= 60;
	m = t % 60; t /= 60;
	h = t % 24; t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��\n";

	write( "������һ�������� "HIR + time + NOR);
	write( "���ڵ�������ʱ�� "HIG + NATURE_D->game_time() + "\n"NOR);
	printf("���ڵ� ���� ʱ�� "HIY"%s��%s��%s��%sʱ%s��%s�룬����%s "NOR,
		chinese_number(now[LT_YEAR]),
		chinese_number(now[LT_MON] + 1),
		chinese_number(now[LT_MDAY]),
		chinese_number(now[LT_HOUR]),
		chinese_number(now[LT_MIN]),
		chinese_number(now[LT_SEC]),
		now[LT_WDAY] == 0 ? "��" : chinese_number(now[LT_WDAY]));
	for ( i=0; i<sizeof(solarfete); i++)
	{
		if(solarfete[i]["month"] == now[LT_MON]+1 &&
			solarfete[i]["day"] == now[LT_MDAY])
			printf(solarfete[i]["name"]+NOR);
	}
	write("\n");
	write( "���ڵ� ũ�� ���� "+HIC"�Ƶ���"+lunar(now[LT_YEAR]+" "+(string)(now[LT_MON]+1)+" "+now[LT_MDAY])+NOR);

	prepare();
	return 1;
}
int GetLeap (int year) 
{ 
	if ( year % 400 == 0 ) return 1; 
	else if ( year % 100 == 0 ) return 0; 
	else if ( year % 4 == 0 ) return 1; 
	else return 0; 
} 
int CalConv() 
{ 
	int leap, d, sm, y, im, l1, l2, acc, i, lm, kc; 

	if (Source == 0)
	{ 
		if ( SolarYear <= FIRSTYEAR || SolarYear > LASTYEAR ) return 1; 
		sm = SolarMonth - 1; 
		if ( sm < 0 || sm > 11 ) return 2; 
		leap = GetLeap( SolarYear ); 
		if ( sm == 1 ) d = leap + 28; 
		else d = SolarCal[sm]; 
		if ( SolarDate < 1 || SolarDate > d ) return 3; 
		y = SolarYear - FIRSTYEAR; 
		acc = SolarDays[leap][sm] + SolarDate; 
		Weekday = ( acc + LunarCal[y][2] ) % 7; 
		kc = acc + LunarCal[y][3]; 
		Gan = kc % 10; 
		Zhi = kc % 12; 
		if ( acc <= LunarCal[y][0]) 
		{ 
			y--; 
			LunarYear = SolarYear - 1; 
			leap = GetLeap( LunarYear ); 
			sm += 12; 
			acc = SolarDays[leap][sm] + SolarDate; 
		} 
		else LunarYear = SolarYear; 
		l1 = LunarCal[y][0]; 
		for ( i=0; i<13; i++ ) 
		{ 
			l2 = l1 + LunarCal[y][i+4] + 29; 
			if ( acc <= l2 ) break; 
			l1 = l2; 
		} 
		LunarMonth = i + 1; 
		LunarDate = acc - l1; 
		im = LunarCal[y][1]; 
		if ( im != 0 && LunarMonth > im ) 
		{ 
			LunarMonth--; 
			if ( LunarMonth == im ) LunarMonth = -im; 
		} 
		if ( LunarMonth > 12 ) LunarMonth -= 12; 
	} 
	else /* Lunar */ 
	{ 
		if ( LunarYear < FIRSTYEAR || LunarYear >= LASTYEAR ) return 1; 
		y = LunarYear - FIRSTYEAR; 
		im = LunarCal[y][1]; 
		lm = LunarMonth; 
		if ( lm < 0 ) 
		{ 
			if ( lm != -im ) return 2; 
		} 
		else if ( lm < 1 || lm > 12 ) return 2; 
		if ( im != 0 ) 
		{ 
			if ( lm > im ) lm++; 
			else if ( lm == -im ) lm = im + 1; 
		} 
		lm--; 
		if ( LunarDate > LunarCal[y][lm+4] + 29 ) return 3; 
		acc = LunarCal[y][0]; 
		for ( i=0; i<lm; i++ ) acc += LunarCal[y][i+4] + 29; 
		acc += LunarDate; 
		leap = GetLeap( LunarYear ); 
		for ( i=13; i>=0; i-- ) 
			if ( acc > SolarDays[leap][i] ) break; 
		SolarDate = acc - SolarDays[leap][i]; 
		if ( i <= 11 ) 
		{ 
			SolarYear = LunarYear; 
			SolarMonth = i + 1; 
		} 
		else 
		{ 
			SolarYear = LunarYear + 1; 
			SolarMonth = i - 11; 
		} 
		leap = GetLeap( SolarYear ); 
		y = SolarYear - FIRSTYEAR; 
		acc = SolarDays[leap][SolarMonth-1] + SolarDate; 
		Weekday = ( acc + LunarCal[y][2]) % 7; 
		kc = acc + LunarCal[y][3]; 
		Gan = kc % 10; 
		Zhi = kc % 12; 
	} 
	return 0; 
} 
// ������1937-2031��
string lunar(string arg)
{ 
	int yy, mm, dd, i, OK=0; 
	string lunarmsg;

	sscanf(arg, "%d%d%d", yy, mm, dd);
	if(yy<=2031 && yy>=1937 && mm<=12 && mm>=1 && dd<=31 && dd>=1)
	{ 
		SolarYear  = yy;
		SolarMonth = mm;
		SolarDate  = dd;
		Source = 0;
		CalConv();
		lunarmsg = sprintf("%s��%s��%s��%s%s ", chinese_number(2697+LunarYear), LunarMonth<0 ? "��"+chinese_number(-LunarMonth) : chinese_number(LunarMonth), chinese_number(LunarDate), sym_tian[Gan], sym_di[Zhi]);
		for ( i=0; i<sizeof(lunarfete); i++)
		{
			if(lunarfete[i]["month"] == LunarMonth &&
				lunarfete[i]["day"] == LunarDate)
				lunarmsg += lunarfete[i]["name"]+NOR;
		}
		lunarmsg += "\n"NOR;
	} 
	return lunarmsg;
} 
void prepare()
{
	mixed *now;
	int i, days;
	string time, msg;
	int yy, mm, dd; 

	for( days=1; days<8; days++)
	{
		if (days == 1)
			msg = "������";
		else
			if (days == 2)
				msg = "������";
			else
				msg = "�ٹ�"+chinese_number(days)+"����";
		now = localtime(time() + days * 86400);
		for ( i=0; i<sizeof(solarfete); i++)
		{
			if(solarfete[i]["month"] == now[LT_MON]+1 &&
				solarfete[i]["day"] == now[LT_MDAY])
			{
				printf(msg+solarfete[i]["name"]+"\n");
			}
		}
		SolarYear  = now[LT_YEAR];
		SolarMonth = now[LT_MON] + 1;
		SolarDate  = now[LT_MDAY];
		Source = 0;
		CalConv();
		for ( i=0; i<sizeof(lunarfete); i++)
		{
			if(lunarfete[i]["month"] == LunarMonth &&
				lunarfete[i]["day"] == LunarDate)
			{
				printf(msg+lunarfete[i]["name"]+"\n");
			}
		}
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ: time

    ���ָ������֪�����ڵ���Ϸʱ�䡢��ʵ�ı���ʱ���ũ�������գ���
����Ϸ�Ѿ��������е�ʱ�䡣
    ���ָ������㻻��ũ�����磺 time 1999-12-31�����õ������ũ
�����ڡ�

HELP
	);
	return 1;
}

