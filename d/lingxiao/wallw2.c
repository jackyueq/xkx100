// Room: /d/lingxiao/wallw2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ");
	set("long", @LONG 
�ߴ���ʤ������ֻ��ѩ����˪Ҳ�׷׶��¡�ͷ�����ϻ���ʯ��ľ�⣬
һ���Ӿ�˪ѩ���죬�����ס���ʫ�ơ�����˪ѩ�������������Ҳ��
�������˼�ɡ�
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west" : __DIR__"wallw3",
		"east" : __DIR__"wallw1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31020);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup(); 
	replace_program(ROOM);
}

