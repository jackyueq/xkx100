// wg_wupinfang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ʒ��");
	set("long", @LONG
������Ʒ����һ������ӡ�����ŵ��������룬��������Ĺܼ���
�����渺��ģ�һЩ�����ڸ�����Ʒ���ߵĹܼ�˵��ʲô��
LONG);
	set("exits", ([
		"west" : __DIR__"wg_lang4",
		"east" : __DIR__"wg_lang6",
		"north" : __DIR__"wg_shilu-1",
	]));
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/wg_laoli" : 1,
		__DIR__"npc/wg_tlsdizi" : 1,
	]));
	set("coor/x", 41);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

