// Room: /d/suzhou/disanquan.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","����Ȫ");
	set("long",@LONG
����Ȫ��ǧ��ʯ֮�����������£���Ȫ��Ө����ϵ�ƴ���ʥ½��
���ڣ�������½�𾮡���Ʒ��Ϊ���µ���Ȫ����������Ȫͤ�����⡰��
���ҡ����֣�ȡ����ʫ���������ұڡ����⡣
LONG);
	set("outdoors", "suzhou");
	set("exits",([
		"east" :__DIR__"qianrenshi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 790);
	set("coor/y", -1020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
