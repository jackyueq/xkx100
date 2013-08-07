// Room: /d/nanshaolin/zdyuan.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"֤��Ժ"NOR);
	set("long", @LONG
���������ȣ�ǰ�����һƬ������Ժ�䡣Ժ�ŵ��Ҷ���д�š�֤��
Ժ���������֣���������ɮ�����ճ���з𣬲��������ĵط���Ժ��
�����˴����Եü����ľ�������Χ�������в��ϴ���������󳪺�ľ
���û���������
LONG );
	set("exits", ([
		"west" : __DIR__"chanfang-1",
		"east" : __DIR__"celang-2",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/dapi" : 1,
		__DIR__"npc/xiao-ku" : 1
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1800);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "��������") && dir == "west" &&
		objectp(present("dapi dashi", environment(me))))
		return notify_fail("��ƣ��ʦ�ȵ���֤��Ժ�˱��µ�������֮������Ǳ��µ��ӣ��������ڡ�\n");
	return ::valid_leave(me, dir);
}


