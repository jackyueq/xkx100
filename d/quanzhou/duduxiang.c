// Room: /d/quanzhou/duduxiang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ȫ�ݵ�һ��С��徻���ࡣԶԶ�ɼ���׺�ǽ����������ɭ
�ϣ���Ȼ������ͨ��ס�ҡ�
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west" : __DIR__"northroad3",
		"east" : __DIR__"dudufu",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1860);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
