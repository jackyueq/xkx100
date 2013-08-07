// Room: /d/xingxiu/xxroad5.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
ɽ�������･�����ƽ�������Ѿ�������������ɽ���׵�ˮ������
����һ��ɽ����
LONG );
	set("exits", ([
		"south" : __DIR__"xxroad4",
		"enter" : __DIR__"cangku",
		"north" : __DIR__"xxroad6",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/chuchen" : 1,
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -51000);
	set("coor/y", 20120);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "������") &&
		dir != "south" && (present("chuchen zi", environment(me))))
	{
		say("������һ�Բ�������������"+me->name()+"��ǰ��\n");
		return notify_fail("������һ�Բ�����������������ǰ��\n");
	}
	return ::valid_leave(me, dir);
}
