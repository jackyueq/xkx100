// Room: /d/kunlun/xuedi.c
// Last Modified by winder on Jun. 29 2001
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
ѩ�������и���ѩ�ѣ����ѩ����ũ�һ���Ĳݶѡ����캮�ض���
¡���Ϻ��ʬ�岻�ḯ����������һͷأӥ�ڿ��������˼���Ȧ�ӣ�
Ѱ�һ����Ա��������ʳ��
LONG );
	set("outdoors", "hongmei");
	set("exits", ([
		"south" : __DIR__"kekexili",
	]));
	set("objects", ([
		"/clone/misc/corpse" : 1,
	]));
	set("coor/x", -100000);
	set("coor/y", 20010);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
