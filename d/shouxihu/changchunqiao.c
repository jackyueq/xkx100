// Room: /yangzhou/changchunqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
����������ʯ��������������ڴ���ţ����������ƣ������Լ��
���ö̰����������������ϱ�������Ϊ½�������Ҫ����
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"west"     : __DIR__"shuiyun",
		"eastup"   : __DIR__"changchunling",
	]));
	set("objects", ([
		"/d/city/npc/popo" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
