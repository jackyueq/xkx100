//zhandao2.c
inherit ROOM;

void create()
{
	set("short", "ջ��");
	set("long", @LONG
������ͨ�����̵�ջ��������ï�����ƣ�������ա�
    ԶԶ������ͷ��������������������ۼ�ķ��ܻ����ˡ�
LONG);
	set("exits", ([
		"northup"   : __DIR__"tianweitang",
		"southdown" : __DIR__"zhandao1",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 1030);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}