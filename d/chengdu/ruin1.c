// Room: /d/chengdu/ruyin1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "�ƾɴ�լ");
	set("long", @LONG
������һ���ƾɴ�լ��ǰԺ�������Ѿ�������һ�룬���ڵ�������
ס�����ȥ·��ͥԺ���Ӳݴ����������Ѿ��ܾ�û����ס�ˣ���˵����
�����й����֣����ǵ�Ҳ��û��˵�����˱�������˸����ľ�����Ȼ
�ճ����
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([ /* sizeof() == 1 */
		"out"   : __DIR__"cai",
		"west"  : __DIR__"ruin2",
		"north" : "/d/npc/m_weapon/lianbangshi",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 3,
	]));
	set("coor/x", -8070);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

