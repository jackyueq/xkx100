// hsroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��ϱ���Լ�ɼ������ݳǵĳ�ǽ������������·��
��ͨ��ɽ�
LONG );
        set("outdoors", "village");
	set("exits", ([
		"south"     : __DIR__"hsroad1",
		"northwest" : __DIR__"hsroad3",
		"northeast" : "/d/huashan/jzroad1",
	]));
	set("no_clean_up", 0);

	set("coor/x", -960);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}