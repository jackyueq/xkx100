inherit ROOM;

void create()
{
	set("short", "�ذ��������");
	set("long", @LONG
����һ����������Ĵ��������ͨ���ذ��š�����ͨ�����ı���֡�
�ϱ��������ˣ�һ���˶��������Ƕ�ȥ��
LONG );
        set("outdoors", "beijing");

	set("exits", ([
		"east"  : __DIR__"di_an3",
		"west"  : __DIR__"xisi2",
		"south" : __DIR__"xichangdamen",
		"north" : __DIR__"shuyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
