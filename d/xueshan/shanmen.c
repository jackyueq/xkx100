// shanmen.c ѩɽ��ɽ��

inherit ROOM;

void create()
{
	set("short","ѩɽ��ɽ��");
	set("long",@LONG
������ѩɽ�����µ�ɽ�ţ���ǰ�����ﲻ���Ľ��㳯ʥ����ͽ����
������������˿�����ϵĲ�˿��ɽ��(gate)ǰվ�˸��ֳַ����ĸ��ײ�
��ά�����򣬶�����һ����ʯ���̳ɵ�ɽ·��
LONG );
	set("outdoors","xueshansi");
	set("no_fight", 1);
	set("exits",([
		"north"    : __DIR__"guangchang",
		"eastdown" : "/d/xuedao/nroad4",
	]));
	set("item_desc",([
		"gate" : "���Ⱥ���ͭɫ���ţ��Ǻ�����֮�����������ƶ��ġ�\n",
	]));
	set("objects",([
		CLASS_D("xueshan")+"/gelunbu": 1,
		"/d/wudang/npc/guest": 2,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", -70000);
	set("coor/y", -20000);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "ѩɽ��") &&
		(dir == "north") &&
		(me->query_temp("marks/xueshangate") != 1) &&
		objectp(present("gelunbu", environment(me))))
	return notify_fail("���ײ���ס��˵����׼����ʲ�ṩ�����Ƿ�үѽ��\n");

	return ::valid_leave(me, dir);
}
