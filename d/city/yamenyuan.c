// Room: /city/yamenyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "���Ŵ�Ժ");
	set("long", @LONG
һ�������Ժ�ӣ������������ޱ����վ�š��������׶���Ϊһ��
����ţ�������һ�Ҷ���ݡ������Ű����ţ���ϡ���Կ���������Ӱ��
������ǩѺ������������һ�¶��ţ��Ŷ��Ͽ������顸���ԡ���
LONG );
	set("exits", ([
		"south"   : __DIR__"yamen",
		"northup" : __DIR__"zhengtang",
		"east"    : __DIR__"qianyafang",
		"west"    : __DIR__"tianjing",
	]));
	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -20);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}