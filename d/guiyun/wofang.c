// Room: /d/guiyun/wofang.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","�Է�");
	set("long",@LONG
����ׯ�����Է������䲻����ʰ�úܸɾ������е�С�������Ϸ�
��һ�Ѿƺ���һֻ���ѣ��������˳������������ס�
LONG );
	set("exits",([
		"east" : __DIR__"houting",
	]) );
	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}
