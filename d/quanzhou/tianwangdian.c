// Room: /d/quanzhou/tianwangdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ɽ�ż�����������������������һ��ŭĿͦ����״����
�͡��������һƬ���Ĵ�ʯͥ��ͨ������Ĵ��۱��
LONG );
	set("exits", ([
		"south" : __DIR__"kaiyuansi",
		"north" : __DIR__"dxbaodian",
	]));
	set("objects", ([
		"/d/hangzhou/npc/shami" : 1,
	]));
	set("coor/x", 1830);
	set("coor/y", -6510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
