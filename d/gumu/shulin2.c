// shulin2.c ����
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
������һ���ּ��С���ϣ����ܶ�������Զ���ƺ���һ�ǽ����ķ�
�ܴ�������¶�˳�����Ҳ������ɽ����һ������֮�ࡣ��Щ�����
�в��������������䶼�Ѿ��ܳ��ˡ�
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"southwest" : __DIR__"shulin3",
		"northeast" : __DIR__"shulin1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3210);
	set("coor/y", 60);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
