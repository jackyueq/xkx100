// Room: /d/yanping/gudao2.c
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
		"westdown" : __DIR__"gudao1",
		"eastdown" : __DIR__"gudao3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1200);
	set("coor/y", -6300);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
