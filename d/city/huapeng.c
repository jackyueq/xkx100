// Room: /city/huapeng.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ҩ�������ò�ȥƤ��������ɵ�һ��������ϵ���Ҷ��
�ɣ�����������������Ȼ��ʯ������������ľ��ݣ����Զζ������ˮ��
��ת���ܣ������������ڴ������ͻ������⾳���
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"west"       : __DIR__"chanzhimenqian",
	]));
	set("coor/x", -19);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}