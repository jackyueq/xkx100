// Room: /yangzhou/pingtai4.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ƽ̨");
	set("long", @LONG
���Ƿ�����ɽ����ǰƽ̨��ƽ̨����ͨ������·��ƽ̨��������
�ء���ͩ����ͨ�����ţ����Ϸ����������µ�ɽ���ˡ�
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"north"     : __DIR__"lianhuaqiao",
		"southwest" : __DIR__"lianxingsi",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", -10);
	set("coor/y", 90);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
