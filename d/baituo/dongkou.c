// Room: /d/baituo/dongkou.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ɽ�������ѵĶ��ڲ�������֮�£��������е���ɭ��������һ��ʯ
���͵����棬����ľ�壬��ǿ����š�����ʱ�⣬������������ֵ���
�����ر�ɭ�ϡ�
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongnei",
		"south" : __DIR__"xiaolu4",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 2,
	]));
	set("coor/x", -49960);
	set("coor/y", 20030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
