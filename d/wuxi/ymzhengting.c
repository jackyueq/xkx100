// Room: /d/wuxi/zhengtang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���ϵ�����ʮ�����¡����������ס���Ǹ����������˼���ׯ�ء�
��ǽ������һ�����ң����顰����������ĸ���������Ĵ��֡�����
��������֮ʱ��֪�������ڵ񻨷������������飬ʦү�����ں�
LONG
	);
	set("exits", ([
		"south" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/xia": 1,
		__DIR__"npc/shiye": 1,
	]));
	set("coor/x", 380);
	set("coor/y", -780);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
