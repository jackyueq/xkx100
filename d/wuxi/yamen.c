// Room: /d/wuxi/yamen.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ���
���ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ�������ģ���Ȼ�ǹ�С����ԩ
�õġ���������վ����ǰ����ŭ������
LONG );
	set("exits", ([
		"south" : __DIR__"eastroad1",
		"north" : __DIR__"ymzhengting",
	]));
	set("objects", ([
		"/d/city/npc/yayi" : 4,
	]));
	set("coor/x", 380);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if(!wizardp(me) && !me->query("officerlvl") && objectp(present("ya yi",environment(me)))&&dir=="north")
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}
