// Room: /d/yanping/yidao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�Թ������޳�;����������ȫ��������������������������ͨ��
������ؽ�ϪϪ�����£�ɽ�ҽ�����é����أ����ë��һ·��ͬ����
����״������ɽ���ദ���壬��ˮ�峺ˬ�ڣ�����������죬��Ȼһ·
�������������䣬��Ҳ����һ����Ȥ��
LONG );
	set("exits", ([
		"northdown" : __DIR__"shandao1",
		"southup"   : __DIR__"yidao2",
	]));
	set("objects", ([
		"/d/taishan/npc/tiao-fu" : 2,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -6000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
