// Room: /wuliang/shanlu8.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��ʯɽ·������������ġ���Ϊɽ�Ͼ����������ɵĵ�ͷ�ˡ���
������������ɽ���Լ������Ѿã����������ʲƣ�����·Ҳ�޵���ģ
������
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"   : __DIR__"shanlu9",
		"southdown" : __DIR__"shanlu7",
	]));
	set("coor/x", -71000);
	set("coor/y", -79960);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}