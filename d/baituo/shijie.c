// Room: /d/baituo/shijie.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","ʯ��");
	set("long",@TEXT
��������ʯ���̳ɵ�ʯ���ϡ�������Ǵ�˵�����صİ���ɽ��ԶԶ
��ȥ��������ɳ�ѻ��γɵ�ɽ�����һֻ���յļ�����һ��ɽ��������
����ǰ��
TEXT );
	set("exits",([
		"east"      : __DIR__"caoping",
		"northup"   : __DIR__"damen",
		"southdown" : __DIR__"guangchang" ,
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
