// Room: /d/suzhou/tulu2.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long",@long
��������һ����·�ϡ����ϱ���������ԶԶ��ȥ����������������
���߿����ҵ���ȥ���ݵĹٵ���
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"tulu1",
		"southwest" : __DIR__"jiangbian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 780);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
