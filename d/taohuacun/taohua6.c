// Room: /d/taohuacun/taohua6.c

inherit ROOM;

void create()
{
	set("short", "�һ�͡");
	set("long", @LONG
�һ�͡���һ�Ϫ�ߡ�һ��һ������Ϫ��Ȥ������������������
ϧ�������޾����顣��ˮ�������ʱ�ڣ���ĿƮ�㣬����һ����
Ȥ��͡��һ�������е�㾫��Ư����С����������ס�Һ�ȥ����
LONG );
	set("outdoors", "taohuacun");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"shijigate",
		"south"     : __DIR__"taohua2",
		"west"      : __DIR__"taohua7",
		"east"      : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/taohuatong" : 1,
	]));
	set("coor/x", -100);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}