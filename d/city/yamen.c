// Room: /city/yamen.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ���
���ӷַ���ͷʯʨ�ӵ��Աߡ���ǰ������Ӱ��Ÿ�Ƥ�ģ�����һ��ľ颡�
��Ȼ�ǹ�С����ԩ�õġ�������������ǰѲ�ߡ�
LONG );
	set("exits", ([
		"south" : __DIR__"tongsijie",
		"north" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 2,
//		__DIR__"npc/xunbu" : 1,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}