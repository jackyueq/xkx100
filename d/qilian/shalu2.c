// Room: /d/qilian/shalu2.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "��ʯɳ·");
	set("long", @LONG
������һ����Ƨ����ʯɳ·�ϣ���������һ����ΰ�Ĺذ�������ͨ
���Ȫ��
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northeast" : __DIR__"shalu1",
		"southwest" : __DIR__"jiuquan",
	]));
	set("objects", ([
		__DIR__"npc/duzhizhu" : 2,
	]));
	set("coor/x", -20100);
	set("coor/y", 290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}