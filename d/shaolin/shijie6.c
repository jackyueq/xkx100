// Room: /d/shaolin/shijie6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�������ٲ��Ϸ�һ��խխ��ɽ������Ȼ��ɡ�ʯ�������˹�
���һ�����ݡ����϶��˼���ľ׮�����ϴֳ���������Ϊ���֡�
�ٲ��ڽ��±��ڶ������ڲ�Զ��ɽ���»��һ����̶��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shijie5",
		"northup" : __DIR__"shijie7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", -20);
	set("coor/y", 740);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}