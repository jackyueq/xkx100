//Room: wdroad5.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ�������Ũ�ܵ����֣���ɭ
ɭ��ʮ�����ˡ������������¶��߽��ˡ�����ȴ��һƬ�ݵء�
LONG);
	set("outdoors", "sanbuguan");
	set("exits", ([
            "northwest" : __DIR__"wdroad6",
            "north"     : "/d/xiangyang/caodi6",
            "northeast"      : __DIR__"wdroad4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
