// /kaifeng/dadao2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ��бб��С·������ȥ��Զ��Ƭ���֣�����ȥ�ں������ԴӲ���
ǰ�����г���Ұ�����˺��������������ߡ�ֻ��̰ͼ·�����˻�����
������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"yezhulin",
		"northeast" : __DIR__"dadao1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
