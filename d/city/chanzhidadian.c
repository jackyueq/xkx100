// Room: /city/chanzhidadian.c

inherit ROOM;

void create()
{
	set("short", "�����´��");
	set("long", @LONG
�����޵�����������Ľ���������������ʮ���޺�������Ȼ����
�Ǵ󣬵������������֮ȫ����Ҳ���ټ������Կ�������һ���ĸ�ԣ��
���ˡ�����������ƣ��о�֮�������ڶ���
LONG );
	set("exits", ([
		"east"   : __DIR__"chanzhixf",
		"south"  : __DIR__"chanzhisi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", -8);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}