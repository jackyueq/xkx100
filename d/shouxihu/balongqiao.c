// Room: /yangzhou/balongqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
��̨��С��ɽ֮����һ���������̣������жμ���������ܰ���ͷ
�������ţ�����ǰ����š�
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"north"   : __DIR__"chuitai",
		"southup" : __DIR__"changchunling",
	]));
	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}