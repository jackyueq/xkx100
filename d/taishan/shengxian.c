// Room: /d/taishan/shenxian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "���ɷ�");
	set("long", @LONG
������ʮ���̵��м䣬������ֱ�������ŵ�һ�ξ��ǽ�ʮ�����ˡ�
�ɴ˿���ʯ���ϣ�������˿��Կ���ǰ����˵�Ь�ף�ǰ����˻�ͷ��
�ɼ���������˵ķ�����������һ����ÿ��ʮ������Ҫ��һ��Ϣ��
LONG );
	set("exits", ([
		"northup"   : __DIR__"jin18",
		"southdown" : __DIR__"jinman18",
	]));
	set("objects", ([
		__DIR__"npc/jianchu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 750);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
