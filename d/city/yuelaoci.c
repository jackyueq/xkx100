// Room: /yangzhou/yuelaoci.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
СС���������ϡ�٣����������ݳǵı���Ľ����ϡ�������Ա
������żȻ��Щ������Ů�ҴҵĽ��룬ϲ�ǲΰ���뿪���������У���
�乩�źͰ����׵����ϡ�������ǰһ�Ź����������ʯ����򵥵��ĳ�
�衣
LONG );
	set("exits", ([
		"southwest"  : __DIR__"tianningxiang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 50);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}