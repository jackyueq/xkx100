// Room: /d/baituo/dongnei.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ɽ�������ѵ����ڡ���ɭʪ��������ϣ�����һЩ�����ӡ���
���£����еĻ�Ƥ���θ�����Ŀ���Ա���һ�ප��������������Ů�ӵĿ�
����
LONG	);
	set("exits", ([
		"west" : __DIR__"cedong",
		"south" : __DIR__"dongkou",
	]));
	set("objects",([
		__DIR__"npc/shanzei3" : 1,
	]));
	set("coor/x", -49960);
	set("coor/y", 20040);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
	if (  (dir == "west") &&
		objectp(present("shanzei tou", environment(me))) )
	return notify_fail("ɽ��ͷ����ȭͷ������ռ�����ŵı��ˣ������\n");
	return ::valid_leave(me, dir);
}
