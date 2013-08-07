// Room: /yangzhou/caohecexiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","С�ݺӲ���");
	set("long",@LONG
�����ٺӵĲݺ�С���ϵ�һ������ͨͨ�����ӣ�Ҳ������ľ�����
��һ���֡��򶫴����ݺ�С�־��ǹٺ��ˣ�����ͨ�򷱻����ֵ�ͨ���֣�
��������������ͨ���ţ����ݵ����š�������С��ȴ�������֣�������
�����̣��������С���ؽְ�̯��ߺ�����Լ������⡣
LONG );
	set("outdoors", "yangzhouw");
	set("exits", ([
		"east"      : __DIR__"yudian",
		"southeast" : __DIR__"huadian",
		"southwest" : __DIR__"garments",
		"north"     : __DIR__"caizhu",
		"northeast" : __DIR__"tongsijie",
	]));
	set("objects", ([
		__DIR__"npc/tangfan" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}