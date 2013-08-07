// Room: /wuliang/shanlu6.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
ת��ɽ�ֻ꣬��һ�����ʯ֮���������Ŷ�ʮ���ˡ���С�������
�߽�ǰȥ�����˴���һ����С����������һ�����֮�ϣ��߳����ˣ��
��һ��ɽ����ӣ���̬�����ư�������������ũ����˾�����ˡ�
LONG );
	set("outdoors", "wuliang");
	set("exits", ([
		"eastup"  : __DIR__"shanlu5",
		"northup" : __DIR__"shanlu7",
	]));
	set("objects", ([
		__DIR__"npc/shennongdizi" : 3,
		__DIR__"npc/hong" : 1,
		__DIR__"npc/sheng" : 1,
		__DIR__"npc/sikongxuan" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -71000);
	set("coor/y", -79980);
	set("coor/z", 50);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (objectp(present("sikong xuan", environment(me))))
		return notify_fail("˾������ס��˵�������˴��������������йأ���ͯ��֮����ɱ��\n�⣬�㻹���ߣ�\n");
	return ::valid_leave(me, dir);
}
