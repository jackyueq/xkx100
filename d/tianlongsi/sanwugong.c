inherit ROOM;

void create()
{
        set("short", "���޹�");
        set("long",@LONG
����������㵽����ΰ�������ʿ�������������Χ��һ������ɮ
���ּۻ��ۡ�
LONG );
        set("exits", ([
                "southeast" : __DIR__"doushuai",
		"north" : __DIR__"cibeiyuan",
	]));
	set("objects",([
                "/d/wudang/npc/guest" : 4,
		__DIR__"npc/laoniansengren" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37010);
	set("coor/y", -57070);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}