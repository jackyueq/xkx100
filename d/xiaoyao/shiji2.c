// shiji2.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�γ�����ʯ������������ȱ����������������ô����ɭɭ��
�о���ʯ�����Ŷ���������չ��һ����ȥ��������������ͷ��
LONG );
	set("exits", ([
		"east" : __DIR__"shishi2",
		"west" : __DIR__"shidong",
		"north" : __DIR__"fangjian2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}