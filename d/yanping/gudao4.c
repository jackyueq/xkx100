// Room: /d/yanping/gudao4.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣ɽ��
�������޳�û�޳�����·������
LONG );
	set("exits", ([
		"southwest" : __DIR__"gudao3",
		"northeast" : __DIR__"ximen",
	]));
	set("objects", ([
		__DIR__"npc/wubushe" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1400);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
