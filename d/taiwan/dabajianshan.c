// Room: /d/taiwan/dabajianshan.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��Լ�ɽ");
	set("long", @LONG
�񶫿����������紦��һ��ͻ������Ϊ��Լ�ɽ��ɽ��ǧ�ɣ���
���������Ĵθ�ɽ���ɽ�������С�������塹֮�ƵĴ�Լ�ɽ������
ͻأ��̩�������Ϊ����ɽ����
LONG );
	set("exits", ([
		"westdown" : __DIR__"maolishe",
	]));
	set("objects", ([
//		__DIR__"npc/taiyaren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2530);
	set("coor/y", -6990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

