// Room: /d/qilian/shalu1.c
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
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : "/d/xingxiu/jiayuguan",
		"southwest" : __DIR__"shalu2",
	]));
	set("coor/x", -20000);
	set("coor/y", 300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}