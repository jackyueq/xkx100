// Room: /heizhao/shanlu9.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ���������ɿڿʣ�����Զ����������ˮ�����㵱��
�ӿ�Ų�����ɽ�żţ���ˮ����ɽ�ȼ伤�����죬������ڣ�����
ˮ�����󣬴��������붥��ֻ��һ�������ƵĴ��ٲ��Ӷ���˫��֮
�䱼�ڶ��£��������Ǿ��ˡ�����������ȥ���ٲ�����һ����ݡ�
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"pubu",
		"eastdown"  : __DIR__"shanlu8",
	]));
	set("coor/x", -5020);
	set("coor/y", -1290);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}