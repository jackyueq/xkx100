// Room: /yangzhou/jicuixuan.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
��������������麣���һ�����ȡ�ɽʯˮ�ء�����������ɾ���ͥ
Ժ�������Ҷ�������Ҽ������(lian)��������һ�����ȣ������϶�
ͨ��ͤ��ͤ�������ࡱ������ͤ����Ժ����Ϊ������鿡������������
��(lian1) �����ǰ��ˮƽ̨���Ͱ������ˣ��ɵá��������ơ�����ּ
Ȥ����Ϊ������ˮ��֮�á�������������ὡ���뼯ʫ���(lian2)��
��������������
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIG"
        ��        ��
        ʯ        ��
        ͨ        ��
        Ϫ        ��
        ˮ        ��
\n"NOR,
		"lian1" : HIG"
        ��        ��
        ԰        ��
        ��        ٳ
        ��        ��
        ˮ        ׯ
\n"NOR,
		"lian2" : HIG"
        ��        ǰ
        ҵ        ��
        ��        ��
        ��        ��
        ��        ��
\n"NOR,
	]));
	set("exits", ([
		"northwest" : __DIR__"baitaqingyun",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}