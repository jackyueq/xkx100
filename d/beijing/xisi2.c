inherit ROOM;

void create()
{
	set("short", "���ı����");
	set("long", @LONG
���������ı���֡��ϱ�ͨ������������ͨ��ذ��ţ�������һ��
��Ժ��
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east"  : __DIR__"di_an4",
		"south" : __DIR__"xisi",
		"north" : __DIR__"weifu_men",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
