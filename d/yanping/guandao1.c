// Room: /d/yanping/guandao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
�������ǳǽ�����������Ҳ�����������������ݵĹٻ��������̶�
�Ѷ�����������ٴ죬����һ����ζ��
    �����й�����ð���ƺ��м�Ұ�ꡣ
LONG );
	set("exits", ([
		"east"   : "/d/fuzhou/ximen",
		"north"  : __DIR__"jiusi",
		"westup" : __DIR__"guandao2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1800);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
