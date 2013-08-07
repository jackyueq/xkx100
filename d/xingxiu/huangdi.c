// Room: /d/xingxiu/huangdi.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;
void create()
{
	set("short", "ɽǰ�ĵ�");
	set("long", @LONG
��վ��ʯɽǰ�Ļĵ��ϡ�����˼�������������ȥ�����ǿ����ܲݡ�
˷����ɱ�������ľ�������·���м������޵�����������ͬʱ��������
��һ��һ������û�£����ǿ�ذɡ�
LONG);
	set("objects", ([
		CLASS_D("xingxiu")+"/feitian" : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("exits", ([
		"south"     : __DIR__"xxh2",
		"northup"   : __DIR__"riyuedong1",
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20300);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if (dir =="northup" && present("feitian zi", environment(me)) &&
		(!myfam || myfam["family_name"] != "������") &&
		me->query("combat_exp") < 100000) 
		return notify_fail("�����ӵ�ס���㣺������������а�ɵ�����ô����ȥ�ݼ��������ɣ�\n");
	return ::valid_leave(me, dir);
}

