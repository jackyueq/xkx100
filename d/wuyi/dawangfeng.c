// Room: /d/wuyi/dawangfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ֳ�ɴñ�壬ɽ�������ɴñ���������Ƕ���������ɽΪ��
���ĵ�һ�塣�������±������Ϸ������������ۻ롣ԶԶ��ȥ��������
�����������Ůңң������ʯ���Ͽ��С��Ӹ�˼Σ�����ֺ�Ȼ��Ŀ����
�˴������飬�������棬ֱָ���ġ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"path3",
		"southdown" : __DIR__"path1",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	set("coor/x", 1390);
	set("coor/y", -4990);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

