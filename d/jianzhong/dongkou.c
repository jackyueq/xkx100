#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG
������Ĵ�������������ʯ��ᾣ���һ����������Ȼ���¡�
���֮�У���һ����ɽ����������ǰ����֪����ʲôǰ������ס
�����档
LONG
	);
	set("exits",([
		"south":__DIR__"shangu",
		"north":__DIR__"donghou",
		"enter":__DIR__"shandong1",
	]));
	set("objects",([
		__DIR__"npc/shendiao":1,
		CLASS_D("gumu")+"/yangguo":1,
	]));
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -440);
	set("coor/z", 0);
	setup();
}
	