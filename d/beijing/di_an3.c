inherit ROOM;

void create()
{
	set("short", "�ذ��������");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ�����ġ���֪
��Ϊʲô�����������������壬�������������ˡ�
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"di_anmen",
		"west" : __DIR__"di_an4",
	]));
	set("objects", ([
		"/d/city/npc/liumangtou" : 1,
		"/d/city/npc/liumang" :  2,
	]));
	set("coor/x", -200);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
