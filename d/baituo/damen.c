// Room: /d/baituo/damen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������µġ�����ɽׯ���Ĵ��š��������ϵ����̷��ۼ
���أ���֪�����Ŷ����ܹ��ɽ�����Ѫ�����Գ�ׯ���ĸ������Թ���
ǰ���Ҹ�����һֻ����ׯ�ϵ�ʯʨ�ӡ�
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"kongdi",
		"southdown" : __DIR__"shijie",
	]));
	set("objects",([
		__DIR__"npc/menwei" : 2,
		CLASS_D("baituo")+"/first" :1,
	]));
	set("coor/x", -50010);
	set("coor/y", 20010);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "north") && ((int)me->query("shen") > 300) &&
		objectp(present("men wei", environment(me))) &&
		living(present("men wei", environment(me))))
		return notify_fail("��������һ���������������������һ���Ͷ��ģ������\n");
	return ::valid_leave(me, dir);
}
