// Room: /d/suzhou/lingyanshan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long",@long
������ɽ����״����֥�ľ�ʯ����������ɽ������ɽ��ͦ��������
��ʯ��ᾣ���������⹬�ż������С����е�һ�塱��������
long);
	set("outdoors", "suzhou");
	set("objects",([
		__DIR__"obj/xiao-shuzhi" : 1,
		__DIR__"obj/da-shitou" : 1,
	]));
	set("exits",([
		"south"     : __DIR__"road7",
		"eastup"    : __DIR__"yingxiaoting",
		"northwest" : __DIR__"tianpingshan",
	]));
	set("coor/x", 850);
	set("coor/y", -1100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
