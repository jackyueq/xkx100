// Room: /yangzhou/guanshaoting.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>;
inherit ROOM;
void create()
{
	set("short","����ͤ");
	set("long",@LONG
���绨��Ϊ��ҩĵ��԰��ȡ������ĵ����������ҩ��֮�⡣Ϊ����
���ϰ���������������̨֮�䣬�ɹ���ͤ������������ˮ鿡��ഫΪǬ
¡������ҩ��������ͤ���ܷ��Σ����ڻ�̳֮�У�����֣����ī������
��ͤ���ң��������ұ���л���������(lian)��ͤ�ж���Ϊ��ҩ�ʻ档
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIR"
        ��        ��
        ��        ҩ
        ��        ��
        ��        ��
        ��        ��
\n"NOR,
	]));
	set("exits", ([
		"northwest" : __DIR__"chongyanting",
		"southeast" : __DIR__"shuixie",
	]));
	set("objects", ([
		"/d/village/npc/kid" : 3,
	]));
	set("coor/x", -40);
	set("coor/y", 80);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}