// /kaifeng/daoxiang1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����������������ʷ�ˡ����ⶰ¥����ںڵ���������ܿ�������
���������ʳ�ͻ���ͦ�ࡣ�����������ˡ�¥�ϵ�Ȼ��������������Ҫ
��һ����ݵ�λ���˲����ϡ�
LONG
	);
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("exits", ([
		"up"   : __DIR__"daoxiang2",
		"west" : __DIR__"road2",
		"east" : __DIR__"majiu",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));

	setup();
	"/clone/board/kedian19_b"->foo();
	replace_program(ROOM);
}
