//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long",@LONG
�����ͨ�����չ����������Ĵ��š��������Ҹ���һͷʯ�����
�գ��ߴ��������࣬��๾�צ���񿥷Ƿ��������������ƺ���ʱҪ�ڿ�
��ȥ��
LONG );
	set("outdoors", "lingjiu");
	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
	]));
	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		__DIR__"npc/lanjian" : 1,
	]));
	set("coor/x", -51000);
	set("coor/y", 30120);
	set("coor/z", 70);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( (dir == "north") &&
		((string)me->query("family/family_name") != "��ң��") &&
		((string)me->query("family/family_name") != "���չ�") &&
		( objectp(present("mei jian", environment(me))) ||
		objectp(present("lan jian", environment(me))) ) )
		return notify_fail("÷��˫�������ס�㣬˵����������ң������أ���\n");
	return ::valid_leave(me, dir);
}