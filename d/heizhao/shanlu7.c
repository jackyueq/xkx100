// Room: /heizhao/shanlu7.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�������󲽾�����ɽ��ѭ�Ŷ�·���룬ԼĪ����һ��ʱ������
·��խ����Щ�ط���������ӷ��ܹ�ȥ������·��ɽ����죬����
�����ﶨ�ܽ�����ȫȻ��ȥ����Ҳ�Լ���Ϊ������
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"shanlu6",
		"northup"  : __DIR__"shanlu8",
	]));
	set("coor/x", -5010);
	set("coor/y", -1300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}