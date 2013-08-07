// Room: /d/tiezhang/shanmen.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ǽ������ŷ�ɥ���ġ����ư���Դӡ����Ƽߺ�ɽ��һ��
����ɽ�ɴ��һ�겻��֮�󣬰�������ˮ��Ư����ͷ���𽭺���������
��ɽ�ıؾ�֮·������С·ͨ��ɽ�·��һ������һ������(paizi) ��
���Ե������ڲ�ʱ����һЩ�������ƺ������ڰ��м��ӡ�
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 2 */
		"northup"   : __DIR__"shanlu1",
		"southdown" : __DIR__"shanjiao",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/heiyi" : 2,
		CLASS_D("tiezhang")+"/first" : 1,
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"paizi" : "[31m��������--����[0;37;0m\n",
	]));
	set("no_clean_up", 0);

	set("coor/x", -2040);
	set("coor/y", -2000);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "���ư�") &&
		dir == "northup" && (int)me->query("combat_exp", 1) >= 10000 &&
		objectp(present("heiyi bangzhong", environment(me))))
		return notify_fail("���°��ڳ鵶��ס���ȥ·��˵�������㲻�����ư���ӣ�������ɽ��\n");

	return ::valid_leave(me, dir);
}
