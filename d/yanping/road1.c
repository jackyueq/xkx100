// Room: /d/yanping/road1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
һ����ʯ�������ϱ������߱��Ǹ��õ�Χǽ����������ש���͵ĳ�
ǽ����ƽ����ɽ���������нֵ�ֻ�ȳ�ǽ�԰�������ǽ���ٽ�һ�࣬��
ǽ�ߺ������ǽ�������ˡ�
LONG );
	set("exits", ([
		"north"     : __DIR__"dongmen",
		"south"     : __DIR__"yanfumen",
		"southwest" : __DIR__"road2",
	]));
	set("objects", ([
		"/d/village/npc/boy" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1520);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
