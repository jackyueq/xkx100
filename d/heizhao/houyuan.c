// Room: /heizhao/houyuan.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��Ժ");
	set("long", @LONG
��Ժ���й��������ջ�ϲ�𣬷�����ͦ����һ�����͵��ֳ�
���ƵĻ���Τ�ӡ����������Ͼ�������һ����ɮ�����봹�أ����
��ɮ��ֱ������գ����Ե�ü�붨���м����Ϻ��С�Сɳ��������
�ԡ�
LONG );
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/xiaoshami2" : 2,
		__DIR__"npc/laoheshang" : 1,
		CLASS_D("dali")+"/yideng/yideng" : 1,
	]));
	set("exits", ([
		"south"  : __DIR__"zhulin1",
	]));
	set("coor/x", -5020);
	set("coor/y", -1000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}