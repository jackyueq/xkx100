// Room: /yixing/tiandi.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ��
һ������أ����д�����ų�һ�������֣�������һЩ���ڸ�����ũ
�ˣ���·��̰��·Ҳ���Դ���侮�ַָ��С��������
LONG );
	set("outdoors", "yixing");
	set("exits", ([
		"west"      : __DIR__"yixing",
		"northeast" : __DIR__"shulin5",
	]));
	set("objects", ([
		__DIR__"npc/banjiu" : 1,
	]));
	set("coor/x", 200);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	if (userp(me))
	if (dir == "west" )
	{
		me->receive_damage("qi", 10);
		tell_object(me,"���������ͻ���С���⣬���ĺ�����խ�����������˽�ȥ��\n");
	}
	else
	{
		me->receive_damage("qi", 10);
		message_vision("$N��������С���⣬������ǰ��ȥ��\n", me);
	}
	return 1;
}
