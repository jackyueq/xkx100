inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡����˵ȫ�����ض�������
�ķֵ꣬�������еĿ�ջ����һ�������С�������������¶�棬˭Ҳ��
֪��������������һ���ˡ�
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandaj1",
		"east" : __DIR__"majiu",
	]));
	set("coor/x", -190);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian2_b"->foo();
	replace_program(ROOM);
}
