// Room: /d/quanzhou/xita.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������������붫�����ֲ����������⣬�������������ͬ��
ǡ��һ��������á������������������������Ÿ��ֻ����񡢳桢��
��װ��ͼ����Ҳ��������������̬���棬����һ�����á��泩�����С�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"yuetai",
	]));
	set("coor/x", 1820);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
