// Room: /d/songshan/eastting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͥ");
	set("long", @LONG
������һ��ССͥԺ��Ժ���ﳣ����ɽ���ӽ��������ͥԺ���ܰ�
ǽ�³��ŵ�С��ľ�ż��ð�����ǰ�ɫС��������ϸʯ�̾͵�С·��
��ľ�Ժͳ��ݼ䴩����
LONG );
	set("outdoors", "songshan");
	set("exits", ([
		"east"  : __DIR__"jianlu",
		"west"  : __DIR__"eastpath1",
		"north" : __DIR__"eastpath2",
		"south" : __DIR__"shuzhai",
	]));
	set("objects", ([
		__DIR__"npc/dizi": random(2),
	]));
	set("coor/x", 0);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
