// Room: /d/yanping/beimenling.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ƽ������ǽ����ɽ�¾���֮�䣬��������ڱ�����䡣�������
�ߴ���ʵ�ã��ɽ�ˣ��Ӵ����½���ϪԴʮ�ﻭ�ȣ�ֱ��ã�����Ϫ
Դ��
LONG );
	set("exits", ([
		"northwest" : __DIR__"youlang",
		"southdown" : __DIR__"meishanpo",
	]));
	set("outdoors", "jiangnan");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
