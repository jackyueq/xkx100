inherit ROOM;

void create()
{
	set("short", "�ذ��Ŷ����");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ����������
LONG );
        set("outdoors", "beijing");

	set("exits", ([
		"east" : __DIR__"di_an1",
		"west" : __DIR__"di_anmen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg" :  2,
	]));
	set("coor/x", -180);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
