// Room: /d/suzhou/hutong1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "��ͬ");
	set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ��
������ͨ��С��������˾��ӵ�Ȼ�ǲ������Ǳ���ȥ�ġ������߾ͻ�
�ص����д�·�ˡ�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"dongdajie1",
		"northeast" : __DIR__"hutong2",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", 860);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
