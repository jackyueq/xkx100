// Room: /beijing/nandaj2.c

inherit ROOM;

void create()
{
	set("short", "�ϴ�ֹ㳡");
	set("long", @LONG
������һ�����ֵĹ㳡�����Ǳ������������֡������ҵĵضΡ�һ
�����ź�綫�����������ӻ������Ϸ���ܽ������˵Ⱦ۾ӵ����ڡ���
���Ĵ�����ϱ���ͷ���졣�ϱ��������ţ�ͨ�����⣻�������ϴ�֣�
ͨ���찲�š������������ġ�������ݡ������Ƕ������Ƕ���Ϣ���졣
������һ�Һܴ�����׳�����ʱ�����������İ�����
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"tuzai",
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"yongding",
		"north" : __DIR__"nandaj1",
	]));
        set("objects", ([
		"/d/baituo/npc/snaker" : 1,
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
        ]));
	set("coor/x", -200);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
