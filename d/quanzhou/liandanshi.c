// Room: /d/quanzhou/liandanshi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
���������ϵ�һ��խʯ (stone)��������ڡ��������ϣ��������
˺�������絶�ͷ��Ŀѣ��ҡҡ��׹���ഫ������������Ӣ�������
����ʱ������ʯ����������̵ġ�������ɽ���ĸ��֡�
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"stone" :"ֻ��խʯ���������ϣ��ο�籩��ʼ�ղ������㲻����̾����֮�档\n",
	]));
	set("exits", ([
		"eastdown"  : __DIR__"shanlu2",
		"northwest" : __DIR__"qianshouyan",
	]));
	set("coor/x", 1840);
	set("coor/y", -6410);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
