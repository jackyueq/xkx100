// hanshuitan.c ��ˮ̶
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
	set("short", "��ˮ̶");
	set("long", @LONG
�����ǲݵصı�Ե������Ѿ���ϡ���ˣ���Ȼ��һ��������صط�
��Ѱ��ʳ������ǰ��һ���岨�����Ĵ�ˮ̶ (tan)������ӳ���£�
ˮ�淺����һ����ɫ�ʺ磬����������������������
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northwest" : __DIR__"caodi2",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : random(3),
	]));
	set("item_desc", ([
		"tan": "̶ˮ���壬��Լ���Լ���ˮ�׵Ĺ�ʯ��ᾣ�һ������ٿ�ش�ˮ���ι����ֲ�֪���㵽�Ŀ�ʯͷ�������ȥ�ˡ�\n",
	]) );
	set("coor/x", -3200);
	set("coor/y", 30);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

