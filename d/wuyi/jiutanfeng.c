// Room: /d/wuyi/jiutanfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��̳��");
	set("long", @LONG
��̳��λ���������ϵĸ���̨���࣬���������塣�ҷ����ͦ����
���絹���ľ�̳���ഫ�����������ڴ�һŭ�߷��ľ�̳�����ʵ�����
�����㲻�ϡ�������Ůʿ��ȴ���ɽ�����̳�塣
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"gengyitai",
	]));
	set("objects", ([
		"/d/taishan/npc/seng-ren" : 1,
	]));
	set("coor/x", 1350);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

