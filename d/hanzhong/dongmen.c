// dongmen.c ����
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ�����Ķ��ţ���ǰ��ǽ���ʣ�ǽ�ϵļ����������
��������ȥ��������������ǽ�����������׹⣬�ƺ��Ǳ��������
�Ĺ⡣���������š����š��������֣��ſ�վ��һЩ�ٱ������ֳ�
���������������������ǡ�
LONG
	);
	set("outdoors", "hanzhong");
	set("exits", ([
		"east" : __DIR__"guandao2",
		"west" : __DIR__"dongjie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -3120);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
