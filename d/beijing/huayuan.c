inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
����һ��С��԰����Ȼ������̫�࣬ȴʮ��������࣬����ƽ��
����������ɨ����԰������һ����á�
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
  		"east"  : __DIR__"kang3",
  		"north" : __DIR__"fotang",
	]));
	set("coor/x", -181);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
