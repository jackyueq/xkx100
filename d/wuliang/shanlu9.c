// Room: /wuliang/shanlu9.c
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
		"northup"   : __DIR__"jianhugate",
		"northdown" : __DIR__"shanlu8",
	]));
	set("coor/x", -71000);
	set("coor/y", -79970);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}