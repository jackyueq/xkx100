// Room: /d/wuyi/dazangfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��ط�");
	set("long", @LONG
ÿ�ο������������ϰ��Ĵ�ط壬����һ��͸�������������͸��
���������ٸ������������������Ĳ��Ϻ����䣬��ʷ��������ʱ��
�˵ĺ��غ���ã����ط���Ϫ�ߺ�����𣬶���ǧ�𡣰����������Ѩ��
��Ѩ������ҡ�����ǧ�겻���ĵ��ݣ���Ѩ���𼦶������к��Ű�ͼ�
�ߴ��ס���ν��ǧ�Ÿ��������Σ��������¾���˹������
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"4qu",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 1370);
	set("coor/y", -5020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

