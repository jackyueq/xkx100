inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ����Ͼ��Ǳ����ǡ������ӵġ���
�̵ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ
����������������߷ɳ۶���������һ·�����������и�С̯�����
��������ЪϢ��
LONG );
	set("exits", ([
		"west"  : __DIR__"xiaotan",
		"north" : __DIR__"road4",
		"south" : __DIR__"road9",
	]));
	set("outdoors", "huabei");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 3100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

