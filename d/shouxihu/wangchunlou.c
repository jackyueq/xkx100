// Room: /yangzhou/wangchunlou.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","����¥");
	set("long",@LONG
����¥λ��������������������̨����������������麣����㣬��
������Ъɽ���߶���¥���½�Ϊ�����ȡ��²��ϱ�������¥�ݹ�������
��׺��ˮԺ��ɽͥ����ɽˮ��ʯ�������ڡ��ײ�����ɽǽ��ľ�������
�ţ�����ɡ���÷�������Ρ���������Τׯ����ĳ�˼������(lian)��
¥����Ϊ��ש����¶̨������ʯ����¥������������ͼ����������ͷ��
¥ͷ��ǽ����ʯɽ�ӡ�
LONG );
	set("item_desc", ([
		"lian" : HIM"
        ��        ��
        ��        ��
        ��        ��
        ��        ��
        ݺ        ��
        ��        ��
        ��        ��
\n"NOR,
	]));
	set("exits", ([
		"north" : __DIR__"changdi3",
		"east"  : __DIR__"baitaqingyun",
		"west"  : __DIR__"ershisiqiao",
		"up"    : __DIR__"wangchunlou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}