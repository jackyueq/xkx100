inherit ROOM;

void create()
{
	set("short", "���ı����");
	set("long", @LONG
����һ�������Ľֵ������߾��������ǳ�ȥ���������ﳤ����𲻶ϣ�
�������ơ��ϱ�����������֡�
LONG );
  set("outdoors", "city2");
	set("coor/x", -220);
	set("coor/y", 4070);
	set("coor/z", 0);

	set("exits", ([
		"north" : __DIR__"xisi2",
		"east" : __DIR__"wenmiao",
		"south" : __DIR__"xidan1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


