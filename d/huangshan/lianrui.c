// Room: /d/huangshan/lianrui.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
��������������໥���У�����ǡ������֮��岻�ߣ��ɹ�ʯ��
��룬�ߵ�������������ߣ����Ҳ���ʤ�����������˺�����
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"yuping",
	]));
	set("objects", ([
		__DIR__"obj/guai" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
