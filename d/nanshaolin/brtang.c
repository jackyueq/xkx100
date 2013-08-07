// Room: /d/nanshaolin/brtang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"������"NOR);
	set("long", @LONG
����ǰ��һ���ܴ��Ժ�䣬��Χ�ø�ǽΧס��Ժ���Ҷ���д�š���
���á��������֡����������ֵ��Ӿ������¸��Ҹ����书�����ڡ��к�
�������ɮ�˽���������Ժ�ڴ����������������������
LONG );
	set("exits", ([
		"west" : __DIR__"stoneroad3",
		"east" : __DIR__"lwc16",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		CLASS_D("nanshaolin") + "/dahen" : 1,
		__DIR__"npc/xiao-ku" : 1
	]));
	set("coor/x", 1840);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "��������") && dir == "east" &&
		objectp(present("xuannan dashi", environment(me))))
		return notify_fail("���Ѻȵ����������˱��ɵ���ϰ��֮������Ǳ��ɵ��ӣ��������ڡ�\n");
		
	return ::valid_leave(me, dir);
}
