// Room: /yangzhou/shuixie.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short","����ˮ�");
	set("long",@LONG
���绨��ˮ�Ϊ����һ麣����Σ�������Ъɽ���߶�������̨�ף�
����ƽ̨�������ʯ���塣���������鷨��ŷ����ʯ�����ҡ���������
��֮��¬���ڼ������(lian)�������۾�������̨������¥����ʮ����
��ʤ�����۵ס���������������ά��˼������(lian1)��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIR"
        ��        ¥
        ��        ̨
        ��        ��
        ��        ��
        ��        ��
\n"NOR,
		"lian1" : HIG"
        ��        ��
        ��        ʯ
        ��        ��
        ��        ̦
        ��        ��
        ��        ��
        ��        ��
\n"NOR,
	]));
	set("exits", ([
		"northwest" : __DIR__"guanshaoting",
		"southeast" : __DIR__"lianxingsi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}