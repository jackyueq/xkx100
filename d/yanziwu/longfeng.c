//ROOM: /d/yanziwu/juxian.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@LONG
����һ������Ρ�룬������Ĵ����ã�����ǰһ�Դ�ʯʨ������
��צ�������� "������" ���������پ����������Ȳ���������ǽ�Ϲ���
�����ֻ���һ�Ŵ�������ϲ������������Χ��һȦ̴��ľ���Ρ�
LONG );
	set("exits", ([
		"south" : __DIR__"yimen",
		"east"  : __DIR__"lixiang",
		"west"  : __DIR__"pindi"
	]));
	set("no_clean_up", 0);
	set("coor/x", 820);
	set("coor/y", -1520);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}