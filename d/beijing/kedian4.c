inherit ROOM;

void create()
{
	set("short", "���ͷ�");
	set("long", @LONG
���������ͷ���һ���ƹ��������ƶ��ڽ�����ɪɪ������
LONG );
	set("exits", ([
		"east" : __DIR__"kedian2",
	]));
	set("objects", ([
		__DIR__"npc/zhanggui":1,
		__DIR__"npc/huoji":2,
	]));
	set("coor/x", -230);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
