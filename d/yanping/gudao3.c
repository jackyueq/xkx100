// Room: /d/yanping/gudao3.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "���ӹŵ�");
	set("long", @LONG
����������������ɽ�������������Ĺ���̣����ղ�����⡣ɽ��
�������޳�û�޳�����·������·����һ���Ẻ���������ϣ������۴�
�����㡣
LONG );
	set("exits", ([
		"westup"    : __DIR__"gudao2",
		"northeast" : __DIR__"gudao4",
	]));
	set("objects", ([
		"/d/qingcheng/npc/jia" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1300);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
