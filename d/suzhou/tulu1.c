// Room: /d/suzhou/tulu1.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long",@long
��������һ����·�ϣ����ϱ߲�Զ������������������ȥ���ݵĹ�
����
long);
	set("outdoors", "suzhou");
	set("exits",([
		"north"     : __DIR__"road4",
		"southwest" : __DIR__"tulu2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 790);
	set("coor/y", -1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
