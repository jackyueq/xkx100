// Room: /d/suzhou/tingyu.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������ݳ��ڵ�һ��Ψһ��һ������ˡ��������Ÿ��ָ�����
�鼮��ʲôС˵��������������������������������书�����ȵȵȵȡ�
ֻ�뻨�������ӾͿ�������Ҫ���顣
LONG );
//	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : __DIR__"nandajie2",
	]));
	set("objects", ([
		__DIR__"npc/bookboss" : 1,
	]));
	set("coor/x", 860);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
